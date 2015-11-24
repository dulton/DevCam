#include <Windows.h>
#include <stdio.h>
#include "../Common/DevCam.h"
#include "dhnetsdk.h"
#include "YUV2JPG.h"

#pragma comment(lib, "dhnetsdk.lib")
#pragma comment(lib, "dhconfigsdk.lib")
#pragma comment(lib, "YUV2JPG.lib")

void GetSize(unsigned char size,int &width,int &height);

void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser){
}

void CALLBACK AutoConnectFunc(LONG lLoginID,char *pchDVRIP,LONG nDVRPort,DWORD dwUser){
}

void CALLBACK RealDataCallBack(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize,LONG param,LDWORD dwUser){
	unsigned char *frameBuffer = (unsigned char *)dwUser;
	memcpy(frameBuffer,pBuffer,dwBufSize);
}


/*----------------------------------
函数功能：初始化设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	return CLIENT_Init(DisConnectFunc,0);
}

/*----------------------------------
函数功能：卸载设备SDK库
调用参数：void
调用成功，返回TRUE；调用失败，返回FALSE。
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	CLIENT_Cleanup();
	return true;
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

	CLIENT_SetAutoReconnect(AutoConnectFunc,0);

	NET_DEVICEINFO	      deviceInfo = {0};
	int				      error;
	DHDEV_CHANNEL_CFG	  channelConfig = {0};
	DHDEV_SYSTEM_ATTR_CFG systemAttr = {0};
	LDWORD			      bytesReturned;

	commonParam->loginID=CLIENT_Login(commonParam->deviceIP,commonParam->devicePort,commonParam->userName,commonParam->passWord,&deviceInfo,&error);

	if(error != 0){
		commonParam->devError = InitError;
		return FALSE;
	}

	if(!CLIENT_GetDevConfig(commonParam->loginID, DH_DEV_DEVICECFG,-1,&systemAttr,sizeof(systemAttr),&bytesReturned)){
		commonParam->devError = InitError;
		return FALSE;
	}

	if(systemAttr.byDevType == NET_NVR_SERIAL){
		commonParam->deviceType = NET_NVR_SERIAL;
		DEV_ENCODER_CFG_EX encoderConfigEx = {0};
		if(!CLIENT_GetDevConfig(commonParam->loginID, DH_DEV_ENCODER_CFG, -1, &encoderConfigEx,sizeof(encoderConfigEx),&bytesReturned)){
			commonParam->devError = InitError;
			return FALSE;
		}

		commonParam->totalChannels = encoderConfigEx.nChannels;
		commonParam->onlineCameras = new int[encoderConfigEx.nChannels];
		commonParam->cameraParam = new struct tagCommonParam[encoderConfigEx.nChannels];
		for(int i=0;i<encoderConfigEx.nChannels;i++){
			commonParam->onlineCameras[i] = encoderConfigEx.stuDevInfo[i].bDevChnEnable;
			if(encoderConfigEx.stuDevInfo[i].byManuFactory == 22){
				commonParam->onlineCameras[i] = 0;
			}
		}
		
		for(int i = 0;i < encoderConfigEx.nChannels;i++){
			commonParam->cameraParam[i].deviceType = NET_IPC_SERIAL;
			strcpy(commonParam->cameraParam[i].deviceIP,encoderConfigEx.stuDevInfo[i].szDevIp);
			strcpy(commonParam->cameraParam[i].userName,encoderConfigEx.stuDevInfo[i].szDevUser);
			strcpy(commonParam->cameraParam[i].passWord,encoderConfigEx.stuDevInfo[i].szDevPwd);
			commonParam->cameraParam[i].devicePort = encoderConfigEx.stuDevInfo[i].wDevPort;
			commonParam->cameraParam[i].channelNo = encoderConfigEx.stuDevInfo[i].byDecoderID;
		}
	}else if(systemAttr.byDevType == NET_IPC_SERIAL){
		if(commonParam->playHwnd == NULL){
			commonParam->playHwnd = CreateWindow("EDIT",NULL,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,NULL,NULL);
		}
		char *channelName = new char[16*32];
		int channelCount ;
		if(!CLIENT_QueryChannelName(commonParam->loginID,channelName,16*32,&channelCount)){
			commonParam->devError = InitError;
			return FALSE;
		}
		strcpy(commonParam->deviceName,channelName);
		delete []channelName;
		channelName = NULL;
		commonParam->deviceType = NET_IPC_SERIAL;
		CLIENT_GetDevConfig(commonParam->loginID,DH_DEV_CHANNELCFG,0,&channelConfig,sizeof(channelConfig),&bytesReturned);
		GetSize(channelConfig.stMainVideoEncOpt->byImageSize,commonParam->frameWidth,commonParam->frameHeight);
	}else{
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

	if(commonParam->deviceType = NET_IPC_SERIAL){
		
	}

	if(commonParam->deviceType = NET_NVR_SERIAL){
		delete []commonParam->cameraParam;
		commonParam->cameraParam = NULL;
	}

	return CLIENT_Logout(commonParam->loginID);
}

/*----------------------------------
函数功能：获取码流分辨率
调用参数：
返回参数：
函数说明：连接NVR后，获取单个摄像头码流分辨率
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetSize(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		return FALSE;
	}
	if(commonParam->deviceType == NET_IPC_SERIAL){
		return TRUE;
	}
	if(commonParam->cameraParam[channel].playHwnd == NULL){
		commonParam->cameraParam[channel].playHwnd = CreateWindow("EDIT",NULL,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,NULL,NULL);
	}
	NET_DEVICEINFO	      deviceInfo = {0};
	int				      error;
	DHDEV_CHANNEL_CFG	  channelConfig = {0};
	LDWORD			      bytesReturned;
	commonParam->cameraParam[channel].loginID = CLIENT_Login(commonParam->cameraParam[channel].deviceIP,commonParam->cameraParam[channel].devicePort,commonParam->cameraParam[channel].userName,commonParam->cameraParam[channel].passWord,&deviceInfo,&error);
	if(error != 0){
		return FALSE;
	}
	CLIENT_GetDevConfig(commonParam->cameraParam[channel].loginID,DH_DEV_CHANNELCFG,0,&channelConfig,sizeof(channelConfig),&bytesReturned);
	GetSize(channelConfig.stMainVideoEncOpt->byImageSize,commonParam->cameraParam[channel].frameWidth,commonParam->cameraParam[channel].frameHeight);
	CLIENT_Logout(commonParam->cameraParam[channel].loginID);

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

	if(commonParam->deviceType == NET_NVR_SERIAL){
		commonParam->cameraParam[channel].frameBufferSize = commonParam->cameraParam[channel].frameWidth * commonParam->cameraParam[channel].frameHeight * 3 / 2;
		commonParam->cameraParam[channel].frameBuffer = new unsigned char[commonParam->cameraParam[channel].frameBufferSize];
		commonParam->cameraParam[channel].JPEGSize = commonParam->cameraParam[channel].frameWidth * commonParam->cameraParam[channel].frameHeight * 3 / 2;
		commonParam->cameraParam[channel].JPEGBuffer = new unsigned char[commonParam->cameraParam[channel].JPEGSize];
		memset(commonParam->cameraParam[channel].frameBuffer,0,commonParam->cameraParam[channel].frameBufferSize);
		memset(commonParam->cameraParam[channel].JPEGBuffer,0,commonParam->cameraParam[channel].JPEGSize);
		commonParam->cameraParam[channel].playHandle = CLIENT_RealPlay(commonParam->loginID,channel,commonParam->cameraParam[channel].playHwnd);
		CLIENT_SetRealDataCallBackEx(commonParam->cameraParam[channel].playHandle,RealDataCallBack,(DWORD)commonParam->cameraParam[channel].frameBuffer,4);
	}

	if(commonParam->deviceType == NET_IPC_SERIAL){
		commonParam->frameBufferSize = commonParam->frameWidth * commonParam->frameHeight * 3 / 2;
		commonParam->frameBuffer = new unsigned char[commonParam->frameBufferSize];

		commonParam->JPEGSize = commonParam->frameWidth * commonParam->frameHeight * 3 / 2;
		commonParam->JPEGBuffer = new unsigned char[commonParam->JPEGSize];

		memset(commonParam->frameBuffer,0,commonParam->frameBufferSize);
		memset(commonParam->JPEGBuffer,0,commonParam->JPEGSize);

		commonParam->playHandle = CLIENT_RealPlay(commonParam->loginID,commonParam->channelNo,commonParam->playHwnd);
		if(!CLIENT_SetRealDataCallBackEx(commonParam->playHandle,RealDataCallBack,(DWORD)commonParam->frameBuffer,4)){
			return FALSE;
		}
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
	if (commonParam == NULL){
		commonParam->devError = StopPlayError;
		return FALSE;
	}
	
	if(commonParam->deviceType == NET_IPC_SERIAL){
		CLIENT_StopRealPlay(commonParam->playHandle);
		delete []commonParam->frameBuffer;
		commonParam->frameBuffer = NULL;
		delete []commonParam->JPEGBuffer;
		commonParam->JPEGBuffer = NULL;
	}
	if(commonParam->deviceType == NET_NVR_SERIAL){
		CLIENT_StopRealPlay(commonParam->cameraParam[channel].playHandle);
		delete []commonParam->cameraParam[channel].frameBuffer;
		commonParam->cameraParam[channel].frameBuffer = NULL;
		delete []commonParam->cameraParam[channel].JPEGBuffer;
		commonParam->cameraParam[channel].JPEGBuffer = NULL;
	}
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
	if(commonParam->deviceType == NET_NVR_SERIAL){
		if(YUV2JPG(commonParam->cameraParam[channel].frameBuffer, commonParam->cameraParam[channel].frameWidth, commonParam->cameraParam[channel].frameHeight, 100,commonParam->cameraParam[channel].frameWidth,commonParam->cameraParam[channel].JPEGBuffer, (DWORD*)&commonParam->cameraParam[channel].JPEGSize)){
			return FALSE;
		}
	}
	if(commonParam->deviceType == NET_IPC_SERIAL){
		if(YUV2JPG(commonParam->frameBuffer, commonParam->frameWidth, commonParam->frameHeight, 100,commonParam->frameWidth,commonParam->JPEGBuffer, (DWORD*)&commonParam->JPEGSize)){
			return FALSE;
		}
	}

	return true;
}

/*----------------------------------
函数功能：下载录像
调用参数：
返回参数：
函数说明：传入保存目录commonParam->videoPath
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DownLoad(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		return FALSE;
	}
	NET_TIME startTime = {commonParam->cameraParam[channel].startTime.wYear,commonParam->cameraParam[channel].startTime.wMonth,commonParam->cameraParam[channel].startTime.wDay,commonParam->cameraParam[channel].startTime.wHour,commonParam->cameraParam[channel].startTime.wMinute,commonParam->cameraParam[channel].startTime.wSecond};
	NET_TIME endTime = {commonParam->cameraParam[channel].endTime.wYear,commonParam->cameraParam[channel].endTime.wMonth,commonParam->cameraParam[channel].endTime.wDay,commonParam->cameraParam[channel].endTime.wHour,commonParam->cameraParam[channel].endTime.wMinute,commonParam->cameraParam[channel].endTime.wSecond};
	char fileName[64];
	sprintf(fileName,"%s/%d.%d.%d.%d.%d.%d-%d.%d.%d.%d.%d.%d.dav",commonParam->videoPath,startTime.dwYear,startTime.dwMonth,startTime.dwDay,startTime.dwHour,startTime.dwMinute,startTime.dwSecond,endTime.dwYear,endTime.dwMonth,endTime.dwDay,endTime.dwHour,endTime.dwMinute,endTime.dwSecond);
	CLIENT_DownloadByTime(commonParam->loginID,channel,0,&startTime,&endTime,fileName,NULL,NULL);
	return TRUE;
}

void GetSize(unsigned char size,int &width,int &height){
	switch(size){
		case 0:
			width = 704;
			height = 576;
			break;
		case 1:
			width = 352;
			height = 576;
			break;
		case 2:
			width = 704;
			height = 288;
			break;
		case 3:
			width = 352;
			height = 288;
			break;
		case 4:
			width = 176;
			height = 144;
			break;
		case 5:
			width =  640;
			height = 480;
			break;
		case 6:
			width = 320;
			height = 240;
			break;
		case 7:
			width = 480;
			height = 480;
			break;
		case 8:
			width = 160;
			height = 128;
			break;
		case 9:
			width = 800;
			height = 592;
			break;
		case 10:
			width = 1024;
			height = 768;
			break;
		case 11:
			width = 1280;
			height = 800;
			break;
		case 12:
			width = 1280;
			height = 1024;
			break;
		case 13:
			width = 1600;
			height = 1024;
			break;
		case 14:
			width = 1600;
			height = 1200;
			break;
		case 15:
			width = 1920;
			height = 1200;
			break;
		case 16:
			width = 240;
			height = 192;
			break;
		case 17:
			width = 1280;
			height = 720;
			break;
		case 18:
			width = 1920;
			height = 1080;
			break;
		case 19:
			width = 1280;
			height = 960;
			break;
		case 20:
			width = 1872;
			height = 1408;
			break;
		case 21:
			width = 3744;
			height = 1408;
			break;
		case 22:
			width = 2048;
			height = 1536;
			break;
		case 23:
			width = 2432;
			height = 2050;
			break;
		case 24:
			width = 1216;
			height = 1024;
			break;
		case 25:
			width = 1408;
			height = 1024;
			break;
		case 26:
			width = 3296;
			height = 2472;
			break;
		case 27:
			width = 2560;
			height = 1920;
			break;
		case 28:
			width = 960;
			height = 576;
			break;
		case 29:
			width = 960;
			height = 720;
			break;
		case 30:
			width = 640;
			height = 360;
			break;
		case 31:
			width = 320;
			height = 180;
			break;
		case 32:
			width = 160;
			height = 90;
			break;
		case 255:
			break;
	}
}