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
/// <para>Physics variables.</para>
/// </summary>
struct MoveVars {
	/// <summary>
	/// <para>Gravity for map.</para>
	/// </summary>
	float gravity{};

	/// <summary>
	/// <para>Deceleration when not moving.</para>
	/// </summary>
	float stop_speed{};

	/// <summary>
	/// <para>Max allowed speed.</para>
	/// </summary>
	float max_speed{};

	/// <summary>
	/// </summary>
	float spectator_max_speed{};

	/// <summary>
	/// <para>Acceleration factor.</para>
	/// </summary>
	float accelerate{};

	/// <summary>
	/// <para>Acceleration factor when in open air.</para>
	/// </summary>
	float air_accelerate{};

	/// <summary>
	/// <para>Acceleration factor when in water.</para>
	/// </summary>
	float water_accelerate{};

	/// <summary>
	/// </summary>
	float friction{};

	/// <summary>
	/// <para>Extra friction near dropofs.</para>
	/// </summary>
	float edge_friction{};

	/// <summary>
	/// <para>Less in water.</para>
	/// </summary>
	float water_friction{};

	/// <summary>
	/// <para>1.0.</para>
	/// </summary>
	float entity_gravity{};

	/// <summary>
	/// <para>Wall bounce value. 1.0.</para>
	/// </summary>
	float bounce{};

	/// <summary>
	/// <para>sv_stepsize.</para>
	/// </summary>
	float step_size{};

	/// <summary>
	/// <para>Maximum server velocity.</para>
	/// </summary>
	float max_velocity{};

	/// <summary>
	/// <para>Max z-buffer range (for GL).</para>
	/// </summary>
	float z_max{};

	/// <summary>
	/// <para>Water wave height (for GL).</para>
	/// </summary>
	float wave_height{};

	/// <summary>
	/// <para>Play footstep sounds.</para>
	/// </summary>
	qboolean footsteps{};

	/// <summary>
	/// <para>Name of the sky map.</para>
	/// </summary>
	char sky_name[32]{};

	/// <summary>
	/// </summary>
	float roll_angle{};

	/// <summary>
	/// </summary>
	float roll_speed{};

	/// <summary>
	/// </summary>
	float sky_color_r{};

	/// <summary>
	/// </summary>
	float sky_color_g{};

	/// <summary>
	/// </summary>
	float sky_color_b{};

	/// <summary>
	/// </summary>
	float sky_vec_x{};

	/// <summary>
	/// </summary>
	float sky_vec_y{};

	/// <summary>
	/// </summary>
	float sky_vec_z{};
};
