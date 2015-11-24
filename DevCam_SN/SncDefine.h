//
//	SncDefine.h - definitions for "Sony Network Camera SDK".
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef _SNCDEFINES_H_
#define _SNCDEFINES_H_

#include <ctime>    // for 'time_t'

#ifdef _MSC_VER
   typedef unsigned __int32 uint32_t;	// Define it from MSVC's internal type
#else
   #include <stdint.h>		            // Use the C99 official header
   #ifdef __stdcall
   #undef __stdcall
   #warning "Stdcall is previous defined, changed to pascal. Check if it is compiliance"
   #endif// __stdcall
   #define __stdcall __attribute__ ((stdcall))
#endif

namespace SNC
{

#define SNC_HANDLE	int
#define CAM_HANDLE	SNC_HANDLE

const int SNC_INVALID_HANDLE_VALUE = -1;
//////////////////////////////////////////////
// Codec
//////////////////////////////////////////////
enum AUDIOCODEC
{
	AUDIO_CODEC_UNKNOWN,
	AUDIO_CODEC_G711_64K,
	AUDIO_CODEC_G726_40K,
	AUDIO_CODEC_G726_32K,
	AUDIO_CODEC_G726_24K,
	AUDIO_CODEC_G726_16K,
	AUDIO_CODEC_AAC_48K_128K,
	AUDIO_CODEC_AAC_16K_64K,
};

enum VIDEOCODEC
{
	VIDEO_CODEC_UNKNOWN,
	VIDEO_CODEC_JPEG,
	VIDEO_CODEC_MPEG4,
	VIDEO_CODEC_H264,
};

struct CODECINFO
{
	VIDEOCODEC		VideoCodec;
	AUDIOCODEC		AudioCodec;
};

//////////////////////////////////////////////
// Instance
//////////////////////////////////////////////
enum VIDEO_INSTANCE
{
	VIDEO_INSTANCE_UNKNOWN,
	VIDEO_INSTANCE_1,
	VIDEO_INSTANCE_2,
	VIDEO_INSTANCE_3,
};

//////////////////////////////////////////////
// Network settings
//////////////////////////////////////////////

enum IPVERSIONINFO
{
    IPVERSION_UNKNOWN,
    IPVERSION_V4,
    IPVERSION_V6
};

struct NETINFO
{
	char			CamIpAddr[256];			// Camera address
    IPVERSIONINFO       CamIpVersion;           // IPv4 / IPv6, if "UNKNOWN" is set, it will be resolved if necessary
	unsigned short	CamPort;				// Camera port
	bool			ProxyFunc;				// HTTP Proxy setting	true:Use, false:Not use
	char			ProxyIpAddr[256];		// HTTP Proxy server address	(Available only manual setting)
    IPVERSIONINFO       ProxyIpVersion;         // IPv4 / IPv6
	unsigned short	ProxyPort;				// HTTP Proxy server port		(Available only manual setting)
	bool			AuthenticationFunc;		// Ahthentication setting	true:use false:not use
	char			User[17];				// User ID	(Available at using ahthenfunc. MAX:16 characters)
	char			Password[29];			// Password	(Available at using ahthenfunc. MAX:28 characters)
};

////////////////////////////////////////////////////////////////////////////////
// SSL
////////////////////////////////////////////////////////////////////////////////
enum SSL_AUTH_MODE
{
    SAM_NONE,                               // No authentication
    SAM_PEER                                // The server's certificate will be verified
};

enum SSL_CERT_STORE
{
    SCS_USE_SYSTEM,                         // Use of OS's installed certificates
    SCS_USE_CERT_FILE,                      // Use of certificate file (Set in SSLINFO structure)
    SCS_USE_BOTH                            // Use both of them
};

enum SSL_CERT_FILE_FORMAT
{
    SCFF_PEM,                               // Use of PEM format ceritificate file
    SCFF_PKCS12                             // Use of PKCS#12 format certificate file
};

struct ClientCertCallbackData
{
    char    FriendlyName[256];
    char    SubjectName[256];
    char    IssuerName[256];
    time_t  NotBefore;
    time_t  NotAfter;
};

// SSL authentication error
enum SSL_AUTH_ERROR
{
    SSL_AE_OK                                   = 0,
    SSL_AE_UNABLE_TO_GET_ISSUER_CERT            = 2,
    SSL_AE_UNABLE_TO_GET_CRL                    = 3,
    SSL_AE_UNABLE_TO_DECRYPT_CERT_SIGNATURE     = 4,
    SSL_AE_UNABLE_TO_DECRYPT_CRL_SIGNATURE      = 5,
    SSL_AE_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY   = 6,
    SSL_AE_CERT_SIGNATURE_FAILURE               = 7,
    SSL_AE_CRL_SIGNATURE_FAILURE                = 8,
    SSL_AE_CERT_NOT_YET_VALID                   = 9,
    SSL_AE_CERT_HAS_EXPIRED                     = 10,
    SSL_AE_CRL_NOT_YET_VALID                    = 11,
    SSL_AE_CRL_HAS_EXPIRED                      = 12,
    SSL_AE_ERROR_IN_CERT_NOT_BEFORE_FIELD       = 13,
    SSL_AE_ERROR_IN_CERT_NOT_AFTER_FIELD        = 14,
    SSL_AE_ERROR_IN_CRL_LAST_UPDATE_FIELD       = 15,
    SSL_AE_ERROR_IN_CRL_NEXT_UPDATE_FIELD       = 16,
    SSL_AE_DEPTH_ZERO_SELF_SIGNED_CERT          = 18,
    SSL_AE_SELF_SIGNED_CERT_IN_CHAIN            = 19,
    SSL_AE_UNABLE_TO_GET_ISSUER_CERT_LOCALLY    = 20,
    SSL_AE_UNABLE_TO_VERIFY_LEAF_SIGNATURE      = 21,
    SSL_AE_CERT_CHAIN_TOO_LONG                  = 22,
    SSL_AE_CERT_REVOKED                         = 23,
    SSL_AE_INVALID_CA                           = 24,
    SSL_AE_PATH_LENGTH_EXCEEDED                 = 25,
    SSL_AE_INVALID_PURPOSE                      = 26,
    SSL_AE_CERT_UNTRUSTED                       = 27,
    SSL_AE_CERT_REJECTED                        = 28,
    SSL_AE_SUBJECT_ISSUER_MISMATCH              = 29,
    SSL_AE_AKID_SKID_MISMATCH                   = 30,
    SSL_AE_AKID_ISSUER_SERIAL_MISMATCH          = 31,
    SSL_AE_KEYUSAGE_NO_CERTSIGN                 = 32,
    SSL_AE_UNABLE_TO_GET_CRL_ISSUER             = 33,
    SSL_AE_UNHANDLED_CRITICAL_EXTENSION         = 34,
    SSL_AE_KEYUSAGE_NO_CRL_SIGN                 = 35,
    SSL_AE_UNHANDLED_CRITICAL_CRL_EXTENSION     = 36,
    SSL_AE_INVALID_NON_CA                       = 37,
    SSL_AE_PROXY_PATH_LENGTH_EXCEEDED           = 38,
    SSL_AE_KEYUSAGE_NO_DIGITAL_SIGNATURE        = 39,
    SSL_AE_PROXY_CERTIFICATES_NOT_ALLOWED       = 40,
    SSL_AE_INVALID_EXTENSION                    = 41,
    SSL_AE_INVALID_POLICY_EXTENSION             = 42,
    SSL_AE_NO_EXPLICIT_POLICY                   = 43,
    SSL_AE_UNNESTED_RESOURCE                    = 44,
    SSL_AE_CN_NO_MATCH                          = 62,
    SSL_AE_OTHERS                               = 63
};

// Callback function for authentication error process.
// return 'true' to ignore this error; return 'false' to cancel the connection.
// 'subject_name' is the subject name of the related certificate.
// 'depth' is the depth of the certificate in the verification path.
// 'param' is the user-data 'AuthCallbackParam' set in SSLINFO
typedef bool (__stdcall *SSL_AUTH_CALLBACK)( SSL_AUTH_ERROR err, const char * subject_name, int depth, void * param );

// Callback function for select Client Certificate to use
// Return index to select cetificate. ( 0 <= index < array_size )
// Return '-1' to cancel.
// 'param' is the user-data 'AuthCallbackParam' set in SSLINFO
typedef int (__stdcall *CLIENT_CERT_CALLBACK)( const ClientCertCallbackData * data_array, int array_size, void * param );

struct SSL_IGNORE_AUTH_ERROR
{
    unsigned long           MaskBitsL;              // A bit-mask to define the errors to be ignored (Low parts:   0~31 bit)
                                                    //   "SSL_AE_UNABLE_TO_GET_ISSUER_CERT" ~ "SSL_AE_AKID_ISSUER_SERIAL_MISMATCH"
    unsigned long           MaskBitsH;              // A bit-mask to define the errors to be ignored (High parts: 32~63 bit)
                                                    //   "SSL_AE_KEYUSAGE_NO_CERTSIGN" ~ "SSL_AE_OTHERS"
};

// Server authentication profile
struct SSL_SERVER_AUTH
{
    SSL_AUTH_MODE           AuthMode;               // Authentication mode
    SSL_IGNORE_AUTH_ERROR   IgnoreAuthError;        // Ingore authentication errors
    SSL_AUTH_CALLBACK       AuthCallback;           // A callback function to deal with error. 'null' to cancel on any error.
    void *                  AuthCallbackParam;      // "user-data" for authentication callback
    SSL_CERT_STORE          RootCertStore;          // Store of "Trusted Root Certificates"
    char                    RootCertChainFile[256]; // PEM file of "Trusted Root Certificates"
};

// Client authentication profile
struct SSL_CLIENT_AUTH
{
    SSL_CERT_STORE          ClientCertStore;        // Store of "Client Certificates"
    SSL_CERT_FILE_FORMAT    ClientCertFileFormat;   // File format of "Client Certificate" file
    char                    ClientCertFile[256];    // PEM file of "Client Certificates"
    char                    ClientCertKeyFile[256]; // PEM private key file of "Client Certificates"
    char                    ClientCertPassword[256];// Password for the "Client Certificate"
    CLIENT_CERT_CALLBACK    ClientCertCallback;     // A callback function to select client certificate.
    void *                  ClientCertCallbackParam;// "user-data" for client cert callback
};

// SSLINFO
struct SSLINFO
{
    unsigned short          SSLPort;                // Port of SSL
    SSL_SERVER_AUTH         ServerAuthProfile;      // Profile for server authentication
    SSL_CLIENT_AUTH         ClientAuthProfile;      // Profile for client authentication
};

////////////////////////////////////////////////////////////////////////////////
// Common data type
////////////////////////////////////////////////////////////////////////////////

struct IpAddress
{
    IPVERSIONINFO       version;
    unsigned char   raw[16];
};

struct MacAddress
{
    unsigned char raw[6];
};

////////////////////////////////////////////////////////////////////////////////
// SNC_ERROR
////////////////////////////////////////////////////////////////////////////////
enum SNC_ERROR
{
	SNC_OK								= 0,
	SNC_ERR_PARAM						= 400,			// Parameter error
	SNC_ERR_ALLOC						= 401,			// Failed to allocate memory
	SNC_ERR_VERSION						= 402,			// Failed to get the version information
	SNC_ERR_SOCKET						= 403,			// Socket error
	SNC_ERR_NOT_INIT					= 404,			// Not initialized
	SNC_ERR_STATUS						= 405,			// Status error
	SNC_ERR_DECODE						= 406,			// Decode error
	SNC_ERR_INTERNAL					= 407,			// Internal error
	SNC_ERR_EOF							= 408,			// End of File (Connection close)
	SNC_ERR_TIMEOUT						= 409,			// Timeout
	SNC_ERR_LACK_OF_BUFSIZE				= 410,			// Buffer size lack
	SNC_ERR_NOT_ENOUGH_DATA				= 411,			// Not enough data
	SNC_ERR_BAD_STREAM_TYPE				= 412,			// Bad stream type
	SNC_ERR_BAD_CODEC_TYPE				= 413,			// Bad codec type
	SNC_ERR_BAD_VIDEO_CODEC_TYPE		= 414,			// Bad video codec type
	SNC_ERR_BAD_AUDIO_CODEC_TYPE		= 415,			// Bad audio codec type
	SNC_ERR_VIDEO_CODEC_TYPE_MISMATCH	= 416,			// Video codec type mismatch
	SNC_ERR_AUDIO_CODEC_TYPE_MISMATCH	= 417,			// Audio codec type mismatch
	SNC_ERR_RECEPTION_FAILURE			= 418,			// Reception failure
	SNC_ERR_HTTP_STATUS_CODE			= 419,			// Status code error
	SNC_ERR_UNEXPECTED_RESPONSE			= 420,			// Unexpected HTTP response
	SNC_ERR_CANNOT_OPEN_VIDEO_STREAM	= 421,			// Video stream can not open
	SNC_ERR_CANNOT_OPEN_AUDIO_STREAM	= 422,			// Audio stream can not open
	SNC_ERR_NOT_LOADED					= 423,			// Library load error
	SNC_ERR_HTTP_BAD_REQUEST			= 424,			// 400 Bad request
	SNC_ERR_HTTP_UNAUTHORIZED			= 425,			// 401 Unauthorized
	SNC_ERR_HTTP_SERVICE_UNAVAILABLE	= 426,			// 503 Service unavailable
	SNC_ERR_FTP_CONNECTION				= 427,			// Failed to FTP connetion
	SNC_ERR_CANNOT_CONNECT				= 428,			// Failed to HTTP connection
	SNC_ERR_DEVICE						= 429,			// Video/Audio device error
	SNC_ERR_ABOVE_STRM_LIMIT			= 430,			// Invalid stream number
	SNC_ERR_ABOVE_CAMERA_LIMIT			= 431,			// Over maximum camera number
	SNC_ERR_INVALID_HANDLE				= 432,			// Invalid camera handle
	SNC_ERR_FILE						= 433,			// File error
	SNC_ERR_VERSION_UP					= 434,			// Version up sequence error
	SNC_ERR_FTP_FUNC					= 435,			// Camera FTP function failure
	SNC_ERR_FTP_USER					= 436,			// Camera FTP function authentication failure
	SNC_ERR_FTP_MEMORY_SIZE				= 437,			// Memory shortage for Camera FTP function
	SNC_ERR_IMG_MEM_FUNC				= 438,			// Image memory function failure
	SNC_ERR_LEVEL4_USER					= 439,			// Level4 user failure
	SNC_ERR_LOST_CAMERA					= 440,			// Camera can not find in the period of version up sequence
	SNC_ERR_PROCESSING_YET				= 441,			// Executing Version up sequence
	SNC_ERR_VERSION_UP_MISMATCH			= 442,			// Inconsistent version-up information
	SNC_ERR_NOEFFECT					= 443,			// It has no effect calling or arguments
	SNC_ERR_DEVICE_NOT_SUPPORTED		= 444,			// Library does not support this device
	SNC_ERR_UNKNOWN_VALUE				= 445,			// Library does not support the value
	SNC_ERR_INVALID_ADAPTER				= 446,			// Invalid adapter IP address specified
	SNC_ERR_SETTING_FAILURE				= 447,			// The request partially failed
	SNC_ERR_BUSY                        = 448,          // The request can not be processed at this moment
    SNC_ERR_OPERATION_NOT_SUPPORTED     = 449,          // The operation is not supported on this device (CGI Wrapper)
    SNC_ERR_UNSUPPORTED_TYPE            = 450,          // The type is not supported for this parameter (CGI Wrapper)
    SNC_ERR_ID_OUT_OF_RANGE             = 451,          // The ID is out-of-range for this parameter (CGI Wrapper)
    SNC_ERR_SSL_HANDSHAKE               = 452,          // Failed to establish an SSL connection
    SNC_ERR_SSL_LOAD_CERT               = 453,          // Failed to load client cerfiticate, password error
    SNC_ERR_SVU_FILE_VERSION            = 454,          // SVU file does not compatible with current version VersionUpLib
    SNC_ERR_HTTP_REDIRECT               = 455           // HTTP redirect
};

// Logger Level
enum SNC_LOG_LEVEL
{
    SNC_LOG_LEVEL_NONE      = 0,
    SNC_LOG_LEVEL_INFO      = 1,
    SNC_LOG_LEVEL_DBG       = 2
};

} // namespace SNC

using namespace SNC;

#endif // _SNCDEFINES_H_
