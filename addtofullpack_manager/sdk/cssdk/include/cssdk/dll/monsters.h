// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

/// <summary>
/// Enum HitBoxGroup
/// </summary>
enum class HitBoxGroup {
	/// <summary>
	/// </summary>
	Generic = 0,

	/// <summary>
	/// </summary>
	Head,

	/// <summary>
	/// </summary>
	Chest,

	/// <summary>
	/// </summary>
	Stomach,

	/// <summary>
	/// </summary>
	LeftArm,

	/// <summary>
	/// </summary>
	RightArm,

	/// <summary>
	/// </summary>
	LeftLeg,

	/// <summary>
	/// </summary>
	RightLeg,

	/// <summary>
	/// </summary>
	Shield,

	/// <summary>
	/// </summary>
	NumHitGroups
};

/// <summary>
/// Enum MoveTypeNpc
/// </summary>
enum class MoveTypeNpc {
	/// <summary>
	/// <para>Normal move in the direction monster is facing.</para>
	/// </summary>
	Normal = 0,

	/// <summary>
	/// <para>Moves in direction specified, no matter which way monster is facing.</para>
	/// </summary>
	Strafe
};
