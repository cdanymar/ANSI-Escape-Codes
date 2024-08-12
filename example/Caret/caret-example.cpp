#define EXAMPLE_CXX

#ifdef EXAMPLE_C

#include <stdio.h>

#define _ANSI_CSI
#include "ansi.h"

int main(void)
{
    printf("Hello, world!\n");
    printf(CUU(1) "!dlrow ,olleH\n");

    printf(CUP(15, 15) "* (15, 15)");

    return 0;
}

#elif defined(EXAMPLE_CPP)

#include <iostream>
#include <cansi>

using namespace ansi::manipulators;

int main()
{
    std::cout << "Hello, world!" << std::endl;
    std::cout << caret::up() << "!dlrow ,olleH" << std::endl;
}

#elif defined(EXAMPLE_CXX)

import std;
import ansi;

using namespace ansi::manipulators;

auto main() -> int
{
    ansi::println("Hello, world!");
    ansi::println<caret::up()>("!dlrow ,olleH");
}

#endif
