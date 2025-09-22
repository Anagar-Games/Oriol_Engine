# INIParser Component
INI file parser and generator for configuration management in C++.

## Basic API Methods
#### Class INIParser
- `INIParser(const std::string& filename_a)` - Constructor with filename
- `bool Load()` - Loads and parses the INI file
- `bool Save() const` - Saves changes back to the file
- `std::string GetValue(const std::string& section_a, const std::string& key_a) const` - Retrieves a value
- `void SetValue(const std::string& section_a, const std::string& key_a, const std::string& value_a)` - Sets a value
- `std::vector<std::string> GetSections() const` - Returns all section names
- `std::map<std::string, std::string> GetKeys(const std::string& section_a) const` - Returns all key-value pairs in a section

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/INI/INIParser.hpp>

using namespace OL;

OLMain()
{
    // Create parser instance
    INIParser config_("settings.ini");
    
    // Load configuration file
    if (!config_.Load()) 
    {
        std::cout << "Failed to load config file, creating default" << std::endl;
        
        // Set default values
        config_.SetValue("Graphics", "Resolution", "1920x1080");
        config_.SetValue("Graphics", "Fullscreen", "true");
        config_.SetValue("Audio", "Volume", "80");
        config_.SetValue("Audio", "Mute", "false");
        
        // Save default configuration
        if (!config_.Save())
        {
            std::cout << "Failed to save config file" << std::endl;
            return 1;
        }
    }
    
    // Read values
    std::string resolution_ = config_.GetValue("Graphics", "Resolution");
    std::string volume_ = config_.GetValue("Audio", "Volume");
    
    std::cout << "Resolution: " << resolution_ << std::endl;
    std::cout << "Volume: " << volume_ << std::endl;
    
    // Modify a value
    config_.SetValue("Audio", "Volume", "90");
    
    // List all sections
    auto sections_ = config_.GetSections();
    std::cout << "Sections:" << std::endl;
    for (const auto& section_ : sections_) 
    {
        std::cout << "  " << section_ << std::endl;
    }
    
    // Save changes
    if (config_.Save())
    {
        std::cout << "Configuration saved successfully" << std::endl;
    }
    
    DOPE 0;
}
```

#### Example INI File (settings.ini):
```ini
[Graphics]
Resolution=1920x1080
Fullscreen=true

[Audio]
Volume=80
Mute=false

; This is a comment
[Network]
Port=8080
Timeout=30
```
