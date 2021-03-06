#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
_QWERTY,
_QGMLWY,
_LOWER,
_RAISE,
_FUNCTION,
_MOVE,
_MOUSE,
_ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MO_MOVE MO(_MOVE)
#define ESC_MSL LT(_MOUSE, KC_ESC)
#define KC_SSPC SFT_T(KC_SPC)

#define OSM_GUI OSM(MOD_RGUI)
#define OSM_ALT OSM(MOD_RALT)
#define OSM_SFT OSM(MOD_RSFT)
#define OSM_CTL OSM(MOD_RCTL)
#define OSL_FUN OSL(_FUNCTION)

#define CTL_TAB LCTL(KC_TAB)
#define CTLSTAB LCTL(LSFT(KC_TAB))

#define MCR1_RC DYN_REC_START1
#define MCR2_RC DYN_REC_START2
#define MCR1_PL DYN_MACRO_PLAY1
#define MCR2_PL DYN_MACRO_PLAY2
#define MCR_STP DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
  ESC_MSL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ALT_T(KC_BSPC), \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT), \
  MO_MOVE, KC_LGUI, KC_LCTL, KC_LALT, LOWER,   KC_SPC,  KC_SSPC, RAISE,   KC_RCTL, KC_RALT, TG(_QGMLWY),   KC_RGUI \
),

[_QGMLWY] = KEYMAP(
  _______, KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN, _______,
  _______, KC_D,    KC_S,    KC_T,    KC_N,    KC_R,    KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_J,    KC_K,    KC_P,    _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = KEYMAP( \
  KC_GRV,  CTLSTAB, OSM_GUI, OSM_ALT, KC_F4,   KC_F5,   KC_F6,   KC_UNDS, CTL_TAB, KC_LCBR, KC_RCBR, KC_BSLS, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_F7,   KC_F8,   OSM_CTL, KC_F10,  KC_F11,  KC_F12,  KC_ENT,  KC_PLUS, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_RAISE] = KEYMAP( \
  KC_TILD, KC_F1,   OSM_GUI, OSM_ALT, OSM_SFT, KC_F5,   KC_F6,   OSL_FUN, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F7,   KC_F8,   OSM_CTL, KC_F10,  KC_F11,  KC_F12,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_FUNCTION] = KEYMAP( \
  _______, MCR1_RC, MCR1_PL, MCR2_RC, MCR2_PL, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, MCR_STP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


[_MOVE] = KEYMAP(
  KC_TAB,  KC_WH_L, KC_WH_U, KC_END , KC_ENT,  _______, _______, KC_PGUP, KC_TAB,  KC_LCBR, KC_HOME, KC_PIPE, \
  _______, KC_HOME, KC_WH_D, KC_PGDN, KC_BTN1, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______, \
  _______, _______, KC_WH_L, KC_WH_R, KC_F11,  KC_F12,  KC_END , KC_ENT,  KC_QUOT, KC_DQT,  _______, _______, \
  _______, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, _______ \
),


[_MOUSE] = KEYMAP(
  _______, _______, KC_WH_U, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, KC_INS,  KC_DEL,
  _______, _______, KC_WH_D, _______, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_WH_D, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_ACL2, KC_ACL1, KC_ACL0, RESET,   _______ \
),

[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_MUTE, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_VOLU, KC_VOLD, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
