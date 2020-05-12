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
/// </summary>
constexpr auto SEQUENCE_MODIFIER_EFFECT_BIT = 1 << 1;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_POSITION_BIT = 1 << 2;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_COLOR_BIT = 1 << 3;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_COLOR2_BIT = 1 << 4;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_FADE_IN_BIT = 1 << 5;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_FADEOUT_BIT = 1 << 6;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_HOLD_TIME_BIT = 1 << 7;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_FX_TIME_BIT = 1 << 8;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_SPEAKER_BIT = 1 << 9;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_LISTENER_BIT = 1 << 10;

/// <summary>
/// </summary>
constexpr auto SEQUENCE_MODIFIER_TEXT_CHANNEL_BIT = 1 << 11;

/// <summary>
/// Enum SequenceCommandType
/// </summary>
enum class SequenceCommandType {
	/// <summary>
	/// </summary>
	Command,

	/// <summary>
	/// </summary>
	Modifier
};

/// <summary>
/// Struct ClientTextMessage
/// </summary>
struct ClientTextMessage {
	/// <summary>
	/// </summary>
	int effect{};

	/// <summary>
	/// </summary>
	byte r1{}, g1{}, b1{}, a1{};

	/// <summary>
	/// </summary>
	byte r2{}, g2{}, b2{}, a2{};

	/// <summary>
	/// </summary>
	float x{};

	/// <summary>
	/// </summary>
	float y{};

	/// <summary>
	/// </summary>
	float fade_in{};

	/// <summary>
	/// </summary>
	float fade_out{};

	/// <summary>
	/// </summary>
	float hold_time{};

	/// <summary>
	/// </summary>
	float fx_time{};

	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	const char* message{};
};

/// <summary>
/// <para>Structure representing a single command (usually 1 line) from a .SEQ file entry.</para>
/// </summary>
struct SequenceCommandLine {
	/// <summary>
	/// <para>Specifies the type of command.</para>
	/// </summary>
	SequenceCommandType command_type{};

	/// <summary>
	/// <para>Text HUD message struct.</para>
	/// </summary>
	ClientTextMessage client_message;

	/// <summary>
	/// <para>Target name of speaking entity.</para>
	/// </summary>
	char* speaker_name{};

	/// <summary>
	/// <para>Target name of entity being spoken to.</para>
	/// </summary>
	char* listener_name{};

	/// <summary>
	/// <para>Name of sound file to play.</para>
	/// </summary>
	char* sound_file_name{};

	/// <summary>
	/// <para>Name of sentences.txt to play.</para>
	/// </summary>
	char* sentence_name{};

	/// <summary>
	/// <para>List of target names to fire.</para>
	/// </summary>
	char* fire_target_names{};

	/// <summary>
	/// <para>List of target names to remove.</para>
	/// </summary>
	char* kill_target_names{};

	/// <summary>
	/// <para>Seconds 'till next command.</para>
	/// </summary>
	float delay{};

	/// <summary>
	/// <para>If nonzero, reset execution pointer to top of block (N times, -1 = infinite).</para>
	/// </summary>
	int repeat_count{};

	/// <summary>
	/// <para>Display channel on which text message is sent.</para>
	/// </summary>
	int text_channel{};

	/// <summary>
	/// <para>Bit field to specify what client message fields are valid.</para>
	/// </summary>
	int modifier_bit_field{};

	/// <summary>
	/// <para>Next command (linked list).</para>
	/// </summary>
	SequenceCommandLine* next_command_line{};
};

/// <summary>
/// <para>Structure representing a single command (usually 1 line) from a .SEQ file entry.</para>
/// </summary>
struct SequenceEntry {
	/// <summary>
	/// <para>Name of sequence file without .SEQ extension.</para>
	/// </summary>
	char* file_name{};

	/// <summary>
	/// <para>Name of entry label in file.</para>
	/// </summary>
	char* entry_name{};

	/// <summary>
	/// <para>Linked list of commands in entry.</para>
	/// </summary>
	SequenceCommandLine* first_command{};

	/// <summary>
	/// <para>Next loaded entry.</para>
	/// </summary>
	SequenceEntry* next_entry{};

	/// <summary>
	/// <para>Is entry retained over level transitions?</para>
	/// </summary>
	qboolean is_global{};
};

/// <summary>
/// <para>Structure representing a single sentence of a group from a .SEQ file entry.<br/>
/// Sentences are identical to entries in sentences.txt, but can be unique per level and are loaded/unloaded with the level.</para>
/// </summary>
struct SentenceEntry {
	/// <summary>
	/// <para>Sentence data (ie "We have hostiles").</para>
	/// </summary>
	char* data{};

	/// <summary>
	/// <para>Next loaded entry</para>
	/// </summary>
	SentenceEntry* next_entry{};

	/// <summary>
	/// <para>Is entry retained over level transitions?</para>
	/// </summary>
	qboolean is_global{};

	/// <summary>
	/// <para>This entry's position in the file.</para>
	/// </summary>
	unsigned int index{};
};
