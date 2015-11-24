/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_func.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 
        Author: c00510 
   Description: 该文件定义了sdk相关的错误码、宏、枚举、结构体、函数接口

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
* 拼帧前媒体流数据回调函数的指针类型。\n
* @param [IN] ulStreamHandle   流句柄
* @param [IN] pucBuffer        拼帧前媒体流数据缓冲区指针
* @param [IN] ulBufSize        缓冲区大小
* @param [IN] ulMediaDataType  媒体数据类型，参见媒体类型定义: IMOS_MW_MEDIA_DATA_TS
* @param [IN] lUserParam       用户设置参数，即用户在调用 IMOS_MW_SetOrgMediaDataCallback 函数时指定的用户参数
* @param [IN] lReserved        存放拼帧前媒体流扩展信息缓冲区指针，用户需要转换为# IMOS_MW_SOURCE_DATA_EX_INFO_S
*                              结构体指针类型，内含解码器标签（DecoderTag），当用户使用播放库解码和显示回调
*                              的媒体流时，可根据解码器标签指定解码器。
* @return 无。
* @note 
* -     用户应及时处理输出的媒体流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL* IMOS_MW_SOURCE_MEDIA_DATA_CALLBACK_PF)(IN ULONG ulStreamHandle,
                                                              IN const UCHAR *pucBuffer,
                                                              IN ULONG ulBufSize,
                                                              IN ULONG ulMediaDataType,
                                                              IN LONG lUserParam,
                                                              IN LONG lReserved);

/**
* 拼帧后视频流数据回调函数的指针类型。\n
* @param [IN] ulStreamHandle        流句柄
* @param [IN] pstParseVideoData     存放拼帧后视频流数据信息缓冲区指针
* @param [IN] lUserParam            用户设置参数，即用户在调用IMOS_MW_SetParseVideoDataCallback函数时指定的用户参数
* @param [IN] lReserved             保留参数
* @return 无。
* @note
* -     用户应及时处理输出的数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
*/
typedef VOID (STDCALL *IMOS_MW_PARSE_VIDEO_DATA_CALLBACK_PF)(IN ULONG ulStreamHandle,
                                                             IN const IMOS_MW_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                             IN LONG lUserParam,
                                                             IN LONG lReserved);

/**
* 解码后视频流数据回调函数的指针类型。\n
* @param [IN] ulStreamHandle   流句柄
* @param [IN] pPictureData     存放解码后视频流数据信息缓冲区指针
* @param [IN] lUserParam       用户设置参数，即用户在调用IMOS_MW_SetDecodedVideoDataCallback函数时指定的用户参数
* @param [IN] lReserved        保留参数
* @return 无。
* @note
* -     1、用户应及时处理输出的视频流数据，确保函数尽快返回，否则会影响播放器内的媒体流处理。
* -     2、视频数据是yv12格式。排列顺序“Y0-Y1-......”，“U0-U1-......”，“V0-V1-......”
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
/** @defgroup groupSDKInit SDK初始化和注销
*   SDK初始化，详细的调用依赖关系请参见SDK说明文档。该模块包含初始化接口和清空接口。
*   @{
*/
/**
 * SDK初始化 \n
 * @param [IN] 无
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_CREATE_THREAD_FAIL         创建线程失败
 * -             #ERR_SDK_XP_INIT_FAILED             播放器初始化失败
 * -             #ERR_SDK_REINIT                     SDK 已经初始化
 * -             #ERR_SDK_COMMON_NO_MEMORY           缓存不足
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Initiate(VOID);

/**
 * SDK资源释放 \n
 * @param [IN] 无 
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Cleanup(VOID);
/** @} */ /* end of SDKInit Module */

#if 0
#endif
/*************************************************************************************
SDK Info
***************************************************************************************/
/** @defgroup groupSDKInfo SDK日志和信息
*   SDK日志记录和版本信息
*   @{
*/
/**
 * 获取SDK版本号 \n
 * @param [OUT]pucVersion     版本号，长度: IMOS_MW_SDK_CLIENT_VERSION_LEN
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * @note 
 * -     调用者需保证指针所指向的内存长度不小于: IMOS_MW_SDK_CLIENT_VERSION_LEN
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetSDKVersion(OUT UCHAR *pucVersion);

/**
 * 设置SDK日志信息 \n
 * @param [IN] ulLogLevel  日志级别，参见: IMOS_SDK_LOG_CLOSE 等
 * @param [IN] pcLogPath   保存路径
 * @param [IN] ulLogSize   日志大小
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_LOG_CLOSE                  日志已关闭
 * @note 
 * -     1、日志级别的含义，实际记录所有高于设置级别的日志信息，建议设置为: IMOS_SDK_LOG_INFO。
 * -     2、日志保存路径需指定，路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（包括文件名在内）。
 * -     3、SDK默认日志文件名称 "IMOS_MW_SDK00.log", 默认单个日志文件大小为1.5M，超过该大小时，将已有日志文件备份为"IMOS_MW_SDK01.log", 后重新记录在原文件中。
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
/** @defgroup groupStatusReport 设置状态上报回调函数
*   设置设备运行中的状态或异常消息的处理函数
*   @{
*/
/**
 * SDK状态上报回调函数 \n
 * @param [IN] pcUserID          用户ID, 表示当前上报状态的用户
 * @param [IN] ulReportType      消息或者异常消息类型，参见 IMOS_MW_STATUS_KEEPALIVE 等
 * @param [IN] pParam            存放消息或异常消息数据的缓冲区指针
 * @return ULONG
 * @note 
 * -     1、用户需要确保该回调函数尽快返回
 * -     2、不能在该回调函数中直接调用播放器的任何接口函数。
 * -     3、参数pParam所指的缓冲区中存放的数据的类型视消息或者异常消息类型而定，用户需要根据消息或者异常消息类型对其做类型转换
 */
typedef VOID (STDCALL* IMOS_MW_STATUS_REPORT_CALLBACK_PF)(IN CHAR *pcUserID,
                                                          IN ULONG ulReportType, 
                                                          IN VOID *pParam);
