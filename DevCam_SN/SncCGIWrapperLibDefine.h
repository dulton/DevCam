//
//	SncCGIWrapperLibDefine.h - data-types for using "Sony Network Camera CGI Wrapper Library".
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef _SNCCGIWRAPPERLIBDEFINE_H_
#define _SNCCGIWRAPPERLIBDEFINE_H_

#include "SncDefine.h"
#include "SncCGIWrapperLibDefineEnum.h"

namespace SNC {

struct CameraInfo
{
    char            modelname[256];
    char            version[256];
};

struct ImageSizeType
{
    int width;
    int height;
};

struct ConfigurableStreamInfo
{
    unsigned int    use;
    IMAGE_CODEC     codec;
    ImageSizeType   size;
    unsigned int    framerate;
    unsigned int    quality;
    unsigned int    bitrate;
    PROFILE_TYPE    profile;
	unsigned int    cbr;
	unsigned int    iframe_interval;
    unsigned int    h264_quality;
	unsigned int	auto_rate_control_bitrate_min;
	unsigned int	auto_rate_control_bitrate_max;
};

struct ConfigurableVideoInfo
{
    ConfigurableStreamInfo  instance1;
    ConfigurableStreamInfo  instance2;
    ConfigurableStreamInfo  instance3;
};

struct DateTime
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

struct DayScheduleType
{
    bool            has_schedule;
    unsigned int    start_hour;
    unsigned int    start_minute;
    unsigned int    start_second;
    unsigned int    end_hour;
    unsigned int    end_minute;
    unsigned int    end_second;
};

struct DayScheduleTypeEx
{
	WEEK			week;
	unsigned int    start_hour;
    unsigned int    start_minute;
    unsigned int    duration;
};

struct  IpFilterRule
{
    IpAddress           ip;
    unsigned int        mask;
    PROTOCOL_TYPE       protocol;
    unsigned short      port;
    IP_FILTER_RULE_POLICY   policy;
    unsigned int        no;
};

struct IpLimitType
{
    IpAddress           ip;
    unsigned int        mask;
    IP_LIMIT_POLICY     policy;
};

struct IpMangleRule
{
    IpAddress           ip;
    unsigned int        mask;
    PROTOCOL_TYPE       protocol;
    unsigned short      port;
    unsigned int        value;
    unsigned int        no;
};

struct PositionPercent
{
    unsigned int        x;
    unsigned int        y;
};

struct PresetPositionGroupName
{
    unsigned int    id;
    char            name[256];
};

struct PresetPositionName
{
    unsigned int    id;
    char            name[256];
};

struct PrivacyMaskColorType
{
    COMMON_COLOR      color;
    PRIVACY_MASK_ATTRIBUTE  attr;
};

struct PrivacyMaskPosition
{
    unsigned int    x1;
    unsigned int    y1;
    unsigned int    x2;
    unsigned int    y2;
    unsigned int    x3;
    unsigned int    y3;
    unsigned int    x4;
    unsigned int    y4; 
};

struct RangeInt
{
    int             lower;
    int             upper;
    bool            lower_open;
    bool            upper_open;
};

struct RangeUint
{
    unsigned int    lower;
    unsigned int    upper;
    bool            lower_open;
    bool            upper_open;
};

struct RectRegion
{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct ShutterSpeedType
{
    int numerator;
    int denominator;
};

struct SuperimposeColorType
{
    COMMON_COLOR      color_font;
    COMMON_COLOR      color_back;
    TRANSMITTANCE_MODE  mode;
};

struct SuperimposeWordStyle
{
    SUPERIMPOSE_WORD_COLOR  color;
    bool                    blink;
    SUPERIMPOSE_WORD_EFFECT effect;
};

struct TimeHHMM
{
    unsigned int hour;
    unsigned int minute;
};

struct WeeklyScheduleType
{
    DayScheduleType schedule[7];
};

struct WeeklyScheduleTypeEx
{
    DayScheduleTypeEx schedule[7];
};

}

#endif // _SNCCGIWRAPPERLIBDEFINE_H_
