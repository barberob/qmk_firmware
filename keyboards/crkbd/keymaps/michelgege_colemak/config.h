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

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// custom
    #define AUTO_SHIFT_TIMEOUT 250
#define TAPPING_TERM 180

#define TRACKPOINT_MULTIPLIER 2
#define PS2_MOUSE_X_MULTIPLIER TRACKPOINT_MULTIPLIER
#define PS2_MOUSE_Y_MULTIPLIER TRACKPOINT_MULTIPLIER
#define MOUSEKEY_MOVE_DELTA 6


// #define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE) /* Default */
/* Use remote mode instead of the default stream mode (see link) */

/* Enable the scrollwheel or scroll gesture on your mouse or touchpad */
// #define PS2_MOUSE_ENABLE_SCROLLING 0
#define CAPS_WORD_INVERT_ON_SHIFT


// achordion
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY
#define ACHORDION_STREAK
#define RETRO_TAPPING


// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 3
