# StringHelper Component
Comprehensive string manipulation and utility library with fluent interface.

## Basic API Methods
#### Class StringHelper
- **Construction**: `StringHelper(const std::string&)`, `StringHelper(const char*)`
- **Case Conversion**: `ToLowerCase()`, `ToUpperCase()`
- **Trimming**: `Trim()` - removes leading/trailing whitespace
- **Splitting**: `Split(char)` - splits string by delimiter
- **Pattern Matching**: `Contains()`, `StartsWith()`, `EndsWith()`
- **Replacement**: `Replace(old, new)` - replaces all occurrences
- **Search**: `IndexOf()`, `LastIndexOf()` - finds substring positions
- **Substrings**: `Substring(start, length)` - extracts substring
- **Validation**: `IsEmpty()`, `Length()`
- **Conversion**: `ToInt()`, `ToDouble()`, `ToBool()` (returns std::optional)
- **Extraction**: `ExtractNumericPart()` - extracts digits and decimal points

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/StringHelper/StringHelper.hpp>

using namespace OL;

OLMain()
{
    // Create StringHelper instances
    StringHelper str1_("  Hello World  ");
    StringHelper str2_("File_123.txt");
    StringHelper str3_("true");
    StringHelper str4_("42.5kg");
    
    // Basic operations
    std::cout << "Trimmed: '" << str1_.Trim() << "'" << std::endl;
    std::cout << "Lower case: " << str1_.ToLowerCase() << std::endl;
    std::cout << "Upper case: " << str1_.ToUpperCase() << std::endl;
    
    // Pattern matching
    std::cout << "Contains 'World': " << str1_.Contains("World") << std::endl;
    std::cout << "StartsWith 'Hello': " << str1_.StartsWith("Hello") << std::endl;
    std::cout << "EndsWith '.txt': " << str2_.EndsWith(".txt") << std::endl;
    
    // Splitting
    auto parts_ = StringHelper("a,b,c,d").Split(',');
    std::cout << "Split parts: ";
    for (const auto& part_ : parts_) 
    {
        std::cout << "'" << part_ << "' ";
    }
    
    std::cout << std::endl;
    
    // Replacement
    std::cout << "Replaced: " 
              << StringHelper("Hello World").Replace("World", "C++") 
              << std::endl;
    
    // Numeric extraction and conversion
    std::cout << "Numeric part: " << str4_.ExtractNumericPart() << std::endl;
    
    // Safe conversion with optional
    if (auto num_ = str4_.ToInt()) 
    {
        std::cout << "As int: " << *num_ << std::endl;
    } 
    else 
    {
        std::cout << "Not a valid integer" << std::endl;
    }
    
    if (auto flag_ = str3_.ToBool()) 
    {
        std::cout << "As bool: " << (*flag_ ? "true" : "false") << std::endl;
    }
    
    // Method chaining
    std::string result_ = StringHelper("  Hello WORLD  ")
        .Trim()
        .ToLowerCase()
        .Replace("world", "Universe");
    
    std::cout << "Chained result: " << result_ << std::endl;
    
    DOPE 0;
}
```
