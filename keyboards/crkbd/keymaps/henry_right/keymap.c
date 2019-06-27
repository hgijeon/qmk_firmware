#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "mousekey.h"
#include "pointing_device.h"
#include "report.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

extern bool isScrollMode;
extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _R_LAY 1
#define _D_LAY 2
#define _ADJUST 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    R_LAY,
    D_LAY,
    ADJUST,
    BACKLIT,
    RGBRST,
    SCRL
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_R_LAY R_LAY
#define KC_D_LAY D_LAY
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)
#define KC_SCRL   SCRL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LALT,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RCTL,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI, D_LAY,  LSFT,      SPC, R_LAY,  RSFT \
                              //`--------------------'  `--------------------'
  ),

  [_R_LAY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  DELT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,                   LEFT,  DOWN,    UP, RIGHT,  MINS,   EQL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,   F11,   F12, _____, _____, _____,                  _____,  SCRL,  LBRC,  RBRC,  BSLS,  RALT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_D_LAY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  BTN4,  BTN3,  BTN2,  BTN1, _____,                   HOME,  PGDN,  PGUP,   END, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,      ENT, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

};


int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case R_LAY:
      if (record->event.pressed) {
        layer_on(_R_LAY);
      } else {
        layer_off(_R_LAY);
      }
      return false;
      break;
    case D_LAY:
      if (record->event.pressed) {
        layer_on(_D_LAY);
      } else {
        layer_off(_D_LAY);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
    case SCRL:
      if (record->event.pressed) {
        isScrollMode = true;
      }
      else {
        isScrollMode = false;
      }
      return false;
  }
  return true;
}
