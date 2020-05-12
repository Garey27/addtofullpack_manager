// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/arch_types.h>
#include <cssdk/public/base_types.h>

#ifdef REHLDS_FIXES
/// <summary>
/// </summary>
constexpr auto COM_TOKEN_LEN = 2048;
#else
/// <summary>
/// </summary>
constexpr auto COM_TOKEN_LEN = 1024;
#endif

/// <summary>
/// </summary>
constexpr auto SIZE_BUF_CHECK_OVERFLOW = 0;

/// <summary>
/// </summary>
constexpr auto SIZE_BUF_ALLOW_OVERFLOW = 1 << 0;

/// <summary>
/// </summary>
constexpr auto SIZE_BUF_OVERFLOWED = 1 << 1;

/// <summary>
/// </summary>
constexpr auto MAX_NUM_ARGV_S = 50;

/// <summary>
/// </summary>
constexpr auto NUM_SAFE_ARGV_S = 7;

/// <summary>
/// </summary>
constexpr auto COM_COPY_CHUNK_SIZE = 1024;

/// <summary>
/// </summary>
constexpr auto COM_MAX_CMD_LINE = 256;

/// <summary>
/// Struct SizeBuf
/// </summary>
struct SizeBuf {
	/// <summary>
	/// </summary>
	const char* buffer_name{};

	/// <summary>
	/// </summary>
	uint16 flags{};

	/// <summary>
	/// </summary>
	byte* data{};

	/// <summary>
	/// </summary>
	int max_size{};

	/// <summary>
	/// </summary>
	int current_size{};
};
