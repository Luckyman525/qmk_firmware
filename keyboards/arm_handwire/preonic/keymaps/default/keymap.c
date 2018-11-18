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
  _PLOVER,
  _GREEK,
  _GREEKCAP,
  _RAISE,
  _LOWER,
  _GAMING,
  _ADJUST,
};

enum olkb_keycodes {
  COLEMAK = SAFE_RANGE,
  PLOVER,
  GREEK,
  GREEKCAP,
  LOWER,
  RAISE,
  GAMING,
  EXT_PLV,
  EXT_GMG,
};

enum unicode_name {
  ALPHACP,
  ALPHA,
  BETACP,
  BETA,
  GAMMACP,
  GAMMA,
  DELTACP,
  DELTA,
  EPSICP,
  EPSI,
  ZETACP,
  ZETA,
  ETACP,
  ETA,
  THETACP,
  THETA,
  IOTACP,
  IOTA,
  KAPPACP,
  KAPPA,
  LAMDACP,
  LAMDA,
  MUCP,
  MU,
  NUCP,
  NU,
  XICP,
  XI,
  OMCRNCP,
  OMCRN,
  PICP,
  PI,
  RHOCP,
  RHO,
  SIGMACP,
  SIGMA,
  TAUCP,
  TAU,
  UPSLNCP,
  UPSLN,
  PHICP,
  PHI,
  CHICP,
  CHI,
  PSICP,
  PSI,
  OMEGACP,
  OMEGA
};

const uint32_t PROGMEM unicode_map[] = {
  [ALPHACP]      = 0x0391,	// capital α
  [ALPHA]        = 0x03B1,	// α
  [BETACP]       = 0x0392,
  [BETA]         = 0x03B2,
  [GAMMACP]      = 0x0393,
  [GAMMA]        = 0x03B3,
  [DELTACP]      = 0x0394,
  [DELTA]        = 0x03B4,
  [EPSICP]       = 0x0395,
  [EPSI]         = 0x03B5,
  [ZETACP]       = 0x0396,
  [ZETA]         = 0x03B6,
  [ETACP]        = 0x0397,
  [ETA]          = 0x03B7,
  [THETACP]      = 0x0398,
  [THETA]        = 0x03B8,
  [IOTACP]       = 0x0399,
  [IOTA]         = 0x03B9,
  [KAPPACP]      = 0x039A,
  [KAPPA]        = 0x03BA,
  [LAMDACP]      = 0x039B,
  [LAMDA]        = 0x03BB,
  [MUCP]         = 0x039C,	// capital μ (mu)
  [MU]           = 0x00B5,	// µ (micro sign!)
  [NUCP]         = 0x039D,
  [NU]           = 0x03BD,
  [XICP]         = 0x039E,
  [XI]           = 0x03BE,
  [OMCRNCP]      = 0x039F,
  [OMCRN]        = 0x03BF,
  [PICP]         = 0x03A0,
  [PI]           = 0x03C0,
  [RHOCP]        = 0x03A1,
  [RHO]          = 0x03C1,
  [SIGMACP]      = 0x03A3,
  [SIGMA]        = 0x03C3,
  [TAUCP]        = 0x03A4,
  [TAU]          = 0x03C4,
  [UPSLNCP]      = 0x03A5,
  [UPSLN]        = 0x03C5,
  [PHICP]        = 0x03A6,
  [PHI]          = 0x03C6,
  [CHICP]        = 0x03A7,
  [CHI]          = 0x03C7,
  [PSICP]        = 0x03A8,
  [PSI]          = 0x03C8,
  [OMEGACP]      = 0x03A9,
  [OMEGA]        = 0x03C9
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI
#define CAPLSFT MT(MOD_LSFT, KC_CAPS)
#define LOWESC LT(_LOWER, KC_ESC)
#define GRK OSL(_GREEK)
#define GRKCAP OSL(_GREEKCAP)
#define SFT MOD_LSFT
#define CTL MOD_LCTL
#define GUI MOD_LGUI

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
 * | Ctrl |   \  |  GUI |  ALT |Lower | Enter| Space| Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = { 
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_NUHS },
  {KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN },
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  {KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWESC,  KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},

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
  {EXT_PLV, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   ST_BOLT, ST_GEM },
  {KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB },
  {STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR },
  {KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR },
  {KC_NO,   KC_NO,   KC_NO,   STN_A,   STN_O,   KC_NO,   KC_NO,   STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2}
},

/* Greek
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
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
[_GREEK] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, THETA,   OMEGA,   PHI,     PI,      BETA,    _______, LAMDA,   UPSLN,   PSI,     _______, _______},
  {_______, ALPHA,   RHO,     SIGMA,   TAU,     GAMMA,   KAPPA,   NU,      EPSI,    IOTA,    OMCRN,   _______},
  {_______, ZETA,    XI,      CHI,     DELTA,   _______, MU,      _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Greek Capitals
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
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
[_GREEKCAP] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, THETA,   OMEGA,   PHI,     PI,      BETA,    _______, LAMDA,   UPSLN,   PSI,     _______, _______},
  {_______, ALPHA,   RHO,     SIGMA,   TAU,     GAMMA,   KAPPA,   NU,      EPSI,    IOTA,    OMCRN,   _______},
  {_______, ZETA,    XI,      CHI,     DELTA,   _______, MU,      _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Exit |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bspc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |   -  |   =  | Alt  |       Space        |   #  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_GAMING] = {  
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    EXT_GMG},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL },
  {KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {CAPLSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_MINS, KC_EQL,  KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_NUHS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |   -  |   =  |   [  |   ]  | GRK  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |PrtScr|
 * `-----------------------------------------------------------------------------------'
 */	

[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_CAPS, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, GRK    },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |   F10|   F11|   F12|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      | HOME | PGDN | PGUP | END  |GRKCAP|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_CAPS, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  GRKCAP },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

  
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
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
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
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
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to colemak and this is a huge string\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_COLEMAK);
	layer_off(_GAMING);
	layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
	set_single_persistent_default_layer(_PLOVER);
	if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
        layer_on(_COLEMAK);
	layer_on(_GAMING);
	layer_on(_RAISE);
	layer_on(_LOWER);
	layer_on(_ADJUST);
	set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
	set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
    case EXT_GMG:
      if (record->event.pressed) {
	set_single_persistent_default_layer(_COLEMAK);
      }
  }
  return true;
};
