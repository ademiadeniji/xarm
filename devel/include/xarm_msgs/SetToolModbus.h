// Generated by gencpp from file xarm_msgs/SetToolModbus.msg
// DO NOT EDIT!


#ifndef XARM_MSGS_MESSAGE_SETTOOLMODBUS_H
#define XARM_MSGS_MESSAGE_SETTOOLMODBUS_H

#include <ros/service_traits.h>


#include <xarm_msgs/SetToolModbusRequest.h>
#include <xarm_msgs/SetToolModbusResponse.h>


namespace xarm_msgs
{

struct SetToolModbus
{

typedef SetToolModbusRequest Request;
typedef SetToolModbusResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetToolModbus
} // namespace xarm_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_msgs::SetToolModbus > {
  static const char* value()
  {
    return "0b8299eb42a5262c78587a39fca90c6d";
  }

  static const char* value(const ::xarm_msgs::SetToolModbus&) { return value(); }
};

template<>
struct DataType< ::xarm_msgs::SetToolModbus > {
  static const char* value()
  {
    return "xarm_msgs/SetToolModbus";
  }

  static const char* value(const ::xarm_msgs::SetToolModbus&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_msgs::SetToolModbusRequest> should match 
// service_traits::MD5Sum< ::xarm_msgs::SetToolModbus > 
template<>
struct MD5Sum< ::xarm_msgs::SetToolModbusRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::SetToolModbus >::value();
  }
  static const char* value(const ::xarm_msgs::SetToolModbusRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::SetToolModbusRequest> should match 
// service_traits::DataType< ::xarm_msgs::SetToolModbus > 
template<>
struct DataType< ::xarm_msgs::SetToolModbusRequest>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::SetToolModbus >::value();
  }
  static const char* value(const ::xarm_msgs::SetToolModbusRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_msgs::SetToolModbusResponse> should match 
// service_traits::MD5Sum< ::xarm_msgs::SetToolModbus > 
template<>
struct MD5Sum< ::xarm_msgs::SetToolModbusResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_msgs::SetToolModbus >::value();
  }
  static const char* value(const ::xarm_msgs::SetToolModbusResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_msgs::SetToolModbusResponse> should match 
// service_traits::DataType< ::xarm_msgs::SetToolModbus > 
template<>
struct DataType< ::xarm_msgs::SetToolModbusResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_msgs::SetToolModbus >::value();
  }
  static const char* value(const ::xarm_msgs::SetToolModbusResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_MSGS_MESSAGE_SETTOOLMODBUS_H