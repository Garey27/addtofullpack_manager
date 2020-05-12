// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/player_consts.h>

//
// Auto buy class.
//

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_NONE = 0;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_PRIMARY = 1 << 0;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_SECONDARY = 1 << 1;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_AMMO = 1 << 2;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_ARMOR = 1 << 3;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_DEFUSER = 1 << 4;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_PISTOL = 1 << 5;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_SMG = 1 << 6;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_RIFLE = 1 << 7;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_SNIPER_RIFLE = 1 << 8;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_SHOTGUN = 1 << 9;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_MACHINE_GUN = 1 << 10;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_GRENADE = 1 << 11;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_NIGHT_VISION = 1 << 12;

/// <summary>
/// </summary>
constexpr auto AUTO_BUY_CLASS_SHIELD = 1 << 13;

//
// Item cost.
//

/// <summary>
/// </summary>
constexpr auto ASSAULT_SUIT_PRICE = 1000;

/// <summary>
/// </summary>
constexpr auto FLASH_BANG_PRICE = 200;

/// <summary>
/// </summary>
constexpr auto HE_GRENADE_PRICE = 300;

/// <summary>
/// </summary>
constexpr auto SMOKE_GRENADE_PRICE = 300;

/// <summary>
/// </summary>
constexpr auto KEVLAR_PRICE = 650;

/// <summary>
/// </summary>
constexpr auto HELMET_PRICE = 350;

/// <summary>
/// </summary>
constexpr auto NVG_PRICE = 1250;

/// <summary>
/// </summary>
constexpr auto DEFUSE_KIT_PRICE = 200;

//
// Ammo cost.
//

/// <summary>
/// </summary>
constexpr auto AMMO_338MAG_PRICE = 125;

/// <summary>
/// </summary>
constexpr auto AMMO_357SIG_PRICE = 50;

/// <summary>
/// </summary>
constexpr auto AMMO_45ACP_PRICE = 25;

/// <summary>
/// </summary>
constexpr auto AMMO_50AE_PRICE = 40;

/// <summary>
/// </summary>
constexpr auto AMMO_556MM_PRICE = 60;

/// <summary>
/// </summary>
constexpr auto AMMO_57MM_PRICE = 50;

/// <summary>
/// </summary>
constexpr auto AMMO_762MM_PRICE = 80;

/// <summary>
/// </summary>
constexpr auto AMMO_9MM_PRICE = 20;

/// <summary>
/// </summary>
constexpr auto AMMO_BUCKSHOT_PRICE = 65;

/// <summary>
/// </summary>
constexpr auto AMMO_FLASH_BANG_PRICE = FLASH_BANG_PRICE;

/// <summary>
/// </summary>
constexpr auto AMMO_HE_GRENADE_PRICE = HE_GRENADE_PRICE;

/// <summary>
/// </summary>
constexpr auto AMMO_SMOKE_GRENADE_PRICE = SMOKE_GRENADE_PRICE;

//
// Weapon cost.
//

/// <summary>
/// </summary>
constexpr auto AK47_PRICE = 2500;

/// <summary>
/// </summary>
constexpr auto AWP_PRICE = 4750;

/// <summary>
/// </summary>
constexpr auto DEAGLE_PRICE = 650;

/// <summary>
/// </summary>
constexpr auto G3SG1_PRICE = 5000;

/// <summary>
/// </summary>
constexpr auto SG550_PRICE = 4200;

/// <summary>
/// </summary>
constexpr auto GLOCK18_PRICE = 400;

/// <summary>
/// </summary>
constexpr auto M249_PRICE = 5750;

/// <summary>
/// </summary>
constexpr auto M3_PRICE = 1700;

/// <summary>
/// </summary>
constexpr auto M4A1_PRICE = 3100;

/// <summary>
/// </summary>
constexpr auto AUG_PRICE = 3500;

/// <summary>
/// </summary>
constexpr auto MP5NAVY_PRICE = 1500;

/// <summary>
/// </summary>
constexpr auto P228_PRICE = 600;

/// <summary>
/// </summary>
constexpr auto P90_PRICE = 2350;

/// <summary>
/// </summary>
constexpr auto UMP45_PRICE = 1700;

/// <summary>
/// </summary>
constexpr auto MAC10_PRICE = 1400;

/// <summary>
/// </summary>
constexpr auto SCOUT_PRICE = 2750;

/// <summary>
/// </summary>
constexpr auto SG552_PRICE = 3500;

