#include <Windows.h>
#include <stdio.h>
#include "HCNetSDK.h"
#include "../Common/DevCam.h"

#pragma comment (lib,"HCNetSDK.lib")

void CALLBACK RealDataCallBack (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser){
}

/*----------------------------------
函数功能：初始化设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	NET_DVR_Init();
	return TRUE;
}


/*----------------------------------
函数功能：卸载设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	NET_DVR_Cleanup();
	return TRUE;
}

/*----------------------------------
函数功能：设备初始化
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Init(CommonParam *commonParam){
	if (commonParam == NULL){
		commonParam->devError = InitError;
		return FALSE;
	}

	NET_DVR_DEVICEINFO_V30 deviceInfo = {0};
	NET_DVR_USER_LOGIN_INFO loginInfo = {0};
	strcpy(loginInfo.sDeviceAddress,commonParam->deviceIP);
	strcpy(loginInfo.sUserName,commonParam->userName);
	strcpy(loginInfo.sPassword,commonParam->passWord);
	loginInfo.wPort = commonParam->devicePort;

	commonParam->loginID = NET_DVR_Login_V40(&loginInfo,&deviceInfo);

	if(commonParam->loginID<0){
		commonParam->devError = InitError;
		return FALSE;
	}

	//deviceType:0代表IPC，1代表NVR
	if(deviceInfo.byIPChanNum + deviceInfo.byHighDChanNum*256 == 0){
		commonParam->deviceType = 0;

		NET_DVR_PICCFG_V40 picCfg = {0};
		DWORD bytesReturned;
		NET_DVR_GetDVRConfig(commonParam->loginID,NET_DVR_GET_PICCFG_V40,1,&picCfg,sizeof(NET_DVR_PICCFG_V40),&bytesReturned);
		strcpy(commonParam->deviceName,(char*)picCfg.sChanName);

		//获取镜头配置分辨率:截取一帧图片（JPEG格式），读取0xffc0标志位后面的尺寸信息
		NET_DVR_JPEGPARA jpegPara = {255,0};
		SYSTEMTIME systeTime; 
		GetLocalTime( &systeTime); 
		char haiKangCaptureName[64];
		sprintf(haiKangCaptureName,"HaiKangCapture%d%d%d%d%d%d%d%d.jpg",systeTime.wYear,systeTime.wMonth,systeTime.wDay,systeTime.wDayOfWeek,systeTime.wHour,systeTime.wMinute,systeTime.wSecond,systeTime.wMilliseconds);
		if(!NET_DVR_CaptureJPEGPicture(commonParam->loginID,1,&jpegPara,haiKangCaptureName)){
			commonParam->devError = InitError;
			return FALSE;
		}
		FILE *fp = NULL;
		fp = fopen(haiKangCaptureName,"r");
		if(fp == NULL){
			commonParam->devError = InitError;
			return FALSE;
		}
		unsigned char *c = new unsigned char[10240];
		memset(c, 0, 10240);
		fread(c,1,10240,fp);
		for(int i = 0;i<10240;i++){
			if(c[i] == 0xff){
				i++;
				if(c[i] == 0xc0){
					i+=4;
					commonParam->frameHeight = c[i];
					commonParam->frameHeight = commonParam->frameHeight * 256 + c[i+1];
					commonParam->frameWidth = c[i+2];
					commonParam->frameWidth = commonParam->frameWidth * 256 + c[i+3];
					break;
				}
			}
		}
		delete []c;
		c = NULL;
		fclose(fp);
		remove(haiKangCaptureName);
	}else{
		commonParam->deviceType = 1;
		commonParam->totalChannels = deviceInfo.byIPChanNum + deviceInfo.byHighDChanNum*256;
		commonParam->onlineCameras = new int[commonParam->totalChannels];
		commonParam->cameraParam = new struct tagCommonParam[commonParam->totalChannels];
		commonParam->channelNo = deviceInfo.byStartDChan;
		NET_DVR_IPPARACFG_V40 ipParaCfg;
		unsigned long bytesReturned;
		NET_DVR_GetDVRConfig(commonParam->loginID,NET_DVR_GET_IPPARACFG_V40,0xffffffff,&ipParaCfg,sizeof(NET_DVR_IPPARACFG_V40),&bytesReturned);
		for(int i=0;i<commonParam->totalChannels;i++){
			strcpy(commonParam->cameraParam[i].deviceIP,ipParaCfg.struIPDevInfo[i].struIP.sIpV4);
			commonParam->onlineCameras[i] = ipParaCfg.struIPDevInfo[i].byEnable;
			if(ipParaCfg.struIPDevInfo[i].byProType == 18){
				commonParam->onlineCameras[i] = 0;
			}
		}
	}

	return TRUE;
}


/*----------------------------------
函数功能：终止设备使用
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam){
	if (commonParam == NULL){
		commonParam->devError = UnInitError;
		return FALSE;
	}

	if(commonParam->deviceType == 1){
		delete []commonParam->onlineCameras;
		commonParam->onlineCameras = NULL;
		delete []commonParam->cameraParam;
		commonParam->cameraParam = NULL;
	}
	NET_DVR_Logout(commonParam->loginID);

	return TRUE;
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
	if(commonParam->deviceType == 0){
		return TRUE;
	}

	NET_DVR_JPEGPARA jpegPara = {255,0};
	SYSTEMTIME systeTime; 
	GetLocalTime( &systeTime); 
	char haiKangCaptureName[64];
	sprintf(haiKangCaptureName,"HaiKangCapture%d%d%d%d%d%d%d%d.jpg",systeTime.wYear,systeTime.wMonth,systeTime.wDay,systeTime.wDayOfWeek,systeTime.wHour,systeTime.wMinute,systeTime.wSecond,systeTime.wMilliseconds);
	if(!NET_DVR_CaptureJPEGPicture(commonParam->loginID,commonParam->channelNo + channel,&jpegPara,haiKangCaptureName)){
		return FALSE;
	}
	FILE *fp = NULL;
	fp = fopen(haiKangCaptureName,"r");
	if(fp == NULL){
		commonParam->devError = InitError;
		return FALSE;
	}
	unsigned char *c = new unsigned char[10240];
	memset(c, 0, 10240);
	fread(c,1,10240,fp);
	for(int i = 0;i<10240;i++){
		if(c[i] == 0xff){
			i++;
			if(c[i] == 0xc0){
				i+=4;
				commonParam->cameraParam[channel].frameHeight = c[i];
				commonParam->cameraParam[channel].frameHeight = commonParam->cameraParam[channel].frameHeight * 256 + c[i+1];
				commonParam->cameraParam[channel].frameWidth = c[i+2];
				commonParam->cameraParam[channel].frameWidth = commonParam->cameraParam[channel].frameWidth * 256 + c[i+3];
				break;
			}
		}
	}
	delete []c;
	c = NULL;
	fclose(fp);
	remove(haiKangCaptureName);

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

	if(commonParam->deviceType == 0){
		commonParam->JPEGSize = commonParam->frameWidth*commonParam->frameHeight*3/2;
		commonParam->JPEGBuffer = new unsigned char[commonParam->JPEGSize];
		memset(commonParam->JPEGBuffer,0,commonParam->JPEGSize);

		NET_DVR_CLIENTINFO clientInfo = {1,0,commonParam->playHwnd,NULL};
		commonParam->playHandle = NET_DVR_RealPlay_V30(commonParam->loginID, &clientInfo);

		if (commonParam->playHandle < 0){
			commonParam->devError = PlayError;
			return FALSE;
		}
		//NET_DVR_SetRealDataCallBack(commonParam->playHandle,RealDataCallBack,0);
	}

	if(commonParam->deviceType == 1){
		commonParam->cameraParam[channel].JPEGSize = commonParam->cameraParam[channel].frameWidth*commonParam->cameraParam[channel].frameHeight*3/2;
		commonParam->cameraParam[channel].JPEGBuffer = new unsigned char[commonParam->cameraParam[channel].JPEGSize];
		memset(commonParam->cameraParam[channel].JPEGBuffer,0,commonParam->cameraParam[channel].JPEGSize);

		NET_DVR_CLIENTINFO clientInfo = {commonParam->channelNo + channel,0,commonParam->cameraParam[channel].playHwnd,NULL};
		commonParam->cameraParam[channel].playHandle = NET_DVR_RealPlay_V30(commonParam->loginID, &clientInfo);
		if (commonParam->cameraParam[channel].playHandle < 0){
			commonParam->devError = PlayError;
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

	if(commonParam->deviceType == 0){
		if(!NET_DVR_StopRealPlay(commonParam->playHandle)){
			commonParam->devError = StopPlayError;
			return FALSE;
		}
		delete []commonParam->JPEGBuffer;
		commonParam->JPEGBuffer = NULL;
	}

	if(commonParam->deviceType == 1){
		if(!NET_DVR_StopRealPlay(commonParam->cameraParam[channel].playHandle)){
			commonParam->devError = StopPlayError;
			return FALSE;
		}
		delete []commonParam->cameraParam[channel].JPEGBuffer;
		commonParam->cameraParam[channel].JPEGBuffer = NULL;
	}
	return TRUE;
}

/*----------------------------------
函数功能：获取设备一帧图像
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		commonParam->devError = CaptureError;
		return FALSE;
	}

	NET_DVR_JPEGPARA jpegPara = {255,0};
	if(commonParam->deviceType == 0){
		if(!NET_DVR_CaptureJPEGPicture_NEW(commonParam->loginID, 1, &jpegPara, (char*)commonParam->JPEGBuffer, commonParam->frameHeight*commonParam->frameWidth*3/2+1000, (LPDWORD)&commonParam->JPEGSize)){
			commonParam->devError = CaptureError;
			return FALSE;
		}else{
			commonParam->devError = NoError;
		}
	}

	if(commonParam->deviceType == 1){
		if(!NET_DVR_CaptureJPEGPicture_NEW(commonParam->loginID, commonParam->channelNo + channel, &jpegPara, (char*)commonParam->cameraParam[channel].JPEGBuffer, commonParam->cameraParam[channel].frameHeight*commonParam->cameraParam[channel].frameWidth*3/2+1000, (LPDWORD)&commonParam->cameraParam[channel].JPEGSize)){
			commonParam->devError = CaptureError;
			return FALSE;
		}else{
			commonParam->devError = NoError;
		}
	}

	return TRUE;
}

/*----------------------------------
函数功能：下载录像
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DownLoad(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		return FALSE;
	}
	NET_DVR_PLAYCOND  downloadCond = {0};
	downloadCond.dwChannel = commonParam->channelNo + channel;
	downloadCond.struStartTime.dwYear = commonParam->cameraParam[channel].startTime.wYear;
	downloadCond.struStartTime.dwMonth = commonParam->cameraParam[channel].startTime.wMonth;
	downloadCond.struStartTime.dwDay = commonParam->cameraParam[channel].startTime.wDay;
	downloadCond.struStartTime.dwHour = commonParam->cameraParam[channel].startTime.wHour;
	downloadCond.struStartTime.dwMinute = commonParam->cameraParam[channel].startTime.wMinute;
	downloadCond.struStartTime.dwSecond = commonParam->cameraParam[channel].startTime.wSecond;

	downloadCond.struStopTime.dwYear = commonParam->cameraParam[channel].endTime.wYear;
	downloadCond.struStopTime.dwMonth = commonParam->cameraParam[channel].endTime.wMonth;
	downloadCond.struStopTime.dwDay = commonParam->cameraParam[channel].endTime.wDay;
	downloadCond.struStopTime.dwHour = commonParam->cameraParam[channel].endTime.wHour;
	downloadCond.struStopTime.dwMinute = commonParam->cameraParam[channel].endTime.wMinute;
	downloadCond.struStopTime.dwSecond = commonParam->cameraParam[channel].endTime.wSecond;

	char fileName[64];
	sprintf(fileName,"%s/%d.%d.%d.%d.%d.%d-%d.%d.%d.%d.%d.%d.mp4",commonParam->videoPath,downloadCond.struStartTime.dwYear,downloadCond.struStartTime.dwMonth,downloadCond.struStartTime.dwDay,downloadCond.struStartTime.dwHour,downloadCond.struStartTime.dwMinute,downloadCond.struStartTime.dwSecond,downloadCond.struStopTime.dwYear,downloadCond.struStopTime.dwMonth,downloadCond.struStopTime.dwDay,downloadCond.struStopTime.dwHour,downloadCond.struStopTime.dwMinute,downloadCond.struStopTime.dwSecond);
	NET_DVR_GetFileByTime_V40(commonParam->loginID,fileName,&downloadCond);
	return TRUE;
}