#include <iostream>
#include "demo.h"
#include <Gdiplus.h>
#include <OCIdl.h>
#include <olectl.h>
#include "include/SDL.h"
#include "include/SDL_image.h"
#include "../Common/DevCam.h"

#pragma comment(lib,"DevCam.lib")
#pragma comment(lib,"GdiPlus.lib")
#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2_image.lib")

#undef main

using namespace std;
using namespace Gdiplus;

int main(){
	InitShowWindows();

	IPC();//网络摄像头调用示例
	
	//NVR();//网络硬盘录像机调用示例

	return 0;
}

int IPC(){
	stop = 0;
	MSG msg;

	//初始化SDK
	CAM_InitSDK();

	//定义设备通用参数
	CommonParam cp = {0};
	strcpy(cp.deviceIP,"192.168.1.111");
	strcpy(cp.userName,"admin");
	strcpy(cp.passWord,"12345");
	cp.devicePort = 8000;
	cp.channelNo = 1;
	cp.playHwnd = myWindow[1].hwnd;

	CommonParam cp1 = {0};
	strcpy(cp1.deviceIP,"192.168.1.189");
	strcpy(cp1.userName,"admin");
	strcpy(cp1.passWord,"12345");
	cp1.devicePort = 8000;
	cp1.channelNo = 1;
	cp1.playHwnd = myWindow[2].hwnd;

	//初始化设备
	CAM_Init(&cp);
	CAM_Init(&cp1);

	//开始播放
	if(CAM_StartStreamPlay(&cp)){
		Sleep(1);
	}
	CAM_StartStreamPlay(&cp1);

	//开辟线程进行抓帧
	CreateThread(NULL,0,IPCCapture,&cp,NULL,NULL);

	//Windows消息循环
	while(GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//等待抓帧线程退出
	stop = 1;
	while(stop == 1){
		Sleep(1);
	}

	//结束播放
	CAM_StopStreamPlay(&cp);
	CAM_StopStreamPlay(&cp1);

	//释放设备资源
	CAM_UnInit(&cp);
	CAM_UnInit(&cp1);

	//释放SDK资源
	CAM_UnInitSDK();

	return 0;
}

int NVR(){
	stop = 0;
	MSG msg;

	//初始化SDK
	CAM_InitSDK();

	//定义设备通用参数
	CommonParam cp = {0};
	strcpy(cp.deviceIP,"192.168.1.2");
	strcpy(cp.userName,"admin");
	strcpy(cp.passWord,"admin");
	cp.devicePort = 37777;

	//初始化设备
	CAM_Init(&cp);

	//遍历所有摄像头，先获取码流分辨率在打开播放
	for(int i=0;i<cp.totalChannels;i++){
		if(cp.onlineCameras[i] == 1){						//判断设备是否在线，0断线，1在线
			cp.cameraParam[i].playHwnd = NULL;//myWindow[i+1].hwnd;//设置每路摄像头的播放窗口
			CAM_GetSize(&cp,i);								//获取码流分辨率
			CAM_StartStreamPlay(&cp,i);						//开始播放
		}
	}

	//开辟线程进行抓帧
	CreateThread(NULL,0,NVRCapture,&cp,NULL,NULL);

	////按时间段下载视频
	//strcpy(cp.videoPath,"C:\\");
	//GetLocalTime(&cp.cameraParam[0].startTime);
	//cp.cameraParam[0].startTime.wHour = 14;
	//cp.cameraParam[0].startTime.wMinute = 30;

	//GetLocalTime(&cp.cameraParam[0].endTime);
	//cp.cameraParam[0].endTime.wHour = 14;
	//cp.cameraParam[0].endTime.wMinute = 35;
	//CAM_DownLoad(&cp,0);

	//Windows消息循环
	while(GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//等待抓帧线程退出
	stop = 1;
	while(stop == 1){
		Sleep(1);
	}

	//结束播放
	for(int i=0;i<cp.totalChannels;i++){
		if(cp.onlineCameras[i] == 1){						//判断设备是否在线，0断线，1在线
			CAM_StopStreamPlay(&cp,i);
		}
	}

	//释放设备资源
	CAM_UnInit(&cp);

	//释放SDK资源
	CAM_UnInitSDK();

	return 0;
}

DWORD WINAPI IPCCapture(LPVOID lpParam){
	LPCommonParam lpCp = (LPCommonParam)lpParam;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindowFrom(myWindow[3].hwnd);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture *background = NULL;
	SDL_RWops *src = NULL;
	for(;;){
		if(stop == 1){
			stop =0;
			break;
		}
		//抓取一帧
		if(!CAM_CaptureFrame(lpCp)){
			continue;
		}
		src = SDL_RWFromMem(lpCp->JPEGBuffer,lpCp->JPEGSize);
		
		background = IMG_LoadTexture_RW(renderer,src,1);
		
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(background);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}

DWORD WINAPI NVRCapture(LPVOID lpParam){
	LPCommonParam lpCp = (LPCommonParam)lpParam;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindowFrom(myWindow[9].hwnd);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture *background = NULL;
	SDL_RWops *src = NULL; 
	for(;;){
		if(stop == 1){
			stop =0;
			break;
		}
		//抓取一帧
		if(!CAM_CaptureFrame(lpCp,1)){
			continue;
		}
		src = SDL_RWFromMem(lpCp->cameraParam[1].JPEGBuffer,lpCp->cameraParam[1].JPEGSize);

		background = IMG_LoadTexture_RW(renderer,src,1);

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(background);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}

LRESULT CALLBACK MainWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam){
	switch(message){
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}

LRESULT CALLBACK ChildWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam){
	RECT rect;
	switch(message){
		case WM_LBUTTONDBLCLK:
			GetClientRect(myWindow[0].hwnd,&rect);
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if((unsigned int)hwnd == (unsigned int)myWindow[i*3+j+1].hwnd){
						if(myWindow[i*3+j+1].isFull == 0){
							MoveWindow(hwnd,0,0,rect.right,rect.bottom,TRUE);
							myWindow[i*3+j+1].isFull = 1;
							for(int k=1;k<10;k++){
								if(k != (i*3+j+1)){
									ShowWindow(myWindow[k].hwnd,SW_HIDE);
								}
							}
							break;
						}else{
							MoveWindow(hwnd,j*rect.right/3,i*rect.bottom/3,rect.right/3,rect.bottom/3,TRUE);
							myWindow[i*3+j+1].isFull = 0;
							for(int k=1;k<10;k++){
								if(k != (i*3+j+1)){
									ShowWindow(myWindow[k].hwnd,SW_SHOW);
								}
							}
							break;
						}
					}
				}
			}
			break;
		default:
			return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}

int InitShowWindows(){
	for(int i=0;i<10;i++){
		myWindow[i].isFull = 0;
	}

	HMODULE hInstance = 0;
	hInstance = GetModuleHandle(NULL); 

	WNDCLASS mainWndClass;
	mainWndClass.style=CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;
	mainWndClass.lpfnWndProc=MainWndProc;
	mainWndClass.cbWndExtra=0;
	mainWndClass.cbClsExtra=0;
	mainWndClass.hInstance=hInstance;
	mainWndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	mainWndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	mainWndClass.hbrBackground=(HBRUSH) GetStockObject(GRAY_BRUSH);
	mainWndClass.lpszMenuName=NULL;
	mainWndClass.lpszClassName="MainWindow";

	RegisterClass(&mainWndClass);

	myWindow[0].hwnd = CreateWindow("MainWindow","视频监控",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT, NULL,NULL,hInstance,NULL);
	ShowWindow(myWindow[0].hwnd, SW_MAXIMIZE);
	UpdateWindow(myWindow[0].hwnd);

	WNDCLASS childWndClass;
	childWndClass.style=CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;
	childWndClass.lpfnWndProc=ChildWndProc;
	childWndClass.cbWndExtra=0;
	childWndClass.cbClsExtra=0;
	childWndClass.hInstance=hInstance;
	childWndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	childWndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	childWndClass.hbrBackground=(HBRUSH) GetStockObject(DKGRAY_BRUSH);
	childWndClass.lpszMenuName=NULL;
	childWndClass.lpszClassName="ChildWindow";

	RegisterClass(&childWndClass);

	RECT rect;
	GetClientRect(myWindow[0].hwnd,&rect);

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			myWindow[i*3+j+1].hwnd = CreateWindow("ChildWindow",NULL,WS_CHILD|WS_BORDER,j*rect.right/3,i*(rect.bottom)/3, rect.right/3,(rect.bottom)/3,myWindow[0].hwnd,NULL,hInstance,NULL);
			ShowWindow(myWindow[i*3+j+1].hwnd, SW_SHOW);
			UpdateWindow(myWindow[i*3+j+1].hwnd);
		}
	}

	return 0;
}

