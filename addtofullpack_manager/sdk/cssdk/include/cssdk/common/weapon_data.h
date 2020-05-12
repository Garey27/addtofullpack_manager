// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/base_types.h>

/// <summary>
/// <para>Info about weapons player might have in his/her possession.</para>
/// </summary>
struct WeaponData {
	/// <summary>
	/// </summary>
	int id{};

	/// <summary>
	/// </summary>
	int clip{};

	/// <summary>
	/// </summary>
	float next_primary_attack{};

	/// <summary>
	/// </summary>
	float next_secondary_attack{};

	/// <summary>
	/// </summary>
	float time_weapon_idle{};

	/// <summary>
	/// </summary>
	qboolean in_reload{};

	/// <summary>
	/// </summary>
	qboolean in_special_reload{};

	/// <summary>
	/// </summary>
	float next_reload{};

	/// <summary>
	/// </summary>
	float pump_time{};

	/// <summary>
	/// </summary>
	float reload_time{};

	/// <summary>
	/// </summary>
	float aimed_damage{};

	/// <summary>
	/// </summary>
	float next_aim_bonus{};

	/// <summary>
	/// </summary>
	qboolean in_zoom{};

	/// <summary>
	/// </summary>
	int weapon_state{};

	/// <summary>
	/// </summary>
	int i_user1{};

	/// <summary>
	/// </summary>
	int i_user2{};

	/// <summary>
	/// </summary>
	int i_user3{};

	/// <summary>
	/// </summary>
	int i_user4{};

	/// <summary>
	/// </summary>
	float f_user1{};

	/// <summary>
	/// </summary>
	float f_user2{};

	/// <summary>
	/// </summary>
	float f_user3{};

	/// <summary>
	/// </summary>
	float f_user4{};
};
