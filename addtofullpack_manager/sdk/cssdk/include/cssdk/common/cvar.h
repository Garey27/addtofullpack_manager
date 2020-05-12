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
/// <para>Set to cause it to be saved to vars.rc.</para>
/// </summary>
constexpr auto FCVAR_ARCHIVE = 1 << 0;

/// <summary>
/// <para>Changes the client's info string.</para>
/// </summary>
constexpr auto FCVAR_USER_INFO = 1 << 1;

/// <summary>
/// <para>Notifies players when changed.</para>
/// </summary>
constexpr auto FCVAR_SERVER = 1 << 2;

/// <summary>
/// <para>Defined by external DLL.</para>
/// </summary>
constexpr auto FCVAR_EXT_DLL = 1 << 3;

/// <summary>
/// <para>Defined by the client dll.</para>
/// </summary>
constexpr auto FCVAR_CLIENT_DLL = 1 << 4;

/// <summary>
/// <para>It's a server cvar, but we don't send the data since it's a password, etc.<br/>
/// Sends 1 if it's not bland/zero, 0 otherwise as value.</para>
/// </summary>
constexpr auto FCVAR_PROTECTED = 1 << 5;

/// <summary>
/// <para>This cvar cannot be changed by clients connected to a multiplayer server.</para>
/// </summary>
constexpr auto FCVAR_SP_ONLY = 1 << 6;

/// <summary>
/// <para>This cvar's string cannot contain unprintable characters (e.g., used for player name etc).</para>
/// </summary>
constexpr auto FCVAR_PRINTABLE_ONLY = 1 << 7;

/// <summary>
/// <para>If this is a FCVAR_SERVER, don't log changes to the log file / console if we are creating a log.</para>
/// </summary>
constexpr auto FCVAR_UNLOGGED = 1 << 8;

/// <summary>
/// <para>Strip trailing/leading whitespace from this cvar.</para>
/// </summary>
constexpr auto FCVAR_NO_EXTRA_WHITESPACE = 1 << 9;

/// <summary>
/// Struct CVar
/// </summary>
struct CVar {
	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	const char* string{};

	/// <summary>
	/// </summary>
	int flags{};

	/// <summary>
	/// </summary>
	float value{};

	/// <summary>
	/// </summary>
	CVar* next{};
};

/// <summary>
/// </summary>
using CVarCallback = void (*)(const char* new_value);

/// <summary>
/// Struct CVarListener
/// </summary>
struct CVarListener {
	/// <summary>
	/// </summary>
	CVarListener(const char* var_name, const CVarCallback handler) : func(handler), name(var_name)
	{
	}

	/// <summary>
	/// </summary>
	CVarCallback func{};

	/// <summary>
	/// </summary>
	const char* name{};
};
