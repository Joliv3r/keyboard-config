/*
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _CLMK,
    _NO,
    _NUM,
    _SYM,
    _NAV,
    _FN
};


enum tap_dances {
  TD_LAYERS
};


void switch_between_layers(tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      layer_move(_BASE);
      break;
    case 2:
      layer_move(_NO);
      break;
    case 3:
      layer_move(_NUM);
      break;
    case 4:
      layer_move(_CLMK);
      break;
    default:
      break;
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYERS] = ACTION_TAP_DANCE_FN(switch_between_layers)
};

enum unicode_names {
  U_AE_LOWER,
  U_AE_UPPER,
  U_OE_LOWER,
  U_OE_UPPER,
  U_AA_LOWER,
  U_AA_UPPER
};

const uint32_t PROGMEM unicode_map[] = {
  [U_AE_LOWER] = 0x00E6,
  [U_AE_UPPER] = 0x00C6,
  [U_OE_LOWER] = 0x00F8,
  [U_OE_UPPER] = 0x00D8,
  [U_AA_LOWER] = 0x00E5,
  [U_AA_UPPER] = 0x00C5
};

#define U_AE UP(U_AE_LOWER, U_AE_UPPER)
#define U_OE UP(U_OE_LOWER, U_OE_UPPER)
#define U_AA UP(U_AA_LOWER, U_AA_UPPER)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
      TD(TD_LAYERS),         KC_Q,         KC_W,       KC_E,           KC_R,    KC_T,          KC_Y,         KC_U,         KC_I,         KC_O,           KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),    KC_G,          KC_H, RSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      XXXXXXX,         KC_Z,         KC_X,       KC_C,           KC_V,    KC_B,          KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
                            LGUI_T(KC_DEL), LT(_NUM, KC_BSPC), LT(_NAV, KC_ENT),           LT(_FN, KC_TAB), LT(_SYM, KC_SPC),  RALT_T(KC_ESC)
  ),

    [_CLMK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
      TD(TD_LAYERS),         KC_Q,         KC_W,       KC_F,           KC_P,    KC_B,          KC_J,         KC_L,         KC_U,         KC_Y,           KC_SCLN,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,          KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      XXXXXXX,         KC_Z,         KC_X,       KC_C,           KC_D,    KC_B,          KC_K,         KC_H,      KC_COMM,       KC_DOT,         KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
                            LGUI_T(KC_DEL), LT(_NUM, KC_BSPC), LT(_NAV, KC_ENT),           LT(_FN, KC_TAB), LT(_SYM, KC_SPC),  RALT_T(KC_ESC)
  ),

    [_NO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
      TD(TD_LAYERS),         KC_Q,         KC_W,       KC_E,           KC_R,    KC_T,          KC_Y,         KC_U,         KC_I,         KC_O,           KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),    KC_G,          KC_H, RSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      XXXXXXX,         KC_Z,         KC_X,       KC_C,           KC_V,    KC_B,          KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
                            LGUI_T(KC_DEL), LT(_NUM, KC_BSPC), LT(_NAV, KC_ENT),           LT(_FN, KC_TAB), LT(_SYM, KC_SPC),  RALT_T(KC_ESC)
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //.-------------------------------------------------------------------.               .-------------------------------------------------------------------.
      TD(TD_LAYERS),      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_PAST,      KC_7,       KC_8,       KC_9,       KC_NO,      XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
      XXXXXXX,      KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,              KC_PSLS,      KC_4,       KC_5,       KC_6,       KC_PENT,      XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
      XXXXXXX,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_NO,      KC_1,       KC_2,       KC_3,       KC_SLSH,      XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
                                            XXXXXXX,    XXXXXXX, MO(_NAV),              KC_BSPC,    KC_0,       XXXXXXX
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //.--------------------------------------------------------------------.              .-------------------------------------------------------------------.
      XXXXXXX,      KC_NO,      KC_LPRN,    KC_RPRN,    S(KC_QUOT), KC_QUOT,              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      XXXXXXX,
  //.---------------------------   (   -----    )  -----    "   ----  '  |              |-------------------------------------------------------------------|
      XXXXXXX,      KC_BSLS,    KC_LBRC,    KC_RBRC,    KC_EQL,     S(KC_BSLS),             KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,
  //.---------------  \|   -----   [{  -----   ]}  -----  =+   -------  |              |-------------------------------------------------------------------|
      XXXXXXX,      KC_NO,      KC_LABK,      KC_RABK,      KC_MINS,    KC_GRV,              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      XXXXXXX,
  //.---------------------------------------------------   -_  ------  `~ |              |-------------------------------------------------------------------|
                                            XXXXXXX,    KC_ESC,     KC_BSPC,            XXXXXXX,      XXXXXXX,      XXXXXXX
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //.-------------------------------------------------------------------.               .-------------------------------------------------------------------.
      XXXXXXX,      KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_BRIU,    XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
      XXXXXXX,      KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,              KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_MUTE,    XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
      XXXXXXX,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_BRID,    XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
                                            XXXXXXX,    XXXXXXX,     XXXXXXX,              KC_MPLY,    KC_DEL,     XXXXXXX
  ),

    [_FN] = LAYOUT_split_3x6_3(
  //.-------------------------------------------------------------------.               .-------------------------------------------------------------------.
      XXXXXXX,      KC_F12,     KC_F7,      KC_F8,      KC_F9,      KC_NO,              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
      XXXXXXX,      KC_F11,     KC_F4,      KC_F5,      KC_F6,      KC_NO,              KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
      XXXXXXX,      KC_F10,     KC_F1,      KC_F2,      KC_F3,      KC_NO,              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      XXXXXXX,
  //|-------------------------------------------------------------------|               |-------------------------------------------------------------------|
                                            XXXXXXX,    KC_NO,      KC_NO,              XXXXXXX,     XXXXXXX,       XXXXXXX
  ),
};;
