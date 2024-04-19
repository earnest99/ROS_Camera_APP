import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class EdgeDetectorNode(Node):
    def __init__(self):
        super().__init__('canny')
        self.subscription = self.create_subscription(
            Image,
            '/camera',
            self.image_callback,
            10)
        self.subscription  
        self.publisher_ = self.create_publisher(Image, 'canny_edge', 10)  
        self.cv_bridge = CvBridge()

    def image_callback(self, msg):
        cv_image = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        gray_image = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray_image, 100, 200) 
        edges_msg = self.cv_bridge.cv2_to_imgmsg(edges, encoding='mono8')
        self.publisher_.publish(edges_msg)  

def main(args=None):
    rclpy.init(args=args)
    edge_detector_node = EdgeDetectorNode()
    rclpy.spin(edge_detector_node)
    edge_detector_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()