/// <summary>
/// </summary>
constexpr auto TMP_PRICE = 1250;

/// <summary>
/// </summary>
constexpr auto USP_PRICE = 500;

/// <summary>
/// </summary>
constexpr auto ELITE_PRICE = 800;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_PRICE = 750;

/// <summary>
/// </summary>
constexpr auto XM1014_PRICE = 3000;

/// <summary>
/// </summary>
constexpr auto GALIL_PRICE = 2000;

/// <summary>
/// </summary>
constexpr auto FAMAS_PRICE = 2250;

/// <summary>
/// </summary>
constexpr auto SHIELD_GUN_PRICE = 2200;

//
// Weapon state.
//

/// <summary>
/// </summary>
constexpr auto WPN_STATE_USP_SILENCED = 1 << 0;

/// <summary>
/// </summary>
constexpr auto WPN_STATE_GLOCK18_BURST_MODE = 1 << 1;

/// <summary>
/// </summary>
constexpr auto WPN_STATE_M4A1_SILENCED = 1 << 2;

/// <summary>
/// </summary>
constexpr auto WPN_STATE_ELITE_LEFT = 1 << 3;

/// <summary>
/// </summary>
constexpr auto WPN_STATE_FAMAS_BURST_MODE = 1 << 4;

/// <summary>
/// </summary>
constexpr auto WPN_STATE_SHIELD_DRAWN = 1 << 5;

//
// Default amount of ammo that comes with each gun when it spawns.
//

/// <summary>
/// </summary>
constexpr auto P228_DEFAULT_GIVE = 13;

/// <summary>
/// </summary>
constexpr auto GLOCK18_DEFAULT_GIVE = 20;

/// <summary>
/// </summary>
constexpr auto SCOUT_DEFAULT_GIVE = 10;

/// <summary>
/// </summary>
constexpr auto HE_GRENADE_DEFAULT_GIVE = 1;

/// <summary>
/// </summary>
constexpr auto XM1014_DEFAULT_GIVE = 7;

/// <summary>
/// </summary>
constexpr auto C4_DEFAULT_GIVE = 1;

/// <summary>
/// </summary>
constexpr auto MAC10_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto AUG_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto SMOKE_GRENADE_DEFAULT_GIVE = 1;

/// <summary>
/// </summary>
constexpr auto ELITE_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_DEFAULT_GIVE = 20;

/// <summary>
/// </summary>
constexpr auto UMP45_DEFAULT_GIVE = 25;

/// <summary>
/// </summary>
constexpr auto SG550_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto GALIL_DEFAULT_GIVE = 35;

/// <summary>
/// </summary>
constexpr auto FAMAS_DEFAULT_GIVE = 25;

/// <summary>
/// </summary>
constexpr auto USP_DEFAULT_GIVE = 12;

/// <summary>
/// </summary>
constexpr auto AWP_DEFAULT_GIVE = 10;

/// <summary>
/// </summary>
constexpr auto MP5NAVY_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto M249_DEFAULT_GIVE = 100;

/// <summary>
/// </summary>
constexpr auto M3_DEFAULT_GIVE = 8;

/// <summary>
/// </summary>
constexpr auto M4A1_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto TMP_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto G3SG1_DEFAULT_GIVE = 20;

/// <summary>
/// </summary>
constexpr auto FLASH_BANG_DEFAULT_GIVE = 1;

/// <summary>
/// </summary>
constexpr auto DEAGLE_DEFAULT_GIVE = 7;

/// <summary>
/// </summary>
constexpr auto SG552_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto AK47_DEFAULT_GIVE = 30;

/// <summary>
/// </summary>
constexpr auto P90_DEFAULT_GIVE = 50;

//
// Weapon clip size.
//

/// <summary>
/// </summary>
constexpr auto P228_MAX_CLIP = 13;

/// <summary>
/// </summary>
constexpr auto GLOCK18_MAX_CLIP = 20;

/// <summary>
/// </summary>
constexpr auto SCOUT_MAX_CLIP = 10;

/// <summary>
/// </summary>
constexpr auto XM1014_MAX_CLIP = 7;

/// <summary>
/// </summary>
constexpr auto MAC10_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto AUG_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto ELITE_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_MAX_CLIP = 20;

/// <summary>
/// </summary>
constexpr auto UMP45_MAX_CLIP = 25;

/// <summary>
/// </summary>
constexpr auto SG550_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto GALIL_MAX_CLIP = 35;

/// <summary>
/// </summary>
constexpr auto FAMAS_MAX_CLIP = 25;

