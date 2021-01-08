#include "ros/ros.h"
#include "learning_launch/talk_info.h"

#include <sstream>

void rec_callback(const learning_launch::talk_info::ConstPtr& msg){
  std::cout << "Received:" << (*msg).s << std::endl;
}


int main(int argc, char** argv){
  /*
  std::cout << argc << std::endl;
  for (int i = 0; i < argc; i++){
    std::cout << argv[i] << std::endl;
  }
  */
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<learning_launch::talk_info>("chatter", 1000, rec_callback);

  ros::spin();
  
  return 0;
}
