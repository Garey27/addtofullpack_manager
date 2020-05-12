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
/// <para>Max # of clients allowed in a server.</para>
/// </summary>
constexpr auto MAX_CLIENTS = 32;

/// <summary>
/// </summary>
constexpr auto MAX_RESOURCE_PATH_LENGTH = 64;

//
//	Volume values.
//

/// <summary>
/// </summary>
constexpr auto VOL_NORM = 1.0f;

//
//	Attenuation values.
//

/// <summary>
/// </summary>
constexpr auto ATTN_NONE = 0.0f;

/// <summary>
/// </summary>
constexpr auto ATTN_NORM = 0.8f;

/// <summary>
/// </summary>
constexpr auto ATTN_STATIC = 1.25f;

/// <summary>
/// </summary>
constexpr auto ATTN_IDLE = 2.0f;

//
//	Pitch values.
//

/// <summary>
/// </summary>
constexpr auto PITCH_LOW = 95;

/// <summary>
/// </summary>
constexpr auto PITCH_NORM = 100;

/// <summary>
/// </summary>
constexpr auto PITCH_HIGH = 120;

//
//	Temp entity events.
//

/// <summary>
/// <para>Beam effect between two points.</para>
/// </summary>
constexpr auto TE_BEAM_POINTS = 0;

/// <summary>
/// <para>Beam effect between point and entity.</para>
/// </summary>
constexpr auto TE_BEAM_ENT_POINT = 1;

/// <summary>
/// <para>Particle effect plus ricochet sound.</para>
/// </summary>
constexpr auto TE_GUNSHOT = 2;

/// <summary>
/// <para>Additive sprite, 2 dynamic lights, flickering particles, explosion sound, move vertically 8 pps.</para>
/// </summary>
constexpr auto TE_EXPLOSION = 3;

/// <summary>
/// <para>Quake 1 "tarbaby" explosion with sound.</para>
/// </summary>
constexpr auto TE_TAR_EXPLOSION = 4;

/// <summary>
/// <para>Alphablend sprite, move vertically 30 pps.</para>
/// </summary>
constexpr auto TE_SMOKE = 5;

/// <summary>
/// <para>Tracer effect from point to point.</para>
/// </summary>
constexpr auto TE_TRACER = 6;

/// <summary>
/// <para>TE_BEAM_POINTS with simplified parameters.</para>
/// </summary>
constexpr auto TE_LIGHTNING = 7;

/// <summary>
/// </summary>
constexpr auto TE_BEAM_ENTITIES = 8;

/// <summary>
/// <para>8 random tracers with gravity, ricochet sprite.</para>
/// </summary>
constexpr auto TE_SPARKS = 9;

/// <summary>
/// <para>Quake 1 lava splash.</para>
/// </summary>
constexpr auto TE_LAVA_SPLASH = 10;

/// <summary>
/// <para>Quake 1 teleport splash.</para>
/// </summary>
constexpr auto TE_TELEPORT = 11;

/// <summary>
/// <para>Quake 1 colormaped (base palette) particle explosion with sound.</para>
/// </summary>
constexpr auto TE_EXPLOSION2 = 12;

/// <summary>
/// <para>Decal from the .BSP file.</para>
/// </summary>
constexpr auto TE_BSP_DECAL = 13;

/// <summary>
/// <para>Tracers moving toward a point.</para>
/// </summary>
constexpr auto TE_IMPLOSION = 14;

/// <summary>
/// <para>Line of moving glow sprites with gravity, fadeout, and collisions.</para>
/// </summary>
constexpr auto TE_SPRITE_TRAIL = 15;

/// <summary>
/// <para>Obsolete.</para>
/// </summary>
constexpr auto TE_BEAM = 16;

/// <summary>
/// <para>Additive sprite, plays 1 cycle.</para>
/// </summary>
constexpr auto TE_SPRITE = 17;

/// <summary>
/// <para>A beam with a sprite at the end.</para>
/// </summary>
constexpr auto TE_BEAM_SPRITE = 18;

/// <summary>
/// <para>Screen aligned beam ring, expands to max radius over lifetime.</para>
/// </summary>
constexpr auto TE_BEAM_TORUS = 19;

/// <summary>
/// <para>Disk that expands to max radius over lifetime.</para>
/// </summary>
constexpr auto TE_BEAM_DISK = 20;

