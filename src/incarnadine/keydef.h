/* 
   Copyright (c) 2010 Daniel Collins, Daniel Flahive

   Permission to use, copy, modify, and distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.
 
   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef ENGINE_KEYDEF_H
#define ENGINE_KEYDEF_H

#include "SDL_keysym.h"

// Generated with:
// awk '$1 ~ "SDLK_[a-zA-Z0-9]+" { printf " INC_KEY_%-16s%s\n", substr($1, 6, length($1)-1), $1 }' SDL_keysym.h

enum Key {INC_KEY_UNKNOWN = SDLK_UNKNOWN,
          INC_KEY_FIRST       = SDLK_FIRST,
          INC_KEY_BACKSPACE   = SDLK_BACKSPACE,
          INC_KEY_TAB         = SDLK_TAB,
          INC_KEY_CLEAR       = SDLK_CLEAR,
          INC_KEY_RETURN      = SDLK_RETURN,
          INC_KEY_PAUSE       = SDLK_PAUSE,
          INC_KEY_ESCAPE      = SDLK_ESCAPE,
          INC_KEY_SPACE       = SDLK_SPACE,
          INC_KEY_EXCLAIM     = SDLK_EXCLAIM,
          INC_KEY_QUOTEDBL    = SDLK_QUOTEDBL,
          INC_KEY_HASH        = SDLK_HASH,
          INC_KEY_DOLLAR      = SDLK_DOLLAR,
          INC_KEY_AMPERSAND   = SDLK_AMPERSAND,
          INC_KEY_QUOTE       = SDLK_QUOTE,
          INC_KEY_LEFTPAREN   = SDLK_LEFTPAREN,
          INC_KEY_RIGHTPAREN  = SDLK_RIGHTPAREN,
          INC_KEY_ASTERISK    = SDLK_ASTERISK,
          INC_KEY_PLUS        = SDLK_PLUS,
          INC_KEY_COMMA       = SDLK_COMMA,
          INC_KEY_MINUS       = SDLK_MINUS,
          INC_KEY_PERIOD      = SDLK_PERIOD,
          INC_KEY_SLASH       = SDLK_SLASH,
          INC_KEY_0           = SDLK_0,
          INC_KEY_1           = SDLK_1,
          INC_KEY_2           = SDLK_2,
          INC_KEY_3           = SDLK_3,
          INC_KEY_4           = SDLK_4,
          INC_KEY_5           = SDLK_5,
          INC_KEY_6           = SDLK_6,
          INC_KEY_7           = SDLK_7,
          INC_KEY_8           = SDLK_8,
          INC_KEY_9           = SDLK_9,
          INC_KEY_COLON       = SDLK_COLON,
          INC_KEY_SEMICOLON   = SDLK_SEMICOLON,
          INC_KEY_LESS        = SDLK_LESS,
          INC_KEY_EQUALS      = SDLK_EQUALS,
          INC_KEY_GREATER     = SDLK_GREATER,
          INC_KEY_QUESTION    = SDLK_QUESTION,
          INC_KEY_AT          = SDLK_AT,
          INC_KEY_LEFTBRACKET = SDLK_LEFTBRACKET,
          INC_KEY_BACKSLASH   = SDLK_BACKSLASH,
          INC_KEY_RIGHTBRACKET= SDLK_RIGHTBRACKET,
          INC_KEY_CARET       = SDLK_CARET,
          INC_KEY_UNDERSCORE  = SDLK_UNDERSCORE,
          INC_KEY_BACKQUOTE   = SDLK_BACKQUOTE,
          INC_KEY_A           = SDLK_a,
          INC_KEY_B           = SDLK_b,
          INC_KEY_C           = SDLK_c,
          INC_KEY_D           = SDLK_d,
          INC_KEY_E           = SDLK_e,
          INC_KEY_F           = SDLK_f,
          INC_KEY_G          = SDLK_g,
          INC_KEY_H           = SDLK_h,
          INC_KEY_I           = SDLK_i,
          INC_KEY_J           = SDLK_j,
          INC_KEY_K           = SDLK_k,
          INC_KEY_L           = SDLK_l,
          INC_KEY_M           = SDLK_m,
          INC_KEY_N           = SDLK_n,
          INC_KEY_O           = SDLK_o,
          INC_KEY_P           = SDLK_p,
          INC_KEY_Q           = SDLK_q,
          INC_KEY_R           = SDLK_r,
          INC_KEY_S           = SDLK_s,
          INC_KEY_T           = SDLK_t,
          INC_KEY_U           = SDLK_u,
          INC_KEY_V           = SDLK_v,
          INC_KEY_W           = SDLK_w,
          INC_KEY_X           = SDLK_x,
          INC_KEY_Y           = SDLK_y,
          INC_KEY_Z           = SDLK_z,
          INC_KEY_DELETE      = SDLK_DELETE,
          INC_KEY_WORLD_0     = SDLK_WORLD_0,
          INC_KEY_WORLD_1     = SDLK_WORLD_1,
          INC_KEY_WORLD_2     = SDLK_WORLD_2,
          INC_KEY_WORLD_3     = SDLK_WORLD_3,
          INC_KEY_WORLD_4     = SDLK_WORLD_4,
          INC_KEY_WORLD_5     = SDLK_WORLD_5,
          INC_KEY_WORLD_6     = SDLK_WORLD_6,
          INC_KEY_WORLD_7     = SDLK_WORLD_7,
          INC_KEY_WORLD_8     = SDLK_WORLD_8,
          INC_KEY_WORLD_9     = SDLK_WORLD_9,
          INC_KEY_WORLD_10    = SDLK_WORLD_10,
          INC_KEY_WORLD_11    = SDLK_WORLD_11,
          INC_KEY_WORLD_12    = SDLK_WORLD_12,
          INC_KEY_WORLD_13    = SDLK_WORLD_13,
          INC_KEY_WORLD_14    = SDLK_WORLD_14,
          INC_KEY_WORLD_15    = SDLK_WORLD_15,
          INC_KEY_WORLD_16    = SDLK_WORLD_16,
          INC_KEY_WORLD_17    = SDLK_WORLD_17,
          INC_KEY_WORLD_18    = SDLK_WORLD_18,
          INC_KEY_WORLD_19    = SDLK_WORLD_19,
          INC_KEY_WORLD_20    = SDLK_WORLD_20,
          INC_KEY_WORLD_21    = SDLK_WORLD_21,
          INC_KEY_WORLD_22    = SDLK_WORLD_22,
          INC_KEY_WORLD_23    = SDLK_WORLD_23,
          INC_KEY_WORLD_24    = SDLK_WORLD_24,
          INC_KEY_WORLD_25    = SDLK_WORLD_25,
          INC_KEY_WORLD_26    = SDLK_WORLD_26,
          INC_KEY_WORLD_27    = SDLK_WORLD_27,
          INC_KEY_WORLD_28    = SDLK_WORLD_28,
          INC_KEY_WORLD_29    = SDLK_WORLD_29,
          INC_KEY_WORLD_30    = SDLK_WORLD_30,
          INC_KEY_WORLD_31    = SDLK_WORLD_31,
          INC_KEY_WORLD_32    = SDLK_WORLD_32,
          INC_KEY_WORLD_33    = SDLK_WORLD_33,
          INC_KEY_WORLD_34    = SDLK_WORLD_34,
          INC_KEY_WORLD_35    = SDLK_WORLD_35,
          INC_KEY_WORLD_36    = SDLK_WORLD_36,
          INC_KEY_WORLD_37    = SDLK_WORLD_37,
          INC_KEY_WORLD_38    = SDLK_WORLD_38,
          INC_KEY_WORLD_39    = SDLK_WORLD_39,
          INC_KEY_WORLD_40    = SDLK_WORLD_40,
          INC_KEY_WORLD_41    = SDLK_WORLD_41,
          INC_KEY_WORLD_42    = SDLK_WORLD_42,
          INC_KEY_WORLD_43    = SDLK_WORLD_43,
          INC_KEY_WORLD_44    = SDLK_WORLD_44,
          INC_KEY_WORLD_45    = SDLK_WORLD_45,
          INC_KEY_WORLD_46    = SDLK_WORLD_46,
          INC_KEY_WORLD_47    = SDLK_WORLD_47,
          INC_KEY_WORLD_48    = SDLK_WORLD_48,
          INC_KEY_WORLD_49    = SDLK_WORLD_49,
          INC_KEY_WORLD_50    = SDLK_WORLD_50,
          INC_KEY_WORLD_51    = SDLK_WORLD_51,
          INC_KEY_WORLD_52    = SDLK_WORLD_52,
          INC_KEY_WORLD_53    = SDLK_WORLD_53,
          INC_KEY_WORLD_54    = SDLK_WORLD_54,
          INC_KEY_WORLD_55    = SDLK_WORLD_55,
          INC_KEY_WORLD_56    = SDLK_WORLD_56,
          INC_KEY_WORLD_57    = SDLK_WORLD_57,
          INC_KEY_WORLD_58    = SDLK_WORLD_58,
          INC_KEY_WORLD_59    = SDLK_WORLD_59,
          INC_KEY_WORLD_60    = SDLK_WORLD_60,
          INC_KEY_WORLD_61    = SDLK_WORLD_61,
          INC_KEY_WORLD_62    = SDLK_WORLD_62,
          INC_KEY_WORLD_63    = SDLK_WORLD_63,
          INC_KEY_WORLD_64    = SDLK_WORLD_64,
          INC_KEY_WORLD_65    = SDLK_WORLD_65,
          INC_KEY_WORLD_66    = SDLK_WORLD_66,
          INC_KEY_WORLD_67    = SDLK_WORLD_67,
          INC_KEY_WORLD_68    = SDLK_WORLD_68,
          INC_KEY_WORLD_69    = SDLK_WORLD_69,
          INC_KEY_WORLD_70    = SDLK_WORLD_70,
          INC_KEY_WORLD_71    = SDLK_WORLD_71,
          INC_KEY_WORLD_72    = SDLK_WORLD_72,
          INC_KEY_WORLD_73    = SDLK_WORLD_73,
          INC_KEY_WORLD_74    = SDLK_WORLD_74,
          INC_KEY_WORLD_75    = SDLK_WORLD_75,
          INC_KEY_WORLD_76    = SDLK_WORLD_76,
          INC_KEY_WORLD_77    = SDLK_WORLD_77,
          INC_KEY_WORLD_78    = SDLK_WORLD_78,
          INC_KEY_WORLD_79    = SDLK_WORLD_79,
          INC_KEY_WORLD_80    = SDLK_WORLD_80,
          INC_KEY_WORLD_81    = SDLK_WORLD_81,
          INC_KEY_WORLD_82    = SDLK_WORLD_82,
          INC_KEY_WORLD_83    = SDLK_WORLD_83,
          INC_KEY_WORLD_84    = SDLK_WORLD_84,
          INC_KEY_WORLD_85    = SDLK_WORLD_85,
          INC_KEY_WORLD_86    = SDLK_WORLD_86,
          INC_KEY_WORLD_87    = SDLK_WORLD_87,
          INC_KEY_WORLD_88    = SDLK_WORLD_88,
          INC_KEY_WORLD_89    = SDLK_WORLD_89,
          INC_KEY_WORLD_90    = SDLK_WORLD_90,
          INC_KEY_WORLD_91    = SDLK_WORLD_91,
          INC_KEY_WORLD_92    = SDLK_WORLD_92,
          INC_KEY_WORLD_93    = SDLK_WORLD_93,
          INC_KEY_WORLD_94    = SDLK_WORLD_94,
          INC_KEY_WORLD_95    = SDLK_WORLD_95,
          INC_KEY_KP0         = SDLK_KP0,
          INC_KEY_KP1         = SDLK_KP1,
          INC_KEY_KP2         = SDLK_KP2,
          INC_KEY_KP3         = SDLK_KP3,
          INC_KEY_KP4         = SDLK_KP4,
          INC_KEY_KP5         = SDLK_KP5,
          INC_KEY_KP6         = SDLK_KP6,
          INC_KEY_KP7         = SDLK_KP7,
          INC_KEY_KP8         = SDLK_KP8,
          INC_KEY_KP9         = SDLK_KP9,
          INC_KEY_KP_PERIOD   = SDLK_KP_PERIOD,
          INC_KEY_KP_DIVIDE   = SDLK_KP_DIVIDE,
          INC_KEY_KP_MULTIPLY = SDLK_KP_MULTIPLY,
          INC_KEY_KP_MINUS    = SDLK_KP_MINUS,
          INC_KEY_KP_PLUS     = SDLK_KP_PLUS,
          INC_KEY_KP_ENTER    = SDLK_KP_ENTER,
          INC_KEY_KP_EQUALS   = SDLK_KP_EQUALS,
          INC_KEY_UP          = SDLK_UP,
          INC_KEY_DOWN        = SDLK_DOWN,
          INC_KEY_RIGHT       = SDLK_RIGHT,
          INC_KEY_LEFT        = SDLK_LEFT,
          INC_KEY_INSERT      = SDLK_INSERT,
          INC_KEY_HOME        = SDLK_HOME,
          INC_KEY_END         = SDLK_END,
          INC_KEY_PAGEUP      = SDLK_PAGEUP,
          INC_KEY_PAGEDOWN    = SDLK_PAGEDOWN,
          INC_KEY_F1          = SDLK_F1,
          INC_KEY_F2          = SDLK_F2,
          INC_KEY_F3          = SDLK_F3,
          INC_KEY_F4          = SDLK_F4,
          INC_KEY_F5          = SDLK_F5,
          INC_KEY_F6          = SDLK_F6,
          INC_KEY_F7          = SDLK_F7,
          INC_KEY_F8          = SDLK_F8,
          INC_KEY_F9          = SDLK_F9,
          INC_KEY_F10         = SDLK_F10,
          INC_KEY_F11         = SDLK_F11,
          INC_KEY_F12         = SDLK_F12,
          INC_KEY_F13         = SDLK_F13,
          INC_KEY_F14         = SDLK_F14,
          INC_KEY_F15         = SDLK_F15,
          INC_KEY_NUMLOCK     = SDLK_NUMLOCK,
          INC_KEY_CAPSLOCK    = SDLK_CAPSLOCK,
          INC_KEY_SCROLLOCK   = SDLK_SCROLLOCK,
          INC_KEY_RSHIFT      = SDLK_RSHIFT,
          INC_KEY_LSHIFT      = SDLK_LSHIFT,
          INC_KEY_RCTRL       = SDLK_RCTRL,
          INC_KEY_LCTRL       = SDLK_LCTRL,
          INC_KEY_RALT        = SDLK_RALT,
          INC_KEY_LALT        = SDLK_LALT,
          INC_KEY_RMETA       = SDLK_RMETA,
          INC_KEY_LMETA       = SDLK_LMETA,
          INC_KEY_LSUPER      = SDLK_LSUPER,
          INC_KEY_RSUPER      = SDLK_RSUPER,
          INC_KEY_MODE        = SDLK_MODE,
          INC_KEY_COMPOSE     = SDLK_COMPOSE,
          INC_KEY_HELP        = SDLK_HELP,
          INC_KEY_PRINT       = SDLK_PRINT,
          INC_KEY_SYSREQ      = SDLK_SYSREQ,
          INC_KEY_BREAK       = SDLK_BREAK,
          INC_KEY_MENU        = SDLK_MENU,
          INC_KEY_POWER       = SDLK_POWER,
          INC_KEY_EURO        = SDLK_EURO,
          INC_KEY_UNDO        = SDLK_UNDO,
          INC_KEY_LAST        = SDLK_LAST};


#endif //ENGINE_DEF_H
