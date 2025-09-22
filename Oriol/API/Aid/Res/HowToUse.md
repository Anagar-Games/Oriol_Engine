# Res Component
Resource packaging and management system for embedding files into a single binary archive.

## Basic API Methods
#### Class ResWriter (Resource Packer)
- `void AddSection(const std::string& section_a)` - Creates a new section
- `void AddFile(const std::string& section_a, const std::string& name_a, const std::string& file_path_a)` - Adds a file to a section
- `void RemoveFile(const std::string& section_a, const std::string& name_a)` - Removes a file from a section
- `void UpdateFile(const std::string& section_a, const std::string& name_a, const std::string& new_file_path_a)` - Updates a file in a section
- `std::vector<std::string> ListSections() const` - Returns all section names
- `std::vector<std::string> ListFiles(const std::string& section_a) const` - Returns all files in a section
- `void WriteToFile(const std::string& out_file_path_a) const` - Creates the resource archive

#### Class ResReader (Resource Extractor)
- `ResReader(const std::string& res_file_path_a)` - Constructor with resource file path
- `std::vector<std::string> ListSections() const` - Returns all section names
- `std::vector<std::string> ListFiles(const std::string& section_a) const` - Returns all files in a section
- `bool HasFile(const std::string& section_a, const std::string& name_a) const` - Checks if a file exists
- `std::vector<char> GetFile(const std::string& section_a, const std::string& name_a) const` - Retrieves file content
- `void ExtractAll(const std::string& out_dir_a) const` - Extracts all files to directory

## Example
#### Creating a Resource Archive (cpp)
```cpp
#include <API/API.hpp>
#include <API/Aid/Res/Res.hpp>

using namespace OL;

OLMain()
{
    // Create a resource archive
    ResWriter writer_;
    
    // Add files to different sections
    writer_.AddFile("textures", "player.png", "assets/textures/player.png");
    writer_.AddFile("textures", "enemy.png", "assets/textures/enemy.png");
    writer_.AddFile("sounds", "explosion.wav", "assets/sounds/explosion.wav");
    writer_.AddFile("sounds", "music.ogg", "assets/sounds/music.ogg");
    writer_.AddFile("config", "settings.ini", "config/settings.ini");
    
    // Create the resource file
    writer_.WriteToFile("game_resources.dat");
    
    std::cout << "Resource archive created successfully!" << std::endl;
    DOPE 0;
}
```

#### Using a Resource Archive (cpp)
```cpp
#include <API/API.hpp>
#include <API/Aid/Res/Res.hpp>
#include <fstream>

using namespace OL;

OLMain()
{
    try 
    {
        // Load the resource archive
        ResReader reader_("game_resources.dat");
        
        // List available sections
        auto sections_ = reader_.ListSections();
        std::cout << "Available sections:" << std::endl;
        for (const auto& section_ : sections_) 
        {
            std::cout << "  " << section_ << std::endl;
        }
        
        // List files in a section
        auto textures_ = reader_.ListFiles("textures");
        std::cout << "Textures:" << std::endl;
        for (const auto& texture_ : textures_) 
        {
            std::cout << "  " << texture_ << std::endl;
        }
        
        // Extract a specific file
        if (reader_.HasFile("sounds", "explosion.wav")) 
        {
            auto sound_data_ = reader_.GetFile("sounds", "explosion.wav");
            std::ofstream out_("explosion.wav", std::ios::binary);
            
            out_.write(sound_data_.data(), sound_data_.size());
            std::cout << "Extracted explosion.wav" << std::endl;
        }
        
        // Extract all files
        reader_.ExtractAll("extracted_resources");
        std::cout << "All resources extracted" << std::endl;
        
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    DOPE 0;
}
```