/// <summary>
/// </summary>
constexpr auto USP_MAX_CLIP = 12;

/// <summary>
/// </summary>
constexpr auto AWP_MAX_CLIP = 10;

/// <summary>
/// </summary>
constexpr auto MP5N_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto M249_MAX_CLIP = 100;

/// <summary>
/// </summary>
constexpr auto M3_MAX_CLIP = 8;

/// <summary>
/// </summary>
constexpr auto M4A1_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto TMP_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto G3SG1_MAX_CLIP = 20;

/// <summary>
/// </summary>
constexpr auto DEAGLE_MAX_CLIP = 7;

/// <summary>
/// </summary>
constexpr auto SG552_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto AK47_MAX_CLIP = 30;

/// <summary>
/// </summary>
constexpr auto P90_MAX_CLIP = 50;

//
// Weapon clip weight.
//

/// <summary>
/// </summary>
constexpr auto P228_WEIGHT = 5;

/// <summary>
/// </summary>
constexpr auto GLOCK18_WEIGHT = 5;

/// <summary>
/// </summary>
constexpr auto SCOUT_WEIGHT = 30;

/// <summary>
/// </summary>
constexpr auto HE_GRENADE_WEIGHT = 2;

/// <summary>
/// </summary>
constexpr auto XM1014_WEIGHT = 20;

/// <summary>
/// </summary>
constexpr auto C4_WEIGHT = 3;

/// <summary>
/// </summary>
constexpr auto MAC10_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto AUG_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto SMOKE_GRENADE_WEIGHT = 1;

/// <summary>
/// </summary>
constexpr auto ELITE_WEIGHT = 5;

/// <summary>
/// </summary>
constexpr auto FIVESEVEN_WEIGHT = 5;

/// <summary>
/// </summary>
constexpr auto UMP45_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto SG550_WEIGHT = 20;

/// <summary>
/// </summary>
constexpr auto GALIL_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto FAMAS_WEIGHT = 75;

/// <summary>
/// </summary>
constexpr auto USP_WEIGHT = 5;

/// <summary>
/// </summary>
constexpr auto AWP_WEIGHT = 30;

/// <summary>
/// </summary>
constexpr auto MP5NAVY_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto M249_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto M3_WEIGHT = 20;

/// <summary>
/// </summary>
constexpr auto M4A1_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto TMP_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto G3SG1_WEIGHT = 20;

/// <summary>
/// </summary>
constexpr auto FLASH_BANG_WEIGHT = 1;

/// <summary>
/// </summary>
constexpr auto DEAGLE_WEIGHT = 7;

/// <summary>
/// </summary>
constexpr auto SG552_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto AK47_WEIGHT = 25;

/// <summary>
/// </summary>
constexpr auto P90_WEIGHT = 26;

/// <summary>
/// </summary>
constexpr auto KNIFE_WEIGHT = 0;

//
// Weapon max ammo.
//

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_BUCKSHOT = 32;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_9MM = 120;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_556NATO = 90;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_556NATOBOX = 200;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_762NATO = 90;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_45ACP = 100;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_50AE = 35;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_338MAGNUM = 30;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_57MM = 100;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_357SIG = 52;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_SMOKE_GRENADE = 1;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_HE_GRENADE = 1;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_FLASH_BANG = 2;

/// <summary>
/// </summary>
constexpr auto MAX_AMMO_C4 = 1;

//
// Ammo buy amount.
//

/// <summary>
/// </summary>
constexpr auto AMMO_338MAG_BUY = 10;

/// <summary>
/// </summary>
constexpr auto AMMO_357SIG_BUY = 13;

/// <summary>
/// </summary>
constexpr auto AMMO_45ACP_BUY = 12;

/// <summary>
/// </summary>
constexpr auto AMMO_50AE_BUY = 7;

/// <summary>
/// </summary>
constexpr auto AMMO_556NATO_BUY = 30;

/// <summary>
/// </summary>
constexpr auto AMMO_556NATOBOX_BUY = 30;

/// <summary>
/// </summary>
constexpr auto AMMO_57MM_BUY = 50;

/// <summary>
/// </summary>
constexpr auto AMMO_762NATO_BUY = 30;

/// <summary>
/// </summary>
constexpr auto AMMO_9MM_BUY = 30;

/// <summary>
/// </summary>
constexpr auto AMMO_BUCKSHOT_BUY = 8;

