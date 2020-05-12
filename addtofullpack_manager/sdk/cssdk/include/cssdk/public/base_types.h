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
/// </summary>
using vec_t = float;

/// <summary>
/// </summary>
using qboolean = int;

/// <summary>
/// </summary>
using byte = unsigned char;

/// <summary>
/// </summary>
using crc32 = unsigned int;

/// <summary>
/// <para>Byte offset of an <c>Edict</c> in the engine's list of entities.<br/>
/// More explicit than <c>int</c>.</para>
/// </summary>
using eoffset = int;

/// <summary>
/// Struct Color24
/// </summary>
struct Color24 {
	/// <summary>
	/// </summary>
	byte red{};

	/// <summary>
	/// </summary>
	byte green{};

	/// <summary>
	/// </summary>
	byte blue{};
};

/// <summary>
/// Struct ColorVec
/// </summary>
struct ColorVec {
	/// <summary>
	/// </summary>
	unsigned red{};

	/// <summary>
	/// </summary>
	unsigned green{};

	/// <summary>
	/// </summary>
	unsigned blue{};

	/// <summary>
	/// </summary>
	unsigned alpha{};
};

/// <summary>
/// Struct HudTextParams
/// </summary>
struct HudTextParams {
	/// <summary>
	/// </summary>
	float x{};

	/// <summary>
	/// </summary>
	float y{};

	/// <summary>
	/// </summary>
	int effect{};

	/// <summary>
	/// </summary>
	byte r1{}, g1{}, b1{}, a1{};

	/// <summary>
	/// </summary>
	byte r2{}, g2{}, b2{}, a2{};

	/// <summary>
	/// </summary>
	float fade_in_time{};

	/// <summary>
	/// </summary>
	float fade_out_time{};

	/// <summary>
	/// </summary>
	float hold_time{};

	/// <summary>
	/// </summary>
	float fx_time{};

	/// <summary>
	/// </summary>
	int channel{};
};
