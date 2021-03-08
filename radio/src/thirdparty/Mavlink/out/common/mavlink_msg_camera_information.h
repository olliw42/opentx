//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_CAMERA_INFORMATION_H
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_H


//----------------------------------------
//-- Message CAMERA_INFORMATION
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_camera_information_t {
    uint32_t time_boot_ms;
    uint32_t firmware_version;
    float focal_length;
    float sensor_size_h;
    float sensor_size_v;
    uint32_t flags;
    uint16_t resolution_h;
    uint16_t resolution_v;
    uint16_t cam_definition_version;
    uint8_t vendor_name[32];
    uint8_t model_name[32];
    uint8_t lens_id;
    char cam_definition_uri[140];
}) fmav_camera_information_t;


#define FASTMAVLINK_MSG_ID_CAMERA_INFORMATION  259

#define FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX  235
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_CRCEXTRA  92

#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FLAGS  0
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FRAME_LEN_MAX  260

#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_VENDOR_NAME_NUM  32 // number of elements in array
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_VENDOR_NAME_LEN  32 // length of array = number of bytes
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_MODEL_NAME_NUM  32 // number of elements in array
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_MODEL_NAME_LEN  32 // length of array = number of bytes
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_URI_NUM  140 // number of elements in array
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_URI_LEN  140 // length of array = number of bytes

#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_TIME_BOOT_MS_OFS  0
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_FIRMWARE_VERSION_OFS  4
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_FOCAL_LENGTH_OFS  8
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_SENSOR_SIZE_H_OFS  12
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_SENSOR_SIZE_V_OFS  16
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_FLAGS_OFS  20
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_RESOLUTION_H_OFS  24
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_RESOLUTION_V_OFS  26
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_VERSION_OFS  28
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_VENDOR_NAME_OFS  30
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_MODEL_NAME_OFS  62
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_LENS_ID_OFS  94
#define FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_URI_OFS  95


