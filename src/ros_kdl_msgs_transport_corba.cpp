//#include "ros_Frame_corba_conversion.hpp"
#include "ros_FrameStamped_corba_conversion.hpp"
//#include "ros_JntArray_corba_conversion.hpp"
#include "ros_JntArrayStamped_corba_conversion.hpp"
//#include "ros_Rotation_corba_conversion.hpp"
#include "ros_RotationStamped_corba_conversion.hpp"
//#include "ros_Twist_corba_conversion.hpp"
#include "ros_TwistStamped_corba_conversion.hpp"
//#include "ros_Vector_corba_conversion.hpp"
#include "ros_VectorStamped_corba_conversion.hpp"
//#include "ros_Wrench_corba_conversion.hpp"
#include "ros_WrenchStamped_corba_conversion.hpp"

#include <rtt/types/TransportPlugin.hpp>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/transports/corba/CorbaTemplateProtocol.hpp>

namespace RTT {
    namespace corba {
      struct CORBAROSkdl_msgsPlugin : public types::TransportPlugin
      {
        bool registerTransport(std::string name, types::TypeInfo* ti)
        {
            if(name == "/kdl_msgs/FrameStamped") { return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new RTT::corba::CorbaTemplateProtocol<kdl_msgs::FrameStamped>());} else
            if(name == "/kdl_msgs/JntArrayStamped") { return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new RTT::corba::CorbaTemplateProtocol<kdl_msgs::JntArrayStamped>());} else
            if(name == "/kdl_msgs/RotationStamped") { return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new RTT::corba::CorbaTemplateProtocol<kdl_msgs::RotationStamped>());} else
            if(name == "/kdl_msgs/TwistStamped") { return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new RTT::corba::CorbaTemplateProtocol<kdl_msgs::TwistStamped>());} else
            if(name == "/kdl_msgs/VectorStamped") { return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new RTT::corba::CorbaTemplateProtocol<kdl_msgs::VectorStamped>());} else
            if(name == "/kdl_msgs/WrenchStamped") { return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new RTT::corba::CorbaTemplateProtocol<kdl_msgs::WrenchStamped>());} else
            { }
            return false;
        }
        
        std::string getTransportName() const {
            return "CORBA";
        }
        
        std::string getTypekitName() const {
            return std::string("ros-")+"kdl_msgs";
        }
        std::string getName() const {
            return std::string("rtt-ros-") + "kdl_msgs" + "-transport-corba";
        }

      };
    }
}

ORO_TYPEKIT_PLUGIN( RTT::corba::CORBAROSkdl_msgsPlugin )
