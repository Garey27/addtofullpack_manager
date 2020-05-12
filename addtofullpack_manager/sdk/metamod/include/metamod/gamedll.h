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

struct MetaGlobals;
struct MetaDllFuncsTables;
struct MetaHookExportFuncs;
enum class MetamodStatus;
enum class MetaPluginLoadTime;

/// <summary>
/// </summary>
extern "C" MetamodStatus DLLEXPORT Meta_Attach(MetaPluginLoadTime, MetaHookExportFuncs*, MetaGlobals*, MetaDllFuncsTables*);

/// <summary>
/// Class GameDll.
/// </summary>
class GameDll {
	friend MetamodStatus DLLEXPORT Meta_Attach(MetaPluginLoadTime, MetaHookExportFuncs*, MetaGlobals*, MetaDllFuncsTables*);

	/// <summary>
	/// <para>DLL functions table.</para>
	/// </summary>
	static const DllFuncPointers* dll_funcs_;

public:
	/// <summary>
	/// <para>Called when the game loads this DLL.<br/></para>
	/// </summary>
	static void game_init()
	{
		dll_funcs_->game_init();
	}

	/// <summary>
	/// <para>Called by the engine to spawn an entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity to spawn.<br/>
	/// </param>
	/// 
	/// <returns>
	///		0 if the entity was successfully spawned, or -1 if it should be removed.<br/>
	/// </returns>
	static int spawn(Edict* entity)
	{
		return dll_funcs_->spawn(entity);
	}

	/// <summary>
	/// <para>Called by the engine to run this entity's think function.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity.<br/>
	/// </param>
	static void think(Edict* entity)
	{
		dll_funcs_->think(entity);
	}

	/// <summary>
	/// <para>Called by the engine to trigger <c>entity_used</c>'s <c>use</c> function, using <c>entity_other</c> as the activator and caller.<br/></para>
	/// </summary>
	///
	/// <remarks>
	///		Obsolete. This is never called by the engine.<br/>
	/// </remarks>
	static void use(Edict* entity_used, Edict* entity_other)
	{
		dll_funcs_->use(entity_used, entity_other);
	}

	/// <summary>
	/// <para>Called by the engine to run <c>entity_touched</c>'s <c>touch</c> function with <c>entity_other</c> as the other entity.<br/></para>
	/// </summary>
	static void touch(Edict* entity_touched, Edict* entity_other)
	{
		dll_funcs_->touch(entity_touched, entity_other);
	}

	/// <summary>
	/// <para>Called by the engine to run <c>entity_blocked</c>'s <c>blocked</c> function with <c>entity_other</c> as the other entity.<br/></para>
	/// </summary>
	static void blocked(Edict* entity_blocked, Edict* entity_other)
	{
		dll_funcs_->blocked(entity_blocked, entity_other);
	}

	/// <summary>
	/// <para>Called by the engine to run <c>entity_key_value</c>'s <c>key_value</c> function with <c>data</c> as the key-value data.<br/></para>
	/// </summary>
	static void key_value(Edict* entity_key_value, KeyValueData* data)
	{
		dll_funcs_->key_value(entity_key_value, data);
	}

	/// <summary>
	/// <para>Called by the engine to save the given entity's state to the given save data block.<br/></para>
	/// </summary>
	static void save(Edict* entity, SaveRestoreData* save_data)
	{
		dll_funcs_->save(entity, save_data);
	}

	/// <summary>
	/// <para>Called by the engine to restore the given entity's state from the given save data block.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity.
	///	</param>
	/// <param name="save_data">
	///		Block to restore data from.
	/// </param>
	/// <param name="global_entity">
	///		Indicating whether this entity has a global name, or was transitioned from another map.<br/>
	/// </param>
	static int restore(Edict* entity, SaveRestoreData* save_data, const qboolean global_entity)
	{
		return dll_funcs_->restore(entity, save_data, global_entity);
	}

