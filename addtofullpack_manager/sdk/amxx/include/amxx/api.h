// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>
#include <amxx/amxx_config.h>
#include <cstddef>
#include <type_traits>
#include <utility>

#ifndef AMXX_182_COMPATIBILITY
#include <amxx/game_configs.h>
#endif

#if defined USE_METAMOD
#include <cssdk/engine/edict.h>
#include <metamod/os_dep.h>
#else
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif !defined(WINAPI)
#define WINAPI
#endif
#if defined _WIN32
#define DLLEXPORT __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define DLLEXPORT __attribute__ ((visibility ("default"), externally_visible))
#endif
#ifdef _WIN32
#define NOINLINE __declspec(noinline)  // NOLINT(cppcoreguidelines-macro-usage)
#define FASTCALL __fastcall  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define NOINLINE __attribute__ ((noinline))
#define FASTCALL
#endif
#endif

/// <summary>
/// <para>AMXX interface version.<br/><br/>
/// 2 - Added log_tag to struct (amxx1.1-rc1).<br/>
/// 3 - Added new Amx structure (amxx1.5).<br/>
/// 4 - Added new 'library' setting for direct loading.</para>
/// </summary>
constexpr auto AMXX_INTERFACE_VERSION = 4;

/// <summary>
/// </summary>
constexpr auto MSG_BLOCK_SET = 0;

/// <summary>
/// </summary>
constexpr auto MSG_BLOCK_GET = 1;

/// <summary>
/// </summary>
constexpr auto BLOCK_NOT = 0;

/// <summary>
/// </summary>
constexpr auto BLOCK_ONCE = 1;

/// <summary>
/// </summary>
constexpr auto BLOCK_SET = 2;

/// <summary>
/// Enum AmxxStatus
/// </summary>
enum class AmxxStatus : int {
	/// <summary>
	/// <para>No error.</para>
	/// </summary>
	Ok = 0,

	/// <summary>
	/// <para>Interface version.</para>
	/// </summary>
	InterfaceMismatch,

	/// <summary>
	/// <para>Invalid parameter.</para>
	/// </summary>
	InvalidParameter,

	/// <summary>
	/// </summary>
	FuncNotPresent
};

/// <summary>
/// Enum AmxxGameStatus
/// </summary>
enum class AmxxGameStatus : int {
	/// <summary>
	/// <para>This module can load on the current game mod.</para>
	/// </summary>
	Ok = 0,

	/// <summary>
	/// <para>This module can not load on the current game mod.</para>
	/// </summary>
	Bad
};

/// <summary>
/// Enum ForwardExecType
/// </summary>
enum class ForwardExecType {
	/// <summary>
	/// <para>Ignore return value.</para>
	/// </summary>
	Ignore = 0,

	/// <summary>
	/// <para>Stop on PLUGIN_HANDLED.</para>
	/// </summary>
	Stop,

	/// <summary>
	/// <para>Stop on PLUGIN_HANDLED, continue on other values, return biggest return value.</para>
	/// </summary>
	Stop2,

	/// <summary>
	/// <para>Continue; return biggest return value.</para>
	/// </summary>
	Continue
};

/// <summary>
/// Enum ForwardParam
/// </summary>
enum class ForwardParam {
	/// <summary>
	/// <para>Specify this as the last argument only tells the function that there are no more arguments.</para>
	/// </summary>
	Done = -1,

	/// <summary>
	/// <para>Normal cell.</para>
	/// </summary>
	Cell,

	/// <summary>
	/// <para>Float; used as normal cell though.</para>
	/// </summary>
	Float,

	/// <summary>
	/// <para>String.</para>
	/// </summary>
	String,

	/// <summary>
	/// <para>String; will be updated to the last function's value.</para>
	/// </summary>
	StringEx,

	/// <summary>
	/// <para>Array; use the return value of prepareArray.</para>
	/// </summary>
	Array,

	/// <summary>
	/// <para>Cell; pass by reference.</para>
	/// </summary>
	CellByRef,

