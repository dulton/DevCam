#ifndef _INFSDK_PLAY_H
#define _INFSDK_PLAY_H

#include "INFSDK_Config.h"
#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

//���ƣ�E_PIC_TYPE
//˵����ö�ٽ�ͼ��ʽ
//ԭ�ͣ�
typedef enum tagPictype{
	PIC_JPEG,
	PIC_BMP,
} E_PIC_TYPE;

typedef enum tagFrametype{
	FT_UYVY, /**< ��Ƶ�� uyvy ��ʽ�� ����˳�� "U0Y0V0Y1U2Y2V2Y3����"�� ��һ������λ��ͼ�����Ͻ� */
} E_FRAME_TYPE;

typedef struct tagFrameInfo{
	unsigned long nWidth; /**< �������λ���� */
	unsigned long nHeight; /**< ����ߣ���λ���� */
	unsigned long nStamp; /**< ʱ����Ϣ����λ���� */
	E_FRAME_TYPE eFrameType; /**< �������ͣ���� E_FRAME_TYPE ����˵�� */
	unsigned long nFrameRate; /**< ��Ƶ֡�� */
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