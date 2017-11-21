#include <sstream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/LaserScan.h>
#include "walker.hpp" 

int main(int argc, char **argv) {
  // initializing a ros node called walker
  ros::init(argc, argv, "walker");

  walker simpleWalker;

  // creating a node handle
  ros::NodeHandle n;

  // Subscribing to the topic publishing laser scanner data
  ros::Subscriber sensor = n.subscribe<sensor_msgs::
          LaserScan>("/scan", 50, &walker::sensorCallback, &simpleWalker);

  // Creating a publisher object which publishes to the given topic
  ros::Publisher velocity = n.advertise<geometry_msgs::Twist>
                             ("/mobile_base/commands/velocity", 1000);
  
  ros::Rate loop_rate(10);

  while (ros::ok()) {
  geometry_msgs::Twist msg;

  // Initiaizing msg with 0
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;

  if (simpleWalker.isClose() == true) {
    // rotate until obstacle out of the range
    msg.angular.z = 1;
  } else {
    // move forward
    msg.linear.x = 0.3;
  }

  velocity.publish(msg);
 
  ros::spinOnce();

  loop_rate.sleep();
  }
  return 0;
}
