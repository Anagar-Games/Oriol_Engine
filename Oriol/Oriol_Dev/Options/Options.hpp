// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace Oriol_Dev
{
    class Options
    {
    public:
        Options(int argc_a, char* argv_a[]);

        void AddOption(const std::string& option_a,
                       const std::string& description_a);

        bool IsOptionSet(const std::string& option_a) const;
        std::string GetOptionValue(const std::string& option_a) const;
        void PrintHelp() const;

    private:
        std::map<std::string, std::string> options_;
        std::vector<std::string> args_;
    };
} // namespace Oriol_Dev
#endif
