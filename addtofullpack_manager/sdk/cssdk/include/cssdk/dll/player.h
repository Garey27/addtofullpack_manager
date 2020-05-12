// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/entity_base.h>
#include <cssdk/dll/hint_message.h>
#include <cssdk/dll/monster_base.h>
#include <cssdk/dll/player_consts.h>
#include <cssdk/dll/unified_signals.h>
#include <cssdk/dll/weapons.h>
#include <cssdk/pm_shared/pm_materials.h>
#include <cssdk/pm_shared/pm_shared.h>

#ifdef REGAMEDLL_API
/// <summary>
/// </summary>
class CsPlayer;
#endif

/// <summary>
/// Class StripWeapons.
/// </summary>
class StripWeapons : public EntityPoint {
public:
	/// <summary>
	/// </summary>
	void use(EntityBase* activator, EntityBase* caller, UseType type, float value) override = 0;
};

/// <summary>
/// Class DeadHev.
/// </summary>
class DeadHev : public MonsterBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	Classify classify() override = 0;

	/// <summary>
	/// <para>Which sequence to display -- temporary, don't need to save.</para>
	/// </summary>
	int pose;
};

/// <summary>
/// Class SprayCan.
/// </summary>
class SprayCan : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void think() override = 0;

	/// <summary>
	/// </summary>
	int object_caps() override = 0;
};

/// <summary>
/// Struct RebuyStruct
/// </summary>
struct RebuyStruct {
	/// <summary>
	/// </summary>
	WeaponId primary_weapon;

	/// <summary>
	/// </summary>
	int primary_ammo{};

	/// <summary>
	/// </summary>
	WeaponId secondary_weapon;

	/// <summary>
	/// </summary>
	int secondary_ammo{};

	/// <summary>
	/// </summary>
	int he_grenade{};

	/// <summary>
	/// </summary>
	int flash_bang{};

	/// <summary>
	/// </summary>
	int smoke_grenade{};

	/// <summary>
	/// </summary>
	qboolean defuser{};

	/// <summary>
	/// </summary>
	qboolean night_vision{};

	/// <summary>
	/// </summary>
	ArmorType armor;
};

/// <summary>
/// Class PlayerBase.
/// </summary>
class PlayerBase : public MonsterBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	int object_caps() override = 0;

	/// <summary>
	/// </summary>
	Classify classify() override = 0;

	/// <summary>
	/// </summary>
	void trace_attack(EntityVars* attacker, float damage, Vector direction, TraceResult* result, int damage_type) override = 0;

	/// <summary>
	/// </summary>
	qboolean take_damage(EntityVars* inflictor, EntityVars* attacker, float damage, int damage_type) override = 0;

	/// <summary>
	/// </summary>
	qboolean take_health(float health, int damage_type) override = 0;

	/// <summary>
	/// </summary>
	void killed(EntityVars* attacker, int gib) override = 0;

	/// <summary>
	/// </summary>
	void add_points(int score, qboolean allow_negative_score) override = 0;

	/// <summary>
	/// </summary>
	void add_points_to_team(int score, qboolean allow_negative_score) override = 0;

	/// <summary>
	/// </summary>
	qboolean add_player_item(PlayerItemBase* item) override = 0;

	/// <summary>
	/// </summary>
	qboolean remove_player_item(PlayerItemBase* item) override = 0;

	/// <summary>
	/// <para>Returns the unique ID for the ammo, or -1 if error.</para>
	/// </summary>
	int give_ammo(int amount, const char* name, int max = -1) override = 0;

#ifndef REGAMEDLL_API
	/// <summary>
	/// </summary>
	void start_sneaking() override = 0;

	/// <summary>
	/// </summary>
	void stop_sneaking() override = 0;
#else
	/// <summary>
	/// </summary>
	void on_create() override = 0;

	/// <summary>
	/// </summary>
	void on_destroy() override = 0;
