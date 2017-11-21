/**
 *  MIT License
 *  
 *  Copyright (c) 2017 Harish Sampathkumar
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/**
 *  @file    main.cpp
 *  @author  Harish Sampathkumar
 *  @copyright MIT License
 *
 *  @brief Implementing a simple walker node
 *
 *  @section DESCRIPTION
 *
 *  This program makes the turtle to move forward until it senses
 *  a obstacle(without colliding), then rotate in place until the
 *  way ahead is clear, then move forward again and repeat.
 */

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
