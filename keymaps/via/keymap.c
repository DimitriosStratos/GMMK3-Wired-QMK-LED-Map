/* Copyright 2024 Glorious, LLC
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

/*
* ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐             ┌───┐
* │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Scr│Pse│             │Mut│ 
* └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘             └───┘ 
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
* │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
* ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
* │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
* ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
* │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │               │ 4 │ 5 │ 6 │   │
* ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
* │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
* ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
* │Ctrl│GUI │Alt │                        │ Alt│ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
* └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
*/

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,    // Base Layer
    _FL,    // Function Layer
    _CL     // Custom Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer (Default Layer) */
    [_BL] = LAYOUT(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,                               KC_MUTE,

        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FL),    KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),

/* Function Layer */
    [_FL] = LAYOUT(
        _______,            KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLD,  KC_VOLU,  QK_REBOOT,   _______,  RESET,  QK_BOOT,                                   _______,

        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                                      _______,  _______,  _______,
        _______,            RGB_SAD,  RGB_SAI,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,            _______,               RGB_VAI,               _______,  _______,  _______,  _______,
        _______,  GU_TOGG,  _______,                                _______,                                _______,  _______,  _______,  _______,     RGB_RMOD, RGB_VAD,  RGB_MOD,     _______,            _______
    ),

    /* Custom Layer */
    [_CL] = LAYOUT(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,                                   _______,

        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                                      _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,               _______,               _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,            _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_CL]   = { ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE


static uint8_t led_charge[RGB_MATRIX_LED_COUNT];

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_is_enabled() || rgb_matrix_get_mode() != RGB_MATRIX_SOLID_COLOR) return false;

    uint8_t v = rgb_matrix_config.hsv.v;
    led_t led_state = host_keyboard_led_state();

    for (uint8_t i = led_min; i < led_max; i++) {
        uint8_t r = 0, g = 200, b = 255; // Βασικό:  (για τα "Others")
        uint8_t react_r = 0, react_g = 0, react_b = 255; // Reactive: ΚΑΘΑΡΟ ΜΠΛΕ
        bool is_special = false;

        // --- 1. LOGO & ΠΛΑΪΝΑ ---
        if (i == 124) { 
            r = 255; g = 40; b = 0; is_special = true; 
        }
        else if (i >= 104 && i <= 123) {
            uint8_t step = (i <= 113) ? (113 - i) : (i - 114);
            r = 255; g = step * 6; b = 0; is_special = true;
        }

        // --- 2. F1-F11  
        else if (i >= 1 && i <= 9)  {
            r = 0; g = 200; b = 255; 
        }
		
		 // --- 2. F10  
        else if (i == 10 )  {
            r = 0; g = 255; b = 0; 
        }
		
		 // --- 2. FF11  
        else if (i == 11)  {
            r = 255; g = 90; b = 0; 
        }
		
		 // --- 2. ΒΕΛΑΚΙΑ - ΓΑΛΑΖΙΟ (CYAN) ---
        else if ((i >= 99 && i <= 101) || (i==86)){
            r = 0; g = 200; b = 255; 
        }

        // --- 3. F12 - ΚΟΚΚΙΝΟ ---
        else if (i == 12) {
            r = 255; g = 0; b = 0;
        }

        // --- 4. NAV CLUSTER (9 ΠΛΗΚΤΡΑ) - ΜΩΒ ---
        else if ((i >= 13 && i <= 15) || (i >= 30 && i <= 32) || (i >= 51 && i <= 53)) {
            r = 150; g = 0; b = 255; 
        }

        // --- 5. WIN (92) & FN (96) 
        else if (i == 92 || i == 96) {
            r = 255; g = 255; b = 255; 
        }

        // --- 6. ALPHAS, NUMBERS 1-0, SPACE 
        else if ((i >= 17 && i <= 26) || (i >= 38 && i <= 49) || (i >= 59 && i <= 69) || 
                 (i >= 75 && i <= 84) || i == 94) {
            r = 0; g = 255; b = 0;
        }

        // --- 7. NUMPAD - 
        else if ((i >= 33 && i <= 36) || (i >= 54 && i <= 57) || (i >= 71 && i <= 73) || 
                 (i >= 87 && i <= 90) || (i >= 102 && i <= 103)) {
            r = 255; g = 90; b = 0; // Άλλαξε αυτές τις τιμές για να αλλάξει μόνο το Numpad
        }

        // --- ΕΚΤΕΛΕΣΗ ΛΟΓΙΚΗΣ LOCKS & REACTIVE ---
        if (!is_special) {
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                    if (g_led_config.matrix_co[row][col] == i) {
                        uint16_t keycode = keymap_key_to_keycode(0, (keypos_t){.row = row, .col = col});
                        
                        // Indicators: Caps, Num, Scroll Lock -> ΚΟΚΚΙΝΟ (Override)
                        if ((keycode == KC_CAPS && led_state.caps_lock) || 
                            (keycode == KC_NUM && led_state.num_lock) ||
                            (keycode == KC_SCRL && led_state.scroll_lock)) {
                            r = 255; g = 0; b = 0;
                        }

                        // Εφέ Πυκνωτή (Reactive)
                        if (matrix_is_on(row, col)) { led_charge[i] = 255; }
                        else if (led_charge[i] > 10) { led_charge[i] -= 3; }
                        else { led_charge[i] = 0; }

                        if (led_charge[i] > 0) {
                            uint8_t effect = led_charge[i];
                            r = ((uint32_t)r * (255 - effect) + (react_r * (uint32_t)effect)) / 255;
                            g = ((uint32_t)g * (255 - effect) + (react_g * (uint32_t)effect)) / 255;
                            b = ((uint32_t)b * (255 - effect) + (react_b * (uint32_t)effect)) / 255;
                        }
                        break;
                    }
                }
            }
        }
        rgb_matrix_set_color(i, (uint16_t)r * v / 255, (uint16_t)g * v / 255, (uint16_t)b * v / 255);
    }
    return false;
}