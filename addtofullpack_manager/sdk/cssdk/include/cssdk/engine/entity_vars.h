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
#include <cssdk/public/strind.h>
#include <cssdk/public/vector.h>

/// <summary>
/// </summary>
struct Edict;

/// <summary>
/// <para>Contains entity variables that the engine needs to access for graphics, networking and physics.</para>
/// </summary>
struct EntityVars {
	/// <summary>
	/// <para>The class name of the entity.</para>
	/// </summary>
	Strind class_name;

	/// <summary>
	/// <para>Global entity name.<br/>
	/// Used for entities that carry their state across level transitions in single player.</para>
	/// </summary>
	Strind global_name;

	/// <summary>
	/// <para>Absolute origin in the world.<br/>
	/// Networked.</para>
	/// </summary>
	Vector origin;

	/// <summary>
	/// <para>Old entity origin.<br/>
	/// Used in the engine to store the player's old origin when no clip is turned off.</para>
	/// </summary>
	Vector old_origin;

	/// <summary>
	/// <para>The entity's absolute velocity.<br/>
	/// Networked.</para>
	/// </summary>
	Vector velocity;

	/// <summary>
	/// <para>Base velocity to apply when standing on conveyors or swimming in water with current contents set.<br/>
	/// Networked.</para>
	/// </summary>
	Vector base_velocity;

	/// <summary>
	/// <para>Base velocity that was passed in to server physics so client can predict conveyors correctly.<br/>
	/// Server zeroes it, so we need to store here, too.<br/>
	/// Zeroed out prior to <c>DllFuncPointers::pre_think</c> being called,
	/// set to the player's basevelocity after the player's think has been called, before <c>DllFuncPointers::post_think</c> is called.</para>
	/// </summary>
	Vector cl_base_velocity;

	/// <summary>
	/// <para>Movement direction and speed.</para>
	/// </summary>
	Vector move_direction;

	/// <summary>
	/// <para>Model angles.<br/>
	/// Networked.</para>
	/// </summary>
	Vector angles;

	/// <summary>
	/// <para>Angle velocity (degrees per second).</para>
	/// </summary>
	Vector angle_velocity;

	/// <summary>
	/// <para>Auto-decaying view angle adjustment.<br/>
	/// Decayed in <c>PM_CheckParameters</c>.<br/>
	/// Networked.</para>
	/// </summary>
	Vector punch_angle;

	/// <summary>
	/// <para>Viewing angle (player only).</para>
	/// </summary>
	Vector viewing_angle;

	/// <summary>
	/// <para>Parametric end position.<br/>
	/// Networked.</para>
	/// </summary>
	Vector end_pos;

	/// <summary>
	/// <para>Parametric start position.<br/>
	/// Networked.</para>
	/// </summary>
	Vector start_pos;

	/// <summary>
	/// <para>Time at which the entity will have traversed the distance between start pos and end pos.<br/>
	/// Networked.</para>
	/// </summary>
	float impact_time{};

	/// <summary>
	/// <para>Time at which the entity has started its parametric movement.<br/>
	/// Networked.</para>
	/// </summary>
	float start_time{};

	/// <summary>
	/// <para>Player only. Sets the player's view angles on the client. The server's angles are not modified automatically.</para>
	/// </summary>
	FixAngleMode fix_angle{};

	/// <summary>
	/// <para>The ideal pitch for this entity. <c>EngineFuncPointers::change_pitch</c> will adjust the entity's pitch to approach this value.</para>
	/// </summary>
	float ideal_pitch{};

	/// <summary>
	/// <para>The pitch speed for this entity. <c>EngineFuncPointers::change_pitch</c> will adjust the entity's pitch at this speed.</para>
	/// </summary>
	float pitch_speed{};

	/// <summary>
	/// <para>The ideal yaw for this entity. <c>EngineFuncPointers::change_yaw</c> will adjust the entity's yaw to approach this value.</para>
	/// </summary>
	float ideal_yaw{};

