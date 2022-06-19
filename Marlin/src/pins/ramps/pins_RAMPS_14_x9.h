/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Arduino Mega with RAMPS v1.4 (or v1.3) pin assignments
 *
 * Applies to the following boards:
 *
 *  RAMPS_14_EFB (Hotend, Fan, Bed)
 *  RAMPS_14_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS_14_EFF (Hotend, Fan0, Fan1)
 *  RAMPS_14_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS_14_SF  (Spindle, Controller Fan)
 *
 *  RAMPS_13_EFB (Hotend, Fan, Bed)
 *  RAMPS_13_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS_13_EFF (Hotend, Fan0, Fan1)
 *  RAMPS_13_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS_13_SF  (Spindle, Controller Fan)
 *
 *  Other pins_MYBOARD.h files may override these defaults
 *
 *  Differences between
 *  RAMPS_13 | RAMPS_14
 *         7 | 11
 */

#if ENABLED(AZSMZ_12864) && DISABLED(ALLOW_SAM3X8E)
  #error "No pins defined for RAMPS with AZSMZ_12864."
#endif

#include "env_validate.h"

// Custom flags and defines for the build
//#define BOARD_CUSTOM_BUILD_FLAGS -D__FOO__

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "RAMPS 1.4"
#endif

//
// Servos
//
#ifndef SERVO0_PIN
  #ifdef IS_RAMPS_13
    #define SERVO0_PIN                         7
  #else
    #define SERVO0_PIN                        11
  #endif
#endif
#ifndef SERVO1_PIN
  #define SERVO1_PIN                           6
#endif
#ifndef SERVO2_PIN
  #define SERVO2_PIN                           5
#endif
#ifndef SERVO3_PIN
  #define SERVO3_PIN                           4
#endif

//
// Limit Switches
//
#define X_MIN_PIN                              3
#define X_MAX_PIN                              2

#define Y_MIN_PIN                             14
#define Y_MAX_PIN                             15

#define Z_MIN_PIN                             18
#define Z_MAX_PIN                             19

#define I_MIN_PIN                             63 // Aux2
#define I_MAX_PIN                             40

#define J_MIN_PIN                             42 // Aux2
#define J_MAX_PIN                             65

#define K_MIN_PIN                             59 // Aux2
#define K_MAX_PIN                             64

#define U_MIN_PIN                             44 // Aux2
#define U_MAX_PIN                             66

#define V_MIN_PIN                             32 // Aux4
#define V_MAX_PIN                             47

#define W_MIN_PIN                             45 // Aux4
#define W_MAX_PIN                             43

//
// Steppers
//
#define X_STEP_PIN                            54
#define X_DIR_PIN                             55
#define X_ENABLE_PIN                          38

#define Y_STEP_PIN                            60
#define Y_DIR_PIN                             61
#define Y_ENABLE_PIN                          56

#define Z_STEP_PIN                            46
#define Z_DIR_PIN                             48
#define Z_ENABLE_PIN                          62

#define I_STEP_PIN                            26
#define I_DIR_PIN                             28
#define I_ENABLE_PIN                          24

#define J_STEP_PIN                            36
#define J_DIR_PIN                             34
#define J_ENABLE_PIN                          30

#define K_STEP_PIN                            41 // Aux4
#define K_DIR_PIN                             39
#define K_ENABLE_PIN                          37

#define U_STEP_PIN                            35 // Aux4
#define U_DIR_PIN                             33
#define U_ENABLE_PIN                          31

#define V_STEP_PIN                            29 // Aux4
#define V_DIR_PIN                             27
#define V_ENABLE_PIN                          25

#define W_STEP_PIN                            23 // Aux4
#define W_DIR_PIN                             17
#define W_ENABLE_PIN                          16

//
// Temperature Sensors
//
#ifndef TEMP_0_PIN
  #define TEMP_0_PIN                          13  // Analog Input
#endif
#ifndef TEMP_1_PIN
  #define TEMP_1_PIN                          15  // Analog Input
#endif
#ifndef TEMP_BED_PIN
  #define TEMP_BED_PIN                        14  // Analog Input
#endif

//
// Heaters / Fans
//
#ifndef MOSFET_A_PIN
  #define MOSFET_A_PIN                        10
#endif
#ifndef MOSFET_B_PIN
  #define MOSFET_B_PIN                         9
#endif
#ifndef MOSFET_C_PIN
  #define MOSFET_C_PIN                         8
#endif
#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN                        -1
#endif

#define HEATER_0_PIN                MOSFET_A_PIN

#if FET_ORDER_EFB                                 // Hotend, Fan, Bed
  #define HEATER_BED_PIN            MOSFET_C_PIN
#elif FET_ORDER_EEF                               // Hotend, Hotend, Fan
  #define HEATER_1_PIN              MOSFET_B_PIN
#elif FET_ORDER_EEB                               // Hotend, Hotend, Bed
  #define HEATER_1_PIN              MOSFET_B_PIN
  #define HEATER_BED_PIN            MOSFET_C_PIN
#elif FET_ORDER_EFF                               // Hotend, Fan, Fan
  #define FAN1_PIN                  MOSFET_C_PIN
#elif DISABLED(FET_ORDER_SF)                      // Not Spindle, Fan (i.e., "EFBF" or "EFBE")
  #define HEATER_BED_PIN            MOSFET_C_PIN
  #if EITHER(HAS_MULTI_HOTEND, HEATERS_PARALLEL)
    #define HEATER_1_PIN            MOSFET_D_PIN
  #else
    #define FAN1_PIN                MOSFET_D_PIN
  #endif
#endif

#ifndef FAN_PIN
  #if EITHER(FET_ORDER_EFB, FET_ORDER_EFF)        // Hotend, Fan, Bed or Hotend, Fan, Fan
    #define FAN_PIN                 MOSFET_B_PIN
  #elif EITHER(FET_ORDER_EEF, FET_ORDER_SF)       // Hotend, Hotend, Fan or Spindle, Fan
    #define FAN_PIN                 MOSFET_C_PIN
  #elif FET_ORDER_EEB                             // Hotend, Hotend, Bed
    #define FAN_PIN                            4  // IO pin. Buffer needed
  #else                                           // Non-specific are "EFB" (i.e., "EFBF" or "EFBE")
    #define FAN_PIN                 MOSFET_B_PIN
  #endif
#endif

//
// Misc. Functions
//
#ifndef SDSS
  #define SDSS                       AUX3_06_PIN
#endif
#define LED_PIN                               13

#ifndef PS_ON_PIN
  #define PS_ON_PIN                           12
#endif


//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER && !defined(SPINDLE_LASER_ENA_PIN)
  #if NUM_SERVOS < 2                              // Use servo connector if possible
    #define SPINDLE_LASER_ENA_PIN              4  // Pullup or pulldown!
    #define SPINDLE_LASER_PWM_PIN              6  // Hardware PWM
    #define SPINDLE_DIR_PIN                    5
  #elif HAS_FREE_AUX2_PINS
    #define SPINDLE_LASER_ENA_PIN             40  // Pullup or pulldown!
    #define SPINDLE_LASER_PWM_PIN             44  // Hardware PWM
    #define SPINDLE_DIR_PIN                   65
  #else
    #error "No auto-assignable Spindle/Laser pins available."
  #endif
#endif