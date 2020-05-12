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
/// <para>Exports the DLL hooks.</para>
/// </summary>
int export_dll_hooks(DllFuncPointers* function_table, int* interface_version);

/// <summary>
/// <para>Exports the DLL post hooks.</para>
/// </summary>
int export_dll_post_hooks(DllFuncPointers* function_table, int* interface_version);

/// <summary>
/// <para>Exports the new DLL hooks.</para>
/// </summary>
int export_dll_new_hooks(DllNewFuncPointers* function_table, int* interface_version);

/// <summary>
/// <para>Exports the new DLL hooks.</para>
/// </summary>
int export_dll_new_post_hooks(DllNewFuncPointers* function_table, int* interface_version);

/// <summary>
/// Class GameDllHooks.
/// </summary>
class GameDllHooks {
	friend void DLLEXPORT Meta_Init();
	friend int export_dll_hooks(DllFuncPointers*, int*);
	friend int export_dll_post_hooks(DllFuncPointers*, int*);

	/// <summary>
	/// <para>DLL hooks table.</para>
	/// </summary>
	static DllFuncPointers* dll_hooks_;

	/// <summary>
	/// <para>DLL post hooks table.</para>
	/// </summary>
	static DllFuncPointers* dll_post_hooks_;

public:
	/// <summary>
	/// <para>Clears all hooks.</para>
	/// </summary>
	static void clear_all_hooks()
	{
		if (dll_hooks_ != nullptr)
			std::memset(static_cast<void*>(dll_hooks_), 0, sizeof(DllFuncPointers));

		if (dll_post_hooks_ != nullptr)
			std::memset(static_cast<void*>(dll_post_hooks_), 0, sizeof(DllFuncPointers));
	}

