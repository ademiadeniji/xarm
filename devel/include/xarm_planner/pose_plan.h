// Generated by gencpp from file xarm_planner/pose_plan.msg
// DO NOT EDIT!


#ifndef XARM_PLANNER_MESSAGE_POSE_PLAN_H
#define XARM_PLANNER_MESSAGE_POSE_PLAN_H

#include <ros/service_traits.h>


#include <xarm_planner/pose_planRequest.h>
#include <xarm_planner/pose_planResponse.h>


namespace xarm_planner
{

struct pose_plan
{

typedef pose_planRequest Request;
typedef pose_planResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct pose_plan
} // namespace xarm_planner


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xarm_planner::pose_plan > {
  static const char* value()
  {
    return "9b6cd400aefab13efff1a5082333de0f";
  }

  static const char* value(const ::xarm_planner::pose_plan&) { return value(); }
};

template<>
struct DataType< ::xarm_planner::pose_plan > {
  static const char* value()
  {
    return "xarm_planner/pose_plan";
  }

  static const char* value(const ::xarm_planner::pose_plan&) { return value(); }
};


// service_traits::MD5Sum< ::xarm_planner::pose_planRequest> should match 
// service_traits::MD5Sum< ::xarm_planner::pose_plan > 
template<>
struct MD5Sum< ::xarm_planner::pose_planRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_planner::pose_plan >::value();
  }
  static const char* value(const ::xarm_planner::pose_planRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_planner::pose_planRequest> should match 
// service_traits::DataType< ::xarm_planner::pose_plan > 
template<>
struct DataType< ::xarm_planner::pose_planRequest>
{
  static const char* value()
  {
    return DataType< ::xarm_planner::pose_plan >::value();
  }
  static const char* value(const ::xarm_planner::pose_planRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xarm_planner::pose_planResponse> should match 
// service_traits::MD5Sum< ::xarm_planner::pose_plan > 
template<>
struct MD5Sum< ::xarm_planner::pose_planResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xarm_planner::pose_plan >::value();
  }
  static const char* value(const ::xarm_planner::pose_planResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xarm_planner::pose_planResponse> should match 
// service_traits::DataType< ::xarm_planner::pose_plan > 
template<>
struct DataType< ::xarm_planner::pose_planResponse>
{
  static const char* value()
  {
    return DataType< ::xarm_planner::pose_plan >::value();
  }
  static const char* value(const ::xarm_planner::pose_planResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XARM_PLANNER_MESSAGE_POSE_PLAN_H
