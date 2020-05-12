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
/// Enum ObserverMode
/// </summary>
enum class ObserverMode {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	ChaseLocked,

	/// <summary>
	/// </summary>
	ChaseFree,

	/// <summary>
	/// </summary>
	Roaming,

	/// <summary>
	/// </summary>
	InEye,

	/// <summary>
	/// </summary>
	MapFree,

	/// <summary>
	/// </summary>
	MapChase
};
