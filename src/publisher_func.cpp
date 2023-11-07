/**
 * @file ROS2 PUBLISHER
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief Publisher in ROS2
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../include/ROS2_Beginner_Tutorials/publisher_func.hpp"

void MinimalPublisher::timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }