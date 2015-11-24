/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_func.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 
        Author: c00510 
   Description: ���ļ�������sdk��صĴ����롢�ꡢö�١��ṹ�塢�����ӿ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------

*******************************************************************************/
#ifndef __IMOS_SDK_FUNC_H__
#define __IMOS_SDK_FUNC_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

/**
* ƴ֡ǰý�������ݻص�������ָ�����͡�\n
* @param [IN] ulStreamHandle   �����
* @param [IN] pucBuffer        ƴ֡ǰý�������ݻ�����ָ��
* @param [IN] ulBufSize        ��������С
* @param [IN] ulMediaDataType  ý���������ͣ��μ�ý�����Ͷ���: IMOS_MW_MEDIA_DATA_TS
* @param [IN] lUserParam       �û����ò��������û��ڵ��� IMOS_MW_SetOrgMediaDataCallback ����ʱָ�����û�����
* @param [IN] lReserved        ���ƴ֡ǰý������չ��Ϣ������ָ�룬�û���Ҫת��Ϊ# IMOS_MW_SOURCE_DATA_EX_INFO_S
*                              �ṹ��ָ�����ͣ��ں���������ǩ��DecoderTag�������û�ʹ�ò��ſ�������ʾ�ص�
*                              ��ý����ʱ���ɸ��ݽ�������ǩָ����������
* @return �ޡ�
* @note 
* -     �û�Ӧ��ʱ���������ý�������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL* IMOS_MW_SOURCE_MEDIA_DATA_CALLBACK_PF)(IN ULONG ulStreamHandle,
                                                              IN const UCHAR *pucBuffer,
                                                              IN ULONG ulBufSize,
                                                              IN ULONG ulMediaDataType,
                                                              IN LONG lUserParam,
                                                              IN LONG lReserved);

/**
* ƴ֡����Ƶ�����ݻص�������ָ�����͡�\n
* @param [IN] ulStreamHandle        �����
* @param [IN] pstParseVideoData     ���ƴ֡����Ƶ��������Ϣ������ָ��
* @param [IN] lUserParam            �û����ò��������û��ڵ���IMOS_MW_SetParseVideoDataCallback����ʱָ�����û�����
* @param [IN] lReserved             ��������
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ������������ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
*/
typedef VOID (STDCALL *IMOS_MW_PARSE_VIDEO_DATA_CALLBACK_PF)(IN ULONG ulStreamHandle,
                                                             IN const IMOS_MW_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                             IN LONG lUserParam,
                                                             IN LONG lReserved);

/**
* �������Ƶ�����ݻص�������ָ�����͡�\n
* @param [IN] ulStreamHandle   �����
* @param [IN] pPictureData     ��Ž������Ƶ��������Ϣ������ָ��
* @param [IN] lUserParam       �û����ò��������û��ڵ���IMOS_MW_SetDecodedVideoDataCallback����ʱָ�����û�����
* @param [IN] lReserved        ��������
* @return �ޡ�
* @note
* -     1���û�Ӧ��ʱ�����������Ƶ�����ݣ�ȷ���������췵�أ������Ӱ�첥�����ڵ�ý��������
* -     2����Ƶ������yv12��ʽ������˳��Y0-Y1-......������U0-U1-......������V0-V1-......��
*/
typedef VOID (STDCALL* IMOS_MW_DECODE_VIDEO_DATA_CALLBACK_PF)(IN ULONG ulStreamHandle,
                                                              IN const IMOS_MW_PICTURE_DATA_S *pstPictureData,
                                                              IN LONG lUserParam,
                                                              IN LONG lReserved);

#if 0
#endif
/*************************************************************************************
SDK Init
***************************************************************************************/
/** @defgroup groupSDKInit SDK��ʼ����ע��
*   SDK��ʼ������ϸ�ĵ���������ϵ��μ�SDK˵���ĵ�����ģ�������ʼ���ӿں���սӿڡ�
*   @{
*/
/**
 * SDK��ʼ�� \n
 * @param [IN] ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_CREATE_THREAD_FAIL         �����߳�ʧ��
 * -             #ERR_SDK_XP_INIT_FAILED             ��������ʼ��ʧ��
 * -             #ERR_SDK_REINIT                     SDK �Ѿ���ʼ��
 * -             #ERR_SDK_COMMON_NO_MEMORY           ���治��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Initiate(VOID);

/**
 * SDK��Դ�ͷ� \n
 * @param [IN] �� 
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Cleanup(VOID);
/** @} */ /* end of SDKInit Module */

#if 0
#endif
/*************************************************************************************
SDK Info
***************************************************************************************/
/** @defgroup groupSDKInfo SDK��־����Ϣ
*   SDK��־��¼�Ͱ汾��Ϣ
*   @{
*/
/**
 * ��ȡSDK�汾�� \n
 * @param [OUT]pucVersion     �汾�ţ�����: IMOS_MW_SDK_CLIENT_VERSION_LEN
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * @note 
 * -     �������豣ָ֤����ָ����ڴ泤�Ȳ�С��: IMOS_MW_SDK_CLIENT_VERSION_LEN
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetSDKVersion(OUT UCHAR *pucVersion);

/**
 * ����SDK��־��Ϣ \n
 * @param [IN] ulLogLevel  ��־���𣬲μ�: IMOS_SDK_LOG_CLOSE ��
 * @param [IN] pcLogPath   ����·��
 * @param [IN] ulLogSize   ��־��С
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_LOG_CLOSE                  ��־�ѹر�
 * @note 
 * -     1����־����ĺ��壬ʵ�ʼ�¼���и������ü������־��Ϣ����������Ϊ: IMOS_SDK_LOG_INFO��
 * -     2����־����·����ָ����·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ���
 * -     3��SDKĬ����־�ļ����� "IMOS_MW_SDK00.log", Ĭ�ϵ�����־�ļ���СΪ1.5M�������ô�Сʱ����������־�ļ�����Ϊ"IMOS_MW_SDK01.log", �����¼�¼��ԭ�ļ��С�
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetLog(IN ULONG ulLogLevel, 
                                         IN CHAR *pcLogPath, 
                                         IN ULONG ulLogSize);
/** @} */ /* end of SDKInfo Module */

