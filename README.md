# multisearch_sim
A Repository of ROS Packages for a multi-robot simulation in gazebo-ROS with many use cases.

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