	/// <summary>
	/// <para>Called by the engine to set the given entity's absolute bounding box.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity.<br/>
	/// </param>
	static void set_abs_box(Edict* entity)
	{
		dll_funcs_->set_abs_box(entity);
	}

	/// <summary>
	/// <para>Called by the engine to save a named block of data to the given save data block.<br/></para>
	/// </summary>
	/// 
	/// <param name="save_data">
	///		Block to save data to.
	/// </param>
	/// <param name="name">
	///		Name of the data block.
	/// </param>
	/// <param name="base_data">
	///		Pointer to the object containing the data.
	/// </param>
	/// <param name="fields">
	///		List of type descriptions describing the object's data.
	/// </param>
	/// <param name="field_count">
	///		Number of type descriptions in <c>fields</c>.<br/>
	/// </param>
	static void save_write_fields(SaveRestoreData* save_data, const char* name, void* base_data, TypeDescription* fields, const int field_count)
	{
		dll_funcs_->save_write_fields(save_data, name, base_data, fields, field_count);
	}

	/// <summary>
	/// <para>Called by the engine to restore a named block of data from the given save data block.<br/></para>
	/// </summary>
	/// 
	/// <param name="save_data">
	///		Block to restore data from.
	/// </param>
	/// <param name="name">
	///		Name of the data block.
	/// </param>
	/// <param name="base_data">
	///		Pointer to the object containing the data.
	/// </param>
	/// <param name="fields">
	///		List of type descriptions describing the object's data.
	/// </param>
	/// <param name="field_count">
	///		Number of type descriptions in <c>fields</c>.<br/>
	/// </param>
	static void save_read_fields(SaveRestoreData* save_data, const char* name, void* base_data, TypeDescription* fields, const int field_count)
	{
		dll_funcs_->save_read_fields(save_data, name, base_data, fields, field_count);
	}

	/// <summary>
	/// <para>Called by the engine to save global state.<br/></para>
	/// </summary>
	static void save_global_state(SaveRestoreData* save_data)
	{
		dll_funcs_->save_global_state(save_data);
	}

	/// <summary>
	/// <para>Called by the engine to restore global state.<br/></para>
	/// </summary>
	static void restore_global_state(SaveRestoreData* save_data)
	{
		dll_funcs_->restore_global_state(save_data);
	}

	/// <summary>
	/// <para>Called by the engine to reset global state.<br/></para>
	/// </summary>
	static void reset_global_state()
	{
		dll_funcs_->reset_global_state();
	}

	/// <summary>
	/// <para>Called by the engine when a client connects.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.
	/// </param>
	/// <param name="name">
	///		Net name of the player.
	/// </param>
	/// <param name="address">
	///		IP address of the client.
	/// </param>
	/// <param name="reject_reason">
	///		Reason why the client was rejected.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if the client should be allowed to connect, false otherwise.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Returning false rejects the client's connection. Setting <c>reject_reason</c> presents that to the client.<br/>
	///		Network messages cannot be sent at this time.<br/>
	/// </remarks>
	static qboolean client_connect(Edict* client, const char* name, const char* address, char reject_reason[128])
	{
		return dll_funcs_->client_connect(client, name, address, reject_reason);
	}

	/// <summary>
	/// <para>Called when a client disconnects.<br/>
	/// This will not be called if the client connection was rejected in <c>client_connect</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.<br/>
	/// </param>
	static void client_disconnect(Edict* client)
	{
		dll_funcs_->client_disconnect(client);
	}

	/// <summary>
	/// <para>Called by the engine when the player has issued a "kill" command.<br/>
	/// Only if the player's health is larger than 0.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.<br/>
	/// </param>
	static void client_kill(Edict* client)
	{
		dll_funcs_->client_kill(client);
	}

