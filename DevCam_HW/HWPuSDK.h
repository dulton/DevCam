#ifndef _HW_PU_SDK_H_
#define _HW_PU_SDK_H_

#ifdef _WIN32
//for windows
#ifdef HWFEDSDK_EXPORTS
#define _HW_PU_API extern "C" __declspec(dllexport)
#else
#define _HW_PU_API extern "C" __declspec(dllimport)
#endif

#else
//for linux
#define _HW_PU_API
#define __stdcall
#define CALLBACK
#define WINAPI
#endif

#ifdef _WIN32
#define PU_TRUE TRUE
#define PU_FALSE FALSE
//#include "stdafx.h"
#else
#define PU_TRUE 1
#define PU_FALSE 0

#ifndef CONST
#define CONST const
#endif

typedef char                CHAR;
typedef unsigned char       UCHAR;
typedef short               SHORT;
typedef unsigned short      USHORT;
typedef int                 INT;
typedef unsigned int        UINT;
typedef int                 BOOL;
typedef long                LONG;
typedef long                DWORD;
typedef unsigned long       ULONG;
typedef unsigned long long  ULONGLONG;
typedef long long           LONGLONG;
typedef void *              HANDLE;
typedef void                VOID;
typedef int                 SOCKET;
typedef void *              HWND;
typedef float               FLOAT;

#endif

#pragma pack(push,1)
/********************************宏定义**********************************************/
#define PU_RESERVE_LEN             32            //预留字节长

#define PU_VERSION_LEN             32            //版本长度
#define PU_DEVICE_NAME_LEN         32            //设备名称长度
#define PU_FAC_NAME_LEN            12            //厂商名称长度
#define PU_DEVICE_TYPE_LEN         32            //设备类型长度
#define PU_SERIAL_LEN              32            //序列号长度

#define PU_IP4_ADDR_LEN            16            //ipv4
#define PU_IP6_ADDR_LEN            40            //ipv6

#define PU_PLATFORM_INFO_LEN       32            //平台信息长度

#define PU_PTZ_NAME_LEN            32            //云台名称最大值
#define PU_PTZ_CRUISE_LEN          32            //预置位长度
#define PU_PTZ_CRUISE_POINT_MAX    20            //轨迹点最大值
#define PU_PTZ_PRESET_NUM          10            //预置位数

#define PU_PRIVACY_MASK_MAX        10            //隐私保护矩形最大值
#define PU_ALARM_TIME_MAX          8             //告警时间段最大值
#define PU_ALARM_AREA_MAX          16            //告警矩形最大值

#define PU_CRUISE_DWELL_MIN        3             //巡航轨迹最小停留时间
#define PU_CRUISE_DWELL_MAX        3600          //巡航轨迹最大停留时间
#define PU_CRUISE_SPEED_MIN        1             //巡航轨迹最小转动速度
#define PU_CRUISE_SPEED_MAX        10            //巡航轨迹最大转动速度

#define PU_TIME_YEAR_LEN           5             //日期中"年"字符串长度
#define PU_TIME_OTHERS_LEN         3             //日期中除"年"外其他字符串长度
#define PU_TIME_TOTAL_LEN          32            //日期字符串总长度

#define PU_UPGRADE_FILE_NUM_MAX    4             //上传文件最大数
#define PU_UPGRADE_FILE_LEN_MAX       300              //上传文件路径长度

#define PU_INVADE_LINE_NUM_MAX     5             //入侵线最大数

#define PU_SAVE_FILE_PATH_MAX      128           //保存文件的最大路径

#define PU_ALARM_CAMERA_MAX        4             //最大告警联动镜头数
#define PU_ALARM_DO_MAX            4             //最大告警联动输出开关数

#define PU_USER_NAME_LEN           32            //用户名最大长度
#define PU_PASSWORD_LEN            (64 + 4)      //密码最大长度

#define PU_CAMERA_NUM_MAX          4             //摄像机支持的最大镜头数

#define PU_TRIPWIRE_LEN_NUM_MAX    5             //绊线告警最大线数
#define PU_IGT_AREA_POINTS_NUM     10            //区域顶点最大数目
#define PU_IGT_AREA_NUM            4             //最大区域数目
#define PU_IGT_LINE_NAME_LEN       (32 + 4)      //智能拌线名称长度
#define PU_IGT_AREA_NAME_LEN       (32 + 4)      //智能区域名称长度

#define PU_DEVICE_NUM_MAX          1000          //最大接入1000路设备
#define PU_TRANSPARENT_CMD_MAX     256           //透明通道命令长度
#define PU_DOMAIN_LEN              256           //域名最大长度
#define PU_IRLIGHT_NUM_MAX         4             //红外球机支持的红外灯个数

#define PU_DIO_NAME_LEN            (32 + 4)      //开关量名称长度
#define PU_DIO_NUM_MAX             4             //开关量输入/输出最大个数
#define PU_RECORD_PLAN_NUM         28            //录像计划条数
#define PU_LOG_INFO_LEN            256           //每条日志的最大长度
#define PU_LOG_INFO_NUM            100           //日志查询每次返回的最大长度
#define PU_NAT_SESSIONID_LEN       32            //NAT穿越的sessid长度
#define PU_NAT_URL_LEN             256           //NAT穿越的会话URL长度
#define PU_RECORD_TYPE_NUM         4             //录像类型个数
#define PU_RECORD_INFO_NUM_MAX     5             //录像信息最大个数
#define PU_RECORD_CONTENTID_LEN    40            //录像文件名长度
#define PU_VIDEO_FORMAT_NUM        4             //视频编码格式个数
#define PU_STREAM_NUM              4             //最大码流个数
#define PU_OSD_STRING_LEN          (96 + 4)      //OSD场名最大值
#define PU_OSD_STRING_NUM          7             //OSD字符串个数
#define PU_MAC_ADDR_LEN            30            //MAC地址长度
#define PU_SNAP_IMAGE_NAME_LEN     24            //抓拍图片文件名长度
#define PU_MAX_URL_LEN             512           //URL长度
#define PU_CONFIG_FILE_PATH_MAX    512           //配置文件最大路径

//解码器宏定义
#define PU_ROI_AREA_NUM_MAX        8             //ROI区域最大数
#define PU_PORT_MODE_NUM_MAX       16            //最大端口模式
#define PU_BNC_PORT_MAX            32            //最大BNC输出端口
#define PU_VGA_PORT_MAX            8             //最大VGA输出端口
#define PU_DVI_PORT_MAX            8             //最大DVI输出端口
#define PU_HDMI_PORT_MAX           8             //最大HDMI输出端口

#define PU_DECODE_TYPE_MAX         4             //解码器支持的解码类型
#define PU_PORT_NUM_MAX            32            //最大端口数
#define PU_CHANNEL_NUM_MAX         32            //最大通道数

#define PU_OSD_MAX_LENGTH          (96 + 1)      //解码器OSD场名的长度
#define PU_CRYPTION_PASSWD_LEN     44            //密钥长度

#define PU_DEC_CHANNEL_NAME_LEN    32            //解码器通道名称长度
#define PU_DECODER_ID_LEN          20            //解码器ID
#define PU_DECODER_NAME_LEN        32            //解码器通道名称长度
#define PU_DEC_PAY_LOAD_TYPE_NUM   16            //PayLoadType的最大个数
#define PU_DECODER_ENCODING_LEN    16            //解码器编码格式最大长度



/********************************枚举类型**********************************************/
//全局错误码
typedef enum ERROR_CODE
{
    PU_ERROR_CODE_NOERROR = 0,                                      //没有错误

    PU_ERROR_CODE_COMMON_ERROR = 1,                                 //一般错误
    PU_ERROR_CODE_PASSWORD_ERROR = 2,                               //用户名或密码错误
    PU_ERROR_CODE_NO_PRIORITY = 3,                                  //没有操作权限
    PU_ERROR_CODE_NO_INIT = 4,                                      //SDK未初始化
    PU_ERROR_CODE_HAS_INIT = 5,                                     //SDK已初始化
    PU_ERROR_CODE_VERSION_NO_MATCH = 6,                             //SDK与设备版本不匹配
    PU_ERROR_CODE_STARTUP_NETWORK_ERROR = 7,                        //网络启动错误
    PU_ERROR_CODE_SOCKET_ERROR = 8,                                 //网络套接字错误
    PU_ERROR_CODE_CONNECT_ERROR = 9,                                //网络连接错误
    PU_ERROR_CODE_SEND_TIMEOUT = 10,                                //发送消息超时
    PU_ERROR_CODE_RECV_TIMEOUT = 11,                                //接收消息超时
    PU_ERROR_CODE_OPERATION_TIMEOUT = 12,                           //设备操作超时
    PU_ERROR_CODE_OUT_OF_MEMORY = 13,                               //内存不足，无法分配内存
    PU_ERROR_CODE_SERVER_IS_SHUTDOWN = 14,                          //服务端关闭连接
    PU_ERROR_CODE_TOO_MANY_REALPLAY = 15,                           //实况路数超过最大值
    PU_ERROR_CODE_LOG_ERROR = 16,                                   //日志出错
    PU_ERROR_CODE_NO_FREE_PORT = 17,                                //没有多余的端口资源
    PU_ERROR_CODE_HAS_REG_EVENT_CALLBACK = 18,                      //事件回调函数已注册
    PU_ERROR_CODE_REGISTER_FAIL = 19,                               //前端主动注册平台失败
    PU_ERROR_CODE_REGISTER_REDIRECT = 20,                           //前端主动注册平台重定向

    //API调用错误
    PU_ERROR_CODE_SDKINIT_LINK_MODE_ERROR = 101,                    //SDK初始化连接模式出错
    PU_ERROR_CODE_SDKINIT_LOCALIP_ERROR = 102,                      //SDK初始化本地IP出错
    PU_ERROR_CODE_SDKLOGIN_PARA_ERROR = 103,                        //登录参数错误
    PU_ERROR_CODE_CODE_IS_INVALID = 104,                            //错误码无效
    PU_ERROR_CODE_SDKGETVERSION_PARA_ERROR = 105,                   //获取版本参数出错
    PU_ERROR_CODE_IDENTIFYID_ERROR = 106,                           //错误的用户ID号
    PU_ERROR_CODE_SDKGETDEVICE_PARA_ERROR = 107,                    //获取设备参数错误
    PU_ERROR_CODE_ALARMREPORT_CB_IS_NULL = 108,                     //告警上报回调函数为空
    PU_ERROR_CODE_VOICETB_CB_IS_NULL = 109,                         //语音对讲回调函数为空
    PU_ERROR_CODE_REALPLAY_CB_IS_NULL = 110,                        //实况播放回调函数为空
    PU_ERROR_CODE_LOAD_PLAYDLL_ERROR = 111,                         //加载播放库出错
    PU_ERROR_CODE_CFGFILE_ERROR = 112,                              //配置文件出错
    PU_ERROR_CODE_UNSUPPORT_ALARM_TYPE = 113,                       //未知告警类型
    PU_ERROR_CODE_SDKUPGRADE_PARA_ERROR = 114,                      //升级参数错误
    PU_ERROR_CODE_SDKUPGRADE_ERROR = 115,                           //升级错误
    PU_ERROR_CODE_SDKUPGRADE_FILE_ERROR = 116,                      //升级文件错误
    PU_ERROR_CODE_UNSUPPORT_PLATFORM_TYPE = 117,                    //未知平台类型
    PU_ERROR_CODE_SDKSETPLATFORM_PARA_ERROR = 118,                  //设置平台参数出错
    PU_ERROR_CODE_UNSUPPORT_ENCODE_TYPE = 119,                      //未知音视频编码类型
    PU_ERROR_CODE_UNSUPPORT_STREAM_TYPE = 120,                      //未知码流类型
    PU_ERROR_CODE_UNSUPPORT_BITRATE_TYPE = 121,                     //未知码率类型
    PU_ERROR_CODE_UNSUPPORT_PTZ_CMD = 122,                          //未知云台命令
    PU_ERROR_CODE_CRUISE_PARA_ERROR = 123,                          //巡航轨迹参数错误
    PU_ERROR_CODE_ALARM_TMP_PARA_ERROR = 124,                       //温度告警参数错误
    PU_ERROR_CODE_ALARM_MOTION_DETEC_PARA_ERROR = 125,              //移动侦测告警参数错误
    PU_ERROR_CODE_ALARM_INPUT_PARA_ERROR = 126,                     //输入告警参数错误
    PU_ERROR_CODE_ALARM_HIDE_PARA_ERROR = 127,                      //遮挡告警参数错误
    PU_ERROR_CODE_ALARM_INVADE_PARA_ERROR = 128,                    //入侵检测告警参数错误
    PU_ERROR_CODE_ALARM_COUNT_PARA_ERROR = 129,                     //目标计数告警参数错误
    PU_ERROR_CODE_ALARM_DISTURB_PARA_ERROR = 130,                   //干扰告警参数错误
    PU_ERROR_CODE_PRIVACY_PARA_ERROR = 131,                         //隐私保护参数错误
    PU_ERROR_CODE_OSD_PARA_ERROR = 132,                             //OSD参数错误
    PU_ERROR_CODE_PTZ_PARA_ERROR = 133,                             //云台控制参数错误
    PU_ERROR_CODE_SDKGUARD_PARA_ERROR = 134,                        //布撤防参数错误
    PU_ERROR_CODE_SDKGETALARAM_PARA_ERROR = 135,                    //获取告警参数错误
    PU_ERROR_CODE_PARA_ERROR = 136,                                 //参数出错
    PU_ERROR_CODE_PLAYER_FUNC_ERROR = 137,                          //播放库函数调用出错
    PU_ERROR_CODE_SDKSAVEREALDATA_ERROR = 138,                      //保存实况数据
    PU_ERROR_CODE_SDKGETGUARDSTATE_PARA_ERROR = 139,                //获取布防状态参数出错
    PU_ERROR_CODE_MUTUALLYEXCLUSIVE_RELATIONSHIP = 140,             //因互斥关系而导致不能设置成功
    PU_ERROR_CODE_DEVICE_RELOGIN = 141,                             //重复登录设备
    PU_ERROR_CODE_INVALID_CONFIG_FILE = 142,                        //配置文件不合法

    //解码器错误码
    PU_ERROR_CODE_DEC_INITDEC_ERROR = 1001,                         //初始化解码失败
    PU_ERROR_CODE_DEC_STARTDEC_ERROR = 1002,                        //开始解码失败
    PU_ERROR_CODE_DEC_STOPDEC_ERROR = 1003,                         //停止解码失败
    PU_ERROR_CODE_DEC_TOO_MANY_CHANNEL = 1004,                      //太多的解码通道
    PU_ERROR_CODE_DEC_ERROR_PORT_NUM = 1005,                        //端口数错误
    PU_ERROR_CODE_DEC_ERROR_DEC_HANDEL = 1006,                      //错误的解码句柄
    PU_ERROR_CODE_DEC_ERROR_UNSUPPORT_DECODE_TYPE = 1007,           //不支持的解码类型
    PU_ERROR_CODE_DEC_ERROR_INVALID_CHANNEL_ID = 1008,              //无效的通道号

    //服务端错误码
    PU_ERROR_CODE_SERVER_COMMON_ERROR = 10001,                      //一般错误
    PU_ERROR_CODE_SYNTAX_ERROR = 10002,                             //配置语法错误
    PU_ERROR_CODE_UNSUPPORT_ERROR = 10003,                          //不支持的请求
    PU_ERROR_CODE_PARAMETER_ERROR = 10004,                          //参数错误
    PU_ERROR_CODE_INVALID_VCU_ID = 10005,                           //设备ID错误
    PU_ERROR_CODE_INVALID_CHANNEL = 10006,                          //通道号错误
    PU_ERROR_CODE_INVALID_SERIAL_NO = 10007,                        //串口号错误
    PU_ERROR_CODE_INVALID_ALARM_NO = 10008,                         //报警端口错误
    PU_ERROR_CODE_UNSUPPORTED_MEDIA_TYPE = 10009,                   //不支持的媒体类型
    PU_ERROR_CODE_PARTLY_SUPPORT = 10011,                           //仅部分参数配置成功
    PU_ERROR_CODE_TOO_MANY_PLANS = 10012,                           //计划条数超过限制
    PU_ERROR_CODE_NO_DISK = 10013,                                  //设备无硬盘
    PU_ERROR_CODE_OPEN_SOUND_FAIL = 10014,                          //打开声音失败
    PU_ERROR_CODE_VOICE_OPEND = 10015,                              //服务器语音对讲被占用
    PU_ERROR_CODE_DEVICE_BUSY = 10016,                              //设备忙
    PU_ERROR_CODE_OPERATE_FLASH_ERROR = 10019,                      //FLASH出错 
    PU_ERROR_CODE_UNSUPPORTED_VIDEO_FORMAT = 10020,                 //不支持的视频制式
    PU_ERROR_CODE_IP_ADDRESS_CONFLICT = 10022,                      //IP地址冲突

    PU_ERROR_CODE_INVALID_VERIFICATION = 10102,                     //错误的用户名或密码
    PU_ERROR_CODE_INVALID_VERSION_FILE = 10103,                     //VERSION文件校验失败
    PU_ERROR_CODE_INVALID_KERNEL_FILE = 10104,                      //内核升级文件校验失败
    PU_ERROR_CODE_INVALID_ROOTFS_FILE = 10105,                      //文件系统升级文件校验失败
    PU_ERROR_CODE_FIRST_LOGIN = 10106,                              //第一次登录
    PU_ERROR_CODE_CLIENT_ALREADY_LOGIN = 10107,                     //已有客户端登录
    PU_ERROR_CODE_USER_LOCKED = 10108,                              //用户被锁定
    PU_ERROR_CODE_MANY_USER = 10109,                                //用户个数超过限制
    PU_ERROR_CODE_NOT_NEED_UPDATE = 10113,                          //版本号一致，不需要升级
    PU_ERROR_CODE_NOT_SUPPORT_ABILITY = 10114,                      //不支持的能力参数
    PU_ERROR_CODE_PRESET_IN_GUARD_POSITION = 10115,                 //预置位在看守位中
    PU_ERROR_CODE_PRESET_IN_CRUISE_TRACK = 10116,                   //预置位在巡航轨迹中
    PU_ERROR_CODE_THE_CRUISE_IS_RUNNING = 10122,                    //巡航轨迹正在运行
    PU_ERROR_CODE_UPDATE = 10125,                                   //系统正在升级
    PU_ERROR_CODE_REBOOT = 10126,                                   //系统正在重启
    PU_ERROR_CODE_RESTORE = 10127,                                  //正在恢复默认配置
    PU_ERROR_CODE_RECOVER_OPRATE_FORBIDDEN = 10128,                 //恢复默认配置禁止配置等操作
    PU_ERROR_CODE_ROI_ERROR_BY_MJPEG = 10129,                       //MJPEG下设置ROI 失败
    PU_ERROR_CODE_ROI_ERROR_BY_NOSUBSTREAM = 10130,                 //只有主码流，设置子码流ROI失败
    PU_ERROR_CODE_TZ_ERROR_BY_CONFLICT = 10131,                     //设置绊线检测使能有冲突
    PU_ERROR_CODE_OC_ERROR_BY_CONFLICT = 10132,                     //设置目标计数使能有冲突
    PU_ERROR_CODE_MD_ERROR_BY_CONFLICT = 10133,                     //设置移动侦测使能有冲突
    PU_ERROR_CODE_TW_ERROR_BY_CONFLICT = 10134,                     //设置绊线检测使能有冲突
    PU_ERROR_CODE_AREA_ERROR_BY_CONFLICT = 10135,                   //设置区域检(周界入侵、物品遗留、物品移走）测使能有冲突
    PU_ERROR_CODE_VD_ERROR_BY_CONFLICT = 10136,                     //设置视频干扰使能有冲突
    PU_ERROR_CODE_IGT_ENABLE_CONFLICT = 10137,                      //智能开关已打开  设置照度增强失败,设置遮挡失败
    PU_ERROR_CODE_ILLUMINATION_ENABLE_CONFLICT = 10138,             //照度开关已使能  设置智能开关失败，设置遮挡失败
    PU_ERROR_CODE_VIDEOBLOCK_ENABLE_CONFLICT = 10139,               //视频遮挡已使能，设置智能开关、找到增强失败
    PU_ERROR_CODE_IGT_FAIL_BY_SWITCHOFF = 10140,                    //智能开关未使能，设置智能业务失败
    PU_ERROR_CODE_TW_ERROR_BY_OVER_NUM = 10141,                     //设置绊线条数超过最大数
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_NUM = 10142,                   //设置区域个数超过最大数4
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_TOTAL_NUM = 10143,             //设置区域个数超过最大总数10
    PU_ERROR_CODE_AREA_ERROR_BY_ZERO_NUM = 10144,                   //设置区域个数为0
    PU_ERROR_CODE_AREA_POINT_ERROR_BY_OVER_NUM = 10145,             //设置区域顶点数超过最大数
    PU_ERROR_CODE_AREA_ABN_ERROR_BY_CONFLICT = 10146,               //设置区域检物品移走，遗留使能已开启有冲突
    PU_ERROR_CODE_AREA_RMV_ERROR_BY_CONFLICT = 10147,               //设置区域检物品遗留，移走使能已开启有冲突
    PU_ERROR_CODE_VIM_GLOBAL_PARA_ERROR = 10148,                    //设置智能分析算法全局参数失败
    PU_ERROR_CODE_AREA_NOTSURPORT_ERROR = 10149,                    //设置智能分析区域无效
    PU_ERROR_CODE_PRIVACY_MASK_AREA_BEYOND = 10150,                 //隐私保护区域超出总面积
    PU_ERROR_CODE_MEDIA_ADAPT_BW_MUTEX = 10151,                     //带宽自适应与编码类型或者码率类型冲突
    PU_ERROR_CODE_IP_FILTER_RULE_SAME = 10152,                      //存在相同的IP过滤规则

    PU_ERROR_CODE_WD_FRAME_CONFLICT = 10153,                        //宽动态手动或自动，采集帧不能设置50、60
    PU_ERROR_CODE_FRAME_WD_CONFLICT = 10154,                        //采集帧为50、60，宽动态不能设置手动或自动
    PU_ERROR_CODE_CONFLICT_VIDEOBLOCK_OR_IGT_IS_ENABLE = 10155,     //视频遮挡或行为分析已使能,设置照度增强失败

    PU_ERROR_CODE_INVALID_UPDATEFILE = 13100,                       //升级文件非法
    PU_ERROR_CODE_UPDATEFILE_BAD = 13101,                           //文件损坏
    PU_ERROR_CODE_INVALID_FILE_FORMAT = 13102,                      //文件格式错误

    PU_ERROR_CODE_BUSY_CURISE = 13103,                              //正在巡航，无法设置巡航轨迹参数
    PU_ERROR_CODE_DEVICE_CLOSE = 13104,                             //设备未开启
    PU_ERROR_CODE_BUSY_PRESET = 13105,                              //预置位被使用，无法删除

    PU_ERROR_CODE_INVALID_IGT_AREA_ID = 13106,                      //智能分析区域不存在
    PU_ERROR_CODE_INVALID_IGT_LINE_ID = 13107,                      //智能分析线条不存在
    PU_ERROR_CODE_INVALID_PRIVACY_ID = 13108,                       //隐私保护区域不存在

    PU_ERROR_MAX = 20000
}PU_ERROR_CODE_E;

