// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <cssdk/dll/regamedll_api.h>

/// <summary>
/// Class RegamedllApi.
/// </summary>
class RegamedllApi {
	/// <summary>
	/// </summary>
	static int major_version_;

	/// <summary>
	/// </summary>
	static int minor_version_;

	/// <summary>
	/// </summary>
	static GameRules* game_rules_;

	/// <summary>
	/// </summary>
	static const RegamedllFuncs* regamedll_funcs_;

	/// <summary>
	/// </summary>
	static RegamedllHookChains* regamedll_hook_chains_;

	/// <summary>
	/// </summary>
	static RegamedllApiInterface* regamedll_api_interface_;

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
	static GameRules* game_rules()
	{
		return game_rules_;
	}

	/// <summary>
	/// </summary>
	static const RegamedllFuncs* funcs()
	{
		return regamedll_funcs_;
	}

	/// <summary>
	/// </summary>
	static RegamedllHookChains* hook_chains()
	{
		return regamedll_hook_chains_;
	}

	/// <summary>
	/// </summary>
	static WeaponInfoStruct* get_weapon_info(const WeaponId weapon)
	{
		return regamedll_api_interface_->get_weapon_info(weapon);
	}

	/// <summary>
	/// </summary>
	static WeaponInfoStruct* get_weapon_info(const char* weapon)
	{
		return regamedll_api_interface_->get_weapon_info(weapon);
	}

	/// <summary>
	/// </summary>
	static PlayerMove* get_player_move()
	{
		return regamedll_api_interface_->get_player_move();
	}

	/// <summary>
	/// </summary>
	static WeaponSlotInfo* get_weapon_slot(const WeaponId weapon)
	{
		return regamedll_api_interface_->get_weapon_slot(weapon);
	}

	/// <summary>
	/// </summary>
	static WeaponSlotInfo* get_weapon_slot(const char* weapon)
	{
		return regamedll_api_interface_->get_weapon_slot(weapon);
	}

	/// <summary>
	/// </summary>
	static ItemInfo* get_item_info(const WeaponId weapon)
	{
		return regamedll_api_interface_->get_item_info(weapon);
	}

	/// <summary>
	/// </summary>
	static AmmoInfo* get_ammo_info(const AmmoType ammo)
	{
		return regamedll_api_interface_->get_ammo_info(ammo);
	}

	/// <summary>
	/// </summary>
	static AmmoInfoStruct* get_ammo_info_ex(const AmmoType ammo)
	{
		return regamedll_api_interface_->get_ammo_info_ex(ammo);
	}

	/// <summary>
	/// </summary>
	static AmmoInfoStruct* get_ammo_info_ex(const char* ammo)
	{
		return regamedll_api_interface_->get_ammo_info_ex(ammo);
	}

private:
	/// <summary>
	/// </summary>
	static bool check_cs_entity_version(const char* version)
	{
		return regamedll_api_interface_->check_cs_entity_version(version);
	}

	/// <summary>
	/// </summary>
	static bool check_game_rules_version(const char* version)
	{
		return regamedll_api_interface_->check_game_rules_version(version);
	}
};
