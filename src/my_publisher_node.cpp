#include "ros/ros.h"
#include "baxter_core_msgs/JointCommand.h"

int main(int argc, char* argv[]){

ros::init(argc, argv, "my_publisher_baxter");

ros::NodeHandle n;

ros::Publisher pub = n.advertise <baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command",1000);


while(ros::ok()){
//baxter_core_msgs
}


return 0;
}
