/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_pub.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created:
        Author:  
   Description: 该文件定义了sdk相关的枚举、结构体

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------

*******************************************************************************/
#ifndef __IMOS_SDK_PUB_H__
#define __IMOS_SDK_PUB_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

/**
 * @struct tagMwPoint
 * @brief 点坐标
 * @attention 无
 */
typedef struct tagMwPoint
{
    ULONG ulX;        /**< 横坐标 */
    ULONG ulY;        /**< 纵坐标 */
}IMOS_MW_POINT_S;

/**
 * @struct tagMwPoint
 * @brief 线坐标结构
 * @attention 无
 */
typedef struct tagMwLine
{
    IMOS_MW_POINT_S stHead;       /**< 头坐标 */
    IMOS_MW_POINT_S stTail;       /**< 尾坐标 */
}IMOS_MW_LINE_S;

/**
 * @struct tagMwRectangle
 * @brief 矩形框坐标结构
 * @attention 无
 */
typedef struct tagMwRectangle
{
    IMOS_MW_POINT_S stTopLeft;       /**< 左上角坐标 */
    IMOS_MW_POINT_S stBotRight;      /**< 右下角坐标 */
}IMOS_MW_RECTANGLE_S;

/**
 * @struct tagMwQuadrangle
 * @brief 四方形框坐标结构
 * @attention 无
 */
typedef struct tagMwQuadrangle
{
    IMOS_MW_POINT_S stTopLeft;       /**< 左上角坐标 */
    IMOS_MW_POINT_S stTopRight;      /**< 右上角坐标 */
    IMOS_MW_POINT_S stBotLeft;       /**< 左下角坐标 */
    IMOS_MW_POINT_S stBotRight;      /**< 右下角坐标 */
}IMOS_MW_QUADRANGLE_S;

/**
* @struct tagMwAddr
* @brief 地址结构
* @attention 
*/
typedef struct tagMwAddr
{
    CHAR szIPAddr[IMOS_MW_IPADDR_LEN];       /**< IP地址 */
    USHORT usPort;                           /**< 端口 */
    USHORT usReserve;                        /**< 保留 */
}IMOS_MW_ADDR_S;

#if 0
#endif

#if 0
#endif 
/******************************* 系统、设备维护相关结构 ***********************************/
/**
 * @struct tagMwPlayerStatus
 * @brief 播放器状态
 * @attention 无
 */ 
typedef struct tagMwPlayerStatus
{
    ULONG ulStreamHandle;           /**< 流句柄 */
    ULONG ulErrCode;                /**< 错误码 */
}IMOS_MW_PLAYER_STATUS_S;


/**
 * @struct tagMwTime
 * @brief 时间信息
 * @attention 
 */
typedef struct tagMwTime
{
    USHORT usYear;           /**< 年，当前年数（如2009年时，该值为2009） */
    USHORT usMonth;          /**< 月，当前月份（1－12） */
    USHORT usMonthDay;       /**< 日，每月的几号（1－31） */
    USHORT usHour;           /**< 时，当前小时数（0－23） */
    USHORT usMinute;         /**< 分，当前分钟数（0－59） */
    USHORT usSecond;         /**< 秒，当前秒数（0－60） */
    USHORT usWeekday;        /**< 周几，每周的星期几（0－6），0 对应周日，1-6 对应周一 至 周六 ， 暂未使用 */
    USHORT usReserve;        /**< 保留 */
}IMOS_MW_TIME_S;

/**
 * @struct tagMwSystemTimeInfo
 * @brief 系统(本地)时间
 * @attention  lTimeZone为 本地时区与零时区的差，例如 北京时间UTC+8,则填写 8
 */
typedef struct tagMwSystemTimeInfo
{
    LONG lTimeZone;                   /**< 设置系统时区, -12到12，对应和标准时间的偏差 */
    IMOS_MW_TIME_S stLocalTime;       /**< 本地时间 */
}IMOS_MW_SYSTEM_TIME_INFO_S;

#if 1
/* 待界面删除后，删除该结构 */
/**
* @struct tagMwSnmpTrapServer
* @brief  SNMP的团体名和TRP服务器地址
* @attention 操作该项配置时，不需要通道号
*/
typedef struct tagMwSnmpTrapServerInfo
{
    CHAR szROCommunity[IMOS_MW_COMMUNITY_LEN + 4];      /**< 只读SNMP团体名 */
    CHAR szRWCommunity[IMOS_MW_COMMUNITY_LEN + 4];      /**< 读写SNMP团体名 */
    CHAR szTrapCommunity[IMOS_MW_COMMUNITY_LEN + 4];    /**< trap上报团体名 */
    CHAR szTrapAddress[IMOS_MW_IPADDR_LEN];             /**< Trap服务器地址 */
    USHORT usSNMPTrapPort;                              /**< TRAP端口号 */
    USHORT usResv;                                      /**< 保留 */
}IMOS_MW_SNMPTRAP_SERVER_INFO_S;
#endif

/**
 * @struct tagMwUserInfo
 * @brief 用户信息
 * @attention 删除用户信息时，只需传入用户名即可
 */
