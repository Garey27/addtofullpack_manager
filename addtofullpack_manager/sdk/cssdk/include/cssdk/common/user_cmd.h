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
/// Struct UserCmd
/// </summary>
struct UserCmd {
	/// <summary>
	/// </summary>
	short lerp_msec{};

	/// <summary>
	/// </summary>
	byte msec{};

	/// <summary>
	/// </summary>
	Vector view_angles;

	/// <summary>
	/// </summary>
	float forward_move{};

	/// <summary>
	/// </summary>
	float side_move{};

	/// <summary>
	/// </summary>
	float up_move{};

	/// <summary>
	/// </summary>
	byte light_level{};

	/// <summary>
	/// </summary>
	unsigned short buttons{};

	/// <summary>
	/// </summary>
	byte impulse{};

	/// <summary>
	/// </summary>
	byte weapon_select{};

	/// <summary>
	/// </summary>
	int impact_index{};

	/// <summary>
	/// </summary>
	Vector impact_position;
};
