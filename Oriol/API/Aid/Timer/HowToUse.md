# Timer Component
High-resolution timer for precise performance measurement and timing operations.

## Basic API Methods
#### Class Timer
- `Timer()` - Constructor (automatically starts the timer)
- `double GetMillisecondsElapsed()` - Returns elapsed time in milliseconds
- `void Restart()` - Resets and starts the timer
- `bool Stop()` - Stops the timer (returns success status)
- `bool Start()` - Starts the timer (returns success status)

## Example
#### cpp
```cpp
#include <API/API.hpp>
#include <API/Aid/Timer/Timer.hpp>
#include <thread>

using namespace OL;

void ExpensiveOperation()
{
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

OLMain()
{
    Timer timer_;
    
    // Measure execution time
    ExpensiveOperation();
    
    std::cout << "Operation took: " 
              << timer_.GetMillisecondsElapsed() 
              << " ms" << std::endl;
    
    // Use start/stop for precise measurement
    timer_.Restart();
    
    // Start and stop around specific code
    timer_.Start();
    ExpensiveOperation();
    timer_.Stop();
    
    std::cout << "Timed operation: " 
              << timer_.GetMillisecondsElapsed() 
              << " ms" << std::endl;
    
    // Multiple measurements
    timer_.Restart();
    for (int i_ = 0; i_ < 5; ++i_) 
    {
        ExpensiveOperation();
        std::cout << "Loop " << i_ << ": " 
                  << timer_.GetMillisecondsElapsed() 
                  << " ms" << std::endl;
    }
    
    // Benchmarking example
    Timer bench_timer_;
    const int iterations_ = 10;
    
    for (int i_ = 0; i_ < iterations_; ++i_) 
    {
        ExpensiveOperation();
    }
    
    double total_time_ = bench_timer_.GetMillisecondsElapsed();
    double averageTime = total_time_ / iterations_;
    
    std::cout << "Total time: " << total_time_ << " ms" << std::endl;
    std::cout << "Average per operation: " << average_time_ << " ms" << std::endl;
    
    DOPE 0;
}
```
