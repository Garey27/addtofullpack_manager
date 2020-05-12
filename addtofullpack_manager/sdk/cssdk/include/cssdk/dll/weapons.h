// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/cdll_dll.h>
#include <cssdk/dll/entity_base.h>
#include <cssdk/dll/monster_base.h>
#include <cssdk/dll/weapon_type.h>

/// <summary>
/// </summary>
class PlayerBase;

#ifdef REGAMEDLL_API
/// <summary>
/// </summary>
class CsPlayerItem;

/// <summary>
/// </summary>
class CsPlayerWeapon;
#endif

/// <summary>
/// </summary>
constexpr auto MAX_NORMAL_BATTERY = 100.0f;

/// <summary>
/// </summary>
constexpr auto MAX_DIST_RELOAD_SOUND = 512.0f;

/// <summary>
/// </summary>
constexpr auto MAX_WEAPONS = 32;

/// <summary>
/// </summary>
constexpr auto ITEM_FLAG_SELECT_ON_EMPTY = 1;

/// <summary>
/// </summary>
constexpr auto ITEM_FLAG_NO_AUTO_RELOAD = 2;

/// <summary>
/// </summary>
constexpr auto ITEM_FLAG_NO_AUTO_SWITCH_EMPTY = 4;

/// <summary>
/// </summary>
constexpr auto ITEM_FLAG_LIMIT_IN_WORLD = 8;

/// <summary>
/// <para>A player can totally exhaust their ammo supply and lose this weapon.</para>
/// </summary>
constexpr auto ITEM_FLAG_EXHAUSTIBLE = 16;

/// <summary>
/// </summary>
constexpr auto WEAPON_IS_ON_TARGET = 0x40;

/// <summary>
/// <para>The maximum amount of ammo each weapon's clip can hold.</para>
/// </summary>
constexpr auto WEAPON_NO_CLIP = -1;

/// <summary>
/// </summary>
constexpr auto LOUD_GUN_VOLUME = 1000;

/// <summary>
/// </summary>
constexpr auto NORMAL_GUN_VOLUME = 600;

/// <summary>
/// </summary>
constexpr auto QUIET_GUN_VOLUME = 200;

/// <summary>
/// </summary>
constexpr auto BRIGHT_GUN_FLASH = 512;

/// <summary>
/// </summary>
constexpr auto NORMAL_GUN_FLASH = 256;

/// <summary>
/// </summary>
constexpr auto DIM_GUN_FLASH = 128;

/// <summary>
/// </summary>
constexpr auto BIG_EXPLOSION_VOLUME = 2048;

/// <summary>
/// </summary>
constexpr auto NORMAL_EXPLOSION_VOLUME = 1024;

/// <summary>
/// </summary>
constexpr auto SMALL_EXPLOSION_VOLUME = 512;

/// <summary>
/// </summary>
constexpr auto WEAPON_ACTIVITY_VOLUME = 64;

/// <summary>
/// <para>Grenades flagged with this will be triggered when the owner calls <c>detonate_satchel_charges</c>.</para>
/// </summary>
constexpr auto SF_DETONATE = 1 << 0;

/// <summary>
/// Enum ArmorType
/// </summary>
enum class ArmorType {
	/// <summary>
	/// <para>No armor.</para>
	/// </summary>
	None = 0,

	/// <summary>
	/// <para>Body vest only.</para>
	/// </summary>
	Kevlar,

	/// <summary>
	/// <para>Vest and helmet.</para>
	/// </summary>
	VestHelm
};

/// <summary>
/// Enum ArmouryItemPack
/// </summary>
enum class ArmouryItemPack {
	/// <summary>
	/// </summary>
	Mp5Navy = 0,

	/// <summary>
	/// </summary>
	Tmp,

	/// <summary>
	/// </summary>
	P90,

	/// <summary>
	/// </summary>
	Mac10,

	/// <summary>
	/// </summary>
	Ak47,

	/// <summary>
	/// </summary>
	Sg552,

	/// <summary>
	/// </summary>
	M4A1,

	/// <summary>
	/// </summary>
	Aug,

	/// <summary>
	/// </summary>
	Scout,

	/// <summary>
	/// </summary>
	G3Sg1,

	/// <summary>
	/// </summary>
	Awp,

	/// <summary>
	/// </summary>
	M3,

	/// <summary>
	/// </summary>
	Xm1014,

	/// <summary>
	/// </summary>
	M249,

	/// <summary>
	/// </summary>
	FlashBang,

	/// <summary>
	/// </summary>
	HeGrenade,

	/// <summary>
	/// </summary>
	Kevlar,

	/// <summary>
	/// </summary>
	Assault,

	/// <summary>
	/// </summary>
	SmokeGrenade,

	/// <summary>
	/// </summary>
	Shield,

	/// <summary>
	/// </summary>
	Famas,

	/// <summary>
	/// </summary>
	Sg550,

	/// <summary>
	/// </summary>
	Galil,

	/// <summary>
	/// </summary>
	Ump45,

	/// <summary>
	/// </summary>
	Glock18,

	/// <summary>
	/// </summary>
	Usp,

	/// <summary>
	/// </summary>
	Elite,

	/// <summary>
	/// </summary>
	Fiveseven,

	/// <summary>
	/// </summary>
	P228,

	/// <summary>
	/// </summary>
	Deagle
};

