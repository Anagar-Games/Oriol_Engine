#include "ConsoleColor.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <stdlib.h>
#endif

namespace Oriol_Dev
{
    void ConsoleColor::setRed()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#else
        std::cout << "\033[31m";
#endif
    }

    void ConsoleColor::setGreen()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
#else
        std::cout << "\033[32m";
#endif
    }

    void ConsoleColor::setYellow()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#else
        std::cout << "\033[33m";
#endif
    }

    void ConsoleColor::setBlue()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
#else
        std::cout << "\033[34m";
#endif
    }

    void ConsoleColor::reset()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
        std::cout << "\033[0m";
#endif
    }
} // namespace Oriol_Dev
