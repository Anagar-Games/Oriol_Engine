# Singleton Component
Thread-safe singleton pattern implementation using modern C++ features.

## Basic API Methods
#### Class Singleton<T>
- `static T& Instance()` - Returns the single instance of type T (thread-safe)
- Protected constructor and destructor to prevent external instantiation
- Deleted copy constructor and assignment operator

## Example
#### hpp
```cpp
#include <API/API.hpp>
#include <API/Aid/Singleton/Singleton.hpp>

using namespace OL;

class Logger : public Singleton<Logger>
{
    friend class Singleton<Logger>;
    
public:
    void Log(const std::string& message_a)
    {
        std::cout << "LOG: " << message_a << std::endl;
    }
    
    void SetLogLevel(int level_a)
    {
        log_level_ = level_a;
    }
    
private:
    Logger() = default;
    ~Logger() = default;
    
    int log_level_ = 0;
};

class ConfigManager : public Singleton<ConfigManager>
{
    friend class Singleton<ConfigManager>;
    
public:
    std::string GetValue(const std::string& key_a)
    {
        return config_values_[key_a];
    }
    
    void SetValue(const std::string& key_a, const std::string& value_a)
    {
        config_values_[key_a] = value_a;
    }
    
private:
    ConfigManager() = default;
    ~ConfigManager() = default;
    
    std::unordered_map<std::string, std::string> config_values_;
};
```

#### cpp
```cpp
#include <API/API.hpp>
#include "Logger.hpp"
#include "ConfigManager.hpp"

using namespace OL;

OLMain()
{
    // Access singleton instances
    Logger::Instance().Log("Application started");
    Logger::Instance().SetLogLevel(2);
    
    ConfigManager::Instance().SetValue("resolution", "1920x1080");
    ConfigManager::Instance().SetValue("fullscreen", "true");
    
    std::cout << "Resolution: " 
              << ConfigManager::Instance().GetValue("resolution") 
              << std::endl;
    
    // Thread-safe access from multiple threads
    std::thread t1_([](){
        Logger::Instance().Log("Message from thread 1");
    });
    
    std::thread t2_([](){
        Logger::Instance().Log("Message from thread 2");
    });
    
    t1_.join();
    t2_.join();
    
    DOPE 0;
}
```