/// <summary>
/// <para>Cylinder that expands to max radius over lifetime.</para>
/// </summary>
constexpr auto TE_BEAM_CYLINDER = 21;

/// <summary>
/// <para>Create a line of decaying beam segments until entity stops moving.</para>
/// </summary>
constexpr auto TE_BEAM_FOLLOW = 22;

/// <summary>
/// </summary>
constexpr auto TE_GLOW_SPRITE = 23;

/// <summary>
/// <para>Connect a beam ring to two entities.</para>
/// </summary>
constexpr auto TE_BEAM_RING = 24;

/// <summary>
/// <para>Oriented shower of tracers.</para>
/// </summary>
constexpr auto TE_STREAK_SPLASH = 25;

/// <summary>
/// <para>Obsolete.</para>
/// </summary>
constexpr auto TE_BEAM_HOSE = 26;

/// <summary>
/// <para>Dynamic light, effect world, minor entity effect.</para>
/// </summary>
constexpr auto TE_DYN_LIGHT = 27;

/// <summary>
/// <para>Point entity light, no world effect.</para>
/// </summary>
constexpr auto TE_ENT_LIGHT = 28;

/// <summary>
/// </summary>
constexpr auto TE_TEXT_MESSAGE = 29;

/// <summary>
/// </summary>
constexpr auto TE_LINE = 30;

/// <summary>
/// </summary>
constexpr auto TE_BOX = 31;

/// <summary>
/// <para>Kill all beams attached to entity.</para>
/// </summary>
constexpr auto TE_KILL_BEAM = 99;

/// <summary>
/// </summary>
constexpr auto TE_LARGE_FUNNEL = 100;

/// <summary>
/// <para>Particle spray.</para>
/// </summary>
constexpr auto TE_BLOODSTREAM = 101;

/// <summary>
/// <para>Line of particles every 5 units, dies in 30 seconds.</para>
/// </summary>
constexpr auto TE_SHOW_LINE = 102;

/// <summary>
/// <para>Particle spray.</para>
/// </summary>
constexpr auto TE_BLOOD = 103;

/// <summary>
/// <para>Decal applied to a brush entity (not the world).</para>
/// </summary>
constexpr auto TE_DECAL = 104;

/// <summary>
/// <para>Create alpha sprites inside of entity, float upwards.</para>
/// </summary>
constexpr auto TE_FIZZ = 105;

/// <summary>
/// <para>Create a moving model that bounces and makes a sound when it hits.</para>
/// </summary>
constexpr auto TE_MODEL = 106;

/// <summary>
/// <para>Spherical shower of models, picks from set.</para>
/// </summary>
constexpr auto TE_EXPLODE_MODEL = 107;

/// <summary>
/// <para>Box of models or sprites.</para>
/// </summary>
constexpr auto TE_BREAK_MODEL = 108;

/// <summary>
/// <para>Decal and ricochet sound.</para>
/// </summary>
constexpr auto TE_GUNSHOT_DECAL = 109;

/// <summary>
/// <para>Spray of alpha sprites.</para>
/// </summary>
constexpr auto TE_SPRITE_SPRAY = 110;

/// <summary>
/// <para>Quick spark sprite, client ricochet sound.</para>
/// </summary>
constexpr auto TE_ARMOR_RICOCHET = 111;

/// <summary>
/// </summary>
constexpr auto TE_PLAYER_DECAL = 112;

/// <summary>
/// <para>Create alpha sprites inside of box, float upwards.</para>
/// </summary>
constexpr auto TE_BUBBLES = 113;

/// <summary>
/// <para>Create alpha sprites along a line, float upwards.</para>
/// </summary>
constexpr auto TE_BUBBLE_TRAIL = 114;

/// <summary>
/// <para>Spray of opaque sprite1's that fall, single sprite2 for 1..2 secs (this is a high-priority temp entity).</para>
/// </summary>
constexpr auto TE_BLOOD_SPRITE = 115;

/// <summary>
/// <para>Decal applied to the world brush.</para>
/// </summary>
constexpr auto TE_WORLD_DECAL = 116;

/// <summary>
/// <para>Decal (with texture index > 256) applied to world brush.</para>
/// </summary>
constexpr auto TE_WORLD_DECAL_HIGH = 117;

