// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/decals.h>
#include <cssdk/dll/ext_defs.h>
#include <cssdk/dll/monster_event.h>
#include <cssdk/dll/regamedll_consts.h>
#include <cssdk/engine/eiface.h>
#include <cssdk/public/utils.h>
#include <cassert>
#include <cstddef>

/// <summary>
/// <para>Must be provided by user of this code.</para>
/// </summary>
extern EngineFuncPointers g_engine_funcs;

/// <summary>
/// <para>Maximum number of targets a single multi source entity may be assigned.</para>
/// </summary>
constexpr auto MAX_MS_TARGETS = 32;

/// <summary>
/// </summary>
constexpr auto SF_MULTI_INIT = 1 << 0;

/// <summary>
/// </summary>
constexpr auto SF_BUTTON_DONT_MOVE = 1 << 0;

/// <summary>
/// <para>Button stays pushed until reactivated.</para>
/// </summary>
constexpr auto SF_BUTTON_TOGGLE = 1 << 5;

/// <summary>
/// <para>Button sparks in OFF state.</para>
/// </summary>
constexpr auto SF_BUTTON_SPARK_IF_OFF = 1 << 6;

/// <summary>
/// <para>Button only fires as a result of USE key.</para>
/// </summary>
constexpr auto SF_BUTTON_TOUCH_ONLY = 1 << 8;

/// <summary>
/// Enum ButtonCode
/// </summary>
enum class ButtonCode {
	/// <summary>
	/// </summary>
	ButtonNothing = 0,

	/// <summary>
	/// </summary>
	ButtonActivate,

	/// <summary>
	/// </summary>
	ButtonReturn
};

/// <summary>
/// </summary>
class MonsterBase;

/// <summary>
/// </summary>
class SquadMonster;

/// <summary>
/// </summary>
class PlayerItemBase;

#ifdef REGAMEDLL_API
/// <summary>
/// </summary>
class CsEntity;
#endif

/// <summary>
/// Class EntityBase.
/// </summary>
class EntityBase {
public:
	/// <summary>
	/// </summary>
	virtual void spawn() = 0;

	/// <summary>
	/// </summary>
	virtual void precache() = 0;

	/// <summary>
	/// </summary>
	virtual void restart() = 0;

	/// <summary>
	/// </summary>
	virtual void key_value(KeyValueData* data) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean save(Save& save) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean restore(Restore& restore) = 0;

	/// <summary>
	/// </summary>
	virtual int object_caps() = 0;

	/// <summary>
	/// </summary>
	virtual void activate() = 0;

	/// <summary>
	/// <para>Setup the object->object collision box (<c>EntityVars->min_size / EntityVars->max_size</c> is the <c>object->world</c> collision box).</para>
	/// </summary>
	virtual void set_object_collision_box() = 0;

	/// <summary>
	/// <para>Returns the type of group (i.e, "houndeye", or "human military" so that monsters with different class names
	/// still realize that they are teammates (overridden for monsters that form groups).</para>
	/// </summary>
	virtual Classify classify() = 0;

	/// <summary>
	/// </summary>
	virtual void death_notice(EntityVars* child) = 0;

	/// <summary>
	/// </summary>
	virtual void trace_attack(EntityVars* attacker, float damage, Vector direction, TraceResult* result, int damage_type) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean take_damage(EntityVars* inflictor, EntityVars* attacker, float damage, int damage_type) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean take_health(float health, int damage_type) = 0;

	/// <summary>
	/// </summary>
	virtual void killed(EntityVars* attacker, int gib) = 0;

	/// <summary>
	/// </summary>
	virtual int blood_color() = 0;

	/// <summary>
	/// </summary>
	virtual void trace_bleed(float damage, Vector direction, TraceResult* result, int damage_type) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_triggered(EntityBase* activator) = 0;

	/// <summary>
	/// </summary>
	virtual MonsterBase* my_monster_pointer() = 0;

	/// <summary>
	/// </summary>
	virtual SquadMonster* my_squad_monster_pointer() = 0;

	/// <summary>
	/// </summary>
	virtual ToggleState get_toggle_state() = 0;

