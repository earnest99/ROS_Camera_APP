import cv2

def main():
    video_file = "/home/earnest/camera_study/recordings/20240419_103847.avi"  # 저장된 비디오 파일 경로
    cap = cv2.VideoCapture(video_file)

    if not cap.isOpened():
        print("Error: Failed to open video file.")
        return

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        cv2.imshow("Video Playback", frame)
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
