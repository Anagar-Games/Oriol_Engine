// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_GLSLSCANNER_HPP
#define OL_GLSLSCANNER_HPP

#include "../SLScanner.hpp"

namespace OL
{
    class GLSLScanner : public SLScanner
    {
    public:
        GLSLScanner(Log* log_a = nullptr);

    private:
        TokenPtr ScanIdentifierOrKeyword(std::string&& spell_a) override;
    };
} // namespace OL

#endif
