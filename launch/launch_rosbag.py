"""
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
"""
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import TextSubstitution
from launch.substitutions import LaunchConfiguration
from launch.actions import ExecuteProcess
from launch.conditions import IfCondition

def generate_launch_description():
    change_msg=DeclareLaunchArgument('new_mesg',default_value='I am updating to Iron Ironwiyi')
    rbag=DeclareLaunchArgument('bag_record',default_value=TextSubstitution(text="True"),choices=['True','False'],description="Recording ROS bag")

    return LaunchDescription([

        Node(
            package='ros2_beginner_tutorials',
            executable='talker',
            parameters=[
                {"new_mesg":LaunchConfiguration('new_mesg')}

            ]
        ),
        Node(
            package='ros2_beginner_tutorials',
            executable='listener'
        ),
        # ),
        ExecuteProcess(
            condition=IfCondition(LaunchConfiguration('bag_record')),
            cmd=['ros2', 'bag', 'record', '-a', '--output', "./src/ROS2_Beginner_Tutorials/Results/Bags"],
            shell=True
        )
    ])