typedef struct tagMwUserInfo
{
    CHAR szUserName[IMOS_MW_USER_NAME_LEN + 4];           /**< 用户名 */
    CHAR szPassword[IMOS_MW_USER_PASSWORD_LEN + 4];       /**< 用户密码 */
    ULONG ulLevel;                                        /**< 用户级别, 参见: IMOS_MW_USERLEVEL_ADMINISTRATOR 等 */
}IMOS_MW_USER_INFO_S;

#if 0
#endif
/******************************* 网口信息 ***********************************/
/**
 * @struct tagMwPPPoE
 * @brief PPPoE配置
 * @attention 无
 */
typedef struct tagMwPPPoE
{
    CHAR szUserName[IMOS_MW_PPPOE_USERNAME_LEN + 4];     /**< PPPoE账号 */
    CHAR szPassword[IMOS_MW_PPPOE_PASSWORD_LEN + 4];     /**< PPPoE密码 */
}IMOS_MW_PPPOE_S;

/**
 * @struct tagMwNetworkInterfaceCfg
 * @brief 网口信息
 * @attention 
 */
typedef struct tagMwNetworkInterfaceCfg
{
    ULONG ulIPGetType;                          /**< IP获取方式, 参见: IMOS_MW_IP_GET_TYPE_STATIC 等 */ 
    IMOS_MW_PPPOE_S stPPPoE;                    /**< PPPoE配置 */
    ULONG ulMTULen;                             /**< MTU长度, IP获取方式为PPPoE时该参数无效 */
    CHAR szIpAddress[IMOS_MW_IPADDR_LEN];       /**< IP地址 */
    CHAR szIpNetmask[IMOS_MW_IPADDR_LEN];       /**< 子网掩码 */
    CHAR szIpGateway[IMOS_MW_IPADDR_LEN];       /**< 网关 */
    ULONG ulWorkMode;                           /**< 网口工作模式, 参见: IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION 等 */
}IMOS_MW_NETWORK_INTERFACE_CFG_S;

#if 0
#endif
/*************************** 图像相关结构 ****************************************/
/**
 * @struct tagMwWDR
 * @brief 宽动态参数 
 * @attention 
 */
typedef struct tagMwWDR
{
    ULONG ulMode;              /**< 宽动态模式, 参见: IMOS_MW_WDR_DISABLE 等 */
    ULONG ulExpRatio;          /**< 曝光比率，暂不支持 */
}IMOS_MW_WDR_S;

/**
 * @struct tagMwMetering
 * @brief 测光参数 
 * @attention
 */
typedef struct tagMwMetering
{
    ULONG ulMode;                  /**< 测光模式, 参见: IMOS_MW_METERING_CENTER 等 */
    IMOS_MW_RECTANGLE_S stArea;    /**< 测光区域 */
}IMOS_MW_METERING_S;

/**
 * @struct tagMwDayNight
 * @brief 昼夜模式参数 
 * @attention
 */
typedef struct tagMwDayNight
{
    ULONG ulMode;              /**< 昼夜模式, 参见: IMOS_MW_DAYNIGHT_AUTO 等 */
    ULONG ulSensitivity;       /**< 切换灵敏度 */
}IMOS_MW_DAYNIGHT_S;

/**
 * @struct tagMwSharpness
 * @brief 锐度参数 
 * @attention
 */
typedef struct tagMwSharpness
{
    ULONG ulMode;              /**< 锐度模式, 参见: IMOS_MW_SHARPNESS_AUTO 等 */
    ULONG ulSharpness;         /**< 锐度值 */
}IMOS_MW_SHARPNESS_S;

/**
 * @struct tagMwDenoise
 * @brief 图像降噪 
 * @attention 无
 */
typedef struct tagMwDenoise
{
    ULONG ul2DLevel;           /**< 2D降噪等级 */
    ULONG ul3DLevel;           /**< 3D降噪等级 */
}IMOS_MW_DENOISE_S;

/**
 * @struct tagMwCustomExposure
 * @brief 自定义曝光参数
 * @attention 无
 */
typedef struct tagMwCustomExposure
{
    ULONG ulMaxIris;                        /**< 最大光圈, 单位: f值*100 */
    ULONG ulMinIris;                        /**< 最小光圈, 单位: f值*100 */
    ULONG ulSlowShutter;                    /**< 最慢快门 */               
    ULONG ulFastShutter;                    /**< 最快快门 */       
    ULONG ulMaxGain;                        /**< 最大增益, 单位: db */
    ULONG ulMinGain;                        /**< 最小增益, 单位: db */
}IMOS_MW_CUSTOM_EXPOSURE_S;

/**
 * @struct tagMwSlowShutter
 * @brief 慢快门
 * @attention 无
 */
typedef struct tagMwSlowShutter
{
    BOOL_T bEnable;                         /**< 慢快门使能项 */
    ULONG ulMaxSlowShutter;                 /**< 最慢慢快门 */
}IMOS_MW_SLOW_SHUTTER_S;

/**
 * @struct tagMwExposure
 * @brief 曝光参数 
 * @attention 
 */
