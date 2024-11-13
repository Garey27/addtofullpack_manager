// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

/**
 * Metamod plugin?
 */
#define USE_METAMOD

/**
 * Uncomment this for compatibility with AMXX v1.8.2.
 */
//#define AMXX_182_COMPATIBILITY

/*
 * -------------------------------------------------------------------------------------------
 *	AMXX module info.
 * -------------------------------------------------------------------------------------------
 */
#ifndef USE_METAMOD
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_NAME = "AddToFullPack Manager";
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_VERSION = PROJECT_VERSION;
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_AUTHOR = "Denzer";
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_LOG_TAG = "addtofullpack_manager";
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_URL = "https://dev-cs.ru";
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_DATE = __DATE__;
#else
#include <metamod/metamod_config.h>
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_NAME = META_PLUGIN_NAME;
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_VERSION = META_PLUGIN_VERSION;
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_AUTHOR = META_PLUGIN_AUTHOR;
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_URL = META_PLUGIN_URL;
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_LOG_TAG = META_PLUGIN_LOG_TAG;
/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_DATE = META_PLUGIN_DATE;
#endif

/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_LIBRARY = "addtofullpack_manager";

/// <summary>
/// </summary>
constexpr auto AMXX_MODULE_LIB_CLASS = "addtofullpack_manager";

/// <summary>
/// <para>Reload module on map change.</para>
/// </summary>
constexpr auto AMXX_MODULE_RELOAD_ON_MAP_CHANGE = false;

/*
 * -------------------------------------------------------------------------------------------
 *	AMXX init function declarations.
 * -------------------------------------------------------------------------------------------
 */
//#define AMXX_QUERY				on_amxx_query				// void ()                              // NOLINT(cppcoreguidelines-macro-usage)
//#define AMXX_CHECK_GAME			on_amxx_check_game			// AmxxGameStatus (const char* game)    // NOLINT(cppcoreguidelines-macro-usage)
#define AMXX_ATTACH					on_amxx_attach				// AmxxStatus ()                        // NOLINT(cppcoreguidelines-macro-usage)
#define AMXX_DETACH					on_amxx_detach				// void ()                              // NOLINT(cppcoreguidelines-macro-usage)
//#define AMXX_PLUGINS_LOADED		on_amxx_plugins_loaded		// void ()                              // NOLINT(cppcoreguidelines-macro-usage)
//#define AMXX_PLUGINS_UNLOADED		on_amxx_plugins_unloaded	// void ()                              // NOLINT(cppcoreguidelines-macro-usage)
//#define AMXX_PLUGINS_UNLOADING	on_amxx_plugins_unloading	// void ()                              // NOLINT(cppcoreguidelines-macro-usage)
