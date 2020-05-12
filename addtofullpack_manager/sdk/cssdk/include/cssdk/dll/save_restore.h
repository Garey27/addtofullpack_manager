// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/engine/edict.h>
#include <cssdk/public/strind.h>
#include <cssdk/public/vector.h>

/// <summary>
/// <para>These are encoded in the lower 16 bits of <c>EntityTable::flags</c>.</para>
/// </summary>
constexpr auto MAX_LEVEL_CONNECTIONS = 16;

/// <summary>
/// <para>This field is masked for global entity save/restore.</para>
/// </summary>
constexpr auto FTYPE_DESC_GLOBAL = 0x0001;

/// <summary>
/// <para>This is a global entity.<br/>
/// The engine uses this to merge changes made to global entities.</para>
/// </summary>
constexpr auto FENT_TABLE_GLOBAL = 0x10000000;

/// <summary>
/// <para>Entities that return <c>FCAP_ACROSS_TRANSITION</c> from <c>ObjectCaps</c> are flagged with this.</para>
/// </summary>
constexpr auto FENT_TABLE_MOVEABLE = 0x20000000;

/// <summary>
/// <para>Flags the entity as having been removed.<br/>
/// Done by the engine when reading .HL1 save patch files.</para>
/// </summary>
constexpr auto FENT_TABLE_REMOVED = 0x40000000;

/// <summary>
/// <para>This entity is a player.</para>
/// </summary>
constexpr auto FENT_TABLE_PLAYER = 0x80000000;

/// <summary>
/// Enum FieldType
/// </summary>
enum class FieldType {
	/// <summary>
	/// <para>Any floating point value.</para>
	/// </summary>
	FieldFloat = 0,

	/// <summary>
	/// <para>A string ID (return from alloc_string).</para>
	/// </summary>
	FieldString,

	/// <summary>
	/// <para>An entity offset.</para>
	/// </summary>
	FieldEntity,

	/// <summary>
	/// <para><c>EntityBase*</c>.</para>
	/// </summary>
	FieldClassPtr,

	/// <summary>
	/// <para>Entity handle.</para>
	/// </summary>
	FieldEntHandle,

	/// <summary>
	/// <para><c>EntityVars*</c>.</para>
	/// </summary>
	FieldEntVars,

	/// <summary>
	/// <para><c>Edict*</c>.</para>
	/// </summary>
	FieldEdict,

	/// <summary>
	/// <para>Any vector.</para>
	/// </summary>
	FieldVector,

	/// <summary>
	/// <para>A world coordinate (these are fixed up across level transitions automagically).</para>
	/// </summary>
	FieldPositionVector,

	/// <summary>
	/// <para>Arbitrary data pointer... to be removed, use an array of <c>field_character</c>.</para>
	/// </summary>
	FieldPointer,

	/// <summary>
	/// <para>Any integer or enum.</para>
	/// </summary>
	FieldInteger,

	/// <summary>
	/// <para>A class function pointer (think, use, etc).</para>
	/// </summary>
	FieldFunction,

	/// <summary>
	/// <para>Boolean, implemented as an int, I may use this as a hint for compression.</para>
	/// </summary>
	FieldBoolean,

	/// <summary>
	/// <para>2 byte integer.</para>
	/// </summary>
	FieldShort,

	/// <summary>
	/// <para>A byte.</para>
	/// </summary>
	FieldCharacter,

	/// <summary>
	/// <para>A floating point time (these are fixed up automatically too!).</para>
	/// </summary>
	FieldTime,

	/// <summary>
	/// <para>Engine string that is a model name (needs precache).</para>
	/// </summary>
	FieldModelName,

	/// <summary>
	/// <para>Engine string that is a sound name (needs precache).</para>
	/// </summary>
	FieldSoundName,

	/// <summary>
	/// <para>Must be last.</para>
	/// </summary>
	FieldTypeCount
};

