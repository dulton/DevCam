//
//	SncStreamLib.h - definitions/declarations for using "Sony Network Camera Stream Library".
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef _SNCSTREAMLIB_H_
#define _SNCSTREAMLIB_H_

#include "SncStreamLibDefine.h"

// API for Basic Setting
SNC_ERROR	__stdcall sncGetLibraryVersion		( unsigned int *pVersion );
SNC_HANDLE	__stdcall sncOpenHandle				(  );
void		__stdcall sncCloseHandle			( SNC_HANDLE Handle );
void		__stdcall sncCloseAllHandle			(  );
SNC_ERROR	__stdcall sncInitialize				( SNC_HANDLE Handle );
SNC_ERROR	__stdcall sncFinalize				( SNC_HANDLE Handle );
void		__stdcall sncFinalizeAll			( );


// API for Input setting
SNC_ERROR	__stdcall sncSetNetwork				( SNC_HANDLE Handle, NETINFO *pNetInfo );
SNC_ERROR	__stdcall sncGetNetworkSetting		( SNC_HANDLE Handle, NETINFO *pNetInfo );
SNC_ERROR	__stdcall sncSetJPEGInterval		( SNC_HANDLE Handle, unsigned int Interval );
SNC_ERROR	__stdcall sncSetVideoCodec			( SNC_HANDLE Handle, VIDEOCODEC VideoCodec );
SNC_ERROR	__stdcall sncGetCameraInfo			( SNC_HANDLE Handle, CAMINFO *pCamInfo );
SNC_ERROR	__stdcall sncSendCGICommand			( SNC_HANDLE Handle, char *pMethod, char *pCgi, char *pQuery, char *pBuf, unsigned int BufLen, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncSetMemory				( SNC_HANDLE Handle, CODECINFO *pCodec, unsigned int FrameRate );
SNC_ERROR	__stdcall sncGetMemorySetting		( SNC_HANDLE Handle, CODECINFO *pCodec, unsigned int *pFrameRate);
SNC_ERROR	__stdcall sncWriteVideoStream		( SNC_HANDLE Handle, char *pBuf, unsigned int BufLen, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncWriteAudioStream		( SNC_HANDLE Handle, char *pBuf, unsigned int BufLen, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncSetFrameRate			( SNC_HANDLE Handle, unsigned int FrameRate );
SNC_ERROR	__stdcall sncResetAudioMemory		( SNC_HANDLE Handle );
SNC_ERROR	__stdcall sncSetStreamProtocol		( SNC_HANDLE Handle, PROTOCOLTYPE Type );
SNC_ERROR	__stdcall sncSetUDPMulticastMode    ( SNC_HANDLE Handle, bool UDPMulticastMode );
SNC_ERROR	__stdcall sncGetUDPMulticastMode    ( SNC_HANDLE Handle, bool *pUDPMulticastMode );
SNC_ERROR	__stdcall sncSetVideoInstance		( SNC_HANDLE Handle, VIDEO_INSTANCE	Instance );


// API for Setting
#ifndef _WIN64
SNC_ERROR	__stdcall sncSetCallBack			( SNC_HANDLE Handle, CALLBACKTYPE Type, void *pFunction, unsigned long Param );
SNC_ERROR	__stdcall sncSetMessageDecodeFinish	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, unsigned long Param );
SNC_ERROR	__stdcall sncSetMessageSplitFinish	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, unsigned long Param );
SNC_ERROR	__stdcall sncSetMessageEnd			( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, unsigned long Param );
SNC_ERROR	__stdcall sncSetMessageChangeImageSize	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, unsigned long Param );
SNC_ERROR	__stdcall sncSetMessageStartRender	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, unsigned long Param );
#else
SNC_ERROR	__stdcall sncSetCallBack			( SNC_HANDLE Handle, CALLBACKTYPE Type, void *pFunction, DWORD_PTR Param );
SNC_ERROR	__stdcall sncSetMessageDecodeFinish	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, DWORD_PTR Param );
SNC_ERROR	__stdcall sncSetMessageSplitFinish	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, DWORD_PTR Param );
SNC_ERROR	__stdcall sncSetMessageEnd			( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, DWORD_PTR Param );
SNC_ERROR	__stdcall sncSetMessageChangeImageSize	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, DWORD_PTR Param );
SNC_ERROR	__stdcall sncSetMessageStartRender	( SNC_HANDLE Handle, HWND HandleWnd, unsigned int Msg, DWORD_PTR Param );
#endif
SNC_ERROR	__stdcall sncSetRawDataType			( SNC_HANDLE Handle, RAWDATATYPE Type );
SNC_ERROR	__stdcall sncSetVideoDecodeOpt		( SNC_HANDLE Handle, VIDEODECODEOPT Option );
SNC_ERROR	__stdcall sncEnableVideoStream		( SNC_HANDLE Handle, bool Enable );
SNC_ERROR	__stdcall sncEnableAudioStream		( SNC_HANDLE Handle, bool Enable );
SNC_ERROR	__stdcall sncEnableVideoDecode		( SNC_HANDLE Handle, bool Enable );
SNC_ERROR	__stdcall sncEnableAudioDecode		( SNC_HANDLE Handle, bool Enable );
SNC_ERROR	__stdcall sncEnableVideoPlay		( SNC_HANDLE Handle, bool Enable );
SNC_ERROR	__stdcall sncEnableAudioPlay		( SNC_HANDLE Handle, bool Enable );


