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
�������ܣ���ʼ���豸SDK��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	CoInitializeEx(0, COINIT_MULTITHREADED);
	return TRUE;
}

/*----------------------------------
�������ܣ�ж���豸SDK��
���ò�����void
���óɹ�������TRUE������ʧ�ܣ�����FALSE��
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	CoUninitialize();
	return TRUE;
}

/*----------------------------------
�������ܣ�
���ò�����BASE_PARAM��ָ�룺
���óɹ�������TRUE������ʧ�ܣ�����FALSE��������Ҫ���صĲ��������ڽṹ��BASE_PARAM�С�
����˵����
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
�������ܣ���ֹ�豸ʹ��
���ò������ض��豸�Ľṹ��LOGIN_PARAM��ָ�룺
���óɹ�������TRUE������ʧ�ܣ�����FALSE��������Ҫ���صĲ��������ڽṹ��INIT_PARAM�С�
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam){
	if (commonParam == NULL)
		return FALSE;
	sncwCloseCamera(commonParam->loginID);
	sncCloseCameraHandle(commonParam->loginID);
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
	if (commonParam == NULL)
		return FALSE;

	sncStart(commonParam->loginID);
	while(commonParam->frameBufferSize == 0){
		Sleep(1);
	}

	return TRUE;
}

/*----------------------------------
�������ܣ�ֹͣ����ʵʱ��ý��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StopStreamPlay(CommonParam *commonParam,long channel){
	if (commonParam == NULL)
		return FALSE;

	sncStop(commonParam->loginID);
	return TRUE;
}

/*----------------------------------
�������ܣ���ȡ�豸һ֡ͼ��
���ò������ض��豸�Ľṹ��PICTURE_PARAM��ָ�룺
���óɹ�������TRUE������ʧ�ܣ�����FALSE��������Ҫ���صĲ��������ڽṹ��PICTURE_PARAM��ָ���С�
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if (commonParam == NULL)
		return FALSE;
	commonParam->JPEGSize = RGB2JPEG(commonParam->frameBuffer, commonParam->frameWidth, commonParam->frameHeight, commonParam->JPEGBuffer, 100);
	return TRUE;
}