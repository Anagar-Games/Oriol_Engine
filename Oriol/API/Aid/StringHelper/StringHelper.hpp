// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_STRINGHELPER_HPP
#define OL_STRINGHELPER_HPP

#include <algorithm>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace OL
{
    class StringHelper
    {
    public:
        StringHelper() = default;
        StringHelper(const std::string& str_a);
        StringHelper(const char* str_a);

        std::string ToLowerCase() const;
        std::string ToUpperCase() const;
        std::string Trim() const;

        std::vector<std::string> Split(char delimiter_a) const;
        bool Contains(const std::string& substr_a) const;
        bool StartsWith(const std::string& prefix_a) const;
        bool EndsWith(const std::string& suffix_a) const;

        std::string Replace(const std::string& old_str_a,
                            const std::string& new_str_a) const;

        int IndexOf(const std::string& substr_a) const;
        int LastIndexOf(const std::string& substr_a) const;

        std::string Substring(size_t start_a,
                              size_t length_a = std::string::npos) const;

        bool IsEmpty() const;
        size_t Length() const;
        std::string ExtractNumericPart() const;

        StringHelper& operator=(const std::string& str_a);
        StringHelper& operator=(const char* str_a);

        bool operator==(const StringHelper& other_a) const;
        bool operator!=(const StringHelper& other_a) const;

        std::optional<int> ToInt() const;
        std::optional<double> ToDouble() const;
        std::optional<bool> ToBool() const;

        operator std::string() const;

    private:
        std::string data_;
    };
} // namespace OL
#endif
