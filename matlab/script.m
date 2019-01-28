clc
clear all

rosshutdown
rosinit

commandMsg = rosmessage('geometry_msgs/Twist');

commandPub = rospublisher('turtle1/cmd_vel', 'geometry_msgs/Twist');

commandMsg.Linear.X = 0.3;
commandMsg.Angular.Z = 0.3;

while(1)
send(commandPub, commandMsg);
end