//前端注册模式
typedef enum PU_LINK_MODE                          
{
    PU_AUTOLOGIN_MODE = 0,                                          //主动登陆模式，初始化后前端设备主动登录到SDK，仅解码器支持
    PU_MANUALLOGIN_MODE = 1,                                        //手动登陆模式，需手动调用IVS_PU_Login登录前端设备
    PU_BOTHLOGIN_MODE = 3,                                          //以上两种登陆模式都支持，仅IPC支持

    PU_LINK_MODE_MAX
}PU_LINK_MODE_E;

//device event callback type
typedef enum PU_EVENT_TYPE
{
    /* 连接状态回调 */
    PU_EVENT_TYPE_CONNCET = 1,                                      //前端主动连接，网络连接上
    PU_EVENT_TYPE_REGISTER,                                         //前端主动注册
    PU_EVENT_TYPE_NOT_REGISTER,                                     //前端主动连接后未注册
    PU_EVENT_TYPE_UNREGISTER,                                       //前端主动注销
    PU_EVENT_TYPE_DISCONNECT,                                       //前端网络连接断开
    PU_EVENT_TYPE_SEND_RECV_ERROR,                                  //发送或接收失败
    PU_EVENT_TYPE_KEEPLIVE_FAIL,                                    //前端保活失败

    /* 事件通知回调 */
    PU_EVENT_TYPE_STREAM_PACKAGE_CHANGE,                            //流套餐变更
    PU_EVENT_TYPE_WATERMARK_ERR,                                    //数字水印校验错误
    PU_EVENT_TYPE_UPLOAD_IMAGE_URL,                                 //前端主动获取抓拍图片上传URL请求
    PU_EVENT_TYPE_UPLOAD_IMAGE_COMP_NOTIFY,                         //前端抓拍图片上载完成通知
    PU_EVENT_TYPE_TRANSPARENT_CHANNEL_NOTIFY,                       //透明通道数据上报
    PU_EVENT_TYPE_REALPALY_ERROR,                                   //实况异常

    PU_EVENT_TYPE_MAX
}PU_EVENT_TYPE_E;

//音视频编码类型
typedef enum PU_ENCODE_TYPE
{
    PU_ENC_PCMU          = 0,
    PU_ENC_1016          = 1,
    PU_ENC_G721          = 2,
    PU_ENC_GSM           = 3,
    PU_ENC_G723          = 4,
    PU_ENC_DVI4_8K       = 5,
    PU_ENC_DVI4_16K      = 6,
    PU_ENC_LPC           = 7,
    PU_ENC_PCMA          = 8,
    PU_ENC_G722          = 9,
    PU_ENC_S16BE_STEREO  = 10,
    PU_ENC_S16BE_MONO    = 11,
    PU_ENC_QCELP         = 12,
    PU_ENC_CN            = 13,
    PU_ENC_MPEGAUDIO     = 14,
    PU_ENC_G728          = 15,
    PU_ENC_DVI4_3        = 16,
    PU_ENC_DVI4_4        = 17,
    PU_ENC_G729          = 18,
    PU_ENC_G711A         = 19,                 //g711a
    PU_ENC_G711U         = 20,                 //g711u
    PU_ENC_G726          = 21,                 //g726
    PU_ENC_G729A         = 22,
    PU_ENC_LPCM          = 23,
    PU_ENC_CelB          = 25,
    PU_ENC_JPEG          = 26,
    PU_ENC_CUSM          = 27,
    PU_ENC_NV            = 28,
    PU_ENC_PICW          = 29,
    PU_ENC_CPV           = 30,
    PU_ENC_H261          = 31,
    PU_ENC_MPEGVIDEO     = 32,
    PU_ENC_MPEG2TS       = 33,
    PU_ENC_H263          = 34,
    PU_ENC_SPEG          = 35,
    PU_ENC_MPEG2VIDEO    = 36,
    PU_ENC_AAC           = 37,
    PU_ENC_WMA9STD       = 38,
    PU_ENC_HEAAC         = 39,
    PU_ENC_PCM_VOICE     = 40,
    PU_ENC_PCM_AUDIO     = 41,
    PU_ENC_AACLC         = 42,
    PU_ENC_MP3           = 43,
    PU_ENC_ADPCMA        = 49,
    PU_ENC_AEC           = 50,
    PU_ENC_X_LD          = 95,
    PU_ENC_H264          = 96,
    PU_ENC_D_GSM_HR      = 200,
    PU_ENC_D_GSM_EFR     = 201,
    PU_ENC_D_L8          = 202,
    PU_ENC_D_RED         = 203,
    PU_ENC_D_VDVI        = 204,
    PU_ENC_D_BT656       = 220,
    PU_ENC_D_H263_1998   = 221,
    PU_ENC_D_MP1S        = 222,
    PU_ENC_D_MP2P        = 223,
    PU_ENC_D_BMPEG       = 224,
    PU_ENC_MP4VIDEO      = 230,             //mepg-4
    PU_ENC_MP4AUDIO      = 237,
    PU_ENC_VC1           = 238,
    PU_ENC_JVC_ASF       = 255,
    PU_ENC_D_AVI         = 256,

    PU_ENC_AMR           = 1001,
    PU_ENC_MJPEG         = 1002,            //motion jpeg

    PU_ENC_MAX
}PU_ENCODE_TYPE_E;

//视频分辨率类型
typedef enum PU_RESOLUTION_TYPE
{
    PU_RESOLUTION_480I = 0,
    PU_RESOLUTION_576I,
    PU_RESOLUTION_QCIF_PAL,
    PU_RESOLUTION_QCIF_NTSC,
    PU_RESOLUTION_CIF_PAL,
    PU_RESOLUTION_CIF_NTSC,
    PU_RESOLUTION_2CIF,
    PU_RESOLUTION_HD1,
    PU_RESOLUTION_D1_PAL,
    PU_RESOLUTION_D1_NTSC,

    PU_RESOLUTION_QVGA,                        //320 * 240
    PU_RESOLUTION_VGA,                         //640 * 480
    PU_RESOLUTION_XGA,                         //1024 * 768
    PU_RESOLUTION_SXGA,                        //1400 * 1050
    PU_RESOLUTION_UXGA,                        //1600 * 1200
    PU_RESOLUTION_QXGA,                        //2048 * 1536

    PU_RESOLUTION_WVGA,                        //854 * 480
    PU_RESOLUTION_WSXGA,                       //1680 * 1050
    PU_RESOLUTION_WUXGA,                       //1920 * 1200
    PU_RESOLUTION_WQXGA,                       //2560 * 1600

    PU_RESOLUTION_HD720,                       //1280 * 720
    PU_RESOLUTION_HD1080,                      //1920 * 1080
    PU_RESOLUTION_HD1080I,

    PU_RESOLUTION_MAX
}PU_RESOLUTION_TYPE_E;

//视频流模式
typedef enum PU_STREAM_MODE_E
{
    PU_VIEDO_STREAM_NONE   = 0,             //不设置流套餐
    PU_VIEDO_STREAM_SINGLE = 1,             //视频单流
    PU_VIEDO_STREAM_DOUBLE = 2,             //视频双流
    PU_VIEDO_STREAM_TRIPLE = 3,             //视频三流
    PU_VIEDO_STREAM_FOUR   = 4,             //视频四流
    PU_VIEDO_STREAM_MAX
}PU_STREAM_MODE_E;

//视频流类型
typedef enum PU_STREAM_TYPE
{
    PU_VIDEO_MAIN_STREAM = 0,                //视频主码流
    PU_VIDEO_SUB_STREAM1,                    //视频子码流1
    PU_VIDEO_SUB_STREAM2,                    //视频子码流2
    PU_VIDEO_SUB_STREAM3,                    //视频子码流3
    PU_VIDEO_STREAM_MAX
}PU_STREAM_TYPE_E;

//图像质量
typedef enum PU_PIC_QUALITY                                          
{
    PU_PIC_QUALITY_BEST = 0,                //最好
    PU_PIC_QUALITY_MORE_BETTER,             //次好
    PU_PIC_QUALITY_BETTER,                  //较好
    PU_PIC_QUALITY_ORDINARY,                //一般
    PU_PIC_QUALITY_BAD,                     //较差
    PU_PIC_QUALITY_BADEST,                  //差
    PU_PIC_QUALITY_MAX
}PU_PIC_QUALITY_E;

//传输类型
typedef enum PU_PROTOCOL_TYPE
{
    PU_PROTOCOL_TYPE_UDP = 0,                  //UDP方式
    PU_PROTOCOL_TYPE_TCP,                      //TCP方式
    PU_PROTOCOL_TYPE_MULTICAST,                //组播方式
    PU_PROTOCOL_TYPE_MAX
}PU_PROTOCOL_TYPE_E;

//媒体回调类型
typedef enum PU_MEDIA_CALLBACK_TYPE
{
    PU_MEDIA_CALLBACK_TYPE_RTP = 0,         //RTP包方式
    PU_MEDIA_CALLBACK_TYPE_RTP_CRYPTO,      //RTP包形式，不解密
    PU_MEDIA_CALLBACK_TYPE_FRAME,           //帧回调方式
    PU_MEDIA_CALLBACK_TYPE_YUV,             //YUV方式，Linux不支持
    PU_MEDIA_CALLBACK_TYPE_MAX
}PU_MEDIA_CALLBACK_TYPE_E;

//流类型
typedef enum PU_VIDEO_TYPE
{
    PU_VIDEO_TYPE_VIDEO = 0,                    //视频流
    PU_VIDEO_TYPE_AUDIO,                        //音频流
    PU_VIDEO_TYPE_MUX,                          //复合流
    PU_VIDEO_TYPE_RECORD,                       //录像流
    PU_VIDEO_TYPE_MAX
}PU_VIDEO_TYPE_E;

//媒体加密类型
typedef enum PU_MEDIA_CRYPTO_TYPE
{
    PU_MEDIA_CRYPTO_NONE = 0,               //不加密
    PU_MEDIA_CRYPTO_HW_SIMPLE = 1,          //华为加密
    PU_MEDIA_CRYPTO_AES_128BIT = 2,         //128位AES加密
    PU_MEDIA_CRYPTO_AES_192BIT = 3,         //192位AES加密
    PU_MEDIA_CRYPTO_AES_256BIT = 4,         //256位AES加密
    PU_MEDIA_CRYPTO_MAX,
}PU_MEDIA_CRYPTO_TYPE_E;

//码率类型
typedef enum PU_BIT_RATE_TYPE
{
    PU_BIT_RATE_TYPE_FIXED = 0,             //定码率
    PU_BIT_RATE_TYPE_VARIABLE,              //变码率
    PU_BIT_RATE_TYPE_QP,                    //MJPEG码流
    PU_BIT_RATE_TYPE_MAX
}PU_BITRATE_TYPE_E;

//视频制式
typedef enum PU_VIDEO_FORMAT
{
    PU_VIDEO_FORMAT_PAL = 0,                //P制
    PU_VIDEO_FORMAT_NTSC,                   //N制
    PU_VIDEO_FORMAT_MAX
}PU_VIDEO_FORMAT_E;

/*帧率优先码率优先*/
typedef enum PU_H264_RC_PRI
{
    PU_H264_RC_FRAMERATE_PRI = 1,           //帧率优先
    PU_H264_RC_BITRATE_PRI,                 //码流优先

    PU_H264_RC_PRI_MAX
}PU_H264_RC_PRI_E;

//语言类型
typedef enum PU_LANGUAGE_TYPE
{
    PU_LANGUAGE_TYPE_CHINESE = 0,              //中文
    PU_LANGUAGE_TYPE_ENGLISH,                  //英文
    PU_LANGUAGE_TYPE_MAX
}PU_LANGUAGE_TYPE_E;

//本地保存录像方式
typedef enum PU_SAVE_REALDATA_TYPE
{
    PU_SAVE_REALDATA_TYPE_TIME = 0,         //按时间保存(单位：min)
    PU_SAVE_REALDATA_TYPE_SIZE = 1,         //按大小保存(单位：MBytes)
    PU_SAVE_REALDATA_TYPE_MAX
}PU_SAVE_REALDATA_TYPE_E;

//本地保存图片方式
typedef enum PU_SAVE_PICTURE_TYPE
{
    PU_SAVE_PICTURE_TYPE_BMP = 0,              //BMP文件
    PU_SAVE_PICTURE_TYPE_JEPG = 1,             //JPEG文件
    PU_SAVE_PICTURE_TYPE_MAX
}PU_SAVE_PICTURE_TYPE_E;

//串口类型
typedef enum PU_SERIAL_PORT_MODE
{
    PU_SERIAL_PORT_RS232 = 0,                  //232串口
    PU_SERIAL_PORT_RS422,                      //422串口
    PU_SERIAL_PORT_RS485,                      //485串口
    PU_SERIAL_PORT_MAX
}PU_SERIAL_PORT_MODE_E;

//波特率
typedef enum PU_BAUD_RATE
{
    PU_BAUD_R2400 = 0,
    PU_BAUD_R4800,
    PU_BAUD_R9600,
    PU_BAUD_R19200,
    PU_BAUD_R38400,
    PU_BAUD_R57600,
    PU_BAUD_R115200,
    PU_BAUD_R230400,
    PU_BAUD_R460800,
    PU_BAUD_R921600,
    PU_BAUD_MAX
}PU_BAUD_RATE_E;

//数据位
typedef enum PU_DATA_BIT
{
    PU_DATA_BIT_CS5 = 0,
    PU_DATA_BIT_CS6,
    PU_DATA_BIT_CS7,
    PU_DATA_BIT_CS8,
    PU_DATA_BIT_MAX
}PU_DATA_BIT_E;

//校验位
typedef enum PU_PARITY_BIT
{
    PU_PARITY_BIT_NONE = 0,
    PU_PARITY_BIT_ODD,
    PU_PARITY_BIT_EVEN,
    PU_PARITY_BIT_MARK,
    PU_PARITY_BIT_SPACE,
    PU_PARITY_BIT_MAX
}PU_PARITY_BIT_E;

//停止位
typedef enum PU_STOP_BIT
{
    PU_STOP_BIT_OFF = 0,
    PU_STOP_BIT_ON,
    PU_STOP_BIT_MAX
}PU_STOP_BIT_E; 

//串口流控制类型
typedef enum PU_FLOW_CONTROL
{
    PU_FLOW_CONTROL_NONE = 0,
    PU_FLOW_CONTROL_SOFT,
    PU_FLOW_CONTROL_HARD,
    PU_FLOW_CONTROL_MAX
}PU_FLOW_CONTROL_E;

//云台解码器类型
typedef enum PU_PTZ_DECODER_TYPE
{
    PU_PTZ_DECODER_PELCO_P = 1,
    PU_PTZ_DECODER_PELCO_D,
    PU_PTZ_DECODER_YAAN,
    PU_PTZ_DECODER_SAMSUNG,
    PU_PTZ_DECODER_REDAPPLE_5052,
    PU_PTZ_DECODER_TAISHUO,
    PU_PTZ_DECODER_REDAPPLE_5051,
    PU_PTZ_DECODER_USER_DEF,
    PU_PTZ_DECODER_MAX
}PU_PTZ_DECODER_TYPE_E;

//正反向控制
typedef enum PU_PTZ_CONTROL_MODE
{
    PU_PTZ_CONTROL_MODE_FORWARD = 1,
    PU_PTZ_CONTROL_MODE_BACK,
    PU_PTZ_CONTROL_MODE_MAX
}PU_PTZ_CONTROL_MODE_E;

//告警布防
typedef enum PU_ALARM_ACTION
{
    PU_ALARM_ACTION_MOVE = 1,                  //告警移除
    PU_ALARM_ACTION_HAPPEN,                    //告警发生
    PU_ALARM_ACTION_MAX
}PU_ALARM_ACTION_E;

