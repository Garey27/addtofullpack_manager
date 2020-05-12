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
#include <cssdk/common/cvar.h>
#include <cssdk/common/entity_state.h>
#include <cssdk/common/net_address.h>
#include <cssdk/common/sequence.h>
#include <cssdk/common/user_cmd.h>
#include <cssdk/common/weapon_data.h>
#include <cssdk/dll/monsters.h>
#include <cssdk/dll/save_restore.h>
#include <cssdk/engine/custom.h>
#include <cssdk/engine/edict.h>
#include <cssdk/pm_shared/pm_defs.h>
#include <cssdk/public/arch_types.h>
#include <cssdk/public/base_types.h>
#include <cssdk/public/strind.h>
#include <cssdk/public/vector.h>

#ifdef HLDEMO_BUILD
/// <summary>
/// </summary>
constexpr auto INTERFACE_VERSION = 001;
#else
/// <summary>
/// </summary>
constexpr auto INTERFACE_VERSION = 140;
#endif

/// <summary>
/// </summary>
constexpr auto ENGINE_INTERFACE_VERSION = 138;

/// <summary>
/// </summary>
constexpr auto DLL_NEW_FUNCTIONS_VERSION = 1;

/// <summary>
/// </summary>
constexpr auto TR_IGNORE_NONE = 0;

/// <summary>
/// <para>Ignore monsters (entities that don't have <c>MoveTypeEntity::PushStep</c>).</para>
/// </summary>
constexpr auto TR_IGNORE_MONSTERS = 1;

/// <summary>
/// <para>Use missile bounds <c>(-15 -15 -15, 15, 15, 15)</c>.</para>
/// </summary>
constexpr auto TR_IGNORE_MISSILE = 2;

/// <summary>
/// <para>Ignore transparent entities.<br/>
/// Transparent entities have a render mode other than <c>RENDER_NORMAL</c> and don't have the flag <c>FL_WORLD_BRUSH</c> set.<br/></para>
/// <remarks>
/// Aside from TR_IGNORE_GLASS, all flags are mutually exclusive and cannot be used in combination with each other.
/// </remarks>
/// </summary>
constexpr auto TR_IGNORE_GLASS = 0x100;

/// <summary>
/// Enum PrintType
/// </summary>
enum class PrintType {
	/// <summary>
	/// </summary>
	Console,

	/// <summary>
	/// </summary>
	Center,

	/// <summary>
	/// </summary>
	Chat
};

/// <summary>
/// Enum AlertType
/// </summary>
enum class AlertType {
	/// <summary>
	/// </summary>
	Notice,

	/// <summary>
	/// <para>Same as <c>Notice</c>, but forces a <c>con_print</c>, not a message box.</para>
	/// </summary>
	Console,

	/// <summary>
	/// <para>Same as <c>console</c>, but only shown if developer level is 2!</para>
	/// </summary>
	DevConsole,

	/// <summary>
	/// </summary>
	Warning,

	/// <summary>
	/// </summary>
	Error,

	/// <summary>
	/// <para>Server print to console (only in multiplayer games).</para>
	/// </summary>
	Logged
};

/// <summary>
/// <para>For integrity checking of content on clients.</para>
/// </summary>
enum class ForceType {
	/// <summary>
	/// <para>File on client must exactly match server's file.</para>
	/// </summary>
	ExactFile,

	/// <summary>
	/// <para>For model files only, the geometry must fit in the same bounding box.</para>
	/// </summary>
	ModelSameBounds,

	/// <summary>
	/// <para>For model files only, the geometry must fit in the specified bounding box.</para>
	/// </summary>
	ModelSpecifyBounds,

	/// <summary>
	/// <para>For Steam model files only, the geometry must fit in the specified bounding box (if the file is available).</para>
	/// </summary>
	ModelSpecifyBoundsIfAvail
};

/// <summary>
/// <para>Returned by trace_line.</para>
/// </summary>
struct TraceResult {
	/// <summary>
	/// <para>If true, plane is not valid.</para>
	/// </summary>
	qboolean all_solid{};

	/// <summary>
	/// <para>If true, the initial point was in a solid area.</para>
	/// </summary>
	qboolean start_solid{};

	/// <summary>
	/// <para>Trace crossed open space.</para>
	/// </summary>
	qboolean in_open{};

	/// <summary>
	/// <para>Trace crossed a water boundary.</para>
	/// </summary>
	qboolean in_water{};

	/// <summary>
	/// <para>How far the trace went until hitting something.<br/>
	/// This is a fraction of end - start, equal to <c>(end_pos - start).length() / (end - start).length()</c><br/>
	/// If 1.0, the trace didn't hit anything.<br/></para>
	/// </summary>
	float fraction{};

	/// <summary>
	/// <para>Final position.</para>
	/// </summary>
	Vector end_position;

	/// <summary>
	/// <para>Distance from origin that the plane is positioned at.<br/>
	/// <c>plane_normal * plane_dist</c> represents a point that lies on the plane.</para>
	/// </summary>
	float plane_distance{};

	/// <summary>
	/// <para>Surface normal at impact.</para>
	/// </summary>
	Vector plane_normal;

	/// <summary>
	/// <para>Entity the surface is on.</para>
	/// </summary>
	Edict* entity_hit{};

	/// <summary>
	/// <para>Hit specific body part.</para>
	/// </summary>
	HitBoxGroup hit_group{};
};

/// <summary>
/// <para>Passed to <c>Key_value</c></para>
/// </summary>
struct KeyValueData {
	/// <summary>
	/// <para>In: entity class name.</para>
	/// </summary>
	char* class_name{};

