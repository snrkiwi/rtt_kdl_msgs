#include <orocos/kdl_msgs/boost/Frame.h>
#include <orocos/kdl_msgs/boost/FrameStamped.h>
#include <orocos/kdl_msgs/boost/JntArray.h>
#include <orocos/kdl_msgs/boost/JntArrayStamped.h>
#include <orocos/kdl_msgs/boost/Rotation.h>
#include <orocos/kdl_msgs/boost/RotationStamped.h>
#include <orocos/kdl_msgs/boost/Twist.h>
#include <orocos/kdl_msgs/boost/TwistStamped.h>
#include <orocos/kdl_msgs/boost/Vector.h>
#include <orocos/kdl_msgs/boost/VectorStamped.h>
#include <orocos/kdl_msgs/boost/Wrench.h>
#include <orocos/kdl_msgs/boost/WrenchStamped.h>

#include <rtt_roscomm/rtt_rostopic_ros_msg_transporter.hpp>
#include <rtt_roscomm/rtt_rostopic.h>
#include <rtt/types/TransportPlugin.hpp>
#include <rtt/types/TypekitPlugin.hpp>

namespace rtt_roscomm {
  using namespace RTT;
    struct ROSkdl_msgsPlugin
      : public types::TransportPlugin
    {
      bool registerTransport(std::string name, types::TypeInfo* ti)
      {
          if(name == "KDL.Frame") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<KDL::Frame>());} else
          if(name == "/kdl_msgs/FrameStamped") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<kdl_msgs::FrameStamped>());} else
          if(name == "KDL.JntArray") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<KDL::JntArray>());} else
          if(name == "/kdl_msgs/JntArrayStamped") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<kdl_msgs::JntArrayStamped>());} else
          if(name == "KDL.Rotation") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<KDL::Rotation>());} else
          if(name == "/kdl_msgs/RotationStamped") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<kdl_msgs::RotationStamped>());} else
          if(name == "KDL.Twist") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<KDL::Twist>());} else
          if(name == "/kdl_msgs/TwistStamped") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<kdl_msgs::TwistStamped>());} else
          if(name == "KDL.Vector") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<KDL::Vector>());} else
          if(name == "/kdl_msgs/VectorStamped") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<kdl_msgs::VectorStamped>());} else
          if(name == "KDL.Wrench") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<KDL::Wrench>());} else
          if(name == "/kdl_msgs/WrenchStamped") { return ti->addProtocol(ORO_ROS_PROTOCOL_ID,new RosMsgTransporter<kdl_msgs::WrenchStamped>());} else
          { }
          return false;
      }
      
      std::string getTransportName() const {
          return "ros";
      }
      
      std::string getTypekitName() const {
          return std::string("ros-")+"kdl_msgs";
      }
      std::string getName() const {
          return std::string("rtt-ros-") + "kdl_msgs" + "-transport";
      }

    };
}

ORO_TYPEKIT_PLUGIN( rtt_roscomm::ROSkdl_msgsPlugin )
