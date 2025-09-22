# RTTI Component
Runtime Type Information system for C++ with automatic type registration and name retrieval.

## Basic API Methods
#### Class RTTI
- `virtual std::string GetTypeName() const = 0` - Returns the type name as a string
- `static void RegisterType(const std::type_index& type_id_a, const std::string& type_name_a)` - Registers a type in the RTTI system
- `static std::string GetTypeNameById(const std::type_index& type_id_a)` - Retrieves type name by type index

#### Macro RTTI_DECLARE_TYPE
- `RTTI_DECLARE_TYPE(type_a)` - Implements GetTypeName() method for a class

## Example
#### hpp
```cpp
#include <API/API.hpp>
#include <API/Aid/DateTime/DateTime.hpp>

using namespace OL;

class GameObject : public RTTI
{
public:
    RTTI_DECLARE_TYPE(GameObject)
    // ... other class members
};

class Player : public GameObject
{
public:
    RTTI_DECLARE_TYPE(Player)
    // ... other class members
};

class Enemy : public GameObject
{
public:
    RTTI_DECLARE_TYPE(Enemy)
    // ... other class members
};
```

#### cpp
```cpp
#include "GameObjects.hpp"
#include <API/API.hpp>
#include <API/Aid/DateTime/DateTime.hpp>

using namespace OL;

void PrintTypeInfo(const RTTI* object_a)
{
    std::cout << "Object type: " << object_a->GetTypeName() << std::endl;
}

OLMain()
{
    Player player_;
    Enemy enemy_;
    
    PrintTypeInfo(&player_); // Output: Object type: Player
    PrintTypeInfo(&enemy_);  // Output: Object type: Enemy
    
    // Get type name without an instance
    std::type_index player_type_ = typeid(Player);
    std::cout << "Player type name: " 
              << RTTI::GetTypeNameById(player_type_) 
              << std::endl;
    
    DOPE 0;
}
```