	/// <summary>
	/// <para>The yaw speed for this entity. <c>EngineFuncPointers::change_yaw</c> will adjust the entity's yaw at this speed.</para>
	/// </summary>
	float yaw_speed{};

	/// <summary>
	/// <para>If this entity has a model, this is the index of that model. Otherwise, is 0.
	/// Set by <c>EngineFuncPointers::set_model</c>.
	/// Networked.</para>
	/// </summary>
	int model_index{};

	/// <summary>
	/// <para>If this entity has a model, this is the name of that model. Otherwise, is 0.</para>
	/// </summary>
	Strind model;

	/// <summary>
	/// <para>The player's viewmodel (v_*.mdl).<br/>
	/// Networked.</para>
	/// </summary>
	int view_model{};

	/// <summary>
	/// <para>What other players see; the player's third person viewmodel (p_*.mdl).<br/>
	/// Networked.</para>
	/// </summary>
	int weapon_model{};

	/// <summary>
	/// <para>Bounding box max translated to world coord.<br/>
	/// Set by the engine whenever the entity moves, set by game code to adjust the size.</para>
	/// </summary>
	Vector abs_min;

	/// <summary>
	/// <para>Bounding box max translated to world coord.<br/>
	/// Set by the engine whenever the entity moves, set by game code to adjust the size.</para>
	/// </summary>
	Vector abs_max;

	/// <summary>
	/// <para>Local bounding box min.</para>
	/// </summary>
	Vector min_size;

	/// <summary>
	/// <para>Local bounding box max.</para>
	/// </summary>
	Vector max_size;

	/// <summary>
	/// <para>max_size - min_size.</para>
	/// </summary>
	Vector size;

	/// <summary>
	/// <para>Last think time for brush entities (<c>MoveTypeEntity::Push</c>).</para>
	/// </summary>
	float last_think{};

	/// <summary>
	/// <para>Next think time. Should be GlobalVars::time + delay for all entities except <c>MoveTypeEntity::Push</c> entities; use last_think + delay for those instead.</para>
	/// </summary>
	float next_think{};

	/// <summary>
	/// <para>Move type.<br/>
	/// Networked.</para>
	/// </summary>
	MoveTypeEntity move_type{};

	/// <summary>
	/// <para>Solid type.<br/>
	/// Networked.</para>
	/// </summary>
	SolidType solid{};

	/// <summary>
	/// <para>Studio model skin index. Seems to affect the player's z velocity if the FL_ON_TARGET flag is set.<br/>
	/// Networked.</para>
	/// </summary>
	int skin{};

	/// <summary>
	/// <para>Sub-model selection for studio models.<br/>
	/// Networked.</para>
	/// </summary>
	int body{};

	/// <summary>
	/// <para>Effects flags.<br/>
	/// Networked.</para>
	/// </summary>
	int effects{};

	/// <summary>
	/// <para>% of "normal" gravity.<br/>
	/// Default 1.0.<br/>
	/// Networked.</para>
	/// </summary>
	float gravity{};

	/// <summary>
	/// <para>Inverse elasticity of <c>MoveTypeEntity::Bounce</c>.<br/>
	/// Networked.</para>
	/// </summary>
	float friction{};

	/// <summary>
	/// <para>The stored light level for this entity.<br/>
	/// Use <c>EngineFuncPointers::get_entity_illumination</c> to retrieve this.</para>
	/// </summary>
	int light_level{};

	/// <summary>
	/// <para>Animation sequence.<br/>
	/// Networked.</para>
	/// </summary>
	int sequence{};

	/// <summary>
	/// <para>Movement animation sequence for player (0 for none).<br/>
	/// Networked for clients only.</para>
	/// </summary>
	int gait_sequence{};

	/// <summary>
	/// <para>% playback position in animation sequences (0..255).<br/>
	/// Networked.</para>
	/// </summary>
	float frame{};