	/// <summary>
	/// <para>In: name of key.</para>
	/// </summary>
	char* key_name{};

	/// <summary>
	/// <para>In: value of key.</para>
	/// </summary>
	char* value{};

	/// <summary>
	/// <para>Out: DLL sets to true if key-value pair was understood.</para>
	/// </summary>
	qboolean handled{};
};

/// <summary>
/// <para>Engine hands this to DLLs for functionality callbacks.</para>
/// </summary>
struct EngineFuncPointers {
	/// <summary>
	/// <para>Precaches a model.</para>
	/// </summary>
	int (*precache_model)(const char* path){};

	/// <summary>
	/// <para>Precaches a sound.</para>
	/// </summary>
	int (*precache_sound)(const char* path){};

	/// <summary>
	/// <para>Sets the model of the given entity. Also changes the entity bounds based on the model.</para>
	/// </summary>
	void (*set_model)(Edict* entity, const char* model){};

	/// <summary>
	/// <para>Gets the index of the given model.</para>
	/// </summary>
	int (*model_index)(const char* model){};

	/// <summary>
	/// <para>Gets the number of frames in the given model.</para>
	/// </summary>
	int (*model_frames)(int model_index){};

	/// <summary>
	/// <para>Sets the entity bounds. Also relinks the entity.</para>
	/// </summary>
	void (*set_size)(Edict* entity, const Vector& min, const Vector& max){};

	/// <summary>
	/// <para>Changes the level. This will append a change level command to the server command buffer.</para>
	/// </summary>
	void (*change_level)(const char* level_name, const char* landmark_name){};

	/// <summary>
	/// <para>Does nothing useful. Will trigger a host error if the given entity is not a client.</para>
	/// </summary>
	void (*get_spawn_params)(Edict* client){};

	/// <summary>
	/// <para>Does nothing useful. Will trigger a host error if the given entity is not a client.</para>
	/// </summary>
	void (*save_spawn_params)(Edict* client){};

	/// <summary>
	/// <para>Converts a direction vector to a yaw angle.</para>
	/// </summary>
	float (*vec_to_yaw)(const Vector& direction){};

	/// <summary>
	/// <para>Converts a direction vector to angles.</para>
	/// </summary>
	void (*vec_to_angles)(const Vector& direction_in, Vector& angles_out){};

	/// <summary>
	/// <para>Moves the given entity to the given destination.</para>
	/// </summary>
	void (*move_to_origin)(Edict* entity, const Vector& goal, float distance, MoveTypeNpc move_type){};

	/// <summary>
	/// <para>Changes the entity's yaw angle to approach its ideal yaw.</para>
	/// </summary>
	void (*change_yaw)(Edict* entity){};

	/// <summary>
	/// <para>Changes the entity's pitch angle to approach its ideal pitch.</para>
	/// </summary>
	void (*change_pitch)(Edict* entity){};

	/// <summary>
	/// <para>Finds an entity by comparing strings.</para>
	/// </summary>
	Edict* (*find_entity_by_string)(Edict* edict_start_search_after, const char* field, const char* value){};

	/// <summary>
	/// </summary>
	int (*get_entity_illumination)(Edict* entity){};

	/// <summary>
	/// <para>Finds an entity in a sphere.</para>
	/// </summary>
	Edict* (*find_entity_in_sphere)(Edict* edict_start_search_after, const Vector& origin, float radius){};

	/// <summary>
	/// <para>Finds a client in the potentially visible set.</para>
	/// </summary>
	Edict* (*find_client_in_pvs)(Edict* entity){};

	/// <summary>
	/// <para>Find entities in potentially visible set.</para>
	/// </summary>
	Edict* (*entities_in_pvs)(Edict* entity){};

	/// <summary>
	/// <para>Make direction vectors from angles.</para>
	/// </summary>
	void (*make_vectors)(const Vector& angles){};

	/// <summary>
	/// <para>Make direction vectors from angles.</para>
	/// </summary>
	void (*angle_vectors)(const Vector& angles, Vector& forward, Vector& right, Vector& up){};

	/// <summary>
	/// <para>Allocates an entity dictionary for use with an entity.</para>
	/// </summary>
	Edict* (*create_entity)(){};

	/// <summary>
	/// <para>Immediately removes the given entity.</para>
	/// </summary>
	void (*remove_entity)(Edict* entity){};

	/// <summary>
	/// <para>Creates an entity of the class <c>class_name</c>.</para>
	/// </summary>
	Edict* (*create_named_entity)(Strind class_name){};

	/// <summary>
	/// <para>Makes an entity static. Static entities are copied to the client side and are removed on the server side.</para>
	/// </summary>
	void (*make_static)(Edict* entity){};

	/// <summary>
	/// </summary>
	qboolean (*ent_is_on_floor)(Edict* entity){};

	/// <summary>
	/// <para>Drops the entity to the floor.</para>
	/// </summary>
	int (*drop_to_floor)(Edict* entity){};

	/// <summary>
	/// <para>Makes the entity walk.</para>
	/// </summary>
	qboolean (*walk_move)(Edict* entity, float yaw, float dist, WalkMoveMode mode){};

	/// <summary>
	/// <para>Sets the origin of the given entity.</para>
	/// </summary>
	void (*set_origin)(Edict* entity, const Vector& origin){};

	/// <summary>
	/// <para>Emits a sounds from the given entity.</para>
	/// </summary>
	void (*emit_sound)(Edict* entity, SoundChannel channel, const char* sample, float volume, float attenuation, int flags, int pitch){};

