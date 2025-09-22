// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_INFOSYS_HPP
#define OL_INFOSYS_HPP

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <array>
#include <memory>

namespace OL
{
    class InfoSys
    {
    public:
        static std::string GetOSName();
        static std::string GetOSVersion();
        static std::string GetCPUInfo();
        static std::string GetMemoryInfo();
        static std::string GetDiskInfo();

    private:
#if defined(_WIN32) || defined(_WIN64)
        static std::string _ExecCommand(const std::string& command_a);
#else
        static std::string _ExecCommand(const char* command_a);
#endif
    };
} // namespace OL
#endif
