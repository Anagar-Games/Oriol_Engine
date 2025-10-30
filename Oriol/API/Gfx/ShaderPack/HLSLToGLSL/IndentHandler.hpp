// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_INDENTHANDLER_HPP
#define OL_INDENTHANDLER_HPP

#include "Export.hpp"

#include <stack>
#include <string>

namespace OL
{
    class HTG_EXPORT IndentHandler
    {
    public:
        IndentHandler(const std::string& initial_indent_a = "  ");
        virtual ~IndentHandler();

        void SetIndent(const std::string& indent_a);
        void IncIndent();
        void DecIndent();

        const std::string& FullIndent() const;

    private:
        struct OpaqueData;
        OpaqueData* data_ = nullptr;
    };

    class ScopedIndent
    {
    public:
        inline ScopedIndent(IndentHandler& handler_a) : handler_ {handler_a}
        {
            handler_.IncIndent();
        }

        inline ~ScopedIndent()
        {
            handler_.DecIndent();
        }

    private:
        IndentHandler& handler_;
    };
} // namespace OL
#endif