	/// <summary>
	/// <para>Emits a sounds from the given entity.</para>
	/// </summary>
	void (*emit_ambient_sound)(Edict* entity, Vector& origin, const char* sample, float volume, float attenuation, int flags, int pitch){};

	/// <summary>
	/// <para>Performs a trace between a starting and ending position.</para>
	/// </summary>
	void (*trace_line)(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, Edict* entity_to_ignore, TraceResult* result){};

	/// <summary>
	/// <para>Traces a toss.</para>
	/// </summary>
	void (*trace_toss)(Edict* entity, Edict* entity_to_ignore, TraceResult* result){};

	/// <summary>
	/// <para>Performs a trace between a starting and ending position, using the given entity's min size and max size.</para>
	/// </summary>
	qboolean (*trace_monster_hull)(Edict* entity, const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, Edict* entity_to_ignore, TraceResult* result){};

	/// <summary>
	/// <para>Performs a trace between a starting and ending position, using the specified hull.</para>
	/// </summary>
	void (*trace_hull)(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, int hull_number, Edict* entity_to_ignore, TraceResult* result){};

	/// <summary>
	/// <para>Performs a trace between a starting and ending position.<br/>
	/// Similar to <c>trace_hull</c>, but will instead perform a trace in the given world hull using the given entity's model's hulls.<br/>
	/// For studio models this will use the model's hit boxes.
	/// </para>
	/// </summary>
	void (*trace_model)(const Vector& start_pos, const Vector& end_pos, int hull_number, Edict* entity, TraceResult* result){};

	/// <summary>
	/// <para>Used to get texture info.</para>
	/// </summary>
	const char* (*trace_texture)(Edict* texture_entity, const Vector& start_pos, const Vector& end_pos){};

	/// <summary>
	/// <para>Not implemented. Triggers a sys error.</para>
	/// </summary>
	void (*trace_sphere)(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, float radius, Edict* entity_to_ignore, TraceResult* result){};

	/// <summary>
	/// <para>Get the aim vector for the given entity.<br/>
	/// Assumes <c>make_vectors</c> was called with <c>entity->vars.angles</c> beforehand.</para>
	/// </summary>
	void (*get_aim_vector)(Edict* entity, float speed, Vector& vec_return){};

	/// <summary>
	/// <para>Issues a command to the server.</para>
	/// </summary>
	void (*server_command)(const char* command){};

	/// <summary>
	/// <para>Executes all pending server commands.</para>
	/// </summary>
	void (*server_execute)(){};

	/// <summary>
	/// <para>Sends a client command to the given client.</para>
	/// </summary>
	void (*client_command)(Edict* client, const char* format, ...){};

	/// <summary>
	/// <para>Creates a particle effect.</para>
	/// </summary>
	void (*particle_effect)(const Vector& origin, const Vector& direction, float color, float count){};

	/// <summary>
	/// <para>Sets the given light style to the given value.</para>
	/// </summary>
	void (*light_style)(int style, const char* value){};

	/// <summary>
	/// <para>Gets the index of the given decal.</para>
	/// </summary>
	int (*decal_index)(const char* name){};

	/// <summary>
	/// <para>Gets the contents of the given location in the world.</para>
	/// </summary>
	int (*point_contents)(const Vector& origin){};

	/// <summary>
	/// <para>Begins a new network message.</para>
	/// </summary>
	void (*message_begin)(MessageType msg_type, int msg_id, const vec_t* origin, Edict* client){};

	/// <summary>
	/// <para>Ends a network message.</para>
	/// </summary>
	void (*message_end)(){};

	/// <summary>
	/// <para>Writes a single unsigned byte.</para>
	/// </summary>
	void (*write_byte)(int value){};

	/// <summary>
	/// <para>Writes a single character.</para>
	/// </summary>
	void (*write_char)(int value){};

	/// <summary>
	/// <para>Writes a single unsigned short.</para>
	/// </summary>
	void (*write_short)(int value){};

	/// <summary>
	/// <para>Writes a single unsigned int.</para>
	/// </summary>
	void (*write_long)(int value){};

	/// <summary>
	/// <para>Writes a single angle value.</para>
	/// </summary>
	void (*write_angle)(float value){};

	/// <summary>
	/// <para>Writes a single coordinate value.</para>
	/// </summary>
	void (*write_coord)(float value){};

	/// <summary>
	/// <para>Writes a single null terminated string.</para>
	/// </summary>
	void (*write_string)(const char* value){};

	/// <summary>
	/// <para>Writes a single entity index.</para>
	/// </summary>
	void (*write_entity)(int value){};

	/// <summary>
	/// <para>Registers a console variable.</para>
	/// </summary>
	void (*cvar_register)(CVar* cvar){};

	/// <summary>
	/// <para>Gets the value of console variable as a float.</para>
	/// </summary>
	float (*cvar_get_float)(const char* cvar_name){};

	/// <summary>
	/// <para>Gets the value of console variable as a string.</para>
	/// </summary>
	const char* (*cvar_get_string)(const char* cvar_name){};

	/// <summary>
	/// <para>Sets the value of console variable as a float.</para>
	/// </summary>
	void (*cvar_set_float)(const char* cvar_name, float value){};

	/// <summary>
	/// <para>Sets the value of console variable as a string.</para>
	/// </summary>
	void (*cvar_set_string)(const char* cvar_name, const char* value){};

	/// <summary>
	/// <para>Outputs a message to the server console.</para>
	/// </summary>
	void (*alert_message)(AlertType type, const char* format, ...){};

	/// <summary>
	/// <para>Obsolete. Will print a message to the server console using alert_message indicating if it's being used.</para>
	/// </summary>
	void (*engine_file_print)(void* file, const char* format, ...){};

