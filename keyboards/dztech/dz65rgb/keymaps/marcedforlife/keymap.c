#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
        CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_DEL,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_MPLY,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        KC_GRV,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_PSCR,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,   KC_PGUP,
        CTL_T(KC_CAPS), RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, KC_PGDN,
        KC_LSFT,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        _______,        _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};

/* Timers for numberic keys for detecting hold events
static uint16_t fn_key_timer[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
*/
static uint16_t esc_key_timer = -1;

/**
 * Listens for user input events
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
        case KC_ESC: {
            if (record->event.pressed) {
                esc_key_timer = timer_read();
            } else if (esc_key_timer != -1) {
                esc_key_timer = -1;
                tap_code(KC_ESC);
            }
            return false;
        }
        /* Disabled numeric F keys on hold
        case KC_1 ... KC_0: {
            uint8_t index = keycode - KC_1;
            if (record->event.pressed) {
                fn_key_timer[index] = timer_read();
            } else if (fn_key_timer[index] != -1) {
                fn_key_timer[index] = -1;
                tap_code(KC_1 + index);
            }
            return false;
        }
        */
    }
    return true;
}

/**
 * Should avoid using this but it allows sending hold key events without releasing the held key
 */
void matrix_scan_user(void) {
    if(esc_key_timer != -1 && timer_elapsed(esc_key_timer) > TAPPING_TERM) {
        esc_key_timer = -1;
        tap_code(KC_GRV);
    }
    /* Disabled numeric F keys on hold
    int index;
    for (index = 0; index < 10; index++) {
        if(fn_key_timer[index] != -1 && timer_elapsed(fn_key_timer[index]) > TAPPING_TERM) {
            fn_key_timer[index] = -1;
            tap_code(KC_F1 + index);
        }
    }
    */
}
