/** @file
 *    @brief MAVLink comm protocol testsuite generated from opentx.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef OPENTX_TESTSUITE_H
#define OPENTX_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_storm32(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_opentx(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_storm32(system_id, component_id, last_msg);
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_opentx(system_id, component_id, last_msg);
}
#endif

#include "../storm32/testsuite.h"
#include "../ardupilotmega/testsuite.h"



static void mavlink_test_opentx(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // OPENTX_TESTSUITE_H
