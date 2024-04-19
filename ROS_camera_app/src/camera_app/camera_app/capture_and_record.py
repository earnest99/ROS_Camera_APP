

from camera_app_msgs.srv import Capture
import cv2
import numpy
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import datetime

class ImgCapture(Node):
    def __init__(self):
        super().__init__('img_capture')
        self.server = self.create_service(Capture, 'img_capture', self.callback_service)
        self.create_subscription(Image, '/emoji_overlay_result', self.img_callback2, 10)
        self.create_subscription(Image, '/camera', self.img_callback1, 10)
        self.create_subscription(Image, '/canny_edge', self.img_callback3, 10)
        self.cv_bridge = CvBridge()
        self.video_writer = None
        self.recording = False
        self.ori=1
        self.emo=1
        self.can=1
        

    def callback_service(self, request, response):
        self.ori = self.count_subscribers('/camera')
        self.emo = self.count_subscribers('/emoji_overlay_result')
        self.can = self.count_subscribers('/canny_edge')

        print(request.cam, type(request.cam))
        now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")

        if self.emo > 1:
            self.img = self.img2
        elif self.can > 1:
            self.img = self.img3
        else:
            self.img = self.img1
        
        if request.cam == 1:
            filename = "/home/earnest/camera_study/recordings/" + now + ".png"
            cv2.imwrite(filename, self.img)
            print("Image saved!")
        elif request.rec == 1:
            filename = "/home/earnest/camera_study/recordings/" + now + ".avi"
            self.start_recording(filename)
            print("Recording started!")
        elif request.rec == 0:
            self.stop_recording()
            print("Recording stopped!")
        else:
            print("Error!")

        return response

    def start_recording(self, filename):
        if self.video_writer is None:
            frame_size = (self.img1.shape[1], self.img1.shape[0])  # Get frame size from the first frame
            fourcc = cv2.VideoWriter_fourcc(*'XVID')
            self.video_writer = cv2.VideoWriter(filename, fourcc, 20.0, frame_size)
            self.recording = True
            

    def stop_recording(self):
        if self.video_writer is not None:
            self.video_writer.release()
            self.video_writer = None
            self.recording = False

    def write_frame(self, frame):
        if self.video_writer is not None:
            self.video_writer.write(frame)

    def img_callback1(self, msg):
        self.img1 = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        if self.ori > 3 and self.recording:
            print(self.ori,self.emo,self.can)
            self.write_frame(self.img1)

    def img_callback2(self, msg):
        self.img2 = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        if self.emo > 1 and self.recording:
            print(self.ori,self.emo,self.can)
            self.write_frame(self.img2)
    
    def img_callback3(self, msg):
        self.img3 = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        if self.can > 1 and self.recording:
            print(self.ori,self.emo,self.can)
            self.write_frame(self.img3)

def main():
    rclpy.init()
    node = ImgCapture()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
