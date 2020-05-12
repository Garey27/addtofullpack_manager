// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/base_types.h>

#ifdef HOOK_HLTV
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#else
#include <limits.h>
/// <summary>
/// </summary>
constexpr auto MAX_PATH = PATH_MAX;
#endif
#endif // HOOK_HLTV

/// <summary>
/// <para>Must match value in quakedefs.h.</para>
/// </summary>
constexpr auto MAX_QPATH = 64;

/// <summary>
/// </summary>
constexpr auto MAX_RESOURCE_LIST = 1280;

/// <summary>
/// <para>Disconnect if we can't get this file.</para>
/// </summary>
constexpr auto RES_FATAL_IF_MISSING = 1 << 0;

/// <summary>
/// <para>Do we have the file locally, did we get it ok?</para>
/// </summary>
constexpr auto RES_WAS_MISSING = 1 << 1;

/// <summary>
/// <para>Is this resource one that corresponds to another player's customization
/// or is it a server startup resource.</para>
/// </summary>
constexpr auto RES_CUSTOM = 1 << 2;

/// <summary>
/// <para>Already requested a download of this one.</para>
/// </summary>
constexpr auto RES_REQUESTED = 1 << 3;

/// <summary>
/// <para>Already precached.</para>
/// </summary>
constexpr auto RES_PRECACHED = 1 << 4;

/// <summary>
/// <para>Download always even if available on client.</para>
/// </summary>
constexpr auto RES_ALWAYS = 1 << 5;

/// <summary>
/// </summary>
constexpr auto RES_UNK_6 = 1 << 6;

/// <summary>
/// <para>Check file on client.</para>
/// </summary>
constexpr auto RES_CHECK_FILE = 1 << 7;

/// <summary>
/// </summary>
constexpr auto FCUST_FROM_HPAK = 1 << 0;

/// <summary>
/// </summary>
constexpr auto FCUST_WIPE_DATA = 1 << 1;

/// <summary>
/// </summary>
constexpr auto FCUST_IGNORE_INIT = 1 << 2;

/// <summary>
/// Enum ResourceType
/// </summary>
enum class ResourceType {
	/// <summary>
	/// </summary>
	Sound = 0,

	/// <summary>
	/// </summary>
	Skin,

	/// <summary>
	/// </summary>
	Model,

	/// <summary>
	/// </summary>
	Decal,

	/// <summary>
	/// </summary>
	Generic,

	/// <summary>
	/// </summary>
	EventScript,

	/// <summary>
	/// </summary>
	World,

	/// <summary>
	/// </summary>
	Unk,

	/// <summary>
	/// </summary>
	Max
};

/// <summary>
/// Struct ResourceInfoS
/// </summary>
struct ResourceInfoS {
	/// <summary>
	/// </summary>
	int size{};
};

/// <summary>
/// Struct ResourceInfo
/// </summary>
struct ResourceInfo {
	/// <summary>
	/// </summary>
	ResourceInfoS info[static_cast<int>(ResourceType::Max)]{};
};

/// <summary>
/// Struct Resource
/// </summary>
struct Resource {
#ifdef HOOK_HLTV
	/// <summary>
	/// <para>NOTE HLTV: array szFileName declared on 260 cell,
	/// this changes necessary for compatibility hookers.</para>
	/// </summary>
	char file_name[MAX_PATH]{};
#else
	/// <summary>
	/// <para>File name to download/precache.</para>
	/// </summary>
	char file_name[MAX_QPATH]{};
#endif // HOOK_HLTV

	/// <summary>
	/// </summary>
	ResourceType type{};

	/// <summary>
	/// <para>For <c>ResourceType::Decal</c></para>
	/// </summary>
	int index{};

	/// <summary>
	/// <para>Size in bytes if this must be downloaded.</para>
	/// </summary>
	int download_size{};

	/// <summary>
	/// </summary>
	unsigned char flags{};

	/// <summary>
	/// <para>To determine if we already have it.</para>
	/// </summary>
	unsigned char md5_hash[16]{};

	/// <summary>
	/// <para>Which player index this resource is associated with, if it's a custom resource.</para>
	/// </summary>
	unsigned char player_num{};

	/// <summary>
	/// <para>For future expansion.</para>
	/// </summary>
	unsigned char reserved[32]{};

	/// <summary>
	/// <para>Next in chain.</para>
	/// </summary>
	Resource* next{};

#if !defined(HLTV)
	/// <summary>
	/// </summary>
	Resource* prev{};
#else
	/// <summary>
	/// </summary>
	unsigned char* data;
#endif // !defined(HLTV)
};

/// <summary>
/// Struct Customization
/// </summary>
struct Customization {
	/// <summary>
	/// <para>Is this customization in use.</para>
	/// </summary>
	qboolean in_use{};

	/// <summary>
	/// <para>The resource for this customization.</para>
	/// </summary>
	Resource resource;

	/// <summary>
	/// <para>Has the raw data been translated into a useable format?<br/>
	/// (e.g., raw decal .wad make into <c>Texture*</c>).</para>
	/// </summary>
	qboolean translated{};

	/// <summary>
	/// <para>Customization specific data.</para>
	/// </summary>
	int user_data1{};

	/// <summary>
	/// <para>Customization specific data.</para>
	/// </summary>
	int user_data2{};

	/// <summary>
	/// <para>Buffer that holds the data structure that references the data (e.g., the cache_wad_t).</para>
	/// </summary>
	void* info{};

	/// <summary>
	/// <para>Buffer that holds the data for the customization (the raw .wad data).</para>
	/// </summary>
	void* buffer{};

	/// <summary>
	/// <para>Next in chain.</para>
	/// </summary>
	Customization* next{};
};
