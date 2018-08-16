#include "split_maxipad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LOWER 1 
#define _RAISE 2 
#define _MOUSE 3 
#define _SHIF 4 // shitit layer
#define _REVS 5 // reverse layer

#define MACRO_SHIFTIT_MOVE         10
#define MACRO_SHIFTIT_LUP         11
#define MACRO_SHIFTIT_LDOWN         12
#define MACRO_SHIFTIT_RUP         13
#define MACRO_SHIFTIT_RDOWN         14
#define MACRO_SHIFTIT_LEFT         15
#define MACRO_SHIFTIT_RIGHT         16
#define MACRO_SHIFTIT_UP         17
#define MACRO_SHIFTIT_DOWN         18
#define MACRO_SHIFTIT_FULL         19
#define MACRO_ZERO_ZERO           20

#define MACRO_TMUX_ESC 30
#define MACRO_TMUX_LANG 31
#define MACRO_TMUX_BRC 32
#define MACRO_TMUX_MINUS 33
#define MACRO_TMUX_S_MINUS 34
#define MACRO_TMUX_QUOT 35

#define MACRO_OSX_MISSION        40
#define MACRO_OSX_ZOOMIN        41
#define MACRO_OSX_ZOOMOUT        42
#define MACRO_OSX_FORWARD        43
#define MACRO_OSX_RETURN        44
#define MACRO_OSX_APP           45

#define M_SH_LU   M(MACRO_SHIFTIT_LUP)
#define M_SH_LD   M(MACRO_SHIFTIT_LDOWN)
#define M_SH_RU   M(MACRO_SHIFTIT_RUP)
#define M_SH_RD   M(MACRO_SHIFTIT_RDOWN)
#define M_SH_L   M(MACRO_SHIFTIT_LEFT)
#define M_SH_R   M(MACRO_SHIFTIT_RIGHT)
#define M_SH_U   M(MACRO_SHIFTIT_UP)
#define M_SH_D   M(MACRO_SHIFTIT_DOWN)
#define M_SH_FL   M(MACRO_SHIFTIT_FULL)
#define M_SH_MV   M(MACRO_SHIFTIT_MOVE)

#define M_TESC   M(MACRO_TMUX_ESC)
#define M_TLANG   M(MACRO_TMUX_LANG)
#define M_BRC   M(MACRO_TMUX_BRC)
#define M_MINUS   M(MACRO_TMUX_MINUS)
#define M_S_MINUS   M(MACRO_TMUX_S_MINUS)
#define M_QUOT   M(MACRO_TMUX_QUOT)

#define M_OSX_MISSION   M(MACRO_OSX_MISSION)
#define M_OSX_ZOOMIN   M(MACRO_OSX_ZOOMIN)
#define M_OSX_ZOOMOUT   M(MACRO_OSX_ZOOMOUT)
#define M_OSX_FORWARD   M(MACRO_OSX_FORWARD)
#define M_OSX_RETURN   M(MACRO_OSX_RETURN)
#define M_OSX_APP      M(MACRO_OSX_APP)

#define PUSH_TIME 100

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  SHIF,
  REVS,
};

//Tap Dance Declarations
enum {
 TD_BRC,
 TD_MINUS_EQL,
 TD_S_MINUS_EQL,
 TD_LCTL,
 TD_QUOT_BSLS,
 TD_LANG,
 TD_RAIS,
 TD_LOWR,
 TD_LAYR,
 TD_REVS
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
 * | Esc  | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    M_MINUS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    M_BRC,    KC_P,    KC_O,    KC_I,    KC_U,    KC_Y, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,    KC_SCLN,    KC_L,    KC_K,    KC_J, KC_H, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    M_QUOT,    KC_SLSH,    KC_DOT, KC_COMM,  KC_M, KC_N , \
  KC_ESC,  TD(TD_LANG), KC_LALT, KC_LGUI, TD(TD_LOWR),   LT(_MOUSE, KC_SPC),  KC_RIGHT,  KC_UP,   KC_DOWN, KC_LEFT, TD(TD_RAIS),   LT(_SHIF ,KC_BSPC) \
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
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11, KC_F10,   KC_F9,   KC_F8,   KC_F7,  KC_F6,  
  S(KC_GRV),S(KC_1),S(KC_2), S(KC_3), S(KC_4),S(KC_5),M_S_MINUS,S(KC_0), S(KC_9), S(KC_8), S(KC_7),S(KC_6),
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  RESET, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_DELETE \
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
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, RESET, _______,  _______, _______, _______, KC_DELETE \
),

