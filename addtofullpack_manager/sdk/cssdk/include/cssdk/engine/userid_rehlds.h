// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/arch_types.h>

/// <summary>
/// <para>Authentication types.</para>
/// </summary>
enum class AuthIdType {
	/// <summary>
	/// </summary>
	Unknown = 0,

	/// <summary>
	/// </summary>
	Steam,

	/// <summary>
	/// </summary>
	Valve,

	/// <summary>
	/// </summary>
	Local
};

/// <summary>
/// Struct UserId
/// </summary>
struct UserId {
	/// <summary>
	/// </summary>
	AuthIdType id_type{};

	/// <summary>
	/// </summary>
	uint64 steam_id{};

	/// <summary>
	/// </summary>
	unsigned int client_ip{};
};
