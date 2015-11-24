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
/********************************�궨��**********************************************/
#define PU_RESERVE_LEN             32            //Ԥ���ֽڳ�

#define PU_VERSION_LEN             32            //�汾����
#define PU_DEVICE_NAME_LEN         32            //�豸���Ƴ���
#define PU_FAC_NAME_LEN            12            //�������Ƴ���
#define PU_DEVICE_TYPE_LEN         32            //�豸���ͳ���
#define PU_SERIAL_LEN              32            //���кų���

#define PU_IP4_ADDR_LEN            16            //ipv4
#define PU_IP6_ADDR_LEN            40            //ipv6

#define PU_PLATFORM_INFO_LEN       32            //ƽ̨��Ϣ����

#define PU_PTZ_NAME_LEN            32            //��̨�������ֵ
#define PU_PTZ_CRUISE_LEN          32            //Ԥ��λ����
#define PU_PTZ_CRUISE_POINT_MAX    20            //�켣�����ֵ
#define PU_PTZ_PRESET_NUM          10            //Ԥ��λ��

#define PU_PRIVACY_MASK_MAX        10            //��˽�����������ֵ
#define PU_ALARM_TIME_MAX          8             //�澯ʱ������ֵ
#define PU_ALARM_AREA_MAX          16            //�澯�������ֵ

#define PU_CRUISE_DWELL_MIN        3             //Ѳ���켣��Сͣ��ʱ��
#define PU_CRUISE_DWELL_MAX        3600          //Ѳ���켣���ͣ��ʱ��
#define PU_CRUISE_SPEED_MIN        1             //Ѳ���켣��Сת���ٶ�
#define PU_CRUISE_SPEED_MAX        10            //Ѳ���켣���ת���ٶ�

#define PU_TIME_YEAR_LEN           5             //������"��"�ַ�������
#define PU_TIME_OTHERS_LEN         3             //�����г�"��"�������ַ�������
#define PU_TIME_TOTAL_LEN          32            //�����ַ����ܳ���

#define PU_UPGRADE_FILE_NUM_MAX    4             //�ϴ��ļ������
#define PU_UPGRADE_FILE_LEN_MAX       300              //�ϴ��ļ�·������

#define PU_INVADE_LINE_NUM_MAX     5             //�����������

#define PU_SAVE_FILE_PATH_MAX      128           //�����ļ������·��

#define PU_ALARM_CAMERA_MAX        4             //���澯������ͷ��
#define PU_ALARM_DO_MAX            4             //���澯�������������

#define PU_USER_NAME_LEN           32            //�û�����󳤶�
#define PU_PASSWORD_LEN            (64 + 4)      //������󳤶�

#define PU_CAMERA_NUM_MAX          4             //�����֧�ֵ����ͷ��

#define PU_TRIPWIRE_LEN_NUM_MAX    5             //���߸澯�������
#define PU_IGT_AREA_POINTS_NUM     10            //���򶥵������Ŀ
#define PU_IGT_AREA_NUM            4             //���������Ŀ
#define PU_IGT_LINE_NAME_LEN       (32 + 4)      //���ܰ������Ƴ���
#define PU_IGT_AREA_NAME_LEN       (32 + 4)      //�����������Ƴ���

#define PU_DEVICE_NUM_MAX          1000          //������1000·�豸
#define PU_TRANSPARENT_CMD_MAX     256           //͸��ͨ�������
#define PU_DOMAIN_LEN              256           //������󳤶�
#define PU_IRLIGHT_NUM_MAX         4             //�������֧�ֵĺ���Ƹ���

#define PU_DIO_NAME_LEN            (32 + 4)      //���������Ƴ���
#define PU_DIO_NUM_MAX             4             //����������/���������
#define PU_RECORD_PLAN_NUM         28            //¼��ƻ�����
#define PU_LOG_INFO_LEN            256           //ÿ����־����󳤶�
#define PU_LOG_INFO_NUM            100           //��־��ѯÿ�η��ص���󳤶�
#define PU_NAT_SESSIONID_LEN       32            //NAT��Խ��sessid����
#define PU_NAT_URL_LEN             256           //NAT��Խ�ĻỰURL����
#define PU_RECORD_TYPE_NUM         4             //¼�����͸���
#define PU_RECORD_INFO_NUM_MAX     5             //¼����Ϣ������
#define PU_RECORD_CONTENTID_LEN    40            //¼���ļ�������
#define PU_VIDEO_FORMAT_NUM        4             //��Ƶ�����ʽ����
#define PU_STREAM_NUM              4             //�����������
#define PU_OSD_STRING_LEN          (96 + 4)      //OSD�������ֵ
#define PU_OSD_STRING_NUM          7             //OSD�ַ�������
#define PU_MAC_ADDR_LEN            30            //MAC��ַ����
#define PU_SNAP_IMAGE_NAME_LEN     24            //ץ��ͼƬ�ļ�������
#define PU_MAX_URL_LEN             512           //URL����
#define PU_CONFIG_FILE_PATH_MAX    512           //�����ļ����·��

//�������궨��
#define PU_ROI_AREA_NUM_MAX        8             //ROI���������
#define PU_PORT_MODE_NUM_MAX       16            //���˿�ģʽ
#define PU_BNC_PORT_MAX            32            //���BNC����˿�
#define PU_VGA_PORT_MAX            8             //���VGA����˿�
#define PU_DVI_PORT_MAX            8             //���DVI����˿�
#define PU_HDMI_PORT_MAX           8             //���HDMI����˿�

#define PU_DECODE_TYPE_MAX         4             //������֧�ֵĽ�������
#define PU_PORT_NUM_MAX            32            //���˿���
#define PU_CHANNEL_NUM_MAX         32            //���ͨ����

#define PU_OSD_MAX_LENGTH          (96 + 1)      //������OSD�����ĳ���
#define PU_CRYPTION_PASSWD_LEN     44            //��Կ����

#define PU_DEC_CHANNEL_NAME_LEN    32            //������ͨ�����Ƴ���
#define PU_DECODER_ID_LEN          20            //������ID
#define PU_DECODER_NAME_LEN        32            //������ͨ�����Ƴ���
#define PU_DEC_PAY_LOAD_TYPE_NUM   16            //PayLoadType��������
#define PU_DECODER_ENCODING_LEN    16            //�����������ʽ��󳤶�



/********************************ö������**********************************************/
//ȫ�ִ�����
typedef enum ERROR_CODE
{
    PU_ERROR_CODE_NOERROR = 0,                                      //û�д���

    PU_ERROR_CODE_COMMON_ERROR = 1,                                 //һ�����
    PU_ERROR_CODE_PASSWORD_ERROR = 2,                               //�û������������
    PU_ERROR_CODE_NO_PRIORITY = 3,                                  //û�в���Ȩ��
    PU_ERROR_CODE_NO_INIT = 4,                                      //SDKδ��ʼ��
    PU_ERROR_CODE_HAS_INIT = 5,                                     //SDK�ѳ�ʼ��
    PU_ERROR_CODE_VERSION_NO_MATCH = 6,                             //SDK���豸�汾��ƥ��
    PU_ERROR_CODE_STARTUP_NETWORK_ERROR = 7,                        //������������
    PU_ERROR_CODE_SOCKET_ERROR = 8,                                 //�����׽��ִ���
    PU_ERROR_CODE_CONNECT_ERROR = 9,                                //�������Ӵ���
    PU_ERROR_CODE_SEND_TIMEOUT = 10,                                //������Ϣ��ʱ
    PU_ERROR_CODE_RECV_TIMEOUT = 11,                                //������Ϣ��ʱ
    PU_ERROR_CODE_OPERATION_TIMEOUT = 12,                           //�豸������ʱ
    PU_ERROR_CODE_OUT_OF_MEMORY = 13,                               //�ڴ治�㣬�޷������ڴ�
    PU_ERROR_CODE_SERVER_IS_SHUTDOWN = 14,                          //����˹ر�����
    PU_ERROR_CODE_TOO_MANY_REALPLAY = 15,                           //ʵ��·���������ֵ
    PU_ERROR_CODE_LOG_ERROR = 16,                                   //��־����
    PU_ERROR_CODE_NO_FREE_PORT = 17,                                //û�ж���Ķ˿���Դ
    PU_ERROR_CODE_HAS_REG_EVENT_CALLBACK = 18,                      //�¼��ص�������ע��
    PU_ERROR_CODE_REGISTER_FAIL = 19,                               //ǰ������ע��ƽ̨ʧ��
    PU_ERROR_CODE_REGISTER_REDIRECT = 20,                           //ǰ������ע��ƽ̨�ض���

    //API���ô���
    PU_ERROR_CODE_SDKINIT_LINK_MODE_ERROR = 101,                    //SDK��ʼ������ģʽ����
    PU_ERROR_CODE_SDKINIT_LOCALIP_ERROR = 102,                      //SDK��ʼ������IP����
    PU_ERROR_CODE_SDKLOGIN_PARA_ERROR = 103,                        //��¼��������
    PU_ERROR_CODE_CODE_IS_INVALID = 104,                            //��������Ч
    PU_ERROR_CODE_SDKGETVERSION_PARA_ERROR = 105,                   //��ȡ�汾��������
    PU_ERROR_CODE_IDENTIFYID_ERROR = 106,                           //������û�ID��
    PU_ERROR_CODE_SDKGETDEVICE_PARA_ERROR = 107,                    //��ȡ�豸��������
    PU_ERROR_CODE_ALARMREPORT_CB_IS_NULL = 108,                     //�澯�ϱ��ص�����Ϊ��
    PU_ERROR_CODE_VOICETB_CB_IS_NULL = 109,                         //�����Խ��ص�����Ϊ��
    PU_ERROR_CODE_REALPLAY_CB_IS_NULL = 110,                        //ʵ�����Żص�����Ϊ��
    PU_ERROR_CODE_LOAD_PLAYDLL_ERROR = 111,                         //���ز��ſ����
    PU_ERROR_CODE_CFGFILE_ERROR = 112,                              //�����ļ�����
    PU_ERROR_CODE_UNSUPPORT_ALARM_TYPE = 113,                       //δ֪�澯����
    PU_ERROR_CODE_SDKUPGRADE_PARA_ERROR = 114,                      //������������
    PU_ERROR_CODE_SDKUPGRADE_ERROR = 115,                           //��������
    PU_ERROR_CODE_SDKUPGRADE_FILE_ERROR = 116,                      //�����ļ�����
    PU_ERROR_CODE_UNSUPPORT_PLATFORM_TYPE = 117,                    //δ֪ƽ̨����
    PU_ERROR_CODE_SDKSETPLATFORM_PARA_ERROR = 118,                  //����ƽ̨��������
    PU_ERROR_CODE_UNSUPPORT_ENCODE_TYPE = 119,                      //δ֪����Ƶ��������
    PU_ERROR_CODE_UNSUPPORT_STREAM_TYPE = 120,                      //δ֪��������
    PU_ERROR_CODE_UNSUPPORT_BITRATE_TYPE = 121,                     //δ֪��������
    PU_ERROR_CODE_UNSUPPORT_PTZ_CMD = 122,                          //δ֪��̨����
    PU_ERROR_CODE_CRUISE_PARA_ERROR = 123,                          //Ѳ���켣��������
    PU_ERROR_CODE_ALARM_TMP_PARA_ERROR = 124,                       //�¶ȸ澯��������
    PU_ERROR_CODE_ALARM_MOTION_DETEC_PARA_ERROR = 125,              //�ƶ����澯��������
    PU_ERROR_CODE_ALARM_INPUT_PARA_ERROR = 126,                     //����澯��������
    PU_ERROR_CODE_ALARM_HIDE_PARA_ERROR = 127,                      //�ڵ��澯��������
    PU_ERROR_CODE_ALARM_INVADE_PARA_ERROR = 128,                    //���ּ��澯��������
    PU_ERROR_CODE_ALARM_COUNT_PARA_ERROR = 129,                     //Ŀ������澯��������
    PU_ERROR_CODE_ALARM_DISTURB_PARA_ERROR = 130,                   //���Ÿ澯��������
    PU_ERROR_CODE_PRIVACY_PARA_ERROR = 131,                         //��˽������������
    PU_ERROR_CODE_OSD_PARA_ERROR = 132,                             //OSD��������
    PU_ERROR_CODE_PTZ_PARA_ERROR = 133,                             //��̨���Ʋ�������
    PU_ERROR_CODE_SDKGUARD_PARA_ERROR = 134,                        //��������������
    PU_ERROR_CODE_SDKGETALARAM_PARA_ERROR = 135,                    //��ȡ�澯��������
    PU_ERROR_CODE_PARA_ERROR = 136,                                 //��������
    PU_ERROR_CODE_PLAYER_FUNC_ERROR = 137,                          //���ſ⺯�����ó���
    PU_ERROR_CODE_SDKSAVEREALDATA_ERROR = 138,                      //����ʵ������
    PU_ERROR_CODE_SDKGETGUARDSTATE_PARA_ERROR = 139,                //��ȡ����״̬��������
    PU_ERROR_CODE_MUTUALLYEXCLUSIVE_RELATIONSHIP = 140,             //�򻥳��ϵ�����²������óɹ�
    PU_ERROR_CODE_DEVICE_RELOGIN = 141,                             //�ظ���¼�豸
    PU_ERROR_CODE_INVALID_CONFIG_FILE = 142,                        //�����ļ����Ϸ�

    //������������
    PU_ERROR_CODE_DEC_INITDEC_ERROR = 1001,                         //��ʼ������ʧ��
    PU_ERROR_CODE_DEC_STARTDEC_ERROR = 1002,                        //��ʼ����ʧ��
    PU_ERROR_CODE_DEC_STOPDEC_ERROR = 1003,                         //ֹͣ����ʧ��
    PU_ERROR_CODE_DEC_TOO_MANY_CHANNEL = 1004,                      //̫��Ľ���ͨ��
    PU_ERROR_CODE_DEC_ERROR_PORT_NUM = 1005,                        //�˿�������
    PU_ERROR_CODE_DEC_ERROR_DEC_HANDEL = 1006,                      //����Ľ�����
    PU_ERROR_CODE_DEC_ERROR_UNSUPPORT_DECODE_TYPE = 1007,           //��֧�ֵĽ�������
    PU_ERROR_CODE_DEC_ERROR_INVALID_CHANNEL_ID = 1008,              //��Ч��ͨ����

    //����˴�����
    PU_ERROR_CODE_SERVER_COMMON_ERROR = 10001,                      //һ�����
    PU_ERROR_CODE_SYNTAX_ERROR = 10002,                             //�����﷨����
    PU_ERROR_CODE_UNSUPPORT_ERROR = 10003,                          //��֧�ֵ�����
    PU_ERROR_CODE_PARAMETER_ERROR = 10004,                          //��������
    PU_ERROR_CODE_INVALID_VCU_ID = 10005,                           //�豸ID����
    PU_ERROR_CODE_INVALID_CHANNEL = 10006,                          //ͨ���Ŵ���
    PU_ERROR_CODE_INVALID_SERIAL_NO = 10007,                        //���ںŴ���
    PU_ERROR_CODE_INVALID_ALARM_NO = 10008,                         //�����˿ڴ���
    PU_ERROR_CODE_UNSUPPORTED_MEDIA_TYPE = 10009,                   //��֧�ֵ�ý������
    PU_ERROR_CODE_PARTLY_SUPPORT = 10011,                           //�����ֲ������óɹ�
    PU_ERROR_CODE_TOO_MANY_PLANS = 10012,                           //�ƻ�������������
    PU_ERROR_CODE_NO_DISK = 10013,                                  //�豸��Ӳ��
    PU_ERROR_CODE_OPEN_SOUND_FAIL = 10014,                          //������ʧ��
    PU_ERROR_CODE_VOICE_OPEND = 10015,                              //�����������Խ���ռ��
    PU_ERROR_CODE_DEVICE_BUSY = 10016,                              //�豸æ
    PU_ERROR_CODE_OPERATE_FLASH_ERROR = 10019,                      //FLASH���� 
    PU_ERROR_CODE_UNSUPPORTED_VIDEO_FORMAT = 10020,                 //��֧�ֵ���Ƶ��ʽ
    PU_ERROR_CODE_IP_ADDRESS_CONFLICT = 10022,                      //IP��ַ��ͻ

    PU_ERROR_CODE_INVALID_VERIFICATION = 10102,                     //������û���������
    PU_ERROR_CODE_INVALID_VERSION_FILE = 10103,                     //VERSION�ļ�У��ʧ��
    PU_ERROR_CODE_INVALID_KERNEL_FILE = 10104,                      //�ں������ļ�У��ʧ��
    PU_ERROR_CODE_INVALID_ROOTFS_FILE = 10105,                      //�ļ�ϵͳ�����ļ�У��ʧ��
    PU_ERROR_CODE_FIRST_LOGIN = 10106,                              //��һ�ε�¼
    PU_ERROR_CODE_CLIENT_ALREADY_LOGIN = 10107,                     //���пͻ��˵�¼
    PU_ERROR_CODE_USER_LOCKED = 10108,                              //�û�������
    PU_ERROR_CODE_MANY_USER = 10109,                                //�û�������������
    PU_ERROR_CODE_NOT_NEED_UPDATE = 10113,                          //�汾��һ�£�����Ҫ����
    PU_ERROR_CODE_NOT_SUPPORT_ABILITY = 10114,                      //��֧�ֵ���������
    PU_ERROR_CODE_PRESET_IN_GUARD_POSITION = 10115,                 //Ԥ��λ�ڿ���λ��
    PU_ERROR_CODE_PRESET_IN_CRUISE_TRACK = 10116,                   //Ԥ��λ��Ѳ���켣��
    PU_ERROR_CODE_THE_CRUISE_IS_RUNNING = 10122,                    //Ѳ���켣��������
    PU_ERROR_CODE_UPDATE = 10125,                                   //ϵͳ��������
    PU_ERROR_CODE_REBOOT = 10126,                                   //ϵͳ��������
    PU_ERROR_CODE_RESTORE = 10127,                                  //���ڻָ�Ĭ������
    PU_ERROR_CODE_RECOVER_OPRATE_FORBIDDEN = 10128,                 //�ָ�Ĭ�����ý�ֹ���õȲ���
    PU_ERROR_CODE_ROI_ERROR_BY_MJPEG = 10129,                       //MJPEG������ROI ʧ��
    PU_ERROR_CODE_ROI_ERROR_BY_NOSUBSTREAM = 10130,                 //ֻ��������������������ROIʧ��
    PU_ERROR_CODE_TZ_ERROR_BY_CONFLICT = 10131,                     //���ð��߼��ʹ���г�ͻ
    PU_ERROR_CODE_OC_ERROR_BY_CONFLICT = 10132,                     //����Ŀ�����ʹ���г�ͻ
    PU_ERROR_CODE_MD_ERROR_BY_CONFLICT = 10133,                     //�����ƶ����ʹ���г�ͻ
    PU_ERROR_CODE_TW_ERROR_BY_CONFLICT = 10134,                     //���ð��߼��ʹ���г�ͻ
    PU_ERROR_CODE_AREA_ERROR_BY_CONFLICT = 10135,                   //���������(�ܽ����֡���Ʒ��������Ʒ���ߣ���ʹ���г�ͻ
    PU_ERROR_CODE_VD_ERROR_BY_CONFLICT = 10136,                     //������Ƶ����ʹ���г�ͻ
    PU_ERROR_CODE_IGT_ENABLE_CONFLICT = 10137,                      //���ܿ����Ѵ�  �����ն���ǿʧ��,�����ڵ�ʧ��
    PU_ERROR_CODE_ILLUMINATION_ENABLE_CONFLICT = 10138,             //�նȿ�����ʹ��  �������ܿ���ʧ�ܣ������ڵ�ʧ��
    PU_ERROR_CODE_VIDEOBLOCK_ENABLE_CONFLICT = 10139,               //��Ƶ�ڵ���ʹ�ܣ��������ܿ��ء��ҵ���ǿʧ��
    PU_ERROR_CODE_IGT_FAIL_BY_SWITCHOFF = 10140,                    //���ܿ���δʹ�ܣ���������ҵ��ʧ��
    PU_ERROR_CODE_TW_ERROR_BY_OVER_NUM = 10141,                     //���ð����������������
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_NUM = 10142,                   //��������������������4
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_TOTAL_NUM = 10143,             //����������������������10
    PU_ERROR_CODE_AREA_ERROR_BY_ZERO_NUM = 10144,                   //�����������Ϊ0
    PU_ERROR_CODE_AREA_POINT_ERROR_BY_OVER_NUM = 10145,             //�������򶥵������������
    PU_ERROR_CODE_AREA_ABN_ERROR_BY_CONFLICT = 10146,               //�����������Ʒ���ߣ�����ʹ���ѿ����г�ͻ
    PU_ERROR_CODE_AREA_RMV_ERROR_BY_CONFLICT = 10147,               //�����������Ʒ����������ʹ���ѿ����г�ͻ
    PU_ERROR_CODE_VIM_GLOBAL_PARA_ERROR = 10148,                    //�������ܷ����㷨ȫ�ֲ���ʧ��
    PU_ERROR_CODE_AREA_NOTSURPORT_ERROR = 10149,                    //�������ܷ���������Ч
    PU_ERROR_CODE_PRIVACY_MASK_AREA_BEYOND = 10150,                 //��˽�������򳬳������
    PU_ERROR_CODE_MEDIA_ADAPT_BW_MUTEX = 10151,                     //��������Ӧ��������ͻ����������ͳ�ͻ
    PU_ERROR_CODE_IP_FILTER_RULE_SAME = 10152,                      //������ͬ��IP���˹���

    PU_ERROR_CODE_WD_FRAME_CONFLICT = 10153,                        //��̬�ֶ����Զ����ɼ�֡��������50��60
    PU_ERROR_CODE_FRAME_WD_CONFLICT = 10154,                        //�ɼ�֡Ϊ50��60����̬���������ֶ����Զ�
    PU_ERROR_CODE_CONFLICT_VIDEOBLOCK_OR_IGT_IS_ENABLE = 10155,     //��Ƶ�ڵ�����Ϊ������ʹ��,�����ն���ǿʧ��

    PU_ERROR_CODE_INVALID_UPDATEFILE = 13100,                       //�����ļ��Ƿ�
    PU_ERROR_CODE_UPDATEFILE_BAD = 13101,                           //�ļ���
    PU_ERROR_CODE_INVALID_FILE_FORMAT = 13102,                      //�ļ���ʽ����

    PU_ERROR_CODE_BUSY_CURISE = 13103,                              //����Ѳ�����޷�����Ѳ���켣����
    PU_ERROR_CODE_DEVICE_CLOSE = 13104,                             //�豸δ����
    PU_ERROR_CODE_BUSY_PRESET = 13105,                              //Ԥ��λ��ʹ�ã��޷�ɾ��

    PU_ERROR_CODE_INVALID_IGT_AREA_ID = 13106,                      //���ܷ������򲻴���
    PU_ERROR_CODE_INVALID_IGT_LINE_ID = 13107,                      //���ܷ�������������
    PU_ERROR_CODE_INVALID_PRIVACY_ID = 13108,                       //��˽�������򲻴���

    PU_ERROR_MAX = 20000
}PU_ERROR_CODE_E;

