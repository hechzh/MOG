#include "rosbagsubscriber.h"
#include <iostream>

#include <time.h>

#include "ros/ros.h"
#include "ros/console.h"
#include "nav_msgs/MapMetaData.h"

#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH
rosbagsubscriber::rosbagsubscriber()
{
    init();
}
rosbagsubscriber::rosbagsubscriber(ros::NodeHandle& nh):node_(nh)
{
    init();
}
void rosbagsubscriber::init() {

}
void rosbagsubscriber::startLiveSlam()
{
//entropy_publisher_ = private_nh_.advertise<std_msgs::Float64>("entropy", 1, true);
//sst_ = node_.advertise<nav_msgs::OccupancyGrid>("map", 1, true);
//sstm_ = node_.advertise<nav_msgs::MapMetaData>("map_metadata", 1, true);
//ss_ = node_.advertiseService("dynamic_map", &rosbagsubscriber::mapCallback, this);
scan_filter_sub_ = new message_filters::Subscriber<sensor_msgs::LaserScan>(node_, "scan", 5);
scan_filter_ = new tf::MessageFilter<sensor_msgs::LaserScan>(*scan_filter_sub_, tf_, "base_odom", 5);
scan_filter_->registerCallback(boost::bind(&rosbagsubscriber::laserCallback, this, _1));

transform_thread_ = new boost::thread(boost::bind(&rosbagsubscriber::publishLoop, this, transform_publish_period_));
}
void rosbagsubscriber::laserCallback(const sensor_msgs::LaserScan::ConstPtr &scan) {
    std::cout<<(double)((*scan).range_min)<<std::endl;
}
void rosbagsubscriber::publishLoop(double transform_publish_period) {
    if(transform_publish_period == 0)
        return;
    ros::Rate r(1.0 / transform_publish_period);
    while(ros::ok()){
        publishTransform();
        r.sleep();
    }
}
void rosbagsubscriber::publishTransform() {
    std::cout << "publish loop success" << std::endl;
}
rosbagsubscriber::~rosbagsubscriber()
{
    if(transform_thread_){
        transform_thread_->join();
        delete transform_thread_;
    }

    //delete gsp_;
    //if(gsp_laser_)
    //    delete gsp_laser_;
    //if(gsp_odom_)
    //    delete gsp_odom_;
    if (scan_filter_)
        delete scan_filter_;
    if (scan_filter_sub_)
        delete scan_filter_sub_;
}