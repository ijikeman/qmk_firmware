#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3
#define _LED 4

#define MACRO_TMUX_LANG 31
#define MACRO_TMUX_BRC 32
#define MACRO_TMUX_MINUS 33
#define MACRO_TMUX_S_MINUS 34
#define MACRO_TMUX_QUOT 35

#define MACRO_CUT 40
#define MACRO_COPY 41
#define MACRO_PASTE 42

#define M_LANG M(MACRO_TMUX_LANG)
#define M_BRC   M(MACRO_TMUX_BRC)
#define M_MINUS   M(MACRO_TMUX_MINUS)
#define M_S_MINUS   M(MACRO_TMUX_S_MINUS)
#define M_QUOT   M(MACRO_TMUX_QUOT)

#define M_CUT   M(MACRO_CUT)
#define M_COPY   M(MACRO_COPY)
#define M_PASTE   M(MACRO_PASTE)

#define PUSH_TIME 75

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  LED,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
* ,-----------------------------------------------------------------------------------.
* |      |  Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [/] |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | CTR  |  A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |ESC/SFT|  Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /  | '/\  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |  ALT | GUI  |Lower/SPC|Raise/BS | Led/IME|     |     |    |   |
* `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12(
   KC_ESC,       KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BRC, \
   CTL_T(KC_TAB), KC_A,KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
   SFT_T(KC_ESC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, M_QUOT, \
   _______,  _______,  _______, KC_LALT, KC_LGUI,LT(_LOWER,KC_SPC),LT(_RAISE,KC_BSPC), LT(_LED,M_LANG),_______,_______,_______,_______  \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _/+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|      |      |      |      |      | Del  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  S(KC_GRV),S(KC_1),S(KC_2), S(KC_3), S(KC_4),S(KC_5),S(KC_6), S(KC_7), S(KC_8), S(KC_9),S(KC_0), M_S_MINUS, \
  KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  RESET, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -/= |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | F7   |  F8  |  F9  | F10  | F11  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   M_MINUS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  MUP |     |WWW_REF| F7   |  F8  |  F9  | F10  | F11  |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |LCLICK| MLEFT|MDOWN |MRGHT |WWW_BK| LEFT | DOWN |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RCLICK|WHDOWN|      | WHUP |WWW_FW| CUT  | COPY | PASTE|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, KC_MS_U, _______, KC_WREF, KC_F7,  KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, \
  _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK, KC_LEFT,KC_DOWN, KC_UP, KC_RGHT,   _______, _______, \
  _______, KC_BTN2, KC_WH_D, _______, KC_WH_U, KC_WFWD, M_CUT,  M_COPY,  M_PASTE, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_LED] =  LAYOUT_ortho_4x12( \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
    case LED:
      if (record->event.pressed) {
        layer_on(_LED);
      } else {
        layer_off(_LED);
      }
      return false;
      break;
  }
  return true;
}

static uint16_t key_timer;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case MACRO_TMUX_LANG:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          return MACRO(D(LALT), T(GRAVE), U(LALT), END);
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
        case MACRO_TMUX_S_MINUS:
        if (record->event.pressed) {
          key_timer = timer_read();
        } else {
          if (timer_elapsed(key_timer) >= PUSH_TIME) {
            return MACRO(D(LSFT), T(EQL), U(LSFT), END);
          } else {
            return MACRO(D(LSFT), T(MINUS), U(LSFT), END);
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
        case MACRO_CUT:
        if (record->event.pressed) {
          return MACRO(D(LCTL), T(X), U(LCTL), END);
        }
        break;
        case MACRO_COPY:
        if (record->event.pressed) {
          return MACRO(D(LCTL), T(C), U(LCTL), END);
        }
        break;
        case MACRO_PASTE:
        if (record->event.pressed) {
          return MACRO(D(LCTL), T(V), U(LCTL), END);
        }
        break;
      }
      return MACRO_NONE;
};