typedef struct tagMwExposure
{
    ULONG ulMode;                                /**< 曝光模式, 参见: IMOS_MW_EXPOSURE_AUTO 等 */
    LONG lExpCompensate;                         /**< 曝光补偿 */
    ULONG ulIris;                                /**< 光圈值, 单位: f值*100 */
    ULONG ulShutter;                             /**< 快门值 */
    ULONG ulGain;                                /**< 增益, 单位: db */
    IMOS_MW_CUSTOM_EXPOSURE_S stCustomExposure;  /**< 自定义曝光参数 */
    IMOS_MW_SLOW_SHUTTER_S stSlowShutter;        /**< 慢快门参数 */
    IMOS_MW_WDR_S stWDR;                         /**< 宽动态参数 */
    IMOS_MW_METERING_S stMetering;               /**< 测光参数 */
    IMOS_MW_DAYNIGHT_S stDayNight;               /**< 昼夜参数 */
}IMOS_MW_EXPOSURE_S;

/**
 * @struct tagMwWhiteBalance
 * @brief 白平衡参数 
 * @attention
 */
typedef struct tagMwWhiteBalance
{
    ULONG ulMode;                           /**< 白平衡模式, 参见: IMOS_MW_WB_AUTO 等 */
    LONG lBlueOffset;                       /**< 蓝色偏移量 */
    LONG lRedOffset;                        /**< 红色偏移量 */
}IMOS_MW_WHITE_BALANCE_S;

/**
 * @struct tagMwImageEnhance
 * @brief 图像增强参数 
 * @attention 
 */
typedef struct tagMwImageEnhance
{
    ULONG ulBrightness;                     /**< 亮度 */
    ULONG ulContrast;                       /**< 对比度 */
    ULONG ulSaturation;                     /**< 饱和度 */
    ULONG ulHue;                            /**< 色调 */
    IMOS_MW_SHARPNESS_S stSharpness;        /**< 锐度参数 */
    IMOS_MW_DENOISE_S stDenoise;            /**< 降噪参数 */
    ULONG ulMirrorMode;                     /**< 镜像模式, 参见: IMOS_MW_MIRROR_MODE_NONE 等 */
}IMOS_MW_IMAGE_ENHANCE_S;

/**
 * @struct tagMwFocus
 * @brief 对焦参数 
 * @attention 
 */
typedef struct tagMwFocus
{
    ULONG ulFocusMode;                       /**< 对焦模式, 参见: IMOS_MW_FOCUS_AUTO 等 */
    ULONG ulAutoFocusSense;                  /**< 自动对焦灵敏度 */
    ULONG ulManualFocusMinDistance;          /**< 最小对焦距离，手动对焦, 单位: 毫米 */
}IMOS_MW_FOCUS_S;

/**
 * @struct tagMwExposureCfg
 * @brief 曝光参数配置
 * @attention  
 */
typedef struct tagMwExposureCfg
{
    ULONG ulImageType;                    /**< 图像类型, 参见: IMOS_MW_IMAGE_TYPE_VIDEO 等 */
    IMOS_MW_EXPOSURE_S stExposure;        /**< 曝光参数 */
}IMOS_MW_EXPOSURE_CFG_S;

/**
 * @struct tagMwWhiteBalanceCfg
 * @brief 白平衡参数配置
 * @attention 
 */
typedef struct tagMwWhiteBalanceCfg
{
    ULONG ulImageType;                         /**< 图像类型, 参见: IMOS_MW_IMAGE_TYPE_VIDEO 等 */
    IMOS_MW_WHITE_BALANCE_S stWhiteBalance;    /**< 白平衡参数 */
}IMOS_MW_WHITE_BALANCE_CFG_S;

/**
 * @struct tagMwImageEnhanceCfg
 * @brief 图像增强参数配置
 * @attention 
 */
typedef struct tagMwImageEnhanceCfg
{
    ULONG ulImageType;                         /**< 图像类型, 参见: IMOS_MW_IMAGE_TYPE_VIDEO 等 */
    IMOS_MW_IMAGE_ENHANCE_S stImageEnhance;    /**< 图像增强参数 */
}IMOS_MW_IMAGE_ENHANCE_CFG_S;

/**
 * @struct tagMwImageEnhanceCfg
 * @brief 对焦参数配置
 * @attention 
 */
typedef struct tagMwFocusCfg
{
    ULONG ulImageType;                         /**< 图像类型, 参见: IMOS_MW_IMAGE_TYPE_VIDEO 等 */
    IMOS_MW_FOCUS_S stFocus;                   /**< 对焦参数 */
}IMOS_MW_FOCUS_CFG_S;

/**
 * @struct tagMwConditionCfgEx
 * @brief 场景 环境参数
 * @attention
 */
typedef struct tagMwConditionCfgEx
{
    ULONG ulType;              /**< 环境参数类型，参见: IMOS_MW_CONDITION_ILLUMINATION 等 */
    LONG lParam1;              /**< 环境参数1 */
    LONG lParam2;              /**< 环境参数2 */
    LONG lParam3;              /**< 环境参数3 */
}IMOS_MW_CONDITION_CFG_EX_S;

#if 0
#endif
/*************************** OSD 相关结构 ****************************************/
/**
 * @struct tagMwOSDInfoParam
 * @brief OSD 叠加内容
 * @attention 无
 */