#if 0
#endif
/*************************************************************************************
Status Report
***************************************************************************************/
/** @defgroup groupStatusReport ����״̬�ϱ��ص�����
*   �����豸�����е�״̬���쳣��Ϣ�Ĵ�����
*   @{
*/
/**
 * SDK״̬�ϱ��ص����� \n
 * @param [IN] pcUserID          �û�ID, ��ʾ��ǰ�ϱ�״̬���û�
 * @param [IN] ulReportType      ��Ϣ�����쳣��Ϣ���ͣ��μ� IMOS_MW_STATUS_KEEPALIVE ��
 * @param [IN] pParam            �����Ϣ���쳣��Ϣ���ݵĻ�����ָ��
 * @return ULONG
 * @note 
 * -     1���û���Ҫȷ���ûص��������췵��
 * -     2�������ڸûص�������ֱ�ӵ��ò��������κνӿں�����
 * -     3������pParam��ָ�Ļ������д�ŵ����ݵ���������Ϣ�����쳣��Ϣ���Ͷ������û���Ҫ������Ϣ�����쳣��Ϣ���Ͷ���������ת��
 */
typedef VOID (STDCALL* IMOS_MW_STATUS_REPORT_CALLBACK_PF)(IN CHAR *pcUserID,
                                                          IN ULONG ulReportType, 
                                                          IN VOID *pParam);
/**
 * ����״̬�ϱ��ص����� \n
 * @param [IN] pfStatusReportCB       SDK״̬�ϱ��ص������ĺ���ָ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * @note 
 * -     1���û���Ҫȷ���ûص��������췵�ء�
 * -     2�������ڸûص�������ֱ�ӵ��ò�����SDK���κνӿں�����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetStatusCallback(IN IMOS_MW_STATUS_REPORT_CALLBACK_PF pfStatusReportCBFun);
/** @} */ /* end of StatusReport Module */  

#if 0
#endif
/*************************************************************************************
User Login
***************************************************************************************/
/** @defgroup groupUserLogin �û���¼
*   SDK�û���¼���ǳ�
*   @{
*/
/**
 * �û���¼ \n
 * @param [IN]  pcUserName        �û�����ĵ�¼��������Ϊ IMOS_MW_USER_NAME_LEN
 * @param [IN]  pcPassword        �û���������룬����Ϊ IMOS_MW_USER_PASSWORD_LEN
 * @param [IN]  pcServerIP        Ŀ���ն˵�IP��ַ������Ϊ IMOS_MW_IPADDR_LEN
 * @param [IN]  usServerPort      Ŀ���ն˵Ķ˿ںţ���Ϊ0��������ڲ�����
 * @param [OUT] pcUserID          �û�ID������Ϊ IMOS_MW_RES_CODE_LEN
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       ��������Ƿ�
 * -             #ERR_SDK_NOTINIT                    �豸SDKδ��ʼ��
 * -             #ERR_SDK_USERFULL                   �豸�û�����
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_USER_PASSWD_INVALID        �û��������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     1���ýӿ����ڵ�¼IPC�豸
 * -     2��pcUserID �û���ʶ������Ψһ�ԣ��������豸�Ĳ�������Ҫͨ����IDʵ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Login(IN CHAR *pcUserName,
                                        IN CHAR *pcPassword,
                                        IN CHAR *pcServerIP,
                                        IN USHORT usServerPort,
                                        OUT CHAR *pcUserID);

/**
 * �û�ע�� \n
 * @param [IN]  pcUserID      �û�ID
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       ��������Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     ����������û�ID���ǵ�¼ʱ��ȡ���ġ�
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Logout(IN CHAR *pcUserID);
/** @} */ /* end of UserLogin Module */  

#if 0
#endif
/*************************************************************************************
Device Config
***************************************************************************************/
/** @defgroup groupDeviceConfig ��������
*   ��������
*   @{
*/
/**
 * ��ȡ�豸������Ϣ \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulCmdType          �������ͣ��μ�: IMOS_MW_SYSTEM_TIME_INFO ��
 * @param [IN] ulChannel          ͨ����
 * @param [INOUT] pulBufferLen    �������ݵĻ�������С
 * @param [INOUT] pConfigDataBuf  �����������Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_NOENOUGH_BUF               �����С����
 * @note
 * -     1������ ulChannel ���ڸ������������в�ͬ�ĺ��壬���������ֲ���Ҫ�ò���������Ϊ��Чֵ(0xFFFF)��
 * -     2������ pulBufferLen ���ʱ��ʾ��Ż�ȡ�����õĻ�������С�����α�ʾʵ�ʻ�ȡ��������Ҫ�Ļ�������С��
 *          ���ڲ��ֳ��ȿɱ�����������λ�������С��������Ҫ���ݳ������»�ȡ���á�
 * -     3������ pConfigDataBuf ��ʾ��Ż�ȡ�����õ�ָ�룬���Ӧ�Ľṹ����μ��������ֵ�˵�������в��ֲ����Ļ�ȡ����Ҫ����ָ��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            INOUT ULONG *pulBufferLen,
                                            INOUT VOID *pConfigDataBuf);

/**
 * �����豸������Ϣ \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulCmdType             �������ͣ��μ�: IMOS_MW_SYSTEM_TIME_INFO ��
 * @param [IN] ulChannel             ͨ����
 * @param [IN] ulBufferLen           �������ݵĻ�������С
 * @param [IN] pConfigDataBuf        �����������Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * @note
 * -     1������ ulChannel ���ڸ������������в�ͬ�ĺ��壬���������ֲ���Ҫ�ò���������Ϊ��Чֵ(0xFFFF)��
 * -     2������ pulBufferLen ��ʾ��Ŵ����õ����û�������С��
 * -     3������ pConfigDataBuf ��ʾ����������õ�ָ�룬���Ӧ�Ľṹ����μ��������ֵ�˵�������в��ֲ��������ã���Ҫ����ָ��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            IN ULONG ulBufferLen,
                                            IN VOID *pConfigDataBuf);

/**
 * ɾ���豸������Ϣ \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulCmdType             �������ͣ��μ�: IMOS_MW_INFO_OSD_CFG ��
 * @param [IN] ulChannel             ͨ����
 * @param [IN] ulBufferLen           �������ݵĻ�������С
 * @param [IN] pConfigDataBuf        �����������Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * @note
 * -     1������ ulChannel ���ڸ������������в�ͬ�ĺ��壬���������ֲ���Ҫ�ò���������Ϊ��Чֵ(0xFFFF)��
 * -     2������ pulBufferLen ��ʾ��Ŵ����õ����û�������С��
 * -     3������ pConfigDataBuf ��ʾ����������õ�ָ�룬���Ӧ�Ľṹ����μ��������ֵ�˵�������в��ֲ�����ɾ������Ҫ����ָ��������
 * -     4��֧��ɾ���������У�����OSD���ã��ڸ�OSD���á��˶�����������á��澯��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_DelConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            IN ULONG ulBufferLen,
                                            IN VOID *pConfigDataBuf);
/** @} */ /* end of Device Config Module */  

