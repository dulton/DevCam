/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_def.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 
        Author:  
   Description: 该文件定义了sdk相关的错误码、宏

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------

*******************************************************************************/
#ifndef __IMOS_SDK_DEF_H__
#define __IMOS_SDK_DEF_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#if 0
#endif
/*******************************************************************************
编译选项
*******************************************************************************/
#if defined(WIN32)
    #if defined(IMOS_EXPORTS_DLL)
        #define IMOS_EXPORT  __declspec( dllexport )
    #else
        #if defined(IMOS_AS_STATIC_LIB)
            #define IMOS_EXPORT
        #else
            #define IMOS_EXPORT  __declspec( dllimport )    
        #endif
    #endif
#else
    #define IMOS_EXPORT
#endif

/* 函数标准调用约定 */
#ifdef WIN32
    #define STDCALL         __stdcall
#else
    #ifdef i386
        #define STDCALL         __attribute__((stdcall))
    #else
        #define STDCALL
    #endif
#endif 

#if 0
#endif
/*******************************************************************************
通用数据类型定义
*******************************************************************************/
/** @brief 8位有符号整型 */
#ifndef CHAR
typedef char CHAR;
#endif

/** @brief 8位无符号整型 */
#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

/** @brief 16位有符号整型 */
#ifndef SHORT
typedef short SHORT;
#endif

/** @brief 16位无符号整型 */
typedef unsigned short USHORT;

/** @brief 32位有符号整型 */
typedef long LONG;

/** @brief 32位无符号整型 */
typedef unsigned long ULONG;

/** @brief 有符号整型 */
typedef int INT;

/** @brief 无符号整型 */
typedef unsigned int UINT;

/** @brief 64位有符号整型 */
#if defined (_MSC_VER)
typedef __int64 DLONG;
#else
typedef long long DLONG;
#endif

/** @brief 64位无符号整型 */
#if defined (_MSC_VER)
typedef unsigned __int64 DULONG;
#else
typedef unsigned long long DULONG;
#endif

/** @brief 双精度数据类型 */
typedef double DOUBLE;

/** @brief 浮点数据类型 */
typedef float FLOAT;

/** @brief 布尔型 */
typedef unsigned long BOOL_T;

/** @brief 表示长度数据类型 */
typedef unsigned long SIZE_T;

/** @brief 表示时间数据类型 */
typedef long TIME_T;

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;

/** @brief VOID型 */
#define VOID                            void

/** @brief 表示通用句柄类型 */
typedef VOID* HANDLE;

/** @brief IMOS ID 数据类型 */
typedef DULONG IMOS_ID;

/** @brief 通用句柄类型 IMOS_HANDLE */
#ifndef IMOS_HANDLE
#if defined (WIN32)
typedef HANDLE IMOS_HANDLE;
#else
typedef int IMOS_HANDLE;
#endif
#endif

/** @brief 函数参数类型定义 */
#define IN
#define OUT
#define INOUT

/** @brief IMOS编程规范布尔值 */
#define BOOL_TRUE                       ((BOOL_T) 1)
#define BOOL_FALSE                      ((BOOL_T) 0)

#ifndef NULL
#define NULL (void *)0
#endif

#if 0
#endif
/*******************************************************************************
SDK 错误码/状态码
*******************************************************************************/
/* 通用成功 */
#define ERR_COMMON_SUCCEED                       0x000000      /**< 执行成功 */

/*********************** SDK 状态码定义(257 - 356) *****************************/
#define ERR_SDK_LOG_CLOSE                        257            /**< SDK 日志关闭 */
#define ERR_SDK_DEVICE_STREAM_FULL               259            /**< 设备流已满 */
#define ERR_SDK_DEVICE_STREAM_CLOSED             260            /**< 设备流已关闭 */
#define ERR_SDK_DEVICE_STREAM_NONEXIST           261            /**< 设备流不存在 */
#define ERR_SDK_USER_PASSWORD_CHANGE             262            /**< 用户密码修改 */
#define ERR_SDK_USER_DELETED                     263            /**< 用户已删除 */

/*********************** SDK 错误码定义(357 - 506) *****************************/
#define ERR_SDK_COMMON_FAIL                      357            /**< 操作失败 */
#define ERR_SDK_COMMON_INVALID_PARAM             358            /**< 输入参数非法 */
#define ERR_SDK_COMMON_NO_MEMORY                 359            /**< 系统内存不足 */
#define ERR_SDK_COMMON_SYS_FAIL                  360            /**< 系统通用错误，Q: 暂未使用 */
#define ERR_SDK_COMMON_FAIL_STAT                 361            /**< 读取文件（目录）状态失败 */
#define ERR_SDK_COMMON_FILE_NONEXIST             362            /**< 文件不存在 */

#define ERR_SDK_USER_NOT_AUTHORIZED              457            /**< 用户未授权 */
#define ERR_SDK_USERFULL                         458            /**< 用户已满 */
#define ERR_SDK_USERNONEXIST                     459            /**< 用户不存在 */
#define ERR_SDK_USER_PASSWD_INVALID              460            /**< 用户密码错误 */
#define ERR_SDK_USER_KEEPALIVEFAIL               461            /**< SDK保活失败 */
#define ERR_SDK_NOTINIT                          462            /**< SDK未初始化 */
#define ERR_SDK_REINIT                           463            /**< SDK已初始化 */

