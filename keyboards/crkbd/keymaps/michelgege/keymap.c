/*
Copyright 2019 @foostan
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
#include "features/achordion.h"

#define TAPPING_TERM 180

#define __S LT(2,KC_S)
#define __D MT(MOD_LCTL,KC_D)
#define __F MT(MOD_LSFT,KC_F)
#define __G MT(MOD_LALT,KC_G)
#define __H MT(MOD_LALT,KC_H)
#define __J MT(MOD_RSFT,KC_J)
#define __K MT(MOD_LCTL,KC_K)
#define __L LT(1,KC_L)
#define __QUOT LT(4, KC_QUOT)
#define __M LT(2, KC_M)

#define __THUMB_LEFT_1 LT(1, KC_SPC)
#define __THUMB_LEFT_2 MT(MOD_LCTL, KC_SPC)
#define __THUMB_LEFT_3 MT(MOD_LSFT, KC_SPC)
#define __THUMB_RIGHT_3 MT(MOD_LSFT, KC_TAB)
#define __THUMB_RIGHT_2 MT(MOD_LCTL, KC_SPC)
#define __THUMB_RIGHT_1 LT(4,KC_ENT)

enum custom_keycodes {
    RARR = SAFE_RANGE,
    EQRARR,
    THIS,
    ATTR_EQ,
    ALT_BACKTICK,
    AGRAVE,
    EGRAVE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // qwerty
    [0] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_CAPS_WORD_TOGGLE,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB,    LT(1, KC_A),    __S,   __D,    __F,    __G,                                __H,    __J,   __K,    __L, LT(3, KC_SCLN), __QUOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    __M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RALT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            __THUMB_LEFT_1, __THUMB_LEFT_2, __THUMB_LEFT_3,                     __THUMB_RIGHT_3,   __THUMB_RIGHT_2, __THUMB_RIGHT_1
                                      //`--------------------------'  `--------------------------'

    ),

    [1] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,    S(KC_SCLN),    KC_7,    KC_8,    KC_9,    KC_PLUS,                         _______,    _______,    _______,    _______,    _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_BACKSLASH, KC_UNDERSCORE, KC_4, KC_5, KC_6, KC_MINUS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, KC_RALT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_SLSH, KC_0, KC_1, KC_2, KC_3, KC_EQUAL,                      CW_TOGG, KC_BSPC, KC_ENT, KC_ESC, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LCTL, KC_DOT,  KC_0,     KC_ENT, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_WWW_BACK, KC_WWW_FORWARD,   _______, EGRAVE,  _______, _______,                      KC_AMPR, KC_HASH, KC_LPRN, KC_RPRN, KC_GRV, KC_CIRCUMFLEX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_WWW_REFRESH, AGRAVE, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, ALT_BACKTICK, _______,                      KC_PERC,  KC_DLR, KC_LCBR, KC_RCBR, KC_EXLM,  KC_TILD,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, ALT_BACKTICK, ATTR_EQ, EQRARR, RARR, THIS,                      KC_PIPE, KC_ASTR, KC_LBRC, KC_RBRC, KC_AT, KC_RALT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,  _______,     KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_DOWN
                                          //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, _______,                      _______, _______ ,_______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, QK_CAPS_WORD_TOGGLE, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,                      _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_MS_WH_UP, KC_MS_BTN3, KC_MS_WH_DOWN, _______,                      _______, _______, _______, _______, KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_MS_BTN3, KC_MS_BTN2,  KC_MS_BTN1,     _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [4] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, _______, KC_F7, KC_F8, KC_F9, KC_F12,                      KC_PRINT_SCREEN, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_F4, KC_F5, KC_F6, KC_F11,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_F1, KC_F2, KC_F3, KC_F10,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,  _______,QK_CAPS_WORD_TOGGLE,     _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
        case RARR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case EQRARR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
        case THIS:
            if (record->event.pressed) {
                SEND_STRING("$this->");
            }
            return false;
        case ATTR_EQ:
            if (record->event.pressed) {
                SEND_STRING("=\"\"");
                tap_code(KC_LEFT);
            }
            return false;
        case ALT_BACKTICK:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`"));
            }
            return false;
        case AGRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`"));
                SEND_STRING("a");
            }
            return false;
        case EGRAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("`"));
                SEND_STRING("e");
            }
            return false;
    }

    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    switch(tap_hold_keycode) {
        case __THUMB_LEFT_1:
        // case __THUMB_LEFT_2: // pareil que thumb_right_2
        case __THUMB_LEFT_3:
        case __THUMB_RIGHT_3:
        case __THUMB_RIGHT_2:
        case __THUMB_RIGHT_1:
            return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 500;
}

void matrix_scan_user(void) {
    achordion_task();
}

// Define combo arrays separately
const uint16_t PROGMEM backspace_combo[] = { __J, __K, COMBO_END };
const uint16_t PROGMEM escape_combo[] = { __F, __D, COMBO_END };
const uint16_t PROGMEM enter_combo[] = { __K, __L, COMBO_END };
const uint16_t PROGMEM space_combo[] = { __F, __J, COMBO_END };
const uint16_t PROGMEM space_combo2[] = { __S, __D, COMBO_END };
const uint16_t PROGMEM click_combo_2[] = { KC_U, __J, COMBO_END };
const uint16_t PROGMEM click_combo_3[] = { __F, KC_R, COMBO_END };
const uint16_t PROGMEM click_combo_4[] = { __F, KC_V, COMBO_END };
const uint16_t PROGMEM click_combo_5[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM click_combo_6[] = { __M, KC_COMM, COMBO_END };
const uint16_t PROGMEM middle_click_combo[] = { KC_E, __D, COMBO_END };
const uint16_t PROGMEM right_click_combo[] = { __G, KC_T, COMBO_END };
const uint16_t PROGMEM right_click_combo2[] = { __H, KC_Y, COMBO_END };
const uint16_t PROGMEM scroll_down_combo[] = { __G, KC_B, COMBO_END };
const uint16_t PROGMEM scroll_up_combo[] = { KC_X, KC_C, COMBO_END };
// Initialize the key_combos array using the pre-defined arrays
combo_t key_combos[] = {
    COMBO(backspace_combo, KC_BSPC),
    COMBO(escape_combo, KC_ESC),
    COMBO(enter_combo, KC_ENT),
    COMBO(space_combo, KC_SPC),
    COMBO(space_combo2, KC_SPC),
    COMBO(click_combo_2, KC_MS_BTN1),
    COMBO(click_combo_3, KC_MS_BTN1),
    COMBO(click_combo_4, KC_MS_BTN1),
    COMBO(click_combo_5, KC_MS_BTN1),
    COMBO(click_combo_6, KC_MS_BTN1),
    COMBO(middle_click_combo, KC_MS_BTN3),
    COMBO(right_click_combo, KC_MS_BTN2),
    COMBO(right_click_combo2, KC_MS_BTN2),
    COMBO(scroll_down_combo, KC_MS_WH_DOWN),
    COMBO(scroll_up_combo, KC_MS_WH_UP),
};

// Automatically calculate the combo count
#define COMBO_COUNT (sizeof(key_combos) / sizeof(key_combos[0]))
