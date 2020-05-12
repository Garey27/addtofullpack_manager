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
#include <cssdk/common/model.h>
#include <cssdk/common/pm_trace.h>
#include <cssdk/common/trace.h>
#include <cssdk/common/user_cmd.h>
#include <cssdk/pm_shared/pm_move_vars.h>
#include <cssdk/public/arch_types.h>
#include <cssdk/public/base_types.h>
#include <cssdk/public/vector.h>

/// <summary>
/// </summary>
constexpr auto MAX_PHYS_ENTS = 600;

/// <summary>
/// </summary>
constexpr auto MAX_MOVE_ENTS = 64;

/// <summary>
/// </summary>
constexpr auto MAX_CLIP_PLANES = 5;

/// <summary>
/// </summary>
constexpr auto PM_NORMAL = 0x00000000;

/// <summary>
/// </summary>
constexpr auto PM_STUDIO_IGNORE = 0x00000001;

/// <summary>
/// </summary>
constexpr auto PM_STUDIO_BOX = 0x00000002;

/// <summary>
/// </summary>
constexpr auto PM_GLASS_IGNORE = 0x00000004;

/// <summary>
/// </summary>
constexpr auto PM_WORLD_ONLY = 0x00000008;

/// <summary>
/// </summary>
constexpr auto PM_TRACE_LINE_PHYS_ENTS_ONLY = 0;

/// <summary>
/// </summary>
constexpr auto PM_TRACE_LINE_ANY_VISIBLE = 1;

/// <summary>
/// Struct PhysEntity
/// </summary>
struct PhysEntity {
	/// <summary>
	/// <para>Name of model, or "player" or "world".</para>
	/// </summary>
	char name[32]{};

	/// <summary>
	/// </summary>
	int player{};

	/// <summary>
	/// <para>Model's origin in world coordinates.</para>
	/// </summary>
	Vector origin;

	/// <summary>
	/// <para>Only for bsp models.</para>
	/// </summary>
	Model* bsp_model{};

	/// <summary>
	/// <para><c>SolidType::BoundingBox</c>, but studio clip intersections.</para>
	/// </summary>
	Model* studio_model{};

	/// <summary>
	/// <para>Only for non-bsp models.</para>
	/// </summary>
	Vector min_size;

	/// <summary>
	/// <para>Only for non-bsp models.</para>
	/// </summary>
	Vector max_size;

	/// <summary>
	/// <para>For client or server to use to identify (index into edicts or cl_entities).</para>
	/// </summary>
	int info{};

	/// <summary>
	/// <para>Rotated entities need this info for hull testing to work.</para>
	/// </summary>
	Vector angles;

	/// <summary>
	/// <para>Triggers and func_door type WATER brushes are <c>SolidType::NotSolid</c>.</para>
	/// </summary>
	SolidType solid{};

	/// <summary>
	/// <para>BSP Contents for such things like fun_door water brushes.</para>
	/// </summary>
	int skin{};

	/// <summary>
	/// <para>So we can ignore glass.</para>
	/// </summary>
	Rendering render_mode{};

	/// <summary>
	/// </summary>
	float frame{};

	/// <summary>
	/// </summary>
	int sequence{};

	/// <summary>
	/// </summary>
	byte controller[4]{};

	/// <summary>
	/// </summary>
	byte blending[2]{};

	/// <summary>
	/// </summary>
	MoveTypeEntity move_type{};

	/// <summary>
	/// </summary>
	int take_damage{};

	/// <summary>
	/// </summary>
	int blood_decal{};

	/// <summary>
	/// </summary>
	int team{};

	/// <summary>
	/// </summary>
	int class_number{};

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
/// Struct PlayerMove
/// </summary>
struct PlayerMove {
	/// <summary>
	/// </summary>
	int player_index{};

	/// <summary>
	/// </summary>
	qboolean server{};

	/// <summary>
	/// </summary>
	qboolean multiplayer{};