// API for Replaying/Stopping Stream
SNC_ERROR	__stdcall sncStart					( SNC_HANDLE Handle );
SNC_ERROR	__stdcall sncStop					( SNC_HANDLE Handle );
SNC_ERROR	__stdcall sncSetPause				( SNC_HANDLE Handle, PAUSETYPE Type );
SNC_ERROR	__stdcall sncStepFrame				( SNC_HANDLE Handle );


// API for Getting Information
SNC_ERROR	__stdcall sncGetVideoCodecInfo		( SNC_HANDLE Handle, VIDEOCODECINFO *pVideoCodecInfo );
SNC_ERROR	__stdcall sncGetAudioCodecInfo		( SNC_HANDLE Handle, AUDIOCODECINFO *pAudioCodecInfo );
SNC_ERROR	__stdcall sncGetCurrentDecVideo		( SNC_HANDLE Handle, VIDEOINFO *pVideoInfo, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncGetCurrentRawVideo		( SNC_HANDLE Handle, VIDEOINFO *pVideoInfo, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncGetCurrentDecAudio		( SNC_HANDLE Handle, AUDIOINFO *pAudioInfo, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncGetCurrentRawAudio		( SNC_HANDLE Handle, AUDIOINFO *pAudioInfo, unsigned int *pWrittenLen );
SNC_ERROR	__stdcall sncGetCurrentFrameNum		( SNC_HANDLE Handle, unsigned int *pFrameNum );
SNC_ERROR	__stdcall sncGetDrawFrame			( SNC_HANDLE Handle, int* pFps);


// Video Play
SNC_ERROR	__stdcall sncCreateScreen			( SNC_HANDLE Handle, HWND ParentHandleWnd, int X, int Y, int W, int H );
SNC_ERROR	__stdcall sncSetScreenPos			( SNC_HANDLE Handle, HWND HandleWndInsertAfter, int X, int Y, int W, int H, UINT Flags );
SNC_ERROR	__stdcall sncGetScreenHandle		( SNC_HANDLE Handle, HWND *pHandleWnd);
SNC_ERROR	__stdcall sncSetRenderingType		( SNC_HANDLE Handle, RENDERINGTYPE Type );
SNC_ERROR	__stdcall sncSetSuperImpose			( SNC_HANDLE Handle, IMPOSEINFO *info);
SNC_ERROR	__stdcall sncSetMouseDrawType		( SNC_HANDLE Handle, DRAWTYPE Type);
SNC_ERROR	__stdcall sncGetMouseDrawType		( SNC_HANDLE Handle, DRAWTYPE* Type);
SNC_ERROR	__stdcall sncSetDrawObject			( SNC_HANDLE Handle, DRAWTYPE type,RECT* Rect=NULL,COLORREF color=RGB(255,0,0));
SNC_ERROR	__stdcall sncSetEffectiveArea		( SNC_HANDLE Handle, int left, int top,int right, int bottom);


// Audio play
SNC_ERROR	__stdcall sncSetAudioVolume			( SNC_HANDLE Handle, unsigned short Volume );
SNC_ERROR	__stdcall sncGetAudioVolume			( SNC_HANDLE Handle, unsigned short *pVolume );
SNC_ERROR	__stdcall sncSetAudioMute			( SNC_HANDLE Handle, bool Mute );
SNC_ERROR	__stdcall sncGetAudioMute			( SNC_HANDLE Handle, bool *pMute);
SNC_ERROR	__stdcall sncCheckAudioDevice		( SNC_HANDLE Handle, bool* pEnable );




#endif // !_SNCSTREAMLIB_H_