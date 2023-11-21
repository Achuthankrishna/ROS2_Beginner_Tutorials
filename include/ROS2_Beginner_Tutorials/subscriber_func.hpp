/**
 * @file subscriber_func.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief
 * @version 0.1
 * @date 2023-11-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
using std::placeholders::_1;
using namespace std::chrono_literals;
/**
 * @brief Subscriber Class
 *
 */
class MinimalSubscriber : public rclcpp::Node {
 public:
  MinimalSubscriber() : Node("minimal_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

 private:
  void topic_callback(const std_msgs::msg::String& msg) const;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};
