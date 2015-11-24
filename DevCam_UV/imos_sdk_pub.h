/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_pub.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created:
        Author:  
   Description: ���ļ�������sdk��ص�ö�١��ṹ��

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
 * @brief ������
 * @attention ��
 */
typedef struct tagMwPoint
{
    ULONG ulX;        /**< ������ */
    ULONG ulY;        /**< ������ */
}IMOS_MW_POINT_S;

/**
 * @struct tagMwPoint
 * @brief ������ṹ
 * @attention ��
 */
typedef struct tagMwLine
{
    IMOS_MW_POINT_S stHead;       /**< ͷ���� */
    IMOS_MW_POINT_S stTail;       /**< β���� */
}IMOS_MW_LINE_S;

/**
 * @struct tagMwRectangle
 * @brief ���ο�����ṹ
 * @attention ��
 */
typedef struct tagMwRectangle
{
    IMOS_MW_POINT_S stTopLeft;       /**< ���Ͻ����� */
    IMOS_MW_POINT_S stBotRight;      /**< ���½����� */
}IMOS_MW_RECTANGLE_S;

/**
 * @struct tagMwQuadrangle
 * @brief �ķ��ο�����ṹ
 * @attention ��
 */
typedef struct tagMwQuadrangle
{
    IMOS_MW_POINT_S stTopLeft;       /**< ���Ͻ����� */
    IMOS_MW_POINT_S stTopRight;      /**< ���Ͻ����� */
    IMOS_MW_POINT_S stBotLeft;       /**< ���½����� */
    IMOS_MW_POINT_S stBotRight;      /**< ���½����� */
}IMOS_MW_QUADRANGLE_S;

/**
* @struct tagMwAddr
* @brief ��ַ�ṹ
* @attention 
*/
typedef struct tagMwAddr
{
    CHAR szIPAddr[IMOS_MW_IPADDR_LEN];       /**< IP��ַ */
    USHORT usPort;                           /**< �˿� */
    USHORT usReserve;                        /**< ���� */
}IMOS_MW_ADDR_S;

#if 0
#endif

#if 0
#endif 
/******************************* ϵͳ���豸ά����ؽṹ ***********************************/
/**
 * @struct tagMwPlayerStatus
 * @brief ������״̬
 * @attention ��
 */ 
typedef struct tagMwPlayerStatus
{
    ULONG ulStreamHandle;           /**< ����� */
    ULONG ulErrCode;                /**< ������ */
}IMOS_MW_PLAYER_STATUS_S;


/**
 * @struct tagMwTime
 * @brief ʱ����Ϣ
 * @attention 
 */
typedef struct tagMwTime
{
    USHORT usYear;           /**< �꣬��ǰ��������2009��ʱ����ֵΪ2009�� */
    USHORT usMonth;          /**< �£���ǰ�·ݣ�1��12�� */
    USHORT usMonthDay;       /**< �գ�ÿ�µļ��ţ�1��31�� */
    USHORT usHour;           /**< ʱ����ǰСʱ����0��23�� */
    USHORT usMinute;         /**< �֣���ǰ��������0��59�� */
    USHORT usSecond;         /**< �룬��ǰ������0��60�� */
    USHORT usWeekday;        /**< �ܼ���ÿ�ܵ����ڼ���0��6����0 ��Ӧ���գ�1-6 ��Ӧ��һ �� ���� �� ��δʹ�� */
    USHORT usReserve;        /**< ���� */
}IMOS_MW_TIME_S;

/**
 * @struct tagMwSystemTimeInfo
 * @brief ϵͳ(����)ʱ��
 * @attention  lTimeZoneΪ ����ʱ������ʱ���Ĳ���� ����ʱ��UTC+8,����д 8
 */
typedef struct tagMwSystemTimeInfo
{
    LONG lTimeZone;                   /**< ����ϵͳʱ��, -12��12����Ӧ�ͱ�׼ʱ���ƫ�� */
    IMOS_MW_TIME_S stLocalTime;       /**< ����ʱ�� */
}IMOS_MW_SYSTEM_TIME_INFO_S;

#if 1
/* ������ɾ����ɾ���ýṹ */
/**
* @struct tagMwSnmpTrapServer
* @brief  SNMP����������TRP��������ַ
* @attention ������������ʱ������Ҫͨ����
*/
typedef struct tagMwSnmpTrapServerInfo
{
    CHAR szROCommunity[IMOS_MW_COMMUNITY_LEN + 4];      /**< ֻ��SNMP������ */
    CHAR szRWCommunity[IMOS_MW_COMMUNITY_LEN + 4];      /**< ��дSNMP������ */
    CHAR szTrapCommunity[IMOS_MW_COMMUNITY_LEN + 4];    /**< trap�ϱ������� */
    CHAR szTrapAddress[IMOS_MW_IPADDR_LEN];             /**< Trap��������ַ */
    USHORT usSNMPTrapPort;                              /**< TRAP�˿ں� */
    USHORT usResv;                                      /**< ���� */
}IMOS_MW_SNMPTRAP_SERVER_INFO_S;
#endif

/**
 * @struct tagMwUserInfo
 * @brief �û���Ϣ
 * @attention ɾ���û���Ϣʱ��ֻ�贫���û�������
 */
