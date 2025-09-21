#include "ConsoleColor.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <stdlib.h>
#endif

namespace Oriol_Dev
{
    void ConsoleColor::SetRed()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#else
        std::cout << "\033[31m";
#endif
    }

    void ConsoleColor::SetGreen()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
#else
        std::cout << "\033[32m";
#endif
    }

    void ConsoleColor::SetYellow()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#else
        std::cout << "\033[33m";
#endif
    }

    void ConsoleColor::SetBlue()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
#else
        std::cout << "\033[34m";
#endif
    }

    void ConsoleColor::Reset()
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
        std::cout << "\033[0m";
#endif
    }
} // namespace Oriol_Dev