typedef struct tagMwOSDInfoParam
{
    ULONG ulInfoType;                              /**< 叠加内容类型，参考: IMOS_MW_OSD_INFO_TYPE_UNUSED 等 */
    CHAR szValue[IMOS_MW_OSD_INFO_LEN + 4];        /**< 自定义 OSD 内容 */ 
}IMOS_MW_OSD_INFO_PARAM_S;

/**
* @struct tagMwOSDInfoConf
* @brief 叠加OSD 参数
* @attention 无
*/
typedef struct tagMwOSDInfoConf
{
    ULONG ulIndex;                                                       /**< 叠加区域ID */
    BOOL_T bEnable;                                                      /**< 使能开关 */ 
    IMOS_MW_OSD_INFO_PARAM_S astInfoParam[IMOS_MW_INFO_OSD_LINE_MAX];    /**< 叠加内容 */  
    IMOS_MW_RECTANGLE_S stArea;                                          /**< 叠加区域 */
}IMOS_MW_INFO_OSD_S;

/**
* @struct tagMwInfoOSDCfg
* @brief 叠加OSD 配置
* @attention 删除该配置时，只需指定待删除区域的ID
*/
typedef struct tagMwInfoOSDCfg
{
    ULONG ulAreaNum;                        /**< 叠加区域个数 */
    IMOS_MW_INFO_OSD_S astInfoOSD[1];       /**< 叠加OSD 配置，区域最大个数为: IMOS_MW_INFO_OSD_MAX_NUM */
}IMOS_MW_INFO_OSD_CFG_S;

/**
* @struct tagMwOSDStyleCfg
* @brief 叠加OSD 样式
* @attention 无
*/
typedef struct tagMwOSDStyleCfg
{
    ULONG ulFontStyle;     /**< 字体形式, 参见: IMOS_MW_OSD_FONT_STYLE_NORMAL 等 */
    ULONG ulFontSize;      /**< 字体大小, 参见: IMOS_MW_OSD_FONT_SIZE_LARGE 等 */
    ULONG ulFontType;      /**< 字体, 暂不支持设置 */
    ULONG ulColor;         /**< 颜色, 参见: IMOS_MW_OSD_COLOR_WHITE 等 */
    ULONG ulAlpha;         /**< 透明度, 参见: IMOS_MW_OSD_ALPHA_NO 等 */
    ULONG ulTimeFormat;    /**< 时间格式, 参见: IMOS_MW_TIME_FORMAT_HHMMSS 等 */
    ULONG ulDateFormat;    /**< 日期格式, 参见: IMOS_MW_DATE_FORMAT_YYYYMMDD 等 */
}IMOS_MW_OSD_STYLE_CFG_S;

#if 0
#endif
/******************************* 媒体流相关结构 ***********************************/
/**
 * @struct tagMwResolution
 * @brief 分辨率
 * @attention 
 */
typedef struct tagMwResolution
{
    ULONG ulWidth;           /**< 宽，单位: 像素 */
    ULONG ulHeight;          /**< 高，单位: 像素 */
}IMOS_MW_RESOLUTION_S;

/**
 * @struct tagMwVideoInModeCfg
 * @brief 采集制式
 * @attention 
 */
typedef struct tagMwVideoInModeCfg
{
    IMOS_MW_RESOLUTION_S stResolution;    /**< 采集分辨率 */ 
    ULONG ulFrameRate;                    /**< 采集帧率 */
}IMOS_MW_VIDEOIN_MODE_CFG_S;

/**
 * @struct tagMwVideoStreamConf
 * @brief 视频编码参数
 * @attention 
 */
typedef struct tagMwVideoStreamConf
{
    BOOL_T bIsEnable;                              /**< 启动/关闭编码 0-关闭 1-启动 */
    ULONG ulEncodeFmt;                             /**< 编码格式，参见: IMOS_MW_STREAM_FORMAT_MPEG1 等 */
    IMOS_MW_RESOLUTION_S stResolution;             /**< 编码分辨率 */ 
    ULONG ulBitRate;                               /**< 码率 */
    ULONG ulFrameRate;                             /**< 帧率 */ 
    ULONG ulGopType;                               /**< gop结构参数, 参考: IMOS_MW_GOP_TYPE_IP 等 */  
    ULONG ulIInterval;                             /**< I帧间隔 */
    ULONG ulEncMode;                               /**< 编码模式，参见: IMOS_MW_ENCODE_MODE_CBR 等 */ 
    ULONG ulQuality;                               /**< 编码压缩质量 */
    ULONG ulSmoothValue;                           /**< 码流平滑 */                            
}IMOS_MW_VIDEO_STREAM_CONF_S;

/**
 * @struct tagMwVideoEncoderCfg
 * @brief 视频编码参数配置
 * @attention 获取指定流的编码参数时，需要传入流ID
 */
typedef struct tagMwVideoEncoderCfg
{
    ULONG ulStreamID;                              /**< 流ID, 参见: IMOS_MW_STREAM_ID_MAIN 等 */
    IMOS_MW_VIDEO_STREAM_CONF_S stVideoStreamCfg;  /**< 视频编码参数 */
}IMOS_MW_VIDEO_ENCODER_CFG_S;