	/// <summary>
	/// <para>Float; pass by reference.</para>
	/// </summary>
	FloatByRef,
};

/// <summary>
/// Enum PlayerProp
/// </summary>
enum class PlayerProp {
	/// <summary>
	/// <para>string.</para>
	/// </summary>
	Name = 0,

	/// <summary>
	/// <para>string.</para>
	/// </summary>
	Ip,

	/// <summary>
	/// <para>string.</para>
	/// </summary>
	Team,

	/// <summary>
	/// <para>bool.</para>
	/// </summary>
	InGame,

	/// <summary>
	/// <para>bool.</para>
	/// </summary>
	Authorized,

	/// <summary>
	/// <para>bool.</para>
	/// </summary>
	Vgui,

	/// <summary>
	/// <para>float.</para>
	/// </summary>
	Time,

	/// <summary>
	/// <para>float.</para>
	/// </summary>
	PlayTime,

	/// <summary>
	/// <para>float.</para>
	/// </summary>
	MenuExpire,

	/// <summary>
	/// <para>struct{int,int}[32].</para>
	/// </summary>
	Weapons,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	CurrentWeapon,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	TeamId,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	Deaths,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	Aiming,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	Menu,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	Keys,

	/// <summary>
	/// <para>int[32].</para>
	/// </summary>
	Flags,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	NewMenu,

	/// <summary>
	/// <para>int.</para>
	/// </summary>
	NewMenuPage
};

/// <summary>
/// Enum LibType
/// </summary>
enum class LibType {
	/// <summary>
	/// </summary>
	Library = 0,

	/// <summary>
	/// </summary>
	Class
};

/// <summary>
/// Struct AmxxModuleInfo.
/// </summary>
struct AmxxModuleInfo {
	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	const char* author{};

	/// <summary>
	/// </summary>
	const char* version{};

	/// <summary>
	/// <para>Reload on map change when nonzero.</para>
	/// </summary>
	int reload{};

	/// <summary>
	/// </summary>
	const char* log_tag{};

	/// <summary>
	/// </summary>
	const char* library{};

	/// <summary>
	/// </summary>
	const char* lib_class{};
};

