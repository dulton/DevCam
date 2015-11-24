/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_def.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 
        Author:  
   Description: ���ļ�������sdk��صĴ����롢��

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
����ѡ��
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

/* ������׼����Լ�� */
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
ͨ���������Ͷ���
*******************************************************************************/
/** @brief 8λ�з������� */
#ifndef CHAR
typedef char CHAR;
#endif

/** @brief 8λ�޷������� */
#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

/** @brief 16λ�з������� */
#ifndef SHORT
typedef short SHORT;
#endif

/** @brief 16λ�޷������� */
typedef unsigned short USHORT;

/** @brief 32λ�з������� */
typedef long LONG;

/** @brief 32λ�޷������� */
typedef unsigned long ULONG;

/** @brief �з������� */
typedef int INT;

/** @brief �޷������� */
typedef unsigned int UINT;

/** @brief 64λ�з������� */
#if defined (_MSC_VER)
typedef __int64 DLONG;
#else
typedef long long DLONG;
#endif

/** @brief 64λ�޷������� */
#if defined (_MSC_VER)
typedef unsigned __int64 DULONG;
#else
typedef unsigned long long DULONG;
#endif

/** @brief ˫������������ */
typedef double DOUBLE;

/** @brief ������������ */
typedef float FLOAT;

/** @brief ������ */
typedef unsigned long BOOL_T;

/** @brief ��ʾ������������ */
typedef unsigned long SIZE_T;

/** @brief ��ʾʱ���������� */
typedef long TIME_T;

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;

/** @brief VOID�� */
#define VOID                            void

/** @brief ��ʾͨ�þ������ */
typedef VOID* HANDLE;

/** @brief IMOS ID �������� */
typedef DULONG IMOS_ID;

/** @brief ͨ�þ������ IMOS_HANDLE */
#ifndef IMOS_HANDLE
#if defined (WIN32)
typedef HANDLE IMOS_HANDLE;
#else
typedef int IMOS_HANDLE;
#endif
#endif

/** @brief �����������Ͷ��� */
#define IN
#define OUT
#define INOUT

/** @brief IMOS��̹淶����ֵ */
#define BOOL_TRUE                       ((BOOL_T) 1)
#define BOOL_FALSE                      ((BOOL_T) 0)

#ifndef NULL
#define NULL (void *)0
#endif

#if 0
#endif
/*******************************************************************************
SDK ������/״̬��
*******************************************************************************/
/* ͨ�óɹ� */
#define ERR_COMMON_SUCCEED                       0x000000      /**< ִ�гɹ� */

/*********************** SDK ״̬�붨��(257 - 356) *****************************/
#define ERR_SDK_LOG_CLOSE                        257            /**< SDK ��־�ر� */
#define ERR_SDK_DEVICE_STREAM_FULL               259            /**< �豸������ */
#define ERR_SDK_DEVICE_STREAM_CLOSED             260            /**< �豸���ѹر� */
#define ERR_SDK_DEVICE_STREAM_NONEXIST           261            /**< �豸�������� */
#define ERR_SDK_USER_PASSWORD_CHANGE             262            /**< �û������޸� */
#define ERR_SDK_USER_DELETED                     263            /**< �û���ɾ�� */

/*********************** SDK �����붨��(357 - 506) *****************************/
#define ERR_SDK_COMMON_FAIL                      357            /**< ����ʧ�� */
#define ERR_SDK_COMMON_INVALID_PARAM             358            /**< ��������Ƿ� */
#define ERR_SDK_COMMON_NO_MEMORY                 359            /**< ϵͳ�ڴ治�� */
#define ERR_SDK_COMMON_SYS_FAIL                  360            /**< ϵͳͨ�ô���Q: ��δʹ�� */
#define ERR_SDK_COMMON_FAIL_STAT                 361            /**< ��ȡ�ļ���Ŀ¼��״̬ʧ�� */
#define ERR_SDK_COMMON_FILE_NONEXIST             362            /**< �ļ������� */

#define ERR_SDK_USER_NOT_AUTHORIZED              457            /**< �û�δ��Ȩ */
#define ERR_SDK_USERFULL                         458            /**< �û����� */
#define ERR_SDK_USERNONEXIST                     459            /**< �û������� */
#define ERR_SDK_USER_PASSWD_INVALID              460            /**< �û�������� */
#define ERR_SDK_USER_KEEPALIVEFAIL               461            /**< SDK����ʧ�� */
#define ERR_SDK_NOTINIT                          462            /**< SDKδ��ʼ�� */
#define ERR_SDK_REINIT                           463            /**< SDK�ѳ�ʼ�� */

#define ERR_SDK_CREATE_THREAD_FAIL               466            /**< �����߳�ʧ�� */
#define ERR_SDK_NOENOUGH_BUF                     467            /**< ������̫С: �����豸���ݵĻ����� */
#define ERR_SDK_SOCKET_LSN_FAIL                  468            /**< ����socket listenʧ�� */
#define ERR_SDK_SUBSCRIBE_FULL                   470            /**< ���û���������, �豸���û����������Ĵ����벻�ܷ��� */
#define ERR_SDK_COMMAND_SEND_FAIL                471            /**< ������ʧ�� */
#define ERR_SDK_COMMAND_TIMEOUT                  472            /**< ����ʱ */
#define ERR_SDK_UPDATE_NOTADMIN                  473            /**< ��admin�û��޷����� */
#define ERR_SDK_UPDATE_INVALID                   474            /**< ���� δ��ʼ */
#define ERR_SDK_UPDATE_INPROCESS                 475            /**< ���� ������ */
#define ERR_SDK_UPDATE_NOMEMORY                  476            /**< ���� �ڴ�ռ䲻�� */
#define ERR_SDK_UPDATE_FILE_OPEN_ERR             477            /**< ���� �򿪾����ļ����� */
#define ERR_SDK_UPDATE_DEVICE_ERR                478            /**< ���� FLASH���� */
#define ERR_SDK_UPDATE_BUSY                      479            /**< ����ͬʱ���ض���������� */
#define ERR_SDK_UPDATE_FAIL_TIMEOUT              480            /**< ������ʱ */