	/// <summary>
	/// </summary>
	virtual void add_points(int score, qboolean allow_negative_score) = 0;

	/// <summary>
	/// </summary>
	virtual void add_points_to_team(int score, qboolean allow_negative_score) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean add_player_item(PlayerItemBase* item) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean remove_player_item(PlayerItemBase* item) = 0;

	/// <summary>
	/// </summary>
	virtual int give_ammo(int amount, const char* name, int max = -1) = 0;

	/// <summary>
	/// </summary>
	virtual float get_delay() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_moving() = 0;

	/// <summary>
	/// </summary>
	virtual void override_reset() = 0;

	/// <summary>
	/// </summary>
	virtual Decal damage_decal(int damage_type) = 0;

	/// <summary>
	/// </summary>
	virtual void set_toggle_state(int state) = 0;

#ifndef REGAMEDLL_API
	/// <summary>
	/// </summary>
	virtual void start_sneaking() = 0;

	/// <summary>
	/// </summary>
	virtual void stop_sneaking() = 0;
#else
	/// <summary>
	/// </summary>
	virtual void on_create() = 0;

	/// <summary>
	/// </summary>
	virtual void on_destroy() = 0;
#endif

	/// <summary>
	/// </summary>
	virtual qboolean on_controls(EntityVars* on_ev) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_sneaking() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_alive() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_bsp_model() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean reflect_gauss() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean has_target(Strind target_name) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_in_world() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_player() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean is_net_client() = 0;

	/// <summary>
	/// </summary>
	virtual const char* team_id() = 0;

	/// <summary>
	/// </summary>
	virtual EntityBase* get_next_target() = 0;

	/// <summary>
	/// </summary>
	virtual void think() = 0;

	/// <summary>
	/// </summary>
	virtual void touch(EntityBase* other) = 0;

	/// <summary>
	/// </summary>
	virtual void use(EntityBase* activator, EntityBase* caller, UseType type = UseType::UseOff, float value = 0.0f) = 0;

	/// <summary>
	/// </summary>
	virtual void blocked(EntityBase* other) = 0;

	/// <summary>
	/// </summary>
	virtual EntityBase* respawn() = 0;

	/// <summary>
	/// <para>Used by monsters that are created by the MonsterMaker.</para>
	/// </summary>
	virtual void update_owner() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean become_prone() = 0;

	/// <summary>
	/// <para>Center point of entity.</para>
	/// </summary>
	virtual Vector center() = 0;

	/// <summary>
	/// <para>Position of eyes.</para>
	/// </summary>
	virtual Vector eye_position() = 0;

	/// <summary>
	/// <para>Position of ears.</para>
	/// </summary>
	virtual Vector ear_position() = 0;

	/// <summary>
	/// <para>Position to shoot at.</para>
	/// </summary>
	virtual Vector body_target(const Vector& pos_src) = 0;

	/// <summary>
	/// </summary>
	virtual int illumination() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean visible(EntityBase* entity) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean visible(const Vector& origin) = 0;

	/// <summary>
	/// </summary>
	EntityVars* vars;

	/// <summary>
	/// </summary>
	EntityBase* goal_ent;

	/// <summary>
	/// </summary>
	EntityBase* link;

	/// <summary>
	/// </summary>
	void (EntityBase::* think_callback)();

	/// <summary>
	/// </summary>
	void (EntityBase::* touch_callback)(EntityBase* other);

	/// <summary>
	/// </summary>
	void (EntityBase::* use_callback)(EntityBase* activator, EntityBase* caller, UseType type, float value);

	/// <summary>
	/// </summary>
	void (EntityBase::* blocked_callback)(EntityBase* other);

#ifdef REGAMEDLL_API
	/// <summary>
	/// </summary>
	CsEntity* entity;
#else
	/// <summary>
	/// </summary>
	int* current_ammo;
#endif

	/// <summary>
	/// </summary>
	float cur_ent_ammo;

	/// <summary>
	/// </summary>
	int max_ammo_buckshot;

	/// <summary>
	/// </summary>
	int ammo_buckshot;