/// <summary>
/// Struct ItemInfo
/// </summary>
struct ItemInfo {
	/// <summary>
	/// </summary>
	InventorySlot slot{};

	/// <summary>
	/// </summary>
	int position{};

	/// <summary>
	/// </summary>
	const char* ammo1{};

	/// <summary>
	/// </summary>
	int max_ammo1{};

	/// <summary>
	/// </summary>
	const char* ammo2{};

	/// <summary>
	/// </summary>
	int max_ammo2{};

	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	int max_clip{};

	/// <summary>
	/// </summary>
	WeaponId id{};

	/// <summary>
	/// </summary>
	int flags{};

	/// <summary>
	/// </summary>
	int weight{};
};

/// <summary>
/// Struct AmmoInfo
/// </summary>
struct AmmoInfo {
	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// </summary>
	int id{};
};

/// <summary>
/// Struct MultiDamage
/// </summary>
struct MultiDamage {
	/// <summary>
	/// </summary>
	EntityBase* entity{};

	/// <summary>
	/// </summary>
	float amount{};

	/// <summary>
	/// </summary>
	int type{};
};

//
// Armoury.
//

/// <summary>
/// Class Armoury.
/// </summary>
class Armoury : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	void restart() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

#ifdef REGAMEDLL_FIXES
	/// <summary>
	/// <para>Setup the object->object collision box (<c>EntityVars->min_size / EntityVars->max_size</c> is the <c>object->world</c> collision box).</para>
	/// </summary>
	void set_object_collision_box() override = 0;
#endif

	/// <summary>
	/// </summary>
	ArmouryItemPack item;

	/// <summary>
	/// </summary>
	int count{};

	/// <summary>
	/// </summary>
	int initial_count{};

	/// <summary>
	/// </summary>
	bool already_counted{};
};

//
// Grenade.
//

/// <summary>
/// Enum SatchelCode
/// </summary>
enum class SatchelCode {
	Detonate = 0,
	Release
};

/// <summary>
/// Class Grenade.
/// </summary>
class Grenade : public MonsterBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

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
	void killed(EntityVars* attacker, int gib) override = 0;

	/// <summary>
	/// </summary>
	int blood_color() override = 0;

	/// <summary>
	/// </summary>
	void use(EntityBase* activator, EntityBase* caller, UseType type, float value) override = 0;

	/// <summary>
	/// </summary>
	virtual void bounce_sound() = 0;

	/// <summary>
	/// </summary>
	bool start_defuse;

	/// <summary>
	/// </summary>
	bool is_c4;

	/// <summary>
	/// </summary>
	EntityHandle<PlayerBase> bomb_defuser;

	/// <summary>
	/// </summary>
	float defuse_count_down;

	/// <summary>
	/// </summary>
	float c4_blow;

	/// <summary>
	/// </summary>
	float next_freq_interval;

	/// <summary>
	/// </summary>
	float next_beep;

	/// <summary>
	/// </summary>
	float next_freq;

	/// <summary>
	/// </summary>
	char* beep_name;

	/// <summary>
	/// </summary>
	float attenuation;

	/// <summary>
	/// </summary>
	float next_blink;

	/// <summary>
	/// </summary>
	float next_defuse;

	/// <summary>
	/// </summary>
	bool just_blew;

	/// <summary>
	/// </summary>
	TeamName team;

	/// <summary>
	/// </summary>
	int cur_wave;

	/// <summary>
	/// </summary>
	Edict* cur_bomb_target;

	/// <summary>
	/// </summary>
	int sg_smoke;

	/// <summary>
	/// </summary>
	int angle;

	/// <summary>
	/// </summary>
	unsigned short event;

	/// <summary>
	/// </summary>
	bool light_smoke;

	/// <summary>
	/// </summary>
	bool detonated;

	/// <summary>
	/// </summary>
	Vector smoke_detonate;

	/// <summary>
	/// </summary>
	int bounce_count;

	/// <summary>
	/// </summary>
	qboolean registered_sound;
};

//
// Player item base.
//

/// <summary>
/// <para>Items that the player has in their inventory that they can use.</para>
/// </summary>
class PlayerItemBase : public AnimatingBase {
public:
	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	void set_object_collision_box() override = 0;

	/// <summary>
	/// </summary>
	EntityBase* respawn() override = 0;

	/// <summary>
	/// <para>Return true if the item you want the item added to the player inventory.</para>
	/// </summary>
	virtual qboolean add_to_player(PlayerBase* player) = 0;

	/// <summary>
	/// <para>Return true if you want your duplicate removed from world.</para>
	/// </summary>
	virtual qboolean add_duplicate(PlayerItemBase* item) = 0;

	/// <summary>
	/// <para>Returns false if struct not filled out.</para>
	/// </summary>
	virtual qboolean get_item_info(ItemInfo* info) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean can_deploy() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean can_drop() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean deploy() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_weapon() = 0;

	/// <summary>
	/// <para>Can this weapon be put away right now?.</para>
	/// </summary>
	virtual qboolean can_holster() = 0;

	/// <summary>
	/// </summary>
	virtual void holster(qboolean skip_local = false) = 0;

	/// <summary>
	/// </summary>
	virtual void update_item_info() = 0;

	/// <summary>
	/// <para>Called each frame by the player <c>pre_think</c>.</para>
	/// </summary>
	virtual void item_pre_frame() = 0;

