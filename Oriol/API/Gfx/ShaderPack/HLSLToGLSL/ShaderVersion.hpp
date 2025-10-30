// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_SHADERVERSION_HPP
#define OL_SHADERVERSION_HPP

#include <string>

namespace OL
{
    class ShaderVersion
    {
    public:
        ShaderVersion() = default;
        ShaderVersion(const ShaderVersion&) = default;
        ShaderVersion& operator=(const ShaderVersion&) = default;

        ShaderVersion(int major_a, int minor_a);

        std::string ToString() const;

        inline int Major() const
        {
            return major_;
        }

        inline int Minor() const
        {
            return minor_;
        }

    private:
        int major_ = 0;
        int minor_ = 0;
    };

    bool operator==(const ShaderVersion& lhs_a, const ShaderVersion& rhs_a);
    bool operator!=(const ShaderVersion& lhs_a, const ShaderVersion& rhs_a);

    bool operator<(const ShaderVersion& lhs_a, const ShaderVersion& rhs_a);
    bool operator<=(const ShaderVersion& lhs_a, const ShaderVersion& rhs_a);

    bool operator>(const ShaderVersion& lhs_a, const ShaderVersion& rhs_a);
    bool operator>=(const ShaderVersion& lhs_a, const ShaderVersion& rhs_a);
} // namespace OL
#endif
