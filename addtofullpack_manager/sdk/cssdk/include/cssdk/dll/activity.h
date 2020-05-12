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
/// Enum Activity
/// </summary>
enum class Activity {
	/// <summary>
	/// </summary>
	Invalid = -1,

	/// <summary>
	/// <para>Set activity to this invalid value to force a reset to ideal_activity.</para>
	/// </summary>
	Reset = 0,

	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Guard,

	/// <summary>
	/// </summary>
	Walk,

	/// <summary>
	/// </summary>
	Run,

	/// <summary>
	/// <para>Fly (and flap if appropriate).</para>
	/// </summary>
	Fly,

	/// <summary>
	/// </summary>
	Swim,

	/// <summary>
	/// <para>Vertical jump.</para>
	/// </summary>
	Hop,

	/// <summary>
	/// <para>Long forward jump.</para>
	/// </summary>
	Leap,

	/// <summary>
	/// </summary>
	Fall,

	/// <summary>
	/// </summary>
	Land,

	/// <summary>
	/// </summary>
	StrafeLeft,

	/// <summary>
	/// </summary>
	StrafeRight,

	/// <summary>
	/// <para>Tuck and roll, left.</para>
	/// </summary>
	RollLeft,

	/// <summary>
	/// <para>Tuck and roll, right.</para>
	/// </summary>
	RollRight,

	/// <summary>
	/// <para>Turn quickly left (stationary).</para>
	/// </summary>
	TurnLeft,

	/// <summary>
	/// <para>Turn quickly right (stationary).</para>
	/// </summary>
	TurnRight,

	/// <summary>
	/// <para>The act of crouching down from a standing position.</para>
	/// </summary>
	Crouch,

	/// <summary>
	/// <para>Holding body in crouched position (loops).</para>
	/// </summary>
	CrouchIdle,

	/// <summary>
	/// <para>The act of standing from a crouched position.</para>
	/// </summary>
	Stand,

	/// <summary>
	/// </summary>
	Use,

	/// <summary>
	/// </summary>
	Signal1,

	/// <summary>
	/// </summary>
	Signal2,

	/// <summary>
	/// </summary>
	Signal3,

	/// <summary>
	/// </summary>
	Twitch,

	/// <summary>
	/// </summary>
	Cower,

	/// <summary>
	/// </summary>
	SmallFlinch,

	/// <summary>
	/// </summary>
	BigFlinch,

	/// <summary>
	/// </summary>
	RangeAttack1,

	/// <summary>
	/// </summary>
	RangeAttack2,

	/// <summary>
	/// </summary>
	MeleeAttack1,

	/// <summary>
	/// </summary>	
	MeleeAttack2,

	/// <summary>
	/// </summary>
	Reload,

	/// <summary>
	/// <para>Pull out gun, for instance.</para>
	/// </summary>
	Arm,

	/// <summary>
	/// <para>Reholster gun.</para>
	/// </summary>
	Disarm,

	/// <summary>
	/// <para>Monster chowing on a large food item (loop).</para>
	/// </summary>
	Eat,

	/// <summary>
	/// </summary>
	DieSimple,

	/// <summary>
	/// </summary>
	DieBackward,

	/// <summary>
	/// </summary>
	DieForward,

	/// <summary>
	/// </summary>
	DieViolent,

	/// <summary>
	/// <para>Barnacle tongue hits a monster.</para>
	/// </summary>
	BarnacleHit,

	/// <summary>
	/// <para>Barnacle is lifting the monster (loop).</para>
	/// </summary>
	BarnaclePull,

	/// <summary>
	/// <para>Barnacle latches on to the monster.</para>
	/// </summary>
	BarnacleChomp,

	/// <summary>
	/// <para>Barnacle is holding the monster in its mouth (loop).</para>
	/// </summary>
	BarnacleChew,

	/// <summary>
	/// </summary>
	Sleep,

	/// <summary>
	/// <para>For active idles, look at something on or near the floor.</para>
	/// </summary>
	InspectFloor,

	/// <summary>
	/// <para>For active idles, look at something directly ahead of you (doesn't HAVE to be a wall or on a wall).</para>
	/// </summary>
	InspectWall,

	/// <summary>
	/// <para>Alternate idle animation in which the monster is clearly agitated. (loop).</para>
	/// </summary>
	IdleAngry,

	/// <summary>
	/// <para>Limp (loop).</para>
	/// </summary>
	WalkHurt,

