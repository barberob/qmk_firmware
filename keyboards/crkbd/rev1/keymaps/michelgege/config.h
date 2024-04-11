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

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// custom
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define AUTO_SHIFT_TIMEOUT 250
#define TAPPING_TERM 180

#define TRACKPOINT_MULTIPLIER 4
#define PS2_MOUSE_X_MULTIPLIER TRACKPOINT_MULTIPLIER
#define PS2_MOUSE_Y_MULTIPLIER TRACKPOINT_MULTIPLIER
#define CAPS_WORD_INVERT_ON_SHIFT