typedef struct tagMwUserInfo
{
    CHAR szUserName[IMOS_MW_USER_NAME_LEN + 4];           /**< �û��� */
    CHAR szPassword[IMOS_MW_USER_PASSWORD_LEN + 4];       /**< �û����� */
    ULONG ulLevel;                                        /**< �û�����, �μ�: IMOS_MW_USERLEVEL_ADMINISTRATOR �� */
}IMOS_MW_USER_INFO_S;

#if 0
#endif
/******************************* ������Ϣ ***********************************/
/**
 * @struct tagMwPPPoE
 * @brief PPPoE����
 * @attention ��
 */
typedef struct tagMwPPPoE
{
    CHAR szUserName[IMOS_MW_PPPOE_USERNAME_LEN + 4];     /**< PPPoE�˺� */
    CHAR szPassword[IMOS_MW_PPPOE_PASSWORD_LEN + 4];     /**< PPPoE���� */
}IMOS_MW_PPPOE_S;

/**
 * @struct tagMwNetworkInterfaceCfg
 * @brief ������Ϣ
 * @attention 
 */
typedef struct tagMwNetworkInterfaceCfg
{
    ULONG ulIPGetType;                          /**< IP��ȡ��ʽ, �μ�: IMOS_MW_IP_GET_TYPE_STATIC �� */ 
    IMOS_MW_PPPOE_S stPPPoE;                    /**< PPPoE���� */
    ULONG ulMTULen;                             /**< MTU����, IP��ȡ��ʽΪPPPoEʱ�ò�����Ч */
    CHAR szIpAddress[IMOS_MW_IPADDR_LEN];       /**< IP��ַ */
    CHAR szIpNetmask[IMOS_MW_IPADDR_LEN];       /**< �������� */
    CHAR szIpGateway[IMOS_MW_IPADDR_LEN];       /**< ���� */
    ULONG ulWorkMode;                           /**< ���ڹ���ģʽ, �μ�: IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION �� */
}IMOS_MW_NETWORK_INTERFACE_CFG_S;

#if 0
#endif
/*************************** ͼ����ؽṹ ****************************************/
/**
 * @struct tagMwWDR
 * @brief ��̬���� 
 * @attention 
 */
typedef struct tagMwWDR
{
    ULONG ulMode;              /**< ��̬ģʽ, �μ�: IMOS_MW_WDR_DISABLE �� */
    ULONG ulExpRatio;          /**< �ع���ʣ��ݲ�֧�� */
}IMOS_MW_WDR_S;

/**
 * @struct tagMwMetering
 * @brief ������ 
 * @attention
 */
typedef struct tagMwMetering
{
    ULONG ulMode;                  /**< ���ģʽ, �μ�: IMOS_MW_METERING_CENTER �� */
    IMOS_MW_RECTANGLE_S stArea;    /**< ������� */
}IMOS_MW_METERING_S;

/**
 * @struct tagMwDayNight
 * @brief ��ҹģʽ���� 
 * @attention
 */
typedef struct tagMwDayNight
{
    ULONG ulMode;              /**< ��ҹģʽ, �μ�: IMOS_MW_DAYNIGHT_AUTO �� */
    ULONG ulSensitivity;       /**< �л������� */
}IMOS_MW_DAYNIGHT_S;

/**
 * @struct tagMwSharpness
 * @brief ��Ȳ��� 
 * @attention
 */
typedef struct tagMwSharpness
{
    ULONG ulMode;              /**< ���ģʽ, �μ�: IMOS_MW_SHARPNESS_AUTO �� */
    ULONG ulSharpness;         /**< ���ֵ */
}IMOS_MW_SHARPNESS_S;

/**
 * @struct tagMwDenoise
 * @brief ͼ���� 
 * @attention ��
 */
typedef struct tagMwDenoise
{
    ULONG ul2DLevel;           /**< 2D����ȼ� */
    ULONG ul3DLevel;           /**< 3D����ȼ� */
}IMOS_MW_DENOISE_S;

/**
 * @struct tagMwCustomExposure
 * @brief �Զ����ع����
 * @attention ��
 */
typedef struct tagMwCustomExposure
{
    ULONG ulMaxIris;                        /**< ����Ȧ, ��λ: fֵ*100 */
    ULONG ulMinIris;                        /**< ��С��Ȧ, ��λ: fֵ*100 */
    ULONG ulSlowShutter;                    /**< �������� */               
    ULONG ulFastShutter;                    /**< ������ */       
    ULONG ulMaxGain;                        /**< �������, ��λ: db */
    ULONG ulMinGain;                        /**< ��С����, ��λ: db */
}IMOS_MW_CUSTOM_EXPOSURE_S;

/**
 * @struct tagMwSlowShutter
 * @brief ������
 * @attention ��
 */
typedef struct tagMwSlowShutter
{
    BOOL_T bEnable;                         /**< ������ʹ���� */
    ULONG ulMaxSlowShutter;                 /**< ���������� */
}IMOS_MW_SLOW_SHUTTER_S;

/**
 * @struct tagMwExposure
 * @brief �ع���� 
 * @attention 
 */
