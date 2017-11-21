#include <stdlib.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "walker.hpp"

// constructor of walker object
walker::walker() {}

// destructor of walker object 
walker::~walker() {}

// callback function of subscriber, which keeps checking if there is a obstacle ahead
void walker::sensorCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    for (int i = 0; i < msg->ranges.size(); ++i) {
        if (msg->ranges[i] < 0.7) {
            obstacle = true;
            ROS_DEBUG_STREAM("Range " << msg->ranges[i] << " less than 0.7m");
            return;
        }
    }

    obstacle = false;
    ROS_DEBUG_STREAM("No obstacles ahead");
    return;
}

// returns the value of obstacle
bool walker::isClose() {
  return obstacle;
}