#define ERR_SDK_CREATE_THREAD_FAIL               466            /**< 创建线程失败 */
#define ERR_SDK_NOENOUGH_BUF                     467            /**< 缓冲区太小: 接收设备数据的缓冲区 */
#define ERR_SDK_SOCKET_LSN_FAIL                  468            /**< 创建socket listen失败 */
#define ERR_SDK_SUBSCRIBE_FULL                   470            /**< 本用户订阅已满, 设备侧用户订阅已满的错误码不能返回 */
#define ERR_SDK_COMMAND_SEND_FAIL                471            /**< 请求发送失败 */
#define ERR_SDK_COMMAND_TIMEOUT                  472            /**< 请求超时 */
#define ERR_SDK_UPDATE_NOTADMIN                  473            /**< 非admin用户无法升级 */
#define ERR_SDK_UPDATE_INVALID                   474            /**< 升级 未开始 */
#define ERR_SDK_UPDATE_INPROCESS                 475            /**< 升级 处理中 */
#define ERR_SDK_UPDATE_NOMEMORY                  476            /**< 升级 内存空间不够 */
#define ERR_SDK_UPDATE_FILE_OPEN_ERR             477            /**< 升级 打开镜像文件出错 */
#define ERR_SDK_UPDATE_DEVICE_ERR                478            /**< 升级 FLASH出错 */
#define ERR_SDK_UPDATE_BUSY                      479            /**< 不能同时加载多个升级进程 */
#define ERR_SDK_UPDATE_FAIL_TIMEOUT              480            /**< 升级超时 */

#define ERR_SDK_IP_CONFLICT                      486            /**< IP地址冲突 */
#define ERR_SDK_NETWORKMODE_NOTSUPPORT           487            /**< 网口模式不支持 */


/*********************** SDK 业务模块错误码定义(507-656) *******************/
/* 设备维护相关(507 - 556) */
#define ERR_SDK_INVALID_CONFIGFILE               507            /**< 配置文件无效 */

/* 媒体相关(557 - 606) */
#define ERR_SDK_BIAUDIO_AUDIOBCAST_FULL          557            /**< 语音业务已满 */

/* 云台相关(607 - 656) */
#define ERR_SDK_PTZ_TRACK_ISUSED                 612            /**< 轨迹已使用，无法删除*/
#define ERR_SDK_PTZ_SERIALMODE_MISMATCH          614            /**< 串口模式不匹配*/
#define ERR_SDK_PTZ_TRACK_NOT_EXIST              618            /**< 轨迹不存在*/
#define ERR_SDK_PTZ_MODE_CRUISE_FULL             626            /**< 模式路径轨迹点个数已满 */


/*********************** SDK 播放器错误码定义(657 - 756) ****************************/
#define ERR_SDK_XP_INIT_FAILED                   657            /**< 播放器初始化失败 */
#define ERR_SDK_XP_PORT_ALLOC_FAILED             658            /**< 播放器通道分配失败 */
#define ERR_SDK_XP_PORT_NOT_EXIST                659            /**< 播放器通道不存在 */
#define ERR_SDK_XP_START_STREAM_FAILED           660            /**< 播放器启流失败 */
#define ERR_SDK_XP_START_PLAY_FAILED             662            /**< 开始播放失败 */
#define ERR_SDK_XP_FILE_PLAY_FINISHED            669            /**< 文件已播放完 */
#define ERR_SDK_XP_DISK_CAPACITY_WARN            670            /**< 硬盘剩余空间低于阈值 */
#define ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH      671            /**< 硬盘剩余空间不足 */
#define ERR_SDK_XP_NO_PICTURE_TO_SNATCH          672            /**< 没有解码过的图片可供抓拍 */
#define ERR_SDK_XP_SERIES_SNATCH_FAILED          673            /**< 连续抓拍过程中抓拍失败 */
#define ERR_SDK_XP_WRITE_FILE_FAILED             674            /**< 写文件操作失败 */
#define ERR_SDK_XP_FILE_DESTROY                  675            /**< 文件已损坏 */
#define ERR_SDK_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE 676            /**< 媒体编码格式不支持录像操作 */
#define ERR_SDK_XP_PROCESS_MEDIA_DATA_FAILED     677            /**< 媒体数据处理失败 */
#define ERR_SDK_XP_RECV_DATA_FAILED              678            /**< 网络故障造成接收数据失败 */
#define ERR_SDK_XP_MEDIA_RESOLUTION_CHANGE       679            /**< 媒体流分辨率发生变化 */
#define ERR_SDK_XP_VOICE_RUNNING_ERROR           680            /**< 语音对讲或广播过程中出错 */
#define ERR_SDK_XP_AUDIO_DEVICE_UNRIPE           682            /**< 音频设备未准备好 */

/*******************************************************************************
SDK 宏定义 
*******************************************************************************/
#if 0
#endif
/**************************************** 设备状态相关 ***************************************/
/**@brief 设备状态类型 */
#define IMOS_MW_STATUS_KEEPALIVE                   0            /**< SDK保活，状态码为: ERR_SDK_USER_KEEPALIVEFAIL */
#define IMOS_MW_STATUS_UPDATE                      1            /**< 升级结果，状态码为: ERR_SDK_UPDATE_INVALID 等 */
#define IMOS_MW_STATUS_NETWORK_CHANGE              54           /**< 网口配置结果，状态码为: ERR_SDK_IP_CONFLICT 等 */
#define IMOS_MW_STATUS_PTZ_ABS_POSITION            101          /**< 云台绝对位置，对应参数类型: IMOS_MW_PTZ_ABSPOSITION_S */                    
#define IMOS_MW_STATUS_PTZ_ABS_ZOOM                102          /**< 云台绝对ZOOM倍数，对应参数类型: IMOS_MW_PTZ_ABSZOOM_S */  
#define IMOS_MW_STATUS_PLAYER_MEDIA_PROCESS        201          /**< 视频媒体处理过程中的上报运行信息，信息内容见: IMOS_MW_PLAYER_STATUS_S */

