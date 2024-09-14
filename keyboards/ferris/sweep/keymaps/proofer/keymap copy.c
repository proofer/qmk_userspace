// brec34 & Ferris Sweep
#include QMK_KEYBOARD_H

enum layers {
    BASE, // Default
    SYM,  // Symbols
    NUM_NAV,  // Numbers & Navigation
    FN,  // Fn keys 1..12
    MISC, // Mouse keys & Reset
};

// keycode macros
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_CMD OSM(MOD_LGUI)
#define KC_MB1 KC_MS_BTN1

// Shift-Space -> Backspace
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_BSPC);
const key_override_t *key_overrides[] = {
	&backspace_key_override
};
#define SPC_BSPC KC_SPACE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_2(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,      KC_P,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,      KC_SCLN,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,    KC_QUOT,
                       KC_LSFT,   LT(NUM_NAV, KC_ESC),     /*|*/     LT(SYM, KC_ENTER),   SPC_BSPC
  ),
  [SYM] = LAYOUT_split_3x5_2(
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   KC_PERC,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   OS_CTRL,   OS_CMD,    OS_ALT,    XXXXXXX,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_TILD,   KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_SLASH,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [NUM_NAV] = LAYOUT_split_3x5_2(
    XXXXXXX,   XXXXXXX,   KC_UP,     KC_TAB,    KC_PGUP,   /*|*/ CW_TOGG,   KC_7,      KC_8,      KC_9,      KC_COMMA,
    XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_DEL,    /*|*/ KC_0,      KC_1,      KC_2,      KC_3,      KC_MINUS,
    XXXXXXX,   OS_ALT,    OS_CMD,    OS_CTRL,   KC_PGDN,   /*|*/ MO(FN),    KC_4,      KC_5,      KC_6,      KC_DOT,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [FN] = LAYOUT_split_3x5_2(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     /*|*/ KC_F11,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   OS_ALT,    OS_CMD,    OS_CTRL,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    /*|*/ KC_F12,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [MISC] = LAYOUT_split_3x5_2(
    C(KC_MB1), A(KC_MB1), G(KC_MB1), S(KC_MB1), XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   TO(BASE),  /*|*/ XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   XXXXXXX,
    QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
};

enum combos{
    fj_MISC_LAYER,
    hj_CTRL_J,      // in insert mode completion drop-down
    we_CTRL_S,      // vim Save
    er_CMD_F,       // browser Find
    xc_CTRL_X,      // vim Close buffer
    cv_CMD_C,       // Copy
    vb_CMD_V,       // Paste

    df_LCTL,
    jk_RCTL,
    sd_LCMD,
    kl_RCMD,
    sf_LOPT,
    jl_ROPT,
};

const uint16_t PROGMEM fj_combo[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM hj_combo[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM we_combo[] = { KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = { KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM xc_combo[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[] = { KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM df_combo[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM sd_combo[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sf_combo[] = { KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM jl_combo[] = { KC_J, KC_L, COMBO_END};

combo_t key_combos[] = {
    [fj_MISC_LAYER] = COMBO(fj_combo, TO(MISC)),
    [hj_CTRL_J]     = COMBO(hj_combo, LCTL(KC_J)),
    [we_CTRL_S]     = COMBO(we_combo, LCTL(KC_S)),
    [er_CMD_F]      = COMBO(er_combo, LCMD(KC_F)),
    [xc_CTRL_X]     = COMBO(xc_combo, LCTL(KC_X)),
    [cv_CMD_C]      = COMBO(cv_combo, LCMD(KC_C)),
    [vb_CMD_V]      = COMBO(vb_combo, LCMD(KC_V)),

    [df_LCTL]       = COMBO(df_combo, KC_LCTL),
    [jk_RCTL]       = COMBO(jk_combo, KC_RCTL),
    [sd_LCMD]       = COMBO(sd_combo, KC_LCMD),
    [kl_RCMD]       = COMBO(kl_combo, KC_RCMD),
    [sf_LOPT]       = COMBO(sf_combo, KC_LOPT),
    [jl_ROPT]       = COMBO(jl_combo, KC_ROPT),
};

