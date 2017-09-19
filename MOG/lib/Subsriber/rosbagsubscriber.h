#include <iostream>
#include <time.h>

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/Float64.h"
#include "nav_msgs/GetMap.h"
#include "tf/transform_listener.h"
#include "tf/transform_broadcaster.h"
#include "message_filters/subscriber.h"
#include "tf/message_filter.h"

//#include "gmapping/gridfastslam/gridslamprocessor.h"
//#include "gmapping/sensor/sensor_base/sensor.h"

#include <boost/thread.hpp>
#ifndef MOG_ROSBAGSUBSCRIBER_H
#define MOG_ROSBAGSUBSCRIBER_H


class rosbagsubscriber {
public:
    rosbagsubscriber();
    rosbagsubscriber(ros::NodeHandle& nh);
    ~rosbagsubscriber();
    void init();
    void startLiveSlam();
    void publishTransform();
    void laserCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
    //bool mapCallback(nav_msgs::GetMap::Request  &req,
    //                 nav_msgs::GetMap::Response &res);
    void publishLoop(double transform_publish_period);
private:
    ros::NodeHandle node_;
    ros::Publisher entropy_publisher_;
    ros::Publisher sst_;
    ros::Publisher sstm_;
    ros::ServiceServer ss_;
    tf::TransformListener tf_;
    message_filters::Subscriber<sensor_msgs::LaserScan>* scan_filter_sub_;
    tf::MessageFilter<sensor_msgs::LaserScan>* scan_filter_;
    tf::TransformBroadcaster* tfB_;
    ros::NodeHandle private_nh_;
    boost::thread* transform_thread_;
    const double transform_publish_period_=1;
    double tf_delay_;
    std::string odom_frame_;
};


#endif //MOG_ROSBAGSUBSCRIBER_H
