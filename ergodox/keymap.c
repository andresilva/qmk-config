// André Silva's Ergodox Infinity keyboard layout.

#include QMK_KEYBOARD_H

#include "logos.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols layer
    MDIA, // media layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base layer
//
// ┌─────────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
// │  `~     │  1  │  2  │  3  │  4  │  5  │ ESC │     │  ─  │  6  │  7  │  8  │  9  │  0  │     =+  │
// ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼─────────┤
// │Media/Tab│  Q  │  W  │  E  │  R  │  T  │  [  │     │  ]  │  Y  │  U  │  I  │  O  │  P  │     \│  │
// ├─────────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼─────────┤
// │  Ctrl   │  A  │  S  │  D  │  F  │  G  ├─────┤     ├─────┤  H  │  J  │  K  │  L  │  ;  │     '"  │
// ├─────────┼─────┼─────┼─────┼─────┼─────┤Shift│     │ Tab ├─────┼─────┼─────┼─────┼─────┼─────────┤
// │  Shift  │  Z  │  X  │  C  │  V  │  B  │─Tab │     │     │  N  │  M  │  ,  │  .  │  /  │  Shift  │
// └──┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼──────┬──┘
//    │Symbol│ Meh │Hyper│LGui │LAlt │                             │ RAlt│ RGui│Hyper│ Meh │Symbol│
//    └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
//                                   ┌─────┬─────┐     ┌─────┬─────┐
//                                   │Home │ End │     │ Left│Right│
//                             ┌─────┼─────┼─────┤     ├─────┼─────┼─────┐
//                             │     │     │PgUp │     │  Up │     │     │
//                             │ Bsp │ Del ├─────┤     ├─────┤Enter│Space│
//                             │     │     │PgDn │     │ Down│     │     │
//                             └─────┴─────┴─────┘     └─────┴─────┴─────┘
[BASE] = LAYOUT_ergodox(
    // left hand
    KC_GRV,           KC_1,         KC_2,         KC_3,    KC_4,    KC_5,    KC_ESC,
    LT(MDIA, KC_TAB), KC_Q,         KC_W,         KC_E,    KC_R,    KC_T,    KC_LBRC,
    KC_LCTL,          KC_A,         KC_S,         KC_D,    KC_F,    KC_G,
    KC_LSFT,          KC_Z,         KC_X,         KC_C,    KC_V,    KC_B,    LSFT(KC_TAB),
    MO(SYMB),         MEH_T(KC_NO), ALL_T(KC_NO), KC_LGUI, KC_LALT,
                                                                    KC_HOME, KC_END,
                                                                             KC_PGUP,
                                                           KC_BSPC, KC_DEL,  KC_PGDN,

    // right hand
    KC_MINS,          KC_6,         KC_7,         KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_RBRC,          KC_Y,         KC_U,         KC_I,    KC_O,    KC_P,    KC_BSLS,
                      KC_H,         KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_TAB,           KC_N,         KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                    KC_RALT,      KC_RGUI, KC_HYPR, KC_MEH,  MO(SYMB),
    KC_LEFT,          KC_RGHT,
    KC_UP,
    KC_DOWN,          KC_ENT,       KC_SPC
),

