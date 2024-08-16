<a id="readme-top"></a>

<div align="center">
    <h1>ANSI Escape Codes</h1>
    <p>A C/C++ utility for formatting output in a neat way.</p>
    <p>
        <a href="">
            <img src="https://img.shields.io/github/last-commit/cdanymar1/ANSI-Escape-Codes" alt="last commit">
        </a>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/network/members">
            <img src="https://img.shields.io/github/forks/cdanymar1/ANSI-Escape-Codes" alt="forks">
        </a>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codese/stargazers">
            <img src="https://img.shields.io/github/stars/cdanymar1/ANSI-Escape-Codes" alt="stars">
        </a>
        <br>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/issues/">
            <img src="https://img.shields.io/github/issues/cdanymar1/ANSI-Escape-Codes" alt="open issues">
        </a>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/blob/master/LICENSE">
            <img src="https://custom-icon-badges.demolab.com/badge/license-MIT-yellow?logo=law" alt="license">
        </a>
        <img src="https://custom-icon-badges.demolab.com/badge/ISO-23-blue?logo=cplusplus" alt="C++ ISO">
    </p>
    <h4>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/tree/master/example">Examples</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/tree/master/docs">Documentation</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/issues">Report Bug</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/issues">Request Feature</a>
    </h4>
</div>
<br>
<details>
    <summary>Table of Contents</summary>
    <ol>
        <li>
            <a href="#about">About</a>
        </li>
        <li>
            <a href="#getting-started">Getting Started</a>
        </li>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#license">License</a></li>
        <li><a href="#acknowledgments">Acknowledgments</a></li>
    </ol>
</details>

## About
This library provides a neat way for formatting text, manipulating caret and display using output streams and the ANSI escape sequences. Additionally, it includes functions for Unicode output in the standard output stream.

Alternatively it has macros that can be used similarly in both C and C++.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Getting Started
You can download this library as a single source file for C++ or a single header file with macros for C.

If you are using Windows Command Prompt as your default terminal application, you may use the scripts for enabling virtual terminal to have all the ANSI sequences executed.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Usage
To use this library in your project it must support C++23 features such as `std::vprint_unicode()` and the named standard library module `std`.

```c++
import ansi;

using namespace ansi::manipulators;
```

Import the library as a module, and it is recommended to have the using-namespace clause for the ease of use and readability.

```c++
ansi::println<fg::rgb(121, 32, 21), text::underline>("My red underlined text.");
```

It includes a function for standard output based on the C++26 syntax for `std::println`, but with additional support for styles passed as template arguments.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License
This library is under [MIT license](https://github.com/cdanymar1/ANSI-Escape-Codes/blob/master/LICENSE).
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Acknowledgments
The project in inspired by the [Wikipedia page](https://en.wikipedia.org/wiki/ANSI_escape_code) of the ANSI escape sequences.
<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
