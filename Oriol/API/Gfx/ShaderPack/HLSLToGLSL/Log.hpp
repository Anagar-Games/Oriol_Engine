// Copyright (c) 2025 Anagar GAmes
// MIT License

#ifndef OL_LOG_HPP
#define OL_LOG_HPP

#include "IndentHandler.hpp"
#include "Report.hpp"

#include <string>
#include <vector>

namespace OL
{
    class HTG_EXPORT Log
    {
    public:
        virtual ~Log() = default;

        virtual void SubmitReport(const Report& report_a) = 0;

        inline void SetIndent(const std::string& indent_a)
        {
            indent_handler_.SetIndent(indent_a);
        }

        inline void IncIndent()
        {
            indent_handler_.IncIndent();
        }

        inline void DecIndent()
        {
            indent_handler_.DecIndent();
        }

    protected:
        Log() = default;

        inline const std::string& FullIndent() const
        {
            return indent_handler_.FullIndent();
        }

    private:
        IndentHandler indent_handler_;
    };

    class HTG_EXPORT StdLog : public Log
    {
    public:
        StdLog();
        ~StdLog();

        void SubmitReport(const Report& report_a) override;
        void PrintAll(bool verbose_a = true);

    private:
        struct OpaqueData;
        OpaqueData* data_ = nullptr;
    };
} // namespace OL
#endif
