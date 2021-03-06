// Generated by gencpp from file xarm_msgs/MoveVelocity.msg
// DO NOT EDIT!


#ifndef XARM_MSGS_MESSAGE_MOVEVELOCITY_H
#define XARM_MSGS_MESSAGE_MOVEVELOCITY_H

#include <ros/service_traits.h>


#include <xarm_msgs/MoveVelocityRequest.h>
#include <xarm_msgs/MoveVelocityResponse.h>


namespace xarm_msgs
{

struct MoveVelocity
{

typedef MoveVelocityRequest Request;
typedef MoveVelocityResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveVelocity
} // namespace xarm_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_msgs::MoveVelocity > {
  static const char* value()
  {
    return "ba6e5e4cb25baf01712a273c753becc6";
  }

  static const char* value(const ::xarm_msgs::MoveVelocity&) { return value(); }
};

template<>
struct DataType< ::xarm_msgs::MoveVelocity > {
  static const char* value()
  {
    return "xarm_msgs/MoveVelocity";
  }

  static const char* value(const ::xarm_msgs::MoveVelocity&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_msgs::MoveVelocityRequest> should match 
// service_traits::MD5Sum< ::xarm_msgs::MoveVelocity > 
template<>
struct MD5Sum< ::xarm_msgs::MoveVelocityRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::MoveVelocity >::value();
  }
  static const char* value(const ::xarm_msgs::MoveVelocityRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::MoveVelocityRequest> should match 
// service_traits::DataType< ::xarm_msgs::MoveVelocity > 
template<>
struct DataType< ::xarm_msgs::MoveVelocityRequest>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::MoveVelocity >::value();
  }
  static const char* value(const ::xarm_msgs::MoveVelocityRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_msgs::MoveVelocityResponse> should match 
// service_traits::MD5Sum< ::xarm_msgs::MoveVelocity > 
template<>
struct MD5Sum< ::xarm_msgs::MoveVelocityResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::MoveVelocity >::value();
  }
  static const char* value(const ::xarm_msgs::MoveVelocityResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::MoveVelocityResponse> should match 
// service_traits::DataType< ::xarm_msgs::MoveVelocity > 
template<>
struct DataType< ::xarm_msgs::MoveVelocityResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::MoveVelocity >::value();
  }
  static const char* value(const ::xarm_msgs::MoveVelocityResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_MSGS_MESSAGE_MOVEVELOCITY_H