/**
 * 设置状态上报回调函数 \n
 * @param [IN] pfStatusReportCB       SDK状态上报回调函数的函数指针
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * @note 
 * -     1、用户需要确保该回调函数尽快返回。
 * -     2、不能在该回调函数中直接调用播放器SDK的任何接口函数。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetStatusCallback(IN IMOS_MW_STATUS_REPORT_CALLBACK_PF pfStatusReportCBFun);
/** @} */ /* end of StatusReport Module */  

#if 0
#endif
/*************************************************************************************
User Login
***************************************************************************************/
/** @defgroup groupUserLogin 用户登录
*   SDK用户登录、登出
*   @{
*/
/**
 * 用户登录 \n
 * @param [IN]  pcUserName        用户输入的登录名，长度为 IMOS_MW_USER_NAME_LEN
 * @param [IN]  pcPassword        用户输入的密码，长度为 IMOS_MW_USER_PASSWORD_LEN
 * @param [IN]  pcServerIP        目的终端的IP地址，长度为 IMOS_MW_IPADDR_LEN
 * @param [IN]  usServerPort      目的终端的端口号，若为0，则程序内部分配
 * @param [OUT] pcUserID          用户ID，长度为 IMOS_MW_RES_CODE_LEN
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       输入参数非法
 * -             #ERR_SDK_NOTINIT                    设备SDK未初始化
 * -             #ERR_SDK_USERFULL                   设备用户已满
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_USER_PASSWD_INVALID        用户密码错误
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note
 * -     1、该接口用于登录IPC设备
 * -     2、pcUserID 用户标识，具有唯一性，后续对设备的操作都需要通过此ID实现
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Login(IN CHAR *pcUserName,
                                        IN CHAR *pcPassword,
                                        IN CHAR *pcServerIP,
                                        IN USHORT usServerPort,
                                        OUT CHAR *pcUserID);

/**
 * 用户注销 \n
 * @param [IN]  pcUserID      用户ID
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       输入参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note
 * -     输入参数中用户ID，是登录时获取到的。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Logout(IN CHAR *pcUserID);
/** @} */ /* end of UserLogin Module */  