	/// <summary>
	/// <para>Called by the engine when the client has finished connecting.<br/>
	/// This is where the player should be spawned and put into the world, or given a spectator position to view from.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.<br/>
	/// </param>
	static void client_put_in_server(Edict* client)
	{
		dll_funcs_->client_put_in_server(client);
	}

	/// <summary>
	/// <para>Called by the engine when it has received a command from the given client.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.<br/>
	/// </param>
	///
	/// <remarks>
	///		Command arguments can be retrieved using <c>Engine::cmd_args</c>, <c>Engine::cmd_argv</c>, <c>Engine::cmd_argc</c>.<br/>
	/// </remarks>
	static void client_command(Edict* client)
	{
		dll_funcs_->client_command(client);
	}

	/// <summary>
	/// <para>Called by the engine whenever the client's user info string changes.<br/>
	/// This includes the player's model.<br/></para>
	/// </summary>
	static void client_user_info_changed(Edict* client, char* info_buffer)
	{
		dll_funcs_->client_user_info_changed(client, info_buffer);
	}

	/// <summary>
	/// <para>Called when the engine has finished spawning the map.<br/></para>
	/// </summary>
	/// 
	/// <param name="edict_list">
	///		Pointer to the list of edicts.
	/// </param>
	/// <param name="edict_count">
	///		Number of valid edicts.
	/// </param>
	/// <param name="client_max">
	///		Maximum number of players that can connect to this server.<br/>
	/// </param>
	static void server_activate(Edict* edict_list, const int edict_count, const int client_max)
	{
		dll_funcs_->server_activate(edict_list, edict_count, client_max);
	}

	/// <summary>
	/// <para>Called when the map has ended. This happens before entities are destroyed.<br/></para>
	/// </summary>
	static void server_deactivate()
	{
		dll_funcs_->server_deactivate();
	}

	/// <summary>
	/// <para>Called by the engine before it runs physics.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.<br/>
	/// </param>
	static void player_pre_think(Edict* client)
	{
		dll_funcs_->player_pre_think(client);
	}

	/// <summary>
	/// <para>Called by the engine after it runs physics.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Entity that represents this client.<br/>
	/// </param>
	static void player_post_think(Edict* client)
	{
		dll_funcs_->player_post_think(client);
	}

	/// <summary>
	/// <para>Called at the start of a server game frame.<br/></para>
	/// </summary>
	static void start_frame()
	{
		dll_funcs_->start_frame();
	}

	/// <summary>
	/// <para>Obsolete.<br/></para>
	/// </summary>
	static void params_new_level()
	{
		dll_funcs_->params_new_level();
	}

	/// <summary>
	/// <para>Called by the engine when a level is saved.<br/>
	/// Also called when a player has spawned after a saved game has been loaded.<br/></para>
	/// </summary>
	static void params_change_level()
	{
		dll_funcs_->params_change_level();
	}

	/// <summary>
	/// <para>Returns string describing current .dll. E.g., TeamFortress 2, Half-Life.<br/></para>
	/// </summary>
	static const char* get_game_description()
	{
		return dll_funcs_->get_game_description();
	}

	/// <summary>
	/// <para>Notify dll about a player customization.<br/></para>
	/// </summary>
	static void player_customization(Edict* client, Customization* custom)
	{
		dll_funcs_->player_customization(client, custom);
	}

	/// <summary>
	/// <para>Called when a HLTV spectator has connected.<br/></para>
	/// </summary>
	static void spectator_connect(Edict* client)
	{
		dll_funcs_->spectator_connect(client);
	}

	/// <summary>
	/// <para>Called when a HLTV spectator has disconnected.<br/></para>
	/// </summary>
	static void spectator_disconnect(Edict* client)
	{
		dll_funcs_->spectator_disconnect(client);
	}

	/// <summary>
	/// <para>Called when a HLTV spectator's think function has to run.<br/></para>
	/// </summary>
	static void spectator_think(Edict* client)
	{
		dll_funcs_->spectator_think(client);
	}

