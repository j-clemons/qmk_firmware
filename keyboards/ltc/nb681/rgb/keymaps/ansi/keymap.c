/*
Copyright 2020 Dimitris Mantzouranis

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

enum custom_keycodes {
    GITB = SAFE_RANGE,
    ATM,
    GITSS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GITB:
        if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING("git branch"SS_TAP(X_ENT));
        } else {
          // when keycode is released
        }
        break;

    case ATM:
        if (record->event.pressed) {
          SEND_STRING("atom ."SS_TAP(X_ENT));
        } else {

        }
        break;

    case GITSS:
        if (record->event.pressed) {
          SEND_STRING("git stash save ");
        } else {

        }
        break;
    }
    return true;
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*      Row:         0          1          2          3        4         5        6         7        8        9          10         11         12         13         14         15        */
      [_BASE] = { {   KC_GESC,   KC_1,      KC_2,      KC_3,    KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_INS,    KC_PGUP   },
                  {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,     KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLASH, KC_DEL,    KC_PGDOWN   },
                  {   MO(_FN1),  KC_A,      KC_S,      KC_D,    KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_NO   },
                  {   KC_LSPO,   KC_NO,     KC_Z,      KC_X,    KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSPC,   KC_NO,     KC_UP,     KC_NO },
                  {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,    KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     KC_RALT,   MO(_FN2),  KC_RCTRL,  KC_LEFT,   KC_DOWN,   KC_RGHT   }
                },
      [_FN1] = {  {   KC_GESC,   KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_MPRV, KC_MPLY, KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_TRNS,   KC_NO,     KC_NO    },
                  {   KC_NO,     KC_NO,     KC_NO,  C(KC_DEL),C(KC_BSPC), KC_NO,   KC_NO,  S(KC_MINS),KC_UP,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO  },
                  {   KC_NO,     KC_NO,     KC_NO,     KC_DEL,  KC_BSPC,  KC_NO,  C(KC_LEFT),KC_LEFT, KC_DOWN, KC_RGHT,  C(KC_RGHT), KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO    },
                  {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_MINS, KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO  },
                  {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   KC_TRNS,  KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS    }
               },
      [_FN2] = {  {   KC_GRV,    KC_F1,     KC_F2,     KC_F3,   KC_F4,    KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,     KC_PSCR,   KC_HOME    },
                  {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_MOD,   KC_PAUS,   KC_END  },
                  {   KC_CAPS,   ATM,       GITSS,     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     RGB_SAD,   RGB_SAI,   KC_NO,     KC_NO,     KC_NO,     KC_NO    },
                  {   KC_NO,     KC_NO,     KC_NO,     RGB_TOG, KC_NO,    KC_NO,   GITB,     KC_NO,   KC_NO,   RGB_RMOD,  RGB_MOD,   RGB_TOG,   KC_NO,     KC_NO,     RGB_VAI,   KC_NO  },
                  {   KC_GRV,    KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   RESET,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_HUD,   RGB_VAD,   RGB_HUI    }
               }
};

void keyboard_pre_init_user(void) {
    setPinOutput(B9);  // initialize B9 for LED. Stock - Caps Lock
    setPinOutput(B10);  // initialize B10 for LED. Stock - Fn Lock
    setPinOutput(B11);  // initialize B10 for LED. Stock - Mac/Win
    setPinOutput(B12);  // initialize B10 for LED. Stock - Macro
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _FN1:
        writePinHigh(B11);
        writePinLow(B10);
        writePinLow(B12);
        break;
    case _FN2:
        writePinHigh(B12);
        writePinLow(B10);
        writePinLow(B11);
        break;
    default: //  for any other layers, or the default layer
        writePinHigh(B10);
        writePinLow(B11);
        writePinLow(B12);
        break;
    }
  return state;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
