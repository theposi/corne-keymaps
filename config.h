/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stddef.h>

// LAYERS NAMES
enum layer_names {
    _BASE = 0,
    _NAVIGATION,
    _SYMBOLS,
    _NUMPAD,
    _SETTINGS,
    _DAVINCI,
};

// TAP DANCE DEFS
enum {
    TD_MOD1_ENT,
};

// COMBO DEFS
enum combo_events {
    EDIT_COMBO_ON,
    EDIT_COMBO_OFF,
};

//#define USE_MATRIX_I2C
//#define QUICK_TAP_TERM 0
#define TAPPING_TERM    180
#define COMBO_TERM      200

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

// ────────────────────────────────────────────
// DAVINCI MACROS 
// ────────────────────────────────────────────

// LEFT
#define MARKIN          KC_I
#define MARKOUT         KC_O
#define CUT             LCTL(KC_B)
#define CDLEFT          LCTL(LSFT(KC_LBRC))
#define CDRIGHT         LCTL(LSFT(KC_RBRC))
#define ZOOMFIT         LSFT(KC_Z) 
#define TRIM_IN         LSFT(KC_LBRC)
#define TRIM_OUT        LSFT(KC_RBRC)
#define SWPCL_L         LCTL(LSFT(KC_COMMA))
#define SWPCL_R         LCTL(LSFT(KC_DOT))
#define INSERT          KC_F9
#define SELECT          KC_A
#define MARK            KC_M
#define RIP_DEL         LSFT(KC_BACKSPACE)
#define DYTRIM          KC_W
#define TRYMODE         KC_T
#define PLAY            KC_SPACE
#define UNDO            LCTL(KC_Z)

// RIGHT 
#define PRV_F           KC_LEFT 
#define NXT_F           KC_RIGHT
#define PREV_CLIP       KC_UP
#define NEXT_CLIP       KC_DOWN
#define START           KC_HOME
#define END             KC_END
#define REVERSE         KC_J
#define STOP            KC_K
#define FORWARD         KC_L
#define SRC_TML         KC_Q
#define ACT_DACT        KC_D
#define FULL_SCR        LCTL(KC_F)
#define LSEL_CL         LCTL(KC_LEFT)
#define RSEL_CL         LCTL(KC_RIGHT)
#define USEL_CL         LCTL(KC_UP)
#define DSEL_CL         LCTL(KC_DOWN)
#define MF_R            KC_DOT
#define MF_L            KC_COMMA
#define REDO            LCTL(LSFT(KC_Z))
#define TML_ZIN         LCTL(KC_EQL)
#define TML_ZOUT        LCTL(KC_MINUS)