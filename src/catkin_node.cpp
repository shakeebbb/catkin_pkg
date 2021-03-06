#include <ros/ros.h>
#include<std_msgs/String.h>

int main(int argc, char ** argv)

{

ros::init(argc, argv, "catkin_node");

int loopRate;

ros::param::get("ros_node/loopRate", loopRate);

ros::NodeHandle n;

ros::Publisher pub = n.advertise <std_msgs::String> ("/hello_msg", 100);

ros::Rate loop_rate(loopRate);

while(ros::ok())
{
std::string s = "Hello";

std_msgs::String helloMsg;
helloMsg.data = s;

pub.publish(helloMsg);

loop_rate.sleep();
}

}
