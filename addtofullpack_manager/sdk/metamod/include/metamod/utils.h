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
#include <metamod/plugin_info.h>
#include <cstdarg>
#include <utility>

/// <summary>
/// Enum MetamodStatus
/// </summary>
enum class MetamodStatus;

/// <summary>
/// Enum MetaGameInfo
/// </summary>
enum class MetaGameInfo {
	/// <summary>
	/// <para>Game name.</para>
	/// </summary>
	Name = 0,

	/// <summary>
	/// <para>Game description.</para>
	/// </summary>
	Description,

	/// <summary>
	/// <para>Game directory.</para>
	/// </summary>
	Directory,

	/// <summary>
	/// <para>Game DLL full path.</para>
	/// </summary>
	DllFullPath,

	/// <summary>
	/// <para>Game DLL file name.</para>
	/// </summary>
	DllFileName,

	/// <summary>
	/// <para>Game real DLL full path.</para>
	/// </summary>
	RealDllFullPath
};

/// <summary>
/// <para>Meta utility function table type.</para>
/// </summary>
struct MetaUtilFuncPointers {
	void (*log_console)(MetaPluginInfo* plugin, const char* format, ...){};
	void (*log_message)(MetaPluginInfo* plugin, const char* format, ...){};
	void (*log_error)(MetaPluginInfo* plugin, const char* format, ...){};
	void (*log_developer)(MetaPluginInfo* plugin, const char* format, ...){};
	void (*center_say)(MetaPluginInfo* plugin, const char* format, ...){};
	void (*center_say_params)(MetaPluginInfo* plugin, HudTextParams hud_params, const char* format, ...){};
	void (*center_say_varargs)(MetaPluginInfo* plugin, HudTextParams hud_params, const char* format, std::va_list args){};
	qboolean (*call_game_entity)(MetaPluginInfo* plugin, const char* game_entity, EntityVars* entity_vars){};
	int (*get_user_msg_id)(MetaPluginInfo* plugin, const char* msg_name, int* size){};
	const char* (*get_user_msg_name)(MetaPluginInfo* plugin, int msg_id, int* size){};
	const char* (*get_plugin_path)(MetaPluginInfo* plugin){};
	const char* (*get_game_info)(MetaPluginInfo* plugin, MetaGameInfo tag){};
	int (*load_plugin)(MetaPluginInfo* plugin, const char* cmdline, MetaPluginLoadTime now, void** plugin_handle){};
	int (*unload_plugin)(MetaPluginInfo* plugin, const char* cmdline, MetaPluginLoadTime now, MetaPluginUnloadReason reason){};
	int (*unload_plugin_by_handle)(MetaPluginInfo* plugin, void* plugin_handle, MetaPluginLoadTime now, MetaPluginUnloadReason reason){};
	const char* (*is_querying_client_cvar)(MetaPluginInfo* plugin, const Edict* edict){};
	int (*make_request_id)(MetaPluginInfo* plugin){};
	void (*get_hook_tables)(MetaPluginInfo* plugin, EngineFuncPointers** engine_funcs, DllFuncPointers** dll_funcs, DllNewFuncPointers** new_dll_funcs){};
};

/// <summary>
/// <para>Get info about plugin, compare meta_interface versions, provide meta utility callback functions.</para>
/// </summary>
extern "C" MetamodStatus DLLEXPORT Meta_Query(const char*, MetaPluginInfo**, MetaUtilFuncPointers*);

/// <summary>
/// <para>Metamod utility functions.</para>
/// </summary>
class MetaUtils {
	friend MetamodStatus DLLEXPORT Meta_Query(const char*, MetaPluginInfo**, MetaUtilFuncPointers*);

	/// <summary>
	/// <para>Plugin ID.</para>
	/// </summary>
	static MetaPluginInfo* plugin_info_;

	/// <summary>
	/// <para>Metamod utility functions.</para>
	/// </summary>
	static const MetaUtilFuncPointers* util_funcs_;

public:
	/// <summary>
	/// </summary>
	static MetaPluginInfo* get_plugin_id()
	{
		return plugin_info_;
	}

