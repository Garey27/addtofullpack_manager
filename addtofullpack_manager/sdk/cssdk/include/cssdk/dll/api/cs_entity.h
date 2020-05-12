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
/// </summary>
constexpr auto CS_ENTITY_API_INTERFACE_VERSION = "CSENTITY_API_INTERFACE_VERSION001";

/// <summary>
/// Class CsEntity.
/// </summary>
class CsEntity {
public:
	/// <summary>
	/// </summary>
	CsEntity() : containing_entity(nullptr)
	{
	}

	/// <summary>
	/// </summary>
	CsEntity(const CsEntity&) = default;

	/// <summary>
	/// </summary>
	CsEntity& operator=(const CsEntity&) = default;

	/// <summary>
	/// </summary>
	virtual ~CsEntity() = default;

	/// <summary>
	/// </summary>
	virtual void fire_bullets(int shots, Vector& src, Vector& dir_shooting, Vector& spread, float distance,
	                          int bullet_type, int tracer_freq, int damage, EntityVars* attacker) = 0;

	/// <summary>
	/// </summary>
	virtual Vector fire_bullets3(Vector& src, Vector& dir_shooting, float spread, float distance, int penetration, int bullet_type,
	                             int damage, float range_modifier, EntityVars* attacker, bool pistol, int shared_rand) = 0;

	/// <summary>
	/// </summary>
	EntityBase* containing_entity;
};

/// <summary>
/// Class CsDelay.
/// </summary>
class CsDelay : public CsEntity {
};

/// <summary>
/// Class CsAnimating.
/// </summary>
class CsAnimating : public CsDelay {
};

/// <summary>
/// Class CsToggle.
/// </summary>
class CsToggle : public CsAnimating {
};

/// <summary>
/// Class CsMonster.
/// </summary>
class CsMonster : public CsToggle {
};
