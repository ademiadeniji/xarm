// Generated by gencpp from file xarm_msgs/GetDigitalIO.msg
// DO NOT EDIT!


#ifndef XARM_MSGS_MESSAGE_GETDIGITALIO_H
#define XARM_MSGS_MESSAGE_GETDIGITALIO_H

#include <ros/service_traits.h>


#include <xarm_msgs/GetDigitalIORequest.h>
#include <xarm_msgs/GetDigitalIOResponse.h>


namespace xarm_msgs
{

struct GetDigitalIO
{

typedef GetDigitalIORequest Request;
typedef GetDigitalIOResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetDigitalIO
} // namespace xarm_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_msgs::GetDigitalIO > {
  static const char* value()
  {
    return "5c2bfd923228c71a217e97a1d1747b99";
  }

  static const char* value(const ::xarm_msgs::GetDigitalIO&) { return value(); }
};

template<>
struct DataType< ::xarm_msgs::GetDigitalIO > {
  static const char* value()
  {
    return "xarm_msgs/GetDigitalIO";
  }

  static const char* value(const ::xarm_msgs::GetDigitalIO&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_msgs::GetDigitalIORequest> should match 
// service_traits::MD5Sum< ::xarm_msgs::GetDigitalIO > 
template<>
struct MD5Sum< ::xarm_msgs::GetDigitalIORequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::GetDigitalIO >::value();
  }
  static const char* value(const ::xarm_msgs::GetDigitalIORequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::GetDigitalIORequest> should match 
// service_traits::DataType< ::xarm_msgs::GetDigitalIO > 
template<>
struct DataType< ::xarm_msgs::GetDigitalIORequest>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::GetDigitalIO >::value();
  }
  static const char* value(const ::xarm_msgs::GetDigitalIORequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_msgs::GetDigitalIOResponse> should match 
// service_traits::MD5Sum< ::xarm_msgs::GetDigitalIO > 
template<>
struct MD5Sum< ::xarm_msgs::GetDigitalIOResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::GetDigitalIO >::value();
  }
  static const char* value(const ::xarm_msgs::GetDigitalIOResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::GetDigitalIOResponse> should match 
// service_traits::DataType< ::xarm_msgs::GetDigitalIO > 
template<>
struct DataType< ::xarm_msgs::GetDigitalIOResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::GetDigitalIO >::value();
  }
  static const char* value(const ::xarm_msgs::GetDigitalIOResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_MSGS_MESSAGE_GETDIGITALIO_H