typedef struct tagMwExposure
{
    ULONG ulMode;                                /**< �ع�ģʽ, �μ�: IMOS_MW_EXPOSURE_AUTO �� */
    LONG lExpCompensate;                         /**< �عⲹ�� */
    ULONG ulIris;                                /**< ��Ȧֵ, ��λ: fֵ*100 */
    ULONG ulShutter;                             /**< ����ֵ */
    ULONG ulGain;                                /**< ����, ��λ: db */
    IMOS_MW_CUSTOM_EXPOSURE_S stCustomExposure;  /**< �Զ����ع���� */
    IMOS_MW_SLOW_SHUTTER_S stSlowShutter;        /**< �����Ų��� */
    IMOS_MW_WDR_S stWDR;                         /**< ��̬���� */
    IMOS_MW_METERING_S stMetering;               /**< ������ */
    IMOS_MW_DAYNIGHT_S stDayNight;               /**< ��ҹ���� */
}IMOS_MW_EXPOSURE_S;

/**
 * @struct tagMwWhiteBalance
 * @brief ��ƽ����� 
 * @attention
 */
typedef struct tagMwWhiteBalance
{
    ULONG ulMode;                           /**< ��ƽ��ģʽ, �μ�: IMOS_MW_WB_AUTO �� */
    LONG lBlueOffset;                       /**< ��ɫƫ���� */
    LONG lRedOffset;                        /**< ��ɫƫ���� */
}IMOS_MW_WHITE_BALANCE_S;

/**
 * @struct tagMwImageEnhance
 * @brief ͼ����ǿ���� 
 * @attention 
 */
typedef struct tagMwImageEnhance
{
    ULONG ulBrightness;                     /**< ���� */
    ULONG ulContrast;                       /**< �Աȶ� */
    ULONG ulSaturation;                     /**< ���Ͷ� */
    ULONG ulHue;                            /**< ɫ�� */
    IMOS_MW_SHARPNESS_S stSharpness;        /**< ��Ȳ��� */
    IMOS_MW_DENOISE_S stDenoise;            /**< ������� */
    ULONG ulMirrorMode;                     /**< ����ģʽ, �μ�: IMOS_MW_MIRROR_MODE_NONE �� */
}IMOS_MW_IMAGE_ENHANCE_S;

/**
 * @struct tagMwFocus
 * @brief �Խ����� 
 * @attention 
 */
typedef struct tagMwFocus
{
    ULONG ulFocusMode;                       /**< �Խ�ģʽ, �μ�: IMOS_MW_FOCUS_AUTO �� */
    ULONG ulAutoFocusSense;                  /**< �Զ��Խ������� */
    ULONG ulManualFocusMinDistance;          /**< ��С�Խ����룬�ֶ��Խ�, ��λ: ���� */
}IMOS_MW_FOCUS_S;

/**
 * @struct tagMwExposureCfg
 * @brief �ع��������
 * @attention  
 */
typedef struct tagMwExposureCfg
{
    ULONG ulImageType;                    /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_EXPOSURE_S stExposure;        /**< �ع���� */
}IMOS_MW_EXPOSURE_CFG_S;

/**
 * @struct tagMwWhiteBalanceCfg
 * @brief ��ƽ���������
 * @attention 
 */
typedef struct tagMwWhiteBalanceCfg
{
    ULONG ulImageType;                         /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_WHITE_BALANCE_S stWhiteBalance;    /**< ��ƽ����� */
}IMOS_MW_WHITE_BALANCE_CFG_S;

/**
 * @struct tagMwImageEnhanceCfg
 * @brief ͼ����ǿ��������
 * @attention 
 */
typedef struct tagMwImageEnhanceCfg
{
    ULONG ulImageType;                         /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_IMAGE_ENHANCE_S stImageEnhance;    /**< ͼ����ǿ���� */
}IMOS_MW_IMAGE_ENHANCE_CFG_S;

/**
 * @struct tagMwImageEnhanceCfg
 * @brief �Խ���������
 * @attention 
 */
typedef struct tagMwFocusCfg
{
    ULONG ulImageType;                         /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_FOCUS_S stFocus;                   /**< �Խ����� */
}IMOS_MW_FOCUS_CFG_S;

/**
 * @struct tagMwConditionCfgEx
 * @brief ���� ��������
 * @attention
 */
typedef struct tagMwConditionCfgEx
{
    ULONG ulType;              /**< �����������ͣ��μ�: IMOS_MW_CONDITION_ILLUMINATION �� */
    LONG lParam1;              /**< ��������1 */
    LONG lParam2;              /**< ��������2 */
    LONG lParam3;              /**< ��������3 */
}IMOS_MW_CONDITION_CFG_EX_S;

#if 0
#endif
/*************************** OSD ��ؽṹ ****************************************/
/**
 * @struct tagMwOSDInfoParam
 * @brief OSD ��������
 * @attention ��
 */
typedef struct tagMwOSDInfoParam
{
    ULONG ulInfoType;                              /**< �����������ͣ��ο�: IMOS_MW_OSD_INFO_TYPE_UNUSED �� */
    CHAR szValue[IMOS_MW_OSD_INFO_LEN + 4];        /**< �Զ��� OSD ���� */ 
}IMOS_MW_OSD_INFO_PARAM_S;