/// <summary>
/// <para>Same as TE_DECAL, but the texture index was greater than 256.</para>
/// </summary>
constexpr auto TE_DECAL_HIGH = 118;

/// <summary>
/// <para>Makes a projectile (like a nail) (this is a high-priority temp entity).</para>
/// </summary>
constexpr auto TE_PROJECTILE = 119;

/// <summary>
/// <para>Throws a shower of sprites or models.</para>
/// </summary>
constexpr auto TE_SPRAY = 120;

/// <summary>
/// <para>Sprites emit from a player's bounding box (ONLY use for players!).</para>
/// </summary>
constexpr auto TE_PLAYER_SPRITES = 121;

/// <summary>
/// <para>Very similar to <c>TE_LAVA_SPLASH</c>.</para>
/// </summary>
constexpr auto TE_PARTICLE_BURST = 122;

/// <summary>
/// <para>Makes a field of fire.</para>
/// </summary>
constexpr auto TE_FIRE_FIELD = 123;

/// <summary>
/// <para>Attaches a temp entity to a player (this is a high-priority temp entity).</para>
/// </summary>
constexpr auto TE_PLAYER_ATTACHMENT = 124;

/// <summary>
/// <para>Will expire all TENTS attached to a player..</para>
/// </summary>
constexpr auto TE_KILL_PLAYER_ATTACHMENTS = 125;

/// <summary>
/// <para>Much more compact shotgun message.</para>
/// </summary>
constexpr auto TE_MULTI_GUNSHOT = 126;

/// <summary>
/// <para>Larger message than the standard tracer, but allows some customization.</para>
/// </summary>
constexpr auto TE_USER_TRACER = 127;

//
//	Temp entity bounce sound types.
//

/// <summary>
/// </summary>
constexpr auto TE_BOUNCE_NULL = 0;

/// <summary>
/// </summary>
constexpr auto TE_BOUNCE_SHELL = 1;

/// <summary>
/// </summary>
constexpr auto TE_BOUNCE_SHOT_SHELL = 2;

//
//	The explosion effect has some flags to control performance/aesthetic features.
//

/// <summary>
/// <para>All flags clear makes default Half-Life explosion.</para>
/// </summary>
constexpr auto TE_EXPL_FLAG_NONE = 0;

/// <summary>
/// <para>Sprite will be drawn opaque (ensure that the sprite you send is a non-additive sprite).</para>
/// </summary>
constexpr auto TE_EXPL_FLAG_NO_ADDITIVE = 1;

/// <summary>
/// <para>Do not render dynamic lights.</para>
/// </summary>
constexpr auto TE_EXPL_FLAG_NO_DYN_LIGHTS = 2;

/// <summary>
/// <para>Do not play client explosion sound.</para>
/// </summary>
constexpr auto TE_EXPL_FLAG_NO_SOUND = 4;

/// <summary>
/// <para>Do not draw particles.</para>
/// </summary>
constexpr auto TE_EXPL_FLAG_NO_PARTICLES = 8;

//
// Event flags.
//

/// <summary>
/// <para>Skip local host for event send.</para>
/// </summary>
constexpr auto FEV_NOT_HOST = 1 << 0;

/// <summary>
/// <para>Send the event reliably.<br/>
/// You must specify the origin and angles and use <c>playback_event</c>
/// for this to work correctly on the server for anything that depends on the event origin/angles.<br/>
/// I.e., the origin/angles are not taken from the invoking edict for reliable events.</para>
/// </summary>
constexpr auto FEV_RELIABLE = 1 << 1;

/// <summary>
/// <para>Don't restrict to PAS/PVS, send this event to _everybody_ on the server
/// (useful for stopping <c>SoundChannel::Static</c> sounds started by client event when client is not in PVS anymore (hwguy in TFC e.g.).</para>
/// </summary>
constexpr auto FEV_GLOBAL = 1 << 2;

/// <summary>
/// <para>If this client already has one of these events in its queue, just update the event instead of sending it as a duplicate.</para>
/// </summary>
constexpr auto FEV_UPDATE = 1 << 3;

/// <summary>
/// <para>Only send to entity specified as the invoker.</para>
/// </summary>
constexpr auto FEV_HOST_ONLY = 1 << 4;

/// <summary>
/// <para>Only send if the event was created on the server.</para>
/// </summary>
constexpr auto FEV_SERVER = 1 << 5;