/// <summary>
/// </summary>
constexpr auto AMMO_FLASH_BANG_BUY = 1;

/// <summary>
/// </summary>
constexpr auto AMMO_HE_GRENADE_BUY = 1;

/// <summary>
/// </summary>
constexpr auto AMMO_SMOKE_GRENADE_BUY = 1;

/// <summary>
/// Enum WeaponId
/// </summary>
enum class WeaponId {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	P228,

	/// <summary>
	/// </summary>
	Glock,

	/// <summary>
	/// </summary>
	Scout,

	/// <summary>
	/// </summary>
	HeGrenade,

	/// <summary>
	/// </summary>
	Xm1014,

	/// <summary>
	/// </summary>
	C4,

	/// <summary>
	/// </summary>
	Mac10,

	/// <summary>
	/// </summary>
	Aug,

	/// <summary>
	/// </summary>
	SmokeGrenade,

	/// <summary>
	/// </summary>
	Elite,

	/// <summary>
	/// </summary>
	Fiveseven,

	/// <summary>
	/// </summary>
	Ump45,

	/// <summary>
	/// </summary>
	Sg550,

	/// <summary>
	/// </summary>
	Galil,

	/// <summary>
	/// </summary>
	Famas,

	/// <summary>
	/// </summary>
	Usp,

	/// <summary>
	/// </summary>
	Glock18,

	/// <summary>
	/// </summary>
	Awp,

	/// <summary>
	/// </summary>
	Mp5Navy,

	/// <summary>
	/// </summary>
	M249,

	/// <summary>
	/// </summary>
	M3,

	/// <summary>
	/// </summary>
	M4A1,

	/// <summary>
	/// </summary>
	Tmp,

	/// <summary>
	/// </summary>
	G3Sg1,

	/// <summary>
	/// </summary>
	FlashBang,

	/// <summary>
	/// </summary>
	Deagle,

	/// <summary>
	/// </summary>
	Sg552,

	/// <summary>
	/// </summary>
	Ak47,

	/// <summary>
	/// </summary>
	Knife,

	/// <summary>
	/// </summary>
	P90,

	/// <summary>
	/// </summary>
	ShieldGun = 99
};

/// <summary>
/// Enum AmmoType
/// </summary>
enum class AmmoType {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Ammo338Magnum,

	/// <summary>
	/// </summary>
	Ammo762Nato,

	/// <summary>
	/// </summary>
	Ammo556Natobox,

	/// <summary>
	/// </summary>
	Ammo556Nato,

	/// <summary>
	/// </summary>
	AmmoBuckshot,

	/// <summary>
	/// </summary>
	Ammo45Acp,

	/// <summary>
	/// </summary>
	Ammo57Mm,

	/// <summary>
	/// </summary>
	Ammo50Ae,

	/// <summary>
	/// </summary>
	Ammo357Sig,

	/// <summary>
	/// </summary>
	Ammo9Mm,

	/// <summary>
	/// </summary>
	AmmoFlashBang,

	/// <summary>
	/// </summary>
	AmmoHeGrenade,

	/// <summary>
	/// </summary>
	AmmoSmokeGrenade,

	/// <summary>
	/// </summary>
	AmmoC4,

	/// <summary>
	/// </summary>
	AmmoMaxTypes
};

/// <summary>
/// Enum WeaponClass
/// </summary>
enum class WeaponClass {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Knife,

	/// <summary>
	/// </summary>
	Pistol,

	/// <summary>
	/// </summary>
	Grenade,

	/// <summary>
	/// </summary>
	SubmachineGun,

	/// <summary>
	/// </summary>
	Shotgun,

	/// <summary>
	/// </summary>
	MachineGun,

	/// <summary>
	/// </summary>
	Rifle,

	/// <summary>
	/// </summary>
	SniperRifle,

	/// <summary>
	/// </summary>
	Max
};

/// <summary>
/// Enum ShieldGun
/// </summary>
enum class ShieldGun {
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
	ShootEmpty,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	Draw,

	/// <summary>
	/// </summary>
	DrawnIdle,

	/// <summary>
	/// </summary>
	Up,

	/// <summary>
	/// </summary>
	Down
};

/// <summary>
/// Enum ShieldGrenade
/// </summary>
enum class ShieldGrenade {
	/// <summary>
	/// </summary>
	Idle = 4,

	/// <summary>
	/// </summary>
	Up,

	/// <summary>
	/// </summary>
	Down
};

/// <summary>
/// Enum InventorySlot
/// </summary>
enum class InventorySlot {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Primary,

