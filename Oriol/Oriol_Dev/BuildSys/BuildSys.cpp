// BuildSys.cpp
#include "BuildSys.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib> // Для getenv
#include <filesystem> // Для работы с путями
#include <algorithm> // Для std::replace

namespace Oriol_Dev
{
    bool BuildSys::StartBuild()
    {
        // Парсим Oriol.ol
        std::ifstream input("Oriol.ol");
        if (!input.is_open())
        {
            std::cerr << "Could not open Oriol.ol" << std::endl;
            return false;
        }

        FPLParser parser;
        auto config = parser.Parse(input);
        input.close();

        // Получаем путь к фреймворку из переменной окружения ORIOL_HOME
        const char* oriolHome = std::getenv("ORIOL_HOME");
        if (!oriolHome) {
            std::cerr << "ORIOL_HOME environment variable is not set!" << std::endl;
            return false;
        }

        // Формируем правильные пути
        std::filesystem::path basePath(oriolHome);
        basePath = basePath.parent_path(); // Убираем имя файла ol.exe из пути

        // Нормализуем пути и заменяем обратные слеши
        std::string libPath = "/mnt/d_drive/Anagar_Games/Techs/Oriol_Engine/Out/bin/API/libOriol_Engine.a";
        std::string includePath = "/mnt/d_drive/Anagar_Games/Techs/Oriol_Engine/Oriol/";
        
       
        // Извлекаем пути из секции Paths
        std::string sourcesDir = "Sources";
        std::string buildDir = "Build";

        if (config.find("Paths") != config.end())
        {
            auto& paths = config.at("Paths");
            if (paths.find("sources") != paths.end())
                sourcesDir = std::get<std::string>(paths.at("sources").data_);
            if (paths.find("build") != paths.end())
                buildDir = std::get<std::string>(paths.at("build").data_);
        }

        // Рекурсивно ищем все .cpp файлы
        std::vector<std::string> sources;
        FindSources(sourcesDir, sources);

        // Настраиваем MakeFusion
        MakeFusion mf;
        mf.SetOutputDirectory(buildDir);
        
        // Устанавливаем имя выходного файла из секции Info
        if (config.find("Info") != config.end())
        {
            auto& info = config.at("Info");
            if (info.find("name") != info.end())
                mf.SetOutputName(std::get<std::string>(info.at("name").data_));
        }

        // Добавляем пути к инклюдам и библиотеке фреймворка
        mf.AddIncludeDir(includePath);
          // Добавляем флаги для x86-64 и консольного приложения
    mf.AddCompilerFlag("-m64");
    mf.AddLinkerFlag("-m64");

    // Добавляем библиотеку фреймворка и стандартную библиотеку C++
    mf.AddLinkerFlag(libPath);
    mf.AddLibrary("stdc++"); // Явно линкуем стандартную библиотеку

        // Добавляем все исходные файлы
        for (const auto& src : sources)
            mf.AddSource(src);

        // Генерируем и запускаем сборку
        if (!mf.Generate())
            return false;

        return mf.Build();
    }

    void BuildSys::FindSources(const std::filesystem::path& path, std::vector<std::string>& sources)
    {
        try
        {
            for (const auto& entry : std::filesystem::recursive_directory_iterator(path))
            {
                if (entry.is_regular_file() && entry.path().extension() == ".cpp")
                    sources.push_back(entry.path().string());
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error finding sources: " << e.what() << std::endl;
        }
    }
}
