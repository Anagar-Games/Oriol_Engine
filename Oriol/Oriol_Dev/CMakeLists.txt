set(Options
	Options/Options.hpp
	Options/Options.cpp) 
	
set(ProjectCreator
ProjectCreator/ProjectCreator.cpp
ProjectCreator/ProjectCreator.hpp
ProjectCreator/ConsoleColor.cpp
ProjectCreator/ConsoleColor.hpp)

set(SRC
	${Options}
	${ProjectCreator}
    Oriol_Dev.cpp
    )

source_group(" " FILES ${SRC})

add_executable(ol ${SRC})

# Устанавливаем путь вывода исполняемого файла
set_target_properties(ol PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Oriol_Dev"
)