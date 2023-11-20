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
#include "geometry_msgs/msg/transform_stamped.hpp"

/**
 * @brief Construct a new Minimal Publisher:: Minimal Publisher object
 * 
 */
MinimalPublisher::MinimalPublisher()
    : Node("minimal_publisher"), count_(0) {
//     std::string new_mesg_param = this->get_parameter("new_mesg").as_string();
    this->declare_parameter<std::string>
                        ("new_mesg",
                        "Hello, I am ROS Humble, the LTS Version :p ! ");
    std::string new_mesg_param = this->get_parameter("new_mesg").as_string();

    if (!new_mesg_param.empty()) {
        message.data = new_mesg_param;
        RCLCPP_ERROR_STREAM (this->get_logger(), "NO NEW MESSAGE");
    } else {
      message.data = "Hello, I am ROS Humble, the LTS Version :p ! ";}
      // message.data = "Hello, I am ROS Humble, the LTS Version :p ! " +
      // std::to_string(count_++);
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    tf_static_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
      this->make_transforms();
    timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::
                                    timer_callback, this));

    auto serviceCallbackPtr = std::bind(&MinimalPublisher::service_callback,
                                    this,
                                    std::placeholders::_1,
                                    std::placeholders::_2);
    service_ = this->create_service<ros2_beginner_tutorials::
      srv::ChangeString>(
      "change_string", serviceCallbackPtr); 
       }

//       MinimalPublisher::tf_static_broadcaster_  =
//     std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

/**
 * @brief Timer Callback
 * 
 */
void MinimalPublisher::timer_callback() {

      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
}

/**
 * @brief Service call
 * 
 * @param request 
 * @param response 
 */
void MinimalPublisher::service_callback(
    const std::shared_ptr<ros2_beginner_tutorials::
    srv::ChangeString::Request> request,
    std::shared_ptr<ros2_beginner_tutorials::
    srv::ChangeString::Response> response) {
    RCLCPP_WARN(rclcpp::get_logger("rclcpp"),
    "Incoming request\nnew_string: %s", request->update.c_str());
    message.data = request->update;
      RCLCPP_DEBUG_STREAM (this->get_logger(), "DEBUG STREAM");
      RCLCPP_ERROR_STREAM (this->get_logger(), "ERROR CHECK");
      RCLCPP_FATAL_STREAM (this->get_logger(), "FATAL CHECK");
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
    response->status = "Changed";
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
    "sending back response: [%s]", response->status.c_str()); }

void MinimalPublisher::make_transforms()
{
      geometry_msgs::msg::TransformStamped t;

      t.header.stamp = this->get_clock()->now();
      t.header.frame_id = "world";
      t.child_frame_id = "talker";

      t.transform.translation.x = 1;
      t.transform.translation.y = 0;
      t.transform.translation.z = 0;
      tf2::Quaternion q;
      q.setRPY(0, 0, 90);
      t.transform.rotation.x = q.x();
      t.transform.rotation.y = q.y();
      t.transform.rotation.z = q.z();
      t.transform.rotation.w = q.w();

      RCLCPP_INFO(this->get_logger(), "Broadcasting transformation from world to talker.");
      RCLCPP_WARN(this->get_logger(), "Broadcasting transformation from world to talker.");

      tf_static_broadcaster_->sendTransform(t);
}