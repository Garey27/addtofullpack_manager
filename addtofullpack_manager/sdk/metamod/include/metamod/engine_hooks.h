// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <cssdk/engine/eiface.h>
#include <metamod/os_dep.h>
#include <cstring>
#include <type_traits>

/// <summary>
/// </summary>
extern "C" void DLLEXPORT Meta_Init();

/// <summary>
/// <para>Exports the engine hooks.</para>
/// </summary>
int export_engine_hooks(EngineFuncPointers* function_table, int* interface_version);

/// <summary>
/// <para>Exports the engine post hooks.</para>
/// </summary>
int export_engine_post_hooks(EngineFuncPointers* function_table, int* interface_version);

/// <summary>
/// <para>Class EngineHooks.</para>
/// </summary>
class EngineHooks {
	friend void DLLEXPORT Meta_Init();
	friend int export_engine_hooks(EngineFuncPointers*, int*);
	friend int export_engine_post_hooks(EngineFuncPointers*, int*);

	/// <summary>
	/// <para>Engine hooks table.</para>
	/// </summary>
	static EngineFuncPointers* engine_hooks_;

	/// <summary>
	/// <para>Engine post hooks table.</para>
	/// </summary>
	static EngineFuncPointers* engine_post_hooks_;

public:
	/// <summary>
	/// <para>Clears all hooks.</para>
	/// </summary>
	static void clear_all_hooks()
	{
		if (engine_hooks_ != nullptr)
			std::memset(static_cast<void*>(engine_hooks_), 0, sizeof(EngineFuncPointers));

		if (engine_post_hooks_ != nullptr)
			std::memset(static_cast<void*>(engine_post_hooks_), 0, sizeof(EngineFuncPointers));
	}

