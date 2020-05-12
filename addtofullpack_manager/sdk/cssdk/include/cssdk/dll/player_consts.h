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
/// </summary>
constexpr auto SOUND_FLASHLIGHT_ON = "items/flashlight1.wav";

/// <summary>
/// </summary>
constexpr auto SOUND_FLASHLIGHT_OFF = "items/flashlight1.wav";

#ifdef REGAMEDLL_FIXES
/// <summary>
/// </summary>
constexpr auto MIN_BUY_TIME = 0;
#else
/// <summary>
/// <para>The minimum threshold values for cvar mp_buytime 15 sec's.</para>
/// </summary>
constexpr auto MIN_BUY_TIME = 15;
#endif

/// <summary>
/// </summary>
constexpr auto MAX_PLAYER_NAME_LENGTH = 32;

/// <summary>
/// </summary>
constexpr auto MAX_AUTO_BUY_LENGTH = 256;

/// <summary>
/// </summary>
constexpr auto MAX_REBUY_LENGTH = 256;

/// <summary>
/// </summary>
constexpr auto MAX_RECENT_PATH = 20;

/// <summary>
/// <para>The maximum number of icons of the hostages in the HUD.</para>
/// </summary>
constexpr auto MAX_HOSTAGE_ICON = 4;

/// <summary>
/// </summary>
constexpr auto MAX_SUIT_NO_REPEAT = 32;

/// <summary>
/// <para>Max of 4 suit sentences queued up at any time.</para>
/// </summary>
constexpr auto MAX_SUIT_PLAYLIST = 4;

/// <summary>
/// </summary>
constexpr auto MAX_BUFFER_MENU = 175;

/// <summary>
/// </summary>
constexpr auto MAX_BUFFER_MENU_BRIEFING = 50;

/// <summary>
/// </summary>
constexpr auto SUIT_UPDATE_TIME = 3.5f;

/// <summary>
/// </summary>
constexpr auto SUIT_FIRST_UPDATE_TIME = 0.1f;

/// <summary>
/// </summary>
constexpr auto MAX_PLAYER_FATAL_FALL_SPEED = 1100.0f;

/// <summary>
/// </summary>
constexpr auto MAX_PLAYER_SAFE_FALL_SPEED = 500.0f;

/// <summary>
/// </summary>
constexpr auto MAX_PLAYER_USE_RADIUS = 64.0f;

/// <summary>
/// <para>Armor Takes 50% of the damage.</para>
/// </summary>
constexpr auto ARMOR_RATIO = 0.5f;

/// <summary>
/// <para>Each Point of Armor is work 1/x points of health.</para>
/// </summary>
constexpr auto ARMOR_BONUS = 0.5f;

/// <summary>
/// <para>100 units / 3 minutes.</para>
/// </summary>
constexpr auto FLASH_DRAIN_TIME = 1.2f;

/// <summary>
/// <para>100 units / 20 seconds (seconds per unit).</para>
/// </summary>
constexpr auto FLASH_CHARGE_TIME = 0.2f;

/// <summary>
/// <para>Damage per unit per second..</para>
/// </summary>
constexpr auto DAMAGE_FOR_FALL_SPEED = 100.0f / (MAX_PLAYER_FATAL_FALL_SPEED - MAX_PLAYER_SAFE_FALL_SPEED);

/// <summary>
/// </summary>
constexpr auto PLAYER_MIN_BOUNCE_SPEED = 350.0f;

/// <summary>
/// <para>Won't punch player's screen/make scrape noise unless player falling at least this fast.</para>
/// </summary>
constexpr auto PLAYER_FALL_PUNCH_THRESHOLD = 250.0f;

/// <summary>
/// <para>Money blinks few of times on the freeze period.<br/></para>
/// </summary>
/// <remarks>
/// It works for CZ.
/// </remarks>
constexpr auto MONEY_BLINK_AMOUNT = 30;

//
// Player time based damage.
//

/// <summary>
/// <para>Lung full of air lasts this many seconds.</para>
/// </summary>
constexpr auto AIRTIME = 12;

