// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/api/cs_entity.h>
#include <cssdk/dll/player.h>

/// <summary>
/// Enum WeaponInfiniteAmmoMode
/// </summary>
enum class WeaponInfiniteAmmoMode {
	/// <summary>
	/// </summary>
	Clip = 1,

	/// <summary>
	/// </summary>
	BackpackAmmo
};

/// <summary>
/// Enum ProtectionState
/// </summary>
enum class ProtectionState {
	/// <summary>
	/// </summary>
	NoSet = 0,

	/// <summary>
	/// </summary>
	Active,

	/// <summary>
	/// </summary>
	Expired
};

/// <summary>
/// Class CsPlayer.
/// </summary>
class CsPlayer : public CsMonster {
public:
	/// <summary>
	/// </summary>
	[[nodiscard]] virtual bool is_connected() const = 0;

	/// <summary>
	/// </summary>
	virtual void set_animation(PlayerAnim player_anim) = 0;

	/// <summary>
	/// </summary>
	virtual void add_account(int amount, RewardType type = RewardType::None, bool track_change = true) = 0;

	/// <summary>
	/// </summary>
	virtual EntityBase* give_named_item(const char* name) = 0;

	/// <summary>
	/// </summary>
	virtual EntityBase* give_named_item_ex(const char* name) = 0;

	/// <summary>
	/// </summary>
	virtual void give_default_items() = 0;

	/// <summary>
	/// </summary>
	virtual void give_shield(bool deploy = true) = 0;

	/// <summary>
	/// </summary>
	virtual void drop_shield(bool deploy = true) = 0;

	/// <summary>
	/// </summary>
	virtual void drop_player_item(const char* item_name) = 0;

	/// <summary>
	/// </summary>
	virtual bool remove_shield() = 0;

	/// <summary>
	/// </summary>
	virtual void remove_all_items(bool remove_suit) = 0;

	/// <summary>
	/// </summary>
	virtual bool remove_player_item(const char* item_name) = 0;

	/// <summary>
	/// </summary>
	virtual void set_player_model(bool has_c4) = 0;

	/// <summary>
	/// </summary>
	virtual void set_player_model_ex(const char* model_name) = 0;

	/// <summary>
	/// </summary>
	virtual void set_new_player_model(const char* model_name) = 0;

	/// <summary>
	/// </summary>
	virtual void client_command(const char* cmd, const char* arg1 = nullptr, const char* arg2 = nullptr, const char* arg3 = nullptr) = 0;

	/// <summary>
	/// </summary>
	virtual void set_progress_bar_time(int time) = 0;

	/// <summary>
	/// </summary>
	virtual void set_progress_bar_time2(int time, float time_elapsed) = 0;

	/// <summary>
	/// </summary>
	virtual struct edict_s* ent_select_spawn_point() = 0;

	/// <summary>
	/// </summary>
	virtual void set_bomb_icon(bool flash = false) = 0;

	/// <summary>
	/// </summary>
	virtual void set_score_attribute(PlayerBase* dest) = 0;

	/// <summary>
	/// </summary>
	virtual void send_item_status() = 0;

	/// <summary>
	/// </summary>
	virtual void reload_weapons(PlayerItemBase* weapon = nullptr, bool force_reload = false, bool force_refill = false) = 0;

	/// <summary>
	/// </summary>
	virtual void observer_set_mode(int mode) = 0;

	/// <summary>
	/// </summary>
	virtual bool select_spawn_spot(const char* ent_class_name, EntityBase*& spot) = 0;

	/// <summary>
	/// </summary>
	virtual bool switch_weapon(PlayerItemBase* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual void switch_team() = 0;

	/// <summary>
	/// </summary>
	virtual bool join_team(TeamName team) = 0;

	/// <summary>
	/// </summary>
	virtual void start_observer(Vector& position, Vector& view_angle) = 0;

	/// <summary>
	/// </summary>
	virtual void team_change_update() = 0;

	/// <summary>
	/// </summary>
	virtual void drop_secondary() = 0;

	/// <summary>
	/// </summary>
	virtual void drop_primary() = 0;

	/// <summary>
	/// </summary>
	virtual bool has_player_item(PlayerItemBase* check_item) = 0;

	/// <summary>
	/// </summary>
	virtual bool has_named_player_item(const char* item_name) = 0;

	/// <summary>
	/// </summary>
	virtual PlayerItemBase* get_item_by_id(WeaponId weapon) = 0;

	/// <summary>
	/// </summary>
	virtual PlayerItemBase* get_item_by_name(const char* item_name) = 0;

	/// <summary>
	/// </summary>
	virtual void disappear() = 0;

	/// <summary>
	/// </summary>
	virtual void make_vip() = 0;

	/// <summary>
	/// </summary>
	virtual bool make_bomber() = 0;

	/// <summary>
	/// </summary>
	virtual void reset_sequence_info() = 0;

	/// <summary>
	/// </summary>
	virtual void start_death_cam() = 0;

	/// <summary>
	/// </summary>
	virtual bool remove_player_item_ex(const char* item_name, bool remove_ammo) = 0;

	/// <summary>
	/// </summary>
	virtual void set_spawn_protection(float protection_time) = 0;

	/// <summary>
	/// </summary>
	virtual void remove_spawn_protection() = 0;

	/// <summary>
	/// </summary>
	virtual bool hint_message_ex(const char* message, float duration = 6.0f, bool display_if_player_dead = false, bool override = false) = 0;

	/// <summary>
	/// </summary>
	char model[32]{};

	/// <summary>
	/// </summary>
	bool force_show_menu{};

	/// <summary>
	/// </summary>
	float respawn_pending{};

	/// <summary>
	/// </summary>
	float spawn_protection_end_time{};

	/// <summary>
	/// </summary>
	Vector old_viewing_angle;

	/// <summary>
	/// </summary>
	WeaponInfiniteAmmoMode infinite_ammo_mode{};

	/// <summary>
	/// </summary>
	int weapon_infinite_ids{};

	/// <summary>
	/// </summary>
	bool can_shoot_override{};

	/// <summary>
	/// </summary>
	[[nodiscard]] PlayerBase* player_base() const
	{
		return reinterpret_cast<PlayerBase*>(this->containing_entity);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] ProtectionState protection_state() const
	{
		// No protection set.
		if (spawn_protection_end_time <= 0.0f)
			return ProtectionState::NoSet;

		// Check if end time of protection isn't expired yet.
		if (spawn_protection_end_time >= g_global_vars->time)
			return ProtectionState::Active;

		// Has expired.
		return ProtectionState::Expired;
	}
};
