// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_HLSLKEYWORDS_HPP
#define OL_HLSLKEYWORDS_HPP

#include "../../AST/ASTEnums.hpp"
#include "../../AST/Token.hpp"

#include <string>

namespace OL
{
    const KeywordMapType& HLSLKeywords();
    const KeywordMapType& HLSLKeywordsExtCg();

    DataType HLSLKeywordToDataType(const std::string& keyword_a);
    DataType HLSLKeywordExtCgToDataType(const std::string& keyword_a);

    PrimitiveType HLSLKeywordToPrimitiveType(const std::string& keyword_a);

    StorageClass HLSLKeywordToStorageClass(const std::string& keyword_a);
    InterpModifier HLSLKeywordToInterpModifier(const std::string& keyword_a);

    TypeModifier HLSLKeywordToTypeModifier(const std::string& keyword_a);
    UniformBufferType HLSLKeywordToUniformBufferType(
            const std::string& keyword_a);

    BufferType HLSLKeywordToBufferType(const std::string& keyword_a);
    SamplerType HLSLKeywordToSamplerType(const std::string& keyword_a);
    const std::string* AttributeTypeToHLSLKeyword(const AttributeType t_a);

    AttributeType HLSLKeywordToAttributeType(const std::string& keyword_a);
    AttributeValue HLSLKeywordToAttributeValue(const std::string& keyword_a);

    IndexedSemantic HLSLKeywordToSemantic(const std::string& ident_a,
                                          bool use_d3d10_semantics_a = true);
} // namespace OL

#endif