	/// <summary>
	/// <para>Allocates memory for <c>EntityBase</c> instances.</para>
	/// </summary>
	void* (*alloc_ent_private_data)(Edict* entity, int32 size){};

	/// <summary>
	/// </summary>
	void* (*ent_private_data)(Edict* entity){};

	/// <summary>
	/// <para>Frees the <c>EntityBase</c> memory assigned to entity.</para>
	/// </summary>
	void (*free_ent_private_data)(Edict* entity){};

	/// <summary>
	/// <para>Gets the string assigned to the index.</para>
	/// </summary>
	const char* (*sz_from_index)(Strind string){};

	/// <summary>
	/// <para>Allocates a string in the string pool.</para>
	/// </summary>
	Strind (*alloc_string)(const char* value){};

	/// <summary>
	/// <para>Gets the <c>EntityVars</c> instance assigned to the given entity instance.</para>
	/// </summary>
	EntityVars* (*get_vars_of_ent)(Edict* entity){};

	/// <summary>
	/// <para>Gets an entity by offset.<br/>
	/// This uses the byte offset of the entity to retrieve it.<br/>
	/// DO NOT USE THIS. Use the <c>entity_of_ent_index</c> instead.</para>
	/// </summary>
	Edict* (*entity_of_ent_offset)(eoffset entity_offset){};

	/// <summary>
	/// <para>Gets the entity offset of the entity.</para>
	/// </summary>
	eoffset (*ent_offset_of_entity)(const Edict* entity){};

	/// <summary>
	/// <para>Gets the entity index of the entity dictionary.</para>
	/// </summary>
	int (*index_of_edict)(const Edict* edict){};

	/// <summary>
	/// <para>Gets the entity at the given entity index.</para>
	/// </summary>
	Edict* (*entity_of_ent_index)(int entity_index){};

	/// <summary>
	/// <para>Gets the entity of an <c>EntityVars</c>.</para>
	/// </summary>
	Edict* (*find_entity_by_vars)(EntityVars* vars){};

	/// <summary>
	/// <para>Gets the model pointer of the given entity.</para>
	/// </summary>
	void* (*get_model_pointer)(Edict* entity){};

	/// <summary>
	/// <para>Registers a user message.</para>
	/// </summary>
	int (*reg_user_message)(const char* name, int size){};

	/// <summary>
	/// <para>Does nothing.</para>
	/// </summary>
	void (*animation_auto_move)(const Edict* entity, float time){};

	/// <summary>
	/// <para>Gets the bone position and angles for the given entity and bone.</para>
	/// </summary>
	void (*get_bone_position)(const Edict* entity, int bone, Vector& origin, Vector& angles){};

	/// <summary>
	/// <para>Gets the index of an exported function.</para>
	/// </summary>
	uint32 (*function_from_name)(const char* name){};

	/// <summary>
	/// <para>Gets the name of an exported function.</para>
	/// </summary>
	const char* (*name_for_function)(uint32 function){};

	/// <summary>
	/// <para>Sends a message to the client console.</para>
	/// </summary>
	void (*client_print)(Edict* entity, PrintType type, const char* message){};

	/// <summary>
	/// <para>Sends a message to the server console.<br/>
	/// The message is output regardless of the value of the developer cvar.</para>
	/// </summary>
	void (*server_print)(const char* message){};

	/// <summary>
	/// </summary>
	const char* (*cmd_args)(){};

	/// <summary>
	/// <para>Gets the command argument at the given index.</para>
	/// </summary>
	const char* (*cmd_argv)(int argc){};

	/// <summary>
	/// </summary>
	int (*cmd_argc)(){};

	/// <summary>
	/// <para>Gets the attachment origin and angles.</para>
	/// </summary>
	void (*get_attachment)(const Edict* entity, int attachment, Vector& origin, Vector& angles){};

	/// <summary>
	/// <para>Initializes the CRC instance.</para>
	/// </summary>
	void (*crc32_init)(crc32* pul_crc){};

	/// <summary>
	/// <para>Processes a buffer and updates the CRC.</para>
	/// </summary>
	void (*crc32_process_buffer)(crc32* pul_crc, void* buffer, int len){};

	/// <summary>
	/// <para>Processes a single byte.</para>
	/// </summary>
	void (*crc32_process_byte)(crc32* pul_crc, unsigned char ch){};

	/// <summary>
	/// <para>Finalizes the CRC instance.</para>
	/// </summary>
	crc32 (*crc32_final)(crc32 pul_crc){};

	/// <summary>
	/// <para>Generates a random long number in the range [low, high].</para>
	/// </summary>
	int32 (*random_long)(int32 low, int32 high){};

	/// <summary>
	/// <para>Generates a random float number in the range [low, high].</para>
	/// </summary>
	float (*random_float)(float low, float high){};

	/// <summary>
	/// <para>Sets the view of a client to the given entity.</para>
	/// </summary>
	void (*set_view)(const Edict* client, const Edict* view_entity){};

	/// <summary>
	/// </summary>
	float (*time)(){};

	/// <summary>
	/// <para>Sets the angles of the given client's crosshairs to the given settings.</para>
	/// </summary>
	void (*crosshair_angle)(const Edict* client, float pitch, float yaw){};

	/// <summary>
	/// <para>Loads a file from disk.</para>
	/// </summary>
	byte* (*load_file_for_me)(const char* file_name, int* length){};

	/// <summary>
	/// <para>Frees the buffer provided by the <c>load_file_for_me</c>.</para>
	/// </summary>
	void (*free_file)(void* buffer){};