#define ERR_SDK_IP_CONFLICT                      486            /**< IP��ַ��ͻ */
#define ERR_SDK_NETWORKMODE_NOTSUPPORT           487            /**< ����ģʽ��֧�� */


/*********************** SDK ҵ��ģ������붨��(507-656) *******************/
/* �豸ά�����(507 - 556) */
#define ERR_SDK_INVALID_CONFIGFILE               507            /**< �����ļ���Ч */

/* ý�����(557 - 606) */
#define ERR_SDK_BIAUDIO_AUDIOBCAST_FULL          557            /**< ����ҵ������ */

/* ��̨���(607 - 656) */
#define ERR_SDK_PTZ_TRACK_ISUSED                 612            /**< �켣��ʹ�ã��޷�ɾ��*/
#define ERR_SDK_PTZ_SERIALMODE_MISMATCH          614            /**< ����ģʽ��ƥ��*/
#define ERR_SDK_PTZ_TRACK_NOT_EXIST              618            /**< �켣������*/
#define ERR_SDK_PTZ_MODE_CRUISE_FULL             626            /**< ģʽ·���켣��������� */


/*********************** SDK �����������붨��(657 - 756) ****************************/
#define ERR_SDK_XP_INIT_FAILED                   657            /**< ��������ʼ��ʧ�� */
#define ERR_SDK_XP_PORT_ALLOC_FAILED             658            /**< ������ͨ������ʧ�� */
#define ERR_SDK_XP_PORT_NOT_EXIST                659            /**< ������ͨ�������� */
#define ERR_SDK_XP_START_STREAM_FAILED           660            /**< ����������ʧ�� */
#define ERR_SDK_XP_START_PLAY_FAILED             662            /**< ��ʼ����ʧ�� */
#define ERR_SDK_XP_FILE_PLAY_FINISHED            669            /**< �ļ��Ѳ����� */
#define ERR_SDK_XP_DISK_CAPACITY_WARN            670            /**< Ӳ��ʣ��ռ������ֵ */
#define ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH      671            /**< Ӳ��ʣ��ռ䲻�� */
#define ERR_SDK_XP_NO_PICTURE_TO_SNATCH          672            /**< û�н������ͼƬ�ɹ�ץ�� */
#define ERR_SDK_XP_SERIES_SNATCH_FAILED          673            /**< ����ץ�Ĺ�����ץ��ʧ�� */
#define ERR_SDK_XP_WRITE_FILE_FAILED             674            /**< д�ļ�����ʧ�� */
#define ERR_SDK_XP_FILE_DESTROY                  675            /**< �ļ����� */
#define ERR_SDK_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE 676            /**< ý������ʽ��֧��¼����� */
#define ERR_SDK_XP_PROCESS_MEDIA_DATA_FAILED     677            /**< ý�����ݴ���ʧ�� */
#define ERR_SDK_XP_RECV_DATA_FAILED              678            /**< ���������ɽ�������ʧ�� */
#define ERR_SDK_XP_MEDIA_RESOLUTION_CHANGE       679            /**< ý�����ֱ��ʷ����仯 */
#define ERR_SDK_XP_VOICE_RUNNING_ERROR           680            /**< �����Խ���㲥�����г��� */
#define ERR_SDK_XP_AUDIO_DEVICE_UNRIPE           682            /**< ��Ƶ�豸δ׼���� */

/*******************************************************************************
SDK �궨�� 
*******************************************************************************/
#if 0
#endif
/**************************************** �豸״̬��� ***************************************/
/**@brief �豸״̬���� */
#define IMOS_MW_STATUS_KEEPALIVE                   0            /**< SDK���״̬��Ϊ: ERR_SDK_USER_KEEPALIVEFAIL */
#define IMOS_MW_STATUS_UPDATE                      1            /**< ���������״̬��Ϊ: ERR_SDK_UPDATE_INVALID �� */
#define IMOS_MW_STATUS_NETWORK_CHANGE              54           /**< �������ý����״̬��Ϊ: ERR_SDK_IP_CONFLICT �� */
#define IMOS_MW_STATUS_PTZ_ABS_POSITION            101          /**< ��̨����λ�ã���Ӧ��������: IMOS_MW_PTZ_ABSPOSITION_S */                    
#define IMOS_MW_STATUS_PTZ_ABS_ZOOM                102          /**< ��̨����ZOOM��������Ӧ��������: IMOS_MW_PTZ_ABSZOOM_S */  
#define IMOS_MW_STATUS_PLAYER_MEDIA_PROCESS        201          /**< ��Ƶý�崦������е��ϱ�������Ϣ����Ϣ���ݼ�: IMOS_MW_PLAYER_STATUS_S */

#if 0
#endif
/*************************************** ������� ********************************************/
/**@brief ���ò��������� */
/* ϵͳ���� */
#define IMOS_MW_SYSTEM_TIME_INFO            0          /**< ��ȡ/���� ϵͳʱ��(��ʱ����Ϣ)����Ӧ�ṹ����: IMOS_MW_SYSTEM_TIME_INFO_S */
       
