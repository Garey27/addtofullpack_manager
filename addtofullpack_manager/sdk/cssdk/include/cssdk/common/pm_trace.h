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
#include <cssdk/public/base_types.h>
#include <cssdk/public/vector.h>

/// <summary>
/// Struct PmPlane
/// </summary>
struct PmPlane {
	/// <summary>
	/// </summary>
	Vector normal;

	/// <summary>
	/// </summary>
	float dist{};
};

/// <summary>
/// Struct PmTrace
/// </summary>
struct PmTrace {
	/// <summary>
	/// <para>If true, plane is not valid.</para>
	/// </summary>
	qboolean all_solid{};

	/// <summary>
	/// <para>If true, the initial point was in a solid area.</para>
	/// </summary>
	qboolean start_solid{};

	/// <summary>
	/// <para>End point is in empty space.</para>
	/// </summary>
	qboolean in_open{};

	/// <summary>
	/// <para>End point is in empty water.</para>
	/// </summary>
	qboolean in_water{};

	/// <summary>
	/// <para>Time completed, 1.0 = didn't hit anything.</para>
	/// </summary>
	float fraction{};

	/// <summary>
	/// <para>Final position.</para>
	/// </summary>
	Vector end_pos;

	/// <summary>
	/// <para>Surface normal at impact.</para>
	/// </summary>
	PmPlane plane;

	/// <summary>
	/// <para>Entity at impact.</para>
	/// </summary>
	int entity{};

	/// <summary>
	/// <para>Change in player's velocity caused by impact.</para>
	/// </summary>
	Vector delta_velocity;

	/// <summary>
	/// <para>Hit specific body part.</para>
	/// </summary>
	HitBoxGroup hit_group{};
};