#if 0
#endif
/*************************************************************************************
Real Play
***************************************************************************************/
/** @defgroup groupRealPlay ʵ������
*   ʵ������
*   @{
*/
/**
 * ����(����)ý���� \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulChannel             ͨ����, ����չ
 * @param [IN] ulStreamID            ��ID, �μ� IMOS_MW_STREAM_ID_MAIN ��
 * @param [IN] ulTransMode           ������ģʽ���μ� IMOS_MW_TRANSFER_MODE_RTP_UDP ��
 * @param [IN] pcIpAddress           �������ն�IP��ַ, 
 * @param [IN] usPort                �������ն˶˿�, ���˿�Ϊ0, ����SDK�ڲ�������ն˿�
 * @param [IN] bKeepAlive            �������־�����������ڵ���������ʱ���� BOOL_FALSE
 * @param [OUT] pulStreamHandle      �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������  
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ����ʧ��
 * -             #ERR_SDK_SOCKET_LSN_FAIL            ����Socketʧ��
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       ��ȡ��������Դʧ��
 * -             #ERR_SDK_DEVICE_STREAM_FULL         �豸������
 * -             #ERR_SDK_XP_START_STREAM_FAILED     ý��������ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     1���������ն�IP��ַ��Ϊ: ""�� NULL, �� "0.0.0.0" ����ʾ����ip, ���ն˶�ipΪ����ʱ�ɲ�ָ���˿ں�(��0)
 * -     2������IPC�豸ʵ�����Ľ���
 * -     3����ȡ��������������ں��������Ĵ���
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartMediaStream(IN CHAR *pcUserID,
                                                   IN ULONG ulChannel,
                                                   IN ULONG ulStreamID,
                                                   IN ULONG ulTransMode,
                                                   IN CHAR *pcIpAddress,
                                                   IN USHORT usPort,
                                                   IN BOOL_T bKeepAlive,
                                                   OUT ULONG *pulStreamHandle);

/**
 * ��ʼ����ý���� \n
 * @param [IN] ulWndHandle     ���Ŵ��ھ��
 * @param [IN] ulStreamHandle  ý�������
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ�� 
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       XP��Դ����ʧ��
 * -             #ERR_SDK_XP_START_STREAM_FAILED     ������ʧ��
 * -             #ERR_SDK_XP_START_PLAY_FAILED       �������Ĳ���ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartPlay(IN ULONG ulWndHandle,
                                            IN ULONG ulStreamHandle);

/**
 * ֹͣý�������� \n
 * @param [IN] ulWndHandle     ���Ŵ��ھ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note 
 * -     �������Ĳ��ţ�����Ҫ��¼�豸
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopPlay(IN ULONG ulWndHandle);

/**
 * ɾ��(ֹͣ)ý���� \n
 * @param [IN] pcUserID         �û�ID
 * @param [IN] ulStreamHandle   ���������ʶһ����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMAND_SEND_FAIL          ��Ϣ����ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * @note 
 * -     ����IPC�豸ʵ������ɾ����������� IMOS_MW_StartMediaStream ��ȡ����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopMediaStream(IN CHAR *pcUserID,
                                                  IN ULONG ulStreamHandle);

/**
 * ��ʼʵ������(������ָ������) \n
 * @param [IN] pcUserID          �û�ID
 * @param [IN] ulChannel         ͨ����
 * @param [IN] ulStreamID        ��ID(��������), �μ�: IMOS_MW_STREAM_ID_MAIN ��
 * @param [IN] ulTransMode       ������ģʽ, �μ�: IMOS_MW_TRANSFER_MODE_RTP_UDP ��
 * @param [IN] ulWndHandle       ���Ŵ��ھ��
 * @param [OUT] pulStreamHandle  �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ����ʧ��
 * -             #ERR_SDK_USERNONEXIST               �û�������  
 * -             #ERR_SDK_SOCKET_LSN_FAIL            ����Socketʧ��
 * -             #ERR_SDK_DEVICE_STREAM_FULL         �豸������
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       ��ȡ��������Դʧ��
 * -             #ERR_SDK_XP_START_STREAM_FAILED     ý��������ʧ��
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       XP��Դ����ʧ��
 * -             #ERR_SDK_XP_START_PLAY_FAILED       �������Ĳ���ʧ��
 * @note 
 * -     1������IPC�豸ʵ�����Ľ������洢�ط����Ľ���, ����ָ�����ڲ���
 * -     2����ȡ��������������ں�����ʵ�������洢�ط�����ֹͣ
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_RealPlay(IN CHAR *pcUserID,
                                           IN ULONG ulChannel,
                                           IN ULONG ulStreamID,
                                           IN ULONG ulTransMode,
                                           IN ULONG ulWndHandle,
                                           OUT ULONG *pulStreamHandle);

/**
 * ֹͣʵ�����ţ�ָֹͣ�������ʵ���� \n
 * @param [IN] pcUserID            �û�ID
 * @param [IN] ulStreamHandle      �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMAND_SEND_FAIL          ��Ϣ����ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * @note 
 * -      ����ָ�������в��ŵ�ý������ɾ������������ IMOS_MW_RealPlay ����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopRealPlay(IN CHAR *pcUserID,
                                               IN ULONG ulStreamHandle);
                                               
/**
 * ��ʼ�ಥ����(������ָ������) \n
 * @param [IN] ulWndHandle          ���Ŵ��ھ��
 * @param [IN] pcLocalIP            ���ص�ַ
 * @param [IN] pcMulticastIP        �ಥԴ��ַ
 * @param [IN] usMulticastPort      �ಥĿ�Ķ˿�
 * @param [OUT] pulStreamHandle     �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ����ʧ��
 * -             #ERR_SDK_SOCKET_LSN_FAIL            ����Socketʧ��
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       XP��Դ����ʧ��
 * -             #ERR_SDK_XP_START_PLAY_FAILED       �������Ĳ���ʧ��
 * @note 
 * -     1������IPC�豸�ಥ���Ľ�������ָ�����ڲ���
 * -     2����ȡ��������������ں����Ը�·��������
 * -     3�����ص�ַ����д�����鲥����IP��ַ
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartMulticastPlay(IN ULONG ulWndHandle,
                                                     IN CHAR *pcLocalIP,
                                                     IN CHAR *pcMulticastIP,
                                                     IN USHORT usMulticastPort,
                                                     OUT ULONG *pulStreamHandle);

/**
 * ֹͣ�ಥ���ţ�ָֹͣ�������ʵ���� \n
 * @param [IN] ulStreamHandle      �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * @note 
 * -      ����ɾ��ָ�������в��ŵĶಥ������������ IMOS_MW_StartMulticastPlay ����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopMulticastPlay(IN ULONG ulStreamHandle);

/** @} */ /* end of Real Play Module */  

                                      

