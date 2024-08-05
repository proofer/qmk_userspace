// Ferris Sweep
#include QMK_KEYBOARD_H

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
  [BASE] = LAYOUT_split_3x5_2(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,      KC_P,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,      KC_SCLN,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,    KC_QUOT,
                       KC_LSFT,          TL_NAV,           /*|*/        TL_SYM,           KC_SPC
  ),
  [SYM] = LAYOUT_split_3x5_2(
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   KC_PERC,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   OS_CTRL,   OS_CMD,    OS_ALT,    OS_SHFT,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_TILD,   KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_SLASH,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [NAV] = LAYOUT_split_3x5_2(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  XXXXXXX,
    OS_SHFT,   OS_ALT,    OS_CMD,    OS_CTRL,   KC_DEL,    /*|*/ KC_TAB,    KC_BSPC,   KC_ENTER,  SW_NEXT,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   CW_TOGG,   /*|*/ XXXXXXX,   KC_PGDN,   KC_PGUP,   XXXXXXX,   XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [NUM] = LAYOUT_split_3x5_2(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     /*|*/ KC_F11,    KC_7,      KC_8,      KC_9,      KC_BSPC,
    OS_SHFT,   OS_ALT,    OS_CMD,    OS_CTRL,   KC_COMMA,  /*|*/ KC_0,      KC_4,      KC_5,      KC_6,      KC_MINUS,
    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    /*|*/ KC_F12,    KC_1,      KC_2,      KC_3,      KC_DOT,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [MISC] = LAYOUT_split_3x5_2(
    C(KC_MB1), A(KC_MB1), G(KC_MB1), S(KC_MB1), XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   TO(BASE),  /*|*/ XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
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
 //   zx_CTRL,
 //   dotquot_CMD,
    shftnav_CTRL,
    symspc_CMD,
};

const uint16_t PROGMEM jk_combo[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM hj_combo[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM xc_combo[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM sd_combo[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = { KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM zx_combo[] = { KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM dotquot_combo[] = { KC_DOT, KC_QUOT, COMBO_END};
const uint16_t PROGMEM shftnav_combo[] = { KC_LSFT, TL_NAV, COMBO_END};
const uint16_t PROGMEM symspc_combo[] = { TL_SYM, KC_SPC, COMBO_END};

combo_t key_combos[] = {
    [jk_ESC]        = COMBO(jk_combo, KC_ESCAPE),
    [fj_MISC_LAYER] = COMBO(fj_combo, TO(MISC)),
    [hj_CTRL_J]     = COMBO(hj_combo, LCTL(KC_J)),
    [sd_CTRL_S]     = COMBO(sd_combo, LCTL(KC_S)),
    [xc_CTRL_X]     = COMBO(xc_combo, LCTL(KC_X)),
    [cv_CMD_C]      = COMBO(cv_combo, LCMD(KC_C)),
    [vb_CMD_V]      = COMBO(vb_combo, LCMD(KC_V)),
    [df_CMD_F]      = COMBO(df_combo, LCMD(KC_F)),
//    [zx_CTRL]       = COMBO(zx_combo, KC_LCTL),
//    [dotquot_CMD]   = COMBO(dotquot_combo, KC_LGUI),
    [shftnav_CTRL]  = COMBO(shftnav_combo, KC_LCTL),
    [symspc_CMD]    = COMBO(symspc_combo, KC_LGUI),
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
