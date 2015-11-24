#ifndef INFSDKNET_H
#define INFSDKNET_H

#include "INFSDK_Config.h"
#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

//���ƣ�E_ENCODE_TYPE
//˵�����������Ͳ���
//ԭ�ͣ�
typedef enum tagEncodeType
{
	ENCODE_MPEG4 = 1, /**< MPEG4 ���� */
	ENCODE_H264, /**< H264 ���� */
	ENCODE_H264_Hi3510, /**< H264 3510 ���� */
	ENCODE_MJPEG, /**< MJPEG ���룬������ */
} E_ENCODE_TYPE;

//���ƣ�S_REALDATA_INFO
//˵����ʵʱ����������
//ԭ�ͣ�
typedef struct tagRealDataInfo
{
	unsigned long lChannel; /**< ͨ���ţ��� 0 ��ʼ */
	unsigned long lStreamMode; /**< �������ͣ�0-��������1-������ */
	E_ENCODE_TYPE eEncodeType; /**< �������� */
}S_REALDATA_INFO;

//���ƣ�E_REALDATA_TYPE
//˵�����ص�ʵʱ������������
//ԭ�ͣ�
typedef enum tagRealDataType
{
	REALDATA_HEAD, /**< ʵʱ����ͷ���� */
	REALDATA_VIDEO, /**< ʵʱ��Ƶ�����ݣ�����������������Ƶ�ֿ�����Ƶ�����ݣ� */
	REALDATA_AUDIO, /**< ʵʱ��Ƶ������ */
} E_REALDATA_TYPE;

typedef void (CALLBACK *CBRealData)(long lRealHandle,E_REALDATA_TYPE eDataType,unsigned char *pBuffer,unsigned long lBufSize,void *pUserData);

INFSDK_API bool STDCALL INFNET_Init();

INFSDK_API bool STDCALL INFNET_Cleanup();

INFSDK_API long STDCALL INFNET_Login(const char *sDevIP,const unsigned int nDevPort,const char *sUserName,const char *sPassword);

INFSDK_API bool STDCALL INFNET_Logout(long lLoginID);

INFSDK_API long STDCALL INFNET_StartRealData(long lLoginID,S_REALDATA_INFO *pRealDataInfo,CBRealData fRealData,void *pUserData = NULL);

INFSDK_API bool STDCALL INFNET_StopRealData(long lRealHandle);

INFSDK_API long STDCALL INFNET_GetLastError();

#ifdef __cplusplus
}
#endif

#endif