	/// <summary>
	/// <para>Precaches a model.</para>
	/// </summary>
	static void precache_model(const std::add_pointer_t<int(const char* path)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::precache_model, callback, post);
	}

	/// <summary>
	/// <para>Precaches a sound.</para>
	/// </summary>
	static void precache_sound(const std::add_pointer_t<int(const char* path)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::precache_sound, callback, post);
	}

	/// <summary>
	/// <para>Sets the model of the given entity. Also changes the entity bounds based on the model.</para>
	/// </summary>
	static void set_model(const std::add_pointer_t<void(Edict* entity, const char* model)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_model, callback, post);
	}

	/// <summary>
	/// <para>Gets the index of the given model.</para>
	/// </summary>
	static void model_index(const std::add_pointer_t<int(const char* model)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::model_index, callback, post);
	}

	/// <summary>
	/// <para>Gets the number of frames in the given model.</para>
	/// </summary>
	static void model_frames(const std::add_pointer_t<int(int model_index)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::model_frames, callback, post);
	}

	/// <summary>
	/// <para>Sets the entity bounds. Also relinks the entity.</para>
	/// </summary>
	static void set_size(const std::add_pointer_t<void(Edict* entity, const Vector& min, const Vector& max)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_size, callback, post);
	}

	/// <summary>
	/// <para>Changes the level. This will append a change level command to the server command buffer.</para>
	/// </summary>
	static void change_level(const std::add_pointer_t<void(const char* level_name, const char* landmark_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::change_level, callback, post);
	}

	/// <summary>
	/// <para>Does nothing useful. Will trigger a host error if the given entity is not a client.</para>
	/// </summary>
	static void get_spawn_params(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_spawn_params, callback, post);
	}

	/// <summary>
	/// <para>Does nothing useful. Will trigger a host error if the given entity is not a client.</para>
	/// </summary>
	static void save_spawn_params(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::save_spawn_params, callback, post);
	}

	/// <summary>
	/// <para>Converts a direction vector to a yaw angle.</para>
	/// </summary>
	static void vec_to_yaw(const std::add_pointer_t<float(const Vector& direction)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::vec_to_yaw, callback, post);
	}

	/// <summary>
	/// <para>Converts a direction vector to angles.</para>
	/// </summary>
	static void vec_to_angles(const std::add_pointer_t<void(const Vector& direction_in, Vector& angles_out)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::vec_to_angles, callback, post);
	}

	/// <summary>
	/// <para>Moves the given entity to the given destination.</para>
	/// </summary>
	static void move_to_origin(const std::add_pointer_t<void(Edict* entity, const Vector& goal, float distance, MoveTypeNpc move_type)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::move_to_origin, callback, post);
	}

	/// <summary>
	/// <para>Changes the entity's yaw angle to approach its ideal yaw.</para>
	/// </summary>
	static void change_yaw(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::change_yaw, callback, post);
	}

	/// <summary>
	/// <para>Changes the entity's pitch angle to approach its ideal pitch.</para>
	/// </summary>
	static void change_pitch(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::change_pitch, callback, post);
	}

	/// <summary>
	/// <para>Finds an entity by comparing strings.</para>
	/// </summary>
	static void find_entity_by_string(const std::add_pointer_t<Edict*(Edict* edict_start_search_after, const char* field, const char* value)> callback,
	                                  const bool post = false)
	{
		set_hook(&EngineFuncPointers::find_entity_by_string, callback, post);
	}

	/// <summary>
	/// </summary>
	static void get_entity_illumination(const std::add_pointer_t<int(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_entity_illumination, callback, post);
	}

	/// <summary>
	/// <para>Finds an entity in a sphere.</para>
	/// </summary>
	static void find_entity_in_sphere(const std::add_pointer_t<Edict*(Edict* edict_start_search_after, const Vector& origin, float radius)> callback,
	                                  const bool post = false)
	{
		set_hook(&EngineFuncPointers::find_entity_in_sphere, callback, post);
	}

	/// <summary>
	/// <para>Finds a client in the potentially visible set.</para>
	/// </summary>
	static void find_client_in_pvs(const std::add_pointer_t<Edict*(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::find_client_in_pvs, callback, post);
	}

	/// <summary>
	/// <para>Find entities in potentially visible set.</para>
	/// </summary>
	static void entities_in_pvs(const std::add_pointer_t<Edict*(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::entities_in_pvs, callback, post);
	}

	/// <summary>
	/// <para>Make direction vectors from angles.</para>
	/// </summary>
	static void make_vectors(const std::add_pointer_t<void(const Vector& angles)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::make_vectors, callback, post);
	}

	/// <summary>
	/// <para>Make direction vectors from angles.</para>
	/// </summary>
	static void angle_vectors(const std::add_pointer_t<void(const Vector& angles, Vector& forward, Vector& right, Vector& up)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::angle_vectors, callback, post);
	}

	/// <summary>
	/// <para>Allocates an entity dictionary for use with an entity.</para>
	/// </summary>
	static void create_entity(const std::add_pointer_t<Edict*()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::create_entity, callback, post);
	}

	/// <summary>
	/// <para>Immediately removes the given entity.</para>
	/// </summary>
	static void remove_entity(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::remove_entity, callback, post);
	}

	/// <summary>
	/// <para>Creates an entity of the class <c>class_name</c>.</para>
	/// </summary>
	static void create_named_entity(const std::add_pointer_t<Edict*(Strind class_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::create_named_entity, callback, post);
	}

	/// <summary>
	/// <para>Makes an entity static. Static entities are copied to the client side and are removed on the server side.</para>
	/// </summary>
	static void make_static(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::make_static, callback, post);
	}

	/// <summary>
	/// </summary>
	static void ent_is_on_floor(const std::add_pointer_t<qboolean(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::ent_is_on_floor, callback, post);
	}

	/// <summary>
	/// <para>Drops the entity to the floor.</para>
	/// </summary>
	static void drop_to_floor(const std::add_pointer_t<int(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::drop_to_floor, callback, post);
	}

	/// <summary>
	/// <para>Makes the entity walk.</para>
	/// </summary>
	static void walk_move(const std::add_pointer_t<qboolean(Edict* entity, float yaw, float dist, WalkMoveMode mode)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::walk_move, callback, post);
	}

	/// <summary>
	/// <para>Sets the origin of the given entity.</para>
	/// </summary>
	static void set_origin(const std::add_pointer_t<void(Edict* entity, const Vector& origin)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_origin, callback, post);
	}

	/// <summary>
	/// <para>Emits a sounds from the given entity.</para>
	/// </summary>
	static void emit_sound(
		const std::add_pointer_t<void(Edict* entity, SoundChannel channel, const char* sample, float volume, float attenuation, int flags, int pitch)> callback,
		const bool post = false)
	{
		set_hook(&EngineFuncPointers::emit_sound, callback, post);
	}

	/// <summary>
	/// <para>Emits a sounds from the given entity.</para>
	/// </summary>
	static void emit_ambient_sound(
		const std::add_pointer_t<void(Edict* entity, Vector& origin, const char* sample, float volume, float attenuation, int flags, int pitch)> callback,
		const bool post = false)
	{
		set_hook(&EngineFuncPointers::emit_ambient_sound, callback, post);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position.</para>
	/// </summary>
	static void trace_line(
		const std::add_pointer_t<void(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, Edict* entity_to_ignore, TraceResult* result)> callback,
		const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_line, callback, post);
	}

	/// <summary>
	/// <para>Traces a toss.</para>
	/// </summary>
	static void trace_toss(const std::add_pointer_t<void(Edict* entity, Edict* entity_to_ignore, TraceResult* result)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_toss, callback, post);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position, using the given entity's min size and max size.</para>
	/// </summary>
	static void trace_monster_hull(const std::add_pointer_t<qboolean(Edict* entity, const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags,
	                                                                 Edict* entity_to_ignore, TraceResult* result)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_monster_hull, callback, post);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position, using the specified hull.</para>
	/// </summary>
	static void trace_hull(const std::add_pointer_t<void(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, int hull_number,
	                                                     Edict* entity_to_ignore, TraceResult* result)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_hull, callback, post);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position.<br/>
	/// Similar to <c>trace_hull</c>, but will instead perform a trace in the given world hull using the given entity's model's hulls.<br/>
	/// For studio models this will use the model's hit boxes.
	/// </para>
	/// </summary>
	static void trace_model(const std::add_pointer_t<void(const Vector& start_pos, const Vector& end_pos, int hull_number, Edict* entity, TraceResult* result)> callback,
	                        const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_model, callback, post);
	}

	/// <summary>
	/// <para>Used to get texture info.</para>
	/// </summary>
	static void trace_texture(const std::add_pointer_t<const char*(Edict* texture_entity, const Vector& start_pos, const Vector& end_pos)> callback,
	                          const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_texture, callback, post);
	}

	/// <summary>
	/// <para>Not implemented. Triggers a sys error.</para>
	/// </summary>
	static void trace_sphere(const std::add_pointer_t<void(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, float radius,
	                                                       Edict* entity_to_ignore, TraceResult* result)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::trace_sphere, callback, post);
	}

	/// <summary>
	/// <para>Get the aim vector for the given entity.<br/>
	/// Assumes <c>make_vectors</c> was called with <c>entity->vars.angles</c> beforehand.</para>
	/// </summary>
	static void get_aim_vector(const std::add_pointer_t<void(Edict* entity, float speed, Vector& vec_return)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_aim_vector, callback, post);
	}

	/// <summary>
	/// <para>Issues a command to the server.</para>
	/// </summary>
	static void server_command(const std::add_pointer_t<void(const char* command)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::server_command, callback, post);
	}

	/// <summary>
	/// <para>Executes all pending server commands.</para>
	/// </summary>
	static void server_execute(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::server_execute, callback, post);
	}

	/// <summary>
	/// <para>Sends a client command to the given client.</para>
	/// </summary>
	template <typename ...Args>
	static void client_command(const std::add_pointer_t<void(Edict* client, const char* format, Args&&... args)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::client_command, callback, post);
	}

	/// <summary>
	/// <para>Creates a particle effect.</para>
	/// </summary>
	static void particle_effect(const std::add_pointer_t<void(const Vector& origin, const Vector& direction, float color, float count)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::particle_effect, callback, post);
	}

	/// <summary>
	/// <para>Sets the given light style to the given value.</para>
	/// </summary>
	static void light_style(const std::add_pointer_t<void(int style, const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::light_style, callback, post);
	}

	/// <summary>
	/// <para>Gets the index of the given decal.</para>
	/// </summary>
	static void decal_index(const std::add_pointer_t<int(const char* name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::decal_index, callback, post);
	}

	/// <summary>
	/// <para>Gets the contents of the given location in the world.</para>
	/// </summary>
	static void point_contents(const std::add_pointer_t<int(const Vector& origin)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::point_contents, callback, post);
	}

	/// <summary>
	/// <para>Begins a new network message.</para>
	/// </summary>
	static void message_begin(const std::add_pointer_t<void(MessageType msg_type, int msg_id, const vec_t* origin, Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::message_begin, callback, post);
	}

	/// <summary>
	/// <para>Ends a network message.</para>
	/// </summary>
	static void message_end(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::message_end, callback, post);
	}

	/// <summary>
	/// <para>Writes a single unsigned byte.</para>
	/// </summary>
	static void write_byte(const std::add_pointer_t<void(int value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_byte, callback, post);
	}

	/// <summary>
	/// <para>Writes a single character.</para>
	/// </summary>
	static void write_char(const std::add_pointer_t<void(int value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_char, callback, post);
	}

	/// <summary>
	/// <para>Writes a single unsigned short.</para>
	/// </summary>
	static void write_short(const std::add_pointer_t<void(int value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_short, callback, post);
	}

	/// <summary>
	/// <para>Writes a single unsigned int.</para>
	/// </summary>
	static void write_long(const std::add_pointer_t<void(int value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_long, callback, post);
	}

	/// <summary>
	/// <para>Writes a single angle value.</para>
	/// </summary>
	static void write_angle(const std::add_pointer_t<void(float value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_angle, callback, post);
	}

	/// <summary>
	/// <para>Writes a single coordinate value.</para>
	/// </summary>
	static void write_coord(const std::add_pointer_t<void(float value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_coord, callback, post);
	}

	/// <summary>
	/// <para>Writes a single null terminated string.</para>
	/// </summary>
	static void write_string(const std::add_pointer_t<void(const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_string, callback, post);
	}

	/// <summary>
	/// <para>Writes a single entity index.</para>
	/// </summary>
	static void write_entity(const std::add_pointer_t<void(int value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::write_entity, callback, post);
	}

	/// <summary>
	/// <para>Registers a console variable.</para>
	/// </summary>
	static void cvar_register(const std::add_pointer_t<void(CVar* cvar)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_register, callback, post);
	}

	/// <summary>
	/// <para>Gets the value of console variable as a float.</para>
	/// </summary>
	static void cvar_get_float(const std::add_pointer_t<float(const char* cvar_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_get_float, callback, post);
	}

	/// <summary>
	/// <para>Gets the value of console variable as a string.</para>
	/// </summary>
	static void cvar_get_string(const std::add_pointer_t<const char*(const char* cvar_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_get_string, callback, post);
	}

	/// <summary>
	/// <para>Sets the value of console variable as a float.</para>
	/// </summary>
	static void cvar_set_float(const std::add_pointer_t<void(const char* cvar_name, float value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_set_float, callback, post);
	}

	/// <summary>
	/// <para>Sets the value of console variable as a string.</para>
	/// </summary>
	static void cvar_set_string(const std::add_pointer_t<void(const char* cvar_name, const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_set_string, callback, post);
	}

	/// <summary>
	/// <para>Outputs a message to the server console.</para>
	/// </summary>
	template <typename ...Args>
	static void alert_message(const std::add_pointer_t<void(AlertType type, const char* format, Args&&... args)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::alert_message, callback, post);
	}

	/// <summary>
	/// <para>Obsolete. Will print a message to the server console using alert_message indicating if it's being used.</para>
	/// </summary>
	template <typename ...Args>
	static void engine_file_print(const std::add_pointer_t<void(void* file, const char* format, Args&&... args)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::engine_file_print, callback, post);
	}

	/// <summary>
	/// <para>Allocates memory for <c>entity_base</c> instances.</para>
	/// </summary>
	static void alloc_ent_private_data(const std::add_pointer_t<void*(Edict* entity, int32 size)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::alloc_ent_private_data, callback, post);
	}

	/// <summary>
	/// </summary>
	static void ent_private_data(const std::add_pointer_t<void*(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::ent_private_data, callback, post);
	}

	/// <summary>
	/// <para>Frees the <c>entity_base</c> memory assigned to entity.</para>
	/// </summary>
	static void free_ent_private_data(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::free_ent_private_data, callback, post);
	}

	/// <summary>
	/// <para>Gets the string assigned to the index.</para>
	/// </summary>
	static void sz_from_index(const std::add_pointer_t<const char*(Strind string)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::sz_from_index, callback, post);
	}

	/// <summary>
	/// <para>Allocates a string in the string pool.</para>
	/// </summary>
	static void alloc_string(const std::add_pointer_t<Strind(const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::alloc_string, callback, post);
	}

	/// <summary>
	/// <para>Gets the <c>EntityVars</c> instance assigned to the given entity instance.</para>
	/// </summary>
	static void get_vars_of_ent(const std::add_pointer_t<EntityVars*(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_vars_of_ent, callback, post);
	}

	/// <summary>
	/// <para>Gets an entity by offset.<br/>
	/// This uses the byte offset of the entity to retrieve it.<br/>
	/// DO NOT USE THIS. Use the <c>entity_of_ent_index</c> instead.</para>
	/// </summary>
	static void entity_of_ent_offset(const std::add_pointer_t<Edict*(eoffset entity_offset)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::entity_of_ent_offset, callback, post);
	}

	/// <summary>
	/// <para>Gets the entity offset of the entity.</para>
	/// </summary>
	static void ent_offset_of_entity(const std::add_pointer_t<eoffset(const Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::ent_offset_of_entity, callback, post);
	}

	/// <summary>
	/// <para>Gets the entity index of the entity dictionary.</para>
	/// </summary>
	static void index_of_edict(const std::add_pointer_t<int(const Edict* edict)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::index_of_edict, callback, post);
	}

	/// <summary>
	/// <para>Gets the entity at the given entity index.</para>
	/// </summary>
	static void entity_of_ent_index(const std::add_pointer_t<Edict *(int entity_index)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::entity_of_ent_index, callback, post);
	}

	/// <summary>
	/// <para>Gets the entity of an <c>EntityVars</c>.</para>
	/// </summary>
	static void find_entity_by_vars(const std::add_pointer_t<Edict *(EntityVars* vars)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::find_entity_by_vars, callback, post);
	}

	/// <summary>
	/// <para>Gets the model pointer of the given entity.</para>
	/// </summary>
	static void get_model_pointer(const std::add_pointer_t<void*(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_model_pointer, callback, post);
	}

	/// <summary>
	/// <para>Registers a user message.</para>
	/// </summary>
	static void reg_user_message(const std::add_pointer_t<int(const char* name, int size)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::reg_user_message, callback, post);
	}

	/// <summary>
	/// <para>Does nothing.</para>
	/// </summary>
	static void animation_auto_move(const std::add_pointer_t<void(const Edict* entity, float time)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::animation_auto_move, callback, post);
	}

	/// <summary>
	/// <para>Gets the bone position and angles for the given entity and bone.</para>
	/// </summary>
	static void get_bone_position(const std::add_pointer_t<void(const Edict* entity, int bone, Vector& origin, Vector& angles)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_bone_position, callback, post);
	}

	/// <summary>
	/// <para>Gets the index of an exported function.</para>
	/// </summary>
	static void function_from_name(const std::add_pointer_t<uint32(const char* name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::function_from_name, callback, post);
	}

	/// <summary>
	/// <para>Gets the name of an exported function.</para>
	/// </summary>
	static void name_for_function(const std::add_pointer_t<const char*(uint32 function)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::name_for_function, callback, post);
	}

	/// <summary>
	/// <para>Sends a message to the client console.</para>
	/// </summary>
	static void client_print(const std::add_pointer_t<void(Edict* entity, PrintType type, const char* message)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::client_print, callback, post);
	}

	/// <summary>
	/// <para>Sends a message to the server console.<br/>
	/// The message is output regardless of the value of the developer cvar.</para>
	/// </summary>
	static void server_print(const std::add_pointer_t<void(const char* message)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::server_print, callback, post);
	}

	/// <summary>
	/// </summary>
	static void cmd_args(const std::add_pointer_t<const char*()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cmd_args, callback, post);
	}

	/// <summary>
	/// <para>Gets the command argument at the given index.</para>
	/// </summary>
	static void cmd_argv(const std::add_pointer_t<const char*(int argc)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cmd_argv, callback, post);
	}

	/// <summary>
	/// </summary>
	static void cmd_argc(const std::add_pointer_t<int()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cmd_argc, callback, post);
	}

	/// <summary>
	/// <para>Gets the attachment origin and angles.</para>
	/// </summary>
	static void get_attachment(const std::add_pointer_t<void(const Edict* entity, int attachment, Vector& origin, Vector& angles)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_attachment, callback, post);
	}

	/// <summary>
	/// <para>Initializes the CRC instance.</para>
	/// </summary>
	static void crc32_init(const std::add_pointer_t<void(crc32* pul_crc)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::crc32_init, callback, post);
	}

	/// <summary>
	/// <para>Processes a buffer and updates the CRC.</para>
	/// </summary>
	static void crc32_process_buffer(const std::add_pointer_t<void(crc32* pul_crc, void* buffer, int len)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::crc32_process_buffer, callback, post);
	}

	/// <summary>
	/// <para>Processes a single byte.</para>
	/// </summary>
	static void crc32_process_byte(const std::add_pointer_t<void(crc32* pul_crc, unsigned char ch)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::crc32_process_byte, callback, post);
	}

	/// <summary>
	/// <para>Finalizes the CRC instance.</para>
	/// </summary>
	static void crc32_final(const std::add_pointer_t<crc32(crc32 pul_crc)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::crc32_final, callback, post);
	}

	/// <summary>
	/// <para>Generates a random long number in the range [low, high].</para>
	/// </summary>
	static void random_long(const std::add_pointer_t<int32(int32 low, int32 high)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::random_long, callback, post);
	}

	/// <summary>
	/// <para>Generates a random float number in the range [low, high].</para>
	/// </summary>
	static void random_float(const std::add_pointer_t<float(float low, float high)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::random_float, callback, post);
	}

	/// <summary>
	/// <para>Sets the view of a client to the given entity.</para>
	/// </summary>
	static void set_view(const std::add_pointer_t<void(const Edict* client, const Edict* view_entity)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_view, callback, post);
	}

	/// <summary>
	/// </summary>
	static void time(const std::add_pointer_t<float()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::time, callback, post);
	}

	/// <summary>
	/// <para>Sets the angles of the given client's crosshairs to the given settings.</para>
	/// </summary>
	static void crosshair_angle(const std::add_pointer_t<void(const Edict* client, float pitch, float yaw)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::crosshair_angle, callback, post);
	}

	/// <summary>
	/// <para>Loads a file from disk.</para>
	/// </summary>
	static void load_file_for_me(const std::add_pointer_t<byte *(const char* file_name, int* length)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::load_file_for_me, callback, post);
	}

	/// <summary>
	/// <para>Frees the buffer provided by the <c>load_file_for_me</c>.</para>
	/// </summary>
	static void free_file(const std::add_pointer_t<void(void* buffer)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::free_file, callback, post);
	}

	/// <summary>
	/// <para>Signals the engine that a section has ended.</para>
	/// </summary>
	static void end_section(const std::add_pointer_t<void(const char* section_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::end_section, callback, post);
	}

	/// <summary>
	/// <para>Compares file times.</para>
	/// </summary>
	static void compare_file_time(const std::add_pointer_t<qboolean(char* file_name1, char* file_name2, int* compare)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::compare_file_time, callback, post);
	}

	/// <summary>
	/// <para>Gets the game directory name.</para>
	/// </summary>
	static void get_game_dir(const std::add_pointer_t<void(char* game_dir)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_game_dir, callback, post);
	}

	/// <summary>
	/// <para>Registers a Cvar. Identical to <c>cvar_register</c>, except it doesn't set the <c>FCVAR_EXT_DLL</c> flag.</para>
	/// </summary>
	static void cvar_register_variable(const std::add_pointer_t<void(CVar* variable)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_register_variable, callback, post);
	}

	/// <summary>
	/// <para>Fades the given client's volume.</para>
	/// </summary>
	static void fade_client_volume(
		const std::add_pointer_t<void(const Edict* client, int fade_percent, int fade_out_seconds, int hold_time, int fade_in_seconds)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::fade_client_volume, callback, post);
	}

	/// <summary>
	/// <para>Sets the client's maximum speed value.</para>
	/// </summary>
	static void set_client_max_speed(const std::add_pointer_t<void(Edict* client, float new_max_speed)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_client_max_speed, callback, post);
	}

	/// <summary>
	/// <para>Creates a fake client (bot).</para>
	/// </summary>
	static void create_fake_client(const std::add_pointer_t<Edict *(const char* name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::create_fake_client, callback, post);
	}

	/// <summary>
	/// <para>Runs client movement for a fake client.</para>
	/// </summary>
	static void run_player_move(const std::add_pointer_t<void(Edict* fake_client, const Vector& view_angles, float forward_move, float side_move, float up_move,
	                                                          unsigned short buttons, byte impulse, byte msec)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::run_player_move, callback, post);
	}

	/// <summary>
	/// <para>Computes the total number of entities currently in existence.</para>
	/// </summary>
	static void number_of_entities(const std::add_pointer_t<int()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::number_of_entities, callback, post);
	}

	/// <summary>
	/// <para>Gets the given client's info key buffer.</para>
	/// </summary>
	static void get_info_key_buffer(const std::add_pointer_t<char*(Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_info_key_buffer, callback, post);
	}

	/// <summary>
	/// <para>Gets the value of the given key from the given buffer.</para>
	/// </summary>
	static void info_key_value(const std::add_pointer_t<char*(char* info_buffer, const char* key)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::info_key_value, callback, post);
	}

	/// <summary>
	/// <para>Sets the value of the given key in the given buffer.</para>
	/// </summary>
	static void set_key_value(const std::add_pointer_t<void(char* info_buffer, const char* key, const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_key_value, callback, post);
	}

	/// <summary>
	/// <para>Sets the value of the given key in the given buffer.</para>
	/// </summary>
	static void set_client_key_value(const std::add_pointer_t<void(int client_index, char* info_buffer, const char* key, const char* value)> callback,
	                                 const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_client_key_value, callback, post);
	}

	/// <summary>
	/// <para>Checks if the given file_name is a valid map.</para>
	/// </summary>
	static void is_map_valid(const std::add_pointer_t<qboolean(const char* file_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::is_map_valid, callback, post);
	}

	/// <summary>
	/// <para>Projects a static decal in the world.</para>
	/// </summary>
	static void static_decal(const std::add_pointer_t<void(const Vector& origin, int decal_index, int entity_index, int model_index)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::static_decal, callback, post);
	}

	/// <summary>
	/// <para>Precaches a file.</para>
	/// </summary>
	static void precache_generic(const std::add_pointer_t<int(const char* path)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::precache_generic, callback, post);
	}

	/// <summary>
	/// <para>Returns the server assigned user id for this client.</para>
	/// </summary>
	static void get_player_user_id(const std::add_pointer_t<int(Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_player_user_id, callback, post);
	}

	/// <summary>
	/// <para>Builds a sound message to send to a client.</para>
	/// </summary>
	static void build_sound_msg(const std::add_pointer_t<void(Edict* entity, int channel, const char* sample, float volume, float attenuation,
	                                                          int flags, int pitch, MessageType msg_type, int msg_id,
	                                                          const Vector& origin, Edict* client)> callback, const bool post = false)

	{
		set_hook(&EngineFuncPointers::build_sound_msg, callback, post);
	}

	/// <summary>
	/// </summary>
	static void is_dedicated_server(const std::add_pointer_t<qboolean()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::is_dedicated_server, callback, post);
	}

	/// <summary>
	/// </summary>
	static void cvar_get_pointer(const std::add_pointer_t<CVar *(const char* cvar_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_get_pointer, callback, post);
	}

	/// <summary>
	/// <para>Returns the server assigned WON id for this client.</para>
	/// </summary>
	static void get_player_won_id(const std::add_pointer_t<unsigned int(Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_player_won_id, callback, post);
	}

	/// <summary>
	/// <para>Removes a key from the info buffer.</para>
	/// </summary>
	static void info_remove_key(const std::add_pointer_t<void(char* info_buffer, const char* key)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::info_remove_key, callback, post);
	}

	/// <summary>
	/// <para>Gets the given physics key-value from the given client's buffer.</para>
	/// </summary>
	static void get_physics_key_value(const std::add_pointer_t<const char*(const Edict* client, const char* key)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_physics_key_value, callback, post);
	}

	/// <summary>
	/// <para>Sets the given physics key-value in the given client's buffer.</para>
	/// </summary>
	static void set_physics_key_value(const std::add_pointer_t<void(const Edict* client, const char* key, const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_physics_key_value, callback, post);
	}

	/// <summary>
	/// <para>Gets the physics info string for the given client.</para>
	/// </summary>
	static void get_physics_info_string(const std::add_pointer_t<const char*(const Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_physics_info_string, callback, post);
	}

	/// <summary>
	/// <para>Precaches an event.</para>
	/// </summary>
	static void precache_event(const std::add_pointer_t<unsigned short(int type, const char* path)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::precache_event, callback, post);
	}

	/// <summary>
	/// </summary>
	static void playback_event(const std::add_pointer_t<void(int flags, const Edict* invoker, unsigned short event_index, float delay,
	                                                         Vector& origin, Vector& angles, float f_param1, float f_param2, int i_param1, int i_param2,
	                                                         qboolean b_param1, qboolean b_param2)> callback, const bool post = false)

	{
		set_hook(&EngineFuncPointers::playback_event, callback, post);
	}

	/// <summary>
	/// <para>Sets the fat potentially visible set buffer to contain data based on the given origin.</para>
	/// </summary>
	static void set_fat_pvs(const std::add_pointer_t<unsigned char*(Vector& origin)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_fat_pvs, callback, post);
	}

	/// <summary>
	/// <para>Sets the fat potentially audible set buffer to contain data based on the given origin.</para>
	/// </summary>
	static void set_fat_pas(const std::add_pointer_t<unsigned char*(Vector& origin)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_fat_pas, callback, post);
	}

	/// <summary>
	/// <para>Checks if the given entity is visible in the given visible set.</para>
	/// </summary>
	static void check_visibility(const std::add_pointer_t<qboolean(Edict* entity, unsigned char* set)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::check_visibility, callback, post);
	}

	/// <summary>
	/// <para>Marks the given field in the given list as set.</para>
	/// </summary>
	static void delta_set_field(const std::add_pointer_t<void(struct delta* fields, const char* field_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::delta_set_field, callback, post);
	}

	/// <summary>
	/// <para>Marks the given field in the given list as not set.</para>
	/// </summary>
	static void delta_unset_field(const std::add_pointer_t<void(struct delta* fields, const char* field_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::delta_unset_field, callback, post);
	}

	/// <summary>
	/// <para>Adds a delta encoder.</para>
	/// </summary>
	static void delta_add_encoder(
		const std::add_pointer_t<void(const char* name, void (*conditional_encode)(struct delta* fields, const unsigned char* from, const unsigned char* to))> callback,
		const bool post = false)
	{
		set_hook(&EngineFuncPointers::delta_add_encoder, callback, post);
	}

	/// <summary>
	/// </summary>
	static void get_current_player(const std::add_pointer_t<int()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_current_player, callback, post);
	}

	/// <summary>
	/// </summary>
	static void can_skip_player(const std::add_pointer_t<qboolean(const Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::can_skip_player, callback, post);
	}

	/// <summary>
	/// <para>Finds the index of a delta field.</para>
	/// </summary>
	static void delta_find_field(const std::add_pointer_t<int(struct delta* fields, const char* field_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::delta_find_field, callback, post);
	}

	/// <summary>
	/// <para>Marks a delta field as set by index.</para>
	/// </summary>
	static void delta_set_field_by_index(const std::add_pointer_t<void(struct delta* fields, int field_number)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::delta_set_field_by_index, callback, post);
	}

	/// <summary>
	/// <para>Marks a delta field as not set by index.</para>
	/// </summary>
	static void delta_unset_field_by_index(const std::add_pointer_t<void(struct delta* fields, int field_number)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::delta_unset_field_by_index, callback, post);
	}

	/// <summary>
	/// <para>Used to filter contents checks.</para>
	/// </summary>
	static void set_group_mask(const std::add_pointer_t<void(int mask, int operation)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::set_group_mask, callback, post);
	}

	/// <summary>
	/// <para>Creates an instanced baseline. Used to define a baseline for a particular entity type.</para>
	/// </summary>
	static void create_instanced_baseline(const std::add_pointer_t<int(Strind class_name, EntityState* baseline)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::create_instanced_baseline, callback, post);
	}

	/// <summary>
	/// <para>Directly sets a console variable value.</para>
	/// </summary>
	static void cvar_direct_set(const std::add_pointer_t<void(CVar* cvar, const char* value)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::cvar_direct_set, callback, post);
	}

	/// <summary>
	/// <para>Forces the client and server to be running with the same version of the specified file (e.g., a client model).</para>
	/// </summary>
	static void force_unmodified(const std::add_pointer_t<void(ForceType type, Vector& min_size, Vector& max_size, const char* file_name)> callback,
	                             const bool post = false)
	{
		set_hook(&EngineFuncPointers::force_unmodified, callback, post);
	}

	/// <summary>
	/// <para>Get client statistics.</para>
	/// </summary>
	static void get_player_stats(const std::add_pointer_t<void(const Edict* client, int* ping, int* packet_loss)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_player_stats, callback, post);
	}

	/// <summary>
	/// <para>Adds a server command.</para>
	/// </summary>
	static void add_server_command(const std::add_pointer_t<void(const char* cmd_name, void (*callback)())> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::add_server_command, callback, post);
	}

	/// <summary>
	/// <para>Gets whether the given receiver can hear the given sender.</para>
	/// </summary>
	static void voice_get_client_listening(const std::add_pointer_t<qboolean(int receiver, int sender)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::voice_get_client_listening, callback, post);
	}

	/// <summary>
	/// <para>Sets whether the given receiver can hear the given sender.</para>
	/// </summary>
	static void voice_set_client_listening(const std::add_pointer_t<qboolean(int receiver, int sender, qboolean listen)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::voice_set_client_listening, callback, post);
	}

	/// <summary>
	/// <para>Gets the client's auth ID.</para>
	/// </summary>
	static void get_player_auth_id(const std::add_pointer_t<const char*(Edict* client)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_player_auth_id, callback, post);
	}

	/// <summary>
	/// <para>Gets the sequence that has the given entry name.</para>
	/// </summary>
	static void sequence_get(const std::add_pointer_t<SequenceEntry *(const char* file_name, const char* entry_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::sequence_get, callback, post);
	}

	/// <summary>
	/// <para>Picks a sentence from the given group.</para>
	/// </summary>
	static void sequence_pick_sentence(const std::add_pointer_t<SentenceEntry *(const char* group_name, int pick_method, int* picked)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::sequence_pick_sentence, callback, post);
	}

	/// <summary>
	/// <para>LH: Give access to file size via filesystem.</para>
	/// </summary>
	static void get_file_size(const std::add_pointer_t<int(const char* file_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_file_size, callback, post);
	}

	/// <summary>
	/// <para>Gets the average wave length in seconds.</para>
	/// </summary>
	static void get_approx_wave_play_len(const std::add_pointer_t<unsigned int(const char* file_path)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_approx_wave_play_len, callback, post);
	}

	/// <summary>
	/// </summary>
	static void is_career_match(const std::add_pointer_t<qboolean()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::is_career_match, callback, post);
	}

	/// <summary>
	/// </summary>
	static void get_localized_string_length(const std::add_pointer_t<int(const char* label)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_localized_string_length, callback, post);
	}

	/// <summary>
	/// <para>Marks the message with the given ID as having been shown.</para>
	/// </summary>
	static void register_tutor_message_shown(const std::add_pointer_t<void(int message_id)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::register_tutor_message_shown, callback, post);
	}

	/// <summary>
	/// <para>Gets the number of times the message with the given ID has been shown.</para>
	/// </summary>
	static void get_times_tutor_message_shown(const std::add_pointer_t<int(int message_id)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::get_times_tutor_message_shown, callback, post);
	}

	/// <summary>
	/// <para>Processes the tutor message decay buffer.</para>
	/// </summary>
	static void process_tutor_message_decay_buffer(const std::add_pointer_t<void(int* buffer, int buffer_length)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::process_tutor_message_decay_buffer, callback, post);
	}

	/// <summary>
	/// <para>Constructs the tutor message decay buffer.</para>
	/// </summary>
	static void construct_tutor_message_decay_buffer(const std::add_pointer_t<void(int* buffer, int buffer_length)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::construct_tutor_message_decay_buffer, callback, post);
	}

	/// <summary>
	/// <para>Resets tutor message decay data.</para>
	/// </summary>
	static void reset_tutor_message_decay_data(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::reset_tutor_message_decay_data, callback, post);
	}

	/// <summary>
	/// <para>Queries the given client for a cvar value.</para>
	/// </summary>
	static void query_client_cvar_value(const std::add_pointer_t<void(const Edict* client, const char* cvar_name)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::query_client_cvar_value, callback, post);
	}

	/// <summary>
	/// <para>Queries the given client for a cvar value.</para>
	/// </summary>
	static void query_client_cvar_value2(const std::add_pointer_t<void(const Edict* client, const char* cvar_name, int request_id)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::query_client_cvar_value2, callback, post);
	}

	/// <summary>
	/// <para>Checks if a command line parameter was provided.</para>
	/// </summary>
	static void eng_check_param(const std::add_pointer_t<int(const char* cmd_line_token, char** next)> callback, const bool post = false)
	{
		set_hook(&EngineFuncPointers::eng_check_param, callback, post);
	}

private:
	/// <summary>
	/// </summary>
	template <typename TMember, typename TCallback>
	static void set_hook(TMember EngineFuncPointers::* member, const TCallback callback, const bool post)
	{
		if (post) {
			engine_hooks_->*member = callback;
		}
		else {
			engine_post_hooks_->*member = callback;
		}
	}
};
