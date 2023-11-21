/**
 * @file p_main.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief Main file for publisher call
 * @version 0.1
 * @date 2023-11-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>

#include "../include/ROS2_Beginner_Tutorials/publisher_func.hpp"
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
