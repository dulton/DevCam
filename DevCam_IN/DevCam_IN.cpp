#include "INFSDK_Net.h"
#include "INFSDK_Play.h"
#include "../Common/DevCam.h"
#include "YUV422toJPEG.h"

#pragma comment (lib,"INFSDK_Net.lib")
#pragma comment (lib,"INFSDK_Play.lib")

void CALLBACK MyCBRealData(long lRealHandle,E_REALDATA_TYPE eDataType,unsigned char *pBuffer,unsigned long lBufSize,void *pUserData){
	long *playHandle = (long*)pUserData;
	if(eDataType == REALDATA_HEAD){
		*playHandle = INFPLAY_OpenStream(pBuffer,lBufSize);
	}

	if(eDataType == REALDATA_VIDEO){
		INFPLAY_InputData(*playHandle,pBuffer,lBufSize);
	}
}

unsigned char *imageBuffer;
void CALLBACK MyCBDecodeCallBack( long lPlayHandle,unsigned char *pBuf,unsigned long nBufSize,S_FRAMEINFO *pFrameInfo,void *pUserData ){
	unsigned char* buffer = (unsigned char*)pUserData;
	imageBuffer = pBuf;
}

/*----------------------------------
函数功能：初始化设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	INFNET_Init();
	INFPLAY_Init();
	return TRUE;
}

/*----------------------------------
函数功能：卸载设备SDK库
调用参数：void
调用成功，返回TRUE；调用失败，返回FALSE。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	INFNET_Cleanup();
	INFPLAY_Cleanup();
	return TRUE;
}

/*----------------------------------
函数功能：
调用参数：BASE_PARAM的指针：
调用成功，返回TRUE；调用失败，返回FALSE。其它需要返回的参数，置于结构：BASE_PARAM中。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Init(CommonParam *commonParam){
	if (commonParam == NULL){
		commonParam->devError = InitError;
		return FALSE;
	}

	commonParam->playHandle = -1;

	S_REALDATA_INFO realData = {commonParam->channelNo,0,ENCODE_H264};

	commonParam->loginID = INFNET_Login(commonParam->deviceIP,commonParam->devicePort,commonParam->userName,commonParam->passWord);
	INFNET_StartRealData(commonParam->loginID,&realData,MyCBRealData,&commonParam->playHandle);
	while(commonParam->playHandle == -1){
		Sleep(1);
	}

	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);
	char infinovaCaptureName[128];
	sprintf(infinovaCaptureName,"InfinovaCaptureName%d%d%d%d%d%d%d%d.bmp",systemTime.wYear,systemTime.wMonth,systemTime.wDay,systemTime.wDayOfWeek,systemTime.wHour,systemTime.wMinute,systemTime.wSecond,systemTime.wMilliseconds);
	INFPLAY_CapturePicture(commonParam->playHandle,infinovaCaptureName,PIC_BMP );
	int size[2];
	FILE *fp = NULL;
	fp = fopen(infinovaCaptureName,"r");
	if(fp == NULL){
		commonParam->devError = InitError;
		return FALSE;
	}
	fseek(fp,18,SEEK_SET);
	fread(size,1,8,fp);
	fclose(fp);
	remove(infinovaCaptureName);
	commonParam->frameWidth = size[0];
	commonParam->frameHeight = size[1];

	if(!INFPLAY_SetDecodeCallBack(commonParam->playHandle ,MyCBDecodeCallBack,commonParam->frameBuffer)){
		commonParam->devError = InitError;
		return FALSE;
	}
	return TRUE;
}

/*----------------------------------
函数功能：终止设备使用
调用参数：特定设备的结构：LOGIN_PARAM的指针：
调用成功，返回TRUE；调用失败，返回FALSE。其它需要返回的参数，置于结构：INIT_PARAM中。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam){
	if (commonParam == NULL){
		commonParam->devError = UnInitError;
		return FALSE;
	}

	if(!INFPLAY_CloseStream( commonParam->playHandle )){
		commonParam->devError = UnInitError;
		return FALSE;
	}
	if(!INFNET_Logout(commonParam->loginID)){
		commonParam->devError = UnInitError;
		return FALSE;
	}
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
	if (commonParam == NULL){
		commonParam->devError = PlayError;
		return FALSE;
	}

	commonParam->JPEGSize = commonParam->frameWidth*commonParam->frameHeight*3/2;
	commonParam->JPEGBuffer = new unsigned char[commonParam->JPEGSize];
	memset(commonParam->frameBuffer,0,commonParam->frameBufferSize);
	
	imageBuffer = NULL;

	if(!INFPLAY_Play(commonParam->playHandle ,commonParam->playHwnd,TRUE)){
		commonParam->devError = PlayError;
		return FALSE;
	}

	while(imageBuffer == NULL){
		Sleep(1);
	}

	commonParam->frameBuffer = imageBuffer;

	return TRUE;
}

/*----------------------------------
函数功能：停止播放实时流媒体
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StopStreamPlay(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		commonParam->devError = StopPlayError;
		return FALSE;
	}

	if(!INFPLAY_Stop(commonParam->playHandle)){
		commonParam->devError = StopPlayError;
		return FALSE;
	}

	if(!INFNET_StopRealData(commonParam->playHandle)){
		commonParam->devError = StopPlayError;
		return FALSE;
	}

	delete []commonParam->JPEGBuffer;
	commonParam->JPEGBuffer = NULL;

	return TRUE;
}

/*----------------------------------
函数功能：获取设备一帧图像
调用参数：特定设备的结构：PICTURE_PARAM的指针：
调用成功，返回TRUE；调用失败，返回FALSE。其它需要返回的参数，置于结构：PICTURE_PARAM的指针中。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		commonParam->devError = CaptureError;
		return FALSE;
	}

	commonParam->JPEGSize = YUV422ToJPEG(commonParam->frameBuffer, commonParam->frameWidth, commonParam->frameHeight, commonParam->JPEGBuffer, 100);

	return TRUE;
}