#if 0
#endif
/*************************************************************************************
Device Config
***************************************************************************************/
/** @defgroup groupDeviceConfig 参数配置
*   参数配置
*   @{
*/
/**
 * 获取设备配置信息 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulCmdType          命令类型，参见: IMOS_MW_SYSTEM_TIME_INFO 等
 * @param [IN] ulChannel          通道号
 * @param [INOUT] pulBufferLen    传入数据的缓冲区大小
 * @param [INOUT] pConfigDataBuf  存放输出参数的缓冲区
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_NOENOUGH_BUF               缓存大小不足
 * @note
 * -     1、参数 ulChannel 对于各类型命令字有不同的含义，部分命令字不需要该参数，设置为无效值(0xFFFF)。
 * -     2、参数 pulBufferLen 入参时表示存放获取到配置的缓存区大小，出参表示实际获取到配置需要的缓存区大小；
 *          对于部分长度可变的配置项，若入参缓存区大小不够，需要根据出参重新获取配置。
 * -     3、参数 pConfigDataBuf 表示存放获取到配置的指针，其对应的结构定义参见各命令字的说明，其中部分参数的获取，需要传入指定参数。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            INOUT ULONG *pulBufferLen,
                                            INOUT VOID *pConfigDataBuf);

/**
 * 设置设备配置信息 \n
 * @param [IN] pcUserID              用户ID
 * @param [IN] ulCmdType             命令类型，参见: IMOS_MW_SYSTEM_TIME_INFO 等
 * @param [IN] ulChannel             通道号
 * @param [IN] ulBufferLen           传入数据的缓冲区大小
 * @param [IN] pConfigDataBuf        存放输入参数的缓冲区
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * @note
 * -     1、参数 ulChannel 对于各类型命令字有不同的含义，部分命令字不需要该参数，设置为无效值(0xFFFF)。
 * -     2、参数 pulBufferLen 表示存放待设置的配置缓存区大小。
 * -     3、参数 pConfigDataBuf 表示存待设置配置的指针，其对应的结构定义参见各命令字的说明，其中部分参数的设置，需要传入指定参数。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            IN ULONG ulBufferLen,
                                            IN VOID *pConfigDataBuf);

/**
 * 删除设备配置信息 \n
 * @param [IN] pcUserID              用户ID
 * @param [IN] ulCmdType             命令类型，参见: IMOS_MW_INFO_OSD_CFG 等
 * @param [IN] ulChannel             通道号
 * @param [IN] ulBufferLen           传入数据的缓冲区大小
 * @param [IN] pConfigDataBuf        存放输入参数的缓冲区
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * @note
 * -     1、参数 ulChannel 对于各类型命令字有不同的含义，部分命令字不需要该参数，设置为无效值(0xFFFF)。
 * -     2、参数 pulBufferLen 表示存放待设置的配置缓存区大小。
 * -     3、参数 pConfigDataBuf 表示存待设置配置的指针，其对应的结构定义参见各命令字的说明，其中部分参数的删除，需要传入指定参数。
 * -     4、支持删除的配置有：叠加OSD配置，遮盖OSD配置、运动检测区域配置、告警联动配置
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
/** @defgroup groupRealPlay 实况播放
*   实况播放
*   @{
*/
/**
 * 创建(启动)媒体流 \n
 * @param [IN] pcUserID              用户ID
 * @param [IN] ulChannel             通道号, 待扩展
 * @param [IN] ulStreamID            流ID, 参见 IMOS_MW_STREAM_ID_MAIN 等
 * @param [IN] ulTransMode           流传输模式，参见 IMOS_MW_TRANSFER_MODE_RTP_UDP 等
 * @param [IN] pcIpAddress           码流接收端IP地址, 
 * @param [IN] usPort                码流接收端端口, 若端口为0, 则由SDK内部分配接收端口
 * @param [IN] bKeepAlive            流保活标志，建立流用于第三方播放时，填 BOOL_FALSE
 * @param [OUT] pulStreamHandle      流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在  
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存分配失败
 * -             #ERR_SDK_SOCKET_LSN_FAIL            创建Socket失败
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       获取播放器资源失败
 * -             #ERR_SDK_DEVICE_STREAM_FULL         设备流已满
 * -             #ERR_SDK_XP_START_STREAM_FAILED     媒体流创建失败
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -     1、码流接收端IP地址设为: ""或 NULL, 或 "0.0.0.0" 均表示本端ip, 接收端端ip为本端时可不指定端口号(置0)
 * -     2、用于IPC设备实况流的建立
 * -     3、获取到的流句柄，用于后续对流的处理
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
 * 开始播放媒体流 \n
 * @param [IN] ulWndHandle     播放窗口句柄
 * @param [IN] ulStreamHandle  媒体流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败 
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       XP资源分配失败
 * -             #ERR_SDK_XP_START_STREAM_FAILED     流建立失败
 * -             #ERR_SDK_XP_START_PLAY_FAILED       开启流的播放失败
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartPlay(IN ULONG ulWndHandle,
                                            IN ULONG ulStreamHandle);

/**
 * 停止媒体流播放 \n
 * @param [IN] ulWndHandle     播放窗口句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 
 * -     用于流的播放，不需要登录设备
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopPlay(IN ULONG ulWndHandle);

/**
 * 删除(停止)媒体流 \n
 * @param [IN] pcUserID         用户ID
 * @param [IN] ulStreamHandle   流句柄，标识一条流
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMAND_SEND_FAIL          消息发送失败
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     设备流不存在
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * @note 
 * -     用于IPC设备实况流的删除，流句柄是 IMOS_MW_StartMediaStream 获取到的
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopMediaStream(IN CHAR *pcUserID,
                                                  IN ULONG ulStreamHandle);

/**
 * 开始实况播放(播放至指定窗格) \n
 * @param [IN] pcUserID          用户ID
 * @param [IN] ulChannel         通道号
 * @param [IN] ulStreamID        流ID(主、辅流), 参见: IMOS_MW_STREAM_ID_MAIN 等
 * @param [IN] ulTransMode       流传输模式, 参见: IMOS_MW_TRANSFER_MODE_RTP_UDP 等
 * @param [IN] ulWndHandle       播放窗口句柄
 * @param [OUT] pulStreamHandle  流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存分配失败
 * -             #ERR_SDK_USERNONEXIST               用户不存在  
 * -             #ERR_SDK_SOCKET_LSN_FAIL            创建Socket失败
 * -             #ERR_SDK_DEVICE_STREAM_FULL         设备流已满
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       获取播放器资源失败
 * -             #ERR_SDK_XP_START_STREAM_FAILED     媒体流创建失败
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       XP资源分配失败
 * -             #ERR_SDK_XP_START_PLAY_FAILED       开启流的播放失败
 * @note 
 * -     1、用于IPC设备实况流的建立、存储回放流的建立, 并在指定窗口播放
 * -     2、获取到的流句柄，用于后续对实况流、存储回放流的停止
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_RealPlay(IN CHAR *pcUserID,
                                           IN ULONG ulChannel,
                                           IN ULONG ulStreamID,
                                           IN ULONG ulTransMode,
                                           IN ULONG ulWndHandle,
                                           OUT ULONG *pulStreamHandle);

/**
 * 停止实况播放（停止指定窗格的实况） \n
 * @param [IN] pcUserID            用户ID
 * @param [IN] ulStreamHandle      流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMAND_SEND_FAIL          消息发送失败
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     设备流不存在
 * @note 
 * -      用于指定窗口中播放的媒体流的删除，该流须由 IMOS_MW_RealPlay 建立
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopRealPlay(IN CHAR *pcUserID,
                                               IN ULONG ulStreamHandle);
                                               
/**
 * 开始多播播放(播放至指定窗格) \n
 * @param [IN] ulWndHandle          播放窗口句柄
 * @param [IN] pcLocalIP            本地地址
 * @param [IN] pcMulticastIP        多播源地址
 * @param [IN] usMulticastPort      多播目的端口
 * @param [OUT] pulStreamHandle     流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存分配失败
 * -             #ERR_SDK_SOCKET_LSN_FAIL            创建Socket失败
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       XP资源分配失败
 * -             #ERR_SDK_XP_START_PLAY_FAILED       开启流的播放失败
 * @note 
 * -     1、用于IPC设备多播流的建立并在指定窗口播放
 * -     2、获取到的流句柄，用于后续对该路流做操作
 * -     3、本地地址需填写接收组播流的IP地址
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartMulticastPlay(IN ULONG ulWndHandle,
                                                     IN CHAR *pcLocalIP,
                                                     IN CHAR *pcMulticastIP,
                                                     IN USHORT usMulticastPort,
                                                     OUT ULONG *pulStreamHandle);

/**
 * 停止多播播放（停止指定窗格的实况） \n
 * @param [IN] ulStreamHandle      流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     设备流不存在
 * @note 
 * -      用于删除指定窗口中播放的多播流，该流须由 IMOS_MW_StartMulticastPlay 建立
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopMulticastPlay(IN ULONG ulStreamHandle);

/** @} */ /* end of Real Play Module */  

                                      

