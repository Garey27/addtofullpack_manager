// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/api/cs_player_item.h>

/// <summary>
/// Class CsPlayerWeapon.
/// </summary>
class CsPlayerWeapon : public CsPlayerItem {
public:
	/// <summary>
	/// </summary>
	bool has_secondary_attack{};

	/// <summary>
	/// </summary>
	float base_damage{};

	/// <summary>
	/// </summary>
	[[nodiscard]] PlayerWeaponBase* player_weapon_base() const
	{
		return reinterpret_cast<PlayerWeaponBase*>(this->containing_entity);
	}
};
