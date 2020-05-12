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
#include <utility>

/// <summary>
/// <para>Receive engine function table from engine.</para>
/// </summary>
extern "C" void DLLEXPORT WINAPI GiveFnptrsToDll(EngineFuncPointers*, GlobalVars*);

/// <summary>
/// Class Engine.
/// </summary>
class Engine {
	friend void WINAPI GiveFnptrsToDll(EngineFuncPointers*, GlobalVars*);

	/// <summary>
	/// <para>Engine functions table.</para>
	/// </summary>
	static const EngineFuncPointers* engine_funcs_;

public:
	/// <summary>
	/// <para>Precaches a model.<br/></para>
	/// </summary>
	/// 
	/// <param name="path">Model path. Starts in the game directory.<br/>
	///		This string must live for at least as long as the map itself.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the model.<br/>
	/// </returns>
	/// 
	/// <remarks>
	///		If path is null, is empty or contains an invalid value in the first character, triggers a host error.<br/>
	///		If the maximum number of model precacheable resources has been reached, triggers a host error.<br/>
	///		If this is called after <c>server_activate</c>, triggers a host error.<br/>
	/// </remarks>
	static int precache_model(const char* path)
	{
		return engine_funcs_->precache_model(path);
	}

	/// <summary>
	/// <para>Precaches a sound.<br/></para>
	/// </summary>
	/// 
	/// <param name="path">Sound path. Starts in the sound/ directory.<br/>
	///		This string must live for at least as long as the map itself.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the sound.<br/>
	/// </returns>
	/// 
	/// <remarks>
	///		If path is null, is empty or contains an invalid value in the first character, triggers a host error.<br/>
	///		If the maximum number of sound precacheable resources has been reached, triggers a host error.<br/>
	///		If this is called after <c>server_activate</c>, triggers a host error.<br/>
	/// </remarks>
	static int precache_sound(const char* path)
	{
		return engine_funcs_->precache_sound(path);
	}

	/// <summary>
	/// <para>Sets the model of the given entity. Also changes the entity bounds based on the model.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to set the model on.
	/// </param>
	/// <param name="model">
	///		Model path.<br/>
	///		This string must live for at least as long as the map itself.
	/// </param>
	static void set_model(Edict* entity, const char* model)
	{
		engine_funcs_->set_model(entity, model);
	}

	/// <summary>
	/// <para>Gets the index of the given model.<br/></para>
	/// </summary>
	/// 
	/// <param name="model">
	///		Path to the model whose index is to be returned.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the model.<br/>
	/// </returns>
	/// 
	/// <remarks>
	///		If the given model was not precached, shuts the game down.<br/>
	/// </remarks>
	static int model_index(const char* model)
	{
		return engine_funcs_->model_index(model);
	}

	/// <summary>
	/// <para>Gets the number of frames in the given model.<br/></para>
	/// </summary>
	/// 
	/// <param name="model_index">
	///		Index of the model whose frame count is to be returned.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Frame count of the model.<br/>
	/// </returns>
	/// 
	/// <remarks>
	///		If this is a sprite, returns the number of sprite frames.<br/>
	///		If this is a studio model, this is all of the submodels in each body part multiplied with each-other.
	///		It represents the number of variations that can be created by changing submodels (e.g. heads, weapons, etc).<br/>
	///		Otherwise, returns 1.<br/>
	/// </remarks>
	static int model_frames(const int model_index)
	{
		return engine_funcs_->model_frames(model_index);
	}

	/// <summary>
	/// <para>Sets the entity bounds. Also relinks the entity:<br>
	/// <c>EntityVars::min_size</c>, <c>EntityVars::max_size</c> and <c>EntityVars::size</c> are changed.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose bounds are to be changed.
	/// </param>
	/// <param name="min">
	///		Minimum relative bounds.
	/// </param>
	/// <param name="max">
	///		Maximum relative bounds.<br/>
	/// </param>
	/// 
	/// <remarks>
	///		If the bounds are backwards (max smaller than min), a host error is triggered.<br/>
	/// </remarks>
	static void set_size(Edict* entity, const Vector& min, const Vector& max)
	{
		engine_funcs_->set_size(entity, min, max);
	}

	/// <summary>
	///		<para>Changes the level. This will append a changelevel command to the server command buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="level_name">
	///		Name of the level to change to.
	/// </param>
	/// <param name="landmark_name">
	///		Name of the landmark to use. If null, no landmark is used.<br/>
	/// </param>
	///
	/// <remarks>
	///		Calling <c>server_execute</c> will trigger the changelevel.
	///		Subsequent calls made during the same map will be ignored.<br/>
	/// </remarks>
	static void change_level(const char* level_name, const char* landmark_name)
	{
		engine_funcs_->change_level(level_name, landmark_name);
	}

	/// <summary>
	/// <para>Does nothing useful. Will trigger a host error if the given entity is not a client.</para>
	/// </summary>
	static void get_spawn_params(Edict* client)
	{
		engine_funcs_->get_spawn_params(client);
	}

	/// <summary>
	/// <para>Does nothing useful. Will trigger a host error if the given entity is not a client.<br/>
	/// Will trigger a sys error if the given entity is invalid.</para>
	/// </summary>
	static void save_spawn_params(Edict* client)
	{
		engine_funcs_->save_spawn_params(client);
	}

	/// <summary>
	/// <para>Converts a direction vector to a yaw angle.<br/></para>
	/// </summary>
	/// 
	/// <param name="direction">
	///		Direction vector.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Yaw angle.<br/>
	/// </returns>
	static float vec_to_yaw(const Vector& direction)
	{
		return engine_funcs_->vec_to_yaw(direction);
	}

	/// <summary>
	/// <para>Converts a direction vector to angles.<br/></para>
	/// </summary>
	/// 
	/// <param name="direction_in">
	///		Direction vector.
	/// </param>
	/// <param name="angles_out">
	///		Angles.<br/>
	/// </param>
	static void vec_to_angles(const Vector& direction_in, Vector& angles_out)
	{
		engine_funcs_->vec_to_angles(direction_in, angles_out);
	}

	/// <summary>
	/// <para>Moves the given entity to the given destination.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to move.
	/// </param>
	/// <param name="goal">
	///		Destination.
	/// </param>
	/// <param name="distance">
	///		Distance to cover in this movement operation, in units.
	/// </param>
	/// <param name="move_type">
	///		Move type.<br/>
	/// </param>
	static void move_to_origin(Edict* entity, const Vector& goal, const float distance, const MoveTypeNpc move_type)
	{
		engine_funcs_->move_to_origin(entity, goal, distance, move_type);
	}

	/// <summary>
	/// <para>Changes the entity's yaw angle to approach its ideal yaw.<br/>
	/// Yaw is updated at <c>EntityVars::yaw_speed</c> speed to match <c>EntityVars::ideal_yaw</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose yaw is to be changed.<br/>
	/// </param>
	static void change_yaw(Edict* entity)
	{
		engine_funcs_->change_yaw(entity);
	}

	/// <summary>
	/// <para>Changes the entity's pitch angle to approach its ideal pitch.<br/>
	/// Pitch is updated at <c>EntityVars::pitch_speed</c> speed to match <c>EntityVars::ideal_pitch</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose pitch is to be changed.<br/>
	/// </param>
	static void change_pitch(Edict* entity)
	{
		engine_funcs_->change_pitch(entity);
	}

