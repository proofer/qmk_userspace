/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

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

#define SPLIT_USB_DETECT   // default for ARM
#define MASTER_LEFT

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

// Pick good defaults for enabling homerow modifiers
// #define TAPPING_TERM 300
// #define PERMISSIVE_HOLD
// #define QUICK_TAP_TERM 0

#define COMBO_COUNT 6

#ifdef RGB_MATRIX_ENABLE
// The following two redefintions are commented out pending a 36-key rgb matrix
// #define RGBLIGHT_LED_COUNT 48       // Total number of RGB LEDs for keys and underglow
// #define RGB_MATRIX_SPLIT { 24, 24 } // Number of LEDs on each half
// #   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_MATRIX_SLEEP // turn off effects when suspended
// #   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limit number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limit in ms frequency of animation updating LEDs. 16 ms is equivalent to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limit max brightness (range 0..255). Higher may cause controller crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#endif