/**
* @struct tagMwOSDInfoConf
* @brief ����OSD ����
* @attention ��
*/
typedef struct tagMwOSDInfoConf
{
    ULONG ulIndex;                                                       /**< ��������ID */
    BOOL_T bEnable;                                                      /**< ʹ�ܿ��� */ 
    IMOS_MW_OSD_INFO_PARAM_S astInfoParam[IMOS_MW_INFO_OSD_LINE_MAX];    /**< �������� */  
    IMOS_MW_RECTANGLE_S stArea;                                          /**< �������� */
}IMOS_MW_INFO_OSD_S;

/**
* @struct tagMwInfoOSDCfg
* @brief ����OSD ����
* @attention ɾ��������ʱ��ֻ��ָ����ɾ�������ID
*/
typedef struct tagMwInfoOSDCfg
{
    ULONG ulAreaNum;                        /**< ����������� */
    IMOS_MW_INFO_OSD_S astInfoOSD[1];       /**< ����OSD ���ã�����������Ϊ: IMOS_MW_INFO_OSD_MAX_NUM */
}IMOS_MW_INFO_OSD_CFG_S;

/**
* @struct tagMwOSDStyleCfg
* @brief ����OSD ��ʽ
* @attention ��
*/
typedef struct tagMwOSDStyleCfg
{
    ULONG ulFontStyle;     /**< ������ʽ, �μ�: IMOS_MW_OSD_FONT_STYLE_NORMAL �� */
    ULONG ulFontSize;      /**< �����С, �μ�: IMOS_MW_OSD_FONT_SIZE_LARGE �� */
    ULONG ulFontType;      /**< ����, �ݲ�֧������ */
    ULONG ulColor;         /**< ��ɫ, �μ�: IMOS_MW_OSD_COLOR_WHITE �� */
    ULONG ulAlpha;         /**< ͸����, �μ�: IMOS_MW_OSD_ALPHA_NO �� */
    ULONG ulTimeFormat;    /**< ʱ���ʽ, �μ�: IMOS_MW_TIME_FORMAT_HHMMSS �� */
    ULONG ulDateFormat;    /**< ���ڸ�ʽ, �μ�: IMOS_MW_DATE_FORMAT_YYYYMMDD �� */
}IMOS_MW_OSD_STYLE_CFG_S;

#if 0
#endif
/******************************* ý������ؽṹ ***********************************/
/**
 * @struct tagMwResolution
 * @brief �ֱ���
 * @attention 
 */
typedef struct tagMwResolution
{
    ULONG ulWidth;           /**< ����λ: ���� */
    ULONG ulHeight;          /**< �ߣ���λ: ���� */
}IMOS_MW_RESOLUTION_S;

/**
 * @struct tagMwVideoInModeCfg
 * @brief �ɼ���ʽ
 * @attention 
 */
typedef struct tagMwVideoInModeCfg
{
    IMOS_MW_RESOLUTION_S stResolution;    /**< �ɼ��ֱ��� */ 
    ULONG ulFrameRate;                    /**< �ɼ�֡�� */
}IMOS_MW_VIDEOIN_MODE_CFG_S;

/**
 * @struct tagMwVideoStreamConf
 * @brief ��Ƶ�������
 * @attention 
 */
typedef struct tagMwVideoStreamConf
{
    BOOL_T bIsEnable;                              /**< ����/�رձ��� 0-�ر� 1-���� */
    ULONG ulEncodeFmt;                             /**< �����ʽ���μ�: IMOS_MW_STREAM_FORMAT_MPEG1 �� */
    IMOS_MW_RESOLUTION_S stResolution;             /**< ����ֱ��� */ 
    ULONG ulBitRate;                               /**< ���� */
    ULONG ulFrameRate;                             /**< ֡�� */ 
    ULONG ulGopType;                               /**< gop�ṹ����, �ο�: IMOS_MW_GOP_TYPE_IP �� */  
    ULONG ulIInterval;                             /**< I֡��� */
    ULONG ulEncMode;                               /**< ����ģʽ���μ�: IMOS_MW_ENCODE_MODE_CBR �� */ 
    ULONG ulQuality;                               /**< ����ѹ������ */
    ULONG ulSmoothValue;                           /**< ����ƽ�� */                            
}IMOS_MW_VIDEO_STREAM_CONF_S;

/**
 * @struct tagMwVideoEncoderCfg
 * @brief ��Ƶ�����������
 * @attention ��ȡָ�����ı������ʱ����Ҫ������ID
 */
typedef struct tagMwVideoEncoderCfg
{
    ULONG ulStreamID;                              /**< ��ID, �μ�: IMOS_MW_STREAM_ID_MAIN �� */
    IMOS_MW_VIDEO_STREAM_CONF_S stVideoStreamCfg;  /**< ��Ƶ������� */
}IMOS_MW_VIDEO_ENCODER_CFG_S;

/** 
 * @struct tagMwAudioInCfg
 * @brief ��Ƶ�������
 * @attention 
 */
typedef struct tagMwAudioInCfg
{
    ULONG ulEncFormat;           /**< ��Ƶ��ʽ���μ�: IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2 �� */
    ULONG ulSampling;            /**< ������, �μ�: IMOS_MW_AUDIO_SAMPLING_8000 �� */
    ULONG ulBitRate;             /**< ��Ƶ���� */
    BOOL_T bMute;                /**< �������� */
    ULONG ulInputPlus;           /**< ��������(0-255) Ĭ��0 */
}IMOS_MW_AUDIO_IN_CFG_S;

