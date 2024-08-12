/// @file manip.ixx
/// @author Danylo Marchenko (cdanymar)
/// @brief Introduces compile-time constants with ready for use ANSI output manipulators.
/// @version 1.0
/// @date 2024-08-11
/// @copyright Copyright (c) 2024
#pragma once

#include "csi.hpp"

/// @brief ANSI Escape Codes.
namespace ansi
{
    /// @brief ANSI Escape Codes output manipulators.
    inline namespace manipulators
    {
        /// @brief Reset or normal.
        /// @details All attributes become turned off.
        constexpr inline sgr reset{{}, 'm'};

        /// @brief Caret manipulations.
        namespace caret
        {
            /// @brief Caret up.
            /// @details Moves caret up. If caret is already at the edge of the screen, this has no effect.
            /// @param[in] lines Number of lines to go up.
            /// @return CSI representing the <i>caret up</i> action.
            constexpr auto up(const byte lines = 1) -> csi<1> { return {{lines}, 'A'}; }

            /// @brief Caret down.
            /// @details Moves caret down. If caret is already at the edge of the screen, this has no effect.
            /// @param[in] lines Number of lines to go down.
            /// @return CSI representing the <i>caret down</i> action.
            constexpr auto down(const byte lines = 1) -> csi<1> { return {{lines}, 'B'}; }

            /// @brief Caret forward.
            /// @details Moves caret forward. If caret is already at the edge of the screen, this has no effect.
            /// @param[in] lines Number of lines to forward.
            /// @return CSI representing the <i>caret forward</i> action.
            constexpr auto forward(const byte lines = 1) -> csi<1> { return {{lines}, 'C'}; }

            /// @brief Caret back.
            /// @details Moves caret back. If caret is already at the edge of the screen, this has no effect.
            /// @param[in] lines Number of lines to go back.
            /// @return CSI representing the <i>caret back</i> action.
            constexpr auto back(const byte lines = 1) -> csi<1> { return {{lines}, 'D'}; }

            /// @brief Caret vertical position.
            /// @details Moves caret to specific column.
            /// @param[in] column Column number.
            /// @return CSI representing the <i>caret vertical movement</i> action.
            constexpr auto move(const byte column) -> csi<1> { return {{column}, 'G'}; }

            /// @brief Caret position.
            /// @details Moves caret to specific cell.
            /// @param[in] row    Row number.
            /// @param[in] column Column number.
            /// @return CSI representing the <i>caret movement</i> action.
            constexpr auto move(const byte row, const byte column) -> csi<2> { return {{row, column}, 'H'}; }

            /// @brief Caret position.
            /// @details Moves caret the origin.
            /// @return CSI representing the <i>caret movement</i> action.
            /// @see ansi::manip::move()
            consteval auto home() -> csi<0> { return {'H'}; }
        }

        /// @brief Line movement.
        namespace line
        {
            /// @brief Moves caret to the beginning of the next line.
            /// @param[in] lines Number of lines to go down.
            /// @return CSI representing the <i>next line</i> action.
            constexpr auto next(const byte lines = 1) -> csi<1> { return {{lines}, 'E'}; }

            /// @brief Moves caret to the beginning of the previous line.
            /// @param[in] lines Number of lines to go up.
            /// @return CSI representing the <i>previous line</i> action.
            constexpr auto prev(const byte lines = 1) -> csi<1> { return {{lines}, 'F'}; }
        }

        /// @brief Erase functions.
        namespace erase
        {
            /// @brief Erase mode specializations.
            /// @see ansi::byte
            enum erase_mode final : byte
            {
                from_caret, ///< Erase from caret to the end.
                to_caret, ///< Erase from the beginning to caret.
                whole, ///< Erase wholely.

                /// @brief Erase wholely and clear scrollback buffer.
                /// @warning Works only with @c erase::all() .
                /// @warning May not clear the terminal.
                scrollback
            };


            /// @brief Erases in display.
            /// @param[in] how Erase mode.
            /// @return CSI representing the <i>erase all</i> action.
            /// @enum ansi::manipulators::erase::erase_mode
            constexpr auto all(const erase_mode how = whole) -> csi<1> { return {how, 'J'}; }

            /// @brief Erases in line.
            /// @param[in] how Erase mode.
            /// @return CSI representing the <i>erase in line</i> action.
            /// @enum ansi::manipulators::erase::erase_mode
            constexpr auto line(const erase_mode how = whole) -> csi<1> { return {how, 'K'}; }
        }

        /// @brief Scroll functions.
        namespace scroll
        {
            /// @brief Scrolls page up.
            /// @param[in] lines Number of lines to scroll up by.
            /// @return CSI representing the <i>scroll up</i> action.
            constexpr auto up(const byte lines = 1) -> csi<1> { return {{lines}, 'S'}; }

            /// @brief Scrolls page down.
            /// @param[in] lines Number of lines to scroll down by.
            /// @return CSI representing the <i>scroll down</i> action.
            constexpr auto down(const byte lines = 1) -> csi<1> { return {{lines}, 'T'}; }
        }

        /// @brief Text styles.
        namespace text
        {
            /// @brief Makes text bold or increased intensity.
            constexpr inline sgr bold{{1}, 'm'};

            /// @brief Makes text faint or decreased intensity, dim.
            constexpr inline sgr faint{{2}, 'm'};

            /// @brief Makes text italic.
            constexpr inline sgr italic{{3}, 'm'};

            /// @brief Makes text underlined.
            constexpr inline sgr underline{{4}, 'm'};

            /// @brief Makes text doubly underlined.
            constexpr inline sgr double_underline{{21}, 'm'};

            /// @brief Makes text blink 150 times a minute.
            constexpr inline sgr blink{{5}, 'm'};

            /// @brief Makes text blink more than 150 times a minute.
            /// @warning Not widely supported.
            constexpr inline sgr blink_fast{{6}, 'm'};

            /// @brief Swaps foreground and background colors.
            constexpr inline sgr invert{{7}, 'm'};

            /// @brief Swaps foreground and background colors back.
            constexpr inline sgr revert{{27}, 'm'};

            /// @brief Makes text invisible.
            constexpr inline sgr conceal{{8}, 'm'};

            /// @brief Makes text visible.
            constexpr inline sgr reveal{{28}, 'm'};

            /// @brief Makes text strikethrough.
            constexpr inline sgr strike{{9}, 'm'};

            /// @brief Makes text overlined.
            constexpr inline sgr overline{{53}, 'm'};

            /// @brief Undoing text styles.
            namespace un
            {
                /// @brief Undoes the bold text.
                constexpr inline sgr bold{{22}, 'm'};

                /// @brief Undoes the faint text.
                constexpr inline sgr faint{{22}, 'm'};

                /// @brief Undoes the italic text.
                constexpr inline sgr italic{{23}, 'm'};

                /// @brief Undoes the underlined text.
                constexpr inline sgr underline{{24}, 'm'};

                /// @brief Stops text from blinking.
                constexpr inline sgr blink{{25}, 'm'};

                /// @brief Undoes the swapped colors.
                constexpr inline sgr invert{{27}, 'm'};

                /// @brief Undoes the hidden text.
                constexpr inline sgr conceal{{28}, 'm'};

                /// @brief Undoes the strikethrough text.
                constexpr inline sgr strike{{29}, 'm'};

                /// @brief Undoes the overlined text.
                constexpr inline sgr overline{{55}, 'm'};
            }
        }

        /// @brief Foreground color.
        namespace fg
        {
            /// @brief Restores default color.
            constexpr inline sgr regular{{39}, 'm'};

            /// @brief Makes the color black.
            constexpr inline sgr black{{30}, 'm'};

            /// @brief Makes the color red.
            constexpr inline sgr red{{31}, 'm'};

            /// @brief Makes the color green.
            constexpr inline sgr green{{32}, 'm'};

            /// @brief Makes the color yellow.
            constexpr inline sgr yellow{{33}, 'm'};

            /// @brief Makes the color indigo.
            constexpr inline sgr indigo{{34}, 'm'};

            /// @brief Makes the color magenta.
            constexpr inline sgr magenta{{35}, 'm'};

            /// @brief Makes the color cyan.
            constexpr inline sgr cyan{{36}, 'm'};

            /// @brief Makes the color white.
            constexpr inline sgr white{{37}, 'm'};

            /// @brief Makes the color gray.
            constexpr inline sgr gray{{90}, 'm'};


            /// @brief Sets a custom 8-bit color.
            /// @param[in] color Color code.
            /// @return SGR representing the 8-bit color.
            constexpr auto set(const byte color) -> col { return {{38, 5, color}, 'm'}; }

            /// @brief Sets a custom RGB color.
            /// @param[in] r Red byte channel.
            /// @param[in] g Green byte channel.
            /// @param[in] b Blue byte channel.
            /// @return SGR representing the RGB color.
            constexpr auto rgb(const byte r, const byte g, const byte b) -> rgb { return {{38, 2, r, g, b}, 'm'}; }

            /// @brief Bright versions of the colors.
            namespace bright
            {
                /// @brief Makes the color bright black.
                constexpr inline sgr black{{90}, 'm'};

                /// @brief Makes the color bright red.
                constexpr inline sgr red{{91}, 'm'};

                /// @brief Makes the color bright green.
                constexpr inline sgr green{{92}, 'm'};

                /// @brief Makes the color bright yellow.
                constexpr inline sgr yellow{{93}, 'm'};

                /// @brief Makes the color bright indigo.
                constexpr inline sgr indigo{{94}, 'm'};

                /// @brief Makes the color bright magenta.
                constexpr inline sgr magenta{{95}, 'm'};

                /// @brief Makes the color bright cyan.
                constexpr inline sgr cyan{{96}, 'm'};

                /// @brief Makes the color bright white.
                constexpr inline sgr white{{97}, 'm'};
            }
        }

        /// @brief Background color.
        namespace bg
        {
            /// @brief Restores default color.
            constexpr inline sgr regular{{49}, 'm'};

            /// @brief Makes the color black.
            constexpr inline sgr black{{40}, 'm'};

            /// @brief Makes the color red.
            constexpr inline sgr red{{41}, 'm'};

            /// @brief Makes the color green.
            constexpr inline sgr green{{42}, 'm'};

            /// @brief Makes the color yellow.
            constexpr inline sgr yellow{{43}, 'm'};

            /// @brief Makes the color indigo.
            constexpr inline sgr indigo{{44}, 'm'};

            /// @brief Makes the color magenta.
            constexpr inline sgr magenta{{45}, 'm'};

            /// @brief Makes the color cyan.
            constexpr inline sgr cyan{{46}, 'm'};

            /// @brief Makes the color white.
            constexpr inline sgr white{{47}, 'm'};

            /// @brief Makes the color gray.
            constexpr inline sgr gray{{100}, 'm'};


            /// @brief Sets a custom 8-bit color.
            /// @param[in] color Color code.
            /// @return SGR representing the 8-bit color.
            constexpr auto set(const byte color) -> col { return {{48, 5, color}, 'm'}; }

            /// @brief Sets a custom RGB color.
            /// @param[in] r Red byte channel.
            /// @param[in] g Green byte channel.
            /// @param[in] b Blue byte channel.
            /// @return SGR representing the RGB color.
            constexpr auto rgb(const byte r, const byte g, const byte b) -> rgb { return {{48, 2, r, g, b}, 'm'}; }

            /// @brief Bright versions of the colors.
            namespace bright
            {
                /// @brief Makes the color bright black.
                constexpr inline sgr black{{100}, 'm'};

                /// @brief Makes the color bright red.
                constexpr inline sgr red{{101}, 'm'};

                /// @brief Makes the color bright green.
                constexpr inline sgr green{{102}, 'm'};

                /// @brief Makes the color bright yellow.
                constexpr inline sgr yellow{{103}, 'm'};

                /// @brief Makes the color bright indigo.
                constexpr inline sgr indigo{{104}, 'm'};

                /// @brief Makes the color bright magenta.
                constexpr inline sgr magenta{{105}, 'm'};

                /// @brief Makes the color bright cyan.
                constexpr inline sgr cyan{{106}, 'm'};

                /// @brief Makes the color bright white.
                constexpr inline sgr white{{107}, 'm'};
            }
        }

        /// @brief Underline color.
        namespace underline
        {
            /// @brief Restores default color.
            constexpr inline sgr regular{{59}, 'm'};


            /// @brief Sets a custom 8-bit color.
            /// @param[in] color Color code.
            /// @return SGR representing the 8-bit color.
            constexpr auto set(const byte color) -> col { return {{58, 5, color}, 'm'}; }

            /// @brief Sets a custom RGB color.
            /// @param[in] red   Red byte channel.
            /// @param[in] green Green byte channel.
            /// @param[in] blue  Blue byte channel.
            /// @return SGR representing the RGB color.
            constexpr auto rgb(const byte red, const byte green, const byte blue) -> rgb { return {{58, 2, red, green, blue}, 'm'}; }
        }
    }
}
