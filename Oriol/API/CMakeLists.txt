#================AID-MODULE================

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

#================GFX-MODULE================

set(ShaderPack_HTG_AST_Visitor
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ASTPrinter.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ASTPrinter.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ControlPathAnalyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ControlPathAnalyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/EndOfScopeAnalyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/EndOfScopeAnalyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ExprConverter.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ExprConverter.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ExprEvaluator.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ExprEvaluator.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/FuncNameConverter.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/FuncNameConverter.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/Optimizer.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/Optimizer.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ReferenceAnalyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ReferenceAnalyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ReflectionAnalyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/ReflectionAnalyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/StructParameterAnalyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/StructParameterAnalyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/TypeConverter.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/TypeConverter.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/UniformPacker.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/UniformPacker.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/Visitor.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/Visitor.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/VisitorTracker.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Visitor/VisitorTracker.hpp)

set(ShaderPack_HTG_AST
	Gfx/ShaderPack/HLSLToGLSL/AST/AST.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/AST.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/ASTEnums.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/ASTEnums.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/ASTFactory.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/ASTFactory.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Identifier.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Identifier.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/SourceArea.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/SourceArea.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/SourcePosition.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/SourcePosition.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Token.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/Token.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/TokenString.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/TokenString.hpp
	Gfx/ShaderPack/HLSLToGLSL/AST/TypeDenoter.cpp
	Gfx/ShaderPack/HLSLToGLSL/AST/TypeDenoter.hpp)

set(ShaderPack_HTG_Backend_GLSL
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLConverter.cpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLConverter.hpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLExtensionAgent.cpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLExtensionAgent.hpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLGenerator.cpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLGenerator.hpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLIntrinsics.cpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/GLSL/GLSLIntrinsics.hpp)

set(ShaderPack_HTG_Backend
	Gfx/ShaderPack/HLSLToGLSL/Backend/Converter.cpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/Converter.hpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/Generator.cpp
	Gfx/ShaderPack/HLSLToGLSL/Backend/Generator.hpp)

set(ShaderPack_HTG_Frontend_GLSL
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLExtensions.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLExtensions.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLKeywords.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLKeywords.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLParser.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLParser.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLPreProcessor.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLPreProcessor.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLScanner.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/GLSL/GLSLScanner.hpp)

set(ShaderPack_HTG_Frontend_HLSL
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLAnalyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLAnalyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLIntrinsics.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLIntrinsics.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLKeywords.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLKeywords.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLParser.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLParser.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLScanner.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/HLSL/HLSLScanner.hpp)

set(ShaderPack_HTG_Frontend
	Gfx/ShaderPack/HLSLToGLSL/Frontend/Analyzer.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/Analyzer.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/IntrinsicAdept.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/IntrinsicAdept.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/Parser.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/Parser.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/PreProcessor.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/PreProcessor.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/PreProcessorScanner.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/PreProcessorScanner.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/Scanner.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/Scanner.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/SLParser.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/SLParser.hpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/SLScanner.cpp
	Gfx/ShaderPack/HLSLToGLSL/Frontend/SLScanner.hpp)

set(ShaderPack_HTG_Report
	Gfx/ShaderPack/HLSLToGLSL/Report/ReportHandler.cpp
	Gfx/ShaderPack/HLSLToGLSL/Report/ReportHandler.hpp
	Gfx/ShaderPack/HLSLToGLSL/Report/ReportIdents.hpp
	Gfx/ShaderPack/HLSLToGLSL/Report/ReportIdentsEN.hpp)

