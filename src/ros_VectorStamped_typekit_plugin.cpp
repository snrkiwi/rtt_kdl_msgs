#include <kdl_msgs/boost/VectorStamped.h>
#include <rtt/types/TypekitPlugin.hpp>
#include <rtt/types/StructTypeInfo.hpp>
#include <rtt/types/PrimitiveSequenceTypeInfo.hpp>
#include <rtt/types/CArrayTypeInfo.hpp>
#include <vector>

// Note: we need to put these up-front or we get gcc compiler warnings:
// <<warning: type attributes ignored after type is already defined>>        
template class RTT_EXPORT RTT::internal::DataSourceTypeInfo< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::internal::DataSource< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::internal::AssignableDataSource< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::internal::AssignCommand< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::internal::ValueDataSource< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::internal::ConstantDataSource< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::internal::ReferenceDataSource< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::OutputPort< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::InputPort< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::Property< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::Attribute< kdl_msgs::VectorStamped >;
template class RTT_EXPORT RTT::Constant< kdl_msgs::VectorStamped >;

namespace rtt_roscomm {
  using namespace RTT;
    // Factory function
    
      void rtt_ros_addType_kdl_msgs_VectorStamped() {
           // Only the .msg type is sent over ports. The msg[] (variable size) and  cmsg[] (fixed size) exist only as members of larger messages
           RTT::types::Types()->addType( new types::StructTypeInfo<kdl_msgs::VectorStamped>("/kdl_msgs/VectorStamped") );
           RTT::types::Types()->addType( new types::PrimitiveSequenceTypeInfo<std::vector<kdl_msgs::VectorStamped> >("/kdl_msgs/VectorStamped[]") );
           RTT::types::Types()->addType( new types::CArrayTypeInfo<RTT::types::carray<kdl_msgs::VectorStamped> >("/kdl_msgs/cVectorStamped[]") );
      }

    
}

