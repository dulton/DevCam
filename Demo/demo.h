#include <Windows.h>

int stop;//�����߳��˳�

typedef struct tagWindow{
	HWND hwnd;
	BOOL isFull;
}MyWindow;

static MyWindow myWindow[10];

LRESULT CALLBACK MainWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK ChildWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

int InitShowWindows();

int ReadFromBuffer(char* video_data,int size,int Video_Width,int Video_Height,HWND hwnd);

int IPC();//��������ͷ����ʾ��
int NVR();//����Ӳ��¼�������ʾ��

DWORD WINAPI IPCCapture(LPVOID lpParam);//��������ͷץ֡�߳�
DWORD WINAPI NVRCapture(LPVOID lpParam);//����Ӳ��¼���ץ֡�߳