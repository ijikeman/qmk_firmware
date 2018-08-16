#include "split_maxipad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1 
#define _RAISE 2 
#define _MOUSE 3 

#define PUSH_TIME 200
#define MACRO_TMUX_ESC 30
#define MACRO_TMUX_LANG 31
#define MACRO_TMUX_BRC 32
#define MACRO_TMUX_MINUS 33
#define MACRO_TMUX_QUOT 34

#define M_TESC   M(MACRO_TMUX_ESC)
#define M_TLANG   M(MACRO_TMUX_LANG)
#define M_BRC   M(MACRO_TMUX_BRC)
#define M_MINUS   M(MACRO_TMUX_MINUS)
#define M_QUOT   M(MACRO_TMUX_QUOT)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  M_TESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    M_MINUS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    M_BRC,    KC_P,    KC_O,    KC_I,    KC_U,    KC_Y, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,    KC_SCLN,    KC_L,    KC_K,    KC_J, KC_H, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    M_QUOT,    KC_SLSH,    KC_DOT, KC_COMM,  KC_M, KC_N , \
  KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LT(_MOUSE, KC_SPC),  KC_RGHT,  KC_UP,   KC_DOWN, KC_LEFT, RAISE,   KC_BSPC \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11, KC_F10,   KC_F9,   KC_F8,   KC_F7,  KC_F6,  
  S(KC_GRV),S(KC_1),S(KC_2), S(KC_3), S(KC_4),S(KC_5),S(M_MINUS),S(KC_0), S(KC_9), S(KC_8), S(KC_7),S(KC_6),
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    M_MINUS,    KC_0,    KC_9,    KC_8,    KC_7,    KC_6, \
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_RGHT, KC_UP, KC_DOWN, KC_LEFT, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_MOUSE] = KEYMAP( \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11, KC_F10,   KC_F9,   KC_F8,   KC_F7,  KC_F6,  
  _______, _______, _______, KC_MS_U, _______, _______, KC_F12, _______,  _______, _______, _______, _______, \
  _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,  _______, _______, _______, _______, \
  _______, KC_BTN2, KC_WH_D, _______, KC_WH_U, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      }
      return false;
      break;
  }
  return true;
}

static uint16_t key_timer;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case MACRO_TMUX_ESC:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          if (timer_elapsed(key_timer) >= PUSH_TIME) {
            return MACRO(T(ESC), END);
          } else {
            return MACRO(T(GRV), END);
          }
        }
        break;
        case MACRO_TMUX_BRC:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          if (timer_elapsed(key_timer) >= PUSH_TIME) {
            return MACRO(T(RBRC), END);
          } else {
            return MACRO(T(LBRC), END);
          }
        }
        break;
        case MACRO_TMUX_LANG:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          if (timer_elapsed(key_timer) >= PUSH_TIME) {
            return MACRO(D(LGUI), T(SPC), U(LGUI), END);
          } else {
            return MACRO(END);
          }
        }
        break;
        case MACRO_TMUX_MINUS:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          if (timer_elapsed(key_timer) >= PUSH_TIME) {
            return MACRO(T(EQL), END);
          } else {
            return MACRO(T(MINUS), END);
          }
        }
        break;
        case MACRO_TMUX_QUOT:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          if (timer_elapsed(key_timer) >= PUSH_TIME) {
            return MACRO(T(BSLS), END);
          } else {
            return MACRO(T(QUOT), END);
          }
        }
        break;
      }
      return MACRO_NONE;
};
