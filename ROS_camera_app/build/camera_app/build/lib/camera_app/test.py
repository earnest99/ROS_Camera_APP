import cv2, dlib, sys
import numpy as np

scaler = 0.5

# initialize face detector and shape predictor
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor('/home/earnest/camera_study/src/camera_app/camera_app/shape_predictor_68_face_landmarks.dat')

# load video
cap = cv2.VideoCapture(-1)
# load overlay image
overlay = cv2.imread('/home/earnest/camera_study/src/camera_app/camera_app/samples/ryan_transparent.png', cv2.IMREAD_UNCHANGED)

# overlay function
def overlay_transparent(background_img, img_to_overlay_t, x, y, overlay_size=None):
    bg_img = background_img.copy()
    # convert 3 channels to 4 channels
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

    # convert 4 channels to 4 channels
    bg_img = cv2.cvtColor(bg_img, cv2.COLOR_BGRA2BGR)

    return bg_img

face_roi = []
face_sizes = []

frame_count = 0

# Loop
while True:
    # Read frame buffer from video
    ret, img = cap.read()
    if not ret:
        break
    DEFAULT_FACE_SIZE = min(img.shape[0], img.shape[1]) // 4

    # Resize frame
    img = cv2.resize(img, (int(img.shape[1] * scaler), int(img.shape[0] * scaler)))
    ori = img.copy()

    # Find faces
    faces = detector(img, 1)

    # No faces
    if len(faces) == 0:
        result=ori
        print('no faces!')
    else:
        for face in faces:
            dlib_shape = predictor(img, face)
            shape_2d = np.array([[p.x, p.y] for p in dlib_shape.parts()])

            # Compute face center
            center_x, center_y = np.mean(shape_2d, axis=0).astype(np.int)

            # Check if face center is within image boundaries
            if center_x < 0 or center_x >= img.shape[1] or center_y < 0 or center_y >= img.shape[0]:
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
            face_sizes.append(face_size)

            # Reset face_sizes list if it exceeds a certain length
            if len(face_sizes) > 10:
                face_sizes = face_sizes[1:]

            # Compute mean face size based on recent face sizes
            mean_face_size = int(np.mean(face_sizes) * 1.8)

            # Load emoji based on some conditions (for example, change emoji every few frames)
            # Replace this line with your own logic to load a new emoji
            if frame_count % 30 == 0:
                overlay = cv2.imread('/home/earnest/camera_study/src/camera_app/camera_app/samples/ryan_transparent.png', cv2.IMREAD_UNCHANGED)

            # Resize emoji based on face size
            resized_overlay = cv2.resize(overlay, (mean_face_size, mean_face_size))

            # Overlay emoji on face
            result = overlay_transparent(ori, resized_overlay, center_x , center_y -25 , overlay_size=(mean_face_size, mean_face_size))

    # Visualize
    # cv2.imshow('original', ori)
    cv2.imshow('result', result)

    frame_count += 1

    if cv2.waitKey(1) == ord('q'):
        sys.exit(1)
