// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif !defined(WINAPI)
#define WINAPI
#endif

#if defined _WIN32
#define DLLEXPORT __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define DLLEXPORT __attribute__ ((visibility ("default"), externally_visible))
#endif

#ifdef _WIN32
#define NOINLINE __declspec(noinline)  // NOLINT(cppcoreguidelines-macro-usage)
#define FASTCALL __fastcall  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define NOINLINE __attribute__ ((noinline))
#define FASTCALL
#endif
