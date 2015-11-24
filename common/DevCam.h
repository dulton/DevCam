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

//错误类型
typedef enum tagErrorType{
	NoError,					//没有错误
	InitError,					//初始化错误
	UnInitError,			
	PlayError,					//播放错误
	StopPlayError,			
	CaptureError				//抓图错误
} ErrorType;

//设备参数（摄像头或NVR）
typedef struct tagCommonParam{
	unsigned char deviceType;			//设备类型
	char deviceName[32];				//设备名称，一般是摄像头所在地点
	char deviceIP[32];					//设备IP
	char userName[128];					//用户名
	char passWord[128];					//密码
	int devicePort;						//设备端口号

	long loginID;						//登录返回用户ID值，该用户ID具有唯一性
	char UVLoginID[64];					//宇视专用登录ID值
	int totalChannels;					//NVR通道总数
	int *onlineCameras;					//在线的摄像头
	long channelNo;						//通道号
	long playPort;						//播放通道号，海康专用
	long playHandle;					//播放句柄

	unsigned char *frameBuffer;			//回调获取的图像数据
	long frameBufferSize;				//回调获取的图像数据大小
	int frameWidth;						//图像宽度
	int frameHeight;					//图像长度

	unsigned char *JPEGBuffer;			//抓帧函数获取的JPEG图像数据
	long JPEGSize;						//JPEG图像数据大小

	ErrorType devError;					//错误类型

	HWND playHwnd;						//播放窗口句柄

	SYSTEMTIME startTime;				//下载录像开始时间
	SYSTEMTIME endTime;					//下载录像结束时间
	char videoPath[256];				//下载录像文件目录

	struct tagCommonParam *cameraParam; //若是NVR，下连若干摄像头
} CommonParam,*LPCommonParam;


/*
文件描述：设备管理动态库头文件
文件名称：DevCam.h
使用说明：应用软件工程中包含该文件
运行依赖库：DevCam.Dll
使用说明：
1、在应用软件目录下创建二级目录，命名为：DevCamDrvs.
2、在目录下创建各种设备的三级目录，名称以相关设备命名，如海康系列摄像设备命名为：
	HKNVR_Srv01(表示为：NVR服务器01)、HKDVR_Srv01(表示为：DVR服务器01)、HKIP_Camera01(表示为：IP摄像头01)等。
3、将该动态库(DevCam.Dll)与相关设备的驱动程序拷贝到相应目录。
4、应用程序在使用该设备时，先查询DevCamDrvs目录下设备情况，并把各设备添加到设备树控件中备用。
5、应用程序在设备树中选择要操作的设备。
6、动态库接口函数形参的实现规则，请参考各设备提供商的SDK
*/

/*----------------------------------
函数功能：初始化设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_InitSDK();


/*----------------------------------
函数功能：卸载设备SDK库
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInitSDK();

/*----------------------------------
函数功能：设备初始化
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Init(CommonParam *commonParam);


/*----------------------------------
函数功能：终止设备使用
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_UnInit(CommonParam *commonParam);

/*----------------------------------
函数功能：获取码流分辨率
调用参数：
返回参数：
函数说明：连接NVR后，获取单个摄像头码流分辨率
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetSize(CommonParam *commonParam,long channel = 0);

/*----------------------------------
函数功能：获取设备一帧图像
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_CaptureFrame(CommonParam *commonParam,long channel = 0);


/*----------------------------------
函数功能：获取设备名称
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DriverName(CommonParam *commonParam);


/*----------------------------------
函数功能：获取设备描述符
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DriverDesc(CommonParam *commonParam);


/*----------------------------------
函数功能：配置设备功能参数
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_Config(CommonParam *commonParam);


/*----------------------------------
函数功能：获得设备列表
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_GetDevList(CommonParam *commonParam);


/*----------------------------------
函数功能：开始播放实时流媒体
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StartStreamPlay(CommonParam *commonParam,long channel = 0);


/*----------------------------------
函数功能：停止播放实时流媒体
调用参数：
返回参数：
函数说明：
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_StopStreamPlay(CommonParam *commonParam,long channel = 0);

/*----------------------------------
函数功能：下载录像
调用参数：
返回参数：
函数说明：传入保存目录commonParam->videoPath
-----------------------------------*/
_EXT_C_DEVCAM_API BOOL CAM_DownLoad(CommonParam *commonParam,long channel = 0);

#endif // __DEVCAM_H__