#if 0
#endif
/*************************************************************************************
Stream Data
***************************************************************************************/
/** @defgroup groupStreamData ���û�ȡý�������ݻص�
*   ý�������ݻ�ȡ�ص�������
*   @{
*/
/**
 * ����ƴ֡ǰý�������ݻص����� \n
 * @param [IN] ulStreamHandle          �����
 * @param [IN] pfnSourceMediaDataCBFun ƴ֡ǰý�������ݻص�������ָ��
 * @param [IN] bContinue               �Ƿ�������к����ƴ֡
 * @param [IN] lUserParam              �û����ò���
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * @note 
 * -     1���ú�����#IMOS_MW_StartPlay֮ǰ��֮����ã���#IMOS_MW_StopPlayʱ�Զ�ʧЧ��
 * -     2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ����ΪNULL��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetOrgMediaDataCallback(IN ULONG ulStreamHandle,
                                                          IN IMOS_MW_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun, 
                                                          IN BOOL_T bContinue,
                                                          IN LONG lUserParam);

/**
 * ����ƴ֡����Ƶ���ݻص����� \n
 * @param [IN] ulStreamHandle          �����
 * @param [IN] pfnParseVideoDataCBFun  ƴ֡����Ƶ���ݻص�������ָ��
 * @param [IN] bContinue               �Ƿ�������к���Ĳ��Ų���
 * @param [IN] lUserParam              �û����ò���
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * @note 
 * -    1���ú�����#IMOS_MW_StartPlay֮ǰ��֮����ã���#IMOS_MW_StopPlayʱ�Զ�ʧЧ��
 * -    2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ����ΪNULL��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetParseVideoDataCallback(IN ULONG ulStreamHandle,
                                                            IN IMOS_MW_PARSE_VIDEO_DATA_CALLBACK_PF pfnParseVideoDataCBFun, 
                                                            IN BOOL_T bContinue,
                                                            IN LONG lUserParam);

/**
 * ���ý������Ƶ���ݻص����� \n
 * @param [IN] ulStreamHandle             �����
 * @param [IN] pfnDecodeVideoDataCBFun    �������Ƶý�������ݻص�������ָ��
 * @param [IN] bContinue                  �Ƿ�������к������ʾ����
 * @param [IN] lUserParam                 �û����ò���
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * @note 
 * -    1���ú�����#IMOS_MW_StartPlay֮ǰ��֮����ã���#IMOS_MW_StopPlayʱ�Զ�ʧЧ��
 * -    2���ص�����Ҫ���췵�أ����Ҫֹͣ�ص������԰ѻص�����ָ����ΪNULL��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetDecodedVideoDataCallback(IN ULONG ulStreamHandle,
                                                              IN IMOS_MW_DECODE_VIDEO_DATA_CALLBACK_PF pfnDecodeVideoDataCBFun, 
                                                              IN BOOL_T bContinue,
                                                              IN LONG lUserParam);
/** @} */ /* end of Stream Data Module */


#if 0
#endif
/*************************************************************************************
Video Statistics
***************************************************************************************/
/** @defgroup groupVideoStatistics ʵ��ͳ����Ϣ
*   ʵ��ͳ����Ϣ
*   @{
*/
/**
 * ��ȡ��Ƶ�����ʽ \n
 * @param [IN] ulStreamHandle      ����� 
 * @param [IN] pulVideoEncodeType  ��Ƶ�����ʽ, �μ�: IMOS_MW_STREAM_FORMAT_H264 �� 
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetVideoEncodeType(IN ULONG ulStreamHandle, 
                                                     OUT ULONG *pulVideoEncodeType);
/**
 * ��ȡ��Ƶͳ����Ϣ \n
 * @param [IN] ulStreamHandle       ����� 
 * @param [OUT] pstVideoParam       ��Ƶ�������
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetVideoParam(IN ULONG ulStreamHandle, 
                                                OUT IMOS_MW_VIDEO_PARAM_S *pstVideoParam);
/**
 * ��λ������ \n
 * @param [IN]  ulStreamHandle      ����� 
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ResetLostPacketRate(IN ULONG ulStreamHandle);

/**
 * ��λ��֡�� \n
 * @param [IN]  ulStreamHandle    ����� 
 * @param [OUT] pulRecvPktNum     ����ѽ��յ�������ָ��
 * @param [OUT] pulLostPktNum     ��Ŷ���������ָ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ResetLostFrameRate(IN ULONG ulStreamHandle);
/** @} */ /* end of Video Statistics Module */  

