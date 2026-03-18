// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "lib/crosses.h"

/*
 * Keycodes, combos, and layers! oh my!
 */

enum CROSSES_LAYERS { _BASE, _NUM, _NAV, _MEDIA, _FUNC, _MOUS, _CUST };

enum crosses_keycode { C_MINC = QK_KB_0, C_MDEC, C_MTOGG, C_DRAG, C_DRAG_HOLD };

/*
 * Keymaps!
 */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───────────┬───────────┬───────────┬────────────┐                      ┌──────┬────────────┬───────────┬───────────┬───────────┐
//    │     q     │     w     │     f     │     p     │     b      │                      │  j   │     l      │     u     │     y     │     ;     │
//    ├───────────┼───────────┼───────────┼───────────┼────────────┤                      ├──────┼────────────┼───────────┼───────────┼───────────┤
//    │ LGUI_T(a) │ LALT_T(r) │ LCTL_T(s) │ LSFT_T(t) │     g      │                      │  m   │ RSFT_T(n)  │ RCTL_T(e) │ RALT_T(i) │ RGUI_T(o) │
//    ├───────────┼───────────┼───────────┼───────────┼────────────┤                      ├──────┼────────────┼───────────┼───────────┼───────────┤
//    │     z     │     x     │     c     │     d     │     v      │                      │  k   │     h      │     ,     │     .     │ LT(3, /)  │
//    └───────────┴───────────┴───────────┼───────────┼────────────┼─────┐   ┌────────────┼──────┼────────────┼───────────┴───────────┴───────────┘
//                                        │   MO(5)   │ LT(2, esc) │ spc │   │ LT(1, ent) │ bspc │ LT(4, del) │
//                                        └───────────┴────────────┴─────┘   └────────────┴──────┴────────────┘
[_BASE] = LAYOUT_default(
  KC_Q         , KC_W         , KC_F         , KC_P         , KC_B          ,                              KC_J    , KC_L          , KC_U         , KC_Y         , KC_SCLN       ,
  LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G          ,                              KC_M    , RSFT_T(KC_N)  , RCTL_T(KC_E) , RALT_T(KC_I) , RGUI_T(KC_O)  ,
  KC_Z         , KC_X         , KC_C         , KC_D         , KC_V          ,                              KC_K    , KC_H          , KC_COMM      , KC_DOT       , LT(3, KC_SLSH),
                                               MO(5)        , LT(2, KC_ESC) , KC_SPC ,     LT(1, KC_ENT) , KC_BSPC , LT(4, KC_DEL)
),