#if 0
#endif
/*************************************************************************************
Stream Data
***************************************************************************************/
/** @defgroup groupStreamData 设置获取媒体流数据回调
*   媒体流数据获取回调的设置
*   @{
*/
/**
 * 设置拼帧前媒体流数据回调函数 \n
 * @param [IN] ulStreamHandle          流句柄
 * @param [IN] pfnSourceMediaDataCBFun 拼帧前媒体流数据回调函数的指针
 * @param [IN] bContinue               是否继续进行后面的拼帧
 * @param [IN] lUserParam              用户设置参数
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     设备流不存在
 * @note 
 * -     1、该函数在#IMOS_MW_StartPlay之前或之后调用，在#IMOS_MW_StopPlay时自动失效；
 * -     2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetOrgMediaDataCallback(IN ULONG ulStreamHandle,
                                                          IN IMOS_MW_SOURCE_MEDIA_DATA_CALLBACK_PF pfnSourceMediaDataCBFun, 
                                                          IN BOOL_T bContinue,
                                                          IN LONG lUserParam);

/**
 * 设置拼帧后视频数据回调函数 \n
 * @param [IN] ulStreamHandle          流句柄
 * @param [IN] pfnParseVideoDataCBFun  拼帧后视频数据回调函数的指针
 * @param [IN] bContinue               是否继续进行后面的播放操作
 * @param [IN] lUserParam              用户设置参数
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     设备流不存在
 * @note 
 * -    1、该函数在#IMOS_MW_StartPlay之前或之后调用，在#IMOS_MW_StopPlay时自动失效；
 * -    2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetParseVideoDataCallback(IN ULONG ulStreamHandle,
                                                            IN IMOS_MW_PARSE_VIDEO_DATA_CALLBACK_PF pfnParseVideoDataCBFun, 
                                                            IN BOOL_T bContinue,
                                                            IN LONG lUserParam);

/**
 * 设置解码后视频数据回调函数 \n
 * @param [IN] ulStreamHandle             流句柄
 * @param [IN] pfnDecodeVideoDataCBFun    解码后视频媒体流数据回调函数的指针
 * @param [IN] bContinue                  是否继续进行后面的显示操作
 * @param [IN] lUserParam                 用户设置参数
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     设备流不存在
 * @note 
 * -    1、该函数在#IMOS_MW_StartPlay之前或之后调用，在#IMOS_MW_StopPlay时自动失效；
 * -    2、回调函数要尽快返回，如果要停止回调，可以把回调函数指针设为NULL；
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
/** @defgroup groupVideoStatistics 实况统计信息
*   实况统计信息
*   @{
*/
/**
 * 获取视频编码格式 \n
 * @param [IN] ulStreamHandle      流句柄 
 * @param [IN] pulVideoEncodeType  视频编码格式, 参见: IMOS_MW_STREAM_FORMAT_H264 等 
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetVideoEncodeType(IN ULONG ulStreamHandle, 
                                                     OUT ULONG *pulVideoEncodeType);
/**
 * 获取视频统计信息 \n
 * @param [IN] ulStreamHandle       流句柄 
 * @param [OUT] pstVideoParam       视频解码参数
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetVideoParam(IN ULONG ulStreamHandle, 
                                                OUT IMOS_MW_VIDEO_PARAM_S *pstVideoParam);
/**
 * 复位丢包率 \n
 * @param [IN]  ulStreamHandle      流句柄 
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ResetLostPacketRate(IN ULONG ulStreamHandle);

/**
 * 复位丢帧率 \n
 * @param [IN]  ulStreamHandle    流句柄 
 * @param [OUT] pulRecvPktNum     存放已接收到包数的指针
 * @param [OUT] pulLostPktNum     存放丢弃包数的指针
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ResetLostFrameRate(IN ULONG ulStreamHandle);
/** @} */ /* end of Video Statistics Module */  

#if 0
#endif
/*************************************************************************************
Display Param
***************************************************************************************/
/** @defgroup groupDisplayParam 显示设置
*   显示设置
*   @{
*/
/**
 * 设置指定播放通道的视频图像显示比例。\n
 * @param [IN] ulWndHandle   播放窗口句柄。
 * @param [IN] ulRenderScale 视频图像在播放通道上的显示比例, 参见: IMOS_MW_RENDER_SCALE_FULL 等
 * @return ULONG，返回如下错误码：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          播放通道不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败 
 * @note
 * -    1、在不调用该接口的情况下，视频图像默认填充整个播放窗格；
 * -    2、需在IMOS_MW_StartPlay之后设置, 实时生效
 * -    3、该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetRenderScale(IN ULONG ulWndHandle, 
                                                 IN ULONG ulRenderScale);

/**
 * 设置图象的对比度参数，即时起作用。\n
 * @param [IN] ulWndHandle           播放窗口句柄。
 * @param [IN] ulContrastMode        图象对比度模式，参见: IMOS_MW_PICTURE_CONTRAST_MODE_NONE 等
 * @param [IN] ulContrastLevel       图象对比度级别，范围: 1-10
 * @return ULONG，返回如下错误码：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          播放通道不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note
 * -    1、在不调用该接口的情况下，视频图像默认不进行对比度调节处理。
 * -    2、在开始播放IMOS_MW_StartPlay之前设置，作为启动播放时的初始值, 在开始播放后生效。
 * -    3、调用该接口对指定播放通道设置的对比参数在播放器运行期间一直有效；当参数ulContrastMode
 *         传入IMOS_MW_PICTURE_CONTRAST_MODE_NONE时，即停止对比度调节处理，此时ulContrastLevel参数传
 *         入的值无效。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPictureContrast(IN ULONG ulWndHandle, 
                                                     IN ULONG ulContrastMode,
                                                     IN ULONG ulContrastLevel);

/**
 * 防闪烁处理\n
 * @param [IN] ulWndHandle            播放窗口句柄。
 * @param [IN] ulWinSize              参考帧数，范围: 0-100
 * @param [IN] ulSoftenVal            帧间滤波参数, 范围: 0-30
 * @param [IN] bOpen                  是否启动防闪烁处理
 * @return ULONG，返回如下错误码：
 * -         #ERR_COMMON_SUCCEED                     成功
 * -         #ERR_SDK_XP_PORT_NOT_EXIST              播放通道不存在
 * -         #ERR_SDK_COMMON_FAIL                    操作失败
 * @note
 * -    1、在不调用该接口的情况下，视频图像默认不进行对比度调节处理；
 * -    2、需在IMOS_MW_StartPlay之后设置；
 * -    3、该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetAntiFlicker(IN ULONG ulWndHandle,
                                                 IN ULONG ulWinSize, 
                                                 IN ULONG ulSoftenVal,
                                                 IN BOOL_T bOpen);

/**
* 模糊处理\n
* @param [IN] ulWndHandle        播放窗口句柄。
* @param [IN] ulFactor           模糊处理参数, 范围: 1-127，默认为80
* @param [IN] bOpen              是否启动模糊处理
* @return ULONG，返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_SDK_XP_PORT_NOT_EXIST              播放通道不存在
* -         #ERR_SDK_COMMON_FAIL                    操作失败
* @note
* -    1、该函数需要在IMOS_MW_StartPlay之后和IMOS_MW_StopPlay之前调用。
* -    2、默认不启动模糊处理。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetVideoMotionBlur(IN ULONG ulWndHandle,
                                                     IN ULONG ulFactor,
                                                     IN BOOL_T bOpen);

/**
* 锐化处理\n
* @param [IN] ulWndHandle        播放窗口句柄。
* @param [IN] fSigma             锐化处理参数, 范围: 0.0--2.0，默认为0.05
* @param [IN] bOpen              是否启动锐化处理
* @return ULONG，返回如下错误码：
* -         #ERR_COMMON_SUCCEED                     成功
* -         #ERR_SDK_XP_PORT_NOT_EXIST              播放通道不存在
* -         #ERR_SDK_COMMON_FAIL                    操作失败
* @note
* -    1、该函数需要在IMOS_MW_StartPlay之后和IMOS_MW_StopPlay之前调用。
* -    2、默认不启动锐化处理。
* -    3、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetVideoSharpen(IN ULONG ulWndHandle,
                                                  IN FLOAT fSigma,
                                                  IN BOOL_T bOpen);

/**
* 影像调节\n
* @param [IN] ulWndHandle        播放通道号
* @param [IN] pstAdjust          影像调节参数
* @param [IN] bOpen              是否打开影像调节
* @return ULONG，返回如下错误码：
* -         #ERR_COMMON_SUCCEED                 成功
* -         #ERR_SDK_COMMON_INVALID_PARAM       输入参数无效
* -         #ERR_SDK_XP_PORT_NOT_EXIST          播放通道不存在
* -         #ERR_SDK_COMMON_FAIL                操作失败
* @note
* -    1、该函数需要在IMOS_MW_StartPlay之后和IMOS_MW_StopPlay之前调用。
* -    2、默认不启动影像调节。
* -    3、影像调节参数中，对比度取值范围为[0--199]，默认值为100；
* -                       亮度取值范围为[0--199]，默认值为100；
* -                       色调取值范围为[0--359]，默认值为0；
* -                       饱和度取值范围为[0--359]，默认值为100；
* -                       伽玛取值范围为[0--99]，默认值为10。
* -    4、该接口函数仅支持Windows。
*/
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetVideoAdjust(IN ULONG ulWndHandle,
                                                 IN IMOS_MW_VIDEO_ADJUST_S *pstAdjust,
                                                 IN BOOL_T bOpen);

