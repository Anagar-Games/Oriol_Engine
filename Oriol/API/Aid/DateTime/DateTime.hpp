// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_DATETIME_HPP
#define OL_DATETIME_HPP

#include <iostream>
#include <string>
#include <ctime>

namespace OL
{
    class DateTime
    {
    public:
        DateTime();
        DateTime(std::time_t time_a);

        std::string GetCurrentDateTime() const;
        std::string GetCurrentDate() const;
        std::string GetCurrentTime() const;

        void SetTime(std::time_t time_a);
        std::time_t GetTime() const;

        std::string Format(const std::string& format_a) const;

    public:
        bool operator==(const DateTime& other_a) const;
        bool operator!=(const DateTime& other_a) const;
        bool operator<(const DateTime& other_a) const;
        bool operator>(const DateTime& other_a) const;
        bool operator<=(const DateTime& other_a) const;
        bool operator>=(const DateTime& other_a) const;

    private:
        std::time_t current_time_;
    };
} // namespace OL
#endif
