// Generated by gencpp from file xarm_planner/joint_plan.msg
// DO NOT EDIT!


#ifndef XARM_PLANNER_MESSAGE_JOINT_PLAN_H
#define XARM_PLANNER_MESSAGE_JOINT_PLAN_H

#include <ros/service_traits.h>


#include <xarm_planner/joint_planRequest.h>
#include <xarm_planner/joint_planResponse.h>


namespace xarm_planner
{

struct joint_plan
{

typedef joint_planRequest Request;
typedef joint_planResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct joint_plan
} // namespace xarm_planner


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_planner::joint_plan > {
  static const char* value()
  {
    return "80c5e1dbd8cca88d8f7d1c0e51bf50cf";
  }

  static const char* value(const ::xarm_planner::joint_plan&) { return value(); }
};

template<>
struct DataType< ::xarm_planner::joint_plan > {
  static const char* value()
  {
    return "xarm_planner/joint_plan";
  }

  static const char* value(const ::xarm_planner::joint_plan&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_planner::joint_planRequest> should match 
// service_traits::MD5Sum< ::xarm_planner::joint_plan > 
template<>
struct MD5Sum< ::xarm_planner::joint_planRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_planner::joint_plan >::value();
  }
  static const char* value(const ::xarm_planner::joint_planRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_planner::joint_planRequest> should match 
// service_traits::DataType< ::xarm_planner::joint_plan > 
template<>
struct DataType< ::xarm_planner::joint_planRequest>
{
  static const char* value()
  {
    return DataType< ::xarm_planner::joint_plan >::value();
  }
  static const char* value(const ::xarm_planner::joint_planRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_planner::joint_planResponse> should match 
// service_traits::MD5Sum< ::xarm_planner::joint_plan > 
template<>
struct MD5Sum< ::xarm_planner::joint_planResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_planner::joint_plan >::value();
  }
  static const char* value(const ::xarm_planner::joint_planResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_planner::joint_planResponse> should match 
// service_traits::DataType< ::xarm_planner::joint_plan > 
template<>
struct DataType< ::xarm_planner::joint_planResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_planner::joint_plan >::value();
  }
  static const char* value(const ::xarm_planner::joint_planResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_PLANNER_MESSAGE_JOINT_PLAN_H
