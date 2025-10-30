// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef STRUCTPARAMETERANALYZER_HPP
#define STRUCTPARAMETERANALYZER_HPP

#include "../../Targets.hpp"
#include "VisitorTracker.hpp"

#include <set>

namespace OL
{
    class StructParameterAnalyzer : private VisitorTracker
    {
    public:
        void MarkStructsFromEntryPoint(Program& program_a,
                                       const ShaderTarget shader_target_a);

    private:
        bool NotVisited(const AST* ast_a);

        void VisitStmntList(const std::vector<StmntPtr>& stmnts_a);

        bool IsVariableAnEntryPointParameter(VarDeclStmnt* var_a) const;
        bool IsActiveFunctionDeclEntryPoint() const;

        DECL_VISIT_PROC(CodeBlock);
        DECL_VISIT_PROC(SwitchCase);
        DECL_VISIT_PROC(TypeSpecifier);

        DECL_VISIT_PROC(VarDecl);
        DECL_VISIT_PROC(StructDecl);
        DECL_VISIT_PROC(BufferDecl);

        DECL_VISIT_PROC(FunctionDecl);
        DECL_VISIT_PROC(UniformBufferDecl);
        DECL_VISIT_PROC(BufferDeclStmnt);

        DECL_VISIT_PROC(CallExpr);
        DECL_VISIT_PROC(ObjectExpr);

    private:
        Program* program_ = nullptr;
        ShaderTarget shader_target_ = ShaderTarget::VertexShader;

        std::set<const AST*> visit_set_;
    };
} // namespace OL
#endif