#if 0
#endif
/*************************************************************************************
Display Param
***************************************************************************************/
/** @defgroup groupDisplayParam ��ʾ����
*   ��ʾ����
*   @{
*/
/**
 * ����ָ������ͨ������Ƶͼ����ʾ������\n
 * @param [IN] ulWndHandle   ���Ŵ��ھ����
 * @param [IN] ulRenderScale ��Ƶͼ���ڲ���ͨ���ϵ���ʾ����, �μ�: IMOS_MW_RENDER_SCALE_FULL ��
 * @return ULONG���������´����룺
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          ����ͨ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ�� 
 * @note
 * -    1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ������������Ŵ���
 * -    2������IMOS_MW_StartPlay֮������, ʵʱ��Ч
 * -    3���ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetRenderScale(IN ULONG ulWndHandle, 
                                                 IN ULONG ulRenderScale);

/**
 * ����ͼ��ĶԱȶȲ�������ʱ�����á�\n
 * @param [IN] ulWndHandle           ���Ŵ��ھ����
 * @param [IN] ulContrastMode        ͼ��Աȶ�ģʽ���μ�: IMOS_MW_PICTURE_CONTRAST_MODE_NONE ��
 * @param [IN] ulContrastLevel       ͼ��Աȶȼ��𣬷�Χ: 1-10
 * @return ULONG���������´����룺
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          ����ͨ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note
 * -    1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ�ϲ����жԱȶȵ��ڴ���
 * -    2���ڿ�ʼ����IMOS_MW_StartPlay֮ǰ���ã���Ϊ��������ʱ�ĳ�ʼֵ, �ڿ�ʼ���ź���Ч��
 * -    3�����øýӿڶ�ָ������ͨ�����õĶԱȲ����ڲ����������ڼ�һֱ��Ч��������ulContrastMode
 *         ����IMOS_MW_PICTURE_CONTRAST_MODE_NONEʱ����ֹͣ�Աȶȵ��ڴ�����ʱulContrastLevel������
 *         ���ֵ��Ч��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPictureContrast(IN ULONG ulWndHandle, 
                                                     IN ULONG ulContrastMode,
                                                     IN ULONG ulContrastLevel);

/**
 * ����˸����\n
 * @param [IN] ulWndHandle            ���Ŵ��ھ����
 * @param [IN] ulWinSize              �ο�֡������Χ: 0-100
 * @param [IN] ulSoftenVal            ֡���˲�����, ��Χ: 0-30
 * @param [IN] bOpen                  �Ƿ���������˸����
 * @return ULONG���������´����룺
 * -         #ERR_COMMON_SUCCEED                     �ɹ�
 * -         #ERR_SDK_XP_PORT_NOT_EXIST              ����ͨ��������
 * -         #ERR_SDK_COMMON_FAIL                    ����ʧ��
 * @note
 * -    1���ڲ����øýӿڵ�����£���Ƶͼ��Ĭ�ϲ����жԱȶȵ��ڴ���
 * -    2������IMOS_MW_StartPlay֮�����ã�
 * -    3���ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetAntiFlicker(IN ULONG ulWndHandle,
                                                 IN ULONG ulWinSize, 
                                                 IN ULONG ulSoftenVal,
                                                 IN BOOL_T bOpen);

/**
* ģ������\n
* @param [IN] ulWndHandle        ���Ŵ��ھ����
* @param [IN] ulFactor           ģ���������, ��Χ: 1-127��Ĭ��Ϊ80
* @param [IN] bOpen              �Ƿ�����ģ������
* @return ULONG���������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_SDK_XP_PORT_NOT_EXIST              ����ͨ��������
* -         #ERR_SDK_COMMON_FAIL                    ����ʧ��
* @note
* -    1���ú�����Ҫ��IMOS_MW_StartPlay֮���IMOS_MW_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ�����ģ������
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetVideoMotionBlur(IN ULONG ulWndHandle,
                                                     IN ULONG ulFactor,
                                                     IN BOOL_T bOpen);

/**
* �񻯴���\n
* @param [IN] ulWndHandle        ���Ŵ��ھ����
* @param [IN] fSigma             �񻯴������, ��Χ: 0.0--2.0��Ĭ��Ϊ0.05
* @param [IN] bOpen              �Ƿ������񻯴���
* @return ULONG���������´����룺
* -         #ERR_COMMON_SUCCEED                     �ɹ�
* -         #ERR_SDK_XP_PORT_NOT_EXIST              ����ͨ��������
* -         #ERR_SDK_COMMON_FAIL                    ����ʧ��
* @note
* -    1���ú�����Ҫ��IMOS_MW_StartPlay֮���IMOS_MW_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ������񻯴���
* -    3���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetVideoSharpen(IN ULONG ulWndHandle,
                                                  IN FLOAT fSigma,
                                                  IN BOOL_T bOpen);

/**
* Ӱ�����\n
* @param [IN] ulWndHandle        ����ͨ����
* @param [IN] pstAdjust          Ӱ����ڲ���
* @param [IN] bOpen              �Ƿ��Ӱ�����
* @return ULONG���������´����룺
* -         #ERR_COMMON_SUCCEED                 �ɹ�
* -         #ERR_SDK_COMMON_INVALID_PARAM       ���������Ч
* -         #ERR_SDK_XP_PORT_NOT_EXIST          ����ͨ��������
* -         #ERR_SDK_COMMON_FAIL                ����ʧ��
* @note
* -    1���ú�����Ҫ��IMOS_MW_StartPlay֮���IMOS_MW_StopPlay֮ǰ���á�
* -    2��Ĭ�ϲ�����Ӱ����ڡ�
* -    3��Ӱ����ڲ����У��Աȶ�ȡֵ��ΧΪ[0--199]��Ĭ��ֵΪ100��
* -                       ����ȡֵ��ΧΪ[0--199]��Ĭ��ֵΪ100��
* -                       ɫ��ȡֵ��ΧΪ[0--359]��Ĭ��ֵΪ0��
* -                       ���Ͷ�ȡֵ��ΧΪ[0--359]��Ĭ��ֵΪ100��
* -                       ٤��ȡֵ��ΧΪ[0--99]��Ĭ��ֵΪ10��
* -    4���ýӿں�����֧��Windows��
*/
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetVideoAdjust(IN ULONG ulWndHandle,
                                                 IN IMOS_MW_VIDEO_ADJUST_S *pstAdjust,
                                                 IN BOOL_T bOpen);

/**
 * ���ò���ͼ�������Ի�ʵʱ�ԡ�\n
 * @param [IN] ulWndHandle        ���Ŵ��ھ����
 * @param [IN] ulPictureFluency   ����ͼ����ʵʱ�����Ȼ������������ȣ��μ�: IMOS_MW_PICTURE_TIME_PRIORITY ��
 * @return ULONG���������´����룺
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * @note
 * -    1���ú�����������������������������ʱͼ��������ԣ��Ա����ļ��ط�ʱͼ��������ý��������ã�
 * -    2���ýӿ���Ҫ��IMOS_MW_StartPlay֮ǰ���ã�������ʵ�ֻ���Դ��ھ��������
 * -    3������û������øú������ò���ͼ�������ԣ��򲥷����ڲ�Ĭ��ʹ��ͼ��ʵʱ�����ȣ�
 * -    4���ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPictureFluency(IN ULONG ulWndHandle, 
                                                    IN ULONG ulPictureFluency);
                                                    
/**
 * ������Ƶ��ʾ����  \n
 * @param [IN] pstDisplayParam    ��Ƶ��ʾ����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -     1�����ò��������в���ͨ�������ã�
 * -     2������û������øú���������ʾ�������򲥷����ڲ�Ĭ��ʹ��YUV420��Ƶ���ظ�ʽ��D3D����ʾģʽ
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetDisplayParam(IN IMOS_MW_DISPLAY_PARAM_S *pstDisplayParam);
/** @} */ /* end of Display Param Module */  


#if 0
#endif
/*************************************************************************************
Get StreamInfo
***************************************************************************************/
/** @defgroup groupGetStreamInfo ��ȡý������Ϣ
*   ��ȡý������Ϣ
*   @{
*/

/**
 * ��ȡý������Ϣ \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulChannel             ͨ����
 * @param [INOUT] pulBufferLen       ���ڱ����ȡ����Ļ�������С
 * @param [OUT] pstStreamInfo        ����Ϣ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_NOENOUGH_BUF               �����С����
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     �ýӿ��з��ص�������ͨ�� IMOS_MW_StopMediaStream �ر�
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetMediaStreamInfo(IN CHAR *pcUserID,
                                                     IN ULONG ulChannel,
                                                     INOUT ULONG *pulBufferLen,
                                                     OUT IMOS_MW_VIDEO_STREAM_INFO_S *pstStreamInfo);
/** @} */ /* end of Get StreamInfo Module */  

