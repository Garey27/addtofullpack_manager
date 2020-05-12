// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <amxx/api.h>
#include <cstdint>
#include <cstring>

/// <summary>
/// <para>AMXX API function pointers.</para>
/// </summary>
AmxxApiFuncPointers AmxxApi::amxx_api_funcs_;

/**
 * \brief Requests the AMXX API function.<br/>
 * \param M AmxxApiFuncPointers structure member.
 * \param N requested function name.
 */
#define REQUEST_FUNCTION(M, N) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	if ((*reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(&(M))) = request_function(N)) == nullptr) \
		return AmxxStatus::FuncNotPresent

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Query(int* interface_version, AmxxModuleInfo* module_info)
{
	// Check parameters.
	if (!interface_version || !module_info)
		return AmxxStatus::InvalidParameter;

	// Check interface version.
	if (*interface_version != AMXX_INTERFACE_VERSION) {
		// Tell amxx core our interface version.
		*interface_version = AMXX_INTERFACE_VERSION;
		return AmxxStatus::InterfaceMismatch;
	}

	AmxxModuleInfo info =
	{
		AMXX_MODULE_NAME,
		AMXX_MODULE_AUTHOR,
		AMXX_MODULE_VERSION,
		AMXX_MODULE_RELOAD_ON_MAP_CHANGE,
		AMXX_MODULE_LOG_TAG,
		AMXX_MODULE_LIBRARY,
		AMXX_MODULE_LIB_CLASS
	};

	// Copy module info.
	std::memcpy(module_info, &info, sizeof(AmxxModuleInfo));

#ifdef AMXX_QUERY
	AMXX_QUERY();
#endif

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" AmxxGameStatus DLLEXPORT AMXX_CheckGame([[maybe_unused]] const char* game)
{
#ifdef AMXX_CHECK_GAME
	return AMXX_CHECK_GAME(game);
#else
	return AmxxGameStatus::Ok;
#endif
}

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Attach(const std::add_pointer_t<void*(const char*)> request_function)
{
	if (!request_function)
		return AmxxStatus::InvalidParameter;

	const auto func = &AmxxApi::amxx_api_funcs_;

	REQUEST_FUNCTION(func->amx_allot, "amx_Allot");
	REQUEST_FUNCTION(func->amx_exec, "amx_Exec");
	REQUEST_FUNCTION(func->amx_exec_v, "amx_Execv");
	REQUEST_FUNCTION(func->amx_find_native, "amx_FindNative");
	REQUEST_FUNCTION(func->amx_find_public, "amx_FindPublic");
	REQUEST_FUNCTION(func->amx_push, "amx_Push");
	REQUEST_FUNCTION(func->add_libraries, "AddLibraries");
	REQUEST_FUNCTION(func->add_natives, "AddNatives");
	REQUEST_FUNCTION(func->add_new_natives, "AddNewNatives");
	REQUEST_FUNCTION(func->amx_re_register, "AmxReregister");
	REQUEST_FUNCTION(func->build_path_name, "BuildPathname");
	REQUEST_FUNCTION(func->build_path_name_r, "BuildPathnameR");
	//REQUEST_FUNCTION(func->cell_to_real, "CellToReal");
	REQUEST_FUNCTION(func->copy_amx_memory, "CopyAmxMemory");
	REQUEST_FUNCTION(func->execute_forward, "ExecuteForward");
	REQUEST_FUNCTION(func->find_amx_script_by_amx, "FindAmxScriptByAmx");
	REQUEST_FUNCTION(func->find_amx_script_by_name, "FindAmxScriptByName");
	REQUEST_FUNCTION(func->find_library, "FindLibrary");
	REQUEST_FUNCTION(func->format, "Format");
	REQUEST_FUNCTION(func->format_amx_string, "FormatAmxString");
	REQUEST_FUNCTION(func->get_amx_address, "GetAmxAddr");
	REQUEST_FUNCTION(func->get_amx_script, "GetAmxScript");
	REQUEST_FUNCTION(func->get_amx_script_name, "GetAmxScriptName");
	REQUEST_FUNCTION(func->get_amx_string, "GetAmxString");
	REQUEST_FUNCTION(func->get_amx_string_len, "GetAmxStringLen");
	REQUEST_FUNCTION(func->get_local_info, "GetLocalInfo");
	REQUEST_FUNCTION(func->get_mod_name, "GetModname");
	REQUEST_FUNCTION(func->get_player_armor, "GetPlayerArmor");
	REQUEST_FUNCTION(func->get_player_cur_weapon, "GetPlayerCurweapon");
	REQUEST_FUNCTION(func->get_player_deaths, "GetPlayerDeaths");
	REQUEST_FUNCTION(func->get_player_edict, "GetPlayerEdict");
	REQUEST_FUNCTION(func->get_player_flags, "GetPlayerFlags");
	REQUEST_FUNCTION(func->get_player_frags, "GetPlayerFrags");
	REQUEST_FUNCTION(func->get_player_health, "GetPlayerHealth");
	REQUEST_FUNCTION(func->get_player_ip, "GetPlayerIP");
	REQUEST_FUNCTION(func->get_player_keys, "GetPlayerKeys");
	REQUEST_FUNCTION(func->get_player_menu, "GetPlayerMenu");
	REQUEST_FUNCTION(func->get_player_name, "GetPlayerName");
	REQUEST_FUNCTION(func->get_player_play_time, "GetPlayerPlayTime");
	REQUEST_FUNCTION(func->get_player_team, "GetPlayerTeam");
	REQUEST_FUNCTION(func->get_player_team_id, "GetPlayerTeamID");
	REQUEST_FUNCTION(func->get_player_time, "GetPlayerTime");
	REQUEST_FUNCTION(func->is_player_alive, "IsPlayerAlive");
	REQUEST_FUNCTION(func->is_player_authorized, "IsPlayerAuthorized");
	REQUEST_FUNCTION(func->is_player_bot, "IsPlayerBot");
	REQUEST_FUNCTION(func->is_player_connecting, "IsPlayerConnecting");
	REQUEST_FUNCTION(func->is_player_hltv, "IsPlayerHLTV");
	REQUEST_FUNCTION(func->is_player_in_game, "IsPlayerInGame");
	REQUEST_FUNCTION(func->is_player_valid, "IsPlayerValid");
	REQUEST_FUNCTION(func->load_amx_script, "LoadAmxScript");
	REQUEST_FUNCTION(func->log, "Log");
	REQUEST_FUNCTION(func->log_error, "LogError");
	REQUEST_FUNCTION(func->merge_definition_file, "MergeDefinitionFile");
	REQUEST_FUNCTION(func->message_block, "MessageBlock");
	REQUEST_FUNCTION(func->override_natives, "OverrideNatives");
	REQUEST_FUNCTION(func->player_prop_address, "PlayerPropAddr");
	REQUEST_FUNCTION(func->prepare_cell_array, "PrepareCellArray");
	REQUEST_FUNCTION(func->prepare_cell_array_a, "PrepareCellArrayA");
	REQUEST_FUNCTION(func->prepare_char_array, "PrepareCharArray");
	REQUEST_FUNCTION(func->prepare_char_array_a, "PrepareCharArrayA");
	REQUEST_FUNCTION(func->print_srv_console, "PrintSrvConsole");
	REQUEST_FUNCTION(func->raise_amx_error, "RaiseAmxError");
	//REQUEST_FUNCTION(func->real_to_cell, "RealToCell");
	REQUEST_FUNCTION(func->reg_auth_func, "RegAuthFunc");
	REQUEST_FUNCTION(func->register_forward, "RegisterForward");
	REQUEST_FUNCTION(func->register_function, "RegisterFunction");
	REQUEST_FUNCTION(func->register_function_ex, "RegisterFunctionEx");
	REQUEST_FUNCTION(func->register_sp_forward, "RegisterSPForward");
	REQUEST_FUNCTION(func->register_sp_forward_by_name, "RegisterSPForwardByName");
	REQUEST_FUNCTION(func->remove_libraries, "RemoveLibraries");
	REQUEST_FUNCTION(func->set_amx_string, "SetAmxString");
	REQUEST_FUNCTION(func->set_player_team_info, "SetPlayerTeamInfo");
	REQUEST_FUNCTION(func->unload_amx_script, "UnloadAmxScript");
	REQUEST_FUNCTION(func->unregister_auth_func, "UnregAuthFunc");
	REQUEST_FUNCTION(func->unregister_sp_forward, "UnregisterSPForward");

#ifndef AMXX_182_COMPATIBILITY
	REQUEST_FUNCTION(func->get_amx_string_null, "GetAmxStringNull");
	REQUEST_FUNCTION(func->get_amx_vector_null, "GetAmxVectorNull");
	REQUEST_FUNCTION(func->get_config_manager, "GetConfigManager");
	REQUEST_FUNCTION(func->load_amx_script_ex, "LoadAmxScriptEx");
	REQUEST_FUNCTION(func->set_amx_string_utf8_cell, "SetAmxStringUTF8Cell");
	REQUEST_FUNCTION(func->set_amx_string_utf8_char, "SetAmxStringUTF8Char");
#endif

#ifdef AMXX_ATTACH
	return AMXX_ATTACH();
#else
	return AmxxStatus::Ok;
#endif
}

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Detach()
{
#ifdef AMXX_DETACH
	AMXX_DETACH();
#endif

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_PluginsLoaded()
{
#ifdef AMXX_PLUGINS_LOADED
	AMXX_PLUGINS_LOADED();
#endif

	return AmxxStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" void DLLEXPORT AMXX_PluginsUnloaded()
{
#ifdef AMXX_PLUGINS_UNLOADED
	AMXX_PLUGINS_UNLOADED();
#endif
}

/// <summary>
/// </summary>
extern "C" void DLLEXPORT AMXX_PluginsUnloading()
{
#ifdef AMXX_PLUGINS_UNLOADING
	AMXX_PLUGINS_UNLOADING();
#endif
}

/// <summary>
/// </summary>
const char* filename_from_path(const char* const path)
{
	if (!path)
		return path;
	
	std::size_t index = 0;

#ifdef _WIN32
	for (std::size_t i = 0; path[i]; ++i) {
		if (path[i] == '\\')
			index = i;
	}
#else
	for (std::size_t i = 0; path[i]; ++i) {
		if (path[i] == '/')
			index = i;
	}
#endif

	return index ? path + index + 1 : path;
}
