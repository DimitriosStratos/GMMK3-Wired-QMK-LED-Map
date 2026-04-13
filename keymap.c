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


// Δημιουργούμε έναν πίνακα για να κρατάμε τη "φόρτιση" κάθε LED
static uint8_t led_charge[RGB_MATRIX_LED_COUNT];

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_is_enabled() || rgb_matrix_get_mode() != RGB_MATRIX_SOLID_COLOR) return false;

    uint8_t v = rgb_matrix_config.hsv.v;
    led_t led_state = host_keyboard_led_state(); // Κατάσταση Lock Keys

    for (uint8_t i = led_min; i < led_max; i++) {
        uint8_t r = 3, g = 255, b = 3; // Βασικό: Πράσινο (Εδώ πήρε το χρώμα το 105!)
        uint8_t react_r = 0, react_g = 0, react_b = 255; // Προεπιλογή ουράς: Μπλε
        float dimmer = 1.0;
        bool is_special = false;

        // --- 1. SIDES, KNOB & GHOSTS ---
        
        // ΑΡΙΣΤΕΡΗ ΠΛΑΪΝΗ ΛΩΡΙΔΑ (105-114) - Πορτοκαλί (Πάνω) -> Κόκκινο (Κάτω)
        if (i >= 105 && i <= 114) { 
            uint8_t step = 114 - i; 
            r = 255;
            g = step * 14; 
            b = 0;
            is_special = true;
        }
        
        // ΔΕΞΙΑ ΠΛΑΪΝΗ ΛΩΡΙΔΑ (115-124) - Κόκκινο (Κάτω) -> Κίτρινο -> Πράσινο (Πάνω)
        else if (i >= 115 && i <= 124) { 
            uint8_t step = i - 115; 
            
            if (step <= 4) { 
                // Κάτω μισό (115-119): Κόκκινο -> Κίτρινο
                r = 255; 
                g = step * 63; // Το πράσινο ανεβαίνει σταδιακά
                b = 0;
            } else { 
                // Πάνω μισό (120-124): Κίτρινο -> Πράσινο
                r = 255 - ((step - 4) * 51); // Το κόκκινο αρχίζει να σβήνει
                g = 255; // Το πράσινο είναι πλέον τέρμα
                b = 0;
            }
            is_special = true;
        }
        
        // ΤΟ KNOB (125) - Λευκό
        else if (i == 125) { 
            r = 255; g = 255; b = 255;
            is_special = true;
        }
        
        // ΣΒΗΣΤΑ ΤΑ "ΦΑΝΤΑΣΜΑΤΑ" (126+)
        else if (i >= 126) { 
            r = 0; g = 0; b = 0;
            is_special = true;
        }

        // --- 2. MATRIX SCAN (Ο Δικός σου Άθικτος Κώδικας) ---
        if (!is_special) {
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                    if (g_led_config.matrix_co[row][col] == i) {
                        uint16_t keycode = keymap_key_to_keycode(0, (keypos_t){.row = row, .col = col});
                        
                        switch (keycode) {
                            case KC_CAPS:
                                if (led_state.caps_lock) { r = 255; g = 0; b = 0; }
                                else { r = 3; g = 255; b = 3; }
                                break;
                            case KC_NUM:
                                if (led_state.num_lock) { r = 255; g = 0; b = 0; }
                                else { r = 1; g = 204; b = 255; }
                                break;
                            case KC_SCRL:
                                if (led_state.scroll_lock) { r = 255; g = 0; b = 0; }
                                else { r = 1; g = 204; b = 255; }
                                break;

                            case KC_ENT:
                                r = 255; g = 0; b = 0; break;

                            case KC_P1 ... KC_P9: 
                            case KC_P0: case KC_PDOT: case KC_PENT:
                            case KC_PSLS: case KC_PAST: case KC_PMNS: case KC_PPLS:
                            case KC_UP: case KC_DOWN: case KC_LEFT: case KC_RGHT:
                            case KC_INS: case KC_HOME: case KC_PGUP: case KC_DEL: case KC_END: case KC_PGDN:
                                r = 1; g = 204; b = 255; 
                                react_r = 255; react_g = 255; react_b = 255; 
                                break;

                            case KC_F1 ... KC_F12:
                            case KC_PSCR: case KC_PAUS:
                                r = 1; g = 204; b = 255; break;

                            case KC_LWIN: case MO(1):
                                r = 255; g = 255; b = 255; break;
                        }

                        // Λογική "Πυκνωτή"
                        if (matrix_is_on(row, col)) {
                            led_charge[i] = 255;
                        } else if (led_charge[i] > 10) {
                            led_charge[i] -= 4;
                        } else {
                            led_charge[i] = 0;
                        }

                        // Εφαρμογή Reactive Εφέ
                        if (led_charge[i] > 0) {
                            uint8_t effect = led_charge[i];
                            r = ((uint32_t)r * (255 - effect) + (react_r * (uint32_t)effect)) / 255;
                            g = ((uint32_t)g * (255 - effect) + (react_g * (uint32_t)effect)) / 255;
                            b = ((uint32_t)b * (255 - effect) + (react_b * (uint32_t)effect)) / 255;
                            dimmer = 1.0;
                        }
                        break;
                    }
                }
            }
        }
        
        rgb_matrix_set_color(i, (uint16_t)r * v * dimmer / 255, (uint16_t)g * v * dimmer / 255, (uint16_t)b * v * dimmer / 255);
    }

    // --- Η "ΒΟΜΒΑ" ΤΟΥ ESC - ΠΑΝΤΑ ΚΟΚΚΙΝΟ (ID 0) ---
    rgb_matrix_set_color(0, 255, 0, 0);

    return false;
}