	/// <summary>
	/// <para>Signals the engine that a section has ended.</para>
	/// </summary>
	void (*end_section)(const char* section_name){};

	/// <summary>
	/// <para>Compares file times.</para>
	/// </summary>
	qboolean (*compare_file_time)(char* file_name1, char* file_name2, int* compare){};

	/// <summary>
	/// <para>Gets the game directory name.</para>
	/// </summary>
	void (*get_game_dir)(char* game_dir){};

	/// <summary>
	/// <para>Registers a Cvar. Identical to <c>cvar_register</c>, except it doesn't set the <c>FCVAR_EXT_DLL</c> flag.</para>
	/// </summary>
	void (*cvar_register_variable)(CVar* variable){};

	/// <summary>
	/// <para>Fades the given client's volume.</para>
	/// </summary>
	void (*fade_client_volume)(const Edict* client, int fade_percent, int fade_out_seconds, int hold_time, int fade_in_seconds){};

	/// <summary>
	/// <para>Sets the client's maximum speed value.</para>
	/// </summary>
	void (*set_client_max_speed)(Edict* client, float new_max_speed){};

	/// <summary>
	/// <para>Creates a fake client (bot).</para>
	/// </summary>
	Edict* (*create_fake_client)(const char* name){};

	/// <summary>
	/// <para>Runs client movement for a fake client.</para>
	/// </summary>
	void (*run_player_move)(Edict* fake_client, const Vector& view_angles, float forward_move, float side_move,
	                        float up_move, unsigned short buttons, byte impulse, byte msec){};

	/// <summary>
	/// <para>Computes the total number of entities currently in existence.</para>
	/// </summary>
	int (*number_of_entities)(){};

	/// <summary>
	/// <para>Gets the given client's info key buffer.</para>
	/// </summary>
	char* (*get_info_key_buffer)(Edict* client){};

	/// <summary>
	/// <para>Gets the value of the given key from the given buffer.</para>
	/// </summary>
	char* (*info_key_value)(char* info_buffer, const char* key){};

	/// <summary>
	/// <para>Sets the value of the given key in the given buffer.</para>
	/// </summary>
	void (*set_key_value)(char* info_buffer, const char* key, const char* value){};

	/// <summary>
	/// <para>Sets the value of the given key in the given buffer.</para>
	/// </summary>
	void (*set_client_key_value)(int client_index, char* info_buffer, const char* key, const char* value){};

	/// <summary>
	/// <para>Checks if the given file_name is a valid map.</para>
	/// </summary>
	qboolean (*is_map_valid)(const char* file_name){};

	/// <summary>
	/// <para>Projects a static decal in the world.</para>
	/// </summary>
	void (*static_decal)(const Vector& origin, int decal_index, int entity_index, int model_index){};

	/// <summary>
	/// <para>Precaches a file.</para>
	/// </summary>
	int (*precache_generic)(const char* path){};

	/// <summary>
	/// <para>Returns the server assigned user id for this client.</para>
	/// </summary>
	int (*get_player_user_id)(Edict* client){};

	/// <summary>
	/// <para>Builds a sound message to send to a client.</para>
	/// </summary>
	void (*build_sound_msg)(Edict* entity, int channel, const char* sample, float volume, float attenuation, int flags, int pitch,
	                        MessageType msg_type, int msg_id, const Vector& origin, Edict* client){};

	/// <summary>
	/// </summary>
	qboolean (*is_dedicated_server)(){};

	/// <summary>
	/// </summary>
	CVar* (*cvar_get_pointer)(const char* cvar_name){};

	/// <summary>
	/// <para>Returns the server assigned WON id for this client.</para>
	/// </summary>
	unsigned int (*get_player_won_id)(Edict* client){};

	/// <summary>
	/// <para>Removes a key from the info buffer.</para>
	/// </summary>
	void (*info_remove_key)(char* info_buffer, const char* key){};

	/// <summary>
	/// <para>Gets the given physics key-value from the given client's buffer.</para>
	/// </summary>
	const char* (*get_physics_key_value)(const Edict* client, const char* key){};

	/// <summary>
	/// <para>Sets the given physics key-value in the given client's buffer.</para>
	/// </summary>
	void (*set_physics_key_value)(const Edict* client, const char* key, const char* value){};

	/// <summary>
	/// <para>Gets the physics info string for the given client.</para>
	/// </summary>
	const char* (*get_physics_info_string)(const Edict* client){};

	/// <summary>
	/// <para>Precaches an event.</para>
	/// </summary>
	unsigned short (*precache_event)(int type, const char* path){};

	/// <summary>
	/// </summary>
	void (*playback_event)(int flags, const Edict* invoker, unsigned short event_index, float delay, Vector& origin, Vector& angles,
	                       float f_param1, float f_param2, int i_param1, int i_param2, qboolean b_param1, qboolean b_param2){};

	/// <summary>
	/// <para>Sets the fat potentially visible set buffer to contain data based on the given origin.</para>
	/// </summary>
	unsigned char* (*set_fat_pvs)(Vector& origin){};

	/// <summary>
	/// <para>Sets the fat potentially audible set buffer to contain data based on the given origin.</para>
	/// </summary>
	unsigned char* (*set_fat_pas)(Vector& origin){};

	/// <summary>
	/// <para>Checks if the given entity is visible in the given visible set.</para>
	/// </summary>
	qboolean (*check_visibility)(Edict* entity, unsigned char* set){};

	/// <summary>
	/// <para>Marks the given field in the given list as set.</para>
	/// </summary>
	void (*delta_set_field)(struct delta* fields, const char* field_name){};

