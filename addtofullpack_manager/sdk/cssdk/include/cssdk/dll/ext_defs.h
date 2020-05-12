// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/base_types.h>
#include <cssdk/public/strind.h>

#undef DLLEXPORT
#undef NOINLINE

#ifdef _WIN32
// Attributes to specify an "exported" function, visible from outside the DLL.
#define DLLEXPORT __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#define NOINLINE __declspec(noinline)  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define DLLEXPORT __attribute__ ((visibility ("default"), externally_visible))
#define WINAPI
#define NOINLINE __attribute__((noinline))
#endif // _WIN32

// Manual branch optimization for GCC 3.0.0 and newer
#if !defined(__GNUC__) || __GNUC__ < 3
#define LIKELY(x) (x)  // NOLINT(cppcoreguidelines-macro-usage)
#define UNLIKELY(x) (x)  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#endif

/// <summary>
/// Enum HashType
/// </summary>
enum class HashType {
	/// <summary>
	/// </summary>
	ClassName = 0
};

/// <summary>
/// Enum ToggleState
/// </summary>
enum class ToggleState {
	/// <summary>
	/// </summary>
	AtTop = 0,

	/// <summary>
	/// </summary>
	AtBottom,

	/// <summary>
	/// </summary>
	GoingUp,

	/// <summary>
	/// </summary>
	GoingDown
};

/// <summary>
/// Enum UseType
/// </summary>
enum class UseType {
	/// <summary>
	/// </summary>
	UseOff = 0,

	/// <summary>
	/// </summary>
	UseOn,

	/// <summary>
	/// </summary>
	UseSet,

	/// <summary>
	/// </summary>
	UseToggle
};

/// <summary>
/// Struct LockSound
/// </summary>
struct LockSound {
	/// <summary>
	/// </summary>
	Strind locked_sound;

	/// <summary>
	/// </summary>
	Strind locked_sentence;

	/// <summary>
	/// </summary>
	Strind unlocked_sound;

	/// <summary>
	/// </summary>
	Strind unlocked_sentence;

	/// <summary>
	/// </summary>
	int locked_sentence_i{};

	/// <summary>
	/// </summary>
	int unlocked_sentence_i{};

	/// <summary>
	/// </summary>
	float wait_sound{};

	/// <summary>
	/// </summary>
	float wait_sentence{};

	/// <summary>
	/// </summary>
	byte eof_locked{};

	/// <summary>
	/// </summary>
	byte eof_unlocked{};
};
