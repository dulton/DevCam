//
//	SncCGIWrapperLibDefineEnum.h - enum definitions.
//
//	Copyright (c) Sony Corporation. All rights reserved.
//

#ifndef	_SNCCGIWRAPPERLIBDEFINEENUM_H_
#define	_SNCCGIWRAPPERLIBDEFINEENUM_H_

namespace SNC
{

// enum definition

enum ALARM_OUTPUT_TYPE
{
    ALARM_OUTPUT_TYPE_alarm_out_1,
    ALARM_OUTPUT_TYPE_alarm_out_2,
    ALARM_OUTPUT_TYPE_alarm_out_3,
    ALARM_OUTPUT_TYPE_alarm_out_4,
    ALARM_OUTPUT_TYPE_voice_alert_1,
    ALARM_OUTPUT_TYPE_voice_alert_2,
    ALARM_OUTPUT_TYPE_voice_alert_3,
    ALARM_OUTPUT_TYPE_ftp_client,
    ALARM_OUTPUT_TYPE_smtp,
    ALARM_OUTPUT_TYPE_image_memory,
    ALARM_OUTPUT_TYPE_edge_storage
};

enum ALARM_TRIGGER_MODE
{
    ALARM_TRIGGER_MODE_sensor,
    ALARM_TRIGGER_MODE_timer,
    ALARM_TRIGGER_MODE_sync_day_night
};

enum ANALOG_VIDEO_STANDARD_TYPE
{
    ANALOG_VIDEO_STANDARD_TYPE_pal,
    ANALOG_VIDEO_STANDARD_TYPE_ntsc,
    ANALOG_VIDEO_STANDARD_TYPE_novideo
};

enum ASPECT_RATIO_CONVERSION
{
    ASPECT_RATIO_CONVERSION_squeeze,
    ASPECT_RATIO_CONVERSION_letterbox
};

enum AUDIO_CODEC
{
    AUDIO_CODEC_g711_64,
    AUDIO_CODEC_g726_40,
    AUDIO_CODEC_g726_32,
    AUDIO_CODEC_g726_24,
    AUDIO_CODEC_g726_16,
    AUDIO_CODEC_aac16_64,
    AUDIO_CODEC_aac48_128
};

enum AUDIO_DETECTION_SENSITIVITY
{
    AUDIO_DETECTION_SENSITIVITY_low,
    AUDIO_DETECTION_SENSITIVITY_high,
    AUDIO_DETECTION_SENSITIVITY_manual
};

enum AUDIO_DETECTION_TYPE
{
    AUDIO_DETECTION_TYPE_ftp_client_alarm,
    AUDIO_DETECTION_TYPE_smtp_alarm,
    AUDIO_DETECTION_TYPE_alarm_out_1_alarm,
    AUDIO_DETECTION_TYPE_alarm_out_2_alarm,
    AUDIO_DETECTION_TYPE_alarm_out_3_alarm,
    AUDIO_DETECTION_TYPE_alarm_out_4_alarm,
    AUDIO_DETECTION_TYPE_image_memory_alarm,
    AUDIO_DETECTION_TYPE_voice_alert_1_alarm,
    AUDIO_DETECTION_TYPE_voice_alert_2_alarm,
    AUDIO_DETECTION_TYPE_voice_alert_3_alarm,
    AUDIO_DETECTION_TYPE_audio_detection
};

enum AUDIO_IN_SOURCE
{
    AUDIO_IN_SOURCE_mic,
    AUDIO_IN_SOURCE_line
};

enum AUTO_FLIP
{
    AUTO_FLIP_on,
    AUTO_FLIP_off,
    AUTO_FLIP_0,
    AUTO_FLIP_250,
    AUTO_FLIP_500,
    AUTO_FLIP_750
};

enum AUTO_FLIP_MODE
{
    AUTO_FLIP_MODE_mechaflip,
    AUTO_FLIP_MODE_eflip
};

enum BACKUP_FTP_PERIOD_MODE
{
    BACKUP_FTP_PERIOD_MODE_always,
    BACKUP_FTP_PERIOD_MODE_sensor1
};

enum BACKUP_FTP_SUFFIX
{
    BACKUP_FTP_SUFFIX_date,
    BACKUP_FTP_SUFFIX_sequence
};

enum CAMERA_CONTROL_INTERFACE
{
    CAMERA_CONTROL_INTERFACE_serial,
    CAMERA_CONTROL_INTERFACE_coaxitron
};

enum CAMERA_ID_TYPE
{
    CAMERA_ID_TYPE_serial_destination,
    CAMERA_ID_TYPE_serial_source
};

enum COLOR_MODE_TYPE
{
    COLOR_MODE_TYPE_color,
    COLOR_MODE_TYPE_black_and_white
};

enum COMMAND_TIMEOUT_TYPE
{
    COMMAND_TIMEOUT_TYPE_normal,
    COMMAND_TIMEOUT_TYPE_no_reply
};
    
enum COMMON_COLOR
{
    COMMON_COLOR_black,
    COMMON_COLOR_gray1,
    COMMON_COLOR_gray2,
    COMMON_COLOR_gray3,
    COMMON_COLOR_gray4,
    COMMON_COLOR_gray5,
    COMMON_COLOR_gray6,
    COMMON_COLOR_white,
    COMMON_COLOR_red,
    COMMON_COLOR_green,
    COMMON_COLOR_blue,
    COMMON_COLOR_cyan,
    COMMON_COLOR_yellow,
    COMMON_COLOR_magenta
};

enum CONDITION
{
    CONDITION_none,
    CONDITION_and,
    CONDITION_or,
    CONDITION_then
};

enum CONFIGURABLE_PARAMETER
{
    CONFIGURABLE_PARAMETER_codec,
    CONFIGURABLE_PARAMETER_imagesize,
    CONFIGURABLE_PARAMETER_framerate,
    CONFIGURABLE_PARAMETER_bitrate,
    CONFIGURABLE_PARAMETER_quality,
    CONFIGURABLE_PARAMETER_profile,
	CONFIGURABLE_PARAMETER_cbr,
	CONFIGURABLE_PARAMETER_iframe_interval,
	CONFIGURABLE_PARAMETER_h264_quality,
	CONFIGURABLE_PARAMETER_auto_rate_control_bitrate_min,
	CONFIGURABLE_PARAMETER_auto_rate_control_bitrate_max
};

enum DATE_FORMAT
{
    DATE_FORMAT_ymd,
    DATE_FORMAT_mdy,
    DATE_FORMAT_dmy
};

enum DAY_NIGHT_MODE
{
    DAY_NIGHT_MODE_disable,
    DAY_NIGHT_MODE_auto,
    DAY_NIGHT_MODE_manual,
    DAY_NIGHT_MODE_timer,
    DAY_NIGHT_MODE_sensor
};

enum DAY_NIGHT_THRESHOLD_LEVEL
{
    DAY_NIGHT_THRESHOLD_LEVEL_low,
    DAY_NIGHT_THRESHOLD_LEVEL_high
};

enum DEFAULT_HOMEPAGE_MODE
{
    DEFAULT_HOMEPAGE_MODE_default,
    DEFAULT_HOMEPAGE_MODE_userset,
    DEFAULT_HOMEPAGE_MODE_custom
};

enum DELETE_RECALL
{
    DELETE_RECALL_homepage,
    DELETE_RECALL_voice_alert,
    DELETE_RECALL_voice_alert_1,
    DELETE_RECALL_voice_alert_2,
    DELETE_RECALL_voice_alert_3,
    DELETE_RECALL_log,
    DELETE_RECALL_panorama,
    DELETE_RECALL_round_panorama,
    DELETE_RECALL_overview_image
};

enum DETECTION_TYPE
{
    DETECTION_TYPE_ftp_client,
    DETECTION_TYPE_smtp,
    DETECTION_TYPE_image_memory,
    DETECTION_TYPE_alarm_out_1,
    DETECTION_TYPE_alarm_out_2,
    DETECTION_TYPE_alarm_out_3,
    DETECTION_TYPE_alarm_out_4,
    DETECTION_TYPE_voice_alert_1,
    DETECTION_TYPE_voice_alert_2,
    DETECTION_TYPE_voice_alert_3,
    DETECTION_TYPE_smtp_emergency_fan_detect,
    DETECTION_TYPE_smtp_emergency_video_detect,
    DETECTION_TYPE_smtp_emergency_power_detect,
    DETECTION_TYPE_smtp_emergency_memory_card_detect
};

enum DIGITAL_GAIN
{
    DIGITAL_GAIN_high,
    DIGITAL_GAIN_mid,
    DIGITAL_GAIN_low,
	DIGITAL_GAIN_on,
    DIGITAL_GAIN_off
};

enum DOT1X_EAP_METHOD
{
    DOT1X_EAP_METHOD_tls,
    DOT1X_EAP_METHOD_ttls,
    DOT1X_EAP_METHOD_peap,
    DOT1X_EAP_METHOD_leap,
    DOT1X_EAP_METHOD_md5
};

enum DOT1X_NETWORK_STATUS
{
    DOT1X_NETWORK_STATUS_wired,
    DOT1X_NETWORK_STATUS_wireless
};

enum DOT1X_TLS_MODE
{
    DOT1X_TLS_MODE_normal,
    DOT1X_TLS_MODE_csr
};

enum DRIVER_TYPE
{
    DRIVER_TYPE_a_slot,
    DRIVER_TYPE_b_slot,
    DRIVER_TYPE_builtin
};

enum EDGE_STORAGE_SUPPORTED_ALARM
{
    EDGE_STORAGE_SUPPORTED_ALARM_none,
    EDGE_STORAGE_SUPPORTED_ALARM_sensor1,
    EDGE_STORAGE_SUPPORTED_ALARM_sensor2,
    EDGE_STORAGE_SUPPORTED_ALARM_sensor3,
    EDGE_STORAGE_SUPPORTED_ALARM_sensor4,
    EDGE_STORAGE_SUPPORTED_ALARM_disconnected,
    EDGE_STORAGE_SUPPORTED_ALARM_vmf,
    EDGE_STORAGE_SUPPORTED_ALARM_detection,
    EDGE_STORAGE_SUPPORTED_ALARM_tampering,
    EDGE_STORAGE_SUPPORTED_ALARM_audio,
    EDGE_STORAGE_SUPPORTED_ALARM_condition1,
    EDGE_STORAGE_SUPPORTED_ALARM_condition2,
	EDGE_STORAGE_SUPPORTED_ALARM_condition3,
	EDGE_STORAGE_SUPPORTED_ALARM_condition4,
	EDGE_STORAGE_SUPPORTED_ALARM_condition5,
	EDGE_STORAGE_SUPPORTED_ALARM_condition6,
	EDGE_STORAGE_SUPPORTED_ALARM_condition7,
	EDGE_STORAGE_SUPPORTED_ALARM_condition8,
	EDGE_STORAGE_SUPPORTED_ALARM_condition9,
	EDGE_STORAGE_SUPPORTED_ALARM_condition10,
	EDGE_STORAGE_SUPPORTED_ALARM_vmd,
	EDGE_STORAGE_SUPPORTED_ALARM_presencesensor,
	EDGE_STORAGE_SUPPORTED_ALARM_facedetection
};

enum EMAIL_ADDRESS_TYPE
{
    EMAIL_ADDRESS_TYPE_smtp_ip_notify_recpt,
    EMAIL_ADDRESS_TYPE_smtp_ip_notify_from,
    EMAIL_ADDRESS_TYPE_backup_ftp_client_recpt,
    EMAIL_ADDRESS_TYPE_backup_ftp_client_from,
    EMAIL_ADDRESS_TYPE_smtp_recpt_1,
    EMAIL_ADDRESS_TYPE_smtp_recpt_2,
    EMAIL_ADDRESS_TYPE_smtp_recpt_3,
    EMAIL_ADDRESS_TYPE_smtp_admin,
    EMAIL_ADDRESS_TYPE_image_memory_recpt,
    EMAIL_ADDRESS_TYPE_image_memory_from,
    EMAIL_ADDRESS_TYPE_smtp_emergency_recpt,
    EMAIL_ADDRESS_TYPE_smtp_emergency_admin
};

enum EMERGENCY_TYPE
{
    EMERGENCY_TYPE_smtp_alarm
};

enum ETHERNET_DUPLEX_MODE
{
    ETHERNET_DUPLEX_MODE_full,
    ETHERNET_DUPLEX_MODE_half
};

enum ETHERNET_MDI_MODE
{
    ETHERNET_MDI_MODE_mdi,
    ETHERNET_MDI_MODE_mdi_x,
    ETHERNET_MDI_MODE_mdi_auto
};

enum ETHERNET_MDI_STATUS
{
    ETHERNET_MDI_STATUS_mdi,
    ETHERNET_MDI_STATUS_mdi_x,
    ETHERNET_MDI_STATUS_sloc
};

enum ETHERNET_SPEED
{
    ETHERNET_SPEED_10,
    ETHERNET_SPEED_100
};

enum ETHERNET_STATUS
{
    ETHERNET_STATUS_100full,
    ETHERNET_STATUS_100half,
    ETHERNET_STATUS_10full,
    ETHERNET_STATUS_10half,
    ETHERNET_STATUS_sloc
};

enum EVENT_TYPE
{
    EVENT_TYPE_sensor1,
    EVENT_TYPE_sensor2,
    EVENT_TYPE_sensor3,
    EVENT_TYPE_sensor4,
    EVENT_TYPE_tampering,
    EVENT_TYPE_vmf,
    EVENT_TYPE_motion_detection,
    EVENT_TYPE_audio_detection
};

enum EXPOSURE_MODE_TYPE
{
    EXPOSURE_MODE_TYPE_full,
    EXPOSURE_MODE_TYPE_shutter,
    EXPOSURE_MODE_TYPE_iris,
    EXPOSURE_MODE_TYPE_manual,
    EXPOSURE_MODE_TYPE_auto_iris_lens,
    EXPOSURE_MODE_TYPE_manual_iris_lens,
    EXPOSURE_MODE_TYPE_manual_iris_lens2
};

enum FACTORY_DEFAULT
{
    FACTORY_DEFAULT_soft,
    FACTORY_DEFAULT_hard
};

enum FAN_MODE
{
    FAN_MODE_auto,
    FAN_MODE_on,
    FAN_MODE_off
};

enum FOCUS_MODE_TYPE
{
    FOCUS_MODE_TYPE_auto,
    FOCUS_MODE_TYPE_manual
};

enum FOCUS_TYPE
{
    FOCUS_TYPE_near,
    FOCUS_TYPE_far,
    FOCUS_TYPE_auto_focus
};

enum FTP_CLIENT_FILE_EXIST_RULE
{
    FTP_CLIENT_FILE_EXIST_RULE_overwrite,
    FTP_CLIENT_FILE_EXIST_RULE_rename
};

enum HEATER_MODE
{
    HEATER_MODE_auto,
    HEATER_MODE_on,
    HEATER_MODE_off
};

enum HOME_POSITION_OPERATION_TYPE
{
    HOME_POSITION_OPERATION_TYPE_set,
    HOME_POSITION_OPERATION_TYPE_reset,
    HOME_POSITION_OPERATION_TYPE_recall,
    HOME_POSITION_OPERATION_TYPE_ptz_recall
};

enum HTTP_METHOD
{
    HTTP_METHOD_get,
    HTTP_METHOD_post
};

enum IMAGE_CODEC
{
    IMAGE_CODEC_jpeg,
    IMAGE_CODEC_mpeg4,
    IMAGE_CODEC_h264,
    IMAGE_CODEC_jpeg_mpeg4,
    IMAGE_CODEC_mpeg4_jpeg,
    IMAGE_CODEC_jpeg_h264,
    IMAGE_CODEC_h264_jpeg,
    IMAGE_CODEC_mpeg4_h264,
    IMAGE_CODEC_h264_mpeg4,
    IMAGE_CODEC_off
};

enum IMAGE_CODEC_INSTANCE
{
    IMAGE_CODEC_INSTANCE_off,
    IMAGE_CODEC_INSTANCE_image1,
    IMAGE_CODEC_INSTANCE_image2,
    IMAGE_CODEC_INSTANCE_image3
};

enum IMAGE_CODEC_TYPE
{
    IMAGE_CODEC_TYPE_jpeg,
    IMAGE_CODEC_TYPE_mpeg4,
    IMAGE_CODEC_TYPE_h264
};

enum INTERVAL_TYPE
{
    INTERVAL_TYPE_backup_ftp_client_send,
    INTERVAL_TYPE_backup_ftp_client_record,
    INTERVAL_TYPE_backup_ftp_client_retry,
    INTERVAL_TYPE_move_pan_tilt_zoom_ex,
    INTERVAL_TYPE_ssl_key_change,
    INTERVAL_TYPE_ntp,
    INTERVAL_TYPE_smtp_emergency
};

enum IP_FILTER_RULE_POLICY
{
    IP_FILTER_RULE_POLICY_allow,
    IP_FILTER_RULE_POLICY_deny
};

enum IP_LIMIT_POLICY
{
    IP_LIMIT_POLICY_allow,
    IP_LIMIT_POLICY_deny
};

enum IP_VERSION_TYPE
{
    IP_VERSION_TYPE_ipv4,
    IP_VERSION_TYPE_ipv6
};

enum LED_TYPE
{
    LED_TYPE_power,
    LED_TYPE_network
};

enum LIGHT_FUNNEL_MODE
{
    LIGHT_FUNNEL_MODE_sync_with_day_night,
    LIGHT_FUNNEL_MODE_auto,
    LIGHT_FUNNEL_MODE_manual,
    LIGHT_FUNNEL_MODE_timer
};

enum LIGHT_FUNNEL_THRESHOLD_LEVEL
{
    LIGHT_FUNNEL_THRESHOLD_LEVEL_low,
    LIGHT_FUNNEL_THRESHOLD_LEVEL_high
};

enum MAX_GAIN_LEVEL
{
    MAX_GAIN_LEVEL_low,
    MAX_GAIN_LEVEL_mid,
    MAX_GAIN_LEVEL_high
};

enum MEMORY_TYPE
{
    MEMORY_TYPE_ata_memory_card,
    MEMORY_TYPE_memory_stick,
    MEMORY_TYPE_cf_memory_card,
    MEMORY_TYPE_usb_memory,
    MEMORY_TYPE_sd_card
};

enum MODEL_FORM
{
	MODEL_FORM_box,
	MODEL_FORM_box_bullet,
	MODEL_FORM_dome,
	MODEL_FORM_dome_vandal,
	MODEL_FORM_ptz,
	MODEL_FORM_rpd,
	MODEL_FORM_rpd_vandal
};

enum MOVE_DIRECTION
{
    MOVE_DIRECTION_left_up,
    MOVE_DIRECTION_up,
    MOVE_DIRECTION_right_up,
    MOVE_DIRECTION_right,
    MOVE_DIRECTION_right_down,
    MOVE_DIRECTION_down,
    MOVE_DIRECTION_left_down,
    MOVE_DIRECTION_left,
    MOVE_DIRECTION_zoom_wide,
    MOVE_DIRECTION_zoom_tele
};

enum MOVE_TYPE
{
    MOVE_TYPE_pan_tilt,
    MOVE_TYPE_zoom,
    MOVE_TYPE_focus,
    MOVE_TYPE_all
};

enum NETWORK_DIAGNOSIS_MODE
{
    NETWORK_DIAGNOSIS_MODE_tcp,
    NETWORK_DIAGNOSIS_MODE_udp,
    NETWORK_DIAGNOSIS_MODE_multicast
};

enum NETWORK_TYPE
{
    NETWORK_TYPE_wired,
    NETWORK_TYPE_wireless,
    NETWORK_TYPE_ipv6_wired,
    NETWORK_TYPE_ipv6_wireless
};

enum NTP_SERVER_ADDRESS_MODE
{
    NTP_SERVER_ADDRESS_MODE_manual_set,
    NTP_SERVER_ADDRESS_MODE_dhcp_through,
    NTP_SERVER_ADDRESS_MODE_multicast_address_use
};

enum OUTPUT_PERIODICAL_MODE
{
    OUTPUT_PERIODICAL_MODE_period,
    OUTPUT_PERIODICAL_MODE_sync_tour
};

enum OUTPUT_SUFFIX_MODE
{
    OUTPUT_SUFFIX_MODE_none,
    OUTPUT_SUFFIX_MODE_date,
    OUTPUT_SUFFIX_MODE_sequence_number
};

enum OUTPUT_TYPE
{
    OUTPUT_TYPE_ftp_client,
    OUTPUT_TYPE_smtp,
    OUTPUT_TYPE_image_memory,
    OUTPUT_TYPE_smtp_alarm_tampering
};

enum PERIOD_MODE
{
    PERIOD_MODE_always,
    PERIOD_MODE_schedule
};

enum POP_MODE
{
    POP_MODE_pop3,
    POP_MODE_apop
};

enum PORT_TYPE
{
    PORT_TYPE_http,
    PORT_TYPE_multi_cast_video,
    PORT_TYPE_multi_cast_video_1,
    PORT_TYPE_multi_cast_video_2,
    PORT_TYPE_multi_cast_video_3,
    PORT_TYPE_multi_cast_audio,
    PORT_TYPE_uni_cast_video,
    PORT_TYPE_uni_cast_video_1,
    PORT_TYPE_uni_cast_video_2,
    PORT_TYPE_uni_cast_video_3,
    PORT_TYPE_uni_cast_audio,
    PORT_TYPE_smtp,
    PORT_TYPE_pop,
    PORT_TYPE_https,
    PORT_TYPE_serial_tcp,
    PORT_TYPE_http_ip_notify_proxy,
    PORT_TYPE_rtsp_mc_video_port_1,
    PORT_TYPE_rtsp_mc_video_port_2,
    PORT_TYPE_rtsp_mc_video_port_3,
    PORT_TYPE_rtsp_mc_audio_port,
    PORT_TYPE_rtsp_uc_video_port_1,
    PORT_TYPE_rtsp_uc_video_port_2,
    PORT_TYPE_rtsp_uc_video_port_3,
    PORT_TYPE_rtsp_uc_audio_port,
    PORT_TYPE_rtsp
};

enum PRIVACY_MASK_ATTRIBUTE
{
    PRIVACY_MASK_ATTRIBUTE_opaque,
    PRIVACY_MASK_ATTRIBUTE_mosaic,
    PRIVACY_MASK_ATTRIBUTE_transmittance
};

enum PROFILE_TYPE
{
    PROFILE_TYPE_baseline,
    PROFILE_TYPE_main,
    PROFILE_TYPE_high
};

enum PROTOCOL_TYPE
{
    PROTOCOL_TYPE_udp,
    PROTOCOL_TYPE_tcp,
    PROTOCOL_TYPE_all
};

enum PTZF_MODE
{
    PTZF_MODE_normal,
    PTZF_MODE_step
};

enum RECORDING_MODE
{
    RECORDING_MODE_always,
    RECORDING_MODE_alarm
};

enum SECURITY_TYPE
{
    SECURITY_TYPE_ssl,
    SECURITY_TYPE_dot1x
};

enum SERIAL_PARITY_BIT
{
    SERIAL_PARITY_BIT_none,
    SERIAL_PARITY_BIT_odd,
    SERIAL_PARITY_BIT_even
};

enum SERIAL_PROTOCOL
{
    SERIAL_PROTOCOL_pelco_d,
    SERIAL_PROTOCOL_ad,
    SERIAL_PROTOCOL_pelco_p,
    SERIAL_PROTOCOL_bosch,
    SERIAL_PROTOCOL_vicon,
    SERIAL_PROTOCOL_panasonic,
    SERIAL_PROTOCOL_ge,
    SERIAL_PROTOCOL_visca
};

enum SERIAL_STANDARD_TYPE
{
    SERIAL_STANDARD_TYPE_rs232c,
    SERIAL_STANDARD_TYPE_rs485,
    SERIAL_STANDARD_TYPE_rs422
};

enum SERIAL_TYPE
{
    SERIAL_TYPE_tcpip,
    SERIAL_TYPE_visca,
    SERIAL_TYPE_pelco_d,
    SERIAL_TYPE_normal
};

enum SERVER_TYPE
{
    SERVER_TYPE_smtp,
    SERVER_TYPE_ntp_1,
    SERVER_TYPE_ntp_2,
    SERVER_TYPE_ntp_3,
    SERVER_TYPE_ftp_client,
    SERVER_TYPE_image_memory,
    SERVER_TYPE_smtp_auth_pop,
    SERVER_TYPE_http_ip_notify_proxy
};

enum SMTP_AUTHENTICATION_METHOD
{
    SMTP_AUTHENTICATION_METHOD_login,
    SMTP_AUTHENTICATION_METHOD_md5
};

enum SMTP_AUTHENTICATION_MODE
{
    SMTP_AUTHENTICATION_MODE_none,
    SMTP_AUTHENTICATION_MODE_smtp,
    SMTP_AUTHENTICATION_MODE_pop,
    SMTP_AUTHENTICATION_MODE_smtp_pop
};

enum SOLID_PAN_TILT_ZOOM_MODE
{
    SOLID_PAN_TILT_ZOOM_MODE_resolution,
    SOLID_PAN_TILT_ZOOM_MODE_framerate
};


enum SRC_FRAME_RATE
{
    SRC_FRAME_RATE_x1,
    SRC_FRAME_RATE_x2
};

enum SSL_CERTIFICATE_MODE
{
    SSL_CERTIFICATE_MODE_pki,
    SSL_CERTIFICATE_MODE_normal,
    SSL_CERTIFICATE_MODE_csr,
    SSL_CERTIFICATE_MODE_auto
};

enum SSL_MODE
{
    SSL_MODE_plain,
    SSL_MODE_ssl,
    SSL_MODE_plain_ssl,
    SSL_MODE_ssl_plain
};

enum SSL_PROTOCOL
{
    SSL_PROTOCOL_ssl_v23,
    SSL_PROTOCOL_ssl_v3,
    SSL_PROTOCOL_tls_v1,
    SSL_PROTOCOL_tls_v10
};

enum STILL_IMAGE_SEND_TYPE
{
    STILL_IMAGE_SEND_TYPE_ftp_client_alarm,
    STILL_IMAGE_SEND_TYPE_ftp_client_period,
    STILL_IMAGE_SEND_TYPE_smtp_alarm,
    STILL_IMAGE_SEND_TYPE_smtp_period
};

enum SUPERIMPOSE_AZIMUTH_MODE
{
    SUPERIMPOSE_AZIMUTH_MODE_off,
    SUPERIMPOSE_AZIMUTH_MODE_four_direction,
    SUPERIMPOSE_AZIMUTH_MODE_eight_direction
};

enum SUPERIMPOSE_COLOR_PATTERN
{
    SUPERIMPOSE_COLOR_PATTERN_white,
    SUPERIMPOSE_COLOR_PATTERN_black,
    SUPERIMPOSE_COLOR_PATTERN_white_with_black_border,
    SUPERIMPOSE_COLOR_PATTERN_black_with_white_border,
    SUPERIMPOSE_COLOR_PATTERN_white_with_black_background,
    SUPERIMPOSE_COLOR_PATTERN_black_with_white_background,
    SUPERIMPOSE_COLOR_PATTERN_white_with_transparent_background
};

enum SUPERIMPOSE_DIRECTION_MODE
{
    SUPERIMPOSE_DIRECTION_MODE_azimuth,
    SUPERIMPOSE_DIRECTION_MODE_areatitling
};

enum SUPERIMPOSE_FONT_SIZE
{
    SUPERIMPOSE_FONT_SIZE_small,
    SUPERIMPOSE_FONT_SIZE_large,
    SUPERIMPOSE_FONT_SIZE_middle
};

enum SUPERIMPOSE_MODE
{
    SUPERIMPOSE_MODE_text,
    SUPERIMPOSE_MODE_time,
    SUPERIMPOSE_MODE_text_and_time,
    SUPERIMPOSE_MODE_custom,
    SUPERIMPOSE_MODE_off
};

enum SUPERIMPOSE_POSITION
{
    SUPERIMPOSE_POSITION_left_top,
    SUPERIMPOSE_POSITION_middle_top,
    SUPERIMPOSE_POSITION_right_top,
    SUPERIMPOSE_POSITION_left_center,
    SUPERIMPOSE_POSITION_middle_center,
    SUPERIMPOSE_POSITION_right_center,
    SUPERIMPOSE_POSITION_left_bottom,
    SUPERIMPOSE_POSITION_middle_bottom,
    SUPERIMPOSE_POSITION_right_bottom
};

enum SUPERIMPOSE_TAG_TYPE
{
    SUPERIMPOSE_TAG_TYPE_camera_id,
    SUPERIMPOSE_TAG_TYPE_zoom_ratio,
    SUPERIMPOSE_TAG_TYPE_codec_info,
    SUPERIMPOSE_TAG_TYPE_event,
    SUPERIMPOSE_TAG_TYPE_direction,
    SUPERIMPOSE_TAG_TYPE_date,
    SUPERIMPOSE_TAG_TYPE_string
};

enum SUPERIMPOSE_WORD_COLOR
{
    SUPERIMPOSE_WORD_COLOR_black,
    SUPERIMPOSE_WORD_COLOR_blue,
    SUPERIMPOSE_WORD_COLOR_red,
    SUPERIMPOSE_WORD_COLOR_magenta,
    SUPERIMPOSE_WORD_COLOR_green,
    SUPERIMPOSE_WORD_COLOR_cyan,
    SUPERIMPOSE_WORD_COLOR_yellow,
    SUPERIMPOSE_WORD_COLOR_white
};

enum SUPERIMPOSE_WORD_EFFECT
{
    SUPERIMPOSE_WORD_EFFECT_outline,
    SUPERIMPOSE_WORD_EFFECT_transparent,
    SUPERIMPOSE_WORD_EFFECT_half_transparent_white,
    SUPERIMPOSE_WORD_EFFECT_half_transparent_black,
    SUPERIMPOSE_WORD_EFFECT_white,
    SUPERIMPOSE_WORD_EFFECT_black
};

enum SYSTEM_RECALL
{
    SYSTEM_RECALL_reboot,
    SYSTEM_RECALL_initialize,
    SYSTEM_RECALL_versionup
};

enum TAMPERING_LEVEL
{
    TAMPERING_LEVEL_low,
    TAMPERING_LEVEL_mid,
    TAMPERING_LEVEL_high
};

enum TAMPERING_TYPE
{
    TAMPERING_TYPE_ftp_client_alarm,
    TAMPERING_TYPE_smtp_alarm,
    TAMPERING_TYPE_alarm_out_1_alarm,
    TAMPERING_TYPE_alarm_out_2_alarm,
    TAMPERING_TYPE_alarm_out_3_alarm,
    TAMPERING_TYPE_alarm_out_4_alarm,
    TAMPERING_TYPE_image_memory_alarm,
    TAMPERING_TYPE_voice_alert_1_alarm,
    TAMPERING_TYPE_voice_alert_2_alarm,
    TAMPERING_TYPE_voice_alert_3_alarm,
    TAMPERING_TYPE_tampering
};

enum TEXT_ALIGN_MODE
{
    TEXT_ALIGN_MODE_left,
    TEXT_ALIGN_MODE_center,
    TEXT_ALIGN_MODE_right
};

enum TILT_DIRECTION
{
    TILT_DIRECTION_up,
    TILT_DIRECTION_down
};

enum TITLE_COLOR
{
    TITLE_COLOR_white,
    TITLE_COLOR_red,
    TITLE_COLOR_yellow,
    TITLE_COLOR_blue,
    TITLE_COLOR_green
};

enum TITLE_DISPLAY_MODE
{
    TITLE_DISPLAY_MODE_on,
    TITLE_DISPLAY_MODE_off,
    TITLE_DISPLAY_MODE_clear
};

enum TRANSMITTANCE_MODE
{
    TRANSMITTANCE_MODE_off,
    TRANSMITTANCE_MODE_low,
    TRANSMITTANCE_MODE_high
};

enum TRIGGER_ACTION
{
    TRIGGER_ACTION_on,
    TRIGGER_ACTION_off,
    TRIGGER_ACTION_toggle
};

enum TRIGGER_OUTPUT_TYPE
{
	TRIGGER_OUTPUT_TYPE_alarm_out,
	TRIGGER_OUTPUT_TYPE_voice_alert
};

enum TRIGGER_TYPE
{
    TRIGGER_TYPE_none,
    TRIGGER_TYPE_sensor1,
    TRIGGER_TYPE_sensor2,
    TRIGGER_TYPE_sensor3,
    TRIGGER_TYPE_sensor4,
    TRIGGER_TYPE_disconnected,
    TRIGGER_TYPE_vmf,
    TRIGGER_TYPE_vmd,
    TRIGGER_TYPE_tampering,
    TRIGGER_TYPE_facedetection,
    TRIGGER_TYPE_aud,
    TRIGGER_TYPE_condition1,
    TRIGGER_TYPE_condition2,
    TRIGGER_TYPE_condition3,
    TRIGGER_TYPE_condition4,
    TRIGGER_TYPE_condition5,
    TRIGGER_TYPE_condition6,
    TRIGGER_TYPE_condition7,
    TRIGGER_TYPE_condition8,
    TRIGGER_TYPE_condition9,
    TRIGGER_TYPE_condition10
};

enum USER_TYPE
{
    USER_TYPE_smtp_auth,
    USER_TYPE_ftp_client
};

enum VIDEO_OUTPUT_MODE_TYPE
{
    VIDEO_OUTPUT_MODE_TYPE_ip_only,
    VIDEO_OUTPUT_MODE_TYPE_ip_and_ntsc,
    VIDEO_OUTPUT_MODE_TYPE_ip_and_pal
};

enum VMF_TYPE
{
    VMF_TYPE_ftp_client_alarm,
    VMF_TYPE_smtp_alarm,
    VMF_TYPE_alarm_out_1_alarm,
    VMF_TYPE_alarm_out_2_alarm,
    VMF_TYPE_alarm_out_3_alarm,
    VMF_TYPE_alarm_out_4_alarm,
    VMF_TYPE_image_memory_alarm,
    VMF_TYPE_voice_alert_1_alarm,
    VMF_TYPE_voice_alert_2_alarm,
    VMF_TYPE_voice_alert_3_alarm
};

enum WEEK
{
	WEEK_sun,
	WEEK_mon,
	WEEK_tue,
	WEEK_wed,
	WEEK_thu,
	WEEK_fri,
	WEEK_sat
};

enum WEEKLY_SCHEDULE
{
	WEEKLY_SCHEDULE_smtp_alarm,
	WEEKLY_SCHEDULE_smtp_periodical,
	WEEKLY_SCHEDULE_edgestorage,
	WEEKLY_SCHEDULE_ircutfilter
};

enum WEEKLY_SCHEDULE_EX
{
	WEEKLY_SCHEDULE_EX_timer,
	WEEKLY_SCHEDULE_EX_alarmout,
    WEEKLY_SCHEDULE_EX_voicealert
};

enum WHITE_BALANCE_GAIN_TYPE
{
    WHITE_BALANCE_GAIN_TYPE_red,
    WHITE_BALANCE_GAIN_TYPE_green,
    WHITE_BALANCE_GAIN_TYPE_blue,
    WHITE_BALANCE_GAIN_TYPE_high_resolution_red,
    WHITE_BALANCE_GAIN_TYPE_high_resolution_blue
};

enum WHITE_BALANCE_MODE_TYPE
{
    WHITE_BALANCE_MODE_TYPE_atw,
    WHITE_BALANCE_MODE_TYPE_atw_pro,
    WHITE_BALANCE_MODE_TYPE_auto,
    WHITE_BALANCE_MODE_TYPE_fluorescent_lamp,
    WHITE_BALANCE_MODE_TYPE_mercury_lamp,
    WHITE_BALANCE_MODE_TYPE_sodium_lamp,
    WHITE_BALANCE_MODE_TYPE_metal_halide_lamp,
    WHITE_BALANCE_MODE_TYPE_white_led,
    WHITE_BALANCE_MODE_TYPE_one_push_white_balance,
    WHITE_BALANCE_MODE_TYPE_manual,
    WHITE_BALANCE_MODE_TYPE_indoor,
    WHITE_BALANCE_MODE_TYPE_outdoor,
    WHITE_BALANCE_MODE_TYPE_dual_white_balance,
    WHITE_BALANCE_MODE_TYPE_advanced_auto
};

enum WIDE_DYNAMIC_RANGE_LEVEL
{
    WIDE_DYNAMIC_RANGE_LEVEL_level1,
    WIDE_DYNAMIC_RANGE_LEVEL_level2,
    WIDE_DYNAMIC_RANGE_LEVEL_level3
};

enum WIRELESS_ANTENNA_MODE
{
    WIRELESS_ANTENNA_MODE_internal,
    WIRELESS_ANTENNA_MODE_external,
    WIRELESS_ANTENNA_MODE_diversity
};

enum WIRELESS_AUTHENTICATION_MODE
{
    WIRELESS_AUTHENTICATION_MODE_none,
    WIRELESS_AUTHENTICATION_MODE_wep,
    WIRELESS_AUTHENTICATION_MODE_wep_dynamic,
    WIRELESS_AUTHENTICATION_MODE_wpa,
    WIRELESS_AUTHENTICATION_MODE_wpa2,
    WIRELESS_AUTHENTICATION_MODE_wpa_psk,
    WIRELESS_AUTHENTICATION_MODE_wpa2_psk,
    WIRELESS_AUTHENTICATION_MODE_wps
};

enum WIRELESS_NETWORK_TYPE
{
    WIRELESS_NETWORK_TYPE_ad_hoc,
    WIRELESS_NETWORK_TYPE_infra_structure
};


enum ZOOM_DIRECTION
{
    ZOOM_DIRECTION_tele,
    ZOOM_DIRECTION_wide
};

enum ZOOM_MODE_TYPE
{
    ZOOM_MODE_TYPE_full,
    ZOOM_MODE_TYPE_optical_only,
    ZOOM_MODE_TYPE_optical,
};

}	// namespace unci

#endif	// _SNCCGIWRAPPERLIBDEFINEENUM_H_
