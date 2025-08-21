// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef PROJECT_CREATOR_HPP
#define PROJECT_CREATOR_HPP

#include <filesystem>
#include <string>

namespace fs = std::filesystem;
namespace Oriol_Dev
{
    class ProjectCreator
    {
    public:
        ProjectCreator(const std::string& project_name_a);
        
        bool CreateProjectStructure();
        bool CreateProjectFiles(int license_choice_a);
        
        int  SelectLicenseInteractively();
        void ShowProjectStructure() const;

    private:
        std::string project_name_;
        fs::path project_dir_;

    private:
        bool _CreateDirectories(const fs::path& path_a);
        bool _CreateFile(const fs::path& path_a, const std::string& content_a);
        std::string _GetLicenseText(int license_choice_a) const;
    };
} // namespace Oriol_Dev

#endif