[_MOUSE] = KEYMAP( \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11, KC_F10,   KC_F9,   KC_F8,   KC_F7,  KC_F6,  
  _______, _______, M_OSX_RETURN, KC_MS_U, M_OSX_FORWARD, _______, KC_F12, _______,  _______, _______, _______, _______, \
  _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, M_OSX_ZOOMOUT, _______, _______,  KC_RGHT, KC_UP, KC_DOWN, KC_LEFT, \
  _______, KC_BTN2, KC_WH_D, M_OSX_MISSION, KC_WH_U, M_OSX_ZOOMIN, _______, _______, LGUI(KC_V),LGUI(KC_X), LGUI(KC_C), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),


// SHIFTIT LAYER
[_SHIF] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, M_SH_LU, M_SH_U, M_SH_RU, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, M_SH_L, M_SH_FL, M_SH_R,  M_OSX_APP, _______, _______,  _______, _______, _______, _______, \
  _______, _______, M_SH_LD, M_SH_D, M_SH_RD, M_SH_MV,  _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_REVS] = KEYMAP( \
  TD(TD_MINUS_EQL), KC_0,    KC_9,    KC_8,    KC_7,    KC_6, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    \
  TD(TD_BRC),    KC_P,    KC_O,    KC_I,    KC_U,    KC_Y, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    \
  KC_ENT,    KC_SCLN,    KC_L,    KC_K,    KC_J, KC_H, TD(TD_LCTL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    \
  TD(TD_QUOT_BSLS),    KC_SLSH,    KC_DOT, KC_COMM,  KC_M, KC_N , KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    \
  KC_RIGHT,  KC_UP,   KC_DOWN, KC_LEFT, TD(TD_RAIS),   LT(_SHIF ,KC_BSPC), TG(_BASE),  TD(TD_LANG), KC_LALT, KC_LGUI, TD(TD_LOWR),   LT(_MOUSE, KC_SPC)
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

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _BASE);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _BASE);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _BASE);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _BASE);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
        update_tri_layer(_LOWER, _MOUSE, _BASE);
      } else {
        layer_off(_MOUSE);
        update_tri_layer(_LOWER, _MOUSE, _BASE);
      }
      return false;
      break;
    case SHIF:
      if (record->event.pressed) {
        layer_on(_SHIF);
        update_tri_layer(_LOWER, _SHIF, _BASE);
      } else {
        layer_off(_SHIF);
        update_tri_layer(_LOWER, _SHIF, _BASE);
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
        case MACRO_SHIFTIT_MOVE:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(N), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_FULL:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(M), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_RUP:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(2), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_LUP:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(1), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_LDOWN:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(3), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_RDOWN:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(4), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_LEFT:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(5), U(LCTL), U(LALT), U(LGUI), END);
        }
        case MACRO_SHIFTIT_RIGHT:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(6), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        break;
        case MACRO_SHIFTIT_UP:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(7), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
        case MACRO_SHIFTIT_DOWN:
        if (record->event.pressed) {
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(8), U(LCTL), U(LALT), U(LGUI), END);
        }
        break;
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
        case MACRO_OSX_MISSION: 
        if (record->event.pressed) {
          return MACRO(D(LCTL), T(UP), U(LCTL), END);
        }
        break;
        case MACRO_OSX_ZOOMIN: 
        if (record->event.pressed) {
          return MACRO(D(LGUI), D(LSHIFT), T(EQL), U(LSHIFT), U(LGUI), END);
        }
        break;
        case MACRO_OSX_ZOOMOUT: 
        if (record->event.pressed) {
          return MACRO(D(LGUI), T(MINUS), U(LGUI), END);
        }
        break;
        case MACRO_OSX_FORWARD: 
        if (record->event.pressed) {
          return MACRO(D(LGUI), T(RBRC), U(LGUI), END);
        }
        break;
        case MACRO_OSX_RETURN: 
        if (record->event.pressed) {
          return MACRO(D(LGUI), T(LBRC), U(LGUI), END);
        }
        break;
        case MACRO_OSX_APP: 
        if (record->event.pressed) {
          return MACRO(D(LGUI), T(TAB), END);
        }
        break;
      }
      return MACRO_NONE;
};

