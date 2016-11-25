#include <kdl_msgs/boost/Frame.h>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/StructTypeInfo.hpp>
#include <rtt/types/PrimitiveSequenceTypeInfo.hpp>
#include <rtt/types/CArrayTypeInfo.hpp>
#include <vector>

// Note: we need to put these up-front or we get gcc compiler warnings:
// <<warning: type attributes ignored after type is already defined>>        
template class RTT_EXPORT RTT::internal::DataSourceTypeInfo< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::internal::DataSource< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::internal::AssignableDataSource< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::internal::AssignCommand< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::internal::ValueDataSource< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::internal::ConstantDataSource< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::internal::ReferenceDataSource< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::OutputPort< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::InputPort< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::Property< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::Attribute< kdl_msgs::Frame >;
template class RTT_EXPORT RTT::Constant< kdl_msgs::Frame >;

namespace rtt_roscomm {
  using namespace RTT;
    // Factory function
    
      void rtt_ros_addType_kdl_msgs_Frame() {
          types::TypeInfo *ti = types::Types()->getTypeInfo< ::KDL::Frame >();
          if (!ti) {
              log(Error) << "The kdl_typekit package has to be imported before rtt_kdl_msgs." << endlog();
              return;
          }
          ti->addAlias("/kdl_msgs/Frame");
          ti->addTypeAlias<kdl_msgs::Frame>();

          // Only the .msg type is sent over ports. The msg[] (variable size) and  cmsg[] (fixed size) exist only as members of larger messages
          RTT::types::Types()->addType( new types::PrimitiveSequenceTypeInfo<std::vector<kdl_msgs::Frame> >("/kdl_msgs/Frame[]") );
          RTT::types::Types()->addType( new types::CArrayTypeInfo<RTT::types::carray<kdl_msgs::Frame> >("/kdl_msgs/cFrame[]") );
      }

    
}