/** 
 * @struct tagMwAudioOutCfg
 * @brief ��Ƶ�������
 * @attention ������������ʱ������Ҫͨ����
 */
typedef struct tagMwAudioOutCfg
{
    BOOL_T bSilence;          /**< �������� */
    ULONG ulAudioOutPlus;     /**< ������� */
}IMOS_MW_AUDIO_OUT_CFG_S;

/**
 * @enum tagMwMediaStreamInfo
 * @brief ý������Ϣ
 * @attention ��
 */
typedef struct tagMwMediaStreamInfo
{
    ULONG ulStreamHandle;                         /**< ����� */
    ULONG ulStreamID;                             /**< ��ID, �μ�: IMOS_MW_STREAM_ID_MAIN �� */
    ULONG ulTransMode;                            /**< ����ģʽ���μ�: IMOS_MW_TRANSFER_MODE_RTP_UDP �� */
    CHAR szIPAddr[IMOS_MW_IPADDR_LEN];            /**< ��Ŀ��IP��ַ */
    USHORT usPort;                                /**< ��Ŀ�Ķ˿� */
    USHORT usReserved;                            /**< ���� */
    ULONG ulMediaType;                            /**< ý������, �μ�: IMOS_MW_MEDIA_VIDEO �� */
    CHAR szUser[IMOS_MW_NAME_LEN];                /**< �������� */
}IMOS_MW_VIDEO_STREAM_INFO_S;

#if 0
#endif
/******************************* �澯������ؽṹ ***********************************/
/**
 * @struct tagMwEventTrap
 * @brief �澯�ϱ��ṹ��
 * @attention  
 */
typedef struct tagMwEventTrap
{
    ULONG ulAlarmCmd;                           /**< �澯������, �μ�: IMOS_MW_ALARM_SYSTEM_HIGH_TEMPERATURE �� */  
    LONG lTimeStamp;                            /**< �澯ʱ�� */  
    ULONG ulChannelID;                          /**< ͨ��ID */  
    ULONG ulSubChannelID;                       /**< ��ͨ��ID */  
    CHAR szIpAddress[IMOS_MW_IPADDR_LEN];       /**< IP��ַ, ֻ����ʶ, ������ */
    CHAR szDeviceID[IMOS_MW_CODE_LEN];          /**< �豸ID, ��MAC��ַ������ʶ��澯�����ĸ��豸*/          
}IMOS_MW_EVENT_TRAP_S;

#if 0
#endif
/******************************* ��̨Ѳ����ؽṹ ***********************************/
/**
 * @struct tagMwPTZPresetParam
 * @brief Ԥ��λ������Ϣ
 * @attention 
 */
typedef struct tagMwPTZPresetParam
{
    ULONG ulPresetID;                                     /**<  Ԥ��λID����Χ��1--255�� */
    CHAR szPresetName[IMOS_MW_PTZ_PRESET_NAME + 4];       /**<  Ԥ��λ���� */
}IMOS_MW_PRESET_PARAM_S;

/**
 * @struct tagMwPTZPresetCfg
 * @brief Ԥ��λ�б�
 * @attention
 */
typedef struct tagMwPTZPresetCfg
{
    ULONG ulPresetNum;                                  /**< Ԥ��λ���� */
    IMOS_MW_PRESET_PARAM_S astPresetCfg[1];             /**< Ԥ��λ�б� */
}IMOS_MW_PRESET_CFG_S;

/**
 * @struct tagMwPTZGuardPresetCfg
 * @brief ����λ������Ϣ
 * @attention ������������ʱ������Ҫͨ����
 */
typedef struct tagMwPTZGuardPresetCfg
{
    ULONG ulGuardPreset;       /**< ����λ */
    ULONG ulDelaySecond;       /**< �ӳ�ʱ�䵥λ�� */
}IMOS_MW_GUARD_PRESET_CFG_S;

/**
 * @struct tagMwPTZCfg
 * @brief ��̨����������Ϣ
 * @attention ������������ʱ������Ҫͨ����
 */
typedef struct tagMwPTZCfg
{
    CHAR szPtzFactoryName[IMOS_MW_PTZ_NAME_LEN];       /**< ��̨Э������ */
    ULONG ulAddr;                                      /**< ��̨��ַ�� */
    ULONG ulPtzMode;                                   /**< ��̨ģʽ��0 ��ʾ������̨���ȣ�1 ��ʾ������̨���� */
}IMOS_MW_PTZ_CFG_S;

/**
 * @struct tagMwPTZPhyParamCfg
 * @brief ��̨����������Ϣ, ͨ������Ŵ��������
 * @attention ������������ʱ������Ҫͨ����
 */
