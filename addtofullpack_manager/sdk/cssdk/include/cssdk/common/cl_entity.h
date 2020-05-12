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
#include <cssdk/public/base_types.h>
#include <cssdk/public/vector.h>

/// <summary>
/// <para>Must be power of 2.</para>
/// </summary>
constexpr auto HISTORY_MAX = 64;

/// <summary>
/// </summary>
constexpr auto HISTORY_MASK = HISTORY_MAX - 1;

/// <summary>
/// </summary>
struct Model;

/// <summary>
/// </summary>
struct MLeaf;

/// <summary>
/// </summary>
struct MNode;

/// <summary>
/// </summary>
struct ClEntity;

/// <summary>
/// Struct EFrag
/// </summary>
struct EFrag {
	/// <summary>
	/// </summary>
	MLeaf* leaf{};

	/// <summary>
	/// </summary>
	EFrag* leaf_next{};

	/// <summary>
	/// </summary>
	ClEntity* entity{};

	/// <summary>
	/// </summary>
	EFrag* ent_next{};
};

/// <summary>
/// Struct Mouth
/// </summary>
struct Mouth {
	/// <summary>
	/// <para>0 = mouth closed, 255 = mouth agape.</para>
	/// </summary>
	byte mouth_open{};

	/// <summary>
	/// <para>Counter for running average.</para>
	/// </summary>
	byte snd_count{};

	/// <summary>
	/// <para>Running average.</para>
	/// </summary>
	int snd_avg{};
};

/// <summary>
/// Struct LatchedVars
/// </summary>
struct LatchedVars {
	/// <summary>
	/// </summary>
	float prev_anim_time{};

	/// <summary>
	/// </summary>
	float sequence_time{};

	/// <summary>
	/// </summary>
	byte prev_seq_blending[2]{};

	/// <summary>
	/// </summary>
	Vector prev_origin;

	/// <summary>
	/// </summary>
	Vector prev_angles;

	/// <summary>
	/// </summary>
	int prev_sequence{};

	/// <summary>
	/// </summary>
	float prev_frame{};

	/// <summary>
	/// </summary>
	byte prev_controller[4]{};

	/// <summary>
	/// </summary>
	byte prev_blending[2]{};
};

/// <summary>
/// Struct PositionHistory
/// </summary>
struct PositionHistory {
	/// <summary>
	/// <para>Time stamp for this movement.</para>
	/// </summary>
	float anim_time{};

	/// <summary>
	/// </summary>
	Vector origin;

	/// <summary>
	/// </summary>
	Vector angles;
};

/// <summary>
/// Struct ClEntity
/// </summary>
struct ClEntity {
	/// <summary>
	/// <para>Index into cl_entities (should match actual slot, but not necessarily).</para>
	/// </summary>
	int index{};

	/// <summary>
	/// <para>True if this entity is a "player".</para>
	/// </summary>
	qboolean player{};

	/// <summary>
	/// <para>The original state from which to delta during an uncompressed message.</para>
	/// </summary>
	EntityState baseline;

	/// <summary>
	/// <para>The state information from the penultimate message received from the server.</para>
	/// </summary>
	EntityState prev_state;

	/// <summary>
	/// <para>The state information from the last message received from server.</para>
	/// </summary>
	EntityState cur_state;

	/// <summary>
	/// <para>Last received history update index.</para>
	/// </summary>
	int current_position{};

	/// <summary>
	/// <para>History of position and angle updates for this player.</para>
	/// </summary>
	PositionHistory position_history[HISTORY_MAX];

	/// <summary>
	/// <para>For synchronizing mouth movements.</para>
	/// </summary>
	Mouth mouth;

	/// <summary>
	/// <para>Variables used by studio model rendering routines.</para>
	/// </summary>
	LatchedVars latched;

	/// <summary>
	/// <para>Information based on interplocation, extrapolation, prediction, or just copied from last msg received.</para>
	/// </summary>
	float last_move{};

	/// <summary>
	/// <para>Actual render position and angles.</para>
	/// </summary>
	Vector origin;

	/// <summary>
	/// </summary>
	Vector angles;

	/// <summary>
	/// <para>Attachment points.</para>
	/// </summary>
	Vector attachment[4];

	/// <summary>
	/// <para>Other entity local information.</para>
	/// </summary>
	int trivial_accept{};

	/// <summary>
	/// <para>cl.model_precache[curstate.modelindes]; all visible entities have a model.</para>
	/// </summary>
	Model* model{};

	/// <summary>
	/// <para>linked list of EFrag.</para>
	/// </summary>
	EFrag* e_frag{};

	/// <summary>
	/// <para>For bmodels, first world node that splits bmodel, or NULL if not split.</para>
	/// </summary>
	MNode* top_node{};

	/// <summary>
	/// <para>For client-side animations -- used by obsolete alias animation system, remove?</para>
	/// </summary>
	float sync_base{};

	/// <summary>
	/// <para>Last frame this entity was found in an active leaf.</para>
	/// </summary>
	int vis_frame{};

	/// <summary>
	/// </summary>
	ColorVec floor_color;
};