/**
 * 设置播放图像流畅性或实时性。\n
 * @param [IN] ulWndHandle        播放窗口句柄。
 * @param [IN] ulPictureFluency   播放图像是实时性优先还是流畅性优先，参见: IMOS_MW_PICTURE_TIME_PRIORITY 等
 * @return ULONG，返回如下错误码：
 * -             #ERR_COMMON_SUCCEED                 成功
 * @note
 * -    1、该函数用于设置网络流和输入流播放时图像的流畅性，对本地文件回放时图像进行设置将不起作用；
 * -    2、该接口需要在IMOS_MW_StartPlay之前调用，故现有实现会忽略窗口句柄参数；
 * -    3、如果用户不调用该函数设置播放图像流畅性，则播放器内部默认使用图像实时性优先；
 * -    4、该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPictureFluency(IN ULONG ulWndHandle, 
                                                    IN ULONG ulPictureFluency);
                                                    
/**
 * 设置视频显示参数  \n
 * @param [IN] pstDisplayParam    视频显示参数
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -     1、设置参数对所有播放通道起作用；
 * -     2、如果用户不调用该函数设置显示参数，则播放器内部默认使用YUV420视频像素格式，D3D的显示模式
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetDisplayParam(IN IMOS_MW_DISPLAY_PARAM_S *pstDisplayParam);
/** @} */ /* end of Display Param Module */  


#if 0
#endif
/*************************************************************************************
Get StreamInfo
***************************************************************************************/
/** @defgroup groupGetStreamInfo 获取媒体流信息
*   获取媒体流信息
*   @{
*/

