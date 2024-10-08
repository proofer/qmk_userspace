// Corne36
#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers {
    BASE, // Default
    SYM,  // Symbols
    NAV,  // Navigation
    NUM,  // Numbers & Fn keys, n in 1..12
    MISC, // Mouse keys & Reset
};

// keycode macros
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_CMD OSM(MOD_LGUI)
#define KC_MB1 KC_MS_BTN1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,      KC_P,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,      KC_SCLN,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,    KC_QUOTE,
                 MO(NUM),     KC_LSFT,     MO(NAV),         /*|*/        MO(SYM),      KC_SPC,      KC_BSPC
  ),
  [SYM] = LAYOUT_split_3x5_3(
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   KC_PERC,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   OS_CTRL,   OS_CMD,    OS_ALT,    OS_SHFT,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_TILD,   KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_SLASH,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
  [NAV] = LAYOUT_split_3x5_3(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,
    OS_SHFT,   OS_ALT,    OS_CMD,    OS_CTRL,   CW_TOGG,   /*|*/ KC_DEL,    KC_ENTER,  KC_TAB,    XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   KC_PGDN,   KC_PGUP,   XXXXXXX,   XXXXXXX,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
  [NUM] = LAYOUT_split_3x5_3(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     /*|*/ KC_F11,    KC_7,      KC_8,      KC_9,      KC_COMMA,
    OS_SHFT,   OS_ALT,    OS_CMD,    OS_CTRL,   XXXXXXX,   /*|*/ KC_0,      KC_1,      KC_2,      KC_3,      KC_MINUS,
    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    /*|*/ KC_F12,    KC_4,      KC_5,      KC_6,      KC_DOT,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
  [MISC] = LAYOUT_split_3x5_3(
    C(KC_MB1), A(KC_MB1), G(KC_MB1), S(KC_MB1), XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,
    XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   TO(BASE),  /*|*/ XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   XXXXXXX,
    QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                 _______,     _______,     _______,        /*|*/        _______,     _______,     _______
  ),
};

enum combos{
    jk_ESC,
    fj_MISC_LAYER,
    hj_CTRL_J,
    sd_CTRL_S,
    xc_CTRL_X,
    cv_CMD_C,
    vb_CMD_V,
    df_CMD_F,
    zx_CTRL,
    dotquot_CMD,
};

const uint16_t PROGMEM jk_combo[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM hj_combo[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM xc_combo[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM sd_combo[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM zx_combo[] = { KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM dotquot_combo[] = { KC_DOT, KC_QUOT, COMBO_END};

combo_t key_combos[] = {
    [jk_ESC]        = COMBO(jk_combo, KC_ESCAPE),
    [fj_MISC_LAYER] = COMBO(fj_combo, TO(MISC)),
    [hj_CTRL_J]     = COMBO(hj_combo, LCTL(KC_J)),
    [sd_CTRL_S]     = COMBO(sd_combo, LCTL(KC_S)),
    [xc_CTRL_X]     = COMBO(xc_combo, LCTL(KC_X)),
    [cv_CMD_C]      = COMBO(cv_combo, LCMD(KC_C)),
    [vb_CMD_V]      = COMBO(vb_combo, LCMD(KC_V)),
    [df_CMD_F]      = COMBO(df_combo, LCMD(KC_F)),
    [zx_CTRL]       = COMBO(zx_combo, KC_LCTL),
    [dotquot_CMD]   = COMBO(dotquot_combo, KC_LGUI),
};

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