/// <summary>
/// <para>Only issue event client side (from shared code).</para>
/// </summary>
constexpr auto FEV_CLIENT = 1 << 6;

//
//	Entity effects.
//

/// <summary>
/// <para>Swirling cloud of particles.</para>
/// </summary>
constexpr auto EF_BRIGHT_FIELD = 1 << 0;

/// <summary>
/// <para>Single frame ELIGHT on entity attachment 0.</para>
/// </summary>
constexpr auto EF_MUZZLE_FLASH = 1 << 1;

/// <summary>
/// <para>DLIGHT centered at entity origin.</para>
/// </summary>
constexpr auto EF_BRIGHT_LIGHT = 1 << 2;

/// <summary>
/// <para>Player flashlight.</para>
/// </summary>
constexpr auto EF_DIM_LIGHT = 1 << 3;

/// <summary>
/// <para>Get lighting from ceiling.</para>
/// </summary>
constexpr auto EF_INV_LIGHT = 1 << 4;

/// <summary>
/// <para>Don't interpolate the next frame.</para>
/// </summary>
constexpr auto EF_NO_INTERPOLATE = 1 << 5;

/// <summary>
/// <para>Rocket flare glow sprite.</para>
/// </summary>
constexpr auto EF_LIGHT = 1 << 6;

/// <summary>
/// <para>Don't draw entity.</para>
/// </summary>
constexpr auto EF_NO_DRAW = 1 << 7;

/// <summary>
/// <para>Player night vision.</para>
/// </summary>
constexpr auto EF_NIGHT_VISION = 1 << 8;

/// <summary>
/// <para>Sniper laser effect.</para>
/// </summary>
constexpr auto EF_SNIPER_LASER = 1 << 9;

/// <summary>
/// <para>Fiber camera.</para>
/// </summary>
constexpr auto EF_FIBER_CAMERA = 1 << 10;

/// <summary>
/// </summary>
constexpr auto EF_FORCE_VISIBILITY = 1 << 11;

/// <summary>
/// </summary>
constexpr auto EF_OWNER_VISIBILITY = 1 << 12;

/// <summary>
/// </summary>
constexpr auto EF_OWNER_NO_VISIBILITY = 1 << 13;

//
//	Take damage mode.
//

/// <summary>
/// Don't take damage.
/// </summary>
constexpr auto DAMAGE_NO = 0;

/// <summary>
/// Take damage.
/// </summary>
constexpr auto DAMAGE_YES = 1;

/// <summary>
/// Take damage, auto aim should snap to this target.
/// </summary>
constexpr auto DAMAGE_AIM = 2;

//
//	Buttons.
//

/// <summary>
/// </summary>
constexpr auto IN_ATTACK = 1 << 0;

/// <summary>
/// </summary>
constexpr auto IN_JUMP = 1 << 1;

/// <summary>
/// </summary>
constexpr auto IN_DUCK = 1 << 2;

/// <summary>
/// </summary>
constexpr auto IN_FORWARD = 1 << 3;

/// <summary>
/// </summary>
constexpr auto IN_BACK = 1 << 4;

/// <summary>
/// </summary>
constexpr auto IN_USE = 1 << 5;

/// <summary>
/// </summary>
constexpr auto IN_CANCEL = 1 << 6;

/// <summary>
/// </summary>
constexpr auto IN_LEFT = 1 << 7;

/// <summary>
/// </summary>
constexpr auto IN_RIGHT = 1 << 8;

/// <summary>
/// </summary>
constexpr auto IN_MOVE_LEFT = 1 << 9;

/// <summary>
/// </summary>
constexpr auto IN_MOVE_RIGHT = 1 << 10;

/// <summary>
/// </summary>
constexpr auto IN_ATTACK2 = 1 << 11;

/// <summary>
/// </summary>
constexpr auto IN_RUN = 1 << 12;

/// <summary>
/// </summary>
constexpr auto IN_RELOAD = 1 << 13;

/// <summary>
/// </summary>
constexpr auto IN_ALT1 = 1 << 14;

/// <summary>
/// <para>Used by client.dll for when scoreboard is held down.</para>
/// </summary>
constexpr auto IN_SCORE = 1 << 15;

//
//	Entity flags.
//

