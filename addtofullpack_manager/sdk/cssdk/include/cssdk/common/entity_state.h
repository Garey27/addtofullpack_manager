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
#include <cssdk/pm_shared/pm_info.h>
#include <cssdk/public/base_types.h>
#include <cssdk/public/vector.h>

/// <summary>
/// </summary>
constexpr auto ENTITY_NORMAL = 1 << 0;

/// <summary>
/// </summary>
constexpr auto ENTITY_BEAM = 1 << 1;

/// <summary>
/// </summary>
constexpr auto ENTITY_UNINITIALIZED = 1 << 30;

/// <summary>
/// <para>Entity state is used for the baseline and for delta compression
/// of a packet of entities that is sent to a client.</para>
/// </summary>
struct EntityState {
	/// <summary>
	/// <para>Fields which are filled in by routines outside of delta compression.</para>
	/// </summary>
	int entity_type{}; 

	/// <summary>
	/// <para>Index into cl_entities array for this entity.</para>
	/// </summary>
	int number{};

	/// <summary>
	/// </summary>
	float msg_time{}; 

	/// <summary>
	/// <para>Message number last time the player/entity state was updated.</para>
	/// </summary>
	int message_num{}; 

	/// <summary>
	/// </summary>
	Vector origin; 

	/// <summary>
	/// </summary>
	Vector angles;

	/// <summary>
	/// </summary>
	int model_index{};

	/// <summary>
	/// </summary>
	int sequence{};

	/// <summary>
	/// </summary>
	float frame{};

	/// <summary>
	/// </summary>
	int color_map{};

	/// <summary>
	/// </summary>
	short skin{};

	/// <summary>
	/// </summary>
	short solid{};

	/// <summary>
	/// </summary>
	int effects{};

	/// <summary>
	/// </summary>
	float scale{};

	/// <summary>
	/// </summary>
	byte entity_flags{};

	/// <summary>
	/// </summary>
	Rendering render_mode{};

	/// <summary>
	/// </summary>
	int render_amount{};

	/// <summary>
	/// </summary>
	Color24 render_color{};

	/// <summary>
	/// </summary>
	RenderingFx render_fx{};

	/// <summary>
	/// </summary>
	MoveTypeEntity move_type{};

	/// <summary>
	/// </summary>
	float anim_time{};

	/// <summary>
	/// </summary>
	float frame_rate{};

	/// <summary>
	/// </summary>
	int body{};

	/// <summary>
	/// </summary>
	byte controller[4]{};

	/// <summary>
	/// </summary>
	byte blending[4]{};

	/// <summary>
	/// </summary>
	Vector velocity;

	/// <summary>
	/// </summary>
	Vector min_size;

	/// <summary>
	/// </summary>
	Vector max_size;

	/// <summary>
	/// </summary>
	int aim_entity{};

	/// <summary>
	/// <para>If owned by a player, the index of that player (for projectiles).</para>
	/// </summary>
	int owner{};

	/// <summary>
	/// <para>Friction, for prediction.</para>
	/// </summary>
	float friction{};

	/// <summary>
	/// <para>Gravity multiplier.</para>
	/// </summary>
	float gravity{};

	/// <summary>
	/// </summary>
	int team{};

	/// <summary>
	/// </summary>
	int player_class{};

	/// <summary>
	/// </summary>
	int health{};

	/// <summary>
	/// </summary>
	qboolean spectator{};

	/// <summary>
	/// </summary>
	int weapon_model{};

	/// <summary>
	/// </summary>
	int gait_sequence{};

	/// <summary>
	/// <para>If standing on conveyor, e.g.</para>
	/// </summary>
	Vector base_velocity;

	/// <summary>
	/// <para>Use the crouched hull, or the regular player hull.</para>
	/// </summary>
	int use_hull{};

	/// <summary>
	/// <para>Latched buttons last time state updated.</para>
	/// </summary>
	int old_buttons{};

	/// <summary>
	/// <para>-1 = in air, else move entity number.</para>
	/// </summary>
	int on_ground{};

	/// <summary>
	/// </summary>
	int step_left{};

	/// <summary>
	/// <para>How fast we are falling.</para>
	/// </summary>
	float fall_velocity{};

	/// <summary>
	/// </summary>
	float fov{};

	/// <summary>
	/// </summary>
	int weapon_anim{};

	/// <summary>
	/// </summary>
	Vector start_pos;

	/// <summary>
	/// </summary>
	Vector end_pos;

	/// <summary>
	/// </summary>
	float impact_time{};

	/// <summary>
	/// </summary>
	float start_time{};

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

	/// <summary>
	/// </summary>
	Vector v_user1;

	/// <summary>
	/// </summary>
	Vector v_user2;

	/// <summary>
	/// </summary>
	Vector v_user3;

	/// <summary>
	/// </summary>
	Vector v_user4;
};

/// <summary>
/// Struct ClientData
/// </summary>
struct ClientData {
	/// <summary>
	/// </summary>
	Vector origin;

	/// <summary>
	/// </summary>
	Vector velocity;

	/// <summary>
	/// </summary>
	int view_model{};

	/// <summary>
	/// </summary>
	Vector punch_angle;

	/// <summary>
	/// </summary>
	int flags{};

	/// <summary>
	/// </summary>
	int water_level{};

	/// <summary>
	/// </summary>
	int water_type{};

	/// <summary>
	/// </summary>
	Vector view_ofs;

	/// <summary>
	/// </summary>
	float health{};

	/// <summary>
	/// </summary>
	qboolean in_duck{};

	/// <summary>
	/// </summary>
	int weapons{};

	/// <summary>
	/// </summary>
	int time_step_sound{};

	/// <summary>
	/// </summary>
	int duck_time{};

	/// <summary>
	/// </summary>
	int swim_time{};

	/// <summary>
	/// </summary>
	int water_jump_time{};

	/// <summary>
	/// </summary>
	float max_speed{};

	/// <summary>
	/// </summary>
	float field_of_view{};

	/// <summary>
	/// </summary>
	int weapon_anim{};

	/// <summary>
	/// </summary>
	int id{};

	/// <summary>
	/// </summary>
	int ammo_shells{};

	/// <summary>
	/// </summary>
	int ammo_nails{};

	/// <summary>
	/// </summary>
	int ammo_cells{};

	/// <summary>
	/// </summary>
	int ammo_rockets{};

	/// <summary>
	/// </summary>
	float next_attack{};

	/// <summary>
	/// </summary>
	int tf_state{};

	/// <summary>
	/// </summary>
	int push_msec{};

	/// <summary>
	/// </summary>
	DeathState dead_flag{};

	/// <summary>
	/// </summary>
	char phys_info[MAX_PHYS_INFO_STRING]{};

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

	/// <summary>
	/// </summary>
	Vector v_user1;

	/// <summary>
	/// </summary>
	Vector v_user2;

	/// <summary>
	/// </summary>
	Vector v_user3;

	/// <summary>
	/// </summary>
	Vector v_user4;
};
