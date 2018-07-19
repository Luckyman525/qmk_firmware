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

#include "fordham.h"

enum olkb_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum olkb_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT  
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  #   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   \  | Win  | Alt  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS},
  {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_NUBS, KC_APP,  KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |   -  |   =  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   ]  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SHIFT|      |      |      |      |      |      |      |      |      |      | SHIFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    SPACE    |      | HOME | PGUP | PGDN | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RBRC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT},
  {_______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |   F10|   F11|   F12|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  [   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   ;  |  DEL |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SHIFT|      |      |      |      |      |      |      |      |      |      | SHIFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    SPACE    |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_DEL },
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT},
  {_______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

  
  /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          //backlight_step();
          LED_TGL();
        #endif
        // and equal the opposite i guess
      } else {
        unregister_code(KC_RSFT);
        //Do some things
      }
      return false;
      break;    
  }
  return true;
}
