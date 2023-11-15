#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

enum layer_number {
  _QWERTY = 0,
  _COLEMAK
  _ADJUST,
  _QMK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  A   |  S   |  D   |  F   |  G   |-------.    ,-------|  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| [|ADJ |    | ]|ADJ |------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  V   |  B   |-------|    |-------|  N   |  M   |  ,   |  .   |  /   |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | Del  | /Space  /       \Enter \  |BackSP| Left |Right |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,  KC_2,     KC_3,     KC_4,    KC_5,                                                  KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,  KC_W,     KC_E,     KC_R,    KC_T,                                                  KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,  KC_S,     KC_D,     KC_F,    KC_G,                                                  KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,  KC_X,     KC_C,     KC_V,    KC_B,    LT(_ADJUST, KC_LBRC),  LT(_ADJUST, KC_RBRC),  KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                   KC_LGUI,  KC_LALT,  KC_DEL,  KC_SPC,                                                KC_ENT,  KC_BSPC,  KC_LEFT,  KC_RGHT
),
/* COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  F   |  P   |  B   |                    |  J   |  L   |  U   |  Y   |  ;   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  A   |  R   |  S   |  T   |  G   |-------.    ,-------|  M   |  N   |  E   |  I   |  O   |  '   |
 * |------+------+------+------+------+------| [|ADJ |    | ]|ADJ |------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  D   |  V   |-------|    |-------|  K   |  H   |  ,   |  .   |  /   |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | Del  | /Space  /       \Enter \  |BackSP| Left |Right |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,  KC_2,     KC_3,     KC_4,    KC_5,                                                  KC_6,    KC_7,     KC_8,     KC_9,    KC_0,     KC_EQL,
  KC_TAB,   KC_Q,  KC_W,     KC_F,     KC_P,    KC_B,                                                  KC_J,    KC_L,     KC_U,     KC_Y,    KC_SCLN,  KC_MINS,
  KC_LCTL,  KC_A,  KC_R,     KC_S,     KC_T,    KC_G,                                                  KC_M,    KC_N,     KC_E,     KC_I,    KC_O,     KC_QUOT,
  KC_LSFT,  KC_Z,  KC_X,     KC_C,     KC_D,    KC_V,    LT(_ADJUST, KC_LBRC),  LT(_ADJUST, KC_RBRC),  KC_K,    KC_H,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                   KC_LGUI,  KC_LALT,  KC_DEL,  KC_SPC,                                                KC_ENT,  KC_BSPC,  KC_LEFT,  KC_RGHT
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |MODE+ | BRT+ | Sat+ | Hue+ |RGB ON|-------.    ,-------| NumL |  \   |  Up  | Ins  | Home | PgUp |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|Swirl |Rainb |Breath|Plain | QMK  |-------|    |-------| QMK  | Left | Down |Right | End  | PgDn |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | Del  | /Space  /       \Enter \  |BackSP| Left |Right |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  KC_GRV,   KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,                         KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_CAPS,  KC_P1,     KC_P2,    KC_P3,    KC_P4,    KC_P5,                         KC_P6,     KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_F12,
  _______,  RGB_MOD,   RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_TOG,                       KC_NUM,    KC_BSLS,  KC_UP,    KC_INS,   KC_HOME,  KC_PGUP,
  _______,  RGB_M_SW,  RGB_M_R,  RGB_M_B,  RGB_M_P,  MO(_QMK),  XXXXXXX,  XXXXXXX,  MO(_QMK),  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   KC_PGDN,
                       _______,  _______,  _______,  _______,                       _______,   _______,  _______,  _______
),
/* QMK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |EEPROM|      |      |      |RGB ON|                    |RGB ON|      |      |      |EEPROM|RESET |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |QWERTY|COLEMK|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QMK] = LAYOUT(
  QK_BOOT,  EE_CLR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_TOG,                      RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EE_CLR,       QK_BOOT,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DF(_QWERTY),  DF(_COLEMAK),
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  } else {
    return OLED_ROTATION_270;
  }
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
char keylog_str[24] = {};
const char *read_logo(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

//https://github.com/laosteven/fluffy-octo-eureka/blob/master/oled.c
void set_keylog(uint16_t keycode, keyrecord_t *record) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
      keycode = keycode & 0xFF;
  } else if (keycode > 0xFF) {
      keycode = 0;
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "[MTX] %dx%d [KYC] %03d\n",
          record->event.key.row, record->event.key.col,
          keycode);
}

void oled_render_keylog(void) {
    if (strlen(keylog_str) == 0) {
        snprintf(keylog_str, sizeof(keylog_str), "[MTX] 0x0 [KYC] 000 ");
    }
    oled_write(keylog_str, false);
}

//OLED layout
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    //Layer Indicator
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state | default_layer_state)) { 
      case _QWERTY:
        oled_write_P(PSTR("[QWR]"), false);
        break;
      case _COLEMAK:
        oled_write_P(PSTR("[CMK]"), false);
        break;
      case _ADJUST:
        oled_write_P(PSTR("[ADJ]"), false);
        break;
      case _QMK:
        oled_write_P(PSTR("[QMK]"), false);
        break;
      default:
        oled_write_P(PSTR("[UDF]"), false);
    }    

    //Matrix Coordinate & Keycode
    oled_write_P(PSTR("-----"), false); 
    oled_render_keylog();

    //Caps and Num Lock Indicator
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM +") : PSTR("NUM -"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP +") : PSTR("CAP -"), false);

    //Mode/HSV Indicator
    oled_write_P(PSTR("-----"), false);
    static char led_buf[30];
    snprintf(led_buf, sizeof(led_buf) - 1, "M: %2dH: %2dS: %2dV: %2d\n",
        (uint8_t)rgblight_get_mode(),
        (uint8_t)(rgblight_get_hue() / RGBLIGHT_HUE_STEP),
        (uint8_t)(rgblight_get_sat() / RGBLIGHT_SAT_STEP),
        (uint8_t)(rgblight_get_val() / RGBLIGHT_VAL_STEP));
    oled_write(led_buf, false);    
  
  } else {
    //Lily58 Logo
    oled_write(read_logo(), false);
  }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