/* ���� */
#define IMOS_MW_NETWORK_INTERFACE_CFG       12         /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_NETWORK_INTERFACE_CFG_S */
    
/* ͼ��������� */
#define IMOS_MW_EXPOSURE_CFG                20         /**< ��ȡ/���� �ع��������Ӧ�ṹ����: IMOS_MW_EXPOSURE_CFG_S */
#define IMOS_MW_WHITE_BALANCE_CFG           21         /**< ��ȡ/���� ��ƽ���������Ӧ�ṹ����: IMOS_MW_WHITE_BALANCE_CFG_S */
#define IMOS_MW_IMAGE_ENHANCE_CFG           22         /**< ��ȡ/���� ͼ����ǿ��������Ӧ�ṹ����: IMOS_MW_IMAGE_ENHANCE_CFG_S */
#define IMOS_MW_FOCUS_CFG                   23         /**< ��ȡ/���� �Խ���������Ӧ�ṹ����: IMOS_MW_FOCUS_CFG_S */

/* ��Ƶ���롢��Ƶ����������OSD */
#define IMOS_MW_VIDEOIN_MODE_CFG            30         /**< ��ȡ/���� ��Ƶ������ʽ����Ӧ�ṹ����: IMOS_MW_VIDEOIN_MODE_CFG_S */
#define IMOS_MW_VIDEO_ENCODER_CFG           31         /**< ��ȡ/���� ��Ƶ����������ã���Ӧ�ṹ����:IMOS_MW_VIDEO_ENCODER_CFG_S */
#define IMOS_MW_AUDIO_IN_CFG                32         /**< ��ȡ/���� ��Ƶ����������ã���Ӧ�ṹ����:IMOS_MW_AUDIO_IN_CFG_S */
#define IMOS_MW_OSD_STYLE_CFG               35         /**< ��ȡ/���� ����OSD��ʽ���ã���Ӧ�ṹ����: IMOS_MW_OSD_STYLE_CFG_S */
#define IMOS_MW_INFO_OSD_CFG                36         /**< ��ȡ/����/ɾ�� ����OSD���ã���Ӧ�ṹ����: IMOS_MW_INFO_OSD_CFG_S */

/* ��̨���: Ԥ��λ�б�����λ */
#define IMOS_MW_PTZ_PRESET_CFG              51         /**< ��ȡ      Ԥ��λ��Ϣ����Ӧ�ṹ����: IMOS_MW_PRESET_CFG_S */    
#define IMOS_MW_PTZ_GUARD_PRESET_CFG        52         /**< ��ȡ/���� ����λ��Ϣ����Ӧ�ṹ����: IMOS_MW_GUARD_PRESET_CFG_S */ 
#if 0
#endif
/*************************************** �豸ά����� ********************************************/
/*@brief ͨ��CODE����*/
#define IMOS_MW_CODE_LEN                    48   

/*@brief ͨ�������ַ������� */
#define IMOS_MW_NAME_LEN                    64     

/*@brief �ļ������ַ������� */
#define IMOS_MW_FILE_NAME_LEN               IMOS_MW_NAME_LEN    

/*@brief ��Դ������Ϣ�ַ������� */
#define IMOS_MW_RES_CODE_LEN                IMOS_MW_CODE_LEN

/*@brief ϵͳĬ��·������ */
#define IMOS_MW_DEFAULT_PATH_LEN            256

/*@brief SDK �ͻ��˰汾�ų��� */
#define IMOS_MW_SDK_CLIENT_VERSION_LEN      32

/*@brief IP��ַ��Ϣ�ַ������� 
  * IPV4: "192.168.0.102"
  * IPV6: "A1:0:8:100:200:0:0:321A"
  * ����: "AS_server_hangzhou" */
#define IMOS_MW_IPADDR_LEN                  64  

/*@brief SNMP ����������  */
#define IMOS_MW_COMMUNITY_LEN               32

/*@brief ʱ�� ��ʽ */
#define IMOS_MW_TIME_FORMAT_HHMMSS          0        /**< XX:XX:XX �������й���������Ӣ����*/
#define IMOS_MW_TIME_FORMAT_HHMMSS_PM       1        /**< XX:XX:XX p.m. �����ڳ�����������������������*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS_PM     2        /**< XX:XX:XX PM �����ڳ�Ӣ�������Ӣ�����*/
#define IMOS_MW_TIME_FORMAT_PM_HHMMSS       3        /**< PM XX:XX:XX ����������(�¼���)*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS        4        /**< ���� XX:XX:XX ����������(̨��)*/

/*@brief ���� ��ʽ */
#define IMOS_MW_DATE_FORMAT_YYYYMMDD        0        /**< XXXX-XX-XX ������ */
#define IMOS_MW_DATE_FORMAT_MMDDYYYY        1        /**< XX-XX-XXXX ������ */
#define IMOS_MW_DATE_FORMAT_YYYY_MM_DD      2        /**< XXXX��XX��XX�� */
#define IMOS_MW_DATE_FORMAT_MM_DD_YYYY      3        /**< XX��XX��XXXX�� */

/*@brief �汾��Ϣ���� */
#define IMOS_MW_VERSION_LEN                 256 

/*@brief �û�����󳤶� */
#define IMOS_MW_USER_NAME_LEN               32   

/*@brief �û�������󳤶� */
#define IMOS_MW_USER_PASSWORD_LEN           32  

