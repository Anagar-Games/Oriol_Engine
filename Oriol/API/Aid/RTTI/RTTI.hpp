// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_RTTI_HPP
#define OL_RTTI_HPP

#include <string>
#include <typeindex>

namespace OL
{
    class RTTI
    {
    public:
        virtual ~RTTI() = default;

        virtual std::string GetTypeName() const = 0;

        static void RegisterType(const std::type_index& type_id_a,
                                 const std::string& type_name_a);

        static std::string GetTypeNameById(const std::type_index& type_id_a);

    protected:
        RTTI()
        {
            RegisterType(std::type_index(typeid(*this)), GetTypeName());
        }
    };

#define RTTI_DECLARE_TYPE(type_a)                                              \
public:                                                                        \
    virtual std::string GetTypeName() const override                           \
    {                                                                          \
        return #type_a;                                                        \
    }
} // namespace OL
#endif
