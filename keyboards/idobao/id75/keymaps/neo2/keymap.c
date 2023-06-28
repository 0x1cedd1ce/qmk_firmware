/* Copyright 2023 Oxi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap_german.h"

// Keyboard Layers
#define _L1D 0
#define _L1 1
#define _L2 3
#define _L2D 4
#define _L3 5
#define _L3D 6
#define _L4 7
#define _L4D 8
#define _L5 9
#define _L6 10
#define _QW 2
#define _FN 11

#define CONCAT(m, n) m ## n
#define NU(v) UC(CONCAT(0x, v))

enum custom_keycodes {
  NE_M3 = SAFE_RANGE,
  NE_M4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | q      | w      | e      | r      | t      | y      | u      | i      | o      | p      | [      | ]      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | CAPS   | a      | s      | d      | f      | g      | h      | j      | k      | l      | ;      | '      | \      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | Mod4   | LSHIFT | z      | x      | c      | v      | b      | n      | m      | ,      | .      | /      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    MO(_FN), KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, DF(_L1),
    KC_ESC,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
    KC_RALT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  MO(_L4), KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | QK_BOOT  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NUM,  KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS,
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, QK_BOOT,   _______, _______, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
 ),

 /* NEO2 Layer 1
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ˆ      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | `      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | x      | v      | l      | c      | w      | k      | h      | g      | f      | q      | ß      | '      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | u      | i      | a      | e      | o      | s      | n      | r      | t      | d      | y      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | ü      | ö      | ä      | p      | z      | b      | m      | ,      | .      | j      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L1] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(0302),KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    MO(_FN), KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    UC(L'ß'),KC_RBRC, DF(_L1D),
    KC_ESC,  NE_M3,   KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_Y,    NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, UC(L'ü'),UC(L'ö'),UC(L'ä'),KC_P,    KC_Z,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* NEO2 Layer 2
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ˇ      | °      | §      | ℓ      | »      | «      | $      | €      | „      | “      | ”      | —      | ¸      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | X      | V      | L      | C      | W      | K      | H      | G      | F      | Q      | ẞ      | ̃      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | U      | I      | A      | E      | O      | S      | N      | R      | T      | D      | Y      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | Ü      | Ö      | Ä      | P      | Z      | B      | M      | –      | •      | J      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L2] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(030C),UC(L'°'),NU(00A7),UC(L'ℓ'),UC(L'»'),UC(L'«'),KC_DLR,  UC(L'€'),UC(L'„'),UC(L'“'),UC(L'”'),NU(2014),NU(0327),KC_BSPC,
    MO(_FN), KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    UC(L'ẞ'),NU(0303),KC_TRNS,
    KC_ESC,  NE_M3,   KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_Y, NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, UC(L'Ü'),UC(L'Ö'),UC(L'Ä'),KC_P,    KC_Z,    KC_B,    KC_M,    NU(2013),UC(L'•'),S(KC_J), KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

 /* NEO2 Layer 3
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ↻      | ¹      | ²      | ³      | ›      | ‹      | ¢      | ¥      | ‚      | ‘      | ’      |        | ̊      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | …      | _      | [      | ]      | ^      | !      | <      | >      | =      | &      | ſ      | ̷      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | \      | /      | {      | }      | *      | ?      | (      | )      | -      | :      | @      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | #      | $      | |      | ~      | `      | +      | %      | "      | '      | ;      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L3] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(02B4),NU(00B9),NU(00B2),NU(00B3),UC(L'›'),UC(L'‹'),UC(L'¢'),UC(L'¥'),UC(L'‚'),UC(L'‘'),UC(L'’'),KC_NO,  NU(030A),KC_BSPC,
    MO(_FN), KC_RALT, UC(L'…'),KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, UC(L'ſ'),NU(0338),KC_TRNS,
    KC_ESC,  NE_M3,   KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT,   NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

 /* NEO2 Layer 4
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ̇      | ª      | º      | №      |        | ·      | £      | ¤      | Num    | /      | *      | -      | ̈      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | Pg Up  | Bcksp  | Up     | Del    | Pg Dw  | ¡      | 7      | 8      | 9      | +      | -      | ̋      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | Home   | Left   | Down   | Right  | End    | ¿      | 4      | 5      | 6      | ,      | .      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT |  ESC   | LTab   | Ins    | Enter  | Undo   | :      | 1      | 2      | 3      | ;      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | 0      | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L4] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(0307),NU(00AA),NU(00BA),UC(L'№'),KC_NO,   UC(L'·'),UC(L'£'),UC(L'¤'),KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, NU(0308),KC_BSPC,
    MO(_FN), KC_TAB,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, UC(L'¡'),KC_P7,   KC_P8,   KC_P9,   KC_PPLS, NU(2212),KC_RBRC, UC_NEXT,
    KC_ESC,  NE_M3,   KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  UC(L'¿'),KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_PDOT, NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, KC_ESC,  S(KC_TAB),KC_INS, KC_ENT,  KC_UNDO, KC_COLN,  KC_P1,   KC_P2,   KC_P3,   KC_SCLN, KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_P0,   KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* NEO2 Layer 5
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ˞      | ₁      | ₂      | ₃      | ♀      | ♂      | ⚥      | ϰ      | ⟨      | ⟩      | ₀      | ‑      | ̔      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | ξ      |        | λ      | χ      | ω      | κ      | ψ      | γ      | φ      | ϕ      | ς      | ̓      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     |        | ι      | α      | ε      | ο      | σ      | ν      | ρ      | τ      | δ      | υ      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT |        | ϵ      | η      | π      | ζ      | β      | μ      | ϱ      | ϑ      | θ      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | PSPACE | HOME   | END    | PSPACE | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L5] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(02DE),NU(2081),NU(2082),NU(2083),UC(L'♀'),UC(L'♂'),UC(L'⚥'),UC(L'ϰ'),UC(L'⟨'),UC(L'⟩'),NU(2080),NU(2011),NU(0314),KC_BSPC,
    MO(_FN), KC_TAB,  UC(L'ξ'),KC_NO,   UC(L'λ'),UC(L'χ'),UC(L'ω'),UC(L'κ'),UC(L'ψ'),UC(L'γ'),UC(L'φ'),UC(L'ϕ'),UC(L'ς'),NU(0313),KC_TRNS,
    KC_ESC,  NE_M3,   KC_NO,   UC(L'ι'),UC(L'α'),UC(L'ε'),UC(L'ο'),UC(L'σ'),UC(L'ν'),UC(L'ρ'),UC(L'τ'),UC(L'δ'),UC(L'υ'),NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, KC_NO,   UC(L'ϵ'),UC(L'η'),UC(L'π'),UC(L'ζ'),UC(L'β'),UC(L'μ'),UC(L'ϱ'),UC(L'ϑ'),UC(L'θ'),KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, NU(00A0),KC_HOME, KC_END,  NU(00A0),NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* NEO2 Layer 6
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ̣      | ¬      | ∨      | ∧      | ⊥      | ∡      | ∥      | →      | ∞      | ∝      | ∅      | -      | ̄      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | Ξ      | √      | Λ      | ℂ      | Ω      | ×      | Ψ      | Γ      | Φ      | ℚ      | ∘      | ̆      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | ⊂      | ∫      | ∀      | ∃      | ∈      | Σ      | ℕ      | ℝ      | ∂      | Δ      | ∇      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | ∪      | ∩      | ℵ      | Π      | ℤ      | ⇐      | ⇔      | ⇒      | ↦      | Θ      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPSPACE| HOME   | END    | SPSPACE| Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L6] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(0302),UC(L'¬'),UC(L'∨'),UC(L'∧'),UC(L'⊥'),UC(L'∡'),UC(L'∥'),UC(L'→'),UC(L'∞'),UC(L'∝'),UC(L'∅'),NU(00AD),NU(0304),KC_BSPC,
    MO(_FN), KC_TAB,  UC(L'Ξ'),UC(L'√'),UC(L'Λ'),UC(L'ℂ'),UC(L'Ω'),UC(L'×'),UC(L'Ψ'),UC(L'Γ'),UC(L'Φ'),UC(L'ℚ'),UC(L'∘'),NU(0306),KC_TRNS,
    KC_ESC,  NE_M3,   UC(L'⊂'),UC(L'∫'),UC(L'∀'),UC(L'∃'),UC(L'∈'),UC(L'Σ'),UC(L'ℕ'),UC(L'ℝ'),UC(L'∂'),UC(L'Δ'),UC(L'∇'),NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, UC(L'∪'),UC(L'∩'),UC(L'ℵ'),UC(L'Π'),UC(L'ℤ'),UC(L'⇐'),UC(L'⇔'),UC(L'⇒'),UC(L'↦'),UC(L'Θ'),KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, NU(202F),KC_HOME, KC_END,  NU(202F),NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

 /* NEO2 Layer 1
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ˆ      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | `      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | x      | v      | l      | c      | w      | k      | h      | g      | f      | q      | ß      | '      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | u      | i      | a      | e      | o      | s      | n      | r      | t      | d      | y      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | ü      | ö      | ä      | p      | z      | b      | m      | ,      | .      | j      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L1D] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, DE_CIRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_MINS, DE_EQL,  KC_BSPC,
    MO(_FN), KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    DE_SS,   KC_RBRC, DF(_QW),
    KC_ESC,  NE_M3,   KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    DE_Y,    NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, DE_UDIA, DE_ODIA, DE_ADIA, KC_P,    DE_Z,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* NEO2 Layer 2
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ˇ      | °      | §      | ℓ      | »      | «      | $      | €      | „      | “      | ”      | —      | ¸      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | X      | V      | L      | C      | W      | K      | H      | G      | F      | Q      | ẞ      | ̃      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | U      | I      | A      | E      | O      | S      | N      | R      | T      | D      | Y      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | Ü      | Ö      | Ä      | P      | Z      | B      | M      | –      | •      | J      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L2D] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(030C),DE_DEG,  DE_SECT, UC(L'ℓ'),UC(L'»'),UC(L'«'),DE_DLR,  DE_EURO, UC(L'„'),UC(L'“'),UC(L'”'),NU(2014),NU(0327),KC_BSPC,
    MO(_FN), KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    UC(L'ẞ'),NU(0303),KC_TRNS,
    KC_ESC,  NE_M3,   KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    DE_Y,    NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, DE_UDIA, DE_ODIA, DE_ADIA, KC_P,    DE_Z,    KC_B,    KC_M,    NU(2013),UC(L'•'),KC_J,    KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),
/* NEO2 Layer 3
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ↻      | ¹      | ²      | ³      | ›      | ‹      | ¢      | ¥      | ‚      | ‘      | ’      |        | ̊      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | …      | _      | [      | ]      | ^      | !      | <      | >      | =      | &      | ſ      | ̷      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | \      | /      | {      | }      | *      | ?      | (      | )      | -      | :      | @      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT | #      | $      | |      | ~      | `      | +      | %      | "      | '      | ;      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | SPACE  | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L3D] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(02B4),NU(00B9),NU(00B2),NU(00B3),UC(L'›'),UC(L'‹'),UC(L'¢'),UC(L'¥'),UC(L'‚'),UC(L'‘'),UC(L'’'),KC_NO,  NU(030A),KC_BSPC,
    MO(_FN), KC_RALT, UC(L'…'),DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, UC(L'ſ'),NU(0338),KC_TRNS,
    KC_ESC,  NE_M3,   DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,   NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,  DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_SPC,  KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

 /* NEO2 Layer 4
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ̇      | ª      | º      | №      |        | ·      | £      | ¤      | Num    | /      | *      | -      | ̈      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | Pg Up  | Bcksp  | Up     | Del    | Pg Dw  | ¡      | 7      | 8      | 9      | +      | -      | ̋      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     | Home   | Left   | Down   | Right  | End    | ¿      | 4      | 5      | 6      | ,      | .      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT |  ESC   | LTab   | Ins    | Enter  | Undo   | :      | 1      | 2      | 3      | ;      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | SPACE  | HOME   | END    | 0      | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_L4D] = LAYOUT_ortho_5x15( /* QWERTY */
    QK_BOOT, NU(0307),NU(00AA),NU(00BA),UC(L'№'),KC_NO,   UC(L'·'),UC(L'£'),UC(L'¤'),KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, NU(0308),KC_BSPC,
    MO(_FN), KC_TAB,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, UC(L'¡'),KC_P7,   KC_P8,   KC_P9,   KC_PPLS, NU(2212),KC_RBRC, UC_NEXT,
    KC_ESC,  NE_M3,   KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  UC(L'¿'),KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_PDOT, NE_M3,   KC_ENT,
    NE_M4,   KC_LSFT, KC_ESC,  S(KC_TAB),KC_INS, KC_ENT,  KC_UNDO, DE_COLN, KC_P1,   KC_P2,   KC_P3,   DE_SCLN, KC_RSFT, KC_UP,   KC_DEL,
    KC_PSCR, KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_P0,   KC_HOME, KC_END,  KC_SPC,  NE_M4,   KC_PGUP, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* NEO2 Layer 5
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | ˞      | ₁      | ₂      | ₃      | ♀      | ♂      | ⚥      | ϰ      | ⟨      | ⟩      | ₀      | ‑      | ̔      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | FN     | TAB    | ξ      |        | λ      | χ      | ω      | κ      | ψ      | γ      | φ      | ϕ      | ς      | ̓      | SW_LYT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | M3     |        | ι      | α      | ε      | ο      | σ      | ν      | ρ      | τ      | δ      | υ      | M3     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | M4     | LSHIFT |        | ϵ      | η      | π      | ζ      | β      | μ      | ϱ      | ϑ      | θ      | RSHIFT | UP     | DEL    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | PRINT  | LCTRL  | LGUI   | MENU   | LALT   | PSPACE | HOME   | END    | PSPACE | Mod4   | PG UP  | PG DN  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _L1:
            case _L1D:
                rgb_matrix_set_color(i, RGB_ORANGE);
                break;
            case _L2:
            case _L2D:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            case _L3:
            case _L3D:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case _L4:
            case _L4D:
                if(IS_LAYER_ON_STATE(default_layer_state ,_L1) || IS_LAYER_ON_STATE(default_layer_state, _L1D)) {
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else {
                    rgb_matrix_set_color(i, RGB_AZURE);
                }
                break;
            case _L5:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            case _L6:
                rgb_matrix_set_color(i, RGB_MAGENTA);
                break;
            case _FN:
                rgb_matrix_set_color(i, RGB_GOLD);
                break;
            case _QW:
                rgb_matrix_set_color(i, RGB_WHITE);
                break;
            default:
                break;
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NE_M3:
      if (IS_LAYER_ON_STATE(default_layer_state ,_L1)) {
        if (record->event.pressed) {
            layer_on(_L3);
            update_tri_layer(_L3, _L4, _L6);
            update_tri_layer(_L3, _L2, _L5);
        } else {
            layer_off(_L3);
            update_tri_layer(_L3, _L4, _L6);
            update_tri_layer(_L3, _L2, _L5);
        }
      } else {
        if (record->event.pressed) {
            layer_on(_L3D);
            update_tri_layer(_L3D, _L4D, _L6);
            update_tri_layer(_L3D, _L2D, _L5);
        } else {
            layer_off(_L3D);
            update_tri_layer(_L3D, _L4D, _L6);
            update_tri_layer(_L3D, _L2D, _L5);
        }
      }
      return false;
    case NE_M4:
      if (IS_LAYER_ON_STATE(default_layer_state, _L1)) {
        if (record->event.pressed) {
            layer_on(_L4);
            update_tri_layer(_L3, _L4, _L6);
        } else {
            layer_off(_L4);
            update_tri_layer(_L3, _L4, _L6);
        }
      } else {
        if (record->event.pressed) {
            layer_on(_L4D);
            update_tri_layer(_L3D, _L4D, _L6);
        } else {
            layer_off(_L4D);
            update_tri_layer(_L3D, _L4D, _L6);
        }
      }
      return false;
    case KC_LSFT:
    case KC_RSFT:
      if (record->event.pressed && IS_LAYER_ON_STATE(default_layer_state ,_L1)) {
        layer_on(_L2);
        update_tri_layer(_L3, _L2, _L5);
      } else {
        layer_off(_L2);
        update_tri_layer(_L3, _L2, _L5);
      }
      if (record->event.pressed && IS_LAYER_ON_STATE(default_layer_state ,_L1D)) {
        layer_on(_L2D);
        update_tri_layer(_L3D, _L2D, _L5);
      } else {
        layer_off(_L2D);
        update_tri_layer(_L3D, _L2D, _L5);
      }
  }
  return true;
}
