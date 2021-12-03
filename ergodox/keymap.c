// André Silva's Ergodox Infinity keyboard layout.

#include QMK_KEYBOARD_H

#define LCD_BACKLIGHT_IDLE_TIMEOUT 300

static uint32_t idle_timer;
static bool is_idle;
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

void matrix_init_user() {
    // disable QMK logo animation
    memset(
        default_startup_animation.frame_lengths,
        0,
        sizeof(default_startup_animation.frame_lengths)
    );
}

void matrix_scan_user() {
    if (is_keyboard_master()) {
        // check the timer only if the keyboard is not idle
        if (!is_idle) {
            if (timer_elapsed32(idle_timer) >= LCD_BACKLIGHT_IDLE_TIMEOUT * 1000) {
                is_idle = true;

                // disable LCD display
                visualizer_suspend();
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (is_keyboard_master()) {
        // reset idle timer on each keypress
        idle_timer = timer_read32();

        if (is_idle) {
            is_idle = false;

            // re-enable LCD display
            visualizer_resume();
        }
    }

    return true;
}
