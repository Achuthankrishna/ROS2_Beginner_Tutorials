/**
 * @file s_main.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief Main subscriber file
 * @version 0.1
 * @date 2023-11-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "../include/ROS2_Beginner_Tutorials/subscriber_func.hpp"
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