	/// <summary>
	/// <para>World time when frame was set.<br/>
	/// Networked.</para>
	/// </summary>
	float anim_time{};

	/// <summary>
	/// <para>Animation playback rate (-8x to 8x).<br/>
	/// Networked.</para>
	/// </summary>
	float frame_rate{};

	/// <summary>
	/// <para>Bone controller setting (0..255).<br/>
	/// Networked.</para>
	/// </summary>
	byte controller[4]{};

	/// <summary>
	/// <para>Blending amount between sub-sequences (0..255).<br/>
	/// Networked.</para>
	/// </summary>
	byte blending[2]{};

	/// <summary>
	/// <para>Sprite rendering scale (0..255).<br/>
	/// Networked.</para>
	/// </summary>
	float scale{};

	/// <summary>
	/// <para>Render mode.<br/>
	/// Networked.</para>
	/// </summary>
	Rendering render_mode{};

	/// <summary>
	/// <para>Render amount.<br/>
	/// Networked.</para>
	/// </summary>
	float render_amount{};

	/// <summary>
	/// <para>Render color. Each component is in the range [0, 255].<br/>
	/// Networked.</para>
	/// </summary>
	Vector render_color;

	/// <summary>
	/// <para>Render FX.<br/>
	/// Networked.</para>
	/// </summary>
	RenderingFx render_fx{};

	/// <summary>
	/// <para>Health.<br/>
	/// Networked.</para>
	/// </summary>
	float health{};

	/// <summary>
	/// <para>Frags. Player score.</para>
	/// </summary>
	float frags{};

	/// <summary>
	/// <para>Bit mask for available weapons.<br/>
	/// Networked.</para>
	/// </summary>
	int weapons{};

	/// <summary>
	/// <para>Whether this entity can take damage, and whether the player's auto aim can snap to this entity.</para>
	/// </summary>
	float take_damage{};

	/// <summary>
	/// <para>Current entity death state.<br/>
	/// Networked.</para>
	/// </summary>
	DeathState dead_flag{};

	/// <summary>
	/// <para>Eye position.<br/>
	/// Networked.</para>
	/// </summary>
	Vector view_ofs;

	/// <summary>
	/// <para>Buttons that the player currently has pressed in.<br/>
	/// Stores the use type for delayed triggers.</para>
	/// </summary>
	int button{};

	/// <summary>
	/// <para>Current player impulse command.</para>
	/// </summary>
	int impulse{};

	/// <summary>
	/// <para>Entity pointer when linked into a linked list.<br/>
	/// Used by <c>EngineFuncPointers::entities_in_pvs</c> to return a list of entities.</para>
	/// </summary>
	Edict* chain{};

	/// <summary>
	/// <para>Used in <c>MonsterBase::take_damage</c> and <c>PlayerBase::update_client_data</c> to track the last damage inflictor.</para>
	/// </summary>
	Edict* damage_inflictor{};

	/// <summary>
	/// <para>Used as a destination for <c>EngineFuncPointers::move_to_origin</c> when the entity is flying or swimming.</para>
	/// </summary>
	Edict* enemy{};

	/// <summary>
	/// <para>Entity pointer when <c>MoveTypeEntity::Follow</c>.</para>
	/// </summary>
	Edict* aim_entity{};

	/// <summary>
	/// <para>The entity that owns this entity, or null if it has no owner.</para>
	/// </summary>
	Edict* owner{};

	/// <summary>
	/// <para>The entity that this entity is currently standing on, or null if it isn't standing on anything.</para>
	/// </summary>
	Edict* ground_entity{};

	/// <summary>
	/// <para>Spawn flags. These are specific to each entity.</para>
	/// </summary>
	int spawn_flags{};

	/// <summary>
	/// <para>Flags.</para>
	/// </summary>
	int flags{};

