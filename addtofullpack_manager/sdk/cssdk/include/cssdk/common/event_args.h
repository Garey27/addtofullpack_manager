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
/// <para>Event was invoked with stated origin.</para>
/// </summary>
constexpr auto FEVENT_ORIGIN = 1 << 0;

/// <summary>
/// <para>Event was invoked with stated angles.</para>
/// </summary>
constexpr auto FEVENT_ANGLES = 1 << 1;

/// <summary>
/// Struct EventArgs
/// </summary>
struct EventArgs {
	/// <summary>
	/// </summary>
	int flags{};

	/// <summary>
	/// <para>Transmitted.</para>
	/// </summary>
	int entity_index{};

	/// <summary>
	/// </summary>
	Vector origin;

	/// <summary>
	/// </summary>
	Vector angles;

	/// <summary>
	/// </summary>
	Vector velocity;

	/// <summary>
	/// </summary>
	qboolean ducking{};

	/// <summary>
	/// </summary>
	float f_param1{};

	/// <summary>
	/// </summary>
	float f_param2{};

	/// <summary>
	/// </summary>
	int i_param1{};

	/// <summary>
	/// </summary>
	int i_param2{};

	/// <summary>
	/// </summary>
	qboolean b_param1{};

	/// <summary>
	/// </summary>
	qboolean b_param2{};
};
