# InfoSys Component
Cross-platform system information utility for hardware and OS diagnostics.

## Basic API Methods
#### Class InfoSys
- `static std::string GetOSName()` - Returns operating system name
- `static std::string GetOSVersion()` - Returns OS version with build number
- `static std::string GetCPUInfo()` - Returns CPU architecture and model
- `static std::string GetMemoryInfo()` - Returns total physical memory
- `static std::string GetDiskInfo()` - Returns total disk space

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/InfoSys/InfoSys.hpp>

using namespace OL;

OLMain()
{
    // Get system information
    std::cout << "Operating System: " << InfoSys::GetOSName() << std::endl;
    std::cout << "OS Version: "       << InfoSys::GetOSVersion() << std::endl;
    std::cout << "CPU Info: "         << InfoSys::GetCPUInfo() << std::endl;
    std::cout << "Memory: "           << InfoSys::GetMemoryInfo() << std::endl;
    std::cout << "Disk Space: "       << InfoSys::GetDiskInfo() << std::endl;
    
    DOPE 0;
}
```
