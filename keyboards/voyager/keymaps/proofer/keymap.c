#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#define KC_TRNSP KC_TRANSPARENT

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
 KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_NO,
 KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUOTE, KC_NO,
                 LT(3, KC_BSPC),  LT(2, KC_ENTER),        LT(1, KC_TAB),   MT(MOD_LSFT, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_GRAVE, KC_LABK, KC_RABK, KC_UNDS, KC_QUES, KC_AMPR, KC_LPRN, KC_LCBR, KC_LBRC, KC_PERC, KC_TRNSP,
 KC_TRNSP, KC_EXLM, KC_MINUS, KC_PLUS, KC_EQUAL, KC_HASH, KC_PIPE,  OSM(MOD_LSFT),  OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL), KC_TRNSP,
 KC_TRNSP, KC_CIRC, KC_AT, KC_ASTR, KC_BSLS, KC_DLR, KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_SLASH, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP
  ),
  [2] = LAYOUT_voyager(
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT), KC_DELETE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, CW_TOGG, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP
  ),
  [3] = LAYOUT_voyager(
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11, KC_7, KC_8, KC_9, KC_BSPC, KC_TRNSP,
 KC_TRNSP, OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  TO(0), KC_0, KC_4, KC_5, KC_6, KC_MINUS, KC_TRNSP,
 KC_TRNSP, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12, KC_1, KC_2, KC_3, KC_DOT, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP
  ),
  [4] = LAYOUT_voyager(
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, LCTL( KC_MS_BTN1),LALT( KC_MS_BTN1),LGUI( KC_MS_BTN1),LSFT( KC_MS_BTN1), KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, QK_BOOT, KC_TRNSP,
 KC_TRNSP, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, KC_LEFT_SHIFT,  TO(0), KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP,
 KC_TRNSP, KC_TRNSP, KC_TRNSP, KC_TRNSP
  ),
};

const uint16_t PROGMEM combo0[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_V, KC_B, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, TO(4)),
    COMBO(combo2, LGUI( KC_Z)),
    COMBO(combo3, LGUI( KC_X)),
    COMBO(combo4, LGUI( KC_C)),
    COMBO(combo5, LGUI( KC_V)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255} },

    [1] = { {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142}, {74,222,142} },

    [2] = { {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {169,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



