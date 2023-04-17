/* Auto-generated by genmsg_cpp for file /home/hcrl-nuc/workspaces/search_ws/src/a1_autonomy/amrl_msgs/msg/ColoredPoint2D.msg */
#ifndef AMRL_MSGS_MESSAGE_COLOREDPOINT2D_H
#define AMRL_MSGS_MESSAGE_COLOREDPOINT2D_H
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
struct ColoredPoint2D_ {
  typedef ColoredPoint2D_<ContainerAllocator> Type;

  ColoredPoint2D_()
  : point()
  , color(0)
  {
  }

  ColoredPoint2D_(const ContainerAllocator& _alloc)
  : point(_alloc)
  , color(0)
  {
  }

  typedef  ::amrl_msgs::Point2D_<ContainerAllocator>  _point_type;
   ::amrl_msgs::Point2D_<ContainerAllocator>  point;

  typedef uint32_t _color_type;
  uint32_t color;


  typedef boost::shared_ptr< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator>  const> ConstPtr;
}; // struct ColoredPoint2D
typedef  ::amrl_msgs::ColoredPoint2D_<std::allocator<void> > ColoredPoint2D;

typedef boost::shared_ptr< ::amrl_msgs::ColoredPoint2D> ColoredPoint2DPtr;
typedef boost::shared_ptr< ::amrl_msgs::ColoredPoint2D const> ColoredPoint2DConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace amrl_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ddbdd5a0fbcde494542b00e8d4047aee";
  }

  static const char* value(const  ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xddbdd5a0fbcde494ULL;
  static const uint64_t static_value2 = 0x542b00e8d4047aeeULL;
};

template<class ContainerAllocator>
struct DataType< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "amrl_msgs/ColoredPoint2D";
  }

  static const char* value(const  ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Point2D point\n\
uint32 color\n\
================================================================================\n\
MSG: amrl_msgs/Point2D\n\
float32 x\n\
float32 y\n\
\n\
";
  }

  static const char* value(const  ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.point);
    stream.next(m.color);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER
}; // struct ColoredPoint2D_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::amrl_msgs::ColoredPoint2D_<ContainerAllocator> & v) 
  {
    s << indent << "point: ";
s << std::endl;
    Printer< ::amrl_msgs::Point2D_<ContainerAllocator> >::stream(s, indent + "  ", v.point);
    s << indent << "color: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.color);
  }
};


} // namespace message_operations
} // namespace ros

#endif // AMRL_MSGS_MESSAGE_COLOREDPOINT2D_H