/**
 * 获取媒体流信息 \n
 * @param [IN] pcUserID              用户ID
 * @param [IN] ulChannel             通道号
 * @param [INOUT] pulBufferLen       用于保存获取结果的缓存区大小
 * @param [OUT] pstStreamInfo        流信息
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_NOENOUGH_BUF               缓存大小不足
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -     该接口中返回的流，可通过 IMOS_MW_StopMediaStream 关闭
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
/** @defgroup groupAudioPlay 语音业务
*   语音业务
*   @{
*/
/**
 * 启动语音对讲 \n
 * @param [IN] pcUserID               用户ID
 * @param [IN] ulTranProtocol         流传输协议, 参见: IMOS_MW_PROTOCOL_UDP 等
 * @param [OUT] pulVoiceTalkHandle    语音对讲句柄
 * @return ULONG，返回如下结果：
 * -        #ERR_COMMON_SUCCEED                 成功
 * -        #ERR_SDK_COMMON_FAIL                操作失败
 * -        #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -        #ERR_SDK_USERNONEXIST               用户非法
 * -        #ERR_SDK_SOCKET_LSN_FAIL            创建Socket失败
 * -        #ERR_SDK_XP_START_STREAM_FAILED     XP 语音业务启流失败
 * -        #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -        #ERR_SDK_XP_PORT_ALLOC_FAILED       获取播放通道资源失败
 * -        #ERR_SDK_XP_START_STREAM_FAILED     语音业务启流失败
 * -        #ERR_SDK_XP_AUDIO_DEVICE_UNRIPE     音频设备未准备好
 * -        #ERR_SDK_BIAUDIO_AUDIOBCAST_FULL    设备语音业务已满
 * @note 
 * -      目前语音业务的传输协议仅支持UDP
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartVoiceTalk(IN CHAR *pcUserID,
                                                 IN ULONG ulProtocol,
                                                 OUT ULONG *pulVoiceTalkHandle);

/**
 * 停止语音对讲 \n
 * @param [IN] pcUserID                用户ID
 * @param [IN] ulVoiceTalkHandle       语音对讲句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          通道不存在
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopVoiceTalk(IN CHAR *pcUserID,
                                                IN ULONG ulVoiceTalkHandle);

/**
 * 启动语音广播 \n
 * @param [IN] pcUserID             用户ID
 * @param [IN] ulTranProtocol       流传输协议, 参见: IMOS_MW_PROTOCOL_UDP 等
 * @param [OUT] pulBroadcastHandle  语音广播句柄
 * @return ULONG，返回如下结果：
 * -        #ERR_COMMON_SUCCEED                 成功
 * -        #ERR_SDK_COMMON_FAIL                操作失败
 * -        #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -        #ERR_SDK_USERNONEXIST               用户非法
 * -        #ERR_SDK_SOCKET_LSN_FAIL            创建Socket失败
 * -        #ERR_SDK_XP_START_STREAM_FAILED     XP 语音业务启流失败
 * -        #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -        #ERR_SDK_XP_PORT_ALLOC_FAILED       获取播放通道资源失败
 * -        #ERR_SDK_XP_START_STREAM_FAILED     语音业务启流失败
 * -        #ERR_SDK_XP_AUDIO_DEVICE_UNRIPE     音频设备未准备好
 * -        #ERR_SDK_BIAUDIO_AUDIOBCAST_FULL    设备语音业务已满
 * @note 
 * -      目前语音业务的传输协议仅支持UDP
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartVoiceBroadcast(IN CHAR *pcUserID,
                                                      IN ULONG ulProtocol,
                                                      OUT ULONG *pulBroadcastHandle);

/**
 * 停止语音广播 \n
 * @param [IN] pcUserID                用户ID
 * @param [IN] ulBroadcastHandle       语音广播句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_XP_PORT_NOT_EXIST          通道不存在
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopVoiceBroadcast(IN CHAR *pcUserID,
                                                     IN ULONG ulBroadcastHandle);

/** @} */ /* end of Audio Play Module */  

#if 0
#endif
/*************************************************************************************
Audio Ctrl
***************************************************************************************/
/** @defgroup groupAudioCtrl 声音控制
*   声音控制
*   @{
*/
/**
 * 打开声音 \n
 * @param [IN] ulStreamHandle  流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -     1、同一时刻只能播放一路声音，如果现在已经有声音打开，则自动关闭原来已经打开的声音。默认关闭。
 * -     2、该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PlaySound(IN ULONG ulStreamHandle);

/**
 * 关闭声音 \n
 * @param [IN] ulStreamHandle   流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -      该接口函数仅支持Windows
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopSound(IN ULONG ulStreamHandle);

/**
 * 获得麦克风音量 \n
 * @param [OUT] pulMicVolume    麦克风音量（范围从0到255，255为最大音量）
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -      该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetMicVolume(OUT ULONG *pulMicVolume);

/**
 * 设置麦克风音量 \n
 * @param [IN] ulMicVolume    麦克风音量（范围从0到255，255为最大音量）
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -    1、该接口函数仅支持Windows。
 * -    2、影响所有流
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetMicVolume(IN ULONG ulMicVolume);

/**
 * 获取扬声器音量 \n
 * @param [OUT] pulSpeakerVolume    扬声器音量（范围从0到255，255为最大音量）
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -      该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetSpeakerVolume(OUT ULONG *pulSpeakerVolume);

/**
 * 设置扬声器音量 \n
 * @param [IN] ulSpeakerVolume    扬声器音量（范围从0到255，255为最大音量）
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * @note 
 * -     该接口函数仅支持Windows。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetSpeakerVolume(IN ULONG ulSpeakerVolume);

/** @} */ /* end of Audio Ctrl Module */

#if 0
#endif