int ReadFromBuffer(char* video_data,int size,int Video_Width,int Video_Height,HWND hwnd){
	if(size<=16){
		return -1;
	}
	RECT rect;
	GetClientRect(hwnd,&rect);
	IPicture *pPic = NULL;
	IStream *pStm = NULL; 
	HANDLE h = GetProcessHeap();
	LPVOID pvData = NULL ;
	pvData = HeapAlloc(h,HEAP_ZERO_MEMORY,size);
	if(pvData == NULL){
		return -1;
	}
	memcpy(pvData,video_data,size);
	if(FAILED(CreateStreamOnHGlobal(pvData,TRUE,&pStm))){
		cout<<"ERROR1"<<endl;
		if(pStm != NULL){
			pStm->Release();
		}
		return -1;
	}

	//装入图形文件
	if(FAILED(OleLoadPicture(pStm,size,TRUE,IID_IPicture,(LPVOID*)&pPic))){//附:如果video_data这个数组包含的图像有错，则OleLoadPicture 容易产生读写内存错误
		cout<<"ERROR2"<<endl;
		HeapFree(h,HEAP_NO_SERIALIZE,pvData);
		if(pPic != NULL){
			pPic->Release();
		}
		pStm->Release();
		return -1;
	}

	OLE_XSIZE_HIMETRIC hmWidth;

	OLE_YSIZE_HIMETRIC hmHeight;

	pPic->get_Width(&hmWidth); //用接口方法获得图片的宽和高

	pPic->get_Height(&hmHeight);

	pPic->Render(GetDC(hwnd),0,0,rect.right,rect.bottom,0,hmHeight,hmWidth,-hmHeight,NULL); //在指定的DC上绘出图片

	HeapFree(h,HEAP_NO_SERIALIZE,pvData);
	pPic->Release();
	pStm->Release();

	return 0;
}