//ǰ��ע��ģʽ
typedef enum PU_LINK_MODE                          
{
    PU_AUTOLOGIN_MODE = 0,                                          //������½ģʽ����ʼ����ǰ���豸������¼��SDK����������֧��
    PU_MANUALLOGIN_MODE = 1,                                        //�ֶ���½ģʽ�����ֶ�����IVS_PU_Login��¼ǰ���豸
    PU_BOTHLOGIN_MODE = 3,                                          //�������ֵ�½ģʽ��֧�֣���IPC֧��

    PU_LINK_MODE_MAX
}PU_LINK_MODE_E;

//device event callback type
typedef enum PU_EVENT_TYPE
{
    /* ����״̬�ص� */
    PU_EVENT_TYPE_CONNCET = 1,                                      //ǰ���������ӣ�����������
    PU_EVENT_TYPE_REGISTER,                                         //ǰ������ע��
    PU_EVENT_TYPE_NOT_REGISTER,                                     //ǰ���������Ӻ�δע��
    PU_EVENT_TYPE_UNREGISTER,                                       //ǰ������ע��
    PU_EVENT_TYPE_DISCONNECT,                                       //ǰ���������ӶϿ�
    PU_EVENT_TYPE_SEND_RECV_ERROR,                                  //���ͻ����ʧ��
    PU_EVENT_TYPE_KEEPLIVE_FAIL,                                    //ǰ�˱���ʧ��

    /* �¼�֪ͨ�ص� */
    PU_EVENT_TYPE_STREAM_PACKAGE_CHANGE,                            //���ײͱ��
    PU_EVENT_TYPE_WATERMARK_ERR,                                    //����ˮӡУ�����
    PU_EVENT_TYPE_UPLOAD_IMAGE_URL,                                 //ǰ��������ȡץ��ͼƬ�ϴ�URL����
    PU_EVENT_TYPE_UPLOAD_IMAGE_COMP_NOTIFY,                         //ǰ��ץ��ͼƬ�������֪ͨ
    PU_EVENT_TYPE_TRANSPARENT_CHANNEL_NOTIFY,                       //͸��ͨ�������ϱ�
    PU_EVENT_TYPE_REALPALY_ERROR,                                   //ʵ���쳣

    PU_EVENT_TYPE_MAX
}PU_EVENT_TYPE_E;

//����Ƶ��������
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

//��Ƶ�ֱ�������
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

//��Ƶ��ģʽ
typedef enum PU_STREAM_MODE_E
{
    PU_VIEDO_STREAM_NONE   = 0,             //���������ײ�
    PU_VIEDO_STREAM_SINGLE = 1,             //��Ƶ����
    PU_VIEDO_STREAM_DOUBLE = 2,             //��Ƶ˫��
    PU_VIEDO_STREAM_TRIPLE = 3,             //��Ƶ����
    PU_VIEDO_STREAM_FOUR   = 4,             //��Ƶ����
    PU_VIEDO_STREAM_MAX
}PU_STREAM_MODE_E;

//��Ƶ������
typedef enum PU_STREAM_TYPE
{
    PU_VIDEO_MAIN_STREAM = 0,                //��Ƶ������
    PU_VIDEO_SUB_STREAM1,                    //��Ƶ������1
    PU_VIDEO_SUB_STREAM2,                    //��Ƶ������2
    PU_VIDEO_SUB_STREAM3,                    //��Ƶ������3
    PU_VIDEO_STREAM_MAX
}PU_STREAM_TYPE_E;

//ͼ������
typedef enum PU_PIC_QUALITY                                          
{
    PU_PIC_QUALITY_BEST = 0,                //���
    PU_PIC_QUALITY_MORE_BETTER,             //�κ�
    PU_PIC_QUALITY_BETTER,                  //�Ϻ�
    PU_PIC_QUALITY_ORDINARY,                //һ��
    PU_PIC_QUALITY_BAD,                     //�ϲ�
    PU_PIC_QUALITY_BADEST,                  //��
    PU_PIC_QUALITY_MAX
}PU_PIC_QUALITY_E;

//��������
typedef enum PU_PROTOCOL_TYPE
{
    PU_PROTOCOL_TYPE_UDP = 0,                  //UDP��ʽ
    PU_PROTOCOL_TYPE_TCP,                      //TCP��ʽ
    PU_PROTOCOL_TYPE_MULTICAST,                //�鲥��ʽ
    PU_PROTOCOL_TYPE_MAX
}PU_PROTOCOL_TYPE_E;

//ý��ص�����
typedef enum PU_MEDIA_CALLBACK_TYPE
{
    PU_MEDIA_CALLBACK_TYPE_RTP = 0,         //RTP����ʽ
    PU_MEDIA_CALLBACK_TYPE_RTP_CRYPTO,      //RTP����ʽ��������
    PU_MEDIA_CALLBACK_TYPE_FRAME,           //֡�ص���ʽ
    PU_MEDIA_CALLBACK_TYPE_YUV,             //YUV��ʽ��Linux��֧��
    PU_MEDIA_CALLBACK_TYPE_MAX
}PU_MEDIA_CALLBACK_TYPE_E;

//������
typedef enum PU_VIDEO_TYPE
{
    PU_VIDEO_TYPE_VIDEO = 0,                    //��Ƶ��
    PU_VIDEO_TYPE_AUDIO,                        //��Ƶ��
    PU_VIDEO_TYPE_MUX,                          //������
    PU_VIDEO_TYPE_RECORD,                       //¼����
    PU_VIDEO_TYPE_MAX
}PU_VIDEO_TYPE_E;

//ý���������
typedef enum PU_MEDIA_CRYPTO_TYPE
{
    PU_MEDIA_CRYPTO_NONE = 0,               //������
    PU_MEDIA_CRYPTO_HW_SIMPLE = 1,          //��Ϊ����
    PU_MEDIA_CRYPTO_AES_128BIT = 2,         //128λAES����
    PU_MEDIA_CRYPTO_AES_192BIT = 3,         //192λAES����
    PU_MEDIA_CRYPTO_AES_256BIT = 4,         //256λAES����
    PU_MEDIA_CRYPTO_MAX,
}PU_MEDIA_CRYPTO_TYPE_E;

//��������
typedef enum PU_BIT_RATE_TYPE
{
    PU_BIT_RATE_TYPE_FIXED = 0,             //������
    PU_BIT_RATE_TYPE_VARIABLE,              //������
    PU_BIT_RATE_TYPE_QP,                    //MJPEG����
    PU_BIT_RATE_TYPE_MAX
}PU_BITRATE_TYPE_E;

//��Ƶ��ʽ
typedef enum PU_VIDEO_FORMAT
{
    PU_VIDEO_FORMAT_PAL = 0,                //P��
    PU_VIDEO_FORMAT_NTSC,                   //N��
    PU_VIDEO_FORMAT_MAX
}PU_VIDEO_FORMAT_E;

/*֡��������������*/
typedef enum PU_H264_RC_PRI
{
    PU_H264_RC_FRAMERATE_PRI = 1,           //֡������
    PU_H264_RC_BITRATE_PRI,                 //��������

    PU_H264_RC_PRI_MAX
}PU_H264_RC_PRI_E;

//��������
typedef enum PU_LANGUAGE_TYPE
{
    PU_LANGUAGE_TYPE_CHINESE = 0,              //����
    PU_LANGUAGE_TYPE_ENGLISH,                  //Ӣ��
    PU_LANGUAGE_TYPE_MAX
}PU_LANGUAGE_TYPE_E;

//���ر���¼��ʽ
typedef enum PU_SAVE_REALDATA_TYPE
{
    PU_SAVE_REALDATA_TYPE_TIME = 0,         //��ʱ�䱣��(��λ��min)
    PU_SAVE_REALDATA_TYPE_SIZE = 1,         //����С����(��λ��MBytes)
    PU_SAVE_REALDATA_TYPE_MAX
}PU_SAVE_REALDATA_TYPE_E;

//���ر���ͼƬ��ʽ
typedef enum PU_SAVE_PICTURE_TYPE
{
    PU_SAVE_PICTURE_TYPE_BMP = 0,              //BMP�ļ�
    PU_SAVE_PICTURE_TYPE_JEPG = 1,             //JPEG�ļ�
    PU_SAVE_PICTURE_TYPE_MAX
}PU_SAVE_PICTURE_TYPE_E;

//��������
typedef enum PU_SERIAL_PORT_MODE
{
    PU_SERIAL_PORT_RS232 = 0,                  //232����
    PU_SERIAL_PORT_RS422,                      //422����
    PU_SERIAL_PORT_RS485,                      //485����
    PU_SERIAL_PORT_MAX
}PU_SERIAL_PORT_MODE_E;

//������
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