#if 0
#endif
/*************************************************************************************
Audio Play
***************************************************************************************/
/** @defgroup groupAudioPlay ����ҵ��
*   ����ҵ��
*   @{
*/
/**
 * ���������Խ� \n
 * @param [IN] pcUserID               �û�ID
 * @param [IN] ulTranProtocol         ������Э��, �μ�: IMOS_MW_PROTOCOL_UDP ��
 * @param [OUT] pulVoiceTalkHandle    �����Խ����
 * @return ULONG���������½����
 * -        #ERR_COMMON_SUCCEED                 �ɹ�
 * -        #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -        #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -        #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -        #ERR_SDK_SOCKET_LSN_FAIL            ����Socketʧ��
 * -        #ERR_SDK_XP_START_STREAM_FAILED     XP ����ҵ������ʧ��
 * -        #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -        #ERR_SDK_XP_PORT_ALLOC_FAILED       ��ȡ����ͨ����Դʧ��
 * -        #ERR_SDK_XP_START_STREAM_FAILED     ����ҵ������ʧ��
 * -        #ERR_SDK_XP_AUDIO_DEVICE_UNRIPE     ��Ƶ�豸δ׼����
 * -        #ERR_SDK_BIAUDIO_AUDIOBCAST_FULL    �豸����ҵ������
 * @note 
 * -      Ŀǰ����ҵ��Ĵ���Э���֧��UDP
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartVoiceTalk(IN CHAR *pcUserID,
                                                 IN ULONG ulProtocol,
                                                 OUT ULONG *pulVoiceTalkHandle);

/**
 * ֹͣ�����Խ� \n
 * @param [IN] pcUserID                �û�ID
 * @param [IN] ulVoiceTalkHandle       �����Խ����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          ͨ��������
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopVoiceTalk(IN CHAR *pcUserID,
                                                IN ULONG ulVoiceTalkHandle);

/**
 * ���������㲥 \n
 * @param [IN] pcUserID             �û�ID
 * @param [IN] ulTranProtocol       ������Э��, �μ�: IMOS_MW_PROTOCOL_UDP ��
 * @param [OUT] pulBroadcastHandle  �����㲥���
 * @return ULONG���������½����
 * -        #ERR_COMMON_SUCCEED                 �ɹ�
 * -        #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -        #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -        #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -        #ERR_SDK_SOCKET_LSN_FAIL            ����Socketʧ��
 * -        #ERR_SDK_XP_START_STREAM_FAILED     XP ����ҵ������ʧ��
 * -        #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -        #ERR_SDK_XP_PORT_ALLOC_FAILED       ��ȡ����ͨ����Դʧ��
 * -        #ERR_SDK_XP_START_STREAM_FAILED     ����ҵ������ʧ��
 * -        #ERR_SDK_XP_AUDIO_DEVICE_UNRIPE     ��Ƶ�豸δ׼����
 * -        #ERR_SDK_BIAUDIO_AUDIOBCAST_FULL    �豸����ҵ������
 * @note 
 * -      Ŀǰ����ҵ��Ĵ���Э���֧��UDP
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartVoiceBroadcast(IN CHAR *pcUserID,
                                                      IN ULONG ulProtocol,
                                                      OUT ULONG *pulBroadcastHandle);

/**
 * ֹͣ�����㲥 \n
 * @param [IN] pcUserID                �û�ID
 * @param [IN] ulBroadcastHandle       �����㲥���
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          ͨ��������
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopVoiceBroadcast(IN CHAR *pcUserID,
                                                     IN ULONG ulBroadcastHandle);

/** @} */ /* end of Audio Play Module */  

#if 0
#endif
/*************************************************************************************
Audio Ctrl
***************************************************************************************/
/** @defgroup groupAudioCtrl ��������
*   ��������
*   @{
*/
/**
 * ������ \n
 * @param [IN] ulStreamHandle  �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -     1��ͬһʱ��ֻ�ܲ���һ·��������������Ѿ��������򿪣����Զ��ر�ԭ���Ѿ��򿪵�������Ĭ�Ϲرա�
 * -     2���ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PlaySound(IN ULONG ulStreamHandle);

/**
 * �ر����� \n
 * @param [IN] ulStreamHandle   �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -      �ýӿں�����֧��Windows
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopSound(IN ULONG ulStreamHandle);

/**
 * �����˷����� \n
 * @param [OUT] pulMicVolume    ��˷���������Χ��0��255��255Ϊ���������
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -      �ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetMicVolume(OUT ULONG *pulMicVolume);

/**
 * ������˷����� \n
 * @param [IN] ulMicVolume    ��˷���������Χ��0��255��255Ϊ���������
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -    1���ýӿں�����֧��Windows��
 * -    2��Ӱ��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetMicVolume(IN ULONG ulMicVolume);

/**
 * ��ȡ���������� \n
 * @param [OUT] pulSpeakerVolume    ��������������Χ��0��255��255Ϊ���������
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -      �ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetSpeakerVolume(OUT ULONG *pulSpeakerVolume);

/**
 * �������������� \n
 * @param [IN] ulSpeakerVolume    ��������������Χ��0��255��255Ϊ���������
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note 
 * -     �ýӿں�����֧��Windows��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetSpeakerVolume(IN ULONG ulSpeakerVolume);

/** @} */ /* end of Audio Ctrl Module */

#if 0
#endif

