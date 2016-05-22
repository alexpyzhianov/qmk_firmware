#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   1  |   2  |   3  |   4  |Numlck|           |      |   7  |   8  |   9  |   0  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |  5   |           |   6  |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | RShift |
 * |--------+------+------+------+------+------|CapsL |           | LGui |------+------+------+------+------+--------|
 * |CtrlShft|Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | ~MDIA  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Left | Right|                                       | Down |  Up  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |       |       |
 *                                 ,------|------|------|       |-------+-------+------.
 *                                 |      |      | RAlt |       |  Esc  |       |      |
 *                                 |Space/|BSpace|------|       |-------|  Tab  |Enter/|
 *                                 |~SYMB |      | LAlt |       |  Esc  |       |~SYMB |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,           KC_NO,       KC_1,  KC_2,    KC_3,    KC_4, KC_NUMLOCK,
        KC_NO,           KC_Q,        KC_W,  KC_E,    KC_R,    KC_T,       KC_5,
        KC_LSHIFT,       KC_A,        KC_S,  KC_D,    KC_F,    KC_G,
        LCTL(KC_LSHIFT), CTL_T(KC_Z), KC_X,  KC_C,    KC_V,    KC_B,    KC_CAPS,
        KC_NO,           KC_NO,       KC_NO, KC_LEFT, KC_RGHT,
                                                                    KC_NO, KC_NO,
                                                                         KC_RALT,
                                            LT(SYMB, KC_SPC), KC_BSPACE, KC_LALT,
        // right hand
             KC_NO,   KC_7,   KC_8,    KC_9,    KC_0,   KC_NO,   KC_NO,
             KC_6,    KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_NO,
                      KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RSHIFT,
             KC_LGUI, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, MO(MDIA),
                              KC_DOWN, KC_UP,   KC_NO,  KC_NO,   KC_NO,
             KC_NO, KC_NO,
             KC_ESC,
             KC_ESC, KC_TAB, LT(SYMB, KC_ENT) 
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |  F1  |  F2  |  F3  |  F4  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  \   |  +   |  {   |   }  |  -   |  F5  |           |  F6  |  |   | np7  | np8  | np9  |  "   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |(LShift)|  *   |  %   |  (   |   )  |  =   |------|           |------|  _   | np4  | np5  | np6  |  '   |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   |  !   |  [   |   ]  |  ~   |      |           |      |  &   | np1  | np2  | np3  |  `   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | np0  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |(RAlt)|       |      |      |      |
 *                                 |(HOLD)|      |------|       |------|      |(HOLD)|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_NO,   KC_NO,     KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_NO,
       KC_NO,   KC_BSLASH, KC_PLUS, KC_LCBR, KC_RCBR, KC_MINUS, KC_F5,
       KC_TRNS, KC_ASTR,   KC_PERC, KC_LPRN, KC_RPRN, KC_EQL,
       KC_NO,   KC_HASH,   KC_EXLM, KC_LBRC, KC_RBRC, KC_TILD,  KC_NO,
       KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,
                                                      KC_NO, KC_NO,
                                                             KC_NO,
                                             KC_TRNS, KC_NO, KC_NO,
       // right hand
       KC_NO, KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_NO,
       KC_F6, KC_PIPE, KC_P7,  KC_P8,   KC_P9,   KC_DQT,   KC_NO,
              KC_UNDS, KC_P4,  KC_P5,   KC_P6,   KC_QUOTE, KC_F12,
       KC_NO, KC_AMPR, KC_P1,  KC_P2,   KC_P3,   KC_GRAVE, KC_NO,
                       KC_NO,  KC_NO,   KC_P0,   KC_NO,    KC_NO,
       KC_NO, KC_NO,
       KC_TRNS,
       KC_NO, KC_NO, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|Shtdwn|           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | (HOLD) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Wheel |Wheel |      |       |      | Rclk | Lclk |
 *                                 |up    |down  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO,   KC_MS_U, KC_NO,   KC_NO, KC_NO,
       KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
       KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PWR,
       KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,
                                                      KC_NO,
                          KC_MS_WH_UP, KC_MS_WH_DOWN, KC_NO,
    // right hand
       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_BTN2, KC_BTN1
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSHIFT);
        } else {
          unregister_code(KC_RSHIFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
