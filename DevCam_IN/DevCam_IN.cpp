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
�������ܣ���ʼ���豸SDK��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	INFNET_Init();
	INFPLAY_Init();
	return TRUE;
}

/*----------------------------------
�������ܣ�ж���豸SDK��
���ò�����void
���óɹ�������TRUE������ʧ�ܣ�����FALSE��
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	INFNET_Cleanup();
	INFPLAY_Cleanup();
	return TRUE;
}

/*----------------------------------
�������ܣ�
���ò�����BASE_PARAM��ָ�룺
���óɹ�������TRUE������ʧ�ܣ�����FALSE��������Ҫ���صĲ��������ڽṹ��BASE_PARAM�С�
����˵����
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
�������ܣ���ֹ�豸ʹ��
���ò������ض��豸�Ľṹ��LOGIN_PARAM��ָ�룺
���óɹ�������TRUE������ʧ�ܣ�����FALSE��������Ҫ���صĲ��������ڽṹ��INIT_PARAM�С�
����˵����
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
�������ܣ���ȡ�����ֱ���
���ò�����
���ز�����
����˵��������NVR�󣬻�ȡ��������ͷ�����ֱ���
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetSize(CommonParam *commonParam,long channel){
	return TRUE;
}

/*----------------------------------
�������ܣ���ʼ����ʵʱ��ý��
���ò�����
���ز�����
����˵����
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
�������ܣ�ֹͣ����ʵʱ��ý��
���ò�����
���ز�����
����˵����
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
�������ܣ���ȡ�豸һ֡ͼ��
���ò������ض��豸�Ľṹ��PICTURE_PARAM��ָ�룺
���óɹ�������TRUE������ʧ�ܣ�����FALSE��������Ҫ���صĲ��������ڽṹ��PICTURE_PARAM��ָ���С�
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		commonParam->devError = CaptureError;
		return FALSE;
	}

	commonParam->JPEGSize = YUV422ToJPEG(commonParam->frameBuffer, commonParam->frameWidth, commonParam->frameHeight, commonParam->JPEGBuffer, 100);

	return TRUE;
}