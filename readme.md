A ROS GUI as a separate node is being developed to achieve colour recognition and learning. The development of this work is mainly intended for NTU Singaboat which was developed for the purpose of Maritime RobotX Challenge.

# Usage:
## Follow below steps for installing and using webcam of your Laptop to publish camera image messages:
Installing nodes to use the webcam on ROS (GScam node).

STEP 1:

$ sudo apt-get install ros-kinetic-gscam

STEP 2:

Install Gstreamer

$ sudo apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools

Install its plugins

$ sudo apt-get install gstreamer0.10-plugins-good

STEP 3:

Find your video device using command

$ ls -ltrh /dev/video*

STEP 4:

Change source environment to ROS:

$ source /opt/ros/kinetic/setup.bash 

Run $ roscore on a separate terminal.

STEP 5:

$ roscd gscam

$ export GSCAM_CONFIG="v4l2src device=/dev/video0 ! video/x-raw-rgb ! ffmpegcolor

$ space"

$ rosrun gscam gscam

gscam node should start publishing topic such as camera/image_raw etc. in the command:

$ rostopic list

STEP 6:

To convert the raw image into coloured or mono form, another node image_proc has been used.

In another terminal:

If the driver is publishing topics /my_camera/image_raw and /my_camera/camera_info you would do:

$ ROS_NAMESPACE=my_camera rosrun image_proc image_proc

In a separate terminal:

$ rosrun image_view image_view image:=my_camera/image_color    (To view colored image)

### For using opencv2 with ros images

STEP 1: (one-time install)	

Install opencv2 and related items using single line command:

$ curl -s "https://raw.githubusercontent.com/arthurbeggs/scripts/master/install_apps/install_opencv2.sh" | bash

STEP 2:

Create a new catkin_pkg inside a catkin workspace.

catkin_create_pkg should have following dependencies: sensor_msgs cv_bridge roscpp std_msgs image_transport

Now create a .cpp file. Code link: http://wiki.ros.org/cv_bridge/Tutorials/UsingCvBridgeToConvertBetweenROSImagesAndOpenCVImages

STEP 3: 
Run the node using rosrun command. gscam node should already be running. 

## Follow below steps for using this repository:

STEP 1:
Create a new ROS package named as rqt_image_view under new catkin workspace.

STEP 2: 
Build your catkin_workspace using $ catkin_make.
Source your environment using $ source devel/setup.bash in your catkin_worksapce.

STEP 3:
Run $ roscore in separate terminal.
Use $ rosrun rqt_image_view rqt_image_view and a GUI will appear.
If you have already started publishing your webcam image messages in a separate terminal, then subscribe to them in GUI and then you will see your video stream. 