/// <summary>
/// <para>Changes the <c>SV_Movestep()</c> behavior to not need to be on ground.</para>
/// </summary>
constexpr auto FL_FLY = 1 << 0;

/// <summary>
/// <para>Changes the <c>SV_Movestep()</c> behavior to not need to be on ground (but stay in water).</para>
/// </summary>
constexpr auto FL_SWIM = 1 << 1;

/// <summary>
/// </summary>
constexpr auto FL_CONVEYOR = 1 << 2;

/// <summary>
/// </summary>
constexpr auto FL_CLIENT = 1 << 3;

/// <summary>
/// </summary>
constexpr auto FL_IN_WATER = 1 << 4;

/// <summary>
/// </summary>
constexpr auto FL_MONSTER = 1 << 5;

/// <summary>
/// </summary>
constexpr auto FL_GOD_MODE = 1 << 6;

/// <summary>
/// </summary>
constexpr auto FL_NO_TARGET = 1 << 7;

/// <summary>
/// <para>Don't send entity to local host, it's predicting this entity itself.</para>
/// </summary>
constexpr auto FL_SKIP_LOCAL_HOST = 1 << 8;

/// <summary>
/// <para>At rest / on the ground.</para>
/// </summary>
constexpr auto FL_ON_GROUND = 1 << 9;

/// <summary>
/// <para>Not all corners are valid.</para>
/// </summary>
constexpr auto FL_PARTIAL_GROUND = 1 << 10;

/// <summary>
/// <para>Player jumping out of water.</para>
/// </summary>
constexpr auto FL_WATER_JUMP = 1 << 11;

/// <summary>
/// <para>Player is frozen for 3rd person camera.</para>
/// </summary>
constexpr auto FL_FROZEN = 1 << 12;

/// <summary>
/// <para>Fake client, simulated server side; don't send network messages to them.</para>
/// </summary>
constexpr auto FL_FAKE_CLIENT = 1 << 13;

/// <summary>
/// <para>Player flag -- Player is fully crouched.</para>
/// </summary>
constexpr auto FL_DUCKING = 1 << 14;

/// <summary>
/// <para>Apply floating force to this entity when in water.</para>
/// </summary>
constexpr auto FL_FLOAT = 1 << 15;

/// <summary>
/// <para>World graph has this entity listed as something that blocks a connection.</para>
/// </summary>
constexpr auto FL_GRAPHED = 1 << 16;

/// <summary>
/// </summary>
constexpr auto FL_IMMUNE_WATER = 1 << 17;

/// <summary>
/// </summary>
constexpr auto FL_IMMUNE_SLIME = 1 << 18;

/// <summary>
/// </summary>
constexpr auto FL_IMMUNE_LAVA = 1 << 19;

/// <summary>
/// <para>This is a spectator proxy.</para>
/// </summary>
constexpr auto FL_PROXY = 1 << 20;

/// <summary>
/// <para>Brush model flag -- call think every frame regardless of next_think - last_think (for constantly changing velocity/path).</para>
/// </summary>
constexpr auto FL_ALWAYS_THINK = 1 << 21;

/// <summary>
/// <para>Base velocity has been applied this frame (used to convert base velocity into momentum).</para>
/// </summary>
constexpr auto FL_BASE_VELOCITY = 1 << 22;

/// <summary>
/// <para>Only collide in with monsters who have FL_MONSTER_CLIP set.</para>
/// </summary>
constexpr auto FL_MONSTER_CLIP = 1 << 23;

/// <summary>
/// <para>Player is _controlling_ a train, so movement commands should be ignored on client during prediction.</para>
/// </summary>
constexpr auto FL_ON_TRAIN = 1 << 24;

/// <summary>
/// <para>Not moveable/removeable brush entity (really part of the world, but represented as an entity for transparency or something).</para>
/// </summary>
constexpr auto FL_WORLD_BRUSH = 1 << 25;

/// <summary>
/// <para>This client is a spectator, don't run touch functions, etc.</para>
/// </summary>
constexpr auto FL_SPECTATOR = 1 << 26;

/// <summary>
/// <para>This is a custom entity.</para>
/// </summary>
constexpr auto FL_CUSTOM_ENTITY = 1 << 29;

/// <summary>
/// <para>This entity is marked for death -- This allows the engine to kill entities at the appropriate time.</para>
/// </summary>
constexpr auto FL_KILL_ME = 1 << 30;