//����λ
typedef enum PU_DATA_BIT
{
    PU_DATA_BIT_CS5 = 0,
    PU_DATA_BIT_CS6,
    PU_DATA_BIT_CS7,
    PU_DATA_BIT_CS8,
    PU_DATA_BIT_MAX
}PU_DATA_BIT_E;

//У��λ
typedef enum PU_PARITY_BIT
{
    PU_PARITY_BIT_NONE = 0,
    PU_PARITY_BIT_ODD,
    PU_PARITY_BIT_EVEN,
    PU_PARITY_BIT_MARK,
    PU_PARITY_BIT_SPACE,
    PU_PARITY_BIT_MAX
}PU_PARITY_BIT_E;

//ֹͣλ
typedef enum PU_STOP_BIT
{
    PU_STOP_BIT_OFF = 0,
    PU_STOP_BIT_ON,
    PU_STOP_BIT_MAX
}PU_STOP_BIT_E; 

//��������������
typedef enum PU_FLOW_CONTROL
{
    PU_FLOW_CONTROL_NONE = 0,
    PU_FLOW_CONTROL_SOFT,
    PU_FLOW_CONTROL_HARD,
    PU_FLOW_CONTROL_MAX
}PU_FLOW_CONTROL_E;

//��̨����������
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

//���������
typedef enum PU_PTZ_CONTROL_MODE
{
    PU_PTZ_CONTROL_MODE_FORWARD = 1,
    PU_PTZ_CONTROL_MODE_BACK,
    PU_PTZ_CONTROL_MODE_MAX
}PU_PTZ_CONTROL_MODE_E;

//�澯����
typedef enum PU_ALARM_ACTION
{
    PU_ALARM_ACTION_MOVE = 1,                  //�澯�Ƴ�
    PU_ALARM_ACTION_HAPPEN,                    //�澯����
    PU_ALARM_ACTION_MAX
}PU_ALARM_ACTION_E;

// ��̨����
typedef enum PU_PTZ_OPCODE
{
    PU_PTZ_STOP = 1,                            //��ֹ̨ͣ,����para1��para2
    PU_PTZ_UP = 2,                              //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_DOWN = 3,                            //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_LEFT = 4,                            //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_UP_LEFT = 5,                         //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_DOWN_LEFT = 6,                       //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_RIGHT = 7,                           //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_UP_RIGHT = 8,                        //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_DOWN_RIGHT = 9,                      //��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_AUTO = 10,                           //��̨�Զ�,����para1��para2
    PU_PTZ_PRESET_RUN = 11,                     //Ԥ��λ����,para1����Ԥ��λ���,����para2
    PU_PTZ_CRUISE_RUN = 12,                     //Ѳ���켣����,para1����Ѳ���켣���,����para2
    PU_PTZ_CRUISE_STOP = 13,                    //Ѳ���켣ֹͣ,����para1��para2
    PU_PTZ_FLIP = 17,                           //��̨��ת180��,����para1��para2
    PU_PTZ_HOMING = 18,                         //��̨��λ,����para1��para2

    // ��ͷ����
    PU_PTZ_LENS_APERTURE_OPEN = 19,             //��Ȧ�Ŵ�,para1�̶�Ϊ����ģʽ(2),para2�����ٶ�
    PU_PTZ_LENS_APERTURE_CLOSE = 20,            //��Ȧ��С,para1�̶�Ϊ����ģʽ(2),para2�����ٶ�
    PU_PTZ_LENS_ZOOM_IN = 21,                   //��Χ�Ŵ�,para1�̶�Ϊ����ģʽ(2),para2�����ٶ�
    PU_PTZ_LENS_ZOOM_OUT = 22,                  //��Χ��С,para1�̶�Ϊ����ģʽ(2),para2�����ٶ�
    PU_PTZ_LENS_ZOOM_STOP = 23,                 //���Źر�
    PU_PTZ_LENS_FOCAL_NEAR = 24,                //�۽���,para1�̶�Ϊ����ģʽ(2),para2�����ٶȣ���Χ1-10��
    PU_PTZ_LENS_FOCAL_FAR = 25,                 //�۽�Զ,para1�̶�Ϊ����ģʽ(2),para2�����ٶȣ���Χ1-10��
    PU_PTZ_LENS_FOCAL_STOP = 26,                //�۽��ر�
    PU_PTZ_AUX_OPEN = 27,                       //�����豸��,para1�����豸����,,����para2
    PU_PTZ_AUX_STOP = 28,                       //�����豸�ر�,para1�����豸����,����para2

    PU_PTZ_HORIZONTAL_SCAN = 29,                //ˮƽɨ��,para1�̶�Ϊ����ģʽ,para2�����ٶȣ���Χ1-10��
    PU_PTZ_VERTICAL_SCAN = 30,                  //��ֱɨ��,para1�̶�Ϊ����ģʽ,para2�����ٶȣ���Χ1-10��

    PU_PTZ_MODE_SET_START =31,                  //�����켣��¼��ʼ
    PU_PTZ_MODE_SET_STOP =32,                   //�����켣��¼ֹͣ
    PU_PTZ_FAST_LOCATE =33,                     //3d��λ
    PU_PTZ_FAST_RETURN =34,                     //3d����
    PU_PTZ_REBOOT = 35,                         //���������
    PU_PTZ_RESTORE = 36,                        //�����ָ�Ĭ������
    PU_PTZ_SET_LEFT_LIMIT = 37,                 //��������λ
    PU_PTZ_SET_RIGHT_LIMIT = 38,                //��������λ
    PU_PTZ_MODE_CRUISE_START =39,               //�����켣��ʼ para1����Ѳ���켣���,����para2
    PU_PTZ_MODE_CRUISE_STOP =40,                //�����켣ֹͣpara1����Ѳ���켣���,����para2
    PU_PTZ_FAST_MOVE =41,                       //��ѡ���ٶ�λ.para1��ʾx���ꡢpara2��ʾy����

    PU_PTZ_CMD_MAX
}PU_PTZ_OPCODE_E;
                                            
//��̨�˶�ģʽ
typedef enum PU_PTZ_MOTION_MODE
{
    PU_PTZ_MOTION_MODE_BURST = 1,               //�㶯ģʽ
    PU_PTZ_MOTION_MODE_CONTINUOUS,              //����ģʽ

    PU_PTZ_MOTION_MODE_MAX
}PU_PTZ_MOTION_MODE_E;

//��̨Ԥ��λ����������
typedef enum PU_PTZ_PRESET_CMD
{
    PU_PTZ_PRESET_SET = 1,                      //����Ԥ��λ
    PU_PTZ_PRESET_GET,                          //��ȡԤ��λ
    PU_PTZ_PRESET_CLR,                          //���Ԥ��λ
    PU_PTZ_PRESET_GOTO,                         //ת��Ԥ��λ
    PU_PTZ_PRESET_MAX
}PU_PTZ_PRESET_CMD_E;

//Ѳ���켣����������
typedef enum PU_PTZ_CRUISE_TRACK
{
    PU_PTZ_CRUISE_TRACK_SET = 1,                //����Ѳ���켣
    PU_PTZ_CRUISE_TRACK_GET,                    //��ȡѲ���켣
    PU_PTZ_CRUISE_TRACK_CLR,                    //���Ѳ���켣
    PU_PTZ_CRUISE_TRACK_GOTO,                   //��̨Ѳ��
    PU_PTZ_CRUISE_TRACK_STOP,                   //ֹͣѲ��
    PU_PTZ_CRUISE_TRACK_MAX
}PU_PTZ_CRUISE_TRACK_E;

typedef enum PU_OSD_DATE_TYPE
{
    PU_YYYY_MM_DD = 0,                          //YYYY-MM-DD
    PU_MM_DD_YYYY,                              //MM-DD-YYYY
    PU_YYYY_MM_DD_CH,                           //��-��-��
    PU_MM_DD_YYYY_CH,                           //��-��-��
    PU_DD_MM_YYYY,                              //DD-MM-YYYY

    PU_OSD_DATA_TYPE_MAX
}PU_OSD_DATE_TYPE_E;

//�澯����
typedef enum PU_ALARM_TYPE
{
    PU_ALARM_TYPE_DI = 1,                       //����������
    PU_ALARM_TYPE_DISK_FULL,                    //Ӳ�����澯
    PU_ALARM_TYPE_NO_SIGNAL,                    //����Ƶ�澯����Ƶ��ʧ��
    PU_ALARM_TYPE_MOVE_DECTION,                 //�ƶ����澯
    PU_ALARM_TYPE_DISK_FAULT,                   //Ӳ�̹���
    PU_ALARM_TYPE_SHIELD,                       //�ڵ��澯�����������ڵ��澯
    PU_ALARM_TYPE_NETWORK_INTERRUPT,            //�����ж�
    PU_ALARM_TYPE_IP_ADDRESS_CONFLICT,          //IP��ͻ
    PU_ALARM_TYPE_TEMPERATURE,                  //�¶ȸ澯
    PU_ALARM_TYPE_FACE_DETECTION,               //�������
    PU_ALARM_TYPE_INVADE,                       //
    PU_ALARM_TYPE_COUNT,                        //Ŀ�����
    PU_ALARM_TYPE_DISTURB,                      //���ż��

    /* ���ܸ澯 */
    PU_ALARM_TYPE_TRIPWIRE = 14,                //���߼��
    PU_ALARM_TYPE_INTRUSION = 15,               //���ּ��
    PU_ALARM_TYPE_HOVER = 16,                   //�ǻ����
    PU_ALARM_TYPE_LEGACY = 17,                  //�����������
    PU_ALARM_TYPE_REMOVE = 18,                  //���嶪ʧ���

    PU_ALARM_TYPE_MAX                           //Ԥ��
}PU_ALARM_TYPE_E;

//ƽ̨����(ƽ̨����)
typedef enum PU_PLATFORM_TYPE
{
    PU_PLATFORM_TYPE_NVS = 1,                   //NVSƽ̨
    PU_PLATFORM_TYPE_IVS = 2,                   //IVSƽ̨
    PU_PLATFORM_TYPE_GBT,                       //28281ƽ̨
    PU_PLATFORM_TYPE_IVS_ENABLE,                //IVSƽ̨����ʹ��
    PU_PLATFORM_TYPE_GBT_ENABLE,                //28281ƽ̨����ʹ��
    PU_PLATFORM_TYPE_SDK_ENABLE,                //SDKƽ̨��������ʹ��
    PU_PLATFORM_TYPE_OTHERS,
    PU_PLATFORM_TYPE_MAX
}PU_PLATFORM_TYPE_E;

typedef enum PU_SDK_PLATFORM_MODE_E
{
    PU_SDK_PALTFORM_MODE_SINGEL = 1,           //��������ģʽ
    PU_SDK_PLATFORM_MODE_DUAL,                 //˫������ģʽ
    PU_SDK_PLATFORM_MODE_MAX
}PU_SDK_PLATFORM_MODE_E;

//��־����
typedef enum PU_LOG_TYPE
{
    PU_LOG_TYPE_OPERATION = 1,                  //������־
    PU_LOG_TYPE_EXCEPT,                         //�쳣��־
    PU_LOG_TYPE_ALARM,                          //�澯��־
    PU_LOG_TYPE_MAX
}PU_LOG_TYPE_E;

//���������Ͷ���

//�ֱ���ģʽ
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

//�˿�����
typedef enum PU_PORT_TYPE
{
    PU_PORT_TYPE_HDMI = 0,
    PU_PORT_TYPE_VGA = 1,
    PU_PORT_TYPE_BNC = 2,
    PU_PORT_TYPE_DVI = 3,

    PU_PORT_TYPE_MAX
}PU_PORT_TYPE_E;

//�˿�ģʽ
typedef enum PU_PORT_MODE
{
    PU_PORT_MODE_1 = 1,                        //1����
    PU_PORT_MODE_2 = 2,                        //2����
    PU_PORT_MODE_4 = 4,                        //4����
    PU_PORT_MODE_9 = 9,                        //9����
    PU_PORT_MODE_16 = 16,                      //16����

    PU_PORT_MODE_MAX
}PU_PORT_MODE_E;

//֡��
typedef enum PU_FRAME_RATE
{
    PU_FRAME_RATE_30 = 0,
    PU_FRAME_RATE_50,
    PU_FRAME_RATE_60
}PU_FRAME_RATE_E;

//������������
typedef enum PU_ENCRYPT_TYPE
{
    PU_ENCRYPT_TYPE_HUAWEI_VIDEO = 0,          //ʵ�л�Ϊ���������㷨,������Ƶ
    PU_ENCRYPT_TYPE_HUAWEI_AUDIO,              //ʵ�л�Ϊ���������㷨,������Ƶ
    PU_ENCRYPT_TYPE_HUAWEI_MUX,                //ʵ�л�Ϊ���������㷨,���ܸ�����
    PU_ENCRYPT_TYPE_NONE,                      //��ʵ����������
    PU_ENCRYPT_TYPE_MAX
}PU_ENCRYPT_TYPE_E;

//��Ƶ�˿�����
typedef enum PU_AUDIO_PORT_TYPE
{
    PU_AUDIO_PORT_TYPE_BNC_PLAY = 0,           //BNC�����˿�
    PU_AUDIO_PORT_TYPE_HDMI_PLAY = 1,          //HDMI�����˿�

    PU_AUDIO_PORT_TYPE_MAX
}PU_AUDIO_PORT_TYPE_E;

//��Ƶ������
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

//G726�����ʽ������
typedef enum PU_AUDIO_G726_BPS
{
    PU_AUDIO_G726_16K = 0,                  /* G726 16kbps, */ 
    PU_AUDIO_G726_24K,                      /* G726 24kbps, */
    PU_AUDIO_G726_32K,                      /* G726 32kbps, */
    PU_AUDIO_G726_40K,                      /* G726 40kbps, */
    PU_AUDIO_G726_MAX,
}PU_AUDIO_G726_BPS_E;

/* ��Ƶ��ҹģʽ  */
typedef enum PU_VIDEO_DAYNIGHT_MODE
{
    PU_VIDEO_DAYNIGHT_MODE_AUTO = 0,           //�Զ�ģʽ
    PU_VIDEO_DAYNIGHT_MODE_COLOR,              //��ɫģʽ
    PU_VIDEO_DAYNIGHT_MODE_GRAY,               //�ڰ�ģʽ
    PU_VIDEO_DAYNIGHT_MODE_MAX
}PU_VIDEO_DAYNIGHT_MODE_E;

/* ͼ�������ת��ʽ */
typedef enum PU_VIDEO_MIRROR_MODE
{
    PU_VIDEO_MIRROR_MODE_NORMAL = 0,           //����ͼ��
    PU_VIDEO_MIRROR_MODE_MIRROR,               //���Ҿ���
    PU_VIDEO_MIRROR_MODE_FLIP,                 //����
    PU_VIDEO_MIRROR_MODE_BOTH,                 //��������
    PU_VIDEO_MIRROR_MODE_MAX
}PU_VIDEO_MIRROR_MODE_E;

/* ����Ƶ��  */
typedef enum PU_VIDEO_FLICKER_MODE
{
    PU_VIDEO_FLICKER_NONE = 0,                 //�ر�
    PU_VIDEO_FLICKER_50HZ,                     //50HZ
    PU_IDEO_FLICKER_60HZ,                      //60HZ

    PU_VIDEO_FLICKER_MAX
}PU_VIDEO_FLICKER_MODE_E;

/* ���ģʽ */
typedef enum PU_VIDEO_AEMETERING_MODE
{
    PU_VIDEO_AEMETERING_CENTER = 0,            //���Ĳ��
    PU_VIDEO_AEMETERING_SPOT,                  //���ĵ���
    PU_VIDEO_AEMETERING_AVERAGE,               //ƽ�����
    PU_VIDEO_AEMETERING_BACKLIGHT,             //������

    PU_VIDEO_AEMETERING_MAX
}PU_VIDEO_AEMETERING_MODE_E;

