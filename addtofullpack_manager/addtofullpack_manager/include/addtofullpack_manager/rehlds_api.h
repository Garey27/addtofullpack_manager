// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <cssdk/engine/rehlds_api.h>

/// <summary>
/// Class RehldsApi.
/// </summary>
class RehldsApi {
	/// <summary>
	/// </summary>
	static int major_version_;

	/// <summary>
	/// </summary>
	static int minor_version_;

	/// <summary>
	/// </summary>
	static const RehldsFuncs* rehlds_funcs_;

	/// <summary>
	/// </summary>
	static RehldsHookChains* rehlds_hook_chains_;

	/// <summary>
	/// </summary>
	static RehldsServerStatic* rehlds_server_static_;

	/// <summary>
	/// </summary>
	static RehldsServerData* rehlds_server_data_;

	/// <summary>
	/// </summary>
	static RehldsFlightRecorder* rehlds_flight_recorder_;

public:
	/// <summary>
	/// </summary>
	static bool init();

	/// <summary>
	/// </summary>
	static int major_version()
	{
		return major_version_;
	}

	/// <summary>
	/// </summary>
	static int minor_version()
	{
		return minor_version_;
	}

	/// <summary>
	/// </summary>
	static const RehldsFuncs* funcs()
	{
		return rehlds_funcs_;
	}

	/// <summary>
	/// </summary>
	static RehldsHookChains* hook_chains()
	{
		return rehlds_hook_chains_;
	}

	/// <summary>
	/// </summary>
	static RehldsServerStatic* server_static()
	{
		return rehlds_server_static_;
	}

	/// <summary>
	/// </summary>
	static RehldsServerData* server_data()
	{
		return rehlds_server_data_;
	}

	/// <summary>
	/// </summary>
	static RehldsFlightRecorder* flight_recorder()
	{
		return rehlds_flight_recorder_;
	}
};