#if 0
#endif
/*************************************** 配置相关 ********************************************/
/**@brief 配置操作命令字 */
/* 系统配置 */
#define IMOS_MW_SYSTEM_TIME_INFO            0          /**< 获取/设置 系统时间(含时区信息)，对应结构定义: IMOS_MW_SYSTEM_TIME_INFO_S */
       
/* 网口 */
#define IMOS_MW_NETWORK_INTERFACE_CFG       12         /**< 获取/设置 网口配置，对应结构定义: IMOS_MW_NETWORK_INTERFACE_CFG_S */
    
/* 图像参数配置 */
#define IMOS_MW_EXPOSURE_CFG                20         /**< 获取/设置 曝光参数，对应结构定义: IMOS_MW_EXPOSURE_CFG_S */
#define IMOS_MW_WHITE_BALANCE_CFG           21         /**< 获取/设置 白平衡参数，对应结构定义: IMOS_MW_WHITE_BALANCE_CFG_S */
#define IMOS_MW_IMAGE_ENHANCE_CFG           22         /**< 获取/设置 图像增强参数，对应结构定义: IMOS_MW_IMAGE_ENHANCE_CFG_S */
#define IMOS_MW_FOCUS_CFG                   23         /**< 获取/设置 对焦参数，对应结构定义: IMOS_MW_FOCUS_CFG_S */

/* 视频编码、音频编解码参数、OSD */
#define IMOS_MW_VIDEOIN_MODE_CFG            30         /**< 获取/设置 视频编码制式，对应结构定义: IMOS_MW_VIDEOIN_MODE_CFG_S */
#define IMOS_MW_VIDEO_ENCODER_CFG           31         /**< 获取/设置 视频编码参数配置，对应结构定义:IMOS_MW_VIDEO_ENCODER_CFG_S */
#define IMOS_MW_AUDIO_IN_CFG                32         /**< 获取/设置 音频输入参数配置，对应结构定义:IMOS_MW_AUDIO_IN_CFG_S */
#define IMOS_MW_OSD_STYLE_CFG               35         /**< 获取/设置 叠加OSD样式配置，对应结构定义: IMOS_MW_OSD_STYLE_CFG_S */
#define IMOS_MW_INFO_OSD_CFG                36         /**< 获取/设置/删除 叠加OSD配置，对应结构定义: IMOS_MW_INFO_OSD_CFG_S */

/* 云台相关: 预置位列表、看守位 */
#define IMOS_MW_PTZ_PRESET_CFG              51         /**< 获取      预置位信息，对应结构定义: IMOS_MW_PRESET_CFG_S */    
#define IMOS_MW_PTZ_GUARD_PRESET_CFG        52         /**< 获取/设置 看守位信息，对应结构定义: IMOS_MW_GUARD_PRESET_CFG_S */ 
#if 0
#endif
/*************************************** 设备维护相关 ********************************************/
/*@brief 通用CODE长度*/
#define IMOS_MW_CODE_LEN                    48   

/*@brief 通用名称字符串长度 */
#define IMOS_MW_NAME_LEN                    64     

/*@brief 文件名称字符串长度 */
#define IMOS_MW_FILE_NAME_LEN               IMOS_MW_NAME_LEN    

/*@brief 资源编码信息字符串长度 */
#define IMOS_MW_RES_CODE_LEN                IMOS_MW_CODE_LEN

/*@brief 系统默认路径长度 */
#define IMOS_MW_DEFAULT_PATH_LEN            256

/*@brief SDK 客户端版本号长度 */
#define IMOS_MW_SDK_CLIENT_VERSION_LEN      32

/*@brief IP地址信息字符串长度 
  * IPV4: "192.168.0.102"
  * IPV6: "A1:0:8:100:200:0:0:321A"
  * 域名: "AS_server_hangzhou" */
#define IMOS_MW_IPADDR_LEN                  64  

/*@brief SNMP 团体名长度  */
#define IMOS_MW_COMMUNITY_LEN               32

/*@brief 时间 格式 */
#define IMOS_MW_TIME_FORMAT_HHMMSS          0        /**< XX:XX:XX 常见于中国，美国，英国等*/
#define IMOS_MW_TIME_FORMAT_HHMMSS_PM       1        /**< XX:XX:XX p.m. 常见于除西班牙以外的西班牙语国家*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS_PM     2        /**< XX:XX:XX PM 常见于除英国以外的英语国家*/
#define IMOS_MW_TIME_FORMAT_PM_HHMMSS       3        /**< PM XX:XX:XX 常见于中文(新加坡)*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS        4        /**< 下午 XX:XX:XX 常见于中文(台湾)*/

/*@brief 日期 格式 */
#define IMOS_MW_DATE_FORMAT_YYYYMMDD        0        /**< XXXX-XX-XX 年月日 */
#define IMOS_MW_DATE_FORMAT_MMDDYYYY        1        /**< XX-XX-XXXX 月日年 */
#define IMOS_MW_DATE_FORMAT_YYYY_MM_DD      2        /**< XXXX年XX月XX日 */
#define IMOS_MW_DATE_FORMAT_MM_DD_YYYY      3        /**< XX月XX日XXXX年 */

/*@brief 版本信息长度 */
#define IMOS_MW_VERSION_LEN                 256 

/*@brief 用户名最大长度 */
#define IMOS_MW_USER_NAME_LEN               32   

/*@brief 用户密码最大长度 */
#define IMOS_MW_USER_PASSWORD_LEN           32  