/*************************************************************************************
PTZ Ctrl
***************************************************************************************/
/** @defgroup groupPTZCtrl 云台控制
*   云台控制相关接口，含预置位操作、通用云台控制、云台绝对位置控制
*   @{
*/
/**
 * 设置预置位 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulChannel          通道号
 * @param [IN] pstPreset          预置位信息
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -      通道号暂未使用，默认 0
 * - 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPreset(IN CHAR *pcUserID, 
                                            IN ULONG ulChannel,
                                            IN IMOS_MW_PRESET_PARAM_S *pstPreset);

/**
 * 删除预置位 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulChannel          通道号
 * @param [IN] ulPresetID         待删除的预置位ID
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -      通道号暂未使用，默认 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_DelPreset(IN CHAR *pcUserID, 
                                            IN ULONG ulChannel,
                                            IN ULONG ulPresetID);

/**
 * 调用预置位 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulChannel          通道号
 * @param [IN] ulPresetID         调用的预置位ID
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -      通道号暂未使用，默认 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GotoPreset(IN CHAR *pcUserID, 
                                             IN ULONG ulChannel,
                                             IN ULONG ulPresetID);

/**
 * 云台控制 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulChannel          通道号
 * @param [IN] pstPtzCommand      云台控制指令
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -      通道号暂未使用，默认 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PtzCommand(IN CHAR *pcUserID,
                                             IN ULONG ulChannel,
                                             IN IMOS_MW_PTZ_COMMAND_S *pstPtzCommand); 

/**
 * 拉框放大 \n
 * @param [IN] pcUserID           用户信息标识
 * @param [IN] ulChannel          通道号
 * @param [IN] pstAreaInfo        拉框信息
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #其余错误码待增加                   失败
 * @note 
 * -      通道号暂未使用，默认 0,
 * -      当拉框大小为0或者为播放窗格时，则为3D定位
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_AreaZoomIn(IN CHAR *pcUserID,
                                             IN ULONG ulChannel,
                                             IN IMOS_MW_PTZ_ZOOMAREA_S *pstAreaInfo); 

/**
 * 拉框缩小 \n
 * @param [IN] pcUserID           用户信息标识
 * @param [IN] ulChannel          通道号
 * @param [IN] pstAreaInfo        拉框信息
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #其余错误码待增加                   失败
 * @note 
 * -      通道号暂未使用，默认 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_AreaZoomOut(IN CHAR *pcUserID,
                                              IN ULONG ulChannel,
                                              IN IMOS_MW_PTZ_ZOOMAREA_S *pstAreaInfo);

/**
 * 云台实现同时绝对变倍和移动至绝对位置 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulChannel          通道号
 * @param [IN] pstAbsZoom         变倍信息
 * @param [IN] pstAbsPosition     云台绝对位置
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -      1、若其中变倍或绝对位置为空则实现相对应的单个操作
 * -      2、通道号暂未使用，默认 0
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PTZAbsoluteMove(IN CHAR *pcUserID,
                                                  IN ULONG ulChannel,
                                                  IN IMOS_MW_PTZ_ABSZOOM_S *pstAbsZoom,
                                                  IN IMOS_MW_PTZ_ABSPOSITION_S *pstAbsPosition); 
                                             
/**
 * 云台实现指定速度变倍到指定变倍和移动至指定位置 \n
 * @param [IN] pcUserID                 用户ID
 * @param [IN] ulChannel                通道号
 * @param [IN] pstControledZoom   	    变倍信息
 * @param [IN] pstControledPosition     云台位置和角速度
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_PTZ_SERIALMODE_MISMATCH    串口模式不匹配
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -      通道号暂未使用，默认 0
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
/** @defgroup groupDeviceStatus 获取设备状态
*   获取设备状态接口
*   @{
*/
/**
 * 获取状态函数 \n
 * @param [IN] pcUserID           用户ID
 * @param [IN] ulChannel          通道号
 * @param [IN] ulCmdType          状态命令类型, 参见: IMOS_MW_STATUS_KEEPALIVE 等
 * @param [INOUT] pStatusInfo     状态信息, 参见各状态命令类型的 说明
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * @note 
 * - 无
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
/** @defgroup groupDeviceManage 设备维护管理
*   设备维护管理含: 设备维护含系统升级，设备重启，诊断信息导出，配置导入、导出，恢复默认配置，恢复默认参数等
*   @{
*/
/**
 * 系统升级 \n
 * @param [IN] pcUserID      用户信息标识
 * @param [IN] pcFile        升级文件的路径(含文件名)
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_UPDATE_BUSY                升级中，不允许重复升级
 * -             #ERR_SDK_UPDATE_NOTADMIN            非admin用户不允许升级
 * -             #ERR_SDK_CREATE_THREAD_FAIL         创建线程失败
 * @note 路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（包括文件名在内） 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Upgrade(IN CHAR *pcUserID,
                                          IN CHAR *pcFile);

/**
 * 系统重启 \n
 * @param [IN] pcUserID    用户信息标识
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Reboot(IN CHAR *pcUserID);

/**
 * 导出配置文件 \n
 * @param [IN] pcUserID        用户信息标识
 * @param [IN] pcFile          存放配置信息的路径
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -     1、将配置文件导出至指定路径(不含文件名)下；
 * -     2、路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（包括文件名在内）。 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ExportConfig(IN CHAR *pcUserID,
                                               IN CHAR *pcFile);

/**
 * 导入配置文件 \n
 * @param [IN] pcUserID        用户信息标识
 * @param [IN] pcFile          配置文件(含绝对路径)
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMON_FAIL_STAT           读取文件失败
 * -             #ERR_SDK_INVALID_CONFIGFILE         配置文件非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -     1、导入指定路径下的配置文件(含绝对路径)
 * -     2、路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（包括文件名在内）。 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ImportConfig(IN CHAR *pcUserID,
                                               IN CHAR *pcFile);

/**
 * 恢复出厂配置 \n
 * @param [IN] pcUserID       用户信息标识
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note 
 * -     恢复出厂配置时，保留设备IP地址、网页密码
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_RestoreConfig(IN CHAR *pcUserID);

/**
 * 恢复默认参数 \n
 * @param [IN] pcUserID       用户信息标识
 * @param [IN] ulChannel      通道号
 * @param [IN] ulParamType    待恢复的参数类型, 参见: IMOS_MW_PARAM_TYPE_OPTICS_VIDEO 等
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                成功
 * -             #ERR_SDK_COMMON_FAIL               操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM      参数非法
 * -             #ERR_SDK_USERNONEXIST              用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT           请求超时
 * @note 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_RestoreDefaultParam(IN CHAR *pcUserID,
                                                      IN ULONG ulChannel,
                                                      IN ULONG ulParamType);

/**
 * 获取诊断信息 \n
 * @param [IN] pcUserID             用户信息标识
 * @param [IN] pcDiagInfoPath       存放诊断信息的路径
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_USERNONEXIST               用户不存在
 * -             #ERR_SDK_COMMAND_TIMEOUT            请求超时
 * @note
 * -     1、将诊断信息保存至指定路径(不含文件名)下；
 * -     2、路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（包括文件名在内）。 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ExportDiagnoseInfo(IN CHAR *pcUserID,
                                                     IN CHAR *pcDiagInfoPath);
/** @} */ /* end of Device Manage Module */

