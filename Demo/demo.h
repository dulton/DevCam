#include <Windows.h>

int stop;//控制线程退出

typedef struct tagWindow{
	HWND hwnd;
	BOOL isFull;
}MyWindow;

static MyWindow myWindow[10];

LRESULT CALLBACK MainWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK ChildWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

int InitShowWindows();

int ReadFromBuffer(char* video_data,int size,int Video_Width,int Video_Height,HWND hwnd);

int IPC();//网络摄像头调用示例
int NVR();//网络硬盘录像机调用示例

DWORD WINAPI IPCCapture(LPVOID lpParam);//网络摄像头抓帧线程
DWORD WINAPI NVRCapture(LPVOID lpParam);//网络硬盘录像机抓帧线程