	/// <summary>
	/// <para>Finds an entity by comparing strings.<br/></para>
	/// </summary>
	/// 
	/// <param name="edict_start_search_after">
	///		Edict to start searching after.
	///	</param>
	/// <param name="field">
	///		Entity field to compare. Only string fields in <c>EntityVars</c> are considered.
	/// </param>
	/// <param name="value">
	///		Value to compare to.<br/>
	/// </param>
	/// 
	/// <returns>
	///		If the given field exists, and the given value is not null, and an entity has a matching value, returns the edict of that entity.<br/>
	///		Otherwise, returns null.<br/>
	/// </returns>
	static Edict* find_entity_by_string(Edict* edict_start_search_after, const char* field, const char* value)
	{
		return engine_funcs_->find_entity_by_string(edict_start_search_after, field, value);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose light value is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		If the given entity is null, returns -1.<br/>
	///		If the given entity is a client or the world, returns <c>EntityVars::light_level</c>.<br/>
	///		Otherwise, returns the color of the floor that the entity is standing on.<br/>
	/// </returns>
	static int get_entity_illumination(Edict* entity)
	{
		return engine_funcs_->get_entity_illumination(entity);
	}

	/// <summary>
	/// <para>Finds an entity in a sphere.<br/></para>
	/// </summary>
	/// 
	/// <param name="edict_start_search_after">
	///		Edict to start searching after.
	/// </param>
	/// <param name="origin">
	///		Origin in the world to center the sphere around.
	/// </param>
	/// <param name="radius">
	///		Sphere radius.<br/>
	/// </param>
	/// 
	/// <returns>
	///		The first valid entity in the sphere's radius, or null if no entity can be found.
	/// </returns>
	static Edict* find_entity_in_sphere(Edict* edict_start_search_after, const Vector& origin, const float radius)
	{
		return engine_funcs_->find_entity_in_sphere(edict_start_search_after, origin, radius);
	}

	/// <summary>
	/// <para>Finds a client in the Potentially Visible Set.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose origin and view offset should be used to determine which client is visible.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Client, or null if no client could be found.<br/>
	/// </returns>
	/// 
	/// <remarks>
	///		This function's behavior is unexpected: it will get the next client every 0.1 seconds, and check if the entity can see it.<br/>
	///		If so, the client is returned. Otherwise, the world is returned.<br/>
	/// </remarks>
	static Edict* find_client_in_pvs(Edict* entity)
	{
		return engine_funcs_->find_client_in_pvs(entity);
	}

	/// <summary>
	/// <para>Find entities in Potentially Visible Set.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose origin and view offset should be used to determine which entities are visible.<br/>
	/// </param>
	/// 
	/// <returns>
	///		First entity in the chain of entities that are visible, or worldspawn if no entities are visible.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This builds a list of entities using <c>EntityVars::chain</c>.
	///		This list is temporary, so store its results elsewhere if it is needed later on.<br/><br/>
	///		This operation is expensive as it checks every entity. Avoid using this unless it is absolutely necessary.<br/>
	/// </remarks>
	static Edict* entities_in_pvs(Edict* entity)
	{
		return engine_funcs_->entities_in_pvs(entity);
	}

	/// <summary>
	/// <para>Make direction vectors from angles.<br/></para>
	/// </summary>
	/// 
	/// <param name="angles">
	///		Angles to convert to direction vectors.<br/>
	/// </param>
	///
	/// <remarks>
	///		The results are stored in <c>g_global_vars->vec_forward</c>, <c>g_global_vars->vec_right</c> and <c>g_global_vars->vec_up</c>.
	/// </remarks>
	static void make_vectors(const Vector& angles)
	{
		engine_funcs_->make_vectors(angles);
	}

	/// <summary>
	/// <para>Make direction vectors from angles.<br/></para>
	/// </summary>
	/// 
	/// <param name="angles">
	///		Angles to convert to direction vectors.
	/// </param>
	/// <param name="forward">
	///		Stores the forward direction vector.
	/// </param>
	/// <param name="right">
	///		Stores the right direction vector.
	/// </param>
	/// <param name="up">
	///		Stores the up direction vector.<br/>
	/// </param>
	static void angle_vectors(const Vector& angles, Vector& forward, Vector& right, Vector& up)
	{
		engine_funcs_->angle_vectors(angles, forward, right, up);
	}

	/// <summary>
	/// <para>Allocates an edict for use with an entity.<br/></para>
	/// </summary>
	/// 
	/// <returns>
	///		Newly allocated edict.<br/>
	/// </returns>
	///
	/// <remarks>
	///		If the engine is out of edicts, triggers a sys error.<br/>
	///		If the engine is not ready for entity instantiation yet (e.g. during restore), triggers a sys error.<br/>
	/// </remarks>
	static Edict* create_entity()
	{
		return engine_funcs_->create_entity();
	}

	/// <summary>
	/// <para>Immediately removes the given entity.<br/>
	/// Increments the edict serial number.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to remove.<br/>
	/// </param>
	static void remove_entity(Edict* entity)
	{
		engine_funcs_->remove_entity(entity);
	}

	/// <summary>
	/// <para>Creates an entity of the class <c>class_name</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="class_name">
	///		Name of the class to instantiate.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Edict of the entity that was instantiated, or null if no such entity exists.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This will not fall back to invoking the custom entity handler if the given class does not exist.<br/>
	/// </remarks>
	static Edict* create_named_entity(const Strind class_name)
	{
		return engine_funcs_->create_named_entity(class_name);
	}

	/// <summary>
	/// <para>Makes an entity static.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to make static.<br/>
	/// </param>
	///
	/// <remarks>
	///		Static entities are copied to the client side and are removed on the server side.<br/>
	///		Only valid during map spawn.<br/>
	/// </remarks>
	static void make_static(Edict* entity)
	{
		engine_funcs_->make_static(entity);
	}

	/// <summary>
	/// <para>Returns whether the given entity is on the floor.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to check.<br/>
	/// </param>
	/// 
	/// <returns>
	///		1 if the entity is on the floor, 0 otherwise.<br/>
	/// </returns>
	static qboolean ent_is_on_floor(Edict* entity)
	{
		return engine_funcs_->ent_is_on_floor(entity);
	}

	/// <summary>
	/// <para>Drops the entity to the floor.<br/>
	/// The entity will be moved down to the floor, effectively being teleported.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to drop.<br/>
	/// </param>
	/// 
	/// <returns>
	///		-1 if the entity is stuck inside a solid object.<br/>
	///		0 if the floor is further than 256 units away.<br/>
	///		1 if the entity was dropped to the floor.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Maximum drop distance is 256 units.
	///		If the floor is further than that away, the entity will not be moved.<br/>
	/// </remarks>
	static int drop_to_floor(Edict* entity)
	{
		return engine_funcs_->drop_to_floor(entity);
	}

	/// <summary>
	/// <para>Makes the entity walk.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to move.
	/// </param>
	/// <param name="yaw">
	///		Yaw distance. This is the entity's current movement direction in the XY plane.
	/// </param>
	/// <param name="dist">
	///		Distance to move, in units.
	/// </param>
	/// <param name="mode">
	///		Movement type.<br/>
	/// </param>
	/// 
	/// <returns>
	///		1 if the move succeeded (no obstacles in the way), 0 otherwise.<br/>
	/// </returns>
	///
	/// <remarks>
	///		The entity must be capable of flying (<c>FL_FLY</c>) or swimming (<c>FL_SWIM</c>), or be on the ground (<c>FL_ON_GROUND</c>).<br/>
	/// </remarks>
	static qboolean walk_move(Edict* entity, const float yaw, const float dist, const WalkMoveMode mode)
	{
		return engine_funcs_->walk_move(entity, yaw, dist, mode);
	}

	/// <summary>
	/// <para>Sets the origin of the given entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose origin is to be set.
	/// </param>
	/// <param name="origin">
	///		Origin to set.<br/>
	/// </param>
	static void set_origin(Edict* entity, const Vector& origin)
	{
		engine_funcs_->set_origin(entity, origin);
	}

	/// <summary>
	/// <para>Emits a sounds from the given entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity that is emitting the sound.
	/// </param>
	/// <param name="channel">
	///		Channel to play the sound on.
	/// </param>
	/// <param name="sample">
	///		Sample to play. The sound must be precached.
	/// </param>
	/// <param name="volume">
	///		Sound volume. Must be a value in the range 0 - 1.
	/// </param>
	/// <param name="attenuation">
	///		Sound attenuation.
	/// </param>
	/// <param name="flags">
	///		Sound flags.
	/// </param>
	/// <param name="pitch">
	///		Sound pitch. Must be a value in the range 0 - 255.<br/>
	/// </param>
	static void emit_sound(Edict* entity, const SoundChannel channel, const char* sample, const float volume,
	                       const float attenuation, const int flags, const int pitch)
	{
		engine_funcs_->emit_sound(entity, channel, sample, volume, attenuation, flags, pitch);
	}

	/// <summary>
	/// <para>Emits a sounds from the given entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity that is emitting the sound.
	/// </param>
	/// <param name="origin">
	///		Position in the world to play the sound at.
	/// </param>
	/// <param name="sample">
	///		Sample to play. The sound must be precached.
	/// </param>
	/// <param name="volume">
	///		Sound volume. Must be a value in the range 0 - 1.
	/// </param>
	/// <param name="attenuation">
	///		Sound attenuation.
	/// </param>
	/// <param name="flags">
	///		Sound flags.
	/// </param>
	/// <param name="pitch">
	///		Sound pitch. Must be a value in the range 0 - 255.<br/>
	/// </param>
	static void emit_ambient_sound(Edict* entity, Vector& origin, const char* sample, const float volume,
	                               const float attenuation, const int flags, const int pitch)
	{
		engine_funcs_->emit_ambient_sound(entity, origin, sample, volume, attenuation, flags, pitch);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position.<br/></para>
	/// </summary>
	/// 
	/// <param name="start_pos">
	///		Start position.
	/// </param>
	/// <param name="end_pos">
	///		End position.
	/// </param>
	/// <param name="trace_ignore_flags">
	///		Bit vector containing trace flags (see <c>TR_IGNORE_*</c> flags).
	/// </param>
	/// <param name="entity_to_ignore">
	///		Entity to ignore during the trace.
	/// </param>
	/// <param name="result">
	///		Trace result instance.<br/>
	/// </param>
	static void trace_line(const Vector& start_pos, const Vector& end_pos, const int trace_ignore_flags,
	                       Edict* entity_to_ignore, TraceResult* result)
	{
		engine_funcs_->trace_line(start_pos, end_pos, trace_ignore_flags, entity_to_ignore, result);
	}

	/// <summary>
	/// <para>Traces a toss.<br/>
	/// This simulates tossing the entity using its current origin, velocity, angular velocity, angles and gravity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to toss.
	/// </param>
	/// <param name="entity_to_ignore">
	///		Entity to ignore during the trace.
	/// </param>
	/// <param name="result">
	///		Trace result instance.<br/>
	/// </param>
	///
	/// <remarks>
	///		This does not use the same code as <c>MoveTypeEntity::Toss</c>, and may return different results.
	/// </remarks>
	static void trace_toss(Edict* entity, Edict* entity_to_ignore, TraceResult* result)
	{
		engine_funcs_->trace_toss(entity, entity_to_ignore, result);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position, using the given entity's min_size and max_size.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose hull will be used.
	/// </param>
	/// <param name="start_pos">
	///		Start position.
	/// </param>
	/// <param name="end_pos">
	///		End position.
	/// </param>
	/// <param name="trace_ignore_flags">
	///		Bit vector containing trace flags (see <c>TR_IGNORE_*</c> flags).
	/// </param>
	/// <param name="entity_to_ignore">
	///		Entity to ignore during the trace.
	/// </param>
	/// <param name="result">
	///		Trace result instance.<br/>
	/// </param>
	/// 
	/// <returns>
	///		1 if the trace was entirely in a solid object, or if it hit something.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This can be any entity, not just monsters.
	/// </remarks>
	static qboolean trace_monster_hull(Edict* entity, const Vector& start_pos, const Vector& end_pos, const int trace_ignore_flags,
	                                   Edict* entity_to_ignore, TraceResult* result)
	{
		return engine_funcs_->trace_monster_hull(entity, start_pos, end_pos, trace_ignore_flags, entity_to_ignore, result);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position, using the specified hull.<br/></para>
	/// </summary>
	/// 
	/// <param name="start_pos">
	///		Start position.
	/// </param>
	/// <param name="end_pos">
	///		End position.
	/// </param>
	/// <param name="trace_ignore_flags">
	///		Bit vector containing trace flags (see <c>TR_IGNORE_*</c> flags).
	/// </param>
	/// <param name="hull_number">
	///		Hull to use.
	/// </param>
	/// <param name="entity_to_ignore">
	///		Entity to ignore during the trace.
	/// </param>
	/// <param name="result">
	///		Trace result instance.<br/>
	/// </param>
	static void trace_hull(const Vector& start_pos, const Vector& end_pos, const int trace_ignore_flags,
	                       const int hull_number, Edict* entity_to_ignore, TraceResult* result)
	{
		engine_funcs_->trace_hull(start_pos, end_pos, trace_ignore_flags, hull_number, entity_to_ignore, result);
	}

	/// <summary>
	/// <para>Performs a trace between a starting and ending position.<br/>
	/// Similar to <c>trace_hull</c>, but will instead perform a trace in the given world hull using the given entity's model's hulls.<br/>
	/// For studio models this will use the model's hit boxes.<br/></para>
	/// </summary>
	/// 
	/// <param name="start_pos">
	///		Start position.
	/// </param>
	/// <param name="end_pos">
	///		End position.
	/// </param>
	/// <param name="hull_number">
	///		Hull to use.
	/// </param>
	/// <param name="entity">
	///		Entity whose hull will be used.
	/// </param>
	/// <param name="result">
	///		Trace result instance.<br/>
	/// </param>
	///
	/// <remarks>
	///		If the given entity's model is a studio model, uses its hit boxes.<br/>
	///		If it's a brush model, the brush model's hull for the given hull number is used (this may differ if custom brush hull sizes are in use).<br/>
	///		Otherwise, the entity bounds are converted into a hull.<br/>
	/// </remarks>
	static void trace_model(const Vector& start_pos, const Vector& end_pos, const int hull_number, Edict* entity, TraceResult* result)
	{
		engine_funcs_->trace_model(start_pos, end_pos, hull_number, entity, result);
	}

	/// <summary>
	/// <para>Used to get texture info.<br/>
	/// The given entity must have a brush model set.<br/></para>
	/// </summary>
	/// 
	/// <param name="texture_entity">
	///		Entity whose texture is to be retrieved.
	/// </param>
	/// <param name="start_pos">
	///		Start position.
	/// </param>
	/// <param name="end_pos">
	///		End position.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Texture instance, or null if no texture could be found.<br/>
	/// </returns>
	///
	/// <remarks>
	///		If the trace line intersects the model, the texture of the surface it intersected is returned.
	///		Otherwise, returns null.<br/>
	/// </remarks>
	static const char* trace_texture(Edict* texture_entity, const Vector& start_pos, const Vector& end_pos)
	{
		return engine_funcs_->trace_texture(texture_entity, start_pos, end_pos);
	}

	/// <summary>
	/// <para>Not implemented. Triggers a sys error.<br/></para>
	/// </summary>
	static void trace_sphere(const Vector& start_pos, const Vector& end_pos, const int trace_ignore_flags,
	                         const float radius, Edict* entity_to_ignore, TraceResult* result)
	{
		engine_funcs_->trace_sphere(start_pos, end_pos, trace_ignore_flags, radius, entity_to_ignore, result);
	}

	/// <summary>
	/// <para>Get the aim vector for the given entity.<br/>
	/// Assumes <c>make_vectors</c> was called with <c>entity->vars.angles</c> beforehand.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to retrieve the aim vector for.
	/// </param>
	/// <param name="speed">
	///		Unused.
	/// </param>
	/// <param name="vec_return">
	///		The resulting aim vector.<br/>
	/// </param>
	///
	/// <remarks>
	///		The aim vector is the auto aim vector used when sv_aim is enabled.<br/>
	///		It will snap to entities that are close to the entity's forward vector axis.<br/>
	/// </remarks>
	static void get_aim_vector(Edict* entity, const float speed, Vector& vec_return)
	{
		engine_funcs_->get_aim_vector(entity, speed, vec_return);
	}

	/// <summary>
	/// <para>Issues a command to the server.<br/></para>
	/// </summary>
	/// 
	/// <param name="command">
	///		Command to execute.<br/>
	/// </param>
	///
	/// <remarks>
	///		The command must end with either a newline ('\n') or a semicolon (';') in order to be considered valid by the engine.<br/>
	///		The command will be enqueued for execution at a later point.<br/>
	/// </remarks>
	static void server_command(const char* command)
	{
		engine_funcs_->server_command(command);
	}

	/// <summary>
	/// <para>Executes all pending server commands.<br/></para>
	/// </summary>
	///
	/// <remarks>
	///		If a changelevel command is in the buffer, this can result in the caller being freed before this call returns.<br/>
	/// </remarks>
	static void server_execute()
	{
		engine_funcs_->server_execute();
	}

	/// <summary>
	/// <para>Sends a client command to the given client.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Edict of the client that should execute the command.
	/// </param>
	/// <param name="format">
	///		Format string.
	/// </param>
	/// <param name="args">
	///		Format arguments.<br/>
	/// </param>
	template <typename ...Args>
	static void client_command(Edict* client, const char* format, Args&&... args)
	{
		engine_funcs_->client_command(client, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Creates a particle effect.<br/></para>
	/// </summary>
	/// 
	/// <param name="origin">
	///		Origin in the world.
	/// </param>
	/// <param name="direction">
	///		Direction of the effect.
	/// </param>
	/// <param name="color">
	///		Color of the effect.
	/// </param>
	/// <param name="count">
	///		Number of particles to create.<br/>
	/// </param>
	static void particle_effect(const Vector& origin, const Vector& direction, const float color, const float count)
	{
		engine_funcs_->particle_effect(origin, direction, color, count);
	}

	/// <summary>
	/// <para>Sets the given light style to the given value.<br/></para>
	/// </summary>
	/// 
	/// <param name="style">
	///		Style index.
	/// </param>
	/// <param name="value">
	///		Value to set. This string must live for at least as long as the map itself.<br/>
	/// </param>
	static void light_style(const int style, const char* value)
	{
		engine_funcs_->light_style(style, value);
	}

	/// <summary>
	/// <para>Gets the index of the given decal.<br/></para>
	/// </summary>
	/// 
	/// <param name="name">
	///		Name of the decal.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the decal, or -1 if the decal couldn't be found.<br/>
	/// </returns>
	static int decal_index(const char* name)
	{
		return engine_funcs_->decal_index(name);
	}

	/// <summary>
	/// <para>Gets the contents of the given location in the world.<br/></para>
	/// </summary>
	/// 
	/// <param name="origin">
	///		Location in the world.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Contents of the location in the world (see <c>CONTENTS_*</c> constants).<br/>
	/// </returns>
	static int point_contents(const Vector& origin)
	{
		return engine_funcs_->point_contents(origin);
	}

	/// <summary>
	/// <para>Begins a new network message.<br/></para>
	/// </summary>
	/// 
	/// <param name="msg_type">
	///		Message type.
	/// </param>
	/// <param name="msg_id">
	///		Message ID.
	/// </param>
	/// <param name="origin">
	///		Origin to use for PVS and PAS checks (optional).
	/// </param>
	/// <param name="client">
	///		If it's a message to one client, client to send the message to (optional).<br/>
	/// </param>
	///
	/// <remarks>
	///		If the message type is to one client, and no client is provided, triggers a sys error.<br/>
	///		If the message type is to all clients, and a client is provided, triggers a sys error.<br/>
	///		If another message had already been started and was not ended, triggers a sys error.<br/>
	/// </remarks>
	static void message_begin(const MessageType msg_type, const int msg_id, const vec_t* origin = nullptr, Edict* client = nullptr)
	{
		engine_funcs_->message_begin(msg_type, msg_id, origin, client);
	}

	/// <summary>
	/// <para>Begins a new network message.<br/></para>
	/// </summary>
	/// 
	/// <param name="msg_type">
	///		Message type.
	/// </param>
	/// <param name="msg_id">
	///		Message ID.
	/// </param>
	/// <param name="origin">
	///		Origin to use for PVS and PAS checks (optional).
	/// </param>
	/// <param name="client">
	///		If it's a message to one client, client to send the message to (optional).<br/>
	/// </param>
	///
	/// <remarks>
	///		If the message type is to one client, and no client is provided, triggers a sys error.<br/>
	///		If the message type is to all clients, and a client is provided, triggers a sys error.<br/>
	///		If another message had already been started and was not ended, triggers a sys error.<br/>
	/// </remarks>
	static void message_begin(const MessageType msg_type, const int msg_id, const Vector& origin, Edict* client)
	{
		engine_funcs_->message_begin(msg_type, msg_id, static_cast<const vec_t*>(origin), client);
	}

	/// <summary>
	/// <para>Ends a network message.<br/></para>
	/// </summary>
	///
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	///		If the buffer had overflowed, triggers a sys error.<br/>
	///		If the message is a user message, and exceeds 192 bytes, triggers a host error.<br/>
	///		If the message has a fixed size and the wrong size was written, triggers a sys error.<br/>
	///		If the given client is invalid, triggers a host error.<br/>
	/// </remarks>
	static void message_end()
	{
		engine_funcs_->message_end();
	}

	/// <summary>
	/// <para>Writes a single unsigned byte.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_byte(const int value)
	{
		engine_funcs_->write_byte(value);
	}

	/// <summary>
	/// <para>Writes a single character.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_char(const int value)
	{
		engine_funcs_->write_char(value);
	}

	/// <summary>
	/// <para>Writes a single unsigned short.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_short(const int value)
	{
		engine_funcs_->write_short(value);
	}

	/// <summary>
	/// <para>Writes a single unsigned int.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_long(const int value)
	{
		engine_funcs_->write_long(value);
	}

	/// <summary>
	/// <para>Writes a single angle value.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_angle(const float value)
	{
		engine_funcs_->write_angle(value);
	}

	/// <summary>
	/// <para>Writes a single coordinate value.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_coord(const float value)
	{
		engine_funcs_->write_coord(value);
	}

	/// <summary>
	/// <para>Writes a single null terminated string.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_string(const char* value)
	{
		engine_funcs_->write_string(value);
	}

	/// <summary>
	/// <para>Writes a single entity index.<br/></para>
	/// </summary>
	/// 
	/// <remarks>
	///		If no message had been started, triggers a sys error.<br/>
	/// </remarks>
	static void write_entity(const int value)
	{
		engine_funcs_->write_entity(value);
	}

	/// <summary>
	/// <para>Registers a cvar.<br/>
	/// Sets the flag <c>FCVAR_EXT_DLL</c> on the cvar.<br/></para>
	/// </summary>
	/// 
	/// <param name="cvar">
	///		Cvar to register.<br/>
	/// </param>
	static void cvar_register(CVar* cvar)
	{
		engine_funcs_->cvar_register(cvar);
	}

	/// <summary>
	/// <para>Gets the value of a cvar as a float.<br/></para>
	/// </summary>
	/// 
	/// <param name="cvar_name">
	///		Name of the cvar whose value is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Value of the cvar, or 0 if the cvar doesn't exist.<br/>
	/// </returns>
	static float cvar_get_float(const char* cvar_name)
	{
		return engine_funcs_->cvar_get_float(cvar_name);
	}

	/// <summary>
	/// <para>Gets the value of a cvar as a string.<br/></para>
	/// </summary>
	/// 
	/// <param name="cvar_name">
	///		Name of the cvar whose value is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Value of the cvar, or an empty string if the cvar doesn't exist.<br/>
	/// </returns>
	static const char* cvar_get_string(const char* cvar_name)
	{
		return engine_funcs_->cvar_get_string(cvar_name);
	}

	/// <summary>
	/// <para>Sets the value of a cvar as a float.<br/></para>
	/// </summary>
	/// 
	/// <param name="cvar_name">
	///		Name of the cvar whose value to set.
	/// </param>
	/// <param name="value">
	///		Value to set.<br/>
	/// </param>
	static void cvar_set_float(const char* cvar_name, const float value)
	{
		engine_funcs_->cvar_set_float(cvar_name, value);
	}

	/// <summary>
	/// <para>Sets the value of a cvar as a string.<br/></para>
	/// </summary>
	/// 
	/// <param name="cvar_name">
	///		Name of the cvar whose value to set.
	/// </param>
	/// <param name="value">
	///		Value to set. The string is copied.<br/>
	/// </param>
	static void cvar_set_string(const char* cvar_name, const char* value)
	{
		engine_funcs_->cvar_set_string(cvar_name, value);
	}

	/// <summary>
	/// <para>Outputs a message to the server console.<br/></para>
	/// </summary>
	/// 
	/// <param name="type">
	///		Type of message.
	/// </param>
	/// <param name="format">
	///		Format string.
	/// </param>
	/// <param name="args">
	///		Format arguments.<br/>
	/// </param>
	///
	/// <remarks>
	///		If <c>type</c> is <c>AlertType::Logged</c> and this is a multiplayer game, logs the message to the log file.<br/>
	///		Otherwise, if the developer cvar is not 0, outputs the message to the console.<br/>
	/// </remarks>
	template <typename ...Args>
	static void alert_message(const AlertType type, const char* format, Args&&... args)
	{
		engine_funcs_->alert_message(type, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Obsolete. Will print a message to the server console using <c>alert_message</c> indicating if it's being used.<br/></para>
	/// </summary>
	template <typename ...Args>
	static void engine_file_print(void* file, const char* format, Args&&... args)
	{
		engine_funcs_->engine_file_print(file, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Allocates memory for <c>EntityBase</c> instances.<br/>
	/// The memory will be zeroed out.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to allocate memory for.
	/// </param>
	/// <param name="size">
	///		Number of bytes to allocate.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Pointer to <c>EntityBase</c> memory, or null if it could not be allocated.<br/>
	/// </returns>
	static void* alloc_ent_private_data(Edict* entity, const int32 size)
	{
		return engine_funcs_->alloc_ent_private_data(entity, size);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose entity memory is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Pointer to entity <c>EntityBase</c> instance, or null if edict is null or there is no entity assigned to it.<br/>
	/// </returns>
	static void* ent_private_data(Edict* entity)
	{
		return engine_funcs_->ent_private_data(entity);
	}

	/// <summary>
	/// <para>Frees the <c>EntityBase</c> memory assigned to entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose memory should be freed.<br/>
	/// </param>
	static void free_ent_private_data(Edict* entity)
	{
		engine_funcs_->free_ent_private_data(entity);
	}

	/// <summary>
	/// <para>Gets the string assigned to the index.<br/></para>
	/// </summary>
	/// 
	/// <param name="string">
	///		String index whose string should be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		String.<br/>
	/// </returns>
	///
	/// <remarks>
	///		If the index is invalid, returns a pointer to invalid memory.<br/>
	/// </remarks>
	static const char* sz_from_index(const Strind string)
	{
		return engine_funcs_->sz_from_index(string);
	}

	/// <summary>
	/// <para>Allocates a string in the string pool.<br/></para>
	/// </summary>
	/// 
	/// <param name="value">
	///		String to allocate.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index assigned to the string.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This will allocate memory from the hunk. If the hunk runs out of memory, will trigger sys error.<br/>
	///		Each call allocates new memory. No actual pooling of strings occurs.<br/>
	/// </remarks>
	static Strind alloc_string(const char* value)
	{
		return engine_funcs_->alloc_string(value);
	}

	/// <summary>
	/// <para>Gets the <c>EntityVars</c> instance assigned to the given <c>Edict</c> instance.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose <c>EntityVars</c> is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		<c>EntityVars</c><br/>
	/// </returns>
	///
	/// <remarks>
	///		In effect, returns <c>&entity->vars</c>.<br/>
	///		If <c>entity</c> is null, causes a crash.<br/>
	/// </remarks>
	static EntityVars* get_vars_of_ent(Edict* entity)
	{
		return engine_funcs_->get_vars_of_ent(entity);
	}

	/// <summary>
	/// <para>Gets an edict by offset.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity_offset">
	///		Entity offset.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Edict at the given offset.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This uses the byte offset of the edict to retrieve it.<br/>
	///		DO NOT USE THIS. Use <c>entity_of_ent_index</c>.<br/>
	/// </remarks>
	static Edict* entity_of_ent_offset(const eoffset entity_offset)
	{
		return engine_funcs_->entity_of_ent_offset(entity_offset);
	}

	/// <summary>
	/// <para>Gets the entity offset of the edict.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Edict whose offset is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Entity offset.<br/>
	/// </returns>
	///
	/// <remarks>
	///		DO NOT USE THIS. Use <c>index_of_edict</c>.<br/>
	/// </remarks>
	static eoffset ent_offset_of_entity(const Edict* entity)
	{
		return engine_funcs_->ent_offset_of_entity(entity);
	}

	/// <summary>
	/// <para>Gets the entity index of the edict.<br/></para>
	/// </summary>
	/// 
	/// <param name="edict">
	///		Edict whose entity index is to be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		If <c>edict</c> is null, returns 0.<br/>
	///		If <c>edict</c> is not managed by the engine, triggers a sys error.<br/>
	///		Otherwise, returns the entity index.<br/>
	/// </returns>
	static int index_of_edict(const Edict* edict)
	{
		return engine_funcs_->index_of_edict(edict);
	}

	/// <summary>
	/// <para>Gets the edict at the given entity index.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity_index">
	///		Entity index.<br/>
	/// </param>
	/// 
	/// <returns>
	///		If the given index is not valid, returns null.<br/>
	///		Otherwise, if the entity at the given index is not in use, returns null.<br/>
	///		Otherwise, if the entity at the given index is not a player and does not have a <c>EntityBase</c> instance, returns null.<br/>
	///		Otherwise, returns the entity.<br/>
	/// </returns>
	static Edict* entity_of_ent_index(const int entity_index)
	{
		return engine_funcs_->entity_of_ent_index(entity_index);
	}

	/// <summary>
	/// <para>Gets the edict of an <c>EntityVars</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="vars">
	///		EntityVars.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Edict.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This will enumerate all entities, so this operation can be very expensive.<br/>
	///		Use <c>vars->containing_entity</c> if possible.<br/>
	/// </remarks>
	static Edict* find_entity_by_vars(EntityVars* vars)
	{
		return engine_funcs_->find_entity_by_vars(vars);
	}

	/// <summary>
	/// <para>Gets the model pointer of the given entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Pointer to the model, or null if the entity doesn't have one.<br/>
	///		Triggers a sys error if the model wasn't loaded and couldn't be loaded.<br/>
	/// </returns>
	static void* get_model_pointer(Edict* entity)
	{
		return engine_funcs_->get_model_pointer(entity);
	}

	/// <summary>
	/// <para>Registers a user message.<br/></para>
	/// </summary>
	/// 
	/// <param name="name">
	///		Name of the message. Maximum length is 12, excluding null terminator. Can be a temporary string.
	/// </param>
	/// <param name="size">
	///		Size of the message, in bytes. Maximum size is 192 bytes. Specify -1 for variable length messages.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Message ID, or 0 if the message could not be registered.<br/>
	/// </returns>
	///
	/// <remarks>
	///		The name of the message is used to find an exported function in the client library.<br/>
	///		The format is MsgFunc_<name>.<br/>
	/// </remarks>
	static int reg_user_message(const char* name, const int size)
	{
		return engine_funcs_->reg_user_message(name, size);
	}

	/// <summary>
	/// <para>Does nothing.<br/></para>
	/// </summary>
	static void animation_auto_move(const Edict* entity, const float time)
	{
		engine_funcs_->animation_auto_move(entity, time);
	}

	/// <summary>
	/// <para>Gets the bone position and angles for the given entity and bone.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose model should be queried.
	/// </param>
	/// <param name="bone">
	///		Bone index.
	/// </param>
	/// <param name="origin">
	///		Origin of the bone.
	/// </param>
	/// <param name="angles">
	///		Angles of the bone. Is not set by the engine.<br/>
	/// </param>
	///
	/// <remarks>
	///		If the given entity is invalid, or does not have a studio model,
	///		or the bone index is invalid, will cause invalid accesses to occur.<br/>
	/// </remarks>
	static void get_bone_position(const Edict* entity, const int bone, Vector& origin, Vector& angles)
	{
		engine_funcs_->get_bone_position(entity, bone, origin, angles);
	}

	/// <summary>
	/// <para>Gets the index of an exported function.<br/></para>
	/// </summary>
	/// 
	/// <param name="name">
	///		Name of the function.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the function, or 0 if the function couldn't be found.<br/>
	/// </returns>
	static uint32 function_from_name(const char* name)
	{
		return engine_funcs_->function_from_name(name);
	}

	/// <summary>
	/// <para>Gets the name of an exported function.<br/></para>
	/// </summary>
	/// 
	/// <param name="function">
	///		Function index.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Function name, or null if no function exists at that index.<br/>
	/// </returns>
	static const char* name_for_function(const uint32 function)
	{
		return engine_funcs_->name_for_function(function);
	}

	/// <summary>
	/// <para>Sends a message to the client console.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Client to send the message to.
	/// </param>
	/// <param name="type">
	///		Where to print the message.
	/// </param>
	/// <param name="message">
	///		Message to send.<br/>
	/// </param>
	///
	/// <remarks>
	///		<c>PrintType::Chat</c> outputs to the console, just as <c>PrintType::Console</c>.<br/>
	/// </remarks>
	static void client_print(Edict* entity, const PrintType type, const char* message)
	{
		engine_funcs_->client_print(entity, type, message);
	}

	/// <summary>
	/// <para>Sends a message to the server console.<br/></para>
	/// </summary>
	/// 
	/// <param name="message">
	///		Message to send.<br/>
	/// </param>
	///
	/// <remarks>
	///		The message is output regardless of the value of the developer cvar.<br/>
	/// </remarks>
	static void server_print(const char* message)
	{
		engine_funcs_->server_print(message);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <returns>
	/// String containing all of the command arguments, not including the command name.
	/// </returns>
	static const char* cmd_args()
	{
		return engine_funcs_->cmd_args();
	}

	/// <summary>
	/// <para>Gets the command argument at the given index.<br/></para>
	/// </summary>
	/// 
	/// <param name="argc">
	///		Argument index.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Command argument.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Argument 0 is the command name.<br/>
	/// </remarks>
	static const char* cmd_argv(const int argc)
	{
		return engine_funcs_->cmd_argv(argc);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <returns>
	///		The number of command arguments. This includes the command name.
	/// </returns>
	static int cmd_argc()
	{
		return engine_funcs_->cmd_argc();
	}

	/// <summary>
	/// <para>Gets the attachment origin and angles.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity whose model will be queried for the attachment data.
	/// </param>
	/// <param name="attachment">
	///		Attachment index.
	/// </param>
	/// <param name="origin">
	///		Attachment origin.
	/// </param>
	/// <param name="angles">
	///		Attachment angles.<br/>
	/// </param>
	///
	/// <remarks>
	///		If the entity is null, or does not have a studio model, illegal access will occur.<br/>
	/// </remarks>
	static void get_attachment(const Edict* entity, const int attachment, Vector& origin, Vector& angles)
	{
		engine_funcs_->get_attachment(entity, attachment, origin, angles);
	}

	/// <summary>
	/// <para>Initializes the CRC instance.<br/></para>
	/// </summary>
	static void crc32_init(crc32* pul_crc)
	{
		engine_funcs_->crc32_init(pul_crc);
	}

	/// <summary>
	/// <para>Processes a buffer and updates the CRC.<br/></para>
	/// </summary>
	/// 
	/// <param name="pul_crc">
	///		CRC instance.
	/// </param>
	/// <param name="buffer">
	///		Buffer to process.
	/// </param>
	/// <param name="len">
	///		Number of bytes in the buffer to process.
	/// </param>
	static void crc32_process_buffer(crc32* pul_crc, void* buffer, const int len)
	{
		engine_funcs_->crc32_process_buffer(pul_crc, buffer, len);
	}

	/// <summary>
	/// <para>Processes a single byte.<br/></para>
	/// </summary>
	/// 
	/// <param name="pul_crc">
	///		CRC instance.
	/// </param>
	/// <param name="ch">
	///		Byte.
	/// </param>
	static void crc32_process_byte(crc32* pul_crc, const unsigned char ch)
	{
		engine_funcs_->crc32_process_byte(pul_crc, ch);
	}

	/// <summary>
	/// <para>Finalizes the CRC instance.<br/></para>
	/// </summary>
	/// 
	/// <param name="pul_crc">
	///		CRC instance.<br/>
	/// </param>
	/// 
	/// <returns>
	///		CRC value.<br/>
	/// </returns>
	static crc32 crc32_final(const crc32 pul_crc)
	{
		return engine_funcs_->crc32_final(pul_crc);
	}

	/// <summary>
	/// <para>Generates a random long number in the range <c>low</c> - <c>high</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="low">
	///		Lower bound.
	/// </param>
	/// <param name="high">
	///		Higher bound.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Random number, or <c>low</c> if <c>high</c> is smaller than or equal to <c>low</c>.<br/>
	/// </returns>
	static int32 random_long(const int32 low, const int32 high)
	{
		return engine_funcs_->random_long(low, high);
	}

	/// <summary>
	/// <para>Generates a random long number in the range <c>low</c> - <c>high</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="low">
	///		Lower bound.
	/// </param>
	/// <param name="high">
	///		Higher bound.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Random number, or <c>low</c> if <c>high</c> is smaller than or equal to <c>low</c>.<br/>
	/// </returns>
	static float random_float(const float low, const float high)
	{
		return engine_funcs_->random_float(low, high);
	}

	/// <summary>
	/// <para>Sets the view of a client to the given entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client whose view is to be set.
	/// </param>
	/// <param name="view_entity">
	///		Entity to use as the client's viewpoint.<br/>
	/// </param>
	///
	/// <remarks>
	///		If <c>client</c> is not a client, triggers a host error.<br/>
	///		Set the view to the client itself to reset it.<br/>
	/// </remarks>
	static void set_view(const Edict* client, const Edict* view_entity)
	{
		engine_funcs_->set_view(client, view_entity);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <returns>
	///		The time since the first call to Time.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Used for delta operations that operate in real world time,
	///		as opposed to game world time (which will advance frame by frame, and can be paused).<br/>
	/// </remarks>
	static float time()
	{
		return engine_funcs_->time();
	}

	/// <summary>
	/// <para>Sets the angles of the given player's crosshairs to the given settings.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client whose crosshair settings should be set.
	/// </param>
	/// <param name="pitch">
	///		Pitch.
	/// </param>
	/// <param name="yaw">
	///		Yaw.<br/>
	/// </param>
	///
	/// <remarks>
	///		Set both to 0 to disable.<br/>
	/// </remarks>
	static void crosshair_angle(const Edict* client, const float pitch, const float yaw)
	{
		engine_funcs_->crosshair_angle(client, pitch, yaw);
	}

	/// <summary>
	/// <para>Loads a file from disk.<br/></para>
	/// </summary>
	/// 
	/// <param name="file_name">
	///		Name of the file. Path starts in the game directory.
	/// </param>
	/// <param name="length">
	///		If not null, is set to the size of the file, in bytes.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Pointer to the file buffer, or null if the file could not be loaded.<br/>
	/// </returns>
	static byte* load_file_for_me(const char* file_name, int* length)
	{
		return engine_funcs_->load_file_for_me(file_name, length);
	}

	/// <summary>
	/// <para>Frees the buffer provided by <c>load_file_for_me</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="buffer">
	///		Pointer to buffer.<br/>
	/// </param>
	static void free_file(void* buffer)
	{
		engine_funcs_->free_file(buffer);
	}

	/// <summary>
	/// <para>Signals the engine that a section has ended.<br/></para>
	/// </summary>
	/// 
	/// <param name="section_name">
	///		Possible values:<br/>
	///		_oem_end_training<br/>
	///		_oem_end_logo<br/>
	///		_oem_end_demo<br/>
	/// </param>
	///
	/// <remarks>
	///		A disconnect command is sent by this call.<br/>
	/// </remarks>
	static void end_section(const char* section_name)
	{
		engine_funcs_->end_section(section_name);
	}

	/// <summary>
	/// <para>Compares file times.<br/></para>
	/// </summary>
	/// 
	/// <param name="file_name1">
	///		First file to compare.
	/// </param>
	/// <param name="file_name2">
	///		Second file to compare.<br/>
	/// </param>
	/// <param name="compare">
	///		<br/>
	///		If both files are equal, 0.<br/>
	///		If the first file is older, -1.<br/>
	///		If the second file is older, 1.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if both file names are non-null, false otherwise.<br/>
	/// </returns>
	static qboolean compare_file_time(char* file_name1, char* file_name2, int* compare)
	{
		return engine_funcs_->compare_file_time(file_name1, file_name2, compare);
	}

	/// <summary>
	/// <para>Gets the game directory name.<br/></para>
	/// </summary>
	/// 
	/// <param name="game_dir">
	///		Buffer to store the game directory name in. Must be at least MAX_PATH bytes large.<br/>
	/// </param>
	static void get_game_dir(char* game_dir)
	{
		engine_funcs_->get_game_dir(game_dir);
	}

	/// <summary>
	/// <para>Registers a CVar.<br/>
	/// Identical to <c>cvar_register</c>, except it doesn't set the <c>FCVAR_EXT_DLL</c> flag.<br/></para>
	/// </summary>
	static void cvar_register_variable(CVar* variable)
	{
		engine_funcs_->cvar_register_variable(variable);
	}

	/// <summary>
	/// <para>Fades the given client's volume.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.
	/// </param>
	/// <param name="fade_percent">
	///		Percentage volume to fade out to.
	/// </param>
	/// <param name="fade_out_seconds">
	///		How long it takes to fade out, in seconds.
	/// </param>
	/// <param name="hold_time">
	///		How long to stay faded out, in seconds.
	/// </param>
	/// <param name="fade_in_seconds">
	///		How long it takes to fade in, in seconds.<br/>
	/// </param>
	static void fade_client_volume(const Edict* client, const int fade_percent, const int fade_out_seconds,
	                               const int hold_time, const int fade_in_seconds)
	{
		engine_funcs_->fade_client_volume(client, fade_percent, fade_out_seconds, hold_time, fade_in_seconds);
	}

	/// <summary>
	/// <para>Sets the client's maximum speed value.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client to set.
	/// </param>
	/// <param name="new_max_speed">
	///		Maximum speed value.<br/>
	/// </param>
	///
	/// <remarks>
	///		Effectively sets <c>Edict->vars.max_speed.</c><br/>
	/// </remarks>
	static void set_client_max_speed(Edict* client, const float new_max_speed)
	{
		engine_funcs_->set_client_max_speed(client, new_max_speed);
	}

	/// <summary>
	/// <para>Creates a fake client (bot).<br/></para>
	/// </summary>
	/// 
	/// <param name="name">
	///		Name of the client to show.<br/>
	/// </param>
	/// 
	/// <returns>
	///		The fake client, or null if it can't be created.<br/>
	/// </returns>
	static Edict* create_fake_client(const char* name)
	{
		return engine_funcs_->create_fake_client(name);
	}

	/// <summary>
	/// <para>Runs player movement for a fake client.<br/></para>
	/// </summary>
	/// 
	/// <param name="fake_client">
	///		Client to move. Must be a fake client.
	/// </param>
	/// <param name="view_angles">
	///		Client view angles.
	/// </param>
	/// <param name="forward_move">
	///		Velocity X value.
	/// </param>
	/// <param name="side_move">
	///		Velocity Y value.
	/// </param>
	/// <param name="up_move">
	///		Velocity Z value.
	/// </param>
	/// <param name="buttons">
	///		Buttons that are currently pressed in. Equivalent to player <c>vars.button.</c>.
	/// </param>
	/// <param name="impulse">
	///		Impulse commands to execute. Equivalent to player <c>vars.impulse.</c>.
	/// </param>
	/// <param name="msec">
	///		Time between now and previous <c>run_player_move</c> call.<br/>
	/// </param>
	static void run_player_move(Edict* fake_client, const Vector& view_angles, const float forward_move, const float side_move, const float up_move,
	                            const unsigned short buttons, const byte impulse, const byte msec)
	{
		engine_funcs_->run_player_move(fake_client, view_angles, forward_move, side_move, up_move, buttons, impulse, msec);
	}

	/// <summary>
	/// <para>Computes the total number of entities currently in existence.<br/></para>
	/// </summary>
	/// 
	/// <returns>
	///		Number of entities.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This will calculate the number of entities in real-time. May be expensive if called many times.<br/>
	/// </remarks>
	static int number_of_entities()
	{
		return engine_funcs_->number_of_entities();
	}

	/// <summary>
	/// <para>Gets the given client's info key buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Info key buffer.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Passing in the world gets the server info.<br/>
	///		Passing in null gets the local info. Local info is not used by the engine itself, only the game.<br/>
	///		This function checks the max players value incorrectly and may crash if the wrong edict gets passed in.<br/>
	/// </remarks>
	static char* get_info_key_buffer(Edict* client)
	{
		return engine_funcs_->get_info_key_buffer(client);
	}

	/// <summary>
	/// <para>Gets the value of the given key from the given buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="info_buffer">
	///		Buffer to query.
	/// </param>
	/// <param name="key">
	///		Key whose value to retrieve.<br/>
	/// </param>
	/// 
	/// <returns>
	///		The requested value, or an empty string.<br/>
	/// </returns>
	static char* info_key_value(char* info_buffer, const char* key)
	{
		return engine_funcs_->info_key_value(info_buffer, key);
	}

	/// <summary>
	/// <para>Sets the value of the given key in the given buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="info_buffer">
	///		Buffer to modify.
	/// </param>
	/// <param name="key">
	///		Key whose value to set.
	/// </param>
	/// <param name="value">
	///		Value to set.<br/>
	/// </param>
	///
	/// <remarks>
	///		If the given buffer is not the local info or server info buffer, triggers a sys error.<br/>
	/// </remarks>
	static void set_key_value(char* info_buffer, const char* key, const char* value)
	{
		engine_funcs_->set_key_value(info_buffer, key, value);
	}

	/// <summary>
	/// <para>Sets the value of the given key in the given buffer.<br/>
	/// This only works for client buffers.<br/></para>
	/// </summary>
	/// 
	/// <param name="client_index">
	///		Entity index of the client.
	/// </param>
	/// <param name="info_buffer">
	///		Buffer to modify.
	/// </param>
	/// <param name="key">
	///		Key whose value to set.
	/// </param>
	/// <param name="value">
	///		Value to set.<br/>
	/// </param>
	static void set_client_key_value(const int client_index, char* info_buffer, const char* key, const char* value)
	{
		engine_funcs_->set_client_key_value(client_index, info_buffer, key, value);
	}

	/// <summary>
	/// <para>Checks if the given filename is a valid map.<br/></para>
	/// </summary>
	/// 
	/// <param name="file_name">
	///		Name of the map to check.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if the map is valid, false otherwise.
	/// </returns>
	static qboolean is_map_valid(const char* file_name)
	{
		return engine_funcs_->is_map_valid(file_name);
	}

	/// <summary>
	/// <para>Projects a static decal in the world.<br/></para>
	/// </summary>
	/// 
	/// <param name="origin">
	///		Origin in the world to project the decal at.
	/// </param>
	/// <param name="decal_index">
	///		Index of the decal to project.
	/// </param>
	/// <param name="entity_index">
	///		Index of the entity to project the decal onto.
	/// </param>
	/// <param name="model_index">
	///		Index of the model to project the decal onto.<br/>
	/// </param>
	static void static_decal(const Vector& origin, const int decal_index, const int entity_index, const int model_index)
	{
		engine_funcs_->static_decal(origin, decal_index, entity_index, model_index);
	}

	/// <summary>
	/// <para>Precaches a file.<br/></para>
	/// </summary>
	/// 
	/// <param name="path">
	///		Name of the file to precache. Starts in the game directory.<br/>
	///		This string must live for at least as long as the map itself.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the file.<br/>
	/// </returns>
	///
	/// <remarks>
	///		If <c>path</c> is null, is empty or contains an invalid value in the first character, triggers a host error.<br/>
	///		If the maximum number of generic precacheable resources has been reached, triggers a host error.<br/>
	///		If this is called after <c>server_activate</c>, triggers a host error.<br/>
	/// </remarks>
	static int precache_generic(const char* path)
	{
		return engine_funcs_->precache_generic(path);
	}

	/// <summary>
	/// <para>Returns the server assigned userid for this player.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.<br/>
	///	</param>
	/// 
	/// <returns>
	///		 User ID or -1 if the edict couldn't be found in the list of clients.<br/>
	/// </returns>
	static int get_player_user_id(Edict* client)
	{
		return engine_funcs_->get_player_user_id(client);
	}

	/// <summary>
	/// <para>Builds a sound message to send to a client.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity that is playing the sound.
	/// </param>
	/// <param name="channel">
	///		Channel to play the sound on.
	/// </param>
	/// <param name="sample">
	///		Sound to play.
	/// </param>
	/// <param name="volume">
	///		Volume of the sound. Must be in the range 0 - 1.
	/// </param>
	/// <param name="attenuation">
	///		Attenuation.
	/// </param>
	/// <param name="flags">
	///		Sound flags.
	/// </param>
	/// <param name="pitch">
	///		Pitch. Must be in the range 0 - 255.
	/// </param>
	/// <param name="msg_type">
	///		Message type.
	/// </param>
	/// <param name="msg_id">
	///		Message ID.
	/// </param>
	/// <param name="origin">
	///		Origin in the world to use for PAS and PVS messages.
	/// </param>
	/// <param name="client">
	///		Client to send the message to for message types that target one client.<br/>
	/// </param>
	static void build_sound_msg(Edict* entity, const int channel, const char* sample, const float volume, const float attenuation, const int flags,
	                            const int pitch, const MessageType msg_type, const int msg_id, const Vector& origin, Edict* client)
	{
		engine_funcs_->build_sound_msg(entity, channel, sample, volume, attenuation, flags, pitch, msg_type, msg_id, origin, client);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <returns>
	///		Whether this is a dedicated server.<br/>
	/// </returns>
	static qboolean is_dedicated_server()
	{
		return engine_funcs_->is_dedicated_server();
	}

	/// <summary>
	/// </summary>
	/// 
	/// <param name="cvar_name">
	///		Name of the CVar to retrieve.<br/>
	/// </param>
	/// 
	/// <returns>
	///		CVar pointer, or null if the cvar doesn't exist.<br/>
	/// </returns>
	static CVar* cvar_get_pointer(const char* cvar_name)
	{
		return engine_funcs_->cvar_get_pointer(cvar_name);
	}

	/// <summary>
	/// <para>Returns the server assigned WONid for this player.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.<br/>
	/// </param>
	/// 
	/// <returns>
	///		WON ID, or -1 if the edict couldn't be found in the list of clients.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Always returns -1 when using the Steam version.<br/>
	/// </remarks>
	static unsigned int get_player_won_id(Edict* client)
	{
		return engine_funcs_->get_player_won_id(client);
	}

	/// <summary>
	/// <para>Removes a key from the info buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="info_buffer">
	///		Buffer to modify.
	/// </param>
	/// <param name="key">
	///		Key to remove.<br/>
	/// </param>
	static void info_remove_key(char* info_buffer, const char* key)
	{
		engine_funcs_->info_remove_key(info_buffer, key);
	}

	/// <summary>
	/// <para>Gets the given physics key-value from the given client's buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client whose buffer will be queried.
	/// </param>
	/// <param name="key">
	///		Key whose value will be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		The value, or an empty string if the key does not exist.<br/>
	/// </returns>
	static const char* get_physics_key_value(const Edict* client, const char* key)
	{
		return engine_funcs_->get_physics_key_value(client, key);
	}

	/// <summary>
	/// <para>Sets the given physics key-value in the given client's buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client whose buffer will be modified.
	/// </param>
	/// <param name="key">
	///		Key whose value will be set.
	/// </param>
	/// <param name="value">
	///		Value to set.<br/>
	/// </param>
	static void set_physics_key_value(const Edict* client, const char* key, const char* value)
	{
		engine_funcs_->set_physics_key_value(client, key, value);
	}

	/// <summary>
	/// <para>Gets the physics info string for the given client.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client whose buffer will be retrieved.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Buffer, or an empty string if the client is invalid.<br/>
	/// </returns>
	static const char* get_physics_info_string(const Edict* client)
	{
		return engine_funcs_->get_physics_info_string(client);
	}

	/// <summary>
	/// <para>Precaches an event.<br/></para>
	/// </summary>
	/// 
	/// <param name="type">
	///		Should always be 1.
	/// </param>
	/// <param name="path">
	///		Name of the event. Format should be events/<name>.sc, including the directory and extension.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Event index. Used with <c>playback_event</c>.<br/>
	/// </returns>
	static unsigned short precache_event(const int type, const char* path)
	{
		return engine_funcs_->precache_event(type, path);
	}

	/// <summary>
	/// </summary>
	/// 
	/// <param name="flags">
	///		Event flags.
	/// </param>
	/// <param name="invoker">
	///		Client that triggered the event.
	/// </param>
	/// <param name="event_index">
	///		Event index.
	/// </param>
	/// <param name="delay">
	///		Delay before the event should be run.
	/// </param>
	/// <param name="origin">
	///		If not zero vector, this is the origin parameter sent to the clients.
	/// </param>
	/// <param name="angles">
	///		If not zero vector, this is the angles parameter sent to the clients.
	/// </param>
	/// <param name="f_param1">
	///		Float parameter 1.
	/// </param>
	/// <param name="f_param2">
	///		Float parameter 2.
	/// </param>
	/// <param name="i_param1">
	///		Integer parameter 1.
	/// </param>
	/// <param name="i_param2">
	///		Integer parameter 2.
	/// </param>
	/// <param name="b_param1">
	///		Boolean parameter 1.
	/// </param>
	/// <param name="b_param2">
	///		Boolean parameter 2.<br/>
	/// </param>
	static void playback_event(const int flags, const Edict* invoker, const unsigned short event_index, const float delay, Vector& origin, Vector& angles,
	                           const float f_param1, const float f_param2, const int i_param1, const int i_param2, const qboolean b_param1, const qboolean b_param2)
	{
		engine_funcs_->playback_event(flags, invoker, event_index, delay, origin, angles, f_param1, f_param2, i_param1, i_param2, b_param1, b_param2);
	}

	/// <summary>
	/// <para>Sets the Fat Potentially Visible Set buffer to contain data based on the given origin.<br/></para>
	/// </summary>
	/// 
	/// <param name="origin">
	///		Origin.<br/>
	/// </param>
	/// 
	/// <returns>
	///		PVS data.<br/>
	/// </returns>
	static unsigned char* set_fat_pvs(Vector& origin)
	{
		return engine_funcs_->set_fat_pvs(origin);
	}

	/// <summary>
	/// <para>Sets the Fat Potentially Audible Set buffer to contain data based on the given origin.<br/></para>
	/// </summary>
	/// 
	/// <param name="origin">
	///		Origin.<br/>
	/// </param>
	/// 
	/// <returns>
	///		PAS data.<br/>
	/// </returns>
	static unsigned char* set_fat_pas(Vector& origin)
	{
		return engine_funcs_->set_fat_pas(origin);
	}

	/// <summary>
	/// <para>Checks if the given entity is visible in the given visible set.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to check.
	/// </param>
	/// <param name="set">
	///		Buffer detailing the current visible set.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Whether the given entity is visible in the given visible set.<br/>
	/// </returns>
	static qboolean check_visibility(Edict* entity, unsigned char* set)
	{
		return engine_funcs_->check_visibility(entity, set);
	}

	/// <summary>
	/// <para>Marks the given field in the given list as set.<br/></para>
	/// </summary>
	/// 
	/// <param name="fields">
	///		List of fields.
	/// </param>
	/// <param name="field_name">
	///		Field name.<br/>
	/// </param>
	static void delta_set_field(struct delta* fields, const char* field_name)
	{
		engine_funcs_->delta_set_field(fields, field_name);
	}

	/// <summary>
	/// <para>Marks the given field in the given list as not set.<br/></para>
	/// </summary>
	/// 
	/// <param name="fields">
	///		List of fields.
	/// </param>
	/// <param name="field_name">
	///		Field name.<br/>
	/// </param>
	static void delta_unset_field(struct delta* fields, const char* field_name)
	{
		engine_funcs_->delta_unset_field(fields, field_name);
	}

	/// <summary>
	/// <para>Adds a delta encoder.<br/></para>
	/// </summary>
	/// 
	/// <param name="name">
	///		Name of the delta.lst entry to add the encoder for.
	/// </param>
	/// <param name="conditional_encode">
	///		Encoder function.<br/>
	/// </param>
	static void delta_add_encoder(const char* name, void (*conditional_encode)(struct delta* fields, const unsigned char* from, const unsigned char* to))
	{
		engine_funcs_->delta_add_encoder(name, conditional_encode);
	}

	/// <summary>
	/// <para>Returns the client index of the client that is currently being handled by an engine callback.<br/></para>
	/// </summary>
	/// 
	/// <returns>
	///		-1 if no client is currently being handled.<br/>
	/// </returns>
	static int get_current_player()
	{
		return engine_funcs_->get_current_player();
	}

	/// <summary>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if the given client has cl_lw (weapon prediction) enabled.
	/// </returns>
	static qboolean can_skip_player(const Edict* client)
	{
		return engine_funcs_->can_skip_player(client);
	}

	/// <summary>
	/// <para>Finds the index of a delta field.<br/></para>
	/// </summary>
	/// 
	/// <param name="fields">
	///		List of fields.
	/// </param>
	/// <param name="field_name">
	///		Name of the field to find.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Index of the delta field, or -1 if the field couldn't be found.
	/// </returns>
	static int delta_find_field(struct delta* fields, const char* field_name)
	{
		return engine_funcs_->delta_find_field(fields, field_name);
	}

	/// <summary>
	/// <para>Marks a delta field as set by index.<br/></para>
	/// </summary>
	/// 
	/// <param name="fields">
	///		List of fields.
	/// </param>
	/// <param name="field_number">
	///		Index of the field.<br/>
	/// </param>
	///
	/// <remarks>
	///		If the index is invalid, causes illegal access.<br/>
	/// </remarks>
	static void delta_set_field_by_index(struct delta* fields, const int field_number)
	{
		engine_funcs_->delta_set_field_by_index(fields, field_number);
	}

	/// <summary>
	/// <para>Marks a delta field as not set by index.<br/></para>
	/// </summary>
	/// 
	/// <param name="fields">
	///		List of fields.
	/// </param>
	/// <param name="field_number">
	///		Index of the field.<br/>
	/// </param>
	///
	/// <remarks>
	///		If the index is invalid, causes illegal access.<br/>
	/// </remarks>
	static void delta_unset_field_by_index(struct delta* fields, const int field_number)
	{
		engine_funcs_->delta_unset_field_by_index(fields, field_number);
	}

	/// <summary>
	/// <para>Used to filter contents checks.<br/></para>
	/// </summary>
	/// 
	/// <param name="mask">
	///		Mask to check.
	/// </param>
	/// <param name="operation">
	///		Operation to perform during masking.<br/>
	/// </param>
	static void set_group_mask(const int mask, const int operation)
	{
		engine_funcs_->set_group_mask(mask, operation);
	}

	/// <summary>
	/// <para>Creates an instanced baseline. Used to define a baseline for a particular entity type.<br/></para>
	/// </summary>
	/// 
	/// <param name="class_name">
	///		Name of the entity class.
	/// </param>
	/// <param name="baseline">
	///		Baseline to set.<br/>
	/// </param>
	/// 
	/// <returns>
	/// </returns>
	static int create_instanced_baseline(const Strind class_name, EntityState* baseline)
	{
		return engine_funcs_->create_instanced_baseline(class_name, baseline);
	}

	/// <summary>
	/// <para>Directly sets a CVar value.<br/></para>
	/// </summary>
	/// 
	/// <param name="cvar">
	///		CVar.
	/// </param>
	/// <param name="value">
	///		Value to set.<br/>
	/// </param>
	static void cvar_direct_set(CVar* cvar, const char* value)
	{
		engine_funcs_->cvar_direct_set(cvar, value);
	}

	/// <summary>
	/// <para>Forces the client and server to be running with the same version of the specified file (e.g., a player model).<br/></para>
	/// </summary>
	/// 
	/// <param name="type">
	///		Force type.
	/// </param>
	/// <param name="min_size">
	///		If not null, the minimum bounds that a model can be.
	/// </param>
	/// <param name="max_size">
	///		If not null, the maximum bounds that a model can be.
	/// </param>
	/// <param name="file_name">
	///		File to verify. This string must live for at least as long as the map itself.<br/>
	/// </param>
	///
	/// <remarks>
	///		Calling this has no effect in single player.<br/>
	/// </remarks>
	static void force_unmodified(const ForceType type, Vector& min_size, Vector& max_size, const char* file_name)
	{
		engine_funcs_->force_unmodified(type, min_size, max_size, file_name);
	}

	/// <summary>
	/// <para>Get player statistics.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client to query.
	/// </param>
	/// <param name="ping">
	///		Current ping.
	/// </param>
	/// <param name="packet_loss">
	///		Current packet loss, measured in percentage.<br/>
	/// </param>
	static void get_player_stats(const Edict* client, int* ping, int* packet_loss)
	{
		engine_funcs_->get_player_stats(client, ping, packet_loss);
	}

	/// <summary>
	/// <para>Adds a server command.<br/></para>
	/// </summary>
	/// 
	/// <param name="cmd_name">
	///		Name of the command to add. This string must live for the rest of the server's lifetime.
	/// </param>
	/// <param name="callback">
	///		Function to invoke when the command is received.<br/>
	/// </param>
	static void add_server_command(const char* cmd_name, void (*callback)())
	{
		engine_funcs_->add_server_command(cmd_name, callback);
	}

	/// <summary>
	/// <para>Gets whether the given receiver can hear the given sender.<br/></para>
	/// </summary>
	/// 
	/// <param name="receiver">
	///		Receiver. This is an entity index.
	/// </param>
	/// <param name="sender">
	///		Sender. This is an entity index.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Whether the given receiver can hear the given sender.<br/>
	/// </returns>
	static qboolean voice_get_client_listening(const int receiver, const int sender)
	{
		return engine_funcs_->voice_get_client_listening(receiver, sender);
	}

	/// <summary>
	/// <para>Sets whether the given receiver can hear the given sender.<br/></para>
	/// </summary>
	/// 
	/// <param name="receiver">
	///		Receiver. This is an entity index.
	/// </param>
	/// <param name="sender">
	///		Sender. This is an entity index.
	/// </param>
	/// <param name="listen">
	///		Whether the given receiver can hear the given sender.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Whether the setting was changed.<br/>
	/// </returns>
	static qboolean voice_set_client_listening(const int receiver, const int sender, const qboolean listen)
	{
		return engine_funcs_->voice_set_client_listening(receiver, sender, listen);
	}

	/// <summary>
	/// <para>Gets the player's auth ID.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.<br/>
	/// </param>
	/// 
	/// <returns>
	///		The player's auth ID, or an empty string. This points to a temporary buffer, copy the results.<br/>
	/// </returns>
	static const char* get_player_auth_id(Edict* client)
	{
		return engine_funcs_->get_player_auth_id(client);
	}

	/// <summary>
	/// <para>Gets the sequence that has the given entry name.<br/></para>
	/// </summary>
	/// 
	/// <param name="file_name">
	///		Ignored.
	/// </param>
	/// <param name="entry_name">
	///		Entry name.<br/>
	///	</param>
	///	
	/// <returns>
	///		Sequence, or null if no such sequence exists.<br/>
	/// </returns>
	static SequenceEntry* sequence_get(const char* file_name, const char* entry_name)
	{
		return engine_funcs_->sequence_get(file_name, entry_name);
	}

	/// <summary>
	/// <para>Picks a sentence from the given group.<br/></para>
	/// </summary>
	/// 
	/// <param name="group_name">
	///		Group from which to select a sentence.
	/// </param>
	/// <param name="pick_method">
	///		Ignored.
	///	</param>
	/// <param name="picked">
	///		If not null, this is set to the index of the sentence that was picked.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Sentence that was picked, or null if there is no group by that name, or no sentences in the group.<br/>
	/// </returns>
	static SentenceEntry* sequence_pick_sentence(const char* group_name, const int pick_method, int* picked)
	{
		return engine_funcs_->sequence_pick_sentence(group_name, pick_method, picked);
	}

	/// <summary>
	/// <para>LH: Give access to file size via filesystem.<br/></para>
	/// </summary>
	/// 
	/// <param name="file_name">
	///		Name of the file whose size is to be queried.<br/>
	///	</param>
	///	
	/// <returns>
	///		File size, or -1 if the file doesn't exist.<br/>
	/// </returns>
	static int get_file_size(const char* file_name)
	{
		return engine_funcs_->get_file_size(file_name);
	}

	/// <summary>
	/// <para>Gets the average wave length in seconds.<br/></para>
	/// </summary>
	/// 
	/// <param name="file_path">
	///		Name of the sound.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Length of the sound file, in seconds.<br/>
	/// </returns>
	static unsigned int get_approx_wave_play_len(const char* file_path)
	{
		return engine_funcs_->get_approx_wave_play_len(file_path);
	}

	/// <summary>
	/// <para>MDC: Added for CZ career-mode.<br/></para>
	/// </summary>
	/// 
	/// <returns>
	///		Whether this is a Condition Zero Career match.<br/>
	/// </returns>
	static qboolean is_career_match()
	{
		return engine_funcs_->is_career_match();
	}

	/// <summary>
	/// </summary>
	/// 
	/// <param name="label">
	///		Label.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Number of characters of the localized string referenced by using label.<br/>
	/// </returns>
	static int get_localized_string_length(const char* label)
	{
		return engine_funcs_->get_localized_string_length(label);
	}

	/// <summary>
	/// <para>Marks the message with the given ID as having been shown.<br/></para>
	/// </summary>
	/// 
	/// <param name="message_id">
	///		Message ID.<br/>
	/// </param>
	static void register_tutor_message_shown(const int message_id)
	{
		engine_funcs_->register_tutor_message_shown(message_id);
	}

	/// <summary>
	/// <para>Gets the number of times the message with the given ID has been shown.<br/></para>
	/// </summary>
	/// 
	/// <param name="message_id">
	///		Message ID.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Number of times the message with the given ID has been shown.<br/>
	/// </returns>
	static int get_times_tutor_message_shown(const int message_id)
	{
		return engine_funcs_->get_times_tutor_message_shown(message_id);
	}

	/// <summary>
	/// <para>Processes the tutor message decay buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="buffer">
	///		Buffer.
	/// </param>
	/// <param name="buffer_length">
	///		Size of the buffer, in bytes.<br/>
	/// </param>
	static void process_tutor_message_decay_buffer(int* buffer, const int buffer_length)
	{
		engine_funcs_->process_tutor_message_decay_buffer(buffer, buffer_length);
	}

	/// <summary>
	/// <para>Constructs the tutor message decay buffer.<br/></para>
	/// </summary>
	/// 
	/// <param name="buffer">
	///		Buffer.
	/// </param>
	/// <param name="buffer_length">
	///		Size of the buffer, in bytes.<br/>
	/// </param>
	static void construct_tutor_message_decay_buffer(int* buffer, const int buffer_length)
	{
		engine_funcs_->construct_tutor_message_decay_buffer(buffer, buffer_length);
	}

	/// <summary>
	/// <para>Resets tutor message decay data.<br/></para>
	/// </summary>
	static void reset_tutor_message_decay_data()
	{
		engine_funcs_->reset_tutor_message_decay_data();
	}

	/// <summary>
	/// <para>Queries the given client for a cvar value.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Player to query.
	/// </param>
	/// <param name="cvar_name">
	///		CVar to query.<br/>
	/// </param>
	///
	/// <remarks>
	///		The response is sent to <c>GameDllNewHooks::cvar_value</c>.
	/// </remarks>
	static void query_client_cvar_value(const Edict* client, const char* cvar_name)
	{
		engine_funcs_->query_client_cvar_value(client, cvar_name);
	}

	/// <summary>
	/// <para>Queries the given client for a cvar value.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Player to query.
	/// </param>
	/// <param name="cvar_name">
	///		CVar to query.
	/// </param>
	/// <param name="request_id">
	///		Request ID to pass to <c>cvar_value2</c><br/>
	/// </param>
	///
	/// <remarks>
	///		The response is sent to <c>GameDllNewHooks::cvar_value2</c>.<br/>
	/// </remarks>
	static void query_client_cvar_value2(const Edict* client, const char* cvar_name, const int request_id)
	{
		engine_funcs_->query_client_cvar_value2(client, cvar_name, request_id);
	}

	/// <summary>
	/// <para>Checks if a command line parameter was provided.<br/></para>
	/// </summary>
	/// 
	/// <param name="cmd_line_token">
	///		Command key to look for.
	/// </param>
	/// <param name="next">
	///		If the key was found, this is set to the value.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Key index in the command line buffer, or 0 if it wasn't found.<br/>
	/// </returns>
	static int eng_check_param(const char* cmd_line_token, char** next)
	{
		return engine_funcs_->eng_check_param(cmd_line_token, next);
	}
};
