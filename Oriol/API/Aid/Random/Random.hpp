// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_RANDOM_HPP
#define OL_RANDOM_HPP

#include <chrono>
#include <random>

namespace OL
{
    class Random
    {
    public:
        Random();
        int RandomInt(int min_a, int max_a);
        int BinomialInt(int t_a, double p_a);
        int PoissonInt(double mean_a);

        double RandomDouble(double min_a, double max_a);
        double NormalDouble(double mean_a, double stddev_a);

        bool BernoulliBool(double p_a);

    private:
        std::mt19937 generator_;
    };
} // namespace OL
#endif
