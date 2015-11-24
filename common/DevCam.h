// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DEVCAM_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DEVCAM_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifndef __DEVCAM_H__
#define __DEVCAM_H__

#pragma once

#ifdef DEVCAM_EXPORTS
#define DEVCAM_API __declspec(dllexport)
#else
#define DEVCAM_API __declspec(dllimport)
#endif

#define _EXT_C extern "C"  
#define _EXT_C_DEVCAM_API _EXT_C DEVCAM_API 

//��������
typedef enum tagErrorType{
	NoError,					//û�д���
	InitError,					//��ʼ������
	UnInitError,			
	PlayError,					//���Ŵ���
	StopPlayError,			
	CaptureError				//ץͼ����
} ErrorType;

//�豸����������ͷ��NVR��
typedef struct tagCommonParam{
	unsigned char deviceType;			//�豸����
	char deviceName[32];				//�豸���ƣ�һ��������ͷ���ڵص�
	char deviceIP[32];					//�豸IP
	char userName[128];					//�û���
	char passWord[128];					//����
	int devicePort;						//�豸�˿ں�

	long loginID;						//��¼�����û�IDֵ�����û�ID����Ψһ��
	char UVLoginID[64];					//����ר�õ�¼IDֵ
	int totalChannels;					//NVRͨ������
	int *onlineCameras;					//���ߵ�����ͷ
	long channelNo;						//ͨ����
	long playPort;						//����ͨ���ţ�����ר��
	long playHandle;					//���ž��

	unsigned char *frameBuffer;			//�ص���ȡ��ͼ������
	long frameBufferSize;				//�ص���ȡ��ͼ�����ݴ�С
	int frameWidth;						//ͼ����
	int frameHeight;					//ͼ�񳤶�

	unsigned char *JPEGBuffer;			//ץ֡������ȡ��JPEGͼ������
	long JPEGSize;						//JPEGͼ�����ݴ�С

	ErrorType devError;					//��������

	HWND playHwnd;						//���Ŵ��ھ��

	SYSTEMTIME startTime;				//����¼��ʼʱ��
	SYSTEMTIME endTime;					//����¼�����ʱ��
	char videoPath[256];				//����¼���ļ�Ŀ¼

	struct tagCommonParam *cameraParam; //����NVR��������������ͷ
} CommonParam,*LPCommonParam;


/*
�ļ��������豸����̬��ͷ�ļ�
�ļ����ƣ�DevCam.h
ʹ��˵����Ӧ����������а������ļ�
���������⣺DevCam.Dll
ʹ��˵����
1����Ӧ�����Ŀ¼�´�������Ŀ¼������Ϊ��DevCamDrvs.
2����Ŀ¼�´��������豸������Ŀ¼������������豸�������纣��ϵ�������豸����Ϊ��
	HKNVR_Srv01(��ʾΪ��NVR������01)��HKDVR_Srv01(��ʾΪ��DVR������01)��HKIP_Camera01(��ʾΪ��IP����ͷ01)�ȡ�
3�����ö�̬��(DevCam.Dll)������豸���������򿽱�����ӦĿ¼��
4��Ӧ�ó�����ʹ�ø��豸ʱ���Ȳ�ѯDevCamDrvsĿ¼���豸��������Ѹ��豸��ӵ��豸���ؼ��б��á�
5��Ӧ�ó������豸����ѡ��Ҫ�������豸��
6����̬��ӿں����βε�ʵ�ֹ�����ο����豸�ṩ�̵�SDK
*/

/*----------------------------------
�������ܣ���ʼ���豸SDK��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK();


/*----------------------------------
�������ܣ�ж���豸SDK��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK();

/*----------------------------------
�������ܣ��豸��ʼ��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Init(CommonParam *commonParam);


/*----------------------------------
�������ܣ���ֹ�豸ʹ��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam);

/*----------------------------------
�������ܣ���ȡ�����ֱ���
���ò�����
���ز�����
����˵��������NVR�󣬻�ȡ��������ͷ�����ֱ���
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetSize(CommonParam *commonParam,long channel = 0);

/*----------------------------------
�������ܣ���ȡ�豸һ֡ͼ��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel = 0);


/*----------------------------------
�������ܣ���ȡ�豸����
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DriverName(CommonParam *commonParam);


/*----------------------------------
�������ܣ���ȡ�豸������
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DriverDesc(CommonParam *commonParam);


/*----------------------------------
�������ܣ������豸���ܲ���
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Config(CommonParam *commonParam);


/*----------------------------------
�������ܣ�����豸�б�
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetDevList(CommonParam *commonParam);


/*----------------------------------
�������ܣ���ʼ����ʵʱ��ý��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StartStreamPlay(CommonParam *commonParam,long channel = 0);


/*----------------------------------
�������ܣ�ֹͣ����ʵʱ��ý��
���ò�����
���ز�����
����˵����
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StopStreamPlay(CommonParam *commonParam,long channel = 0);

/*----------------------------------
�������ܣ�����¼��
���ò�����
���ز�����
����˵�������뱣��Ŀ¼commonParam->videoPath
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DownLoad(CommonParam *commonParam,long channel = 0);

#endif // __DEVCAM_H__