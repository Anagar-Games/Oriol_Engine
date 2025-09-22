# DateTime Component
C++ date and time handling utilities with cross-platform support.

## Basic API Methods
#### Class DateTime
- `DateTime()` - Default constructor (creates object with current time)
- `DateTime(std::time_t time_a)` - Constructor with specific time
- `std::string GetCurrentDateTime() const` - Returns formatted date and time (YYYY-MM-DD HH:MM:SS)
- `std::string GetCurrentDate() const` - Returns date portion (YYYY-MM-DD)
- `std::string GetCurrentTime() const` - Returns time portion (HH:MM:SS)
- `void SetTime(std::time_t time_a)` - Sets specific time value
- `std::time_t GetTime() const` - Gets underlying time value
- `std::string Format(const std::string& format_a) const` - Custom formatting using strftime syntax

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/DateTime/DateTime.hpp>

using namespace OL;

OLMain()
{
    // Create DateTime instance with current time
    DateTime now_;
    
    // Get formatted date and time
    std::cout << "Current datetime: " << now_.GetCurrentDateTime() << std::endl;
    std::cout << "Current date: " << now_.GetCurrentDate() << std::endl;
    std::cout << "Current time: " << now_.GetCurrentTime() << std::endl;
    
    // Custom formatting
    std::cout << "Formatted: " << now_.Format("%A, %B %d %Y") << std::endl;
    
    // Create specific time (e.g., 1 hour ago)
    std::time_t one_hour_ago_ = now_.GetTime() - 3600;
    DateTime past_(one_hour_ago_);
    
    // Time comparison
    if (now_ > past_) 
    {
        std::cout << "Now is after past time" << std::endl;
    }
    
    DOPE 0;
}
```
