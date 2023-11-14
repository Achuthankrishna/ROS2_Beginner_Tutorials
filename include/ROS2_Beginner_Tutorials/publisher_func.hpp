/**
 * @file publisher_func.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "ros2_beginner_tutorials/srv/change_string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher();

private:
    void timer_callback();
    void service_callback(const std::shared_ptr<ros2_beginner_tutorials::srv::ChangeString::Request> request,
                          std::shared_ptr<ros2_beginner_tutorials::srv::ChangeString::Response> response);

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
    std_msgs::msg::String message;
    rclcpp::Service<ros2_beginner_tutorials::srv::ChangeString>::SharedPtr service_;
};
