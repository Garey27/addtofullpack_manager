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
/// Enum Decal
/// </summary>
enum class Decal {
	/// <summary>
	/// </summary>
	None = -1,

	/// <summary>
	/// </summary>
	Gunshot1 = 0,

	/// <summary>
	/// </summary>
	Gunshot2,

	/// <summary>
	/// </summary>
	Gunshot3,

	/// <summary>
	/// </summary>
	Gunshot4,

	/// <summary>
	/// </summary>
	Gunshot5,

	/// <summary>
	/// </summary>
	Lambda1,

	/// <summary>
	/// </summary>
	Lambda2,

	/// <summary>
	/// </summary>
	Lambda3,

	/// <summary>
	/// </summary>
	Lambda4,

	/// <summary>
	/// </summary>
	Lambda5,

	/// <summary>
	/// </summary>
	Lambda6,

	/// <summary>
	/// </summary>
	Scorch1,

	/// <summary>
	/// </summary>
	Scorch2,

	/// <summary>
	/// </summary>
	Blood1,

	/// <summary>
	/// </summary>
	Blood2,

	/// <summary>
	/// </summary>
	Blood3,

	/// <summary>
	/// </summary>
	Blood4,

	/// <summary>
	/// </summary>
	Blood5,

	/// <summary>
	/// </summary>
	Blood6,

	/// <summary>
	/// </summary>
	YBlood1,

	/// <summary>
	/// </summary>
	YBlood2,

	/// <summary>
	/// </summary>
	YBlood3,

	/// <summary>
	/// </summary>
	YBlood4,

	/// <summary>
	/// </summary>
	YBlood5,

	/// <summary>
	/// </summary>
	YBlood6,

	/// <summary>
	/// </summary>
	GlassBreak1,

	/// <summary>
	/// </summary>
	GlassBreak2,

	/// <summary>
	/// </summary>
	GlassBreak3,

	/// <summary>
	/// </summary>
	BigShot1,

	/// <summary>
	/// </summary>
	BigShot2,

	/// <summary>
	/// </summary>
	BigShot3,

	/// <summary>
	/// </summary>
	BigShot4,

	/// <summary>
	/// </summary>
	BigShot5,

	/// <summary>
	/// </summary>
	Spit1,

	/// <summary>
	/// </summary>
	Spit2,

	/// <summary>
	/// <para>Bulletproof glass decal.</para>
	/// </summary>
	BProof1,

	/// <summary>
	/// <para>Gargantua stomp crack.</para>
	/// </summary>
	GargStomp1,

	/// <summary>
	/// <para>Small scorch mark.</para>
	/// </summary>
	SmallScorch1,

	/// <summary>
	/// <para>Small scorch mark.</para>
	/// </summary>
	SmallScorch2,

	/// <summary>
	/// <para>Small scorch mark.</para>
	/// </summary>
	SmallScorch3,

	/// <summary>
	/// <para>Big momma birth splatter.</para>
	/// </summary>
	MommaBirth,

	/// <summary>
	/// </summary>
	MommaSplat,

	/// <summary>
	/// </summary>
	End
};

/// <summary>
/// Struct DllDecalList
/// </summary>
struct DllDecalList {
	/// <summary>
	/// </summary>
	char* name{};

	/// <summary>
	/// </summary>
	int index{};
};
