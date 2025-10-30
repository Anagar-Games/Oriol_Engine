// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include "Visitor.hpp"
#include <vector>

namespace OL
{
    class Optimizer : private Visitor
    {
    public:
        void Optimize(Program& program_a);

    private:
        void OptimizeStmntList(std::vector<StmntPtr>& stmnts_a);

        void OptimizeExpr(ExprPtr& expr_a);

        bool CanRemoveStmnt(const Stmnt& ast_a) const;

        DECL_VISIT_PROC(CodeBlock);
        DECL_VISIT_PROC(SwitchCase);
        DECL_VISIT_PROC(ArrayDimension);

        DECL_VISIT_PROC(VarDecl);

        DECL_VISIT_PROC(ForLoopStmnt);
        DECL_VISIT_PROC(WhileLoopStmnt);
        DECL_VISIT_PROC(DoWhileLoopStmnt);
        DECL_VISIT_PROC(IfStmnt);
        DECL_VISIT_PROC(ElseStmnt);
        DECL_VISIT_PROC(SwitchStmnt);
        DECL_VISIT_PROC(ExprStmnt);
        DECL_VISIT_PROC(ReturnStmnt);

        DECL_VISIT_PROC(SequenceExpr);
        DECL_VISIT_PROC(TernaryExpr);
        DECL_VISIT_PROC(BinaryExpr);
        DECL_VISIT_PROC(UnaryExpr);
        DECL_VISIT_PROC(PostUnaryExpr);
        DECL_VISIT_PROC(BracketExpr);
        DECL_VISIT_PROC(ObjectExpr);
        DECL_VISIT_PROC(AssignExpr);
        DECL_VISIT_PROC(ArrayExpr);
        DECL_VISIT_PROC(CastExpr);
        DECL_VISIT_PROC(InitializerExpr);
    };
} // namespace OL
#endif
