// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <metamod/engine_hooks.h>
#include <metamod/engine.h>

/// <summary>
/// <para>Engine hooks table.</para>
/// </summary>
EngineFuncPointers* EngineHooks::engine_hooks_{};

/// <summary>
/// <para>Engine post hooks table.</para>
/// </summary>
EngineFuncPointers* EngineHooks::engine_post_hooks_{};

/// <summary>
/// <para>Exports the engine hooks.</para>
/// </summary>
int export_engine_hooks(EngineFuncPointers* function_table, int* interface_version)
{
	if (function_table == nullptr || *interface_version != ENGINE_INTERFACE_VERSION) {
		delete EngineHooks::engine_hooks_;
		EngineHooks::engine_hooks_ = nullptr;
	}

	if (function_table == nullptr) {
		Engine::alert_message(AlertType::Logged, "%s called with null function_table.\n", __func__);
		return false;
	}

	if (*interface_version != ENGINE_INTERFACE_VERSION) {
		Engine::alert_message(AlertType::Logged, "%s interface version mismatch; requested = %d; ours = %d\n",
		                      __func__, *interface_version, ENGINE_INTERFACE_VERSION);

		// Tell metamod what version we had, so it can figure out who is out of date.
		*interface_version = ENGINE_INTERFACE_VERSION;

		return false;
	}

	std::memcpy(function_table, EngineHooks::engine_hooks_, sizeof(EngineFuncPointers));

	delete EngineHooks::engine_hooks_;
	EngineHooks::engine_hooks_ = function_table;

	return true;
}

/// <summary>
/// <para>Exports the engine post hooks.</para>
/// </summary>
int export_engine_post_hooks(EngineFuncPointers* function_table, int* interface_version)
{
	if (function_table == nullptr || *interface_version != ENGINE_INTERFACE_VERSION) {
		delete EngineHooks::engine_post_hooks_;
		EngineHooks::engine_post_hooks_ = nullptr;
	}

	if (function_table == nullptr) {
		Engine::alert_message(AlertType::Logged, "%s called with null function_table.\n", __func__);
		return false;
	}

	if (*interface_version != ENGINE_INTERFACE_VERSION) {
		Engine::alert_message(AlertType::Logged, "%s interface version mismatch; requested = %d; ours = %d\n",
		                      __func__, *interface_version, ENGINE_INTERFACE_VERSION);

		// Tell metamod what version we had, so it can figure out who is out of date.
		*interface_version = ENGINE_INTERFACE_VERSION;

		return false;
	}

	std::memcpy(function_table, EngineHooks::engine_post_hooks_, sizeof(EngineFuncPointers));

	delete EngineHooks::engine_post_hooks_;
	EngineHooks::engine_post_hooks_ = function_table;

	return true;
}
