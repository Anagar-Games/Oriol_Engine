// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_GLSLPREPROCESSOR_HPP
#define OL_GLSLPREPROCESSOR_HPP

#include "../PreProcessor.hpp"

namespace OL
{
    class GLSLPreProcessor : public PreProcessor
    {
    public:
        GLSLPreProcessor(IncludeHandler& include_handler_a,
                         Log* log_a = nullptr);

    private:
        bool OnDefineMacro(const Macro& macro_a) override;
        bool OnRedefineMacro(const Macro& macro_a,
                             const Macro& previous_macro_a) override;

        bool OnUndefineMacro(const Macro& macro_a) override;
        bool OnSubstitueStdMacro(const Token& ident_tkn_a,
                                 TokenPtrString& token_string_a) override;

        void ParseDirective(const std::string& directive_a,
                            bool ignore_unknown_a) override;

        void ParseDirectiveVersion();
        void ParseDirectiveExtension();

        bool VerifyVersionNo(const int* valid_versions_a) const;

    private:
        bool version_defined_ = false;
        int version_no_ = 0;
    };
} // namespace OL
#endif
