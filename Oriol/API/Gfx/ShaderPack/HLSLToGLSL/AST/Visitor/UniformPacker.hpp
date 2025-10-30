// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef UNIFORMPACKER_HPP
#define UNIFORMPACKER_HPP

#include "../TypeDenoter.hpp"
#include "Visitor.hpp"

#include <string>

namespace OL
{
    class UniformPacker
    {
    public:
        struct CbufferAttributes
        {
#if defined __clang__ || defined __GNUC__
            inline CbufferAttributes()
            {}
            CbufferAttributes(const CbufferAttributes&) = default;
            CbufferAttributes& operator=(const CbufferAttributes&) = default;
#endif

            int binding_slot_ = 0;
            std::string name_ = "hsp_cbuffer";
        };

        void Convert(Program& program_a,
                     const CbufferAttributes& cbuffer_attribs_a = {},
                     bool only_reachable_stmnts_a = true);

    private:
        void MakeUniformBuffer();
        void AppendUniform(const VarDeclStmntPtr& var_decl_stmnt_a);

        bool CanConvertUniformWithTypeDenoter(
                const TypeDenoter& type_den_a) const;

    private:
        CbufferAttributes cbuffer_attribs_;

        UniformBufferDeclPtr uniform_buffer_decl_;
        BasicDeclStmntPtr decl_stmnt_;
    };
} // namespace OL
#endif