/// <summary>
/// <para>Number of 2 second intervals to take damage.</para>
/// </summary>
constexpr auto PARALYZE_DURATION = 2;

/// <summary>
/// <para>Damage to take each 2 second interval.</para>
/// </summary>
constexpr auto PARALYZE_DAMAGE = 1.0f;

/// <summary>
/// </summary>
constexpr auto NERVE_GAS_DURATION = 2;

/// <summary>
/// </summary>
constexpr auto NERVE_GAS_DAMAGE = 5.0f;

/// <summary>
/// </summary>
constexpr auto POISON_DURATION = 5;

/// <summary>
/// </summary>
constexpr auto POISON_DAMAGE = 2.0f;

/// <summary>
/// </summary>
constexpr auto RADIATION_DURATION = 2;

/// <summary>
/// </summary>
constexpr auto RADIATION_DAMAGE = 1.0f;

/// <summary>
/// </summary>
constexpr auto ACID_DURATION = 2;

/// <summary>
/// </summary>
constexpr auto ACID_DAMAGE = 5.0f;

/// <summary>
/// </summary>
constexpr auto SLOW_BURN_DURATION = 2;

/// <summary>
/// </summary>
constexpr auto SLOW_BURN_DAMAGE = 1.0f;

/// <summary>
/// </summary>
constexpr auto SLOW_FREEZE_DURATION = 2;

/// <summary>
/// </summary>
constexpr auto SLOW_FREEZE_DAMAGE = 1.0f;

//
// Player physics flags bits.
// base_player::physics_flags
//

/// <summary>
/// </summary>
constexpr auto PFLAG_ON_LADDER = 1 << 0;

/// <summary>
/// </summary>
constexpr auto PFLAG_ON_SWING = 1 << 0;

/// <summary>
/// </summary>
constexpr auto PFLAG_ON_TRAIN = 1 << 1;

/// <summary>
/// </summary>
constexpr auto PFLAG_ON_BARNACLE = 1 << 2;

/// <summary>
/// <para>In the process of ducking, but not totally squatted yet.</para>
/// </summary>
constexpr auto PFLAG_DUCKING = 1 << 3;

/// <summary>
/// <para>Using a continuous entity.</para>
/// </summary>
constexpr auto PFLAG_USING = 1 << 4;

/// <summary>
/// <para>Player is locked in stationary cam mode. Spectators can move, observers can't.</para>
/// </summary>
constexpr auto PFLAG_OBSERVER = 1 << 5;

//
// Player game state flags.
//

/// <summary>
/// </summary>
constexpr auto HIT_GROUP_SHIELD_ENABLED = 0;

/// <summary>
/// </summary>
constexpr auto HIT_GROUP_SHIELD_DISABLED = 1;

/// <summary>
/// </summary>
constexpr auto TRAIN_OFF = 0x00;

/// <summary>
/// </summary>
constexpr auto TRAIN_NEUTRAL = 0x01;

/// <summary>
/// </summary>
constexpr auto TRAIN_SLOW = 0x02;

/// <summary>
/// </summary>
constexpr auto TRAIN_MEDIUM = 0x03;

/// <summary>
/// </summary>
constexpr auto TRAIN_FAST = 0x04;

/// <summary>
/// </summary>
constexpr auto TRAIN_BACK = 0x05;

/// <summary>
/// </summary>
constexpr auto TRAIN_ACTIVE = 0x80;

/// <summary>
/// </summary>
constexpr auto TRAIN_NEW = 0xc0;

/// <summary>
/// </summary>
constexpr auto SUIT_GROUP = true;

/// <summary>
/// </summary>
constexpr auto SUIT_SENTENCE = false;

/// <summary>
/// </summary>
constexpr auto SUIT_REPEAT_OK = 0;

/// <summary>
/// </summary>
constexpr auto SUIT_NEXT_IN_30_SEC = 30;

/// <summary>
/// </summary>
constexpr auto SUIT_NEXT_IN_1_MIN = 60;

/// <summary>
/// </summary>
constexpr auto SUIT_NEXT_IN_5_MIN = 300;

