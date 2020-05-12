// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

/// <summary>
/// <para>Flags for plugin to indicate when it can be be loaded/unloaded.<br/></para>
/// </summary>
/// <remarks>
/// Order is crucial, as greater/less comparisons are made.
/// </remarks>
enum class MetaPluginLoadTime {
	/// <summary>
	/// </summary>
	Never = 0,

	/// <summary>
	/// <para>Should only be loaded/unloaded at initial HLDS execution.</para>
	/// </summary>
	Startup,

	/// <summary>
	/// <para>Can be loaded/unloaded between maps.</para>
	/// </summary>
	ChangeLevel,

	/// <summary>
	/// <para>Can be loaded/unloaded at any time.</para>
	/// </summary>
	AnyTime,

	/// <summary>
	/// <para>Can be loaded/unloaded at any time, and can be "paused" during a map.</para>
	/// </summary>
	AnyPause
};

/// <summary>
/// <para>Flags to indicate why the plugin is being unloaded.</para>
/// </summary>
enum class MetaPluginUnloadReason {
	/// <summary>
	/// </summary>
	Null = 0,

	/// <summary>
	/// <para>Was deleted from plugins.ini.</para>
	/// </summary>
	IniDeleted,

	/// <summary>
	/// <para>File on disk is newer than last load.</para>
	/// </summary>
	FileNewer,

	/// <summary>
	/// <para>Requested by server/console command.</para>
	/// </summary>
	Command,

	/// <summary>
	/// <para>Forced by server/console command.</para>
	/// </summary>
	CommandForced,

	/// <summary>
	/// <para>Delayed from previous request; can't tell origin
	/// only used for 'real_reason' on MPlugin::unload().</para>
	/// </summary>
	Delayed,

	/// <summary>
	/// <para>Requested by plugin function call.</para>
	/// </summary>
	Plugin,

	/// <summary>
	/// <para>Forced by plugin function call.</para>
	/// </summary>
	PluginForced,

	/// <summary>
	/// <para>Forced unload by reload().</para>
	/// </summary>
	Reload
};

/// <summary>
/// <para>Information plugin provides about itself.</para>
/// </summary>
struct MetaPluginInfo {
	/// <summary>
	/// <para>Meta interface version.</para>
	/// </summary>
	const char* interface_version{};

	/// <summary>
	/// <para>Full name of plugin.</para>
	/// </summary>
	const char* name{};

	/// <summary>
	/// <para>Plugin version.</para>
	/// </summary>
	const char* version{};

	/// <summary>
	/// <para>Plugin date.</para>
	/// </summary>
	const char* date{};

	/// <summary>
	/// <para>Plugin author.</para>
	/// </summary>
	const char* author{};

	/// <summary>
	/// <para>Plugin URL.</para>
	/// </summary>
	const char* url{};

	/// <summary>
	/// <para>Plugin log tag.</para>
	/// </summary>
	const char* log_tag{};

	/// <summary>
	/// <para>Loadable flags.</para>
	/// </summary>
	MetaPluginLoadTime loadable{};

	/// <summary>
	/// <para>Unloadable flags.</para>
	/// </summary>
	MetaPluginLoadTime unloadable{};
};
