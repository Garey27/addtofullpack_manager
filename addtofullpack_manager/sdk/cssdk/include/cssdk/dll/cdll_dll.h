// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

/// <summary>
/// <para>Hud item selection slots.</para>
/// </summary>
constexpr auto MAX_WEAPON_SLOTS = 5;

/// <summary>
/// <para>Hud item selection slots.</para>
/// </summary>
constexpr auto MAX_ITEM_TYPES = 6;

/// <summary>
/// <para>Not really slots.</para>
/// </summary>
constexpr auto MAX_AMMO_SLOTS = 32;

/// <summary>
/// <para>Hard coded item types.</para>
/// </summary>
constexpr auto MAX_ITEMS = 4;

/// <summary>
/// <para>Default field of view.</para>
/// </summary>
constexpr auto DEFAULT_FOV = 90;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_WEAPONS = 1 << 0;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_FLASHLIGHT = 1 << 1;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_ALL = 1 << 2;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_HEALTH = 1 << 3;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_TIMER = 1 << 4;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_MONEY = 1 << 5;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_CROSSHAIR = 1 << 6;

/// <summary>
/// </summary>
constexpr auto HIDE_HUD_OBSERVER_CROSSHAIR = 1 << 7;

/// <summary>
/// </summary>
constexpr auto STATUS_ICON_HIDE = 0;

/// <summary>
/// </summary>
constexpr auto STATUS_ICON_SHOW = 1;

/// <summary>
/// </summary>
constexpr auto STATUS_ICON_FLASH = 2;

/// <summary>
/// </summary>
constexpr auto HUD_PRINT_NOTIFY = 1;

/// <summary>
/// </summary>
constexpr auto HUD_PRINT_CONSOLE = 2;

/// <summary>
/// </summary>
constexpr auto HUD_PRINT_TALK = 3;

/// <summary>
/// </summary>
constexpr auto HUD_PRINT_CENTER = 4;

/// <summary>
/// </summary>
constexpr auto HUD_PRINT_RADIO = 5;

/// <summary>
/// </summary>
constexpr auto STATUS_NIGHT_VISION_ON = 1;

/// <summary>
/// </summary>
constexpr auto STATUS_NIGHT_VISION_OFF = 0;

/// <summary>
/// </summary>
constexpr auto ITEM_STATUS_NIGHT_VISION = 1 << 0;

/// <summary>
/// </summary>
constexpr auto ITEM_STATUS_DEFUSER = 1 << 1;

/// <summary>
/// </summary>
constexpr auto SCORE_STATUS_DEAD = 1 << 0;

/// <summary>
/// </summary>
constexpr auto SCORE_STATUS_BOMB = 1 << 1;

/// <summary>
/// </summary>
constexpr auto SCORE_STATUS_VIP = 1 << 2;

/// <summary>
/// </summary>
constexpr auto SCORE_STATUS_DEF_KIT = 1 << 3;

//
// Player data i_user3.
//

/// <summary>
/// </summary>
constexpr auto PLAYER_CAN_SHOOT = 1 << 0;

/// <summary>
/// </summary>
constexpr auto PLAYER_FREEZE_TIME_OVER = 1 << 1;

/// <summary>
/// </summary>
constexpr auto PLAYER_IN_BOMB_ZONE = 1 << 2;

/// <summary>
/// </summary>
constexpr auto PLAYER_HOLDING_SHIELD = 1 << 3;

/// <summary>
/// </summary>
constexpr auto PLAYER_PREVENT_DUCK = 1 << 4;

/// <summary>
/// <para>The player can't climb ladder.</para>
/// </summary>
constexpr auto PLAYER_PREVENT_CLIMB = 1 << 5;

/// <summary>
/// </summary>
constexpr auto PLAYER_PREVENT_JUMP = 1 << 6;

//
//
//

/// <summary>
/// </summary>
constexpr auto MENU_KEY_1 = 1 << 0;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_2 = 1 << 1;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_3 = 1 << 2;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_4 = 1 << 3;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_5 = 1 << 4;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_6 = 1 << 5;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_7 = 1 << 6;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_8 = 1 << 7;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_9 = 1 << 8;

/// <summary>
/// </summary>
constexpr auto MENU_KEY_0 = 1 << 9;

/// <summary>
/// </summary>
constexpr auto WEAPON_SUIT = 31;

/// <summary>
/// </summary>
constexpr auto WEAPON_ALL_WEAPONS = ~(1 << WEAPON_SUIT);

/// <summary>
/// Enum VguiMenu
/// </summary>
enum class VguiMenu {
	/// <summary>
	/// </summary>
	Team = 2,

	/// <summary>
	/// </summary>
	MapBriefing = 4,

	/// <summary>
	/// </summary>
	ClassT = 26,

	/// <summary>
	/// </summary>
	ClassCt,

	/// <summary>
	/// </summary>
	Buy,

	/// <summary>
	/// </summary>
	BuyPistol,

	/// <summary>
	/// </summary>
	BuyShotGun,

	/// <summary>
	/// </summary>
	BuyRifle,

	/// <summary>
	/// </summary>
	BuySubMachineGun,

	/// <summary>
	/// </summary>
	BuyMachineGun,

	/// <summary>
	/// </summary>
	BuyItem
};

/// <summary>
/// Enum VguiMenuSlot
/// </summary>
enum class VguiMenuSlot {
	/// <summary>
	/// </summary>
	BuyPistol = 1,

	/// <summary>
	/// </summary>
	BuyShotGun,

	/// <summary>
	/// </summary>
	BuySubMachineGun,

	/// <summary>
	/// </summary>
	BuyRifle,

	/// <summary>
	/// </summary>
	BuyMachineGun,

	/// <summary>
	/// </summary>
	BuyPrimAmmo,

	/// <summary>
	/// </summary>
	BuySecAmmo,

	/// <summary>
	/// </summary>
	BuyItem
};