	/// <summary>
	/// <para>Called each frame by the player <c>post_think</c>.</para>
	/// </summary>
	virtual void item_post_frame() = 0;

	/// <summary>
	/// </summary>
	virtual void drop() = 0;

	/// <summary>
	/// </summary>
	virtual void kill() = 0;

	/// <summary>
	/// </summary>
	virtual void attach_to_player(PlayerBase* player) = 0;

	/// <summary>
	/// </summary>
	virtual int primary_ammo_index() = 0;

	/// <summary>
	/// </summary>
	virtual int secondary_ammo_index() = 0;

	/// <summary>
	/// </summary>
	virtual int update_client_data(PlayerBase* player) = 0;

	/// <summary>
	/// </summary>
	virtual PlayerItemBase* get_weapon_ptr() = 0;

	/// <summary>
	/// </summary>
	virtual float get_max_speed() = 0;

	/// <summary>
	/// </summary>
	virtual InventorySlot item_slot() = 0;

	/// <summary>
	/// </summary>
	PlayerBase* player{};

	/// <summary>
	/// </summary>
	PlayerItemBase* next{};

	/// <summary>
	/// </summary>
	WeaponId id;

#ifdef REGAMEDLL_API
	/// <summary>
	/// </summary>
	[[nodiscard]] CsPlayerItem* cs_player_item() const
	{
		return reinterpret_cast<CsPlayerItem*>(this->entity);
	}
#endif
};

//
// Player weapon base.
//

/// <summary>
/// Class PlayerWeaponBase.
/// </summary>
class PlayerWeaponBase : public PlayerItemBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	qboolean add_to_player(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	qboolean add_duplicate(PlayerItemBase* item) override = 0;

	/// <summary>
	/// </summary>
	qboolean can_deploy() override = 0;

	/// <summary>
	/// </summary>
	qboolean is_weapon() override = 0;

	/// <summary>
	/// </summary>
	void holster(qboolean skip_local = false) override = 0;

	/// <summary>
	/// </summary>
	void update_item_info() override = 0;

	/// <summary>
	/// </summary>
	void item_post_frame() override = 0;

	/// <summary>
	/// </summary>
	int primary_ammo_index() override = 0;

	/// <summary>
	/// </summary>
	int secondary_ammo_index() override = 0;

	/// <summary>
	/// </summary>
	int update_client_data(PlayerBase* player) override = 0;

	/// <summary>
	/// </summary>
	PlayerItemBase* get_weapon_ptr() override = 0;

	/// <summary>
	/// </summary>
	virtual int extract_ammo(PlayerWeaponBase* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual int extract_clip_ammo(PlayerWeaponBase* weapon) = 0;

	/// <summary>
	/// </summary>
	virtual int add_weapon() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean play_empty_sound() = 0;

	/// <summary>
	/// </summary>
	virtual void reset_empty_sound() = 0;

	/// <summary>
	/// </summary>
	virtual void send_weapon_anim(int anim, qboolean skip_local = false) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_useable() = 0;

	/// <summary>
	/// </summary>
	virtual void primary_attack() = 0;

	/// <summary>
	/// </summary>
	virtual void secondary_attack() = 0;

	/// <summary>
	/// </summary>
	virtual void reload() = 0;

	/// <summary>
	/// </summary>
	virtual void weapon_idle() = 0;

	/// <summary>
	/// </summary>
	virtual void retire_weapon() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean should_weapon_idle() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean use_decrement() = 0;

	/// <summary>
	/// </summary>
	qboolean can_play_empty_sound{};

	/// <summary>
	/// </summary>
	qboolean fire_on_empty{};

	/// <summary>
	/// <para>Soonest time ItemPostFrame will call <c>primary_attack</c>.</para>
	/// </summary>
	float next_primary_attack{};

	/// <summary>
	/// <para>Soonest time ItemPostFrame will call <c>secondary_attack</c>.</para>
	/// </summary>
	float next_secondary_attack{};

	/// <summary>
	/// <para>Soonest time ItemPostFrame will call <c>weapon_idle</c>.</para>
	/// </summary>
	float time_weapon_idle{};

	/// <summary>
	/// <para>Primary ammo index into players <c>rg_ammo[]</c>.</para>
	/// </summary>
	int primary_ammo_type{};

	/// <summary>
	/// <para>Secondary ammo index into players <c>rg_ammo[]</c>.</para>
	/// </summary>
	int secondary_ammo_type{};

	/// <summary>
	/// <para>Number of shots left in the primary weapon clip, -1 it not used.</para>
	/// </summary>
	int clip{};

	/// <summary>
	/// <para>The last version of <c>clip</c> sent to hud dll.</para>
	/// </summary>
	int client_clip{};

	/// <summary>
	/// <para>The last version of the weapon state sent to hud dll (is current weapon, is on target).</para>
	/// </summary>
	int client_weapon_state{};

	/// <summary>
	/// <para>Are we in the middle of a reload;.</para>
	/// </summary>
	qboolean in_reload{};

	/// <summary>
	/// <para>Are we in the middle of a reload for the shotguns.</para>
	/// </summary>
	qboolean in_special_reload{};

	/// <summary>
	/// <para>How much ammo you get when you pick up this weapon as placed by a level designer.</para>
	/// </summary>
	int default_ammo{};

	/// <summary>
	/// </summary>
	int shell_id{};

	/// <summary>
	/// </summary>
	float max_speed{};

	/// <summary>
	/// </summary>
	bool delay_fire{};

	/// <summary>
	/// </summary>
	qboolean direction{};

	/// <summary>
	/// </summary>
	bool secondary_silencer_on{};

	/// <summary>
	/// </summary>
	float accuracy{};

	/// <summary>
	/// </summary>
	float last_fire{};

	/// <summary>
	/// </summary>
	int shots_fired{};

	/// <summary>
	/// </summary>
	Vector aiming;

	/// <summary>
	/// </summary>
	Strind model_name;

	/// <summary>
	/// <para>Time to shoot the remaining bullets of the Glock18 burst fire.</para>
	/// </summary>
	float glock18_shoot{};

	/// <summary>
	/// <para>Used to keep track of the shots fired during the Glock18 burst fire mode.</para>
	/// </summary>
	int glock18_shots_fired{};

	/// <summary>
	/// <para>Time to shoot the remaining bullets of the Famas burst fire.</para>
	/// </summary>
	float famas_shoot{};

	/// <summary>
	/// <para>Used to keep track of the shots fired during the Famas burst fire mode.</para>
	/// </summary>
	int famas_shots_fired{};

	/// <summary>
	/// </summary>
	float burst_spread{};

	/// <summary>
	/// </summary>
	int weapon_state{};

	/// <summary>
	/// </summary>
	float next_reload{};

	/// <summary>
	/// </summary>
	float decrease_shots_fired{};

	/// <summary>
	/// </summary>
	unsigned short event_fire_glock18{};

	/// <summary>
	/// </summary>
	unsigned short event_fire_famas{};

	/// <summary>
	/// </summary>
	float prev_primary_attack{};

	/// <summary>
	/// </summary>
	float last_fire_time{};

#ifdef REGAMEDLL_API
	/// <summary>
	/// </summary>
	[[nodiscard]] CsPlayerWeapon* cs_player_weapon() const
	{
		return reinterpret_cast<CsPlayerWeapon*>(this->entity);
	}
#endif
};

//
// Weapon box.
//

/// <summary>
/// Class WeaponBox.
/// </summary>
class WeaponBox : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	int save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	int restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	void set_object_collision_box() override = 0;

	/// <summary>
	/// </summary>
	void touch(EntityBase* other) override = 0;

	/// <summary>
	/// </summary>
	PlayerItemBase* player_items[MAX_ITEM_TYPES]{};

	/// <summary>
	/// </summary>
	Strind ammo_names[MAX_AMMO_SLOTS]{};

	/// <summary>
	/// </summary>
	int ammo_count[MAX_AMMO_SLOTS]{};

	/// <summary>
	/// </summary>
	int ammo_types{};

	/// <summary>
	/// </summary>
	bool is_bomb{};
};