/// <summary>
/// Struct AmxxApiFuncPointers
/// </summary>
struct AmxxApiFuncPointers {
	int (*add_natives)(const AmxNativeInfo* list){};
	int (*add_new_natives)(const AmxNativeInfo* list){};
	char* (*build_path_name)(const char* format, ...){};
	char* (*build_path_name_r)(char* buffer, std::size_t max_len, const char* format, ...){};
	cell* (*get_amx_address)(Amx* amx, cell offset){};
	void (*print_srv_console)(const char* format, ...){};
	const char* (*get_mod_name)(){};
	const char* (*get_amx_script_name)(int id){};
	Amx* (*get_amx_script)(int id){};
	int (*find_amx_script_by_amx)(const Amx* amx){};
	int (*find_amx_script_by_name)(const char* name){};
	int (*set_amx_string)(Amx* amx, cell amx_address, const char* source, int max){};
	char* (*get_amx_string)(Amx* amx, cell amx_address, int buffer_id, int* len){};
	int (*get_amx_string_len)(const cell* ptr){};
	char* (*format_amx_string)(Amx* amx, cell* params, int start_param, int* len){};
	void (*copy_amx_memory)(cell* dest, const cell* src, int len){};
	void (*log)(const char* format, ...){};
	void (*log_error)(Amx* amx, AmxError error, const char* format, ...){};
	int (*raise_amx_error)(Amx* amx, AmxError error){};
	int (*register_forward)(const char* func_name, ForwardExecType exec_type, ...){};
	int (*execute_forward)(int id, ...){};
	cell (*prepare_cell_array)(cell* ptr, unsigned int size){};
	cell (*prepare_char_array)(char* ptr, unsigned int size){};
	cell (*prepare_cell_array_a)(cell* ptr, unsigned int size, bool copy_back){};
	cell (*prepare_char_array_a)(char* ptr, unsigned int size, bool copy_back){};
	int (*is_player_valid)(int id){};
	const char* (*get_player_name)(int id){};
	const char* (*get_player_ip)(int id){};
	int (*is_player_in_game)(int id){};
	int (*is_player_bot)(int id){};
	int (*is_player_authorized)(int id){};
	float (*get_player_time)(int id){};
	float (*get_player_play_time)(int id){};
	int (*get_player_flags)(int id){};
	int (*get_player_cur_weapon)(int id){};
	const char* (*get_player_team)(int id){};
	int (*get_player_team_id)(int id){};
	int (*get_player_deaths)(int id){};
	int (*get_player_menu)(int id){};
	int (*get_player_keys)(int id){};
	int (*is_player_alive)(int id){};
	int (*get_player_frags)(int id){};
	int (*is_player_connecting)(int id){};
	int (*is_player_hltv)(int id){};
	int (*get_player_armor)(int id){};
	int (*get_player_health)(int id){};
#ifdef USE_METAMOD
	Edict* (*get_player_edict)(int id){};
#else
	void* (*get_player_edict)(int id){};
#endif
	void* (*player_prop_address)(int id, int prop){};
	int (*amx_exec)(Amx* amx, cell* return_val, int index){};
	int (*amx_exec_v)(Amx* amx, cell* return_val, int index, int num_params, cell params[]){};
	int (*amx_allot)(Amx* amx, int length, cell* amx_address, cell** phys_address){};
	int (*amx_find_public)(Amx* amx, const char* func_name, int* index){};
	int (*amx_find_native)(Amx* amx, const char* func_name, int* index){};
	int (*load_amx_script)(Amx* amx, void** code, const char* path, char error_info[64], int debug){};
	int (*unload_amx_script)(Amx* amx, void** code){};
	//cell (*real_to_cell)(real value){};
	//real (*cell_to_real)(cell value){};
	int (*register_sp_forward)(Amx* amx, int func, ...){};
	int (*register_sp_forward_by_name)(Amx* amx, const char* func_name, ...){};
	void (*unregister_sp_forward)(int id){};
	void (*merge_definition_file)(const char* file_name){};
	const char* (*format)(const char* format, ...){};
	void (*register_function)(void* pfn, const char* desc){};
	int (*amx_push)(Amx* amx, cell value){};
	int (*set_player_team_info)(int player, int team_id, const char* name){};
	void (*reg_auth_func)(std::add_pointer_t<void(int player, const char* auth_string)> authorize_func){};
	void (*unregister_auth_func)(std::add_pointer_t<void(int player, const char* auth_string)> authorize_func){};
	int (*find_library)(const char* name, LibType type){};
	std::size_t (*add_libraries)(const char* name, LibType type, void* parent){};
	std::size_t (*remove_libraries)(void* parent){};
	void (*override_natives)(AmxNativeInfo* natives, const char* my_name){};
	const char* (*get_local_info)(const char* name, const char* def){};
	int (*amx_re_register)(Amx* amx, AmxNativeInfo* list, int number){};
	void* (*register_function_ex)(void* pfn, const char* desc){};
	void (*message_block)(int mode, int message, int* opt){};

#ifndef AMXX_182_COMPATIBILITY
	char* (*get_amx_string_null)(Amx* amx, cell amx_address, int buffer_id, int* len){};
	cell* (*get_amx_vector_null)(Amx* amx, cell offset){};
	GameConfigManager* (*get_config_manager)(){};
	int (*load_amx_script_ex)(Amx* amx, void** code, const char* path, char* error_info, std::size_t max_length, int debug){};
	int (*set_amx_string_utf8_cell)(Amx* amx, cell amx_address, const cell* source, std::size_t source_len, std::size_t max_len){};
	int (*set_amx_string_utf8_char)(Amx* amx, cell amx_address, const char* source, std::size_t source_len, std::size_t max_len){};
#endif
};

