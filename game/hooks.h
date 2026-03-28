#ifndef HOOKS_H
# define HOOKS_H
# ifdef __APPLE__
#  include <Tk/X11/X.h>
#  include <Carbon/Carbon.h>
#  define LEFT_ARROW kVK_LeftArrow
#  define RIGHT_ARROW kVK_RightArrow
#  define ANSI_W kVK_ANSI_W
#  define ANSI_S kVK_ANSI_S
#  define ANSI_A kVK_ANSI_A
#  define ANSI_D kVK_ANSI_D
#  define ANSI_P kVK_ANSI_P
#  define ANSI_E kVK_ANSI_E
#  define ESCAPE kVK_Escape
# else
#  include <X11/keysym.h>
#  include <X11/X.h>
#  define LEFT_ARROW XK_Left
#  define RIGHT_ARROW XK_Right
#  define ANSI_W XK_w
#  define ANSI_S XK_s
#  define ANSI_A XK_a
#  define ANSI_D XK_d
#  define ANSI_P XK_p
#  define ANSI_E XK_e
#  define ESCAPE XK_Escape
# endif

#endif