//
// USP.
//

/// <summary>
/// </summary>
constexpr auto USP_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto USP_DAMAGE = 34.0f;

/// <summary>
/// </summary>
constexpr auto USP_DAMAGE_SIL = 30.0f;

/// <summary>
/// </summary>
constexpr auto USP_RANGE_MODIFER = 0.79f;

/// <summary>
/// </summary>
constexpr auto USP_RELOAD_TIME = 2.7f;

#ifdef REGAMEDLL_FIXES
/// <summary>
/// </summary>
constexpr auto USP_ADJUST_SIL_TIME = 3.13f;
#else
/// <summary>
/// </summary>
constexpr auto USP_ADJUST_SIL_TIME = 3.0f;
#endif

/// <summary>
/// Enum UspAnimSeq
/// </summary>
enum class UspAnimSeq {
	/// <summary>
	/// </summary>
	Idle = 0,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	AttachSilencer,

	/// <summary>
	/// </summary>
	UnsilIdle,

	/// <summary>
	/// </summary>
	UnsilShoot1,

	/// <summary>
	/// </summary>
	UnsilShoot2,

	/// <summary>
	/// </summary>
	UnsilShoot3,

	/// <summary>
	/// </summary>
	UnsilShootEmpty,

	/// <summary>
	/// </summary>
	UnsilReload,

	/// <summary>
	/// </summary>
	UnsilDraw,

	/// <summary>
	/// </summary>
	DetachSilencer
};

/// <summary>
/// Enum UspShieldAnimSeq
/// </summary>
enum class UspShieldAnimSeq {
	/// <summary>
	/// </summary>
	ShieldIdle = 0,

	/// <summary>
	/// </summary>
	ShieldShoot1,

	/// <summary>
	/// </summary>
	ShieldShoot2,

	/// <summary>
	/// </summary>
	ShieldShootEmpty,

	/// <summary>
	/// </summary>
	ShieldReload,

	/// <summary>
	/// </summary>
	ShieldDraw,

	/// <summary>
	/// </summary>
	ShieldUpIdle,

	/// <summary>
	/// </summary>
	ShieldUp,

	/// <summary>
	/// </summary>
	ShieldDown
};

/// <summary>
/// Class Usp.
/// </summary>
class Usp : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// MP5Navy.
//

/// <summary>
/// </summary>
constexpr auto MP5N_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto MP5N_DAMAGE = 26.0f;

/// <summary>
/// </summary>
constexpr auto MP5N_RANGE_MODIFER = 0.84f;