//----------------------------------------
//-- Message CAMERA_INFORMATION packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const uint8_t* vendor_name, const uint8_t* model_name, uint32_t firmware_version, float focal_length, float sensor_size_h, float sensor_size_v, uint16_t resolution_h, uint16_t resolution_v, uint8_t lens_id, uint32_t flags, uint16_t cam_definition_version, const char* cam_definition_uri,
    fmav_status_t* _status)
{
    fmav_camera_information_t* _payload = (fmav_camera_information_t*)msg->payload;

    _payload->time_boot_ms = time_boot_ms;
    _payload->firmware_version = firmware_version;
    _payload->focal_length = focal_length;
    _payload->sensor_size_h = sensor_size_h;
    _payload->sensor_size_v = sensor_size_v;
    _payload->flags = flags;
    _payload->resolution_h = resolution_h;
    _payload->resolution_v = resolution_v;
    _payload->cam_definition_version = cam_definition_version;
    _payload->lens_id = lens_id;
    memcpy(&(_payload->vendor_name), vendor_name, sizeof(uint8_t)*32);
    memcpy(&(_payload->model_name), model_name, sizeof(uint8_t)*32);
    memcpy(&(_payload->cam_definition_uri), cam_definition_uri, sizeof(char)*140);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_CAMERA_INFORMATION;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_CAMERA_INFORMATION_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_camera_information_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_camera_information_pack(
        msg, sysid, compid,
        _payload->time_boot_ms, _payload->vendor_name, _payload->model_name, _payload->firmware_version, _payload->focal_length, _payload->sensor_size_h, _payload->sensor_size_v, _payload->resolution_h, _payload->resolution_v, _payload->lens_id, _payload->flags, _payload->cam_definition_version, _payload->cam_definition_uri,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const uint8_t* vendor_name, const uint8_t* model_name, uint32_t firmware_version, float focal_length, float sensor_size_h, float sensor_size_v, uint16_t resolution_h, uint16_t resolution_v, uint8_t lens_id, uint32_t flags, uint16_t cam_definition_version, const char* cam_definition_uri,
    fmav_status_t* _status)
{
    fmav_camera_information_t* _payload = (fmav_camera_information_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_boot_ms = time_boot_ms;
    _payload->firmware_version = firmware_version;
    _payload->focal_length = focal_length;
    _payload->sensor_size_h = sensor_size_h;
    _payload->sensor_size_v = sensor_size_v;
    _payload->flags = flags;
    _payload->resolution_h = resolution_h;
    _payload->resolution_v = resolution_v;
    _payload->cam_definition_version = cam_definition_version;
    _payload->lens_id = lens_id;
    memcpy(&(_payload->vendor_name), vendor_name, sizeof(uint8_t)*32);
    memcpy(&(_payload->model_name), model_name, sizeof(uint8_t)*32);
    memcpy(&(_payload->cam_definition_uri), cam_definition_uri, sizeof(char)*140);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_CAMERA_INFORMATION;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_CAMERA_INFORMATION >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_CAMERA_INFORMATION >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_camera_information_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_camera_information_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->time_boot_ms, _payload->vendor_name, _payload->model_name, _payload->firmware_version, _payload->focal_length, _payload->sensor_size_h, _payload->sensor_size_v, _payload->resolution_h, _payload->resolution_v, _payload->lens_id, _payload->flags, _payload->cam_definition_version, _payload->cam_definition_uri,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const uint8_t* vendor_name, const uint8_t* model_name, uint32_t firmware_version, float focal_length, float sensor_size_h, float sensor_size_v, uint16_t resolution_h, uint16_t resolution_v, uint8_t lens_id, uint32_t flags, uint16_t cam_definition_version, const char* cam_definition_uri,
    fmav_status_t* _status)
{
    fmav_camera_information_t _payload;

    _payload.time_boot_ms = time_boot_ms;
    _payload.firmware_version = firmware_version;
    _payload.focal_length = focal_length;
    _payload.sensor_size_h = sensor_size_h;
    _payload.sensor_size_v = sensor_size_v;
    _payload.flags = flags;
    _payload.resolution_h = resolution_h;
    _payload.resolution_v = resolution_v;
    _payload.cam_definition_version = cam_definition_version;
    _payload.lens_id = lens_id;
    memcpy(&(_payload.vendor_name), vendor_name, sizeof(uint8_t)*32);
    memcpy(&(_payload.model_name), model_name, sizeof(uint8_t)*32);
    memcpy(&(_payload.cam_definition_uri), cam_definition_uri, sizeof(char)*140);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_CAMERA_INFORMATION,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_camera_information_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_CAMERA_INFORMATION,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_CAMERA_INFORMATION_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message CAMERA_INFORMATION unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_camera_information_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_camera_information_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_camera_information_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_camera_information_decode(fmav_camera_information_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_CAMERA_INFORMATION_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_camera_information_get_field_time_boot_ms(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_camera_information_get_field_firmware_version(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_camera_information_get_field_focal_length(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[8]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_camera_information_get_field_sensor_size_h(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[12]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_camera_information_get_field_sensor_size_v(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[16]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_camera_information_get_field_flags(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[20]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_get_field_resolution_h(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[24]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_get_field_resolution_v(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[26]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_camera_information_get_field_cam_definition_version(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[28]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_camera_information_get_field_lens_id(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[94]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_camera_information_get_field_vendor_name_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[30]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_camera_information_get_field_vendor_name(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_VENDOR_NAME_NUM) return 0;
    return ((uint8_t*)&(msg->payload[30]))[index];
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_camera_information_get_field_model_name_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[62]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_camera_information_get_field_model_name(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_MODEL_NAME_NUM) return 0;
    return ((uint8_t*)&(msg->payload[62]))[index];
}


FASTMAVLINK_FUNCTION_DECORATOR char* fmav_msg_camera_information_get_field_cam_definition_uri_ptr(const fmav_message_t* msg)
{
    return (char*)&(msg->payload[95]);
}


FASTMAVLINK_FUNCTION_DECORATOR char fmav_msg_camera_information_get_field_cam_definition_uri(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_URI_NUM) return 0;
    return ((char*)&(msg->payload[95]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_CAMERA_INFORMATION  259

#define mavlink_camera_information_t  fmav_camera_information_t

#define MAVLINK_MSG_ID_CAMERA_INFORMATION_LEN  235
#define MAVLINK_MSG_ID_CAMERA_INFORMATION_MIN_LEN  235
#define MAVLINK_MSG_ID_259_LEN  235
#define MAVLINK_MSG_ID_259_MIN_LEN  235

#define MAVLINK_MSG_ID_CAMERA_INFORMATION_CRC  92
#define MAVLINK_MSG_ID_259_CRC  92

#define MAVLINK_MSG_CAMERA_INFORMATION_FIELD_VENDOR_NAME_LEN 32
#define MAVLINK_MSG_CAMERA_INFORMATION_FIELD_MODEL_NAME_LEN 32
#define MAVLINK_MSG_CAMERA_INFORMATION_FIELD_CAM_DEFINITION_URI_LEN 140


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_camera_information_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint32_t time_boot_ms, const uint8_t* vendor_name, const uint8_t* model_name, uint32_t firmware_version, float focal_length, float sensor_size_h, float sensor_size_v, uint16_t resolution_h, uint16_t resolution_v, uint8_t lens_id, uint32_t flags, uint16_t cam_definition_version, const char* cam_definition_uri)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_camera_information_pack(
        msg, sysid, compid,
        time_boot_ms, vendor_name, model_name, firmware_version, focal_length, sensor_size_h, sensor_size_v, resolution_h, resolution_v, lens_id, flags, cam_definition_version, cam_definition_uri,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_camera_information_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint32_t time_boot_ms, const uint8_t* vendor_name, const uint8_t* model_name, uint32_t firmware_version, float focal_length, float sensor_size_h, float sensor_size_v, uint16_t resolution_h, uint16_t resolution_v, uint8_t lens_id, uint32_t flags, uint16_t cam_definition_version, const char* cam_definition_uri)
{
    return fmav_msg_camera_information_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        time_boot_ms, vendor_name, model_name, firmware_version, focal_length, sensor_size_h, sensor_size_v, resolution_h, resolution_v, lens_id, flags, cam_definition_version, cam_definition_uri,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_camera_information_decode(const mavlink_message_t* msg, mavlink_camera_information_t* payload)
{
    fmav_msg_camera_information_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_CAMERA_INFORMATION_H