	/// <summary>
	/// </summary>
	int max_ammo_9mm;

	/// <summary>
	/// </summary>
	int ammo_9mm;

	/// <summary>
	/// </summary>
	int max_ammo_556nato;

	/// <summary>
	/// </summary>
	int ammo_556nato;

	/// <summary>
	/// </summary>
	int max_ammo_556natobox;

	/// <summary>
	/// </summary>
	int ammo_556natobox;

	/// <summary>
	/// </summary>
	int max_ammo_762nato;

	/// <summary>
	/// </summary>
	int ammo_762nato;

	/// <summary>
	/// </summary>
	int max_ammo_45acp;

	/// <summary>
	/// </summary>
	int ammo_45acp;

	/// <summary>
	/// </summary>
	int max_ammo_50ae;

	/// <summary>
	/// </summary>
	int ammo_50ae;

	/// <summary>
	/// </summary>
	int max_ammo_338mag;

	/// <summary>
	/// </summary>
	int ammo_338mag;

	/// <summary>
	/// </summary>
	int max_ammo_57mm;

	/// <summary>
	/// </summary>
	int ammo_57mm;

	/// <summary>
	/// </summary>
	int max_ammo_357sig;

	/// <summary>
	/// </summary>
	int ammo_357sig;

	/// <summary>
	/// </summary>
	float start_throw;

	/// <summary>
	/// </summary>
	float release_throw;

	/// <summary>
	/// </summary>
	int swing;

	/// <summary>
	/// </summary>
	bool has_disconnected;

	using UseCallbackFn = decltype(use_callback);
	using ThinkCallbackFn = decltype(think_callback);
	using TouchCallbackFn = decltype(touch_callback);
	using BlockedCallbackFn = decltype(blocked_callback);

	/// <summary>
	/// </summary>
	template <typename T>
	void set_think(void (T::*callback)())
	{
		think_callback = static_cast<ThinkCallbackFn>(callback);
	}

	/// <summary>
	/// </summary>
	void set_think(std::nullptr_t)
	{
		think_callback = nullptr;
	}

	/// <summary>
	/// </summary>
	template <typename T>
	void set_touch(void (T::*callback)(EntityBase* other))
	{
		touch_callback = static_cast<TouchCallbackFn>(callback);
	}

	/// <summary>
	/// </summary>
	void set_touch(std::nullptr_t)
	{
		touch_callback = nullptr;
	}

	/// <summary>
	/// </summary>
	template <typename T>
	void set_use(void (T::*callback)(EntityBase* activator, EntityBase* caller, UseType type, float value))
	{
		use_callback = static_cast<UseCallbackFn>(callback);
	}

	/// <summary>
	/// </summary>
	void set_use(std::nullptr_t)
	{
		use_callback = nullptr;
	}

	/// <summary>
	/// </summary>
	template <typename T>
	void set_blocked(void (T::*callback)(EntityBase* other))
	{
		blocked_callback = static_cast<BlockedCallbackFn>(callback);
	}

	/// <summary>
	/// </summary>
	void set_blocked(std::nullptr_t)
	{
		blocked_callback = nullptr;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Edict* edict() const
	{
		return vars == nullptr ? nullptr : vars->containing_entity;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] int edict_index() const
	{
		return vars == nullptr ? -1 : g_engine_funcs.index_of_edict(vars->containing_entity);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] eoffset edict_offset() const
	{
		return vars == nullptr ? -1 : g_engine_funcs.ent_offset_of_entity(vars->containing_entity);
	}
};

/// <summary>
/// <para>Safe way to point to CBaseEntities who may die between frames.</para>
/// </summary>
template <typename T = EntityBase>
class EntityHandle {
public:
	/// <summary>
	/// </summary>
	EntityHandle() : edict_(nullptr), serial_number_(0)
	{
	}

	/// <summary>
	/// </summary>
	EntityHandle(const EntityHandle<T>& other) : EntityHandle()
	{
		if (other) {
			edict_ = other.edict_;
			serial_number_ = other.serial_number_;
		}
	}