/// <summary>
/// Struct TypeDescription
/// </summary>
struct TypeDescription {
	/// <summary>
	/// </summary>
	FieldType type{};

	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	int offset{};

	/// <summary>
	/// </summary>
	short size{};

	/// <summary>
	/// </summary>
	short flags{};
};

/// <summary>
/// <para>Represents a transition to another level.</para>
/// </summary>
struct LevelList {
	/// <summary>
	/// <para>Name of the map to transition to.</para>
	/// </summary>
	char map_name[32]{};

	/// <summary>
	/// <para>Name of the landmark in this and the next map.</para>
	/// </summary>
	char landmark_name[32]{};

	/// <summary>
	/// <para>Landmark entity.</para>
	/// </summary>
	Edict* ent_landmark{};

	/// <summary>
	/// <para>Landmark origin in this map.</para>
	/// </summary>
	Vector landmark_origin;
};

/// <summary>
/// <para>Describes one entity in the save restore data.</para>
/// </summary>
struct EntityTable {
	/// <summary>
	/// <para>The identifier</para>
	/// </summary>
	int id{};

	/// <summary>
	/// <para>Pointer to the in-game entity.</para>
	/// </summary>
	Edict* entity{};

	/// <summary>
	/// <para>Offset from the base data of this entity.</para>
	/// </summary>
	int location{};

	/// <summary>
	/// <para>Byte size of this entity's data.</para>
	/// </summary>
	int size{};

	/// <summary>
	/// <para>This could be a short -- bit mask of transitions that this entity is in the PVS of.</para>
	/// </summary>
	unsigned int flags{};

	/// <summary>
	/// <para>Entity class name.</para>
	/// </summary>
	Strind class_name;
};

/// <summary>
/// <para>Save data for a single level.</para>
/// </summary>
struct SaveRestoreData {
	/// <summary>
	/// <para>Start of all entity save data.</para>
	/// </summary>
	char* base_data{};

	/// <summary>
	/// <para>Current buffer pointer for sequential access.</para>
	/// </summary>
	char* current_data{};

	/// <summary>
	/// <para>Current data size.</para>
	/// </summary>
	int size{};

	/// <summary>
	/// <para>Total space for data.</para>
	/// </summary>
	int buffer_size{};

	/// <summary>
	/// <para>Size of the linear list of tokens.</para>
	/// </summary>
	int token_size{};

	/// <summary>
	/// <para>Number of elements in the tokens table.</para>
	/// </summary>
	int token_count{};

	/// <summary>
	/// <para>Hash table of entity strings (sparse).</para>
	/// </summary>
	char** tokens{};

	/// <summary>
	/// <para>Holds a global entity table ID.</para>
	/// </summary>
	int current_index{};

	/// <summary>
	/// <para>Number of elements in the entity table.</para>
	/// </summary>
	int table_count{};

	/// <summary>
	/// <para>Number of elements in the LevelList[].</para>
	/// </summary>
	int connection_count{};

	/// <summary>
	/// <para>Array of <c>EntityTable</c> elements (1 for each entity).</para>
	/// </summary>
	EntityTable* table{};

	/// <summary>
	/// <para>List of connections from this level.</para>
	/// </summary>
	LevelList lvl_list[MAX_LEVEL_CONNECTIONS];

	/// <summary>
	/// <para>Smooth transition.</para>
	/// </summary>
	int use_landmark{};

	/// <summary>
	/// <para>Landmark we'll spawn near in next level.</para>
	/// </summary>
	char landmark_name[20]{};

	/// <summary>
	/// <para>For landmark transitions.</para>
	/// </summary>
	Vector landmark_offset;

	/// <summary>
	/// <para>Game time when the save game was written.</para>
	/// </summary>
	float time{};

	/// <summary>
	/// <para>To check global entities.</para>
	/// </summary>
	char current_map_name[32]{};
};

/// <summary>
/// Class Save.
/// </summary>
class Save;

/// <summary>
/// Class Restore.
/// </summary>
class Restore;
