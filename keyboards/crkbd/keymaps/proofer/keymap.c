// Corne36
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "swapper.h"

enum layers {
    BASE, // Default
    SYM,  // Symbols
    NAV,  // Navigation
    NUM,  // Numbers & Fn keys, n in 1..12
    MISC, // Mouse keys & Reset
};

enum keycodes {
    SW_NEXT = SAFE_RANGE, // Switch to next desktop (cmd-tab)
};

// keycode macros
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_CMD OSM(MOD_LGUI)
#define KC_MB1 KC_MS_BTN1
#define TL_SYM TL_LOWR
#define TL_NAV TL_UPPR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,      KC_P,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,      KC_SCLN,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,    KC_QUOTE,
                 KC_LCMD,     KC_LSFT,     TL_NAV,         /*|*/        TL_SYM,      KC_SPC,      KC_BSPC
  ),
  [SYM] = LAYOUT_split_3x5_3(
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   KC_PERC,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   OS_CTRL,   OS_CMD,    OS_ALT,    OS_SHFT,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_TILD,   KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_SLASH,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
  [NAV] = LAYOUT_split_3x5_3(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,
    OS_SHFT,   OS_ALT,    OS_CMD,    OS_CTRL,   CW_TOGG,   /*|*/ KC_DEL,    KC_ENTER,  KC_TAB,    SW_NEXT,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   KC_PGDN,   KC_PGUP,   XXXXXXX,   XXXXXXX,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
  [NUM] = LAYOUT_split_3x5_3(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     /*|*/ KC_F11,    KC_7,      KC_8,      KC_9,      XXXXXXX,
    OS_SHFT,   OS_ALT,    OS_CMD,    OS_CTRL,   KC_COMMA,  /*|*/ KC_0,      KC_4,      KC_5,      KC_6,      KC_MINUS,
    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    /*|*/ KC_F12,    KC_1,      KC_2,      KC_3,      KC_DOT,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
  [MISC] = LAYOUT_split_3x5_3(
    C(KC_MB1), A(KC_MB1), G(KC_MB1), S(KC_MB1), XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,
    XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   TO(BASE),  /*|*/ XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   XXXXXXX,
    QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
};

const uint16_t PROGMEM combo0[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_Z, KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, TO(MISC)),
    COMBO(combo2, LCTL(KC_S)),      // vim save
    COMBO(combo3, LCTL(KC_X)),      // vim delete buffer
    COMBO(combo4, LCTL(KC_J)),      // vim next in completion drop-down
};

bool sw_desk_active = false;
bool sym_pressed = false;
bool nav_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_desk_active, KC_LCMD, KC_TAB, SW_NEXT,
        keycode, record
    );
    switch ( keycode ) {
        case TL_SYM:
            if (record->event.pressed) {
                sym_pressed = true;
            } else {
                sym_pressed = false;
                layer_off(SYM);
                if (nav_pressed) {
                    return false;
                }
            }
            return true;
        case TL_NAV:
            if (record->event.pressed) {
                nav_pressed = true;
            } else {
                nav_pressed = false;
                layer_off(NAV);
                if (sym_pressed) {
                    return false;
                }
            }
            return true;
        default:
            return true;
        };
    return true;
}

void set_hsv_all(uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv;
    RGB rgb;

    hsv.h = h; hsv.s = s; hsv.v = rgb_matrix_get_val();
    rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_user(void) {
#ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case BASE:
            set_hsv_all(HSV_BLUE);
            break;
        case SYM:
            set_hsv_all(HSV_ORANGE);
            break;
        case NAV:
            set_hsv_all(HSV_MAGENTA);
            break;
        case NUM:
            set_hsv_all(HSV_GREEN);
            break;
        case MISC:
            set_hsv_all(HSV_RED);
            break;
    }
#endif
    return false;
}