/**@brief 用户级别 */
#define IMOS_MW_USERLEVEL_ADMINISTRATOR     0        /**< 管理员 */
#define IMOS_MW_USERLEVEL_OPERATOR          1        /**< 操作员 */
#define IMOS_MW_USERLEVEL_USER              2        /**< 普通用户 */
#define IMOS_MW_USERLEVEL_ANONYMOUS         3        /**< 匿名用户 */
#define IMOS_MW_USERLEVEL_EXTENDED          4        /**< 扩展用户 */

/**@brief 参数类型 */
#define IMOS_MW_PARAM_TYPE_OPTICS_VIDEO     0        /**< 视频的图像参数 */
#define IMOS_MW_PARAM_TYPE_OPTICS_PICTURE   1        /**< 照片的图像参数 */

/**@brief 日志级别 */
#define IMOS_SDK_LOG_CLOSE                  0        /**< 关闭日志 */
#define IMOS_SDK_LOG_DEBUG                  1        /**< debug级别 */
#define IMOS_SDK_LOG_INFO                   2        /**< info级别 */
#define IMOS_SDK_LOG_WARN                   3        /**< warn级别 */
#define IMOS_SDK_LOG_ERROR                  4        /**< error级别 */
#define IMOS_SDK_LOG_FATAL                  5        /**< fatal级别 */
#if 0
#endif
/*************************************** 网口相关 ********************************************/
/*@brief PPPoE用户名长度  */
#define IMOS_MW_PPPOE_USERNAME_LEN               32  

/*@brief PPPoE密码长度 */
#define IMOS_MW_PPPOE_PASSWORD_LEN               32

/**@brief IP获取方式 */
#define IMOS_MW_IP_GET_TYPE_STATIC               0        /**< 静态获取 */
#define IMOS_MW_IP_GET_TYPE_PPPOE                1        /**< pppoe分配 */
#define IMOS_MW_IP_GET_TYPE_DHCP                 2        /**< DHCP分配 */

/**@brief 网口类型 */
#define IMOS_MW_PORT_MODE_ELECTRONIC             0        /**< 电口 */
#define IMOS_MW_PORT_MODE_FIBER                  1        /**< 光口 */
#define IMOS_MW_PORT_MODE_EPON                   2        /**< EPON */
#define IMOS_MW_PORT_MODE_LRE                    3        /**< LRE电口 */

/**@brief 网口工作模式 */
#define IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION    0    /**< 自协商 */
#define IMOS_MW_ETH_WORKMODE_10M_FULL            1    /**< 10M FULL */
#define IMOS_MW_ETH_WORKMODE_10M_HALF            2    /**< 10M HALF */
#define IMOS_MW_ETH_WORKMODE_100M_FULL           3    /**< 100M FULL */
#define IMOS_MW_ETH_WORKMODE_100M_HALF           4    /**< 100M HALF */
#define IMOS_MW_ETH_WORKMODE_1000M_FULL          5    /**< 1000M FULL */

#if 0
#endif
/*************************************** 图像相关 ********************************************/
/**@brief 图像类型 */
#define IMOS_MW_IMAGE_TYPE_VIDEO                0       /**< 视频图像 */
#define IMOS_MW_IMAGE_TYPE_CAPTURE              1       /**< 抓拍图像 */
#define IMOS_MW_IMAGE_TYPE_COUNT                2       /**< 图像类型个数 */

/**@brief 白平衡模式 */
#define IMOS_MW_WB_AUTO                         0       /**< 自动白平衡 */
#define IMOS_MW_WB_FINETUNE                     1       /**< 微调白平衡 */
#define IMOS_MW_WB_INDOOR                       2       /**< 室内白平衡 */
#define IMOS_MW_WB_OUTDOOR                      3       /**< 室外白平衡 */
#define IMOS_MW_WB_AUTO_MERCURY                 4       /**< 自动水银灯白平衡 */ 

/**@brief 对焦模式 */
#define IMOS_MW_FOCUS_AUTO                      0       /**< 自动对焦 */
#define IMOS_MW_FOCUS_MANUAL                    1       /**< 手动对焦 */
#define IMOS_MW_FOCUS_PUSH                      2       /**< 一键对焦 */
#define IMOS_MW_FOCUS_PUSH_NIGHTINFRARED        3       /**< 一键对焦(夜间红外) */

/**@brief 快门值单位 */
#define IMOS_MW_SHUTTER_UNIT_MICSEC             0       /**< 微秒 */
#define IMOS_MW_SHUTTER_UNIT_DENOMINATOR        1       /**< 分母表示法，单位: 1/秒 */

/**@brief 曝光模式 */
#define IMOS_MW_EXPOSURE_AUTO                   0       /**< 自动曝光 */
#define IMOS_MW_EXPOSURE_CUSTOM                 1       /**< 自定义曝光 */
#define IMOS_MW_EXPOSURE_SHUTTER                2       /**< 快门优先 */
#define IMOS_MW_EXPOSURE_IRIS                   3       /**< 光圈优先 */
#define IMOS_MW_EXPOSURE_GAIN                   4       /**< 增益优先 */
#define IMOS_MW_EXPOSURE_INDOOR_50HZ            5       /**< 室内50HZ */
#define IMOS_MW_EXPOSURE_INDOOR_60HZ            6       /**< 室内60HZ */
#define IMOS_MW_EXPOSURE_MANUAL                 7       /**< 手动曝光 */

/**@brief 宽动态模式 */
#define IMOS_MW_WDR_DISABLE                     0       /**< 关闭 */
#define IMOS_MW_WDR_ENABLE                      1       /**< 开启 */
#define IMOS_MW_WDR_AUTO                        2       /**< 自动 */