	/// <summary>
	/// <para>Low byte - top color, high byte - bottom color.<br/>
	/// Networked.</para>
	/// </summary>
	int color_map{};

	/// <summary>
	/// <para>The team that this entity belongs to. 0 For no team.<br/>
	/// The engine will check this to see if auto aim should snap to this entity.<br/>
	/// Entities on the same team are never targeted by auto aim.</para>
	/// </summary>
	int team{};

	/// <summary>
	/// <para>Maximum health that this entity can have.<br/>
	/// Entities cannot have a health higher than this when given using GiveHealth.<br/>
	/// Also used by some entities as a counter.<br/>
	/// The engine does not access this.</para>
	/// </summary>
	float max_health{};

	/// <summary>
	/// <para>Used in physics code as <c>PlayerMove::water_jump_time</c>, is save/restored.<br/>
	/// Copied to <c>ClientData::water_jump_time</c>.</para>
	/// </summary>
	float teleport_time{};

	/// <summary>
	/// <para>Never used, is save/restored.</para>
	/// </summary>
	float armor_type{};

	/// <summary>
	/// <para>The amount of armor that this player has.<br/>
	/// Also used by some entities for other purposes.</para>
	/// </summary>
	float armor_value{};

	/// <summary>
	/// <para>The current water level.<br/>
	/// Networked.</para>
	/// </summary>
	int water_level{};

	/// <summary>
	/// <para>The type of water the player is currently in.<br/>
	/// Only valid if the player is in water, is CONTENTS_EMPTY otherwise.</para>
	/// </summary>
	int water_type{};

	/// <summary>
	/// <para>Target name of the entity to trigger when this entity fires its targets.</para>
	/// </summary>
	Strind target;

	/// <summary>
	/// <para>Target name of this entity.</para>
	/// </summary>
	Strind target_name;

	/// <summary>
	/// <para>Name of this player. Set by players using the "name" command.<br/>
	/// Also used by other entities for various purposes.</para>
	/// </summary>
	Strind net_name;

	/// <summary>
	/// <para>Generic string member used by various entities. game_text stores its message here.</para>
	/// </summary>
	Strind message;

	/// <summary>
	/// <para>Tracks the amount of damage that the player took since the last time CBasePlayer::UpdateClientData was called, or since they spawned.<br/>
	/// Also used by other entities for various purposes.</para>
	/// </summary>
	float damage_take{};

	/// <summary>
	/// <para>Used by entities for various purposes.</para>
	/// </summary>
	float damage_save{};

	/// <summary>
	/// <para>Used by <c>MoveTypeEntity::PushStep</c> and <c>MoveTypeEntity::Step</c> while the entity is swimming.<br/>
	/// Damage taken while submerged.<br/>
	/// Engine handling is obsolete for players. The engine code has been superseded by game code player physics.</para>
	/// </summary>
	float damage{};

	/// <summary>
	/// <para>Used by <c>MoveTypeEntity::PushStep</c> and <c>MoveTypeEntity::Step</c> while the entity is swimming.<br/>
	/// Next time lava/slime damage should be taken.<br/>
	/// Engine handling is obsolete for players. The engine code has been superseded by game code player physics.</para>
	/// </summary>
	float damage_time{};

	/// <summary>
	/// <para>Generic string 1.</para>
	/// </summary>
	Strind noise;

	/// <summary>
	/// <para>Generic string 2.</para>
	/// </summary>
	Strind noise1;

	/// <summary>
	/// <para>Generic string 3.</para>
	/// </summary>
	Strind noise2;

	/// <summary>
	/// <para>Generic string 4.</para>
	/// </summary>
	Strind noise3;

	/// <summary>
	/// <para>The entity's movement speed, in units/second.</para>
	/// </summary>
	float speed{};

