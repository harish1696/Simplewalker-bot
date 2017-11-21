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
 *  @file    walker.cpp
 *  @author  Harish Sampathkumar
 *  @copyright MIT License
 *
 *  @brief Implementing the methods of class walker
 *
 *  @section DESCRIPTION
 *
 *  Defines class walker methods  
 *
 */


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

