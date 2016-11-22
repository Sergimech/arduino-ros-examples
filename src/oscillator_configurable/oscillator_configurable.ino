/****
 * Oscillator configurable
 **/

//Includes
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif
#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt16.h>

//ROS variables
ros::NodeHandle nh_;
std_msgs::Float32 float_msg_;
ros::Publisher publisher_("wave", &float_msg_);

//Other variables
float angle_ = 0; 
const float PI_ = 3.141592;

//Store a 2 byte value, positive numbers useful range of 0 to 65,535 (2^16) - 1
unsigned int frequency = 50;

void write_freq(const std_msgs::UInt16& cmd_msg)
{
  frequency = cmd_msg.data;
}

//Subscriber
ros::Subscriber<std_msgs::UInt16> sub("freq", write_freq);

//Setup 
void setup()
{ 
    //ROS init and subscribe
    nh_.initNode();
    nh_.advertise(publisher_);
    nh_.subscribe(sub);
}

void loop()
{
    //Increment the angle
    angle_ = angle_ + PI_/100; 
    if (angle_ > 2*PI_) angle_ = angle_ - 2.0*PI_; 

    //Publish
    float_msg_.data = cos(angle_); 
    publisher_.publish(&float_msg_);

    //spin (ros sync and attend callbacks, if any ...)
    nh_.spinOnce();
    
    //relax (50ms)
    delay(frequency);     
}
