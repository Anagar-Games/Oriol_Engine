// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_SOURCECODE_HPP
#define OL_SOURCECODE_HPP

#include "AST/SourceArea.hpp"

#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace OL
{
    class SourceCode
    {
    public:
        SourceCode(const std::shared_ptr<std::istream>& stream_a);

        bool IsValid() const;
        char Next();
        bool FetchLineMarker(const SourceArea& area_a,
                             std::string& line_a,
                             std::string& marker_a);

        void NextSourceOrigin(const std::string& filename_a, int line_offset_a);

        inline void Ignore()
        {
            Next();
        }

        inline const SourcePosition& Pos() const
        {
            return pos_;
        }

        inline const std::string& Line() const
        {
            return current_line_;
        }

        std::string Filename() const;

    protected:
        SourceCode() = default;

        std::string GetLine(std::size_t line_index_a) const;

        std::shared_ptr<std::istream> stream_;
        std::string current_line_;
        std::vector<std::string> lines_;
        SourcePosition pos_;
    };

    using SourceCodePtr = std::shared_ptr<SourceCode>;
} // namespace OL
#endif
