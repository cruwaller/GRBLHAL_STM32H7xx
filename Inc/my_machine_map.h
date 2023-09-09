/*
  weact_mini_h743_map.h - Minimal board map for WeAct MiniSTM32H743 (incl Trinamic support for testing)

  Part of grblHAL

  Copyright (c) 2022 Jon Escombe

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

// WeAct Mini STM32H743
// Board pins:
// https://raw.githubusercontent.com/WeActStudio/MiniSTM32H7xx/master/Images/STM32H750VB_2.jpg


#if N_ABC_MOTORS > 1
#error "No perkele! Liikaa motteja!"
#endif

#if !defined(STM32H743xx) || HSE_VALUE != 25000000
#error "This board has STM32H743 processor with a 25MHz crystal, please select a corresponding build!"
#endif

#define BOARD_NAME "WeAct Mini H743"
//#define HAS_BOARD_INIT

/*
rusk = pulse
vihr = dir
kelt = ena

Step/dir: (GPIOE) => GPIO_MAP or GPIO_SHIFTxx
    Y1: step  8, dir  9
    Y2: step 10, dir 11
    X : step 12, dir 13
    Z : step 14, dir 15

enable:
    Y1: C2
    Y2: C3
    X : C0
    Z : C1

limits:
    Y1: B12
    Y2: B13
    X : B14
    X : B15

Free:
    GPIOB 10...11

Spindle:
    En: B7
    Dir: B5
    PWM: B0

*/

// Define step pulse output pins.
#define X_STEP_PORT                 GPIOE
#define X_STEP_PIN                  12                  // X
#define Y_STEP_PORT                 GPIOE
#define Y_STEP_PIN                  8                  // Y
#define Z_STEP_PORT                 GPIOE
#define Z_STEP_PIN                  14                  // Z
#define STEP_OUTMODE                GPIO_SINGLE
//#define STEP_OUTMODE                GPIO_MAP
#define STEP_PORT                   GPIOC
//#define STEP_PINMODE                PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT            GPIOE
#define X_DIRECTION_PIN             13
#define Y_DIRECTION_PORT            GPIOE
#define Y_DIRECTION_PIN             9
#define Z_DIRECTION_PORT            GPIOE
#define Z_DIRECTION_PIN             15
#define DIRECTION_OUTMODE           GPIO_SINGLE
//#define DIRECTION_OUTMODE           GPIO_MAP
#define DIRECTION_PORT GPIOC
//#define DIRECTION_PINMODE           PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT               GPIOC
#define X_ENABLE_PIN                0
#define Y_ENABLE_PORT               GPIOC
#define Y_ENABLE_PIN                2
#define Z_ENABLE_PORT               GPIOC
#define Z_ENABLE_PIN                1
//#define STEPPERS_ENABLE_PINMODE   PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                GPIOB
#define X_LIMIT_PIN                 14                           // X- Limit
#define Y_LIMIT_PORT                GPIOB
#define Y_LIMIT_PIN                 12                           // Y- Limit
#define Z_LIMIT_PORT                GPIOB
#define Z_LIMIT_PIN                 15                           // Z- Limit
//#define LIMIT_INMODE                GPIO_SINGLE
#define LIMIT_INMODE                GPIO_MAP
#define LIMIT_PORT                  GPIOB


// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
    #define M3_AVAILABLE                // E0

    #define M3_STEP_PORT                GPIOE
    #define M3_STEP_PIN                 10
    #define M3_DIRECTION_PORT           GPIOE
    #define M3_DIRECTION_PIN            11

    #define M3_ENABLE_PORT              GPIOC
    #define M3_ENABLE_PIN               3

    #define M3_LIMIT_PORT               GPIOB
    #define M3_LIMIT_PIN                13
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOB
#define SPINDLE_ENABLE_PIN          7                           //
#define SPINDLE_DIRECTION_PORT      GPIOB
#define SPINDLE_DIRECTION_PIN       5                           //

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOB_BASE
#define SPINDLE_PWM_PIN             0                           //

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOD
#define COOLANT_FLOOD_PIN           14
#define COOLANT_MIST_PORT           GPIOD
#define COOLANT_MIST_PIN            15

// Define user-control controls (cycle start, reset, feed hold) input pins.
// These are all available on EXP2 along with electrical RESET* (EXP2, pin 3)
#define CONTROL_PORT                GPIOD
#define RESET_PIN                   8
#define FEED_HOLD_PIN               9
#define CYCLE_START_PIN             10

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT            GPIOA
#define SAFETY_DOOR_PIN             7
#endif

#define CONTROL_INMODE              GPIO_SINGLE

// Define probe switch input pin.
#define PROBE_PORT                  GPIOA
#define PROBE_PIN                   15                         // Z probe

#define DEFAULT_SPINDLE_RPM_MIN  6000.0f
#define DEFAULT_SPINDLE_RPM_MAX 24000.0f

// EOF
