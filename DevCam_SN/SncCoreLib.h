//
//	SncCoreLib.h - definitions/declarations for using "Sony Network Camera Core Library".
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef _SNCCORELIB_H_
#define _SNCCORELIB_H_

#include "SncDefine.h"

SNC_HANDLE	__stdcall sncOpenCameraHandle		(  );
void		__stdcall sncCloseCameraHandle		( SNC_HANDLE Handle );
void		__stdcall sncCloseAllCameraHandle	( );

SNC_ERROR	__stdcall snccGetLibraryVersion		( unsigned int *pVersion );		

SNC_ERROR	__stdcall snccSetNetwork			( SNC_HANDLE Handle, const NETINFO *pNetInfo );
SNC_ERROR	__stdcall snccGetNetworkSetting		( SNC_HANDLE Handle, NETINFO *pNetInfo );
SNC_ERROR	__stdcall snccSetMemory				( SNC_HANDLE Handle, const CODECINFO *pCodec, unsigned int FrameRate );
SNC_ERROR	__stdcall snccGetMemorySetting		( SNC_HANDLE Handle, CODECINFO *pCodec, unsigned int *pFrameRate);

SNC_ERROR	__stdcall snccSetSSLInfo			( SNC_HANDLE Handle, const SSLINFO *pSSLInfo );
SNC_ERROR	__stdcall snccGetSSLInfoSetting		( SNC_HANDLE Handle, SSLINFO *pSSLInfo );
SNC_ERROR	__stdcall snccSetSSLMode			( SNC_HANDLE Handle, bool SSLMode );
SNC_ERROR	__stdcall snccGetSSLMode    		( SNC_HANDLE Handle, bool *pSSLMode );

SNC_ERROR   __stdcall snccGetLastRedirect       ( SNC_HANDLE Handle, unsigned int * code, char *pBuf1, unsigned int bufLen1, unsigned int *outLen1, char *pBuf2, unsigned int bufLen2, unsigned int *outLen2 );

// A helper function to ease the set of "IgnoreAuthErrorL" and "IgnoreAuthErrorH".
SNC_ERROR   __stdcall snccSSLAddIgnoreError     ( SSL_IGNORE_AUTH_ERROR * ignore, SSL_AUTH_ERROR err );

// Helper functions for IpAddress and MacAddress structure
SNC_ERROR   __stdcall snccIpAddress2String      ( const IpAddress * addr, char *pBuf, unsigned int bufLen, unsigned int *outLen );
SNC_ERROR   __stdcall snccMacAddress2String     ( const MacAddress * addr, char split, char *pBuf, unsigned int bufLen, unsigned int *outLen );

SNC_ERROR   __stdcall snccString2IpAddress      ( const char * raw, IpAddress *out );
SNC_ERROR   __stdcall snccString2MacAddress     ( const char * raw, MacAddress *out );

// Logger
SNC_ERROR   __stdcall snccSetLogLevel           ( SNC_LOG_LEVEL level );
SNC_ERROR   __stdcall snccSetLogFile            ( const char *pLogFileName );

SNC_ERROR	__stdcall snccCheckDest             ( SNC_HANDLE Handle, unsigned int TimeOut );

#endif // !_SNCCORELIB_H_