// 云台控制
typedef enum PU_PTZ_OPCODE
{
    PU_PTZ_STOP = 1,                            //云台停止,忽略para1、para2
    PU_PTZ_UP = 2,                              //云台向上,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_DOWN = 3,                            //云台向下,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_LEFT = 4,                            //云台向左,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_UP_LEFT = 5,                         //云台左上,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_DOWN_LEFT = 6,                       //云台左下,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_RIGHT = 7,                           //云台向右,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_UP_RIGHT = 8,                        //云台右上,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_DOWN_RIGHT = 9,                      //云台右下,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_AUTO = 10,                           //云台自动,忽略para1、para2
    PU_PTZ_PRESET_RUN = 11,                     //预置位运行,para1代表预置位序号,忽略para2
    PU_PTZ_CRUISE_RUN = 12,                     //巡航轨迹运行,para1代表巡航轨迹序号,忽略para2
    PU_PTZ_CRUISE_STOP = 13,                    //巡航轨迹停止,忽略para1、para2
    PU_PTZ_FLIP = 17,                           //云台翻转180度,忽略para1、para2
    PU_PTZ_HOMING = 18,                         //云台归位,忽略para1、para2

    // 镜头控制
    PU_PTZ_LENS_APERTURE_OPEN = 19,             //光圈放大,para1固定为连续模式(2),para2代表速度
    PU_PTZ_LENS_APERTURE_CLOSE = 20,            //光圈缩小,para1固定为连续模式(2),para2代表速度
    PU_PTZ_LENS_ZOOM_IN = 21,                   //范围放大,para1固定为连续模式(2),para2代表速度
    PU_PTZ_LENS_ZOOM_OUT = 22,                  //范围缩小,para1固定为连续模式(2),para2代表速度
    PU_PTZ_LENS_ZOOM_STOP = 23,                 //缩放关闭
    PU_PTZ_LENS_FOCAL_NEAR = 24,                //聚焦近,para1固定为连续模式(2),para2代表速度（范围1-10）
    PU_PTZ_LENS_FOCAL_FAR = 25,                 //聚焦远,para1固定为连续模式(2),para2代表速度（范围1-10）
    PU_PTZ_LENS_FOCAL_STOP = 26,                //聚焦关闭
    PU_PTZ_AUX_OPEN = 27,                       //辅助设备打开,para1代表设备名称,,忽略para2
    PU_PTZ_AUX_STOP = 28,                       //辅助设备关闭,para1代表设备名称,忽略para2

    PU_PTZ_HORIZONTAL_SCAN = 29,                //水平扫描,para1固定为连续模式,para2代表速度（范围1-10）
    PU_PTZ_VERTICAL_SCAN = 30,                  //垂直扫描,para1固定为连续模式,para2代表速度（范围1-10）

    PU_PTZ_MODE_SET_START =31,                  //花样轨迹记录开始
    PU_PTZ_MODE_SET_STOP =32,                   //花样轨迹记录停止
    PU_PTZ_FAST_LOCATE =33,                     //3d定位
    PU_PTZ_FAST_RETURN =34,                     //3d返回
    PU_PTZ_REBOOT = 35,                         //机电板重启
    PU_PTZ_RESTORE = 36,                        //机电板恢复默认配置
    PU_PTZ_SET_LEFT_LIMIT = 37,                 //设置左限位
    PU_PTZ_SET_RIGHT_LIMIT = 38,                //设置右限位
    PU_PTZ_MODE_CRUISE_START =39,               //花样轨迹开始 para1代表巡航轨迹序号,忽略para2
    PU_PTZ_MODE_CRUISE_STOP =40,                //花样轨迹停止para1代表巡航轨迹序号,忽略para2
    PU_PTZ_FAST_MOVE =41,                       //点选快速定位.para1表示x坐标、para2表示y坐标

    PU_PTZ_CMD_MAX
}PU_PTZ_OPCODE_E;
                                            
//云台运动模式
typedef enum PU_PTZ_MOTION_MODE
{
    PU_PTZ_MOTION_MODE_BURST = 1,               //点动模式
    PU_PTZ_MOTION_MODE_CONTINUOUS,              //连续模式

    PU_PTZ_MOTION_MODE_MAX
}PU_PTZ_MOTION_MODE_E;

//云台预置位操作命令字
typedef enum PU_PTZ_PRESET_CMD
{
    PU_PTZ_PRESET_SET = 1,                      //设置预置位
    PU_PTZ_PRESET_GET,                          //获取预置位
    PU_PTZ_PRESET_CLR,                          //清除预置位
    PU_PTZ_PRESET_GOTO,                         //转到预置位
    PU_PTZ_PRESET_MAX
}PU_PTZ_PRESET_CMD_E;

//巡航轨迹操作命令字
typedef enum PU_PTZ_CRUISE_TRACK
{
    PU_PTZ_CRUISE_TRACK_SET = 1,                //设置巡航轨迹
    PU_PTZ_CRUISE_TRACK_GET,                    //获取巡航轨迹
    PU_PTZ_CRUISE_TRACK_CLR,                    //清除巡航轨迹
    PU_PTZ_CRUISE_TRACK_GOTO,                   //云台巡航
    PU_PTZ_CRUISE_TRACK_STOP,                   //停止巡航
    PU_PTZ_CRUISE_TRACK_MAX
}PU_PTZ_CRUISE_TRACK_E;

typedef enum PU_OSD_DATE_TYPE
{
    PU_YYYY_MM_DD = 0,                          //YYYY-MM-DD
    PU_MM_DD_YYYY,                              //MM-DD-YYYY
    PU_YYYY_MM_DD_CH,                           //年-月-日
    PU_MM_DD_YYYY_CH,                           //月-日-年
    PU_DD_MM_YYYY,                              //DD-MM-YYYY

    PU_OSD_DATA_TYPE_MAX
}PU_OSD_DATE_TYPE_E;

//告警类型
typedef enum PU_ALARM_TYPE
{
    PU_ALARM_TYPE_DI = 1,                       //开关量输入
    PU_ALARM_TYPE_DISK_FULL,                    //硬盘满告警
    PU_ALARM_TYPE_NO_SIGNAL,                    //无视频告警（视频丢失）
    PU_ALARM_TYPE_MOVE_DECTION,                 //移动侦测告警
    PU_ALARM_TYPE_DISK_FAULT,                   //硬盘故障
    PU_ALARM_TYPE_SHIELD,                       //遮挡告警，包括智能遮挡告警
    PU_ALARM_TYPE_NETWORK_INTERRUPT,            //网络中断
    PU_ALARM_TYPE_IP_ADDRESS_CONFLICT,          //IP冲突
    PU_ALARM_TYPE_TEMPERATURE,                  //温度告警
    PU_ALARM_TYPE_FACE_DETECTION,               //人脸检测
    PU_ALARM_TYPE_INVADE,                       //
    PU_ALARM_TYPE_COUNT,                        //目标计数
    PU_ALARM_TYPE_DISTURB,                      //干扰检测

    /* 智能告警 */
    PU_ALARM_TYPE_TRIPWIRE = 14,                //绊线检测
    PU_ALARM_TYPE_INTRUSION = 15,               //入侵检测
    PU_ALARM_TYPE_HOVER = 16,                   //徘徊检测
    PU_ALARM_TYPE_LEGACY = 17,                  //物体遗留检测
    PU_ALARM_TYPE_REMOVE = 18,                  //物体丢失检测

    PU_ALARM_TYPE_MAX                           //预留
}PU_ALARM_TYPE_E;

//平台类型(平台配置)
typedef enum PU_PLATFORM_TYPE
{
    PU_PLATFORM_TYPE_NVS = 1,                   //NVS平台
    PU_PLATFORM_TYPE_IVS = 2,                   //IVS平台
    PU_PLATFORM_TYPE_GBT,                       //28281平台
    PU_PLATFORM_TYPE_IVS_ENABLE,                //IVS平台，带使能
    PU_PLATFORM_TYPE_GBT_ENABLE,                //28281平台，带使能
    PU_PLATFORM_TYPE_SDK_ENABLE,                //SDK平台参数，带使能
    PU_PLATFORM_TYPE_OTHERS,
    PU_PLATFORM_TYPE_MAX
}PU_PLATFORM_TYPE_E;

typedef enum PU_SDK_PLATFORM_MODE_E
{
    PU_SDK_PALTFORM_MODE_SINGEL = 1,           //单服务器模式
    PU_SDK_PLATFORM_MODE_DUAL,                 //双服务器模式
    PU_SDK_PLATFORM_MODE_MAX
}PU_SDK_PLATFORM_MODE_E;

//日志类型
typedef enum PU_LOG_TYPE
{
    PU_LOG_TYPE_OPERATION = 1,                  //操作日志
    PU_LOG_TYPE_EXCEPT,                         //异常日志
    PU_LOG_TYPE_ALARM,                          //告警日志
    PU_LOG_TYPE_MAX
}PU_LOG_TYPE_E;

//解码器类型定义

//分辨率模式
typedef enum PU_DISRESOLUTION_MODE
{
    PU_VGA_NOT_AVALIABLE,
    PU_VGA_MODE_SVGA_60HZ = 1,
    PU_VGA_MODE_SVGA_75HZ,
    PU_VGA_MODE_XGA_60HZ,
    PU_VGA_MODE_XGA_70HZ,
    PU_VGA_MODE_SXGA_60HZ,
    PU_VGA_MODE_720P_60HZ,
    PU_VGA_MODE_1080I_60HZ,
    PU_VGA_MODE_1080P_30HZ,
    PU_VGA_MODE_UXGA_30HZ,
    PU_HDMI_MODE_XGA_60HZ = 21,
    PU_HDMI_MODE_SXGA_60HZ,
    PU_HDMI_MODE_SXGA2_60HZ,
    PU_HDMI_MODE_720P_60HZ,    
    PU_HDMI_MODE_720P_50HZ,        
    PU_HDMI_MODE_1080I_60HZ,
    PU_HDMI_MODE_1080I_50HZ,
    PU_HDMI_MODE_1080P_25HZ,
    PU_HDMI_MODE_1080P_30HZ,
    PU_HDMI_MODE_1080P_50HZ,
    PU_HDMI_MODE_1080P_60HZ,
    PU_HDMI_MODE_UXGA_60HZ,
    PU_DVI_MODE_XGA_60HZ = 41,
    PU_DVI_MODE_SXGA_60HZ,
    PU_DVI_MODE_SXGA2_60HZ,
    PU_DVI_MODE_720P_60HZ,    
    PU_DVI_MODE_720P_50HZ,        
    PU_DVI_MODE_1080I_60HZ,
    PU_DVI_MODE_1080I_50HZ,
    PU_DVI_MODE_1080P_25HZ,
    PU_DVI_MODE_1080P_30HZ,
    PU_DVI_MODE_1080P_50HZ,
    PU_DVI_MODE_1080P_60HZ,
    PU_DVI_MODE_UXGA_60HZ,
    PU_BNC_MODE_D1PAL_60HZ = 61,
    PU_BNC_MODE_D1PAL_50HZ,
    PU_BNC_MODE_D1NTSC_60HZ,
    PU_BNC_MODE_D1NTSC_50HZ,

    PU_DISRESOLUTION_MODE_MAX
}PU_DISRESOLUTION_MODE_E;

//端口类型
typedef enum PU_PORT_TYPE
{
    PU_PORT_TYPE_HDMI = 0,
    PU_PORT_TYPE_VGA = 1,
    PU_PORT_TYPE_BNC = 2,
    PU_PORT_TYPE_DVI = 3,

    PU_PORT_TYPE_MAX
}PU_PORT_TYPE_E;

//端口模式
typedef enum PU_PORT_MODE
{
    PU_PORT_MODE_1 = 1,                        //1画面
    PU_PORT_MODE_2 = 2,                        //2画面
    PU_PORT_MODE_4 = 4,                        //4画面
    PU_PORT_MODE_9 = 9,                        //9画面
    PU_PORT_MODE_16 = 16,                      //16画面

    PU_PORT_MODE_MAX
}PU_PORT_MODE_E;

//帧率
typedef enum PU_FRAME_RATE
{
    PU_FRAME_RATE_30 = 0,
    PU_FRAME_RATE_50,
    PU_FRAME_RATE_60
}PU_FRAME_RATE_E;

//码流加密类型
typedef enum PU_ENCRYPT_TYPE
{
    PU_ENCRYPT_TYPE_HUAWEI_VIDEO = 0,          //实行华为码流加密算法,加密视频
    PU_ENCRYPT_TYPE_HUAWEI_AUDIO,              //实行华为码流加密算法,加密音频
    PU_ENCRYPT_TYPE_HUAWEI_MUX,                //实行华为码流加密算法,加密复合流
    PU_ENCRYPT_TYPE_NONE,                      //不实行码流加密
    PU_ENCRYPT_TYPE_MAX
}PU_ENCRYPT_TYPE_E;

//音频端口类型
typedef enum PU_AUDIO_PORT_TYPE
{
    PU_AUDIO_PORT_TYPE_BNC_PLAY = 0,           //BNC放音端口
    PU_AUDIO_PORT_TYPE_HDMI_PLAY = 1,          //HDMI放音端口

    PU_AUDIO_PORT_TYPE_MAX
}PU_AUDIO_PORT_TYPE_E;

//音频采样率
typedef enum PU_AUDIO_SAMPLERATE
{
    PU_AUDIO_SAMPLERATE_8000 = 8000,
    PU_AUDIO_SAMPLERATE_12000 = 12000,
    PU_AUDIO_SAMPLERATE_11025 = 11025,
    PU_AUDIO_SAMPLERATE_16000 = 16000,
    PU_AUDIO_SAMPLERATE_22050 = 22050,
    PU_AUDIO_SAMPLERATE_24000 = 24000,
    PU_AUDIO_SAMPLERATE_32000 = 32000,
    PU_AUDIO_SAMPLERATE_44100 = 44100,
    PU_AUDIO_SAMPLERATE_48000 = 48000,

    PU_AUDIO_SAMPLERATE_MAX
}PU_AUDIO_SAMPLERATE_E, *LPPU_AUDIO_SAMPLERATE_E;

//G726编码格式的码率
typedef enum PU_AUDIO_G726_BPS
{
    PU_AUDIO_G726_16K = 0,                  /* G726 16kbps, */ 
    PU_AUDIO_G726_24K,                      /* G726 24kbps, */
    PU_AUDIO_G726_32K,                      /* G726 32kbps, */
    PU_AUDIO_G726_40K,                      /* G726 40kbps, */
    PU_AUDIO_G726_MAX,
}PU_AUDIO_G726_BPS_E;

/* 视频昼夜模式  */
typedef enum PU_VIDEO_DAYNIGHT_MODE
{
    PU_VIDEO_DAYNIGHT_MODE_AUTO = 0,           //自动模式
    PU_VIDEO_DAYNIGHT_MODE_COLOR,              //彩色模式
    PU_VIDEO_DAYNIGHT_MODE_GRAY,               //黑白模式
    PU_VIDEO_DAYNIGHT_MODE_MAX
}PU_VIDEO_DAYNIGHT_MODE_E;

/* 图像镜像和旋转方式 */
typedef enum PU_VIDEO_MIRROR_MODE
{
    PU_VIDEO_MIRROR_MODE_NORMAL = 0,           //正常图像
    PU_VIDEO_MIRROR_MODE_MIRROR,               //左右镜像
    PU_VIDEO_MIRROR_MODE_FLIP,                 //上下
    PU_VIDEO_MIRROR_MODE_BOTH,                 //上下左右
    PU_VIDEO_MIRROR_MODE_MAX
}PU_VIDEO_MIRROR_MODE_E;

/* 背景频率  */
typedef enum PU_VIDEO_FLICKER_MODE
{
    PU_VIDEO_FLICKER_NONE = 0,                 //关闭
    PU_VIDEO_FLICKER_50HZ,                     //50HZ
    PU_IDEO_FLICKER_60HZ,                      //60HZ

    PU_VIDEO_FLICKER_MAX
}PU_VIDEO_FLICKER_MODE_E;

/* 测光模式 */
typedef enum PU_VIDEO_AEMETERING_MODE
{
    PU_VIDEO_AEMETERING_CENTER = 0,            //中心测光
    PU_VIDEO_AEMETERING_SPOT,                  //中心点测光
    PU_VIDEO_AEMETERING_AVERAGE,               //平均测光
    PU_VIDEO_AEMETERING_BACKLIGHT,             //背光测光

    PU_VIDEO_AEMETERING_MAX
}PU_VIDEO_AEMETERING_MODE_E;

/* AE曝光模式 */
typedef enum PU_AE_MODE
{
    PU_AE_MODE_AUTO = 0,                       //自动曝光，自动光圈增益、固定的快门值
    PU_AE_MODE_MANUAL,                         //手动曝光
    PU_AE_MODE_SHUTTER_PRI,                    //快门优先
    PU_AE_MODE_IRIS_PRI,                       //光圈优先
    PU_AE_MODE_LOW_NOISE,                      //噪声优先
    PU_AE_MODE_FRAME_RATE,                     //帧率优先
    PU_AE_MODE_BRIGHT,                         //亮度优先

    PU_AE_MODE_MAX
}PU_AE_MODE_E;

//宽动态模式
typedef enum PU_WDR_SWITCH_MODE
{
    PU_WDR_SWITCH_AUTO,                     //自动模式
    PU_WDR_SWITCH_CLOSE,                    //关闭
    PU_WDR_SWITCH_MANUAL,                   //手动模式
    PU_WDR_SWITCH_MAX,
}PU_WDR_SWITCH_MODE_E;

/*抓拍类型*/
typedef enum PU_SNAPSHOT_TYPE
{
    PU_SNAPSHOT_TYPE_MANUAL = 0,               //手动抓拍
    PU_SNAPSHOT_TYPE_ALARM,                    //告警抓拍
    PU_SNAPSHOT_TYPE_TIMER,                    //定时抓拍
    PU_SNAPSHOT_TYPE_MANUAL_EX,                //
    PU_SNAPSHOT_TYPE_MAX
}PU_SNAPSHOT_TYPE_E;

//业务类型
typedef enum PU_BUSINESS_TYPE
{
    PU_BUSINESS_REAL_VIDEO = 0,                //实时浏览
    PU_BUSINESS_AUDIO_TALK,                    //语音对讲
    PU_BUSINESS_AUDIO_BROADCAST,               //语音广播
    PU_BUSINESS_RECORD_DOWNLOAD,               //录像下载
    PU_BUSINESS_RECORD_PLAY_BACK,              //录像回放

    PU_BUSINESS_TYPE_MAX
}PU_BUSINESS_TYPE_E;

//视频流的传输类型
typedef enum PU_VIDEO_CODE_TYPE
{
    PU_VIDEO_CODE_TYPE_ES,                     //ES流
    PU_VIDEO_CODE_TYPE_PS,                     //PS流
    PU_VIDEO_CODE_TYPE_TS,                     //TS流
    PU_VIDEO_CODE_TYPE_MAX
}PU_VIDEO_CODE_TYPE_E;

typedef enum PU_RECORD_TYPE
{
    PU_RECORD_TYPE_ALARM = 0,               //告警录像
    PU_RECORD_TYPE_MANUAL,                  //手动录像
    PU_RECORD_TYPE_TIMING,                  //计划录像
    PU_RECORD_TYPE_MAX,
}PU_RECORD_TYPE_E;

/* 硬盘类型 */
typedef enum PU_DISK_TYPE
{
    PU_DISK_TYPE_IDE = 0,
    PU_DISK_TYPE_SATA,
    PU_DISK_TYPE_FLASH,

    PU_DISK_TYPE_UNKNOWN
}PU_DISK_TYPE_E;

