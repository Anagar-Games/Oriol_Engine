// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_INIPARSER_HPP
#define OL_INIPARSER_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace OL
{
    class INIParser
    {
    public:
        INIParser(const std::string& filename_a);
        bool Load();
        bool Save() const;

        std::string GetValue(const std::string& section_a,
                             const std::string& key_a) const;

        void SetValue(const std::string& section_a,
                      const std::string& key_a,
                      const std::string& value_a);

        std::vector<std::string> GetSections() const;
        std::map<std::string, std::string> GetKeys(
                const std::string& section_a) const;

    private:
        void _Trim(std::string& str_a) const;

    private:
        std::string filename_;
        std::map<std::string, std::map<std::string, std::string>> data_;
    };
} // namespace OL
#endif
