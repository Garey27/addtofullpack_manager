// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/entity_base.h>

/// <summary>
/// Class PlayerAmmoBase.
/// </summary>
class PlayerAmmoBase : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean add_ammo(EntityBase* other) = 0;

	/// <summary>
	/// </summary>
	EntityBase* respawn() override = 0;
};
