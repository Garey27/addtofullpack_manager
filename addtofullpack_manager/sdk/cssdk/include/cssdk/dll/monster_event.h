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
constexpr auto EVENT_SPECIFIC = 0;

/// <summary>
/// </summary>
constexpr auto EVENT_SCRIPTED = 1000;

/// <summary>
/// </summary>
constexpr auto EVENT_SHARED = 2000;

/// <summary>
/// </summary>
constexpr auto EVENT_CLIENT = 5000;

/// <summary>
/// </summary>
constexpr auto MONSTER_EVENT_BODY_DROP_LIGHT = 2001;

/// <summary>
/// </summary>
constexpr auto MONSTER_EVENT_BODY_DROP_HEAVY = 2002;

/// <summary>
/// </summary>
constexpr auto MONSTER_EVENT_SWISH_SOUND = 2010;

/// <summary>
/// Struct MonsterEvent
/// </summary>
struct MonsterEvent {
	/// <summary>
	/// </summary>
	int event{};

	/// <summary>
	/// </summary>
	char* options{};
};
