// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/net_address.h>
#include <cssdk/common/user_cmd.h>
#include <cssdk/engine/common_rehlds.h>
#include <cssdk/engine/custom.h>
#include <cssdk/engine/edict.h>
#include <cssdk/engine/userid_rehlds.h>
#include <cssdk/public/arch_types.h>

/// <summary>
/// </summary>
struct Client;

/// <summary>
/// Class NetChan.
/// </summary>
class NetChan {
public:
	/// <summary>
	/// </summary>
	virtual const NetAddress* get_remote_adr() = 0;

	/// <summary>
	/// </summary>
	virtual SizeBuf* get_message_buf() = 0;
};

/// <summary>
/// Class GameClient.
/// </summary>
class GameClient {
public:
	/// <summary>
	/// </summary>
	virtual int get_id() = 0;

	/// <summary>
	/// </summary>
	virtual bool is_active() = 0;

	/// <summary>
	/// </summary>
	virtual void set_active(bool active) = 0;

	/// <summary>
	/// </summary>
	virtual bool is_spawned() = 0;

	/// <summary>
	/// </summary>
	virtual void set_spawned(bool spawned) = 0;

	/// <summary>
	/// </summary>
	virtual NetChan* get_net_channel() = 0;

	/// <summary>
	/// </summary>
	virtual SizeBuf* get_datagram() = 0;

	/// <summary>
	/// </summary>
	virtual Edict* get_edict() = 0;

	/// <summary>
	/// </summary>
	virtual UserId* get_network_user_id() = 0;

	/// <summary>
	/// </summary>
	virtual const char* get_name() = 0;

	/// <summary>
	/// </summary>
	virtual bool is_connected() = 0;

	/// <summary>
	/// </summary>
	virtual void set_connected(bool connected) = 0;

	/// <summary>
	/// </summary>
	virtual uint32 get_voice_stream(int stream_id) = 0;

	/// <summary>
	/// </summary>
	virtual void set_last_voice_time(double time) = 0;

	/// <summary>
	/// </summary>
	virtual double get_last_voice_time() = 0;

	/// <summary>
	/// </summary>
	virtual bool get_loopback() = 0;

	/// <summary>
	/// </summary>
	virtual UserCmd* get_last_cmd() = 0;
};

/// <summary>
/// Class RehldsServerStatic.
/// </summary>
class RehldsServerStatic {
public:
	/// <summary>
	/// </summary>
	virtual ~RehldsServerStatic() = default;

	/// <summary>
	/// </summary>
	virtual int get_max_clients() = 0;

	/// <summary>
	/// </summary>
	virtual bool is_log_active() = 0;

	/// <summary>
	/// </summary>
	virtual GameClient* get_game_client(int id) = 0;

	/// <summary>
	/// </summary>
	virtual Client* get_client(int id) = 0;

	/// <summary>
	/// </summary>
	virtual int get_index_of_client(Client* client) = 0;

	/// <summary>
	/// </summary>
	virtual int get_max_clients_limit() = 0;
};

/// <summary>
/// Class RehldsServerData.
/// </summary>
class RehldsServerData {
public:
	/// <summary>
	/// </summary>
	virtual ~RehldsServerData() = default;

	/// <summary>
	/// </summary>
	virtual const char* get_model_name() = 0;

	/// <summary>
	/// </summary>
	virtual const char* get_name() = 0;

	/// <summary>
	/// </summary>
	virtual uint32 get_world_map_crc() = 0;

	/// <summary>
	/// </summary>
	virtual uint8* get_client_dll_md5() = 0;

	/// <summary>
	/// </summary>
	virtual SizeBuf* get_datagram() = 0;

	/// <summary>
	/// </summary>
	virtual SizeBuf* get_reliable_datagram() = 0;

	/// <summary>
	/// </summary>
	virtual void set_model_name(const char* model_name) = 0;

	/// <summary>
	/// </summary>
	virtual void set_consistency_num(int num) = 0;

	/// <summary>
	/// </summary>
	virtual int get_consistency_num() = 0;

	/// <summary>
	/// </summary>
	virtual int get_resources_num() = 0;

	/// <summary>
	/// </summary>
	virtual int get_decal_name_num() = 0;

	/// <summary>
	/// </summary>
	virtual double get_time() = 0;

	/// <summary>
	/// </summary>
	virtual void set_resources_num(int num) = 0;

	/// <summary>
	/// </summary>
	virtual Resource* get_resource(int index) = 0;

	/// <summary>
	/// </summary>
	virtual void set_name(const char* name) = 0;

	/// <summary>
	/// </summary>
	virtual class ISteamGameServer* get_steam_game_server() = 0;

	/// <summary>
	/// </summary>
	virtual NetAddress* get_net_from() = 0;

	/// <summary>
	/// </summary>
	virtual double get_old_time() = 0;
};