/** 
 * @struct tagMwAudioInCfg
 * @brief 音频输入参数
 * @attention 
 */
typedef struct tagMwAudioInCfg
{
    ULONG ulEncFormat;           /**< 音频格式，参见: IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2 等 */
    ULONG ulSampling;            /**< 采样率, 参见: IMOS_MW_AUDIO_SAMPLING_8000 等 */
    ULONG ulBitRate;             /**< 音频码率 */
    BOOL_T bMute;                /**< 闭音设置 */
    ULONG ulInputPlus;           /**< 输入增益(0-255) 默认0 */
}IMOS_MW_AUDIO_IN_CFG_S;

/** 
 * @struct tagMwAudioOutCfg
 * @brief 音频输出参数
 * @attention 操作该项配置时，不需要通道号
 */
typedef struct tagMwAudioOutCfg
{
    BOOL_T bSilence;          /**< 静音设置 */
    ULONG ulAudioOutPlus;     /**< 输出音量 */
}IMOS_MW_AUDIO_OUT_CFG_S;

/**
 * @enum tagMwMediaStreamInfo
 * @brief 媒体流信息
 * @attention 无
 */
typedef struct tagMwMediaStreamInfo
{
    ULONG ulStreamHandle;                         /**< 流句柄 */
    ULONG ulStreamID;                             /**< 流ID, 参见: IMOS_MW_STREAM_ID_MAIN 等 */
    ULONG ulTransMode;                            /**< 传输模式，参见: IMOS_MW_TRANSFER_MODE_RTP_UDP 等 */
    CHAR szIPAddr[IMOS_MW_IPADDR_LEN];            /**< 流目的IP地址 */
    USHORT usPort;                                /**< 流目的端口 */
    USHORT usReserved;                            /**< 保留 */
    ULONG ulMediaType;                            /**< 媒体类型, 参见: IMOS_MW_MEDIA_VIDEO 等 */
    CHAR szUser[IMOS_MW_NAME_LEN];                /**< 流建立者 */
}IMOS_MW_VIDEO_STREAM_INFO_S;

#if 0
#endif
/******************************* 告警布防相关结构 ***********************************/
/**
 * @struct tagMwEventTrap
 * @brief 告警上报结构体
 * @attention  
 */
typedef struct tagMwEventTrap
{
    ULONG ulAlarmCmd;                           /**< 告警命令字, 参见: IMOS_MW_ALARM_SYSTEM_HIGH_TEMPERATURE 等 */  
    LONG lTimeStamp;                            /**< 告警时间 */  
    ULONG ulChannelID;                          /**< 通道ID */  
    ULONG ulSubChannelID;                       /**< 子通道ID */  
    CHAR szIpAddress[IMOS_MW_IPADDR_LEN];       /**< IP地址, 只做标识, 过滤用 */
    CHAR szDeviceID[IMOS_MW_CODE_LEN];          /**< 设备ID, 填MAC地址，用于识别告警来自哪个设备*/          
}IMOS_MW_EVENT_TRAP_S;

#if 0
#endif
/******************************* 云台巡航相关结构 ***********************************/
/**
 * @struct tagMwPTZPresetParam
 * @brief 预置位描述信息
 * @attention 
 */
typedef struct tagMwPTZPresetParam
{
    ULONG ulPresetID;                                     /**<  预置位ID，范围（1--255） */
    CHAR szPresetName[IMOS_MW_PTZ_PRESET_NAME + 4];       /**<  预置位名称 */
}IMOS_MW_PRESET_PARAM_S;

/**
 * @struct tagMwPTZPresetCfg
 * @brief 预置位列表
 * @attention
 */
typedef struct tagMwPTZPresetCfg
{
    ULONG ulPresetNum;                                  /**< 预置位个数 */
    IMOS_MW_PRESET_PARAM_S astPresetCfg[1];             /**< 预置位列表 */
}IMOS_MW_PRESET_CFG_S;

/**
 * @struct tagMwPTZGuardPresetCfg
 * @brief 看守位描述信息
 * @attention 操作该项配置时，不需要通道号
 */
typedef struct tagMwPTZGuardPresetCfg
{
    ULONG ulGuardPreset;       /**< 看守位 */
    ULONG ulDelaySecond;       /**< 延迟时间单位秒 */
}IMOS_MW_GUARD_PRESET_CFG_S;

/**
 * @struct tagMwPTZCfg
 * @brief 云台基本配置信息
 * @attention 操作该项配置时，不需要通道号
 */
typedef struct tagMwPTZCfg
{
    CHAR szPtzFactoryName[IMOS_MW_PTZ_NAME_LEN];       /**< 云台协议名称 */
    ULONG ulAddr;                                      /**< 云台地址码 */
    ULONG ulPtzMode;                                   /**< 云台模式，0 表示内置云台优先；1 表示外置云台优先 */
}IMOS_MW_PTZ_CFG_S;

/**
 * @struct tagMwPTZPhyParamCfg
 * @brief 云台物理配置信息, 通用拉框放大参数配置
 * @attention 操作该项配置时，不需要通道号
 */