set(ShaderPack_HTG
	Gfx/ShaderPack/HLSLToGLSL/CiString.hpp
	Gfx/ShaderPack/HLSLToGLSL/CodeWriter.cpp
	Gfx/ShaderPack/HLSLToGLSL/CodeWriter.hpp
	Gfx/ShaderPack/HLSLToGLSL/Compiler.cpp
	Gfx/ShaderPack/HLSLToGLSL/Compiler.hpp
	Gfx/ShaderPack/HLSLToGLSL/ConsoleManip.cpp
	Gfx/ShaderPack/HLSLToGLSL/ConsoleManip.hpp
	Gfx/ShaderPack/HLSLToGLSL/Dictionary.hpp
	Gfx/ShaderPack/HLSLToGLSL/Exception.cpp
	Gfx/ShaderPack/HLSLToGLSL/Exception.hpp
	Gfx/ShaderPack/HLSLToGLSL/Export.hpp
	Gfx/ShaderPack/HLSLToGLSL/Flags.hpp
	Gfx/ShaderPack/HLSLToGLSL/Helper.hpp
	Gfx/ShaderPack/HLSLToGLSL/HTG.cpp
	Gfx/ShaderPack/HLSLToGLSL/HTG.hpp
	Gfx/ShaderPack/HLSLToGLSL/IncludeHandler.cpp
	Gfx/ShaderPack/HLSLToGLSL/IncludeHandler.hpp
	Gfx/ShaderPack/HLSLToGLSL/IndentHandler.cpp
	Gfx/ShaderPack/HLSLToGLSL/IndentHandler.hpp
	Gfx/ShaderPack/HLSLToGLSL/JoinString.cpp
	Gfx/ShaderPack/HLSLToGLSL/JoinString.hpp
	Gfx/ShaderPack/HLSLToGLSL/Log.cpp
	Gfx/ShaderPack/HLSLToGLSL/Log.hpp
	Gfx/ShaderPack/HLSLToGLSL/PlatformConsoleManip.cpp
	Gfx/ShaderPack/HLSLToGLSL/Reflection.cpp
	Gfx/ShaderPack/HLSLToGLSL/Reflection.hpp
	Gfx/ShaderPack/HLSLToGLSL/ReflectionPrinter.cpp
	Gfx/ShaderPack/HLSLToGLSL/ReflectionPrinter.hpp
	Gfx/ShaderPack/HLSLToGLSL/Report.hpp
	Gfx/ShaderPack/HLSLToGLSL/ShaderVersion.cpp
	Gfx/ShaderPack/HLSLToGLSL/ShaderVersion.hpp
	Gfx/ShaderPack/HLSLToGLSL/SourceCode.cpp
	Gfx/ShaderPack/HLSLToGLSL/SourceCode.hpp
	Gfx/ShaderPack/HLSLToGLSL/SymbolTable.cpp
	Gfx/ShaderPack/HLSLToGLSL/SymbolTable.hpp
	Gfx/ShaderPack/HLSLToGLSL/Targets.cpp
	Gfx/ShaderPack/HLSLToGLSL/Targets.hpp
	Gfx/ShaderPack/HLSLToGLSL/Variant.cpp
	Gfx/ShaderPack/HLSLToGLSL/Variant.hpp
	Gfx/ShaderPack/HLSLToGLSL/Version.hpp)

set(ShaderPack
	${ShaderPack_HTG_AST_Visitor}
	${ShaderPack_HTG_AST}
	${ShaderPack_HTG_Backend_GLSL}
	${ShaderPack_HTG_Backend}
	${ShaderPack_HTG_Frontend_GLSL}
	${ShaderPack_HTG_Frontend_HLSL}
	${ShaderPack_HTG_Frontend}
	${ShaderPack_HTG_Report}
	${ShaderPack_HTG}
	Gfx/ShaderPack/ShaderPack.cpp
	Gfx/ShaderPack/ShaderPack.hpp)

set(Gfx
	${ShaderPack}
    Gfx/Window/Window.cpp
    Gfx/Window/Window.hpp)

source_group("Gfx/Window" FILES ${Gfx})

add_library(Oriol_Engine STATIC ${Gfx} ${Aid})

# Устанавливаем пути вывода библиотеки
set_target_properties(Oriol_Engine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
)