/// <summary>
/// </summary>
constexpr auto MP5N_RELOAD_TIME = 2.63f;

/// <summary>
/// Enum Mp5NavyAnimSeq
/// </summary>
enum class Mp5NavyAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Mp5Navy.
/// </summary>
class Mp5Navy : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// SG552.
//

/// <summary>
/// </summary>
constexpr auto SG552_MAX_SPEED = 235.0f;

/// <summary>
/// </summary>
constexpr auto SG552_MAX_SPEED_ZOOM = 200.0f;

/// <summary>
/// </summary>
constexpr auto SG552_DAMAGE = 33.0f;

/// <summary>
/// </summary>
constexpr auto SG552_RANGE_MODIFER = 0.955f;

/// <summary>
/// </summary>
constexpr auto SG552_RELOAD_TIME = 3.0f;

/// <summary>
/// Enum Sg552AnimSeq
/// </summary>
enum class Sg552AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Sg552.
/// </summary>
class Sg552 : public PlayerWeaponBase {
public:

	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// AK47.
//

/// <summary>
/// </summary>
constexpr auto AK47_MAX_SPEED = 221.0f;

/// <summary>
/// </summary>
constexpr auto AK47_DAMAGE = 36.0f;

/// <summary>
/// </summary>
constexpr auto AK47_RANGE_MODIFER = 0.98f;

/// <summary>
/// </summary>
constexpr auto AK47_RELOAD_TIME = 2.45f;

/// <summary>
/// Enum Ak47AnimSeq
/// </summary>
enum class Ak47AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Ak47.
/// </summary>
class Ak47 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// AUG.
//

/// <summary>
/// </summary>
constexpr auto AUG_MAX_SPEED = 240.0f;

/// <summary>
/// </summary>
constexpr auto AUG_DAMAGE = 32.0f;

/// <summary>
/// </summary>
constexpr auto AUG_RANGE_MODIFER = 0.96f;

/// <summary>
/// </summary>
constexpr auto AUG_RELOAD_TIME = 3.3f;

/// <summary>
/// Enum AugAnimSeq
/// </summary>
enum class AugAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Aug.
/// </summary>
class Aug : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// AWP.
//

/// <summary>
/// </summary>
constexpr auto AWP_MAX_SPEED = 210.0f;

/// <summary>
/// </summary>
constexpr auto AWP_MAX_SPEED_ZOOM = 150.0f;

/// <summary>
/// </summary>
constexpr auto AWP_DAMAGE = 115.0f;

/// <summary>
/// </summary>
constexpr auto AWP_RANGE_MODIFER = 0.99f;

/// <summary>
/// </summary>
constexpr auto AWP_RELOAD_TIME = 2.5f;

/// <summary>
/// Enum AwpAnimSeq
/// </summary>
enum class AwpAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class Awp.
/// </summary>
class Awp : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// C4.
//

/// <summary>
/// <para>If the bomb was dropped due to voluntary dropping or death/disconnect.</para>
/// </summary>
constexpr auto BOMB_FLAG_DROPPED = 0;

/// <summary>
/// <para>If the bomb has been planted will also trigger the round timer to hide will also show where the dropped bomb on the Terrorist team's radar.</para>
/// </summary>
constexpr auto BOMB_FLAG_PLANTED = 1;

/// <summary>
/// </summary>
constexpr auto C4_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto C4_ARMING_ON_TIME = 3.0f;

/// <summary>
/// Enum C4AnimSeq
/// </summary>
enum class C4AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Drop,

	/// <summary>
	/// </summary>
	Arm
};

/// <summary>
/// Class C4.
/// </summary>
class C4 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	void use(EntityBase* activator, EntityBase* caller, UseType type, float value) override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	void holster(qboolean skip_local) override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	bool started_arming{};

	/// <summary>
	/// </summary>
	bool bomb_placed_animation{};

	/// <summary>
	/// </summary>
	float armed_time{};
};

//
// Deagle.
//

/// <summary>
/// </summary>
constexpr auto DEAGLE_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto DEAGLE_DAMAGE = 54.0f;

/// <summary>
/// </summary>
constexpr auto DEAGLE_RANGE_MODIFER = 0.81f;

/// <summary>
/// </summary>
constexpr auto DEAGLE_RELOAD_TIME = 2.2f;

/// <summary>
/// Enum DeagleAnimSeq
/// </summary>
enum class DeagleAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class Deagle.
/// </summary>
class Deagle : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// Flash bang.
//

/// <summary>
/// </summary>
constexpr auto FLASH_BANG_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto FLASH_BANG_MAX_SPEED_SHIELD = 180.0f;

/// <summary>
/// Enum FlashBangAnimSeq
/// </summary>
enum class FlashBangAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	PullPin,

	/// <summary>
	/// </summary>
	ThrowGrenade,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class FlashBang.
/// </summary>
class FlashBang : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean can_deploy() override = 0;

	/// <summary>
	/// </summary>
	qboolean can_drop() override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	void holster(qboolean skip_local) override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;
};

//
// G3SG1.
//

/// <summary>
/// </summary>
constexpr auto G3SG1_MAX_SPEED = 210.0f;

/// <summary>
/// </summary>
constexpr auto G3SG1_MAX_SPEED_ZOOM = 150.0f;

/// <summary>
/// </summary>
constexpr auto G3SG1_DAMAGE = 80.0f;

