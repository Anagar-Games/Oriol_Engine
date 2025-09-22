# Filesystem Component
Cross-platform filesystem operations wrapper for C++17 and above.

## Basic API Methods
#### Class Filesystem
- `bool CreateDirectory(const std::string& path_a)` - Creates a directory
- `bool Remove(const std::string& path_a)` - Removes a file or empty directory
- `bool Rename(const std::string& old_path_a, const std::string& new_path_a)` - Renames/moves a file or directory
- `bool Exists(const std::string& path_a) const` - Checks if path exists
- `bool Copy(const std::string& from_a, const std::string& to_a, bool recursive_a = false)` - Copies files/directories
- `std::vector<std::string> ListDirectory(const std::string& path_a) const` - Lists directory contents
- `std::string GetAbsolutePath(const std::string& path_a) const` - Returns absolute path
- `bool IsDirectory(const std::string& path_a) const` - Checks if path is a directory
- `bool IsFile(const std::string& path_a) const` - Checks if path is a regular file
- `uintmax_t FileSize(const std::string& path_a) const` - Gets file size (throws if not a file)

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/Filesystem/Filesystem.hpp>

using namespace OL;

OLMain()
{
    Filesystem fs;
    
    // Create a directory
    if (fs.CreateDirectory("test_dir")) {
        std::cout << "Directory created successfully" << std::endl;
    }
    
    // Check if directory exists
    if (fs.Exists("test_dir") && fs.IsDirectory("test_dir")) {
        std::cout << "Directory exists and is a directory" << std::endl;
    }
    
    // Get absolute path
    std::string abs_path_ = fs.GetAbsolutePath("test_dir");
    std::cout << "Absolute path: " << abs_path_ << std::endl;
    
    // List directory contents (if any)
    auto contents_ = fs.ListDirectory(".");
    std::cout << "Directory contents:" << std::endl;
    for (const auto& item_ : contents_) {
        std::cout << "  " << item_ << std::endl;
    }
    
    // Copy a file
    if (fs.Copy("source.txt", "test_dir/copy.txt")) {
        std::cout << "File copied successfully" << std::endl;
    }
    
    // Get file size
    try {
        auto size_ = fs.FileSize("source.txt");
        std::cout << "File size: " << size_ << " bytes" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error getting file size: " << e.what() << std::endl;
    }
    
    // Clean up
    if (fs.Remove("test_dir/copy.txt")) {
        std::cout << "File removed successfully" << std::endl;
    }
    
    DOPE 0;
}
```