	/// <summary>
	/// <para>Marks the given field in the given list as not set.</para>
	/// </summary>
	void (*delta_unset_field)(struct delta* fields, const char* field_name){};

	/// <summary>
	/// <para>Adds a delta encoder.</para>
	/// </summary>
	void (*delta_add_encoder)(const char* name, void (*conditional_encode)(struct delta* fields, const unsigned char* from, const unsigned char* to)){};

	/// <summary>
	/// </summary>
	int (*get_current_player)(){};

	/// <summary>
	/// </summary>
	qboolean (*can_skip_player)(const Edict* client){};

	/// <summary>
	/// <para>Finds the index of a delta field.</para>
	/// </summary>
	int (*delta_find_field)(struct delta* fields, const char* field_name){};

	/// <summary>
	/// <para>Marks a delta field as set by index.</para>
	/// </summary>
	void (*delta_set_field_by_index)(struct delta* fields, int field_number){};

	/// <summary>
	/// <para>Marks a delta field as not set by index.</para>
	/// </summary>
	void (*delta_unset_field_by_index)(struct delta* fields, int field_number){};

	/// <summary>
	/// <para>Used to filter contents checks.</para>
	/// </summary>
	void (*set_group_mask)(int mask, int operation){};

	/// <summary>
	/// <para>Creates an instanced baseline. Used to define a baseline for a particular entity type.</para>
	/// </summary>
	int (*create_instanced_baseline)(Strind class_name, EntityState* baseline){};

	/// <summary>
	/// <para>Directly sets a console variable value.</para>
	/// </summary>
	void (*cvar_direct_set)(CVar* cvar, const char* value){};

	/// <summary>
	/// <para>Forces the client and server to be running with the same version of the specified file (e.g., a client model).</para>
	/// </summary>
	void (*force_unmodified)(ForceType type, Vector& min_size, Vector& max_size, const char* file_name){};

	/// <summary>
	/// <para>Get client statistics.</para>
	/// </summary>
	void (*get_player_stats)(const Edict* client, int* ping, int* packet_loss){};

	/// <summary>
	/// <para>Adds a server command.</para>
	/// </summary>
	void (*add_server_command)(const char* cmd_name, void (*callback)()){};

	/// <summary>
	/// <para>Gets whether the given receiver can hear the given sender.</para>
	/// </summary>
	qboolean (*voice_get_client_listening)(int receiver, int sender){};

	/// <summary>
	/// <para>Sets whether the given receiver can hear the given sender.</para>
	/// </summary>
	qboolean (*voice_set_client_listening)(int receiver, int sender, qboolean listen){};

	/// <summary>
	/// <para>Gets the client's auth ID.</para>
	/// </summary>
	const char* (*get_player_auth_id)(Edict* client){};

	/// <summary>
	/// <para>Gets the sequence that has the given entry name.</para>
	/// </summary>
	SequenceEntry* (*sequence_get)(const char* file_name, const char* entry_name){};

	/// <summary>
	/// <para>Picks a sentence from the given group.</para>
	/// </summary>
	SentenceEntry* (*sequence_pick_sentence)(const char* group_name, int pick_method, int* picked){};

	/// <summary>
	/// <para>LH: Give access to file size via filesystem.</para>
	/// </summary>
	int (*get_file_size)(const char* file_name){};

	/// <summary>
	/// <para>Gets the average wave length in seconds.</para>
	/// </summary>
	unsigned int (*get_approx_wave_play_len)(const char* file_path){};

	/// <summary>
	/// </summary>
	qboolean (*is_career_match)(){};

	/// <summary>
	/// </summary>
	int (*get_localized_string_length)(const char* label){};

	/// <summary>
	/// <para>Marks the message with the given ID as having been shown.</para>
	/// </summary>
	void (*register_tutor_message_shown)(int message_id){};

	/// <summary>
	/// <para>Gets the number of times the message with the given ID has been shown.</para>
	/// </summary>
	int (*get_times_tutor_message_shown)(int message_id){};

	/// <summary>
	/// <para>Processes the tutor message decay buffer.</para>
	/// </summary>
	void (*process_tutor_message_decay_buffer)(int* buffer, int buffer_length){};

	/// <summary>
	/// <para>Constructs the tutor message decay buffer.</para>
	/// </summary>
	void (*construct_tutor_message_decay_buffer)(int* buffer, int buffer_length){};

	/// <summary>
	/// <para>Resets tutor message decay data.</para>
	/// </summary>
	void (*reset_tutor_message_decay_data)(){};

	/// <summary>
	/// <para>Queries the given client for a cvar value.</para>
	/// </summary>
	void (*query_client_cvar_value)(const Edict* client, const char* cvar_name){};

	/// <summary>
	/// <para>Queries the given client for a cvar value.</para>
	/// </summary>
	void (*query_client_cvar_value2)(const Edict* client, const char* cvar_name, int request_id){};

	/// <summary>
	/// <para>Checks if a command line parameter was provided.</para>
	/// </summary>
	int (*eng_check_param)(const char* cmd_line_token, char** next){};
};

/// <summary>
/// <para>Server library interface to the engine.</para>
/// </summary>
struct DllFuncPointers {
	/// <summary>
	/// <para>Called when the game loads this DLL.</para>
	/// </summary>
	void (*game_init)(){};

	/// <summary>
	/// <para>Called by the engine to spawn an entity.</para>
	/// </summary>
	int (*spawn)(Edict* entity){};

	/// <summary>
	/// <para>Called by the engine to run this entity's think function.</para>
	/// </summary>
	void (*think)(Edict* entity){};

