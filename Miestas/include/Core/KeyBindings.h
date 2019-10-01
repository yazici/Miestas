#ifndef KEY_BINDINGS_H
#define KEY_BINDINGS_H

// We could just use GLFW key codes, but this is a good idea if I were to ever extend/change application in the future. 
// The keycodes are the same as GLFW

#define MIESTAS_KEY_UNKNOWN            -1

#define MIESTAS_KEY_SPACE              32
#define MIESTAS_KEY_APOSTROPHE         39  /* ' */
#define MIESTAS_KEY_COMMA              44  /* , */
#define MIESTAS_KEY_MINUS              45  /* - */
#define MIESTAS_KEY_PERIOD             46  /* . */
#define MIESTAS_KEY_SLASH              47  /* / */
#define MIESTAS_KEY_0                  48
#define MIESTAS_KEY_1                  49
#define MIESTAS_KEY_2                  50
#define MIESTAS_KEY_3                  51
#define MIESTAS_KEY_4                  52
#define MIESTAS_KEY_5                  53
#define MIESTAS_KEY_6                  54
#define MIESTAS_KEY_7                  55
#define MIESTAS_KEY_8                  56
#define MIESTAS_KEY_9                  57
#define MIESTAS_KEY_SEMICOLON          59  /* ; */
#define MIESTAS_KEY_EQUAL              61  /* = */
#define MIESTAS_KEY_A                  65
#define MIESTAS_KEY_B                  66
#define MIESTAS_KEY_C                  67
#define MIESTAS_KEY_D                  68
#define MIESTAS_KEY_E                  69
#define MIESTAS_KEY_F                  70
#define MIESTAS_KEY_G                  71
#define MIESTAS_KEY_H                  72
#define MIESTAS_KEY_I                  73
#define MIESTAS_KEY_J                  74
#define MIESTAS_KEY_K                  75
#define MIESTAS_KEY_L                  76
#define MIESTAS_KEY_M                  77
#define MIESTAS_KEY_N                  78
#define MIESTAS_KEY_O                  79
#define MIESTAS_KEY_P                  80
#define MIESTAS_KEY_Q                  81
#define MIESTAS_KEY_R                  82
#define MIESTAS_KEY_S                  83
#define MIESTAS_KEY_T                  84
#define MIESTAS_KEY_U                  85
#define MIESTAS_KEY_V                  86
#define MIESTAS_KEY_W                  87
#define MIESTAS_KEY_X                  88
#define MIESTAS_KEY_Y                  89
#define MIESTAS_KEY_Z                  90
#define MIESTAS_KEY_LEFT_BRACKET       91  /* [ */
#define MIESTAS_KEY_BACKSLASH          92  /* \ */
#define MIESTAS_KEY_RIGHT_BRACKET      93  /* ] */
#define MIESTAS_KEY_GRAVE_ACCENT       96  /* ` */
#define MIESTAS_KEY_WORLD_1            161 /* non-US #1 */
#define MIESTAS_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define MIESTAS_KEY_ESCAPE             256
#define MIESTAS_KEY_ENTER              257
#define MIESTAS_KEY_TAB                258
#define MIESTAS_KEY_BACKSPACE          259
#define MIESTAS_KEY_INSERT             260
#define MIESTAS_KEY_DELETE             261
#define MIESTAS_KEY_RIGHT              262
#define MIESTAS_KEY_LEFT               263
#define MIESTAS_KEY_DOWN               264
#define MIESTAS_KEY_UP                 265
#define MIESTAS_KEY_PAGE_UP            266
#define MIESTAS_KEY_PAGE_DOWN          267
#define MIESTAS_KEY_HOME               268
#define MIESTAS_KEY_END                269
#define MIESTAS_KEY_CAPS_LOCK          280
#define MIESTAS_KEY_SCROLL_LOCK        281
#define MIESTAS_KEY_NUM_LOCK           282
#define MIESTAS_KEY_PRINT_SCREEN       283
#define MIESTAS_KEY_PAUSE              284
#define MIESTAS_KEY_F1                 290
#define MIESTAS_KEY_F2                 291
#define MIESTAS_KEY_F3                 292
#define MIESTAS_KEY_F4                 293
#define MIESTAS_KEY_F5                 294
#define MIESTAS_KEY_F6                 295
#define MIESTAS_KEY_F7                 296
#define MIESTAS_KEY_F8                 297
#define MIESTAS_KEY_F9                 298
#define MIESTAS_KEY_F10                299
#define MIESTAS_KEY_F11                300
#define MIESTAS_KEY_F12                301
#define MIESTAS_KEY_F13                302
#define MIESTAS_KEY_F14                303
#define MIESTAS_KEY_F15                304
#define MIESTAS_KEY_F16                305
#define MIESTAS_KEY_F17                306
#define MIESTAS_KEY_F18                307
#define MIESTAS_KEY_F19                308
#define MIESTAS_KEY_F20                309
#define MIESTAS_KEY_F21                310
#define MIESTAS_KEY_F22                311
#define MIESTAS_KEY_F23                312
#define MIESTAS_KEY_F24                313
#define MIESTAS_KEY_F25                314
#define MIESTAS_KEY_KP_0               320
#define MIESTAS_KEY_KP_1               321
#define MIESTAS_KEY_KP_2               322
#define MIESTAS_KEY_KP_3               323
#define MIESTAS_KEY_KP_4               324
#define MIESTAS_KEY_KP_5               325
#define MIESTAS_KEY_KP_6               326
#define MIESTAS_KEY_KP_7               327
#define MIESTAS_KEY_KP_8               328
#define MIESTAS_KEY_KP_9               329
#define MIESTAS_KEY_KP_DECIMAL         330
#define MIESTAS_KEY_KP_DIVIDE          331
#define MIESTAS_KEY_KP_MULTIPLY        332
#define MIESTAS_KEY_KP_SUBTRACT        333
#define MIESTAS_KEY_KP_ADD             334
#define MIESTAS_KEY_KP_ENTER           335
#define MIESTAS_KEY_KP_EQUAL           336
#define MIESTAS_KEY_LEFT_SHIFT         340
#define MIESTAS_KEY_LEFT_CONTROL       341
#define MIESTAS_KEY_LEFT_ALT           342
#define MIESTAS_KEY_LEFT_SUPER         343
#define MIESTAS_KEY_RIGHT_SHIFT        344
#define MIESTAS_KEY_RIGHT_CONTROL      345
#define MIESTAS_KEY_RIGHT_ALT          346
#define MIESTAS_KEY_RIGHT_SUPER        347
#define MIESTAS_KEY_MENU               348

#define MIESTAS_MOUSE_BUTTON_1         0
#define MIESTAS_MOUSE_BUTTON_2         1
#define MIESTAS_MOUSE_BUTTON_3         2
#define MIESTAS_MOUSE_BUTTON_4         3
#define MIESTAS_MOUSE_BUTTON_5         4
#define MIESTAS_MOUSE_BUTTON_6         5
#define MIESTAS_MOUSE_BUTTON_7         6
#define MIESTAS_MOUSE_BUTTON_8         7
#define MIESTAS_MOUSE_BUTTON_LAST      MIESTAS_MOUSE_BUTTON_8
#define MIESTAS_MOUSE_BUTTON_LEFT      MIESTAS_MOUSE_BUTTON_1
#define MIESTAS_MOUSE_BUTTON_RIGHT     MIESTAS_MOUSE_BUTTON_2
#define MIESTAS_MOUSE_BUTTON_MIDDLE    MIESTAS_MOUSE_BUTTON_3


#endif