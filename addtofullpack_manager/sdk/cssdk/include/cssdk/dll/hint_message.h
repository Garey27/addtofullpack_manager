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
/// </summary>
constexpr auto DHF_ROUND_STARTED = 1 << 1;

/// <summary>
/// </summary>
constexpr auto DHF_HOSTAGE_SEEN_FAR = 1 << 2;

/// <summary>
/// </summary>
constexpr auto DHF_HOSTAGE_SEEN_NEAR = 1 << 3;

/// <summary>
/// </summary>
constexpr auto DHF_HOSTAGE_USED = 1 << 4;

/// <summary>
/// </summary>
constexpr auto DHF_HOSTAGE_INJURED = 1 << 5;

/// <summary>
/// </summary>
constexpr auto DHF_HOSTAGE_KILLED = 1 << 6;

/// <summary>
/// </summary>
constexpr auto DHF_FRIEND_SEEN = 1 << 7;

/// <summary>
/// </summary>
constexpr auto DHF_ENEMY_SEEN = 1 << 8;

/// <summary>
/// </summary>
constexpr auto DHF_FRIEND_INJURED = 1 << 9;

/// <summary>
/// </summary>
constexpr auto DHF_FRIEND_KILLED = 1 << 10;

/// <summary>
/// </summary>
constexpr auto DHF_ENEMY_KILLED = 1 << 11;

/// <summary>
/// </summary>
constexpr auto DHF_BOMB_RETRIEVED = 1 << 12;

/// <summary>
/// </summary>
constexpr auto DHF_AMMO_EXHAUSTED = 1 << 15;

/// <summary>
/// </summary>
constexpr auto DHF_IN_TARGET_ZONE = 1 << 16;

/// <summary>
/// </summary>
constexpr auto DHF_IN_RESCUE_ZONE = 1 << 17;

/// <summary>
/// </summary>
constexpr auto DHF_IN_ESCAPE_ZONE = 1 << 18;

/// <summary>
/// </summary>
constexpr auto DHF_IN_VIP_SAFETY_ZONE = 1 << 19;

/// <summary>
/// </summary>
constexpr auto DHF_NIGHT_VISION = 1 << 20;

/// <summary>
/// </summary>
constexpr auto DHF_HOSTAGE_CT_MOVE = 1 << 21;

/// <summary>
/// </summary>
constexpr auto DHF_SPEC_DUCK = 1 << 22;

/// <summary>
/// </summary>
constexpr auto DHM_ROUND_CLEAR = DHF_ROUND_STARTED | DHF_HOSTAGE_KILLED | DHF_FRIEND_KILLED | DHF_BOMB_RETRIEVED;

/// <summary>
/// </summary>
constexpr auto DHM_CONNECT_CLEAR = DHF_HOSTAGE_SEEN_FAR | DHF_HOSTAGE_SEEN_NEAR | DHF_HOSTAGE_USED | DHF_HOSTAGE_INJURED
	| DHF_FRIEND_SEEN | DHF_ENEMY_SEEN | DHF_FRIEND_INJURED | DHF_ENEMY_KILLED | DHF_AMMO_EXHAUSTED | DHF_IN_TARGET_ZONE
	| DHF_IN_RESCUE_ZONE | DHF_IN_ESCAPE_ZONE | DHF_IN_VIP_SAFETY_ZONE | DHF_HOSTAGE_CT_MOVE | DHF_SPEC_DUCK;

/// <summary>
/// <para>Dummy. DON'T USE THIS!</para>
/// </summary>
using HintMessageQueue = uint8[24];