	/// <summary>
	/// <para>Log to console; newline added.</para>
	/// </summary>
	template <typename ...Args>
	static void log_console(const char* format, Args&&... args)
	{
		util_funcs_->log_console(plugin_info_, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Log regular message to logs; newline added.</para>
	/// </summary>
	template <typename ...Args>
	static void log_message(const char* format, Args&&... args)
	{
		util_funcs_->log_message(plugin_info_, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Log an error message to logs; newline added.</para>
	/// </summary>
	template <typename ...Args>
	static void log_error(const char* format, Args&&... args)
	{
		util_funcs_->log_error(plugin_info_, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Log a message only if cvar "developer" set; newline added.</para>
	/// </summary>
	template <typename ...Args>
	static void log_developer(const char* format, Args&&... args)
	{
		util_funcs_->log_developer(plugin_info_, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Print message on center of all player's screens.<br/>
	/// Uses default text parameters (color green, 10 second fade-in).</para>
	/// </summary>
	template <typename ...Args>
	static void center_say(const char* format, Args&&... args)
	{
		util_funcs_->center_say(plugin_info_, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Print a center-message, with given text parameters.</para>
	/// </summary>
	template <typename ...Args>
	static void center_say_params(const HudTextParams params, const char* format, Args&&... args)
	{
		util_funcs_->center_say_params(plugin_info_, params, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// <para>Print a center-message, with text parameters and varargs.</para>
	/// </summary>
	static void center_say_varargs(const HudTextParams params, const char* format, std::va_list&& arg_list)
	{
		util_funcs_->center_say_varargs(plugin_info_, params, format, std::forward<va_list>(arg_list));
	}

	/// <summary>
	/// <para>Allow plugins to call the entity functions in the GameDLL.<br/>
	/// In particular, calling "player()" as needed by most Bots.</para>
	/// </summary>
	static qboolean call_game_entity(const char* ent_str, EntityVars* pev)
	{
		return util_funcs_->call_game_entity(plugin_info_, ent_str, pev);
	}

	/// <summary>
	/// <para>Find a user message, registered by the gamedll, with the corresponding message name,
	/// and return remaining info about it (message id, size).</para>
	/// </summary>
	static int get_user_msg_id(const char* message_name, int* size)
	{
		return util_funcs_->get_user_msg_id(plugin_info_, message_name, size);
	}

	/// <summary>
	/// <para>Find a user message, registered by the gamedll, with the corresponding message id,
	/// and return remaining info about it (message name, size).</para>
	/// </summary>
	static const char* get_user_msg_name(const int message_id, int* size)
	{
		return util_funcs_->get_user_msg_name(plugin_info_, message_id, size);
	}

	/// <summary>
	/// <para>Return the full path of the plugin's loaded dll/so file.</para>
	/// </summary>
	static const char* get_plugin_path(MetaPluginInfo* plugin_id)
	{
		return util_funcs_->get_plugin_path(plugin_id);
	}

	/// <summary>
	/// <para>Return various string-based info about the game/MOD/gamedll.</para>
	/// </summary>
	static const char* get_game_info(const MetaGameInfo tag)
	{
		return util_funcs_->get_game_info(plugin_info_, tag);
	}

	/// <summary>
	/// </summary>
	static int load_plugin(MetaPluginInfo* plugin_id, const char* cmd_line, const MetaPluginLoadTime load_time, void** plugin_handle)
	{
		return util_funcs_->load_plugin(plugin_id, cmd_line, load_time, plugin_handle);
	}

	/// <summary>
	/// </summary>
	static int unload_plugin(MetaPluginInfo* plugin_id, const char* cmd_line, const MetaPluginLoadTime load_time, const MetaPluginUnloadReason reason)
	{
		return util_funcs_->unload_plugin(plugin_id, cmd_line, load_time, reason);
	}

	/// <summary>
	/// </summary>
	static int unload_plugin_by_handle(MetaPluginInfo* plugin_id, void* plugin_handle, const MetaPluginLoadTime load_time, const MetaPluginUnloadReason reason)
	{
		return util_funcs_->unload_plugin_by_handle(plugin_id, plugin_handle, load_time, reason);
	}

	/// <summary>
	/// </summary>
	static const char* is_querying_client_cvar(const Edict* edict)
	{
		return util_funcs_->is_querying_client_cvar(plugin_info_, edict);
	}

	/// <summary>
	/// </summary>
	static int make_request_id()
	{
		return util_funcs_->make_request_id(plugin_info_);
	}

	/// <summary>
	/// </summary>
	static void get_hook_tables(MetaPluginInfo* plugin_id, EngineFuncPointers** engine_funcs, DllFuncPointers** dll_funcs, DllNewFuncPointers** new_dll_funcs)
	{
		util_funcs_->get_hook_tables(plugin_id, engine_funcs, dll_funcs, new_dll_funcs);
	}
};
