#include <Windows.h>
#include <iostream>
#include "../Common/DevCam.h"
#include "imos_sdk_def.h"
#include "imos_sdk_pub.h"
#include "imos_sdk_func.h"
#include "YUV2JPG.h"

#pragma comment (lib,"imos_mw_sdk.lib")
#pragma comment (lib,"YUV2JPG.lib")

using namespace std;

VOID STDCALL DecodeVideoDataCallback(IN ULONG ulStreamHandle,IN const IMOS_MW_PICTURE_DATA_S *pstPictureData,IN LONG lUserParam,IN LONG lReserved){
	unsigned char *buffer = (unsigned char*)lUserParam;
	memcpy(buffer,pstPictureData->pucData[0],pstPictureData->ulPicWidth*pstPictureData->ulPicHeight);
	memcpy(buffer+pstPictureData->ulPicWidth*pstPictureData->ulPicHeight,pstPictureData->pucData[1],pstPictureData->ulPicWidth*pstPictureData->ulPicHeight/4);
	memcpy(buffer+pstPictureData->ulPicWidth*pstPictureData->ulPicHeight*5/4,pstPictureData->pucData[2],pstPictureData->ulPicWidth*pstPictureData->ulPicHeight/4);
}

/*----------------------------------
函数功能：初始化设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	IMOS_MW_Initiate();
	return TRUE;
}

/*----------------------------------
函数功能：卸载设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	IMOS_MW_Cleanup();
	return TRUE;
}

/*----------------------------------
函数功能：设备初始化
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Init(CommonParam *commonParam){
	if(IMOS_MW_Login(commonParam->userName,commonParam->passWord,commonParam->deviceIP,0,commonParam->UVLoginID)){
		commonParam->devError = InitError;
		return FALSE;
	}
	if(IMOS_MW_StartMediaStream(commonParam->UVLoginID,0,IMOS_MW_STREAM_ID_MAIN,IMOS_MW_TRANSFER_MODE_RTP_TCP,NULL,0,BOOL_TRUE,(unsigned long*)&commonParam->playHandle)){
		commonParam->devError = InitError;
		return FALSE;
	}

	IMOS_MW_VIDEO_ENCODER_CFG_S videoEncoderCfg;
	ULONG bufferLen = sizeof(IMOS_MW_VIDEO_ENCODER_CFG_S);
	videoEncoderCfg.ulStreamID = IMOS_MW_STREAM_ID_MAIN;
	if(IMOS_MW_GetConfig (commonParam->UVLoginID,IMOS_MW_VIDEO_ENCODER_CFG,0,&bufferLen,&videoEncoderCfg)){
		commonParam->devError = InitError;
		return FALSE;
	}
	commonParam->frameWidth = videoEncoderCfg.stVideoStreamCfg.stResolution.ulWidth;
	commonParam->frameHeight = videoEncoderCfg.stVideoStreamCfg.stResolution.ulHeight;
	return TRUE;
}

/*----------------------------------
函数功能：终止设备使用
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam){
	IMOS_MW_Logout(commonParam->UVLoginID);
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
	commonParam->frameBufferSize = commonParam->frameWidth*commonParam->frameHeight*3/2;
	commonParam->frameBuffer = new unsigned char[commonParam->frameBufferSize];
	memset(commonParam->frameBuffer,0,commonParam->frameBufferSize);

	commonParam->JPEGSize = commonParam->frameWidth*commonParam->frameHeight*3/2;
	commonParam->JPEGBuffer = new unsigned char[commonParam->JPEGSize];
	memset(commonParam->frameBuffer,0,commonParam->frameBufferSize);

	if(IMOS_MW_StartPlay((ULONG)commonParam->playHwnd,(unsigned long)commonParam->playHandle)){
		commonParam->devError = PlayError;
		return FALSE;
	}
	if(IMOS_MW_SetDecodedVideoDataCallback((unsigned long)commonParam->playHandle,DecodeVideoDataCallback,BOOL_TRUE,(long)commonParam->frameBuffer)){
		commonParam->devError = PlayError;
		return FALSE;
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
	IMOS_MW_StopPlay((ULONG)commonParam->playHwnd);
	delete []commonParam->frameBuffer;
	commonParam->frameBuffer = NULL;
	delete []commonParam->JPEGBuffer;
	commonParam->JPEGBuffer = NULL;
	return TRUE;
}

/*----------------------------------
函数功能：获取设备一帧图像
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if(YUV2JPG(commonParam->frameBuffer,commonParam->frameWidth,commonParam->frameHeight,100,commonParam->frameWidth,commonParam->JPEGBuffer,(unsigned long*)&commonParam->JPEGSize)){
		commonParam->devError = CaptureError;
		return FALSE;
	}else{
		commonParam->devError = NoError;
	}
	return TRUE;
}