	/// <summary>
	/// <para>Notify game .dll that engine is going to shut down.<br/>
	/// Allows mod authors to set a breakpoint.<br/></para>
	/// </summary>
	static void sys_error(const char* error_string)
	{
		dll_funcs_->sys_error(error_string);
	}

	/// <summary>
	/// <para>Called by the engine to run player physics.<br/></para>
	/// </summary>
	/// 
	/// <param name="move">
	///		Pointer to player movement data.
	/// </param>
	/// <param name="server">
	///		Whether this is the server or client physics code.<br/>
	/// </param>
	static void pm_move(PlayerMove* move, const qboolean server)
	{
		dll_funcs_->pm_move(move, server);
	}

	/// <summary>
	/// <para>Called by the engine to initialize the player physics data.<br/></para>
	/// </summary>
	static void pm_init(PlayerMove* move)
	{
		dll_funcs_->pm_init(move);
	}

	/// <summary>
	/// <para>Called by the engine to find the texture type of a given texture.<br/></para>
	/// </summary>
	/// 
	/// <param name="name">
	///		Name of the texture to look up.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Texture type. Should always return a valid value, even if no data is available for the given texture.<br/>
	/// </returns>
	///
	/// <remarks>
	///		Never actually called.<br/>
	/// </remarks>
	static char pm_find_texture_type(char* name)
	{
		return dll_funcs_->pm_find_texture_type(name);
	}

	/// <summary>
	/// <para>Set up visibility for the given client.<br/></para>
	/// </summary>
	/// 
	/// <param name="view_entity">
	///		The client's view entity. This is the entity whose origin and view offset should be used as the client's view position.
	/// </param>
	/// <param name="client">
	///		The client.
	/// </param>
	/// <param name="pvs">
	///		Pointer to Potentially Visible Set to use.
	/// </param>
	/// <param name="pas">
	///		Pointer to Potentially Audible Set to use.<br/>
	/// </param>
	static void setup_visibility(Edict* view_entity, Edict* client, unsigned char** pvs, unsigned char** pas)
	{
		dll_funcs_->setup_visibility(view_entity, client, pvs, pas);
	}

	/// <summary>
	/// <para>Updates the given client's data.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.
	/// </param>
	/// <param name="send_weapons">
	///		Indicating whether weapon data should be sent.
	/// </param>
	/// <param name="data">
	///		Client data to send. This is zeroed before the call to this function.<br/>
	/// </param>
	static void update_client_data(const Edict* client, const qboolean send_weapons, ClientData* data)
	{
		dll_funcs_->update_client_data(client, send_weapons, data);
	}

	/// <summary>
	/// <para>Called by the engine to determine whether the given entity should be added to the given client's list of visible entities.<br/></para>
	/// </summary>
	/// 
	/// <param name="state">
	///		Entity state data for the entity that is being added.
	/// </param>
	/// <param name="entity_index">
	///		Index of the entity being considered for addition.
	/// </param>
	/// <param name="entity">
	///		Entity being considered for addition.
	/// </param>
	/// <param name="host">
	///		Client currently being processed.
	/// </param>
	/// <param name="host_flags">
	///		Host flags.
	/// </param>
	/// <param name="player">
	///		True if the entity being added is a player, false otherwise.
	/// </param>
	/// <param name="set">
	///		The PVS provided by <c>setup_visibility</c>
	/// </param>
	static int add_to_full_pack(EntityState* state, const int entity_index, Edict* entity, Edict* host, const int host_flags, const qboolean player, unsigned char* set)
	{
		return dll_funcs_->add_to_full_pack(state, entity_index, entity, host, host_flags, player, set);
	}

