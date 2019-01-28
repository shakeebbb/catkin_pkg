#include <ros/ros.h>
#include<std_msgs/String.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char ** argv)

{

ros::init(argc, argv, "turtle_node");

int loopRate;

ros::param::get("ros_node/loopRate", loopRate);

ros::NodeHandle n;

ros::Publisher pub = n.advertise <geometry_msgs::Twist> ("cmd_vel", 100);

ros::Rate loop_rate(loopRate);

while(ros::ok())
{

geometry_msgs::Twist cmdMsg;

cmdMsg.linear.x = 0.3;
cmdMsg.angular.z = 0.3;

pub.publish(cmdMsg);

loop_rate.sleep();
}

}
