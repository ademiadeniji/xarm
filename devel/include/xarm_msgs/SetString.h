// Generated by gencpp from file xarm_msgs/SetString.msg
// DO NOT EDIT!


#ifndef XARM_MSGS_MESSAGE_SETSTRING_H
#define XARM_MSGS_MESSAGE_SETSTRING_H

#include <ros/service_traits.h>


#include <xarm_msgs/SetStringRequest.h>
#include <xarm_msgs/SetStringResponse.h>


namespace xarm_msgs
{

struct SetString
{

typedef SetStringRequest Request;
typedef SetStringResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetString
} // namespace xarm_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_msgs::SetString > {
  static const char* value()
  {
    return "8ef44a329258a19c2b77a7a598761c55";
  }

  static const char* value(const ::xarm_msgs::SetString&) { return value(); }
};

template<>
struct DataType< ::xarm_msgs::SetString > {
  static const char* value()
  {
    return "xarm_msgs/SetString";
  }

  static const char* value(const ::xarm_msgs::SetString&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_msgs::SetStringRequest> should match 
// service_traits::MD5Sum< ::xarm_msgs::SetString > 
template<>
struct MD5Sum< ::xarm_msgs::SetStringRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::SetString >::value();
  }
  static const char* value(const ::xarm_msgs::SetStringRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::SetStringRequest> should match 
// service_traits::DataType< ::xarm_msgs::SetString > 
template<>
struct DataType< ::xarm_msgs::SetStringRequest>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::SetString >::value();
  }
  static const char* value(const ::xarm_msgs::SetStringRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_msgs::SetStringResponse> should match 
// service_traits::MD5Sum< ::xarm_msgs::SetString > 
template<>
struct MD5Sum< ::xarm_msgs::SetStringResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::SetString >::value();
  }
  static const char* value(const ::xarm_msgs::SetStringResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::SetStringResponse> should match 
// service_traits::DataType< ::xarm_msgs::SetString > 
template<>
struct DataType< ::xarm_msgs::SetStringResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::SetString >::value();
  }
  static const char* value(const ::xarm_msgs::SetStringResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_MSGS_MESSAGE_SETSTRING_H