	/// <summary>
	/// </summary>
	float time{};

	/// <summary>
	/// </summary>
	float frame_time{};

	/// <summary>
	/// </summary>
	Vector forward;

	/// <summary>
	/// </summary>
	Vector right;

	/// <summary>
	/// </summary>
	Vector up;

	/// <summary>
	/// </summary>
	Vector origin;

	/// <summary>
	/// </summary>
	Vector angles;

	/// <summary>
	/// </summary>
	Vector old_angles;

	/// <summary>
	/// </summary>
	Vector velocity;

	/// <summary>
	/// </summary>
	Vector move_direction;

	/// <summary>
	/// </summary>
	Vector base_velocity;

	/// <summary>
	/// </summary>
	Vector view_ofs;

	/// <summary>
	/// </summary>
	float duck_time{};

	/// <summary>
	/// </summary>
	qboolean in_duck{};

	/// <summary>
	/// </summary>
	int time_step_sound{};

	/// <summary>
	/// </summary>
	int step_left{};

	/// <summary>
	/// </summary>
	float fall_velocity{};

	/// <summary>
	/// </summary>
	Vector punch_angle;

	/// <summary>
	/// </summary>
	float swim_time{};

	/// <summary>
	/// </summary>
	float next_primary_attack{};

	/// <summary>
	/// </summary>
	int effects{};

	/// <summary>
	/// </summary>
	int flags{};

	/// <summary>
	/// </summary>
	int use_hull{};

	/// <summary>
	/// </summary>
	float gravity{};

	/// <summary>
	/// </summary>
	float friction{};

	/// <summary>
	/// </summary>
	int old_buttons{};

	/// <summary>
	/// </summary>
	float water_jump_time{};

	/// <summary>
	/// </summary>
	qboolean dead{};

	/// <summary>
	/// </summary>
	DeathState dead_flag{};

	/// <summary>
	/// </summary>
	int spectator{};

	/// <summary>
	/// </summary>
	MoveTypeEntity move_type{};

	/// <summary>
	/// </summary>
	int on_ground{};

	/// <summary>
	/// </summary>
	int water_level{};

	/// <summary>
	/// </summary>
	int water_type{};

	/// <summary>
	/// </summary>
	int old_water_level{};

	/// <summary>
	/// </summary>
	char texture_name[256]{};

	/// <summary>
	/// </summary>
	char texture_type{};

	/// <summary>
	/// </summary>
	float max_speed{};

	/// <summary>
	/// </summary>
	float client_max_speed{};

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

	/// <summary>
	/// </summary>
	int num_phys_ent{};

	/// <summary>
	/// </summary>
	PhysEntity phys_ents[MAX_PHYS_ENTS];

	/// <summary>
	/// </summary>
	int num_move_ent{};

	/// <summary>
	/// </summary>
	PhysEntity move_ents[MAX_MOVE_ENTS];

	/// <summary>
	/// </summary>
	int num_vis_ent{};

	/// <summary>
	/// </summary>
	PhysEntity vis_ents[MAX_PHYS_ENTS];

	/// <summary>
	/// </summary>
	UserCmd cmd;

	/// <summary>
	/// </summary>
	int num_touch{};

	/// <summary>
	/// </summary>
	PmTrace touch_index[MAX_PHYS_ENTS];

	/// <summary>
	/// </summary>
	char phys_info[MAX_PHYS_INFO_STRING]{};

	/// <summary>
	/// </summary>
	MoveVars* move_vars{};

	/// <summary>
	/// </summary>
	Vector player_min_size[MAX_MAP_HULLS];

	/// <summary>
	/// </summary>
	Vector player_max_size[MAX_MAP_HULLS];

	//
	// Common functions.
	// 

	/// <summary>
	/// </summary>
	const char* (*pm_info_value_for_key)(const char* s, const char* key){};

