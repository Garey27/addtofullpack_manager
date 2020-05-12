// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/monsters.h>
#include <cssdk/engine/edict.h>
#include <cssdk/public/base_types.h>
#include <cssdk/public/vector.h>

/// <summary>
/// Struct Plane
/// </summary>
struct Plane {
	/// <summary>
	/// </summary>
	Vector normal;

	/// <summary>
	/// </summary>
	float dist{};
};

/// <summary>
/// Struct Trace
/// </summary>
struct Trace {
	/// <summary>
	/// <para>if true, plane is not valid.</para>
	/// </summary>
	qboolean all_solid{};

	/// <summary>
	/// <para>if true, the initial point was in a solid area.</para>
	/// </summary>
	qboolean start_solid{};

	/// <summary>
	/// <para>.</para>
	/// </summary>
	qboolean in_open{};

	/// <summary>
	/// <para>.</para>
	/// </summary>
	qboolean in_water{};

	/// <summary>
	/// <para>time completed, 1.0 = didn't hit anything.</para>
	/// </summary>
	float fraction{};

	/// <summary>
	/// <para>final position.</para>
	/// </summary>
	Vector end_pos;

	/// <summary>
	/// <para>surface normal at impact.</para>
	/// </summary>
	Plane plane;

	/// <summary>
	/// <para>entity the surface is on.</para>
	/// </summary>
	Edict* entity{};

	/// <summary>
	/// <para>Hit specific body part.</para>
	/// </summary>
	HitBoxGroup hit_group{};
};
