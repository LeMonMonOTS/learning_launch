#include "ros/ros.h"
#include "learning_launch/talk_info.h"

#include <sstream>

int main(int argc, char** argv){
  /*
  std::cout << argc << std::endl;
  for (int i = 0; i < argc; i++){
    std::cout << argv[i] << std::endl;
  }
  */
  ros::init(argc, argv, argv[1]);
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<learning_launch::talk_info>("chatter", 1000);
  ros::Rate pub_rate(1);
  while (ros::ok()){
    std::stringstream ss;
    ss << "Data: " << argv[1]; 
    learning_launch::talk_info msg;
    msg.s = ss.str();
    pub.publish(msg);
    std::cout << "Sending:" << msg.s << std::endl;
    pub_rate.sleep();
  }
  

  return 0;
}
