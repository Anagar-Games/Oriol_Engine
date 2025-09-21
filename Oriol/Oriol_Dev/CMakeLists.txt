set(Options
	Options/Options.hpp
	Options/Options.cpp)

set(BuildSys
	BuildSys/FPLParser/FPLParser.hpp
	BuildSys/FPLParser/FPLParser.cpp
	BuildSys/MakeFusion/MakeFusion.hpp
	BuildSys/MakeFusion/MakeFusion.cpp
	BuildSys/BuildSys.hpp
	BuildSys/BuildSys.cpp)
	
set(ProjectCreator
ProjectCreator/ProjectCreator.cpp
ProjectCreator/ProjectCreator.hpp
ProjectCreator/ConsoleColor.cpp
ProjectCreator/ConsoleColor.hpp)

set(SRC
	${Options}
	${ProjectCreator}
	${BuildSys}
    Oriol_Dev.cpp
    )

source_group(" " FILES ${SRC})


# Явное указание архитектуры x86-64
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m64")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m64")
set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -m64")


add_executable(ol ${SRC})

if(WIN32)
    add_definitions(-DCONSOLE_APPLICATION)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")
endif()

# Устанавливаем путь вывода исполняемого файла
set_target_properties(ol PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Oriol_Dev"
)

target_link_libraries(ol PUBLIC stdc++fs)