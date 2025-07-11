// brec32 -- PCBs have 34 key positions but right pinky column top and bottomm key switches removed
#include QMK_KEYBOARD_H
#include ".&email.h" // defines EMAIL_ADDR and PHONE_NBR

enum layers {
    BASE,    // Default
    SYM,     // Symbols & KC_P
    NUM_NAV, // Numbers & Navigation
    FN_MS,   // Fn keys 1..12; access via SYM;  TODO: mouse buttons and movement
    RESET,   // for flashing new firmware
};

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    PHONE,
};

#define KC_MB1 KC_MS_BTN1

// Shift-Space -> Backspace
// Requires `#KEY_OVERRIDE_ENABLE = yes` in rules.mk, which must be removed if no overrides here.
// const key_override_t backspace_key_override =
//     ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SPACE, KC_BSPC, ~0, MOD_MASK_CAG);
// const key_override_t *key_overrides[] = {
// 	&backspace_key_override
// };
// #define SPC_BSPC KC_SPACE
// Problem with this override: unintended deletion of just-typed shifted character

enum tap_dance_keys {
    // rationale: was accidentally tapping the LT(SYM, KC_ENTER) thumb key, unintenionally posting/sending
    ENTER_SYM,      // tap: same as LSFT(KC_ENTER); double-tap: KC_ENTER; hold: same as MO(SYM)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_2(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      /*|*/ KC_Y,      KC_U,     KC_I,       KC_O,    XXXXXXX,
    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /*|*/ KC_H,      KC_J,     KC_K,       KC_L,    KC_BSPC,
    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      /*|*/ KC_N,      KC_M,     KC_COMMA,   KC_DOT,  XXXXXXX,
                       KC_LSFT,   TD(ENTER_SYM),           /*|*/     MO(NUM_NAV),   KC_SPACE  //SPC_BSPC
  ),
  [SYM] =  LAYOUT_split_3x5_2(  /**** could require Shift as in QUERTY: <>?_+{}|~ ****/
    KC_GRAVE,  KC_LABK,   KC_RABK,   KC_UNDS,   KC_QUES,   /*|*/ KC_AMPR,   KC_LPRN,   KC_LCBR,   KC_LBRC,   XXXXXXX,
    KC_EXLM,   KC_MINUS,  KC_PLUS,   KC_EQUAL,  KC_HASH,   /*|*/ KC_PIPE,   KC_RPRN,   KC_RCBR,   KC_RBRC,   _______,
    KC_CIRC,   KC_AT,     KC_ASTR,   KC_BSLS,   KC_DLR,    /*|*/ KC_PERC,   KC_TILD,   KC_SLASH,  MO(FN_MS), XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [NUM_NAV] = LAYOUT_split_3x5_2(
    PHONE,     KC_HOME,   KC_UP,     KC_CAPS,   KC_PGUP,   /*|*/ KC_MINUS,  KC_7,      KC_8,      KC_9,    XXXXXXX,
    EMAIL,     KC_END,    S(KC_TAB), KC_TAB,    KC_DEL,    /*|*/ KC_0,      KC_1,      KC_2,      KC_3,    _______,
    KC_RSFT,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,   /*|*/ KC_DOT,    KC_4,      KC_5,      KC_6,    XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [FN_MS] = LAYOUT_split_3x5_2(
    XXXXXXX,   KC_F9,     KC_F8 ,    KC_F7,     KC_F12,    /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
    XXXXXXX,   KC_F3,     KC_F2,     KC_F1,     KC_F10,    /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
    XXXXXXX,   KC_F6,     KC_F5,     KC_F4,     KC_F11,    /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
  [RESET] = LAYOUT_split_3x5_2(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   QK_BOOT, XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   TO(BASE),  /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
    QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   /*|*/ XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
                       _______,          _______,          /*|*/        _______,          _______
  ),
};

enum combos{
    io_P,           // KC_P
    commadot_QUOT,  // KC_QUOT; shifted: `"`
    mcomma_SCLN,    // KC_SCLN; shifted: `:`
    fj_RESET_LAYER,
    ui_ESC,         // KC_ESC
    er_CMD_F,       // browser Find
    xc_CTRL_X,      // vim Close buffer
    cv_CMD_C,       // Copy
    vb_CMD_V,       // Paste

    // all combinations of modifiers, using home row keys -- except Shift, which is a thumb key
    df_LCTL,           jk_RCTL,
    sd_LCMD,           kl_RCMD,
    fg_LOPT,           hj_ROPT,

    sf_L_CMD_CTL,      jl_R_CMD_CTL,
    sg_L_CMD_OPT,      hl_R_CMD_OPT,
    dg_L_CTL_OPT,      hk_R_CTL_OPT,
    sdf_L_CMD_CTL_OPT, jkl_R_CMD_CTL_OPT,

    // one Cmd-Shift combo on left hand only
    we_L_CMD_SHFT,


};

const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
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
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
    [io_P]          = COMBO(io_combo, KC_P),
    [commadot_QUOT] = COMBO(commadot_combo, KC_QUOT),
    [mcomma_SCLN]   = COMBO(mcomma_combo, KC_SCLN),
    [fj_RESET_LAYER] = COMBO(fj_combo, TO(RESET)),
    [ui_ESC]        = COMBO(ui_combo, KC_ESC),
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
    [we_L_CMD_SHFT] = COMBO(we_combo, LCMD(KC_LSFT)),
};

/*layer_state_t layer_state_set_user(layer_state_t state) {*/
/*    // if FN_MS ("adjust") on, leave it on until *both* SYM ("lower") and NUM_NAV ("upper") are off*/
/*    if (state & ((layer_state_t)1 << FN_MS)) {*/
/*        if (state & (((layer_state_t)1 << SYM) | (((layer_state_t)1 << NUM_NAV)))) return state;*/
/*    }*/
/*    return update_tri_layer_state(state, SYM, NUM_NAV, FN_MS);*/
/*}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING(EMAIL_ADDR);
            }
            break;
        case PHONE:
            if (record->event.pressed) {
                SEND_STRING(PHONE_NBR);
            }
            break;
    }
    return true;
}

// Following is based on https://docs.qmk.fm/features/tap_dance#example-4

/*********** Tap Dance declarations -- inline ".h file" ***********/

// tap dance states
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,  // like LSFT(KC_ENTER)
    TD_DOUBLE_TAP,  // like tap_code(KC_ENTER)
    TD_SINGLE_HOLD, // like MO(SYM)
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

/*********** Tap Dance definitions ***********/

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LSFT("\n"));
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_ENTER);
            break;
        case TD_SINGLE_HOLD:
            layer_on(SYM);
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(SYM);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [ENTER_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

