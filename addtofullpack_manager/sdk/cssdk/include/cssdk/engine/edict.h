// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/engine/entity_vars.h>
#include <cssdk/public/base_types.h>

/// <summary>
/// <para>The maximum entity leafs.</para>
/// </summary>
constexpr auto MAX_ENT_LEAFS = 48;

/// <summary>
/// Struct Link
/// </summary>
struct Link {
	/// <summary>
	/// </summary>
	Link* prev{};

	/// <summary>
	/// </summary>
	Link* next{};
};

/// <summary>
/// <para>Struct Edict (entity dictionary).</para>
/// </summary>
struct Edict {
	/// <summary>
	/// </summary>
	qboolean free{};

	/// <summary>
	/// </summary>
	int serial_number{};

	/// <summary>
	/// <para>Linked to a division node or leaf.</para>
	/// </summary>
	Link area;

	/// <summary>
	/// <para>-1 to use normal leaf check.</para>
	/// </summary>
	int head_node{};

	/// <summary>
	/// </summary>
	int num_leafs{};

	/// <summary>
	/// </summary>
	short leaf_nums[MAX_ENT_LEAFS]{};

	/// <summary>
	/// <para>sv.time when the object was freed.</para>
	/// </summary>
	float free_time{};

	/// <summary>
	/// <para>Allocated and freed by engine, used by DLLs.</para>
	/// </summary>
	void* private_data{};

	/// <summary>
	/// <para>C exported fields from progs.</para>
	/// </summary>
	EntityVars vars;

	// Other fields from progs come immediately after.
};
