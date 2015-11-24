//
//	SncCGIWrapperLib.h - definitions/declarations for using "Sony Network Camera CGI Wrapper Library".
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef _SNCCGIWRAPPERLIB_H_
#define _SNCCGIWRAPPERLIB_H_

#include "SncCGIWrapperLibDefine.h"

// library / initialize / close

SNC_ERROR   __stdcall   sncwGetLibraryVersion                   ( unsigned int *pVersion );

SNC_ERROR   __stdcall   sncwOpenCamera                          ( SNC_HANDLE Handle );
SNC_ERROR   __stdcall   sncwOpenCameraTimeout                   ( SNC_HANDLE Handle, unsigned int timeout );
SNC_ERROR   __stdcall   sncwOpenCameraVirtual                   ( SNC_HANDLE Handle, const char *model_name, const char *version, const char *optional );

SNC_ERROR   __stdcall   sncwCloseCamera                         ( SNC_HANDLE Handle );

// library control (cache, bundle)

SNC_ERROR   __stdcall   sncwCtrlGetCacheMode                    ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwCtrlSetCacheMode                    ( SNC_HANDLE Handle, bool in );
SNC_ERROR   __stdcall   sncwCtrlGetCacheDiscardOnSetMode        ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwCtrlSetCacheDiscardOnSetMode        ( SNC_HANDLE Handle, bool in );
SNC_ERROR   __stdcall   sncwCtrlGetCacheExpire                  ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwCtrlSetCacheExpire                  ( SNC_HANDLE Handle, unsigned int in );
SNC_ERROR   __stdcall   sncwCtrlDiscardCache                    ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwCtrlGetBundleMode                   ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwCtrlSetBundleMode                   ( SNC_HANDLE Handle, bool in );
SNC_ERROR   __stdcall   sncwCtrlBundleStart                     ( SNC_HANDLE Handle );
SNC_ERROR   __stdcall   sncwCtrlBundleCommit                    ( SNC_HANDLE Handle );
SNC_ERROR   __stdcall   sncwCtrlBundleCancel                    ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwCtrlGetCommandTimeout               ( SNC_HANDLE Handle, COMMAND_TIMEOUT_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwCtrlSetCommandTimeout               ( SNC_HANDLE Handle, COMMAND_TIMEOUT_TYPE type, unsigned int in );

SNC_ERROR   __stdcall   sncwCtrlGetReuseConnectionMode          ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwCtrlSetReuseConnectionMode          ( SNC_HANDLE Handle, bool in );

// camera general information 
SNC_ERROR   __stdcall   sncwIdRangeAlarm                        ( SNC_HANDLE Handle, RangeUint *out );

SNC_ERROR   __stdcall   sncwGetAlarmDataAvailable				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmDataAvailable				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsAlarmDuration                ( SNC_HANDLE Handle, unsigned int id_Alarm, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAlarmDuration                    ( SNC_HANDLE Handle, unsigned int id_Alarm, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAlarmDuration                    ( SNC_HANDLE Handle, unsigned int id_Alarm, unsigned int in );

SNC_ERROR   __stdcall   sncwSupportTypesAlarmOutput             ( SNC_HANDLE Handle, unsigned long *out );

SNC_ERROR   __stdcall   sncwGetAllConfigurationPresetFunction   ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetASlotAvailable					( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetAudioInAvailable					( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetAudioOutAvailable				( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetAudioUploadAvailable             ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetBoundlessRotationAvailable       ( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwOptionsCameraControlInterface		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetCameraControlInterface			( SNC_HANDLE Handle, CAMERA_CONTROL_INTERFACE *out);
SNC_ERROR   __stdcall   sncwSetCameraControlInterface			( SNC_HANDLE Handle, CAMERA_CONTROL_INTERFACE in);

SNC_ERROR   __stdcall   sncwGetCGIVersion                       ( SNC_HANDLE Handle, char *pBuf, int bufLen, int * outLen );

SNC_ERROR	__stdcall	sncwGetChannelId						( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetCommandAuthentication            ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetCommandAuthentication            ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetCustomHomepageAvailable          ( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwOptionsDateFormat					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetDateFormat						( SNC_HANDLE Handle, DATE_FORMAT *out );
SNC_ERROR   __stdcall	sncwSetDateFormat						( SNC_HANDLE Handle, DATE_FORMAT in );

SNC_ERROR   __stdcall   sncwGetDaylightSavingTimeMode           ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetDaylightSavingTimeMode           ( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsDefaultHomepageMode			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetDefaultHomepageMode				( SNC_HANDLE Handle, DEFAULT_HOMEPAGE_MODE *out );
SNC_ERROR   __stdcall	sncwSetDefaultHomepageMode				( SNC_HANDLE Handle, DEFAULT_HOMEPAGE_MODE in );

SNC_ERROR   __stdcall   sncwGetEdgeStorageFunctionSupported		( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall	sncwGetElectricalDayNightAvailable      ( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwSupportTypesEmailAddress			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetEmailAddress						( SNC_HANDLE Handle, EMAIL_ADDRESS_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetEmailAddress						( SNC_HANDLE Handle, EMAIL_ADDRESS_TYPE type, const char *pBuf );

SNC_ERROR   __stdcall   sncwSupportTypesEvent					( SNC_HANDLE Handle, unsigned long *out );

SNC_ERROR   __stdcall   sncwGetExclusiveControl                 ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetExclusiveControl                 ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsExclusiveControlQueueSize    ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetExclusiveControlQueueSize        ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetExclusiveControlQueueSize        ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetExclusiveControlTime             ( SNC_HANDLE Handle, int *wait_time, int *control_time );

SNC_ERROR   __stdcall   sncwOptionsExclusiveControlTimeSlice    ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetExclusiveControlTimeSlice        ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetExclusiveControlTimeSlice        ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetFocusAvailable                   ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetFtpServerAvailable  				( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwSupportTypesInterval				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwOptionsInterval						( SNC_HANDLE Handle, INTERVAL_TYPE type, RangeUint *out );
SNC_ERROR	__stdcall	sncwGetInterval							( SNC_HANDLE Handle, INTERVAL_TYPE type, unsigned int *out );
SNC_ERROR	__stdcall	sncwSetInterval							( SNC_HANDLE Handle, INTERVAL_TYPE type, unsigned int in );

SNC_ERROR   __stdcall   sncwGetIpocFunction        				( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwSupportTypesLedStatus               ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetLedStatus                        ( SNC_HANDLE Handle, LED_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetLedStatus                        ( SNC_HANDLE Handle, LED_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetLetterBoxAvailable               ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwOptionsMaxSession    				( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetMaxSession        				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetMaxSession        				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsMaxSessionAlarmBuffer		( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetMaxSessionAlarmBuffer        	( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetMaxSessionAlarmBuffer        	( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetMemoryFromDriver                 ( SNC_HANDLE Handle,DRIVER_TYPE  type,  MEMORY_TYPE *out );

SNC_ERROR   __stdcall   sncwGetModelForm						( SNC_HANDLE Handle, MODEL_FORM *out );

SNC_ERROR   __stdcall   sncwGetModelName                        ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall   sncwGetMovePanTiltZoomExAvailable       ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetMovePanTiltZoomExInterval        ( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetNtpClientFunction                ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetNtpClientFunction                ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsNtpInterval                  ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetNtpInterval                      ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetNtpInterval                      ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetNtpServer                        ( SNC_HANDLE Handle, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetNtpServer                        ( SNC_HANDLE Handle, const char *in );

SNC_ERROR   __stdcall   sncwOptionsNtpServerAddressMode			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetNtpServerAddressMode				( SNC_HANDLE Handle, NTP_SERVER_ADDRESS_MODE *out );
SNC_ERROR   __stdcall   sncwSetNtpServerAddressMode				( SNC_HANDLE Handle, NTP_SERVER_ADDRESS_MODE in );

SNC_ERROR   __stdcall   sncwIdRangeNtpServerEx					( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetNtpServerEx                      ( SNC_HANDLE Handle, unsigned int id_NtpServer, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetNtpServerEx                      ( SNC_HANDLE Handle, unsigned int id_NtpServer, const char *in );

SNC_ERROR	__stdcall	sncwGetOneShotImage						( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall   sncwGetPanoramaAvailable                ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetPanoramaPictureExist             ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetPanoramaRotation                 ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetPanoramaRotation                 ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetPanoramaRotationAvailable		( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetPanTiltAvailable                 ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetPassword							( SNC_HANDLE Handle, USER_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetPassword							( SNC_HANDLE Handle, USER_TYPE type, const char *in );

SNC_ERROR   __stdcall   sncwGetPowerControl						( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetPowerControl						( SNC_HANDLE Handle, bool out );

SNC_ERROR   __stdcall   sncwGetPresenceSensorFunction			( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetPresetPositionAvailable			( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetPrivacyMaskingAvailable			( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetRoundPanoramaFunction        	( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwGetRoundPanoramaPicture        		( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwIdRangeSensor                       ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwIdRangeSensorEx				        ( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetSensorMode                       ( SNC_HANDLE Handle, unsigned int id_Sensor, bool *out );
SNC_ERROR   __stdcall   sncwSetSensorMode                       ( SNC_HANDLE Handle, unsigned int id_Sensor, bool in );

SNC_ERROR   __stdcall   sncwGetSerial                           ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall   sncwGetSolidPanTiltZoomAvailable        ( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetSrcFrameRateAvailable			( SNC_HANDLE Handle, bool *out);

SNC_ERROR   __stdcall   sncwGetSuperimposeAvailable             ( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwOptionsSuperimposeAzimuthMode		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSuperimposeAzimuthMode			( SNC_HANDLE Handle, SUPERIMPOSE_AZIMUTH_MODE *out );
SNC_ERROR   __stdcall   sncwSetSuperimposeAzimuthMode           ( SNC_HANDLE Handle, SUPERIMPOSE_AZIMUTH_MODE in );

SNC_ERROR   __stdcall   sncwOptionsSuperimposeColorPattern      ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSuperimposeColorPattern          ( SNC_HANDLE Handle, SUPERIMPOSE_COLOR_PATTERN *out );
SNC_ERROR   __stdcall   sncwSetSuperimposeColorPattern          ( SNC_HANDLE Handle, SUPERIMPOSE_COLOR_PATTERN in );

SNC_ERROR   __stdcall   sncwGetSuperimposeColorType             ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id, SuperimposeColorType *out );
SNC_ERROR   __stdcall   sncwSetSuperimposeColorType             ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id, const SuperimposeColorType & in );

SNC_ERROR	__stdcall	sncwOptionsSuperimposeDateFormat		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetSuperimposeDateFormat			( SNC_HANDLE Handle, DATE_FORMAT *out );
SNC_ERROR   __stdcall	sncwSetSuperimposeDateFormat			( SNC_HANDLE Handle, DATE_FORMAT in );

SNC_ERROR	__stdcall	sncwOptionsSuperimposeDateSeparator		( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetSuperimposeDateSeparator			( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetSuperimposeDateSeparator			( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsSuperimposeDirectionMode		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetSuperimposeDirectionMode			( SNC_HANDLE Handle, SUPERIMPOSE_DIRECTION_MODE *out );
SNC_ERROR   __stdcall	sncwSetSuperimposeDirectionMode			( SNC_HANDLE Handle, SUPERIMPOSE_DIRECTION_MODE in );

SNC_ERROR   __stdcall	sncwGetSuperimposeEnable				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetSuperimposeEnable				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall	sncwGetSuperimposeEnableEx				( SNC_HANDLE Handle, unsigned int id_Streaming,  bool *out  );
SNC_ERROR   __stdcall	sncwSetSuperimposeEnableEx				( SNC_HANDLE Handle, unsigned int id_Streaming,  bool in );

SNC_ERROR	__stdcall	sncwOptionsSuperimposeFontSize			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetSuperimposeFontSize				( SNC_HANDLE Handle, SUPERIMPOSE_FONT_SIZE *out );
SNC_ERROR	__stdcall	sncwSetSuperimposeFontSize				( SNC_HANDLE Handle, SUPERIMPOSE_FONT_SIZE in );

SNC_ERROR	__stdcall	sncwOptionsSuperimposeFontSizeEx		( SNC_HANDLE Handle, unsigned int id_Streaming,unsigned long *out );
SNC_ERROR	__stdcall	sncwGetSuperimposeFontSizeEx			( SNC_HANDLE Handle, unsigned int id_Streaming, SUPERIMPOSE_FONT_SIZE *out );
SNC_ERROR	__stdcall	sncwSetSuperimposeFontSizeEx			( SNC_HANDLE Handle, unsigned int id_Streaming, SUPERIMPOSE_FONT_SIZE in );

SNC_ERROR   __stdcall	sncwGetSuperimposeFormat				( SNC_HANDLE Handle, unsigned int id, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall	sncwSetSuperimposeFormat				( SNC_HANDLE Handle, unsigned int id, const char *in );

SNC_ERROR   __stdcall	sncwGetSuperimposeFormatEx				( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall	sncwSetSuperimposeFormatEx				( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id, const char *in  );

SNC_ERROR   __stdcall	sncwGetSuperimposeFormatTag				( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );

SNC_ERROR	__stdcall	sncwSetSuperimposeLogoDelete			( SNC_HANDLE Handle );

SNC_ERROR   __stdcall	sncwGetSuperimposeLogoEnable			( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetSuperimposeLogoEnable			( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwGetSuperimposeMaxCount              ( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwOptionsSuperimposeMode              ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSuperimposeMode                  ( SNC_HANDLE Handle, SUPERIMPOSE_MODE *out );
SNC_ERROR   __stdcall   sncwSetSuperimposeMode                  ( SNC_HANDLE Handle, SUPERIMPOSE_MODE in );

SNC_ERROR   __stdcall   sncwGetSuperimposeMultiStreamingAvailable( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwOptionsSuperimposePosition          ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSuperimposePosition              ( SNC_HANDLE Handle, SUPERIMPOSE_POSITION *out );
SNC_ERROR   __stdcall   sncwSetSuperimposePosition              ( SNC_HANDLE Handle, SUPERIMPOSE_POSITION in );

SNC_ERROR   __stdcall   sncwIdRangeSuperimposePositionEx		( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwOptionsSuperimposePositionEx        ( SNC_HANDLE Handle, unsigned int id_SuperimposePosition, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSuperimposePositionEx            ( SNC_HANDLE Handle, unsigned int id_SuperimposePosition, SUPERIMPOSE_POSITION *out );
SNC_ERROR   __stdcall   sncwSetSuperimposePositionEx            ( SNC_HANDLE Handle, unsigned int id_SuperimposePosition, SUPERIMPOSE_POSITION in );

SNC_ERROR   __stdcall   sncwIdRangeSuperimposePositionEx2		( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwOptionsSuperimposePositionEx2       ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_SuperimposePosition, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSuperimposePositionEx2           ( SNC_HANDLE Handle, unsigned int id_Streaming , unsigned int id_SuperimposePosition, SUPERIMPOSE_POSITION *out);
SNC_ERROR   __stdcall   sncwSetSuperimposePositionEx2           ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_SuperimposePosition, SUPERIMPOSE_POSITION in );

SNC_ERROR   __stdcall   sncwGetSuperimposePositionEx3           ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_SuperimposePosition, PositionPercent *pos, TEXT_ALIGN_MODE *mode );
SNC_ERROR   __stdcall   sncwSetSuperimposePositionEx3           ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_SuperimposePosition, const PositionPercent & pos, TEXT_ALIGN_MODE mode );

SNC_ERROR   __stdcall	sncwGetSuperimposePresetPositionFunction( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetSuperimposePresetPositionFunction( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwSupportTypesSuperimposeTagStyle		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetSuperimposeTagStyle				( SNC_HANDLE Handle, SUPERIMPOSE_TAG_TYPE type, SuperimposeWordStyle *out );
SNC_ERROR	__stdcall	sncwSetSuperimposeTagStyle				( SNC_HANDLE Handle, SUPERIMPOSE_TAG_TYPE type, const SuperimposeWordStyle &in );

SNC_ERROR   __stdcall   sncwGetSuperimposeText                  ( SNC_HANDLE Handle, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetSuperimposeText                  ( SNC_HANDLE Handle, const char *in );

SNC_ERROR   __stdcall   sncwSetSystemReboot                     ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwOptionsTamperingLevel		        ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetTamperingLevel					( SNC_HANDLE Handle, TAMPERING_LEVEL *out );
SNC_ERROR   __stdcall   sncwSetTamperingLevel					( SNC_HANDLE Handle, TAMPERING_LEVEL in );

SNC_ERROR   __stdcall   sncwGetTamperingStatus					( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwSetTamperingStatusClear				( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwOptionsTimeZone                     ( SNC_HANDLE Handle, const char *const** names, int *count );
SNC_ERROR   __stdcall   sncwGetTimeZone                         ( SNC_HANDLE Handle, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetTimeZone                         ( SNC_HANDLE Handle, const char *in );

SNC_ERROR   __stdcall   sncwGetTourMultiStreamingAvailable      ( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwSupportTypesUserName				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetUserName							( SNC_HANDLE Handle, USER_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetUserName							( SNC_HANDLE Handle, USER_TYPE type, const char *in );

SNC_ERROR   __stdcall	sncwGetUserUrlPath						( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetUserUrlPath						( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR   __stdcall	sncwGetUserUrlPathRoot					( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall   sncwGetVersion                          ( SNC_HANDLE Handle, char *pBuf, int bufLen, int * outLen );

SNC_ERROR   __stdcall   sncwOptionsVideoOutputMode			    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetVideoOutputMode                  ( SNC_HANDLE Handle, VIDEO_OUTPUT_MODE_TYPE *out );
SNC_ERROR   __stdcall   sncwSetVideoOutputMode		            ( SNC_HANDLE Handle, VIDEO_OUTPUT_MODE_TYPE in );

SNC_ERROR   __stdcall   sncwGetWideDynamicRangeLevelAvailable	( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetZoomAvailable                    ( SNC_HANDLE Handle, bool *out );

// camera setting
SNC_ERROR   __stdcall   sncwOptionsAnalogVideoStandardMode      ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAnalogVideoStandardMode          ( SNC_HANDLE Handle, ANALOG_VIDEO_STANDARD_TYPE *out );
SNC_ERROR   __stdcall   sncwSetAnalogVideoStandardMode          ( SNC_HANDLE Handle, ANALOG_VIDEO_STANDARD_TYPE in );

SNC_ERROR   __stdcall   sncwGetAreaSet                          ( SNC_HANDLE Handle, RectRegion *out );
SNC_ERROR   __stdcall   sncwSetAreaSet                          ( SNC_HANDLE Handle, const RectRegion & in );

SNC_ERROR   __stdcall   sncwGetAreaSelectStatus                 ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetAreaSelectStatus                 ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetAreaSelectStatusEx               ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetAreaSelectStatusEx               ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsAspectRatioConversion        ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAspectRatioConversion            ( SNC_HANDLE Handle, ASPECT_RATIO_CONVERSION *out );
SNC_ERROR   __stdcall   sncwSetAspectRatioConversion            ( SNC_HANDLE Handle, ASPECT_RATIO_CONVERSION in );

SNC_ERROR   __stdcall	sncwGetAudioEchoSuppressor				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetAudioEchoSuppressor				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsAudioInCodec                 ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAudioInCodec                     ( SNC_HANDLE Handle, AUDIO_CODEC *out );
SNC_ERROR   __stdcall   sncwSetAudioInCodec                     ( SNC_HANDLE Handle, AUDIO_CODEC in );

SNC_ERROR   __stdcall   sncwOptionsAudioInSource			    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetAudioInSource					( SNC_HANDLE Handle, AUDIO_IN_SOURCE *out );
SNC_ERROR   __stdcall	sncwSetAudioInSource					( SNC_HANDLE Handle, AUDIO_IN_SOURCE in );

SNC_ERROR   __stdcall   sncwGetAudioInStatus                    ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetAudioInStatus                    ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsAudioInVolume                ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAudioInVolume                    ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAudioInVolume                    ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall	sncwGetAudioNoiseReduction				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetAudioNoiseReduction				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetAudioOutStatus                   ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetAudioOutStatus                   ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsAudioOutVolume               ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAudioOutVolume                   ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAudioOutVolume                   ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsAutoFlip			            ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetAutoFlip							( SNC_HANDLE Handle, AUTO_FLIP *out );
SNC_ERROR   __stdcall	sncwSetAutoFlip							( SNC_HANDLE Handle, AUTO_FLIP in );

SNC_ERROR   __stdcall	sncwGetAutoFlipMode						( SNC_HANDLE Handle, AUTO_FLIP_MODE *out );

SNC_ERROR   __stdcall   sncwOptionsMaxGain                      ( SNC_HANDLE Handle, const unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwGetAutoGainControlMaxGain           ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAutoGainControlMaxGain           ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsMaxGainLevel                 ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAutoGainControlMaxGainLevel      ( SNC_HANDLE Handle, MAX_GAIN_LEVEL *out );
SNC_ERROR   __stdcall   sncwSetAutoGainControlMaxGainLevel      ( SNC_HANDLE Handle, MAX_GAIN_LEVEL in );

SNC_ERROR   __stdcall   sncwGetAutoRateControl                  ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetAutoRateControl                  ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, bool in );

SNC_ERROR   __stdcall	sncwGetAutoRateControlEx				( SNC_HANDLE Handle, unsigned int id_Streaming, bool *out );
SNC_ERROR   __stdcall	sncwSetAutoRateControlEx				( SNC_HANDLE Handle, unsigned int id_Streaming, bool in );

SNC_ERROR   __stdcall   sncwGetAutoRateControlBitrateMin        ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAutoRateControlBitrateMin        ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );
SNC_ERROR   __stdcall   sncwOptionsAutoRateControlBitrateMin    ( SNC_HANDLE Handle, unsigned int id_Streaming, const unsigned int **out, int *count );

SNC_ERROR   __stdcall   sncwGetAutoRateControlBitrateMax        ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAutoRateControlBitrateMax        ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );
SNC_ERROR   __stdcall   sncwOptionsAutoRateControlBitrateMax    ( SNC_HANDLE Handle, unsigned int id_Streaming, const unsigned int **out, int *count );

SNC_ERROR   __stdcall   sncwOptionsAutoShutterMaxSpeed			( SNC_HANDLE Handle, const ShutterSpeedType **out, int *count );
SNC_ERROR   __stdcall   sncwGetAutoShutterMaxSpeed				( SNC_HANDLE Handle, ShutterSpeedType *out );
SNC_ERROR   __stdcall   sncwSetAutoShutterMaxSpeed				( SNC_HANDLE Handle, const ShutterSpeedType & in );

SNC_ERROR   __stdcall   sncwOptionsAutoShutterMinSpeed			( SNC_HANDLE Handle, const ShutterSpeedType **out, int *count );
SNC_ERROR   __stdcall   sncwGetAutoShutterMinSpeed				( SNC_HANDLE Handle, ShutterSpeedType *out );
SNC_ERROR   __stdcall   sncwSetAutoShutterMinSpeed				( SNC_HANDLE Handle, const ShutterSpeedType & in );

SNC_ERROR   __stdcall   sncwOptionsAutoSlowShutterMinSpeed      ( SNC_HANDLE Handle, const ShutterSpeedType **out, int *count );
SNC_ERROR   __stdcall   sncwGetAutoSlowShutterMinSpeed          ( SNC_HANDLE Handle, ShutterSpeedType *out );
SNC_ERROR   __stdcall   sncwSetAutoSlowShutterMinSpeed          ( SNC_HANDLE Handle, const ShutterSpeedType & in );

SNC_ERROR   __stdcall   sncwGetBandWidthEx						( SNC_HANDLE Handle, unsigned int id_Streaming, double *out );
SNC_ERROR   __stdcall   sncwSetBandWidthEx						( SNC_HANDLE Handle, unsigned int id_Streaming, double in );

SNC_ERROR   __stdcall   sncwOptionsBitRate                      ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetBitRate                          ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetBitRate                          ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsBitRateEx					( SNC_HANDLE Handle, unsigned int id_Streaming, const unsigned int **out, int *count );
SNC_ERROR   __stdcall	sncwGetBitRateEx						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetBitRateEx						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsBrightness	                ( SNC_HANDLE Handle, RangeInt *out );
SNC_ERROR   __stdcall   sncwGetBrightness                       ( SNC_HANDLE Handle, int *out );
SNC_ERROR   __stdcall   sncwSetBrightness                       ( SNC_HANDLE Handle, int in );

SNC_ERROR   __stdcall   sncwSupportTypesCameraId				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwOptionsCameraId						( SNC_HANDLE Handle, CAMERA_ID_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetCameraId							( SNC_HANDLE Handle, CAMERA_ID_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetCameraId							( SNC_HANDLE Handle, CAMERA_ID_TYPE type,  unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsCodecProfile					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetCodecProfile						( SNC_HANDLE Handle, unsigned int id_Streaming, PROFILE_TYPE *out );
SNC_ERROR   __stdcall	sncwSetCodecProfile						( SNC_HANDLE Handle, unsigned int id_Streaming, PROFILE_TYPE in );

SNC_ERROR   __stdcall   sncwOptionsColorMode				    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetColorMode                        ( SNC_HANDLE Handle, COLOR_MODE_TYPE *out );
SNC_ERROR   __stdcall   sncwSetColorMode                        ( SNC_HANDLE Handle, COLOR_MODE_TYPE in );

SNC_ERROR   __stdcall   sncwGetConstantBitRate                  ( SNC_HANDLE Handle, unsigned int id_Streaming, bool *out );
SNC_ERROR   __stdcall   sncwSetConstantBitRate                  ( SNC_HANDLE Handle, unsigned int id_Streaming, bool in );

SNC_ERROR   __stdcall   sncwOptionsContrast		                ( SNC_HANDLE Handle, RangeInt *out );
SNC_ERROR   __stdcall   sncwGetContrast                         ( SNC_HANDLE Handle, int *out );
SNC_ERROR   __stdcall   sncwSetContrast                         ( SNC_HANDLE Handle, int in );

SNC_ERROR   __stdcall	sncwGetDayNightCurrentStatus			( SNC_HANDLE Handle, bool *out );

SNC_ERROR   __stdcall   sncwGetDayNightManualFunction           ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetDayNightManualFunction           ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsDayNightMode                 ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetDayNightMode                     ( SNC_HANDLE Handle, DAY_NIGHT_MODE *out );
SNC_ERROR   __stdcall   sncwSetDayNightMode                     ( SNC_HANDLE Handle, DAY_NIGHT_MODE in );

SNC_ERROR   __stdcall   sncwGetDayNightSensorStatus             ( SNC_HANDLE Handle, unsigned int id_Sensor, bool *out );
SNC_ERROR   __stdcall   sncwSetDayNightSensorStatus             ( SNC_HANDLE Handle, unsigned int id_Sensor, bool in );

SNC_ERROR   __stdcall   sncwOptionsDayNightSensorTrigger        ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetDayNightSensorTrigger            ( SNC_HANDLE Handle, TRIGGER_TYPE *out );
SNC_ERROR   __stdcall   sncwSetDayNightSensorTrigger            ( SNC_HANDLE Handle, TRIGGER_TYPE in );

SNC_ERROR   __stdcall   sncwGetDayNightStatus                   ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetDayNightStatus                   ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetDayNightSyncEasyFocus            ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetDayNightSyncEasyFocus            ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsDayNightThresholdLevel       ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetDayNightThresholdLevel           ( SNC_HANDLE Handle, DAY_NIGHT_THRESHOLD_LEVEL *out );
SNC_ERROR   __stdcall   sncwSetDayNightThresholdLevel           ( SNC_HANDLE Handle, DAY_NIGHT_THRESHOLD_LEVEL in );

SNC_ERROR   __stdcall   sncwOptionsDayNightThresholdTime		( SNC_HANDLE Handle, const unsigned int **out, int *count  );
SNC_ERROR   __stdcall   sncwGetDayNightThresholdTime            ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetDayNightThresholdTime            ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetDayNightThresholdValue           ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetDayNightThresholdValue           ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetDayNightWeeklySchedule           ( SNC_HANDLE Handle, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetDayNightWeeklySchedule           ( SNC_HANDLE Handle, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwOptionsDynamicNoiseReduction	    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetDynamicNoiseReduction			( SNC_HANDLE Handle, DIGITAL_GAIN *out );
SNC_ERROR   __stdcall	sncwSetDynamicNoiseReduction			( SNC_HANDLE Handle, DIGITAL_GAIN in );

SNC_ERROR   __stdcall	sncwGetDynamicNoiseReductionStatus		( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetDynamicNoiseReductionStatus		( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetDynamicRangeCompressor           ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetDynamicRangeCompressor           ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall	sncwGetDynaViewFunction					( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetDynaViewFunction					( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetEffectiveArea                    ( SNC_HANDLE Handle, unsigned int id_Streaming, RectRegion *out );

SNC_ERROR   __stdcall   sncwGetExposureAutoGainControl          ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetExposureAutoGainControl          ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetExposureAutoShutter              ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetExposureAutoShutter              ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetExposureAutoSlowShutter          ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetExposureAutoSlowShutter          ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetExposureBackLightCompensation    ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetExposureBackLightCompensation    ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetExposureCompensationMode         ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetExposureCompensationMode         ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsExposureCompensationValue    ( SNC_HANDLE Handle, const double **out, int *count );
SNC_ERROR   __stdcall   sncwGetExposureCompensationValue        ( SNC_HANDLE Handle, double *out );
SNC_ERROR   __stdcall   sncwSetExposureCompensationValue        ( SNC_HANDLE Handle, double in );

SNC_ERROR   __stdcall   sncwOptionsExposureMode                 ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetExposureMode                     ( SNC_HANDLE Handle, EXPOSURE_MODE_TYPE *out );
SNC_ERROR   __stdcall   sncwSetExposureMode                     ( SNC_HANDLE Handle, EXPOSURE_MODE_TYPE in );

SNC_ERROR   __stdcall   sncwOptionsExposureShutterSpeed         ( SNC_HANDLE Handle, const ShutterSpeedType **out, int *count );
SNC_ERROR   __stdcall   sncwGetExposureShutterSpeed             ( SNC_HANDLE Handle, ShutterSpeedType *out );
SNC_ERROR   __stdcall   sncwSetExposureShutterSpeed             ( SNC_HANDLE Handle, const ShutterSpeedType & in );

SNC_ERROR   __stdcall   sncwOptionsFanMode					    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetFanMode                          ( SNC_HANDLE Handle, FAN_MODE *out );
SNC_ERROR   __stdcall   sncwSetFanMode                          ( SNC_HANDLE Handle, FAN_MODE in );

SNC_ERROR   __stdcall   sncwGetFlicklessMode                    ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetFlicklessMode                    ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsFocusMode				    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetFocusMode                        ( SNC_HANDLE Handle, FOCUS_MODE_TYPE *out );
SNC_ERROR   __stdcall   sncwSetFocusMode                        ( SNC_HANDLE Handle, FOCUS_MODE_TYPE in );

SNC_ERROR   __stdcall   sncwOptionsFrameRate                    ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, const unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwGetFrameRate                        ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetFrameRate                        ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsFrameRateEx					( SNC_HANDLE Handle, unsigned int id_Streaming, const unsigned int **out, int *count );
SNC_ERROR   __stdcall	sncwGetFrameRateEx						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetFrameRateEx						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsGain                         ( SNC_HANDLE Handle, const int **out, int *count );
SNC_ERROR   __stdcall   sncwGetGain                             ( SNC_HANDLE Handle, int *out );
SNC_ERROR   __stdcall   sncwSetGain                             ( SNC_HANDLE Handle, int in );

SNC_ERROR   __stdcall   sncwOptionsGamma		                ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetGamma                            ( SNC_HANDLE Handle, double *out );
SNC_ERROR   __stdcall   sncwSetGamma                            ( SNC_HANDLE Handle, double in );

SNC_ERROR	__stdcall	sncwOptionsGammaValue					( SNC_HANDLE Handle, const double **out, int *count );
SNC_ERROR   __stdcall	sncwGetGammaValue						( SNC_HANDLE Handle, double *out );
SNC_ERROR   __stdcall	sncwSetGammaValue						( SNC_HANDLE Handle, double in );

SNC_ERROR   __stdcall   sncwOptionsH264Quality					( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetH264Quality						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetH264Quality						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsHeaterMode				    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetHeaterMode                       ( SNC_HANDLE Handle, HEATER_MODE *out );
SNC_ERROR   __stdcall   sncwSetHeaterMode                       ( SNC_HANDLE Handle, HEATER_MODE in );

SNC_ERROR   __stdcall   sncwGetHighSensitivityMode              ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetHighSensitivityMode              ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetHoldAutoIrisOpen                 ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetHoldAutoIrisOpen                 ( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsIframeInterval				( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetIframeInterval                   ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetIframeInterval                   ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsIframeIntervalEx				( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetIframeIntervalEx		 			( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetIframeIntervalEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsIframeRatio					( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetIframeRatio			 			( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetIframeRatio						( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsIframeRatioEx				( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetIframeRatioEx		 			( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetIframeRatioEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsImageCodec                   ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetImageCodec                       ( SNC_HANDLE Handle, IMAGE_CODEC *out );
SNC_ERROR   __stdcall   sncwSetImageCodec                       ( SNC_HANDLE Handle, IMAGE_CODEC in );

SNC_ERROR   __stdcall   sncwIdRangeStreaming					( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR	__stdcall	sncwOptionsImageCodecEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetImageCodecEx						( SNC_HANDLE Handle, unsigned int id_Streaming, IMAGE_CODEC *out );
SNC_ERROR   __stdcall	sncwSetImageCodecEx						( SNC_HANDLE Handle, unsigned int id_Streaming, IMAGE_CODEC in );

SNC_ERROR   __stdcall   sncwGetImageFlip                        ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetImageFlip                        ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetImageFlipFunction                ( SNC_HANDLE Handle, bool *out );

SNC_ERROR	__stdcall	sncwGetImageMaxSize						( SNC_HANDLE Handle, ImageSizeType *out ); 

SNC_ERROR	__stdcall	sncwOptionsImageQualityEx				( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetImageQualityEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetImageQualityEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwSupportTypesImageCodecType          ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwOptionsImageSize                    ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, const ImageSizeType **out, int *count );
SNC_ERROR   __stdcall   sncwGetImageSize                        ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, ImageSizeType *out );
SNC_ERROR   __stdcall   sncwSetImageSize                        ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, const ImageSizeType & in );

SNC_ERROR   __stdcall   sncwOptionsImageSizeEx                  ( SNC_HANDLE Handle, unsigned int id_Streaming, const ImageSizeType **out, int *count );
SNC_ERROR   __stdcall	sncwGetImageSizeEx						( SNC_HANDLE Handle, unsigned int id_Streaming, ImageSizeType *out );
SNC_ERROR   __stdcall	sncwSetImageSizeEx						( SNC_HANDLE Handle, unsigned int id_Streaming, const ImageSizeType &in );

SNC_ERROR   __stdcall   sncwSetInsertIframe                     ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type );

SNC_ERROR   __stdcall	sncwSetInsertIFrameEx					( SNC_HANDLE Handle, unsigned int id_Streaming, bool in );

SNC_ERROR   __stdcall   sncwOptionsIrIlluminatorMaxStrength     ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetIrIlluminatorMaxStrength         ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetIrIlluminatorMaxStrength         ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetIrIlluminatorSyncDayNight        ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetIrIlluminatorSyncDayNight        ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsIris                         ( SNC_HANDLE Handle, const double **out, int *count );
SNC_ERROR   __stdcall   sncwGetIris                             ( SNC_HANDLE Handle, double *out );
SNC_ERROR   __stdcall   sncwSetIris                             ( SNC_HANDLE Handle, double in );

SNC_ERROR   __stdcall   sncwGetJpegBandWidth                    ( SNC_HANDLE Handle, double *out );
SNC_ERROR   __stdcall   sncwSetJpegBandWidth                    ( SNC_HANDLE Handle, double in );

SNC_ERROR   __stdcall   sncwOptionsJpegImageQuality             ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetJpegImageQuality                 ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetJpegImageQuality                 ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsJpegQuality					( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetJpegQuality						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetJpegQuality						( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsJpegTargetRatio              ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetJpegTargetRatio                  ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetJpegTargetRatio                  ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsLensAdjust    				( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetLensAdjust        				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetLensAdjust        				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsLightFunnelMode              ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetLightFunnelMode                  ( SNC_HANDLE Handle, LIGHT_FUNNEL_MODE *out );
SNC_ERROR   __stdcall   sncwSetLightFunnelMode                  ( SNC_HANDLE Handle, LIGHT_FUNNEL_MODE in );

SNC_ERROR   __stdcall   sncwGetLightFunnelStatus                ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetLightFunnelStatus                ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsLightFunnelThresholdLevel    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetLightFunnelThresholdLevel        ( SNC_HANDLE Handle, LIGHT_FUNNEL_THRESHOLD_LEVEL *out );
SNC_ERROR   __stdcall   sncwSetLightFunnelThresholdLevel        ( SNC_HANDLE Handle, LIGHT_FUNNEL_THRESHOLD_LEVEL in );

SNC_ERROR	__stdcall	sncwOptionsLightFunnelThresholdTime		( SNC_HANDLE Handle, const unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwGetLightFunnelThresholdTime         ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetLightFunnelThresholdTime         ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetLightFunnelWeeklySchedule        ( SNC_HANDLE Handle, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetLightFunnelWeeklySchedule        ( SNC_HANDLE Handle, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall	sncwGetLineLockFunction					( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetLineLockFunction					( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsLineLockViscaPhase			( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetLineLockViscaPhase				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetLineLockViscaPhase				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsMaxResolution                ( SNC_HANDLE Handle, const ImageSizeType **out, int *count );
SNC_ERROR   __stdcall   sncwGetMaxResolution	                ( SNC_HANDLE Handle, ImageSizeType *out );
SNC_ERROR   __stdcall   sncwSetMaxResolution	                ( SNC_HANDLE Handle, const ImageSizeType & in );

SNC_ERROR   __stdcall   sncwGetMultiCastAddress                 ( SNC_HANDLE Handle, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetMultiCastAddress                 ( SNC_HANDLE Handle, const IpAddress & in );

SNC_ERROR   __stdcall   sncwIdRangeMultiCastAddressEx           ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetMultiCastAddressEx               ( SNC_HANDLE Handle, unsigned int id_MultiCastAddr, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetMultiCastAddressEx               ( SNC_HANDLE Handle, unsigned int id_MultiCastAddr, const IpAddress & in );

SNC_ERROR   __stdcall   sncwGetMultiCastAudioAddress            ( SNC_HANDLE Handle, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetMultiCastAudioAddress            ( SNC_HANDLE Handle, const IpAddress & in );

SNC_ERROR   __stdcall   sncwGetMultiCastAudioAutoMode           ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetMultiCastAudioAutoMode           ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetMultiCastAudioPort               ( SNC_HANDLE Handle, unsigned short *out );
SNC_ERROR   __stdcall   sncwSetMultiCastAudioPort               ( SNC_HANDLE Handle, unsigned short in );

SNC_ERROR   __stdcall   sncwGetMultiCastStatus                  ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetMultiCastStatus                  ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsMultiCastTtl                 ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetMultiCastTtl                     ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetMultiCastTtl                     ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall	sncwGetMultiCastVideoAutoMode			( SNC_HANDLE Handle, unsigned int id_Streaming,  bool *out  );
SNC_ERROR   __stdcall	sncwSetMultiCastVideoAutoMode			( SNC_HANDLE Handle, unsigned int id_Streaming,  bool in );

SNC_ERROR   __stdcall   sncwGetMultiCastVideoPort               ( SNC_HANDLE Handle, unsigned short *out );
SNC_ERROR   __stdcall   sncwSetMultiCastVideoPort               ( SNC_HANDLE Handle, unsigned short in );

SNC_ERROR   __stdcall	sncwGetMultiExposure					( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetMultiExposure					( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetNearIrCompensation               ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetNearIrCompensation               ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsPtzfMode					    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetPtzfMode							( SNC_HANDLE Handle, PTZF_MODE *out );
SNC_ERROR   __stdcall	sncwSetPtzfMode							( SNC_HANDLE Handle, PTZF_MODE in );

SNC_ERROR	__stdcall	sncwOptionsRelativePanTiltMode			( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetRelativePanTiltMode				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetRelativePanTiltMode				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsRelativeZoomMode				( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetRelativeZoomMode					( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetRelativeZoomMode					( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsRtpExpiration                ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetRtpExpiration                    ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetRtpExpiration                    ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetRtspMultiCastAddress             ( SNC_HANDLE Handle, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetRtspMultiCastAddress             ( SNC_HANDLE Handle, const IpAddress & in );

SNC_ERROR	__stdcall	sncwOptionsRtspTimeout                  ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR	__stdcall	sncwGetRtspTimeout                      ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR	__stdcall	sncwSetRtspTimeout                      ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsSaturation	                ( SNC_HANDLE Handle, RangeInt *out );
SNC_ERROR   __stdcall   sncwGetSaturation                       ( SNC_HANDLE Handle, int *out );
SNC_ERROR   __stdcall   sncwSetSaturation                       ( SNC_HANDLE Handle, int in );

SNC_ERROR   __stdcall   sncwGetSensorNum                        ( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwOptionsSharpness	                ( SNC_HANDLE Handle, RangeInt *out );
SNC_ERROR   __stdcall   sncwGetSharpness                        ( SNC_HANDLE Handle, int *out );
SNC_ERROR   __stdcall   sncwSetSharpness                        ( SNC_HANDLE Handle, int in );

SNC_ERROR   __stdcall   sncwGetSolidPanTiltZoom                 ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSolidPanTiltZoom                 ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetSolidPanTiltZoomEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, bool *out );
SNC_ERROR   __stdcall   sncwSetSolidPanTiltZoomEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, bool in );

SNC_ERROR   __stdcall   sncwOptionsSolidPanTiltZoomMode         ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSolidPanTiltZoomMode             ( SNC_HANDLE Handle, SOLID_PAN_TILT_ZOOM_MODE *out );
SNC_ERROR   __stdcall   sncwSetSolidPanTiltZoomMode             ( SNC_HANDLE Handle, SOLID_PAN_TILT_ZOOM_MODE in );

SNC_ERROR   __stdcall   sncwOptionsSolidPanTiltZoomTiltDirection( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSolidPanTiltZoomTiltDirection    ( SNC_HANDLE Handle, TILT_DIRECTION *out );
SNC_ERROR   __stdcall   sncwSetSolidPanTiltZoomTiltDirection    ( SNC_HANDLE Handle, TILT_DIRECTION in );

SNC_ERROR   __stdcall   sncwOptionsSrcFramerate                 ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSrcFramerate                     ( SNC_HANDLE Handle, SRC_FRAME_RATE *out );
SNC_ERROR   __stdcall   sncwSetSrcFramerate                     ( SNC_HANDLE Handle, SRC_FRAME_RATE in );

SNC_ERROR   __stdcall   sncwGetStabilizeMode                    ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetStabilizeMode                    ( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsTargetRatioEx				( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetTargetRatioEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetTargetRatioEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwSetTitleAttribute                   ( SNC_HANDLE Handle, unsigned int x, unsigned int y, TITLE_COLOR c, bool b );

SNC_ERROR   __stdcall   sncwOptionsTitleDisplayMode             ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetTitleDisplayMode                 ( SNC_HANDLE Handle, TITLE_DISPLAY_MODE in );

SNC_ERROR   __stdcall   sncwSetTitleString                      ( SNC_HANDLE Handle, const char *in );

SNC_ERROR   __stdcall   sncwGetUniCastAudioPort                 ( SNC_HANDLE Handle, unsigned short *out );
SNC_ERROR   __stdcall   sncwSetUniCastAudioPort                 ( SNC_HANDLE Handle, unsigned short in );

SNC_ERROR   __stdcall   sncwGetUniCastVideoPort                 ( SNC_HANDLE Handle, unsigned short *out );
SNC_ERROR   __stdcall   sncwSetUniCastVideoPort                 ( SNC_HANDLE Handle, unsigned short in );

SNC_ERROR	__stdcall	sncwGetVideoPanTiltRefreshIntervalTime	( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR	__stdcall	sncwSetVideoPanTiltRefreshIntervalTime	( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwSetVideoPanTiltRefreshManual		( SNC_HANDLE Handle );

SNC_ERROR	__stdcall	sncwOptionsVideoPanTiltRefreshPeriodMode( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetVideoPanTiltRefreshPeriodMode    ( SNC_HANDLE Handle, PERIOD_MODE  *out  );
SNC_ERROR   __stdcall   sncwSetVideoPanTiltRefreshPeriodMode    ( SNC_HANDLE Handle, PERIOD_MODE  in  );

SNC_ERROR	__stdcall	sncwGetVideoPanTiltRefreshStatus		( SNC_HANDLE Handle, bool *out );
SNC_ERROR	__stdcall	sncwSetVideoPanTiltRefreshStatus		( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetVideoPanTiltRefreshWeeklySchedule( SNC_HANDLE Handle, WeeklyScheduleType *out  );
SNC_ERROR   __stdcall   sncwSetVideoPanTiltRefreshWeeklySchedule( SNC_HANDLE Handle, const WeeklyScheduleType &in  );

SNC_ERROR   __stdcall   sncwOptionsVisibilityEnhancer		    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetVisibilityEnhancer				( SNC_HANDLE Handle, DIGITAL_GAIN *out );
SNC_ERROR   __stdcall	sncwSetVisibilityEnhancer				( SNC_HANDLE Handle, DIGITAL_GAIN in );

SNC_ERROR   __stdcall   sncwGetWashedoutImageControl            ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetWashedoutImageControl            ( SNC_HANDLE Handle, bool out );

SNC_ERROR   __stdcall   sncwSetWhiteBalanceAutoDetect           ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwSupportTypesWhiteBalanceGain        ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwOptionsWhiteBalanceGain             ( SNC_HANDLE Handle, WHITE_BALANCE_GAIN_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetWhiteBalanceGain                 ( SNC_HANDLE Handle, WHITE_BALANCE_GAIN_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetWhiteBalanceGain                 ( SNC_HANDLE Handle, WHITE_BALANCE_GAIN_TYPE type, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsWhiteBalanceMode             ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWhiteBalanceMode                 ( SNC_HANDLE Handle, WHITE_BALANCE_MODE_TYPE *out );
SNC_ERROR   __stdcall   sncwSetWhiteBalanceMode                 ( SNC_HANDLE Handle, WHITE_BALANCE_MODE_TYPE in );

SNC_ERROR   __stdcall   sncwSupportTypesWhiteBalanceOffset		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwOptionsWhiteBalanceOffset			( SNC_HANDLE Handle, WHITE_BALANCE_GAIN_TYPE type, RangeInt *out );
SNC_ERROR   __stdcall   sncwGetWhiteBalanceOffset				( SNC_HANDLE Handle, WHITE_BALANCE_GAIN_TYPE type, int *out );
SNC_ERROR   __stdcall   sncwSetWhiteBalanceOffset               ( SNC_HANDLE Handle, WHITE_BALANCE_GAIN_TYPE type, int in );

SNC_ERROR   __stdcall   sncwGetWideDFunction		            ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetWideDFunction	                ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetWideDFunctionOffInNight          ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetWideDFunctionOffInNight          ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsWideDynamicRangeLevel        ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWideDynamicRangeLevel            ( SNC_HANDLE Handle, WIDE_DYNAMIC_RANGE_LEVEL *out );
SNC_ERROR   __stdcall   sncwSetWideDynamicRangeLevel            ( SNC_HANDLE Handle, WIDE_DYNAMIC_RANGE_LEVEL in );

SNC_ERROR   __stdcall   sncwGetWideDynamicRangeMode             ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetWideDynamicRangeMode             ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsZoomMode					    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetZoomMode                         ( SNC_HANDLE Handle, ZOOM_MODE_TYPE *out );
SNC_ERROR   __stdcall   sncwSetZoomMode                         ( SNC_HANDLE Handle, ZOOM_MODE_TYPE in );

SNC_ERROR   __stdcall   sncwGetDefogAvailable                   ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwGetDefog                            ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetDefog                            ( SNC_HANDLE Handle, bool in );

// Camera movement (Pan-Tilt-Zoom-Focus)
SNC_ERROR   __stdcall   sncwOptionsAnalogCameraPanSpeed	        ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetAnalogCameraPanSpeed				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetAnalogCameraPanSpeed				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsAnalogCameraTiltSpeed	    ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetAnalogCameraTiltSpeed			( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetAnalogCameraTiltSpeed			( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsAnalogCameraZoomSpeed	    ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetAnalogCameraZoomSpeed			( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetAnalogCameraZoomSpeed			( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsAnalogCameraFocusSpeed       ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetAnalogCameraFocusSpeed			( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetAnalogCameraFocusSpeed			( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwSetAreaZoom							( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, int x, int y, int width, int height );
SNC_ERROR	__stdcall	sncwSetAreaZoomEx						( SNC_HANDLE Handle, unsigned int id_Streaming, int x, int y, int width, int height );

SNC_ERROR   __stdcall   sncwSetEasyFocus			            ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwSetFocusZoomInitialize              ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwOptionsFocusZoomRelativeFocus       ( SNC_HANDLE Handle, RangeInt *out );
SNC_ERROR   __stdcall   sncwSetFocusZoomRelativeFocus			( SNC_HANDLE Handle, int in );

SNC_ERROR   __stdcall   sncwSetFocusZoomRelativeZoomFocus		( SNC_HANDLE Handle, int zoom, int focus );

SNC_ERROR   __stdcall   sncwGetHorizontalTiltLimitAvailable		( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetHorizontalTiltLimitAvailable		( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetMoveAbsolute                     ( SNC_HANDLE Handle, double *pan_position, double *tilt_position, double *zoom_position, double *focus_position );
SNC_ERROR   __stdcall   sncwSetMoveAbsolute                     ( SNC_HANDLE Handle, double pan_position, double tilt_position, double zoom_position, double focus_position );

SNC_ERROR   __stdcall   sncwGetMoveAbsoluteEx                   ( SNC_HANDLE Handle, unsigned int id_Streaming, double *pan_position, double *tilt_position, double *zoom_position, double *focus_position );
SNC_ERROR   __stdcall   sncwSetMoveAbsoluteEx                   ( SNC_HANDLE Handle, unsigned int id_Streaming, double pan_position, double tilt_position, double zoom_position, double focus_position );

SNC_ERROR   __stdcall   sncwSetMoveFocusAbsolute                ( SNC_HANDLE Handle, double focus_position, unsigned int speed );

SNC_ERROR   __stdcall   sncwSetMoveFocusStart                   ( SNC_HANDLE Handle, FOCUS_TYPE dir, unsigned int speed );
SNC_ERROR   __stdcall   sncwSetMoveFocusStartEx					( SNC_HANDLE Handle, unsigned int id_Streaming, FOCUS_TYPE dir, unsigned int speed );

SNC_ERROR   __stdcall   sncwSetMoveFocusRelative                ( SNC_HANDLE Handle, double focus_delta, unsigned int speed );

SNC_ERROR   __stdcall   sncwSetMovePanAbsolute					( SNC_HANDLE Handle, unsigned int id_Streaming, double pan_position, unsigned int speed );

SNC_ERROR   __stdcall   sncwGetMovePanoramaPanLimit             ( SNC_HANDLE Handle, double *pan_min, double *pan_max );
SNC_ERROR   __stdcall   sncwSetMovePanoramaPanLimit             ( SNC_HANDLE Handle, double pan_min, double pan_max );

SNC_ERROR   __stdcall   sncwGetMovePanoramaTiltLimit            ( SNC_HANDLE Handle, double *pan_min, double *pan_max );
SNC_ERROR   __stdcall   sncwSetMovePanoramaTiltLimit            ( SNC_HANDLE Handle, double pan_min, double pan_max );

SNC_ERROR   __stdcall   sncwSetMovePanTiltZoom                  ( SNC_HANDLE Handle, int pan_speed, int tilt_speed, int zoom_speed );
SNC_ERROR   __stdcall   sncwSetMovePanTiltZoomEx                ( SNC_HANDLE Handle, int pan_speed, int tilt_speed, int zoom_speed );
SNC_ERROR   __stdcall   sncwSetMovePanTiltZoomEx2				( SNC_HANDLE Handle, unsigned int id_Streaming, int pan_speed, int tilt_speed, int zoom_speed );

SNC_ERROR   __stdcall   sncwGetMovePanRange                     ( SNC_HANDLE Handle, double *pan_min, double *pan_max );

SNC_ERROR   __stdcall   sncwGetMovePanTiltAbsolute              ( SNC_HANDLE Handle, double *pan_position, double *tilt_position, unsigned int *speed );
SNC_ERROR   __stdcall   sncwSetMovePanTiltAbsolute              ( SNC_HANDLE Handle, double pan_position, double tilt_position, unsigned int speed );

SNC_ERROR   __stdcall   sncwGetMovePanTiltAbsoluteEx            ( SNC_HANDLE Handle, unsigned int id_Streaming, double *pan_position, double *tilt_position, unsigned int *speed );
SNC_ERROR   __stdcall   sncwSetMovePanTiltAbsoluteEx            ( SNC_HANDLE Handle, unsigned int id_Streaming, double pan_position, double tilt_position, unsigned int speed );

SNC_ERROR   __stdcall   sncwSetMovePanTiltLimit                 ( SNC_HANDLE Handle, double pan_min, double pan_max, double tilt_min, double tilt_max );

SNC_ERROR   __stdcall   sncwSetMovePanTiltRatio                 ( SNC_HANDLE Handle, MOVE_DIRECTION dir, unsigned int ratio );
SNC_ERROR   __stdcall   sncwSetMovePanTiltRatioEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, MOVE_DIRECTION dir, unsigned int ratio );

SNC_ERROR   __stdcall   sncwSetMovePanTiltRelative              ( SNC_HANDLE Handle, double pan_delta, double tilt_delta, unsigned int speed );
SNC_ERROR   __stdcall   sncwSetMovePanTiltRelativeEx            ( SNC_HANDLE Handle, unsigned int id_Streaming, double pan_delta, double tilt_delta, unsigned int speed );

SNC_ERROR   __stdcall   sncwSetMovePanTiltStart                 ( SNC_HANDLE Handle, MOVE_DIRECTION dir, unsigned int speed );
SNC_ERROR   __stdcall   sncwSetMovePanTiltStartEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, MOVE_DIRECTION dir, unsigned int speed );

SNC_ERROR   __stdcall   sncwSetMoveStop                         ( SNC_HANDLE Handle, MOVE_TYPE type );
SNC_ERROR   __stdcall   sncwSetMoveStopEx                       ( SNC_HANDLE Handle, unsigned int id_Streaming, MOVE_TYPE type );

SNC_ERROR   __stdcall   sncwSetMoveStopAll                      ( SNC_HANDLE Handle );
SNC_ERROR   __stdcall   sncwSetMoveStopAllEx                    ( SNC_HANDLE Handle  ,unsigned int id_Streaming);

SNC_ERROR   __stdcall   sncwSetMoveTiltAbsolute					( SNC_HANDLE Handle, unsigned int id_Streaming, double tilt_position, unsigned int speed );

SNC_ERROR   __stdcall   sncwGetMoveTiltRange                    ( SNC_HANDLE Handle, double *tilt_min, double *tilt_max );

SNC_ERROR   __stdcall   sncwSetMoveZoomAbsolute                 ( SNC_HANDLE Handle, double zoom_position, unsigned int speed );
SNC_ERROR   __stdcall   sncwGetMoveZoomAbsoluteEx				( SNC_HANDLE Handle, unsigned int id_Streaming, double *zoom_position );
SNC_ERROR   __stdcall   sncwSetMoveZoomAbsoluteEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, double zoom_position, unsigned int speed );

SNC_ERROR   __stdcall   sncwGetMoveZoomRange                    ( SNC_HANDLE Handle, double *zoom_optical_min, double *zoom_optical_max, double *zoom_digit_max );

SNC_ERROR   __stdcall   sncwSetMoveZoomRelative                 ( SNC_HANDLE Handle, double zoom_delta, unsigned int speed );
SNC_ERROR   __stdcall   sncwSetMoveZoomRelativeEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, double zoom_delta, unsigned int speed );


SNC_ERROR   __stdcall   sncwSetMoveZoomStart                    ( SNC_HANDLE Handle, ZOOM_DIRECTION dir, unsigned int speed );
SNC_ERROR   __stdcall   sncwSetMoveZoomStartEx                  ( SNC_HANDLE Handle, unsigned int id_Streaming, ZOOM_DIRECTION dir, unsigned int speed );

SNC_ERROR   __stdcall   sncwGetSimultaneousPanTiltZoomAvailable ( SNC_HANDLE Handle, bool *out );

//Camera network setting
SNC_ERROR	__stdcall	sncwGetArpingFunction				    (SNC_HANDLE Handle, bool *out );
SNC_ERROR	__stdcall	sncwSetArpingFunction				    (SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetCurrentDnsServerAddress          ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int id, IpAddress *out );

SNC_ERROR   __stdcall   sncwGetCurrentGateWay                   ( SNC_HANDLE Handle, NETWORK_TYPE type, IpAddress *out );

SNC_ERROR   __stdcall   sncwGetCurrentIpAddress                 ( SNC_HANDLE Handle, NETWORK_TYPE type, IpAddress *out );

SNC_ERROR   __stdcall   sncwGetCurrentIpPrefix                  ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int id, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetCurrentIpv6Address               ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int id, IpAddress *out );

SNC_ERROR   __stdcall   sncwGetCurrentSubNetMask                ( SNC_HANDLE Handle, NETWORK_TYPE type, IpAddress *out );

SNC_ERROR   __stdcall   sncwSupportTypesNetworkType             ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetDhcpMode                         ( SNC_HANDLE Handle, NETWORK_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetDhcpMode                         ( SNC_HANDLE Handle, NETWORK_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetDnsAutoMode                      ( SNC_HANDLE Handle, NETWORK_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetDnsAutoMode                      ( SNC_HANDLE Handle, NETWORK_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetDnsServerAddress                 ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int id, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetDnsServerAddress                 ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int id, const IpAddress & in );

SNC_ERROR   __stdcall   sncwGetDomainSuffix                     ( SNC_HANDLE Handle, NETWORK_TYPE type, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetDomainSuffix                     ( SNC_HANDLE Handle, NETWORK_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwGetEthernetAutoNegotiation			( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetEthernetAutoNegotiation			( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsEthernetDuplexMode			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEthernetDuplexMode				( SNC_HANDLE Handle, ETHERNET_DUPLEX_MODE *out );
SNC_ERROR   __stdcall   sncwSetEthernetDuplexMode				( SNC_HANDLE Handle, ETHERNET_DUPLEX_MODE in );

SNC_ERROR	__stdcall	sncwOptionsEthernetMdiMode				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEthernetMdiMode					( SNC_HANDLE Handle, ETHERNET_MDI_MODE *out );
SNC_ERROR   __stdcall   sncwSetEthernetMdiMode					( SNC_HANDLE Handle, ETHERNET_MDI_MODE in );

SNC_ERROR   __stdcall   sncwGetEthernetMdiStatus				( SNC_HANDLE Handle, ETHERNET_MDI_STATUS *out );

SNC_ERROR	__stdcall	sncwOptionsEthernetSpeed				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEthernetSpeed					( SNC_HANDLE Handle, ETHERNET_SPEED *out );
SNC_ERROR   __stdcall   sncwSetEthernetSpeed					( SNC_HANDLE Handle, ETHERNET_SPEED in );

SNC_ERROR   __stdcall   sncwGetEthernetStatus					( SNC_HANDLE Handle, ETHERNET_STATUS *out );

SNC_ERROR   __stdcall   sncwGetGateWay                          ( SNC_HANDLE Handle, NETWORK_TYPE type, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetGateWay                          ( SNC_HANDLE Handle, NETWORK_TYPE type, const IpAddress & in );

SNC_ERROR   __stdcall   sncwGetHostName                         ( SNC_HANDLE Handle, NETWORK_TYPE type, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetHostName                         ( SNC_HANDLE Handle, NETWORK_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwGetHttpPortNumber                   ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned short *out );
SNC_ERROR   __stdcall   sncwSetHttpPortNumber                   ( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned short in );

SNC_ERROR   __stdcall   sncwGetIpAddress                        ( SNC_HANDLE Handle, NETWORK_TYPE type, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetIpAddress                        ( SNC_HANDLE Handle, NETWORK_TYPE type, const IpAddress & in );

SNC_ERROR   __stdcall   sncwIdRangeIpLimit                      ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetIpLimit                          ( SNC_HANDLE Handle, unsigned int id_IpLimit, IpLimitType *out );
SNC_ERROR   __stdcall   sncwSetIpLimit                          ( SNC_HANDLE Handle, unsigned int id_IpLimit, const IpLimitType & in );

SNC_ERROR   __stdcall   sncwOptionsIpLimitDefaultPolicy		    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetIpLimitDefaultPolicy             ( SNC_HANDLE Handle, IP_LIMIT_POLICY *out );
SNC_ERROR   __stdcall   sncwSetIpLimitDefaultPolicy             ( SNC_HANDLE Handle, IP_LIMIT_POLICY in );

SNC_ERROR   __stdcall   sncwGetIpLimitFunction                  ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetIpLimitFunction                  ( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsIpPrefix						( SNC_HANDLE Handle, NETWORK_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetIpPrefix							( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetIpPrefix							( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int in );

SNC_ERROR   __stdcall   sncwGetMacAddress                       ( SNC_HANDLE Handle, NETWORK_TYPE type, MacAddress *out );

SNC_ERROR   __stdcall   sncwOptionsMtu                          ( SNC_HANDLE Handle, NETWORK_TYPE type, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetMtu								( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetMtu								( SNC_HANDLE Handle, NETWORK_TYPE type, unsigned int in );

SNC_ERROR	__stdcall	sncwSupportTypesNetworkPort				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetNetworkPort						( SNC_HANDLE Handle, PORT_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetNetworkPort						( SNC_HANDLE Handle, PORT_TYPE type, unsigned int in );

SNC_ERROR   __stdcall   sncwGetNetworkTypeStatus				( SNC_HANDLE Handle, NETWORK_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetNetworkTypeStatus				( SNC_HANDLE Handle, NETWORK_TYPE type, bool in );

SNC_ERROR	__stdcall	sncwSupportTypesServerName				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetServerName						( SNC_HANDLE Handle, SERVER_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetServerName						( SNC_HANDLE Handle, SERVER_TYPE type, const char *in );

SNC_ERROR   __stdcall   sncwGetSubNetMask                       ( SNC_HANDLE Handle, NETWORK_TYPE type, IpAddress *out );
SNC_ERROR   __stdcall   sncwSetSubNetMask                       ( SNC_HANDLE Handle, NETWORK_TYPE type, const IpAddress & in );

SNC_ERROR   __stdcall   sncwGetViewerAuthenticationMode         ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetViewerAuthenticationMode         ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsWirelessAntenna				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWirelessAntenna					( SNC_HANDLE Handle, WIRELESS_ANTENNA_MODE *out );
SNC_ERROR   __stdcall   sncwSetWirelessAntenna					( SNC_HANDLE Handle, WIRELESS_ANTENNA_MODE in );

SNC_ERROR   __stdcall   sncwOptionsWirelessAuthenticationMode   ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWirelessAuthenticationMode       ( SNC_HANDLE Handle, WIRELESS_AUTHENTICATION_MODE *out );
SNC_ERROR   __stdcall   sncwSetWirelessAuthenticationMode       ( SNC_HANDLE Handle, WIRELESS_AUTHENTICATION_MODE in );

SNC_ERROR   __stdcall   sncwOptionsWirelessChannel              ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetWirelessChannel                  ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetWirelessChannel                  ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetWirelessChannelEnableList        ( SNC_HANDLE Handle, unsigned int **out, int *count );
SNC_ERROR	__stdcall	sncwReleaseWirelessChannelEnableList	( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall	sncwSetWirelessExecute					( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwGetWirelessFunction                 ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetWirelessFunction                 ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsWirelessNetworkType		    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWirelessNetworkType              ( SNC_HANDLE Handle, WIRELESS_NETWORK_TYPE *out );
SNC_ERROR   __stdcall   sncwSetWirelessNetworkType              ( SNC_HANDLE Handle, WIRELESS_NETWORK_TYPE in );

SNC_ERROR   __stdcall	sncwGetWirelessPassPhrase				( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetWirelessPassPhrase				( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR   __stdcall	sncwGetWirelessPinNumber				( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetWirelessPinNumber				( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR   __stdcall   sncwGetWirelessSsid                     ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetWirelessSsid                     ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetWirelessWep                      ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetWirelessWep                      ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwIdRangeWirelessWepKey               ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetWirelessWepKey                   ( SNC_HANDLE Handle, unsigned int id_WirelessWepKey, char *pBuf, int bufLen, int * outLen );
SNC_ERROR   __stdcall   sncwSetWirelessWepKey                   ( SNC_HANDLE Handle, unsigned int id_WirelessWepKey, const char * in );

SNC_ERROR   __stdcall   sncwOptionsWirelessWepKeyInUse          ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetWirelessWepKeyInUse              ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetWirelessWepKeyInUse              ( SNC_HANDLE Handle, unsigned int in );

//Camera Position(preset, home, tour, stour)
SNC_ERROR   __stdcall   sncwOptionsHomePosition				    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetHomePosition                     ( SNC_HANDLE Handle, HOME_POSITION_OPERATION_TYPE in );

SNC_ERROR   __stdcall   sncwOptionsHomePositionEx				( SNC_HANDLE Handle,unsigned int id_Streaming, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetHomePositionEx                   ( SNC_HANDLE Handle, unsigned int id_Streaming, HOME_POSITION_OPERATION_TYPE in );

SNC_ERROR   __stdcall   sncwGetHomePositionProperty             ( SNC_HANDLE Handle, double *pan_position, double *tilt_position, double *zoom_position );
SNC_ERROR   __stdcall   sncwGetHomePositionPropertyEx           ( SNC_HANDLE Handle, unsigned int id_Streaming, double *pan_position, double *tilt_position, double *zoom_position );

SNC_ERROR   __stdcall   sncwSetPresetPositionClear              ( SNC_HANDLE Handle, const unsigned int *in, int count );
SNC_ERROR   __stdcall   sncwSetPresetPositionClearEx            ( SNC_HANDLE Handle, unsigned int id_Streaming, const unsigned int *in, int count );

SNC_ERROR   __stdcall   sncwSetPresetPositionGroupAdd			( SNC_HANDLE Handle, const PresetPositionGroupName &in );

SNC_ERROR   __stdcall   sncwSetPresetPositionGroupClear			( SNC_HANDLE Handle, const unsigned int *in, int count );

SNC_ERROR   __stdcall   sncwGetPresetPositionGroupList          ( SNC_HANDLE Handle, PresetPositionGroupName **out, int *count );
SNC_ERROR   __stdcall   sncwSetPresetPositionGroupList			( SNC_HANDLE Handle, const PresetPositionGroupName *in, int count );
SNC_ERROR	__stdcall	sncwReleasePresetPositionGroupList		( SNC_HANDLE Handle, PresetPositionGroupName **in );

SNC_ERROR   __stdcall   sncwGetPresetPositionList               ( SNC_HANDLE Handle, PresetPositionName **out, int *count );
SNC_ERROR   __stdcall   sncwSetPresetPositionList				( SNC_HANDLE Handle, const PresetPositionName *in, int count );
SNC_ERROR	__stdcall	sncwReleasePresetPositionList			( SNC_HANDLE Handle, PresetPositionName **in );

SNC_ERROR   __stdcall   sncwGetPresetPositionListEx             ( SNC_HANDLE Handle, unsigned int id_Streaming, PresetPositionName **out, int *count);
SNC_ERROR   __stdcall   sncwSetPresetPositionListEx             ( SNC_HANDLE Handle, unsigned int id_Streaming, const PresetPositionName *in, int count );
SNC_ERROR	__stdcall	sncwReleasePresetPositionListEx			( SNC_HANDLE Handle, PresetPositionName **in );

SNC_ERROR   __stdcall   sncwSetPresetPositionMove               ( SNC_HANDLE Handle, unsigned int id_PresetPosition, unsigned int speed );
SNC_ERROR   __stdcall   sncwSetPresetPositionMoveEx             ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_PresetPosition, unsigned int speed );

SNC_ERROR   __stdcall   sncwGetPresetPositionMoveOnSensor       ( SNC_HANDLE Handle, unsigned int id_Sensor, unsigned int * out );
SNC_ERROR   __stdcall   sncwSetPresetPositionMoveOnSensor       ( SNC_HANDLE Handle, unsigned int id_Sensor, unsigned int in );

SNC_ERROR   __stdcall   sncwGetPresetPositionMoveOnSensorEx     ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Sensor, unsigned int * out );
SNC_ERROR   __stdcall   sncwSetPresetPositionMoveOnSensorEx     ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Sensor, unsigned int in );

SNC_ERROR   __stdcall   sncwIdRangePresetPosition               ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwSetPresetPositionSetCurrent         ( SNC_HANDLE Handle, unsigned int id_PresetPosition, const char * in );

SNC_ERROR   __stdcall   sncwIdRangePresetPositionEx             ( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwSetPresetPositionSetCurrentEx       ( SNC_HANDLE Handle, unsigned int id_PresetPosition, const char * name, bool in );
SNC_ERROR   __stdcall   sncwSetPresetPositionSetCurrentEx2      ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_PresetPosition, const char * name, bool in );

SNC_ERROR   __stdcall   sncwSetPresetPositionThumbnailClear		( SNC_HANDLE Handle, const unsigned int *in, int count );
SNC_ERROR   __stdcall   sncwSetPresetPositionThumbnailClearEx	( SNC_HANDLE Handle,unsigned int id_Streaming, const unsigned int *in, int count );

SNC_ERROR   __stdcall   sncwSetPresetPositionThumbnailDelete	( SNC_HANDLE Handle, unsigned int id_PresetPosition );
SNC_ERROR   __stdcall   sncwSetPresetPositionThumbnailDeleteEx	( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_PresetPosition  );

SNC_ERROR   __stdcall   sncwGetShadowTourCurrentRecordTime		( SNC_HANDLE Handle, unsigned int id_ShadowTour, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetShadowTourFunction				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetShadowTourFunction				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetShadowTourMaxRecordTime			( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwOptionsShadowTourPeriodMode         ( SNC_HANDLE Handle, unsigned int id_ShadowTour, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetShadowTourPeriodMode				( SNC_HANDLE Handle, unsigned int id_ShadowTour, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetShadowTourPeriodMode				( SNC_HANDLE Handle, unsigned int id_ShadowTour, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwGetShadowTourPeriodWeeklySchedule	( SNC_HANDLE Handle, unsigned int id_ShadowTour, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetShadowTourPeriodWeeklySchedule	( SNC_HANDLE Handle, unsigned int id_ShadowTour, const WeeklyScheduleType &in );

SNC_ERROR   __stdcall   sncwSetShadowTourPreviewCopy			( SNC_HANDLE Handle, unsigned int id_ShadowTour );

SNC_ERROR   __stdcall   sncwSetShadowTourPreviewStart			( SNC_HANDLE Handle, unsigned int id_ShadowTour );

SNC_ERROR	__stdcall	sncwSetShadowTourPreviewStop			( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwSetShadowTourRecordStart			( SNC_HANDLE Handle, unsigned int id_ShadowTour );

SNC_ERROR	__stdcall	sncwSetShadowTourRecordStop				( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwGetShadowTourResumeMode				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetShadowTourResumeMode				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsShadowTourResumeTime         ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetShadowTourResumeTime				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetShadowTourResumeTime				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwIdRangeShadowTour					( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetShadowTourStatus					( SNC_HANDLE Handle, unsigned int id_ShadowTour, bool *out );
SNC_ERROR   __stdcall   sncwSetShadowTourStatus					( SNC_HANDLE Handle, unsigned int id_ShadowTour, bool in );

SNC_ERROR	__stdcall	sncwSetShadowTourTempPreviewStart		( SNC_HANDLE Handle );

SNC_ERROR	__stdcall	sncwSetShadowTourTempRecordStart		( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwGetTourFunction                     ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetTourFunction                     ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetTourFunctionEx					( SNC_HANDLE Handle, unsigned int id_Streaming,  bool *out );
SNC_ERROR   __stdcall   sncwSetTourFunctionEx					( SNC_HANDLE Handle, unsigned int id_Streaming, bool in );

SNC_ERROR   __stdcall   sncwOptionsTourPeriodMode			    ( SNC_HANDLE Handle, unsigned int id_Tour, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetTourPeriodMode                   ( SNC_HANDLE Handle, unsigned int id_Tour, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetTourPeriodMode                   ( SNC_HANDLE Handle, unsigned int id_Tour, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwOptionsTourPeriodModeEx             ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetTourPeriodModeEx                 ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetTourPeriodModeEx                 ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwGetTourPeriodWeeklySchedule         ( SNC_HANDLE Handle, unsigned int id_Tour, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetTourPeriodWeeklySchedule         ( SNC_HANDLE Handle, unsigned int id_Tour, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwGetTourPeriodWeeklyScheduleEx		( SNC_HANDLE Handle ,unsigned int id_Streaming, unsigned int id_Tour, WeeklyScheduleType *out  );
SNC_ERROR   __stdcall   sncwSetTourPeriodWeeklyScheduleEx		( SNC_HANDLE Handle ,unsigned int id_Streaming, unsigned int id_Tour, const WeeklyScheduleType &in );

SNC_ERROR   __stdcall	sncwSetTourPreviewCopy					( SNC_HANDLE Handle, unsigned int id_Tour );

SNC_ERROR   __stdcall   sncwSetTourPreviewCopyEx				( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour  );

SNC_ERROR   __stdcall   sncwGetTourPreviewSequenceList			( SNC_HANDLE Handle, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwSetTourPreviewSequenceList			( SNC_HANDLE Handle, const unsigned int *in, int count );
SNC_ERROR	__stdcall	sncwReleaseTourPreviewSequenceList		( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwGetTourPreviewSequenceListEx		( SNC_HANDLE Handle, unsigned int id_Streaming,unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwSetTourPreviewSequenceListEx		( SNC_HANDLE Handle, unsigned int id_Streaming,const unsigned int *out, int count );
SNC_ERROR	__stdcall	sncwReleaseTourPreviewSequenceListEx	( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwOptionsTourPreviewSpeed				( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourPreviewSpeed					( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetTourPreviewSpeed					( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsTourPreviewSpeedEx			( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourPreviewSpeedEx				( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out  );
SNC_ERROR   __stdcall   sncwSetTourPreviewSpeedEx				( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall	sncwSetTourPreviewStart					( SNC_HANDLE Handle, unsigned int id_Tour );
SNC_ERROR   __stdcall   sncwSetTourPreviewStartEx				( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour  );

SNC_ERROR   __stdcall	sncwSetTourPreviewStop					( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwGetTourResumeMode                   ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetTourResumeMode                   ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetTourResumeModeEx					( SNC_HANDLE Handle, unsigned int id_Streaming, bool *out );
SNC_ERROR   __stdcall   sncwSetTourResumeModeEx					( SNC_HANDLE Handle, unsigned int id_Streaming, bool in );

SNC_ERROR   __stdcall   sncwOptionsTourResumeTime               ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourResumeTime                   ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetTourResumeTime                   ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsTourResumeTimeEx				( SNC_HANDLE Handle, unsigned int id_Streaming,RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourResumeTimeEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetTourResumeTimeEx					( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int in );

SNC_ERROR   __stdcall   sncwGetTourSequenceList                 ( SNC_HANDLE Handle, unsigned int id_Tour, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwSetTourSequenceList                 ( SNC_HANDLE Handle, unsigned int id_Tour, const unsigned int *in, int count );
SNC_ERROR	__stdcall	sncwReleaseTourSequenceList				( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwIdRangeTourEx						( SNC_HANDLE Handle, unsigned int id_Streaming, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourSequenceListEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwSetTourSequenceListEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, const unsigned int *in, int count );
SNC_ERROR	__stdcall	sncwReleaseTourSequenceListEx			( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwOptionsTourSpeed	                ( SNC_HANDLE Handle, unsigned int id_Tour, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourSpeed                        ( SNC_HANDLE Handle, unsigned int id_Tour, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetTourSpeed                        ( SNC_HANDLE Handle, unsigned int id_Tour, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsTourSpeedEx	                ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int  id_Tour, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourSpeedEx                      ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetTourSpeedEx                      ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, unsigned int in );

SNC_ERROR   __stdcall   sncwIdRangeTour                         ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourStatus                       ( SNC_HANDLE Handle, unsigned int id_Tour, bool *out );
SNC_ERROR   __stdcall   sncwSetTourStatus                       ( SNC_HANDLE Handle, unsigned int id_Tour, bool in );

SNC_ERROR   __stdcall   sncwGetTourStatusEx                     ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, bool *out );
SNC_ERROR   __stdcall   sncwSetTourStatusEx                     ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, bool in );

SNC_ERROR   __stdcall   sncwOptionsTourStayTime                 ( SNC_HANDLE Handle, unsigned int id_Tour, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourStayTime                     ( SNC_HANDLE Handle, unsigned int id_Tour, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetTourStayTime                     ( SNC_HANDLE Handle, unsigned int id_Tour, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsTourStayTimeEx               ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetTourStayTimeEx                   ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, unsigned int *out  );
SNC_ERROR   __stdcall   sncwSetTourStayTimeEx                   ( SNC_HANDLE Handle, unsigned int id_Streaming, unsigned int id_Tour, unsigned int in );

SNC_ERROR   __stdcall	sncwSetTourTempPreviewStart				( SNC_HANDLE Handle );

// Camera FTP Client, FTP Server, SMTP, Image Memory

SNC_ERROR   __stdcall   sncwGetAlarmAssignedName                ( SNC_HANDLE Handle, OUTPUT_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetAlarmAssignedName                ( SNC_HANDLE Handle, OUTPUT_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwGetAlarmBuffer                      ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmBuffer                      ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwSetAlarmClearSequence               ( SNC_HANDLE Handle, OUTPUT_TYPE type );

SNC_ERROR	__stdcall	sncwSupportTypesOutputType				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmFunction                    ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmFunction                    ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetAlarmOnSensor                    ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned int id_Sensor, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmOnSensor                    ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned int id_Sensor, bool in );

SNC_ERROR   __stdcall   sncwOptionsAlarmPeriodMode		        ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmPeriodMode                  ( SNC_HANDLE Handle, OUTPUT_TYPE type, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetAlarmPeriodMode                  ( SNC_HANDLE Handle, OUTPUT_TYPE type, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwGetAlarmPeriodWeeklySchedule        ( SNC_HANDLE Handle, OUTPUT_TYPE type, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetAlarmPeriodWeeklySchedule        ( SNC_HANDLE Handle, OUTPUT_TYPE type, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwGetAlarmRemotePath                  ( SNC_HANDLE Handle, OUTPUT_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetAlarmRemotePath                  ( SNC_HANDLE Handle, OUTPUT_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwOptionsAlarmSuffixMode		        ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmSuffixMode                  ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_SUFFIX_MODE *out );
SNC_ERROR   __stdcall   sncwSetAlarmSuffixMode                  ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_SUFFIX_MODE in );

SNC_ERROR   __stdcall   sncwSupportTypesAudioDetectionType      ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAudioDetectionFunction           ( SNC_HANDLE Handle, AUDIO_DETECTION_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetAudioDetectionFunction           ( SNC_HANDLE Handle, AUDIO_DETECTION_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwOptionsAudioDetectionManualSensitivity( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAudioDetectionManualSensitivity  ( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAudioDetectionManualSensitivity  ( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsAudioDetectionSensitivity    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAudioDetectionSensitivity        ( SNC_HANDLE Handle, AUDIO_DETECTION_SENSITIVITY *out);
SNC_ERROR   __stdcall   sncwSetAudioDetectionSensitivity        ( SNC_HANDLE Handle, AUDIO_DETECTION_SENSITIVITY in);

SNC_ERROR   __stdcall   sncwSupportTypesDetectionType	        ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetDetectionFunction				( SNC_HANDLE Handle, SNC::DETECTION_TYPE type, bool *out );
SNC_ERROR   __stdcall	sncwSetDetectionFunction				( SNC_HANDLE Handle, SNC::DETECTION_TYPE type, bool in );

SNC_ERROR   __stdcall	sncwIdRangeDisableNotifyFilter			( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetDisableNotifyFilter				( SNC_HANDLE Handle, unsigned int index, bool *out );
SNC_ERROR   __stdcall	sncwSetDisableNotifyFilter				( SNC_HANDLE Handle, unsigned int index, bool in );

SNC_ERROR   __stdcall   sncwSupportTypesEmergencyType           ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEmergencyFunction                ( SNC_HANDLE Handle, EMERGENCY_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetEmergencyFunction                ( SNC_HANDLE Handle, EMERGENCY_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetEmergencyNotifyCyclic            ( SNC_HANDLE Handle, EMERGENCY_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetEmergencyNotifyCyclic            ( SNC_HANDLE Handle, EMERGENCY_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwOptionsFtpClientFileExistRule	    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetFtpClientFileExistRule           ( SNC_HANDLE Handle, FTP_CLIENT_FILE_EXIST_RULE *out );
SNC_ERROR   __stdcall   sncwSetFtpClientFileExistRule           ( SNC_HANDLE Handle, FTP_CLIENT_FILE_EXIST_RULE in );

SNC_ERROR   __stdcall   sncwGetFtpClientFunction                ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetFtpClientFunction                ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetFtpClientPassiveMode             ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetFtpClientPassiveMode             ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetFtpClientPassword                ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetFtpClientPassword                ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetFtpClientServerName              ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetFtpClientServerName              ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetFtpClientUserName                ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetFtpClientUserName                ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetFtpServerControlPort             ( SNC_HANDLE Handle, unsigned short *out );
SNC_ERROR   __stdcall   sncwSetFtpServerControlPort             ( SNC_HANDLE Handle, unsigned short in );

SNC_ERROR   __stdcall   sncwGetFtpServerFunction                ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetFtpServerFunction                ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsFtpServerRootDirectory	    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetFtpServerRootDirectory           ( SNC_HANDLE Handle, DRIVER_TYPE *out );
SNC_ERROR   __stdcall   sncwSetFtpServerRootDirectory           ( SNC_HANDLE Handle, DRIVER_TYPE in );

SNC_ERROR   __stdcall   sncwGetFtpServerUser                    ( SNC_HANDLE Handle, unsigned int id, char *pBuf1, int bufLen1, int *outLen1, char *pBuf2, int bufLen2, int *outLen2 );
SNC_ERROR   __stdcall   sncwSetFtpServerUser                    ( SNC_HANDLE Handle, unsigned int id, const char * in1, const char * in2 );

SNC_ERROR   __stdcall   sncwGetImageMemoryAdminEmailAddress     ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetImageMemoryAdminEmailAddress     ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetImageMemoryAssignedName          ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetImageMemoryAssignedName          ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetImageMemoryCapacityWarning       ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetImageMemoryCapacityWarning       ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwSetImageMemoryClearSequence         ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwOptionsImageMemoryDriver		    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetImageMemoryDriver                ( SNC_HANDLE Handle, DRIVER_TYPE *out );
SNC_ERROR   __stdcall   sncwSetImageMemoryDriver                ( SNC_HANDLE Handle, DRIVER_TYPE in );

SNC_ERROR   __stdcall   sncwGetImageMemoryFunction              ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetImageMemoryFunction              ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetImageMemoryOverwrite             ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetImageMemoryOverwrite             ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetImageMemoryRecipientEmailAddress ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetImageMemoryRecipientEmailAddress ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetImageMemorySmtpServerName        ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetImageMemorySmtpServerName        ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwOptionsImageMemorySuffixMode	    ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetImageMemorySuffixMode            ( SNC_HANDLE Handle, OUTPUT_SUFFIX_MODE *out );
SNC_ERROR   __stdcall   sncwSetImageMemorySuffixMode            ( SNC_HANDLE Handle, OUTPUT_SUFFIX_MODE in );

SNC_ERROR   __stdcall   sncwGetManualAssignedName               ( SNC_HANDLE Handle, OUTPUT_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetManualAssignedName               ( SNC_HANDLE Handle, OUTPUT_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwSetManualClearSequence              ( SNC_HANDLE Handle, OUTPUT_TYPE type );

SNC_ERROR   __stdcall   sncwGetManualFunction                   ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetManualFunction                   ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetManualRemotePath                 ( SNC_HANDLE Handle, OUTPUT_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetManualRemotePath                 ( SNC_HANDLE Handle, OUTPUT_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwOptionsManualSuffixMode		        ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetManualSuffixMode                 ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_SUFFIX_MODE *out );
SNC_ERROR   __stdcall   sncwSetManualSuffixMode                 ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_SUFFIX_MODE in );

SNC_ERROR   __stdcall   sncwGetPeriodicalAssignedName           ( SNC_HANDLE Handle, OUTPUT_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetPeriodicalAssignedName           ( SNC_HANDLE Handle, OUTPUT_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwSetPeriodicalClearSequence          ( SNC_HANDLE Handle, OUTPUT_TYPE type );

SNC_ERROR   __stdcall   sncwGetPeriodicalFunction               ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetPeriodicalFunction               ( SNC_HANDLE Handle, OUTPUT_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetPeriodicalIntervalTime           ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetPeriodicalIntervalTime           ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned int in );

SNC_ERROR   __stdcall   sncwOptionsPeriodicalMode		        ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetPeriodicalMode                   ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_PERIODICAL_MODE *out );
SNC_ERROR   __stdcall   sncwSetPeriodicalMode                   ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_PERIODICAL_MODE in );

SNC_ERROR   __stdcall   sncwOptionsPeriodicalPeriodMode         ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetPeriodicalPeriodMode             ( SNC_HANDLE Handle, OUTPUT_TYPE type, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetPeriodicalPeriodMode             ( SNC_HANDLE Handle, OUTPUT_TYPE type, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwGetPeriodicalRemotePath             ( SNC_HANDLE Handle, OUTPUT_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetPeriodicalRemotePath             ( SNC_HANDLE Handle, OUTPUT_TYPE type, const char * in );

SNC_ERROR   __stdcall   sncwOptionsPeriodicalSuffixMode		    ( SNC_HANDLE Handle, OUTPUT_TYPE type, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetPeriodicalSuffixMode             ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_SUFFIX_MODE *out );
SNC_ERROR   __stdcall   sncwSetPeriodicalSuffixMode             ( SNC_HANDLE Handle, OUTPUT_TYPE type, OUTPUT_SUFFIX_MODE in );

SNC_ERROR   __stdcall   sncwGetPeriodicalPeriodWeeklySchedule   ( SNC_HANDLE Handle, OUTPUT_TYPE type, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetPeriodicalPeriodWeeklySchedule   ( SNC_HANDLE Handle, OUTPUT_TYPE type, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwGetSmtpAdminEmailAddress            ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetSmtpAdminEmailAddress            ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetSmtpAlarmFileAttachment          ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSmtpAlarmFileAttachment          ( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsSmtpAuthenticationMethod		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSmtpAuthenticationMethod			( SNC_HANDLE Handle, SMTP_AUTHENTICATION_METHOD *out );
SNC_ERROR   __stdcall   sncwSetSmtpAuthenticationMethod			( SNC_HANDLE Handle, SMTP_AUTHENTICATION_METHOD in );

SNC_ERROR	__stdcall	sncwOptionsSmtpAuthenticationMode		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSmtpAuthenticationMode			( SNC_HANDLE Handle, SMTP_AUTHENTICATION_MODE *out );
SNC_ERROR   __stdcall   sncwSetSmtpAuthenticationMode			( SNC_HANDLE Handle, SMTP_AUTHENTICATION_MODE in );

SNC_ERROR   __stdcall   sncwSetSmtpClearSequence                ( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwGetSmtpFunction                     ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSmtpFunction                     ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetSmtpMessageTemplate              ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetSmtpMessageTemplate              ( SNC_HANDLE Handle, const char * in );

SNC_ERROR	__stdcall	sncwOptionsSmtpPopAfterWaitTime			( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR	__stdcall	sncwGetSmtpPopAfterWaitTime				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR	__stdcall	sncwSetSmtpPopAfterWaitTime				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsSmtpPopMode					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetSmtpPopMode						( SNC_HANDLE Handle, POP_MODE *out );
SNC_ERROR	__stdcall	sncwSetSmtpPopMode						( SNC_HANDLE Handle, POP_MODE in );

SNC_ERROR   __stdcall   sncwGetSmtpRecipientEmailAddress        ( SNC_HANDLE Handle, unsigned int id, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetSmtpRecipientEmailAddress        ( SNC_HANDLE Handle, unsigned int id, const char * in );

SNC_ERROR   __stdcall   sncwGetSmtpServerName                   ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetSmtpServerName                   ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetSmtpSubjectTemplate              ( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetSmtpSubjectTemplate              ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetSmtpTls							( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSmtpTls							( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetSmtpTlsStart						( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSmtpTlsStart						( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwOptionsSmtpTrigger                  ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSmtpTrigger						( SNC_HANDLE Handle, TRIGGER_TYPE *out );
SNC_ERROR   __stdcall   sncwSetSmtpTrigger						( SNC_HANDLE Handle, TRIGGER_TYPE in );

SNC_ERROR	__stdcall	sncwSupportTypesStillImageSend			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetStillImageSend					( SNC_HANDLE Handle, STILL_IMAGE_SEND_TYPE type, unsigned int id_Streaming, bool *out );
SNC_ERROR	__stdcall	sncwSetStillImageSend					( SNC_HANDLE Handle, STILL_IMAGE_SEND_TYPE type, unsigned int id_Streaming, bool in );

SNC_ERROR	__stdcall	sncwSupportTypesStillImageSendEx		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwOptionsStillImageSendEx				( SNC_HANDLE Handle, STILL_IMAGE_SEND_TYPE type, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetStillImageSendEx					( SNC_HANDLE Handle, STILL_IMAGE_SEND_TYPE type, IMAGE_CODEC_INSTANCE *out );
SNC_ERROR	__stdcall	sncwSetStillImageSendEx					( SNC_HANDLE Handle, STILL_IMAGE_SEND_TYPE type, IMAGE_CODEC_INSTANCE in );

SNC_ERROR	__stdcall	sncwSupportTypesTamperingType			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetTamperingFunction				( SNC_HANDLE Handle, TAMPERING_TYPE type, bool *out );
SNC_ERROR   __stdcall	sncwSetTamperingFunction				( SNC_HANDLE Handle, TAMPERING_TYPE type, bool in );

SNC_ERROR	__stdcall	sncwSupportTypesVmfType					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetVmfFunction						( SNC_HANDLE Handle, VMF_TYPE type, bool *out );
SNC_ERROR   __stdcall	sncwSetVmfFunction						( SNC_HANDLE Handle, VMF_TYPE type, bool in );

// Camera Security
SNC_ERROR	__stdcall	sncwIdRangeCaCertificate				( SNC_HANDLE Handle, SECURITY_TYPE type, RangeUint *out );

SNC_ERROR	__stdcall	sncwGetCaCertificateExtendedKeyUsage	( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int id_CaCertificate, char *pBuf, int bufLen, int *outLen );

SNC_ERROR	__stdcall	sncwGetCaCertificateInstalled			( SNC_HANDLE Handle, SECURITY_TYPE type, bool *out );

SNC_ERROR   __stdcall   sncwGetCaCertificateInstalledEx			( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int id_CaCertificate, bool *out );

SNC_ERROR	__stdcall	sncwGetCaCertificateIssuerDomainName	( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int id_CaCertificate, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall   sncwGetCaCertificateNum					( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int *out );

SNC_ERROR	__stdcall	sncwGetCaCertificateSubjectDomainName	( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int id_CaCertificate, char *pBuf, int bufLen, int *outLen );

SNC_ERROR	__stdcall	sncwGetCaCertificateValidityPeriod		( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int id_CaCertificate, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall   sncwSetCertificateDelete				( SNC_HANDLE Handle, SECURITY_TYPE type, unsigned int id_CaCertificate );

SNC_ERROR	__stdcall	sncwGetClientCertificateAvailability	( SNC_HANDLE Handle, SECURITY_TYPE type, bool *out );

SNC_ERROR	__stdcall	sncwGetClientCertificateExtendedKeyUsage( SNC_HANDLE Handle, SECURITY_TYPE type, char *pBuf, int bufLen, int *outLen );

SNC_ERROR	__stdcall	sncwGetClientCertificateInstalled		( SNC_HANDLE Handle, SECURITY_TYPE type, bool *out );

SNC_ERROR	__stdcall	sncwGetClientCertificateIssuerDomainName( SNC_HANDLE Handle, SECURITY_TYPE type, char *pBuf, int bufLen, int *outLen );

SNC_ERROR   __stdcall	sncwGetClientCertificateStatus			( SNC_HANDLE Handle, SECURITY_TYPE type, bool *out );
SNC_ERROR   __stdcall	sncwSetClientCertificateStatus			( SNC_HANDLE Handle, SECURITY_TYPE type, bool in );

SNC_ERROR	__stdcall	sncwGetClientCertificateSubjectDomainName( SNC_HANDLE Handle, SECURITY_TYPE type, char *pBuf, int bufLen, int *outLen );

SNC_ERROR	__stdcall	sncwGetClientCertificateValidityPeriod	( SNC_HANDLE Handle, SECURITY_TYPE type, char *pBuf, int bufLen, int *outLen );

SNC_ERROR	__stdcall	sncwOptionsDot1xEapMethod				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetDot1xEapMethod					( SNC_HANDLE Handle, DOT1X_EAP_METHOD *out );
SNC_ERROR	__stdcall	sncwSetDot1xEapMethod					( SNC_HANDLE Handle, DOT1X_EAP_METHOD in );

SNC_ERROR	__stdcall	sncwGetDot1xIdentity					( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR	__stdcall	sncwSetDot1xIdentity					( SNC_HANDLE Handle, const char *in );

SNC_ERROR	__stdcall	sncwSetDot1xNetworkStatus				( SNC_HANDLE Handle, DOT1X_NETWORK_STATUS in );

SNC_ERROR	__stdcall	sncwGetDot1xPassword					( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR	__stdcall	sncwSetDot1xPassword					( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR	__stdcall	sncwOptionsDot1xTlsMode					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR	__stdcall	sncwGetDot1xTlsMode						( SNC_HANDLE Handle, DOT1X_TLS_MODE *out );
SNC_ERROR	__stdcall	sncwSetDot1xTlsMode						( SNC_HANDLE Handle, DOT1X_TLS_MODE in );

SNC_ERROR	__stdcall	sncwGetDot1xWiredFunction				( SNC_HANDLE Handle, bool *out );
SNC_ERROR	__stdcall	sncwSetDot1xWiredFunction				( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwSupportTypesSecurity				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetPrivatePassword					( SNC_HANDLE Handle, SECURITY_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetPrivatePassword					( SNC_HANDLE Handle, SECURITY_TYPE type, const char *pBuf );

SNC_ERROR   __stdcall   sncwOptionsSslCertificateMode			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSslCertificateMode				( SNC_HANDLE Handle, SSL_CERTIFICATE_MODE *out );
SNC_ERROR   __stdcall   sncwSetSslCertificateMode				( SNC_HANDLE Handle, SSL_CERTIFICATE_MODE in );

SNC_ERROR	__stdcall	sncwSetSslCertificateGenerate			( SNC_HANDLE Handle );

SNC_ERROR   __stdcall   sncwOptionsSslMode						( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSslMode							( SNC_HANDLE Handle, SSL_MODE *out );
SNC_ERROR   __stdcall   sncwSetSslMode							( SNC_HANDLE Handle, SSL_MODE in );

SNC_ERROR   __stdcall   sncwOptionsSslProtocol					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSslProtocol						( SNC_HANDLE Handle, SSL_PROTOCOL *out );
SNC_ERROR   __stdcall   sncwSetSslProtocol						( SNC_HANDLE Handle, SSL_PROTOCOL in );

SNC_ERROR   __stdcall   sncwGetSslSessionKeyChange				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSslSessionKeyChange				( SNC_HANDLE Handle, bool in );

// Camera Alarm output
SNC_ERROR   __stdcall   sncwOptionsAlarmOutputDuration          ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAlarmOutputDuration              ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputDuration              ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, unsigned int in );

SNC_ERROR	__stdcall	sncwIdRangeAlarmOutput					( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAlarmOutputFunction              ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputFunction              ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, bool in );

SNC_ERROR   __stdcall   sncwGetAlarmOutputManualFunction        ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputManualFunction        ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, bool in );

SNC_ERROR   __stdcall   sncwGetAlarmOutputOnSensor              ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, unsigned int id_Sensor, bool *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputOnSensor              ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, unsigned int id_Sensor, bool in );

SNC_ERROR   __stdcall   sncwOptionsAlarmOutputPeriodMode	    ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmOutputPeriodMode            ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputPeriodMode            ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwGetAlarmOutputPeriodWeeklySchedule  ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputPeriodWeeklySchedule  ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwGetAlarmOutputTimerWeeklySchedule   ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputTimerWeeklySchedule   ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwOptionsAlarmOutputTriggerMode	    ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmOutputTriggerMode           ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, ALARM_TRIGGER_MODE *out );
SNC_ERROR   __stdcall   sncwSetAlarmOutputTriggerMode           ( SNC_HANDLE Handle, unsigned int id_AlarmOutput, ALARM_TRIGGER_MODE in );

SNC_ERROR   __stdcall   sncwOptionsAlarmTrigger                 ( SNC_HANDLE Handle, unsigned int id_AlarmOut, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmTrigger                     ( SNC_HANDLE Handle, unsigned int id_AlarmOut, TRIGGER_TYPE *out);
SNC_ERROR   __stdcall   sncwSetAlarmTrigger                     ( SNC_HANDLE Handle, unsigned int id_AlarmOut, TRIGGER_TYPE in);

SNC_ERROR   __stdcall   sncwGetAlarmStatus						( SNC_HANDLE Handle, unsigned int id_AlarmOut, bool *out);

// Camera Voice Alert
SNC_ERROR   __stdcall   sncwIdRangeVoiceAlert                   ( SNC_HANDLE Handle, RangeUint *out );

SNC_ERROR   __stdcall   sncwOptionsVoiceAlertAlarmTrigger		( SNC_HANDLE Handle, unsigned int id_VoiceAlert, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetVoiceAlertAlarmTrigger			( SNC_HANDLE Handle, unsigned int id_VoiceAlert, TRIGGER_TYPE *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertAlarmTrigger			( SNC_HANDLE Handle, unsigned int id_VoiceAlert, TRIGGER_TYPE in );

SNC_ERROR   __stdcall   sncwGetVoiceAlertFileExist              ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, bool *out );

SNC_ERROR   __stdcall   sncwGetVoiceAlertFilename               ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetVoiceAlertFilename               ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, const char * in );

SNC_ERROR   __stdcall   sncwGetVoiceAlertFunction               ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, bool *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertFunction               ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, bool in );

SNC_ERROR   __stdcall   sncwGetVoiceAlertManualFunction         ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, bool *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertManualFunction         ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, bool in );

SNC_ERROR   __stdcall   sncwGetVoiceAlertOnSensor               ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, unsigned int id_Sensor, bool *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertOnSensor               ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, unsigned int id_Sensor, bool in );

SNC_ERROR   __stdcall   sncwOptionsVoiceAlertPeriodMode         ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetVoiceAlertPeriodMode             ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, PERIOD_MODE *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertPeriodMode             ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, PERIOD_MODE in );

SNC_ERROR   __stdcall   sncwGetVoiceAlertPeriodWeeklySchedule   ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, WeeklyScheduleType *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertPeriodWeeklySchedule   ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, const WeeklyScheduleType & in );

SNC_ERROR   __stdcall   sncwOptionsVoiceAlertRepeat             ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetVoiceAlertRepeat                 ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, unsigned int *out );
SNC_ERROR   __stdcall   sncwSetVoiceAlertRepeat                 ( SNC_HANDLE Handle, unsigned int id_VoiceAlert, unsigned int in );

// Camera Alarm Buffer
SNC_ERROR   __stdcall   sncwOptionsAlarmBufferCodec             ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetAlarmBufferCodec                 ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE *out );
SNC_ERROR   __stdcall   sncwSetAlarmBufferCodec                 ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE in );

SNC_ERROR	__stdcall	sncwOptionsAlarmBufferInstance			( SNC_HANDLE Handle, const unsigned int **out, int *count );
SNC_ERROR   __stdcall	sncwGetAlarmBufferInstance				( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetAlarmBufferInstance				( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetAlarmBufferTime                  ( SNC_HANDLE Handle, unsigned int *pre, unsigned int *post );
SNC_ERROR   __stdcall   sncwSetAlarmBufferTime                  ( SNC_HANDLE Handle, unsigned int pre, unsigned int post );

SNC_ERROR   __stdcall   sncwGetAlarmBufferMaxTime               ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int *pre, unsigned int *post );

SNC_ERROR   __stdcall   sncwIdRangeAlarmBufferMaxTime           ( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetAlarmBufferMaxTimeEx             ( SNC_HANDLE Handle, unsigned int id_AlarmBuffer, unsigned int *pre, unsigned int *post );

SNC_ERROR   __stdcall   sncwGetAlarmBufferMaxTimeTotal          ( SNC_HANDLE Handle, IMAGE_CODEC_TYPE type, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetAlarmBufferMaxTimeTotalEx        ( SNC_HANDLE Handle, unsigned int id_AlarmBuffer, unsigned int *out );

// Camera Backup FTP
SNC_ERROR   __stdcall	sncwSetBackupFtpClearSequence			( SNC_HANDLE Handle );

SNC_ERROR	__stdcall	sncwOptionsBackupFtpClientAlarmFileNumber( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetBackupFtpClientAlarmFileNumber	( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientAlarmFileNumber	( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall	sncwGetBackupFtpClientAssignedName		( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientAssignedName		( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR	__stdcall	sncwOptionsBackupFtpClientDriver		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetBackupFtpClientDriver			( SNC_HANDLE Handle, DRIVER_TYPE *out );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientDriver			( SNC_HANDLE Handle, DRIVER_TYPE in );

SNC_ERROR   __stdcall	sncwGetBackupFtpClientFunction			( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientFunction			( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall	sncwGetBackupFtpClientMailService		( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientMailService		( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsBackupFtpClientPeriodMode	( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetBackupFtpClientPeriodMode		( SNC_HANDLE Handle, BACKUP_FTP_PERIOD_MODE *out );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientPeriodMode		( SNC_HANDLE Handle, BACKUP_FTP_PERIOD_MODE in );

SNC_ERROR   __stdcall	sncwGetBackupFtpClientRemotePath		( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );	
SNC_ERROR   __stdcall	sncwSetBackupFtpClientRemotePath		( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR	__stdcall	sncwOptionsBackupFtpClientSuffix		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetBackupFtpClientSuffix			( SNC_HANDLE Handle, BACKUP_FTP_SUFFIX *out );
SNC_ERROR   __stdcall	sncwSetBackupFtpClientSuffix			( SNC_HANDLE Handle, BACKUP_FTP_SUFFIX in );

// Camera Serial
SNC_ERROR	__stdcall	sncwOptionsSerialBaudRate				( SNC_HANDLE Handle, const unsigned int **out, int *count  );
SNC_ERROR   __stdcall	sncwGetSerialBaudRate					( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetSerialBaudRate					( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsSerialCharacterLength		( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetSerialCharacterLength			( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetSerialCharacterLength			( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR	__stdcall	sncwOptionsSerialParityBit				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetSerialParityBit					( SNC_HANDLE Handle, SERIAL_PARITY_BIT *out );
SNC_ERROR   __stdcall	sncwSetSerialParityBit					( SNC_HANDLE Handle, SERIAL_PARITY_BIT in );

SNC_ERROR	__stdcall	sncwOptionsSerialProtocol				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetSerialProtocol					( SNC_HANDLE Handle, SERIAL_PROTOCOL *out );
SNC_ERROR   __stdcall   sncwSetSerialProtocol	                ( SNC_HANDLE Handle, SERIAL_PROTOCOL in );

SNC_ERROR	__stdcall	sncwOptionsSerialStandardType			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetSerialStandardType				( SNC_HANDLE Handle, SERIAL_STANDARD_TYPE *out );
SNC_ERROR   __stdcall	sncwSetSerialStandardType				( SNC_HANDLE Handle, SERIAL_STANDARD_TYPE in );

SNC_ERROR	__stdcall	sncwOptionsSerialStopBit				( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall	sncwGetSerialStopBit					( SNC_HANDLE Handle, unsigned int *out );
SNC_ERROR   __stdcall	sncwSetSerialStopBit					( SNC_HANDLE Handle, unsigned int in );

SNC_ERROR   __stdcall   sncwGetSerialTermination                ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetSerialTermination                ( SNC_HANDLE Handle, bool in );

SNC_ERROR	__stdcall	sncwOptionsSerialType					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetSerialType						( SNC_HANDLE Handle, SERIAL_TYPE *out );
SNC_ERROR   __stdcall	sncwSetSerialType						( SNC_HANDLE Handle, SERIAL_TYPE in );

// Camera Filtering
SNC_ERROR	__stdcall	sncwSupportTypesIpVersion				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetIpFilterFunction					( SNC_HANDLE Handle, IP_VERSION_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetIpFilterFunction					( SNC_HANDLE Handle, IP_VERSION_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetIpFilterRuleList					( SNC_HANDLE Handle, IP_VERSION_TYPE type, IpFilterRule **out, int *count );
SNC_ERROR	__stdcall	sncwSetIpFilterRuleList					( SNC_HANDLE Handle, IP_VERSION_TYPE type, const IpFilterRule *in, int count );
SNC_ERROR	__stdcall	sncwReleaseIpFilterRuleList				( SNC_HANDLE Handle, IpFilterRule **in );

SNC_ERROR   __stdcall   sncwGetIpFilterRuleSequenceList			( SNC_HANDLE Handle, IP_VERSION_TYPE type, unsigned int **out, int *count );	
SNC_ERROR   __stdcall   sncwSetIpFilterRuleSequenceList			( SNC_HANDLE Handle, IP_VERSION_TYPE type, const unsigned int *in, int count );
SNC_ERROR	__stdcall	sncwReleaseIpFilterRuleSequenceList		( SNC_HANDLE Handle, unsigned int **in );

// Camera Qos
SNC_ERROR   __stdcall   sncwGetIpMangleFunction					( SNC_HANDLE Handle, IP_VERSION_TYPE type, bool *out );
SNC_ERROR   __stdcall   sncwSetIpMangleFunction					( SNC_HANDLE Handle, IP_VERSION_TYPE type, bool in );

SNC_ERROR   __stdcall   sncwGetIpMangleRuleList					( SNC_HANDLE Handle, IP_VERSION_TYPE type, IpMangleRule **out, int *count );
SNC_ERROR   __stdcall   sncwSetIpMangleRuleList					( SNC_HANDLE Handle, IP_VERSION_TYPE type, const IpMangleRule *in, int count );
SNC_ERROR	__stdcall	sncwReleaseIpMangleRuleList				( SNC_HANDLE Handle, IpMangleRule **in );

SNC_ERROR   __stdcall   sncwGetIpMangleRuleSequenceList			( SNC_HANDLE Handle, IP_VERSION_TYPE type, unsigned int **out, int *count );	
SNC_ERROR   __stdcall   sncwSetIpMangleRuleSequenceList			( SNC_HANDLE Handle, IP_VERSION_TYPE type, const unsigned int *in, int count );
SNC_ERROR	__stdcall	sncwReleaseIpMangleRuleSequenceList		( SNC_HANDLE Handle, unsigned int **in );

// Camera Dynamic IP Address Notification
SNC_ERROR   __stdcall	sncwOptionsHttpIpNotifyMethod			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetHttpIpNotifyMethod				( SNC_HANDLE Handle, HTTP_METHOD *out );
SNC_ERROR   __stdcall	sncwSetHttpIpNotifyMethod				( SNC_HANDLE Handle, HTTP_METHOD in );

SNC_ERROR   __stdcall	sncwGetHttpIpNotifyService				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetHttpIpNotifyService				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall	sncwGetHttpIpNotifyUrl					( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetHttpIpNotifyUrl					( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR   __stdcall	sncwGetSmtpIpNotifyMessage				( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetSmtpIpNotifyMessage				( SNC_HANDLE Handle, const char *pBuf );

SNC_ERROR   __stdcall	sncwGetSmtpIpNotifyService				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall	sncwSetSmtpIpNotifyService				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall	sncwGetSmtpIpNotifySubject				( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwSetSmtpIpNotifySubject				( SNC_HANDLE Handle, const char *pBuf );

// Camera User
SNC_ERROR   __stdcall   sncwGetAdministrator					( SNC_HANDLE Handle, char *pBuf1, int bufLen1, int *outLen1, char *pBuf2, int bufLen2, int *outLen2 );
SNC_ERROR	__stdcall	sncwSetAdministrator					( SNC_HANDLE Handle, const char *in1, const char *in2 );

SNC_ERROR   __stdcall   sncwIdRangeUser							( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetUser								( SNC_HANDLE Handle, unsigned int id_User, char *pBuf1, int bufLen1, int *outLen1, char *pBuf2, int bufLen2, int *outLen2, char *pBuf3, int bufLen3, int *outLen3 );
SNC_ERROR   __stdcall   sncwSetUser								( SNC_HANDLE Handle, unsigned int id_User, const char *in1, const char *in2, const char *in3 );

SNC_ERROR   __stdcall   sncwGetUserNum                          ( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetViewerAuthentication				( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetViewerAuthentication				( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetViewerModeDefault				( SNC_HANDLE Handle, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall   sncwSetViewerModeDefault				( SNC_HANDLE Handle, const char *in );

// Other
SNC_ERROR   __stdcall   sncwSetCaptureFullImage					( SNC_HANDLE Handle );

SNC_ERROR	__stdcall	sncwOptionsDeleteRecall					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetDeleteRecall                     ( SNC_HANDLE Handle, DELETE_RECALL in );

SNC_ERROR   __stdcall   sncwOptionsDriverFormat					( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetDriverFormat						( SNC_HANDLE Handle, DRIVER_TYPE in );

SNC_ERROR   __stdcall	sncwSupportTypesDriverType				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall	sncwGetDriverFreeSpace					( SNC_HANDLE Handle, DRIVER_TYPE type, char *pBuf, int bufLen, int *outLen );
SNC_ERROR   __stdcall	sncwGetDriverWriteProtected			    ( SNC_HANDLE Handle, DRIVER_TYPE type, bool *out );

SNC_ERROR	__stdcall	sncwOptionsFactoryDefault				( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetFactoryDefault					( SNC_HANDLE Handle, FACTORY_DEFAULT in );

SNC_ERROR   __stdcall   sncwGetGmt                              ( SNC_HANDLE Handle, DateTime *out );
SNC_ERROR   __stdcall   sncwSetGmt                              ( SNC_HANDLE Handle, const DateTime & in );

SNC_ERROR   __stdcall   sncwGetLocalTime                        ( SNC_HANDLE Handle, DateTime *out );
SNC_ERROR   __stdcall   sncwSetLocalTime                        ( SNC_HANDLE Handle, const DateTime & in );

SNC_ERROR   __stdcall   sncwGetSensorStatus                     ( SNC_HANDLE Handle, unsigned int id_Sensor, bool *out );

SNC_ERROR   __stdcall   sncwOptionsSystemRecall	                ( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetSystemRecall		                ( SNC_HANDLE Handle, SYSTEM_RECALL in );

SNC_ERROR   __stdcall   sncwGetTimeZoneDiffGmt                  ( SNC_HANDLE Handle, const char *timezone, double *out );

SNC_ERROR   __stdcall   sncwSupportTypesTriggerAction			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwOptionsTriggerAction				( SNC_HANDLE Handle, TRIGGER_OUTPUT_TYPE type, unsigned int id, unsigned long *out );
SNC_ERROR   __stdcall   sncwSetTriggerAction					( SNC_HANDLE Handle, TRIGGER_OUTPUT_TYPE type, unsigned int id, TRIGGER_ACTION in);

SNC_ERROR   __stdcall   sncwOptionsTriggerRecall                ( SNC_HANDLE Handle, const char *const** names, int *count );
SNC_ERROR   __stdcall   sncwSetTriggerRecall                    ( SNC_HANDLE Handle, const char * name );

SNC_ERROR	__stdcall	sncwSupportTypesWeeklySchedule			( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWeeklySchedule					( SNC_HANDLE Handle, WEEKLY_SCHEDULE type, WeeklyScheduleTypeEx *out );
SNC_ERROR   __stdcall   sncwSetWeeklySchedule					( SNC_HANDLE Handle, WEEKLY_SCHEDULE type, const WeeklyScheduleTypeEx &in );

SNC_ERROR	__stdcall	sncwSupportTypesWeeklyScheduleEx		( SNC_HANDLE Handle, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetWeeklyScheduleEx					( SNC_HANDLE Handle, WEEKLY_SCHEDULE_EX type, unsigned int id, WeeklyScheduleTypeEx *out );
SNC_ERROR   __stdcall   sncwSetWeeklyScheduleEx					( SNC_HANDLE Handle, WEEKLY_SCHEDULE_EX type, unsigned int id, const WeeklyScheduleTypeEx &in );

// edge storage
SNC_ERROR   __stdcall   sncwGetEdgeStorageAlarmRecordingChannelWatchAddress     ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, IpAddress  *out);
SNC_ERROR   __stdcall   sncwSetEdgeStorageAlarmRecordingChannelWatchAddress     ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, const IpAddress  &in);

SNC_ERROR   __stdcall   sncwGetEdgeStorageAlarmRecordingChannelTime		        ( SNC_HANDLE Handle, unsigned int id_EdgeStorage,  unsigned int *pre_time,   unsigned int *post_time );
SNC_ERROR   __stdcall   sncwSetEdgeStorageAlarmRecordingChannelTime		        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage ,  unsigned int pre_time,   unsigned int post_time ) ;

SNC_ERROR	__stdcall	sncwOptionsEdgeStorageSupportedAlarm			        ( SNC_HANDLE Handle, unsigned int id_EdgeStorage, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEdgeStorageAlarmRecordingChannelTrigger	        ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, EDGE_STORAGE_SUPPORTED_ALARM   *out);
SNC_ERROR   __stdcall   sncwSetEdgeStorageAlarmRecordingChannelTrigger	        ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, EDGE_STORAGE_SUPPORTED_ALARM   in);

SNC_ERROR   __stdcall   sncwGetEdgeStorageAlarmRecordingMaximumTime		        ( SNC_HANDLE Handle, unsigned int id_Streaming ,  unsigned int *pre_time,   unsigned int *post_time );

SNC_ERROR   __stdcall   sncwGetEdgeStorageAlarmRecordingMaximumTimeAudio        ( SNC_HANDLE Handle, unsigned int *pre_time, unsigned int *post_time );

SNC_ERROR   __stdcall   sncwSetEdgeStorageDeleteAll						        ( SNC_HANDLE Handle);

SNC_ERROR   __stdcall   sncwSetEdgeStorageDeleteByName			                ( SNC_HANDLE Handle, const char * in );

SNC_ERROR   __stdcall   sncwGetEdgeStorageFunction						        ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetEdgeStorageFunction						        ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwGetEdgeStorageOverwrite						        ( SNC_HANDLE Handle, bool *out );
SNC_ERROR   __stdcall   sncwSetEdgeStorageOverwrite						        ( SNC_HANDLE Handle, bool in );

SNC_ERROR   __stdcall   sncwIdRangeEdgeStorageRecordingChannel			        ( SNC_HANDLE Handle,RangeUint *out );
SNC_ERROR   __stdcall   sncwGetEdgeStorageRecordingChannel				        ( SNC_HANDLE Handle, unsigned int id_EdgeStorage ,  unsigned int *id_Streaming,   bool *audio );
SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannel				        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage , unsigned int id_Streaming,   bool audio ) ;

SNC_ERROR   __stdcall   sncwGetEdgeStorageRecordingChannelFunction		        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, bool *out  );
SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannelFunction		        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, bool in  );

SNC_ERROR	__stdcall	sncwOptionsEdgeStorageRecordingChannelMode		        ( SNC_HANDLE Handle, unsigned int id_EdgeStorage, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEdgeStorageRecordingChannelMode			        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, RECORDING_MODE *out  );
SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannelMode			        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, RECORDING_MODE in  );

SNC_ERROR	__stdcall	sncwOptionsEdgeStorageRecordingChannelPeriodMode        ( SNC_HANDLE Handle, unsigned int id_EdgeStorage, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEdgeStorageRecordingChannelPeriodMode            ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, PERIOD_MODE  *out  );
SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannelPeriodMode            ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, PERIOD_MODE  in  );

SNC_ERROR   __stdcall   sncwGetEdgeStorageRecordingChannelSchedule		        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, WeeklyScheduleType *out  );
SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannelSchedule		        ( SNC_HANDLE Handle,unsigned int id_EdgeStorage, const WeeklyScheduleType &in  );

SNC_ERROR   __stdcall   sncwGetEdgeStorageRecordingChannelStatus		        ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, bool *out);

SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannelStart			        ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage);
SNC_ERROR   __stdcall   sncwSetEdgeStorageRecordingChannelStop			        ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage);

SNC_ERROR	__stdcall	sncwOptionsEdgeStorageRtspRecordingChannelTimeout       ( SNC_HANDLE Handle, unsigned int id_EdgeStorage, RangeUint *out );
SNC_ERROR   __stdcall   sncwGetEdgeStorageRtspRecordingChannelTimeout           ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, unsigned int  *out);
SNC_ERROR   __stdcall   sncwSetEdgeStorageRtspRecordingChannelTimeout           ( SNC_HANDLE Handle,  unsigned int id_EdgeStorage, unsigned int  in);

SNC_ERROR	__stdcall	sncwIdRangeEventConfigCondition							( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR	__stdcall	sncwOptionsEventConfigCondition					        ( SNC_HANDLE Handle, unsigned int id_EventConfigCondition, unsigned long *out );
SNC_ERROR   __stdcall   sncwGetEventConfigCondition						        ( SNC_HANDLE Handle, unsigned int id_EventConfigCondition, CONDITION *out1, EDGE_STORAGE_SUPPORTED_ALARM * out2, EDGE_STORAGE_SUPPORTED_ALARM  * out3, unsigned int * out4);
SNC_ERROR   __stdcall   sncwSetEventConfigCondition						        ( SNC_HANDLE Handle, unsigned int id_EventConfigCondition, CONDITION in1, EDGE_STORAGE_SUPPORTED_ALARM in2, EDGE_STORAGE_SUPPORTED_ALARM  in3, unsigned int in4);

// Capability File Operation
SNC_ERROR	__stdcall	sncwCapabilityImportFile                        ( const char *path, const char *model_name, const char *version );
SNC_ERROR	__stdcall	sncwCapabilityRemoveFile                        ( const char *model_name, const char *version );
SNC_ERROR   __stdcall   sncwGetSupportedCapsModelList	                ( CameraInfo** out, int* count );
SNC_ERROR	__stdcall	sncwReleaseSupportedCapsModelList			    ( CameraInfo** in );

// Configurable Information
SNC_ERROR   __stdcall   sncwGetConfigurableCBR                          ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetConfigurableCodecProfile                 ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned long *out );

SNC_ERROR   __stdcall   sncwGetConfigurableFrameRateList                ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwReleaseConfigurableFrameRateList            ( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwGetConfigurableImageCodec                   ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned long *out );

SNC_ERROR   __stdcall   sncwGetConfigurableImageSizeList                ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, ImageSizeType **out, int *count );
SNC_ERROR   __stdcall   sncwReleaseConfigurableImageSizeList            ( SNC_HANDLE Handle, ImageSizeType **in );

SNC_ERROR   __stdcall   sncwGetConfigurableMaxBitRate                   ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetConfigurableMaxH264Quality               ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetConfigurableMinAutoRateControlBitrateList( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwReleaseConfigurableMinAutoRateControlBitrateList( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwGetConfigurableMaxAutoRateControlBitrateList( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwReleaseConfigurableMaxAutoRateControlBitrateList( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR   __stdcall   sncwGetConfigurableMaxIFrameInterval            ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int *out );

SNC_ERROR   __stdcall   sncwGetConfigurableMaxQuality                   ( SNC_HANDLE Handle, unsigned int id_Streaming, const ConfigurableVideoInfo& info, unsigned int *out );

// Privacy Information
SNC_ERROR	__stdcall	sncwGetPrivacyMaskColorType                     ( SNC_HANDLE Handle, PrivacyMaskColorType *out );
SNC_ERROR	__stdcall	sncwSetPrivacyMaskColorType                     ( SNC_HANDLE Handle, const PrivacyMaskColorType & in );

SNC_ERROR   __stdcall   sncwSetPrivacyMaskEnable                        ( SNC_HANDLE Handle, unsigned int index, bool in );

SNC_ERROR   __stdcall   sncwGetPrivacyMaskEnableList                    ( SNC_HANDLE Handle, unsigned int **out, int *count );
SNC_ERROR   __stdcall   sncwSetPrivacyMaskEnableList                    ( SNC_HANDLE Handle, const unsigned int *in, int count );
SNC_ERROR	__stdcall	sncwReleasePrivacyMaskEnableList                ( SNC_HANDLE Handle, unsigned int **in );

SNC_ERROR	__stdcall	sncwGetPrivacyMaskMaxNum                        ( SNC_HANDLE Handle, unsigned int *out );

SNC_ERROR	__stdcall	sncwGetPrivacyMaskPosition                      ( SNC_HANDLE Handle, unsigned int id_Privacy, PrivacyMaskPosition *out );
SNC_ERROR	__stdcall	sncwSetPrivacyMaskPosition                      ( SNC_HANDLE Handle, unsigned int id_Privacy, const PrivacyMaskPosition & in );

SNC_ERROR	__stdcall	sncwIdRangePrivacy								( SNC_HANDLE Handle, RangeUint *out );
SNC_ERROR	__stdcall	sncwOptionsPrivacyWidthRange					( SNC_HANDLE Handle, unsigned int id_Privacy, RangeUint *width );
SNC_ERROR	__stdcall	sncwOptionsPrivacyHeightRange					( SNC_HANDLE Handle, unsigned int id_Privacy, RangeUint *height );
// end added
#endif // !_SNCCGIWRAPPERLIB_H_
