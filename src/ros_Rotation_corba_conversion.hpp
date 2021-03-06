#ifndef __ROS_kdl_msgs_Rotation_CORBA_CONVERSION__
#define __ROS_kdl_msgs_Rotation_CORBA_CONVERSION__

#include <kdl_msgs/Rotation.h>

#include <rtt_roscomm/rtt_rostopic_ros_msg_transporter.hpp>
#include <rtt_roscomm/rostopic.h>
#include <rtt/Logger.hpp>
#include <rtt/types/TransportPlugin.hpp>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/transports/corba/RTTCorbaConversion.hpp>
#include <sstream>
#include <ros/serialization.h>

namespace RTT
{
  namespace corba{

    template<>
    struct AnyConversion< kdl_msgs::Rotation >
    {
      typedef CORBA::OctetSeq CorbaType;
      typedef kdl_msgs::Rotation StdType;

      static CorbaType* toAny(const StdType& tp) {
        CorbaType* cb = new CorbaType();
        toCorbaType(*cb, tp);
        return cb;
      }

      static bool update(const CORBA::Any& any, StdType& _value) {
        CorbaType* result;
        if ( any >>= result ) {
          return toStdType(_value, *result);
        }
        return false;
      }

      static CORBA::Any_ptr createAny( const StdType& t ) {
        CORBA::Any_ptr ret = new CORBA::Any();
        *ret <<= toAny( t );
        return ret;
      }

      static bool updateAny( StdType const& t, CORBA::Any& any ) {
        any <<= toAny( t );
        return true;
      }

      static bool toCorbaType(CorbaType& cb, const StdType& tp){
        try {
          cb.length(ros::serialization::serializationLength(tp));
          ros::serialization::OStream s(static_cast<uint8_t *>(cb.get_buffer()), static_cast<uint32_t>(cb.length()));
          ros::serialization::serialize(s, tp);
        } catch(ros::serialization::StreamOverrunException& e) {
          RTT::log(RTT::Error) << "StreamOverrunException during serialization of " << ros::message_traits::datatype(tp) << ": "
                               << e.what() << RTT::endlog();
          return false;
        }

        return true;
      }
    
      static bool toStdType(StdType& tp, const CorbaType& cb){
        if(cb.length() == 0){
          return false;
        }

        try {
          ros::serialization::IStream s(const_cast<uint8_t*>(cb.get_buffer()), static_cast<uint32_t>(cb.length()));
          ros::serialization::deserialize(s, tp);
        } catch(ros::serialization::StreamOverrunException& e) {
          RTT::log(RTT::Error) << "StreamOverrunException during deserialization of " << ros::message_traits::datatype(tp) << ": "
                               << e.what() << RTT::endlog();
          return false;
        }

        return true;
      }

    };
  }
}


#endif