/// <summary>
/// </summary>
constexpr auto G3SG1_RANGE_MODIFER = 0.98f;

/// <summary>
/// </summary>
constexpr auto G3SG1_RELOAD_TIME = 3.5f;

/// <summary>
/// Enum G3Sg1AnimSeq
/// </summary>
enum class G3Sg1AnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class G3Sg1.
/// </summary>
class G3Sg1 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// Glock18.
//

/// <summary>
/// </summary>
constexpr auto GLOCK18_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto GLOCK18_DAMAGE = 25.0f;

/// <summary>
/// </summary>
constexpr auto GLOCK18_RANGE_MODIFER = 0.75f;

/// <summary>
/// </summary>
constexpr auto GLOCK18_RELOAD_TIME = 2.2f;

/// <summary>
/// Enum Glock18AnimSeq
/// </summary>
enum class Glock18AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Idle2,

	/// <summary>
	/// </summary>
	Idle3,

	/// <summary>
	/// </summary>
	Shoot,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Holster,

	/// <summary>
	/// </summary>
	AddSilencer,

	/// <summary>
	/// </summary>
	Draw2,

	/// <summary>
	/// </summary>
	Reload2
};

/// <summary>
/// Enum Glock18ShieldAnimSeq
/// </summary>
enum class Glock18ShieldAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Shoot,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Up,

	/// <summary>
	/// </summary>
	Down
};

/// <summary>
/// Class Glock18.
/// </summary>
class Glock18 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	bool burst_fire{};
};

//
// HE grenade.
//

/// <summary>
/// </summary>
constexpr auto HE_GRENADE_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto HE_GRENADE_MAX_SPEED_SHIELD = 180.0f;

/// <summary>
/// Enum HeGrenadeAnimSeq
/// </summary>
enum class HeGrenadeAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	PullPin,

	/// <summary>
	/// </summary>
	ThrowGrenade,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class HeGrenade.
/// </summary>
class HeGrenade : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean can_deploy() override = 0;

	/// <summary>
	/// </summary>
	qboolean can_drop() override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	void holster(qboolean skip_local) override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	unsigned short event_create_explosion{};
};

//
// Knife.
//

/// <summary>
/// </summary>
constexpr auto KNIFE_BODY_HIT_VOLUME = 128.0f;

/// <summary>
/// </summary>
constexpr auto KNIFE_WALL_HIT_VOLUME = 512.0f;

/// <summary>
/// </summary>
constexpr auto KNIFE_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto KNIFE_MAX_SPEED_SHIELD = 180.0f;

/// <summary>
/// Enum KnifeAnimSeq
/// </summary>
enum class KnifeAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Attack1Hit,

	/// <summary>
	/// </summary>
	Attack2Hit,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	StabHit,

	/// <summary>
	/// </summary>
	StabMiss,

	/// <summary>
	/// </summary>
	MidAttack1Hit,

	/// <summary>
	/// </summary>
	MidAttack2Hit
};

/// <summary>
/// Enum KnifeShieldAnimSeq
/// </summary>
enum class KnifeShieldAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Slash,

	/// <summary>
	/// </summary>
	AttackHit,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	UpIdle,

	/// <summary>
	/// </summary>
	Up,

	/// <summary>
	/// </summary>
	Down
};

/// <summary>
/// Class Knife.
/// </summary>
class Knife : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean can_drop() override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	void holster(qboolean skip_local) override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	TraceResult trace_hit;

	/// <summary>
	/// </summary>
	unsigned short event_knife{};
};

//
// M249.
//

/// <summary>
/// </summary>
constexpr auto M249_MAX_SPEED = 220.0f;

/// <summary>
/// </summary>
constexpr auto M249_DAMAGE = 32.0f;

/// <summary>
/// </summary>
constexpr auto M249_RANGE_MODIFER = 0.97f;

/// <summary>
/// </summary>
constexpr auto M249_RELOAD_TIME = 4.7f;

/// <summary>
/// Enum M249AnimSeq
/// </summary>
enum class M249AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class M249.
/// </summary>
class M249 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// M3.
//

/// <summary>
/// </summary>
constexpr auto M3_MAX_SPEED = 230.0f;

/// <summary>
/// </summary>
constexpr auto M3_DAMAGE = 20.0f;

/// <summary>
/// <para>Special shotgun spreads.</para>
/// </summary>
const auto M3_CONE_VECTOR = Vector(0.0675f, 0.0675f, 0.0f);

/// <summary>
/// Enum M3AnimSeq
/// </summary>
enum class M3AnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Fire1,

	/// <summary>
	/// </summary>
	Fire2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Pump,

	/// <summary>
	/// </summary>
	StartReload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Holster
};

/// <summary>
/// Class M3.
/// </summary>
class M3 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	qboolean play_empty_sound() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	float pump_time{};
};

//
// M4A1.
//

/// <summary>
/// </summary>
constexpr auto M4A1_MAX_SPEED = 230.0f;

/// <summary>
/// </summary>
constexpr auto M4A1_DAMAGE = 32.0f;

/// <summary>
/// </summary>
constexpr auto M4A1_DAMAGE_SIL = 33.0f;

/// <summary>
/// </summary>
constexpr auto M4A1_RANGE_MODIFER = 0.97f;