/*************************************************************************************
PTZ Ctrl
***************************************************************************************/
/** @defgroup groupPTZCtrl ��̨����
*   ��̨������ؽӿڣ���Ԥ��λ������ͨ����̨���ơ���̨����λ�ÿ���
*   @{
*/
/**
 * ����Ԥ��λ \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] pstPreset          Ԥ��λ��Ϣ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0
 * - 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPreset(IN CHAR *pcUserID, 
                                            IN ULONG ulChannel,
                                            IN IMOS_MW_PRESET_PARAM_S *pstPreset);

/**
 * ɾ��Ԥ��λ \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] ulPresetID         ��ɾ����Ԥ��λID
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_DelPreset(IN CHAR *pcUserID, 
                                            IN ULONG ulChannel,
                                            IN ULONG ulPresetID);

/**
 * ����Ԥ��λ \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] ulPresetID         ���õ�Ԥ��λID
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GotoPreset(IN CHAR *pcUserID, 
                                             IN ULONG ulChannel,
                                             IN ULONG ulPresetID);

/**
 * ��̨���� \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] pstPtzCommand      ��̨����ָ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PtzCommand(IN CHAR *pcUserID,
                                             IN ULONG ulChannel,
                                             IN IMOS_MW_PTZ_COMMAND_S *pstPtzCommand); 

/**
 * ����Ŵ� \n
 * @param [IN] pcUserID           �û���Ϣ��ʶ
 * @param [IN] ulChannel          ͨ����
 * @param [IN] pstAreaInfo        ������Ϣ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #��������������                   ʧ��
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0,
 * -      �������СΪ0����Ϊ���Ŵ���ʱ����Ϊ3D��λ
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_AreaZoomIn(IN CHAR *pcUserID,
                                             IN ULONG ulChannel,
                                             IN IMOS_MW_PTZ_ZOOMAREA_S *pstAreaInfo); 

/**
 * ������С \n
 * @param [IN] pcUserID           �û���Ϣ��ʶ
 * @param [IN] ulChannel          ͨ����
 * @param [IN] pstAreaInfo        ������Ϣ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #��������������                   ʧ��
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_AreaZoomOut(IN CHAR *pcUserID,
                                              IN ULONG ulChannel,
                                              IN IMOS_MW_PTZ_ZOOMAREA_S *pstAreaInfo);

/**
 * ��̨ʵ��ͬʱ���Ա䱶���ƶ�������λ�� \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] pstAbsZoom         �䱶��Ϣ
 * @param [IN] pstAbsPosition     ��̨����λ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -      1�������б䱶�����λ��Ϊ����ʵ�����Ӧ�ĵ�������
 * -      2��ͨ������δʹ�ã�Ĭ�� 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PTZAbsoluteMove(IN CHAR *pcUserID,
                                                  IN ULONG ulChannel,
                                                  IN IMOS_MW_PTZ_ABSZOOM_S *pstAbsZoom,
                                                  IN IMOS_MW_PTZ_ABSPOSITION_S *pstAbsPosition); 
                                             
/**
 * ��̨ʵ��ָ���ٶȱ䱶��ָ���䱶���ƶ���ָ��λ�� \n
 * @param [IN] pcUserID                 �û�ID
 * @param [IN] ulChannel                ͨ����
 * @param [IN] pstControledZoom   	    �䱶��Ϣ
 * @param [IN] pstControledPosition     ��̨λ�úͽ��ٶ�
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    ����ģʽ��ƥ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -      ͨ������δʹ�ã�Ĭ�� 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PTZMoveWithControledAngularSpeed(IN CHAR *pcUserID,
                                                                   IN ULONG ulChannel,
                                                                   IN IMOS_MW_PTZ_CONTROLEDZOOM_S *pstControledZoom,
                                                                   IN IMOS_MW_PTZ_CONTROLEDPOSITION_S *pstControledPosition);                                         
/** @} */ /* end of PTZ Ctrl Module */

#if 0
#endif
/*************************************************************************************
Device Status
***************************************************************************************/
/** @defgroup groupDeviceStatus ��ȡ�豸״̬
*   ��ȡ�豸״̬�ӿ�
*   @{
*/
/**
 * ��ȡ״̬���� \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] ulCmdType          ״̬��������, �μ�: IMOS_MW_STATUS_KEEPALIVE ��
 * @param [INOUT] pStatusInfo     ״̬��Ϣ, �μ���״̬�������͵� ˵��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * @note 
 * - ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetDeviceStatus(IN CHAR *pcUserID,
                                                  IN ULONG ulChannel,
                                                  IN ULONG ulCmdType, 
                                                  INOUT VOID *pStatusInfo);
/** @} */ /* end of Device Status Module */

#if 0
#endif
/*************************************************************************************
Device Manage
***************************************************************************************/
/** @defgroup groupDeviceManage �豸ά������
*   �豸ά������: �豸ά����ϵͳ�������豸�����������Ϣ���������õ��롢�������ָ�Ĭ�����ã��ָ�Ĭ�ϲ�����
*   @{
*/
/**
 * ϵͳ���� \n
 * @param [IN] pcUserID      �û���Ϣ��ʶ
 * @param [IN] pcFile        �����ļ���·��(���ļ���)
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_UPDATE_BUSY                �����У��������ظ�����
 * -             #ERR_SDK_UPDATE_NOTADMIN            ��admin�û�����������
 * -             #ERR_SDK_CREATE_THREAD_FAIL         �����߳�ʧ��
 * @note ·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ� 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Upgrade(IN CHAR *pcUserID,
                                          IN CHAR *pcFile);

/**
 * ϵͳ���� \n
 * @param [IN] pcUserID    �û���Ϣ��ʶ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Reboot(IN CHAR *pcUserID);

/**
 * ���������ļ� \n
 * @param [IN] pcUserID        �û���Ϣ��ʶ
 * @param [IN] pcFile          ���������Ϣ��·��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     1���������ļ�������ָ��·��(�����ļ���)�£�
 * -     2��·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ��� 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ExportConfig(IN CHAR *pcUserID,
                                               IN CHAR *pcFile);

/**
 * ���������ļ� \n
 * @param [IN] pcUserID        �û���Ϣ��ʶ
 * @param [IN] pcFile          �����ļ�(������·��)
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMON_FAIL_STAT           ��ȡ�ļ�ʧ��
 * -             #ERR_SDK_INVALID_CONFIGFILE         �����ļ��Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     1������ָ��·���µ������ļ�(������·��)
 * -     2��·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ��� 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ImportConfig(IN CHAR *pcUserID,
                                               IN CHAR *pcFile);

/**
 * �ָ��������� \n
 * @param [IN] pcUserID       �û���Ϣ��ʶ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     �ָ���������ʱ�������豸IP��ַ����ҳ����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_RestoreConfig(IN CHAR *pcUserID);

/**
 * �ָ�Ĭ�ϲ��� \n
 * @param [IN] pcUserID       �û���Ϣ��ʶ
 * @param [IN] ulChannel      ͨ����
 * @param [IN] ulParamType    ���ָ��Ĳ�������, �μ�: IMOS_MW_PARAM_TYPE_OPTICS_VIDEO ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                �ɹ�
 * -             #ERR_SDK_COMMON_FAIL               ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM      �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST              �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT           ����ʱ
 * @note 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_RestoreDefaultParam(IN CHAR *pcUserID,
                                                      IN ULONG ulChannel,
                                                      IN ULONG ulParamType);

/**
 * ��ȡ�����Ϣ \n
 * @param [IN] pcUserID             �û���Ϣ��ʶ
 * @param [IN] pcDiagInfoPath       ��������Ϣ��·��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     1���������Ϣ������ָ��·��(�����ļ���)�£�
 * -     2��·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ��� 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ExportDiagnoseInfo(IN CHAR *pcUserID,
                                                     IN CHAR *pcDiagInfoPath);
/** @} */ /* end of Device Manage Module */

