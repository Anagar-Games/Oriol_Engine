# Random Component
Thread-safe random number generation utilities with multiple distribution types.

## Basic API Methods
#### Class Random
- `Random()` - Constructor (auto-seeds with current time)
- `int RandomInt(int min_a, int max_a)` - Uniform integer in [min, max]
- `double RandomDouble(double min_a, double max_a)` - Uniform real in [min, max]
- `double NormalDouble(double mean_a, double stddev_a)` - Normal (Gaussian) distribution
- `int BinomialInt(int t_a, double p_a)` - Binomial distribution (t trials, p success probability)
- `bool BernoulliBool(double p_a)` - Bernoulli trial (true with probability p)
- `int PoissonInt(double mean_a)` - Poisson distribution

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/Random/Random.hpp>

using namespace OL;

OLMain()
{
    // Create random number generator
    Random random_;
    
    // Generate different types of random numbers
    std::cout << "Random integer (1-100): " << random_.RandomInt(1, 100) << std::endl;
    std::cout << "Random double (0.0-1.0): " << random_.RandomDouble(0.0, 1.0) << std::endl;
    std::cout << "Normal distribution (mean=0, stddev=1): " << random_.NormalDouble(0.0, 1.0) << std::endl;
    std::cout << "Binomial (10 trials, 0.5 prob): " << random_.BinomialInt(10, 0.5) << std::endl;
    std::cout << "Bernoulli (0.3 prob): " << random_.BernoulliBool(0.3) << std::endl;
    std::cout << "Poisson (mean=5): " << random_.PoissonInt(5.0) << std::endl;
    
    // Multiple samples from the same distribution
    std::cout << "5 uniform integers (1-6): ";
    for (int i_ = 0; i_ < 5; ++i_) 
    {
        std::cout << random_.RandomInt(1, 6) << " ";
    }
    
    std::cout << std::endl;
    
    DOPE 0;
}
```