/**@brief �û����� */
#define IMOS_MW_USERLEVEL_ADMINISTRATOR     0        /**< ����Ա */
#define IMOS_MW_USERLEVEL_OPERATOR          1        /**< ����Ա */
#define IMOS_MW_USERLEVEL_USER              2        /**< ��ͨ�û� */
#define IMOS_MW_USERLEVEL_ANONYMOUS         3        /**< �����û� */
#define IMOS_MW_USERLEVEL_EXTENDED          4        /**< ��չ�û� */

/**@brief �������� */
#define IMOS_MW_PARAM_TYPE_OPTICS_VIDEO     0        /**< ��Ƶ��ͼ����� */
#define IMOS_MW_PARAM_TYPE_OPTICS_PICTURE   1        /**< ��Ƭ��ͼ����� */

/**@brief ��־���� */
#define IMOS_SDK_LOG_CLOSE                  0        /**< �ر���־ */
#define IMOS_SDK_LOG_DEBUG                  1        /**< debug���� */
#define IMOS_SDK_LOG_INFO                   2        /**< info���� */
#define IMOS_SDK_LOG_WARN                   3        /**< warn���� */
#define IMOS_SDK_LOG_ERROR                  4        /**< error���� */
#define IMOS_SDK_LOG_FATAL                  5        /**< fatal���� */
#if 0
#endif
/*************************************** ������� ********************************************/
/*@brief PPPoE�û�������  */
#define IMOS_MW_PPPOE_USERNAME_LEN               32  

/*@brief PPPoE���볤�� */
#define IMOS_MW_PPPOE_PASSWORD_LEN               32

/**@brief IP��ȡ��ʽ */
#define IMOS_MW_IP_GET_TYPE_STATIC               0        /**< ��̬��ȡ */
#define IMOS_MW_IP_GET_TYPE_PPPOE                1        /**< pppoe���� */
#define IMOS_MW_IP_GET_TYPE_DHCP                 2        /**< DHCP���� */

/**@brief �������� */
#define IMOS_MW_PORT_MODE_ELECTRONIC             0        /**< ��� */
#define IMOS_MW_PORT_MODE_FIBER                  1        /**< ��� */
#define IMOS_MW_PORT_MODE_EPON                   2        /**< EPON */
#define IMOS_MW_PORT_MODE_LRE                    3        /**< LRE��� */

/**@brief ���ڹ���ģʽ */
#define IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION    0    /**< ��Э�� */
#define IMOS_MW_ETH_WORKMODE_10M_FULL            1    /**< 10M FULL */
#define IMOS_MW_ETH_WORKMODE_10M_HALF            2    /**< 10M HALF */
#define IMOS_MW_ETH_WORKMODE_100M_FULL           3    /**< 100M FULL */
#define IMOS_MW_ETH_WORKMODE_100M_HALF           4    /**< 100M HALF */
#define IMOS_MW_ETH_WORKMODE_1000M_FULL          5    /**< 1000M FULL */

#if 0
#endif
/*************************************** ͼ����� ********************************************/
/**@brief ͼ������ */
#define IMOS_MW_IMAGE_TYPE_VIDEO                0       /**< ��Ƶͼ�� */
#define IMOS_MW_IMAGE_TYPE_CAPTURE              1       /**< ץ��ͼ�� */
#define IMOS_MW_IMAGE_TYPE_COUNT                2       /**< ͼ�����͸��� */

/**@brief ��ƽ��ģʽ */
#define IMOS_MW_WB_AUTO                         0       /**< �Զ���ƽ�� */
#define IMOS_MW_WB_FINETUNE                     1       /**< ΢����ƽ�� */
#define IMOS_MW_WB_INDOOR                       2       /**< ���ڰ�ƽ�� */
#define IMOS_MW_WB_OUTDOOR                      3       /**< �����ƽ�� */
#define IMOS_MW_WB_AUTO_MERCURY                 4       /**< �Զ�ˮ���ư�ƽ�� */ 

/**@brief �Խ�ģʽ */
#define IMOS_MW_FOCUS_AUTO                      0       /**< �Զ��Խ� */
#define IMOS_MW_FOCUS_MANUAL                    1       /**< �ֶ��Խ� */
#define IMOS_MW_FOCUS_PUSH                      2       /**< һ���Խ� */
#define IMOS_MW_FOCUS_PUSH_NIGHTINFRARED        3       /**< һ���Խ�(ҹ�����) */

/**@brief ����ֵ��λ */
#define IMOS_MW_SHUTTER_UNIT_MICSEC             0       /**< ΢�� */
#define IMOS_MW_SHUTTER_UNIT_DENOMINATOR        1       /**< ��ĸ��ʾ������λ: 1/�� */

/**@brief �ع�ģʽ */
#define IMOS_MW_EXPOSURE_AUTO                   0       /**< �Զ��ع� */
#define IMOS_MW_EXPOSURE_CUSTOM                 1       /**< �Զ����ع� */
#define IMOS_MW_EXPOSURE_SHUTTER                2       /**< �������� */
#define IMOS_MW_EXPOSURE_IRIS                   3       /**< ��Ȧ���� */
#define IMOS_MW_EXPOSURE_GAIN                   4       /**< �������� */
#define IMOS_MW_EXPOSURE_INDOOR_50HZ            5       /**< ����50HZ */
#define IMOS_MW_EXPOSURE_INDOOR_60HZ            6       /**< ����60HZ */
#define IMOS_MW_EXPOSURE_MANUAL                 7       /**< �ֶ��ع� */

/**@brief ��̬ģʽ */
#define IMOS_MW_WDR_DISABLE                     0       /**< �ر� */
#define IMOS_MW_WDR_ENABLE                      1       /**< ���� */
#define IMOS_MW_WDR_AUTO                        2       /**< �Զ� */

