from setuptools import find_packages, setup
import glob
import os

package_name = 'camera_app'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch',glob.glob(os.path.join('launch', '*.launch.py'))),
        ('share/' + package_name + '/param',glob.glob(os.path.join('param', '*.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='earnest',
    maintainer_email='12yhkim@naver.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'img_publisher = camera_app.img_publisher:main',
            'canny = camera_app.canny:main',
            'emoji_overlay = camera_app.emoji_overlay:main',
            'capture_and_record = camera_app.capture_and_record:main',
            
        ],
    },
)
