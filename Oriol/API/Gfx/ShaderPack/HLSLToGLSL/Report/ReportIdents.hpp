// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_REPORTIDENTS_HPP
#define OL_REPORTIDENTS_HPP

#include "../JoinString.hpp"

namespace OL
{
#define DECL_REPORT(NAME, VALUE)                                               \
    static const OL::JoinableString R_##NAME                                   \
    {                                                                          \
        VALUE                                                                  \
    }

#include "ReportIdentsEN.hpp"

#undef DECL_REPORT
} // namespace OL
#endif
