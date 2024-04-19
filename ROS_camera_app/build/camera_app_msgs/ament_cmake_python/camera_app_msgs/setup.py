from setuptools import find_packages
from setuptools import setup

setup(
    name='camera_app_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('camera_app_msgs', 'camera_app_msgs.*')),
)