#endif

	/// <summary>
	/// </summary>
	qboolean is_sneaking() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_alive() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_player() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_net_client() override = 0;

	/// <summary>
	/// </summary>
	const char* team_id() override = 0;

	/// <summary>
	/// </summary>
	qboolean become_prone() override = 0;

	/// <summary>
	/// </summary>
	Vector body_target(const Vector& src_pos) override = 0;

	/// <summary>
	/// </summary>
	int illumination() override = 0;

	/// <summary>
	/// </summary>
	qboolean should_fade_on_death() override = 0;

	/// <summary>
	/// </summary>
	void reset_max_speed() override = 0;

	/// <summary>
	/// </summary>
	virtual void jump() = 0;

	/// <summary>
	/// </summary>
	virtual void duck() = 0;

	/// <summary>
	/// </summary>
	virtual void pre_think() = 0;

	/// <summary>
	/// </summary>
	virtual void post_think() = 0;

	/// <summary>
	/// </summary>
	virtual Vector get_gun_position() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_bot() = 0;

	/// <summary>
	/// </summary>
	virtual void update_client_data() = 0;

	/// <summary>
	/// </summary>
	virtual void impulse_commands() = 0;

	/// <summary>
	/// </summary>
	virtual void round_respawn() = 0;

	/// <summary>
	/// </summary>
	virtual Vector get_auto_aim_vector(float delta) = 0;

	/// <summary>
	/// </summary>
	virtual void blind(float until_time, float hold_time, float fade_time, int alpha) = 0;

	/// <summary>
	/// </summary>
	virtual void on_touching_weapon(WeaponBox* weapon) = 0;

	/// <summary>
	/// </summary>
	int random_seed;

	/// <summary>
	/// </summary>
	unsigned short event_player_bleed;

	/// <summary>
	/// </summary>
	EntityHandle<PlayerBase> observer_target;

	/// <summary>
	/// </summary>
	float next_observer_input;

	/// <summary>
	/// </summary>
	WeaponId observer_weapon;

	/// <summary>
	/// </summary>
	int observer_c4_state;

	/// <summary>
	/// </summary>
	bool observer_has_defuser;

	/// <summary>
	/// </summary>
	ObserverMode observer_last_mode;

	/// <summary>
	/// </summary>
	float flinch_time;

	/// <summary>
	/// </summary>
	float anim_time;

	/// <summary>
	/// </summary>
	bool high_damage;

	/// <summary>
	/// </summary>
	float velocity_modifier;

	/// <summary>
	/// </summary>
	int last_zoom;

	/// <summary>
	/// </summary>
	bool resume_zoom;

	/// <summary>
	/// </summary>
	float eject_brass;

	/// <summary>
	/// </summary>
	ArmorType kevlar;

	/// <summary>
	/// </summary>
	bool not_killed;

	/// <summary>
	/// </summary>
	TeamName team;

	/// <summary>
	/// </summary>
	int account;

	/// <summary>
	/// </summary>
	bool has_primary;

	/// <summary>
	/// </summary>
	float death_throw_time;

	/// <summary>
	/// </summary>
	ThrowDirection throw_direction;

	/// <summary>
	/// </summary>
	float last_talk;

	/// <summary>
	/// </summary>
	bool just_connected;

	/// <summary>
	/// </summary>
	bool context_help;

	/// <summary>
	/// </summary>
	JoinState joining_state;

	/// <summary>
	/// </summary>
	EntityBase* intro_camera;

	/// <summary>
	/// </summary>
	float intro_cam_time;

	/// <summary>
	/// </summary>
	float last_movement;

	/// <summary>
	/// </summary>
	bool mission_briefing;

	/// <summary>
	/// </summary>
	bool team_changed;

	/// <summary>
	/// </summary>
	ModelName model_name;

	/// <summary>
	/// </summary>
	int team_kills;

	/// <summary>
	/// </summary>
	IgnoreChatMsg ignore_global_chat;

	/// <summary>
	/// </summary>
	bool has_night_vision;

	/// <summary>
	/// </summary>
	bool night_vision_on;

	/// <summary>
	/// </summary>
	Vector recent_path[MAX_RECENT_PATH];

	/// <summary>
	/// </summary>
	float idle_check_time;

	/// <summary>
	/// </summary>
	float radio_time;

	/// <summary>
	/// </summary>
	int radio_messages;

	/// <summary>
	/// </summary>
	bool ignore_radio;

	/// <summary>
	/// </summary>
	bool has_c4;

	/// <summary>
	/// </summary>
	bool has_defuser;

	/// <summary>
	/// </summary>
	bool killed_by_bomb;

	/// <summary>
	/// </summary>
	Vector blast_vector;

	/// <summary>
	/// </summary>
	bool killed_by_grenade;

	/// <summary>
	/// </summary>
	HintMessageQueue hint_message_queue;

	/// <summary>
	/// </summary>
	int display_history;

	/// <summary>
	/// </summary>
	MenuName menu;

	/// <summary>
	/// </summary>
	qboolean chase_target;

	/// <summary>
	/// </summary>
	EntityBase* chase_target_entity;

	/// <summary>
	/// </summary>
	float cam_switch;

	/// <summary>
	/// </summary>
	bool escaped;

	/// <summary>
	/// </summary>
	bool is_vip;

	/// <summary>
	/// </summary>
	float next_radar_update;

	/// <summary>
	/// </summary>
	Vector last_origin;

	/// <summary>
	/// </summary>
	int current_kick_vote;

	/// <summary>
	/// </summary>
	float next_vote_time;

	/// <summary>
	/// </summary>
	bool just_killed_teammate;

	/// <summary>
	/// </summary>
	int hostages_killed;

	/// <summary>
	/// </summary>
	int map_vote;

	/// <summary>
	/// </summary>
	bool can_shoot;

	/// <summary>
	/// </summary>
	float last_fired;

	/// <summary>
	/// </summary>
	float last_attacked_teammate;

	/// <summary>
	/// </summary>
	bool headshot_killed;

	/// <summary>
	/// </summary>
	bool punished_for_tk;

	/// <summary>
	/// </summary>
	bool receives_no_money_next_round;

	/// <summary>
	/// </summary>
	int time_check_allowed;

	/// <summary>
	/// </summary>
	bool has_changed_name;

	/// <summary>
	/// </summary>
	char new_name[MAX_PLAYER_NAME_LENGTH];

	/// <summary>
	/// </summary>
	bool is_defusing;

	/// <summary>
	/// </summary>
	float handle_signals;

	/// <summary>
	/// </summary>
	UnifiedSignals signals;

	/// <summary>
	/// </summary>
	Edict* cur_bomb_target;

	/// <summary>
	/// </summary>
	int player_sound;

	/// <summary>
	/// </summary>
	int target_volume;

	/// <summary>
	/// </summary>
	int weapon_volume;

	/// <summary>
	/// </summary>
	int extra_sound_types;

	/// <summary>
	/// </summary>
	int weapon_flash;

	/// <summary>
	/// </summary>
	float stop_extra_sound_time;

	/// <summary>
	/// </summary>
	float flash_light_time;

	/// <summary>
	/// </summary>
	int flash_battery;

	/// <summary>
	/// </summary>
	int button_last;

	/// <summary>
	/// </summary>
	int button_pressed;

	/// <summary>
	/// </summary>
	int button_released;

	/// <summary>
	/// </summary>
	Edict* snd_last;

	/// <summary>
	/// </summary>
	float snd_room_type;

	/// <summary>
	/// </summary>
	float snd_range;

	/// <summary>
	/// </summary>
	float fall_velocity;

	/// <summary>
	/// </summary>
	int items[MAX_ITEMS];

	/// <summary>
	/// </summary>
	int new_ammo;

	/// <summary>
	/// </summary>
	unsigned int physics_flags;

	/// <summary>
	/// </summary>
	float next_suicide_time;

	/// <summary>
	/// </summary>
	float time_step_sound;

	/// <summary>
	/// </summary>
	float time_weapon_idle;

	/// <summary>
	/// </summary>
	float swim_time;

	/// <summary>
	/// </summary>
	float duck_time;

	/// <summary>
	/// </summary>
	float wall_jump_time;

	/// <summary>
	/// </summary>
	float suit_update;

	/// <summary>
	/// </summary>
	int suit_play_list[MAX_SUIT_PLAYLIST];

	/// <summary>
	/// </summary>
	int suit_play_next;

	/// <summary>
	/// </summary>
	int suit_no_repeat[MAX_SUIT_NO_REPEAT];

	/// <summary>
	/// </summary>
	float suit_no_repeat_time[MAX_SUIT_NO_REPEAT];

	/// <summary>
	/// </summary>
	int last_damage_amount;

	/// <summary>
	/// </summary>
	float time_based_damage_prev;

	/// <summary>
	/// </summary>
	float geiger_range;

	/// <summary>
	/// </summary>
	float geiger_delay;

	/// <summary>
	/// </summary>
	int geiger_range_prev;

	/// <summary>
	/// </summary>
	int step_left;

	/// <summary>
	/// </summary>
	char texture_name[MAX_TEXTURE_NAME_LENGTH];

	/// <summary>
	/// </summary>
	char texture_type;

	/// <summary>
	/// </summary>
	int drown_dmg;

	/// <summary>
	/// </summary>
	int drown_restored;

	/// <summary>
	/// </summary>
	int hud_damage;

	/// <summary>
	/// </summary>
	qboolean init_hud;

	/// <summary>
	/// </summary>
	qboolean game_hud_initialized;

	/// <summary>
	/// </summary>
	int train;

	/// <summary>
	/// </summary>
	qboolean weapon;

	/// <summary>
	/// </summary>
	EntityHandle<> tank;

	/// <summary>
	/// </summary>
	float dead_time;

	/// <summary>
	/// </summary>
	qboolean no_player_sound;

	/// <summary>
	/// </summary>
	qboolean long_jump;

	/// <summary>
	/// </summary>
	float sneaking;

	/// <summary>
	/// </summary>
	int update_time;

	/// <summary>
	/// </summary>
	int client_health;

	/// <summary>
	/// </summary>
	int client_battery;

	/// <summary>
	/// </summary>
	int hide_hud;

	/// <summary>
	/// </summary>
	int client_hide_hud;

	/// <summary>
	/// </summary>
	int fov;

	/// <summary>
	/// </summary>
	int client_fov;

	/// <summary>
	/// </summary>
	int num_spawns;

	/// <summary>
	/// </summary>
	EntityBase* observer;

	/// <summary>
	/// </summary>
	PlayerItemBase* player_items[MAX_ITEM_TYPES];

	/// <summary>
	/// </summary>
	PlayerItemBase* active_item;

	/// <summary>
	/// </summary>
	PlayerItemBase* client_active_item;

	/// <summary>
	/// </summary>
	PlayerItemBase* last_item;

	/// <summary>
	/// </summary>
	int ammo[MAX_AMMO_SLOTS];

	/// <summary>
	/// </summary>
	int ammo_last[MAX_AMMO_SLOTS];

	/// <summary>
	/// </summary>
	Vector auto_aim;

	/// <summary>
	/// </summary>
	qboolean on_target;

	/// <summary>
	/// </summary>
	int deaths;

	/// <summary>
	/// </summary>
	int sbar_state[static_cast<int>(SBarData::End)];

	/// <summary>
	/// </summary>
	float next_sbar_update_time;

	/// <summary>
	/// </summary>
	float status_bar_disappear_delay;

	/// <summary>
	/// </summary>
	char sbar_string0[MAX_SBAR_STRING];

	/// <summary>
	/// </summary>
	int last_x;

	/// <summary>
	/// </summary>
	int last_y;

	/// <summary>
	/// </summary>
	int custom_spray_frames;

	/// <summary>
	/// </summary>
	float next_decal_time;

	/// <summary>
	/// </summary>
	char team_name_string[MAX_TEAM_NAME_LENGTH];

	/// <summary>
	/// </summary>
	int model_index_player;

	/// <summary>
	/// </summary>
	char anim_extension[32];

	/// <summary>
	/// </summary>
	int gait_sequence;

	/// <summary>
	/// </summary>
	float gait_frame;

	/// <summary>
	/// </summary>
	float gait_yaw;

	/// <summary>
	/// </summary>
	Vector prev_gait_origin;

	/// <summary>
	/// </summary>
	float pitch;

	/// <summary>
	/// </summary>
	float yaw;

	/// <summary>
	/// </summary>
	float gait_movement;

	/// <summary>
	/// </summary>
	int auto_wep_switch;

	/// <summary>
	/// </summary>
	bool vgui_menus;

	/// <summary>
	/// </summary>
	bool show_hints;

	/// <summary>
	/// </summary>
	bool shield_drawn;

	/// <summary>
	/// </summary>
	bool owns_shield;

	/// <summary>
	/// </summary>
	bool was_following;

	/// <summary>
	/// </summary>
	float next_follow_time;

	/// <summary>
	/// </summary>
	float yaw_modifier;

	/// <summary>
	/// </summary>
	float blind_until_time;

	/// <summary>
	/// </summary>
	float blind_start_time;

	/// <summary>
	/// </summary>
	float blind_hold_time;

	/// <summary>
	/// </summary>
	float blind_fade_time;

	/// <summary>
	/// </summary>
	int blind_alpha;

	/// <summary>
	/// </summary>
	float allow_auto_follow_time;

	/// <summary>
	/// </summary>
	char auto_buy_string[MAX_AUTO_BUY_LENGTH];

	/// <summary>
	/// </summary>
	char* rebuy_string;

	/// <summary>
	/// </summary>
	RebuyStruct rebuy_struct;

	/// <summary>
	/// </summary>
	bool is_in_rebuy;

	/// <summary>
	/// </summary>
	float last_update_time;

	/// <summary>
	/// </summary>
	char last_location[MAX_LOCATION_LEN];

	/// <summary>
	/// </summary>
	float progress_start;

	/// <summary>
	/// </summary>
	float progress_end;

	/// <summary>
	/// </summary>
	bool observer_auto_director;

	/// <summary>
	/// </summary>
	bool can_switch_observer_modes;

	/// <summary>
	/// </summary>
	float heart_beat_time;

	/// <summary>
	/// </summary>
	float intense_timestamp;

	/// <summary>
	/// </summary>
	float silent_timestamp;

	/// <summary>
	/// </summary>
	MusicState music_state;

	/// <summary>
	/// </summary>
	float last_command_time[static_cast<int>(TrackCommands::CommandsToTrack)];

	/// <summary>
	/// </summary>
	int last_account;

	/// <summary>
	/// </summary>
	int last_client_health;

	/// <summary>
	/// </summary>
	float next_account_health_update;