typedef struct tagMwPTZPhyParamCfg
{
    BOOL_T bEnableAreaZoom;         /**< 是否使能拉框放大 */
    ULONG ulLevelAngleSpeed;        /**< 水平最大角速度°/S */
    ULONG ulApeakAngleSpeed;        /**< 垂直最大角速度°/S */
    ULONG ulLevelSceneAngleView;    /**< 水平镜头最大视角°*/
    ULONG ulApeakSceneAngleView;    /**< 垂直镜头最大视角°*/
    ULONG ulZoomTime;               /**< 变焦时间ms */
    ULONG ulZoomMul;                /**< 变焦倍数 */
    USHORT usLevelRunAdjustModulus; /**< 横向转动调节系数% */
    USHORT usApeakRunAdjustModulus; /**< 纵向转动调节系数% */
    USHORT usZoomAdjustModulus;     /**< 变焦调节系数% */
    UCHAR ucReserve[2];             /**< 预留 */
}IMOS_MW_PTZ_PHYPARAM_CFG_S;

/**
 * @struct tagMwPTZCommand
 * @brief 云台控制指令
 * @attention 无
 */
typedef struct tagMwPTZCommand
{
    ULONG ulPTZCmdID ;         /**< 云台控制命令类型, 参见: IMOS_MW_PTZ_CMD_IRISCLOSESTOP 等 */
    LONG lPTZCmdPara1;         /**< 参数含义参见各命令说明 */
    LONG lPTZCmdPara2;         /**< 参数含义参见各命令说明 */
    LONG lPTZCmdPara3;         /**< 参数含义参见各命令说明 */
}IMOS_MW_PTZ_COMMAND_S;

/**
 * @struct tagMwPTZAbsZoom
 * @brief 云台绝对变倍信息
 * @attention 无
 */
typedef struct tagMwPTZAbsZoom
{    
    FLOAT fPtzZoomNum;        /**< 云台zoom 倍数，精确至小数点后两位，取值范围1-36 */    
    FLOAT fPtzZoomSpeed;      /**< 云台zoom 速度，取值范围0-1，精度至小数点后两位 */
}IMOS_MW_PTZ_ABSZOOM_S;

/**
 * @struct tagMwPTZAbsPosition
 * @brief 云台绝对位置
 * @attention 无
 */
typedef struct tagMwPTZAbsPosition
{
    FLOAT fLatitude;              /**< 云台纬度, 范围: -18~90度, 精度至小数点后两位 */    
    FLOAT fLongitude;             /**< 云台经度, 范围: 0~360度, 精度至小数点后两位 */
    FLOAT fMoveSpeed;             /**< 转动角速度，取值范围0-9级(与现有界面上统一)，0为使用默认速度 */  
}IMOS_MW_PTZ_ABSPOSITION_S;

/**
 * @struct tagMwPTZZoomArea
 * @brief 拉框区域信息
 * @attention 建议坐标系：播放窗格左上角为起点的像素点坐标系
 */
typedef struct tagMwPTZZoomArea
{
    USHORT usMidPointX;         /**< 拉框中心点横坐标 */
    USHORT usMidPointY;         /**< 拉框中心点纵坐标 */             
    USHORT usLengthX;           /**< 拉框长度 */
    USHORT usLengthY;           /**< 拉框宽度 */              
    USHORT usWidth;             /**< 播放窗格长度 */      
    USHORT usHeight;            /**< 播放窗格宽度 */                     
}IMOS_MW_PTZ_ZOOMAREA_S;

/**
 * @struct tagMwPTZControledZoom
 * @brief 云台受控变倍信息
 * @attention 无
 */
typedef struct tagMwPTZControledZoom
{    
    FLOAT fPtzZoomNum;        /**< 云台zoom 倍数，精确至小数点后两位，取值范围1-36 */    
    FLOAT fSpeed;             /**< 变倍速度 */  
}IMOS_MW_PTZ_CONTROLEDZOOM_S;

/**
 * @struct tagMwPTZControledPosition
 * @brief 云台受控位置
 * @attention 无
 */
typedef struct tagMwPTZControledPosition
{
    FLOAT fLatitude;              /**< 云台纬度, 范围: -18-90度, 精度至小数点后两位 */    
    FLOAT fLongitude;             /**< 云台经度, 范围: 0-360度, 精度至小数点后两位 */
    FLOAT fPanSpeed;              /**< 云台转动水平角速度,单位度每秒，范围: 0-400，精度至小数点后两位 */ 
    FLOAT fTiltSpeed;             /**< 云台转动垂直角速度,单位度每秒，范围: 0-400，精度至小数点后两位 */ 
}IMOS_MW_PTZ_CONTROLEDPOSITION_S;
#if 0
#endif
/******************************* 存储(本地)相关结构 ***********************************/
/**
* @struct tagMwLocalPicStor
* @brief 本地SD卡抓拍存储配置信息
* @attention 
*/
typedef struct tagMwLocalPicStor
{   
    ULONG ulAllocPercent;                       /**< 分配容量百分比，单位 %，默认0, 界面暂不使用，界面不显示 */ 
    ULONG ulAllocMemory;                        /**< 分配容量, 单位: MB */
    ULONG ulSpareMemory;                        /**< 剩余容量, 单位: MB */             
    ULONG ulCurrentFileNum;                     /**< 当前文件个数 */                  
    ULONG ulSpareFileNum;                       /**< 剩余可存文件个数 */    
    ULONG ulStorPolicy;                         /**< 存储策略 参见: IMOS_MW_STOR_POLICY_XXX */
    ULONG ulStorMode;                           /**< SD卡存储模式 参见: IMOS_MW_LOCAL_STOR_XXX */
}IMOS_MW_LOCAL_PIC_STORCFG_S;

