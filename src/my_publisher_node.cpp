#include "ros/ros.h"
#include "baxter_core_msgs/JointCommand.h"

int main(int argc, char* argv[]){

ros::init(argc, argv, "my_publisher");

ros::NodeHandle n;

ros::Publisher pubLeft = n.advertise <baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command",1000);

ros::Publisher pubRight = n.advertise <baxter_core_msgs::JointCommand>("/robot/limb/right/joint_command", 1000);

ros::Rate loop_rate(10);

while(ros::ok()){
baxter_core_msgs::JointCommand msgL;
baxter_core_msgs::JointCommand msgR;

msgL.mode = 1;
msgR.mode = 1;

msgL.command.push_back(0.0);
msgL.command.push_back(0.0);
msgL.command.push_back(0.0);
msgL.command.push_back(0.0);
msgL.command.push_back(0.0);
msgL.command.push_back(0.0);
msgL.command.push_back(0.0);
 
msgR.command.push_back(0.0);
msgR.command.push_back(0.0);
msgR.command.push_back(0.0);
msgR.command.push_back(0.0);
msgR.command.push_back(0.0);
msgR.command.push_back(0.0);
msgR.command.push_back(0.0);

msgL.names.push_back("left_w0");
msgL.names.push_back("left_w1");
msgL.names.push_back("left_w2");
msgL.names.push_back("left_e0");
msgL.names.push_back("left_e1");
msgL.names.push_back("left_s0");
msgL.names.push_back("left_s1");

msgR.names.push_back("right_w0");
msgR.names.push_back("right_w1");
msgR.names.push_back("right_w2");
msgR.names.push_back("right_e0");
msgR.names.push_back("right_e1");
msgR.names.push_back("right_s0");
msgR.names.push_back("right_s1");

pubLeft.publish(msgL);
pubRight.publish(msgR);

ros::spinOnce();
loop_rate.sleep();
}

return 0;
}
