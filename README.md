# catkin_pkg
Code for ROS Tutorial - ECE 595 Autonomous Mobile Robots

What is this package about ???

This package contains nodes for our first two publisher-subscriber examples. 

1) "catkin.launch" file launches "catkin_node" and "ros_node" from the package "catkin_pkg".

What do these nodes do ?

--- "catkin_node" publishes a message of type "std_msgs::String" on a topic "hello_msg". The structure of the message is such that it contains a member of C++ standard string type i.e, "std::string data". The publish rate of the message is specified by a parameter "catkin_node/loopRate". We specify this parameter in the launch file "catkin.launch".

--- "ros_node" subscribes a message on the topic "hello_msg" and publishes a reply "Hi!!" every time it receives the message.

2) "turtle.launch" file launches "turtle_node" from the package "catkin_pkg" and "turtlesim_node" from the package "turtlesim". This example shows how to interface your nodes with the nodes from other open source packages.

What do these nodes do ?

--- "turtlesim" is a node inside an open source package turtlesim. Upon running this node, it launches a turtle on a coloured 2 dimensional environment. This node subscribes to the command velocities and publishes the turtle current pose as the turtle moves.

--- "turtle_node" publishes the linear velocities in x and y directions and the angular velocity about the z axis.

How to use this package ?

--- You need a ROS workspace in your Ubuntu machine to use this package. To create a workspace named "catkin_ws" inside your root folder type the following in your terminal:

$ cd ~ <br />
$ mkdir -p catkin_ws/src <br />
$ cd catkin_ws <br />
$ catkin_make <br />

--- Clone this package inside the source folder of the ROS workspace:

$ cd ~/catkin_ws/src <br />
$ git clone https://github.com/shakeebbb/catkin_pkg <br />
$ cd ~/catkin_ws <br />
$ catkin_make <br />

--- Install turtlesim package by using the following commands:

$ cd ~/catkin_ws/src <br />
$ git clone https://github.com/ros/ros_tutorials <br />
$ cd ~/catkin_ws <br />
$ catkin_make <br />

--- Source your workspace by typing the following in your terminal:

$ source ~/catkin_ws/devel/setup.bash <br />

Everything compiled successfully and I am being quite impatient about getting some sort of output, what should I do ?

--- You may want to play with these nodes now for example run the "catkin.launch" file by typing:

$ roslaunch catkin_pkg catkin.launch <br />

Commands like "$ rostopic list",  "$ rostopic echo <topic name>",  "$ rostopic info <topic name>",  "$ rostopic type <topic name>" and "$ rostopic hz <topic name>" might be helpful in analyzing what's going on.

--- If you want to see a turtle moving in a circle, you can also launch "turtle.launch" by typing:
$ roslaunch catkin_pkg turtle.launch <br />

I am already tired of ROS, what should I do ???

--- Good news is that the ROS nodes can be written in Python or Matlab as well. To control the turtle using Matlab, spawn the turtle first on your screen by typing the following on the terminal:

$ source ~/catkin_ws/devel/setup.bash <br />
$ roscore & rosrun turtlesim turtlesim_node <br />

Now run the Matlab script (~/catkin_ws/src/catkin_pkg/matlab/script.m) in your Matlab and you should see the turtle moving in the circle again, but this time using Matlab!

ROS is scary, isn't there any easier way to control the robots this way ???

--- Let me know if you could find any. :)
