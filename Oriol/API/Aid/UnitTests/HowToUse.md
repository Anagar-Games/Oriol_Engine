# UnitTests Component
Lightweight unit testing framework with assertion macros and test registration.

## Basic API Methods
#### Test Registration Macro
- `UTEST(test_case_name, test_name)` - Defines and registers a test case

#### Assertion Macros
- **Boolean**: `ASSERT_TRUE`, `ASSERT_FALSE`, `EXPECT_TRUE`, `EXPECT_FALSE`
- **Equality**: `ASSERT_EQ`, `ASSERT_NE`, `EXPECT_EQ`, `EXPECT_NE`
- **Comparison**: `ASSERT_LT`, `ASSERT_LE`, `ASSERT_GT`, `ASSERT_GE`
- **String**: `ASSERT_STREQ`, `ASSERT_STRNE`, `ASSERT_STRCASEEQ`, `ASSERT_STRCASENE`
- **Exception**: `ASSERT_THROW`, `ASSERT_NO_THROW`
- **Result**: `SUCCEED`, `FAIL`

#### Test Runner
- `RUN_ALL_TESTS()` - Runs all registered tests and returns exit code

## Example
#### test_math.cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/UnitTests/UnitTests.hpp>
#include <cmath>

UTEST(MathTest, Addition)
{
    ASSERT_EQ(2 + 2, 4);
    ASSERT_NE(5 + 3, 7);
}

UTEST(MathTest, Subtraction)
{
    EXPECT_EQ(10 - 4, 6);
    EXPECT_TRUE(8 - 3 == 5);
}

UTEST(MathTest, Division)
{
    ASSERT_THROW(int x = 5 / 0;, std::exception);
    ASSERT_NO_THROW(double y = 5.0 / 2.0);
}

UTEST(StringTest, Comparison)
{
    std::string hello = "Hello";
    std::string world = "World";
    
    ASSERT_STREQ("Hello", hello.c_str());
    ASSERT_STRNE(hello.c_str(), world.c_str());
    ASSERT_STRCASEEQ("hello", hello.c_str()); // Case-insensitive
}

UTEST(ContainerTest, VectorOperations)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    ASSERT_EQ(numbers.size(), 5);
    ASSERT_GT(numbers.back(), numbers.front());
    ASSERT_LT(numbers[0], numbers[4]);
}
```

#### test_main.cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/UnitTests/UnitTests.hpp>

using namespace OL;

// Additional test cases
UTEST(UtilityTest, FileOperations)
{
    // Test file operations
    SUCCEED(); // Explicit success
}

UTEST(UtilityTest, NetworkOperations)
{
    // This test would fail
    FAIL(); // Explicit failure
}

OLMain()
{
    DOPE RUN_ALL_TESTS();
}
```
