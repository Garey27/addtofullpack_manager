// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/activity.h>
#include <cssdk/dll/entity_base.h>

/// <summary>
/// Enum TimeBasedDamage
/// </summary>
enum class TimeBasedDamage {
	/// <summary>
	/// </summary>
	Paralyze = 0,

	/// <summary>
	/// </summary>
	NerveGas,

	/// <summary>
	/// </summary>
	Poison,

	/// <summary>
	/// </summary>
	Radiation,

	/// <summary>
	/// </summary>
	DrownRecover,

	/// <summary>
	/// </summary>
	Acid,

	/// <summary>
	/// </summary>
	SlowBurn,

	/// <summary>
	/// </summary>
	SlowFreeze,

	/// <summary>
	/// </summary>
	End
};

/// <summary>
/// Enum MonsterState
/// </summary>
enum class MonsterState {
	/// <summary>
	/// </summary>
	None = 0,

	/// <summary>
	/// </summary>
	Idle,

	/// <summary>
	/// </summary>
	Combat,

	/// <summary>
	/// </summary>
	Alert,

	/// <summary>
	/// </summary>
	Hunt,

	/// <summary>
	/// </summary>
	Prone,

	/// <summary>
	/// </summary>
	Script,

	/// <summary>
	/// </summary>
	PlayDead,

	/// <summary>
	/// </summary>
	Dead
};

/// <summary>
/// Class MonsterBase.
/// </summary>
class MonsterBase : public ToggleBase {
public:
	/// <summary>
	/// </summary>
	void key_value(KeyValueData* data) override = 0;

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
	virtual int get_blood_color() = 0;

	/// <summary>
	/// </summary>
	qboolean is_alive() override = 0;

	/// <summary>
	/// </summary>
	virtual float change_yaw(int speed) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean has_human_gibs() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean has_alien_gibs() = 0;

	/// <summary>
	/// </summary>
	virtual void fade_monster() = 0;

	/// <summary>
	/// </summary>
	virtual void gib_monster() = 0;

	/// <summary>
	/// </summary>
	virtual Activity get_death_activity() = 0;

	/// <summary>
	/// </summary>
	virtual void become_dead() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean should_fade_on_death() = 0;

	/// <summary>
	/// </summary>
	virtual int relationship(EntityBase* target) = 0;

	/// <summary>
	/// </summary>
	virtual void pain_sound() = 0;

	/// <summary>
	/// </summary>
	virtual void reset_max_speed() = 0;

	/// <summary>
	/// </summary>
	virtual void report_ai_state() = 0;

	/// <summary>
	/// </summary>
	virtual void monster_init_dead() = 0;

	/// <summary>
	/// </summary>
	virtual void look(int distance) = 0;

	/// <summary>
	/// </summary>
	virtual EntityBase* best_visible_enemy() = 0;

	/// <summary>
	/// </summary>
	virtual qboolean in_view_cone(EntityBase* entity) = 0;

	/// <summary>
	/// </summary>
	virtual qboolean in_view_cone(const Vector* origin) = 0;

	/// <summary>
	/// <para>What the monster is doing (animation).</para>
	/// </summary>
	Activity cur_activity;

	/// <summary>
	/// <para>Monster should switch to this activity.</para>
	/// </summary>
	Activity ideal_activity;

	/// <summary>
	/// <para>The last body region that took damage.</para>
	/// </summary>
	HitBoxGroup last_hit_group;

	/// <summary>
	/// <para>What types of damage has monster (player) taken.</para>
	/// </summary>
	int damage_type;

	/// <summary>
	/// </summary>
	byte time_based_damage[static_cast<int>(TimeBasedDamage::End)];

	/// <summary>
	/// <para>Monster's current state.</para>
	/// </summary>
	MonsterState monster_state;

	/// <summary>
	/// <para>Monster should change to this state.</para>
	/// </summary>
	MonsterState ideal_monster_state;

	/// <summary>
	/// </summary>
	int conditions;

	/// <summary>
	/// </summary>
	int memory;

	/// <summary>
	/// <para>Cannot attack again until this time.</para>
	/// </summary>
	float next_attack;

	/// <summary>
	/// <para>The entity that the monster is fighting.</para>
	/// </summary>
	EntityHandle<> enemy;

	/// <summary>
	/// <para>The entity that the monster is trying to reach.</para>
	/// </summary>
	EntityHandle<> target_ent;

	/// <summary>
	/// <para>Width of monster's field of view (dot product).</para>
	/// </summary>
	float field_of_view;

	/// <summary>
	/// <para>Color of blood particles.</para>
	/// </summary>
	int blood_color;

	/// <summary>
	/// <para>HACK until we can query end of gun.</para>
	/// </summary>
	Vector hacked_gun_pos;

	/// <summary>
	/// <para>Last known position of enemy (enemy's origin).</para>
	/// </summary>
	Vector enemy_last_known_position;
};
