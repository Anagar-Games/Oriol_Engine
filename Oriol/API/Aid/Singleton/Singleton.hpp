// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_SINGLETON_HPP
#define OL_SINGLETON_HPP

#include <memory>
#include <mutex>

namespace OL
{
    template <typename T>
    class Singleton
    {
    public:
        static T& Instance()
        {
            std::call_once(init_flag_, []() { instance_ptr_.reset(new T()); });

            return *instance_ptr_;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    protected:
        Singleton() = default;
        virtual ~Singleton() = default;

    private:
        static std::unique_ptr<T> instance_ptr_;
        static std::once_flag init_flag_;
    };

    template <typename T>
    std::unique_ptr<T> Singleton<T>::instance_ptr_ = nullptr;

    template <typename T>
    std::once_flag Singleton<T>::init_flag_;
} // namespace OL
#endif
