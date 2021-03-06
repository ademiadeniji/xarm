// Generated by gencpp from file xarm_msgs/GripperConfig.msg
// DO NOT EDIT!


#ifndef XARM_MSGS_MESSAGE_GRIPPERCONFIG_H
#define XARM_MSGS_MESSAGE_GRIPPERCONFIG_H

#include <ros/service_traits.h>


#include <xarm_msgs/GripperConfigRequest.h>
#include <xarm_msgs/GripperConfigResponse.h>


namespace xarm_msgs
{

struct GripperConfig
{

typedef GripperConfigRequest Request;
typedef GripperConfigResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GripperConfig
} // namespace xarm_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_msgs::GripperConfig > {
  static const char* value()
  {
    return "52f0b064a7be31185f9e28fcaa5260ce";
  }

  static const char* value(const ::xarm_msgs::GripperConfig&) { return value(); }
};

template<>
struct DataType< ::xarm_msgs::GripperConfig > {
  static const char* value()
  {
    return "xarm_msgs/GripperConfig";
  }

  static const char* value(const ::xarm_msgs::GripperConfig&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_msgs::GripperConfigRequest> should match 
// service_traits::MD5Sum< ::xarm_msgs::GripperConfig > 
template<>
struct MD5Sum< ::xarm_msgs::GripperConfigRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::GripperConfig >::value();
  }
  static const char* value(const ::xarm_msgs::GripperConfigRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::GripperConfigRequest> should match 
// service_traits::DataType< ::xarm_msgs::GripperConfig > 
template<>
struct DataType< ::xarm_msgs::GripperConfigRequest>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::GripperConfig >::value();
  }
  static const char* value(const ::xarm_msgs::GripperConfigRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_msgs::GripperConfigResponse> should match 
// service_traits::MD5Sum< ::xarm_msgs::GripperConfig > 
template<>
struct MD5Sum< ::xarm_msgs::GripperConfigResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::GripperConfig >::value();
  }
  static const char* value(const ::xarm_msgs::GripperConfigResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::GripperConfigResponse> should match 
// service_traits::DataType< ::xarm_msgs::GripperConfig > 
template<>
struct DataType< ::xarm_msgs::GripperConfigResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::GripperConfig >::value();
  }
  static const char* value(const ::xarm_msgs::GripperConfigResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_MSGS_MESSAGE_GRIPPERCONFIG_H