#if 0
#endif
/*************************************************************************************
User Manage
***************************************************************************************/
/** @defgroup groupUserManage 用户管理
*   用户管理含: 用户信息获取，用户信息设置和用户删除
*   @{
*/
/**
 * 获取用户信息 \n
 * @param [IN] pcUserID         用户信息标识
 * @param [INOUT] pulBufferLen  传入输入数据的缓冲区大小，期望获取的用户信息个数
 * @param [INOUT] pstUsersInfo  用户信息结构
 * @return ULONG，返回如下结果：
 * -           #ERR_COMMON_SUCCEED                 成功
 * -           #ERR_SDK_USERNONEXIST               用户非法
 * -           #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -           #ERR_SDK_COMMON_FAIL                操作失败
 * -           #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -           #ERR_SDK_NOENOUGH_BUF               缓存区不足
 * @note 
 * -     参数pulBufferLen 作为入参表示用户分配的保存获取结果的缓冲区大小，出参表示实际用户信息的缓存大小
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetUser(IN CHAR *pcUserID,
                                          INOUT ULONG *pulBufferLen,
                                          INOUT IMOS_MW_USER_INFO_S *pstUsersInfo);

/**
 * 设置用户信息 \n
 * @param [IN] pcUserID        用户信息标识
 * @param [IN] ulBufferLen     传入输入数据的缓冲区大小
 * @param [IN] pstUsersInfo    用户信息结构
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_USER_NOT_AUTHORIZED        用户未授权
 * -             #ERR_SDK_USER_PASSWD_INVALID        密码无效
 * -             #ERR_SDK_USERFULL                   用户已满
 * @note 
 * -     1、支持用户的添加和修改
 * -     2、已登录用户密码信息修改后，被修改的用户将收到状态上报通知其退出，对应状态 :IMOS_MW_STATUS_USERINFO_CHANGE
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetUser(IN CHAR *pcUserID,
                                          IN ULONG ulBufferLen,
                                          IN IMOS_MW_USER_INFO_S *pstUsersInfo);

/**
 * 删除用户 \n
 * @param [IN] pcUserID        用户信息标识
 * @param [IN] ulBufferLen     传入输入数据的缓冲区大小
 * @param [IN] pstUsersInfo    用户信息结构
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_USERNONEXIST               用户非法
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_COMMON_NO_MEMORY           系统内存不足
 * -             #ERR_SDK_USER_NOT_AUTHORIZED        用户未授权
 * @note
 * -     1、只有admin用户有权限删除其他用户
 * -     2、admin用户不允许被删除
 * -     3、该接口支持一次删除多个用户
 * -     4、已登录用户被删除后，被删除用户将收到状态上报通知其退出,对应状态 :IMOS_MW_STATUS_USERINFO_CHANGE
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
/** @defgroup groupLocalFilePlay 本地文件播放和抓拍
*   本地文件播放
*   @{
*/
/**
 * 本地单次抓拍 \n
 * @param [IN] ulStreamHandle 流句柄
 * @param [IN] ulPicType      图像格式, 参见: IMOS_MW_PICTURE_FORMAT_BMP 等
 * @param [IN] pcFileName     保存图像的文件路径，包括文件名(含绝对路径)
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                   成功
 * -             #ERR_SDK_COMMON_FAIL                  操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM         参数非法
 * -             #ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH  硬盘剩余空间不足
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST       媒体流不存在
 * @note
 * -     路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（含绝对路径）。
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_LocalSnapShot(IN ULONG ulStreamHandle,
                                                IN ULONG ulPicType, 
                                                IN CHAR *pcFileName);
/**
 * 打开（本地）媒体文件 \n
 * @param [IN] pcFilename         本地文件的文件名（含绝对路径）
 * @param [OUT] pulStreamHandle   流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       获取播放通道资源失败
 * @note 
 * -     路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（含绝对路径）。  
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_OpenMediaFile(IN CHAR *pcFilename,
                                                OUT ULONG *pulStreamHandle);

/**
 * 关闭（本地）媒体文件 \n
 * @param [IN] ulStreamHandle       流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_CloseMediaFile(IN ULONG ulStreamHandle);

/**
 * 获取总的时间长度 \n
 * @param [IN] ulStreamHandle  流句柄
 * @param [IN] pulTotalTime    总的时间长度，单位: 秒
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetFileTime(IN ULONG ulStreamHandle, 
                                              OUT ULONG *pulTotalTime);

/**
 * 获取当前播放位置 \n
 * @param [IN] ulStreamHandle  流句柄
 * @param [IN] pulTime         当前播放进度时间，单位: 秒
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_COMMON_INVALID_PARAM       参数非法
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetPlayedPosition(IN ULONG ulStreamHandle,
                                                    OUT ULONG *pulTime);

/**
 * 根据时间设置播放位置 \n
 * @param [IN] ulStreamHandle  流句柄
 * @param [IN] ulTime          跳转目的时间，单位: 秒
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPlayedPosition(IN ULONG ulStreamHandle, 
                                                    IN ULONG ulTime);

/**
 * 暂停播放 \n
 * @param [IN] ulStreamHandle    流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_PausePlay(IN ULONG ulStreamHandle);

/**
 * 恢复播放 \n
 * @param [IN] ulStreamHandle     流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 无
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ResumePlay(IN ULONG ulStreamHandle);

/**
 * 指定播放速度 \n
 * @param [IN] ulStreamHandle 流句柄
 * @param [IN] ulSpeed        播放速度, 参见: IMOS_MW_PLAY_STATUS_16_BACKWARD 等  
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
 * @note 
 * -     可用于控制播放的快进、快退
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPlaySpeed(IN ULONG ulStreamHandle,
                                               IN ULONG ulSpeed);
                                               
/**
 * 开始本地录像 \n
 * @param [IN] ulStreamHandle      流句柄
 * @param [IN] ulMediaFileFormat   录像文件的格式, 参见: IMOS_MW_MEDIA_FILE_FORMAT_TS 等
 * @param [IN] pcFileName          录像文件存放路径，包括文件名（不带后缀名）
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                     成功
 * -             #ERR_SDK_COMMON_FAIL                    操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST         流不存在
 * -             #ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH    硬盘剩余空间不足，无法继续业务  
 * @note 
 * -     路径长度和操作系统有关，sdk不做限制，windows默认路径长度小于等于256字节（包括文件名在内）。 
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartLocalRecord(IN ULONG ulStreamHandle,
                                                   IN ULONG ulMediaFileFormat, 
                                                   IN CHAR *pcFileName);
/**
 * 停止本地录像 \n
 * @param [IN] ulStreamHandle       流句柄
 * @return ULONG，返回如下结果：
 * -             #ERR_COMMON_SUCCEED                 成功
 * -             #ERR_SDK_COMMON_FAIL                操作失败
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     流不存在
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

