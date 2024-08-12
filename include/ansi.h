/// @file ansi.h
/// @author Danylo Marchenko (cdanymar)
/// @brief Provides a set of macros for ANSI escape sequences, commonly used for terminal text formatting and cursor control. Offers definitions for caret movement, screen clearing, color manipulation, and text attributes.
/// @version 1.0
/// @date 2024-08-11
/// @copyright Copyright (c) 2024
#pragma once

/// @brief ANSI sequence starter, escape character.
#define ESC "\x1b["

#if !defined(_ANSI_CSI) && !defined(_ANSI_SGR)
/// @brief Enable ANSI Control Sequence Introducer sequences.
#define _ANSI_CSI

/// @brief Enable ANSI Select Graphic Rendition parameters.
#define _ANSI_SGR
#endif

#ifdef _ANSI_CSI

/// @brief Caret Up.
/// @details Moves caret @c n cells up. If caret is already at the edge of the screen, this has no effect.
/// @param n Number of lines to go up.
#define CUU(n) ESC #n "A"

/// @brief Caret Down.
/// @details Moves caret @c n cells down. If caret is already at the edge of the screen, this has no effect.
/// @param n Number of lines to go down.
#define CUD(n) ESC #n "B"

/// @brief Caret Forward.
/// @details Moves caret @c n cells forward. If caret is already at the edge of the screen, this has no effect.
/// @param n Number of lines to go forward.
#define CUF(n) ESC #n "C"

/// @brief Caret Back.
/// @details Moves caret @c n cells down. If caret is already at the edge of the screen, this has no effect.
/// @param n Number of lines to go down.
#define CUB(n) ESC #n "D"


/// @brief Caret Next Line.
/// @details Moves caret to beginning of the line @c n lines down.
/// @warning Not ANSI.SYS.
/// @param n Number of lines to go down.
#define CNL(n) ESC #n "E"

/// @brief Caret Previous Line.
/// @details Moves caret to beginning of the line @c n lines up.
/// @warning Not ANSI.SYS.
/// @param n Number of lines to go up.
#define CPL(n) ESC #n "F"


/// @brief Caret Horizontal Absolute.
/// @details Moves caret to column @c n .
/// @warning Not ANSI.SYS.
/// @param n Column number.
#define CHA(n) ESC #n "G"

/// @brief Caret Position.
/// @details Moves caret to row @c n, column @c m . The values are 1-based, and default to 1 (top left corner) if omitted.
/// @param n Row number.
/// @param m Column number.
#define CUP(n, m) ESC #n ";" #m "H"

/// @brief Horizontal Vertical Position.
/// @copydetails CUP
/// @param n Row number.
/// @param m Column number.
#define HVP(n, m) ESC #n ";" #m "f"


/// @brief Erase in Display.
/// @details Clears part of the screen.
/// @param n If 0 (or missing), clears from caret to end of screen. @n If 1, clears from caret to beginning of the screen. @n If 2, clears entire screen. @n If 3, clears entire screen and deletes all lines saved in the scrollback buffer.
#define ED(n) ESC #n "J"

/// @brief Erase in Line.
/// @details Clears part of the line without changing caret position.
/// @param n If 0 (or missing), clear from caret to the end of the line. @n If 1, clear from caret to beginning of the line. @n If 2, clear entire line. entire screen and delete all lines saved in the scrollback buffer.
#define EL(n) ESC #n "K"


/// @brief Scroll Up.
/// @details Scroll whole page up by @c n lines. New lines are added at the bottom.
/// @warning Not ANSI.SYS.
/// @param n Number of lines.
#define SU(n) ESC #n "S"

/// @brief Scroll Down.
/// @details Scroll whole page down by @c n lines. New lines are added at the top.
/// @warning Not ANSI.SYS.
/// @param n Number of lines.
#define SD(n) ESC #n "T"


/// @brief Device Status Report.
/// @details Reports caret position (CPR) by transmitting @code ESC[n;mR@endcode, where @c n is the row and @c m is the column.
#define DSR ESC "6n"

/// @brief Save Caret Position.
/// @details Saves caret position/state in SCO console mode.
#define SCP ESC "s"

/// @brief Restore Caret Position.
/// @details Restores caret position/state in SCO console mode.
#define RCP ESC "u"

#endif


/// @brief Select Graphics Rendition.
/// @details Sets colors and style of the characters following this code.
/// @param n Code.
#define SGR(n) ESC #n "m"


#ifdef _ANSI_SGR

/// @brief Reset or normal.
/// @details All attributes become turned off.
#define RESET SGR(0)

/// @brief Bold or increased intensity.
/// @details As with faint, the color change is a PC (SCO/CGA) invention.
#define BOLD SGR(1)

/// @brief Faint, decreased intensity, or dim.
/// @details May be implemented as a light font weight like bold.
#define FAINT SGR(2)

/// @brief Italic.
#define ITALIC SGR(3)

/// @brief Underline.
#define UNDERLINE SGR(4)

/// @brief Slow blink.
/// @details Sets blinking to less than 150 times per minute.
#define BLINK SGR(5)

/// @brief Rapid blink.
/// @details 150+ per minute.
/// @warning Not widely supported.
#define RAPID_BLINK SGR(6)

/// @brief Reverse video or invert.
/// @details Swap foreground and background colors.
/// @warning Inconsistent emulation.
#define INVERT SGR(7)

/// @brief Conceal or hide.
/// @warning Not widely supported.
#define HIDE SGR(8)

