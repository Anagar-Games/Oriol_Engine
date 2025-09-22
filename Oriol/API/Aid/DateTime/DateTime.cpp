#include "DateTime.hpp"

namespace OL
{
    DateTime::DateTime()
    {
        current_time_ = time(nullptr);
    }

    DateTime::DateTime(std::time_t time_a) : current_time_(time_a)
    {}

    std::string DateTime::GetCurrentDateTime() const
    {
        return Format("%Y-%m-%d %H:%M:%S");
    }

    std::string DateTime::GetCurrentDate() const
    {
        return Format("%Y-%m-%d");
    }

    std::string DateTime::GetCurrentTime() const
    {
        return Format("%H:%M:%S");
    }

    void DateTime::SetTime(std::time_t time_a)
    {
        current_time_ = time_a;
    }

    std::time_t DateTime::GetTime() const
    {
        return current_time_;
    }

    std::string DateTime::Format(const std::string& format_a) const
    {
        tm time_info_ = {};

#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&time_info_, &current_time_);
#else
        localtime_r(&current_time_, &time_info_);
#endif

        char buffer_[80];
        std::strftime(buffer_, sizeof(buffer_), format_a.c_str(), &time_info_);
        return std::string(buffer_);
    }

    bool DateTime::operator==(const DateTime& other_a) const
    {
        return current_time_ == other_a.current_time_;
    }

    bool DateTime::operator!=(const DateTime& other_a) const
    {
        return current_time_ != other_a.current_time_;
    }

    bool DateTime::operator<(const DateTime& other_a) const
    {
        return current_time_ < other_a.current_time_;
    }

    bool DateTime::operator>(const DateTime& other_a) const
    {
        return current_time_ > other_a.current_time_;
    }

    bool DateTime::operator<=(const DateTime& other_a) const
    {
        return current_time_ <= other_a.current_time_;
    }

    bool DateTime::operator>=(const DateTime& other_a) const
    {
        return current_time_ >= other_a.current_time_;
    }
} // namespace OL
