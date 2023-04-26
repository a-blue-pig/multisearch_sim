# multisearch_sim
A Repository of ROS Packages for a multi-robot simulation in gazebo-ROS with many use cases.


## Dependencies
```
sudo apt-get install ros-melodic-turtlebot3-msgs
```

## Clone & Build

```
cd catkin_ws/src
git clone git@github.com:Ryangupta8/multisearch_sim.git
source ../devel/setup.bash
sudo apt install qt5-default libqt5websockets5-dev libgoogle-glog-dev libgflags-dev
cd catkin_ws/src/multisearch_sim/enml && ./InstallPackages
cd catkin_ws/src/multisearch_sim && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
cd amrl_msgs && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH 
make
cd ..
make
cd vector_display && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
make
catkin build
```

## Usage

# ENML Labeld Data Collection
At the moment this repository is being set up for DAQ for training 2D Lidar Segmentation. 
Terminal 1: Run Gazebo Sim for Tbot
```
source catkin_ws/devel/setup.bash
roslaunch turtlebot3_gazebo turtlebot3_world.launch
```
Terminal 2: Run Tbot Navigation
```
source catkin_ws/devel/setup.bash
roslaunch turtlebot3_navigation turtlebot3_navigation.launch
```
Terminal 3: Run Vector Display and ENML
```
source catkin_ws/devel/setup.bash
cd catkin_ws/src/multisearch_sim/
export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
cd amrl_msgs && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
cd ../vector_display && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
roslaunch multisearch_sim tbot-enml.launch
```
Terminal 4: Rosbag to collect the data
```
source catkin_ws/deve/setup.bash
rosbag r
```

# Editing Vectormaps using vector display
NOTE: LAUNCH THE tbot-enml.launch script above first, localize the tbot in ENML using
shift+click and drag and THEN ```rosnode kill /vector_display```
After you have done this, then:
```
source catkin_ws/devel/setup.bash
cd multisearch_sim
export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
cd amrl_msgs && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
cd ../vector_display && export ROS_PACKAGE_PATH=`pwd`:$ROS_PACKAGE_PATH
./bin/vector_display --map office_cpr --edit_localization=true
```
Shift+click and drag to add lines to the map
Ctrl+click to remove lines from the map



Third Party References (Cite if using this repository):
Implementation in C++ of Episodic non-Markov Localization [[pdf]](https://www.joydeepb.com/Publications/ras_episodic_nonmarkov_localization.pdf).
Please cite this work using the following bibtex:
```
@article{biswas2016episodic,
  author = { Joydeep Biswas and Manuela M. Veloso },
  url = { https://www.joydeepb.com/Publications/ras_episodic_nonmarkov_localization.pdf },
  doi = { 10.1016/j.robot.2016.09.005 },
  issn = { 0921-8890 },
  year = { 2017 },
  pages = { 162 - 176 },
  volume = { 87 },
  journal = { Robotics and Autonomous Systems  },
  title = { Episodic non-Markov localization },
}
```


Current version:
1) Turtlebot3 ros code from https://github.com/ROBOTIS-GIT/turtlebot3
2) a map launch for launching the 2D global occupoancy map 
```multisearch_sim/launch/map.launch```
Note that we can change the map we load using that script by replacing the path arg in the launch file
3) Folders for ros maps (pgm + yaml) and vectormaps (.txt)

To change between different gazebo worlds, you can change the ```world_name``` arg in
```
turtlebot3_simulations/turtlebot3_gazebo/launch/turtlebot3_world.launch
```

To change between different ROS maps (after we make them for new gazebo worlds) and test that simulation 
works in our env we can change the ```map_file``` argument in
```
turtlebot3_simulations/turtlebot3_navigation/launch/turtlebot3_navigation.launch
```