/* AE�ع�ģʽ */
typedef enum PU_AE_MODE
{
    PU_AE_MODE_AUTO = 0,                       //�Զ��ع⣬�Զ���Ȧ���桢�̶��Ŀ���ֵ
    PU_AE_MODE_MANUAL,                         //�ֶ��ع�
    PU_AE_MODE_SHUTTER_PRI,                    //��������
    PU_AE_MODE_IRIS_PRI,                       //��Ȧ����
    PU_AE_MODE_LOW_NOISE,                      //��������
    PU_AE_MODE_FRAME_RATE,                     //֡������
    PU_AE_MODE_BRIGHT,                         //��������

    PU_AE_MODE_MAX
}PU_AE_MODE_E;

//��̬ģʽ
typedef enum PU_WDR_SWITCH_MODE
{
    PU_WDR_SWITCH_AUTO,                     //�Զ�ģʽ
    PU_WDR_SWITCH_CLOSE,                    //�ر�
    PU_WDR_SWITCH_MANUAL,                   //�ֶ�ģʽ
    PU_WDR_SWITCH_MAX,
}PU_WDR_SWITCH_MODE_E;

/*ץ������*/
typedef enum PU_SNAPSHOT_TYPE
{
    PU_SNAPSHOT_TYPE_MANUAL = 0,               //�ֶ�ץ��
    PU_SNAPSHOT_TYPE_ALARM,                    //�澯ץ��
    PU_SNAPSHOT_TYPE_TIMER,                    //��ʱץ��
    PU_SNAPSHOT_TYPE_MANUAL_EX,                //
    PU_SNAPSHOT_TYPE_MAX
}PU_SNAPSHOT_TYPE_E;

//ҵ������
typedef enum PU_BUSINESS_TYPE
{
    PU_BUSINESS_REAL_VIDEO = 0,                //ʵʱ���
    PU_BUSINESS_AUDIO_TALK,                    //�����Խ�
    PU_BUSINESS_AUDIO_BROADCAST,               //�����㲥
    PU_BUSINESS_RECORD_DOWNLOAD,               //¼������
    PU_BUSINESS_RECORD_PLAY_BACK,              //¼��ط�

    PU_BUSINESS_TYPE_MAX
}PU_BUSINESS_TYPE_E;

//��Ƶ���Ĵ�������
typedef enum PU_VIDEO_CODE_TYPE
{
    PU_VIDEO_CODE_TYPE_ES,                     //ES��
    PU_VIDEO_CODE_TYPE_PS,                     //PS��
    PU_VIDEO_CODE_TYPE_TS,                     //TS��
    PU_VIDEO_CODE_TYPE_MAX
}PU_VIDEO_CODE_TYPE_E;

typedef enum PU_RECORD_TYPE
{
    PU_RECORD_TYPE_ALARM = 0,               //�澯¼��
    PU_RECORD_TYPE_MANUAL,                  //�ֶ�¼��
    PU_RECORD_TYPE_TIMING,                  //�ƻ�¼��
    PU_RECORD_TYPE_MAX,
}PU_RECORD_TYPE_E;

/* Ӳ������ */
typedef enum PU_DISK_TYPE
{
    PU_DISK_TYPE_IDE = 0,
    PU_DISK_TYPE_SATA,
    PU_DISK_TYPE_FLASH,

    PU_DISK_TYPE_UNKNOWN
}PU_DISK_TYPE_E;

typedef enum PU_FEC_PACKET_LOSS_RATIO
{
    PU_FEC_PACKET_LOSS_RATIO_1 = 0,                  /**<  0: 1%����  */
    PU_FEC_PACKET_LOSS_RATIO_2 = 1,                  /**<  1: 2%����  */
    PU_FEC_PACKET_LOSS_RATIO_3 = 2,                  /**<  2: 3%����  */
    PU_FEC_PACKET_LOSS_RATIO_4 = 3,                  /**<  3: 4%����  */
    PU_FEC_PACKET_LOSS_RATIO_5 = 4,                  /**<  4: 5%����  */
    PU_FEC_PACKET_LOSS_RATIO_MAX
} PU_FEC_PACKET_LOSS_RATIO_E;

//��ɫ
typedef enum PU_COLOR_TYPE
{
    PU_COLOR_BLACK = 0,
    PU_COLOR_WHITE,
    PU_COLOR_MAX
}PU_COLOR_TYPE_E;

//͸����
typedef enum PU_ALPHA_TYPE
{
    PU_ALPHA_NONE = 0,
    PU_ALPHA_HALF,
    PU_ALPHA_ALL,
    PU_ALPHA_MAX
}PU_ALPHA_TYPE_E;

typedef enum PU_DSCP_TYPE
{
    PU_DSCP_TYPE_MEDIA = 0,                 //ý��DSCPֵ ������Ƶ����Ƶ
    PU_DSCP_TYPE_CMD,                       //����DSCPֵ �����澯
    PU_DSCP_TYPE_MAX
}PU_DSCP_TYPE_E;

/*��������������*/
typedef enum PU_IGT_AREA_ALARM_TYPE
{
    PU_IGT_TYPE_INTRUSION  = 0,             //���ּ��
    PU_IGT_TYPE_HOVER,                      //�ǻ����
    PU_IGT_TYPE_LEGACY,                     //�������
    PU_IGT_TYPE_REMOVE,                     //���߼��
    PU_IGT_TYPE_MAX
}PU_IGT_AREA_ALARM_TYPE_E;  

/* ���ܳ���ʹ�� */
typedef enum PU_IGT_FIELD_TYPE
{
    PU_IGT_FIELD_LONGSHOT = 0,              //Զ��
    PU_IGT_FIELD_CLOSESHOT = 1,             //����
    PU_IGT_FIELD_MAX
}PU_IGT_FIELD_TYPE_E;

/* ǰ��Ŀ��ߴ����� */
typedef enum PU_IGT_MINTARGET_SIZE
{
    PU_IGT_TARGETSIZE_SMALL = 0,            //СĿ��
    PU_IGT_TARGETSIZE_MIDDLE = 1,           //��Ŀ��
    PU_IGT_TARGETSIZE_BIG = 2,              //��Ŀ��
    PU_IGT_TARGETSIZE_MAX
}PU_IGT_MINTARGET_SIZE_E;

/* ȥ��Ӱģʽ */
typedef enum PU_IGT_SHADOW_MODE
{
    PU_IGT_SHADOW_WEAK = 0,                 //����Ӱ
    PU_IGT_SHADOW_COMMON = 1,               //��ͨ��Ӱ
    PU_IGT_SHADOW_STRONG = 2,               //ǿ��Ӱ
    PU_IGT_SHADOW_MAX
}PU_IGT_SHADOW_MODE_E;

/* ���������� */
typedef enum PU_IGT_DETECT_SENS
{
    PU_IGT_SENS_LOW = 0,                    //��������
    PU_IGT_SENS_MIDDLE = 1,                 //��������
    PU_IGT_SENS_HIGH = 2,                   //��������
    PU_IGT_SENS_MAX
}PU_IGT_DETECT_SENS_E;

/* ����Ŀ��ʶ��ģʽ */
typedef enum PU_IGT_TARGET_MODE
{
    PU_IGT_TARGETMODE_CENTRE = 0,           //����
    PU_IGT_TARGETMODE_BOTTOM = 1,           //�ײ�
    PU_IGT_TARGETMODE_TOP = 2,              //����
    PU_IGT_TARGETMODE_MAX
}PU_IGT_TARGET_MODE_E;

typedef enum PU_IRLIGHT_MODE
{
    PU_IRLIGHT_MODE_ATUO = 0,               //�Զ�
    PU_IRLIGHT_MODE_MANUAL,                 //�ֶ�

    PU_IRLIGHT_MODE_MAX
}PU_IRLIGHT_MODE_E;

typedef enum PU_IGT_OPT_TYPE
{
    PU_IGT_OPT_TYPE_ADD = 0,                //��������Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��������Ϣ
    PU_IGT_OPT_TYPE_MOD = 1,                //�޸ģ���Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��������Ϣ
    PU_IGT_OPT_TYPE_DEL = 2,                //ɾ����ֻ��Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��channelid��index
    PU_IGT_OPT_TYPE_MOV = 3,                /*�ƶ�����Ӱ��߻�����ʱ����ͼ��ֻ��Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��channelid��index��*/
                                            /*������߻�������Ϣͬʱ����Ϊ���δ�����*/
    PU_IGT_OPT_TYPE_MAX
}PU_IGT_OPT_TYPE_E;

/********************************�ṹ��**********************************************/
//�豸�汾
typedef struct PU_DEVICE_VERSION
{
    CHAR szVerSoftware[PU_VERSION_LEN];        //����汾        
    CHAR szVerUboot[PU_VERSION_LEN];           //UBoot�汾
    CHAR szVerKernel[PU_VERSION_LEN];          //�ں˰汾
    CHAR szVerHardware[PU_VERSION_LEN];        //Ӳ���汾
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_VERSION, *LPPU_DEVICE_VERSION;

//�豸��Ϣ�ṹ
typedef struct PU_DEVICE_INFO
{
    CHAR szDeviceName[PU_DEVICE_NAME_LEN];    //�豸�����32λ
    CHAR szDeviceFac[PU_FAC_NAME_LEN];        //�豸����
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];    //�豸�ͺ�,ֻ�ɲ�ѯ��������
    CHAR szSerialNumber[PU_SERIAL_LEN];       //Ӳ�����к�
    PU_DEVICE_VERSION stDeviceVersion;        //�豸�汾
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICEINFO_S, *LPPU_DEVICEINFO_S;

//��Ƶ�����ṹ
typedef struct PU_VIDEO_ATTRIBUTE
{
    ULONG    ulBitRate;                        //����
    ULONG    ulIFrameInterval;                 //I֡���
    ULONG    ulFrameRate;                      //֡��
    PU_ENCODE_TYPE_E enVideoEncodeMode;        //��Ƶ��������
    PU_RESOLUTION_TYPE_E  enResolution;        //�ֱ���
    PU_BITRATE_TYPE_E     enBitRateType;       //��������
    PU_PIC_QUALITY_E      enPicQuality;        //ͼ������
    PU_VIDEO_FORMAT_E     enVideoFormat;       //ͼ����ʽ
    PU_H264_RC_PRI_E      enRcPriMode;         //֡��������������ģʽ,��H264����Ч
    PU_VIDEO_MIRROR_MODE_E enMirrorMode;       //����ģʽ
    CHAR  szReserve[PU_RESERVE_LEN];           //Ԥ��
}PU_VIDEO_ATTRIBUTE_S, *LPPU_VIDEO_ATTRIBUTE_S;

//��Ƶ����Ϣ�ṹ
typedef struct PU_STREAM_ATTRIBUTE
{
    PU_STREAM_TYPE_E enStreamId;                                    //��������
    PU_VIDEO_ATTRIBUTE_S stVideoAttribute;                          //��Ƶ������
}PU_STREAM_ATTRIBUTE_S, *LPPU_STREAM_ATTRIBUTE_S;

//��Ƶ����Ϣ
typedef struct PU_VIDEO_STREAM_INFO
{
    ULONG ulChannelId;                                              //ͨ��ID
    PU_STREAM_MODE_E enStreamMode;                                  //��Ƶ������
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_VIEDO_STREAM_TRIPLE];//��Ƶ����
    CHAR szReserved[PU_RESERVE_LEN];
}PU_VIDEO_STREAM_INFO_S, *LPPU_VIDEO_STREAM_INFO_S;

//��Ƶ����Ϣ
typedef struct PU_AUDIO_INFO
{
    ULONG ulAudioChannelId;                                         //��Ƶͨ��ID
    PU_ENCODE_TYPE_E enAudioEncodeMode;                             //��Ƶ��������
    ULONG ulInputVolume;                                            //��������
    ULONG ulOutputVolume;                                           //�������
    PU_AUDIO_G726_BPS_E enAudioRate;                                //��ƵG726����
    CHAR szReserved[PU_RESERVE_LEN];
}PU_AUDIO_INFO_S, *LPPU_AUDIO_INFO_S;

//��Ƶ��ʾЧ���ṹ��
typedef struct PU_VIDEO_DISPLAY_INFO
{
    ULONG ulChannelId;                      //ͨ��ID
    LONG lBrightValue;                      //����
    LONG lHueValue;                         //ɫ��
    LONG lSaturationValue;                  //���Ͷ�
    LONG lContrastValue;                    //�Աȶ�
    LONG lSharpValue;                       //���
    CHAR szReserved[PU_RESERVE_LEN];
}PU_VIDEO_DISPLAY_INFO_S, *LPPU_VIDEO_DISPLAY_INFO_S;

//ROI���β����ṹ��
typedef struct PU_ROI_AREA_INFO
{
    LONG lQuality;                          //ͼ��������
    ULONG ulPointX;                         //ROI����X����
    ULONG ulPointY;                         //ROI����Y����
    ULONG ulWidth;                          //ROI������
    ULONG ulHeight;                         //ROI����߶�
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ROI_AREA_INFO_S, *LPPU_ROI_AREA_INFO_S;

//ROI�����ṹ��
typedef struct PU_ROI_INFO
{
    ULONG ulChannelId;                      //ͨ��ID
    PU_STREAM_TYPE_E enStreamId;            //����ID
    LONG lEnable;                           //ʹ��
    ULONG ulROINum;                         //��Ч��ROI������Ŀ
    PU_ROI_AREA_INFO_S stROIAreaInfo[PU_ROI_AREA_NUM_MAX];             //ROI���β���
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ROI_INFO_S, *LPPU_ROI_INFO_S;

//��ȦУ���ṹ��
typedef struct PU_IRIS_EMENDATION
{
    ULONG ulChannelId;                      //ͨ��ID
    PU_LANGUAGE_TYPE_E enLanguageType;      //��������
    CHAR szReserved[PU_RESERVE_LEN];
}PU_IRIS_EMENDATION_S, *LPPU_IRIS_EMENDATION_S;

//ý��˿���Ϣ
typedef struct PU_PORT_INFO
{
    ULONG ulInterLeavedPort;                //��֯�˿�
    ULONG ulVideoRtpPort;                   //��ƵRTP�˿�
    ULONG ulVideoRtcpPort;                  //��ƵRTCP�˿�
    ULONG ulAudioRtpPort;                   //��ƵRTP�˿�
    ULONG ulAudioRtcpPort;                  //��ƵRTCP�˿�
    ULONG ulIgtRtpPort;                     //����RTP�˿�
    ULONG ulIgtRtcpPort;                    //����RTCP�˿�
    CHAR szReserved[PU_RESERVE_LEN];
}PU_PORT_INFO_S, *LPPU_PORT_INFO_S;

//ʵ������ṹ��
typedef struct PU_SAVE_REALDATA_INFO
{
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX]; //�ļ�����·��
    PU_SAVE_REALDATA_TYPE_E enSaveType;     //���淽ʽ
    ULONG ulSaveSize;                       //�����ļ���С����¼�񳤶�(����enSaveType�ж�)
}PU_SAVE_REALDATA_INFO_S, *LPPU_SAVE_REALDATA_INFO_S;

//����ͼƬ�ṹ��
typedef struct PU_SAVE_PICTURE_INFO
{
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX]; //�ļ�����·��+�ļ���
    PU_SAVE_PICTURE_TYPE_E enSavePicType;   //���淽ʽ
}PU_SAVE_PICTURE_INFO_S, *LPPU_SAVE_PICTURE_INFO_S;

//Ѳ���켣����Ϣ
typedef struct PU_CRUISE_POINT
{
    ULONG ulPresetIndex;                    //Ԥ��λ���к�
    ULONG ulDwellTime;                      //Ԥ��λͣ��ʱ��(3-3600s)
    ULONG ulSpeed;                          //ת����һ������ٶ�(1-10)
}PU_CRUISE_POINT_S, *LPPU_CRUISE_POINT_S;

