// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

//
// Dot products for view cone checking.
//

/// <summary>
/// <para>+-180 degrees.</para>
/// </summary>
constexpr auto VIEW_FIELD_FULL = -1.0;

/// <summary>
/// <para>+-135 degrees 0.1 // +-85 degrees, used for full FOV checks.</para>
/// </summary>
constexpr auto VIEW_FIELD_WIDE = -0.7;

/// <summary>
/// <para>+-45 degrees, more narrow check used to set up ranged attacks.</para>
/// </summary>
constexpr auto VIEW_FIELD_NARROW = 0.7;

/// <summary>
/// <para>+-25 degrees, more narrow check used to set up ranged attacks.</para>
/// </summary>
constexpr auto VIEW_FIELD_ULTRA_NARROW = 0.9;

//
//
//

/// <summary>
/// <para>Duplicated in protocol.h stop sound.</para>
/// </summary>
constexpr auto SND_STOP = 1 << 5;

/// <summary>
/// <para>Duplicated in protocol.h change sound vol.</para>
/// </summary>
constexpr auto SND_CHANGE_VOL = 1 << 6;

/// <summary>
/// <para>Duplicated in protocol.h change sound pitch.</para>
/// </summary>
constexpr auto SND_CHANGE_PITCH = 1 << 7;

/// <summary>
/// <para>Duplicated in protocol.h we're spawning, used in some cases for ambients.</para>
/// </summary>
constexpr auto SND_SPAWNING = 1 << 8;

//
// All monsters need this data.
//

/// <summary>
/// </summary>
constexpr auto DONT_BLEED = -1;

/// <summary>
/// </summary>
constexpr byte BLOOD_COLOR_DARK_RED = 223;

/// <summary>
/// </summary>
constexpr byte BLOOD_COLOR_RED = 247;

/// <summary>
/// </summary>
constexpr byte BLOOD_COLOR_YELLOW = 195;

/// <summary>
/// </summary>
constexpr byte BLOOD_COLOR_GREEN = BLOOD_COLOR_YELLOW;

//
//
//

/// <summary>
/// </summary>
constexpr auto GERMAN_GIB_COUNT = 4;

/// <summary>
/// </summary>
constexpr auto HUMAN_GIB_COUNT = 6;

/// <summary>
/// </summary>
constexpr auto ALIEN_GIB_COUNT = 4;

//
//
//

/// <summary>
/// </summary>
constexpr auto LANGUAGE_ENGLISH = 0;

/// <summary>
/// </summary>
constexpr auto LANGUAGE_GERMAN = 1;

/// <summary>
/// </summary>
constexpr auto LANGUAGE_FRENCH = 2;

/// <summary>
/// </summary>
constexpr auto LANGUAGE_BRITISH = 3;

/// <summary>
/// <para>Set this bit on guns and stuff that should never respawn.</para>
/// </summary>
constexpr auto SF_NO_RESPAWN = 1 << 30;

//
// These are caps bits to indicate what an object's capabilities (currently used for save/restore and level transitions).
//

/// <summary>
/// </summary>
constexpr auto FCAP_CUSTOM_SAVE = 0x00000001;

/// <summary>
/// <para>Should transfer between transitions.</para>
/// </summary>
constexpr auto FCAP_ACROSS_TRANSITION = 0x00000002;

/// <summary>
/// <para>Spawn after restore.</para>
/// </summary>
constexpr auto FCAP_MUST_SPAWN = 0x00000004;

/// <summary>
/// <para>Don't save this.</para>
/// </summary>
constexpr auto FCAP_DONT_SAVE = 0x80000000;

/// <summary>
/// <para>Can be used by the player.</para>
/// </summary>
constexpr auto FCAP_IMPULSE_USE = 0x00000008;

/// <summary>
/// <para>Can be used by the player.</para>
/// </summary>
constexpr auto FCAP_CONTINUOUS_USE = 0x00000010;

/// <summary>
/// <para>Can be used by the player.</para>
/// </summary>
constexpr auto FCAP_ON_OFF_USE = 0x00000020;

/// <summary>
/// <para>Player sends +/- 1 when using (currently only track trains).</para>
/// </summary>
constexpr auto FCAP_DIRECTIONAL_USE = 0x00000040;

/// <summary>
/// <para>Can be used to "master" other entities (like multi source).</para>
/// </summary>
constexpr auto FCAP_MASTER = 0x00000080;

/// <summary>
/// <para>Should reset on the new round.</para>
/// </summary>
constexpr auto FCAP_MUST_RESET = 0x00000100;

/// <summary>
/// <para>Should release on the new round.</para>
/// </summary>
constexpr auto FCAP_MUST_RELEASE = 0x00000200;

//
// UNDONE: This will ignore transition volumes (trigger_transition), but not the PVS!!!
//

/// <summary>
/// <para>ALWAYS goes across transitions.</para>
/// </summary>
constexpr auto FCAP_FORCE_TRANSITION = 0x00000080;

//
//
//

/// <summary>
/// <para>Generic damage was done.</para>
/// </summary>
constexpr auto DMG_GENERIC = 0;

/// <summary>
/// <para>Crushed by falling or moving object.</para>
/// </summary>
constexpr auto DMG_CRUSH = 1 << 0;

/// <summary>
/// <para>Shot.</para>
/// </summary>
constexpr auto DMG_BULLET = 1 << 1;

/// <summary>
/// <para>Cut, clawed, stabbed.</para>
/// </summary>
constexpr auto DMG_SLASH = 1 << 2;

/// <summary>
/// <para>Heat burned.</para>
/// </summary>
constexpr auto DMG_BURN = 1 << 3;