	/// <summary>
	/// </summary>
	void (*pm_particle)(Vector& origin, int color, float life, int z_pos, int z_velocity){};

	/// <summary>
	/// </summary>
	int (*pm_test_player_position)(Vector& pos, PmTrace* trace){};

	/// <summary>
	/// </summary>
	void (*con_notify_print)(int pos, const char* format, ...){};

	/// <summary>
	/// </summary>
	void (*con_dev_print)(const char* format, ...){};

	/// <summary>
	/// </summary>
	void (*con_print)(const char* format, ...){};

	/// <summary>
	/// </summary>
	double (*sys_float_time)(){};

	/// <summary>
	/// </summary>
	void (*pm_stuck_touch)(int hit_ent, PmTrace* trace_result){};

	/// <summary>
	/// </summary>
	int (*pm_point_contents)(Vector& pos, int* true_contents){};

	/// <summary>
	/// </summary>
	int (*pm_true_point_contents)(Vector& pos){};

	/// <summary>
	/// </summary>
	int (*pm_hull_point_contents)(Hull* hull, int num, Vector& pos){};

	/// <summary>
	/// </summary>
	PmTrace (*pm_player_trace)(Vector& start, Vector& end, int trace_flags, int ignore_pe){};

	/// <summary>
	/// </summary>
	PmTrace* (*pm_trace_line)(Vector& start, Vector& end, int flags, int use_hull, int ignore_pe){};

	/// <summary>
	/// </summary>
	int32 (*random_long)(int32 low, int32 high){};

	/// <summary>
	/// </summary>
	float (*random_float)(float low, float high){};

	/// <summary>
	/// </summary>
	int (*pm_get_model_type)(Model* mdl){};

	/// <summary>
	/// </summary>
	void (*pm_get_model_bounds)(Model* mdl, Vector& min_size, Vector& max_size){};

	/// <summary>
	/// </summary>
	void (*pm_hull_for_bsp)(PhysEntity* phys_ent, float* offset){};

	/// <summary>
	/// </summary>
	float (*pm_trace_model)(PhysEntity* phys_ent, Vector& start, Vector& end, Trace* trace){};

	/// <summary>
	/// </summary>
	int (*com_file_size)(const char* file_name){};

	/// <summary>
	/// </summary>
	byte* (*com_load_file)(const char* path, int use_hunk, int* length){};

	/// <summary>
	/// </summary>
	void (*com_free_file)(void* buffer){};

	/// <summary>
	/// </summary>
	char* (*mem_file_gets)(byte* mem_file, int file_size, int* file_pos, char* buffer, int buffer_size){};

	//
	// Functions.
	// 

	/// <summary>
	/// <para>Run functions for this frame?</para>
	/// </summary>
	qboolean run_functions{};

	/// <summary>
	/// </summary>
	void (*pm_play_sound)(int channel, const char* sample, float volume, float attenuation, int flags, int pitch){};

	/// <summary>
	/// </summary>
	const char* (*pm_trace_texture)(int ground, Vector& start, Vector& end){};

	/// <summary>
	/// </summary>
	void (*pm_playback_event_full)(int flags, int client_index, unsigned short event_index, float delay, Vector& origin, Vector& angles,
	                               float f_param1, float f_param2, int i_param1, int i_param2, qboolean b_param1, qboolean b_param2){};

	/// <summary>
	/// </summary>
	PmTrace (*pm_player_trace_ex)(Vector& start, Vector& end, int trace_flags, int (*ignore)(PhysEntity* phys_ent)){};

	/// <summary>
	/// </summary>
	int (*pm_test_player_position_ex)(Vector& pos, PmTrace* trace, int (*ignore)(PhysEntity* phys_ent)){};

	/// <summary>
	/// </summary>
	PmTrace* (*pm_trace_line_ex)(Vector& start, Vector& end, int flags, int use_hull, int (*ignore)(PhysEntity* phys_ent)){};
};
