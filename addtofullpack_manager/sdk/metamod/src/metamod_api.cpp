// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <metamod/api.h>
#include <metamod/engine_hooks.h>
#include <metamod/gamedll.h>
#include <metamod/gamedll_hooks.h>
#include <metamod/os_dep.h>
#include <metamod/utils.h>
#include <cstring>
#include <type_traits>

/// <summary>
/// <para>The metamod globals.</para>
/// </summary>
MetaGlobals* g_meta_globals = nullptr;

/// <summary>
/// <para>Table of get api functions, retrieved from each plugin.</para>
/// </summary>
struct MetaHookExportFuncs {
	/// <summary>
	/// <para>Not used.</para>
	/// </summary>
	std::add_pointer_t<int(DllFuncPointers*, int)> export_dll_hooks{};

	/// <summary>
	/// <para>Not used.</para>
	/// </summary>
	std::add_pointer_t<int(DllFuncPointers*, int)> export_dll_hooks_post{};

	/// <summary>
	/// <para>Function export the DLL hooks.</para>
	/// </summary>
	std::add_pointer_t<int(DllFuncPointers*, int*)> export_dll_hooks2{};

	/// <summary>
	/// <para>Function export the DLL post hooks.</para>
	/// </summary>
	std::add_pointer_t<int(DllFuncPointers*, int*)> export_dll_hooks2_post{};

	/// <summary>
	/// <para>Function export the DLL new hooks.</para>
	/// </summary>
	std::add_pointer_t<int(DllNewFuncPointers*, int*)> export_dllnew_hooks{};

	/// <summary>
	/// <para>Function export the DLL new post hooks.</para>
	/// </summary>
	std::add_pointer_t<int(DllNewFuncPointers*, int*)> export_dllnew_hooks_post{};

	/// <summary>
	/// <para>Function export the engine hooks.</para>
	/// </summary>
	std::add_pointer_t<int(EngineFuncPointers*, int*)> export_engine_hooks{};

	/// <summary>
	/// <para>Function export the engine post hooks.</para>
	/// </summary>
	std::add_pointer_t<int(EngineFuncPointers*, int*)> export_engine_hooks_post{};
};

/// <summary>
/// <para>Pair of function tables provided by gamedll.</para>
/// </summary>
struct MetaDllFuncsTables {
	/// <summary>
	/// </summary>
	DllFuncPointers* dll_functions_table{};

	/// <summary>
	/// </summary>
	DllNewFuncPointers* dllnew_functions_table{};
};

/// <summary>
/// </summary>
static void clear_all_hooks()
{
	EngineHooks::clear_all_hooks();
	GameDllHooks::clear_all_hooks();
	GameDllNewHooks::clear_all_hooks();
}

/// <summary>
/// </summary>
extern "C" void DLLEXPORT Meta_Init()
{
	EngineHooks::engine_hooks_ = new EngineFuncPointers;
	EngineHooks::engine_post_hooks_ = new EngineFuncPointers;

	GameDllHooks::dll_hooks_ = new DllFuncPointers;
	GameDllHooks::dll_post_hooks_ = new DllFuncPointers;

	GameDllNewHooks::dll_new_hooks_ = new DllNewFuncPointers;
	GameDllNewHooks::dll_new_post_hooks_ = new DllNewFuncPointers;
	
#ifdef META_INIT
	META_INIT();
#endif
}

/// <summary>
/// <para>Get info about plugin, compare meta_interface versions, provide meta utility callback functions.</para>
/// </summary>
extern "C" MetamodStatus DLLEXPORT Meta_Query(const char* interface_version, MetaPluginInfo** plugin_info, MetaUtilFuncPointers* util_funcs)
{
	if (std::strcmp(interface_version, META_INTERFACE_VERSION) != 0)
		return MetamodStatus::Failed;

	static MetaPluginInfo info =
	{
		META_INTERFACE_VERSION,
		META_PLUGIN_NAME,
		META_PLUGIN_VERSION,
		META_PLUGIN_DATE,
		META_PLUGIN_AUTHOR,
		META_PLUGIN_URL,
		META_PLUGIN_LOG_TAG,
		META_PLUGIN_LOADABLE,
		META_PLUGIN_UNLOADABLE
	};

	*plugin_info = &info;
	MetaUtils::util_funcs_ = util_funcs;
	MetaUtils::plugin_info_ = *plugin_info;

#ifdef META_QUERY
	META_QUERY();
#endif

	return MetamodStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" MetamodStatus DLLEXPORT Meta_Attach(MetaPluginLoadTime /*load_time*/, MetaHookExportFuncs* export_funcs_table,
                                               MetaGlobals* globals, MetaDllFuncsTables* dll_funcs_tables)
{
	MetaHookExportFuncs hook_export_funcs =
	{
		nullptr,
		nullptr,
		export_dll_hooks,
		export_dll_post_hooks,
		export_dll_new_hooks,
		export_dll_new_post_hooks,
		export_engine_hooks,
		export_engine_post_hooks
	};

	g_meta_globals = globals;
	GameDll::dll_funcs_ = dll_funcs_tables->dll_functions_table;
	GameDllNew::dll_new_funcs_ = dll_funcs_tables->dllnew_functions_table;
	std::memcpy(export_funcs_table, &hook_export_funcs, sizeof(MetaHookExportFuncs));

#ifdef META_ATTACH
	if (META_ATTACH() != MetamodStatus::Ok) {
		clear_all_hooks();
		return MetamodStatus::Failed;
	}
#endif

	return MetamodStatus::Ok;
}

/// <summary>
/// </summary>
extern "C" MetamodStatus DLLEXPORT Meta_Detach(MetaPluginLoadTime /*now*/, const MetaPluginUnloadReason /*reason*/)
{
#ifdef META_DETACH
	META_DETACH();
#endif
	
	clear_all_hooks();

	return MetamodStatus::Ok;
}