	/// <summary>
	/// <para>Called when the game loads this DLL.</para>
	/// </summary>
	static void game_init(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::game_init, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to spawn an entity.</para>
	/// </summary>
	static void spawn(const std::add_pointer_t<int(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::spawn, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to run this entity's think function.</para>
	/// </summary>
	static void think(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::think, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to trigger <c>entity_used</c>'s <c>use</c> function, using <c>entity_other</c> as the activator and caller.<br/>
	/// Obsolete. This is never called by the engine.</para>
	/// </summary>
	static void use(const std::add_pointer_t<void(Edict* entity_used, Edict* entity_other)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::use, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to run <c>entity_touched</c>'s <c>touch</c> function with <c>entity_other</c> as the other entity.</para>
	/// </summary>
	static void touch(const std::add_pointer_t<void(Edict* entity_touched, Edict* entity_other)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::touch, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to run <c>entity_blocked</c>'s <c>blocked</c> function with <c>entity_other</c> as the other entity.</para>
	/// </summary>
	static void blocked(const std::add_pointer_t<void(Edict* entity_blocked, Edict* entity_other)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::blocked, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to run <c>entity_key_value</c>'s <c>key_value</c> function with <c>data</c> as the key-value data.</para>
	/// </summary>
	static void key_value(const std::add_pointer_t<void(Edict* entity_key_value, KeyValueData* data)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::key_value, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to save the given entity's state to the given save data block.</para>
	/// </summary>
	static void save(const std::add_pointer_t<void(Edict* entity, SaveRestoreData* save_data)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::save, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to restore the given entity's state from the given save data block.</para>
	/// </summary>
	static void restore(const std::add_pointer_t<int(Edict* entity, SaveRestoreData* save_data, qboolean global_entity)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::restore, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to set the given entity's absolute bounding box.</para>
	/// </summary>
	static void set_abs_box(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::set_abs_box, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to save a named block of data to the given save data block.</para>
	/// </summary>
	static void save_write_fields(
		const std::add_pointer_t<void(SaveRestoreData* save_data, const char* name, void* base_data, TypeDescription* fields, int field_count)> callback,
		const bool post = false)
	{
		set_hook(&DllFuncPointers::save_write_fields, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to restore a named block of data from the given save data block.</para>
	/// </summary>
	static void save_read_fields(
		const std::add_pointer_t<void(SaveRestoreData* save_data, const char* name, void* base_data, TypeDescription* fields, int field_count)> callback,
		const bool post = false)
	{
		set_hook(&DllFuncPointers::save_read_fields, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to save global state.</para>
	/// </summary>
	static void save_global_state(const std::add_pointer_t<void(SaveRestoreData* save_data)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::save_global_state, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to restore global state.</para>
	/// </summary>
	static void restore_global_state(const std::add_pointer_t<void(SaveRestoreData* save_data)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::restore_global_state, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to reset global state.</para>
	/// </summary>
	static void reset_global_state(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::reset_global_state, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when a client connects.<br/>
	/// Returning false rejects the client's connection. Setting <c>reject_reason</c> presents that to the client.</para>
	/// </summary>
	static void client_connect(const std::add_pointer_t<qboolean(Edict* client, const char* name, const char* address, char reject_reason[128])> callback,
	                           const bool post = false)
	{
		set_hook(&DllFuncPointers::client_connect, callback, post);
	}

	/// <summary>
	/// <para>Called when a client disconnects.<br/>
	/// This will not be called if the client connection was rejected in <c>client_connect</c>.</para>
	/// </summary>
	static void client_disconnect(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::client_disconnect, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when the player has issued a "kill" command.<br/>
	/// Only if the player's health is larger than 0.</para>
	/// </summary>
	static void client_kill(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::client_kill, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when the client has finished connecting.<br/>
	/// This is where the player should be spawned and put into the world, or given a spectator position to view from.</para>
	/// </summary>
	static void client_put_in_server(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::client_put_in_server, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when it has received a command from the given client.</para>
	/// </summary>
	static void client_command(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::client_command, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine whenever the client's user info string changes.<br/>
	/// This includes the player's model.</para>
	/// </summary>
	static void client_user_info_changed(const std::add_pointer_t<void(Edict* client, char* info_buffer)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::client_user_info_changed, callback, post);
	}

	/// <summary>
	/// <para>Called when the engine has finished spawning the map.</para>
	/// </summary>
	static void server_activate(const std::add_pointer_t<void(Edict* edict_list, int edict_count, int client_max)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::server_activate, callback, post);
	}

	/// <summary>
	/// <para>Called when the map has ended.<br/>
	/// This happens before entities are destroyed.</para>
	/// </summary>
	static void server_deactivate(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::server_deactivate, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine before it runs physics.</para>
	/// </summary>
	static void player_pre_think(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::player_pre_think, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine after it runs physics.</para>
	/// </summary>
	static void player_post_think(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::player_post_think, callback, post);
	}

	/// <summary>
	/// <para>Called at the start of a server game frame.</para>
	/// </summary>
	static void start_frame(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::start_frame, callback, post);
	}

	/// <summary>
	/// <para>Obsolete.</para>
	/// </summary>
	static void params_new_level(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::params_new_level, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when a level is saved.<br/>
	/// Also called when a player has spawned after a saved game has been loaded.</para>
	/// </summary>
	static void params_change_level(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::params_change_level, callback, post);
	}

	/// <summary>
	/// <para>Returns string describing current .dll. E.g., TeamFortress 2, Half-Life.</para>
	/// </summary>
	static void get_game_description(const std::add_pointer_t<const char*()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::get_game_description, callback, post);
	}

	/// <summary>
	/// <para>Notify dll about a player customization.</para>
	/// </summary>
	static void player_customization(const std::add_pointer_t<void(Edict* client, Customization* custom)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::player_customization, callback, post);
	}

	/// <summary>
	/// <para>Called when a HLTV spectator has connected.</para>
	/// </summary>
	static void spectator_connect(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::spectator_connect, callback, post);
	}

	/// <summary>
	/// <para>Called when a HLTV spectator has disconnected.</para>
	/// </summary>
	static void spectator_disconnect(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::spectator_disconnect, callback, post);
	}

	/// <summary>
	/// <para>Called when a HLTV spectator's think function has to run.</para>
	/// </summary>
	static void spectator_think(const std::add_pointer_t<void(Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::spectator_think, callback, post);
	}

	/// <summary>
	/// <para>Notify game .dll that engine is going to shut down. Allows mod authors to set a breakpoint.</para>
	/// </summary>
	static void sys_error(const std::add_pointer_t<void(const char* error_string)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::sys_error, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to run player physics.</para>
	/// </summary>
	static void pm_move(const std::add_pointer_t<void(PlayerMove* move, qboolean server)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::pm_move, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to initialize the player physics data.</para>
	/// </summary>
	static void pm_init(const std::add_pointer_t<void(PlayerMove* move)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::pm_init, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to find the texture type of a given texture.</para>
	/// </summary>
	static void pm_find_texture_type(const std::add_pointer_t<char(char* name)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::pm_find_texture_type, callback, post);
	}

	/// <summary>
	/// <para>Set up visibility for the given client.</para>
	/// </summary>
	static void setup_visibility(const std::add_pointer_t<void(Edict* view_entity, Edict* client, unsigned char** pvs, unsigned char** pas)> callback,
	                             const bool post = false)
	{
		set_hook(&DllFuncPointers::setup_visibility, callback, post);
	}

	/// <summary>
	/// <para>Updates the given client's data.<br/>
	/// This function can be used to implement first person observer views.</para>
	/// </summary>
	static void update_client_data(const std::add_pointer_t<void(const Edict* client, qboolean send_weapons, ClientData* data)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::update_client_data, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to determine whether the given entity should be added to the given client's list of visible entities.</para>
	/// </summary>
	static void add_to_full_pack(
		const std::add_pointer_t<int(EntityState* state, int entity_index, Edict* entity, Edict* host, int host_flags, qboolean player, unsigned char* set)> callback,
		const bool post = false)
	{
		set_hook(&DllFuncPointers::add_to_full_pack, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to create a baseline for the given entity.</para>
	/// </summary>
	static void create_baseline(const std::add_pointer_t<void(qboolean client, int entity_index, EntityState* baseline, Edict* entity, int player_model_index,
	                                                          Vector player_min_size, Vector player_max_size)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::create_baseline, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to allow the server to register delta encoders.</para>
	/// </summary>
	static void register_encoders(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::register_encoders, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine to retrieve weapon data.</para>
	/// </summary>
	static void get_weapon_data(const std::add_pointer_t<qboolean(Edict* client, WeaponData* info)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::get_weapon_data, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when a user command has been received and is about to begin processing.</para>
	/// </summary>
	static void cmd_start(const std::add_pointer_t<void(const Edict* client, const UserCmd* cmd, unsigned int random_seed)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::cmd_start, callback, post);
	}

	/// <summary>
	/// <para>Called by the engine when a user command has finished processing.</para>
	/// </summary>
	static void cmd_end(const std::add_pointer_t<void(const Edict* client)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::cmd_end, callback, post);
	}

	/// <summary>
	/// <para>Return 1 if the packet is valid. Set response_buffer_size if you want to send a response packet.<br/>
	/// Incoming, it holds the max size of the <c>response_buffer</c>, so you must zero it out if you choose not to respond.</para>
	/// </summary>
	static void connectionless_packet(
		const std::add_pointer_t<qboolean(const NetAddress* net_from, const char* args, char* response_buffer, int* response_buffer_size)> callback,
		const bool post = false)
	{
		set_hook(&DllFuncPointers::connectionless_packet, callback, post);
	}

	/// <summary>
	/// <para>Enumerates player hulls. Returns 0 if the hull number doesn't exist, 1 otherwise.</para>
	/// </summary>
	static void get_hull_bounds(const std::add_pointer_t<qboolean(int hull_number, Vector& min_size, Vector& max_size)> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::get_hull_bounds, callback, post);
	}

	/// <summary>
	/// <para>Create baselines for certain "unplaced" items.</para>
	/// </summary>
	static void create_instanced_baselines(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::create_instanced_baselines, callback, post);
	}

	/// <summary>
	/// <para>One of the <c>force_unmodified</c> files failed the consistency check for the specified player.<br/>
	/// Return 0 to allow the client to continue, 1 to force immediate disconnection (with an optional disconnect message of up to 256 characters).</para>
	/// </summary>
	static void inconsistent_file(const std::add_pointer_t<qboolean(const Edict* client, const char* file_name, char* disconnect_message)> callback,
	                              const bool post = false)
	{
		set_hook(&DllFuncPointers::inconsistent_file, callback, post);
	}

	/// <summary>
	/// <para>The game .dll should return 1 if lag compensation should be allowed (could also just set the sv_unlag cvar).<br/>
	/// Most games right now should return 0, until client-side weapon prediction code is written and tested for them.</para>
	/// </summary>
	static void allow_lag_compensation(const std::add_pointer_t<qboolean()> callback, const bool post = false)
	{
		set_hook(&DllFuncPointers::allow_lag_compensation, callback, post);
	}

private:
	/// <summary>
	/// </summary>
	template <typename TMember, typename TCallback>
	static void set_hook(TMember DllFuncPointers::* member, const TCallback callback, const bool post)
	{
		if (post) {
			dll_post_hooks_->*member = callback;
		}
		else {
			dll_hooks_->*member = callback;
		}
	}
};

/// <summary>
/// Class GameDllNewHooks.
/// </summary>
class GameDllNewHooks {
	friend void DLLEXPORT Meta_Init();
	friend int export_dll_new_hooks(DllNewFuncPointers*, int*);
	friend int export_dll_new_post_hooks(DllNewFuncPointers*, int*);

	/// <summary>
	/// <para>New DLL hooks table.</para>
	/// </summary>
	static DllNewFuncPointers* dll_new_hooks_;

	/// <summary>
	/// <para>New DLL post hooks table.</para>
	/// </summary>
	static DllNewFuncPointers* dll_new_post_hooks_;

public:
	/// <summary>
	/// <para>Clears all hooks.</para>
	/// </summary>
	static void clear_all_hooks()
	{
		if (dll_new_hooks_ != nullptr)
			std::memset(static_cast<void*>(dll_new_hooks_), 0, sizeof(DllNewFuncPointers));

		if (dll_new_post_hooks_ != nullptr)
			std::memset(static_cast<void*>(dll_new_post_hooks_), 0, sizeof(DllNewFuncPointers));
	}

	/// <summary>
	/// <para>Called when an entity is freed by the engine, right before the object's memory is freed.<br/>
	/// Calls <c>OnDestroy</c> and runs the destructor.</para>
	/// </summary>
	static void free_entity_private_data(const std::add_pointer_t<void(Edict* entity)> callback, const bool post = false)
	{
		set_hook(&DllNewFuncPointers::free_entity_private_data, callback, post);
	}

	/// <summary>
	/// <para>Called when the game unloads this DLL.</para>
	/// </summary>
	static void game_shutdown(const std::add_pointer_t<void()> callback, const bool post = false)
	{
		set_hook(&DllNewFuncPointers::game_shutdown, callback, post);
	}

	/// <summary>
	/// <para>Called when the engine believes two entities are about to collide.<br/>
	/// Return 0 if you want the two entities to just pass through each other without colliding or calling the touch function.</para>
	/// </summary>
	static void should_collide(const std::add_pointer_t<qboolean(Edict* entity_touched, Edict* entity_other)> callback, const bool post = false)
	{
		set_hook(&DllNewFuncPointers::should_collide, callback, post);
	}

	/// <summary>
	/// <para>Called when the engine has received a cvar value from the client in response to an <c>engine_func_pointers::query_client_cvar_value</c> call.</para>
	/// </summary>
	static void cvar_value(const std::add_pointer_t<void(const Edict* client, const char* value)> callback, const bool post = false)
	{
		set_hook(&DllNewFuncPointers::cvar_value, callback, post);
	}

	/// <summary>
	/// <para>Called when the engine has received a cvar value from the client in response to a <c>engine_func_pointers::query_client_cvar_value2</c> call.</para>
	/// </summary>
	static void cvar_value2(const std::add_pointer_t<void(const Edict* client, int request_id, const char* cvar_name, const char* value)> callback,
	                        const bool post = false)
	{
		set_hook(&DllNewFuncPointers::cvar_value2, callback, post);
	}

private:
	/// <summary>
	/// </summary>
	template <typename TMember, typename TCallback>
	static void set_hook(TMember DllNewFuncPointers::* member, const TCallback callback, const bool post)
	{
		if (post) {
			dll_new_post_hooks_->*member = callback;
		}
		else {
			dll_new_hooks_->*member = callback;
		}
	}
};