#ifdef TAP_DANCE_ENABLE
#undef TAPPING_TERM
#define TAPPING_TERM    100

void dance_raise_press(qk_tap_dance_state_t *state, void *user_data){// Called on each tap
  switch(state->count){      // Only turn the layer on once
    case 1:
        layer_off(_BASE);
        layer_off(_LOWER);
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _BASE);
        break;
  }
};

void dance_lower_press(qk_tap_dance_state_t *state, void *user_data){// Called on tap
  switch(state->count){
    case 1:         // Turn on lower
        layer_off(_BASE);
        layer_off(_RAISE);
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _BASE);
        break;
  }
};

void dance_raise_lift(qk_tap_dance_state_t *state, void *user_data){ // Called on release
  switch(state->count){
    case 1:         // Normal action. Turn off layers
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _BASE);
        layer_off(_BASE);
        break;
  }
};

void dance_lower_lift(qk_tap_dance_state_t *state, void *user_data){ // Called on release
  switch(state->count){
    case 1:         // Normal action. Turn off layers
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _BASE);
        layer_off(_BASE);
        break;
  }
};

void tap_change_layer(qk_tap_dance_state_t *state, void *user_data){ // Called on release
  switch (state->count) {
    case 1: // _BASE
      layer_on  (_BASE);        //define single tap here
      layer_off (_SHIF);
      layer_off (_MOUSE);
      layer_off (_RAISE);
      layer_off (_LOWER);
      break;
    case 2:
      layer_off (_BASE);
      layer_off (_SHIF);
      layer_on (_MOUSE);        //define double tap here
      layer_off (_RAISE);
      layer_off (_LOWER);
      break;
    case 3:
      layer_off (_BASE);
      layer_on (_SHIF);        //define triple tap here
      layer_off (_MOUSE);
      layer_off (_RAISE);
      layer_off (_LOWER);
      break;
    default:
      reset_tap_dance(state);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_BRC] = ACTION_TAP_DANCE_DOUBLE (KC_LBRC, KC_RBRC),
 [TD_MINUS_EQL] = ACTION_TAP_DANCE_DOUBLE (KC_MINUS, KC_EQL),
 [TD_S_MINUS_EQL] = ACTION_TAP_DANCE_DOUBLE (S(KC_MINUS), S(KC_EQL)),
 [TD_LCTL] = ACTION_TAP_DANCE_DOUBLE (KC_LCTL, KC_CAPS),
 [TD_LANG] = ACTION_TAP_DANCE_DOUBLE (KC_LANG2, KC_LANG1),
 [TD_QUOT_BSLS] = ACTION_TAP_DANCE_DOUBLE (KC_QUOT, KC_BSLS),
 [TD_RAIS] = ACTION_TAP_DANCE_FN_ADVANCED(dance_raise_press, NULL, dance_raise_lift),
 [TD_LOWR] = ACTION_TAP_DANCE_FN_ADVANCED(dance_lower_press, NULL, dance_lower_lift),
 [TD_LAYR] = ACTION_TAP_DANCE_FN (tap_change_layer)
};
#endif