typedef enum PU_FEC_PACKET_LOSS_RATIO
{
    PU_FEC_PACKET_LOSS_RATIO_1 = 0,                  /**<  0: 1%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_2 = 1,                  /**<  1: 2%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_3 = 2,                  /**<  2: 3%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_4 = 3,                  /**<  3: 4%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_5 = 4,                  /**<  4: 5%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_MAX
} PU_FEC_PACKET_LOSS_RATIO_E;

//颜色
typedef enum PU_COLOR_TYPE
{
    PU_COLOR_BLACK = 0,
    PU_COLOR_WHITE,
    PU_COLOR_MAX
}PU_COLOR_TYPE_E;

//透明度
typedef enum PU_ALPHA_TYPE
{
    PU_ALPHA_NONE = 0,
    PU_ALPHA_HALF,
    PU_ALPHA_ALL,
    PU_ALPHA_MAX
}PU_ALPHA_TYPE_E;

typedef enum PU_DSCP_TYPE
{
    PU_DSCP_TYPE_MEDIA = 0,                 //媒体DSCP值 包括音频和视频
    PU_DSCP_TYPE_CMD,                       //信令DSCP值 包含告警
    PU_DSCP_TYPE_MAX
}PU_DSCP_TYPE_E;

/*智能区域检测类型*/
typedef enum PU_IGT_AREA_ALARM_TYPE
{
    PU_IGT_TYPE_INTRUSION  = 0,             //入侵检测
    PU_IGT_TYPE_HOVER,                      //徘徊检测
    PU_IGT_TYPE_LEGACY,                     //遗留检测
    PU_IGT_TYPE_REMOVE,                     //移走检测
    PU_IGT_TYPE_MAX
}PU_IGT_AREA_ALARM_TYPE_E;  

/* 智能场景使能 */
typedef enum PU_IGT_FIELD_TYPE
{
    PU_IGT_FIELD_LONGSHOT = 0,              //远景
    PU_IGT_FIELD_CLOSESHOT = 1,             //近景
    PU_IGT_FIELD_MAX
}PU_IGT_FIELD_TYPE_E;

/* 前景目标尺寸设置 */
typedef enum PU_IGT_MINTARGET_SIZE
{
    PU_IGT_TARGETSIZE_SMALL = 0,            //小目标
    PU_IGT_TARGETSIZE_MIDDLE = 1,           //中目标
    PU_IGT_TARGETSIZE_BIG = 2,              //大目标
    PU_IGT_TARGETSIZE_MAX
}PU_IGT_MINTARGET_SIZE_E;

/* 去阴影模式 */
typedef enum PU_IGT_SHADOW_MODE
{
    PU_IGT_SHADOW_WEAK = 0,                 //弱阴影
    PU_IGT_SHADOW_COMMON = 1,               //普通阴影
    PU_IGT_SHADOW_STRONG = 2,               //强阴影
    PU_IGT_SHADOW_MAX
}PU_IGT_SHADOW_MODE_E;

/* 灵敏度设置 */
typedef enum PU_IGT_DETECT_SENS
{
    PU_IGT_SENS_LOW = 0,                    //低灵敏度
    PU_IGT_SENS_MIDDLE = 1,                 //中灵敏度
    PU_IGT_SENS_HIGH = 2,                   //高灵敏度
    PU_IGT_SENS_MAX
}PU_IGT_DETECT_SENS_E;

/* 智能目标识别模式 */
typedef enum PU_IGT_TARGET_MODE
{
    PU_IGT_TARGETMODE_CENTRE = 0,           //中心
    PU_IGT_TARGETMODE_BOTTOM = 1,           //底部
    PU_IGT_TARGETMODE_TOP = 2,              //顶部
    PU_IGT_TARGETMODE_MAX
}PU_IGT_TARGET_MODE_E;

typedef enum PU_IRLIGHT_MODE
{
    PU_IRLIGHT_MODE_ATUO = 0,               //自动
    PU_IRLIGHT_MODE_MANUAL,                 //手动

    PU_IRLIGHT_MODE_MAX
}PU_IRLIGHT_MODE_E;

typedef enum PU_IGT_OPT_TYPE
{
    PU_IGT_OPT_TYPE_ADD = 0,                //新增：需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的所有信息
    PU_IGT_OPT_TYPE_MOD = 1,                //修改：需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的所有信息
    PU_IGT_OPT_TYPE_DEL = 2,                //删除：只需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的channelid和index
    PU_IGT_OPT_TYPE_MOV = 3,                /*移动至添加绊线或区域时的视图：只需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的channelid和index，*/
                                            /*具体绊线或坐标信息同时会作为出参带回来*/
    PU_IGT_OPT_TYPE_MAX
}PU_IGT_OPT_TYPE_E;

/********************************结构体**********************************************/
//设备版本
typedef struct PU_DEVICE_VERSION
{
    CHAR szVerSoftware[PU_VERSION_LEN];        //软件版本        
    CHAR szVerUboot[PU_VERSION_LEN];           //UBoot版本
    CHAR szVerKernel[PU_VERSION_LEN];          //内核版本
    CHAR szVerHardware[PU_VERSION_LEN];        //硬件版本
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_VERSION, *LPPU_DEVICE_VERSION;

//设备信息结构
typedef struct PU_DEVICE_INFO
{
    CHAR szDeviceName[PU_DEVICE_NAME_LEN];    //设备名称最长32位
    CHAR szDeviceFac[PU_FAC_NAME_LEN];        //设备厂商
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];    //设备型号,只可查询不可设置
    CHAR szSerialNumber[PU_SERIAL_LEN];       //硬件序列号
    PU_DEVICE_VERSION stDeviceVersion;        //设备版本
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICEINFO_S, *LPPU_DEVICEINFO_S;

//视频参数结构
typedef struct PU_VIDEO_ATTRIBUTE
{
    ULONG    ulBitRate;                        //码率
    ULONG    ulIFrameInterval;                 //I帧间隔
    ULONG    ulFrameRate;                      //帧率
    PU_ENCODE_TYPE_E enVideoEncodeMode;        //视频编码类型
    PU_RESOLUTION_TYPE_E  enResolution;        //分辨率
    PU_BITRATE_TYPE_E     enBitRateType;       //码率类型
    PU_PIC_QUALITY_E      enPicQuality;        //图像质量
    PU_VIDEO_FORMAT_E     enVideoFormat;       //图像制式
    PU_H264_RC_PRI_E      enRcPriMode;         //帧率优先码率优先模式,仅H264下有效
    PU_VIDEO_MIRROR_MODE_E enMirrorMode;       //镜像模式
    CHAR  szReserve[PU_RESERVE_LEN];           //预留
}PU_VIDEO_ATTRIBUTE_S, *LPPU_VIDEO_ATTRIBUTE_S;

//视频流信息结构
typedef struct PU_STREAM_ATTRIBUTE
{
    PU_STREAM_TYPE_E enStreamId;                                    //码流类型
    PU_VIDEO_ATTRIBUTE_S stVideoAttribute;                          //视频流参数
}PU_STREAM_ATTRIBUTE_S, *LPPU_STREAM_ATTRIBUTE_S;

//视频流信息
typedef struct PU_VIDEO_STREAM_INFO
{
    ULONG ulChannelId;                                              //通道ID
    PU_STREAM_MODE_E enStreamMode;                                  //视频流类型
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_VIEDO_STREAM_TRIPLE];//视频属性
    CHAR szReserved[PU_RESERVE_LEN];
}PU_VIDEO_STREAM_INFO_S, *LPPU_VIDEO_STREAM_INFO_S;

//音频流信息
typedef struct PU_AUDIO_INFO
{
    ULONG ulAudioChannelId;                                         //音频通道ID
    PU_ENCODE_TYPE_E enAudioEncodeMode;                             //音频编码类型
    ULONG ulInputVolume;                                            //输入音量
    ULONG ulOutputVolume;                                           //输出音量
    PU_AUDIO_G726_BPS_E enAudioRate;                                //音频G726码率
    CHAR szReserved[PU_RESERVE_LEN];
}PU_AUDIO_INFO_S, *LPPU_AUDIO_INFO_S;

//视频显示效果结构体
typedef struct PU_VIDEO_DISPLAY_INFO
{
    ULONG ulChannelId;                      //通道ID
    LONG lBrightValue;                      //亮度
    LONG lHueValue;                         //色度
    LONG lSaturationValue;                  //饱和度
    LONG lContrastValue;                    //对比度
    LONG lSharpValue;                       //锐度
    CHAR szReserved[PU_RESERVE_LEN];
}PU_VIDEO_DISPLAY_INFO_S, *LPPU_VIDEO_DISPLAY_INFO_S;

//ROI矩形参数结构体
typedef struct PU_ROI_AREA_INFO
{
    LONG lQuality;                          //图像质量：
    ULONG ulPointX;                         //ROI区域X坐标
    ULONG ulPointY;                         //ROI区域Y坐标
    ULONG ulWidth;                          //ROI区域宽度
    ULONG ulHeight;                         //ROI区域高度
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ROI_AREA_INFO_S, *LPPU_ROI_AREA_INFO_S;

//ROI参数结构体
typedef struct PU_ROI_INFO
{
    ULONG ulChannelId;                      //通道ID
    PU_STREAM_TYPE_E enStreamId;            //码流ID
    LONG lEnable;                           //使能
    ULONG ulROINum;                         //有效的ROI区域数目
    PU_ROI_AREA_INFO_S stROIAreaInfo[PU_ROI_AREA_NUM_MAX];             //ROI矩形参数
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ROI_INFO_S, *LPPU_ROI_INFO_S;

//光圈校正结构体
typedef struct PU_IRIS_EMENDATION
{
    ULONG ulChannelId;                      //通道ID
    PU_LANGUAGE_TYPE_E enLanguageType;      //语言类型
    CHAR szReserved[PU_RESERVE_LEN];
}PU_IRIS_EMENDATION_S, *LPPU_IRIS_EMENDATION_S;

//媒体端口信息
typedef struct PU_PORT_INFO
{
    ULONG ulInterLeavedPort;                //交织端口
    ULONG ulVideoRtpPort;                   //视频RTP端口
    ULONG ulVideoRtcpPort;                  //视频RTCP端口
    ULONG ulAudioRtpPort;                   //音频RTP端口
    ULONG ulAudioRtcpPort;                  //音频RTCP端口
    ULONG ulIgtRtpPort;                     //智能RTP端口
    ULONG ulIgtRtcpPort;                    //智能RTCP端口
    CHAR szReserved[PU_RESERVE_LEN];
}PU_PORT_INFO_S, *LPPU_PORT_INFO_S;

//实况保存结构体
typedef struct PU_SAVE_REALDATA_INFO
{
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX]; //文件保存路径
    PU_SAVE_REALDATA_TYPE_E enSaveType;     //保存方式
    ULONG ulSaveSize;                       //保存文件大小或者录像长度(根据enSaveType判断)
}PU_SAVE_REALDATA_INFO_S, *LPPU_SAVE_REALDATA_INFO_S;

//保存图片结构体
typedef struct PU_SAVE_PICTURE_INFO
{
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX]; //文件保存路径+文件名
    PU_SAVE_PICTURE_TYPE_E enSavePicType;   //保存方式
}PU_SAVE_PICTURE_INFO_S, *LPPU_SAVE_PICTURE_INFO_S;

//巡航轨迹点信息
typedef struct PU_CRUISE_POINT
{
    ULONG ulPresetIndex;                    //预置位序列号
    ULONG ulDwellTime;                      //预置位停留时间(3-3600s)
    ULONG ulSpeed;                          //转到下一个点的速度(1-10)
}PU_CRUISE_POINT_S, *LPPU_CRUISE_POINT_S;

//巡航轨迹信息
typedef struct PU_PTZ_CRUISE_TRACK_PARA
{
    ULONG ulPtzId;                                                  //云台编号
    ULONG ulCruiseTrackIndex;                                       //巡航轨迹编号
    ULONG ulCruiseType;                                             //巡航模式（1：轨迹扫描，2：花样扫描）
    CHAR szCuriseTrackName[PU_PTZ_CRUISE_LEN];                      //巡航轨迹名称
    ULONG ulPointNum;                                               //轨迹点个数
    PU_CRUISE_POINT_S stCruisePoint[PU_PTZ_CRUISE_POINT_MAX];       //轨迹点列表
    PU_PTZ_CRUISE_TRACK_E enPtzCruiseTrack;                         //巡航轨迹操作命令字
}PU_PTZ_CRUISE_TRACK_PARA_S, *LPPU_PTZ_CRUISE_TRACK_PARA_S;

//巡航轨迹头信息
typedef struct PU_PTZ_CRUISE_TRACK_HEAD
{
    ULONG ulCruiseTrackIndex;                                       //巡航轨迹序列号
    CHAR szCruiseTrackName[PU_PTZ_CRUISE_LEN];                      //巡航轨迹名称
}PU_PTZ_CRUISE_TRACK_HEAD_S, *LPPU_PTZ_CRUISE_TRACK_HEAD_S;

//巡航轨迹列表
typedef struct PU_PTZ_CRUISE_TRACK_LIST
{
    ULONG ulPtzId;                                                  //云台编号
    ULONG ulCruiseTrackNum;                                         //巡航轨迹个数
    PU_PTZ_CRUISE_TRACK_HEAD_S stPtzCruiseTrackHead;                //巡航轨迹头信息
}PU_PTZ_CRUISE_TRACK_LIST, *LPPU_PTZ_CRUISE_TRACK_LIST;

//坐标信息
typedef struct PU_SQUARE_PARA
{
    ULONG ulX;
    ULONG ulY;
}PU_SQUARE_PARA_S, *LPPU_SQUARE_PARA_S;

/* OSD位置和颜色参数 */
typedef struct PU_OSD_INFO
{
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulTextColor;                      //字体颜色 0x00RGB
    PU_COLOR_TYPE_E enBackgroundColor;      //背景颜色
    PU_ALPHA_TYPE_E enBackgroundAlpha;      //背景景透明度
    CHAR szReserve[PU_RESERVE_LEN];
}PU_OSD_INFO_S, *LPPU_OSD_INFO_S;

/* OSD字符串参数 */
typedef struct PU_OSD_STRING_PARA
{
    BOOL bEnable;                           //使能与否
    PU_OSD_INFO_S stOSDInfo;
    ULONG ulStringLen;                      // 字符串长度
    CHAR szString[PU_OSD_STRING_LEN];       // 字符串内容
}PU_OSD_STRING_PARA_S, *LPPU_OSD_STRING_PARA_S;

/* OSD时间参数 */
typedef struct PU_OSD_DATETIME_PARA
{
    BOOL bShowWeekday;                      //是否显示星期
    BOOL bDateEnable;                       //时间使能与否
    PU_OSD_DATE_TYPE_E enDateType;          //日期格式
    PU_LANGUAGE_TYPE_E enLanguageType;      //OSD显示的语言类型: 0:简体中文 1:英文
    PU_OSD_INFO_S stOsdPara;                //位置及颜色
    CHAR szReserve[PU_RESERVE_LEN];
}PU_OSD_DATETIME_PARA_S, *LPPU_OSD_DATETIME_PARA_S;

/* OSD数组 */
typedef struct PU_OSD_STRING_ARRAY
{
    ULONG ulChannelID;                                              //通道ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;                       //OSD时间参数
    ULONG ulOSDStringNum;                                           //有效的字符串个数
    PU_OSD_STRING_PARA_S szStringPara[PU_OSD_STRING_NUM];           //OSD字符串参数
}PU_OSD_PARTICULAR_PARA_S, *LPPU_OSD_PARTICULAR_PARA_S;

//隐私保护区域
typedef struct PU_MASK_PARA
{
    ULONG ulStartX;                         //隐私保护矩形左上角X
    ULONG ulStartY;                         //隐私保护矩形左上角Y
    ULONG ulWidth;
    ULONG ulHeight;
}PU_MASK_PARA_S,*LPPU_MASK_PARA_S;

//隐私保护列表
typedef struct PU_PRIVACY_MASK_ARRAY
{
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_PARA_S stMaskPara[PU_PRIVACY_MASK_MAX];
}PU_PRIVACY_MASK_ARRAY_S, *LPPU_PRIVACY_MASK_ARRAY_S;

//温度
typedef struct PU_TEMPERATURE_PARA
{
    LONG lIntTemp;                          //整数部分温度值
    ULONG ulDotTemp;                        //小数部分温度值
}PU_TEMPERATURE_PARA_S, *LPPU_TEMPERATURE_PARA_S;

//串口参数
typedef struct PU_SERIAL_PORT_PARA
{
    ULONG ulSerialPort;                     //串口编号
    PU_SERIAL_PORT_MODE_E enPortMode;       //串口类型
    PU_BAUD_RATE_E enBaudRate;              //波特率
    PU_DATA_BIT_E enDataBit;                //数据位
    PU_PARITY_BIT_E enParityBit;            //校验位
    PU_STOP_BIT_E enStopBit;                //停止位
    PU_FLOW_CONTROL_E enFlowControl;        //串口流控制
}PU_SERIAL_PORT_PARA_S, *LPPU_SERIAL_PORT_PARA_S;

//云台参数
typedef struct PU_PTZ_PARA
{
    ULONG ulPtzId;                          //云台编号
    ULONG ulSerialPort;                     //串口编号
    PU_PTZ_DECODER_TYPE_E enDecoderType;    //解码器类型
    ULONG ulDecoderAddress;                 //解码器地址
    PU_PTZ_CONTROL_MODE_E enPtzControlMode; //正反控制模式
    BOOL  bEnable;                          //是否使能
}PU_PTZ_PARA_S, *LPPU_PTZ_PARA_S;

//透明通道命令
typedef struct PU_TRANSPARENT_CMD
{
    ULONG ulSerialPort;                                             //串口编号
    ULONG ulCmdLen;                                                 //透明通道命令长度
    CHAR  szTransparentCmd[PU_TRANSPARENT_CMD_MAX];                 //透明通道命令
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_TRANSPARENT_CMD_S, *LPPU_TRANSPARENT_CMD_S;

//时间，时、分、秒，24小时制
typedef struct PU_TIME
{
    CHAR szYear[PU_TIME_YEAR_LEN];
    CHAR szMonth[PU_TIME_OTHERS_LEN];
    CHAR szDay[PU_TIME_OTHERS_LEN];
    CHAR szHour[PU_TIME_OTHERS_LEN];
    CHAR szMinute[PU_TIME_OTHERS_LEN];
    CHAR szSecond[PU_TIME_OTHERS_LEN];
}PU_TIME_S, *LPPU_TIME_S;

//布防时间
typedef struct PU_ALARM_TIME
{
    ULONG ulCycleType;                      //循环方式，0：不循环；1：每周循环；
    ULONG ulPeriod;                         //0：每天，1-7：礼拜一至礼拜天
    PU_TIME_S stStart;                      //起始时间
    PU_TIME_S stEnd;                        //结束时间
}PU_ALARM_TIME_S, *LPPU_ALARM_TIME_S;

//布防时间列表
typedef struct PU_ALARM_TIME_PARA_LIST
{
    ULONG ulNum;                                                    //布防时间段个数
    PU_ALARM_TIME_S stAlarmTime[PU_ALARM_TIME_MAX];                 //布防时间段数组
}PU_ALARM_TIME_LIST_S, *LPPU_ALARM_TIME_LIST_S;

//温度告警参数
typedef struct PU_TEMPERATURE_ALARM_PARA
{
    LONG lEnable;                           //使能
    ULONG ulDeteInterval;                   //告警检测时间间隔1~256,每x秒检测一次是否在告警状态
    LONG lTemperatureMax;
    LONG lTemperatureMin;
}PU_TEMPERATURE_ALARM_PARA_S, *LPPU_TEMPERATURE_ALARM_PARA_S;

//开关量(输入)告警参数
typedef struct PU_INPUT_ALARM_PARA
{
    ULONG ulDeviceId;                       //告警设备ID
    CHAR szName[PU_DIO_NAME_LEN];           //告警设备名称
    LONG lEnable;                           //使能
    ULONG ulType;                           //常开，常闭，0：常开，1：常闭
    ULONG ulDeteInterval;                   //告警检测时间间隔1~256,每x秒检测一次是否在告警状态
    PU_ALARM_TIME_LIST_S stAlarmTimeList;
}PU_INPUT_ALARM_PARA_S, *LPPU_INPUT_ALARM_PARA_S;

//移动侦测/视频遮挡矩形参数
typedef struct PU_DETECTION_AREA
{
    ULONG ulNum;                                                    //检测矩形个数
    PU_MASK_PARA_S stMaskPara[PU_ALARM_AREA_MAX];                   //矩形参数
}PU_DETECTION_AREA_S, *LPPU_DETECTION_AREA_S;

//移动侦测告警参数
typedef struct PU_MOTION_DETECTION_PARA
{
    ULONG ulChannelId;                      //视频通道ID
    LONG lEnable;                           //使能
    ULONG ulInterval;                       //检测事件间隔1~30s，在该间隔内的运动都作为统一运动
    ULONG ulSensitivity;                    //运动检测灵敏度1~5，数字越高越灵敏
    ULONG ulDeteInterval;                   //告警检测时间间隔1~256，每x秒检测一次是否在告警状态
    PU_DETECTION_AREA_S stDetectionArea;    //告警检测区域
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_MOTION_DETECTION_PARA_S, *LPPU_MOTION_DETECTION_PARA_S;

//视频遮挡告警参数
typedef struct PU_HIDE_ALARM_PARA
{
    ULONG ulChannel;                        //视频通道ID
    LONG lEnable;                           //告警使能
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
    ULONG ulSensitivity;                    //运动检测灵敏度1~5，数字越高越灵敏
    PU_DETECTION_AREA_S stDetectionArea;    //告警检测区域
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_HIDE_ALARM_PARA_S, *LPPU_HIDE_ALARM_PARA_S;

//入侵检测点
typedef struct PU_INVADE_POINT
{
    ULONG ulPosX;                           //点X轴坐标(0-352)
    ULONG ulPosY;                           //点Y轴坐标(0-288)
}PU_INVADE_POINT_S, *LPPU_INVADE_POINT_S;

//入侵检测线
typedef struct PU_INVADE_LINE
{
    ULONG ulDirection;                      //检测方向（0：双向；1：左向右；2：右向左）
    PU_INVADE_POINT_S stStartPoint;         //检测线起始点
    PU_INVADE_POINT_S stEndPoint;           //检测线的终点
}PU_INVADE_LINE_S, *LPPU_INVADE_LINE_S;

//入侵检测线列表
typedef struct PU_INVADE_LINE_LIST
{
    ULONG ulLineNum;                                                //入侵线有效数量
    PU_INVADE_LINE_S stLine[PU_INVADE_LINE_NUM_MAX];                //入侵线
}PU_INVADE_LINE_LIST_S, *LPPU_INVADE_LINE_LIST_S;

//入侵检测参数
typedef struct PU_INVADE_PARA
{
    LONG lEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
    ULONG ulMiniSize;                       //目标最小尺寸(5-20)
    ULONG ulMaxSize;                        //目标最大尺寸(10-30)
    PU_INVADE_LINE_LIST_S stLineList;       //入侵检测线列表
}PU_INVADE_PARA_S, *LPPU_INVADE_PARA_S;

//入侵检测告警参数
typedef struct PU_INVADE_ALARM_PARA
{
    ULONG ulChannel;                        //视频通道ID
    PU_INVADE_PARA_S stInvadePara;          //入侵检测参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_INVADE_ALARM_PARA_S, *LPPU_INVADE_ALARM_PARA_S;

//目标计数参数
typedef struct PU_COUNT_PARA
{
    LONG lEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
    ULONG ulMiniSize;                       //目标最小尺寸
    BOOL bOrientation;                      //识别模式设置（0：水平；1：垂直）
    ULONG ulDirection;                      //检测方向（0：双向；1：区域A向区域B；2：区域B向区域A）
}PU_COUNT_PRAR_S, *LPPU_COUNT_PARA_S;

//目标计数告警参数
typedef struct PU_COUNT_ALARM_PARA
{
    ULONG ulChannelId;                      //视频通道ID
    PU_COUNT_PRAR_S stCountPara;            //目标计数参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_COUNT_ALARM_PARA_S, *LPPU_COUNT_ALARM_PARA_S;

//干扰检测参数
typedef struct PU_DISTURB_PARA
{
    LONG lEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    ULONG ulResetTime;                      //检测重置延迟(1~5S)
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
}PU_DISTURB_PARA_S, *LPPU_DISTURB_PARA_S;

//干扰检测告警参数
typedef struct PU_DISTURB_ALARM_PARA
{
    ULONG ulChannelId;                      //视频通道ID
    PU_DISTURB_PARA_S stDisturbPara;        //干扰检测参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_DISTURB_ALARM_PARA_S, *LPPU_DISTURB_ALARM_PARA_S;

//布防参数
typedef struct PU_GUARD_PARA
{
    ULONG ulDeviceId;                       //设备ID，0-所有告警设备
    ULONG ulState;                          //布防：0，撤防：1
}PU_GUARD_PARA_S, *LPPU_GUARD_PARA_S;

typedef struct PU_GUARD_STATE
{
    PU_GUARD_PARA_S szChannelStateList[PU_CAMERA_NUM_MAX];          //镜头布防状态,ulDeviceId=0为无效
    PU_GUARD_PARA_S szInputStateList[PU_DIO_NUM_MAX];               //输入设备告警状态,ulDeviceId=0为无效
    CHAR szReserve[PU_RESERVE_LEN];
}PU_GUARD_STATE_S, *LPPU_GUARD_STATE_S;

//设备系统时间结构体
typedef struct PU_SYSTEM_TIME
{
    PU_TIME_S stSystime;                    //时间
    LONG  lTimeZone;                        //时区的整数部分
    ULONG ulDotTimeZone;                    //时区的小数部分
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SYSTEM_TIME_S, *LPPU_SYSTEM_TIME_S;

typedef struct PU_PTZ_ACTION
{
    BOOL bPresetFlag;
    ULONG ulPresetIndex;
    BOOL bCruiseFlag;
    ULONG ulCruiseIndex; 
}PU_PTZ_ACTION_S,*LPPU_PTZ_ACTION_S;

//云台预置位
typedef struct PU_PTZ_PRESET_PARA
{
    ULONG ulChannelId;                      //通道ID
    CHAR szPresetName[PU_PTZ_NAME_LEN];     //预置位名称
    ULONG ulIndex;                          //预置位索引
    PU_PTZ_PRESET_CMD_E enPresetCmd;        //预置位命令字
}PU_PTZ_PRESET_PARA_S, *LPPU_PTZ_PRESET_PARA_S;

//预置位信息
typedef struct PU_PTZ_PRESET_INFO
{
    ULONG ulIndex;
    CHAR szPresetName[PU_PTZ_NAME_LEN];
}PU_PTZ_PRESET_INFO_S, *LPPU_PTZ_PRESET_INFO_S;

//云台预置位列表
typedef struct PU_PTZ_PRESET_LIST_PARA
{
    ULONG ulChannelId;                                              //通道ID
    ULONG ulBeginIndex;                                             //预置位开始编号
    ULONG ulEndIndex;                                               //预置位结束编号
    ULONG ulTotalNum;                                               //返回的预置位实际个数
    PU_PTZ_PRESET_INFO_S stPtzPresetInfo[PU_PTZ_PRESET_NUM];        //预置位信息
}PU_PTZ_PRESET_LIST_PARA_S, *LPPU_PTZ_PRESET_LIST_PARA_S;

//云台控制
typedef struct PU_PTZ_CONTROL_PARA
{
    ULONG ulChannel;                        //通道ID
    ULONG ulOpCode;                         //云台控制码
    ULONG ulParam1;                         //参数1
    ULONG ulParam2;                         //参数2
}PU_PTZ_CONTROL_PARA_S, *LPPU_PTZ_CONTROL_PARA_S;

//告警上报信息结构
typedef struct PU_ALARM_REPORT      
{                                        
    ULONG ulDeviceId;                       //告警设备ID
    PU_ALARM_TYPE_E enAlarmType;            //告警类型
    PU_TIME_S stTime;                       //告警发生时间
    PU_ALARM_ACTION_E enAction;             //告警发生/消除
    ULONG ulAlarmId;                        //告警ID
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ALARM_REPORT_S, *LPPU_ALARM_REPORT_S;

//NVS平台参数
typedef struct PU_PLATFORM_NVS_PARAM
{
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];        //NVS IP地址
    ULONG ulNvsPort;                           //NVS端口
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];    //设备ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];   //NVS登录名
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN]; //NVS登录域
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];    //NVS登录密码
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_NVS_PARAM_S, *LPPU_PLATFORM_NVS_PARAM_S;

//IVS平台参数
typedef struct PU_PLATFORM_IVS_PARAM_S
{
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];        //IVS IP地址
    ULONG ulNvsPort;                           //IVS端口
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];    //设备ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];   //IVS登录名
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN]; //IVS登录域
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];    //IVS登录密码
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_IVS_PARAM_S, *LPPU_PLATFORM_IVS_PARAM_S;

//千里眼平台参数地址，适用于IVS
typedef struct PU_PLATFORM_IVS_PARA
{
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];
    CHAR szDeviceId[PU_PLATFORM_INFO_LEN];
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szProductName[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_IVS_PARA_S, *LPPU_PLATFORM_IVS_PARA_S;

//28281平台参数地址
typedef struct PU_PLATFORM_GBT_PARA
{
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];    //设备ID与登录名相同
    CHAR szPlatformId[PU_PLATFORM_INFO_LEN];   //服务器编码
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_GBT_PARA_S, *LPPU_PLATFORM_GBT_PARA_S;

//SDK主动注册的地址
typedef struct PU_PLATFORM_SDK_PARA
{
    BOOL bEnable;
    PU_SDK_PLATFORM_MODE_E enSdkPlatformMode;
    CHAR szDeviceId[PU_PLATFORM_INFO_LEN];
    CHAR szPlatformIp[PU_IP4_ADDR_LEN];
    ULONG szPlatformPort;
    CHAR szBackupPlatformIp[PU_IP4_ADDR_LEN];
    ULONG szBackupPlatformPort;
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_SDK_PARA_S, *LPPU_PLATFORM_SDK_PARA_S;

//ONVIF开关
typedef struct PU_ONVIF_SWITCH
{
    BOOL bEnable;                           //ONVIF开关
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_SWITCH_S, *LPPU_ONVIF_SWITCH_S;

//ONVIF密码参数
typedef struct PU_ONVIF_PWD_PARA
{
    CHAR szUserName[PU_USER_NAME_LEN];
    CHAR szOldPassword[PU_PASSWORD_LEN];
    CHAR szNewPassword[PU_PASSWORD_LEN];
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_PWD_PARA_S, *LPPU_ONVIF_PWD_PARA_S;

//升级上传文件路径结构体
typedef struct PU_UPGRADE_FILE_INFO
{
    CHAR cFileNum;                                                          //文件数目,最大文件数为 UPGRADE_FILE_NUM_MAX
    CHAR szFileName[PU_UPGRADE_FILE_NUM_MAX][PU_UPGRADE_FILE_LEN_MAX];    //文件路径及文件名，第一个为uImage,第二个为jffs2，第三、四个为扩展预留
    CHAR szReserve[PU_RESERVE_LEN];
}PU_UPGRADE_FILE_INFO_S, *LPPU_UPGRADE_FILE_INFO_S;

//系统信息结构体
typedef struct PU_SYS_STATUS_INFO
{
    FLOAT fCpuOccupancyRate;                //CPU占用率
    ULONG ulMemTotal;                       //设备总内存(KB)
    ULONG ulMemFree;                        //空闲内存(KB)
    ULONG ulMemBuffer;                      //BUFF内存(KB)
    ULONG ulMemCache;                       //CACHE内存(KB)
    ULONG ulRecvRate;                       //网络接收速率byte
    ULONG ulSendRate;                       //网络发送速率byte
    ULONG ulFlashTotal;                     //总共Flash大小(KB)
    ULONG ulFlashFree;                      //空闲Flash大小(KB)
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SYS_STATUS_INFO_S, *LPPU_SYS_STATUS_INFO_S;


//解码器结构体

//解码器通道信息
typedef struct PU_DECODER_CHANNEL_INFO
{
    unsigned long ulChannelID;                                      //解码器通道号
    char          szChannelName[PU_DEC_CHANNEL_NAME_LEN + 1];          //解码器通道名称
} PU_DECODER_CHANNEL_INFO_S;

//连接信息
typedef struct PU_DECLINK_INFO
{
    CHAR szDecVIP[PU_IP6_ADDR_LEN];         //视频IP地址
    ULONG ulDecVPort;                       //视频端口
    CHAR szDecAIP[PU_IP6_ADDR_LEN];         //音频IP地址
    ULONG ulDecAPort;                       //音频端口
    CHAR chTransProtocol;                   //传输协议: 1:RTP(TCP Client) 2:RTP(UDP) ...  音频视频解码需相同,当TCP时，以上IP、PORT为入参，当UDP时，IP、PORT为出参
    CHAR chDecFlags;                        //解码标志：0 仅解视频; 1 仅解音频; 2 同时解,同时解时使用VIP及VPORT即可
    CHAR chKeepaliveFlags;                  //保活标志,在VIP/VPort 发送RTSP保活信令: 0 不保活,1 保活 
    CHAR szRes[PU_RESERVE_LEN];             //预留,通过sdk发流:szRes[0]= 0;sdk建立信令，调用者直接发流:szRes[0]=1
}PU_DECLINK_INFO_S, *LPPU_DECLINK_INFO_S;

//解码信息结构体
typedef struct PU_DEC_INFO
{
    ULONG ulChannelId;                      //通道ID
    PU_DECLINK_INFO_S stDecLinkInfo;        //连接信息
}PU_DEC_INFO_S, *LPPU_DEC_INFO_S;

//初始化解码响应结构体
typedef struct PU_INIT_DECODE_INFO_RSP
{
    CHAR szDecMediaIp[PU_IP4_ADDR_LEN];     //解码器的媒体IP
    PU_PORT_INFO_S stDecPortInfo;           //解码器的端口信息
    CHAR szReserve[PU_RESERVE_LEN];
}PU_INIT_DECODE_INFO_RSP_S, *LPPU_INIT_DECODE_INFO_RSP_S;

//启动解码结构体
typedef struct PU_START_DECODE_INFO
{
    ULONG ulChannelId;                      //通道号
    PU_ENCODE_TYPE_E enVideoEncodeType;     //视频解码类型
    PU_ENCODE_TYPE_E enAudioEncodeType;     //音频解码类型
    PU_PROTOCOL_TYPE_E enProtocolType;      //初始化解码传输协议
    PU_PORT_INFO_S stLocalPortInfo;         //SDK的端口信息
    CHAR szLocalMediaIp[PU_IP4_ADDR_LEN];   //SDK的媒体IP
    CHAR szSessionID[PU_NAT_SESSIONID_LEN]; //会话ID
    CHAR szSessionUrl[PU_NAT_URL_LEN];      //会话URL
    CHAR szReserve[PU_RESERVE_LEN];
}PU_START_DECODE_INFO_S,*LPPU_START_DECODE_INFO_S;

//解码器端口能力
typedef struct PU_DEC_PORT_ABILITY
{
    CHAR szOutPutModes[PU_PORT_MODE_NUM_MAX];  //1\2\4\9\16 mode,0 the end
    ULONG ulPortType;                       //0:Audio, 1:Video 2:both
    BOOL bSupportEnlarge;                   //端口是否支持放大显示
}PU_DEC_PORT_ABILITY_S,*LPPU_DEC_PORT_ABILITY_S;

//解码器端口能力列表
typedef struct PU_DEC_PORT_ABILITY_LIST
{
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType[PU_DECODE_TYPE_MAX];                 //解码支持的类型
    PU_DEC_PORT_ABILITY_S stBNCAttribute[PU_BNC_PORT_MAX];             //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式；
    PU_DEC_PORT_ABILITY_S stVGAAttribute[PU_VGA_PORT_MAX];             //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_ABILITY_S stHDMIAttribute[PU_HDMI_PORT_MAX];           //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_ABILITY_S stDVIAttribute[PU_DVI_PORT_MAX];             //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；**/
}PU_DEC_PORT_ABILITY_LIST_S, *LPPU_DEC_PORT_ABILITY_LIST_S;

//解码器端口信息
typedef struct PU_DEC_PORT_INFO
{
    BOOL bEnable;                           //端口使能
    PU_PORT_MODE_E enPortMode;              //通道模式
    PU_FRAME_RATE_E enFrameRate;            //帧率  :30帧|| 60 帧
    PU_RESOLUTION_TYPE_E enDecResolution;   //解码输出分辨率
//     BOOL bEnlargeFlag;                   //是否支持放大,0: no support, 1: support
}PU_DEC_PORT_INFO_S, *LPPU_DEC_PORT_INFO_S;

//解码器端口信息列表
typedef struct PU_DEC_PORT_INFO_LIST
{
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType;                                  //解码类型
    PU_DEC_PORT_INFO_S stBNCAttribute[PU_BNC_PORT_MAX];                //输出类型：A/V/AV    ，输出窗口模式:共有1、2、4、9、16等几种模式；
    PU_DEC_PORT_INFO_S stVGAAttribute[PU_VGA_PORT_MAX];                //输出类型：A/V/AV    ，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_INFO_S stHDMIAttribute[PU_HDMI_PORT_MAX];              //输出类型：A/V/AV    ，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_INFO_S stDVIAttribute[PU_DVI_PORT_MAX];                //输出类型：A/V/AV   ， 输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；**/
//    CHAR chSameVInput;                                            //VGA/HDMI/DVI 是否同源模式：0000 0000 不同源, 0000 0111  同源 */
    CHAR chRes[PU_RESERVE_LEN];
}PU_DEC_PORT_INFO_LIST_S, *LPPU_DEC_PORT_INFO_LIST_S;

//通道与端口的映射关系
typedef struct PU_DEC_CHANNEL_PORT_MAP
{
    ULONG ulChannelID;                      //通道号
    PU_PORT_TYPE_E enPortType;              //端口类型
    ULONG ulPortIndex;                      //端口索引
    ULONG ulLayoutIndex;                    //通道所在的布局索引
}PU_DEC_CHANNEL_PORT_MAP_S, *LPPU_DEC_CHANNEL_PORT_MAP_S;

/*通道能力 :音频& 视频*/
/*例子能力：2 ----1 BNC1+D1 1 VGA1||HDMI1 + 1080P
5 ----1 BNC1+D1  4 VGA1||HDMI1 + D1
3 ----1 BNC1+D1  1 VGA1+720P  1 HDMI1+720P   ====   不同源
2 ----1 VGA1+720P  1 HDMI1+720P ====   不同源*/
typedef struct PU_DEC_CHANNEL_ABILITY
{
    PU_DEC_CHANNEL_PORT_MAP_S stChannelPortMap;                     //映射关系
    PU_ENCODE_TYPE_E enVideoDecFormats[PU_DECODE_TYPE_MAX];            //解码视频格式
    PU_ENCODE_TYPE_E enAudioDecFormats[PU_DECODE_TYPE_MAX];            //解码音频格式
    PU_RESOLUTION_TYPE_E enMaxDecResolution ;                       //解码最大分辨率
    PU_FRAME_RATE_E enMaxFrameRate;                                 //最大帧率  :30帧|| 60 帧
    BOOL bSupportDecryption;                                        //0: no support 1: support
    BOOL bSupportWaterMark;                                         //0: no support 1: support
//    BOOL bAudioFlag;                                              //音频开关:一个解码器仅支持一路音频输出，在一个通道里开启后，原来如果有通道开启过，会被默认开闭掉
}PU_DEC_CHANNEL_ABILITY_S,*LPPU_DEC_CHANNEL_ABILITY_S;

//通道能力列表
typedef struct PU_DEC_CHANNEL_ABILITY_LIST
{
    ULONG ulChannelNums;                                            //通道数
    PU_DEC_CHANNEL_ABILITY_S stChnAttri[PU_CHANNEL_NUM_MAX];           //通道属性
}PU_DEC_CHANNEL_ABILITY_LIST_S, *LPPU_DEC_CHANNEL_ABILITY_LIST_S;

/* OSD位置和颜色参数 */
typedef struct PU_DEC_OSD_PARA
{
    ULONG ulStartX;                                         
    ULONG ulStartY;
    ULONG ulFgColor;                        //字体颜色
    UCHAR ucFgAlpha;                        //前景透明度
    UCHAR ucBgAlpha;                        //背景透明度
    ULONG ulBgColor;                        //背景颜色
}PU_DEC_OSD_PARA_S, *LPPU_DEC_OSD_PARA_S;

//解码器OSD字符参数
typedef struct PU_DEC_OSD_STRING_INFO
{
    BOOL bEnable;                           //使能与否
    ULONG ulStringLen;                      //字符串长度
    CHAR szString[PU_OSD_MAX_LENGTH];          //字符串内容
    PU_DEC_OSD_PARA_S stOSDPara;            //OSD文字信息
}PU_DEC_OSD_STRING_INFO_S, *LPPU_DEC_OSD_STRING_INFO_S;

//通道信息
typedef struct PU_DEC_CHANNEL_INFO
{
    ULONG ulChannelId;                      //通道ID号
    BOOL bDenoiseFlag;                      //降噪使能
    BOOL bDemistFlag;                       //去雾使能
    BOOL bEnlargeStatus;                    //图像放大状态
    PU_DEC_OSD_STRING_INFO_S stOsdTextInfo; //OSD文字信息
}PU_DEC_CHANNEL_INFO_S, *LPPU_DEC_CHANNEL_INFO_S;

//通道信息列表
typedef struct PU_DEC_CHANNEL_INFO_LIST
{
    ULONG ulChannnelNums;                                           //通道数
    PU_DEC_CHANNEL_INFO_S stChannelInfo[PU_CHANNEL_NUM_MAX];           //通道信息
}PU_DEC_CHANNEL_INFO_LIST_S, *LPPU_DEC_CHANNEL_INFO_LIST_S;

//解码器解码信息
typedef struct PU_DEC_DECRYPTION_INFO
{
    ULONG               ulChannelId;                                //解密的通道号
    BOOL                bEnable;                                    //解密使能状态
    PU_ENCRYPT_TYPE_E   enDecryptionType;                           //解密算法类型
    CHAR                szVideoCrypto[PU_CRYPTION_PASSWD_LEN];         //视频密钥
    CHAR                szAudioCrypto[PU_CRYPTION_PASSWD_LEN];         //音频密钥
}PU_DEC_DECRYPTION_INFO_S, *LPPU_DEC_DECRYPTION_INFO_S;

//解码器音频端口信息
typedef struct PU_DEC_AUDIO_INFO
{
    PU_AUDIO_PORT_TYPE_E enAudioPortType;                           //音频端口类型
    BOOL bEnable;                                                   //音频端口使能与否
    ULONG ulChannelId;                                              //音频解码的通道号
    PU_ENCODE_TYPE_E enAudioDecodeType;                             //音频解码类型
    ULONG ulAudioVolume;                                            //音量
    PU_AUDIO_SAMPLERATE_E enAudioSampleRate;                        //音频采样率
}PU_DEC_AUDIO_INFO_S, *LPPU_DEC_AUDIO_INFO_S;

typedef struct PU_TIME_PLAN
{
    ULONG ulCycle;                          // 周期控制，0：仅一次，1：每周都按照时间段
    ULONG ulPeriod;                         // 周期： 0:一周全部 1~7:表示各天
    PU_TIME_S stStartTime;                  // 开始时间:  UTC 时间
    PU_TIME_S stEndTime;                    // 结束时间:  UTC 时间
    CHAR szReserved[PU_RESERVE_LEN];
}PU_TIME_PLAN_S, *LPPU_TIME_PALN_S;

/*通道录像计划*/
typedef struct PU_RECORD_PLAN
{
    ULONG ulChannelId;
    ULONG ulTotalPlanNum;                                           //总记录数
    PU_TIME_PLAN_S szRecordPlanList[PU_RECORD_PLAN_NUM];            //录像计划数组
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_PLAN_S, *LPPU_RECORD_PLAN_S;

/* 录像信息查询 */
typedef struct PU_RECORD_INQUIRE
{
    ULONG ulChannelId;
    PU_TIME_S stBeginTime;
    PU_TIME_S stEndTime;
    ULONG     ulBeginIndex;
    PU_RECORD_TYPE_E enRecordTypeList[PU_RECORD_TYPE_NUM];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_INQUIRE_S, *LPPU_RECORD_INQUIRE_S;

/* 前端录像信息 */
typedef struct PU_RECORD_INFO
{
    PU_RECORD_TYPE_E enRecordType;                                  // 录像类型
    PU_TIME_S stBeginTime;                                          // 开始时段
    PU_TIME_S stEndTime;                                            // 结束时段
    ULONG ulContentSize;                                            // 录像文件大小
    CHAR szContentID[PU_RECORD_CONTENTID_LEN];                      // 录像文件名
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_INFO_S, *LPPU_RECORD_INFO_S;

/* 前端录像信息列表 */
typedef struct PU_RECORD_LIST
{
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    PU_RECORD_INFO_S szRecordInfoList[PU_RECORD_INFO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_LIST_S, *LPPU_RECORD_LIST_S;


/************************开关量输出参数设置**************************/
typedef struct PU_SWITCH_OUTPUT_PARA
{
    ULONG  ulOutputId;
    CHAR   szOutputName[PU_DIO_NAME_LEN];   //名称，最大支持32字节
    ULONG  ulHoldTime;                      //保持时间 1-600  默认10秒
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_OUTPUT_PARA_S, *LPPU_SWITCH_OUTPUT_PARA_S;

/************************开关量输出状态设置**************************/
typedef struct PU_SWITCH_OUTPUT_STATE
{
    ULONG  ulOutputId;
    ULONG  ulSwitchType;                    //常开/常闭= 0：常开 1：常闭
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_DO_STATE_S, *LPPU_SWITCH_DO_STATE_S;

/************************开关量输入参数设置**************************/
typedef struct PU_SWITCH_INPUT_PARA
{
    ULONG ulInputId;
    CHAR  szInputName[PU_DIO_NAME_LEN];     //名称，最大支持32字节
    ULONG ulSwitchType;                     //常开/常闭= 0：常开 1：常闭
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_INPUT_PARA_S, *LPPU_SWITCH_INPUT_PARA_S;

/************************开关量输入输出参数设置**********************/
typedef struct PU_DIO_PARA
{
    PU_SWITCH_INPUT_PARA_S  stInput[PU_DIO_NUM_MAX];
    PU_SWITCH_OUTPUT_PARA_S stOutput[PU_DIO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DIO_PARA_S, *LPPU_DIO_PARA_S;

/**************告警联动 镜头信息**********************/
typedef struct PU_ALARM_LINKAGE_CAMERA_INFO
{
    ULONG  ulChannelId;
    ULONG  ulPreId;
    ULONG  ulCruiseId;
    ULONG  ulRecord;
    ULONG  ulSnap;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_LINKAGE_CAMERA_INFO, *LPPU_ALARM_LINKAGE_CAMERA_INFO;

/*******************告警联动参数 ***************************/
typedef struct PU_ALARM_LINKAGE_PARA
{
    ULONG ulChannelNum;                                             //联动镜头个数
    ULONG ulDoNum;                                                  //联动开关量输出个数
    PU_ALARM_LINKAGE_CAMERA_INFO stCameraList[PU_ALARM_CAMERA_MAX]; //联动镜头信息列表
    ULONG szDoIdList[PU_ALARM_DO_MAX];                              //联动开关量输出ID
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_LINKAGE_PARA_S, *LPPU_ALARM_LINKAGE_PARA_S;

//获取前端设备日志
typedef struct PU_LOG_REQ_PARA
{
    PU_TIME_S stStartTime;
    PU_TIME_S stEndTime;
    ULONG ulStartIndex;
    ULONG ulPrePageNum;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LOG_REQ_PARA_S, *LPPU_LOG_REQ_PARA_S;

//前端日志信息
typedef struct PU_LOG_INFO
{
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    CHAR  szLogInfoList[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LOG_INFO_S, *LPPU_LOG_INFO_S;

//实时浏览结构体
typedef struct PU_REAL_PLAY_INFO
{
    ULONG ulChannelId;                                              //通道ID
    HWND hPlayWnd;                                                  //Windows窗口句柄    
    PU_STREAM_TYPE_E enStreamType;                                  //码流类型,主码流、子码流
    PU_VIDEO_TYPE_E enVideoType;                                    //流类型：视频流、音频流、复合流、录像流
    PU_PROTOCOL_TYPE_E enProtocolType;                              //传输协议类型，UDP,TCP
    PU_MEDIA_CALLBACK_TYPE_E enMediaCallbackType;                   //回调类型：0:RTP解密 1:RTP不解密  2:Frame 3:YUV  
    CHAR szLocalIp[PU_IP4_ADDR_LEN];                                //请求端IP
    BOOL bKeepLive;                                                 //是否保活
    PU_TIME_S stStartTime;                                          //请求预录、录像开始时间
    PU_TIME_S stEndTime;                                            //请求预录、录像结束时间
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //加密类型，只支持AES加密
    CHAR szMediaCrypto[PU_CRYPTION_PASSWD_LEN];                     //加密密钥
    CHAR szReserved[PU_RESERVE_LEN];
}PU_REAL_PLAY_INFO_S, *LPPU_REAL_PLAY_INFO_S;

//语音对讲/语音广播结构体
typedef struct PU_VOICE_INFO
{
    ULONG ulChannelId;                      //通道ID
    CHAR  szLocalAudioIp[PU_IP4_ADDR_LEN];  //本地音频IP
    BOOL  bFeedAudioData;                   //是否喂数据(语音对讲：TRUE时回调函数不能为空，FLASE时回调函数必须为空)
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_VOICE_INFO_S, *LPPU_VOICE_INFO_S;

//实时浏览结构体
typedef struct PU_MEDIA_PLAY_INFO
{
    ULONG ulChannelId;                                              //通道号
    PU_BUSINESS_TYPE_E enBusinessType;                              //实时浏览、语音对讲、语音广播、录像下载
    PU_STREAM_TYPE_E enStreamType;                                  //主码流、子码流1、子码流2
    PU_PROTOCOL_TYPE_E enProtocolType;                              //TCP、UDP、组播方式
    PU_VIDEO_CODE_TYPE_E enTansmitType;                             //ES、PS、TS
    PU_VIDEO_TYPE_E enVideoType;                                    //视频流、音频流、复合流
    CHAR szLocalIp[PU_IP4_ADDR_LEN];                                //请求端IP
    PU_PORT_INFO_S stLocalPortInfo;                                 //请求端的端口号
    ULONG ulLinkMode;                                               //连接类型，0直连 1中转
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //加密类型
    CHAR szVideoCrypto[PU_CRYPTION_PASSWD_LEN];                     //视频密钥
    CHAR szAudioCrypto[PU_CRYPTION_PASSWD_LEN];                     //音频密钥
    PU_TIME_S stStartTime;                                          //请求预录、录像开始时间
    PU_TIME_S stEndTime;                                            //请求预录、录像结束时间
    CHAR szSessionIDForNAT[PU_NAT_SESSIONID_LEN];                   //用于NAT穿越的Session
    CHAR szSessionUrl[PU_NAT_URL_LEN];                              //用于NAT的会话URL
    CHAR szReserved[PU_RESERVE_LEN];
}PU_MEDIA_PLAY_INFO_S, *LPPU_MEDIA_PLAY_INFO_S;

//媒体流开始响应、录像下载响应
typedef struct PU_MEDIA_PLAY_RSP
{
    ULONG               ulSessionId;                                //媒体流的唯一标志
    PU_PORT_INFO_S      stPeerPortInfo;                             //发送端的端口信息
    CHAR                szPeerIp[PU_IP4_ADDR_LEN];                  //发送端的IP
    PU_ENCODE_TYPE_E    enVideoEncodeType;                          //视频编码类型
    PU_ENCODE_TYPE_E    enAudioEncodeType;                          //音频编码类型
    PU_TIME_S           stStartTime;                                //录像实际开始时间
    PU_TIME_S           stEndTime;                                  //录像实际结束时间
    CHAR                szReserved[PU_RESERVE_LEN];
}PU_MEDIA_PLAY_RSP_S, *LPPU_MEDIA_PLAY_RSP_S;

/* 硬盘信息 */
typedef struct PU_HARD_DISK_PARA
{
    CHAR szDiskFac[PU_FAC_NAME_LEN];
    PU_DISK_TYPE_E enDiskType;
    ULONG ulAllSpace;
    ULONG ulLeftSpace;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HARD_DISK_PARA_S;

//主设备能力
typedef struct PU_DEVICE_ABILITY
{
    ULONG ulVideoInputChannelNum;           //视频输入通道数
    ULONG ulAudioInputChannelNum;           //音频输入通道数
    ULONG ulAlarmDINum;                     //告警输入数
    ULONG ulAlarmDONum;                     //告警输出数
    ULONG ulSerialPortNum;                  //串口数
    ULONG ulNetworkCardNum;                 //网口数
    ULONG ulHardDiskNum;                    //硬盘数
    ULONG ulPTZNum;                         //云台数
    ULONG ulTalkbackInputNum;               //语音对讲输入数
    ULONG ulTalkbackOutputNum;              //语音对讲输出数
    ULONG ulRTPOverFlag;                    //传输协议: 0:RTPoverUDP 1:RTPoverTCP 2:RTPoverUDP&TCP
    PU_HARD_DISK_PARA_S stHardDiskInfo;     //硬盘信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_ABILITY_S, *LPPU_DEVICE_ABILITY_S;

/* 流能力 */
typedef struct PU_STREAM_ABILITY_PARA
{
    PU_STREAM_TYPE_E enStreamType;                                  //视频流类型
    PU_ENCODE_TYPE_E enVideoFormat[PU_VIDEO_FORMAT_NUM];            //视频编码格式
    PU_RESOLUTION_TYPE_E enMaxResolution;                           //最大分辨率
    ULONG ulMaxBitRate;                                             //最大码率
    ULONG ulMaxFrmRate;                                             //最大帧率
    ULONG ulMaxIFrameInterval;                                      //最大I帧间隔
    PU_VIDEO_TYPE_E enVideoType;                                    //视频流类型
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STREAM_ABILITY_PARA_S, *LPPU_STREAM_ABILITY_PARA_S;

/* 通道流能力 */
typedef struct PU_STREAM_ABILITY
{
    ULONG ulChannelId;
    CHAR  szCameraName[PU_DEVICE_NAME_LEN];
    ULONG ulPTZType;
    ULONG ulPresetNum;
    ULONG ulCruiseTrackNum;
    ULONG ulMaxStreamNum;
    BOOL  bPtzFastLocate;
    BOOL  bPtzHorizotalScan;
    BOOL  bPtzVerticalScan;
    PU_STREAM_ABILITY_PARA_S stStreamAbility[PU_STREAM_NUM];  
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STREAM_ABILITY_S, *LPPU_STREAM_ABILITY_S;

/*前向纠错*/
typedef struct PU_FEC_PARA
{
    ULONG ulChannelId;
    BOOL bEnable;                           //前向纠错使能
    PU_FEC_PACKET_LOSS_RATIO_E enPacketLossRatio;       //前向纠错丢包率
    CHAR szReserved[PU_RESERVE_LEN];
}PU_FEC_PARA_S, *LPPU_FEC_PARA_S;

//动态码流/帧率
typedef struct PU_DYNAMIC_STREAM_INFO
{
    ULONG ulChannelId;
    BOOL  ulEnable;                         //动态帧率和码流是否使能
    ULONG ulDynamicFrameRate;               //动态帧率
    ULONG ulDynamicBitRate;                 //动态码率
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DYNAMIC_STREAM_INFO_S, *LPPU_DYNAMIC_STREAM_INFO_S;

typedef struct PU_DEVICE_REGISTER_RSP
{
    PU_ERROR_CODE_E enErrorCode;
    CHAR  szRedirectIp[PU_IP4_ADDR_LEN];
    ULONG ulRedirectPort;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DEVICE_REGISTER_RSP_S, *LPPU_DEVICE_REGISTER_RSP_S;

//device common callback event struct, include: off line, upload image complete notify 
typedef struct PU_EVENT_COMMON
{
    PU_EVENT_TYPE_E enEventType;            //事件类型
    ULONG           ulIdentifyID;           //唯一标识的ID号
    ULONG           ulChannelId;
}PU_EVENT_COMMON_S, *LPPU_EVENT_COMMON_S;

//device stream package change callback event struct
typedef struct PU_EVENT_STEAM_PACKAGE_CHANGE
{
    PU_EVENT_COMMON_S stPuEventCommon;      //通用事件
    PU_STREAM_MODE_E enStreamMode;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_STEAM_PACKAGE_CHANGE_S, *LPPU_EVENT_STEAM_PACKAGE_CHANGE_S;

//device stream package change callback event struct
typedef struct PU_EVENT_UPLOAD_IMAGE_URL
{
    PU_EVENT_COMMON_S stPuEventCommon;                              // 通用事件
    ULONG ulSessionId;                                              // 前端获取抓拍图片上载URL请求会话ID,用于前端标识一次唯一的会话
    CHAR  szContentID[PU_SNAP_IMAGE_NAME_LEN];                      // 图片名
    ULONG ulLocation;                                               // 图片存储位置: 0:平台  1:前端
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_UPLOAD_IMAGE_URL_S, *LPPU_EVENT_UPLOAD_IMAGE_URL_S;

typedef struct PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    ULONG ulSessionId;                                              //上传完成通知会话ID,用于前端标识一次唯一的会话
    CHAR  szContentID[PU_SNAP_IMAGE_NAME_LEN];                      //图片名
    ULONG ulContentSize;                                            //图片大小
    CHAR  szSnapTime[PU_TIME_TOTAL_LEN];                            //抓拍时间 格式："2009-07-14 15:41:14"
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S, *LPPU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S;

//device auto register callback event struct
typedef struct PU_EVENT_REGISTER
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    CHAR  szDeviceId[PU_MAC_ADDR_LEN];
    CHAR  szDeviceIp[PU_IP4_ADDR_LEN];
    CHAR  szDeviceType[PU_DEVICE_TYPE_LEN];
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_EVENT_REGISTER_S, *LPPU_EVENT_REGISTER_S;

//解码器注册回调
typedef struct PU_DEC_CALLBACK_INFO
{
    PU_EVENT_COMMON_S stPuEventCommon;                                 //通用事件
    CHAR szDecoderID[PU_DECODER_ID_LEN + 4];                           //解码器ID
    CHAR szDecIP[PU_IP4_ADDR_LEN];                                     //解码器IP
    ULONG ulDecPort;                                                   //解码器port
    CHAR szDeviceType[PU_DEC_CHANNEL_NAME_LEN];                        //设备型号
    ULONG ulVideoPayloadTypeNum;                                       //支持的视频PayloadType个数。最大值不超过16
    ULONG ulAudioPayloadTypeNum;                                       //支持的音频PayloadType个数。最大值不超过16
    ULONG ulChannelNum;                                                //解码器有效通道个数，最大不超过
    CHAR szDecoderName[PU_DECODER_NAME_LEN + 4];                       //解码器名称
    CHAR szDecoderEncoding[PU_DECODER_ENCODING_LEN + 4];               //解码器编码格式 
    UCHAR ucVideoPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           //支持的视频PayloadType固定数组。元素个数为16。实际元素个数为ulVideoPayloadTypeNum
    UCHAR ucAudioPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           //支持的音频PayloadType固定数组。元素个数为16。实际元素个数为ulAudioPayloadTypeNum
    PU_DECODER_CHANNEL_INFO_S stChannelInfoArray[PU_CHANNEL_NUM_MAX];  //解码器通道信息的数组元素个数为ulChannelNum
}PU_DEC_CALLBACK_INFO_S, *LPPU_DEC_CALLBACK_INFO_S;

//连接状态回调
typedef struct PU_CONNECT_STATUS
{
    PU_EVENT_COMMON_S         stPuEventCommon;                      //通用事件
    CHAR                      szDeviceIP[PU_IP4_ADDR_LEN];          //设备IP
    ULONG                     ulDevicePort;                         //设备port
    CHAR                      szDeviceFac[PU_FAC_NAME_LEN];         //设备厂商,固定为：HUAWEI PU
    CHAR                      szDeviceID[PU_MAC_ADDR_LEN + 4];      //设备ID
    CHAR                      szDeviceType[PU_DEVICE_NAME_LEN];     //设备型号
    CHAR                      szReserved[PU_RESERVE_LEN];
}PU_CONNECT_STATUS_S, *LPPU_CONNECT_STATUS_S;

typedef struct PU_EVENT_TRANSPARENT
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    PU_TRANSPARENT_CMD_S stTransparentCmd;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_TRANSPARENT_S, *LPPU_EVENT_TRANSPARENT_S;

typedef union PU_EVENT_NOTIFY_BODY
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    PU_EVENT_STEAM_PACKAGE_CHANGE_S stPuStreamPackgeChange;         //IPC流套餐变更
    PU_EVENT_UPLOAD_IMAGE_URL_S stPuUploadImageURL;                 //前端请求上传图片URL
    PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S stUploadCompNotify;         //前端图片上传完成通知

    PU_DEC_CALLBACK_INFO_S stPuDecRegister;                         //前端DEC主动注册
    PU_CONNECT_STATUS_S    stPuConnetStatus;                        //前端设备连接状态
    PU_EVENT_REGISTER_S    stPuIpcRegister;                         //前端IPC主动注册
    PU_EVENT_TRANSPARENT_S stTransparentChannelNotify;              //透明通道数据上报
}PU_EVENT_NOTIFY_BODY_U, *LPPU_EVENT_NOTIFY_BODY_U;

//磁盘满策略
typedef struct RECORD_STRATEGY
{
    ULONG ulChannelId;
    ULONG ulStrategy;                       // 存储策略:0循环覆盖  1停止录像
    ULONG ulMinRecordTime;                  // 最小录制时长 >=60s
    ULONG ulPreAlarmRecordTime;             // 警前预录时间
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_RECORD_STRATEGY_S, *LPPU_RECORD_STRATEGY_S;

//看守位参数
typedef struct GUARD_POSITION_PARA
{
    ULONG ulPtzId;
    BOOL bEnable;
    ULONG ulPresetIndex;
    ULONG ulWaitTime;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_GUARD_POSITION_PARA_S, *LPPU_GUARD_POSITION_PARA_S;

//电子云台参数
typedef struct PU_EPTZ_PARA
{
    ULONG ulChannelId;
    PU_STREAM_TYPE_E enStreamType;
    BOOL  bEnable;
    ULONG ulLeftPercent;
    ULONG ulTopPercent;
    ULONG ulWidthPercent;
    ULONG ulHeightPercent;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_EPTZ_PARA_S, *LPPU_EPTZ_PARA_S;

//码流平滑参数
typedef struct PU_STREAM_SMOOTH_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulTcpUpperCoefficient;
    ULONG ulUdpUpperCoefficient;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_STREAM_SMOOTH_PARA_S, *LPPU_STREAM_SMOOTH_PARA_S;

//查询云台当前位置
typedef struct PU_PTZ_CURRENT_LOCATION
{
    LONG lPTZHorDegree;                     //水平角度
    LONG lPTZVerDegree;                     //垂直角度
    ULONG ulLenMultiple;                    //镜头变倍整数部分
    ULONG ulDotLenMultiple;                 //镜头变倍小数部分
    ULONG ulZoomRatio;                      //数字变倍整数部分
    ULONG ulDotZoomRatio;                   //数字变倍小数部分
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_PTZ_CURRENT_LOCATION_S, *LPPU_PTZ_CURRENT_LOCATION_S;

typedef struct PU_IGT_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bIgtEnable;                       /*智能总开关*/
    BOOL  bTrackEnable;                     /*目标轨迹跟踪使能*/
    PU_IGT_FIELD_TYPE_E enFieldType;        /*场景模式类型*/
    PU_IGT_MINTARGET_SIZE_E enMinTargetSize;/*前景目标最小尺寸设定*/
    PU_IGT_SHADOW_MODE_E enShadowMode;      /*去阴影模式设定*/
    PU_IGT_DETECT_SENS_E enDetectSens;      /*目标检测灵敏度设定*/
    BOOL bInsensitiveObject;                /*是否显示不敏感目标信息*/
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_ALARM_PARA_S, *LPPU_IGT_ALARM_PARA_S;

typedef struct PU_IGT_POINT
{
    USHORT usPointPosX;                     /*点X轴坐标(0-352)*/
    USHORT usPointPosY;                     /*点Y轴坐标(0-288)*/
}PU_IGT_POINT_S;

typedef struct PU_IGT_TW_LINE
{
    UCHAR ucDirection;                      /*检测方向: 0:both 1:Left->right 2:right->left */
    PU_IGT_POINT_S stStartPoit;             /*绊线起始点*/
    PU_IGT_POINT_S stEndPoit;               /*绊线终止点*/
    ULONG ulLineIndex;                      /*绊线索引*/
    BOOL bEnable;                           /*该线是否使能*/
    CHAR szLineName[PU_IGT_LINE_NAME_LEN];  /*绊线名称*/
}PU_IGT_TW_LINE_S, *LPPU_IGT_TW_LINE_S;

typedef struct PU_IGT_TW_LINE_LIST
{
    ULONG ulLineNum;
    PU_IGT_TW_LINE_S szTWLineList[PU_TRIPWIRE_LEN_NUM_MAX];
}PU_IGT_TW_LINE_LIST_S;

/* ------------绊线检测参数结构体------------ */
typedef struct PU_TW_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulAlarmInterval;                  //告警检测间隔
    PU_IGT_TARGET_MODE_E  enTargetDetecMode;//目标识别模式
    PU_IGT_TW_LINE_LIST_S stlineList;       /*绊线数组：获取时会返回所有绊线坐标信息，如果坐标为0说明不再当前镜头范围内（会返回索引）；*/
                                            /*设置时该参数可选，如果ulLineNum不等于0会全部下放，等于0时不下发*/
    PU_ALARM_TIME_LIST_S stTWGuardPlan;     //布防计划
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_TW_ALARM_PARA_S, *LPPU_TW_ALARM_PARA_S;

typedef struct PU_IGT_TW_LINE_ITEM
{
    ULONG ulChannelId;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_TW_LINE_S stIgtTwLine;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_TW_LINE_ITEM_S, *LPPU_IGT_TW_LINE_ITEM_S;

/*区域检测*/
typedef struct PU_IGT_AREA
{
    UINT uPointNum;                                                 /*区域多边形顶点数目*/
    PU_IGT_POINT_S stPoint[PU_IGT_AREA_POINTS_NUM];                 /*点坐标*/
    ULONG ulAreaIndex;                                              /*区域索引*/
    BOOL bEnable;                                                   /*改区域是否使能*/
    CHAR szAreaName[PU_IGT_AREA_NAME_LEN];                          /*区域名称*/
    PU_PTZ_CURRENT_LOCATION_S stLocation;                           /*云台位置信息*/
}PU_IGT_AREA_S, *LPPU_IGT_AREA_S;

typedef struct PU_IGT_AERADTC_LIST
{
    ULONG ulAreaNum;
    PU_IGT_AREA_S stArea[PU_IGT_AREA_NUM];
}PU_IGT_AERADTC_LIST_S;

typedef struct PU_IGT_AEREDTC_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulAlarmInterval;                  //告警检测间隔
    PU_IGT_TARGET_MODE_E enTargetDetecMode; //目标识别模式
    ULONG ulRemainTime;                     //停留时间(只在徘徊时生效)
    PU_IGT_AERADTC_LIST_S stAreaDtcList;    /*区域数组：获取时会返回所有区域信息，如果区域坐标为0说明不再当前镜头范围内（会返回索引）；*/
                                            /*设置时该参数可选，如果ulAreaNum不等于0会全部下放，等于0时不下发*/
    PU_ALARM_TIME_LIST_S stAreaGuardPlan;   //布防计划
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_AREADTC_ALARM_PARA_S, *LPPU_IGT_AREADTC_ALARM_PARA_S;

typedef struct PU_IGT_AREA_ITEM
{
    ULONG ulChannelId;
    PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_AREA_S stIgtArea;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_AREA_ITEM_S, *LPPU_IGT_AREA_ITEM_S;

//Discover 发现响应包
typedef struct PU_DISCOVER_DEVICE_INFO
{
    CHAR  szDeviceMac[PU_MAC_ADDR_LEN];        //设备MAC地址
    CHAR  szDeviceType[PU_DEVICE_TYPE_LEN];    //设备型号
    CHAR  szDeviceVersion[PU_VERSION_LEN];     //设备版本号
    CHAR  szDeviceName[PU_DEVICE_NAME_LEN];    //设备名称
    CHAR  szDeviceIp[PU_IP4_ADDR_LEN];         //设备IP
    CHAR  szDeviceMask[PU_IP4_ADDR_LEN];       //设备掩码
    CHAR  szDeviceGateway[PU_IP4_ADDR_LEN];    //设备网关
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DISCOVER_DEVICE_INFO_S, *LPPU_DISCOVER_DEVICE_INFO_S;

typedef struct PU_DISCOVER_DEVICE_LIST
{
    ULONG ulDeviceNum;
    PU_DISCOVER_DEVICE_INFO_S stDeviceInfo[PU_DEVICE_NUM_MAX];
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DISCOVER_DEVICE_LIST_S, *LPPU_DISCOVER_DEVICE_LIST_S;

/* 网口地址参数 */
typedef struct PU_DEVICE_ETHERNET_PARA
{
    BOOL bDhcpEnable;                          //是否启用DHCP
    CHAR szIPAddress[PU_IP4_ADDR_LEN];         //IP地址
    CHAR szSubNetMask[PU_IP4_ADDR_LEN];        //子网掩码
    CHAR szGateWayAddress[PU_IP4_ADDR_LEN];    //网关地址
    CHAR szFirstDNSAddress[PU_IP4_ADDR_LEN];   //第一组DNS地址
    CHAR szSecondDNSAddress[PU_IP4_ADDR_LEN];  //第二组DNS地址
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_ETHERNET_PARA_S, *LPPU_DEVICE_ETHERNET_PARA_S;

/* NTP参数 */
typedef struct PU_NTP_PARA
{
    BOOL  bNTPEnable;                       //NTP使能
    ULONG ulSynInterval;                    //NTP同步间隔
    CHAR  szNTPAddress[PU_DOMAIN_LEN];      //NTP服务器地址:域名或者IP地址
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_NTP_PARA_S, *LPPU_NTP_PARA_S;

//红外灯参数
typedef struct  PU_IRLIGHT_PARA
{
    BOOL  bEnable;                          //使能
    ULONG ulIRLightLum;                     //亮度
}PU_IRLIGHT_PARA_S;

typedef struct PU_IRLIGHT_LIST
{
    ULONG ulChannelId;
    PU_IRLIGHT_MODE_E enIRLightMode;
    PU_IRLIGHT_PARA_S stIRLightMPara[PU_IRLIGHT_NUM_MAX];           //红外灯数据，手动模式时必填
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IRLIGHT_LIST_S, *LPPU_IRLIGHT_LIST_S;

#pragma pack(pop)

/*******************************************************************************************************************/
/*                                             SDK Function Declaration                                            */
/*******************************************************************************************************************/


/******************************************************************************************************/
/*                                         Common Use Function                                        */
/******************************************************************************************************/

//initialize sdk resources
_HW_PU_API BOOL __stdcall IVS_PU_Init(ULONG ulLinkMode, CHAR *szLocalIP, ULONG ulLocalPort);

//login to device
_HW_PU_API ULONG __stdcall IVS_PU_Login(CHAR *szLoginIP, ULONG ulLoginPort, CHAR *szUserName, CHAR *szPasswd);

//login to device
_HW_PU_API BOOL __stdcall IVS_PU_LoginByID(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

//logout from device
_HW_PU_API BOOL __stdcall IVS_PU_Logout(ULONG ulIdentifyID);

//sdk event callback function type
typedef LONG(CALLBACK * pfGetEventInfoCallBack)(VOID *arg);

//register sdk event callback 
_HW_PU_API BOOL __stdcall IVS_PU_EventStatesCallBack(pfGetEventInfoCallBack fEventResportCallBack);

//release sdk resources
_HW_PU_API BOOL __stdcall IVS_PU_Cleanup();

//get device version info
_HW_PU_API BOOL __stdcall IVS_PU_GetVersion(ULONG *pulVersion);

//get sdk last error
_HW_PU_API ULONG __stdcall IVS_PU_GetLastError();

//get error message by error number
_HW_PU_API CONST CHAR* __stdcall IVS_PU_GetErrorMsg(ULONG ulErrorNo);

//get device log info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogInfo(ULONG ulIdentifyID, PU_LOG_TYPE_E enLogType, LPPU_LOG_REQ_PARA_S pstLogReqPara, LPPU_LOG_INFO_S pstDeviceLogInfo);

//device time 
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceTime(ULONG ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceTime(ULONG ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);

//reboot device
_HW_PU_API BOOL __stdcall IVS_PU_Reboot(ULONG ulIdentifyID);

//restore device default config
_HW_PU_API BOOL __stdcall IVS_PU_Restore(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

//get device info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceInfo(ULONG ulIdentifyID, LPPU_DEVICEINFO_S pstDeviceInfo);

//get device system status info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceStatusInfo(ULONG ulIdentifyID, LPPU_SYS_STATUS_INFO_S pstSysStatusInfo);

//remote upgrade device
_HW_PU_API BOOL __stdcall IVS_PU_Upgrade(ULONG ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo);

//get device upgrade progress
_HW_PU_API INT __stdcall IVS_PU_GetUpgradeProgress(ULONG ulIdentifyID);

//write sdk log to file
_HW_PU_API BOOL __stdcall IVS_PU_WriteLogToFile(ULONG ulLogEnable, CHAR *szFileName, ULONG ulFileNum, ULONG ulSizePerFile);

//device config file
_HW_PU_API BOOL __stdcall IVS_PU_GetConfigFile(ULONG ulIdentifyID, CHAR szConfigFile[PU_CONFIG_FILE_PATH_MAX]);
_HW_PU_API BOOL __stdcall IVS_PU_SetConfigFile(ULONG ulIdentifyID, CHAR szConfigFile[PU_CONFIG_FILE_PATH_MAX], CHAR *pszUserName, CHAR *pszPasswd);

//device log language
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogLanguage(ULONG ulIdentifyID, PU_LANGUAGE_TYPE_E *penLanguage);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceLogLanguage(ULONG ulIdentifyID, PU_LANGUAGE_TYPE_E enLanguage);

#ifdef _WIN32
//device list info by auto discovery
_HW_PU_API BOOL __stdcall IVS_PU_DiscoveryLocalDeviceList(LPPU_DISCOVER_DEVICE_LIST_S pstDeviceList);
#endif

//change device password
_HW_PU_API BOOL __stdcall IVS_PU_ChangeDevicePassword(ULONG ulIdentifyID, CHAR* pszUserName, CHAR* pszOldPasswd, CHAR* pszNewPasswd);

//change device ip address
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceEthernetPara(ULONG ulIdentifyID, LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceEthernetPara(ULONG ulIdentifyID, LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);

//response pu register message
_HW_PU_API BOOL __stdcall IVS_PU_ResponseDeviceRegister(ULONG ulIdentifyID, LPPU_DEVICE_REGISTER_RSP_S pstDevRegisterRsp);



/******************************************************************************************************/
/*                                      IPC Dedicated Functions                                       */
/******************************************************************************************************/


/************************           Device Parameters Functions     ******************************/

//device video stream infos
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoStreamInfo(ULONG ulIdentifyID, LPPU_VIDEO_STREAM_INFO_S pstVideoStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoStreamInfo(ULONG ulIdentifyID, LPPU_VIDEO_STREAM_INFO_S pstVideoStreamInfo);

//device audio stream infos
_HW_PU_API BOOL __stdcall IVS_PU_GetAudioStreamInfo(ULONG ulIdentifyID, LPPU_AUDIO_INFO_S pstAudioInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetAudioStreamInfo(ULONG ulIdentifyID, LPPU_AUDIO_INFO_S pstAudioInfo);

//device video display infos, and restore default display params
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoDisplayInfo(ULONG ulIdentifyID, LPPU_VIDEO_DISPLAY_INFO_S pstVideoDisplayInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoDisplayInfo(ULONG ulIdentifyID, LPPU_VIDEO_DISPLAY_INFO_S pstVideoDisplayInfo);
_HW_PU_API BOOL __stdcall IVS_PU_RestoreDefaultDisplayPara(ULONG ulIdentifyID, ULONG ulChannelId); 

//device ROI params
_HW_PU_API BOOL __stdcall IVS_PU_GetROIInfo(ULONG ulIdentifyID, LPPU_ROI_INFO_S pstROIInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetROIInfo(ULONG ulIdentifyID, LPPU_ROI_INFO_S pstROIInfo);

//device OSD params extern, can set at most 7 OSD strings
_HW_PU_API BOOL __stdcall IVS_PU_GetOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara);

//device privacy mask
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMask(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_S pstPrivacyMaskArray);
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMask(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_S pstPrivacyMaskArray);

#ifdef _WIN32
//set platform params
_HW_PU_API BOOL __stdcall IVS_PU_SetPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_TYPE_E enPlatform, VOID *arg);
#endif

//IVS platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetIVSPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_IVS_PARA_S pstIvsPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIVSPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_IVS_PARA_S pstIvsPlatformPara);

//GBT 28281 platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetGBTPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_GBT_PARA_S pstGbtPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGBTPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_GBT_PARA_S pstGbtPlatformPara);

//SDK platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetSDKPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_SDK_PARA_S pstSdkPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDKPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_SDK_PARA_S pstSdkPlatformPara);

//get/set device dynamic stream info
_HW_PU_API BOOL __stdcall IVS_PU_GetDynamicStreamInfo(ULONG ulIdentifyID, LPPU_DYNAMIC_STREAM_INFO_S pstDynamicStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetDynamicStreamInfo(ULONG ulIdentifyID, LPPU_DYNAMIC_STREAM_INFO_S pstDynamicStreamInfo);

//set device watermark params
_HW_PU_API BOOL __stdcall IVS_PU_SetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType, BOOL bWaterMarkEnable);

//device record plans
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordPlanList(ULONG ulIdentifyID, LPPU_RECORD_PLAN_S pstRecordPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordPlanList(ULONG ulIdentifyID, LPPU_RECORD_PLAN_S pstRecordPlan);

//get device record info
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordInfoList(ULONG ulIdentifyID, LPPU_RECORD_INQUIRE_S pstRecordInquire, LPPU_RECORD_LIST_S pstRecordList);

//device record full strategy
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordFullStrategy(ULONG ulIdentifyID, LPPU_RECORD_STRATEGY_S pstRecordStrategy);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordFullStrategy(ULONG ulIdentifyID, LPPU_RECORD_STRATEGY_S pstRecordStrategy);

//set device stream layer code mode 
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType, BOOL bEnable);

//set device stream function params
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamFunctionPara(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enPURecordStream, PU_STREAM_TYPE_E enPlatRecordStream);

//get device ability params 
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceAbility(ULONG ulIdentifyID, LPPU_DEVICE_ABILITY_S pstDeviceAbility);

//get device stream ability params
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamAbility(ULONG ulIdentifyID, LPPU_STREAM_ABILITY_S pstStreamAbilityPara);

//device snapshot
_HW_PU_API BOOL __stdcall IVS_PU_StartSnapShot(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSnapCount, ULONG ulSnapInterval, PU_SNAPSHOT_TYPE_E enSnapType);
_HW_PU_API BOOL __stdcall IVS_PU_ResponseUploadImageURL(ULONG ulIdentifyID, ULONG ulSessionId, PU_ERROR_CODE_E enErrorCode, CHAR *pszUploadURL);
_HW_PU_API BOOL __stdcall IVS_PU_ResponseUploadImageCompleteNotify(ULONG ulIdentifyID, ULONG ulSessionId, PU_ERROR_CODE_E enErrorCode);

//device FEC params
_HW_PU_API BOOL __stdcall IVS_PU_GetFECPara(ULONG ulIdentifyID, LPPU_FEC_PARA_S pstFecPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFECPara(ULONG ulIdentifyID, LPPU_FEC_PARA_S pstFecPara);

//device EPTZ params
_HW_PU_API BOOL __stdcall IVS_PU_GetEPTZPara(ULONG ulIdentifyID, LPPU_EPTZ_PARA_S pstEPTZPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetEPTZPara(ULONG ulIdentifyID, LPPU_EPTZ_PARA_S pstEPTZPara);

//device ONVIF protocol 
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFSwitch(ULONG ulIdentifyID, BOOL bEnable);

//device ONVIF params
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFPwdPara(ULONG ulIdentifyID, LPPU_ONVIF_PWD_PARA_S pstOnvifPwdPara);

//device ONVIF stream params
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFStreamCodeType(ULONG ulIdentifyID, PU_VIDEO_CODE_TYPE_E *penVideoCodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFStreamCodeType(ULONG ulIdentifyID, PU_VIDEO_CODE_TYPE_E enVideoCodeType);

//device stream buffering params
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamSmoothPara(ULONG ulIdentifyID, LPPU_STREAM_SMOOTH_PARA_S pstStreamSmoothPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamSmoothPara(ULONG ulIdentifyID, LPPU_STREAM_SMOOTH_PARA_S pstStreamSmoothPara);

//device qos dscp params
_HW_PU_API BOOL __stdcall IVS_PU_GetQosDscpPara(ULONG ulIdentifyID, PU_DSCP_TYPE_E *penDscpType, ULONG *pulDscpValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetQosDscpPara(ULONG ulIdentifyID, PU_DSCP_TYPE_E enDscpType, ULONG ulDscpValue);

//device MTU value
_HW_PU_API BOOL __stdcall IVS_PU_GetMTUPara(ULONG ulIdentifyID, ULONG *pulMtuValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetMTUPara(ULONG ulIdentifyID, ULONG ulMtuValue);

//device record upload band width
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordUploadBandwidth(ULONG ulIdentifyID, BOOL *pbEnable, ULONG *pulMaxUploadRate);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordUploadBandwidth(ULONG ulIdentifyID, BOOL bEnable, ULONG ulMaxUploadRate);

//device band width self adaption
_HW_PU_API BOOL __stdcall IVS_PU_GetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

//device NTP params
_HW_PU_API BOOL __stdcall IVS_PU_GetNTPPara(ULONG ulIdentifyID, LPPU_NTP_PARA_S pstNtpPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetNTPPara(ULONG ulIdentifyID, LPPU_NTP_PARA_S pstNtpPara);



/******************************           Stream Functions     **********************************/

//key frame request
_HW_PU_API BOOL __stdcall IVS_PU_KeyFrameRequest(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulStreamId);

//real play callback function type
typedef VOID(CALLBACK *pfRealDataCallBack)(CHAR *szBuffer, LONG lSize, VOID *pUsrData);

//real play
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay(ULONG ulIdentifyID, LPPU_REAL_PLAY_INFO_S pstRealPlayInfo, pfRealDataCallBack fRealDataCallBack, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_StopRealPlay(ULONG ulIdentifyID, ULONG ulRealHandle);
_HW_PU_API BOOL __stdcall IVS_PU_StopAllRealPlay(ULONG ulIdentifyID);

//voice broadcast
_HW_PU_API ULONG __stdcall IVS_PU_StartVoiceBroadcast(ULONG ulIdentifyID, LPPU_VOICE_INFO_S pstVoiceBroadcastInfo);
_HW_PU_API BOOL __stdcall IVS_PU_StopVoiceBroadcast(ULONG ulIdentifyID, ULONG ulVBHandle);

//voice talk back callback function type
typedef VOID(CALLBACK *pfVoiceTBCallBack)(CHAR *szBuffer, LONG lSize, VOID *pUsrData);

//voice talk back
_HW_PU_API ULONG __stdcall IVS_PU_StartVoiceTB(ULONG ulIdentifyID, LPPU_VOICE_INFO_S pstVoiceTBInfo, pfVoiceTBCallBack fVoiceTBCallBack, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_StopVoiceTB(ULONG ulIdentifyID, ULONG ulVoiceTBHandle);

//Feed voice data for voice talk back and broadcast
_HW_PU_API BOOL __stdcall IVS_PU_FeedVoiceData(ULONG ulIdentifyID, ULONG ulVBHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType);

//save real play data
_HW_PU_API BOOL __stdcall IVS_PU_SaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle, LPPU_SAVE_REALDATA_INFO_S pstSaveRealDataInfo);
_HW_PU_API BOOL __stdcall IVS_PU_StopSaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle);

//save local snapshot picture 
_HW_PU_API BOOL __stdcall IVS_PU_SavePicture(ULONG ulIdentifyID, ULONG ulRealHandle, LPPU_SAVE_PICTURE_INFO_S pstSavePictureInfo);

//media signal 
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlay(ULONG ulIdentifyID, LPPU_MEDIA_PLAY_INFO_S pstMediaPlayReqInfo, LPPU_MEDIA_PLAY_RSP_S pstMediaPlayRspInfo);
_HW_PU_API BOOL __stdcall IVS_PU_MeidaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload, ULONG ulAudioPayload, ULONG ulIgtPayload);
_HW_PU_API BOOL __stdcall IVS_PU_MeidaStop(ULONG ulIdentifyID, ULONG ulSessionId);


/***************************           ISP Parameters Functions     *********************************/

//device iris emendation
_HW_PU_API BOOL __stdcall IVS_PU_IrisEmendation(ULONG ulIdentifyID, LPPU_IRIS_EMENDATION_S pstIrisEmendation);
//device day night mode
_HW_PU_API BOOL __stdcall IVS_PU_GetDayNightMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_DAYNIGHT_MODE_E *penDayNightMode, ULONG *pulSensitivity);
_HW_PU_API BOOL __stdcall IVS_PU_SetDayNightMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_DAYNIGHT_MODE_E enDayNightMode, ULONG ulSensitivity);

//device flicker mode
_HW_PU_API BOOL __stdcall IVS_PU_GetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_FLICKER_MODE_E *penFlickerMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_FLICKER_MODE_E enFlickerMode);

//device AE metering mode
_HW_PU_API BOOL __stdcall IVS_PU_GetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_AEMETERING_MODE_E *penAEMeteringMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_AEMETERING_MODE_E enAEMeteringMode);

//device WDR enable state
_HW_PU_API BOOL __stdcall IVS_PU_GetWDR(ULONG ulIdentifyID, ULONG ulChannelId, PU_WDR_SWITCH_MODE_E *penSwitchMode, ULONG *pulAutoType, ULONG *pulSensitivity);
_HW_PU_API BOOL __stdcall IVS_PU_SetWDR(ULONG ulIdentifyID, ULONG ulChannelId, PU_WDR_SWITCH_MODE_E enSwitchMode, ULONG ulAutoType, ULONG ulSensitivity);

//device auto exposure mode
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoExposureMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_AE_MODE_E *penAEMode, ULONG *pulValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoExposureMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_AE_MODE_E enAEMode, ULONG ulValue);

//device white balance mode
_HW_PU_API BOOL __stdcall IVS_PU_GetWhiteBalanceMode(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulWBMode, ULONG *pulRedOffset, ULONG *pulBlueOffset);
_HW_PU_API BOOL __stdcall IVS_PU_SetWhiteBalanceMode(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulWBMode, ULONG ulRedOffset, ULONG ulBlueOffset);

//device back light compensation
_HW_PU_API BOOL __stdcall IVS_PU_GetBackLightCompensation(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable, ULONG *pulCoefficient);
_HW_PU_API BOOL __stdcall IVS_PU_SetBackLightCompensation(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable, ULONG ulCoefficient);

//device slow shutter mode
_HW_PU_API BOOL __stdcall IVS_PU_GetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

//device automatic exposure response time
_HW_PU_API BOOL __stdcall IVS_PU_GetAEResponseTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulAERspTime);
_HW_PU_API BOOL __stdcall IVS_PU_SetAEResponseTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulAERspTime);

//device exposure compensation
_HW_PU_API BOOL __stdcall IVS_PU_GetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulCoefficient);
_HW_PU_API BOOL __stdcall IVS_PU_SetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulCoefficient);


/***************************           PTZ Parameters Functions     *********************************/

//device serial port info
_HW_PU_API BOOL __stdcall IVS_PU_GetSerialPortInfo(ULONG ulIdentifyID, LPPU_SERIAL_PORT_PARA_S pstSerialPortPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSerialPortInfo(ULONG ulIdentifyID, LPPU_SERIAL_PORT_PARA_S pstSerialPortPara);

//device ptz preset
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_Preset(ULONG ulIdentifyID, LPPU_PTZ_PRESET_PARA_S pstPtzPresetPara);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_GetPresetList(ULONG ulIdentifyID, LPPU_PTZ_PRESET_LIST_PARA_S pstPtzPresetList);

//device ptz control
_HW_PU_API BOOL __stdcall IVS_PU_PTZControl(ULONG ulIdentifyID, LPPU_PTZ_CONTROL_PARA_S pstPtzControlPara);

//device ptz cruise track
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_CruiseTrack(ULONG ulIdentifyID, LPPU_PTZ_CRUISE_TRACK_PARA_S pstPtzCruiseTrack);

//device ptz info
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZInfo(ULONG ulIdentifyID, LPPU_PTZ_PARA_S pstPtzPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZInfo(ULONG ulIdentifyID, LPPU_PTZ_PARA_S pstPtzPara);

//device guard position params
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardPositionPara(ULONG ulIdentifyID, LPPU_GUARD_POSITION_PARA_S pstGuardPositionPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGuardPositionPara(ULONG ulIdentifyID, LPPU_GUARD_POSITION_PARA_S pstGuardPositionPara);

//get device ptz current location 
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCurrentLocation(ULONG ulIdentifyID, LPPU_PTZ_CURRENT_LOCATION_S pstCurrentLocation);

//device transparent channel
_HW_PU_API BOOL __stdcall IVS_PU_GetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, BOOL* pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, BOOL bEnable);
_HW_PU_API BOOL __stdcall IVS_PU_InvokeTransparentCmd(ULONG ulIdentifyID, LPPU_TRANSPARENT_CMD_S pstTransparentCmdInfo);

//device infrared light params
_HW_PU_API BOOL __stdcall IVS_PU_GetInfraredLightPara(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetInfraredLightPara(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);


/***************************          Alarm Parameters Functions     ********************************/

//device alarm callback function type
typedef LONG(CALLBACK *pfGetAlarmInfoCallBack)(LPPU_ALARM_REPORT_S pstAlarmReport, VOID *pUsrData);
//register device alarm callback function
_HW_PU_API BOOL __stdcall IVS_PU_AlarmInfoStatesCallBack(ULONG ulIdentifyID, pfGetAlarmInfoCallBack fAlarmResportCallBack, VOID *pUsrData);

//device alarm params, include: temperature alarm, motion detection alarm, hide alarm
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmPara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, VOID *arg);
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmPara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, VOID *arg);

//set device guard 
_HW_PU_API BOOL __stdcall IVS_PU_GuardAlarm(ULONG ulIdentifyID, LPPU_GUARD_PARA_S pstGuardPara);

//get device guard state
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardState(ULONG ulIdentifyID, LPPU_GUARD_STATE_S pstGuardStates);

//get device current temperature
_HW_PU_API BOOL __stdcall IVS_PU_GetTemperature(ULONG ulIdentifyID, LONG *plCurretTemp);

//device switch input and output params
_HW_PU_API BOOL __stdcall IVS_PU_GetDIOPara(ULONG ulIdentifyID, LPPU_DIO_PARA_S pstSwitchDioPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDIOPara(ULONG ulIdentifyID, LPPU_DIO_PARA_S pstSwitchDioPara);

//device DI state
_HW_PU_API BOOL __stdcall IVS_PU_GetDIState(ULONG ulIdentifyID, ULONG ulInputId, LONG *plInputState);

//device DO state
_HW_PU_API BOOL __stdcall IVS_PU_GetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LONG *plOutputState);
_HW_PU_API BOOL __stdcall IVS_PU_SetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LONG lOutputState);

//device alarm linkage para with alarm type
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmLinkagePara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, ULONG ulAlarmId, LPPU_ALARM_LINKAGE_PARA_S pstAlarmLinkagePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmLinkagePara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, ULONG ulAlarmId, LPPU_ALARM_LINKAGE_PARA_S pstAlarmLinkagePara);


/************************      Intelligent Parameters Functions     ******************************/

//device intelligent switch params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtPara(ULONG ulIdentifyID, LPPU_IGT_ALARM_PARA_S pstIgtAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtPara(ULONG ulIdentifyID, LPPU_IGT_ALARM_PARA_S pstIgtAlarmPara);

//device intelligent tripwire alarm params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtTripwireAlarmPara(ULONG ulIdentifyID, LPPU_TW_ALARM_PARA_S pstIgtTwAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtTripwireAlarmPara(ULONG ulIdentifyID, LPPU_TW_ALARM_PARA_S pstIgtTwAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_IgtTripwireLineItem(ULONG ulIdentifyID, LPPU_IGT_TW_LINE_ITEM_S pstLineItem);

//device intelligent area detection alarm params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtAreaDtcAlarmPara(ULONG ulIdentifyID, PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType, LPPU_IGT_AREADTC_ALARM_PARA_S pstIgtAreaDtcAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtAreaDtcAlarmPara(ULONG ulIdentifyID, PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType, LPPU_IGT_AREADTC_ALARM_PARA_S pstIgtAreaDtcAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_IgtAreaItem(ULONG ulIdentifyID, LPPU_IGT_AREA_ITEM_S pstAreaItem);



/******************************************************************************************************/
/*                                      DEC Dedicated Functions                                       */
/******************************************************************************************************/


//获取解码器端口能力列表
_HW_PU_API BOOL __stdcall IVS_PU_GetDecPortAbility(ULONG ulIdentifyID, LPPU_DEC_PORT_ABILITY_LIST_S pstDecIOAbilityList);

//获取解码器端口信息列表
_HW_PU_API BOOL __stdcall IVS_PU_GetDecPortInfoList(ULONG ulIdentifyID, LPPU_DEC_PORT_INFO_LIST_S pstDecPortInfoList);

//设置解码器端口参数
_HW_PU_API BOOL __stdcall IVS_PU_SetDecPortInfoList(ULONG ulIdentifyID, LPPU_DEC_PORT_INFO_LIST_S pstDecPortInfoList);

//获取解码器通道能力列表
_HW_PU_API BOOL __stdcall IVS_PU_GetDecChannelAbility(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_ABILITY_LIST_S pstDecChannelAbilityList);

//获取解码器通道信息列表
_HW_PU_API BOOL __stdcall IVS_PU_GetDecChannelInfoList(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_INFO_LIST_S pstDecChannelInfoList);

//设置通道参数
_HW_PU_API BOOL __stdcall IVS_PU_SetDecChannelInfo(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_INFO_S pstDecChannelInfo);

//设置解码器的解密信息
_HW_PU_API BOOL __stdcall IVS_PU_SetDecDecryptionInfo(ULONG ulIdentifyID, LPPU_DEC_DECRYPTION_INFO_S pstDecDecryptionInfo);

//设置解码器音频端口参数
_HW_PU_API BOOL __stdcall IVS_PU_SetDecAudioPortInfo(ULONG ulIdentifyID, LPPU_DEC_AUDIO_INFO_S pstDecAudioInfo);

//获取解码器音频端口参数
_HW_PU_API BOOL __stdcall IVS_PU_GetDecAudioPortInfo(ULONG ulIdentifyID, LPPU_DEC_AUDIO_INFO_S pstDecAudioInfo);

//开始解码
_HW_PU_API LONG __stdcall IVS_PU_StartDec(ULONG ulIdentifyID, LPPU_DEC_INFO_S *pstDecInfo);

//向解码器发送数据流,只支持25帧的发流
_HW_PU_API BOOL __stdcall IVS_PU_MatrixSendData(ULONG ulPassiveHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType);

//向解码器发送数据流,支持动态修改帧率
_HW_PU_API BOOL __stdcall IVS_PU_MatrixSendDataEx(ULONG ulPassiveHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType, ULONG ulFrameRate);

//初始化解码业务
_HW_PU_API BOOL __stdcall IVS_PU_InitDecBusiness(ULONG ulIdentifyID, ULONG ulChannelId, PU_PROTOCOL_TYPE_E enProtocolType, LPPU_INIT_DECODE_INFO_RSP_S pstInitDecRspInfo);

//开始解码业务
_HW_PU_API BOOL __stdcall IVS_PU_StartDecBusiness(ULONG ulIdentifyID, LPPU_START_DECODE_INFO_S pstStartDecInfo);

//停止解码
_HW_PU_API BOOL __stdcall IVS_PU_StopDec(ULONG ulIdentifyID, ULONG ulChannelId);

//停止所有解码
_HW_PU_API BOOL __stdcall IVS_PU_StopDecAll(ULONG ulIdentifyID);



/*******************************************************************************************************************/
/*                                             SDK Function Declaration                                            */
/*******************************************************************************************************************/


#endif 
