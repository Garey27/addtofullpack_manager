// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <metamod/plugin_info.h>

/*
 * -------------------------------------------------------------------------------------------
 *	Metamod plugin info.
 * -------------------------------------------------------------------------------------------
 */
constexpr auto META_PLUGIN_NAME = "AddToFullPack Manager";
constexpr auto META_PLUGIN_VERSION = "1.0.0";
constexpr auto META_PLUGIN_AUTHOR = "Denzer";
constexpr auto META_PLUGIN_LOG_TAG = "addtofullpack_manager";
constexpr auto META_PLUGIN_URL = "https://dev-cs.ru";
constexpr auto META_PLUGIN_LOADABLE = MetaPluginLoadTime::AnyTime;
constexpr auto META_PLUGIN_UNLOADABLE = MetaPluginLoadTime::AnyTime;
constexpr auto META_PLUGIN_DATE = __DATE__;

/*
 * -------------------------------------------------------------------------------------------
 *	Metamod init function declarations.
 * -------------------------------------------------------------------------------------------
 */
//#define META_INIT     on_meta_init	// void ()          // NOLINT(cppcoreguidelines-macro-usage)
//#define META_QUERY    on_meta_query	// void ()          // NOLINT(cppcoreguidelines-macro-usage)
//#define META_ATTACH   on_meta_attach	// MetamodStatus () // NOLINT(cppcoreguidelines-macro-usage)
//#define META_DETACH   on_meta_detach	// void ()          // NOLINT(cppcoreguidelines-macro-usage)
