# Simplewalker Bot
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview
This program simulates a simple walker turtlebot which can move forward until it senses an obstacle within a paticular
range. If it detects an obstacle, it rotates until the obstacle goes out range and then the turtlebot moves forward and repeats 
the same. 

It also includes the feature of enabling and disabling rosbag recording which when enabled can record all topics except /camera. 
The rosbag file is generated in the results directory. This rosbag file can be played back later.

## Dependencies
This program works on a device running Ubuntu 16.04 and ROS Kinetic Kame.

To install ROS Kinetic Kame in Ubuntu 16.04, follow the steps in this [link](http://wiki.ros.org/kinetic/Installation/Ubuntu).

To install catkin, follow the installation steps in this [link](http://wiki.ros.org/catkin).

## How to build
Open a terminal window and run the following commands

```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
source devel/setup.bash
cd src
git clone https://github.com/harish1696/Simplewalker-bot.git
cd ..
catkin_make
```
## How to run Simulation
Open a terminal window and run the following commands

```
cd ~/catkin_ws
source devel/setup.bash
roslaunch simple_walker simple_walker.launch
```

## How to record bag files with launch command
The following command can be used to generate a rosbag file in the Results directory with launch command

```
roslaunch simple_walker simple_walker.launch record:=enable
```

The generated bag file contains recorded messages published to all topics except /camera which can be played back later.

## How to inspect rosbag file
To get more information about the generated rosbag file, go to the Results directory and run the following command

```
rosbag info sim.bag
```

## How to play a rosbag file  
The generated rosbag file can also be used to play the recorded messages.Open a terminal window 

```
roscore
```

Open a new terminal window.Go to the results directory and run the following command

```
rosbag play sim.bag
```
Note: Gazebo should not be running

