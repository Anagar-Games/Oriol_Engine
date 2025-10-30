// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef SOURCEPOSITION_HPP
#define SOURCEPOSITION_HPP

#include <memory>
#include <string>

namespace OL
{
    struct SourceOrigin
    {
        std::string filename_;
        int line_offset_;
    };

    using SourceOriginPtr = std::shared_ptr<SourceOrigin>;

    class SourcePosition
    {
    public:
        static const SourcePosition ignore;

        SourcePosition() = default;
        SourcePosition(unsigned int row_a,
                       unsigned int column_a,
                       const SourceOriginPtr& origin_a = nullptr);

        std::string ToString(bool print_filename_a = true) const;

        void IncRow();
        void IncColumn();
        bool IsValid() const;

        void Reset();

        bool operator<(const SourcePosition& rhs_a) const;

        inline unsigned int Row() const
        {
            return row_;
        }

        inline unsigned int Column() const
        {
            return column_;
        }

        inline void SetOrigin(const SourceOriginPtr& origin_a)
        {
            origin_ = origin_a;
        }

        inline const SourceOrigin* GetOrigin() const
        {
            return origin_.get();
        }

        inline operator bool() const
        {
            return IsValid();
        }

    private:
        unsigned int row_ = 0;
        unsigned int column_ = 0;

        SourceOriginPtr origin_;
    };
} // namespace OL
#endif