// Symbols layer
//
// ┌─────────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
// │         │ F1  │ F2  │ F3  │ F4  │ F5  │RESET│     │RESET│  F6 │  F7 │  F8 │  F9 │ F10 │         │
// ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼─────────┤
// │         │  !  │  @  │  {  │  }  │  &  │  <  │     │  >  │  │  │  7  │  8  │  9  │  /  │         │
// ├─────────┼─────┼─────┼─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┼─────┼─────┼─────────┤
// │         │  #  │  $  │  (  │  )  │  `  ├─────┤     ├─────┤  /  │  4  │  5  │  6  │  *  │         │
// ├─────────┼─────┼─────┼─────┼─────┼─────┤  '  │     │  "  ├─────┼─────┼─────┼─────┼─────┼─────────┤
// │    ;    │  %  │  ^  │  [  │  ]  │  ~  │     │     │     │  \  │  1  │  2  │  3  │  ─  │         │
// └──┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼──────┬──┘
//    │      │  &  │  *  │  <  │  >  │                             │  0  │  .  │  =  │  +  │      │
//    └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
//                                   ┌─────┬─────┐     ┌─────┬─────┐
//                                   │■■■■■│■■■■■│     │■■■■■│■■■■■│
//                             ┌─────┼─────┼─────┤     ├─────┼─────┼─────┐
//                             │Plus │Equal│■■■■■│     │■■■■■│Under│Minus│
//                             │     │     ├─────┤     ├─────┤Score│     │
//                             │  +  │  =  │■■■■■│     │■■■■■│  _  │  ─  │
//                             └─────┴─────┴─────┘     └─────┴─────┴─────┘
[SYMB] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,       KC_F1,         KC_F2,   KC_F3,         KC_F4,        KC_F5,   RESET,
    KC_TRNS,       KC_EXLM,       KC_AT,   KC_LCBR,       KC_RCBR,      KC_AMPR, LSFT(KC_COMM),
    KC_TRNS,       KC_HASH,       KC_DLR,  KC_LPRN,       KC_RPRN,      KC_GRV,
    KC_SCLN,       KC_PERC,       KC_CIRC, KC_LBRC,       KC_RBRC,      KC_TILD, KC_QUOT,
    KC_TRNS,       KC_AMPR,       KC_ASTR, LSFT(KC_COMM), LSFT(KC_DOT),
                                                                        KC_NO,   KC_NO,
                                                                                 KC_NO,
                                                          KC_PLUS,      KC_EQL,  KC_NO,

    // right hand
    RESET,         KC_F6,         KC_F7,   KC_F8,         KC_F9,        KC_F10,  KC_TRNS,
    LSFT(KC_DOT),  KC_PIPE,       KC_7,    KC_8,          KC_9,         KC_SLSH, KC_TRNS,
                   KC_SLSH,       KC_4,    KC_5,          KC_6,         KC_ASTR, KC_TRNS,
    LSFT(KC_QUOT), KC_BSLS,       KC_1,    KC_2,          KC_3,         KC_MINS, KC_TRNS,
                                  KC_0,    KC_DOT,        KC_EQL,       KC_PLUS, KC_TRNS,
    KC_NO,         KC_NO,
    KC_NO,
    KC_NO,         LSFT(KC_MINS), KC_MINS
),