//Ѳ���켣��Ϣ
typedef struct PU_PTZ_CRUISE_TRACK_PARA
{
    ULONG ulPtzId;                                                  //��̨���
    ULONG ulCruiseTrackIndex;                                       //Ѳ���켣���
    ULONG ulCruiseType;                                             //Ѳ��ģʽ��1���켣ɨ�裬2������ɨ�裩
    CHAR szCuriseTrackName[PU_PTZ_CRUISE_LEN];                      //Ѳ���켣����
    ULONG ulPointNum;                                               //�켣�����
    PU_CRUISE_POINT_S stCruisePoint[PU_PTZ_CRUISE_POINT_MAX];       //�켣���б�
    PU_PTZ_CRUISE_TRACK_E enPtzCruiseTrack;                         //Ѳ���켣����������
}PU_PTZ_CRUISE_TRACK_PARA_S, *LPPU_PTZ_CRUISE_TRACK_PARA_S;

//Ѳ���켣ͷ��Ϣ
typedef struct PU_PTZ_CRUISE_TRACK_HEAD
{
    ULONG ulCruiseTrackIndex;                                       //Ѳ���켣���к�
    CHAR szCruiseTrackName[PU_PTZ_CRUISE_LEN];                      //Ѳ���켣����
}PU_PTZ_CRUISE_TRACK_HEAD_S, *LPPU_PTZ_CRUISE_TRACK_HEAD_S;

//Ѳ���켣�б�
typedef struct PU_PTZ_CRUISE_TRACK_LIST
{
    ULONG ulPtzId;                                                  //��̨���
    ULONG ulCruiseTrackNum;                                         //Ѳ���켣����
    PU_PTZ_CRUISE_TRACK_HEAD_S stPtzCruiseTrackHead;                //Ѳ���켣ͷ��Ϣ
}PU_PTZ_CRUISE_TRACK_LIST, *LPPU_PTZ_CRUISE_TRACK_LIST;

//������Ϣ
typedef struct PU_SQUARE_PARA
{
    ULONG ulX;
    ULONG ulY;
}PU_SQUARE_PARA_S, *LPPU_SQUARE_PARA_S;

/* OSDλ�ú���ɫ���� */
typedef struct PU_OSD_INFO
{
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulTextColor;                      //������ɫ 0x00RGB
    PU_COLOR_TYPE_E enBackgroundColor;      //������ɫ
    PU_ALPHA_TYPE_E enBackgroundAlpha;      //������͸����
    CHAR szReserve[PU_RESERVE_LEN];
}PU_OSD_INFO_S, *LPPU_OSD_INFO_S;

/* OSD�ַ������� */
typedef struct PU_OSD_STRING_PARA
{
    BOOL bEnable;                           //ʹ�����
    PU_OSD_INFO_S stOSDInfo;
    ULONG ulStringLen;                      // �ַ�������
    CHAR szString[PU_OSD_STRING_LEN];       // �ַ�������
}PU_OSD_STRING_PARA_S, *LPPU_OSD_STRING_PARA_S;

/* OSDʱ����� */
typedef struct PU_OSD_DATETIME_PARA
{
    BOOL bShowWeekday;                      //�Ƿ���ʾ����
    BOOL bDateEnable;                       //ʱ��ʹ�����
    PU_OSD_DATE_TYPE_E enDateType;          //���ڸ�ʽ
    PU_LANGUAGE_TYPE_E enLanguageType;      //OSD��ʾ����������: 0:�������� 1:Ӣ��
    PU_OSD_INFO_S stOsdPara;                //λ�ü���ɫ
    CHAR szReserve[PU_RESERVE_LEN];
}PU_OSD_DATETIME_PARA_S, *LPPU_OSD_DATETIME_PARA_S;

/* OSD���� */
typedef struct PU_OSD_STRING_ARRAY
{
    ULONG ulChannelID;                                              //ͨ��ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;                       //OSDʱ�����
    ULONG ulOSDStringNum;                                           //��Ч���ַ�������
    PU_OSD_STRING_PARA_S szStringPara[PU_OSD_STRING_NUM];           //OSD�ַ�������
}PU_OSD_PARTICULAR_PARA_S, *LPPU_OSD_PARTICULAR_PARA_S;

//��˽��������
typedef struct PU_MASK_PARA
{
    ULONG ulStartX;                         //��˽�����������Ͻ�X
    ULONG ulStartY;                         //��˽�����������Ͻ�Y
    ULONG ulWidth;
    ULONG ulHeight;
}PU_MASK_PARA_S,*LPPU_MASK_PARA_S;

//��˽�����б�
typedef struct PU_PRIVACY_MASK_ARRAY
{
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_PARA_S stMaskPara[PU_PRIVACY_MASK_MAX];
}PU_PRIVACY_MASK_ARRAY_S, *LPPU_PRIVACY_MASK_ARRAY_S;

//�¶�
typedef struct PU_TEMPERATURE_PARA
{
    LONG lIntTemp;                          //���������¶�ֵ
    ULONG ulDotTemp;                        //С�������¶�ֵ
}PU_TEMPERATURE_PARA_S, *LPPU_TEMPERATURE_PARA_S;

//���ڲ���
typedef struct PU_SERIAL_PORT_PARA
{
    ULONG ulSerialPort;                     //���ڱ��
    PU_SERIAL_PORT_MODE_E enPortMode;       //��������
    PU_BAUD_RATE_E enBaudRate;              //������
    PU_DATA_BIT_E enDataBit;                //����λ
    PU_PARITY_BIT_E enParityBit;            //У��λ
    PU_STOP_BIT_E enStopBit;                //ֹͣλ
    PU_FLOW_CONTROL_E enFlowControl;        //����������
}PU_SERIAL_PORT_PARA_S, *LPPU_SERIAL_PORT_PARA_S;

//��̨����
typedef struct PU_PTZ_PARA
{
    ULONG ulPtzId;                          //��̨���
    ULONG ulSerialPort;                     //���ڱ��
    PU_PTZ_DECODER_TYPE_E enDecoderType;    //����������
    ULONG ulDecoderAddress;                 //��������ַ
    PU_PTZ_CONTROL_MODE_E enPtzControlMode; //��������ģʽ
    BOOL  bEnable;                          //�Ƿ�ʹ��
}PU_PTZ_PARA_S, *LPPU_PTZ_PARA_S;

//͸��ͨ������
typedef struct PU_TRANSPARENT_CMD
{
    ULONG ulSerialPort;                                             //���ڱ��
    ULONG ulCmdLen;                                                 //͸��ͨ�������
    CHAR  szTransparentCmd[PU_TRANSPARENT_CMD_MAX];                 //͸��ͨ������
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_TRANSPARENT_CMD_S, *LPPU_TRANSPARENT_CMD_S;

//ʱ�䣬ʱ���֡��룬24Сʱ��
typedef struct PU_TIME
{
    CHAR szYear[PU_TIME_YEAR_LEN];
    CHAR szMonth[PU_TIME_OTHERS_LEN];
    CHAR szDay[PU_TIME_OTHERS_LEN];
    CHAR szHour[PU_TIME_OTHERS_LEN];
    CHAR szMinute[PU_TIME_OTHERS_LEN];
    CHAR szSecond[PU_TIME_OTHERS_LEN];
}PU_TIME_S, *LPPU_TIME_S;

//����ʱ��
typedef struct PU_ALARM_TIME
{
    ULONG ulCycleType;                      //ѭ����ʽ��0����ѭ����1��ÿ��ѭ����
    ULONG ulPeriod;                         //0��ÿ�죬1-7�����һ�������
    PU_TIME_S stStart;                      //��ʼʱ��
    PU_TIME_S stEnd;                        //����ʱ��
}PU_ALARM_TIME_S, *LPPU_ALARM_TIME_S;

//����ʱ���б�
typedef struct PU_ALARM_TIME_PARA_LIST
{
    ULONG ulNum;                                                    //����ʱ��θ���
    PU_ALARM_TIME_S stAlarmTime[PU_ALARM_TIME_MAX];                 //����ʱ�������
}PU_ALARM_TIME_LIST_S, *LPPU_ALARM_TIME_LIST_S;

//�¶ȸ澯����
typedef struct PU_TEMPERATURE_ALARM_PARA
{
    LONG lEnable;                           //ʹ��
    ULONG ulDeteInterval;                   //�澯���ʱ����1~256,ÿx����һ���Ƿ��ڸ澯״̬
    LONG lTemperatureMax;
    LONG lTemperatureMin;
}PU_TEMPERATURE_ALARM_PARA_S, *LPPU_TEMPERATURE_ALARM_PARA_S;

//������(����)�澯����
typedef struct PU_INPUT_ALARM_PARA
{
    ULONG ulDeviceId;                       //�澯�豸ID
    CHAR szName[PU_DIO_NAME_LEN];           //�澯�豸����
    LONG lEnable;                           //ʹ��
    ULONG ulType;                           //���������գ�0��������1������
    ULONG ulDeteInterval;                   //�澯���ʱ����1~256,ÿx����һ���Ƿ��ڸ澯״̬
    PU_ALARM_TIME_LIST_S stAlarmTimeList;
}PU_INPUT_ALARM_PARA_S, *LPPU_INPUT_ALARM_PARA_S;

//�ƶ����/��Ƶ�ڵ����β���
typedef struct PU_DETECTION_AREA
{
    ULONG ulNum;                                                    //�����θ���
    PU_MASK_PARA_S stMaskPara[PU_ALARM_AREA_MAX];                   //���β���
}PU_DETECTION_AREA_S, *LPPU_DETECTION_AREA_S;

//�ƶ����澯����
typedef struct PU_MOTION_DETECTION_PARA
{
    ULONG ulChannelId;                      //��Ƶͨ��ID
    LONG lEnable;                           //ʹ��
    ULONG ulInterval;                       //����¼����1~30s���ڸü���ڵ��˶�����Ϊͳһ�˶�
    ULONG ulSensitivity;                    //�˶����������1~5������Խ��Խ����
    ULONG ulDeteInterval;                   //�澯���ʱ����1~256��ÿx����һ���Ƿ��ڸ澯״̬
    PU_DETECTION_AREA_S stDetectionArea;    //�澯�������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //����ʱ���б�
}PU_MOTION_DETECTION_PARA_S, *LPPU_MOTION_DETECTION_PARA_S;

//��Ƶ�ڵ��澯����
typedef struct PU_HIDE_ALARM_PARA
{
    ULONG ulChannel;                        //��Ƶͨ��ID
    LONG lEnable;                           //�澯ʹ��
    ULONG ulDeteInterval;                   //�澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
    ULONG ulSensitivity;                    //�˶����������1~5������Խ��Խ����
    PU_DETECTION_AREA_S stDetectionArea;    //�澯�������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //����ʱ���б�
}PU_HIDE_ALARM_PARA_S, *LPPU_HIDE_ALARM_PARA_S;

//���ּ���
typedef struct PU_INVADE_POINT
{
    ULONG ulPosX;                           //��X������(0-352)
    ULONG ulPosY;                           //��Y������(0-288)
}PU_INVADE_POINT_S, *LPPU_INVADE_POINT_S;

//���ּ����
typedef struct PU_INVADE_LINE
{
    ULONG ulDirection;                      //��ⷽ��0��˫��1�������ң�2��������
    PU_INVADE_POINT_S stStartPoint;         //�������ʼ��
    PU_INVADE_POINT_S stEndPoint;           //����ߵ��յ�
}PU_INVADE_LINE_S, *LPPU_INVADE_LINE_S;

//���ּ�����б�
typedef struct PU_INVADE_LINE_LIST
{
    ULONG ulLineNum;                                                //��������Ч����
    PU_INVADE_LINE_S stLine[PU_INVADE_LINE_NUM_MAX];                //������
}PU_INVADE_LINE_LIST_S, *LPPU_INVADE_LINE_LIST_S;

//���ּ�����
typedef struct PU_INVADE_PARA
{
    LONG lEnable;                           //ʹ��
    ULONG ulSensitivity;                    //������
    ULONG ulDeteInterval;                   //�澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
    ULONG ulMiniSize;                       //Ŀ����С�ߴ�(5-20)
    ULONG ulMaxSize;                        //Ŀ�����ߴ�(10-30)
    PU_INVADE_LINE_LIST_S stLineList;       //���ּ�����б�
}PU_INVADE_PARA_S, *LPPU_INVADE_PARA_S;

//���ּ��澯����
typedef struct PU_INVADE_ALARM_PARA
{
    ULONG ulChannel;                        //��Ƶͨ��ID
    PU_INVADE_PARA_S stInvadePara;          //���ּ�����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //����ʱ���б�
}PU_INVADE_ALARM_PARA_S, *LPPU_INVADE_ALARM_PARA_S;

//Ŀ���������
typedef struct PU_COUNT_PARA
{
    LONG lEnable;                           //ʹ��
    ULONG ulSensitivity;                    //������
    ULONG ulDeteInterval;                   //�澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
    ULONG ulMiniSize;                       //Ŀ����С�ߴ�
    BOOL bOrientation;                      //ʶ��ģʽ���ã�0��ˮƽ��1����ֱ��
    ULONG ulDirection;                      //��ⷽ��0��˫��1������A������B��2������B������A��
}PU_COUNT_PRAR_S, *LPPU_COUNT_PARA_S;

//Ŀ������澯����
typedef struct PU_COUNT_ALARM_PARA
{
    ULONG ulChannelId;                      //��Ƶͨ��ID
    PU_COUNT_PRAR_S stCountPara;            //Ŀ���������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //����ʱ���б�
}PU_COUNT_ALARM_PARA_S, *LPPU_COUNT_ALARM_PARA_S;

//���ż�����
typedef struct PU_DISTURB_PARA
{
    LONG lEnable;                           //ʹ��
    ULONG ulSensitivity;                    //������
    ULONG ulResetTime;                      //��������ӳ�(1~5S)
    ULONG ulDeteInterval;                   //�澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
}PU_DISTURB_PARA_S, *LPPU_DISTURB_PARA_S;

//���ż��澯����
typedef struct PU_DISTURB_ALARM_PARA
{
    ULONG ulChannelId;                      //��Ƶͨ��ID
    PU_DISTURB_PARA_S stDisturbPara;        //���ż�����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //����ʱ���б�
}PU_DISTURB_ALARM_PARA_S, *LPPU_DISTURB_ALARM_PARA_S;

//��������
typedef struct PU_GUARD_PARA
{
    ULONG ulDeviceId;                       //�豸ID��0-���и澯�豸
    ULONG ulState;                          //������0��������1
}PU_GUARD_PARA_S, *LPPU_GUARD_PARA_S;

typedef struct PU_GUARD_STATE
{
    PU_GUARD_PARA_S szChannelStateList[PU_CAMERA_NUM_MAX];          //��ͷ����״̬,ulDeviceId=0Ϊ��Ч
    PU_GUARD_PARA_S szInputStateList[PU_DIO_NUM_MAX];               //�����豸�澯״̬,ulDeviceId=0Ϊ��Ч
    CHAR szReserve[PU_RESERVE_LEN];
}PU_GUARD_STATE_S, *LPPU_GUARD_STATE_S;

//�豸ϵͳʱ��ṹ��
typedef struct PU_SYSTEM_TIME
{
    PU_TIME_S stSystime;                    //ʱ��
    LONG  lTimeZone;                        //ʱ������������
    ULONG ulDotTimeZone;                    //ʱ����С������
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SYSTEM_TIME_S, *LPPU_SYSTEM_TIME_S;

typedef struct PU_PTZ_ACTION
{
    BOOL bPresetFlag;
    ULONG ulPresetIndex;
    BOOL bCruiseFlag;
    ULONG ulCruiseIndex; 
}PU_PTZ_ACTION_S,*LPPU_PTZ_ACTION_S;

//��̨Ԥ��λ
typedef struct PU_PTZ_PRESET_PARA
{
    ULONG ulChannelId;                      //ͨ��ID
    CHAR szPresetName[PU_PTZ_NAME_LEN];     //Ԥ��λ����
    ULONG ulIndex;                          //Ԥ��λ����
    PU_PTZ_PRESET_CMD_E enPresetCmd;        //Ԥ��λ������
}PU_PTZ_PRESET_PARA_S, *LPPU_PTZ_PRESET_PARA_S;

//Ԥ��λ��Ϣ
typedef struct PU_PTZ_PRESET_INFO
{
    ULONG ulIndex;
    CHAR szPresetName[PU_PTZ_NAME_LEN];
}PU_PTZ_PRESET_INFO_S, *LPPU_PTZ_PRESET_INFO_S;

//��̨Ԥ��λ�б�
typedef struct PU_PTZ_PRESET_LIST_PARA
{
    ULONG ulChannelId;                                              //ͨ��ID
    ULONG ulBeginIndex;                                             //Ԥ��λ��ʼ���
    ULONG ulEndIndex;                                               //Ԥ��λ�������
    ULONG ulTotalNum;                                               //���ص�Ԥ��λʵ�ʸ���
    PU_PTZ_PRESET_INFO_S stPtzPresetInfo[PU_PTZ_PRESET_NUM];        //Ԥ��λ��Ϣ
}PU_PTZ_PRESET_LIST_PARA_S, *LPPU_PTZ_PRESET_LIST_PARA_S;

//��̨����
typedef struct PU_PTZ_CONTROL_PARA
{
    ULONG ulChannel;                        //ͨ��ID
    ULONG ulOpCode;                         //��̨������
    ULONG ulParam1;                         //����1
    ULONG ulParam2;                         //����2
}PU_PTZ_CONTROL_PARA_S, *LPPU_PTZ_CONTROL_PARA_S;

//�澯�ϱ���Ϣ�ṹ
typedef struct PU_ALARM_REPORT      
{                                        
    ULONG ulDeviceId;                       //�澯�豸ID
    PU_ALARM_TYPE_E enAlarmType;            //�澯����
    PU_TIME_S stTime;                       //�澯����ʱ��
    PU_ALARM_ACTION_E enAction;             //�澯����/����
    ULONG ulAlarmId;                        //�澯ID
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ALARM_REPORT_S, *LPPU_ALARM_REPORT_S;

//NVSƽ̨����
typedef struct PU_PLATFORM_NVS_PARAM
{
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];        //NVS IP��ַ
    ULONG ulNvsPort;                           //NVS�˿�
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];    //�豸ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];   //NVS��¼��
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN]; //NVS��¼��
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];    //NVS��¼����
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_NVS_PARAM_S, *LPPU_PLATFORM_NVS_PARAM_S;