/**@brief ���ģʽ */
#define IMOS_MW_METERING_CENTER                 0       /**< ����Ȩ�� */
#define IMOS_MW_METERING_AREA                   1       /**< ������Ȩ�� */

/**@brief ��ҹģʽ */
#define IMOS_MW_DAYNIGHT_AUTO                   0       /**< �Զ�ģʽ */
#define IMOS_MW_DAYNIGHT_COLOR                  1       /**< ��ɫ */
#define IMOS_MW_DAYNIGHT_BW                     2       /**< �ڰ� */

/**@brief ���ģʽ */
#define IMOS_MW_SHARPNESS_AUTO                  0       /**< �Զ�ģʽ */
#define IMOS_MW_SHARPNESS_MANUAL                1       /**< �ֶ�ģʽ */

/**@brief ����ģʽ */
#define IMOS_MW_MIRROR_MODE_NONE                0       /**< ����ģʽ */
#define IMOS_MW_MIRROR_MODE_FLIP                1       /**< ��ֱ��ת */
#define IMOS_MW_MIRROR_MODE_MIRROR              2       /**< ˮƽ��ת */
#define IMOS_MW_MIRROR_MODE_FLIP_MIRROR         3       /**< ��ֱˮƽͬʱ��ת */
#define IMOS_MW_MIRROR_MODE_ROTATE_CLOCKWISE    4       /**< ˳ʱ����ת90�� */

#if 0
#endif
/*************************************** OSD��� ********************************************/
/*@brief OSD �������ݵĳ��� */
#define IMOS_MW_OSD_INFO_LEN                      60    

/*@brief ���� OSD ������ */
#define IMOS_MW_INFO_OSD_MAX_NUM                  3   

/*@brief OSD ��������������� */
#define IMOS_MW_INFO_OSD_LINE_MAX                 8

/*@brief �ڸ� OSD ������ */
#define IMOS_MW_COVER_OSD_MAX_NUM                 8 

/*@brief ������������ */
#define IMOS_MW_OSD_INFO_TYPE_UNUSED              0    /* ��ʹ�� */
#define IMOS_MW_OSD_INFO_TYPE_USERDEF             1    /* �Զ��� */
#define IMOS_MW_OSD_INFO_TYPE_DATETIME            2    /* ʱ������ */
#define IMOS_MW_OSD_INFO_TYPE_PTZOPER             3    /* ��̨������ */
#define IMOS_MW_OSD_INFO_TYPE_PTZCOORDINATS       4    /* ��̨���� */
#define IMOS_MW_OSD_INFO_TYPE_CRUISEINFO          5    /* Ѳ����Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_ZOOMINFO            6    /* �䱶��Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_PRESETINFO          7    /* Ԥ��λ��Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_ALARMINFO           8    /* ������Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_ENCODEINFO          9    /* ������Ϣ */

/*@brief ���� OSD ���� */
#define IMOS_MW_OSD_PIC_TIME                      0     /**< ץ����Ƭ ʱ��OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_SPEED             1     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_LIMITED_SPEED             2     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_PECCANCY_TYPE             3     /**< ץ����Ƭ Υ������OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_COLOR             4     /**< ץ����Ƭ ������ɫOSD */
#define IMOS_MW_OSD_PIC_VEHICLE_LOGO              5     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_TYPE              6     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_TYPE_BUTT                     7     /**< ֧�ֵ�ץ��OSD���� */

/*@brief OSD ������ʽ */
#define IMOS_MW_OSD_FONT_STYLE_NORMAL             0    /**< ���� */
#define IMOS_MW_OSD_FONT_STYLE_STROKES            1    /**< ��� */ 
#define IMOS_MW_OSD_FONT_STYLE_HOLLOW             2    /**< ���� */

/*@brief OSD �����С */
#define IMOS_MW_OSD_FONT_SIZE_LARGE               0    /**< �� */
#define IMOS_MW_OSD_FONT_SIZE_MIDDLE              1    /**< �� */
#define IMOS_MW_OSD_FONT_SIZE_SMALL               2    /**< С */

/*@brief OSD ��ɫ */
#define IMOS_MW_OSD_COLOR_WHITE                   0    /**< �� */
#define IMOS_MW_OSD_COLOR_RED                     1    /**< �� */
#define IMOS_MW_OSD_COLOR_YELLOW                  2    /**< �� */
#define IMOS_MW_OSD_COLOR_BLUE                    3    /**< �� */
#define IMOS_MW_OSD_COLOR_BLACK                   4    /**< �� */
#define IMOS_MW_OSD_COLOR_GREEN                   5    /**< �� */
#define IMOS_MW_OSD_COLOR_PURPLE                  6    /**< �� */

/*@brief OSD ͸���� */
#define IMOS_MW_OSD_ALPHA_NO                      0    /**< ��͸�� */
#define IMOS_MW_OSD_ALPHA_SEMI                    1    /**< ��͸�� */
#define IMOS_MW_OSD_ALPHA_ALL                     2    /**< ȫ͸�� */

#if 0
#endif
/*************************************** ý������� ********************************************/
/**@brief ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_RTP_UDP           0        /**< UDP��RTP ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_RTP_TCP           1        /**< TCP��RTP ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW1_TCP      2        /**< TCP��Uniview1 ����ģʽ */        
#define IMOS_MW_TRANSFER_MODE_TS_TCP            3        /**< TCP��TS ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_TS_UDP            4        /**< UDP��TS ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_HTTP              5        /**< ����RTP/RTSP/HTTP/TCP���ط�ʽ */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW2_TCP      6        /**< TCP��Uniview2 ����ģʽ */  

