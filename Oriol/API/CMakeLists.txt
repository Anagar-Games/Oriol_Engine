set(Aid
    Aid/Debug/LogMessage.hpp
    Aid/Debug/LogMessage.cpp)

set(Gfx
    Gfx/Window/Window.cpp
    Gfx/Window/Window.hpp)

source_group("Gfx/Window" FILES ${Gfx})

add_library(Oriol_Engine STATIC ${Gfx} ${Aid})

# Устанавливаем пути вывода библиотеки
set_target_properties(Oriol_Engine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
)