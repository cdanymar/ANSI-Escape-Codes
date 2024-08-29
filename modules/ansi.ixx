/// @file ansi.ixx
/// @author Danylo Marchenko (cdanymar)
/// @brief Modular wrapper for ANSI.
/// @version 1.0
/// @date 2024-08-29
/// @copyright Copyright (c) 2024
export module ansi;

export import <cansi>;

import std;

/// @brief ANSI Escape Codes.
export namespace ansi
{
    /// @brief Prints ANSI-styled unicode to an output stream with variadic format string.
    /// @tparam Manips ANSI CSI output manip, styles.
    /// @tparam Args   Variadic arguments to put in the string.
    /// @param[out] stream Output stream.
    /// @param[in]  fmt    Format string.
    /// @param[in]  args   Variadic format arguments.
    template <csi... Manips, typename... Args>
    auto print(std::ostream& stream, const std::string_view fmt, Args&&... args) -> void
    {
        if constexpr (sizeof...(Manips) > 0)
        {
            ((stream << Manips), ...);

            std::vprint_unicode(stream, fmt, std::make_format_args(args...));
            stream << reset;
        }
        else std::vprint_unicode(stream, fmt, std::make_format_args(args...));
    }

    /// @brief Prints ANSI-styled unicode to standard output stream with variadic format string.
    /// @tparam Manips ANSI CSI output manip, styles.
    /// @tparam Args   Variadic arguments to put in the string.
    /// @param[in] fmt  Format string.
    /// @param[in] args Variadic format arguments.
    template <csi... Manips, typename... Args>
    auto print(const std::string_view fmt, Args&&... args) -> void
    {
        ansi::print<Manips...>(std::cout, fmt, std::forward<Args>(args)...);
    }

    /// @brief Prints ANSI-styled unicode to an output stream with variadic format string; flushes the output stream and ends the line.
    /// @tparam Manips ANSI CSI output manip, styles.
    /// @tparam Args   Variadic arguments to put in the string.
    /// @param[out] stream Output stream.
    /// @param[in]  fmt    Format string.
    /// @param[in]  args   Variadic format arguments.
    template <csi... Manips, typename... Args>
    auto println(std::ostream& stream, const std::string_view fmt, Args&&... args) -> void
    {
        ansi::print<Manips...>(stream, fmt, std::forward<Args>(args)...);
        stream << std::endl;
    }

    /// @brief Prints ANSI-styled unicode to standard output stream with variadic format string; flushes the standard output stream and ends the line.
    /// @tparam Manips ANSI CSI output manip, styles.
    /// @tparam Args   Variadic arguments to put in the string.
    /// @param[in] fmt  Format string.
    /// @param[in] args Variadic format arguments.
    template <csi... Manips, typename... Args>
    auto println(const std::string_view fmt, Args&&... args) -> void
    {
        ansi::println<Manips...>(std::cout, fmt, std::forward<Args>(args)...);
    }

    /// @brief Flushes the output stream and ends the line.
    /// @param[out] stream Output steam.
    inline auto println(std::ostream& stream) -> void { stream << std::endl; }

    /// @brief Flushes the standard output stream and ends the lines.
    inline auto println() -> void { ansi::println(std::cout); }
}