	/// <summary>
	/// <para>Used by <c>MoveTypeEntity::PushStep</c> and <c>MoveTypeEntity::Step</c> while the entity is swimming.<br/>
	/// When the entity runs out of air.<br/>
	/// Engine handling is obsolete for players. The engine code has been superseded by game code player physics.</para>
	/// </summary>
	float air_finished{};

	/// <summary>
	/// <para>Used by <c>MoveTypeEntity::PushStep</c> and <c>MoveTypeEntity::Step</c> while the entity is swimming.<br/>
	/// Next time drown damage should be taken.<br/>
	/// Engine handling is obsolete for players. The engine code has been superseded by game code player physics.</para>
	/// </summary>
	float pain_finished{};

	/// <summary>
	/// <para>Used by <c>MoveTypeEntity::PushStep</c> and <c>MoveTypeEntity::Step</c> while the entity is swimming.<br/>
	/// When the player's protection against lava/slime has run out.<br/>
	/// Engine handling is obsolete for players. The engine code has been superseded by game code player physics.</para>
	/// </summary>
	float rad_suit_finished{};

	/// <summary>
	/// <para>The <c>Edict</c> instance that this <c>EntityVars</c> instance belongs to.<br/>
	/// Should be <c>reinterpret_cast<Edict*>(reinterpret_cast<byte*>(&class_name) - offsetof(Edict, vars))</c>.</para>
	/// </summary>
	Edict* containing_entity{};

	/// <summary>
	/// <para>The player's class. Mod specific.<br/>
	/// If this is a <c>SolidType::Bsp</c>, this will determine whether damage decals will be applied to the bsp model.<br/>
	/// A setting of 1 enables damage decals.<br/>
	/// Networked.</para>
	/// </summary>
	int player_class{};

	/// <summary>
	/// <para>Maximum movement speed.<br/>
	/// Networked.</para>
	/// </summary>
	float max_speed{};

	/// <summary>
	/// <para>This player's field of view.<br/>
	/// Networked in <c>ClientData.</c></para>
	/// </summary>
	float field_of_view{};

	/// <summary>
	/// <para>The player's current weapon animation.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	int weapon_anim{};

	/// <summary>
	/// <para>Never used on the server side. This variable is completely unused.</para>
	/// </summary>
	int push_msec{};

	/// <summary>
	/// <para>Whether the player is currently ducking. This state is synchronized with <c>PlayerMove</c>.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	qboolean in_duck{};

	/// <summary>
	/// <para>Time until the next step sound should be played for this player. This state is synchronized with <c>PlayerMove</c>.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	int time_step_sound{};

	/// <summary>
	/// <para>Time until the next swim sound should be played for this player. This state is synchronized with <c>PlayerMove</c>.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	int swim_time{};

	/// <summary>
	/// <para>How much longer until the player is fully ducked. This state is synchronized with <c>PlayerMove</c>.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	int duck_time{};

	/// <summary>
	/// <para>Whether the last step sound was a left or right step sound. This state is synchronized with <c>PlayerMove</c>.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	int step_left{};

	/// <summary>
	/// <para>The player's current fall velocity. This state is synchronized with <c>PlayerMove</c>.<br/>
	/// Networked in <c>ClientData</c>.</para>
	/// </summary>
	float fall_velocity{};

	/// <summary>
	/// <para>Special variable used to tell the engine to skip the shield hit box for CS shield weapons.<br/>
	/// 0: don't skip.<br/>
	/// 1: skip.</para>
	/// </summary>
	int game_state{};

	/// <summary>
	/// <para>Player button states for the previous frame.<br/>
	/// Networked.</para>
	/// </summary>
	int old_buttons{};

	/// <summary>
	/// <para>Trace line group.</para>
	/// </summary>
	int group_info{};

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
	Edict* e_user1{};

	/// <summary>
	/// </summary>
	Edict* e_user2{};

	/// <summary>
	/// </summary>
	Edict* e_user3{};

	/// <summary>
	/// </summary>
	Edict* e_user4{};
};
