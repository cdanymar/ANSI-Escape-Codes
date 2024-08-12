#define EXAMPLE_CXX

#ifdef EXAMPLE_C

#include <stdio.h>

#define _ANSI_SGR
#include "ansi.h"

int main(void)
{
    printf(BOLD ITALIC UNDERLINE BLINK "Hello, world! Nice to see you!\n" RESET);
    return 0;
}

#elif defined(EXAMPLE_CPP)

#include <iostream>
#include <cansi>

using namespace ansi::manipulators::text;

int main()
{
    std::cout << bold << italic << underline << blink << "Hello, world! Nice to see you!" << std::endl;
}

#elif defined(EXAMPLE_CXX)

import std;
import ansi;

using namespace ansi::manipulators::text;

auto main() -> int
{
    ansi::println<bold, italic, underline, blink>("Hello, world! Nice to see you!");
}

#endif