/**@brief 测光模式 */
#define IMOS_MW_METERING_CENTER                 0       /**< 中央权重 */
#define IMOS_MW_METERING_AREA                   1       /**< 区域测光权重 */

/**@brief 昼夜模式 */
#define IMOS_MW_DAYNIGHT_AUTO                   0       /**< 自动模式 */
#define IMOS_MW_DAYNIGHT_COLOR                  1       /**< 彩色 */
#define IMOS_MW_DAYNIGHT_BW                     2       /**< 黑白 */

/**@brief 锐度模式 */
#define IMOS_MW_SHARPNESS_AUTO                  0       /**< 自动模式 */
#define IMOS_MW_SHARPNESS_MANUAL                1       /**< 手动模式 */

/**@brief 镜像模式 */
#define IMOS_MW_MIRROR_MODE_NONE                0       /**< 正常模式 */
#define IMOS_MW_MIRROR_MODE_FLIP                1       /**< 垂直翻转 */
#define IMOS_MW_MIRROR_MODE_MIRROR              2       /**< 水平翻转 */
#define IMOS_MW_MIRROR_MODE_FLIP_MIRROR         3       /**< 垂直水平同时翻转 */
#define IMOS_MW_MIRROR_MODE_ROTATE_CLOCKWISE    4       /**< 顺时针旋转90度 */

#if 0
#endif
/*************************************** OSD相关 ********************************************/
/*@brief OSD 叠加内容的长度 */
#define IMOS_MW_OSD_INFO_LEN                      60    

/*@brief 叠加 OSD 最大个数 */
#define IMOS_MW_INFO_OSD_MAX_NUM                  3   

/*@brief OSD 叠加内容最大行数 */
#define IMOS_MW_INFO_OSD_LINE_MAX                 8

/*@brief 遮盖 OSD 最大个数 */
#define IMOS_MW_COVER_OSD_MAX_NUM                 8 

/*@brief 叠加内容类型 */
#define IMOS_MW_OSD_INFO_TYPE_UNUSED              0    /* 不使用 */
#define IMOS_MW_OSD_INFO_TYPE_USERDEF             1    /* 自定义 */
#define IMOS_MW_OSD_INFO_TYPE_DATETIME            2    /* 时间日期 */
#define IMOS_MW_OSD_INFO_TYPE_PTZOPER             3    /* 云台控制者 */
#define IMOS_MW_OSD_INFO_TYPE_PTZCOORDINATS       4    /* 云台坐标 */
#define IMOS_MW_OSD_INFO_TYPE_CRUISEINFO          5    /* 巡航信息 */
#define IMOS_MW_OSD_INFO_TYPE_ZOOMINFO            6    /* 变倍信息 */
#define IMOS_MW_OSD_INFO_TYPE_PRESETINFO          7    /* 预置位信息 */
#define IMOS_MW_OSD_INFO_TYPE_ALARMINFO           8    /* 报警信息 */
#define IMOS_MW_OSD_INFO_TYPE_ENCODEINFO          9    /* 编码信息 */

/*@brief 其他 OSD 类型 */
#define IMOS_MW_OSD_PIC_TIME                      0     /**< 抓拍照片 时间OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_SPEED             1     /**< 抓拍照片 车速OSD */
#define IMOS_MW_OSD_PIC_LIMITED_SPEED             2     /**< 抓拍照片 限速OSD */
#define IMOS_MW_OSD_PIC_PECCANCY_TYPE             3     /**< 抓拍照片 违章类型OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_COLOR             4     /**< 抓拍照片 车身颜色OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_LOGO              5     /**< 抓拍照片 车标OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_TYPE              6     /**< 抓拍照片 车型OSD */
#define IMOS_MW_OSD_TYPE_BUTT                     7     /**< 支持的抓拍OSD个数 */

/*@brief OSD 字体样式 */
#define IMOS_MW_OSD_FONT_STYLE_NORMAL             0    /**< 正常 */
#define IMOS_MW_OSD_FONT_STYLE_STROKES            1    /**< 描边 */ 
#define IMOS_MW_OSD_FONT_STYLE_HOLLOW             2    /**< 空心 */

/*@brief OSD 字体大小 */
#define IMOS_MW_OSD_FONT_SIZE_LARGE               0    /**< 大 */
#define IMOS_MW_OSD_FONT_SIZE_MIDDLE              1    /**< 中 */
#define IMOS_MW_OSD_FONT_SIZE_SMALL               2    /**< 小 */

/*@brief OSD 颜色 */
#define IMOS_MW_OSD_COLOR_WHITE                   0    /**< 白 */
#define IMOS_MW_OSD_COLOR_RED                     1    /**< 红 */
#define IMOS_MW_OSD_COLOR_YELLOW                  2    /**< 黄 */
#define IMOS_MW_OSD_COLOR_BLUE                    3    /**< 蓝 */
#define IMOS_MW_OSD_COLOR_BLACK                   4    /**< 黑 */
#define IMOS_MW_OSD_COLOR_GREEN                   5    /**< 绿 */
#define IMOS_MW_OSD_COLOR_PURPLE                  6    /**< 紫 */

/*@brief OSD 透明度 */
#define IMOS_MW_OSD_ALPHA_NO                      0    /**< 不透明 */
#define IMOS_MW_OSD_ALPHA_SEMI                    1    /**< 半透明 */
#define IMOS_MW_OSD_ALPHA_ALL                     2    /**< 全透明 */

