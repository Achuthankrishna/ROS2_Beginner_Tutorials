/**
 * @file subscriber_func.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief Subscriber function
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../include/ROS2_Beginner_Tutorials/subscriber_func.hpp"

void MinimalSubscriber::topic_callback(const std_msgs::msg::String & msg) const
{
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
}