/**@brief ��ID */
#define IMOS_MW_STREAM_ID_MAIN                  0        /**< ���� */
#define IMOS_MW_STREAM_ID_AUX                   1        /**< ���� */
#define IMOS_MW_STREAM_ID_THIRD                 2        /**< ���� */

/**@brief ý�������� */
#define IMOS_MW_MEDIA_VIDEO                     0       /**< ʵ���� */
#define IMOS_MW_MEDIA_VOICE_TALK                1       /**< �����Խ� */
#define IMOS_MW_MEDIA_VOICE_BROADCAST           2       /**< �����㲥 */

/**@brief �������� */
#define IMOS_MW_STREAM_TYPE_TS                  0       /**<  TS  */
#define IMOS_MW_STREAM_TYPE_H3C_ES              1       /**<  H3C ES RTP  */
#define IMOS_MW_STREAM_TYPE_PS                  2       /**<  PS  */
#define IMOS_MW_STREAM_TYPE_UNIVIEW             6       /**< ���ӿ��ڵ羯Э�� */

/**@brief ��������ģʽ */
#define IMOS_MW_CONNECT_TYPE_UDP                0       /**<  UDP  */
#define IMOS_MW_CONNECT_TYPE_TCP                1       /**<  TCP  */
#define IMOS_MW_CONNECT_TYPE_RTP                2       /**<  RTP  */
#define IMOS_MW_CONNECT_TYPE_RTP_NO_RTCP        3       /**< RTP no rtcp*/
#define IMOS_MW_CONNECT_TYPE_AUTO               4       /**< ����Ӧ */
#define IMOS_MW_CONNECT_TYPE_HTTP               5       /**< RTP/RTSP/HTTP/TCP ���ط�ʽ */

/**@brief GOPģʽ */
#define IMOS_MW_GOP_TYPE_IP                     0       /**< IP */
#define IMOS_MW_GOP_TYPE_IBP                    1       /**< IBP */
#define IMOS_MW_GOP_TYPE_IBBP                   2       /**< IBBP */
#define IMOS_MW_GOP_TYPE_I                      3       /**< I */

/**@brief ����ģʽ */
#define IMOS_MW_ENCODE_MODE_CBR                 0       /**< CBR��ʽ */
#define IMOS_MW_ENCODE_MODE_VBR                 1       /**< VBR��ʽ */

/**@brief ��Ƶ�����ʽ */
#define IMOS_MW_STREAM_FORMAT_MPEG1             0       /**< MPEG1 */
#define IMOS_MW_STREAM_FORMAT_MPEG2             1       /**< MPEG2 */
#define IMOS_MW_STREAM_FORMAT_MPEG4             2       /**< MPEG4 */
#define IMOS_MW_STREAM_FORMAT_MJPEG             3       /**< MJPEG */
#define IMOS_MW_STREAM_FORMAT_H263              4       /**< H263 */
#define IMOS_MW_STREAM_FORMAT_H263PLUS          5       /**< H263+ */
#define IMOS_MW_STREAM_FORMAT_H264              6       /**< H.264 */
#define IMOS_MW_STREAM_FORMAT_AUTO              7       /**< ����Ӧ(����) */
#define IMOS_MW_STREAM_FORMAT_MPEG4_DS          8       /**< MPEG4-ds */
#define IMOS_MW_STREAM_FORMAT_MPEG2_DS          9       /**< MPEG2-ds */ 
#define IMOS_MW_STREAM_FORMAT_MPEG4_2           10      /**< MPEG4 ���� */    
#define IMOS_MW_STREAM_FORMAT_H264_2            11      /**< H264 ���� */   
#define IMOS_MW_STREAM_FORMAT_JPEG              12      /**< JPEG */ 

/**@brief ��Ƶ�����ʽ */
#define IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2       0       /**< MPEG1_LAYER2 */
#define IMOS_MW_AUDIO_ENCODE_G711A              1       /**< G.711A */
#define IMOS_MW_AUDIO_ENCODE_G711U              2       /**< G.711U */
#define IMOS_MW_AUDIO_ENCODE_ADPCM              3       /**< ADPCM */
#define IMOS_MW_AUDIO_ENCODE_OGG                4       /**< OGG */
#define IMOS_MW_AUDIO_ENCODE_AUTO               5       /**< �Զ� */
#define IMOS_MW_AUDIO_ENCODE_AAC                6       /**< AAC */

/**@brief ������� */
#define IMOS_MW_AUDIO_VOLUME_REDUCE_8           1 
#define IMOS_MW_AUDIO_VOLUME_REDUCE_4           2
#define IMOS_MW_AUDIO_VOLUME_REDUCE_2           3
#define IMOS_MW_AUDIO_VOLUME_ZOOM_1             4
#define IMOS_MW_AUDIO_VOLUME_ZOOM_2             5
#define IMOS_MW_AUDIO_VOLUME_ZOOM_4             6
#define IMOS_MW_AUDIO_VOLUME_ZOOM_8             7

/**@brief ������ */
#define IMOS_MW_AUDIO_SAMPLING_8000             0 
#define IMOS_MW_AUDIO_SAMPLING_16000            1
#define IMOS_MW_AUDIO_SAMPLING_22050            2
#define IMOS_MW_AUDIO_SAMPLING_24000            3
#define IMOS_MW_AUDIO_SAMPLING_32000            4
#define IMOS_MW_AUDIO_SAMPLING_44100            5
#define IMOS_MW_AUDIO_SAMPLING_48000            6
#define IMOS_MW_AUDIO_SAMPLING_96000            7

