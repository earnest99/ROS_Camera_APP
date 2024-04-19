import cv2
import dlib
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class EmojiOverlayNode(Node):
    def __init__(self):
        super().__init__('emoji_overlay')
        self.subscription = self.create_subscription(
            Image,
            '/camera',
            self.image_callback,
            10)
        self.publisher_ = self.create_publisher(Image, 'emoji_overlay_result', 10)
        self.cv_bridge = CvBridge()

        # Initialize face detector and shape predictor
        self.detector = dlib.get_frontal_face_detector()
        self.predictor = dlib.shape_predictor('/home/earnest/camera_study/src/camera_app/camera_app/shape_predictor_68_face_landmarks.dat')

        # Load emoji image
        self.overlay = cv2.imread('/home/earnest/camera_study/src/camera_app/camera_app/samples/ryan_transparent.png', cv2.IMREAD_UNCHANGED)

        # Initialize variables
        self.face_sizes = []
        self.frame_count = 0

    def overlay_transparent(self, background_img, img_to_overlay_t, x, y, overlay_size=None):
        bg_img = background_img.copy()

        if bg_img.shape[2] == 3:
            bg_img = cv2.cvtColor(bg_img, cv2.COLOR_BGR2BGRA)

        if overlay_size is not None:
            img_to_overlay_t = cv2.resize(img_to_overlay_t.copy(), overlay_size)

        b, g, r, a = cv2.split(img_to_overlay_t)
        mask = cv2.medianBlur(a, 5)
        mask = mask.astype(np.uint8)

        h, w, _ = img_to_overlay_t.shape
        roi = bg_img[int(y-h/2):int(y+h/2), int(x-w/2):int(x+w/2)]

        img1_bg = cv2.bitwise_and(roi.copy(), roi.copy(), mask=cv2.bitwise_not(mask))
        img2_fg = cv2.bitwise_and(img_to_overlay_t, img_to_overlay_t, mask=mask)

        bg_img[int(y-h/2):int(y+h/2), int(x-w/2):int(x+w/2)] = cv2.add(img1_bg, img2_fg)
        bg_img = cv2.cvtColor(bg_img, cv2.COLOR_BGRA2BGR)

        return bg_img

    def image_callback(self, msg):
        cv_image = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        ori = cv_image.copy()

        # Find faces
        faces = self.detector(cv_image, 1)

        # No faces
        if len(faces) == 0:
            result = ori
            print('No faces detected!')
        else:
            for face in faces:
                dlib_shape = self.predictor(cv_image, face)
                shape_2d = np.array([[p.x, p.y] for p in dlib_shape.parts()])

                # Compute face center
                center_x, center_y = np.mean(shape_2d, axis=0).astype(np.int)

                # Check if face center is within image boundaries
                if center_x < 0 or center_x >= cv_image.shape[1] or center_y < 0 or center_y >= cv_image.shape[0]:
                    continue

                # Compute face boundaries
                min_coords = np.min(shape_2d, axis=0)
                max_coords = np.max(shape_2d, axis=0)

                # Compute face size
                face_size = max(max_coords - min_coords)

                # Ensure that face_size is not zero
                if face_size == 0:
                    continue

                # Update face_sizes list with current face size
                self.face_sizes.append(face_size)

                # Reset face_sizes list if it exceeds a certain length
                if len(self.face_sizes) > 10:
                    self.face_sizes = self.face_sizes[1:]

                # Compute mean face size based on recent face sizes
                mean_face_size = int(np.mean(self.face_sizes) * 1.8)

                # Resize emoji based on face size
                resized_overlay = cv2.resize(self.overlay, (mean_face_size, mean_face_size))

                # Overlay emoji on face
                result = self.overlay_transparent(ori, resized_overlay, center_x , center_y -25 , overlay_size=(mean_face_size, mean_face_size))

        # Publish result
        edges_msg = self.cv_bridge.cv2_to_imgmsg(result, encoding='bgr8')
        self.publisher_.publish(edges_msg)

def main(args=None):
    rclpy.init(args=args)
    emoji_overlay_node = EmojiOverlayNode()
    rclpy.spin(emoji_overlay_node)
    emoji_overlay_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