typedef struct tagMwPTZPhyParamCfg
{
    BOOL_T bEnableAreaZoom;         /**< �Ƿ�ʹ������Ŵ� */
    ULONG ulLevelAngleSpeed;        /**< ˮƽ�����ٶȡ�/S */
    ULONG ulApeakAngleSpeed;        /**< ��ֱ�����ٶȡ�/S */
    ULONG ulLevelSceneAngleView;    /**< ˮƽ��ͷ����ӽǡ�*/
    ULONG ulApeakSceneAngleView;    /**< ��ֱ��ͷ����ӽǡ�*/
    ULONG ulZoomTime;               /**< �佹ʱ��ms */
    ULONG ulZoomMul;                /**< �佹���� */
    USHORT usLevelRunAdjustModulus; /**< ����ת������ϵ��% */
    USHORT usApeakRunAdjustModulus; /**< ����ת������ϵ��% */
    USHORT usZoomAdjustModulus;     /**< �佹����ϵ��% */
    UCHAR ucReserve[2];             /**< Ԥ�� */
}IMOS_MW_PTZ_PHYPARAM_CFG_S;

/**
 * @struct tagMwPTZCommand
 * @brief ��̨����ָ��
 * @attention ��
 */
typedef struct tagMwPTZCommand
{
    ULONG ulPTZCmdID ;         /**< ��̨������������, �μ�: IMOS_MW_PTZ_CMD_IRISCLOSESTOP �� */
    LONG lPTZCmdPara1;         /**< ��������μ�������˵�� */
    LONG lPTZCmdPara2;         /**< ��������μ�������˵�� */
    LONG lPTZCmdPara3;         /**< ��������μ�������˵�� */
}IMOS_MW_PTZ_COMMAND_S;

/**
 * @struct tagMwPTZAbsZoom
 * @brief ��̨���Ա䱶��Ϣ
 * @attention ��
 */
typedef struct tagMwPTZAbsZoom
{    
    FLOAT fPtzZoomNum;        /**< ��̨zoom ��������ȷ��С�������λ��ȡֵ��Χ1-36 */    
    FLOAT fPtzZoomSpeed;      /**< ��̨zoom �ٶȣ�ȡֵ��Χ0-1��������С�������λ */
}IMOS_MW_PTZ_ABSZOOM_S;

/**
 * @struct tagMwPTZAbsPosition
 * @brief ��̨����λ��
 * @attention ��
 */
typedef struct tagMwPTZAbsPosition
{
    FLOAT fLatitude;              /**< ��̨γ��, ��Χ: -18~90��, ������С�������λ */    
    FLOAT fLongitude;             /**< ��̨����, ��Χ: 0~360��, ������С�������λ */
    FLOAT fMoveSpeed;             /**< ת�����ٶȣ�ȡֵ��Χ0-9��(�����н�����ͳһ)��0Ϊʹ��Ĭ���ٶ� */  
}IMOS_MW_PTZ_ABSPOSITION_S;

/**
 * @struct tagMwPTZZoomArea
 * @brief ����������Ϣ
 * @attention ��������ϵ�����Ŵ������Ͻ�Ϊ�������ص�����ϵ
 */
typedef struct tagMwPTZZoomArea
{
    USHORT usMidPointX;         /**< �������ĵ������ */
    USHORT usMidPointY;         /**< �������ĵ������� */             
    USHORT usLengthX;           /**< ���򳤶� */
    USHORT usLengthY;           /**< ������ */              
    USHORT usWidth;             /**< ���Ŵ��񳤶� */      
    USHORT usHeight;            /**< ���Ŵ����� */                     
}IMOS_MW_PTZ_ZOOMAREA_S;

/**
 * @struct tagMwPTZControledZoom
 * @brief ��̨�ܿر䱶��Ϣ
 * @attention ��
 */
typedef struct tagMwPTZControledZoom
{    
    FLOAT fPtzZoomNum;        /**< ��̨zoom ��������ȷ��С�������λ��ȡֵ��Χ1-36 */    
    FLOAT fSpeed;             /**< �䱶�ٶ� */  
}IMOS_MW_PTZ_CONTROLEDZOOM_S;

/**
 * @struct tagMwPTZControledPosition
 * @brief ��̨�ܿ�λ��
 * @attention ��
 */
typedef struct tagMwPTZControledPosition
{
    FLOAT fLatitude;              /**< ��̨γ��, ��Χ: -18-90��, ������С�������λ */    
    FLOAT fLongitude;             /**< ��̨����, ��Χ: 0-360��, ������С�������λ */
    FLOAT fPanSpeed;              /**< ��̨ת��ˮƽ���ٶ�,��λ��ÿ�룬��Χ: 0-400��������С�������λ */ 
    FLOAT fTiltSpeed;             /**< ��̨ת����ֱ���ٶ�,��λ��ÿ�룬��Χ: 0-400��������С�������λ */ 
}IMOS_MW_PTZ_CONTROLEDPOSITION_S;
#if 0
#endif
/******************************* �洢(����)��ؽṹ ***********************************/
/**
* @struct tagMwLocalPicStor
* @brief ����SD��ץ�Ĵ洢������Ϣ
* @attention 
*/
typedef struct tagMwLocalPicStor
{   
    ULONG ulAllocPercent;                       /**< ���������ٷֱȣ���λ %��Ĭ��0, �����ݲ�ʹ�ã����治��ʾ */ 
    ULONG ulAllocMemory;                        /**< ��������, ��λ: MB */
    ULONG ulSpareMemory;                        /**< ʣ������, ��λ: MB */             
    ULONG ulCurrentFileNum;                     /**< ��ǰ�ļ����� */                  
    ULONG ulSpareFileNum;                       /**< ʣ��ɴ��ļ����� */    
    ULONG ulStorPolicy;                         /**< �洢���� �μ�: IMOS_MW_STOR_POLICY_XXX */
    ULONG ulStorMode;                           /**< SD���洢ģʽ �μ�: IMOS_MW_LOCAL_STOR_XXX */
}IMOS_MW_LOCAL_PIC_STORCFG_S;

