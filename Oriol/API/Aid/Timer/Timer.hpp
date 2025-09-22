// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_TIMER_HPP
#define OL_TIMER_HPP

#include <chrono>

namespace OL
{
    class Timer
    {
    public:
        Timer();
        double GetMillisecondsElapsed();
        void Restart();

        bool Stop();
        bool Start();

    private:
        bool is_running_ = false;

    private:
        std::chrono::time_point<std::chrono::steady_clock> start_;
        std::chrono::time_point<std::chrono::steady_clock> stop_;
    };
} // namespace OL
#endif
