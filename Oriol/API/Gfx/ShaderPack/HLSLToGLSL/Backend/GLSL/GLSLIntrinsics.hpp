// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef GLSLINTRINSICS_HPP
#define GLSLINTRINSICS_HPP

#include "../../AST/ASTEnums.hpp"
#include "../../AST/Token.hpp"

#include <string>

namespace OL
{
    const std::string* IntrinsicToGLSLKeyword(const Intrinsic intr_a,
                                              bool use_glsl_120_a = false);
} // namespace OL
#endif
