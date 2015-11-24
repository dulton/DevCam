#ifndef INFSDKNET_H
#define INFSDKNET_H

#include "INFSDK_Config.h"
#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

//名称：E_ENCODE_TYPE
//说明：编码类型参数
//原型：
typedef enum tagEncodeType
{
	ENCODE_MPEG4 = 1, /**< MPEG4 编码 */
	ENCODE_H264, /**< H264 编码 */
	ENCODE_H264_Hi3510, /**< H264 3510 编码 */
	ENCODE_MJPEG, /**< MJPEG 编码，暂无用 */
} E_ENCODE_TYPE;

//名称：S_REALDATA_INFO
//说明：实时数据流参数
//原型：
typedef struct tagRealDataInfo
{
	unsigned long lChannel; /**< 通道号，从 0 开始 */
	unsigned long lStreamMode; /**< 码流类型，0-主码流，1-子码流 */
	E_ENCODE_TYPE eEncodeType; /**< 编码类型 */
}S_REALDATA_INFO;

//名称：E_REALDATA_TYPE
//说明：回调实时流的数据类型
//原型：
typedef enum tagRealDataType
{
	REALDATA_HEAD, /**< 实时流的头数据 */
	REALDATA_VIDEO, /**< 实时视频流数据（包括复合流和音视频分开的视频流数据） */
	REALDATA_AUDIO, /**< 实时音频流数据 */
} E_REALDATA_TYPE;

typedef void (CALLBACK *CBRealData)(long lRealHandle,E_REALDATA_TYPE eDataType,unsigned char *pBuffer,unsigned long lBufSize,void *pUserData);

INFSDK_API bool STDCALL INFNET_Init();

INFSDK_API bool STDCALL INFNET_Cleanup();

INFSDK_API long STDCALL INFNET_Login(const char *sDevIP,const unsigned int nDevPort,const char *sUserName,const char *sPassword);

INFSDK_API bool STDCALL INFNET_Logout(long lLoginID);

INFSDK_API long STDCALL INFNET_StartRealData(long lLoginID,S_REALDATA_INFO *pRealDataInfo,CBRealData fRealData,void *pUserData = NULL);

INFSDK_API bool STDCALL INFNET_StopRealData(long lRealHandle);

INFSDK_API long STDCALL INFNET_GetLastError();

#ifdef __cplusplus
}
#endif

#endif