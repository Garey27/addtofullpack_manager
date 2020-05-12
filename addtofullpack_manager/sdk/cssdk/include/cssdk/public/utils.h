// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/consts.h>
#include <cssdk/engine/edict.h>

/// <summary>
/// </summary>
inline bool cssdk_is_valid_entity(const Edict* const entity)
{
	return entity && !entity->free && entity->private_data && !(entity->vars.flags & FL_KILL_ME);
}

/// <summary>
/// </summary>
template <typename T>
T cssdk_entity_private_data(const Edict* const entity)
{
	return entity == nullptr ? T() : static_cast<T>(entity->private_data);
}
