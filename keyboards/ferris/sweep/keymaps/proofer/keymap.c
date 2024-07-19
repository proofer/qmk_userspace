#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define KC_MB1 KC_MS_BTN1

enum layers {
    BASE, // Default
    SYM,  // Symbols
    NAV,  // Navigation
    NUM,  // Numbers & Fn keys, n in 1..12
    MODS, // Mod keys & Reset
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_NEXT, // Switch to next desktop (cmd-tab)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_2(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,      KC_P,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,      KC_SCLN,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,    KC_QUOTE,
           LT(NUM,KC_BSPC),      LT(NAV,KC_ENTER),         /*|*/       LT(SYM,KC_TAB),      MT(MOD_LSFT, KC_SPACE)
  ),
  [SYM] = LAYOUT_split_3x5_2(
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   KC_PERC,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   OS_SHFT,   OS_CMD,    OS_ALT,    OS_CTRL,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_TILD,   KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_SLASH,
           ______,               _______,                  /*|*/        _______,            _______
  ),
  [NAV] = LAYOUT_split_3x5_2(
    _______,   _______,   _______,   _______,   _______,   /*|*/ _______,   _______,   KC_PGUP,   _______,   _______,
    OS_CTRL,   OS_ALT,    OS_CMD,    OS_SHFT,   KC_DELETE, /*|*/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  SW_NEXT,
    _______,   _______,   _______,   _______,   CW_TOGG,   /*|*/ _______,   KC_PGDN,   _______,   _______,   _______,
           ______,               _______,                  /*|*/        _______,            _______
  ),
  [NUM] = LAYOUT_split_3x5_2(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     /*|*/ KC_F11,    KC_7,      KC_8,      KC_9,      KC_BSPC,
    OS_SHFT,   OS_CTRL,   OS_ALT,    OS_CMD,    TO(0),     /*|*/ KC_0,      KC_4,      KC_5,      KC_6,      KC_MINUS,
    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    /*|*/ KC_F12,    KC_1,      KC_2,      KC_3,      KC_DOT,
           ______,               _______,                  /*|*/        _______,            _______
  ),
  [MODS] = LAYOUT_split_3x5_2(
    C(KC_MB1), A(KC_MB1), G(KC_MB1), S(KC_MB1), _______,   /*|*/ _______,   _______,   _______,   _______,   QK_BOOT,
    KC_LCTL,   KC_LALT,   KC_LCMD,   KC_LSFT,   TO(0),     /*|*/ _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   /*|*/ _______,   _______,   _______,   _______,   _______,
           ______,               _______,                  /*|*/        _______,            _______
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
    COMBO(combo2, LCMD(KC_Z)),
    COMBO(combo3, LCMD(KC_X)),
    COMBO(combo4, LCMD(KC_C)),
    COMBO(combo5, LCMD(KC_V)),
};

/*#define LA_SYM MO(SYM)*/
/*#define LA_NAV MO(NAV)*/

bool is_oneshot_cancel_key(uint16_t keycode) {
    /*switch (keycode) {*/
    /*case LA_SYM:*/
    /*case LA_NAV:*/
    /*    return true;*/
    /*default:*/
    /*    return false;*/
    /*}*/
    return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

// bool sw_win_active = false;
bool sw_desk_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_desk_active, KC_LCMD, KC_TAB, SW_NEXT,
        keycode, record
    );
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    ukkkdate_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}
