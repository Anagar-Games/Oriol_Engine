// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_SLSCANNER_HPP
#define OL_SLSCANNER_HPP

#include "Scanner.hpp"

namespace OL
{
    class SLScanner : public Scanner
    {
    public:
        SLScanner(Log* log_a = nullptr);

        TokenPtr Next() override;

    protected:
        virtual TokenPtr ScanIdentifierOrKeyword(std::string&& spell_a) = 0;

    private:
        TokenPtr ScanToken() override;

        TokenPtr ScanDirective();
        TokenPtr ScanIdentifier();
        TokenPtr ScanAssignShiftRelationOp(const char chr_a);
        TokenPtr ScanPlusOp();
        TokenPtr ScanMinusOp();
    };
} // namespace OL
#endif
