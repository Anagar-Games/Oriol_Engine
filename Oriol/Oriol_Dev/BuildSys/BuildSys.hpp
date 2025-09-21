// BuildSys.hpp
#ifndef BUILDSYS_HPP
#define BUILDSYS_HPP

#include "FPLParser/FPLParser.hpp"
#include "MakeFusion/MakeFusion.hpp"
#include <filesystem>
#include <iostream>
#include <string>

namespace Oriol_Dev
{
    class BuildSys
    {
    public:
        static bool StartBuild();

    private:
        static void FindSources(const std::filesystem::path& path, std::vector<std::string>& sources);
    };
}

#endif