/// <summary>
/// </summary>
constexpr auto SUIT_NEXT_IN_10_MIN = 600;

/// <summary>
/// </summary>
constexpr auto SUIT_NEXT_IN_30_MIN = 1800;

/// <summary>
/// </summary>
constexpr auto SUIT_NEXT_IN_1_HOUR = 3600;

/// <summary>
/// </summary>
constexpr auto MAX_TEAM_NAME_LENGTH = 16;

/// <summary>
/// </summary>
constexpr auto AUTO_AIM_2DEGREES = 0.0348994967025;

/// <summary>
/// </summary>
constexpr auto AUTO_AIM_5DEGREES = 0.08715574274766;

/// <summary>
/// </summary>
constexpr auto AUTO_AIM_8DEGREES = 0.1391731009601;

/// <summary>
/// </summary>
constexpr auto AUTO_AIM_10DEGREES = 0.1736481776669;

/// <summary>
/// </summary>
constexpr auto MAX_ID_RANGE = 2048.0f;

/// <summary>
/// </summary>
constexpr auto MAX_SPEC_ID_RANGE = 8192.0f;

/// <summary>
/// </summary>
constexpr auto MAX_SBAR_STRING = 128;

/// <summary>
/// </summary>
constexpr auto SBAR_TARGET_TYPE_TEAMMATE = 1;

/// <summary>
/// </summary>
constexpr auto SBAR_TARGET_TYPE_ENEMY = 2;

/// <summary>
/// </summary>
constexpr auto SBAR_TARGET_TYPE_HOSTAGE = 3;

/// <summary>
/// </summary>
constexpr auto MAX_LOCATION_LEN = 32;

/// <summary>
/// Enum RewardType
/// </summary>
enum class RewardType {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	RoundBonus,

	/// <summary>
	/// </summary>
	PlayerReset,

	/// <summary>
	/// </summary>
	PlayerJoin,

	/// <summary>
	/// </summary>
	PlayerSpecJoin,

	/// <summary>
	/// </summary>
	PlayerBoughtSomething,

	/// <summary>
	/// </summary>
	HostageTook,

	/// <summary>
	/// </summary>
	HostageRescued,

	/// <summary>
	/// </summary>
	HostageDamaged,

	/// <summary>
	/// </summary>
	HostageKilled,

	/// <summary>
	/// </summary>
	TeammatesKilled,

	/// <summary>
	/// </summary>
	EnemyKilled,

	/// <summary>
	/// </summary>
	IntoGame,

	/// <summary>
	/// </summary>
	VipKilled,

	/// <summary>
	/// </summary>
	VipRescuedMyself
};

/// <summary>
/// Enum PlayerAnim
/// </summary>
enum class PlayerAnim {
	/// <summary>
	/// </summary>
	Idle = 0,

	/// <summary>
	/// </summary>
	Walk,

	/// <summary>
	/// </summary>
	Jump,

	/// <summary>
	/// </summary>
	SuperJump,

	/// <summary>
	/// </summary>
	Die,

	/// <summary>
	/// </summary>
	Attack1,

	/// <summary>
	/// </summary>
	Attack2,

	/// <summary>
	/// </summary>
	Flinch,

	/// <summary>
	/// </summary>
	LargeFlinch,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// </summary>
	HoldBomb
};

/// <summary>
/// Enum MenuName
/// </summary>
enum class MenuName {
	/// <summary>
	/// </summary>
	Off = 0,

	/// <summary>
	/// </summary>
	ChooseTeam,

	/// <summary>
	/// </summary>
	IgChooseTeam,

	/// <summary>
	/// </summary>
	ChooseAppearance,

	/// <summary>
	/// </summary>
	Buy,

	/// <summary>
	/// </summary>
	BuyPistol,

	/// <summary>
	/// </summary>
	BuyRifle,

	/// <summary>
	/// </summary>
	BuyMachineGun,

	/// <summary>
	/// </summary>
	BuyShotgun,

	/// <summary>
	/// </summary>
	BuySubmachineGun,

