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

#define COMBO_COUNT 10
#define TAPPING_TERM 180

enum custom_keycodes {
    RARR = SAFE_RANGE,
    EQRARR,
    UPDIR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TG(3),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,    KC_A,    LT(2,KC_S),    MT(MOD_LCTL,KC_D),    MT(MOD_LSFT,KC_F),    MT(MOD_LALT,KC_G),       MT(MOD_LALT,KC_H),    RSFT_T(KC_J),    MT(MOD_LCTL,KC_K),   LT(1, KC_L), KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RALT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                    LT(2,KC_SPC), KC_LSFT, KC_MS_BTN1,                     LT(1,KC_TAB),   LT(3,KC_MS_BTN1), LT(4,KC_ENT)
                                    //`--------------------------'  `--------------------------'

    ),

    [1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,    S(KC_SCLN),    KC_7,    KC_8,    KC_9,    KC_PLUS,                         _______,    _______,    _______,    _______,    _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_BACKSLASH, KC_UNDERSCORE, KC_4, KC_5, KC_6, KC_MINUS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, KC_RALT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_SLSH, KC_1, KC_2, KC_3, KC_EQUAL,                      _______, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, KC_UNDERSCORE,  KC_0,     KC_ENT, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_WWW_BACK, KC_WWW_FORWARD,   _______, UPDIR,  _______, _______,                      KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, KC_CIRCUMFLEX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_WWW_REFRESH, QK_CAPS_WORD_TOGGLE, _______, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, _______,                      KC_PERC,  KC_DLR, KC_LCBR, KC_RCBR, KC_EXLM,  KC_TILD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, EQRARR, RARR, _______,                      KC_PIPE, KC_HASH, KC_LBRC, KC_RBRC, KC_AT, KC_RALT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,  _______,     _______, KC_MS_WH_UP, KC_MS_DOWN
                                        //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_MS_WH_UP,                      _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN,                      _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE,
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
                                            _______, _______,  _______,     _______, _______, _______
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
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
    }

    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {

    switch(tap_hold_keycode) {
        case LT(2,KC_SPC):
        case LT(1,KC_MS_BTN1):
        case LT(3,KC_TAB):
        case LT(4,KC_ENT):
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

const uint16_t PROGMEM backspace_combo[] = { MT(MOD_RSFT,KC_J), MT(MOD_LCTL, KC_K), COMBO_END };
const uint16_t PROGMEM escape_combo[] = { MT(MOD_LSFT,KC_F), MT(MOD_LCTL,KC_D), COMBO_END };
const uint16_t PROGMEM space_combo[] = { LT(2,KC_S), MT(MOD_LCTL,KC_D), COMBO_END };
const uint16_t PROGMEM enter_combo[] = { MT(MOD_LCTL,KC_K), LT(1,KC_L), COMBO_END };
const uint16_t PROGMEM click_combo[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM click_combo_2[] = { KC_U, MT(MOD_RSFT,KC_J), COMBO_END };
const uint16_t PROGMEM click_combo_3[] = { MT(MOD_LSFT,KC_F), KC_R, COMBO_END };
const uint16_t PROGMEM scroll_down_combo[] = {  MT(MOD_LALT,KC_G), KC_B, COMBO_END };
const uint16_t PROGMEM scroll_up_combo[] = {  MT(MOD_LALT,KC_G), KC_T, COMBO_END };
const uint16_t PROGMEM middle_click_combo[] = { KC_E, MT(MOD_LCTL,KC_D), COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(backspace_combo, KC_BSPC),
    COMBO(escape_combo, KC_ESC),
    COMBO(space_combo, KC_SPC),
    COMBO(enter_combo, KC_ENT),
    COMBO(click_combo, KC_MS_BTN1),
    COMBO(click_combo_2, KC_MS_BTN1),
    COMBO(click_combo_3, KC_MS_BTN1),
    COMBO(scroll_down_combo, KC_MS_WH_DOWN),
    COMBO(scroll_up_combo, KC_MS_WH_UP),
    COMBO(middle_click_combo, KC_MS_BTN3),
};
