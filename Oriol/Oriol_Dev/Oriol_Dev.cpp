#include "Options/Options.hpp"
#include "ProjectCreator/ConsoleColor.hpp"
#include "ProjectCreator/ProjectCreator.hpp"
#include "BuildSys/BuildSys.hpp"

#include <iostream>

int main(int argc_a, char* argv_a[])
{
    Oriol_Dev::Options options_(argc_a, argv_a);
    options_.AddOption("-c", "Create New Project");
    options_.AddOption("-h", "Auxiliary Help");
    options_.AddOption("-b", "Build Project");

    if (argc_a == 1 || options_.IsOptionSet("-h"))
    {
        options_.PrintHelp();
        
        return 0;
    }

    if (options_.IsOptionSet("-c"))
    {
        std::string project_name_ = options_.GetOptionValue("-c");
        if (project_name_.empty())
        {
            Oriol_Dev::ConsoleColor::SetRed();
            std::cerr << "Specify the project name!\n";
            Oriol_Dev::ConsoleColor::Reset();
            
            return 1;
        }

        Oriol_Dev::ProjectCreator creator_(project_name_);

        if (!creator_.CreateProjectStructure())
        {
            return 1;
        }

        int license_choice_ = creator_.SelectLicenseInteractively();

        if (!creator_.CreateProjectFiles(license_choice_))
        {
            Oriol_Dev::ConsoleColor::SetRed();
            std::cerr << "Error when creating project files!\n";
            Oriol_Dev::ConsoleColor::Reset();
            
            return 1;
        }

        Oriol_Dev::ConsoleColor::SetGreen();
        std::cout << "\nThe project '" << project_name_ << "' was successfully created!\n";
        std::cout << "\nHappy GameDev!";
        Oriol_Dev::ConsoleColor::Reset();

        return 0;
    }

    if (options_.IsOptionSet("-b"))
    {
        if (Oriol_Dev::BuildSys::StartBuild())
        {
            Oriol_Dev::ConsoleColor::SetGreen();
            std::cout << "\nBuild Successful!";
            Oriol_Dev::ConsoleColor::Reset();    
        }
        else
        {
            Oriol_Dev::ConsoleColor::SetRed();
            std::cerr << "\nError when Build project!";
            Oriol_Dev::ConsoleColor::Reset();
        }

        return 0;
    }

    Oriol_Dev::ConsoleColor::SetRed();
    std::cerr << "Unknown command, run -h for help.\n";
    Oriol_Dev::ConsoleColor::Reset();
    return 1;
}
