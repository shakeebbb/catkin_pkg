#include <ros/ros.h>
#include<std_msgs/String.h>

ros::Publisher pub;

void helloCb(const std_msgs::String&);

int main(int argc, char ** argv)

{

ros::init(argc, argv, "ros_node");

ros::NodeHandle n;

pub = n.advertise <std_msgs::String> ("reply_msg", 100);
ros::Subscriber sub = n.subscribe ("/hello_msg", 100, helloCb);


ros::Rate loop_rate(10);

while(ros::ok())
{

ros::spinOnce(); 

loop_rate.sleep();

}
}
void helloCb(const std_msgs::String& msg)
{

std::string s;
s = msg.data;

std_msgs::String reply_msg;
reply_msg.data = "Hi!!";

pub.publish(reply_msg);
}