/// @brief Crossed-out or strike.
/// @details Characters legible but marked as if for deletion.
#define STRIKE SGR(9)

/// @brief Doubly underlined or not bold.
/// @details Double-underline per ECMA-48, but instead disables bold intensity on several terminals, including in the Linux kernel's console before version 4.17.
#define DOUBLE_UNDERLINE SGR(21)

/// @brief Overlined.
/// @warning Not widely supported.
#define OVERLINE SGR(53)


/// @brief Normal intensity.
/// @details Neither bold nor faint; color changes where intensity is implemented as such.
#define NORMAL SGR(22)

/// @brief Neither italic, nor blackletter.#define UN_ITALIC SGR(23)

/// @brief Not underlined.
/// @details Neither singly nor doubly underlined.
#define UN_UNDERLINE SGR(24)

/// @brief Not blinking.
#define UN_BLINK SGR(25)

/// @brief Not reversed.
#define UN_INVERT SGR(27)

/// @copybrief UN_INVERT
#define REVERT SGR(27)

/// @brief Not concealed.
#define UN_HIDE SGR(28)

/// @copybrief UN_HIDE
#define REVEAL SGR(28)

/// @brief Not crossed out.
#define UN_STRIKE SGR(29)

/// @brief Overlined.
/// @warning Not widely supported.
#define UN_OVERLINE SGR(55)


#pragma region Colors

/// @brief Sets foreground to black.
#define FG_BLACK SGR(30)

/// @brief Sets foreground to red.
#define FG_RED SGR(31)

/// @brief Sets foreground to green.
#define FG_GREEN SGR(32)

/// @brief Sets foreground to yellow.
#define FG_YELLOW SGR(33)

/// @brief Sets foreground to blue.
#define FG_BLUE SGR(34)

/// @brief Sets foreground to magenta.
#define FG_MAGENTA SGR(35)

/// @brief Sets foreground to cyan.
#define FG_CYAN SGR(36)

/// @brief Sets foreground to white.
#define FG_WHITE SGR(37)

/// @brief Sets foreground to gray.
#define FG_GRAY SGR(90)


/// @brief Sets foreground to bright black.
#define FG_BRIGHT_BLACK SGR(90)

/// @brief Sets foreground to bright red.
#define FG_BRIGHT_RED SGR(91)

/// @brief Sets foreground to bright green.
#define FG_BRIGHT_GREEN SGR(92)

/// @brief Sets foreground to bright yellow.
#define FG_BRIGHT_YELLOW SGR(93)

/// @brief Sets foreground to bright blue.
#define FG_BRIGHT_BLUE SGR(94)

/// @brief Sets foreground to bright magenta.
#define FG_BRIGHT_MAGENTA SGR(95)

/// @brief Sets foreground to bright cyan.
#define FG_BRIGHT_CYAN SGR(96)

/// @brief Sets foreground to bright white.
#define FG_BRIGHT_WHITE SGR(97)


/// @brief Sets background to black.
#define BG_BLACK SGR(40)

/// @brief Sets background to red.
#define BG_RED SGR(41)

/// @brief Sets background to green.
#define BG_GREEN SGR(42)

/// @brief Sets background to yellow.
#define BG_YELLOW SGR(43)

/// @brief Sets background to blue.
#define BG_BLUE SGR(44)

/// @brief Sets background to magenta.
#define BG_MAGENTA SGR(45)

/// @brief Sets background to cyan.
#define BG_CYAN SGR(46)

/// @brief Sets background to white.
#define BG_WHITE SGR(47)

/// @brief Sets background to gray.
#define BG_GRAY SGR(100)


/// @brief Sets background to bright black.
#define BG_BRIGHT_BLACK SGR(100)

/// @brief Sets background to bright red.
#define BG_BRIGHT_RED SGR(101)

/// @brief Sets background to bright green.
#define BG_BRIGHT_GREEN SGR(102)

/// @brief Sets background to bright yellow.
#define BG_BRIGHT_YELLOW SGR(103)

/// @brief Sets background to bright blue.
#define BG_BRIGHT_BLUE SGR(104)

/// @brief Sets background to bright magenta.
#define BG_BRIGHT_MAGENTA SGR(105)

/// @brief Sets background to bright cyan.
#define BG_BRIGHT_CYAN SGR(106)

/// @brief Sets background to bright white.
#define BG_BRIGHT_WHITE SGR(107)


/// @brief Sets foreground color.
/// @param n 8-bit color.
#define FG_SET(n) ESC "38;5;" #n "m"

/// @brief Sets foreground color.
/// @param r Red channel.
/// @param g Green channel.
/// @param b Blue channel.
#define FG_RGB(r, g, b) ESC "38;2;" #r ";" #g ";" #b "m"


/// @brief Sets background color.
/// @param n 8-bit color.
#define BG_SET(n) ESC "48;5;" #n "m"

/// @brief Sets background color.
/// @param r Red channel.
/// @param g Green channel.
/// @param b Blue channel.
#define BG_RGB(r, g, b) ESC "48;2;" #r ";" #g ";" #b "m"


/// @brief Sets underline color.
/// @warning Not widely supported.
/// @param n 8-bit color.
#define UNDERLINE_SET(n) ESC "58;5;" #n "m"

/// @brief Sets underline color.
/// @warning Not widely supported.
/// @param r Red channel.
/// @param g Green channel.
/// @param b Blue channel.
#define UNDERLINE_RGB(r, g, b) ESC "58;2;" #r ";" #g ";" #b "m"

#pragma endregion

#endif