	/// <summary>
	/// </summary>
	explicit EntityHandle(const Edict* entity) : EntityHandle()
	{
		if (entity)
			set(const_cast<Edict*>(entity));
	}

	/// <summary>
	/// </summary>
	explicit EntityHandle(const T* entity) : EntityHandle()
	{
		if (entity && entity->vars && entity->vars->containing_entity)
			set(entity->vars->containing_entity);
	}

	/// <summary>
	/// </summary>
	EntityHandle(EntityHandle<T>&&) = delete;

	/// <summary>
	/// </summary>
	~EntityHandle() = default;

	/// <summary>
	/// </summary>
	[[nodiscard]] Edict* get() const
	{
		return edict_ && edict_->serial_number == serial_number_ && !edict_->free ? edict_ : nullptr;
	}

	/// <summary>
	/// </summary>
	Edict* set(Edict* edict)
	{
		if (edict) {
			edict_ = edict;
			serial_number_ = edict->serial_number;
		}
		else {
			edict_ = nullptr;
			serial_number_ = 0;
		}

		return edict_;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] int get_serial_number() const
	{
		return serial_number_;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_valid() const
	{
		const auto edict = get();
		return cssdk_is_valid_entity(edict);
	}

	/// <summary>
	/// </summary>
	EntityHandle& operator=(EntityHandle&&) = default;

	/// <summary>
	/// </summary>
	EntityHandle& operator=(const EntityHandle<T>& other) = default;

	/// <summary>
	/// </summary>
	bool operator==(T* entity) const
	{
		if (!entity || !entity->vars || !entity->vars->containing_entity) {
			assert("EntityHandle<T>::operator==: got a null pointer!");
			return false;
		}

		auto edict = entity->vars->containing_entity;
		return edict->serial_number == serial_number_ && edict == edict_;
	}

	/// <summary>
	/// </summary>
	bool operator!=(T* entity) const
	{
		return !(*this == entity);
	}

private:
	/// <summary>
	/// </summary>
	Edict* edict_;

	/// <summary>
	/// </summary>
	int serial_number_;
};

/// <summary>
/// Class EntityPoint.
/// </summary>
class EntityPoint : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	int object_caps() override = 0;
};

/// <summary>
/// <para>Generic delay entity.</para>
/// </summary>
class DelayBase : public EntityBase {
public:
	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	float delay;

	/// <summary>
	/// </summary>
	Strind kill_target;
};

/// <summary>
/// Class AnimatingBase.
/// </summary>
class AnimatingBase : public DelayBase {
public:
	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	virtual void handle_anim_event(MonsterEvent* event) = 0;

	//
	// Animation needs.
	//

	/// <summary>
	/// <para>Computed FPS for current sequence.</para>
	/// </summary>
	float frame_rate;

	/// <summary>
	/// <para>Computed linear movement rate for current sequence.</para>
	/// </summary>
	float ground_speed;

	/// <summary>
	/// <para>Last time the event list was checked.</para>
	/// </summary>
	float last_event_check;

	/// <summary>
	/// <para>Flag set when StudioAdvanceFrame moves across a frame boundry.</para>
	/// </summary>
	qboolean sequence_finished;

	/// <summary>
	/// <para>True if the sequence loops.</para>
	/// </summary>
	qboolean sequence_loops;
};

/// <summary>
/// <para>Generic Toggle entity.</para>
/// </summary>
class ToggleBase : public AnimatingBase {
public:
	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// </summary>
	ToggleState get_toggle_state() override = 0;

	/// <summary>
	/// </summary>
	float get_delay() override = 0;

	/// <summary>
	/// </summary>
	ToggleState state;

	/// <summary>
	/// <para>Like attack_finished, but for doors.</para>
	/// </summary>
	float activate_finished;

	/// <summary>
	/// <para>How far a door should slide or rotate.</para>
	/// </summary>
	float move_distance;

	/// <summary>
	/// </summary>
	float wait;

	/// <summary>
	/// </summary>
	float lip;

	/// <summary>
	/// <para>For plats.</para>
	/// </summary>
	float width;

	/// <summary>
	/// <para>For plats.</para>
	/// </summary>
	float length;