/**
* @struct tagMwLocalVideoStor
* @brief ����SD����Ƶ�洢������Ϣ
* @attention 
*/
typedef struct tagMwLocalVideoStor
{   
    ULONG ulAllocPercent;                       /**< ���������ٷֱȣ���λ %��Ĭ��0, �����ݲ�ʹ�ã����治��ʾ */ 
    ULONG ulAllocMemory;                        /**< ��������, ��λ: MB */
    ULONG ulPlanStreamID;                       /**< �ƻ��� ��ID */
    ULONG ulManualStreamID;                     /**< �ֶ��� ��ID */
    ULONG ulEventStreamID;                      /**< �¼��� ��ID */
    ULONG ulStorPolicy;                         /**< �洢���� �μ�: IMOS_MW_STOR_POLICY_XXX */
    ULONG ulStorMode;                           /**< SD���洢ģʽ �μ�: IMOS_MW_LOCAL_STOR_XXX */
}IMOS_MW_LOCAL_VIDEO_STORCFG_S;

/**
* @struct tagMwLocalStorInfo
* @brief ����SD ���洢
* @attention 
*/
typedef struct tagMwLocalStorInfo
{       
    ULONG ulTotalMemory;                             /**< ���ش洢��������SD��������, ��λ: MB */
    IMOS_MW_LOCAL_PIC_STORCFG_S stPicStorCfg;        /**< SD��ץ��ͼƬ�洢���� */  
    IMOS_MW_LOCAL_VIDEO_STORCFG_S stVideoStorCfg;    /**< SD����Ƶ�洢���� */  
}IMOS_MW_LOCAL_STOR_INFO_S;

/**
* @struct tagMwLocalStorPicInfo
* @brief SD ���ļ���Ϣ
* @attention 
*/
typedef struct tagMwStorLocalPicInfo
{
     CHAR stFile[IMOS_MW_NAME_LEN];          /**< �ļ�ID, �����ļ�ID ���Ȳ����� IMOS_MW_FILE_NAME_LEN */
     IMOS_MW_TIME_S stTime;                  /**< ʱ��(������ʱ����) */
     CHAR szPictureInfo[IMOS_MW_NAME_LEN];   /**< ���ƺ�(����) */
}IMOS_MW_STOR_LOCAL_PIC_INFO_S;

/**
* @struct tagMwStorLocalVideo
* @brief ����SD �� ¼���ļ�
* @attention ��
*/
typedef struct tagMwStorLocalVideo
{
    CHAR szFile[IMOS_MW_FILE_NAME_LEN];      /**< ¼���ļ�ID */ 
    ULONG ulFileSize;                        /**< ¼���ļ���С */ 
    IMOS_MW_TIME_S stSartTime;               /**< ¼���ļ���ʼʱ�� */ 
    IMOS_MW_TIME_S stEndTime;                /**< ¼���ļ�����ʱ�� */ 
}IMOS_MW_STOR_LOCAL_VIDEO_S;

/**
* @struct tagMwStorPathInfo
* @brief �洢·��
* @attention ��
*/
typedef struct tagMwStorPathInfo
{
    CHAR szName[IMOS_MW_DEFAULT_PATH_LEN];       /**< Ŀ¼/�ļ� ������ */
    ULONG ulDirType;                             /**< ·������: Ŀ¼/�ļ�, �μ�: IMOS_MW_STOR_PATH_DIR �� */
    ULONG ulStorFileType;                        /**< �ļ�����: ��Ƭ/¼��, �μ�: IMOS_MW_STOR_FILE_TYPE_VIDEO �� */
}IMOS_MW_STOR_PATH_INFO_S;

#if 0
#endif
/******************************* ��������ؽṹ ***********************************/
/**
* @struct tagMwDisplayParam
* @brief ��Ƶ��ʾ����
* @attention
*/
typedef struct tagMwDisplayParam
{
    ULONG ulRenderMode;         /**< ��Ƶ��ʾģʽ, �μ�: IMOS_MW_RENDER_MODE_D3D �� */
    ULONG ulPixelFormat;        /**< ��Ƶ���ظ�ʽ, �μ�: IMOS_MW_PIXEL_FORMAT_YUV420 �� */
}IMOS_MW_DISPLAY_PARAM_S;  

/**
* @enum tagMwVideoAdjust
* @brief Ӱ����ڲ���
* @attention
*/
typedef struct tagMwVideoAdjust
{
    LONG lContrast;         /**< �Աȶ� */
    LONG lLuminance;        /**< ���� */
    LONG lHue;              /**< ɫ�� */
    LONG lSaturation;       /**< ���Ͷ� */
    LONG lGamma;            /**< ٤�� */
}IMOS_MW_VIDEO_ADJUST_S;

