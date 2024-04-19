# ROS_CAMERA_APP

ROS2 패키지로 만든 카매라 앱

## 1. 기능

+ 사진 촬영

+ 영상 녹화

+ 필터 적용
  + 원본
  + canny필터
  + 얼굴 이모지 필터
---
## rqt-graph 구성도
![Screenshot from 2024-04-19 14-55-56](https://github.com/earnest99/ROS_Camera_APP/assets/128347421/d2fdcc1f-a571-4170-a7d3-e362a053b62a)

---
## 2. 실행

> ros2 패키지폴더에서 (~/ROS_camera_app)
> 
> ~/.bashrc 가장 마지막 줄에 추가
> 
>
> ```
> alias sb="source ~/.bashrc; echo \"bashrc is reloaded\""
> alias humble="source /opt/ros/humble/setup.bash; ros_domain; echo \"ROS2 humble is activated!\""
> alias ros_domain="export ROS_DOMAIN_ID=21; echo \"ROS_DOMAIN_ID= \$ROS_DOMAIN_ID\""
> alias camerastudy="humble; source ~/camera_study/install/local_setup.bash; echo \"camera_study workspace is activated.\""
> ```
> 

---
> ![Screenshot from 2024-04-19 14-26-00](https://github.com/earnest99/ROS_Camera_APP/assets/128347421/b91fe642-489b-44f7-a87b-cc58e0a776e9)
> 
> ---
> ### 터미널1 
> build & launch
> 
> ```bash
> colcon build
> camerastudy
> ros2 launch camera_app camera.launch.py 
> ```
> ---
> ### 터미널2 
> rqt
> ```
> camerastudy
> rqt
> ```
> ---
> ### 터미널3 
> service
> ```
> camerastudy
> ros2 run camera_app capture_and_record 
> ```
> ---
> ### 터미널4 
> 명령
> 
> 1.사진 촬영 명령어
> ```
> camerastudy
> ros2 service call /img_capture camera_app_msgs/srv/Capture "{cam: 1}"
> ```
> 2.영상 녹화 명령어
> ```
> ros2 service call /img_capture camera_app_msgs/srv/Capture "{rec: 1}"
> 
> ```
> 3.녹화 중지 명령어
> ```
> ros2 service call /img_capture camera_app_msgs/srv/Capture "{rec: 0}"
> 
> ```
> 
> ---

## 3. rqt UI
![Screenshot from 2024-04-19 15-02-05](https://github.com/earnest99/ROS_Camera_APP/assets/128347421/a1539023-81b0-45b2-90c6-1d6c8dadd1a4)

원본, 캐니필터, 이모지필터

---

## 4. 저장 결과
![Screenshot from 2024-04-19 14-29-28](https://github.com/earnest99/ROS_Camera_APP/assets/128347421/1d1773ca-6097-4604-b37f-d8d3799a170f)