	/// <summary>
	/// </summary>
	Vector position1;

	/// <summary>
	/// </summary>
	Vector position2;

	/// <summary>
	/// </summary>
	Vector angle1;

	/// <summary>
	/// </summary>
	Vector angle2;

	/// <summary>
	/// <para>trigger_counter only, # of activations remaining.</para>
	/// </summary>
	int triggers_left;

	/// <summary>
	/// </summary>
	float height;

	/// <summary>
	/// </summary>
	EntityHandle<> activator;

	/// <summary>
	/// </summary>
	void (ToggleBase::* move_done_callback)();

	/// <summary>
	/// </summary>
	Vector final_dest;

	/// <summary>
	/// </summary>
	Vector final_angle;

	/// <summary>
	/// <para>DMG_ damage type that the door or trigger does.</para>
	/// </summary>
	int damage_inflict;

	/// <summary>
	/// <para>If this button has a master switch, this is the target name.<br/>
	/// A master switch must be of the <c>MultiSource</c> type.
	/// If all of the switches in the multi source have been triggered,
	/// then the button will be allowed to operate. Otherwise, it will be deactivated.</para>
	/// </summary>
	Strind master;

	using MoveDoneCallbackFn = decltype(move_done_callback);

	/// <summary>
	/// </summary>
	template <typename T>
	void set_move_done(void (T::* callback)())
	{
		move_done_callback = static_cast<MoveDoneCallbackFn>(callback);
	}

	/// <summary>
	/// </summary>
	void set_move_done(std::nullptr_t)
	{
		move_done_callback = nullptr;
	}
};

/// <summary>
/// Class ButtonBase.
/// </summary>
class ButtonBase : public ToggleBase {
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
	qboolean take_damage(EntityVars* inflictor, EntityVars* attacker, float damage, int damage_type) override = 0;

	/// <summary>
	/// </summary>
	qboolean save(Save& save) override = 0;

	/// <summary>
	/// </summary>
	qboolean restore(Restore& restore) override = 0;

	/// <summary>
	/// <para>Buttons that don't take damage can be IMPULSE used.</para>
	/// </summary>
	int object_caps() override = 0;

#ifdef REGAMEDLL_FIXES
	/// <summary>
	/// </summary>
	void restart() override = 0;
#endif

	/// <summary>
	/// <para>Button stays pushed in until touched again?</para>
	/// </summary>
	qboolean stay_pushed;

	/// <summary>
	/// <para>A rotating button?<br/>
	/// Default is a sliding button.</para>
	/// </summary>
	qboolean rotating;

	/// <summary>
	/// <para>If this field is not null, this is an index into the engine string array.<br/>
	/// When this button is touched, it's target entity's TARGET field will be set to the button's ChangeTarget.
	/// This allows you to make a func_train switch paths, etc.</para>
	/// </summary>
	Strind change_target;

	/// <summary>
	/// <para>Door lock sounds.</para>
	/// </summary>
	LockSound lock_snd;

	/// <summary>
	/// </summary>
	byte locked_sound;

	/// <summary>
	/// </summary>
	byte locked_sentence;

	/// <summary>
	/// </summary>
	byte unlocked_sound;

	/// <summary>
	/// </summary>
	byte unlocked_sentence;

	/// <summary>
	/// </summary>
	int sounds;
};

/// <summary>
/// Class MultiSource.
/// </summary>
class MultiSource : public EntityPoint {
public:
	/// <summary>
	/// </summary>
	void spawn() override = 0;

	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

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
	qboolean is_triggered(EntityBase* activator) override = 0;

	/// <summary>
	/// </summary>
	void use(EntityBase* activator, EntityBase* caller, UseType type, float value) override = 0;

#ifdef REGAMEDLL_FIXES
	/// <summary>
	/// </summary>
	void restart() override = 0;
#endif

	/// <summary>
	/// </summary>
	EntityHandle<> entities[MAX_MS_TARGETS];

	/// <summary>
	/// </summary>
	int triggered[MAX_MS_TARGETS];

	/// <summary>
	/// </summary>
	int total;

	/// <summary>
	/// </summary>
	Strind global_state;
};