#if 0
#endif
/*************************************** 媒体流相关 ********************************************/
/**@brief 传输模式 */
#define IMOS_MW_TRANSFER_MODE_RTP_UDP           0        /**< UDP＋RTP 报文模式 */
#define IMOS_MW_TRANSFER_MODE_RTP_TCP           1        /**< TCP＋RTP 报文模式 */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW1_TCP      2        /**< TCP＋Uniview1 报文模式 */        
#define IMOS_MW_TRANSFER_MODE_TS_TCP            3        /**< TCP＋TS 报文模式 */
#define IMOS_MW_TRANSFER_MODE_TS_UDP            4        /**< UDP＋TS 报文模式 */
#define IMOS_MW_TRANSFER_MODE_HTTP              5        /**< 基于RTP/RTSP/HTTP/TCP承载方式 */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW2_TCP      6        /**< TCP＋Uniview2 报文模式 */  

/**@brief 流ID */
#define IMOS_MW_STREAM_ID_MAIN                  0        /**< 主流 */
#define IMOS_MW_STREAM_ID_AUX                   1        /**< 辅流 */
#define IMOS_MW_STREAM_ID_THIRD                 2        /**< 三流 */

/**@brief 媒体流类型 */
#define IMOS_MW_MEDIA_VIDEO                     0       /**< 实况流 */
#define IMOS_MW_MEDIA_VOICE_TALK                1       /**< 语音对讲 */
#define IMOS_MW_MEDIA_VOICE_BROADCAST           2       /**< 语音广播 */

/**@brief 码流类型 */
#define IMOS_MW_STREAM_TYPE_TS                  0       /**<  TS  */
#define IMOS_MW_STREAM_TYPE_H3C_ES              1       /**<  H3C ES RTP  */
#define IMOS_MW_STREAM_TYPE_PS                  2       /**<  PS  */
#define IMOS_MW_STREAM_TYPE_UNIVIEW             6       /**< 宇视卡口电警协议 */

/**@brief 码流传输模式 */
#define IMOS_MW_CONNECT_TYPE_UDP                0       /**<  UDP  */
#define IMOS_MW_CONNECT_TYPE_TCP                1       /**<  TCP  */
#define IMOS_MW_CONNECT_TYPE_RTP                2       /**<  RTP  */
#define IMOS_MW_CONNECT_TYPE_RTP_NO_RTCP        3       /**< RTP no rtcp*/
#define IMOS_MW_CONNECT_TYPE_AUTO               4       /**< 自适应 */
#define IMOS_MW_CONNECT_TYPE_HTTP               5       /**< RTP/RTSP/HTTP/TCP 承载方式 */

/**@brief GOP模式 */
#define IMOS_MW_GOP_TYPE_IP                     0       /**< IP */
#define IMOS_MW_GOP_TYPE_IBP                    1       /**< IBP */
#define IMOS_MW_GOP_TYPE_IBBP                   2       /**< IBBP */
#define IMOS_MW_GOP_TYPE_I                      3       /**< I */

/**@brief 编码模式 */
#define IMOS_MW_ENCODE_MODE_CBR                 0       /**< CBR方式 */
#define IMOS_MW_ENCODE_MODE_VBR                 1       /**< VBR方式 */

/**@brief 视频编码格式 */
#define IMOS_MW_STREAM_FORMAT_MPEG1             0       /**< MPEG1 */
#define IMOS_MW_STREAM_FORMAT_MPEG2             1       /**< MPEG2 */
#define IMOS_MW_STREAM_FORMAT_MPEG4             2       /**< MPEG4 */
#define IMOS_MW_STREAM_FORMAT_MJPEG             3       /**< MJPEG */
#define IMOS_MW_STREAM_FORMAT_H263              4       /**< H263 */
#define IMOS_MW_STREAM_FORMAT_H263PLUS          5       /**< H263+ */
#define IMOS_MW_STREAM_FORMAT_H264              6       /**< H.264 */
#define IMOS_MW_STREAM_FORMAT_AUTO              7       /**< 自适应(解码) */
#define IMOS_MW_STREAM_FORMAT_MPEG4_DS          8       /**< MPEG4-ds */
#define IMOS_MW_STREAM_FORMAT_MPEG2_DS          9       /**< MPEG2-ds */ 
#define IMOS_MW_STREAM_FORMAT_MPEG4_2           10      /**< MPEG4 辅流 */    
#define IMOS_MW_STREAM_FORMAT_H264_2            11      /**< H264 辅流 */   
#define IMOS_MW_STREAM_FORMAT_JPEG              12      /**< JPEG */ 

/**@brief 音频编码格式 */
#define IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2       0       /**< MPEG1_LAYER2 */
#define IMOS_MW_AUDIO_ENCODE_G711A              1       /**< G.711A */
#define IMOS_MW_AUDIO_ENCODE_G711U              2       /**< G.711U */
#define IMOS_MW_AUDIO_ENCODE_ADPCM              3       /**< ADPCM */
#define IMOS_MW_AUDIO_ENCODE_OGG                4       /**< OGG */
#define IMOS_MW_AUDIO_ENCODE_AUTO               5       /**< 自动 */
#define IMOS_MW_AUDIO_ENCODE_AAC                6       /**< AAC */

/**@brief 输出音量 */
#define IMOS_MW_AUDIO_VOLUME_REDUCE_8           1 
#define IMOS_MW_AUDIO_VOLUME_REDUCE_4           2
#define IMOS_MW_AUDIO_VOLUME_REDUCE_2           3
#define IMOS_MW_AUDIO_VOLUME_ZOOM_1             4
#define IMOS_MW_AUDIO_VOLUME_ZOOM_2             5
#define IMOS_MW_AUDIO_VOLUME_ZOOM_4             6
#define IMOS_MW_AUDIO_VOLUME_ZOOM_8             7