/**
* @struct tagMwPictureData
* @brief ��Ž����ͼ�����ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagMwPictureData
{
    UCHAR *pucData[4];                          /**< pucData[0]:Y ƽ��ָ��,pucData[1]:U ƽ��ָ��,pucData[2]:V ƽ��ָ�� */
    ULONG ulLineSize[4];                        /**< ulLineSize[0]:Yƽ��ÿ�п��, ulLineSize[1]:Uƽ��ÿ�п��, ulLineSize[2]:Vƽ��ÿ�п�� */
    ULONG ulPicHeight;                          /**< ͼƬ�߶� */
    ULONG ulPicWidth;                           /**< ͼƬ��� */
    ULONG ulRenderTimeType;                     /**< ������Ⱦ��ʱ���������ͣ��μ�: IMOS_MW_RENDER_TYPE_FRAME_RATE �� */
    DLONG dlRenderTime;                         /**< ������Ⱦ��ʱ������ */
}IMOS_MW_PICTURE_DATA_S;

/**
* @struct tagMwWaveData
* @brief ��Ž������Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention 
*/
typedef struct tagMwWaveData
{
    CHAR *pcData;                               /**< ��Ƶ����ָ�� */
    ULONG ulDataLen;                            /**< ��Ƶ���ݳ��� */
    ULONG ulWaveFormat;                         /**< �������Ƶ��ʽ, �μ�: IMOS_MW_WAVE_FORMAT_PCM8M16 �� */
}IMOS_MW_WAVE_DATA_S;

/**
* @struct tagMwParseVideoData
* @brief ���ƴ֡����Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention 
*/
typedef struct tagMwParseVideoData
{   
    UCHAR *pucData;                      /**< ��Ƶ����ָ�� */
    ULONG ulDataLen;                     /**< ��Ƶ���ݳ��� */
    ULONG ulVideoFrameType;              /**< ��Ƶ֡���ͣ��μ�: IMOS_MW_VIDEO_FRAME_TYPE_I �� */  
    ULONG ulVideoCodeFormat;             /**< ��Ƶ�����ʽ, �μ�: IMOS_MW_STREAM_FORMAT_MPEG1 �� */
    ULONG ulHeight;                      /**< ��Ƶͼ��߶� */
    ULONG ulWidth;                       /**< ��Ƶͼ���� */
    DLONG dlTimeStamp;                   /**< ʱ��������룩*/
    UCHAR *pcExtraInfo;                  /**< ��Ƶ���ݶ�����Ϣ  */
    ULONG ulInfoLen;                     /**< ��Ƶ���ݶ�����Ϣ����  */
    ULONG ulReserved1;                   /**< �������� */
    ULONG ulReserved2;                   /**< �������� */
}IMOS_MW_PARSE_VIDEO_DATA_S;

/**
* @struct tagMwParseAudioData
* @brief ���ƴ֡����Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ�Ľṹ�嶨��
* @attention 
*/
typedef struct tagMwParseAudioData
{
    UCHAR *pucData;                 /**< ��Ƶ����ָ�� */
    ULONG ulDataLen;                /**< ��Ƶ���ݳ��� */
    ULONG ulAudioCodeFormat;        /**< ��Ƶ�����ʽ, �μ�: IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2 �� */     
    ULONG ulWaveFormat;             /**< ��Ƶ���ݽ������Ƶ��ʽ, �μ�: IMOS_MW_WAVE_FORMAT_PCM8M16 �� */
    DLONG dlTimeStamp;              /**< ʱ��������룩*/
    ULONG ulReserved1;              /**< �������� */
    ULONG ulReserved2;              /**< �������� */
}IMOS_MW_PARSE_AUDIO_DATA_S;

/**
* @struct tagMwSourceDataExInfo
* @brief ƴ֡ǰý������չ��Ϣ�Ľṹ�嶨��
* @attention ��
*/
typedef struct tagMwSourceDataExInfo
{
    CHAR szDecoderTag[IMOS_MW_CODE_LEN];           /**< ��������ǩ*/ 
    CHAR szReserved[64];                           /**< ��������*/
}IMOS_MW_SOURCE_DATA_EX_INFO_S;

/**
* @struct tagMwVideoParam
* @brief ��Ƶ�������
* @attention ��
*/
typedef struct tagMwVideoParam
{
    ULONG ulFrameRate;       /**< ֡��, ��λ: fps */
    ULONG ulBitRate;         /**< ����, ��λ: bps */
    ULONG ulRecvPktNum;      /**< �ѽ��յ����� */
    ULONG ulLostPktNum;      /**< �������� */
    ULONG ulAllFrameNum;     /**< ֡���� */
    ULONG ulLostFrameNum;    /**< ������֡�� */
}IMOS_MW_VIDEO_PARAM_S;

/**
* @struct tagMwAudioEncParam
* @brief ��Ƶ�������
* @attention ��
*/
typedef struct tagMwAudioEncParam
{
    ULONG ulAudioEncType;             /**< �����ʽ, �μ�: IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2 �� */
    ULONG ulSampleRate;               /**< ������, �μ�: IMOS_MW_AUDIO_SAMPLING_8000 �� */
    ULONG ulChannels;                 /**< ������ */
    ULONG ulQuantizationBits;         /**< ����λ�� */ 
}IMOS_MW_AUDIO_ENCODE_PARAM_S;

#if 0
#endif

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_PUB_H__*/

