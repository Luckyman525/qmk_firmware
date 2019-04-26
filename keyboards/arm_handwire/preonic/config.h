/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6464
#define DEVICE_VER      0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER QMK
#define PRODUCT Handwired Preonic
#define DESCRIPTION QMK keyboard firmware test for a handwired preonic

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { TEENSY_PIN20, TEENSY_PIN19, TEENSY_PIN18, TEENSY_PIN15, TEENSY_PIN14 }
#define MATRIX_ROW_IOPINS { TEENSY_PIN20_IOPORT, TEENSY_PIN19_IOPORT, TEENSY_PIN18_IOPORT, TEENSY_PIN15_IOPORT, TEENSY_PIN14_IOPORT }
#define MATRIX_COL_PINS { TEENSY_PIN0, TEENSY_PIN1, TEENSY_PIN2, TEENSY_PIN3, TEENSY_PIN4,\
                          TEENSY_PIN5, TEENSY_PIN6, TEENSY_PIN7, TEENSY_PIN8, TEENSY_PIN9,\
                          TEENSY_PIN10, TEENSY_PIN11 }
#define MATRIX_COL_IOPINS { TEENSY_PIN0_IOPORT, TEENSY_PIN1_IOPORT, TEENSY_PIN2_IOPORT, TEENSY_PIN3_IOPORT, TEENSY_PIN4_IOPORT,\
                          TEENSY_PIN5_IOPORT, TEENSY_PIN6_IOPORT, TEENSY_PIN7_IOPORT, TEENSY_PIN8_IOPORT, TEENSY_PIN9_IOPORT,\
                          TEENSY_PIN10_IOPORT, TEENSY_PIN11_IOPORT }

#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_ENTER)) \
)

/* RGB backlight config */
#define RGB_DI_PIN TEENSY_PIN23		/* pin your RGB strip is wired to */
#define RGBLED_NUM 14 			/* number of LEDs in your strip */
#define RGBLIGHT_HUE_STEP 64 		/* how many hues you want to have available */
#define RGBLIGHT_SAT_STEP 64		/* how many steps of saturation you'd like */
#define RGBLIGHT_VAL_STEP 64		/* the number of levels of brightness you want */
#define RGBLIGHT_LIMIT_VAL 255		/* Limit the value of HSV to limit the maximum brightness simply */
#define RGBLIGHT_SLEEP			/* this will shut off the lighting when the host enters sleep mode */

/* Feature disable options
*  These options are also useful to firmware size reduction.
*/

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
#define GRAVE_ESC_CTRL_OVERRIDE
#define FORCE_NKRO

#define UNICODE_WINC_KEY KC_LALT

#endif