/// <summary>
/// <para>Frozen.</para>
/// </summary>
constexpr auto DMG_FREEZE = 1 << 4;

/// <summary>
/// <para>Fell too far.</para>
/// </summary>
constexpr auto DMG_FALL = 1 << 5;

/// <summary>
/// <para>Explosive blast damage.</para>
/// </summary>
constexpr auto DMG_BLAST = 1 << 6;

/// <summary>
/// <para>Crowbar, punch, headbutt.</para>
/// </summary>
constexpr auto DMG_CLUB = 1 << 7;

/// <summary>
/// <para>Electric shock.</para>
/// </summary>
constexpr auto DMG_SHOCK = 1 << 8;

/// <summary>
/// <para>Sound pulse shockwave.</para>
/// </summary>
constexpr auto DMG_SONIC = 1 << 9;

/// <summary>
/// <para>Laser or other high energy beam.</para>
/// </summary>
constexpr auto DMG_ENERGY_BEAM = 1 << 10;

/// <summary>
/// <para>With this bit OR'd in, no damage type will be able to gib victims upon death.</para>
/// </summary>
constexpr auto DMG_NEVER_GIB = 1 << 12;

/// <summary>
/// <para>With this bit OR'd in, any damage type can be made to gib victims upon death.</para>
/// </summary>
constexpr auto DMG_ALWAYS_GIB = 1 << 13;

/// <summary>
/// <para>Drowning.</para>
/// </summary>
constexpr auto DMG_DROWN = 1 << 14;

//
// Time-based damage.
//

/// <summary>
/// <para>Mask for time-based damage.</para>
/// </summary>
constexpr auto DMG_TIME_BASED = ~0x3FFF;

/// <summary>
/// <para>Slows affected creature down.</para>
/// </summary>
constexpr auto DMG_PARALYZE = 1 << 15;

/// <summary>
/// <para>Nerve toxins, very bad.</para>
/// </summary>
constexpr auto DMG_NERVE_GAS = 1 << 16;

/// <summary>
/// <para>Blood poisoning.</para>
/// </summary>
constexpr auto DMG_POISON = 1 << 17;

/// <summary>
/// <para>Radiation exposure.</para>
/// </summary>
constexpr auto DMG_RADIATION = 1 << 18;

/// <summary>
/// <para>Drowning recovery.</para>
/// </summary>
constexpr auto DMG_DROWN_RECOVER = 1 << 19;

/// <summary>
/// <para>Toxic chemicals or acid burns.</para>
/// </summary>
constexpr auto DMG_ACID = 1 << 20;

/// <summary>
/// <para>In an oven.</para>
/// </summary>
constexpr auto DMG_SLOW_BURN = 1 << 21;

/// <summary>
/// <para>In a subzero freezer.</para>
/// </summary>
constexpr auto DMG_SLOW_FREEZE = 1 << 22;

/// <summary>
/// <para>Hit by air raid (done to distinguish grenade from mortar).</para>
/// </summary>
constexpr auto DMG_MORTAR = 1 << 23;

/// <summary>
/// </summary>
constexpr auto DMG_EXPLOSION = 1 << 24;

/// <summary>
/// <para>These are the damage types that are allowed to gib corpses.</para>
/// </summary>
constexpr auto DMG_GIB_CORPSE = DMG_CRUSH | DMG_FALL | DMG_BLAST | DMG_SONIC | DMG_CLUB;

/// <summary>
/// <para>These are the damage types that have client hud art.</para>
/// </summary>
constexpr auto DMG_SHOWN_HUD = DMG_POISON | DMG_ACID | DMG_FREEZE | DMG_SLOW_FREEZE | DMG_DROWN | DMG_BURN |
	DMG_SLOW_BURN | DMG_NERVE_GAS | DMG_RADIATION | DMG_SHOCK;

//
// When calling KILLED(), a value that governs gib behavior is expected to be one of these three values.
//

/// <summary>
/// <para>Gib if entity was overkilled.</para>
/// </summary>
constexpr auto GIB_NORMAL = 0;

/// <summary>
/// <para>Never gib, no matter how much death damage is done (freezing, etc).</para>
/// </summary>
constexpr auto GIB_NEVER = 1;

/// <summary>
/// <para>Always gib (Houndeye Shock, Barnacle Bite).</para>
/// </summary>
constexpr auto GIB_ALWAYS = 2;

/// <summary>
/// </summary>
constexpr auto GIB_HEALTH_VALUE = -30;

/// <summary>
/// Enum Classify
/// </summary>
enum class Classify {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Machine,

	/// <summary>
	/// </summary>
	Player,

	/// <summary>
	/// </summary>
	HumanPassive,

	/// <summary>
	/// </summary>
	HumanMilitary,

	/// <summary>
	/// </summary>
	AlienMilitary,

	/// <summary>
	/// </summary>
	AlienPassive,

	/// <summary>
	/// </summary>
	AlienMonster,

	/// <summary>
	/// </summary>
	AlienPrey,

	/// <summary>
	/// </summary>
	AlienPredator,

	/// <summary>
	/// </summary>
	Insect,

	/// <summary>
	/// </summary>
	PlayerAlly,

	/// <summary>
	/// <para>Hornets and snarks. Launched by players.</para>
	/// </summary>
	PlayerBioWeapon,

	/// <summary>
	/// <para>Hornets and snarks. Launched by the alien menace.</para>
	/// </summary>
	AlienBioWeapon,

	/// <summary>
	/// </summary>
	Vehicle,

	/// <summary>
	/// <para>Special because no one pays attention to it, and it eats a wide cross-section of creatures.</para>
	/// </summary>
	Barnacle = 99
};