//IVSƽ̨����
typedef struct PU_PLATFORM_IVS_PARAM_S
{
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];        //IVS IP��ַ
    ULONG ulNvsPort;                           //IVS�˿�
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];    //�豸ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];   //IVS��¼��
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN]; //IVS��¼��
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];    //IVS��¼����
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_IVS_PARAM_S, *LPPU_PLATFORM_IVS_PARAM_S;

//ǧ����ƽ̨������ַ��������IVS
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

//28281ƽ̨������ַ
typedef struct PU_PLATFORM_GBT_PARA
{
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];    //�豸ID���¼����ͬ
    CHAR szPlatformId[PU_PLATFORM_INFO_LEN];   //����������
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_GBT_PARA_S, *LPPU_PLATFORM_GBT_PARA_S;

//SDK����ע��ĵ�ַ
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

//ONVIF����
typedef struct PU_ONVIF_SWITCH
{
    BOOL bEnable;                           //ONVIF����
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_SWITCH_S, *LPPU_ONVIF_SWITCH_S;

//ONVIF�������
typedef struct PU_ONVIF_PWD_PARA
{
    CHAR szUserName[PU_USER_NAME_LEN];
    CHAR szOldPassword[PU_PASSWORD_LEN];
    CHAR szNewPassword[PU_PASSWORD_LEN];
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_PWD_PARA_S, *LPPU_ONVIF_PWD_PARA_S;

//�����ϴ��ļ�·���ṹ��
typedef struct PU_UPGRADE_FILE_INFO
{
    CHAR cFileNum;                                                          //�ļ���Ŀ,����ļ���Ϊ UPGRADE_FILE_NUM_MAX
    CHAR szFileName[PU_UPGRADE_FILE_NUM_MAX][PU_UPGRADE_FILE_LEN_MAX];    //�ļ�·�����ļ�������һ��ΪuImage,�ڶ���Ϊjffs2���������ĸ�Ϊ��չԤ��
    CHAR szReserve[PU_RESERVE_LEN];
}PU_UPGRADE_FILE_INFO_S, *LPPU_UPGRADE_FILE_INFO_S;

//ϵͳ��Ϣ�ṹ��
typedef struct PU_SYS_STATUS_INFO
{
    FLOAT fCpuOccupancyRate;                //CPUռ����
    ULONG ulMemTotal;                       //�豸���ڴ�(KB)
    ULONG ulMemFree;                        //�����ڴ�(KB)
    ULONG ulMemBuffer;                      //BUFF�ڴ�(KB)
    ULONG ulMemCache;                       //CACHE�ڴ�(KB)
    ULONG ulRecvRate;                       //�����������byte
    ULONG ulSendRate;                       //���緢������byte
    ULONG ulFlashTotal;                     //�ܹ�Flash��С(KB)
    ULONG ulFlashFree;                      //����Flash��С(KB)
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SYS_STATUS_INFO_S, *LPPU_SYS_STATUS_INFO_S;


//�������ṹ��

//������ͨ����Ϣ
typedef struct PU_DECODER_CHANNEL_INFO
{
    unsigned long ulChannelID;                                      //������ͨ����
    char          szChannelName[PU_DEC_CHANNEL_NAME_LEN + 1];          //������ͨ������
} PU_DECODER_CHANNEL_INFO_S;

//������Ϣ
typedef struct PU_DECLINK_INFO
{
    CHAR szDecVIP[PU_IP6_ADDR_LEN];         //��ƵIP��ַ
    ULONG ulDecVPort;                       //��Ƶ�˿�
    CHAR szDecAIP[PU_IP6_ADDR_LEN];         //��ƵIP��ַ
    ULONG ulDecAPort;                       //��Ƶ�˿�
    CHAR chTransProtocol;                   //����Э��: 1:RTP(TCP Client) 2:RTP(UDP) ...  ��Ƶ��Ƶ��������ͬ,��TCPʱ������IP��PORTΪ��Σ���UDPʱ��IP��PORTΪ����
    CHAR chDecFlags;                        //�����־��0 ������Ƶ; 1 ������Ƶ; 2 ͬʱ��,ͬʱ��ʱʹ��VIP��VPORT����
    CHAR chKeepaliveFlags;                  //�����־,��VIP/VPort ����RTSP��������: 0 ������,1 ���� 
    CHAR szRes[PU_RESERVE_LEN];             //Ԥ��,ͨ��sdk����:szRes[0]= 0;sdk�������������ֱ�ӷ���:szRes[0]=1
}PU_DECLINK_INFO_S, *LPPU_DECLINK_INFO_S;

//������Ϣ�ṹ��
typedef struct PU_DEC_INFO
{
    ULONG ulChannelId;                      //ͨ��ID
    PU_DECLINK_INFO_S stDecLinkInfo;        //������Ϣ
}PU_DEC_INFO_S, *LPPU_DEC_INFO_S;

//��ʼ��������Ӧ�ṹ��
typedef struct PU_INIT_DECODE_INFO_RSP
{
    CHAR szDecMediaIp[PU_IP4_ADDR_LEN];     //��������ý��IP
    PU_PORT_INFO_S stDecPortInfo;           //�������Ķ˿���Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
}PU_INIT_DECODE_INFO_RSP_S, *LPPU_INIT_DECODE_INFO_RSP_S;

//��������ṹ��
typedef struct PU_START_DECODE_INFO
{
    ULONG ulChannelId;                      //ͨ����
    PU_ENCODE_TYPE_E enVideoEncodeType;     //��Ƶ��������
    PU_ENCODE_TYPE_E enAudioEncodeType;     //��Ƶ��������
    PU_PROTOCOL_TYPE_E enProtocolType;      //��ʼ�����봫��Э��
    PU_PORT_INFO_S stLocalPortInfo;         //SDK�Ķ˿���Ϣ
    CHAR szLocalMediaIp[PU_IP4_ADDR_LEN];   //SDK��ý��IP
    CHAR szSessionID[PU_NAT_SESSIONID_LEN]; //�ỰID
    CHAR szSessionUrl[PU_NAT_URL_LEN];      //�ỰURL
    CHAR szReserve[PU_RESERVE_LEN];
}PU_START_DECODE_INFO_S,*LPPU_START_DECODE_INFO_S;

//�������˿�����
typedef struct PU_DEC_PORT_ABILITY
{
    CHAR szOutPutModes[PU_PORT_MODE_NUM_MAX];  //1\2\4\9\16 mode,0 the end
    ULONG ulPortType;                       //0:Audio, 1:Video 2:both
    BOOL bSupportEnlarge;                   //�˿��Ƿ�֧�ַŴ���ʾ
}PU_DEC_PORT_ABILITY_S,*LPPU_DEC_PORT_ABILITY_S;

//�������˿������б�
typedef struct PU_DEC_PORT_ABILITY_LIST
{
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType[PU_DECODE_TYPE_MAX];                 //����֧�ֵ�����
    PU_DEC_PORT_ABILITY_S stBNCAttribute[PU_BNC_PORT_MAX];             //������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ��
    PU_DEC_PORT_ABILITY_S stVGAAttribute[PU_VGA_PORT_MAX];             //������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_ABILITY_S stHDMIAttribute[PU_HDMI_PORT_MAX];           //������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_ABILITY_S stDVIAttribute[PU_DVI_PORT_MAX];             //������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��**/
}PU_DEC_PORT_ABILITY_LIST_S, *LPPU_DEC_PORT_ABILITY_LIST_S;

//�������˿���Ϣ
typedef struct PU_DEC_PORT_INFO
{
    BOOL bEnable;                           //�˿�ʹ��
    PU_PORT_MODE_E enPortMode;              //ͨ��ģʽ
    PU_FRAME_RATE_E enFrameRate;            //֡��  :30֡|| 60 ֡
    PU_RESOLUTION_TYPE_E enDecResolution;   //��������ֱ���
//     BOOL bEnlargeFlag;                   //�Ƿ�֧�ַŴ�,0: no support, 1: support
}PU_DEC_PORT_INFO_S, *LPPU_DEC_PORT_INFO_S;

//�������˿���Ϣ�б�
typedef struct PU_DEC_PORT_INFO_LIST
{
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType;                                  //��������
    PU_DEC_PORT_INFO_S stBNCAttribute[PU_BNC_PORT_MAX];                //������ͣ�A/V/AV    ���������ģʽ:����1��2��4��9��16�ȼ���ģʽ��
    PU_DEC_PORT_INFO_S stVGAAttribute[PU_VGA_PORT_MAX];                //������ͣ�A/V/AV    ���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_INFO_S stHDMIAttribute[PU_HDMI_PORT_MAX];              //������ͣ�A/V/AV    ���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_INFO_S stDVIAttribute[PU_DVI_PORT_MAX];                //������ͣ�A/V/AV   �� �������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��**/
//    CHAR chSameVInput;                                            //VGA/HDMI/DVI �Ƿ�ͬԴģʽ��0000 0000 ��ͬԴ, 0000 0111  ͬԴ */
    CHAR chRes[PU_RESERVE_LEN];
}PU_DEC_PORT_INFO_LIST_S, *LPPU_DEC_PORT_INFO_LIST_S;

//ͨ����˿ڵ�ӳ���ϵ
typedef struct PU_DEC_CHANNEL_PORT_MAP
{
    ULONG ulChannelID;                      //ͨ����
    PU_PORT_TYPE_E enPortType;              //�˿�����
    ULONG ulPortIndex;                      //�˿�����
    ULONG ulLayoutIndex;                    //ͨ�����ڵĲ�������
}PU_DEC_CHANNEL_PORT_MAP_S, *LPPU_DEC_CHANNEL_PORT_MAP_S;

/*ͨ������ :��Ƶ& ��Ƶ*/
/*����������2 ----1 BNC1+D1 1 VGA1||HDMI1 + 1080P
5 ----1 BNC1+D1  4 VGA1||HDMI1 + D1
3 ----1 BNC1+D1  1 VGA1+720P  1 HDMI1+720P   ====   ��ͬԴ
2 ----1 VGA1+720P  1 HDMI1+720P ====   ��ͬԴ*/
typedef struct PU_DEC_CHANNEL_ABILITY
{
    PU_DEC_CHANNEL_PORT_MAP_S stChannelPortMap;                     //ӳ���ϵ
    PU_ENCODE_TYPE_E enVideoDecFormats[PU_DECODE_TYPE_MAX];            //������Ƶ��ʽ
    PU_ENCODE_TYPE_E enAudioDecFormats[PU_DECODE_TYPE_MAX];            //������Ƶ��ʽ
    PU_RESOLUTION_TYPE_E enMaxDecResolution ;                       //�������ֱ���
    PU_FRAME_RATE_E enMaxFrameRate;                                 //���֡��  :30֡|| 60 ֡
    BOOL bSupportDecryption;                                        //0: no support 1: support
    BOOL bSupportWaterMark;                                         //0: no support 1: support
//    BOOL bAudioFlag;                                              //��Ƶ����:һ����������֧��һ·��Ƶ�������һ��ͨ���￪����ԭ�������ͨ�����������ᱻĬ�Ͽ��յ�
}PU_DEC_CHANNEL_ABILITY_S,*LPPU_DEC_CHANNEL_ABILITY_S;

//ͨ�������б�
typedef struct PU_DEC_CHANNEL_ABILITY_LIST
{
    ULONG ulChannelNums;                                            //ͨ����
    PU_DEC_CHANNEL_ABILITY_S stChnAttri[PU_CHANNEL_NUM_MAX];           //ͨ������
}PU_DEC_CHANNEL_ABILITY_LIST_S, *LPPU_DEC_CHANNEL_ABILITY_LIST_S;

/* OSDλ�ú���ɫ���� */
typedef struct PU_DEC_OSD_PARA
{
    ULONG ulStartX;                                         
    ULONG ulStartY;
    ULONG ulFgColor;                        //������ɫ
    UCHAR ucFgAlpha;                        //ǰ��͸����
    UCHAR ucBgAlpha;                        //����͸����
    ULONG ulBgColor;                        //������ɫ
}PU_DEC_OSD_PARA_S, *LPPU_DEC_OSD_PARA_S;

//������OSD�ַ�����
typedef struct PU_DEC_OSD_STRING_INFO
{
    BOOL bEnable;                           //ʹ�����
    ULONG ulStringLen;                      //�ַ�������
    CHAR szString[PU_OSD_MAX_LENGTH];          //�ַ�������
    PU_DEC_OSD_PARA_S stOSDPara;            //OSD������Ϣ
}PU_DEC_OSD_STRING_INFO_S, *LPPU_DEC_OSD_STRING_INFO_S;

//ͨ����Ϣ
typedef struct PU_DEC_CHANNEL_INFO
{
    ULONG ulChannelId;                      //ͨ��ID��
    BOOL bDenoiseFlag;                      //����ʹ��
    BOOL bDemistFlag;                       //ȥ��ʹ��
    BOOL bEnlargeStatus;                    //ͼ��Ŵ�״̬
    PU_DEC_OSD_STRING_INFO_S stOsdTextInfo; //OSD������Ϣ
}PU_DEC_CHANNEL_INFO_S, *LPPU_DEC_CHANNEL_INFO_S;

//ͨ����Ϣ�б�
typedef struct PU_DEC_CHANNEL_INFO_LIST
{
    ULONG ulChannnelNums;                                           //ͨ����
    PU_DEC_CHANNEL_INFO_S stChannelInfo[PU_CHANNEL_NUM_MAX];           //ͨ����Ϣ
}PU_DEC_CHANNEL_INFO_LIST_S, *LPPU_DEC_CHANNEL_INFO_LIST_S;

//������������Ϣ
typedef struct PU_DEC_DECRYPTION_INFO
{
    ULONG               ulChannelId;                                //���ܵ�ͨ����
    BOOL                bEnable;                                    //����ʹ��״̬
    PU_ENCRYPT_TYPE_E   enDecryptionType;                           //�����㷨����
    CHAR                szVideoCrypto[PU_CRYPTION_PASSWD_LEN];         //��Ƶ��Կ
    CHAR                szAudioCrypto[PU_CRYPTION_PASSWD_LEN];         //��Ƶ��Կ
}PU_DEC_DECRYPTION_INFO_S, *LPPU_DEC_DECRYPTION_INFO_S;

//��������Ƶ�˿���Ϣ
typedef struct PU_DEC_AUDIO_INFO
{
    PU_AUDIO_PORT_TYPE_E enAudioPortType;                           //��Ƶ�˿�����
    BOOL bEnable;                                                   //��Ƶ�˿�ʹ�����
    ULONG ulChannelId;                                              //��Ƶ�����ͨ����
    PU_ENCODE_TYPE_E enAudioDecodeType;                             //��Ƶ��������
    ULONG ulAudioVolume;                                            //����
    PU_AUDIO_SAMPLERATE_E enAudioSampleRate;                        //��Ƶ������
}PU_DEC_AUDIO_INFO_S, *LPPU_DEC_AUDIO_INFO_S;

typedef struct PU_TIME_PLAN
{
    ULONG ulCycle;                          // ���ڿ��ƣ�0����һ�Σ�1��ÿ�ܶ�����ʱ���
    ULONG ulPeriod;                         // ���ڣ� 0:һ��ȫ�� 1~7:��ʾ����
    PU_TIME_S stStartTime;                  // ��ʼʱ��:  UTC ʱ��
    PU_TIME_S stEndTime;                    // ����ʱ��:  UTC ʱ��
    CHAR szReserved[PU_RESERVE_LEN];
}PU_TIME_PLAN_S, *LPPU_TIME_PALN_S;

/*ͨ��¼��ƻ�*/
typedef struct PU_RECORD_PLAN
{
    ULONG ulChannelId;
    ULONG ulTotalPlanNum;                                           //�ܼ�¼��
    PU_TIME_PLAN_S szRecordPlanList[PU_RECORD_PLAN_NUM];            //¼��ƻ�����
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_PLAN_S, *LPPU_RECORD_PLAN_S;

/* ¼����Ϣ��ѯ */
typedef struct PU_RECORD_INQUIRE
{
    ULONG ulChannelId;
    PU_TIME_S stBeginTime;
    PU_TIME_S stEndTime;
    ULONG     ulBeginIndex;
    PU_RECORD_TYPE_E enRecordTypeList[PU_RECORD_TYPE_NUM];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_INQUIRE_S, *LPPU_RECORD_INQUIRE_S;

/* ǰ��¼����Ϣ */
typedef struct PU_RECORD_INFO
{
    PU_RECORD_TYPE_E enRecordType;                                  // ¼������
    PU_TIME_S stBeginTime;                                          // ��ʼʱ��
    PU_TIME_S stEndTime;                                            // ����ʱ��
    ULONG ulContentSize;                                            // ¼���ļ���С
    CHAR szContentID[PU_RECORD_CONTENTID_LEN];                      // ¼���ļ���
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_INFO_S, *LPPU_RECORD_INFO_S;

/* ǰ��¼����Ϣ�б� */
typedef struct PU_RECORD_LIST
{
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    PU_RECORD_INFO_S szRecordInfoList[PU_RECORD_INFO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_LIST_S, *LPPU_RECORD_LIST_S;


/************************�����������������**************************/
typedef struct PU_SWITCH_OUTPUT_PARA
{
    ULONG  ulOutputId;
    CHAR   szOutputName[PU_DIO_NAME_LEN];   //���ƣ����֧��32�ֽ�
    ULONG  ulHoldTime;                      //����ʱ�� 1-600  Ĭ��10��
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_OUTPUT_PARA_S, *LPPU_SWITCH_OUTPUT_PARA_S;

/************************���������״̬����**************************/
typedef struct PU_SWITCH_OUTPUT_STATE
{
    ULONG  ulOutputId;
    ULONG  ulSwitchType;                    //����/����= 0������ 1������
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_DO_STATE_S, *LPPU_SWITCH_DO_STATE_S;

/************************�����������������**************************/
typedef struct PU_SWITCH_INPUT_PARA
{
    ULONG ulInputId;
    CHAR  szInputName[PU_DIO_NAME_LEN];     //���ƣ����֧��32�ֽ�
    ULONG ulSwitchType;                     //����/����= 0������ 1������
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_INPUT_PARA_S, *LPPU_SWITCH_INPUT_PARA_S;

/************************���������������������**********************/
typedef struct PU_DIO_PARA
{
    PU_SWITCH_INPUT_PARA_S  stInput[PU_DIO_NUM_MAX];
    PU_SWITCH_OUTPUT_PARA_S stOutput[PU_DIO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DIO_PARA_S, *LPPU_DIO_PARA_S;

/**************�澯���� ��ͷ��Ϣ**********************/
typedef struct PU_ALARM_LINKAGE_CAMERA_INFO
{
    ULONG  ulChannelId;
    ULONG  ulPreId;
    ULONG  ulCruiseId;
    ULONG  ulRecord;
    ULONG  ulSnap;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_LINKAGE_CAMERA_INFO, *LPPU_ALARM_LINKAGE_CAMERA_INFO;

/*******************�澯�������� ***************************/
typedef struct PU_ALARM_LINKAGE_PARA
{
    ULONG ulChannelNum;                                             //������ͷ����
    ULONG ulDoNum;                                                  //�����������������
    PU_ALARM_LINKAGE_CAMERA_INFO stCameraList[PU_ALARM_CAMERA_MAX]; //������ͷ��Ϣ�б�
    ULONG szDoIdList[PU_ALARM_DO_MAX];                              //�������������ID
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_LINKAGE_PARA_S, *LPPU_ALARM_LINKAGE_PARA_S;

//��ȡǰ���豸��־
typedef struct PU_LOG_REQ_PARA
{
    PU_TIME_S stStartTime;
    PU_TIME_S stEndTime;
    ULONG ulStartIndex;
    ULONG ulPrePageNum;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LOG_REQ_PARA_S, *LPPU_LOG_REQ_PARA_S;

//ǰ����־��Ϣ
typedef struct PU_LOG_INFO
{
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    CHAR  szLogInfoList[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LOG_INFO_S, *LPPU_LOG_INFO_S;

//ʵʱ����ṹ��
typedef struct PU_REAL_PLAY_INFO
{
    ULONG ulChannelId;                                              //ͨ��ID
    HWND hPlayWnd;                                                  //Windows���ھ��    
    PU_STREAM_TYPE_E enStreamType;                                  //��������,��������������
    PU_VIDEO_TYPE_E enVideoType;                                    //�����ͣ���Ƶ������Ƶ������������¼����
    PU_PROTOCOL_TYPE_E enProtocolType;                              //����Э�����ͣ�UDP,TCP
    PU_MEDIA_CALLBACK_TYPE_E enMediaCallbackType;                   //�ص����ͣ�0:RTP���� 1:RTP������  2:Frame 3:YUV  
    CHAR szLocalIp[PU_IP4_ADDR_LEN];                                //�����IP
    BOOL bKeepLive;                                                 //�Ƿ񱣻�
    PU_TIME_S stStartTime;                                          //����Ԥ¼��¼��ʼʱ��
    PU_TIME_S stEndTime;                                            //����Ԥ¼��¼�����ʱ��
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //�������ͣ�ֻ֧��AES����
    CHAR szMediaCrypto[PU_CRYPTION_PASSWD_LEN];                     //������Կ
    CHAR szReserved[PU_RESERVE_LEN];
}PU_REAL_PLAY_INFO_S, *LPPU_REAL_PLAY_INFO_S;

//�����Խ�/�����㲥�ṹ��
typedef struct PU_VOICE_INFO
{
    ULONG ulChannelId;                      //ͨ��ID
    CHAR  szLocalAudioIp[PU_IP4_ADDR_LEN];  //������ƵIP
    BOOL  bFeedAudioData;                   //�Ƿ�ι����(�����Խ���TRUEʱ�ص���������Ϊ�գ�FLASEʱ�ص���������Ϊ��)
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_VOICE_INFO_S, *LPPU_VOICE_INFO_S;

//ʵʱ����ṹ��
typedef struct PU_MEDIA_PLAY_INFO
{
    ULONG ulChannelId;                                              //ͨ����
    PU_BUSINESS_TYPE_E enBusinessType;                              //ʵʱ����������Խ��������㲥��¼������
    PU_STREAM_TYPE_E enStreamType;                                  //��������������1��������2
    PU_PROTOCOL_TYPE_E enProtocolType;                              //TCP��UDP���鲥��ʽ
    PU_VIDEO_CODE_TYPE_E enTansmitType;                             //ES��PS��TS
    PU_VIDEO_TYPE_E enVideoType;                                    //��Ƶ������Ƶ����������
    CHAR szLocalIp[PU_IP4_ADDR_LEN];                                //�����IP
    PU_PORT_INFO_S stLocalPortInfo;                                 //����˵Ķ˿ں�
    ULONG ulLinkMode;                                               //�������ͣ�0ֱ�� 1��ת
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //��������
    CHAR szVideoCrypto[PU_CRYPTION_PASSWD_LEN];                     //��Ƶ��Կ
    CHAR szAudioCrypto[PU_CRYPTION_PASSWD_LEN];                     //��Ƶ��Կ
    PU_TIME_S stStartTime;                                          //����Ԥ¼��¼��ʼʱ��
    PU_TIME_S stEndTime;                                            //����Ԥ¼��¼�����ʱ��
    CHAR szSessionIDForNAT[PU_NAT_SESSIONID_LEN];                   //����NAT��Խ��Session
    CHAR szSessionUrl[PU_NAT_URL_LEN];                              //����NAT�ĻỰURL
    CHAR szReserved[PU_RESERVE_LEN];
}PU_MEDIA_PLAY_INFO_S, *LPPU_MEDIA_PLAY_INFO_S;

//ý������ʼ��Ӧ��¼��������Ӧ
typedef struct PU_MEDIA_PLAY_RSP
{
    ULONG               ulSessionId;                                //ý������Ψһ��־
    PU_PORT_INFO_S      stPeerPortInfo;                             //���Ͷ˵Ķ˿���Ϣ
    CHAR                szPeerIp[PU_IP4_ADDR_LEN];                  //���Ͷ˵�IP
    PU_ENCODE_TYPE_E    enVideoEncodeType;                          //��Ƶ��������
    PU_ENCODE_TYPE_E    enAudioEncodeType;                          //��Ƶ��������
    PU_TIME_S           stStartTime;                                //¼��ʵ�ʿ�ʼʱ��
    PU_TIME_S           stEndTime;                                  //¼��ʵ�ʽ���ʱ��
    CHAR                szReserved[PU_RESERVE_LEN];
}PU_MEDIA_PLAY_RSP_S, *LPPU_MEDIA_PLAY_RSP_S;

/* Ӳ����Ϣ */
typedef struct PU_HARD_DISK_PARA
{
    CHAR szDiskFac[PU_FAC_NAME_LEN];
    PU_DISK_TYPE_E enDiskType;
    ULONG ulAllSpace;
    ULONG ulLeftSpace;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HARD_DISK_PARA_S;

//���豸����
typedef struct PU_DEVICE_ABILITY
{
    ULONG ulVideoInputChannelNum;           //��Ƶ����ͨ����
    ULONG ulAudioInputChannelNum;           //��Ƶ����ͨ����
    ULONG ulAlarmDINum;                     //�澯������
    ULONG ulAlarmDONum;                     //�澯�����
    ULONG ulSerialPortNum;                  //������
    ULONG ulNetworkCardNum;                 //������
    ULONG ulHardDiskNum;                    //Ӳ����
    ULONG ulPTZNum;                         //��̨��
    ULONG ulTalkbackInputNum;               //�����Խ�������
    ULONG ulTalkbackOutputNum;              //�����Խ������
    ULONG ulRTPOverFlag;                    //����Э��: 0:RTPoverUDP 1:RTPoverTCP 2:RTPoverUDP&TCP
    PU_HARD_DISK_PARA_S stHardDiskInfo;     //Ӳ����Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_ABILITY_S, *LPPU_DEVICE_ABILITY_S;

/* ������ */
typedef struct PU_STREAM_ABILITY_PARA
{
    PU_STREAM_TYPE_E enStreamType;                                  //��Ƶ������
    PU_ENCODE_TYPE_E enVideoFormat[PU_VIDEO_FORMAT_NUM];            //��Ƶ�����ʽ
    PU_RESOLUTION_TYPE_E enMaxResolution;                           //���ֱ���
    ULONG ulMaxBitRate;                                             //�������
    ULONG ulMaxFrmRate;                                             //���֡��
    ULONG ulMaxIFrameInterval;                                      //���I֡���
    PU_VIDEO_TYPE_E enVideoType;                                    //��Ƶ������
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STREAM_ABILITY_PARA_S, *LPPU_STREAM_ABILITY_PARA_S;

/* ͨ�������� */
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

/*ǰ�����*/
typedef struct PU_FEC_PARA
{
    ULONG ulChannelId;
    BOOL bEnable;                           //ǰ�����ʹ��
    PU_FEC_PACKET_LOSS_RATIO_E enPacketLossRatio;       //ǰ���������
    CHAR szReserved[PU_RESERVE_LEN];
}PU_FEC_PARA_S, *LPPU_FEC_PARA_S;

//��̬����/֡��
typedef struct PU_DYNAMIC_STREAM_INFO
{
    ULONG ulChannelId;
    BOOL  ulEnable;                         //��̬֡�ʺ������Ƿ�ʹ��
    ULONG ulDynamicFrameRate;               //��̬֡��
    ULONG ulDynamicBitRate;                 //��̬����
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
    PU_EVENT_TYPE_E enEventType;            //�¼�����
    ULONG           ulIdentifyID;           //Ψһ��ʶ��ID��
    ULONG           ulChannelId;
}PU_EVENT_COMMON_S, *LPPU_EVENT_COMMON_S;

//device stream package change callback event struct
typedef struct PU_EVENT_STEAM_PACKAGE_CHANGE
{
    PU_EVENT_COMMON_S stPuEventCommon;      //ͨ���¼�
    PU_STREAM_MODE_E enStreamMode;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_STEAM_PACKAGE_CHANGE_S, *LPPU_EVENT_STEAM_PACKAGE_CHANGE_S;

//device stream package change callback event struct
typedef struct PU_EVENT_UPLOAD_IMAGE_URL
{
    PU_EVENT_COMMON_S stPuEventCommon;                              // ͨ���¼�
    ULONG ulSessionId;                                              // ǰ�˻�ȡץ��ͼƬ����URL����ỰID,����ǰ�˱�ʶһ��Ψһ�ĻỰ
    CHAR  szContentID[PU_SNAP_IMAGE_NAME_LEN];                      // ͼƬ��
    ULONG ulLocation;                                               // ͼƬ�洢λ��: 0:ƽ̨  1:ǰ��
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_UPLOAD_IMAGE_URL_S, *LPPU_EVENT_UPLOAD_IMAGE_URL_S;

typedef struct PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //ͨ���¼�
    ULONG ulSessionId;                                              //�ϴ����֪ͨ�ỰID,����ǰ�˱�ʶһ��Ψһ�ĻỰ
    CHAR  szContentID[PU_SNAP_IMAGE_NAME_LEN];                      //ͼƬ��
    ULONG ulContentSize;                                            //ͼƬ��С
    CHAR  szSnapTime[PU_TIME_TOTAL_LEN];                            //ץ��ʱ�� ��ʽ��"2009-07-14 15:41:14"
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S, *LPPU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S;

//device auto register callback event struct
typedef struct PU_EVENT_REGISTER
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //ͨ���¼�
    CHAR  szDeviceId[PU_MAC_ADDR_LEN];
    CHAR  szDeviceIp[PU_IP4_ADDR_LEN];
    CHAR  szDeviceType[PU_DEVICE_TYPE_LEN];
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_EVENT_REGISTER_S, *LPPU_EVENT_REGISTER_S;

//������ע��ص�
typedef struct PU_DEC_CALLBACK_INFO
{
    PU_EVENT_COMMON_S stPuEventCommon;                                 //ͨ���¼�
    CHAR szDecoderID[PU_DECODER_ID_LEN + 4];                           //������ID
    CHAR szDecIP[PU_IP4_ADDR_LEN];                                     //������IP
    ULONG ulDecPort;                                                   //������port
    CHAR szDeviceType[PU_DEC_CHANNEL_NAME_LEN];                        //�豸�ͺ�
    ULONG ulVideoPayloadTypeNum;                                       //֧�ֵ���ƵPayloadType���������ֵ������16
    ULONG ulAudioPayloadTypeNum;                                       //֧�ֵ���ƵPayloadType���������ֵ������16
    ULONG ulChannelNum;                                                //��������Чͨ����������󲻳���
    CHAR szDecoderName[PU_DECODER_NAME_LEN + 4];                       //����������
    CHAR szDecoderEncoding[PU_DECODER_ENCODING_LEN + 4];               //�����������ʽ 
    UCHAR ucVideoPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           //֧�ֵ���ƵPayloadType�̶����顣Ԫ�ظ���Ϊ16��ʵ��Ԫ�ظ���ΪulVideoPayloadTypeNum
    UCHAR ucAudioPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           //֧�ֵ���ƵPayloadType�̶����顣Ԫ�ظ���Ϊ16��ʵ��Ԫ�ظ���ΪulAudioPayloadTypeNum
    PU_DECODER_CHANNEL_INFO_S stChannelInfoArray[PU_CHANNEL_NUM_MAX];  //������ͨ����Ϣ������Ԫ�ظ���ΪulChannelNum
}PU_DEC_CALLBACK_INFO_S, *LPPU_DEC_CALLBACK_INFO_S;

//����״̬�ص�
typedef struct PU_CONNECT_STATUS
{
    PU_EVENT_COMMON_S         stPuEventCommon;                      //ͨ���¼�
    CHAR                      szDeviceIP[PU_IP4_ADDR_LEN];          //�豸IP
    ULONG                     ulDevicePort;                         //�豸port
    CHAR                      szDeviceFac[PU_FAC_NAME_LEN];         //�豸����,�̶�Ϊ��HUAWEI PU
    CHAR                      szDeviceID[PU_MAC_ADDR_LEN + 4];      //�豸ID
    CHAR                      szDeviceType[PU_DEVICE_NAME_LEN];     //�豸�ͺ�
    CHAR                      szReserved[PU_RESERVE_LEN];
}PU_CONNECT_STATUS_S, *LPPU_CONNECT_STATUS_S;

typedef struct PU_EVENT_TRANSPARENT
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //ͨ���¼�
    PU_TRANSPARENT_CMD_S stTransparentCmd;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_TRANSPARENT_S, *LPPU_EVENT_TRANSPARENT_S;

typedef union PU_EVENT_NOTIFY_BODY
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //ͨ���¼�
    PU_EVENT_STEAM_PACKAGE_CHANGE_S stPuStreamPackgeChange;         //IPC���ײͱ��
    PU_EVENT_UPLOAD_IMAGE_URL_S stPuUploadImageURL;                 //ǰ�������ϴ�ͼƬURL
    PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S stUploadCompNotify;         //ǰ��ͼƬ�ϴ����֪ͨ

    PU_DEC_CALLBACK_INFO_S stPuDecRegister;                         //ǰ��DEC����ע��
    PU_CONNECT_STATUS_S    stPuConnetStatus;                        //ǰ���豸����״̬
    PU_EVENT_REGISTER_S    stPuIpcRegister;                         //ǰ��IPC����ע��
    PU_EVENT_TRANSPARENT_S stTransparentChannelNotify;              //͸��ͨ�������ϱ�
}PU_EVENT_NOTIFY_BODY_U, *LPPU_EVENT_NOTIFY_BODY_U;

//����������
typedef struct RECORD_STRATEGY
{
    ULONG ulChannelId;
    ULONG ulStrategy;                       // �洢����:0ѭ������  1ֹͣ¼��
    ULONG ulMinRecordTime;                  // ��С¼��ʱ�� >=60s
    ULONG ulPreAlarmRecordTime;             // ��ǰԤ¼ʱ��
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_RECORD_STRATEGY_S, *LPPU_RECORD_STRATEGY_S;

//����λ����
typedef struct GUARD_POSITION_PARA
{
    ULONG ulPtzId;
    BOOL bEnable;
    ULONG ulPresetIndex;
    ULONG ulWaitTime;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_GUARD_POSITION_PARA_S, *LPPU_GUARD_POSITION_PARA_S;

//������̨����
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

//����ƽ������
typedef struct PU_STREAM_SMOOTH_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulTcpUpperCoefficient;
    ULONG ulUdpUpperCoefficient;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_STREAM_SMOOTH_PARA_S, *LPPU_STREAM_SMOOTH_PARA_S;

//��ѯ��̨��ǰλ��
typedef struct PU_PTZ_CURRENT_LOCATION
{
    LONG lPTZHorDegree;                     //ˮƽ�Ƕ�
    LONG lPTZVerDegree;                     //��ֱ�Ƕ�
    ULONG ulLenMultiple;                    //��ͷ�䱶��������
    ULONG ulDotLenMultiple;                 //��ͷ�䱶С������
    ULONG ulZoomRatio;                      //���ֱ䱶��������
    ULONG ulDotZoomRatio;                   //���ֱ䱶С������
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_PTZ_CURRENT_LOCATION_S, *LPPU_PTZ_CURRENT_LOCATION_S;

typedef struct PU_IGT_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bIgtEnable;                       /*�����ܿ���*/
    BOOL  bTrackEnable;                     /*Ŀ��켣����ʹ��*/
    PU_IGT_FIELD_TYPE_E enFieldType;        /*����ģʽ����*/
    PU_IGT_MINTARGET_SIZE_E enMinTargetSize;/*ǰ��Ŀ����С�ߴ��趨*/
    PU_IGT_SHADOW_MODE_E enShadowMode;      /*ȥ��Ӱģʽ�趨*/
    PU_IGT_DETECT_SENS_E enDetectSens;      /*Ŀ�����������趨*/
    BOOL bInsensitiveObject;                /*�Ƿ���ʾ������Ŀ����Ϣ*/
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_ALARM_PARA_S, *LPPU_IGT_ALARM_PARA_S;

typedef struct PU_IGT_POINT
{
    USHORT usPointPosX;                     /*��X������(0-352)*/
    USHORT usPointPosY;                     /*��Y������(0-288)*/
}PU_IGT_POINT_S;

typedef struct PU_IGT_TW_LINE
{
    UCHAR ucDirection;                      /*��ⷽ��: 0:both 1:Left->right 2:right->left */
    PU_IGT_POINT_S stStartPoit;             /*������ʼ��*/
    PU_IGT_POINT_S stEndPoit;               /*������ֹ��*/
    ULONG ulLineIndex;                      /*��������*/
    BOOL bEnable;                           /*�����Ƿ�ʹ��*/
    CHAR szLineName[PU_IGT_LINE_NAME_LEN];  /*��������*/
}PU_IGT_TW_LINE_S, *LPPU_IGT_TW_LINE_S;

typedef struct PU_IGT_TW_LINE_LIST
{
    ULONG ulLineNum;
    PU_IGT_TW_LINE_S szTWLineList[PU_TRIPWIRE_LEN_NUM_MAX];
}PU_IGT_TW_LINE_LIST_S;

/* ------------���߼������ṹ��------------ */
typedef struct PU_TW_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulAlarmInterval;                  //�澯�����
    PU_IGT_TARGET_MODE_E  enTargetDetecMode;//Ŀ��ʶ��ģʽ
    PU_IGT_TW_LINE_LIST_S stlineList;       /*�������飺��ȡʱ�᷵�����а���������Ϣ���������Ϊ0˵�����ٵ�ǰ��ͷ��Χ�ڣ��᷵����������*/
                                            /*����ʱ�ò�����ѡ�����ulLineNum������0��ȫ���·ţ�����0ʱ���·�*/
    PU_ALARM_TIME_LIST_S stTWGuardPlan;     //�����ƻ�
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_TW_ALARM_PARA_S, *LPPU_TW_ALARM_PARA_S;

typedef struct PU_IGT_TW_LINE_ITEM
{
    ULONG ulChannelId;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_TW_LINE_S stIgtTwLine;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_TW_LINE_ITEM_S, *LPPU_IGT_TW_LINE_ITEM_S;

/*������*/
typedef struct PU_IGT_AREA
{
    UINT uPointNum;                                                 /*�������ζ�����Ŀ*/
    PU_IGT_POINT_S stPoint[PU_IGT_AREA_POINTS_NUM];                 /*������*/
    ULONG ulAreaIndex;                                              /*��������*/
    BOOL bEnable;                                                   /*�������Ƿ�ʹ��*/
    CHAR szAreaName[PU_IGT_AREA_NAME_LEN];                          /*��������*/
    PU_PTZ_CURRENT_LOCATION_S stLocation;                           /*��̨λ����Ϣ*/
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
    ULONG ulAlarmInterval;                  //�澯�����
    PU_IGT_TARGET_MODE_E enTargetDetecMode; //Ŀ��ʶ��ģʽ
    ULONG ulRemainTime;                     //ͣ��ʱ��(ֻ���ǻ�ʱ��Ч)
    PU_IGT_AERADTC_LIST_S stAreaDtcList;    /*�������飺��ȡʱ�᷵������������Ϣ�������������Ϊ0˵�����ٵ�ǰ��ͷ��Χ�ڣ��᷵����������*/
                                            /*����ʱ�ò�����ѡ�����ulAreaNum������0��ȫ���·ţ�����0ʱ���·�*/
    PU_ALARM_TIME_LIST_S stAreaGuardPlan;   //�����ƻ�
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

//Discover ������Ӧ��
typedef struct PU_DISCOVER_DEVICE_INFO
{
    CHAR  szDeviceMac[PU_MAC_ADDR_LEN];        //�豸MAC��ַ
    CHAR  szDeviceType[PU_DEVICE_TYPE_LEN];    //�豸�ͺ�
    CHAR  szDeviceVersion[PU_VERSION_LEN];     //�豸�汾��
    CHAR  szDeviceName[PU_DEVICE_NAME_LEN];    //�豸����
    CHAR  szDeviceIp[PU_IP4_ADDR_LEN];         //�豸IP
    CHAR  szDeviceMask[PU_IP4_ADDR_LEN];       //�豸����
    CHAR  szDeviceGateway[PU_IP4_ADDR_LEN];    //�豸����
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DISCOVER_DEVICE_INFO_S, *LPPU_DISCOVER_DEVICE_INFO_S;

typedef struct PU_DISCOVER_DEVICE_LIST
{
    ULONG ulDeviceNum;
    PU_DISCOVER_DEVICE_INFO_S stDeviceInfo[PU_DEVICE_NUM_MAX];
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DISCOVER_DEVICE_LIST_S, *LPPU_DISCOVER_DEVICE_LIST_S;

/* ���ڵ�ַ���� */
typedef struct PU_DEVICE_ETHERNET_PARA
{
    BOOL bDhcpEnable;                          //�Ƿ�����DHCP
    CHAR szIPAddress[PU_IP4_ADDR_LEN];         //IP��ַ
    CHAR szSubNetMask[PU_IP4_ADDR_LEN];        //��������
    CHAR szGateWayAddress[PU_IP4_ADDR_LEN];    //���ص�ַ
    CHAR szFirstDNSAddress[PU_IP4_ADDR_LEN];   //��һ��DNS��ַ
    CHAR szSecondDNSAddress[PU_IP4_ADDR_LEN];  //�ڶ���DNS��ַ
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_ETHERNET_PARA_S, *LPPU_DEVICE_ETHERNET_PARA_S;

/* NTP���� */
typedef struct PU_NTP_PARA
{
    BOOL  bNTPEnable;                       //NTPʹ��
    ULONG ulSynInterval;                    //NTPͬ�����
    CHAR  szNTPAddress[PU_DOMAIN_LEN];      //NTP��������ַ:��������IP��ַ
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_NTP_PARA_S, *LPPU_NTP_PARA_S;

//����Ʋ���
typedef struct  PU_IRLIGHT_PARA
{
    BOOL  bEnable;                          //ʹ��
    ULONG ulIRLightLum;                     //����
}PU_IRLIGHT_PARA_S;

typedef struct PU_IRLIGHT_LIST
{
    ULONG ulChannelId;
    PU_IRLIGHT_MODE_E enIRLightMode;
    PU_IRLIGHT_PARA_S stIRLightMPara[PU_IRLIGHT_NUM_MAX];           //��������ݣ��ֶ�ģʽʱ����
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


//��ȡ�������˿������б�
_HW_PU_API BOOL __stdcall IVS_PU_GetDecPortAbility(ULONG ulIdentifyID, LPPU_DEC_PORT_ABILITY_LIST_S pstDecIOAbilityList);

//��ȡ�������˿���Ϣ�б�
_HW_PU_API BOOL __stdcall IVS_PU_GetDecPortInfoList(ULONG ulIdentifyID, LPPU_DEC_PORT_INFO_LIST_S pstDecPortInfoList);

//���ý������˿ڲ���
_HW_PU_API BOOL __stdcall IVS_PU_SetDecPortInfoList(ULONG ulIdentifyID, LPPU_DEC_PORT_INFO_LIST_S pstDecPortInfoList);

//��ȡ������ͨ�������б�
_HW_PU_API BOOL __stdcall IVS_PU_GetDecChannelAbility(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_ABILITY_LIST_S pstDecChannelAbilityList);

//��ȡ������ͨ����Ϣ�б�
_HW_PU_API BOOL __stdcall IVS_PU_GetDecChannelInfoList(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_INFO_LIST_S pstDecChannelInfoList);

//����ͨ������
_HW_PU_API BOOL __stdcall IVS_PU_SetDecChannelInfo(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_INFO_S pstDecChannelInfo);

//���ý������Ľ�����Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_SetDecDecryptionInfo(ULONG ulIdentifyID, LPPU_DEC_DECRYPTION_INFO_S pstDecDecryptionInfo);

//���ý�������Ƶ�˿ڲ���
_HW_PU_API BOOL __stdcall IVS_PU_SetDecAudioPortInfo(ULONG ulIdentifyID, LPPU_DEC_AUDIO_INFO_S pstDecAudioInfo);

//��ȡ��������Ƶ�˿ڲ���
_HW_PU_API BOOL __stdcall IVS_PU_GetDecAudioPortInfo(ULONG ulIdentifyID, LPPU_DEC_AUDIO_INFO_S pstDecAudioInfo);

//��ʼ����
_HW_PU_API LONG __stdcall IVS_PU_StartDec(ULONG ulIdentifyID, LPPU_DEC_INFO_S *pstDecInfo);

//�����������������,ֻ֧��25֡�ķ���
_HW_PU_API BOOL __stdcall IVS_PU_MatrixSendData(ULONG ulPassiveHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType);

//�����������������,֧�ֶ�̬�޸�֡��
_HW_PU_API BOOL __stdcall IVS_PU_MatrixSendDataEx(ULONG ulPassiveHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType, ULONG ulFrameRate);

//��ʼ������ҵ��
_HW_PU_API BOOL __stdcall IVS_PU_InitDecBusiness(ULONG ulIdentifyID, ULONG ulChannelId, PU_PROTOCOL_TYPE_E enProtocolType, LPPU_INIT_DECODE_INFO_RSP_S pstInitDecRspInfo);

//��ʼ����ҵ��
_HW_PU_API BOOL __stdcall IVS_PU_StartDecBusiness(ULONG ulIdentifyID, LPPU_START_DECODE_INFO_S pstStartDecInfo);

//ֹͣ����
_HW_PU_API BOOL __stdcall IVS_PU_StopDec(ULONG ulIdentifyID, ULONG ulChannelId);

//ֹͣ���н���
_HW_PU_API BOOL __stdcall IVS_PU_StopDecAll(ULONG ulIdentifyID);



/*******************************************************************************************************************/
/*                                             SDK Function Declaration                                            */
/*******************************************************************************************************************/


#endif 
