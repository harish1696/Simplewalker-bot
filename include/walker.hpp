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
 *  @file    walker.hpp
 *  @author  Harish Sampathkumar
 *  @copyright MIT License
 *
 *  @brief Class walker definition
 *
 *  @section DESCRIPTION
 *
 *  Contains the definition of class walker which finds if the path ahead 
 *  is clear of obstacles and acts accordingly.
 *  
 */

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class walker {
 public:

   /**
   *   @brief  Constructor of Walker class
   *
   *   @param  none
   *   @return none
   */
   walker();

   /**
   *   @brief  Destructor of Walker class
   *
   *   @param  none
   *   @return none
   */
   ~walker();

   /**
   *   @brief  Callback function to check if any obstacle 
   *   is within range using /scan topic
   *
   *   @param  message of type sensor_msgs::LaserScan
   *   @return none
   */
   void sensorCallback(const sensor_msgs::LaserScan::ConstPtr& msg);

   /**
   *   @brief  returns the value of obstacle
   *
   *   @param  none
   *   @return true if obstacle is within range, otherwise false
   */
   bool isClose();

 private:
    // a flag variable to denote the presence of any obstacle in proximity
    bool obstacle;

};

