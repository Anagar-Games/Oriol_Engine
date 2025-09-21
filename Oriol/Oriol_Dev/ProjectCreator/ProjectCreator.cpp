#include "ProjectCreator.hpp"
#include "ConsoleColor.hpp"

#include <fstream>
#include <iostream>

namespace Oriol_Dev
{
    ProjectCreator::ProjectCreator(const std::string& project_name_a)
        : project_name_(project_name_a),
          project_dir_(fs::current_path() / project_name_a) {}

    bool ProjectCreator::_CreateDirectories(const fs::path& path_a)
    {
        try
        {
            return fs::create_directories(path_a);
        } 
        catch (const std::exception& e_)
        {
            ConsoleColor::SetRed();
            std::cerr << "Error when creating a directory: " 
                      << e_.what() << std::endl;

            ConsoleColor::Reset();
            return false;
        }
    }

    bool ProjectCreator::_CreateFile(const fs::path& path_a,
                                     const std::string& content_a)
    {
        try
        {
            std::ofstream file_(path_a);
            if (!file_.is_open())
                return false;

            file_ << content_a;
            file_.close();
            return true;
        } 
        catch (const std::exception& e_)
        {
            ConsoleColor::SetRed();
            std::cerr << "Error when creating a file: " 
                      << e_.what() << std::endl;
            
            ConsoleColor::Reset();
            return false;
        }
    }

    bool ProjectCreator::CreateProjectStructure()
    {
        if (fs::exists(project_dir_))
        {
            ConsoleColor::SetRed();
            std::cerr << "The directory'" << project_name_ 
                      << "' already exists!" << std::endl;

            ConsoleColor::Reset();
            return false;
        }

        fs::path assets_dir_  = project_dir_ / "Assets";
        fs::path build_dir_   = project_dir_ / "Build";
        fs::path sources_dir_ = project_dir_ / "Sources";

        return _CreateDirectories(assets_dir_) && 
               _CreateDirectories(build_dir_)  && 
               _CreateDirectories(sources_dir_);
    }

    std::string ProjectCreator::_GetLicenseText(int license_choice_a) const
    {
        switch (license_choice_a)
        {
        case 1:
            return "MIT License\n\nCopyright (c) 2025 " + project_name_ + "\n\n"
                   "Permission is hereby granted, free of charge, to any person obtaining a copy of\n"
                   "this software and associated documentation files (the \"Software\"), to deal in\n"
                   "the Software without restriction, including without limitation the rights to\n"
                   "use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of\n"
                   "the Software, and to permit persons to whom the Software is furnished to do so,\n"
                   "subject to the following conditions:\n\n"
                   "The above copyright notice and this permission notice shall be included in all\n"
                   "copies or substantial portions of the Software.\n\n"
                   "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
                   "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS\n"
                   "FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR\n"
                   "COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER\n"
                   "IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN\n"
                   "CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n";

        case 2:
            return "Apache License Version 2.0\n\n"
                   "Copyright 2025 " + project_name_ + "\n\n"
                   "Licensed under the Apache License, Version 2.0 (the \"License\");\n"
                   "you may not use this file except in compliance with the License.\n"
                   "You may obtain a copy of the License at\n\n"
                   "    http://www.apache.org/licenses/LICENSE-2.0\n\n"
                   "Unless required by applicable law or agreed to in writing, software\n"
                   "distributed under the License is distributed on an \"AS IS\" BASIS,\n"
                   "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
                   "See the License for the specific language governing permissions and\n"
                   "limitations under the License.\n";

        case 3:
            return "GNU GENERAL PUBLIC LICENSE Version 3\n\n"
                   "Copyright (C) 2025 " + project_name_ + "\n\n"
                   "This program is free software: you can redistribute it and/or modify\n"
                   "it under the terms of the GNU General Public License as published by\n"
                   "the Free Software Foundation, either version 3 of the License, or\n"
                   "(at your option) any later version.\n\n"
                   "This program is distributed in the hope that it will be useful,\n"
                   "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                   "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"
                   "GNU General Public License for more details.\n\n"
                   "You should have received a copy of the GNU General Public License\n"
                   "along with this program. If not, see <https://www.gnu.org/licenses/>.\n";

        default:
            return "";
        }
    }

    int ProjectCreator::SelectLicenseInteractively()
    {
        int choice_ = 0;
        while (choice_ < 1 || choice_ > 3)
        {
            ConsoleColor::SetBlue();
            std::cout << "\nSelect a license:\n";
            ConsoleColor::Reset();

            std::cout << "1. MIT License\n";
            std::cout << "2. Apache License 2.0\n";
            std::cout << "3. GNU General Public License v3.0\n";
            std::cout << "Your choice (1-3): ";

            std::cin >> choice_;
            if (std::cin.fail() || choice_ < 1 || choice_ > 3)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                ConsoleColor::SetRed();
                std::cout << "Incorrect input. Try again.\n";
                ConsoleColor::Reset();
                choice_ = 0;
            }
        }

        return choice_;
    }

    bool ProjectCreator::CreateProjectFiles(int license_choice_a)
    {
        fs::path main_cpp_     = project_dir_ / "Sources" / "Main.cpp";
        fs::path license_file_ = project_dir_ / "LICENSE";
        fs::path project_file_ = project_dir_ / "Oriol.ol";
        fs::path readme_file_  = project_dir_ / "Readme.md";

        std::string main_content_ = 
R"(#include <API/API.hpp>
#include <API/Aid/Debug/LogMessage.hpp>

using namespace OL;

OLMain()
{
    LogMessage::Print(TM::INFO, "Hello, Oriol Engine!");
    DOPE 0;
}
)";

        std::string project_file_content_ = 
R"(@Info
{
    name: )" + project_name_ + R"(
    description: "Game on Oriol Engine"
    version: 1.0.0
    engine_v: 0.0.1
}

@Paths
{
    assets: "Assets"
    build: "Build"
    sources: "Sources"
})";

        std::string readme_content_ = 
R"(# )" + project_name_ + R"(

## Description
Oriol Engine Project

## Start
- ``cd Build``
- ``ol -s .``

## Build
- ``cd Build``
- ``ol -b``)";

        std::string license_text_ = _GetLicenseText(license_choice_a);

        return _CreateFile(main_cpp_, main_content_)
               && _CreateFile(license_file_, license_text_)
               && _CreateFile(project_file_, project_file_content_)
               && _CreateFile(readme_file_, readme_content_);
    }

    void ProjectCreator::ShowProjectStructure() const
    {
        std::cout << project_name_ << "/\n";
        std::cout << "├── Assets/\n";
        std::cout << "├── Build/\n";
        std::cout << "├── Sources/\n";
        std::cout << "│   └── Main.cpp\n";
        std::cout << "├── LICENSE\n";
        std::cout << "├── " << project_name_ << ".ol\n";
        std::cout << "└── Readme.md\n";
    }
} // namespace Oriol_Dev
