#include <Windows.h>
#include <iostream>
#include "../Common/DevCam.h"
#include "SncCoreLib.h"
#include "SncStreamLib.h"
#include "SncCGIWrapperLib.h"
#include "RGB2JPEG.h"

#pragma comment(lib,"snccore.lib")
#pragma comment(lib,"sncstrm.lib")
#pragma comment(lib,"snccgiw.lib")

using namespace std;

void __stdcall SncVCallBack(VIDEOINFO *pVideoInfo,unsigned long Param ){
	LPCommonParam lpCommonParam = (LPCommonParam)Param;
	if(pVideoInfo->VideoCodecInfo.Codec == VIDEO_CODEC_JPEG){
		lpCommonParam->frameBufferSize = pVideoInfo->BufLen;
		memcpy(lpCommonParam->frameBuffer,pVideoInfo->pBuf,pVideoInfo->BufLen);
	}
}

/*----------------------------------
函数功能：初始化设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	CoInitializeEx(0, COINIT_MULTITHREADED);
	return TRUE;
}

/*----------------------------------
函数功能：卸载设备SDK库
调用参数：void
调用成功，返回TRUE；调用失败，返回FALSE。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	CoUninitialize();
	return TRUE;
}

/*----------------------------------
函数功能：
调用参数：BASE_PARAM的指针：
调用成功，返回TRUE；调用失败，返回FALSE。其它需要返回的参数，置于结构：BASE_PARAM中。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Init(CommonParam *commonParam){
	if (commonParam == NULL)
		return FALSE;

	commonParam->frameBufferSize = 0;

	NETINFO netInfo;
	VIDEOCODECINFO videoCodecInfo;
	memset(&netInfo,0,sizeof(netInfo));
	memset(&videoCodecInfo,0,sizeof(videoCodecInfo));
	strcpy(netInfo.CamIpAddr,commonParam->deviceIP);
	netInfo.CamIpVersion = IPVERSION_UNKNOWN;
	netInfo.CamPort = commonParam->devicePort;
	netInfo.ProxyFunc = false;
	netInfo.ProxyIpVersion = IPVERSION_UNKNOWN;
	netInfo.AuthenticationFunc = true;

	commonParam->loginID = sncOpenCameraHandle();

	sncInitialize(commonParam->loginID);

	snccSetNetwork(commonParam->loginID,&netInfo);

	sncwOpenCamera(commonParam->loginID);

	IMAGE_CODEC imageCodec;
	sncwGetImageCodecEx(commonParam->loginID,1,&imageCodec);
	if((imageCodec != IMAGE_CODEC_jpeg) && (imageCodec != IMAGE_CODEC_jpeg_mpeg4) && (imageCodec != IMAGE_CODEC_mpeg4_jpeg) && (imageCodec != IMAGE_CODEC_jpeg_h264) && (imageCodec != IMAGE_CODEC_h264_jpeg)){
		commonParam->devError = InitError;
		return FALSE;
	}

	RECT rect;
	GetClientRect(commonParam->playHwnd,&rect);

	sncCreateScreen(commonParam->loginID,commonParam->playHwnd,0,0,rect.right - rect.left,rect.bottom - rect.top);

	sncEnableVideoStream(commonParam->loginID,true);

	sncEnableVideoPlay(commonParam->loginID,true);

	ImageSizeType imageSizeType;

	sncwGetImageSizeEx(commonParam->loginID,1 ,&imageSizeType);

	commonParam->frameWidth = imageSizeType.width;

	commonParam->frameHeight = imageSizeType.height;

	sncSetCallBack(commonParam->loginID,CALLBACK_DEC_VIDEO,SncVCallBack,(unsigned long)commonParam);

	return TRUE;
}

/*----------------------------------
函数功能：终止设备使用
调用参数：特定设备的结构：LOGIN_PARAM的指针：
调用成功，返回TRUE；调用失败，返回FALSE。其它需要返回的参数，置于结构：INIT_PARAM中。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam){
	if (commonParam == NULL)
		return FALSE;
	sncwCloseCamera(commonParam->loginID);
	sncCloseCameraHandle(commonParam->loginID);
	return TRUE;
}

/*----------------------------------
函数功能：获取码流分辨率
调用参数：
返回参数：
函数说明：连接NVR后，获取单个摄像头码流分辨率
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetSize(CommonParam *commonParam,long channel){
	return TRUE;
}

/*----------------------------------
函数功能：开始播放实时流媒体
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StartStreamPlay(CommonParam *commonParam,long channel){
	if (commonParam == NULL)
		return FALSE;

	sncStart(commonParam->loginID);
	while(commonParam->frameBufferSize == 0){
		Sleep(1);
	}

	return TRUE;
}

/*----------------------------------
函数功能：停止播放实时流媒体
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StopStreamPlay(CommonParam *commonParam,long channel){
	if (commonParam == NULL)
		return FALSE;

	sncStop(commonParam->loginID);
	return TRUE;
}

/*----------------------------------
函数功能：获取设备一帧图像
调用参数：特定设备的结构：PICTURE_PARAM的指针：
调用成功，返回TRUE；调用失败，返回FALSE。其它需要返回的参数，置于结构：PICTURE_PARAM的指针中。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if (commonParam == NULL)
		return FALSE;
	commonParam->JPEGSize = RGB2JPEG(commonParam->frameBuffer, commonParam->frameWidth, commonParam->frameHeight, commonParam->JPEGBuffer, 100);
	return TRUE;
}