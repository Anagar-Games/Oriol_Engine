set (DateTime
	 Aid/DateTime/DateTime.cpp
 	 Aid/DateTime/DateTime.hpp)

set (Debug
	 Aid/Debug/LogMessage.cpp
 	 Aid/Debug/LogMessage.hpp)

set (Filesystem
	 Aid/Filesystem/Filesystem.cpp
 	 Aid/Filesystem/Filesystem.hpp)

set (InfoSys
	 Aid/InfoSys/InfoSys.cpp
 	 Aid/InfoSys/InfoSys.hpp)

set (INI
	 Aid/INI/INIParser.cpp
 	 Aid/INI/INIParser.hpp)

set (JSON
	 Aid/JSON/JSONParser.cpp
 	 Aid/JSON/JSONParser.hpp)

set (Plugins
	 Aid/Plugins/Plugins.cpp
 	 Aid/Plugins/Plugins.hpp)

set (Random
	 Aid/Random/Random.cpp
 	 Aid/Random/Random.hpp)

set (Res
	 Aid/Res/Res.cpp
 	 Aid/Res/Res.hpp)

set (RTTI
	 Aid/RTTI/RTTI.cpp
 	 Aid/RTTI/RTTI.hpp)

set (Singleton
	 Aid/Singleton/Singleton.cpp
 	 Aid/Singleton/Singleton.hpp)

set (StringHelper
	 Aid/StringHelper/StringHelper.cpp
 	 Aid/StringHelper/StringHelper.hpp)

set (Timer
	 Aid/Timer/Timer.cpp
 	 Aid/Timer/Timer.hpp)

set (TypeToType
	 Aid/TypeToType/TypeToType.cpp
 	 Aid/TypeToType/TypeToType.hpp)

set (UnitTests
	 Aid/UnitTests/UnitTests.cpp
 	 Aid/UnitTests/UnitTests.hpp)

set(Aid
    ${DateTime}
	${Debug}
	${Filesystem}
	${InfoSys}
	${INI}
	${JSON}
	${Plugins}
	${Random}
	${Res}
	${RTTI}
	${Singleton}
	${StringHelper}
	${Timer}
	${TypeToType}
	${UnitTests})

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
