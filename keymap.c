/* Copyright (c) 2017 Tim Perkins */

#include QMK_KEYBOARD_H

#include "melody96_transpose.h"

#define KEYMAP LAYOUT_transpose

#define XXXXXXX KC_NO
#define _______ KC_TRNS

enum tprk77_layers {
  LR_QWTY = 0,  /* QWERTY (BASE) */
  LR_NAV  = 1,  /* NAV */
};

enum tprk77_fns {
  MO_NAV  = KC_FN0,
};

enum tprk77_mod_keys {
  MD_HYPR = ALL_T(KC_NO),
  MD_MEH  = MEH_T(KC_NO),
  MD_CADL = LCTL(LALT(KC_DEL)),
};

#define SR SAFE_RANGE

enum tprk77_keys {
  MC_PI = SR,   /* 3.14159265358979323846 (As defined in "math.h") */
  MC_BEES,      /* YOU'RE THE BEE'S KNEES */
};

#undef SR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * QWERTY (BASE) LAYER:
   *
   * ,-----------------------------------------.
   * | Ctrl | Shift| Nav  | Tab  |  `   | Esc  |
   * |------+------+------+------+------+------|
   * | GUI  | Shift|  A   |  Q   |  1   | F1   |
   * |------+------+------+------+------+------|
   * | Alt  |  Z   |  S   |  W   |  2   | F2   |
   * |------+------+------+------+------+------|
   * |      |  X   |  D   |  E   |  3   | F3   |
   * |      |------+------+------+------+------|
   * |      |  C   |  F   |  R   |  4   | F4   |
   * |      |------+------+------+------+------|
   * |      |  V   |  G   |  T   |  5   | F5   |
   * |      |------+------+------+------+------|
   * | Spc  |  B   |  H   |  Y   |  6   | F6   |
   * |      |------+------+------+------+------|
   * |      |  N   |  J   |  U   |  7   | F7   |
   * |      |------+------+------+------+------|
   * |      |  M   |  K   |  I   |  8   | F8   |
   * |      |------+------+------+------+------|
   * |      |  ,   |  L   |  O   |  9   | F9   |
   * |------+------+------+------+------+------|
   * | Left |  .   |  ;   |  P   |  0   | F10  |
   * |------+------+------+------+------+------|
   * | Down |  /   |  '   |  [   |  _   | F11  |
   * |------+------+------+------+------+------|
   * | Up   |      |      |  ]   |  =   | F12  |
   * |------| Shift|      |------+------+------|
   * | Right|      | Enter|      | Bspc | Pscr |
   * |------+------|      |  /   |------+------|
   * | Bee's| Shift|      |      | Bspc | Del  |
   * |------+------+------+------+------+------|
   * |  0   |  1   |  4   |  7   | Num  | Calc |
   * |------+------+------+------+------+------|
   * |  0   |  2   |  5   |  8   | /    | Mute |
   * |------+------+------+------+------+------|
   * |  .   |  3   |  6   |  9   | *    | Vol- |
   * |------+------+------+------+------+------|
   * | Enter| Enter|  +   |  +   | -    | Vol+ |
   * `-----------------------------------------'
   */
  [LR_QWTY] = KEYMAP(
      KC_LCTL, KC_LSFT, MO_NAV,  KC_TAB,  KC_GRV,  KC_ESC,
      KC_LGUI, KC_LSFT, KC_A,    KC_Q,    KC_1,    KC_F1,
      KC_LALT, KC_Z,    KC_S,    KC_W,    KC_2,    KC_F2,
               KC_X,    KC_D,    KC_E,    KC_3,    KC_F3,
               KC_C,    KC_F,    KC_R,    KC_4,    KC_F4,
               KC_V,    KC_G,    KC_T,    KC_5,    KC_F5,
      KC_SPC,  KC_B,    KC_H,    KC_Y,    KC_6,    KC_F6,
               KC_N,    KC_J,    KC_U,    KC_7,    KC_F7,
               KC_M,    KC_K,    KC_I,    KC_8,    KC_F8,
               KC_COMM, KC_L,    KC_O,    KC_9,    KC_F9,
      KC_LEFT, KC_DOT,  KC_SCLN, KC_P,    KC_0,    KC_F10,
      KC_DOWN, KC_SLSH, KC_QUOT, KC_LBRC, KC_MINS, KC_F11,
      KC_UP,   KC_RSFT, KC_ENT,  KC_RBRC, KC_EQL,  KC_F12,
      KC_RGHT,                   KC_BSLS, KC_BSPC, KC_PSCR,
      MC_BEES, KC_RSFT,                   KC_BSPC, KC_DEL,
      KC_P0,   KC_P1,   KC_P4,   KC_P7,   KC_NLCK, KC_CALC,
      KC_P0,   KC_P2,   KC_P5,   KC_P8,   KC_PSLS, KC_MUTE,
      KC_PDOT, KC_P3,   KC_P6,   KC_P9,   KC_PAST, KC_VOLD,
      KC_PENT, KC_PENT, KC_PPLS, KC_PPLS, KC_PMNS, KC_VOLU
  ),

  /*
   * NAV LAYER:
   *
   * ,-----------------------------------------.
   * | Ctrl | Shift| Nav  | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | GUI  | Shift| XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | Alt  | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * |      | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |      |------+------+------+------+------|
   * |      | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |      |------+------+------+------+------|
   * |      | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |      |------+------+------+------+------|
   * | Ctrl | XXXX | XXXX | PgDn | PgUp | XXXX |
   * |      |------+------+------+------+------|
   * |      | XXXX | XXXX | Left | Home | XXXX |
   * |      |------+------+------+------+------|
   * |      | XXXX | XXXX | Down | Up   | XXXX |
   * |      |------+------+------+------+------|
   * |      | XXXX | XXXX | Right| End  | XXXX |
   * |------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | XXXX |      |      | XXXX | XXXX | XXXX |
   * |------| Shift|      |------+------+------|
   * | XXXX |      | XXXX |      | XXXX | XXXX |
   * |------+------|      | XXXX |------+------|
   * | Pi   | Shift|      |      | XXXX |C-A-Dl|
   * |------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|
   * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * `-----------------------------------------'
   */
  [LR_NAV] = KEYMAP(
      KC_LCTL, KC_LSFT, MO_NAV,  XXXXXXX, XXXXXXX, XXXXXXX,
      KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_LCTL, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
               XXXXXXX, KC_LEFT, KC_HOME, XXXXXXX, XXXXXXX,
               XXXXXXX, KC_DOWN, KC_UP,   XXXXXXX, XXXXXXX,
               XXXXXXX, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,
      MC_PI,   KC_RSFT,                   XXXXXXX, MD_CADL,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  /* MO_NAV  */ [0] = ACTION_LAYER_MOMENTARY(LR_NAV),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  /* Process macro keys */
  if (record->event.pressed) {
    switch (keycode) {
      case MC_PI:
        SEND_STRING("3.14159265358979323846");
        return false;
      case MC_BEES:
        SEND_STRING("YOU'RE THE BEE'S KNEES");
        return false;
    }
  }
  return true;
}

void matrix_init_user(void)
{
  /* For some reason, disabling RBG lighting has the effect off turning it on as
   * bright red. My guess is that this is some kind of default state for the
   * LEDs, which are still powered. So what we actually need to do is enable RGB
   * lighting and set the brightness to zero. Go figure.
   *
   * BTW, the non-EEPROM functions don't seem to work in the init function. The
   * seem to be overwritten by something. I'm not sure what. (They do work other
   * places like in the scan function.) So just use the EEPROM functions, write
   * the values once, and don't worry about it.
   *
   * Uncomment these lines to write out the EEPROM again.
   */
  /* rgblight_enable(); */
  /* rgblight_sethsv(0, 0, 0); */
}

  /*
   * LAYER TEMPLATE
   *
   * ,-----------------------------------------.
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------|      |      |------+------+------|
   * |      |      |      |      |      |      |
   * |------+------|      |      |------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * `-----------------------------------------'
   */

/* (setq tab-stop-list '(6 15 24 33 42 51 60 69)) */