/**
* @struct tagMwLocalVideoStor
* @brief 本地SD卡视频存储配置信息
* @attention 
*/
typedef struct tagMwLocalVideoStor
{   
    ULONG ulAllocPercent;                       /**< 分配容量百分比，单位 %，默认0, 界面暂不使用，界面不显示 */ 
    ULONG ulAllocMemory;                        /**< 分配容量, 单位: MB */
    ULONG ulPlanStreamID;                       /**< 计划流 流ID */
    ULONG ulManualStreamID;                     /**< 手动流 流ID */
    ULONG ulEventStreamID;                      /**< 事件流 流ID */
    ULONG ulStorPolicy;                         /**< 存储策略 参见: IMOS_MW_STOR_POLICY_XXX */
    ULONG ulStorMode;                           /**< SD卡存储模式 参见: IMOS_MW_LOCAL_STOR_XXX */
}IMOS_MW_LOCAL_VIDEO_STORCFG_S;

/**
* @struct tagMwLocalStorInfo
* @brief 本地SD 卡存储
* @attention 
*/
typedef struct tagMwLocalStorInfo
{       
    ULONG ulTotalMemory;                             /**< 本地存储总容量（SD卡容量）, 单位: MB */
    IMOS_MW_LOCAL_PIC_STORCFG_S stPicStorCfg;        /**< SD卡抓拍图片存储配置 */  
    IMOS_MW_LOCAL_VIDEO_STORCFG_S stVideoStorCfg;    /**< SD卡视频存储配置 */  
}IMOS_MW_LOCAL_STOR_INFO_S;

/**
* @struct tagMwLocalStorPicInfo
* @brief SD 卡文件信息
* @attention 
*/
typedef struct tagMwStorLocalPicInfo
{
     CHAR stFile[IMOS_MW_NAME_LEN];          /**< 文件ID, 单个文件ID 长度不超过 IMOS_MW_FILE_NAME_LEN */
     IMOS_MW_TIME_S stTime;                  /**< 时间(年月日时分秒) */
     CHAR szPictureInfo[IMOS_MW_NAME_LEN];   /**< 车牌号(卡口) */
}IMOS_MW_STOR_LOCAL_PIC_INFO_S;

/**
* @struct tagMwStorLocalVideo
* @brief 本地SD 卡 录像文件
* @attention 无
*/
typedef struct tagMwStorLocalVideo
{
    CHAR szFile[IMOS_MW_FILE_NAME_LEN];      /**< 录像文件ID */ 
    ULONG ulFileSize;                        /**< 录像文件大小 */ 
    IMOS_MW_TIME_S stSartTime;               /**< 录像文件开始时间 */ 
    IMOS_MW_TIME_S stEndTime;                /**< 录像文件结束时间 */ 
}IMOS_MW_STOR_LOCAL_VIDEO_S;

/**
* @struct tagMwStorPathInfo
* @brief 存储路径
* @attention 无
*/
typedef struct tagMwStorPathInfo
{
    CHAR szName[IMOS_MW_DEFAULT_PATH_LEN];       /**< 目录/文件 的名称 */
    ULONG ulDirType;                             /**< 路径属性: 目录/文件, 参见: IMOS_MW_STOR_PATH_DIR 等 */
    ULONG ulStorFileType;                        /**< 文件类型: 照片/录像, 参见: IMOS_MW_STOR_FILE_TYPE_VIDEO 等 */
}IMOS_MW_STOR_PATH_INFO_S;

#if 0
#endif
/******************************* 播放器相关结构 ***********************************/
/**
* @struct tagMwDisplayParam
* @brief 视频显示参数
* @attention
*/
typedef struct tagMwDisplayParam
{
    ULONG ulRenderMode;         /**< 视频显示模式, 参见: IMOS_MW_RENDER_MODE_D3D 等 */
    ULONG ulPixelFormat;        /**< 视频像素格式, 参见: IMOS_MW_PIXEL_FORMAT_YUV420 等 */
}IMOS_MW_DISPLAY_PARAM_S;  

/**
* @enum tagMwVideoAdjust
* @brief 影像调节参数
* @attention
*/
typedef struct tagMwVideoAdjust
{
    LONG lContrast;         /**< 对比度 */
    LONG lLuminance;        /**< 亮度 */
    LONG lHue;              /**< 色调 */
    LONG lSaturation;       /**< 饱和度 */
    LONG lGamma;            /**< 伽玛 */
}IMOS_MW_VIDEO_ADJUST_S;