/**@brief ��Ƶͨ�� */
#define IMOS_MW_AUDIO_CHANNEL_STEREO            0        /**< ������ */
#define IMOS_MW_AUDIO_CHANNEL_L                 1        /**< ������ */
#define IMOS_MW_AUDIO_CHANNEL_R                 2        /**< ������ */
#define IMOS_MW_AUDIO_CHANNEL_MONO              3        /**< ������ */

/**@brief ��Ƶ��������λ�� */
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_8       8
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_16      16
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_32      32

/**@brief ����Э�� */
#define IMOS_MW_PROTOCOL_UDP                    0       /**< UDPЭ�� */
#define IMOS_MW_PROTOCOL_TCP                    1       /**< TCPЭ��*/

#if 0
#endif
/**************************************** ��̨Ѳ����� ***************************************/
/*@brief ���켣�����*/
#define IMOS_MW_TRACK_POINT_NUM                64      

/*@brief Ԥ��λ������Ϣ��󳤶� */ 
#define IMOS_MW_PTZ_PRESET_NAME                64  

/*@brief ��̨Э�����Ƴ��� */ 
#define IMOS_MW_PTZ_NAME_LEN                   16

/*@brief ʱ���ַ������� */ 
#define IMOS_MW_TIME_LEN                       12    

/*@brief �����ַ������� */ 
#define IMOS_MW_DAY_LEN                        12   

/*@brief �ܵ����� */
#define IMOS_MW_WEEK_DAY                       7

/**@brief ��̨�������� */
#define IMOS_MW_PTZ_CMD_IRISCLOSE              0x0102        /**< ��Ȧ��С */
#define IMOS_MW_PTZ_CMD_IRISOPEN               0x0104        /**< ��Ȧ��� */
#define IMOS_MW_PTZ_CMD_FOCUSNEAR              0x0202        /**< ���۽� */
#define IMOS_MW_PTZ_CMD_FOCUSFAR               0x0204        /**< Զ�۽� */
#define IMOS_MW_PTZ_CMD_ZOOMIN                 0x0302        /**< �Ŵ� */
#define IMOS_MW_PTZ_CMD_ZOOMOUT                0x0304        /**< ��С */
#define IMOS_MW_PTZ_CMD_TILTUP                 0x0402        /**< ��, ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_TILTDOWN               0x0404        /**< ��, ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_PANRIGHT               0x0502        /**< ��, ulPTZCmdPara1 ˮƽ�����ٶ� */
#define IMOS_MW_PTZ_CMD_PANLEFT                0x0504        /**< ��, ulPTZCmdPara1 ˮƽ�����ٶ� */
#define IMOS_MW_PTZ_CMD_LEFTUP                 0x0702        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_LEFTDOWN               0x0704        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_RIGHTUP                0x0802        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */    
#define IMOS_MW_PTZ_CMD_RIGHTDOWN              0x0804        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_STOP                   0x0901        /**< ֹͣ */

#if 0
#endif
/**************************************** �洢 (����) ��� ***************************************/
/**@brief �洢�ļ����� */
#define IMOS_MW_STOR_FILE_TYPE_VIDEO        0          /**< ¼�� */

/**@brief �洢���� */
#define IMOS_MW_STOR_POLICY_FULL_STOP       0          /**< ��ֹͣ */
#define IMOS_MW_STOR_POLICY_FULL_REWRITE    1          /**< ������ */

/**@brief �洢ģʽ(����) */
#define IMOS_MW_LOCAL_STOR_AUTO             0          /**< �Զ� */
#define IMOS_MW_LOCAL_STOR_FOREVER          1          /**< ���� */
#define IMOS_MW_LOCAL_STOR_SAVE             2          /**< �������ϴ�����SD���ϵ��ļ� */
#define IMOS_MW_LOCAL_STOR_START            10         /**< ���� */
#define IMOS_MW_LOCAL_STOR_STOP             11         /**< �ر� */

#if 0
#endif
/**************************************** ���ſ��� ***************************************/
/*@brief ���Ŵ��������� */
#define IMOS_MW_MAX_WND_NUM                      9

/**@brief ����״̬ */
#define IMOS_MW_PLAY_STATUS_16_BACKWARD          0       /**< 16���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_8_BACKWARD           1       /**< 8���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_4_BACKWARD           2       /**< 4���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_2_BACKWARD           3       /**< 2���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_1_BACKWARD           4       /**< �����ٶȺ��˲��� */
#define IMOS_MW_PLAY_STATUS_HALF_BACKWARD        5       /**< 1/2���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_QUARTER_BACKWARD     6       /**< 1/4���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_QUARTER_FORWARD      7       /**< 1/4���ٲ��� */
#define IMOS_MW_PLAY_STATUS_HALF_FORWARD         8       /**< 1/2���ٲ��� */
#define IMOS_MW_PLAY_STATUS_1_FORWARD            9       /**< �����ٶ�ǰ������ */
#define IMOS_MW_PLAY_STATUS_2_FORWARD            10      /**< 2����ǰ������ */
#define IMOS_MW_PLAY_STATUS_4_FORWARD            11      /**< 4����ǰ������ */
#define IMOS_MW_PLAY_STATUS_8_FORWARD            12      /**< 8����ǰ������ */
#define IMOS_MW_PLAY_STATUS_16_FORWARD           13      /**< 16����ǰ������ */

/**@brief ý���ļ���ʽ */
#define IMOS_MW_MEDIA_FILE_FORMAT_TS             0       /**< TS��ʽ��ý���ļ� */
#define IMOS_MW_MEDIA_FILE_FORMAT_FLV            1       /**< FLV��ʽ��ý���ļ� */

