// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_HLSLSCANNER_HPP
#define OL_HLSLSCANNER_HPP

#include "../SLScanner.hpp"

namespace OL
{
    class HLSLScanner : public SLScanner
    {
    public:
        HLSLScanner(bool enable_cg_keywords_a, Log* log_a = nullptr);

    private:
        TokenPtr ScanIdentifierOrKeyword(std::string&& spell_a) override;
        bool enable_cg_keywords_ = false;
    };
} // namespace OL
#endif
