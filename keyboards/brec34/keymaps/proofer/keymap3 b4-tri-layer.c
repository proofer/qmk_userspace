// brec34 & Ferris Sweep
#include QMK_KEYBOARD_H

enum layers {
    BASE,    // Default
    SYM_P,   // Symbols & KC_P
    NUM_NAV, // Numbers & Navigation
    FN,      // Fn keys 1..12
    MISC,    // Mouse keys & Reset
};

// keycode macros
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_OPT OSM(MOD_LALT)
#define OS_CMD OSM(MOD_LGUI)
#define TL_SYM_P TL_LOWR
#define TL_NUM_NAV TL_UPPR
#define KC_MB1 KC_MS_BTN1

// Shift-Space -> Backspace
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_BSPC);
const key_override_t *key_overrides[] = {
	&backspace_key_override
};
#define SPC_BSPC KC_SPACE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_2(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,      XXXXXXX,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,      XXXXXXX,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,    XXXXXXX,
                       KC_LSFT,   LT(TL_NUM_NAV, KC_ESC)   /*|*/     LT(TL_SYM_P, KC_ENTER),   SPC_BSPC
  ),
  [SYM_P] = LAYOUT_split_3x5_2(
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   XXXXXXX,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   KC_RPRN,   KC_RCBR,   KC_RBRC,   XXXXXXX,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_PERC,   KC_TILD,   KC_SLASH,  KC_P,      XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [NUM_NAV] = LAYOUT_split_3x5_2(
    XXXXXXX,   XXXXXXX,   KC_UP,     CW_TOGG,   KC_PGUP,   /*|*/ XXXXXXX,   KC_7,      KC_8,      KC_9,      XXXXXXXX,
    XXXXXXX,   KC_HOME,   KC_END,    KC_TAB,    KC_DEL,    /*|*/ KC_0,      KC_1,      KC_2,      KC_3,      XXXXXXXX,
    XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,   /*|*/ KC_DOT,    KC_4,      KC_5,      KC_6,      XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [FN] = LAYOUT_split_3x5_2(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     /*|*/ KC_F11,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   OS_OPT,    OS_CMD,    OS_CTRL,   XXXXXXX,   /*|*/ XXXXXXX,   OS_CTRL,   OS_CMD,    OS_OPT,    XXXXXXX,
    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    /*|*/ KC_F12,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [MISC] = LAYOUT_split_3x5_2(
    C(KC_MB1), A(KC_MB1), G(KC_MB1), S(KC_MB1), XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   TO(BASE),  /*|*/ XXXXXXX,   XXXXXXX,   KC_ENTER,  XXXXXXX,   XXXXXXX,
    QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
};

enum combos{
    commadot_QUOT,  // KC_QUOT
    mcomma_SCLN,    // KC_SCLN
    fj_MISC_LAYER,
    ui_CTRL_J,      // next item in insert mode completion drop-down
    we_CTRL_S,      // vim Save
    er_CMD_F,       // browser Find
    xc_CTRL_X,      // vim Close buffer
    cv_CMD_C,       // Copy
    vb_CMD_V,       // Paste

    df_LCTL,           jk_RCTL,
    sd_LCMD,           kl_RCMD,
    fg_LOPT,           hj_ROPT,

    sf_L_CMD_CTL,      jl_R_CMD_CTL,
    sg_L_CMD_OPT,      hl_R_CMD_OPT,
    dg_L_CTL_OPT,      hk_R_CTL_OPT,
    sdf_L_CMD_CTL_OPT, jkl_R_CMD_CTL_OPT,

};

const uint16_t PROGMEM commadot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM sg_combo[] = {KC_S, KC_G, COMBO_END};
const uint16_t PROGMEM hl_combo[] = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM dg_combo[] = {KC_D, KC_G, COMBO_END};
const uint16_t PROGMEM hk_combo[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    [commadot_QUOT] = COMBO(commadot_combo, KC_QUOT),
    [mcomma_SCLN]   = COMBO(mcomma_combo, KC_SCLN),
    [fj_MISC_LAYER] = COMBO(fj_combo, TO(MISC)),
    [ui_CTRL_J]     = COMBO(ui_combo, LCTL(KC_J)),
    [we_CTRL_S]     = COMBO(we_combo, LCTL(KC_S)),
    [er_CMD_F]      = COMBO(er_combo, LCMD(KC_F)),
    [xc_CTRL_X]     = COMBO(xc_combo, LCTL(KC_X)),
    [cv_CMD_C]      = COMBO(cv_combo, LCMD(KC_C)),
    [vb_CMD_V]      = COMBO(vb_combo, LCMD(KC_V)),

    [df_LCTL]       = COMBO(df_combo, KC_LCTL),
    [jk_RCTL]       = COMBO(jk_combo, KC_RCTL),
    [sd_LCMD]       = COMBO(sd_combo, KC_LCMD),
    [kl_RCMD]       = COMBO(kl_combo, KC_RCMD),
    [fg_LOPT]       = COMBO(fg_combo, KC_LOPT),
    [hj_ROPT]       = COMBO(hj_combo, KC_ROPT),

    [sf_L_CMD_CTL]  = COMBO(sf_combo, LCMD(KC_LCTL)),
    [jl_R_CMD_CTL]  = COMBO(jl_combo, RCMD(KC_RCTL)),
    [sg_L_CMD_OPT]  = COMBO(sg_combo, LCMD(KC_LOPT)),
    [hl_R_CMD_OPT]  = COMBO(hl_combo, RCMD(KC_ROPT)),
    [dg_L_CTL_OPT]  = COMBO(dg_combo, LCTL(KC_LOPT)),
    [hk_R_CTL_OPT]  = COMBO(hk_combo, RCTL(KC_ROPT)),
    [sdf_L_CMD_CTL_OPT] = COMBO(sdf_combo, LCMD(LCTL(KC_LOPT))),
    [jkl_R_CMD_CTL_OPT] = COMBO(jkl_combo, RCMD(RCTL(KC_ROPT))),
};

/*layer_state_t layer_state_set_user(layer_state_t state) {*/
/*    return update_tri_layer_state(state, SYM_P, NUM_NAV, FN);*/
/*}*/

bool sym_p_pressed = false;
bool num_nav_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch ( keycode ) {
        case TL_SYM_P:
            if (record->event.pressed) {
                sym_p_pressed = true;
            } else {
                sym_p_pressed = false;
                layer_off(SYM);
                if (num_nav_pressed) {
                    return false;
                }
            }
            return true;
        case TL_NUM_NAV:
            if (record->event.pressed) {
                num_nav_pressed = true;
            } else {
                num_nav_pressed = false;
                layer_off(NAV);
                if (sym_p_pressed) {
                    return false;
                }
            }
            return true;
        default:
            return true;
        };
    return true;
}