#ifdef REGAMEDLL_API
	/// <summary>
	/// </summary>
	[[nodiscard]] CsPlayer* cs_player() const
	{
		return reinterpret_cast<CsPlayer*>(this->entity);
	}
#endif

	/// <summary>
	/// </summary>
	template <typename T = PlayerItemBase, typename Functor>
	T* for_each_item(const InventorySlot slot, const Functor& func) const
	{
		auto item = player_items[static_cast<int>(slot)];

		while (item) {
			if (func(static_cast<T*>(item)))
				return static_cast<T*>(item);

			item = item->next;
		}

		return nullptr;
	}

	/// <summary>
	/// </summary>
	template <typename T = PlayerItemBase, typename Functor>
	T* for_each_item(const Functor& func) const
	{
		for (auto item : player_items) {
			while (item) {
				if (func(static_cast<T*>(item)))
					return static_cast<T*>(item);

				item = item->next;
			}
		}

		return nullptr;
	}

	/// <summary>
	/// </summary>
	template <typename T = PlayerItemBase, typename Functor>
	T* for_each_item(const char* item_name, const Functor& func) const
	{
		if (!item_name)
			return nullptr;

		for (auto item : player_items) {
			while (item) {
				if (item->vars->class_name == item_name && func(static_cast<T*>(item)))
					return static_cast<T*>(item);

				item = item->next;
			}
		}

		return nullptr;
	}
};