/**
* @struct tagMwPictureData
* @brief 存放解码后图像数据的指针和长度等信息的结构体定义
* @attention 无
*/
typedef struct tagMwPictureData
{
    UCHAR *pucData[4];                          /**< pucData[0]:Y 平面指针,pucData[1]:U 平面指针,pucData[2]:V 平面指针 */
    ULONG ulLineSize[4];                        /**< ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距 */
    ULONG ulPicHeight;                          /**< 图片高度 */
    ULONG ulPicWidth;                           /**< 图片宽度 */
    ULONG ulRenderTimeType;                     /**< 用于渲染的时间数据类型，参见: IMOS_MW_RENDER_TYPE_FRAME_RATE 等 */
    DLONG dlRenderTime;                         /**< 用于渲染的时间数据 */
}IMOS_MW_PICTURE_DATA_S;

/**
* @struct tagMwWaveData
* @brief 存放解码后音频数据的指针和长度等信息的结构体定义
* @attention 
*/
typedef struct tagMwWaveData
{
    CHAR *pcData;                               /**< 音频数据指针 */
    ULONG ulDataLen;                            /**< 音频数据长度 */
    ULONG ulWaveFormat;                         /**< 解码后音频格式, 参见: IMOS_MW_WAVE_FORMAT_PCM8M16 等 */
}IMOS_MW_WAVE_DATA_S;

/**
* @struct tagMwParseVideoData
* @brief 存放拼帧后视频数据的指针和长度等信息的结构体定义
* @attention 
*/
typedef struct tagMwParseVideoData
{   
    UCHAR *pucData;                      /**< 视频数据指针 */
    ULONG ulDataLen;                     /**< 视频数据长度 */
    ULONG ulVideoFrameType;              /**< 视频帧类型，参见: IMOS_MW_VIDEO_FRAME_TYPE_I 等 */  
    ULONG ulVideoCodeFormat;             /**< 视频编码格式, 参见: IMOS_MW_STREAM_FORMAT_MPEG1 等 */
    ULONG ulHeight;                      /**< 视频图像高度 */
    ULONG ulWidth;                       /**< 视频图像宽度 */
    DLONG dlTimeStamp;                   /**< 时间戳（毫秒）*/
    UCHAR *pcExtraInfo;                  /**< 视频数据额外信息  */
    ULONG ulInfoLen;                     /**< 视频数据额外信息长度  */
    ULONG ulReserved1;                   /**< 保留参数 */
    ULONG ulReserved2;                   /**< 保留参数 */
}IMOS_MW_PARSE_VIDEO_DATA_S;

/**
* @struct tagMwParseAudioData
* @brief 存放拼帧后音频数据的指针和长度等信息的结构体定义
* @attention 
*/
typedef struct tagMwParseAudioData
{
    UCHAR *pucData;                 /**< 音频数据指针 */
    ULONG ulDataLen;                /**< 音频数据长度 */
    ULONG ulAudioCodeFormat;        /**< 音频编码格式, 参见: IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2 等 */     
    ULONG ulWaveFormat;             /**< 音频数据解码后音频格式, 参见: IMOS_MW_WAVE_FORMAT_PCM8M16 等 */
    DLONG dlTimeStamp;              /**< 时间戳（毫秒）*/
    ULONG ulReserved1;              /**< 保留参数 */
    ULONG ulReserved2;              /**< 保留参数 */
}IMOS_MW_PARSE_AUDIO_DATA_S;

/**
* @struct tagMwSourceDataExInfo
* @brief 拼帧前媒体流扩展信息的结构体定义
* @attention 无
*/
typedef struct tagMwSourceDataExInfo
{
    CHAR szDecoderTag[IMOS_MW_CODE_LEN];           /**< 解码器标签*/ 
    CHAR szReserved[64];                           /**< 保留参数*/
}IMOS_MW_SOURCE_DATA_EX_INFO_S;

/**
* @struct tagMwVideoParam
* @brief 视频解码参数
* @attention 无
*/
typedef struct tagMwVideoParam
{
    ULONG ulFrameRate;       /**< 帧率, 单位: fps */
    ULONG ulBitRate;         /**< 码率, 单位: bps */
    ULONG ulRecvPktNum;      /**< 已接收到包数 */
    ULONG ulLostPktNum;      /**< 丢弃包数 */
    ULONG ulAllFrameNum;     /**< 帧总数 */
    ULONG ulLostFrameNum;    /**< 丢弃的帧数 */
}IMOS_MW_VIDEO_PARAM_S;

/**
* @struct tagMwAudioEncParam
* @brief 音频编码参数
* @attention 无
*/
typedef struct tagMwAudioEncParam
{
    ULONG ulAudioEncType;             /**< 编码格式, 参见: IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2 等 */
    ULONG ulSampleRate;               /**< 采样率, 参见: IMOS_MW_AUDIO_SAMPLING_8000 等 */
    ULONG ulChannels;                 /**< 声道数 */
    ULONG ulQuantizationBits;         /**< 量化位数 */ 
}IMOS_MW_AUDIO_ENCODE_PARAM_S;

#if 0
#endif

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_PUB_H__*/

