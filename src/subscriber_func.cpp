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

void MinimalSubscriber::topic_callback(const std_msgs::msg::String
                                        & msg) const {
      //DEBUG FOR ERROR
      RCLCPP_DEBUG(this->get_logger(), "Debugging Once  %s", msg.data.c_str());
      if (msg.data.empty()) {
        // Log a warning if it's empty
        RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Empty message data!");
      }
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
      RCLCPP_FATAL_ONCE(this->get_logger(), "FATAL LOG CHECK");
}


