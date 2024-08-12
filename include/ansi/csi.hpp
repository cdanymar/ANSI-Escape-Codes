/// @file csi.h
/// @author Danylo Marchenko (cdanymar)
/// @brief Defines a set of structs and functions for ANSI escape sequences.
/// @version 1.0
/// @date 2024-08-11
/// @copyright Copyright (c) 2024
#pragma once

#include <ostream>

/// @brief ANSI Escape Codes.
namespace ansi
{
    /// @brief Type alias for the smallest unsigned integer.
    using byte = std::uint8_t;

    /// @brief Control Sequence Introducer.
    /// @details Stores information for creating textual ANSI escape code for output manipulations.
    /// @tparam N Number of values.
    template <std::size_t N>
    struct csi
    {
        /// @brief CSI values.
        /// @see ansi::byte
        byte value[N];

        /// @brief CSI delimiter.
        char delim;
    };

    /// @brief CSI for a valueless sequence.
    template <>
    struct csi<0>
    {
        /// @brief CSI delimiter.
        char delim;
    };


    /// @brief Select Graphics Rendition alias for single-valued CSI.
    /// @see ansi::csi
    using sgr = csi<1>;

    /// @brief Select Graphics Rendition with an 8-bit color alias for three-valued CSI.
    /// @see ansi::csi
    using col = csi<3>;

    /// @brief Select Graphics Rendition with an RGB 24-bit color alias for five-valued CSI.
    /// @see ansi::csi
    using rgb = csi<5>;


    /// @brief Creates textual ANSI escape code from a CSI object for an output stream.
    /// @tparam N Number of values.
    /// @param[out] os  Output stream.
    /// @param[in]  obj CSI object,
    /// @return The modified output steam reference.
    /// @see ansi::csi
    template <std::size_t N>
    constexpr auto operator<<(std::ostream& os, const csi<N>& obj) -> std::ostream&
    {
        os << "\x1b[";

        if constexpr (N > 0)
            os << static_cast<unsigned>(obj.value[0]);

        if constexpr (N > 1)
            for (std::size_t i = 1; i < N; i++)
                os << ';' << static_cast<unsigned>(obj.value[i]);

        return os << obj.delim;
    }
}