#if 0
#endif
/*************************************************************************************
User Manage
***************************************************************************************/
/** @defgroup groupUserManage �û�����
*   �û�����: �û���Ϣ��ȡ���û���Ϣ���ú��û�ɾ��
*   @{
*/
/**
 * ��ȡ�û���Ϣ \n
 * @param [IN] pcUserID         �û���Ϣ��ʶ
 * @param [INOUT] pulBufferLen  �����������ݵĻ�������С��������ȡ���û���Ϣ����
 * @param [INOUT] pstUsersInfo  �û���Ϣ�ṹ
 * @return ULONG���������½����
 * -           #ERR_COMMON_SUCCEED                 �ɹ�
 * -           #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -           #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -           #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -           #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -           #ERR_SDK_NOENOUGH_BUF               ����������
 * @note 
 * -     ����pulBufferLen ��Ϊ��α�ʾ�û�����ı����ȡ����Ļ�������С�����α�ʾʵ���û���Ϣ�Ļ����С
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetUser(IN CHAR *pcUserID,
                                          INOUT ULONG *pulBufferLen,
                                          INOUT IMOS_MW_USER_INFO_S *pstUsersInfo);

/**
 * �����û���Ϣ \n
 * @param [IN] pcUserID        �û���Ϣ��ʶ
 * @param [IN] ulBufferLen     �����������ݵĻ�������С
 * @param [IN] pstUsersInfo    �û���Ϣ�ṹ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_USER_NOT_AUTHORIZED        �û�δ��Ȩ
 * -             #ERR_SDK_USER_PASSWD_INVALID        ������Ч
 * -             #ERR_SDK_USERFULL                   �û�����
 * @note 
 * -     1��֧���û�����Ӻ��޸�
 * -     2���ѵ�¼�û�������Ϣ�޸ĺ󣬱��޸ĵ��û����յ�״̬�ϱ�֪ͨ���˳�����Ӧ״̬ :IMOS_MW_STATUS_USERINFO_CHANGE
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetUser(IN CHAR *pcUserID,
                                          IN ULONG ulBufferLen,
                                          IN IMOS_MW_USER_INFO_S *pstUsersInfo);

/**
 * ɾ���û� \n
 * @param [IN] pcUserID        �û���Ϣ��ʶ
 * @param [IN] ulBufferLen     �����������ݵĻ�������С
 * @param [IN] pstUsersInfo    �û���Ϣ�ṹ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_USER_NOT_AUTHORIZED        �û�δ��Ȩ
 * @note
 * -     1��ֻ��admin�û���Ȩ��ɾ�������û�
 * -     2��admin�û�������ɾ��
 * -     3���ýӿ�֧��һ��ɾ������û�
 * -     4���ѵ�¼�û���ɾ���󣬱�ɾ���û����յ�״̬�ϱ�֪ͨ���˳�,��Ӧ״̬ :IMOS_MW_STATUS_USERINFO_CHANGE
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_DelUser(IN CHAR *pcUserID,
                                          IN ULONG ulBufferLen,
                                          IN IMOS_MW_USER_INFO_S *pstUsersInfo);
/** @} */ /* end of User Manage Module */


#if 0
#endif
/*************************************************************************************
LocalFile Play
***************************************************************************************/
/** @defgroup groupLocalFilePlay �����ļ����ź�ץ��
*   �����ļ�����
*   @{
*/
/**
 * ���ص���ץ�� \n
 * @param [IN] ulStreamHandle �����
 * @param [IN] ulPicType      ͼ���ʽ, �μ�: IMOS_MW_PICTURE_FORMAT_BMP ��
 * @param [IN] pcFileName     ����ͼ����ļ�·���������ļ���(������·��)
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                   �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                  ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM         �����Ƿ�
 * -             #ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH  Ӳ��ʣ��ռ䲻��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST       ý����������
 * @note
 * -     ·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ�������·������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_LocalSnapShot(IN ULONG ulStreamHandle,
                                                IN ULONG ulPicType, 
                                                IN CHAR *pcFileName);
/**
 * �򿪣����أ�ý���ļ� \n
 * @param [IN] pcFilename         �����ļ����ļ�����������·����
 * @param [OUT] pulStreamHandle   �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       ��ȡ����ͨ����Դʧ��
 * @note 
 * -     ·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ�������·������  
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_OpenMediaFile(IN CHAR *pcFilename,
                                                OUT ULONG *pulStreamHandle);

/**
 * �رգ����أ�ý���ļ� \n
 * @param [IN] ulStreamHandle       �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_CloseMediaFile(IN ULONG ulStreamHandle);

/**
 * ��ȡ�ܵ�ʱ�䳤�� \n
 * @param [IN] ulStreamHandle  �����
 * @param [IN] pulTotalTime    �ܵ�ʱ�䳤�ȣ���λ: ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetFileTime(IN ULONG ulStreamHandle, 
                                              OUT ULONG *pulTotalTime);

/**
 * ��ȡ��ǰ����λ�� \n
 * @param [IN] ulStreamHandle  �����
 * @param [IN] pulTime         ��ǰ���Ž���ʱ�䣬��λ: ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetPlayedPosition(IN ULONG ulStreamHandle,
                                                    OUT ULONG *pulTime);

/**
 * ����ʱ�����ò���λ�� \n
 * @param [IN] ulStreamHandle  �����
 * @param [IN] ulTime          ��תĿ��ʱ�䣬��λ: ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPlayedPosition(IN ULONG ulStreamHandle, 
                                                    IN ULONG ulTime);

/**
 * ��ͣ���� \n
 * @param [IN] ulStreamHandle    �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PausePlay(IN ULONG ulStreamHandle);

/**
 * �ָ����� \n
 * @param [IN] ulStreamHandle     �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ResumePlay(IN ULONG ulStreamHandle);

/**
 * ָ�������ٶ� \n
 * @param [IN] ulStreamHandle �����
 * @param [IN] ulSpeed        �����ٶ�, �μ�: IMOS_MW_PLAY_STATUS_16_BACKWARD ��  
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note 
 * -     �����ڿ��Ʋ��ŵĿ��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPlaySpeed(IN ULONG ulStreamHandle,
                                               IN ULONG ulSpeed);
                                               
/**
 * ��ʼ����¼�� \n
 * @param [IN] ulStreamHandle      �����
 * @param [IN] ulMediaFileFormat   ¼���ļ��ĸ�ʽ, �μ�: IMOS_MW_MEDIA_FILE_FORMAT_TS ��
 * @param [IN] pcFileName          ¼���ļ����·���������ļ�����������׺����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                     �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                    ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST         ��������
 * -             #ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH    Ӳ��ʣ��ռ䲻�㣬�޷�����ҵ��  
 * @note 
 * -     ·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ��� 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartLocalRecord(IN ULONG ulStreamHandle,
                                                   IN ULONG ulMediaFileFormat, 
                                                   IN CHAR *pcFileName);
/**
 * ֹͣ����¼�� \n
 * @param [IN] ulStreamHandle       �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     ��������
 * @note  
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopLocalRecord(IN ULONG ulStreamHandle);
/** @} */ /* end of LocalFile Play Module */

#if 0
#endif

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_FUNC_H__*/

