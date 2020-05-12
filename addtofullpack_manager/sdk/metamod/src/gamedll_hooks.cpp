// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <metamod/gamedll_hooks.h>
#include <metamod/engine.h>

/// <summary>
/// <para>GameDLL hooks table.</para>
/// </summary>
DllFuncPointers* GameDllHooks::dll_hooks_{};

/// <summary>
/// <para>GameDLL post hooks table.</para>
/// </summary>
DllFuncPointers* GameDllHooks::dll_post_hooks_{};

/// <summary>
/// <para>New GameDLL hooks table.</para>
/// </summary>
DllNewFuncPointers* GameDllNewHooks::dll_new_hooks_{};

/// <summary>
/// <para>New GameDLL post hooks table.</para>
/// </summary>
DllNewFuncPointers* GameDllNewHooks::dll_new_post_hooks_{};

/// <summary>
/// <para>Exports the GameDLL hooks.</para>
/// </summary>
int export_dll_hooks(DllFuncPointers* function_table, int* interface_version)
{
	if (function_table == nullptr || *interface_version != INTERFACE_VERSION) {
		delete GameDllHooks::dll_hooks_;
		GameDllHooks::dll_hooks_ = nullptr;
	}

	if (function_table == nullptr) {
		Engine::alert_message(AlertType::Logged, "%s called with null function_table.\n", __func__);
		return false;
	}

	if (*interface_version != INTERFACE_VERSION) {
		Engine::alert_message(AlertType::Logged, "%s interface version mismatch; requested = %d; ours = %d\n",
		                      __func__, *interface_version, INTERFACE_VERSION);

		// Tell metamod what version we had, so it can figure out who is out of date.
		*interface_version = INTERFACE_VERSION;

		return false;
	}

	std::memcpy(function_table, GameDllHooks::dll_hooks_, sizeof(DllFuncPointers));

	delete GameDllHooks::dll_hooks_;
	GameDllHooks::dll_hooks_ = function_table;

	return true;
}

/// <summary>
/// <para>Exports the GameDLL post hooks.</para>
/// </summary>
int export_dll_post_hooks(DllFuncPointers* function_table, int* interface_version)
{
	if (function_table == nullptr || *interface_version != INTERFACE_VERSION) {
		delete GameDllHooks::dll_post_hooks_;
		GameDllHooks::dll_post_hooks_ = nullptr;
	}

	if (function_table == nullptr) {
		Engine::alert_message(AlertType::Logged, "%s called with null function_table.\n", __func__);
		return false;
	}

	if (*interface_version != INTERFACE_VERSION) {
		Engine::alert_message(AlertType::Logged, "%s interface version mismatch; requested = %d; ours = %d\n",
		                      __func__, *interface_version, INTERFACE_VERSION);

		// Tell metamod what version we had, so it can figure out who is out of date.
		*interface_version = INTERFACE_VERSION;

		return false;
	}

	std::memcpy(function_table, GameDllHooks::dll_post_hooks_, sizeof(DllFuncPointers));

	delete GameDllHooks::dll_post_hooks_;
	GameDllHooks::dll_post_hooks_ = function_table;

	return true;
}

/// <summary>
/// <para>Exports the new GameDLL hooks.</para>
/// </summary>
int export_dll_new_hooks(DllNewFuncPointers* function_table, int* interface_version)
{
	if (function_table == nullptr || *interface_version != DLL_NEW_FUNCTIONS_VERSION) {
		delete GameDllNewHooks::dll_new_hooks_;
		GameDllNewHooks::dll_new_hooks_ = nullptr;
	}

	if (function_table == nullptr) {
		Engine::alert_message(AlertType::Logged, "%s called with null function_table.\n", __func__);
		return false;
	}

	if (*interface_version != DLL_NEW_FUNCTIONS_VERSION) {
		Engine::alert_message(AlertType::Logged, "%s interface version mismatch; requested = %d; ours = %d\n",
		                      __func__, *interface_version, DLL_NEW_FUNCTIONS_VERSION);

		// Tell metamod what version we had, so it can figure out who is out of date.
		*interface_version = DLL_NEW_FUNCTIONS_VERSION;

		return false;
	}

	std::memcpy(function_table, GameDllNewHooks::dll_new_hooks_, sizeof(DllNewFuncPointers));

	delete GameDllNewHooks::dll_new_hooks_;
	GameDllNewHooks::dll_new_hooks_ = function_table;

	return true;
}

/// <summary>
/// <para>Exports the new GameDLL hooks.</para>
/// </summary>
int export_dll_new_post_hooks(DllNewFuncPointers* function_table, int* interface_version)
{
	if (function_table == nullptr || *interface_version != DLL_NEW_FUNCTIONS_VERSION) {
		delete GameDllNewHooks::dll_new_post_hooks_;
		GameDllNewHooks::dll_new_post_hooks_ = nullptr;
	}

	if (function_table == nullptr) {
		Engine::alert_message(AlertType::Logged, "%s called with null function_table.\n", __func__);
		return false;
	}

	if (*interface_version != DLL_NEW_FUNCTIONS_VERSION) {
		Engine::alert_message(AlertType::Logged, "%s interface version mismatch; requested = %d; ours = %d\n",
		                      __func__, *interface_version, DLL_NEW_FUNCTIONS_VERSION);

		// Tell metamod what version we had, so it can figure out who is out of date.
		*interface_version = DLL_NEW_FUNCTIONS_VERSION;

		return false;
	}

	std::memcpy(function_table, GameDllNewHooks::dll_new_post_hooks_, sizeof(DllNewFuncPointers));

	delete GameDllNewHooks::dll_new_post_hooks_;
	GameDllNewHooks::dll_new_post_hooks_ = function_table;

	return true;
}
