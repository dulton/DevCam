#ifndef _YUV2JPG_H_
#define _YUV2JPG_H_

#if defined( _WINDLL)
#define YUV2JPG_API  extern "C"__declspec(dllexport)
#else
#define YUV2JPG_API  extern "C" __declspec(dllimport)
#endif

#define CALLBACK __stdcall
#include <Windows.h>

/**
@function: yuv420תjpg

@param1: �����һ֡yuv420�Ļ�����
@param2: ֡���
@param3: ֡�߶�
@param4: jpg����
@param5: ����
@param6: ת���õ���jpg�Ļ������������濪�ٿռ�
@param7: ѹ�����jpg��С

@return: ת���ɹ�����0��ʧ�ܷ���1 
**/
YUV2JPG_API int YUV2JPG(PBYTE in_YUV, int width, int height, int quality, int nStride, PBYTE out_JPG, DWORD *pnOutSize);

#endif