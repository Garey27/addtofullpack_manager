// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/player.h>

/// <summary>
/// </summary>
constexpr auto ITEM_ID_ANTIDOTE = 2;

/// <summary>
/// </summary>
constexpr auto ITEM_ID_SECURITY = 3;

/// <summary>
/// Enum ItemRestType
/// </summary>
enum class ItemRestType {
	/// <summary>
	/// <para>When a player is buying items.</para>
	/// </summary>
	Buying = 0,

	/// <summary>
	/// <para>When the player touches with a WeaponBox or armoury_entity.</para>
	/// </summary>
	Touched,

	/// <summary>
	/// <para>When an entity game_player_equip gives item to player or default items on player spawn.</para>
	/// </summary>
	Equipped
};

/// <summary>
/// Enum ItemId
/// </summary>
enum class ItemId {
	/// <summary>
	/// </summary>
	None = -1,

	/// <summary>
	/// </summary>
	ShieldGun,

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
	NightVision,

	/// <summary>
	/// </summary>
	DefuseKit,

	/// <summary>
	/// </summary>
	Kevlar,

	/// <summary>
	/// </summary>
	Assault,

	/// <summary>
	/// </summary>
	LongJump,

	/// <summary>
	/// </summary>
	SodaCan,

	/// <summary>
	/// </summary>
	HealthKit,

	/// <summary>
	/// </summary>
	Antidote,

	/// <summary>
	/// </summary>
	Battery
};

/// <summary>
/// Class Item.
/// </summary>
class Item : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	EntityBase* respawn() override = 0;

	/// <summary>
	/// </summary>
	virtual qboolean my_touch(PlayerBase* player) = 0;
};

/// <summary>
/// Class WorldItem.
/// </summary>
class WorldItem : public EntityBase {
public:

	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	int type;
};

/// <summary>
/// Class ItemSuit.
/// </summary>
class ItemSuit : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemBattery.
/// </summary>
class ItemBattery : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemAntidote.
/// </summary>
class ItemAntidote : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemSecurity.
/// </summary>
class ItemSecurity : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemLongJump.
/// </summary>
class ItemLongJump : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemKevlar.
/// </summary>
class ItemKevlar : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemAssaultSuit.
/// </summary>
class ItemAssaultSuit : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};

/// <summary>
/// Class ItemThighPack.
/// </summary>
class ItemThighPack : public Item {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void precache() override = 0;

	/// <summary>
	/// </summary>
	qboolean my_touch(PlayerBase* player) override = 0;
};