/**@brief ��Ƶ��ʾģʽ */
#define IMOS_MW_RENDER_MODE_D3D                  0       /**< ʹ��D3D�ķ�ʽ������ʾ */
#define IMOS_MW_RENDER_MODE_DDRAW_NORMAL         1       /**< ʹ��Ddraw��Normal��ʾģʽ */

/**@brief ��Ƶ���ظ�ʽ */
#define IMOS_MW_PIXEL_FORMAT_YUV420              0       /**< YUV420��ʽ��� */
#define IMOS_MW_PIXEL_FORMAT_RGB32               1       /**< RGB32��ʽ��� */

/**@brief ͼ�񲥷������� */
#define IMOS_MW_PICTURE_TIME_PRIORITY            0       /**< ʵʱ������ */
#define IMOS_MW_PICTURE_FLUENCY_PRIORITY         1       /**< ���������� */
#define IMOS_MW_PICTURE_AUTO                     2       /**< �Զ� */
#define IMOS_MW_PICTURE_LOWDELAY                 3       /**< ����ʱ */

/**@brief ���Ŵ�����ʾͼ��ı��� */
#define IMOS_MW_RENDER_SCALE_FULL                0       /**< ͼ������������Ŵ��� */
#define IMOS_MW_RENDER_SCALE_PROPORTION          1       /**< ͼ�񰴱�����ʾ */

/**@brief ý����������ʽ */
#define IMOS_MW_MEDIA_DATA_TS                    0       /**< TS��װ���� */
#define IMOS_MW_MEDIA_DATA_ES12                  1       /**< RTP + ��/��Ƶ˽��ͷ��12�ֽڣ� + ES���� */
#define IMOS_MW_MEDIA_DATA_ES12_TIME             2       /**< RTP + ʱ�����8�ֽڣ� + ��/��Ƶ˽��ͷ��12�ֽڣ� + ES���� */
#define IMOS_MW_MEDIA_DATA_RTP_ES                3       /**< RTP + ES���� */
#define IMOS_MW_MEDIA_DATA_HK                    4       /**< �����������ص��ĵ�һ�����Ǻ���40�ֽ�ϵͳͷ */
#define IMOS_MW_MEDIA_DATA_DH                    5       /**< ������ */
#define IMOS_MW_MEDIA_DATA_RM                    6       /**< �����������ص��ĵ�һ����������40�ֽ�ϵͳͷ */
#define IMOS_MW_MEDIA_DATA_TDY_SWALLOW           7       /**< TDY-SWALLOW */
#define IMOS_MW_MEDIA_DATA_DMA_SWALLOW           8       /**< DMA-SWALLOW */

/**@brief �������Ƶ��ʽ */
#define IMOS_MW_WAVE_FORMAT_PCM8M16              0       /**< PCM��8K�����ʣ���������M����16λ���� */
#define IMOS_MW_WAVE_FORMAT_PCM16M16             1       /**< PCM��16K�����ʣ���������M����16λ���� */ 
#define IMOS_MW_WAVE_FORMAT_PCM441M16            2       /**< PCM��44.1K�����ʣ���������M����16λ���� */ 

/**@brief ��Ƶ֡���� */
#define IMOS_MW_VIDEO_FRAME_TYPE_I               0       /**< I֡ */
#define IMOS_MW_VIDEO_FRAME_TYPE_P               1       /**< P֡ */
#define IMOS_MW_VIDEO_FRAME_TYPE_B               2       /**< B֡ */

/**@brief ʱ������� */
#define IMOS_MW_RENDER_TYPE_FRAME_RATE           0       /**< ʹ��֡�����ݽ�����Ƶ��Ⱦ */
#define IMOS_MW_RENDER_TYPE_ABSOLUTE_TIME        1       /**< ʹ�þ���ʱ�����ݽ�����Ƶ��Ⱦ */

/**@brief ���� �Աȶ�ģʽ */
#define IMOS_MW_PICTURE_CONTRAST_MODE_NONE        0      /**< �����жԱȶȵ��ڴ��� */
#define IMOS_MW_PICTURE_CONTRAST_MODE_BRIGHTNESS  1      /**< ����ģʽ */
#define IMOS_MW_PICTURE_CONTRAST_MODE_SOFTNESS    2      /**< ���ģʽ */

/**@brief ͼƬ��ʽ */
#define IMOS_MW_PICTURE_FORMAT_BMP                0      /**< BMP ��ʽ */ 
#define IMOS_MW_PICTURE_FORMAT_JPEG               1      /**< JPEG ��ʽ�������μ�: IMOS_MW_CAPTURE_FORMAT_CFG_S */
#define IMOS_MW_PICTURE_FORMAT_CUSTOM             10     /**< ������ʽ, ����Ҫ�������� */

/*@brief ��Ƭ��˵�����Ϣ���� */
#define IMOS_MW_IMAGE_BACKEND_OSD                 0    /**< ���� OSD���ṹ����: IMOS_MW_IMAGE_OSD_INFO_S */
#define IMOS_MW_IMAGE_BACKEND_RECTANGLE           1    /**< ���� ��Ϣ��, �ṹ����: IMOS_MW_RECTANGLE_S, ���У����굥λ 0.01% */
#define IMOS_MW_IMAGE_BACKEND_OSD_OBJ             2    /**< ����OSD, ��Ŀ����Ϣ��, �ṹ����: IMOS_MW_IMAGE_OSD_WITH_OBJ_S, ��Ϣ�����굥λ 0.01% */

#if 0
#endif

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_DEF_H__*/