	/// <summary>
	/// <para>Limp (loop).</para>
	/// </summary>
	RunHurt,

	/// <summary>
	/// <para>Idle while in flight.</para>
	/// </summary>
	Hover,

	/// <summary>
	/// <para>Fly (don't flap).</para>
	/// </summary>
	Glide,

	/// <summary>
	/// <para>Turn left in flight.</para>
	/// </summary>
	FlyLeft,

	/// <summary>
	/// <para>Turn right in flight.</para>
	/// </summary>
	FlyRight,

	/// <summary>
	/// <para>This means the monster smells a scent carried by the air.</para>
	/// </summary>
	DetectScent,

	/// <summary>
	/// <para>This is the act of actually sniffing an item in front of the monster.</para>
	/// </summary>
	Sniff,

	/// <summary>
	/// <para>Some large monsters can eat small things in one bite. This plays one time, EAT loops.</para>
	/// </summary>
	Bite,

	/// <summary>
	/// <para>Without attacking, monster demonstrates that it is angry. (Yell, stick out chest, etc).</para>
	/// </summary>
	ThreatDisplay,

	/// <summary>
	/// <para>Monster just saw something that it is afraid of.</para>
	/// </summary>
	FearDisplay,

	/// <summary>
	/// <para>For some reason, monster is excited. Sees something he really likes to eat, or whatever.</para>
	/// </summary>
	Excited,

	/// <summary>
	/// <para>Very monster specific special attacks.</para>
	/// </summary>
	SpecialAttack1,

	/// <summary>
	/// </summary>
	SpecialAttack2,

	/// <summary>
	/// <para>Agitated idle.</para>
	/// </summary>
	CombatIdle,

	/// <summary>
	/// </summary>
	WalkScared,

	/// <summary>
	/// </summary>
	RunScared,

	/// <summary>
	/// <para>Killed a player, do a victory dance.</para>
	/// </summary>
	VictoryDance,

	/// <summary>
	/// <para>Die, hit in head.</para>
	/// </summary>
	DieHeadShot,

	/// <summary>
	/// <para>Die, hit in chest.</para>
	/// </summary>
	DieChestShot,

	/// <summary>
	/// <para>Die, hit in gut.</para>
	/// </summary>
	DieGutShot,

	/// <summary>
	/// <para>Die, hit in back.</para>
	/// </summary>
	DieBackShot,

	/// <summary>
	/// </summary>
	FlinchHead,

	/// <summary>
	/// </summary>
	FlinchChest,

	/// <summary>
	/// </summary>
	FlinchStomach,

	/// <summary>
	/// </summary>
	FlinchLeftArm,

	/// <summary>
	/// </summary>
	FlinchRightArm,

	/// <summary>
	/// </summary>
	FlinchLeftLeg,

	/// <summary>
	/// </summary>
	FlinchRightLeg,

	/// <summary>
	/// </summary>
	Flinch,

	/// <summary>
	/// </summary>
	LargeFlinch,

	/// <summary>
	/// </summary>
	HoldBomb,

	/// <summary>
	/// </summary>
	IdleFidget,

	/// <summary>
	/// </summary>
	IdleScared,

	/// <summary>
	/// </summary>
	IdleScaredFidget,

	/// <summary>
	/// </summary>
	FollowIdle,

	/// <summary>
	/// </summary>
	FollowIdleFidget,

	/// <summary>
	/// </summary>
	FollowIdleScared,

	/// <summary>
	/// </summary>
	FollowIdleScaredFidget,

	/// <summary>
	/// </summary>
	CrouchIdle2,

	/// <summary>
	/// </summary>
	CrouchIdleFidget,

	/// <summary>
	/// </summary>
	CrouchIdleScared,

	/// <summary>
	/// </summary>
	CrouchIdleScaredFidget,

	/// <summary>
	/// </summary>
	CrouchWalk,

	/// <summary>
	/// </summary>
	CrouchWalkScared,

	/// <summary>
	/// </summary>
	CrouchDie,

	/// <summary>
	/// </summary>
	WalkBack,

	/// <summary>
	/// </summary>
	IdleSneaky,

	/// <summary>
	/// </summary>
	IdleSneakyFidget,

	/// <summary>
	/// </summary>
	WalkSneaky,

	/// <summary>
	/// </summary>
	Wave,

	/// <summary>
	/// </summary>
	Yes,

	/// <summary>
	/// </summary>
	No
};