/// <summary>
/// <para>Entity is dormant, no updates to client.</para>
/// </summary>
constexpr auto FL_DORMANT = 1 << 31;

/// <summary>
/// Enum SoundChannel
/// </summary>
enum class SoundChannel {
	/// <summary>
	/// </summary>
	Auto = 0,

	/// <summary>
	/// </summary>
	Weapon,

	/// <summary>
	/// </summary>
	Voice,

	/// <summary>
	/// </summary>
	Item,

	/// <summary>
	/// </summary>
	Body,

	/// <summary>
	/// <para>Allocate stream channel from the static or dynamic area.</para>
	/// </summary>
	Stream,

	/// <summary>
	/// <para>Allocate channel from the static area.</para>
	/// </summary>
	Static,

	/// <summary>
	/// <para>Voice data coming across the network.</para>
	/// </summary>
	NetworkVoiceBase,

	/// <summary>
	/// <para>Network voice data reserves slots (c_network_voice_base through c_network_voice_end).</para>
	/// </summary>
	NetworkVoiceEnd = 500,

	/// <summary>
	/// </summary>
	Bot
};

/// <summary>
/// Enum WalkMoveMode
/// </summary>
enum class WalkMoveMode {
	/// <summary>
	/// <para>Normal walk move.</para>
	/// </summary>
	Normal = 0,

	/// <summary>
	/// <para>Doesn't hit ANY entities, no matter what the solid type.</para>
	/// </summary>
	WorldOnly,

	/// <summary>
	/// <para>Move, but don't touch triggers.</para>
	/// </summary>
	CheckOnly
};

/// <summary>
/// Enum MoveTypeEntity
/// </summary>
enum class MoveTypeEntity {
	/// <summary>
	/// <para>Never moves.</para>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	//AngleNoClip,

	/// <summary>
	/// </summary>
	//AngleClip,

	/// <summary>
	/// <para>Player only - moving on the ground.</para>
	/// </summary>
	Walk = 3,

	/// <summary>
	/// <para>Gravity, special edge handling - monsters use this.</para>
	/// </summary>
	Step,

	/// <summary>
	/// <para>No gravity, but still collides with stuff.</para>
	/// </summary>
	Fly,

	/// <summary>
	/// <para>Gravity/collisions.</para>
	/// </summary>
	Toss,

	/// <summary>
	/// <para>No clip to world, push and crush.</para>
	/// </summary>
	Push,

	/// <summary>
	/// <para>No gravity, no collisions, still do velocity.</para>
	/// </summary>
	NoClip,

	/// <summary>
	/// <para>Extra size to monsters.</para>
	/// </summary>
	FlyMissile,

	/// <summary>
	/// <para>Just like Toss, but reflect velocity when contacting surfaces.</para>
	/// </summary>
	Bounce,

	/// <summary>
	/// <para>Bounce without gravity.</para>
	/// </summary>
	BounceMissile,

	/// <summary>
	/// <para>Track movement of aim entity.</para>
	/// </summary>
	Follow,

	/// <summary>
	/// <para>BSP model that needs physics/world collisions (uses nearest hull for world collision).</para>
	/// </summary>
	PushStep
};

/// <summary>
/// Enum MessageType
/// </summary>
enum class MessageType : int {
	/// <summary>
	/// <para>Unreliable to all.</para>
	/// </summary>
	Broadcast = 0,

	/// <summary>
	/// <para>Reliable to one (msg_entity).</para>
	/// </summary>
	One,

	/// <summary>
	/// <para>Reliable to all.</para>
	/// </summary>
	All,

	/// <summary>
	/// <para>Write to the init string.</para>
	/// </summary>
	Init,

	/// <summary>
	/// <para>Entities in PVS of origin.</para>
	/// </summary>
	Pvs,

	/// <summary>
	/// <para>Entities in PAS of origin.</para>
	/// </summary>
	Pas,

	/// <summary>
	/// <para>Reliable to PVS.</para>
	/// </summary>
	PvsReliable,

	/// <summary>
	/// <para>Reliable to PAS.</para>
	/// </summary>
	PasReliable,

	/// <summary>
	/// <para>Send to one client, but don't put in reliable stream, put in unreliable datagram (could be dropped).</para>
	/// </summary>
	OneUnreliable,