/**@brief 采样率 */
#define IMOS_MW_AUDIO_SAMPLING_8000             0 
#define IMOS_MW_AUDIO_SAMPLING_16000            1
#define IMOS_MW_AUDIO_SAMPLING_22050            2
#define IMOS_MW_AUDIO_SAMPLING_24000            3
#define IMOS_MW_AUDIO_SAMPLING_32000            4
#define IMOS_MW_AUDIO_SAMPLING_44100            5
#define IMOS_MW_AUDIO_SAMPLING_48000            6
#define IMOS_MW_AUDIO_SAMPLING_96000            7

/**@brief 音频通道 */
#define IMOS_MW_AUDIO_CHANNEL_STEREO            0        /**< 立体声 */
#define IMOS_MW_AUDIO_CHANNEL_L                 1        /**< 左声道 */
#define IMOS_MW_AUDIO_CHANNEL_R                 2        /**< 右声道 */
#define IMOS_MW_AUDIO_CHANNEL_MONO              3        /**< 单声道 */

/**@brief 音频编码量化位数 */
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_8       8
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_16      16
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_32      32

/**@brief 网络协议 */
#define IMOS_MW_PROTOCOL_UDP                    0       /**< UDP协议 */
#define IMOS_MW_PROTOCOL_TCP                    1       /**< TCP协议*/

#if 0
#endif
/**************************************** 云台巡航相关 ***************************************/
/*@brief 最大轨迹点个数*/
#define IMOS_MW_TRACK_POINT_NUM                64      

/*@brief 预置位描述信息最大长度 */ 
#define IMOS_MW_PTZ_PRESET_NAME                64  

/*@brief 云台协议名称长度 */ 
#define IMOS_MW_PTZ_NAME_LEN                   16

/*@brief 时间字符串长度 */ 
#define IMOS_MW_TIME_LEN                       12    

/*@brief 日期字符串长度 */ 
#define IMOS_MW_DAY_LEN                        12   

/*@brief 周的天数 */
#define IMOS_MW_WEEK_DAY                       7

/**@brief 云台控制命令 */
#define IMOS_MW_PTZ_CMD_IRISCLOSE              0x0102        /**< 光圈变小 */
#define IMOS_MW_PTZ_CMD_IRISOPEN               0x0104        /**< 光圈变大 */
#define IMOS_MW_PTZ_CMD_FOCUSNEAR              0x0202        /**< 近聚焦 */
#define IMOS_MW_PTZ_CMD_FOCUSFAR               0x0204        /**< 远聚焦 */
#define IMOS_MW_PTZ_CMD_ZOOMIN                 0x0302        /**< 放大 */
#define IMOS_MW_PTZ_CMD_ZOOMOUT                0x0304        /**< 缩小 */
#define IMOS_MW_PTZ_CMD_TILTUP                 0x0402        /**< 上, ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_TILTDOWN               0x0404        /**< 下, ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_PANRIGHT               0x0502        /**< 右, ulPTZCmdPara1 水平方向速度 */
#define IMOS_MW_PTZ_CMD_PANLEFT                0x0504        /**< 左, ulPTZCmdPara1 水平方向速度 */
#define IMOS_MW_PTZ_CMD_LEFTUP                 0x0702        /**< 左上, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_LEFTDOWN               0x0704        /**< 左下, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_RIGHTUP                0x0802        /**< 右上, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */    
#define IMOS_MW_PTZ_CMD_RIGHTDOWN              0x0804        /**< 右下, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_STOP                   0x0901        /**< 停止 */

#if 0
#endif
/**************************************** 存储 (本地) 相关 ***************************************/
/**@brief 存储文件类型 */
#define IMOS_MW_STOR_FILE_TYPE_VIDEO        0          /**< 录像 */

/**@brief 存储策略 */
#define IMOS_MW_STOR_POLICY_FULL_STOP       0          /**< 满停止 */
#define IMOS_MW_STOR_POLICY_FULL_REWRITE    1          /**< 满覆盖 */

/**@brief 存储模式(开关) */
#define IMOS_MW_LOCAL_STOR_AUTO             0          /**< 自动 */
#define IMOS_MW_LOCAL_STOR_FOREVER          1          /**< 永存 */
#define IMOS_MW_LOCAL_STOR_SAVE             2          /**< 保留，上传后保留SD卡上的文件 */
#define IMOS_MW_LOCAL_STOR_START            10         /**< 开启 */
#define IMOS_MW_LOCAL_STOR_STOP             11         /**< 关闭 */

#if 0
#endif
/**************************************** 播放控制 ***************************************/
/*@brief 播放窗格最大个数 */
#define IMOS_MW_MAX_WND_NUM                      9

/**@brief 播放状态 */
#define IMOS_MW_PLAY_STATUS_16_BACKWARD          0       /**< 16倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_8_BACKWARD           1       /**< 8倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_4_BACKWARD           2       /**< 4倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_2_BACKWARD           3       /**< 2倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_1_BACKWARD           4       /**< 正常速度后退播放 */
#define IMOS_MW_PLAY_STATUS_HALF_BACKWARD        5       /**< 1/2倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_QUARTER_BACKWARD     6       /**< 1/4倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_QUARTER_FORWARD      7       /**< 1/4倍速播放 */
#define IMOS_MW_PLAY_STATUS_HALF_FORWARD         8       /**< 1/2倍速播放 */
#define IMOS_MW_PLAY_STATUS_1_FORWARD            9       /**< 正常速度前进播放 */
#define IMOS_MW_PLAY_STATUS_2_FORWARD            10      /**< 2倍速前进播放 */
#define IMOS_MW_PLAY_STATUS_4_FORWARD            11      /**< 4倍速前进播放 */
#define IMOS_MW_PLAY_STATUS_8_FORWARD            12      /**< 8倍速前进播放 */
#define IMOS_MW_PLAY_STATUS_16_FORWARD           13      /**< 16倍速前进播放 */

