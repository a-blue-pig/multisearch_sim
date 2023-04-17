/* Auto-generated by genmsg_cpp for file /home/hcrl-nuc/workspaces/search_ws/src/a1_autonomy/amrl_msgs/msg/ColoredArc2D.msg */
#ifndef AMRL_MSGS_MESSAGE_COLOREDARC2D_H
#define AMRL_MSGS_MESSAGE_COLOREDARC2D_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "amrl_msgs/Point2D.h"

namespace amrl_msgs
{
template <class ContainerAllocator>
struct ColoredArc2D_ {
  typedef ColoredArc2D_<ContainerAllocator> Type;

  ColoredArc2D_()
  : center()
  , radius(0.0)
  , start_angle(0.0)
  , end_angle(0.0)
  , color(0)
  {
  }

  ColoredArc2D_(const ContainerAllocator& _alloc)
  : center(_alloc)
  , radius(0.0)
  , start_angle(0.0)
  , end_angle(0.0)
  , color(0)
  {
  }

  typedef  ::amrl_msgs::Point2D_<ContainerAllocator>  _center_type;
   ::amrl_msgs::Point2D_<ContainerAllocator>  center;

  typedef float _radius_type;
  float radius;

  typedef float _start_angle_type;
  float start_angle;

  typedef float _end_angle_type;
  float end_angle;

  typedef uint32_t _color_type;
  uint32_t color;


  typedef boost::shared_ptr< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::amrl_msgs::ColoredArc2D_<ContainerAllocator>  const> ConstPtr;
}; // struct ColoredArc2D
typedef  ::amrl_msgs::ColoredArc2D_<std::allocator<void> > ColoredArc2D;

typedef boost::shared_ptr< ::amrl_msgs::ColoredArc2D> ColoredArc2DPtr;
typedef boost::shared_ptr< ::amrl_msgs::ColoredArc2D const> ColoredArc2DConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::amrl_msgs::ColoredArc2D_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace amrl_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::amrl_msgs::ColoredArc2D_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "cca4be38df37d86344ae953f24de0bef";
  }

  static const char* value(const  ::amrl_msgs::ColoredArc2D_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xcca4be38df37d863ULL;
  static const uint64_t static_value2 = 0x44ae953f24de0befULL;
};

template<class ContainerAllocator>
struct DataType< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "amrl_msgs/ColoredArc2D";
  }

  static const char* value(const  ::amrl_msgs::ColoredArc2D_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# Circular arc section.\n\
Point2D center\n\
float32 radius\n\
float32 start_angle\n\
float32 end_angle\n\
uint32 color\n\
================================================================================\n\
MSG: amrl_msgs/Point2D\n\
float32 x\n\
float32 y\n\
\n\
";
  }

  static const char* value(const  ::amrl_msgs::ColoredArc2D_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.center);
    stream.next(m.radius);
    stream.next(m.start_angle);
    stream.next(m.end_angle);
    stream.next(m.color);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER
}; // struct ColoredArc2D_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::amrl_msgs::ColoredArc2D_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::amrl_msgs::ColoredArc2D_<ContainerAllocator> & v) 
  {
    s << indent << "center: ";
s << std::endl;
    Printer< ::amrl_msgs::Point2D_<ContainerAllocator> >::stream(s, indent + "  ", v.center);
    s << indent << "radius: ";
    Printer<float>::stream(s, indent + "  ", v.radius);
    s << indent << "start_angle: ";
    Printer<float>::stream(s, indent + "  ", v.start_angle);
    s << indent << "end_angle: ";
    Printer<float>::stream(s, indent + "  ", v.end_angle);
    s << indent << "color: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.color);
  }
};


} // namespace message_operations
} // namespace ros

#endif // AMRL_MSGS_MESSAGE_COLOREDARC2D_H

