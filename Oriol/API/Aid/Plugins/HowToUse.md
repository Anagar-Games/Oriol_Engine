# Plugins Component
Cross-platform plugin system for dynamic library loading and management.

## Basic API Methods
#### Class IPlugin (Interface)
- `virtual void Initialize() = 0` - Called when plugin is loaded
- `virtual void Execute() = 0` - Main execution method
- `virtual void Shutdown() = 0` - Called when plugin is unloaded

#### Class PluginManager
- `PluginManager()` - Constructor
- `~PluginManager()` - Destructor (automatically unloads all plugins)
- `void LoadPlugin(const std::string& path_a)` - Loads a plugin from file path
- `void UnloadPlugin(const std::string& path_a)` - Unloads a specific plugin
- `void UnloadAll()` - Unloads all plugins
- `const std::vector<std::unique_ptr<IPlugin>>& GetPlugins() const` - Returns loaded plugins

## Creating a Plugin
#### plugin_example.cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/Plugins/Plugins.hpp>

using namespace OL;

class ExamplePlugin : public IPlugin
{
public:
    void Initialize() override
    {
        std::cout << "ExamplePlugin initialized!" << std::endl;
    }
    
    void Execute() override
    {
        std::cout << "ExamplePlugin executed!" << std::endl;
    }
    
    void Shutdown() override
    {
        std::cout << "ExamplePlugin shutdown!" << std::endl;
    }
};

// Export function - must have exactly this name
extern "C" PLUGIN_EXPORT IPlugin* CreatePlugin()
{
    return new ExamplePlugin();
}
```

#### Compilation (Linux/macOS):
```bash
g++ -shared -fPIC plugin_example.cpp -o libexample.so
```

#### Compilation (Windows):
```bash
g++ -shared plugin_example.cpp -o example.dll
```

## Example Usage
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/Plugins/Plugins.hpp>

using namespace OL;

OLMain()
{
    PluginManager plugin_manager_;
    
    try 
    {
        // Load a plugin
        plugin_manager_.LoadPlugin("libexample.so"); // or "example.dll" on Windows
        
        // Get all loaded plugins
        const auto& plugins_ = plugin_manager_.GetPlugins();
        
        // Initialize and execute each plugin
        for (const auto& plugin_ : plugins_) 
        {
            plugin_->Initialize();
            plugin_->Execute();
        }
        
        // Keep plugins loaded until needed
        std::cout << "Press Enter to unload plugins..." << std::endl;
        std::cin.get();
        
        // Unload all plugins (automatic in destructor too)
        plugin_manager_.UnloadAll();
        
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Plugin error: " << e.what() << std::endl;
        return 1;
    }
    
    DOPE 0;
}
```
