# TypeToType Component
Comprehensive type conversion and utility library for common data transformations.

## Basic API Methods

### Type Conversion Functions
- `int StringToInt(const std::string& str_a)` - Converts string to integer
- `double StringToDouble(const std::string& str_a)` - Converts string to double
- `bool StringToBool(const std::string& str_a)` - Converts string to boolean
- `std::string IntToString(int value_a)` - Converts integer to string
- `std::string DoubleToString(double value_a)` - Converts double to string
- `std::string BoolToString(bool value_a)` - Converts boolean to string

### Hexadecimal Functions
- `int HexStringToInt(const std::string& str_a)` - Converts hex string to integer
- `std::string IntToHexString(int value_a)` - Converts integer to hex string

### String Manipulation
- `std::string ToLower(const std::string& str_a)` - Converts string to lowercase
- `std::string ToUpper(const std::string& str_a)` - Converts string to uppercase

### Wide String Functions
- `std::wstring StringToWstring(const std::string& str_a)` - Converts string to wide string
- `std::string WstringToString(const std::wstring& wstr_a)` - Converts wide string to string

### Time Functions
- `time_t StringToTime(const std::string& str_a, const std::string& format_a)` - Parses time string
- `std::string TimeToString(time_t time_a, const std::string& format_a)` - Formats time as string

### Path Utilities
- `std::string GetAbsolutePath(const std::string& path_a)` - Returns absolute path
- `std::string GetRelativePath(const std::string& path_a, const std::string& base_a)` - Returns relative path
- `std::string GetExecutablePath()` - Returns current executable path
- `std::string CombinePaths(const std::string& path1_a, const std::string& path2_a)` - Combines paths
- `std::string GetParentDirectory(const std::string& path_a)` - Returns parent directory
- `std::string GetFilename(const std::string& path_a)` - Returns filename
- `std::string GetFileExtension(const std::string& path_a)` - Returns file extension
- `bool IsAbsolutePath(const std::string& path_a)` - Checks if path is absolute
- `std::string NormalizePath(const std::string& path_a)` - Normalizes path
- `std::string GetCurrentWorkingDirectory()` - Returns current working directory
- `bool PathExists(const std::string& path_a)` - Checks if path exists

### Template Function
- `template <typename T, typename U> std::list<U> VectorToList(const std::vector<T>& vec_a)` - Converts vector to list

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/TypeToType/TypeToType.hpp>
#include <iostream>
#include <vector>

using namespace OL;

OLMain()
{
    // Basic type conversions
    int num_ = StringToInt("42");
    double pi_ = StringToDouble("3.14159");
    bool flag_ = StringToBool("true");
    
    std::cout << "Number: " << num_ << std::endl;
    std::cout << "Pi: " << pi_ << std::endl;
    std::cout << "Flag: " << std::boolalpha << flag_ << std::endl;
    
    // String manipulation
    std::string lower_ = ToLower("Hello WORLD");
    std::string upper_ = ToUpper("hello world");
    std::cout << "Lower: " << lower_ << std::endl;
    std::cout << "Upper: " << upper_ << std::endl;
    
    // Hexadecimal conversions
    int hex_value_ = HexStringToInt("FF");
    std::string hex_string_ = IntToHexString(255);
    std::cout << "Hex to int: " << hex_value_ << std::endl;
    std::cout << "Int to hex: " << hex_string_ << std::endl;
    
    // Path utilities
    std::string abs_path_ = GetAbsolutePath("config.txt");
    std::string filename_ = GetFilename("/path/to/file.txt");
    std::string extension_ = GetFileExtension("document.pdf");
    
    std::cout << "Absolute path: " << abs_path_ << std::endl;
    std::cout << "Filename: " << filename_ << std::endl;
    std::cout << "Extension: " << extension_ << std::endl;
    
    // Time conversions
    time_t now_ = time(nullptr);
    std::string time_str_ = TimeToString(now_, "%Y-%m-%d %H:%M:%S");
    std::cout << "Current time: " << time_str_ << std::endl;
    
    // Container conversion
    std::vector<int> numbers_ = {1, 2, 3, 4, 5};
    std::list<int> number_list_ = VectorToList<int, int>(numbers_);
    
    // Check if path exists
    if (PathExists("config.ini")) 
    {
        std::cout << "Config file exists" << std::endl;
    }
    
    DOPE 0;
}
```
