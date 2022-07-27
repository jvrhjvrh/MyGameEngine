#ifndef KEYS_H_
#define KEYS_H_

#define KEYS_SPACE 0
#define KEYS_APOSTROPHE 1 /* ' */
#define KEYS_COMMA 2      /* , */
#define KEYS_MINUS 3      /* - */
#define KEYS_PERIOD 4     /* . */
#define KEYS_SLASH 5      /* / */
#define KEYS_0 6
#define KEYS_1 7
#define KEYS_2 8
#define KEYS_3 9
#define KEYS_4 10
#define KEYS_5 11
#define KEYS_6 12
#define KEYS_7 13
#define KEYS_8 14
#define KEYS_9 15
#define KEYS_SEMICOLON 16 /* ; */
#define KEYS_EQUAL 17     /* = */
#define KEYS_A 18
#define KEYS_B 19
#define KEYS_C 20
#define KEYS_D 21
#define KEYS_E 22
#define KEYS_F 23
#define KEYS_G 24
#define KEYS_H 25
#define KEYS_I 26
#define KEYS_J 27
#define KEYS_K 28
#define KEYS_L 29
#define KEYS_M 30
#define KEYS_N 31
#define KEYS_O 32
#define KEYS_P 33
#define KEYS_Q 34
#define KEYS_R 35
#define KEYS_S 36
#define KEYS_T 37
#define KEYS_U 38
#define KEYS_V 39
#define KEYS_W 40
#define KEYS_X 41
#define KEYS_Y 42
#define KEYS_Z 43
#define KEYS_LEFT_BRACKET 44  /* [ */
#define KEYS_BACKSLASH 45     /* \ */
#define KEYS_RIGHT_BRACKET 46 /* ] */
#define KEYS_GRAVE_ACCENT 47  /* ` */
#define KEYS_WORLD_1 48       /* non-US #1 */
#define KEYS_WORLD_2 49       /* non-US #2 */
#define KEYS_ESCAPE 50
#define KEYS_ENTER 51
#define KEYS_TAB 52
#define KEYS_BACKSPACE 53
#define KEYS_INSERT 54
#define KEYS_DELETE 55
#define KEYS_RIGHT 56
#define KEYS_LEFT 57
#define KEYS_DOWN 58
#define KEYS_UP 59
#define KEYS_PAGE_UP 60
#define KEYS_PAGE_DOWN 61
#define KEYS_HOME 62
#define KEYS_END 63
#define KEYS_CAPS_LOCK 64
#define KEYS_SCROLL_LOCK 65
#define KEYS_NUM_LOCK 66
#define KEYS_PRINT_SCREEN 67
#define KEYS_PAUSE 68
#define KEYS_F1 69
#define KEYS_F2 70
#define KEYS_F3 71
#define KEYS_F4 72
#define KEYS_F5 73
#define KEYS_F6 74
#define KEYS_F7 75
#define KEYS_F8 76
#define KEYS_F9 77
#define KEYS_F10 78
#define KEYS_F11 79
#define KEYS_F12 80
#define KEYS_F13 81
#define KEYS_F14 82
#define KEYS_F15 83
#define KEYS_F16 84
#define KEYS_F17 85
#define KEYS_F18 86
#define KEYS_F19 87
#define KEYS_F20 88
#define KEYS_F21 89
#define KEYS_F22 90
#define KEYS_F23 91
#define KEYS_F24 92
#define KEYS_F25 93
#define KEYS_KP_0 94
#define KEYS_KP_1 95
#define KEYS_KP_2 96
#define KEYS_KP_3 97
#define KEYS_KP_4 98
#define KEYS_KP_5 99
#define KEYS_KP_6 100
#define KEYS_KP_7 101
#define KEYS_KP_8 102
#define KEYS_KP_9 103
#define KEYS_KP_DECIMAL 104
#define KEYS_KP_DIVIDE 105
#define KEYS_KP_MULTIPLY 106
#define KEYS_KP_SUBTRACT 107
#define KEYS_KP_ADD 108
#define KEYS_KP_ENTER 109
#define KEYS_KP_EQUAL 110
#define KEYS_LEFT_SHIFT 111
#define KEYS_LEFT_CONTROL 112
#define KEYS_LEFT_ALT 113
#define KEYS_LEFT_SUPER 114
#define KEYS_RIGHT_SHIFT 115
#define KEYS_RIGHT_CONTROL 116
#define KEYS_RIGHT_ALT 117
#define KEYS_RIGHT_SUPER 118
#define KEYS_MENU 119

#define KEYS_RELEASE 0
#define KEYS_PRESS 1
#define KEYS_HOLD 2
#define KEYS_NOTHING 3

namespace Keys {
int mapKey(int key);
}
#endif // KEYS_H_
