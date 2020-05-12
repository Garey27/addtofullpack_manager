// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/monsters.h>
#include <cssdk/public/vector.h>

/// <summary>
/// </summary>
struct Edict;

/// <summary>
/// Struct GlobalVars
/// </summary>
struct GlobalVars {
	/// <summary>
	/// </summary>
	float time{};

	/// <summary>
	/// </summary>
	float frame_time{};

	/// <summary>
	/// </summary>
	float force_retouch{};

	/// <summary>
	/// </summary>
	unsigned int map_name{};

	/// <summary>
	/// </summary>
	unsigned int start_spot{};

	/// <summary>
	/// </summary>
	float deathmatch{};

	/// <summary>
	/// </summary>
	float coop{};

	/// <summary>
	/// </summary>
	float teamplay{};

	/// <summary>
	/// </summary>
	float server_flags{};

	/// <summary>
	/// </summary>
	float found_secrets{};

	/// <summary>
	/// </summary>
	Vector vec_forward;

	/// <summary>
	/// </summary>
	Vector vec_up;

	/// <summary>
	/// </summary>
	Vector vec_right;

	/// <summary>
	/// </summary>
	float trace_all_solid{};

	/// <summary>
	/// </summary>
	float trace_start_solid{};

	/// <summary>
	/// </summary>
	float trace_fraction{};

	/// <summary>
	/// </summary>
	Vector trace_end_pos;

	/// <summary>
	/// </summary>
	Vector trace_plane_normal;

	/// <summary>
	/// </summary>
	float trace_plane_dist{};

	/// <summary>
	/// </summary>
	Edict* trace_entity{};

	/// <summary>
	/// </summary>
	float trace_in_open{};

	/// <summary>
	/// </summary>
	float trace_in_water{};

	/// <summary>
	/// </summary>
	HitBoxGroup trace_hit_group{};

	/// <summary>
	/// </summary>
	int trace_flags{};

	/// <summary>
	/// </summary>
	int msg_entity{};

	/// <summary>
	/// </summary>
	int cd_audio_track{};

	/// <summary>
	/// </summary>
	int max_clients{};

	/// <summary>
	/// </summary>
	int max_entities{};

	/// <summary>
	/// </summary>
	const char* string_base{};

	/// <summary>
	/// </summary>
	void* save_data{};

	/// <summary>
	/// </summary>
	Vector landmark_offset;
};
