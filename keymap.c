/*
*keymap set for:
*████████╗██╗  ██╗███████╗██████╗  ██████╗ ███████╗██╗███╗   ██╗████████╗███████╗ ██████╗██╗  ██╗
*╚══██╔══╝██║  ██║██╔════╝██╔══██╗██╔═══██╗██╔════╝██║████╗  ██║╚══██╔══╝██╔════╝██╔════╝██║  ██║
*   ██║   ███████║█████╗  ██████╔╝██║   ██║███████╗██║██╔██╗ ██║   ██║   █████╗  ██║     ███████║
*   ██║   ██╔══██║██╔══╝  ██╔═══╝ ██║   ██║╚════██║██║██║╚██╗██║   ██║   ██╔══╝  ██║     ██╔══██║
*   ██║   ██║  ██║███████╗██║     ╚██████╔╝███████║██║██║ ╚████║   ██║   ███████╗╚██████╗██║  ██║
*   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝      ╚═════╝ ╚══════╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "config.h"

// ────────────────────────────────────────────
// TAP DANCE for modify right enter/space key
// ────────────────────────────────────────────
bool is_mod1_hold = false;

void td_mod1_ent_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && !state->pressed) {
    } else if (state->count == 2) {
        tap_code(KC_ENT);
    }
}

void td_mod1_ent_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && state->pressed) {
        layer_on(_NAVIGATION);
        is_mod1_hold = true;
    } else if (is_mod1_hold) {
        layer_off(_NAVIGATION);
        is_mod1_hold = false;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MOD1_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mod1_ent_finished, td_mod1_ent_reset),
};

// ──────────────────────────────────────────────────
// Combo definitions for go in|out DaVinci editing mode 
// ──────────────────────────────────────────────────
const uint16_t PROGMEM edit_combo_on[] = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM edit_combo_off[] = {KC_SPC, KC_K, COMBO_END};

combo_t key_combos[] = {
    [EDIT_COMBO_ON]  = COMBO(edit_combo_on),
    [EDIT_COMBO_OFF] = COMBO(edit_combo_off),
};

uint16_t COMBO_TERM = 200;

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case EDIT_COMBO_ON:
            if (pressed) {
                layer_move(_DAVINCI);
            }
            break;

        case EDIT_COMBO_OFF:
            if (pressed) {
                layer_move(_BASE);
            }
            break;
    }
}


// ────────────────────────────────────────────
// LAYOUT CONFIG
// ────────────────────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_NUMPAD, KC_ESC),KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LSFT_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RCTL_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL,    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_MINS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LGUI,   MO(_SYMBOLS),  LALT_T(KC_SPC),     KC_SPC,   TD(TD_MOD1_ENT), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRMD, KC_BRMU, XXXXXXX,  KC_F11,  KC_F12, KC_VOLD,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LGUI, _______,  LALT_T(KC_SPC),     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM, XXXXXXX, KC_LPRN, KC_RPRN, KC_PERC,                     KC_PAST, KC_EQL,  KC_AMPR, KC_PIPE, KC_TILD, KC_BSPC,
  //|--------+--------+---------------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, XXXXXXX,			            KC_EXLM, KC_HASH, KC_SLSH, KC_BSLS, XXXXXXX,  KC_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,			            KC_MINS, KC_GRV,  KC_CIRC, KC_AT  , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, _______,  LALT_T(KC_SPC),    KC_SPC, MO(_SETTINGS), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_HOME, KC_PAGE_UP, KC_PAGE_DOWN, KC_END, KC_DELETE,             KC_PPLS,    KC_1,    KC_2,    KC_3, KC_MINS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST,    KC_4,    KC_5,    KC_6, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |----------------+--------+--------+--------+--------+--------|
                                KC_LGUI, _______,  LALT_T(KC_SPC),    KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SETTINGS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LGUI, _______,  LALT_T(KC_SPC),    KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_DAVINCI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MARKIN, MARKOUT,     CUT,  CDLEFT, CDRIGHT, ZOOMFIT,                       PREV_F,  NEXT_F,PRV_CLIP,NXT_CLIP,   START,     END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TRIM_IN,TRIM_OUT, SWPCL_L, SWPCL_R,  INSERT,  SELECT,                      REVERSE,    STOP, FORWARD, SRC_TML,ACT_DACT,FULL_SCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    MARK, RIP_DEL,  DYTRIM, TRYMODE,                      LSEL_CL, RSEL_CL, USEL_CL, DSEL_CL,    MF_R,    MF_L,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXXXX,    UNDO,    PLAY,    TML_ZIN,    REDO, TML_ZOUT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
// ───────────────────────────────────
// OLED: Show actual layer in screen
// ───────────────────────────────────
bool oled_task_user(void) {
    oled_clear();

    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _DAVINCI:
            oled_write_P(PSTR("🎬 DaVinci Mode\n"), false);
            oled_write_P(PSTR("Edit tools active"), false);
            break;
        case _NAVIGATION:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _SETTINGS:
            oled_write_ln_P(PSTR("Settings"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }

    oled_write_P(PSTR("\nLEDs:\n"), false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    oled_write_P(PSTR("\n"), false);
    return false;
}
#endif
