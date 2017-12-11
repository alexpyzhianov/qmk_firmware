#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   1  |   2  |   3  |   4  |      |           |      |   7  |   8  |   9  |   0  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Q/Й  | W/Ц  | E/У  | R/К  | T/Е  |  5   |           |   6  | Y/Н  | U/Г  | I/Ш  | O/Щ  | P/З  |  [/Х   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift | A/Ф  | S/Ы  | D/В  | F/А  | G/П  |------|           |------| H/Р  |J/О/~M| K/Л  | L/Д  | ;/Ж  |'/Э/RSht|
 * |--------+------+------+------+------+------| Home |           | Del  |------+------+------+------+------+--------|
 * |Ctl+Shft|Z/Я/LC| X/Ч  | C/С  | V/М  | B/И  |      |           |      | N/Т  | M/Ь  | ,/Б  | ./Ю  |//./RC|  ]/Ъ   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Left | Right|                                       | Down |  Up  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      | LGui |       | Caps  |       |
 *                                 ,------|------|------|       |-------+-------+------.
 *                                 |      |      |      |       |       |       |      |
 *                                 |Space/|BSpace|------|       |-------|  Tab  |Enter/|
 *                                 |~SYMB |      | LAlt |       |  Esc  |       |~SYMB |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_NO,           KC_NO,        KC_1,  KC_2,    KC_3,    KC_4,   KC_NO,
        KC_NO,           KC_Q,         KC_W,  KC_E,    KC_R,    KC_T,   KC_5,
        KC_LSHIFT,       KC_A,         KC_S,  KC_D,    KC_F,    KC_G,
        LCTL(KC_LSHIFT), LCTL_T(KC_Z), KC_X,  KC_C,    KC_V,    KC_B,   KC_HOME,
        KC_NO,           KC_NO,        KC_NO, KC_LEFT, KC_RGHT,
                                                                KC_NO, KC_LGUI,
                                                                       KC_NO,
                                        LT(SYMB, KC_SPC), KC_BSPACE, KC_LALT,
        // right hand
             KC_NO,   KC_7,   KC_8,           KC_9,    KC_0,    KC_NO,           KC_NO,
             KC_6,    KC_Y,   KC_U,           KC_I,    KC_O,    KC_P,            KC_LBRC,
                      KC_H,   LT(MDIA, KC_J), KC_K,    KC_L,    KC_SCLN,         RSFT_T(KC_QUOTE),
             KC_DELT, KC_N,   KC_M,           KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RBRC,
                              KC_DOWN,        KC_UP,   KC_NO,   KC_NO,           KC_NO,
             KC_CAPSLOCK, KC_NO,
             KC_NO,
             KC_ESC, KC_TAB, LT(SYMB, KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |  F1  |  F2  |  F3  |  F4  |      |           |      |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  \   |  (   |   )  |  +   |  F5  |           |  F6  |  !   |  $   |  #   |  "   |  %   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ^   |  |   |  {   |   }  |  *   |------|           |------|  -   |  =   |  ~   |  '   |  _   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |(LCtl)|  /   |  [   |   ]  |      |      |           |      |      |  &   |  @   |  `   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |  <   |   >  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |(HOLD)|      |------|       |------|      |(HOLD)|
 *                                 |      |      |(LAlt)|       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,   KC_NO,    KC_F1,     KC_F2,   KC_F3,   KC_F4,    KC_NO,
       KC_NO,   KC_NO,    KC_BSLASH, KC_LPRN, KC_RPRN, KC_PLUS,  KC_F5,
       KC_NO,   KC_CIRC,  KC_PIPE,   KC_LCBR, KC_RCBR, KC_ASTR,
       KC_NO,   KC_TRNS,  KC_SLASH,  KC_LBRC, KC_RBRC, KC_NO,    KC_NO,
       KC_NO,   KC_NO,    KC_NO,     KC_LT,   KC_GT,
                                                      KC_NO, KC_NO,
                                                             KC_NO,
                                           KC_TRNS, KC_NO, KC_TRNS,
       // right hand
       KC_NO,  KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
       KC_F6,  KC_EXLM,  KC_DLR,  KC_HASH, KC_DQT,   KC_PERC,   KC_NO,
               KC_MINS,  KC_EQL,  KC_TILD, KC_QUOTE, KC_UNDS, KC_NO,
       KC_NO,  KC_NO,    KC_AMPR, KC_AT,   KC_GRAVE, KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
       KC_NO,  KC_NO,
       KC_PGUP,
       KC_PGDN, KC_NO, KC_TRNS
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
[MDIA] = LAYOUT_ergodox(
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
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
