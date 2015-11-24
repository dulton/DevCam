#include <Windows.h>
#include <iostream>
#include "include/SDL.h"
#include "../Common/DevCam.h"
#include "HWPuSDK.h"
#include "YUV2JPG.h"

#pragma comment (lib,"HWPuSDK.lib")
#pragma comment (lib,"YUV2JPG.lib")
#pragma comment (lib,"SDL2.lib")

using namespace std;

DWORD WINAPI Play(LPVOID lpParam);

VOID CALLBACK RealDataCallBack(CHAR *szBuffer, LONG lSize, VOID *pUsrData){
	unsigned char *buffer = (unsigned char*)pUsrData;
	memcpy(buffer,szBuffer,lSize);
}

void GetSize(PU_RESOLUTION_TYPE_E,int&,int&);

/*----------------------------------
�������ܣ���ʼ���豸SDK��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK(){
	SDL_Init(SDL_INIT_VIDEO);
	IVS_PU_Init(PU_BOTHLOGIN_MODE,NULL,6060);
	return TRUE;
}

/*----------------------------------
�������ܣ�ж���豸SDK��
���ò�����void
���óɹ�������TRUE������ʧ�ܣ�����FALSE��
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK(){
	IVS_PU_Cleanup();
	SDL_Quit();
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

	commonParam->loginID = IVS_PU_Login(commonParam->deviceIP,6060,commonParam->userName,commonParam->passWord);

	if(commonParam->loginID == 0){
		commonParam->devError = InitError;
		return FALSE;
	}

	PU_VIDEO_STREAM_INFO_S videoStreamInfo = {0};
	videoStreamInfo.ulChannelId = 101;
	if(!IVS_PU_GetVideoStreamInfo(commonParam->loginID,&videoStreamInfo)){
		commonParam->devError = InitError;
		return FALSE;
	}

	GetSize(videoStreamInfo.stStreamAttribute->stVideoAttribute.enResolution,commonParam->frameWidth,commonParam->frameHeight);

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

	return IVS_PU_Logout(commonParam->loginID);
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

	commonParam->frameBufferSize = commonParam->frameWidth*commonParam->frameHeight*3/2;
	commonParam->frameBuffer = new unsigned char[commonParam->frameBufferSize];
	memset(commonParam->frameBuffer,0,commonParam->frameBufferSize);
	commonParam->JPEGSize = commonParam->frameWidth*commonParam->frameHeight*3/2;
	commonParam->JPEGBuffer = new unsigned char[commonParam->JPEGSize];
	memset(commonParam->JPEGBuffer,0,commonParam->JPEGSize);

	PU_REAL_PLAY_INFO_S realPlayInfo = {0};
	realPlayInfo.ulChannelId = 101;
	realPlayInfo.enProtocolType = PU_PROTOCOL_TYPE_TCP;
	//realPlayInfo.hPlayWnd = commonParam->playHwnd;

	realPlayInfo.enMediaCallbackType = PU_MEDIA_CALLBACK_TYPE_YUV;

	commonParam->playHandle = IVS_PU_RealPlay(commonParam->loginID,&realPlayInfo,RealDataCallBack,commonParam->frameBuffer);

	CreateThread(NULL,0,Play,commonParam,NULL,NULL);

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

	IVS_PU_StopRealPlay(commonParam->loginID,commonParam->playHandle);

	delete []commonParam->frameBuffer;
	commonParam->frameBuffer = NULL;
	delete []commonParam->JPEGBuffer;
	commonParam->JPEGBuffer = NULL;

	return TRUE;
}

_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel){
	if (commonParam == NULL){
		commonParam->devError = CaptureError;
		return FALSE;
	}
	
	YUV2JPG(commonParam->frameBuffer,commonParam->frameWidth,commonParam->frameHeight,100,commonParam->frameWidth,commonParam->JPEGBuffer,(DWORD*)&commonParam->JPEGSize);
	
	return TRUE;
}

DWORD WINAPI Play(LPVOID lpParam){
	LPCommonParam lpCommonParam= (LPCommonParam)lpParam;
	SDL_Window *window = SDL_CreateWindowFrom(lpCommonParam->playHwnd);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING,lpCommonParam->frameWidth,lpCommonParam->frameHeight);
	int pitch = lpCommonParam->frameWidth*SDL_BYTESPERPIXEL(SDL_PIXELFORMAT_IYUV); 
	while(lpCommonParam->frameBuffer != NULL){
		SDL_UpdateTexture(texture,NULL,lpCommonParam->frameBuffer, pitch );
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer,texture,NULL,NULL);
		SDL_RenderPresent(renderer);
	}
	return 0;
}

void GetSize(PU_RESOLUTION_TYPE_E resolution,int &width,int &height){
	switch(resolution){
		case PU_RESOLUTION_CIF_PAL:
			width = 352;
			height = 288;
			break;
		case PU_RESOLUTION_CIF_NTSC:
			width = 352;
			height = 240;
			break;
		case PU_RESOLUTION_D1_PAL:
			width = 704;
			height = 576;
			break;
		case PU_RESOLUTION_D1_NTSC:
			width = 704;
			height = 480;
			break;
		case PU_RESOLUTION_QVGA:
			width = 320;
			height = 240;
			break;
		case PU_RESOLUTION_VGA:
			width = 640;
			height = 480;
			break;
		case PU_RESOLUTION_XGA:
			width = 1024;
			height = 768;
			break;
		case PU_RESOLUTION_SXGA:
			width = 1400;
			height = 1050;
			break;
		case PU_RESOLUTION_UXGA:
			width = 1600;
			height = 1200;
			break;
		case PU_RESOLUTION_QXGA:
			width = 2048;
			height = 1536;
			break;
		case PU_RESOLUTION_WVGA:
			width = 854;
			height = 480;
			break;
		case PU_RESOLUTION_WSXGA:
			width = 1680;
			height = 1050;
			break;
		case PU_RESOLUTION_WUXGA:
			width = 1920;
			height = 1200;
			break;
		case PU_RESOLUTION_WQXGA:
			width = 2560;
			height = 1600;
			break;
		case PU_RESOLUTION_HD720:
			width = 1280;
			height = 720;
			break;
		case PU_RESOLUTION_HD1080:
			width = 1920;
			height = 1080;
			break;
	}
}

//int main(){
//	PU_DISCOVER_DEVICE_LIST_S stDeviceList = {0};
//
//	IVS_PU_Init(PU_BOTHLOGIN_MODE,NULL,6060);
//
//	IVS_PU_DiscoveryLocalDeviceList(&stDeviceList);
//	cout<<stDeviceList.stDeviceInfo[0].szDeviceIp<<endl;
//	system("pause");
//	return 0;
//}