	/// <summary>
	/// </summary>
	BuyItem,

	/// <summary>
	/// </summary>
	Radio1,

	/// <summary>
	/// </summary>
	Radio2,

	/// <summary>
	/// </summary>
	Radio3,

	/// <summary>
	/// </summary>
	ClientBuy
};

/// <summary>
/// Enum TeamName
/// </summary>
enum class TeamName {
	/// <summary>
	/// </summary>
	Unassigned = 0,

	/// <summary>
	/// </summary>
	Terrorist,

	/// <summary>
	/// </summary>
	Ct,

	/// <summary>
	/// </summary>
	Spectator
};

/// <summary>
/// Enum ModelName
/// </summary>
enum class ModelName {
	/// <summary>
	/// </summary>
	Unassigned = 0,

	/// <summary>
	/// </summary>
	Urban,

	/// <summary>
	/// </summary>
	Terror,

	/// <summary>
	/// </summary>
	Leet,

	/// <summary>
	/// </summary>
	Arctic,

	/// <summary>
	/// </summary>
	Gsg9,

	/// <summary>
	/// </summary>
	Gign,

	/// <summary>
	/// </summary>
	Sas,

	/// <summary>
	/// </summary>
	Guerilla,

	/// <summary>
	/// </summary>
	Vip,

	/// <summary>
	/// </summary>
	Militia,

	/// <summary>
	/// </summary>
	Spetsnaz,

	/// <summary>
	/// </summary>
	Auto
};

/// <summary>
/// Enum JoinState
/// </summary>
enum class JoinState {
	/// <summary>
	/// </summary>
	Joined = 0,

	/// <summary>
	/// </summary>
	ShowText,

	/// <summary>
	/// </summary>
	ReadingText,

	/// <summary>
	/// </summary>
	ShowTeamSelect,

	/// <summary>
	/// </summary>
	PickingTeam,

	/// <summary>
	/// </summary>
	GetIntoGame
};

/// <summary>
/// Enum TrackCommands
/// </summary>
enum class TrackCommands {
	/// <summary>
	/// </summary>
	Say = 0,

	/// <summary>
	/// </summary>
	SayTeam,

	/// <summary>
	/// </summary>
	FullUpdate,

	/// <summary>
	/// </summary>
	Vote,

	/// <summary>
	/// </summary>
	VoteMap,

	/// <summary>
	/// </summary>
	ListMaps,

	/// <summary>
	/// </summary>
	ListPlayers,

	/// <summary>
	/// </summary>
	NightVision,

	/// <summary>
	/// </summary>
	CommandsToTrack
};

/// <summary>
/// Enum IgnoreChatMsg
/// </summary>
enum class IgnoreChatMsg : int {
	/// <summary>
	/// <para>Nothing to do.</para>
	/// </summary>
	None = 0,

	/// <summary>
	/// <para>To ignore any chat messages from the enemy.</para>
	/// </summary>
	Enemy,

	/// <summary>
	/// <para>Same as <c>enemy</c> but ignore teammates.</para>
	/// </summary>
	Team
};

/// <summary>
/// Enum ThrowDirection
/// </summary>
enum class ThrowDirection {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Forward,

	/// <summary>
	/// </summary>
	Backward,

	/// <summary>
	/// </summary>
	HitVel,

	/// <summary>
	/// </summary>
	Bomb,

	/// <summary>
	/// </summary>
	Grenade,

	/// <summary>
	/// </summary>
	HitVelMinusAirVel
};

/// <summary>
/// Enum SBarData
/// </summary>
enum class SBarData {
	/// <summary>
	/// </summary>
	IdTargetType = 1,

	/// <summary>
	/// </summary>
	IdTargetName,

	/// <summary>
	/// </summary>
	IdTargetHealth,

	/// <summary>
	/// </summary>
	End
};

/// <summary>
/// Enum MusicState
/// </summary>
enum class MusicState {
	/// <summary>
	/// </summary>
	Silent = 0,

	/// <summary>
	/// </summary>
	Calm,

	/// <summary>
	/// </summary>
	Intense
};
