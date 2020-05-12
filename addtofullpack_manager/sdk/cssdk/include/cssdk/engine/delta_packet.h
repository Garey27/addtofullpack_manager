// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/entity_state.h>

/// <summary>
/// Struct PacketEntities
/// </summary>
struct PacketEntities {
	/// <summary>
	/// </summary>
	int num_entities{};

	/// <summary>
	/// </summary>
	unsigned char flags[32]{};

	/// <summary>
	/// </summary>
	EntityState* entities{};
};
