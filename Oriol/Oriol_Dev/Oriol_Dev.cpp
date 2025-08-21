#include "Options/Options.hpp"
#include "ProjectCreator/ProjectCreator.hpp"
#include "ProjectCreator/ConsoleColor.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RU-ru");
    CUtils::Options options(argc, argv);
    options.AddOption("-c", "Создать новый проект");
    options.AddOption("-h", "Показать справку");

    if (argc == 1 || options.IsOptionSet("-h")) {
        ConsoleColor::setBlue();
        std::cout << "OL Project Manager - инструмент для создания проектов\n\n";
        ConsoleColor::reset();
        options.PrintHelp();
        return 0;
    }

    if (options.IsOptionSet("-c")) {
        std::string projectName = options.GetOptionValue("-c");
        if (projectName.empty()) {
            ConsoleColor::setRed();
            std::cerr << "Ошибка: не указано имя проекта\n";
            ConsoleColor::reset();
            return 1;
        }

        ProjectCreator creator(projectName);
        
        ConsoleColor::setYellow();
        std::cout << "Создание проекта '" << projectName << "'...\n";
        ConsoleColor::reset();

        if (!creator.createProjectStructure()) {
            return 1;
        }

        int licenseChoice = creator.selectLicenseInteractively();

        if (!creator.createProjectFiles(licenseChoice)) {
            ConsoleColor::setRed();
            std::cerr << "Ошибка при создании файлов проекта!\n";
            ConsoleColor::reset();
            return 1;
        }

        ConsoleColor::setGreen();
        std::cout << "\nПроект '" << projectName << "' успешно создан!\n";
        ConsoleColor::reset();

        std::cout << "\nСтруктура проекта:\n";
        creator.showProjectStructure();

        return 0;
    }

    ConsoleColor::setRed();
    std::cerr << "Неизвестная команда. Используйте -h для справки.\n";
    ConsoleColor::reset();
    return 1;
}