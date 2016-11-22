# arduino-ros-examples
Set of examples of to learn the interface between ROS and Arduino

## Dependecies
To run the examples you need both the [Arduino](https://www.arduino.cc) and [ROS Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu), as well as two extra packages not shipped with the ROS Desktop-full installation:
```shell 
$ sudo apt-get install ros-kinetic-rosserial-arduino
$ sudo apt-get install ros-kinetic-rosserial-python
```
*Note: Examples also run correctly with ROS Indigo*

## Setting Up
The first time you need to call a python script that will generate the necessary code for the Arduino. 
```shell 
$ cd your-arduino-sketchbook/libraries
$ rosrun rosserial_arduino make_libraries.py .
```

*Note: In case you later generate (and install!) a new custom ROS message, or you install a new package with new messages, you will need to run again this script.*

## Running
1. Complie and Load The Arduino code to your board with the Arduino IDE
2. Execute the launch file: 
```shell 
$ roslaunch arduino_ros_examples oscillator.launch
```

Configurable frequency in a sine wave

There is a new file, called oscillator_configurable.ino, which is the same of old file but in this, you can configure the frequency in real time with a simple command on a new terminal.

1- Verify and upload the new code on Arduino IDE

2- Run the launch file:

$ roslaunch arduino_ros_examples oscillator.launch

(Default value of frequency is 50Hz)

3- Then, you can see the sine wave plot in rqt, if you not see this, write on form:

/wave/data

4- If you want to change frequency value, substitute <frequency> in a new value:

$ rostopic pub /freq std_msgs/UInt16 <frequency>

And then, the plot changes automatically the frequency sine wave.

