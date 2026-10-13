#pragma once

/* Tap & hold configuration */
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0 // Tap then hold gives the hold action, never auto-repeat of the tap
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* Carried over from the 2020 keyboard config, upstream ships 3 */
#undef DEBOUNCE
#define DEBOUNCE 5

/* RGB defaults, applied whenever EEPROM is fresh (after a flash or EE_CLR) */
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define RGB_MATRIX_DEFAULT_HUE 112 // Teal, 128 is pure cyan and 85 is pure green
#define RGB_MATRIX_DEFAULT_SAT 220
#define RGB_MATRIX_DEFAULT_SPD 95  // Stock default is 127, two RM_SPDD steps of 16 below it
