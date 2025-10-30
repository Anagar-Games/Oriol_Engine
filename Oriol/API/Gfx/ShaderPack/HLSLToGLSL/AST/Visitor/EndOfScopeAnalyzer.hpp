// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef ENDOFSCOPEANALYZER_HPP
#define ENDOFSCOPEANALYZER_HPP

#include "../../SymbolTable.hpp"
#include "../Token.hpp"
#include "Visitor.hpp"

namespace OL
{
    class EndOfScopeAnalyzer : private Visitor
    {
    public:
        void MarkEndOfScopesFromFunction(FunctionDecl& func_decl_a);

    private:
        DECL_VISIT_PROC(CodeBlock);

        DECL_VISIT_PROC(ForLoopStmnt);
        DECL_VISIT_PROC(WhileLoopStmnt);
        DECL_VISIT_PROC(DoWhileLoopStmnt);
        DECL_VISIT_PROC(IfStmnt);
        DECL_VISIT_PROC(SwitchStmnt);
        DECL_VISIT_PROC(ExprStmnt);
        DECL_VISIT_PROC(ReturnStmnt);
        DECL_VISIT_PROC(CtrlTransferStmnt);
    };
} // namespace OL
#endif
