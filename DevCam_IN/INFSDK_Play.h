#ifndef _INFSDK_PLAY_H
#define _INFSDK_PLAY_H

#include "INFSDK_Config.h"
#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

//名称：E_PIC_TYPE
//说明：枚举截图格式
//原型：
typedef enum tagPictype{
	PIC_JPEG,
	PIC_BMP,
} E_PIC_TYPE;

typedef enum tagFrametype{
	FT_UYVY, /**< 视频， uyvy 格式。 排列顺序 "U0Y0V0Y1U2Y2V2Y3……"， 第一个像素位于图像左上角 */
} E_FRAME_TYPE;

typedef struct tagFrameInfo{
	unsigned long nWidth; /**< 画面宽，单位像素 */
	unsigned long nHeight; /**< 画面高，单位像素 */
	unsigned long nStamp; /**< 时标信息，单位毫秒 */
	E_FRAME_TYPE eFrameType; /**< 数据类型，详见 E_FRAME_TYPE 定义说明 */
	unsigned long nFrameRate; /**< 视频帧率 */
} S_FRAMEINFO;

typedef void (CALLBACK *CBDecodeCallBack)( long lPlayHandle,unsigned char *pBuf,unsigned long nBufSize,S_FRAMEINFO *pFrameInfo,void *pUserData );

INFSDK_API bool STDCALL INFPLAY_Init();

INFSDK_API bool STDCALL INFPLAY_Cleanup();

INFSDK_API long STDCALL INFPLAY_OpenStream( const unsigned char *pStreamHead,unsigned long lStreamHeadSize );

INFSDK_API bool STDCALL INFPLAY_CloseStream( long lPlayHandle );

INFSDK_API bool STDCALL INFPLAY_InputData( long lPlayHandle,const unsigned char *pStreamBuf,unsigned long lStreamBufSize );

INFSDK_API bool STDCALL INFPLAY_Play(long lPlayHandle,HWND hPlayWnd,bool bCloseSound = false);

INFSDK_API bool STDCALL INFPLAY_Stop( long lPlayHandle );

INFSDK_API bool STDCALL INFPLAY_SetDecodeCallBack(long lPlayHandle,CBDecodeCallBack fDecodeCallBack,void *pUserData = NULL);

INFSDK_API bool STDCALL INFPLAY_CapturePicture( long lPlayHandle,const char *sPicFileName,E_PIC_TYPE ePicType );

#ifdef __cplusplus
}
#endif

#endif