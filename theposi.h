#pragma once
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stddef.h>

static uint16_t prev_h = 0;
static uint8_t  prev_s = 0;
static uint8_t  prev_v = 0;
static bool     restored = true;

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

// ────────────────────────────────────────────
// TOOGLE LAYERS MACROS
// ────────────────────────────────────────────
#define DV_MODE TG(_DAVINCI)

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
#define PRV_CLIP        KC_UP
#define NXT_CLIP        KC_DOWN
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