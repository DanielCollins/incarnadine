//========================================================================
//
// Copyright (c) 2010 Daniel Collins, Daniel Flahive
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#ifndef ENGINE_KEYBINDS_H
#define ENGINE_KEYBINDS_H

#include "SDL_keysym.h"

// Generated with:
// awk '$1 ~ "SDLK_[a-zA-Z0-9]+" { printf "#define INC_KEY_%-16s%s\n", substr($1, 6, length($1)-1), $1 }' SDL_keysym.h

#define INC_KEY_UNKNOWN         SDLK_UNKNOWN
#define INC_KEY_FIRST           SDLK_FIRST
#define INC_KEY_BACKSPACE       SDLK_BACKSPACE
#define INC_KEY_TAB             SDLK_TAB
#define INC_KEY_CLEAR           SDLK_CLEAR
#define INC_KEY_RETURN          SDLK_RETURN
#define INC_KEY_PAUSE           SDLK_PAUSE
#define INC_KEY_ESCAPE          SDLK_ESCAPE
#define INC_KEY_SPACE           SDLK_SPACE
#define INC_KEY_EXCLAIM         SDLK_EXCLAIM
#define INC_KEY_QUOTEDBL        SDLK_QUOTEDBL
#define INC_KEY_HASH            SDLK_HASH
#define INC_KEY_DOLLAR          SDLK_DOLLAR
#define INC_KEY_AMPERSAND       SDLK_AMPERSAND
#define INC_KEY_QUOTE           SDLK_QUOTE
#define INC_KEY_LEFTPAREN       SDLK_LEFTPAREN
#define INC_KEY_RIGHTPAREN      SDLK_RIGHTPAREN
#define INC_KEY_ASTERISK        SDLK_ASTERISK
#define INC_KEY_PLUS            SDLK_PLUS
#define INC_KEY_COMMA           SDLK_COMMA
#define INC_KEY_MINUS           SDLK_MINUS
#define INC_KEY_PERIOD          SDLK_PERIOD
#define INC_KEY_SLASH           SDLK_SLASH
#define INC_KEY_0               SDLK_0
#define INC_KEY_1               SDLK_1
#define INC_KEY_2               SDLK_2
#define INC_KEY_3               SDLK_3
#define INC_KEY_4               SDLK_4
#define INC_KEY_5               SDLK_5
#define INC_KEY_6               SDLK_6
#define INC_KEY_7               SDLK_7
#define INC_KEY_8               SDLK_8
#define INC_KEY_9               SDLK_9
#define INC_KEY_COLON           SDLK_COLON
#define INC_KEY_SEMICOLON       SDLK_SEMICOLON
#define INC_KEY_LESS            SDLK_LESS
#define INC_KEY_EQUALS          SDLK_EQUALS
#define INC_KEY_GREATER         SDLK_GREATER
#define INC_KEY_QUESTION        SDLK_QUESTION
#define INC_KEY_AT              SDLK_AT
#define INC_KEY_LEFTBRACKET     SDLK_LEFTBRACKET
#define INC_KEY_BACKSLASH       SDLK_BACKSLASH
#define INC_KEY_RIGHTBRACKET    SDLK_RIGHTBRACKET
#define INC_KEY_CARET           SDLK_CARET
#define INC_KEY_UNDERSCORE      SDLK_UNDERSCORE
#define INC_KEY_BACKQUOTE       SDLK_BACKQUOTE
#define INC_KEY_a               SDLK_a
#define INC_KEY_b               SDLK_b
#define INC_KEY_c               SDLK_c
#define INC_KEY_d               SDLK_d
#define INC_KEY_e               SDLK_e
#define INC_KEY_f               SDLK_f
#define INC_KEY_g               SDLK_g
#define INC_KEY_h               SDLK_h
#define INC_KEY_i               SDLK_i
#define INC_KEY_j               SDLK_j
#define INC_KEY_k               SDLK_k
#define INC_KEY_l               SDLK_l
#define INC_KEY_m               SDLK_m
#define INC_KEY_n               SDLK_n
#define INC_KEY_o               SDLK_o
#define INC_KEY_p               SDLK_p
#define INC_KEY_q               SDLK_q
#define INC_KEY_r               SDLK_r
#define INC_KEY_s               SDLK_s
#define INC_KEY_t               SDLK_t
#define INC_KEY_u               SDLK_u
#define INC_KEY_v               SDLK_v
#define INC_KEY_w               SDLK_w
#define INC_KEY_x               SDLK_x
#define INC_KEY_y               SDLK_y
#define INC_KEY_z               SDLK_z
#define INC_KEY_DELETE          SDLK_DELETE
#define INC_KEY_WORLD_0         SDLK_WORLD_0
#define INC_KEY_WORLD_1         SDLK_WORLD_1
#define INC_KEY_WORLD_2         SDLK_WORLD_2
#define INC_KEY_WORLD_3         SDLK_WORLD_3
#define INC_KEY_WORLD_4         SDLK_WORLD_4
#define INC_KEY_WORLD_5         SDLK_WORLD_5
#define INC_KEY_WORLD_6         SDLK_WORLD_6
#define INC_KEY_WORLD_7         SDLK_WORLD_7
#define INC_KEY_WORLD_8         SDLK_WORLD_8
#define INC_KEY_WORLD_9         SDLK_WORLD_9
#define INC_KEY_WORLD_10        SDLK_WORLD_10
#define INC_KEY_WORLD_11        SDLK_WORLD_11
#define INC_KEY_WORLD_12        SDLK_WORLD_12
#define INC_KEY_WORLD_13        SDLK_WORLD_13
#define INC_KEY_WORLD_14        SDLK_WORLD_14
#define INC_KEY_WORLD_15        SDLK_WORLD_15
#define INC_KEY_WORLD_16        SDLK_WORLD_16
#define INC_KEY_WORLD_17        SDLK_WORLD_17
#define INC_KEY_WORLD_18        SDLK_WORLD_18
#define INC_KEY_WORLD_19        SDLK_WORLD_19
#define INC_KEY_WORLD_20        SDLK_WORLD_20
#define INC_KEY_WORLD_21        SDLK_WORLD_21
#define INC_KEY_WORLD_22        SDLK_WORLD_22
#define INC_KEY_WORLD_23        SDLK_WORLD_23
#define INC_KEY_WORLD_24        SDLK_WORLD_24
#define INC_KEY_WORLD_25        SDLK_WORLD_25
#define INC_KEY_WORLD_26        SDLK_WORLD_26
#define INC_KEY_WORLD_27        SDLK_WORLD_27
#define INC_KEY_WORLD_28        SDLK_WORLD_28
#define INC_KEY_WORLD_29        SDLK_WORLD_29
#define INC_KEY_WORLD_30        SDLK_WORLD_30
#define INC_KEY_WORLD_31        SDLK_WORLD_31
#define INC_KEY_WORLD_32        SDLK_WORLD_32
#define INC_KEY_WORLD_33        SDLK_WORLD_33
#define INC_KEY_WORLD_34        SDLK_WORLD_34
#define INC_KEY_WORLD_35        SDLK_WORLD_35
#define INC_KEY_WORLD_36        SDLK_WORLD_36
#define INC_KEY_WORLD_37        SDLK_WORLD_37
#define INC_KEY_WORLD_38        SDLK_WORLD_38
#define INC_KEY_WORLD_39        SDLK_WORLD_39
#define INC_KEY_WORLD_40        SDLK_WORLD_40
#define INC_KEY_WORLD_41        SDLK_WORLD_41
#define INC_KEY_WORLD_42        SDLK_WORLD_42
#define INC_KEY_WORLD_43        SDLK_WORLD_43
#define INC_KEY_WORLD_44        SDLK_WORLD_44
#define INC_KEY_WORLD_45        SDLK_WORLD_45
#define INC_KEY_WORLD_46        SDLK_WORLD_46
#define INC_KEY_WORLD_47        SDLK_WORLD_47
#define INC_KEY_WORLD_48        SDLK_WORLD_48
#define INC_KEY_WORLD_49        SDLK_WORLD_49
#define INC_KEY_WORLD_50        SDLK_WORLD_50
#define INC_KEY_WORLD_51        SDLK_WORLD_51
#define INC_KEY_WORLD_52        SDLK_WORLD_52
#define INC_KEY_WORLD_53        SDLK_WORLD_53
#define INC_KEY_WORLD_54        SDLK_WORLD_54
#define INC_KEY_WORLD_55        SDLK_WORLD_55
#define INC_KEY_WORLD_56        SDLK_WORLD_56
#define INC_KEY_WORLD_57        SDLK_WORLD_57
#define INC_KEY_WORLD_58        SDLK_WORLD_58
#define INC_KEY_WORLD_59        SDLK_WORLD_59
#define INC_KEY_WORLD_60        SDLK_WORLD_60
#define INC_KEY_WORLD_61        SDLK_WORLD_61
#define INC_KEY_WORLD_62        SDLK_WORLD_62
#define INC_KEY_WORLD_63        SDLK_WORLD_63
#define INC_KEY_WORLD_64        SDLK_WORLD_64
#define INC_KEY_WORLD_65        SDLK_WORLD_65
#define INC_KEY_WORLD_66        SDLK_WORLD_66
#define INC_KEY_WORLD_67        SDLK_WORLD_67
#define INC_KEY_WORLD_68        SDLK_WORLD_68
#define INC_KEY_WORLD_69        SDLK_WORLD_69
#define INC_KEY_WORLD_70        SDLK_WORLD_70
#define INC_KEY_WORLD_71        SDLK_WORLD_71
#define INC_KEY_WORLD_72        SDLK_WORLD_72
#define INC_KEY_WORLD_73        SDLK_WORLD_73
#define INC_KEY_WORLD_74        SDLK_WORLD_74
#define INC_KEY_WORLD_75        SDLK_WORLD_75
#define INC_KEY_WORLD_76        SDLK_WORLD_76
#define INC_KEY_WORLD_77        SDLK_WORLD_77
#define INC_KEY_WORLD_78        SDLK_WORLD_78
#define INC_KEY_WORLD_79        SDLK_WORLD_79
#define INC_KEY_WORLD_80        SDLK_WORLD_80
#define INC_KEY_WORLD_81        SDLK_WORLD_81
#define INC_KEY_WORLD_82        SDLK_WORLD_82
#define INC_KEY_WORLD_83        SDLK_WORLD_83
#define INC_KEY_WORLD_84        SDLK_WORLD_84
#define INC_KEY_WORLD_85        SDLK_WORLD_85
#define INC_KEY_WORLD_86        SDLK_WORLD_86
#define INC_KEY_WORLD_87        SDLK_WORLD_87
#define INC_KEY_WORLD_88        SDLK_WORLD_88
#define INC_KEY_WORLD_89        SDLK_WORLD_89
#define INC_KEY_WORLD_90        SDLK_WORLD_90
#define INC_KEY_WORLD_91        SDLK_WORLD_91
#define INC_KEY_WORLD_92        SDLK_WORLD_92
#define INC_KEY_WORLD_93        SDLK_WORLD_93
#define INC_KEY_WORLD_94        SDLK_WORLD_94
#define INC_KEY_WORLD_95        SDLK_WORLD_95
#define INC_KEY_KP0             SDLK_KP0
#define INC_KEY_KP1             SDLK_KP1
#define INC_KEY_KP2             SDLK_KP2
#define INC_KEY_KP3             SDLK_KP3
#define INC_KEY_KP4             SDLK_KP4
#define INC_KEY_KP5             SDLK_KP5
#define INC_KEY_KP6             SDLK_KP6
#define INC_KEY_KP7             SDLK_KP7
#define INC_KEY_KP8             SDLK_KP8
#define INC_KEY_KP9             SDLK_KP9
#define INC_KEY_KP_PERIOD       SDLK_KP_PERIOD
#define INC_KEY_KP_DIVIDE       SDLK_KP_DIVIDE
#define INC_KEY_KP_MULTIPLY     SDLK_KP_MULTIPLY
#define INC_KEY_KP_MINUS        SDLK_KP_MINUS
#define INC_KEY_KP_PLUS         SDLK_KP_PLUS
#define INC_KEY_KP_ENTER        SDLK_KP_ENTER
#define INC_KEY_KP_EQUALS       SDLK_KP_EQUALS
#define INC_KEY_UP              SDLK_UP
#define INC_KEY_DOWN            SDLK_DOWN
#define INC_KEY_RIGHT           SDLK_RIGHT
#define INC_KEY_LEFT            SDLK_LEFT
#define INC_KEY_INSERT          SDLK_INSERT
#define INC_KEY_HOME            SDLK_HOME
#define INC_KEY_END             SDLK_END
#define INC_KEY_PAGEUP          SDLK_PAGEUP
#define INC_KEY_PAGEDOWN        SDLK_PAGEDOWN
#define INC_KEY_F1              SDLK_F1
#define INC_KEY_F2              SDLK_F2
#define INC_KEY_F3              SDLK_F3
#define INC_KEY_F4              SDLK_F4
#define INC_KEY_F5              SDLK_F5
#define INC_KEY_F6              SDLK_F6
#define INC_KEY_F7              SDLK_F7
#define INC_KEY_F8              SDLK_F8
#define INC_KEY_F9              SDLK_F9
#define INC_KEY_F10             SDLK_F10
#define INC_KEY_F11             SDLK_F11
#define INC_KEY_F12             SDLK_F12
#define INC_KEY_F13             SDLK_F13
#define INC_KEY_F14             SDLK_F14
#define INC_KEY_F15             SDLK_F15
#define INC_KEY_NUMLOCK         SDLK_NUMLOCK
#define INC_KEY_CAPSLOCK        SDLK_CAPSLOCK
#define INC_KEY_SCROLLOCK       SDLK_SCROLLOCK
#define INC_KEY_RSHIFT          SDLK_RSHIFT
#define INC_KEY_LSHIFT          SDLK_LSHIFT
#define INC_KEY_RCTRL           SDLK_RCTRL
#define INC_KEY_LCTRL           SDLK_LCTRL
#define INC_KEY_RALT            SDLK_RALT
#define INC_KEY_LALT            SDLK_LALT
#define INC_KEY_RMETA           SDLK_RMETA
#define INC_KEY_LMETA           SDLK_LMETA
#define INC_KEY_LSUPER          SDLK_LSUPER
#define INC_KEY_RSUPER          SDLK_RSUPER
#define INC_KEY_MODE            SDLK_MODE
#define INC_KEY_COMPOSE         SDLK_COMPOSE
#define INC_KEY_HELP            SDLK_HELP
#define INC_KEY_PRINT           SDLK_PRINT
#define INC_KEY_SYSREQ          SDLK_SYSREQ
#define INC_KEY_BREAK           SDLK_BREAK
#define INC_KEY_MENU            SDLK_MENU
#define INC_KEY_POWER           SDLK_POWER
#define INC_KEY_EURO            SDLK_EURO
#define INC_KEY_UNDO            SDLK_UNDO
#define INC_KEY_LAST            SDLK_LAST


#endif //ENGINE_KEYBINDS_H