/// <summary>
/// </summary>
const char* filename_from_path(const char* path);

/// <summary>
/// </summary>
extern "C" AmxxStatus DLLEXPORT AMXX_Attach(std::add_pointer_t<void*(const char*)>);

/// <summary>
/// Class AmxxApi.
/// </summary>
class AmxxApi {
	friend AmxxStatus AMXX_Attach(std::add_pointer_t<void*(const char*)>);

	/// <summary>
	/// <para>AMXX API function pointers.</para>
	/// </summary>
	static AmxxApiFuncPointers amxx_api_funcs_;

public:
	/// <summary>
	/// </summary>
	static int add_natives(const AmxNativeInfo* list)
	{
		return amxx_api_funcs_.add_natives(list);
	}

	/// <summary>
	/// </summary>
	static int add_new_natives(const AmxNativeInfo* list)
	{
		return amxx_api_funcs_.add_new_natives(list);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static char* build_path_name(const char* format, Args&&... args)
	{
		return amxx_api_funcs_.build_path_name(format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static char* build_path_name_r(char* buffer, const std::size_t max_len, const char* format, Args&&... args)
	{
		return amxx_api_funcs_.build_path_name_r(buffer, max_len, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	static cell* get_amx_address(Amx* amx, const cell offset)
	{
		return amxx_api_funcs_.get_amx_address(amx, offset);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static void print_srv_console(const char* format, Args&&... args)
	{
		amxx_api_funcs_.print_srv_console(format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	static const char* get_mod_name()
	{
		return amxx_api_funcs_.get_mod_name();
	}

	/// <summary>
	/// </summary>
	static const char* get_amx_script_name(const int id, const bool filename = false)
	{
		return filename
			       ? filename_from_path(amxx_api_funcs_.get_amx_script_name(id))
			       : amxx_api_funcs_.get_amx_script_name(id);
	}

	/// <summary>
	/// </summary>
	static Amx* get_amx_script(const int id)
	{
		return amxx_api_funcs_.get_amx_script(id);
	}

	/// <summary>
	/// </summary>
	static int find_amx_script_by_amx(const Amx* amx)
	{
		return amxx_api_funcs_.find_amx_script_by_amx(amx);
	}

	/// <summary>
	/// </summary>
	static int find_amx_script_by_name(const char* name)
	{
		return amxx_api_funcs_.find_amx_script_by_name(name);
	}

	/// <summary>
	/// </summary>
	static int set_amx_string(Amx* amx, const cell amx_address, const char* source, const int max)
	{
		return amxx_api_funcs_.set_amx_string(amx, amx_address, source, max);
	}

	/// <summary>
	/// </summary>
	static char* get_amx_string(Amx* amx, const cell amx_address, const int buffer_id, int* len)
	{
		return amxx_api_funcs_.get_amx_string(amx, amx_address, buffer_id, len);
	}

	/// <summary>
	/// </summary>
	static char* get_amx_string(Amx* amx, const cell amx_address, const int buffer_id = 0)
	{
		auto len = 0;
		return amxx_api_funcs_.get_amx_string(amx, amx_address, buffer_id, &len);
	}

	/// <summary>
	/// </summary>
	static int get_amx_string_len(const cell* ptr)
	{
		return amxx_api_funcs_.get_amx_string_len(ptr);
	}

	/// <summary>
	/// </summary>
	static char* format_amx_string(Amx* amx, cell* params, const int start_param, int* len)
	{
		return amxx_api_funcs_.format_amx_string(amx, params, start_param, len);
	}

	/// <summary>
	/// </summary>
	static void copy_amx_memory(cell* dest, const cell* src, const int len)
	{
		amxx_api_funcs_.copy_amx_memory(dest, src, len);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static void log(const char* format, Args&&... args)
	{
		amxx_api_funcs_.log(format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static void log_error(Amx* amx, const AmxError error, const char* format, Args&&... args)
	{
		amxx_api_funcs_.log_error(amx, error, format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	static int raise_amx_error(Amx* amx, const AmxError error)
	{
		return amxx_api_funcs_.raise_amx_error(amx, error);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static int register_forward(const char* func_name, const ForwardExecType exec_type, Args&&... args)
	{
		return amxx_api_funcs_.register_forward(func_name, exec_type, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static int execute_forward(const int id, Args&&... args)
	{
		return amxx_api_funcs_.execute_forward(id, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	static cell prepare_cell_array(cell* ptr, const unsigned int size)
	{
		return amxx_api_funcs_.prepare_cell_array(ptr, size);
	}

	/// <summary>
	/// </summary>
	static cell prepare_char_array(char* ptr, const unsigned int size)
	{
		return amxx_api_funcs_.prepare_char_array(ptr, size);
	}

	/// <summary>
	/// </summary>
	static cell prepare_cell_array_a(cell* ptr, const unsigned int size, const bool copy_back)
	{
		return amxx_api_funcs_.prepare_cell_array_a(ptr, size, copy_back);
	}

	/// <summary>
	/// </summary>
	static cell prepare_char_array_a(char* ptr, const unsigned int size, const bool copy_back)
	{
		return amxx_api_funcs_.prepare_char_array_a(ptr, size, copy_back);
	}

	/// <summary>
	/// </summary>
	static int is_player_valid(const int id)
	{
		return amxx_api_funcs_.is_player_valid(id);
	}

	/// <summary>
	/// </summary>
	static const char* get_player_name(const int id)
	{
		return amxx_api_funcs_.get_player_name(id);
	}

	/// <summary>
	/// </summary>
	static const char* get_player_ip(const int id)
	{
		return amxx_api_funcs_.get_player_ip(id);
	}

	/// <summary>
	/// </summary>
	static int is_player_in_game(const int id)
	{
		return amxx_api_funcs_.is_player_in_game(id);
	}

	/// <summary>
	/// </summary>
	static int is_player_bot(const int id)
	{
		return amxx_api_funcs_.is_player_bot(id);
	}

	/// <summary>
	/// </summary>
	static int is_player_authorized(const int id)
	{
		return amxx_api_funcs_.is_player_authorized(id);
	}

	/// <summary>
	/// </summary>
	static float get_player_time(const int id)
	{
		return amxx_api_funcs_.get_player_time(id);
	}

	/// <summary>
	/// </summary>
	static float get_player_play_time(const int id)
	{
		return amxx_api_funcs_.get_player_play_time(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_flags(const int id)
	{
		return amxx_api_funcs_.get_player_flags(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_cur_weapon(const int id)
	{
		return amxx_api_funcs_.get_player_cur_weapon(id);
	}

	/// <summary>
	/// </summary>
	static const char* get_player_team(const int id)
	{
		return amxx_api_funcs_.get_player_team(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_team_id(const int id)
	{
		return amxx_api_funcs_.get_player_team_id(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_deaths(const int id)
	{
		return amxx_api_funcs_.get_player_deaths(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_menu(const int id)
	{
		return amxx_api_funcs_.get_player_menu(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_keys(const int id)
	{
		return amxx_api_funcs_.get_player_keys(id);
	}

	/// <summary>
	/// </summary>
	static int is_player_alive(const int id)
	{
		return amxx_api_funcs_.is_player_alive(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_frags(const int id)
	{
		return amxx_api_funcs_.get_player_frags(id);
	}

	/// <summary>
	/// </summary>
	static int is_player_connecting(const int id)
	{
		return amxx_api_funcs_.is_player_connecting(id);
	}

	/// <summary>
	/// </summary>
	static int is_player_hltv(const int id)
	{
		return amxx_api_funcs_.is_player_hltv(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_armor(const int id)
	{
		return amxx_api_funcs_.get_player_armor(id);
	}

	/// <summary>
	/// </summary>
	static int get_player_health(const int id)
	{
		return amxx_api_funcs_.get_player_health(id);
	}

#ifdef USE_METAMOD
	/// <summary>
	/// </summary>
	static Edict* get_player_edict(const int id)
	{
		return amxx_api_funcs_.get_player_edict(id);
	}
#else
	/// <summary>
	/// </summary>
	static void* get_player_edict(const int id)
	{
		return amxx_api_funcs_.get_player_edict(id);
	}
#endif

	/// <summary>
	/// </summary>
	static void* player_prop_address(const int id, const int prop)
	{
		return amxx_api_funcs_.player_prop_address(id, prop);
	}

	/// <summary>
	/// </summary>
	static int amx_exec(Amx* amx, cell* return_val, const int index)
	{
		return amxx_api_funcs_.amx_exec(amx, return_val, index);
	}

	/// <summary>
	/// </summary>
	static int amx_exec_v(Amx* amx, cell* return_val, const int index, const int num_params, cell params[])
	{
		return amxx_api_funcs_.amx_exec_v(amx, return_val, index, num_params, params);
	}

	/// <summary>
	/// </summary>
	static int amx_allot(Amx* amx, const int length, cell* amx_address, cell** phys_address)
	{
		return amxx_api_funcs_.amx_allot(amx, length, amx_address, phys_address);
	}

	/// <summary>
	/// </summary>
	static int amx_find_public(Amx* amx, const char* func_name, int* index)
	{
		return amxx_api_funcs_.amx_find_public(amx, func_name, index);
	}

	/// <summary>
	/// </summary>
	static int amx_find_native(Amx* amx, const char* func_name, int* index)
	{
		return amxx_api_funcs_.amx_find_native(amx, func_name, index);
	}

	/// <summary>
	/// </summary>
	static int load_amx_script(Amx* amx, void** code, const char* path, char error_info[64], const int debug)
	{
		return amxx_api_funcs_.load_amx_script(amx, code, path, error_info, debug);
	}

	/// <summary>
	/// </summary>
	static int unload_amx_script(Amx* amx, void** code)
	{
		return amxx_api_funcs_.unload_amx_script(amx, code);
	}

	/// <summary>
	/// </summary>
	//static cell real_to_cell(const real value)
	//{
	//	return amxx_api_funcs_.real_to_cell(value);
	//}

	/// <summary>
	/// </summary>
	//static real cell_to_real(const cell value)
	//{
	//	return amxx_api_funcs_.cell_to_real(value);
	//}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static int register_sp_forward(Amx* amx, const int func, Args&&... args)
	{
		return amxx_api_funcs_.register_sp_forward(amx, func, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static int register_sp_forward_by_name(Amx* amx, const char* func_name, Args&&... args)
	{
		return amxx_api_funcs_.register_sp_forward_by_name(amx, func_name, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	static void unregister_sp_forward(const int id)
	{
		amxx_api_funcs_.unregister_sp_forward(id);
	}

	/// <summary>
	/// </summary>
	static void merge_definition_file(const char* file_name)
	{
		amxx_api_funcs_.merge_definition_file(file_name);
	}

	/// <summary>
	/// </summary>
	template <typename ...Args>
	static const char* format(const char* format, Args&&... args)
	{
		return amxx_api_funcs_.format(format, std::forward<Args>(args)...);
	}

	/// <summary>
	/// </summary>
	static void register_function(void* pfn, const char* desc)
	{
		amxx_api_funcs_.register_function(pfn, desc);
	}

	/// <summary>
	/// </summary>
	static int amx_push(Amx* amx, const cell value)
	{
		return amxx_api_funcs_.amx_push(amx, value);
	}

	/// <summary>
	/// </summary>
	static int set_player_team_info(const int player, const int team_id, const char* name)
	{
		return amxx_api_funcs_.set_player_team_info(player, team_id, name);
	}

	/// <summary>
	/// </summary>
	static void reg_auth_func(const std::add_pointer_t<void(int player, const char* auth_string)> authorize_func)
	{
		amxx_api_funcs_.reg_auth_func(authorize_func);
	}

	/// <summary>
	/// </summary>
	static void unregister_auth_func(const std::add_pointer_t<void(int player, const char* auth_string)> authorize_func)
	{
		amxx_api_funcs_.unregister_auth_func(authorize_func);
	}

	/// <summary>
	/// </summary>
	static int find_library(const char* name, const LibType type)
	{
		return amxx_api_funcs_.find_library(name, type);
	}

	/// <summary>
	/// </summary>
	static std::size_t add_libraries(const char* name, const LibType type, void* parent)
	{
		return amxx_api_funcs_.add_libraries(name, type, parent);
	}

	/// <summary>
	/// </summary>
	static std::size_t remove_libraries(void* parent)
	{
		return amxx_api_funcs_.remove_libraries(parent);
	}

	/// <summary>
	/// </summary>
	static void override_natives(AmxNativeInfo* natives, const char* my_name)
	{
		amxx_api_funcs_.override_natives(natives, my_name);
	}

	/// <summary>
	/// </summary>
	static const char* get_local_info(const char* name, const char* def)
	{
		return amxx_api_funcs_.get_local_info(name, def);
	}

	/// <summary>
	/// </summary>
	static int amx_re_register(Amx* amx, AmxNativeInfo* list, const int number)
	{
		return amxx_api_funcs_.amx_re_register(amx, list, number);
	}

	/// <summary>
	/// </summary>
	static void* register_function_ex(void* pfn, const char* desc)
	{
		return amxx_api_funcs_.register_function_ex(pfn, desc);
	}

	/// <summary>
	/// </summary>
	static void message_block(const int mode, const int message, int* opt)
	{
		amxx_api_funcs_.message_block(mode, message, opt);
	}

#ifndef AMXX_182_COMPATIBILITY
	/// <summary>
	/// </summary>
	static char* get_amx_string_null(Amx* amx, const cell amx_address, const int buffer_id, int* len)
	{
		return amxx_api_funcs_.get_amx_string_null(amx, amx_address, buffer_id, len);
	}

	/// <summary>
	/// </summary>
	static cell* get_amx_vector_null(Amx* amx, const cell offset)
	{
		return amxx_api_funcs_.get_amx_vector_null(amx, offset);
	}

	/// <summary>
	/// </summary>
	static GameConfigManager* get_config_manager()
	{
		return amxx_api_funcs_.get_config_manager();
	}

	/// <summary>
	/// </summary>
	static int load_amx_script_ex(Amx* amx, void** code, const char* path, char* error_info, const std::size_t max_length, const int debug)
	{
		return amxx_api_funcs_.load_amx_script_ex(amx, code, path, error_info, max_length, debug);
	}

	/// <summary>
	/// </summary>
	static int set_amx_string_utf8_cell(Amx* amx, const cell amx_address, const cell* source, const std::size_t source_len, const std::size_t max_len)
	{
		return amxx_api_funcs_.set_amx_string_utf8_cell(amx, amx_address, source, source_len, max_len);
	}

	/// <summary>
	/// </summary>
	static int set_amx_string_utf8_char(Amx* amx, const cell amx_address, const char* source, const std::size_t source_len, const std::size_t max_len)
	{
		return amxx_api_funcs_.set_amx_string_utf8_char(amx, amx_address, source, source_len, max_len);
	}
#endif
};

#ifdef AMXX_QUERY
void AMXX_QUERY();
#endif

#ifdef AMXX_CHECK_GAME
AmxxGameStatus AMXX_CHECK_GAME(const char* game);
#endif

#ifdef AMXX_ATTACH
AmxxStatus AMXX_ATTACH();
#endif

#ifdef AMXX_DETACH
void AMXX_DETACH();
#endif

#ifdef AMXX_PLUGINS_LOADED
void AMXX_PLUGINS_LOADED();
#endif

#ifdef AMXX_PLUGINS_UNLOADED
void AMXX_PLUGINS_UNLOADED();
#endif

#ifdef AMXX_PLUGINS_UNLOADING
void AMXX_PLUGINS_UNLOADING();
#endif