/// <summary>
/// </summary>
constexpr auto M4A1_RANGE_MODIFER_SIL = 0.95f;

/// <summary>
/// </summary>
constexpr auto M4A1_RELOAD_TIME = 3.05f;

/// <summary>
/// Enum M4A1AnimSeq
/// </summary>
enum class M4A1AnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	AttachSilencer,

	/// <summary>
	/// </summary>
	UnsilIdle,

	/// <summary>
	/// </summary>
	UnsilShoot1,

	/// <summary>
	/// </summary>
	UnsilShoot2,

	/// <summary>
	/// </summary>
	UnsilShoot3,

	/// <summary>
	/// </summary>
	UnsilReload,

	/// <summary>
	/// </summary>
	UnsilDraw,

	/// <summary>
	/// </summary>
	DetachSilencer
};

/// <summary>
/// Class M4A1.
/// </summary>
class M4A1 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// MAC10.
//

/// <summary>
/// </summary>
constexpr auto MAC10_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto MAC10_DAMAGE = 29.0f;

/// <summary>
/// </summary>
constexpr auto MAC10_RANGE_MODIFER = 0.82f;

/// <summary>
/// </summary>
constexpr auto MAC10_RELOAD_TIME = 3.15f;

/// <summary>
/// Enum Mac10AnimSeq
/// </summary>
enum class Mac10AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Mac10.
/// </summary>
class Mac10 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// P228.
//

/// <summary>
/// </summary>
constexpr auto P228_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto P228_DAMAGE = 32.0f;

/// <summary>
/// </summary>
constexpr auto P228_RANGE_MODIFER = 0.8f;

/// <summary>
/// </summary>
constexpr auto P228_RELOAD_TIME = 2.7f;

/// <summary>
/// Enum P228AnimSeq
/// </summary>
enum class P228AnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Enum P228ShieldAnimSeq
/// </summary>
enum class P228ShieldAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	IdleUp,

	/// <summary>
	/// </summary>
	Up,

	/// <summary>
	/// </summary>
	Down
};

/// <summary>
/// Class P228.
/// </summary>
class P228 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// P90.
//

/// <summary>
/// </summary>
constexpr auto P90_MAX_SPEED = 245.0f;

/// <summary>
/// </summary>
constexpr auto P90_DAMAGE = 21.0f;

/// <summary>
/// </summary>
constexpr auto P90_RANGE_MODIFER = 0.885f;

/// <summary>
/// </summary>
constexpr auto P90_RELOAD_TIME = 3.4f;

/// <summary>
/// Enum P90AnimSeq
/// </summary>
enum class P90AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class P90.
/// </summary>
class P90 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// Scout.
//

/// <summary>
/// </summary>
constexpr auto SCOUT_MAX_SPEED = 260.0f;

/// <summary>
/// </summary>
constexpr auto SCOUT_MAX_SPEED_ZOOM = 220.0f;

/// <summary>
/// </summary>
constexpr auto SCOUT_DAMAGE = 75.0f;

/// <summary>
/// </summary>
constexpr auto SCOUT_RANGE_MODIFER = 0.98f;

/// <summary>
/// </summary>
constexpr auto SCOUT_RELOAD_TIME = 2.0f;

/// <summary>
/// Enum ScoutAnimSeq
/// </summary>
enum class ScoutAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class Scout.
/// </summary>
class Scout : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// Smoke grenade.
//

/// <summary>
/// </summary>
constexpr auto SMOKE_GRENADE_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto SMOKE_GRENADE_MAX_SPEED_SHIELD = 180.0f;

/// <summary>
/// Enum SmokeGrenadeAnimSeq
/// </summary>
enum class SmokeGrenadeAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	PullPin,

	/// <summary>
	/// </summary>
	ThrowGrenade,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class SmokeGrenade.
/// </summary>
class SmokeGrenade : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean can_deploy() override = 0;

	/// <summary>
	/// </summary>
	qboolean can_drop() override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	void holster(qboolean skip_local) override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;
};

//
// TMP.
//

/// <summary>
/// </summary>
constexpr auto TMP_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto TMP_DAMAGE = 20.0f;

/// <summary>
/// </summary>
constexpr auto TMP_RANGE_MODIFER = 0.85f;

/// <summary>
/// </summary>
constexpr auto TMP_RELOAD_TIME = 2.12f;

/// <summary>
/// Enum TmpAnimSeq
/// </summary>
enum class TmpAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Tmp.
/// </summary>
class Tmp : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// XM1014.
//

/// <summary>
/// </summary>
constexpr auto XM1014_MAX_SPEED = 240.0f;

/// <summary>
/// </summary>
constexpr auto XM1014_DAMAGE = 20.0f;

/// <summary>
/// <para>Special shotgun spreads.</para>
/// </summary>
const auto XM1014_CONE_VECTOR = Vector(0.0725f, 0.0725f, 0.0f);

/// <summary>
/// Enum Xm1014AnimSeq
/// </summary>
enum class Xm1014AnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Fire1,

	/// <summary>
	/// </summary>
	Fire2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Pump,

	/// <summary>
	/// </summary>
	StartReload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class Xm1014.
/// </summary>
class Xm1014 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	qboolean play_empty_sound() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	float pump_time{};
};

//
// Elite.
//

/// <summary>
/// </summary>
constexpr auto ELITE_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto ELITE_RELOAD_TIME = 4.5f;