	/// <summary>
	/// <para>Called by the engine to trigger <c>entity_used</c>'s <c>use</c> function, using <c>entity_other</c> as the activator and caller.<br/>
	/// Obsolete. This is never called by the engine.</para>
	/// </summary>
	void (*use)(Edict* entity_used, Edict* entity_other){};

	/// <summary>
	/// <para>Called by the engine to run <c>entity_touched</c>'s <c>touch</c> function with <c>entity_other</c> as the other entity.</para>
	/// </summary>
	void (*touch)(Edict* entity_touched, Edict* entity_other){};

	/// <summary>
	/// <para>Called by the engine to run <c>entity_blocked</c>'s <c>blocked</c> function with <c>entity_other</c> as the other entity.</para>
	/// </summary>
	void (*blocked)(Edict* entity_blocked, Edict* entity_other){};

	/// <summary>
	/// <para>Called by the engine to run <c>entity_key_value</c>'s <c>key_value</c> function with <c>data</c> as the key-value data.</para>
	/// </summary>
	void (*key_value)(Edict* entity_key_value, KeyValueData* data){};

	/// <summary>
	/// <para>Called by the engine to save the given entity's state to the given save data block.</para>
	/// </summary>
	void (*save)(Edict* entity, SaveRestoreData* save_data){};

	/// <summary>
	/// <para>Called by the engine to restore the given entity's state from the given save data block.</para>
	/// </summary>
	int (*restore)(Edict* entity, SaveRestoreData* save_data, qboolean global_entity){};

	/// <summary>
	/// <para>Called by the engine to set the given entity's absolute bounding box.</para>
	/// </summary>
	void (*set_abs_box)(Edict* entity){};

	/// <summary>
	/// <para>Called by the engine to save a named block of data to the given save data block.</para>
	/// </summary>
	void (*save_write_fields)(SaveRestoreData* save_data, const char* name, void* base_data, TypeDescription* fields, int field_count){};

	/// <summary>
	/// <para>Called by the engine to restore a named block of data from the given save data block.</para>
	/// </summary>
	void (*save_read_fields)(SaveRestoreData* save_data, const char* name, void* base_data, TypeDescription* fields, int field_count){};

	/// <summary>
	/// <para>Called by the engine to save global state.</para>
	/// </summary>
	void (*save_global_state)(SaveRestoreData* save_data){};

	/// <summary>
	/// <para>Called by the engine to restore global state.</para>
	/// </summary>
	void (*restore_global_state)(SaveRestoreData* save_data){};

	/// <summary>
	/// <para>Called by the engine to reset global state.</para>
	/// </summary>
	void (*reset_global_state)(){};

	/// <summary>
	/// <para>Called by the engine when a client connects.<br/>
	/// Returning false rejects the client's connection. Setting <c>reject_reason</c> presents that to the client.</para>
	/// </summary>
	qboolean (*client_connect)(Edict* client, const char* name, const char* address, char reject_reason[128]){};

	/// <summary>
	/// <para>Called when a client disconnects.<br/>
	/// This will not be called if the client connection was rejected in <c>client_connect</c>.</para>
	/// </summary>
	void (*client_disconnect)(Edict* client){};

	/// <summary>
	/// <para>Called by the engine when the player has issued a "kill" command.<br/>
	/// Only if the player's health is larger than 0.</para>
	/// </summary>
	void (*client_kill)(Edict* client){};

	/// <summary>
	/// <para>Called by the engine when the client has finished connecting.<br/>
	/// This is where the player should be spawned and put into the world, or given a spectator position to view from.</para>
	/// </summary>
	void (*client_put_in_server)(Edict* client){};

	/// <summary>
	/// <para>Called by the engine when it has received a command from the given client.</para>
	/// </summary>
	void (*client_command)(Edict* client){};

	/// <summary>
	/// <para>Called by the engine whenever the client's user info string changes.<br/>
	/// This includes the player's model.</para>
	/// </summary>
	void (*client_user_info_changed)(Edict* client, char* info_buffer){};

	/// <summary>
	/// <para>Called when the engine has finished spawning the map.</para>
	/// </summary>
	void (*server_activate)(Edict* edict_list, int edict_count, int client_max){};

	/// <summary>
	/// <para>Called when the map has ended.<br/>
	/// This happens before entities are destroyed.</para>
	/// </summary>
	void (*server_deactivate)(){};

	/// <summary>
	/// <para>Called by the engine before it runs physics.</para>
	/// </summary>
	void (*player_pre_think)(Edict* client){};

	/// <summary>
	/// <para>Called by the engine after it runs physics.</para>
	/// </summary>
	void (*player_post_think)(Edict* client){};

	/// <summary>
	/// <para>Called at the start of a server game frame.</para>
	/// </summary>
	void (*start_frame)(){};

	/// <summary>
	/// <para>Obsolete.</para>
	/// </summary>
	void (*params_new_level)(){};

	/// <summary>
	/// <para>Called by the engine when a level is saved.<br/>
	/// Also called when a player has spawned after a saved game has been loaded.</para>
	/// </summary>
	void (*params_change_level)(){};

	/// <summary>
	/// <para>Returns string describing current .dll. E.g., TeamFortress 2, Half-Life.</para>
	/// </summary>
	const char* (*get_game_description)(){};

	/// <summary>
	/// <para>Notify dll about a player customization.</para>
	/// </summary>
	void (*player_customization)(Edict* client, Customization* custom){};

	/// <summary>
	/// <para>Called when a HLTV spectator has connected.</para>
	/// </summary>
	void (*spectator_connect)(Edict* client){};

