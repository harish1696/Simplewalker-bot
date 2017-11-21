#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class walker {
 public:

  
   walker();

   ~walker();

   void sensorCallback(const sensor_msgs::LaserScan::ConstPtr& msg);

   bool isClose();

 private:
    // a flag variable to denote the presence of any obstacle in proximity
    bool obstacle;

};

