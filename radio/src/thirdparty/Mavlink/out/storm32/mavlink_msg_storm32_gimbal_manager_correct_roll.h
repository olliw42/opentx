//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_H
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_H


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_CORRECT_ROLL
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_storm32_gimbal_manager_correct_roll_t {
    float roll;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t gimbal_id;
    uint8_t client;
}) fmav_storm32_gimbal_manager_correct_roll_t;


#define FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL  60014

#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX  8
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_CRCEXTRA  134

#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FLAGS  3
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_TARGET_SYSTEM_OFS  4
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_TARGET_COMPONENT_OFS  5

#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FRAME_LEN_MAX  33



#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FIELD_ROLL_OFS  0
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FIELD_TARGET_SYSTEM_OFS  4
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FIELD_TARGET_COMPONENT_OFS  5
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FIELD_GIMBAL_ID_OFS  6
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_FIELD_CLIENT_OFS  7


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_CORRECT_ROLL packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_correct_roll_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, float roll,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_correct_roll_t* _payload = (fmav_storm32_gimbal_manager_correct_roll_t*)msg->payload;

    _payload->roll = roll;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->gimbal_id = gimbal_id;
    _payload->client = client;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_correct_roll_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_correct_roll_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_manager_correct_roll_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->gimbal_id, _payload->client, _payload->roll,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_correct_roll_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, float roll,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_correct_roll_t* _payload = (fmav_storm32_gimbal_manager_correct_roll_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->roll = roll;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->gimbal_id = gimbal_id;
    _payload->client = client;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_correct_roll_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_correct_roll_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_manager_correct_roll_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->gimbal_id, _payload->client, _payload->roll,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_correct_roll_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, float roll,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_correct_roll_t _payload;

    _payload.roll = roll;
    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.gimbal_id = gimbal_id;
    _payload.client = client;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_correct_roll_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_correct_roll_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_CORRECT_ROLL unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_storm32_gimbal_manager_correct_roll_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_storm32_gimbal_manager_correct_roll_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_storm32_gimbal_manager_correct_roll_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_storm32_gimbal_manager_correct_roll_decode(fmav_storm32_gimbal_manager_correct_roll_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_storm32_gimbal_manager_correct_roll_get_field_roll(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[0]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_storm32_gimbal_manager_correct_roll_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_storm32_gimbal_manager_correct_roll_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[5]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_storm32_gimbal_manager_correct_roll_get_field_gimbal_id(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[6]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_storm32_gimbal_manager_correct_roll_get_field_client(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[7]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL  60014

#define mavlink_storm32_gimbal_manager_correct_roll_t  fmav_storm32_gimbal_manager_correct_roll_t

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_LEN  8
#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_MIN_LEN  8
#define MAVLINK_MSG_ID_60014_LEN  8
#define MAVLINK_MSG_ID_60014_MIN_LEN  8

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_CRC  134
#define MAVLINK_MSG_ID_60014_CRC  134




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_manager_correct_roll_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, float roll)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_storm32_gimbal_manager_correct_roll_pack(
        msg, sysid, compid,
        target_system, target_component, gimbal_id, client, roll,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_manager_correct_roll_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, float roll)
{
    return fmav_msg_storm32_gimbal_manager_correct_roll_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, gimbal_id, client, roll,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_storm32_gimbal_manager_correct_roll_decode(const mavlink_message_t* msg, mavlink_storm32_gimbal_manager_correct_roll_t* payload)
{
    fmav_msg_storm32_gimbal_manager_correct_roll_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CORRECT_ROLL_H
