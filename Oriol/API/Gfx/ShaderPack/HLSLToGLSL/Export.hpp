// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_EXPORT_HPP
#define OL_EXPORT_HPP

#if defined(_MSC_VER) && defined(HTG_SHARED_LIB)
#   define HTG_EXPORT __declspec(dllexport)
#else
#   define HTG_EXPORT
#endif

#endif