	/// <summary>
	/// <para>Sends to all spectator proxies.</para>
	/// </summary>
	Spec
};

/// <summary>
/// Enum SvcMessage
/// </summary>
enum class SvcMessage : int {
	/// <summary>
	/// </summary>
	Bad = 0,

	/// <summary>
	/// </summary>
	Nop,

	/// <summary>
	/// </summary>
	Disconnect,

	/// <summary>
	/// </summary>
	Event,

	/// <summary>
	/// </summary>
	Version,

	/// <summary>
	/// </summary>
	SetView,

	/// <summary>
	/// </summary>
	Sound,

	/// <summary>
	/// </summary>
	Time,

	/// <summary>
	/// </summary>
	Print,

	/// <summary>
	/// </summary>
	StuffText,

	/// <summary>
	/// </summary>
	SetAngle,

	/// <summary>
	/// </summary>
	ServerInfo,

	/// <summary>
	/// </summary>
	LightStyle,

	/// <summary>
	/// </summary>
	UpdateUserInfo,

	/// <summary>
	/// </summary>
	DeltaDescription,

	/// <summary>
	/// </summary>
	ClientData,

	/// <summary>
	/// </summary>
	StopSound,

	/// <summary>
	/// </summary>
	Pings,

	/// <summary>
	/// </summary>
	Particle,

	/// <summary>
	/// </summary>
	Damage,

	/// <summary>
	/// </summary>
	SpawnStatic,

	/// <summary>
	/// </summary>
	EventReliable,

	/// <summary>
	/// </summary>
	SpawnBaseline,

	/// <summary>
	/// </summary>
	TempEntity,

	/// <summary>
	/// </summary>
	SetPause,

	/// <summary>
	/// </summary>
	SignonNum,

	/// <summary>
	/// </summary>
	CenterPrint,

	/// <summary>
	/// </summary>
	KilledMonster,

	/// <summary>
	/// </summary>
	FoundSecret,

	/// <summary>
	/// </summary>
	SpawnStaticSound,

	/// <summary>
	/// </summary>
	Intermission,

	/// <summary>
	/// </summary>
	Finale,

	/// <summary>
	/// </summary>
	CdTrack,

	/// <summary>
	/// </summary>
	Restore,

	/// <summary>
	/// </summary>
	CutScene,

	/// <summary>
	/// </summary>
	WeaponAnim,

	/// <summary>
	/// </summary>
	DecalName,

	/// <summary>
	/// </summary>
	RoomType,

	/// <summary>
	/// </summary>
	AddAngle,

	/// <summary>
	/// </summary>
	NewUserMsg,

	/// <summary>
	/// </summary>
	PacketEntities,

	/// <summary>
	/// </summary>
	DeltaPacketEntities,

	/// <summary>
	/// </summary>
	Choke,

	/// <summary>
	/// </summary>
	ResourceList,

	/// <summary>
	/// </summary>
	NewMoveVars,

	/// <summary>
	/// </summary>
	ResourceRequest,

	/// <summary>
	/// </summary>
	Customization,

	/// <summary>
	/// </summary>
	CrosshairAngle,

	/// <summary>
	/// </summary>
	SoundFade,

	/// <summary>
	/// </summary>
	FileTxferFailed,

	/// <summary>
	/// </summary>
	Hltv,

	/// <summary>
	/// </summary>
	Director,

	/// <summary>
	/// </summary>
	VoiceInit,

	/// <summary>
	/// </summary>
	VoiceData,

	/// <summary>
	/// </summary>
	SendExtraInfo,

	/// <summary>
	/// </summary>
	Timescale,

	/// <summary>
	/// </summary>
	ResourceLocation,

	/// <summary>
	/// </summary>
	SendCvarValue,

	/// <summary>
	/// </summary>
	SendCvarValue2,

	/// <summary>
	/// </summary>
	StartOfUserMessages = SendCvarValue2,

	/// <summary>
	/// </summary>
	EndOfList = 255
};

/// <summary>
/// Enum FixAngleMode
/// </summary>
enum class FixAngleMode {
	/// <summary>
	/// <para>Do nothing.</para>
	/// </summary>
	Nothing = 0,

	/// <summary>
	/// <para>Set view angles to <c>EntityVars::angles</c>.</para>
	/// </summary>
	ForceViewAngles,

