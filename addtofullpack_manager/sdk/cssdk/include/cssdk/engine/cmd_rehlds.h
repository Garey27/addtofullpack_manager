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
constexpr auto FCMD_HUD_COMMAND = 1 << 0;

/// <summary>
/// </summary>
constexpr auto FCMD_GAME_COMMAND = 1 << 1;

/// <summary>
/// </summary>
constexpr auto FCMD_WRAPPER_COMMAND = 1 << 2;

/// <summary>
/// Enum CmdSource
/// </summary>
enum class CmdSource {
	/// <summary>
	/// <para>Came in over a net connection as a clc_stringcmd. host_client will be valid during this state.</para>
	/// </summary>
	Client = 0,

	/// <summary>
	/// <para>From the command buffer.</para>
	/// </summary>
	Command
};

/// <summary>
/// </summary>
using XCommand = void(*)();

/// <summary>
/// Struct CmdFunction
/// </summary>
struct CmdFunction {
	/// <summary>
	/// </summary>
	CmdFunction* next{};

	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	XCommand function{};

	/// <summary>
	/// </summary>
	int flags{};
};
