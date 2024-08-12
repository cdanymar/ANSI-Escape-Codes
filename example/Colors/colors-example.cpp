#define EXAMPLE_CXX

#ifdef EXAMPLE_C

#include <stdio.h>

#define _ANSI_SGR
#include "ansi.h"

int main(void)
{
    printf(FG_RED BG_WHITE "Red on white\n" RESET);
    printf(FG_BRIGHT_GREEN "Bright green\n" RESET);
    printf(BG_RGB(123, 42, 98) "RGB background\n" RESET);

    return 0;
}

#elif defined(EXAMPLE_CPP)

#include <iostream>
#include <cansi>

using namespace ansi::manipulators;

int main()
{
    std::cout << fg::red << bg::white << "Red on white" << reset << std::endl;
    std::cout << fg::bright::green << "Bright green" << reset << std::endl;
    std::cout << bg::rgb(123, 42, 98) << "RGB background" << reset << std::endl;
}

#elif defined(EXAMPLE_CXX)

import std;
import ansi;

using namespace ansi::manipulators;

auto main() -> int
{
    ansi::println<fg::red, bg::white>("Red on white");
    ansi::println<fg::bright::green>("Bright green");
    ansi::println<bg::rgb(123, 42, 98)>("RGB background");
}

#endif
