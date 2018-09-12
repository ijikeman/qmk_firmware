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

#define MACRO_TMUX_ESC 30
#define MACRO_TMUX_LANG 31
#define MACRO_TMUX_BRC 32
#define MACRO_TMUX_MINUS 33
#define MACRO_TMUX_S_MINUS 34
#define MACRO_TMUX_QUOT 35

#define M_TESC   M(MACRO_TMUX_ESC)
#define M_TLANG   M(MACRO_TMUX_LANG)
#define M_BRC   M(MACRO_TMUX_BRC)
#define M_MINUS   M(MACRO_TMUX_MINUS)
#define M_S_MINUS   M(MACRO_TMUX_S_MINUS)
#define M_QUOT   M(MACRO_TMUX_QUOT)

#define PUSH_TIME 100

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
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
 TD_LOWR
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
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BRC, \
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, M_QUOT, \
   KC_ESC,  M_TLANG, KC_LALT, KC_LGUI,LOWER,LT(_MOUSE,KC_SPC),SFT_T(KC_BSPC), RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  S(KC_GRV),S(KC_1),S(KC_2), S(KC_3), S(KC_4),S(KC_5),S(KC_6), S(KC_7), S(KC_8), S(KC_9),S(KC_0), M_S_MINUS, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  RESET, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, M_MINUS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, KC_MS_U, _______, _______, KC_F7,  KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, \
  _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   _______, _______, \
  _______, KC_BTN2, KC_WH_D, _______, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
)


};

static uint16_t shift_count = 0; //this is used to keep track of shift state and avoid inserting non breakable space
void hold_shift(void) {
  shift_count = shift_count + 1;
  register_code(KC_LSHIFT);
}

void release_shift(void) {
  shift_count = shift_count - 1;
  if(shift_count <= 0){
    unregister_code(KC_LSHIFT);
    shift_count = 0;
  }
}

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
        update_tri_layer(_LOWER, _RAISE, _MOUSE);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MOUSE);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MOUSE);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MOUSE);
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
  }
  return true;
}

static uint16_t key_timer;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
            return MACRO(D(LALT), T(GRV), U(LALT), END);
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
      layer_off (_MOUSE);
      layer_off (_RAISE);
      layer_off (_LOWER);
      break;
    case 2:
      layer_off (_BASE);
      layer_on (_MOUSE);        //define double tap here
      layer_off (_RAISE);
      layer_off (_LOWER);
      break;
    case 3:
      layer_off (_BASE);
      layer_off (_MOUSE);
      layer_on (_RAISE);
      layer_off (_LOWER);
      break;
    default:
      reset_tap_dance(state);
  }
}

_action_t tap_dance_actions[] = {
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

