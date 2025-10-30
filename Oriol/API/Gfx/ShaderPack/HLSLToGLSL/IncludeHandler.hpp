// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_INCLUDEHANDLER_HPP
#define OL_INCLUDEHANDLER_HPP

#include "Export.hpp"

#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace OL
{
    class HTG_EXPORT IncludeHandler
    {
    public:
        IncludeHandler();
        virtual ~IncludeHandler();
        virtual std::unique_ptr<std::istream> Include(
                const std::string& filename_a,
                bool use_search_paths_first_a);

        std::vector<std::string>& GetSearchPaths();
        const std::vector<std::string>& GetSearchPaths() const;

    private:
        struct OpaqueData;
        OpaqueData* data_ = nullptr;
    };
} // namespace OL
#endif
