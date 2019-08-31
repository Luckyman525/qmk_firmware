/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

#include "preonic.h"
#include "keymap_steno.h"

enum olkb_layers {
  _COLEMAK,
  _PDVORAK,
  _PLOVER,
  _UNICODE,
  _RAISE,
  _LOWER,
  _GAMING,
  _ADJUST,
};

enum olkb_keycodes {
  COLEMAK = SAFE_RANGE,
  PDVORAK,
  TFLIP,
  LENNY,
  PLOVER,
  UNICODE,
  LOWER,
  RAISE,
  GAMING,
  EXT_PLV,
  EXT_GMG,
};

enum unicode_names {
  SNEK,
  VOL,
};

const uint32_t PROGMEM unicode_map[] = {
  [SNEK] = 0x1F40D,
  [VOL]  = 0x1F50A,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI
#define LOWESC LT(_LOWER, KC_ESC)
#define ENTALT MT(MOD_LALT, KC_ENT)
#define UNICODE MO(_UNICODE)
#define UCODE OSL(_UNICODE)
#define ADJ DF(_ADJUST)
#define GAMING DF(_GAMING)
#define PLOVER DF(_PLOVER)
#define SFT MOD_LSFT
#define CTL MOD_LCTL
#define GUI MOD_LGUI
#define POUND LSFT(KC_3)
#define WSPC1 RGUI(KC_1)
#define WSPC2 RGUI(KC_2)
#define WSPC3 RGUI(KC_3)
#define WSPC4 RGUI(KC_4)
#define WSPC5 RGUI(KC_5)
#define WSPC6 RGUI(KC_6)
#define WSPC7 RGUI(KC_7)
#define WSPC8 RGUI(KC_8)
#define WSPC9 RGUI(KC_9)
#define WSPC0 RGUI(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   '  |  #   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bspc |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   \  | UCODE|  GUI |Lower | Enter| Space| Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_NUHS },
  {KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN },
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  {KC_LCTL, KC_NUBS, UNICODE, KC_RGUI, LOWESC,  ENTALT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},

/* Programmer's Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * | Exit |      |      |      |      |      |      |      |      |      |TXBOLT|GEMiNI|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   U  |   O  |      |      |   E  |   U  |  PWR | RES1 | RES2 |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {ADJ,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   ST_BOLT, ST_GEM },
  {KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB },
  {STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR },
  {KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR },
  {KC_NO,   KC_NO,   KC_NO,   STN_A,   STN_O,   KC_NO,   KC_NO,   STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2}
},

/* UNICODE
 * ,-----------------------------------------------------------------------------------.
 * | SNEK | TFLIP| LENNY|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UNICODE] = {
  {X(SNEK), TFLIP,   LENNY,   X(VOL),  _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, UC_M_WC, UC_M_LN, _______, _______, _______, _______, _______}
},

/* GAMING
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |ADJUST|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | GUI  |        Space       |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ADJ    },
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL },
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LALT, _______, _______, KC_SPC,  KC_SPC,  KC_SPC,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |TrmON |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | WSPC1| WSPC2| WSPC3| WSPC4| WSPC5| WSPC6| WSPC7| WSPC8| WSPC9| WSPC0|TrmOff|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps | HOME | PGDN | PGUP | END  |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |UCODE |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |PrtScr|
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TERM_ON},
  {_______, WSPC1,   WSPC2,   WSPC3,   WSPC4,   WSPC5,   WSPC6,   WSPC7,   WSPC8,   WSPC9,   WSPC0,   TERM_OFF},
  {KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UCODE  },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |   F10|   F11|   F12|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | AltGr|      |SuperL|      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_CAPS, KC_EXLM, KC_AT,   POUND,   KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, KC_ALGR, _______, KC_LGUI, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |EEPRS|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SYSOFF|SLEEP |WAKE  |      |      |      |      |      |      |PLOVER|GAMING| CMAK |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {EEP_RST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_PWR,  KC_SLEP, KC_WAKE, _______, _______, _______, _______, _______, _______, PLOVER,  GAMING,  COLEMAK}
},


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*eeconfig_init();*/
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to colemak and this is a huge string\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case PLOVER:
        layer_off(_RAISE);
        layer_off(_LOWER);
		layer_off(_ADJUST);
        layer_on(_PLOVER);
      if (record->event.pressed) {
	  if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case ADJ:
	if (record->event.pressed) {
		layer_off(_PLOVER);
	}
    case TFLIP:
      if (record->event.pressed) {
        //when keycode TFLIP is pressed
        send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        } else {
        //when keycode TFLIP is released
      }
      break;
    case LENNY:
      if (record->event.pressed) {
        send_unicode_hex_string("0028 0020 0361 00B0 035C 0296 0020 0361 00B0 0029");
        } else {
      }
      break;
  }
  return true;
};