/// <summary>
/// </summary>
constexpr auto ELITE_DAMAGE = 36.0f;

/// <summary>
/// </summary>
constexpr auto ELITE_RANGE_MODIFER = 0.75f;

/// <summary>
/// Enum EliteAnimSeq
/// </summary>
enum class EliteAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	IdleLeftEmpty,

	/// <summary>
	/// </summary>
	ShootLeft1,

	/// <summary>
	/// </summary>
	ShootLeft2,

	/// <summary>
	/// </summary>
	ShootLeft3,

	/// <summary>
	/// </summary>
	ShootLeft4,

	/// <summary>
	/// </summary>
	ShootLeft5,

	/// <summary>
	/// </summary>
	ShootLeftLast,

	/// <summary>
	/// </summary>
	ShootRight1,

	/// <summary>
	/// </summary>
	ShootRight2,

	/// <summary>
	/// </summary>
	ShootRight3,

	/// <summary>
	/// </summary>
	ShootRight4,

	/// <summary>
	/// </summary>
	ShootRight5,

	/// <summary>
	/// </summary>
	ShootRightLast,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class Elite.
/// </summary>
class Elite : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// FiveSeven.
//

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_DAMAGE = 20.0f;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_RANGE_MODIFER = 0.885f;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_RELOAD_TIME = 2.7f;

/// <summary>
/// Enum FiveSevenAnimSeq
/// </summary>
enum class FiveSevenAnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class FiveSeven.
/// </summary>
class FiveSeven : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_pistol() = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// UMP45.
//

/// <summary>
/// </summary>
constexpr auto UMP45_MAX_SPEED = 250.0f;

/// <summary>
/// </summary>
constexpr auto UMP45_DAMAGE = 30.0f;

/// <summary>
/// </summary>
constexpr auto UMP45_RANGE_MODIFER = 0.82f;

/// <summary>
/// </summary>
constexpr auto UMP45_RELOAD_TIME = 3.5f;

/// <summary>
/// Enum Ump45AnimSeq
/// </summary>
enum class Ump45AnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Ump45.
/// </summary>
class Ump45 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// SG550.
//

/// <summary>
/// </summary>
constexpr auto SG550_MAX_SPEED = 210.0f;

/// <summary>
/// </summary>
constexpr auto SG550_MAX_SPEED_ZOOM = 150.0f;

/// <summary>
/// </summary>
constexpr auto SG550_DAMAGE = 70.0f;

/// <summary>
/// </summary>
constexpr auto SG550_RANGE_MODIFER = 0.98f;

/// <summary>
/// </summary>
constexpr auto SG550_RELOAD_TIME = 3.35f;

/// <summary>
/// Enum Sg550AnimSeq
/// </summary>
enum class Sg550AnimSeq {
	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Shoot,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw
};

/// <summary>
/// Class Sg550.
/// </summary>
class Sg550 : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};
};

//
// Galil.
//

/// <summary>
/// </summary>
constexpr auto GALIL_MAX_SPEED = 240.0f;

/// <summary>
/// </summary>
constexpr auto GALIL_DAMAGE = 30.0f;

/// <summary>
/// </summary>
constexpr auto GALIL_RANGE_MODIFER = 0.98f;

/// <summary>
/// </summary>
constexpr auto GALIL_RELOAD_TIME = 2.45f;

/// <summary>
/// Enum GalilAnimSeq
/// </summary>
enum class GalilAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Galil.
/// </summary>
class Galil : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};
};

//
// Famas.
//

/// <summary>
/// </summary>
constexpr auto FAMAS_MAX_SPEED = 240.0f;

/// <summary>
/// </summary>
constexpr auto FAMAS_RELOAD_TIME = 3.3f;

/// <summary>
/// </summary>
constexpr auto FAMAS_DAMAGE = 30.0f;

/// <summary>
/// </summary>
constexpr auto FAMAS_DAMAGE_BURST = 34.0f;

/// <summary>
/// </summary>
constexpr auto FAMAS_RANGE_MODIFER = 0.96f;

/// <summary>
/// Enum FamasAnimSeq
/// </summary>
enum class FamasAnimSeq {
	/// <summary>
	/// </summary>
	Idle1,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	Shoot1,

	/// <summary>
	/// </summary>
	Shoot2,

	/// <summary>
	/// </summary>
	Shoot3
};

/// <summary>
/// Class Famas.
/// </summary>
class Famas : public PlayerWeaponBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean get_item_info(ItemInfo* info) override = 0;

	/// <summary>
	/// </summary>
	qboolean deploy() override = 0;

	/// <summary>
	/// </summary>
	float get_max_speed() override = 0;

	/// <summary>
	/// </summary>
	InventorySlot item_slot() override = 0;

	/// <summary>
	/// </summary>
	void primary_attack() override = 0;

	/// <summary>
	/// </summary>
	void secondary_attack() override = 0;

	/// <summary>
	/// </summary>
	void reload() override = 0;

	/// <summary>
	/// </summary>
	void weapon_idle() override = 0;

	/// <summary>
	/// </summary>
	qboolean use_decrement() override = 0;

	/// <summary>
	/// </summary>
	int shell_model{};

	/// <summary>
	/// </summary>
	qboolean shell_on{};

#ifdef REGAMEDLL_API
	/// <summary>
	/// </summary>
	float base_damage_burst{};
#endif
};