// Media layer
//
// ┌─────────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────────┐
// │         │ F11 │ F12 │ F13 │ F14 │ F15 │ Esc │     │■■■■■│ F16 │ F17 │ F18 │ F19 │ F20 │         │
// ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼─────────┤
// │         │■■■■■│■■■■■│ MUp │■■■■■│VolUp│Wheel│     │Wheel│PScrn│ Home│  Up │ PgUp│ Mail│         │
// ├─────────┼─────┼─────┼─────┼─────┼─────┤ Up  │     │  Up ├─────┼─────┼─────┼─────┼─────┼─────────┤
// │         │■■■■■│MLeft│MDown│MRght│VolDn├─────┤     ├─────┤NLock│ Left│ Down│Right│MyCom│         │
// ├─────────┼─────┼─────┼─────┼─────┼─────┤Wheel│     │Wheel├─────┼─────┼─────┼─────┼─────┼─────────┤
// │         │■■■■■│■■■■■│MDown│■■■■■│Mute │Down │     │ Down│■■■■■│ End │ Down│ PgDn│■■■■■│         │
// └──┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼──────┬──┘
//    │■■■■■■│■■■■■│MClik│LClik│RClik│                             │ Ins │ Del │■■■■■│■■■■■│■■■■■■│
//    └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
//                                   ┌─────┬─────┐     ┌─────┬─────┐
//                                   │Stop │Rfrsh│     │ Prev│ Next│
//                             ┌─────┼─────┼─────┤     ├─────┼─────┼─────┐
//                             │Brwsr│Brwsr│Srch │     │VolUp│ Mute│Play-│
//                             │Back │ Fwd ├─────┤     ├─────┤     │Pause│
//                             │     │     │Home │     │VolDn│     │     │
//                             └─────┴─────┴─────┘     └─────┴─────┴─────┘
[MDIA] = LAYOUT_ergodox(
    // left hand
    KC_TRNS, KC_F11,   KC_F12,  KC_F13,   KC_F14,   KC_F15,  KC_ESC,
    KC_TRNS, KC_NO,    KC_NO,   KC_MS_U,  KC_NO,    KC_VOLU, KC_WH_U,
    KC_TRNS, KC_NO,    KC_MS_L, KC_MS_D,  KC_MS_R,  KC_VOLD,
    KC_TRNS, KC_NO,    KC_NO,   KC_MS_D,  KC_NO,    KC_MUTE, KC_WH_D,
    KC_NO,   KC_NO,    KC_BTN3, KC_BTN1,  KC_BTN2,
                                                    KC_WSTP, KC_WREF,
                                                             KC_WSCH,
                                          KC_WBAK,  KC_WFWD, KC_WHOM,

    // right hand
    KC_NO,   KC_F16,   KC_F17,  KC_F18,   KC_F19,   KC_F20,  KC_TRNS,
    KC_WH_U, KC_PSCR,  KC_HOME, KC_UP,    KC_PGUP,  KC_MAIL, KC_TRNS,
             KC_NLCK,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_MYCM, KC_TRNS,
    KC_WH_D, KC_NO,    KC_END,  KC_DOWN,  KC_PGDN,  KC_NO,   KC_TRNS,
                       KC_INS,  KC_DEL,   KC_NO,    KC_NO,   KC_NO,
    KC_MPRV, KC_MNXT,
    KC_VOLU,
    KC_VOLD, KC_MUTE,  KC_MPLY
),

};

void st7565_render_base_logo(bool shift) {
    if (shift) {
        st7565_write_raw_P(BASE_LOGO_SHIFT, sizeof(BASE_LOGO_SHIFT));
    } else {
        st7565_write_raw_P(BASE_LOGO, sizeof(BASE_LOGO));
    }
}

void st7565_render_media_logo(bool shift) {
    if (shift) {
        st7565_write_raw_P(MEDIA_LOGO_SHIFT, sizeof(MEDIA_LOGO_SHIFT));
    } else {
        st7565_write_raw_P(MEDIA_LOGO, sizeof(MEDIA_LOGO));
    }
}

void st7565_render_symbols_logo(bool shift) {
    st7565_write_raw_P(SYMBOLS_LOGO, sizeof(SYMBOLS_LOGO));
}

void st7565_task_user(void) {
    if (!st7565_is_on()) {
        return;
    }

    uint16_t r = 0, g = 0, b = 0;
    bool shift = (get_mods() & MOD_BIT(KC_LSFT)) || (get_mods() & MOD_BIT(KC_RSFT));

    switch (get_highest_layer(layer_state)) {
        case BASE:
            r = UINT16_MAX / 2; g = UINT16_MAX / 2; b = UINT16_MAX / 2; // white
            st7565_render_base_logo(shift);
            break;
        case SYMB:
            r = UINT16_MAX / 2; g = UINT16_MAX; b = UINT16_MAX / 5; // green
            st7565_render_symbols_logo(shift);
            break;
        case MDIA:
            r = UINT16_MAX / 5; g = UINT16_MAX / 2; b = UINT16_MAX; // blue
            st7565_render_media_logo(shift);
            break;
    }

    if (shift) {
        r = UINT16_MAX; g = UINT16_MAX / 5; b = UINT16_MAX / 5; // red
    }

    ergodox_infinity_lcd_color(r, g, b);
}