/**@brief 媒体文件格式 */
#define IMOS_MW_MEDIA_FILE_FORMAT_TS             0       /**< TS格式的媒体文件 */
#define IMOS_MW_MEDIA_FILE_FORMAT_FLV            1       /**< FLV格式的媒体文件 */

/**@brief 视频显示模式 */
#define IMOS_MW_RENDER_MODE_D3D                  0       /**< 使用D3D的方式进行显示 */
#define IMOS_MW_RENDER_MODE_DDRAW_NORMAL         1       /**< 使用Ddraw的Normal显示模式 */

/**@brief 视频像素格式 */
#define IMOS_MW_PIXEL_FORMAT_YUV420              0       /**< YUV420格式输出 */
#define IMOS_MW_PIXEL_FORMAT_RGB32               1       /**< RGB32格式输出 */

/**@brief 图像播放流畅性 */
#define IMOS_MW_PICTURE_TIME_PRIORITY            0       /**< 实时性优先 */
#define IMOS_MW_PICTURE_FLUENCY_PRIORITY         1       /**< 流畅性优先 */
#define IMOS_MW_PICTURE_AUTO                     2       /**< 自动 */
#define IMOS_MW_PICTURE_LOWDELAY                 3       /**< 低延时 */

/**@brief 播放窗格显示图像的比例 */
#define IMOS_MW_RENDER_SCALE_FULL                0       /**< 图像填充整个播放窗格 */
#define IMOS_MW_RENDER_SCALE_PROPORTION          1       /**< 图像按比例显示 */

/**@brief 媒体数据流格式 */
#define IMOS_MW_MEDIA_DATA_TS                    0       /**< TS封装码流 */
#define IMOS_MW_MEDIA_DATA_ES12                  1       /**< RTP + 音/视频私有头（12字节） + ES码流 */
#define IMOS_MW_MEDIA_DATA_ES12_TIME             2       /**< RTP + 时间戳（8字节） + 音/视频私有头（12字节） + ES码流 */
#define IMOS_MW_MEDIA_DATA_RTP_ES                3       /**< RTP + ES码流 */
#define IMOS_MW_MEDIA_DATA_HK                    4       /**< 海康码流，回调的第一个包是海康40字节系统头 */
#define IMOS_MW_MEDIA_DATA_DH                    5       /**< 大华码流 */
#define IMOS_MW_MEDIA_DATA_RM                    6       /**< 锐明码流，回调的第一个包是锐明40字节系统头 */
#define IMOS_MW_MEDIA_DATA_TDY_SWALLOW           7       /**< TDY-SWALLOW */
#define IMOS_MW_MEDIA_DATA_DMA_SWALLOW           8       /**< DMA-SWALLOW */

/**@brief 解码后音频格式 */
#define IMOS_MW_WAVE_FORMAT_PCM8M16              0       /**< PCM，8K采样率，单声道（M），16位采样 */
#define IMOS_MW_WAVE_FORMAT_PCM16M16             1       /**< PCM，16K采样率，单声道（M），16位采样 */ 
#define IMOS_MW_WAVE_FORMAT_PCM441M16            2       /**< PCM，44.1K采样率，单声道（M），16位采样 */ 

/**@brief 视频帧类型 */
#define IMOS_MW_VIDEO_FRAME_TYPE_I               0       /**< I帧 */
#define IMOS_MW_VIDEO_FRAME_TYPE_P               1       /**< P帧 */
#define IMOS_MW_VIDEO_FRAME_TYPE_B               2       /**< B帧 */

/**@brief 时间戳类型 */
#define IMOS_MW_RENDER_TYPE_FRAME_RATE           0       /**< 使用帧率数据进行视频渲染 */
#define IMOS_MW_RENDER_TYPE_ABSOLUTE_TIME        1       /**< 使用绝对时间数据进行视频渲染 */

/**@brief 解码 对比度模式 */
#define IMOS_MW_PICTURE_CONTRAST_MODE_NONE        0      /**< 不进行对比度调节处理 */
#define IMOS_MW_PICTURE_CONTRAST_MODE_BRIGHTNESS  1      /**< 明亮模式 */
#define IMOS_MW_PICTURE_CONTRAST_MODE_SOFTNESS    2      /**< 柔和模式 */

/**@brief 图片格式 */
#define IMOS_MW_PICTURE_FORMAT_BMP                0      /**< BMP 格式 */ 
#define IMOS_MW_PICTURE_FORMAT_JPEG               1      /**< JPEG 格式，参数参见: IMOS_MW_CAPTURE_FORMAT_CFG_S */
#define IMOS_MW_PICTURE_FORMAT_CUSTOM             10     /**< 随流格式, 不需要其他参数 */

/*@brief 照片后端叠加信息类型 */
#define IMOS_MW_IMAGE_BACKEND_OSD                 0    /**< 叠加 OSD，结构定义: IMOS_MW_IMAGE_OSD_INFO_S */
#define IMOS_MW_IMAGE_BACKEND_RECTANGLE           1    /**< 叠加 信息框, 结构定义: IMOS_MW_RECTANGLE_S, 其中，坐标单位 0.01% */
#define IMOS_MW_IMAGE_BACKEND_OSD_OBJ             2    /**< 叠加OSD, 带目标信息框, 结构定义: IMOS_MW_IMAGE_OSD_WITH_OBJ_S, 信息框坐标单位 0.01% */

#if 0
#endif

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_DEF_H__*/