	/// <summary>
	/// <para>Called when a HLTV spectator has disconnected.</para>
	/// </summary>
	void (*spectator_disconnect)(Edict* client){};

	/// <summary>
	/// <para>Called when a HLTV spectator's think function has to run.</para>
	/// </summary>
	void (*spectator_think)(Edict* client){};

	/// <summary>
	/// <para>Notify game .dll that engine is going to shut down. Allows mod authors to set a breakpoint.</para>
	/// </summary>
	void (*sys_error)(const char* error_string){};

	/// <summary>
	/// <para>Called by the engine to run player physics.</para>
	/// </summary>
	void (*pm_move)(PlayerMove* move, qboolean server){};

	/// <summary>
	/// <para>Called by the engine to initialize the player physics data.</para>
	/// </summary>
	void (*pm_init)(PlayerMove* move){};

	/// <summary>
	/// <para>Called by the engine to find the texture type of a given texture.</para>
	/// </summary>
	char (*pm_find_texture_type)(char* name){};

	/// <summary>
	/// <para>Set up visibility for the given client.</para>
	/// </summary>
	void (*setup_visibility)(Edict* view_entity, Edict* client, unsigned char** pvs, unsigned char** pas){};

	/// <summary>
	/// <para>Updates the given client's data.<br/>
	/// This function can be used to implement first person observer views.</para>
	/// </summary>
	void (*update_client_data)(const Edict* client, qboolean send_weapons, ClientData* data){};

	/// <summary>
	/// <para>Called by the engine to determine whether the given entity should be added to the given client's list of visible entities.</para>
	/// </summary>
	int (*add_to_full_pack)(EntityState* state, int entity_index, Edict* entity, Edict* host, int host_flags, qboolean player, unsigned char* set){};

	/// <summary>
	/// <para>Called by the engine to create a baseline for the given entity.</para>
	/// </summary>
	void (*create_baseline)(qboolean client, int entity_index, EntityState* baseline, Edict* entity, int player_model_index, Vector player_min_size,
	                        Vector player_max_size){};

	/// <summary>
	/// <para>Called by the engine to allow the server to register delta encoders.</para>
	/// </summary>
	void (*register_encoders)(){};

	/// <summary>
	/// <para>Called by the engine to retrieve weapon data.</para>
	/// </summary>
	qboolean (*get_weapon_data)(Edict* client, WeaponData* info){};

	/// <summary>
	/// <para>Called by the engine when a user command has been received and is about to begin processing.</para>
	/// </summary>
	void (*cmd_start)(const Edict* client, const UserCmd* cmd, unsigned int random_seed){};

	/// <summary>
	/// <para>Called by the engine when a user command has finished processing.</para>
	/// </summary>
	void (*cmd_end)(const Edict* client){};

	/// <summary>
	/// <para>Return 1 if the packet is valid. Set response_buffer_size if you want to send a response packet.<br/>
	/// Incoming, it holds the max size of the <c>response_buffer</c>, so you must zero it out if you choose not to respond.</para>
	/// </summary>
	qboolean (*connectionless_packet)(const NetAddress* net_from, const char* args, char* response_buffer, int* response_buffer_size){};

	/// <summary>
	/// <para>Enumerates player hulls. Returns 0 if the hull number doesn't exist, 1 otherwise.</para>
	/// </summary>
	qboolean (*get_hull_bounds)(int hull_number, Vector& min_size, Vector& max_size){};

	/// <summary>
	/// <para>Create baselines for certain "unplaced" items.</para>
	/// </summary>
	void (*create_instanced_baselines)(){};

	/// <summary>
	/// <para>One of the <c>force_unmodified</c> files failed the consistency check for the specified player.<br/>
	/// Return 0 to allow the client to continue, 1 to force immediate disconnection (with an optional disconnect message of up to 256 characters).</para>
	/// </summary>
	qboolean (*inconsistent_file)(const Edict* client, const char* file_name, char* disconnect_message){};

	/// <summary>
	/// <para>The game .dll should return 1 if lag compensation should be allowed (could also just set the sv_unlag cvar).<br/>
	/// Most games right now should return 0, until client-side weapon prediction code is written and tested for them.</para>
	/// </summary>
	qboolean (*allow_lag_compensation)(){};
};

/// <summary>
/// <para>Additional server interface to the engine.</para>
/// </summary>
struct DllNewFuncPointers {
	/// <summary>
	/// <para>Called when an entity is freed by the engine, right before the object's memory is freed.<br/>
	/// Calls <c>OnDestroy</c> and runs the destructor.</para>
	/// </summary>
	void (*free_entity_private_data)(Edict* entity){};

	/// <summary>
	/// <para>Called when the game unloads this DLL.</para>
	/// </summary>
	void (*game_shutdown)(){};

	/// <summary>
	/// <para>Called when the engine believes two entities are about to collide.<br/>
	/// Return 0 if you want the two entities to just pass through each other without colliding or calling the touch function.</para>
	/// </summary>
	qboolean (*should_collide)(Edict* entity_touched, Edict* entity_other){};

	/// <summary>
	/// <para>Called when the engine has received a cvar value from the client in response to an <c>EngineFuncPointers::query_client_cvar_value</c> call.</para>
	/// </summary>
	void (*cvar_value)(const Edict* client, const char* value){};

	/// <summary>
	/// <para>Called when the engine has received a cvar value from the client in response to a <c>EngineFuncPointers::query_client_cvar_value2</c> call.</para>
	/// </summary>
	void (*cvar_value2)(const Edict* client, int request_id, const char* cvar_name, const char* value){};
};