//    ┌──────┬───┬───┬───────────┬──────┐               ┌──────┬───────────┬───────────┬──────┬─────┐
//    │ S(8) │ 7 │ 8 │     9     │  /   │               │  \   │   S(9)    │   S(0)    │ S(\) │     │
//    ├──────┼───┼───┼───────────┼──────┤               ├──────┼───────────┼───────────┼──────┼─────┤
//    │  -   │ 4 │ 5 │ LSFT_T(6) │ S(=) │               │ S(5) │ RSFT_T([) │ RCTL_T(]) │ S(;) │  ;  │
//    ├──────┼───┼───┼───────────┼──────┤               ├──────┼───────────┼───────────┼──────┼─────┤
//    │  `   │ 1 │ 2 │     3     │  =   │               │  [   │     ]     │           │      │     │
//    └──────┴───┴───┼───────────┼──────┼─────┐   ┌─────┼──────┼───────────┼───────────┴──────┴─────┘
//                   │           │  0   │     │   │     │      │           │
//                   └───────────┴──────┴─────┘   └─────┴──────┴───────────┘
[_NUM] = LAYOUT_default(
  S(KC_8) , KC_7 , KC_8 , KC_9         , KC_SLSH   ,                         KC_BSLS , S(KC_9)         , S(KC_0)         , S(KC_BSLS) , KC_TRNS,
  KC_MINS , KC_4 , KC_5 , LSFT_T(KC_6) , S(KC_EQL) ,                         S(KC_5) , RSFT_T(KC_LBRC) , RCTL_T(KC_RBRC) , S(KC_SCLN) , KC_SCLN,
  KC_GRV  , KC_1 , KC_2 , KC_3         , KC_EQL    ,                         KC_LBRC , KC_RBRC         , KC_TRNS         , KC_TRNS    , KC_TRNS,
                          KC_TRNS      , KC_0      , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬──────┬───────┬────┐             ┌────┬──────┬──────┬──────┬──────┐
//    │  no  │  no  │  no  │  no   │ no │             │ no │  no  │  no  │  no  │  no  │
//    ├──────┼──────┼──────┼───────┼────┤             ├────┼──────┼──────┼──────┼──────┤
//    │ lgui │ lalt │ lctl │ lsft  │ no │             │ no │ left │ down │  up  │ rght │
//    ├──────┼──────┼──────┼───────┼────┤             ├────┼──────┼──────┼──────┼──────┤
//    │  no  │  no  │ copy │ paste │ no │             │ no │ home │ end  │ pgdn │ pgup │
//    └──────┴──────┴──────┼───────┼────┼────┐   ┌────┼────┼──────┼──────┴──────┴──────┘
//                         │  no   │ no │ no │   │ no │ no │  no  │
//                         └───────┴────┴────┘   └────┴────┴──────┘
[_NAV] = LAYOUT_default(
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,                     KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO  ,
  KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO ,                     KC_NO , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT,
  KC_NO   , KC_NO   , KC_COPY , KC_PSTE , KC_NO ,                     KC_NO , KC_HOME , KC_END  , KC_PGDN , KC_PGUP,
                                KC_NO   , KC_NO , KC_NO ,     KC_NO , KC_NO , KC_NO
),

//    ┌──────┬──────┬──────┬──────┬──────┐             ┌────┬────┬────┬────┬────┐
//    │  no  │  no  │  no  │  no  │  no  │             │ no │ no │ no │ no │ no │
//    ├──────┼──────┼──────┼──────┼──────┤             ├────┼────┼────┼────┼────┤
//    │ mprv │ vold │ mply │ volu │ mnxt │             │ no │ no │ no │ no │ no │
//    ├──────┼──────┼──────┼──────┼──────┤             ├────┼────┼────┼────┼────┤
//    │  no  │  no  │  no  │  no  │  no  │             │ no │ no │ no │ no │ no │
//    └──────┴──────┴──────┼──────┼──────┼────┐   ┌────┼────┼────┼────┴────┴────┘
//                         │  no  │  no  │ no │   │ no │ no │ no │
//                         └──────┴──────┴────┘   └────┴────┴────┘
[_MEDIA] = LAYOUT_default(
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_MPRV , KC_VOLD , KC_MPLY , KC_VOLU , KC_MNXT ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                                KC_NO   , KC_NO   , KC_NO ,     KC_NO , KC_NO , KC_NO
),

//    ┌─────┬─────┬─────┬─────┬─────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │ f11 │ f12 │ f13 │ f14 │ f15 │               │     │      │      │      │      │
//    ├─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │ f6  │ f7  │ f8  │ f9  │ f10 │               │     │ rsft │ rctl │ ralt │ rgui │
//    ├─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │ f1  │ f2  │ f3  │ f4  │ f5  │               │     │      │      │      │      │
//    └─────┴─────┴─────┼─────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┴──────┴──────┘
//                      │     │     │     │   │     │     │      │
//                      └─────┴─────┴─────┘   └─────┴─────┴──────┘
[_FUNC] = LAYOUT_default(
  KC_F11 , KC_F12 , KC_F13 , KC_F14  , KC_F15  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10  ,                         KC_TRNS , KC_RSFT , KC_RCTL , KC_RALT , KC_RGUI,
  KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                             KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌──────┬─────────┬─────────┬─────────┬────┐             ┌────┬────────┬────────┬──────┬─────────┐
//    │ lsft │  lalt   │   no    │   no    │ no │             │ no │ C_MINC │ C_MDEC │  no  │ C_MTOGG │
//    ├──────┼─────────┼─────────┼─────────┼────┤             ├────┼────────┼────────┼──────┼─────────┤
//    │ lctl │ MS_BTN3 │ MS_BTN2 │ MS_BTN1 │ no │             │ no │  rsft  │  rctl  │ ralt │  rgui   │
//    ├──────┼─────────┼─────────┼─────────┼────┤             ├────┼────────┼────────┼──────┼─────────┤
//    │ lgui │   no    │   no    │ C_DRAG  │ no │             │ no │   no   │   no   │  no  │   no    │
//    └──────┴─────────┴─────────┼─────────┼────┼────┐   ┌────┼────┼────────┼────────┴──────┴─────────┘
//                               │         │ no │ no │   │ no │ no │   no   │
//                               └─────────┴────┴────┘   └────┴────┴────────┘
[_MOUS] = LAYOUT_default(
  KC_LSFT , KC_LALT , KC_NO   , KC_NO   , KC_NO ,                     KC_NO , C_MINC  , C_MDEC  , KC_NO   , C_MTOGG,
  KC_LCTL , MS_BTN3 , MS_BTN2 , MS_BTN1 , KC_NO ,                     KC_NO , KC_RSFT , KC_RCTL , KC_RALT , KC_RGUI,
  KC_LGUI , KC_NO   , KC_NO   , C_DRAG  , KC_NO ,                     KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO  ,
                                KC_TRNS , KC_NO , KC_NO ,     KC_NO , KC_NO , KC_NO
),

//    ┌────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┐
//    │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │
//    └────┴────┴────┼────┼────┼────┐   ┌────┼────┼────┼────┴────┴────┘
//                   │ no │ no │ no │   │ no │ no │ no │
//                   └────┴────┴────┘   └────┴────┴────┘
[_CUST] = LAYOUT_default(
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                          KC_NO , KC_NO , KC_NO ,     KC_NO , KC_NO , KC_NO
)
};

// clang-format on

static bool scroll_toggled = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    // ── One-shot скролл: любая клавиша выключает режим, не срабатывая ──
    if (scroll_toggled && record->event.pressed) {
        set_scrolling  = false;
        scroll_toggled = false;
        return false;
    }

    switch (keycode) {
        case RSFT_T(KC_LBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LBRC));
                return false;
            }
            break;

        case RCTL_T(KC_RBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_RBRC));
                return false;
            }
            break;

        case C_MINC:
            if (record->event.pressed) {
                change_pointer_dpi(&global_user_config, true);
                debug_config_to_console(&global_user_config);
                return false;
            }
            break;

        case C_MDEC:
            if (record->event.pressed) {
                change_pointer_dpi(&global_user_config, false);
                debug_config_to_console(&global_user_config);
                return false;
            }
            break;

        case C_MTOGG:
            if (record->event.pressed) {
                bool current_state = get_auto_mouse_enable();
                set_auto_mouse_enable(!current_state);
                return false;
            }
            break;

        // Кнопка-ONE-SHOT: включает скролл, выключается любой следующей клавишей
        case C_DRAG:
            if (record->event.pressed) {
                set_scrolling  = true;
                scroll_toggled = true;
            }
            return false;

        // Кнопка-HOLD: скролл пока зажата
        case C_DRAG_HOLD:
            set_scrolling = record->event.pressed;
            return true;
    }

    return true;
}

