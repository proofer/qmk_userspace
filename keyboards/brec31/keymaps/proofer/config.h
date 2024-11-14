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
// #define SPLIT_LAYER_STATE_ENABLE  // causes non-USB half to be in coma

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
//moved to keyboard.json: #define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
//***********moved to keyboard.json: #define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try to make this as low as possible while keeping the cursor responsive
//***********moved to keyboard.json: #define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
//***********moved to keyboard.json: d#efine MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
// #define PERMISSIVE_HOLD
// #define QUICK_TAP_TERM 0

#define COMBO_MUST_HOLD_MODS
#define COMBO_ONLY_FROM_LAYER 0
#define EE_HANDS


