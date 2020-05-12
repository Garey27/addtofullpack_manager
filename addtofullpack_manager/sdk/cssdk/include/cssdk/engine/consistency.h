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
#include <cssdk/public/vector.h>

/// <summary>
/// </summary>
constexpr auto MAX_CONSISTENCY_LIST = 512;

/// <summary>
/// Struct Consistency
/// </summary>
struct Consistency {
	/// <summary>
	/// </summary>
	char* file_name{};

	/// <summary>
	/// </summary>
	qboolean is_sound{};

	/// <summary>
	/// </summary>
	int orig_index{};

	/// <summary>
	/// </summary>
	int value{};

	/// <summary>
	/// </summary>
	int check_type{};

	/// <summary>
	/// </summary>
	Vector min_size;

	/// <summary>
	/// </summary>
	Vector max_size;
};
