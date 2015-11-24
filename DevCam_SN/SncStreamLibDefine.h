//
//	SncStreamLibDefine.h - definitions for using "Sony Network Camera Stream Library".
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef _SNCSTREAMLIBDEFINE_H_
#define _SNCSTREAMLIBDEFINE_H_

#include "SncDefine.h"

namespace SNC
{
	
namespace STRM
{

//////////////////////////////////////////////
// Pause type
//////////////////////////////////////////////
enum PAUSETYPE
{
	PAUSE_RESTART,
	PAUSE_AUDIO,
	PAUSE_AUDIO_VIDEO,
};
//////////////////////////////////////////////
// Video raw data type
//////////////////////////////////////////////
enum RAWDATATYPE
{
	RDT_FRAME,
	RDT_GOP,
};

//////////////////////////////////////////////
// Video decode option
//////////////////////////////////////////////
enum VIDEODECODEOPT
{
	VDO_ALL,
	VDO_I_ONLY,
};

//////////////////////////////////////////////
// Video/Audio codec
//////////////////////////////////////////////
struct VIDEOCODECINFO
{
	VIDEOCODEC		Codec;
	int				Width;
	int				Height;
};
struct AUDIOCODECINFO
{
	AUDIOCODEC		Codec;
	unsigned short  Channels; 
    unsigned long	SamplesPerSec;
    unsigned short  BitsPerSample; 
};

//////////////////////////////////////////////
// Protocol information
//////////////////////////////////////////////
enum PROTOCOLTYPE
{
	PT_HTTP,
    PT_HTTPS,
    PT_RTP_OVER_UDP
};

//////////////////////////////////////////////
// Draw type information
//////////////////////////////////////////////
enum DRAWTYPE
{
	DT_UNKNOWN,
	DT_PLAIN,
	DT_RECTANGLE,
	DT_ARROW,
	DT_CROSSLINE,
};

//////////////////////////////////////////////
// Draw event information
//////////////////////////////////////////////
enum DRAWEVENT
{
	DE_UNKNOWN,
	DE_START,
	DE_MOVING,
	DE_STOP,
};

//////////////////////////////////////////////
// Rendering type information
//////////////////////////////////////////////
enum RENDERINGTYPE
{
	RT_OFFSCREEN,
	RT_OVERLAY,
};




//////////////////////////////////////////////
// Camera settings
//////////////////////////////////////////////
struct CAMINFO
{
	char			ModelName[32];			// Model name
	char			Serial[8];				// Serial No.
	char			SoftVersion[16];		// Software version
	bool			PanTiltFunc;			// PanTilt function
	bool			ZoomFunc;				// Zoom function
	char			ImageCodec[16];			// Image codec
	char			AudInCodec[16];			// Audio codec
	unsigned int	JpegFrameRate;			// JPEG	frame rate
	unsigned int	Mpeg4FrameRate;			// MPEG4 frame rate
	unsigned int	H264FrameRate;			// H264 frame rate
	bool			AudioIn;				// Audio ON/OFF
	bool			FocusMode;				// Focus Mode  true:Auto, false:Manual
	bool			ZoomMode;				// Zoom Mode   true:Optical, false:Full
};
//////////////////////////////////////////////
// UserData
//////////////////////////////////////////////
struct USERDATA
{
	char			CamTim	[32];
	unsigned short	FrmRate;
	char			TimStamp[11];
	char			CamPos	[17];
	char			AlmEvent[17];
};
//////////////////////////////////////////////
// Get Video/Audio data
//////////////////////////////////////////////
struct VIDEOINFO
{
	char			*pBuf;
	unsigned int	BufLen;
	VIDEOCODECINFO	VideoCodecInfo;
	USERDATA		UserData;
	bool			KeyFrame;
};
struct AUDIOINFO
{
	char			*pBuf;
	unsigned int	BufLen;
	AUDIOCODECINFO	AudioCodecInfo;
};

//////////////////////////////////////////////
// Mouse infomation
//////////////////////////////////////////////
struct MOUSEINFO
{
	DRAWTYPE DType;
	DRAWEVENT DEvent;
	int StartX;
	int StartY;
	int EndX;
	int EndY;
};




//////////////////////////////////////////////
// Call back
//////////////////////////////////////////////
#ifndef _WIN64
typedef void (__stdcall *SNC_VCALLBACK )( VIDEOINFO *pVideoInfo, unsigned long Param );
typedef void (__stdcall *SNC_ACALLBACK )( AUDIOINFO *pAudioInfo, unsigned long Param );
typedef void (__stdcall *SNC_AVCALLBACK)( VIDEOINFO *pVideoInfo, AUDIOINFO *pAudioInfo, unsigned long Param );
typedef void (__stdcall *SNC_UCALLBACK )( USERDATA *pUserInfo, unsigned long Param );
typedef void (__stdcall *SNC_MOUSECALLBACK )( MOUSEINFO *pMouseInfo,unsigned long Param );
typedef LRESULT (__stdcall *SNC_SCREENCALLBACK )( HWND hWnd, unsigned int Msg, WPARAM wParam, LPARAM lParam,bool* bHandled,unsigned long Param );
#else
typedef void (__stdcall *SNC_VCALLBACK )( VIDEOINFO *pVideoInfo, DWORD_PTR Param );
typedef void (__stdcall *SNC_ACALLBACK )( AUDIOINFO *pAudioInfo, DWORD_PTR Param );
typedef void (__stdcall *SNC_AVCALLBACK)( VIDEOINFO *pVideoInfo, AUDIOINFO *pAudioInfo, DWORD_PTR Param );
typedef void (__stdcall *SNC_UCALLBACK )( USERDATA *pUserInfo, DWORD_PTR Param );
typedef void (__stdcall *SNC_MOUSECALLBACK )( MOUSEINFO *pMouseInfo,DWORD_PTR Param );
typedef LRESULT (__stdcall *SNC_SCREENCALLBACK )( HWND hWnd, unsigned int Msg, WPARAM wParam, LPARAM lParam,bool* bHandled,DWORD_PTR Param );

#endif

enum CALLBACKTYPE
{
	CALLBACK_RAW_VIDEO,
	CALLBACK_RAW_AUDIO,
	CALLBACK_RAW_BOTH,
	CALLBACK_DEC_VIDEO,
	CALLBACK_DEC_AUDIO,
	CALLBACK_DEC_BOTH,
	CALLBACK_USER_DATA,
	CALLBACK_SCREEN_DATA,
	CALLBACK_MOUSE_DATA,
};


//////////////////////////////////////////////
// Superimpose Location
//////////////////////////////////////////////
enum IMPOSELOCATION
{
	IL_UNKNOWN,
	IL_LEFTTOP,
	IL_CENTERTOP,
	IL_RIGHTTOP,
	IL_LEFTCENTER,
	IL_CENTER,
	IL_CENTERRIGHT,
	IL_LEFTBOTTOM,
	IL_CENTERBOTTOM,
	IL_RIGHTBOTTOM,
};



//////////////////////////////////////////////
// Superimpose Data
//////////////////////////////////////////////
struct IMPOSEINFO
{
	wchar_t			Buf[256];
	IMPOSELOCATION	location;
	int				fontsize;
	unsigned int	color;
	bool			scroll;
	bool			transparent;
};





} // namespace STRM
} // namespace SNC

using namespace SNC::STRM;

#endif // !_SNCSTREAMLIBDEFINE_H_