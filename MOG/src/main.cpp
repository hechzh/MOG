#include <ros/ros.h>
#include <iostream>

#include "../lib/Hello/Hello.h"
#include "../lib/Subsriber/rosbagsubscriber.h"
using namespace std;
int main(int argc, char** argv){
    cout<<Hello_world()<<endl;
    ros::init(argc, argv,"MOG");
    rosbagsubscriber gn;
    gn.startLiveSlam();
    ros::spin();
    return 0;
}
