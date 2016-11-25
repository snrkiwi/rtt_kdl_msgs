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

#include <rtt/deployment/ComponentLoader.hpp>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/StructTypeInfo.hpp>

namespace rtt_roscomm {
  using namespace RTT;

    /** Declare all factory functions */
            void rtt_ros_addType_kdl_msgs_Frame();
        void rtt_ros_addType_kdl_msgs_FrameStamped();
        void rtt_ros_addType_kdl_msgs_JntArray();
        void rtt_ros_addType_kdl_msgs_JntArrayStamped();
        void rtt_ros_addType_kdl_msgs_Rotation();
        void rtt_ros_addType_kdl_msgs_RotationStamped();
        void rtt_ros_addType_kdl_msgs_Twist();
        void rtt_ros_addType_kdl_msgs_TwistStamped();
        void rtt_ros_addType_kdl_msgs_Vector();
        void rtt_ros_addType_kdl_msgs_VectorStamped();
        void rtt_ros_addType_kdl_msgs_Wrench();
        void rtt_ros_addType_kdl_msgs_WrenchStamped();

   
    /**
     * This interface defines the types of the realTime package.
     */
    class ROSkdl_msgsTypekitPlugin
      : public types::TypekitPlugin
    {
    public:
      virtual std::string getName(){
          return std::string("ros-")+"kdl_msgs";
      }

      virtual bool loadTypes() {
          // Try to import the kdl_typekit for the case it is not yet loaded.
          ComponentLoader::Instance()->import("kdl_typekit", "");

          // call all factory functions
          rtt_ros_addType_kdl_msgs_Frame(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_FrameStamped(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_JntArray(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_JntArrayStamped(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_Rotation(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_RotationStamped(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_Twist(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_TwistStamped(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_Vector(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_VectorStamped(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_Wrench(); // factory function for adding TypeInfo.
          rtt_ros_addType_kdl_msgs_WrenchStamped(); // factory function for adding TypeInfo.

          return true;
      }

      virtual bool loadOperators() { return true; }
      virtual bool loadConstructors() { return true; }
    };
}

ORO_TYPEKIT_PLUGIN( rtt_roscomm::ROSkdl_msgsTypekitPlugin )

