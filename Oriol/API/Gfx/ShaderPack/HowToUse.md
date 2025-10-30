# ShaderPack Component
C++ cross-platform shader packer.

## Basic API Methods
#### Class ShaderPack
**Static Methods:**
- `CreateShaderPack(const std::string& hlsl_path_a, const std::string& entry_point_a, ShaderTarget target_a)` - Creates a shader pack file from HLSL source
  - `hlsl_path_a`: Path to HLSL source file
  - `entry_point_a`: Shader entry point function name
  - `target_a`: Shader target type (VertexShader/FragmentShader)

- `LoadHLSLSection(const std::string& shader_pack_path_a)` - Loads HLSL binary section from shader pack
  - Returns: `std::vector<uint8_t>` containing compiled HLSL binary

- `LoadGLSLSection(const std::string& shader_pack_path_a)` - Loads GLSL binary section from shader pack
  - Returns: `std::vector<uint8_t>` containing compiled GLSL binary

## Platform Support
- **Windows**: Full HLSL compilation + GLSL translation
- **Other Platforms**: GLSL translation only (HLSL compilation disabled)

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/GFX/ShaderPack/ShaderPack.hpp>

using namespace OL;

OLMain()
{
    try 
    {
        ShaderPack::CreateShaderPack(
            "shaders/example.hlsl", 
            "main",
            ShaderTarget::VertexShader
        );
        
        auto hlsl_binary_ = ShaderPack::LoadHLSLSection("shaders/example.shader");
        auto glsl_binary_ = ShaderPack::LoadGLSLSection("shaders/example.shader");
        
        std::cout << "HLSL binary size: " << hlsl_binary_.size() << " bytes" << std::endl;
        std::cout << "GLSL binary size: " << glsl_binary_.size() << " bytes" << std::endl;
        
    } 
    catch (const std::exception& e_) 
    {
        std::cerr << "Shader pack error: " << e_.what() << std::endl;
    }
    
    DOPE 0;
}
```