	/// <summary>
	/// </summary>
	Pistol,

	/// <summary>
	/// </summary>
	Knife,

	/// <summary>
	/// </summary>
	Grenade,

	/// <summary>
	/// </summary>
	C4
};

/// <summary>
/// Enum BulletType
/// </summary>
enum class BulletType {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Player9Mm,

	/// <summary>
	/// </summary>
	PlayerMp5,

	/// <summary>
	/// </summary>
	Player357,

	/// <summary>
	/// </summary>
	PlayerBuckshot,

	/// <summary>
	/// </summary>
	PlayerCrowbar,

	/// <summary>
	/// </summary>
	Monster9Mm,

	/// <summary>
	/// </summary>
	MonsterMp5,

	/// <summary>
	/// </summary>
	Monster12Mm,

	/// <summary>
	/// </summary>
	Player45Acp,

	/// <summary>
	/// </summary>
	Player338Mag,

	/// <summary>
	/// </summary>
	Player762Mm,

	/// <summary>
	/// </summary>
	Player556Mm,

	/// <summary>
	/// </summary>
	Player50Ae,

	/// <summary>
	/// </summary>
	Player57Mm,

	/// <summary>
	/// </summary>
	Player357Sig
};

/// <summary>
/// Struct WeaponStruct
/// </summary>
struct WeaponStruct {
	/// <summary>
	/// </summary>
	WeaponId id{};

	/// <summary>
	/// </summary>
	int price{};

	/// <summary>
	/// </summary>
	TeamName side{};

	/// <summary>
	/// </summary>
	InventorySlot slot{};

	/// <summary>
	/// </summary>
	int ammo_price{};
};

/// <summary>
/// Struct AutoBuyInfoStruct
/// </summary>
struct AutoBuyInfoStruct {
	/// <summary>
	/// </summary>
	int auto_buy_class{};

	/// <summary>
	/// </summary>
	char* command{};

	/// <summary>
	/// </summary>
	char* class_name{};
};

/// <summary>
/// Struct WeaponAliasInfo
/// </summary>
struct WeaponAliasInfo {
	/// <summary>
	/// </summary>
	char* alias{};

	/// <summary>
	/// </summary>
	WeaponId id{};
};

/// <summary>
/// Struct WeaponBuyAliasInfo
/// </summary>
struct WeaponBuyAliasInfo {
	/// <summary>
	/// </summary>
	char* alias{};

	/// <summary>
	/// </summary>
	WeaponId id{};

	/// <summary>
	/// </summary>
	char* fail_name{};
};

/// <summary>
/// Struct WeaponClassAliasInfo
/// </summary>
struct WeaponClassAliasInfo {
	/// <summary>
	/// </summary>
	char* alias{};

	/// <summary>
	/// </summary>
	WeaponClass id{};
};

/// <summary>
/// Struct WeaponInfoStruct
/// </summary>
struct WeaponInfoStruct {
	/// <summary>
	/// </summary>
	WeaponId id{};

	/// <summary>
	/// </summary>
	int cost{};

	/// <summary>
	/// </summary>
	int clip_cost{};

	/// <summary>
	/// </summary>
	int buy_clip_size{};

	/// <summary>
	/// </summary>
	int gun_clip_size{};

	/// <summary>
	/// </summary>
	int max_rounds{};

	/// <summary>
	/// </summary>
	AmmoType ammo_type{};

	/// <summary>
	/// </summary>
	char* entity_name{};

	/// <summary>
	/// </summary>
	const char* ammo_name1{};

	/// <summary>
	/// </summary>
	const char* ammo_name2{};
};

/// <summary>
/// Struct AmmoInfoStruct
/// </summary>
struct AmmoInfoStruct {
	/// <summary>
	/// </summary>
	AmmoType ammo_type{};

	/// <summary>
	/// </summary>
	int clip_cost{};

	/// <summary>
	/// </summary>
	int buy_clip_size{};

	/// <summary>
	/// </summary>
	int max_rounds{};

	/// <summary>
	/// </summary>
	const char* ammo_name1{};

	/// <summary>
	/// </summary>
	const char* ammo_name2{};
};

/// <summary>
/// Struct WeaponSlotInfo
/// </summary>
struct WeaponSlotInfo {
	/// <summary>
	/// </summary>
	WeaponId id{};

	/// <summary>
	/// </summary>
	InventorySlot slot{};

	/// <summary>
	/// </summary>
	const char* weapon_name{};
};