	/// <summary>
	/// <para>Called by the engine to create a baseline for the given entity.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Indicating whether this is a player.
	/// </param>
	/// <param name="entity_index">
	///		Entity index of this entity.
	/// </param>
	/// <param name="baseline">
	///		Baseline to fill.
	/// </param>
	/// <param name="entity">
	///		Entity to make the baseline for.
	/// </param>
	/// <param name="player_model_index">
	///		Index of the model "models/player.mdl".
	/// </param>
	/// <param name="player_min_size">
	///		Array of the player minimum bounds for each hull.
	/// </param>
	/// <param name="player_max_size">
	///		Array of the player maximum bounds for each hull.<br/>
	/// </param>
	static void create_baseline(const qboolean client, const int entity_index, EntityState* baseline, Edict* entity, const int player_model_index,
	                            const Vector player_min_size, const Vector player_max_size)
	{
		dll_funcs_->create_baseline(client, entity_index, baseline, entity, player_model_index, player_min_size, player_max_size);
	}

	/// <summary>
	/// <para>Called by the engine to allow the server to register delta encoders.<br/></para>
	/// </summary>
	static void register_encoders()
	{
		dll_funcs_->register_encoders();
	}

	/// <summary>
	/// <para>Called by the engine to retrieve weapon data.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Player to retrieve weapon info from.
	/// </param>
	/// <param name="info">
	///		Array of <c>WeaponData</c> that should receive the player's weapon data. Is an array of MAX_WEAPONS entries.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if data was added, false otherwise.<br/>
	/// </returns>
	static qboolean get_weapon_data(Edict* client, WeaponData* info)
	{
		return dll_funcs_->get_weapon_data(client, info);
	}

	/// <summary>
	/// <para>Called by the engine when a user command has been received and is about to begin processing.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.
	/// </param>
	/// <param name="cmd">
	///		Command being executed.
	/// </param>
	/// <param name="random_seed">
	///		The player's current random seed.<br/>
	/// </param>
	static void cmd_start(const Edict* client, const UserCmd* cmd, const unsigned int random_seed)
	{
		dll_funcs_->cmd_start(client, cmd, random_seed);
	}

	/// <summary>
	/// <para>Called by the engine when a user command has finished processing.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.
	/// </param>
	static void cmd_end(const Edict* client)
	{
		dll_funcs_->cmd_end(client);
	}

	/// <summary>
	/// <para>Return 1 if the packet is valid. Set response_buffer_size if you want to send a response packet.<br/>
	/// Incoming, it holds the max size of the response_buffer, so you must zero it out if you choose not to respond.<br/></para>
	/// </summary>
	/// 
	/// <param name="net_from">
	///		IP address of the sender of this packet.
	/// </param>
	/// <param name="args">
	///		Arguments provided by the sender.
	/// </param>
	/// <param name="response_buffer">
	///		Buffer that a response can be written into.
	/// </param>
	/// <param name="response_buffer_size">
	///		Size of the buffer.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if the packet has been handled, false otherwise.<br/>
	/// </returns>
	///
	/// <remarks>
	///		This can be used to handle commands akin to rcon. The remote server console can send commands that end up here.<br/>
	///		Anyone can send messages that reach this point, not just rcon.<br/>
	/// </remarks>
	static qboolean connectionless_packet(const NetAddress* net_from, const char* args, char* response_buffer, int* response_buffer_size)
	{
		return dll_funcs_->connectionless_packet(net_from, args, response_buffer, response_buffer_size);
	}

	/// <summary>
	/// <para>Enumerates player hulls. Returns 0 if the hull number doesn't exist, 1 otherwise.<br/></para>
	/// </summary>
	/// 
	/// <param name="hull_number">
	///		Hull to retrieve the bounds for.
	/// </param>
	/// <param name="min_size">
	///		Minimum bounds.
	/// </param>
	/// <param name="max_size">
	///		Maximum bounds.<br/>
	/// </param>
	/// 
	/// <returns>
	///		True if the hull was successfully retrieved, false otherwise.<br/>
	/// </returns>
	static qboolean get_hull_bounds(const int hull_number, Vector& min_size, Vector& max_size)
	{
		return dll_funcs_->get_hull_bounds(hull_number, min_size, max_size);
	}

