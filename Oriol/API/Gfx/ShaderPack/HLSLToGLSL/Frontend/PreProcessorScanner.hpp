// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_PREPROCESSORSCANNER_HPP
#define OL_PREPROCESSORSCANNER_HPP

#include "Scanner.hpp"

namespace OL
{
    class PreProcessorScanner : public Scanner
    {
    public:
        PreProcessorScanner(Log* log_a = nullptr);

        TokenPtr Next() override;

    private:
        TokenPtr ScanToken() override;
        TokenPtr ScanDirectiveOrDirectiveConcat();
        TokenPtr ScanIdentifier();
    };
} // namespace OL

#endif