	/// <summary>
	/// <para>Add angle velocity yaw value to view angles.<br/>
	/// Angle velocity yaw value is set to 0 after this.</para>
	/// </summary>
	AddAngleVelocity
};

/// <summary>
/// Enum SolidType<br/>
/// </summary>
/// <remarks>
/// Some move types will cause collisions independent of NotSolid/Trigger when the entity moves.<br/>
/// SOLID only effects OTHER entities colliding with this one when they move - UGH!
/// </remarks>
enum class SolidType {
	/// <summary>
	/// <para>No interaction with other objects.</para>
	/// </summary>
	NotSolid = 0,

	/// <summary>
	/// <para>Touch on edge, but not blocking.</para>
	/// </summary>
	Trigger,

	/// <summary>
	/// <para>Touch on edge, block.</para>
	/// </summary>
	BoundingBox,

	/// <summary>
	/// <para>Touch on edge, but not an on ground.</para>
	/// </summary>
	SlideBox,

	/// <summary>
	/// <para>BSP clip, touch on edge, block.</para>
	/// </summary>
	Bsp
};

/// <summary>
/// Enum Rendering
/// </summary>
enum class Rendering {
	/// <summary>
	/// <para>src.</para>
	/// </summary>
	Normal = 0,

	/// <summary>
	/// <para>c * a + dest * (1 - a).</para>
	/// </summary>
	TransColor,

	/// <summary>
	/// <para>src * a + dest * (1 - a).</para>
	/// </summary>
	TransTexture,

	/// <summary>
	/// <para>src * a + dest -- No Z buffer checks.</para>
	/// </summary>
	Glow,

	/// <summary>
	/// <para>src* srca + dest * (1 - srca).</para>
	/// </summary>
	TransAlpha,

	/// <summary>
	/// <para>src * a + dest.</para>
	/// </summary>
	TransAdd
};

/// <summary>
/// Enum RenderingFx
/// </summary>
enum class RenderingFx {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	PulseSlow,

	/// <summary>
	/// </summary>
	PulseFast,

	/// <summary>
	/// </summary>
	PulseSlowWide,

	/// <summary>
	/// </summary>
	PulseFastWide,

	/// <summary>
	/// </summary>
	FadeSlow,

	/// <summary>
	/// </summary>
	FadeFast,

	/// <summary>
	/// </summary>
	SolidSlow,

	/// <summary>
	/// </summary>
	SolidFast,

	/// <summary>
	/// </summary>
	StrobeSlow,

	/// <summary>
	/// </summary>
	StrobeFast,

	/// <summary>
	/// </summary>
	StrobeFaster,

	/// <summary>
	/// </summary>
	FlickerSlow,

	/// <summary>
	/// </summary>
	FlickerFast,

	/// <summary>
	/// </summary>
	NoDissipation,

	/// <summary>
	/// <para>Distort/scale/translate flicker.</para>
	/// </summary>
	Distort,

	/// <summary>
	/// <para><c>distort</c> + distance fade.</para>
	/// </summary>
	Hologram,

	/// <summary>
	/// </summary>
	DeadPlayer,

	/// <summary>
	/// <para>Scale up really big!</para>
	/// </summary>
	Explode,

	/// <summary>
	/// <para>Glowing shell.</para>
	/// </summary>
	GlowShell,

	/// <summary>
	/// <para>Keep this sprite from getting very small (SPRITES only!).</para>
	/// </summary>
	ClampMinScale,

	/// <summary>
	/// <para>CTM !!! CZERO added to tell the studio render that the value in i_user2 is a light_multiplier.</para>
	/// </summary>
	LightMultiplier
};

/// <summary>
/// Enum DeathState
/// </summary>
enum class DeathState {
	/// <summary>
	/// <para>Alive.</para>
	/// </summary>
	Alive = 0,

	/// <summary>
	/// <para>Playing death animation or still falling off of a ledge waiting to hit ground.</para>
	/// </summary>
	Dying,

	/// <summary>
	/// <para>Dead. Lying still.</para>
	/// </summary>
	Dead,

	/// <summary>
	/// <para>Dead, and can be respawned.</para>
	/// </summary>
	Respawnable,

	/// <summary>
	/// <para>Not used in the SDK, used by TFC for spies feigning death.</para>
	/// </summary>
	DiscardBody
};
