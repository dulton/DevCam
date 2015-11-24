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
@function: yuv420转jpg

@param1: 输入的一帧yuv420的缓冲区
@param2: 帧宽度
@param3: 帧高度
@param4: jpg质量
@param5: 步长
@param6: 转换得到的jpg的缓冲区，需外面开辟空间
@param7: 压缩后的jpg大小

@return: 转换成功返回0，失败返回1 
**/
YUV2JPG_API int YUV2JPG(PBYTE in_YUV, int width, int height, int quality, int nStride, PBYTE out_JPG, DWORD *pnOutSize);

#endif