#ifdef OLED_ENABLE

extern void render_bongocat(void);

#define SPLASH_DURATION 3000

static bool     splash_done  = false;
static uint32_t splash_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    splash_timer = timer_read32();

    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

static void render_splash(void) {
    static bool     initialized    = false;
    static uint16_t fade_timer     = 0;
    static uint16_t step           = 0;

    if (!initialized) {
        for (uint16_t i = 0; i < 512; i++) {
            oled_write_raw_byte(0xFF, i);
        }
        initialized = true;
        fade_timer  = timer_read();
        return;
    }

    if (timer_elapsed(fade_timer) > 30) {
        fade_timer = timer_read();

        for (uint8_t i = 0; i < 30; i++) {
            uint16_t pos = (step * 137 + 83) % 512;
            oled_write_raw_byte(0x00, pos);
            step++;
        }
    }

    oled_set_cursor(3, 1);
    oled_write_P(PSTR("CROSSES 3x5"), false);
}

bool oled_task_user(void) {
    if (!splash_done) {
        if (timer_elapsed32(splash_timer) < SPLASH_DURATION) {
            render_splash();
            return false;
        } else {
            splash_done = true;
            oled_clear();
        }
    }

    render_bongocat();

    uint8_t col = is_keyboard_left() ? 17 : 0;

    const char* layer_names[] = {
        [_BASE]  = "BASE",
        [_NUM]   = "NUMB",
        [_NAV]   = "NAVI",
        [_MEDIA] = "MED ",
        [_FUNC]  = "FUNC",
        [_MOUS]  = "MOUS",
        [_CUST]  = "CUST",
    };
    oled_set_cursor(col, 0);
    oled_write(layer_names[get_highest_layer(layer_state)], false);

    oled_set_cursor(col, 1);
    char cpi_str[6];
    uint16_t current_dpi = get_pointer_dpi(&global_user_config);
    snprintf(cpi_str, sizeof(cpi_str), "%u", (unsigned int)current_dpi);
    oled_write(cpi_str, false);

    oled_set_cursor(col, 2);
    if (set_scrolling) {
        oled_write_P(PSTR("SCRL"), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }

    return false;
}

#endif /* ifdef OLED_ENABLE */