	/// <summary>
	/// <para>Create baselines for certain "unplaced" items.<br/></para>
	/// </summary>
	static void create_instanced_baselines()
	{
		dll_funcs_->create_instanced_baselines();
	}

	/// <summary>
	/// <para>One of the <c>force_unmodified</c> files failed the consistency check for the specified player.<br/>
	/// Return 0 to allow the client to continue, 1 to force immediate disconnection
	/// (with an optional disconnect message of up to 256 characters).<br/></para>
	/// </summary>
	static qboolean inconsistent_file(const Edict* client, const char* file_name, char* disconnect_message)
	{
		return dll_funcs_->inconsistent_file(client, file_name, disconnect_message);
	}

	/// <summary>
	/// <para>The game .dll should return 1 if lag compensation should be allowed (could also just set the sv_unlag cvar).<br/>
	/// Most games right now should return 0, until client-side weapon prediction code is written and tested for them.<br/></para>
	/// </summary>
	static qboolean allow_lag_compensation()
	{
		return dll_funcs_->allow_lag_compensation();
	}
};

/// <summary>
/// Class GameDllNew.
/// </summary>
class GameDllNew {
	friend MetamodStatus DLLEXPORT Meta_Attach(MetaPluginLoadTime, MetaHookExportFuncs*, MetaGlobals*, MetaDllFuncsTables*);

	/// <summary>
	/// <para>New DLL functions table.</para>
	/// </summary>
	static const DllNewFuncPointers* dll_new_funcs_;

public:
	/// <summary>
	/// <para>Called when an entity is freed by the engine, right before the object's memory is freed.<br/>
	/// Calls <c>OnDestroy</c> and runs the destructor.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity">
	///		Entity.
	/// </param>
	static void free_entity_private_data(Edict* entity)
	{
		dll_new_funcs_->free_entity_private_data(entity);
	}

	/// <summary>
	/// <para>Called when the game unloads this DLL.<br/></para>
	/// </summary>
	static void game_shutdown()
	{
		dll_new_funcs_->game_shutdown();
	}

	/// <summary>
	/// <para>Called when the engine believes two entities are about to collide.<br/></para>
	/// </summary>
	/// 
	/// <param name="entity_touched">
	///		Entity touched.
	/// </param>
	/// <param name="entity_other">
	///		Entity other.<br/>
	/// </param>
	/// 
	/// <returns>
	///		Return 0 if you want the two entities to just pass through each other without colliding or calling the touch function.<br/>
	/// </returns>
	static qboolean should_collide(Edict* entity_touched, Edict* entity_other)
	{
		return dll_new_funcs_->should_collide(entity_touched, entity_other);
	}

	/// <summary>
	/// <para>Called when the engine has received a cvar value from the client in response to an <c>Engine::query_client_cvar_value</c> call.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.
	/// </param>
	/// <param name="value">
	///		CVar value.<br/>
	/// </param>
	static void cvar_value(const Edict* client, const char* value)
	{
		dll_new_funcs_->cvar_value(client, value);
	}

	/// <summary>
	/// <para>Called when the engine has received a cvar value from the client in response to an <c>Engine::query_client_cvar_value2</c> call.<br/></para>
	/// </summary>
	/// 
	/// <param name="client">
	///		Client.
	/// </param>
	/// <param name="request_id">
	///		The ID given to the <c>query_client_cvar_value2</c> function.
	/// </param>
	/// <param name="cvar_name">
	///		Name of the cvar that was queried.
	/// </param>
	/// <param name="value">
	///		CVar value.<br/>
	/// </param>
	static void cvar_value2(const Edict* client, const int request_id, const char* cvar_name, const char* value)
	{
		dll_new_funcs_->cvar_value2(client, request_id, cvar_name, value);
	}
};
