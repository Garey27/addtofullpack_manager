#include <amxx/api.h>
#include <metamod/api.h>
#include <metamod/engine.h>
#include <metamod/engine_hooks.h>
#include <metamod/gamedll.h>
#include <metamod/gamedll_hooks.h>
#include <metamod/utils.h>
#include <addtofullpack_manager/rehlds_api.h>
#include <addtofullpack_manager/regamedll_api.h>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>    // std::find_if

using namespace std;

enum class entity_state_e
{
	es_entity_type = 0,
	es_number,
	es_msg_time,
	es_message_num,
	es_origin,
	es_angles,
	es_model_index,
	es_sequence,
	es_frame,
	es_color_map,
	es_skin,
	es_solid,
	es_effects,
	es_scale,
	es_entity_flags,
	es_render_mode,
	es_render_amount,
	es_render_color,
	es_render_fx,
	es_move_type,
	es_anim_time,
	es_frame_rate,
	es_body,
	es_controller,
	es_blending,
	es_velocity,
	es_min_size,
	es_max_size,
	es_aim_entity,
	es_owner,
	es_friction,
	es_gravity,
	es_team,
	es_player_class,
	es_health,
	es_spectator,
	es_weapon_model,
	es_gait_sequence,
	es_base_velocity,
	es_use_hull,
	es_old_buttons,
	es_on_ground,
	es_step_left,
	es_fall_velocity,
	es_fov,
	es_weapon_anim,
	es_start_pos,
	es_end_pos,
	es_impact_time,
	es_start_time,
	es_i_user1,
	es_i_user2,
	es_i_user3,
	es_i_user4,
	es_f_user1,
	es_f_user2,
	es_f_user3,
	es_f_user4,
	es_v_user1,
	es_v_user2,
	es_v_user3,
	es_v_user4
};

namespace AddToFullPackManager
{
	class SingleEntityState
	{
	private:
		enum EntityStateTypedef
		{
			Byte,
			Short,
			Integer,
			Float,
		};

		struct EntityStateType
		{
			EntityStateTypedef real_type;
			uintptr_t offset;
			uintptr_t real_size;
		};

		static map<entity_state_e, EntityStateType> es_types;

		entity_state_e type;
		void* value;
		uintptr_t offset;
		uintptr_t size;

#define REGISTER_ES_TYPE(amx_estype, amx_celltype)\
		es_types.insert({{ entity_state_e::es_##amx_estype}, {amx_celltype, offsetof(EntityState, amx_estype), sizeof(EntityState::amx_estype) }});

	public:
		static void EntityStateInitTypes()
		{
			//sizeof(EntityState::render_color);
			es_types.clear();
			REGISTER_ES_TYPE(entity_type, Integer);
			REGISTER_ES_TYPE(number, Integer);
			REGISTER_ES_TYPE(msg_time, Float);
			REGISTER_ES_TYPE(message_num, Integer);
			REGISTER_ES_TYPE(origin, Float);
			REGISTER_ES_TYPE(angles, Float);
			REGISTER_ES_TYPE(model_index, Integer);
			REGISTER_ES_TYPE(sequence, Integer);
			REGISTER_ES_TYPE(frame, Float);
			REGISTER_ES_TYPE(color_map, Integer);
			REGISTER_ES_TYPE(skin, Short);
			REGISTER_ES_TYPE(solid, Short);
			REGISTER_ES_TYPE(effects, Integer);
			REGISTER_ES_TYPE(scale, Float);
			REGISTER_ES_TYPE(entity_flags, Byte);
			REGISTER_ES_TYPE(render_mode, Integer);
			REGISTER_ES_TYPE(render_amount, Integer);
			REGISTER_ES_TYPE(render_color, Byte);
			REGISTER_ES_TYPE(render_fx, Integer);
			REGISTER_ES_TYPE(move_type, Integer);
			REGISTER_ES_TYPE(anim_time, Float);
			REGISTER_ES_TYPE(frame_rate, Float);
			REGISTER_ES_TYPE(body, Integer);
			REGISTER_ES_TYPE(controller, Byte);
			REGISTER_ES_TYPE(blending, Byte);
			REGISTER_ES_TYPE(velocity, Float);
			REGISTER_ES_TYPE(min_size, Float);
			REGISTER_ES_TYPE(max_size, Float);
			REGISTER_ES_TYPE(aim_entity, Integer);
			REGISTER_ES_TYPE(owner, Integer);
			REGISTER_ES_TYPE(friction, Float);
			REGISTER_ES_TYPE(gravity, Float);
			REGISTER_ES_TYPE(team, Integer);
			REGISTER_ES_TYPE(player_class, Integer);
			REGISTER_ES_TYPE(health, Integer);
			REGISTER_ES_TYPE(spectator, Integer);
			REGISTER_ES_TYPE(weapon_model, Integer);
			REGISTER_ES_TYPE(gait_sequence, Integer);
			REGISTER_ES_TYPE(base_velocity, Float);
			REGISTER_ES_TYPE(use_hull, Integer);
			REGISTER_ES_TYPE(old_buttons, Integer);
			REGISTER_ES_TYPE(on_ground, Integer);
			REGISTER_ES_TYPE(step_left, Integer);
			REGISTER_ES_TYPE(fall_velocity, Float);
			REGISTER_ES_TYPE(fov, Float);
			REGISTER_ES_TYPE(weapon_anim, Integer);
			REGISTER_ES_TYPE(start_pos, Float);
			REGISTER_ES_TYPE(end_pos, Float);
			REGISTER_ES_TYPE(impact_time, Integer);
			REGISTER_ES_TYPE(start_time, Integer);
			REGISTER_ES_TYPE(i_user1, Integer);
			REGISTER_ES_TYPE(i_user2, Integer);
			REGISTER_ES_TYPE(i_user3, Integer);
			REGISTER_ES_TYPE(i_user4, Integer);
			REGISTER_ES_TYPE(f_user1, Float);
			REGISTER_ES_TYPE(f_user2, Float);
			REGISTER_ES_TYPE(f_user3, Float);
			REGISTER_ES_TYPE(f_user4, Float);
			REGISTER_ES_TYPE(v_user1, Float);
			REGISTER_ES_TYPE(v_user2, Float);
			REGISTER_ES_TYPE(v_user3, Float);
			REGISTER_ES_TYPE(v_user4, Float);
		}

		SingleEntityState(entity_state_e type, cell* value)
		{
			this->type = type;
			setValue(value);
		}

		~SingleEntityState()
		{
			delete value;
		}

		void updateValue(cell* new_value)
		{
			delete value;
			setValue(new_value);

		}

		void setValue(cell* value)
		{
			auto type_found = es_types.find(type);
			if (type_found != es_types.end())
			{
				this->size = type_found->second.real_size;
				this->offset = type_found->second.offset;
				switch (type_found->second.real_type)
				{
				case Float:
				{
					auto arr_size = type_found->second.real_size / sizeof(float);
					float* new_val = new float[arr_size];
					for (auto i = 0; i < arr_size; i++)
					{
						new_val[i] = amx_ctof(value[i]);
					}
					this->value = new_val;
					break;
				}
				case Integer:
				{
					auto arr_size = type_found->second.real_size / sizeof(int);
					int* new_val = new int[arr_size];
					for (auto i = 0; i < arr_size; i++)
					{
						new_val[i] = value[i];
					}
					this->value = new_val;
					break;
				}
				case Byte:
				{
					auto arr_size = type_found->second.real_size / sizeof(uint8);
					uint8* new_val = new uint8[arr_size];
					for (auto i = 0; i < arr_size; i++)
					{
						new_val[i] = value[i];
					}
					this->value = new_val;
					break;
				}
				case Short:
				{
					auto arr_size = type_found->second.real_size / sizeof(uint16);
					uint16* new_val = new uint16[arr_size];
					for (auto i = 0; i < arr_size; i++)
					{
						new_val[i] = value[i];
					}
					this->value = new_val;
					break;
				}
				}
			}
		}

		entity_state_e getType()
		{
			return type;
		}

		uintptr_t getOffset()
		{
			return offset;
		}

		void* getValue()
		{
			return value;
		}

		uintptr_t getSize()
		{
			return size;
		}
	};
}

map <int, map<int, vector<shared_ptr<AddToFullPackManager::SingleEntityState>>>> mapAddToFullPackManager;
map <int, map<int, bool>> mapCollisionManager;
map <int, map<int, bool>> mapNoTraceManager;
map<entity_state_e, AddToFullPackManager::SingleEntityState::EntityStateType> AddToFullPackManager::SingleEntityState::es_types;
PhysEntity phys_ents_backup[MAX_PHYS_ENTS];
uint32_t phys_ents_backup_num;

int add_to_full_pack(EntityState* state, int entity_index, Edict* entity, Edict* host, int host_flags, qboolean player, unsigned char* set)
{
	if (host == entity)
	{
		RETURN_META_VALUE(MetaResult::Ignored, 1);
	}

	int viewer_id = Engine::index_of_edict(host);

	auto found = mapAddToFullPackManager.find(viewer_id);

	if (found != mapAddToFullPackManager.end())
	{
		int entity_id = Engine::index_of_edict(entity);

		auto found2 = found->second.find(entity_id);

		if (found2 != found->second.end())
		{
			for (auto st : found2->second)
			{
				memcpy(reinterpret_cast<uint8_t*>(state) + st->getOffset(), st->getValue(), st->getSize());
			}
		}
	}


	RETURN_META_VALUE(MetaResult::Ignored, 1);
}

void pm_move(PlayerMove* move, qboolean server)
{
	/* PRE */
	int id = move->player_index + 1;
	auto colEl = mapCollisionManager.find(id);
	if (colEl == mapCollisionManager.end())
		return;
	
	phys_ents_backup_num = move->num_phys_ent;
	memcpy(phys_ents_backup, move->phys_ents, sizeof(PhysEntity) * move->num_phys_ent);
	move->num_phys_ent = 0;
	for (int i = 0; i < phys_ents_backup_num; i++)
	{
		if (colEl->second.find(phys_ents_backup[i].info) != colEl->second.end())
		{
			continue;
		}
		memcpy(&move->phys_ents[move->num_phys_ent++], &move->phys_ents[i], sizeof(PhysEntity));
	}
	
	GameDll::pm_move(move, server);
	/* POST */
	move->num_phys_ent = phys_ents_backup_num;
	memcpy(move->phys_ents, phys_ents_backup, sizeof(PhysEntity) * move->num_phys_ent);

	RETURN_META(MetaResult::Supercede);

}

void trace_line(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, Edict* entity_to_ignore, TraceResult* result)
{
	auto id = Engine::index_of_edict(entity_to_ignore);
	auto traceIt = mapNoTraceManager.find(id);

	if (traceIt == mapNoTraceManager.end())
		return;
	if (traceIt->second.empty())
		return;

	map<int, SolidType> saveSolid;

	for (auto ent : traceIt->second)
	{
		auto edict = Engine::entity_of_ent_index(ent.first);
		if (edict)
		{
			saveSolid.insert({ ent.first, edict->vars.solid });
			edict->vars.solid = SolidType::NotSolid;
		}
	}

	Engine::trace_line(start_pos, end_pos, trace_ignore_flags, entity_to_ignore, result);

	for (auto ent : saveSolid)
	{
		auto edict = Engine::entity_of_ent_index(ent.first);
		if (edict)
		{
			edict->vars.solid = ent.second;
		}
	}

	RETURN_META(MetaResult::Supercede);

}

void trace_hull(const Vector& start_pos, const Vector& end_pos, int trace_ignore_flags, int hull_number, Edict* entity_to_ignore, TraceResult* result)
{
	auto id = Engine::index_of_edict(entity_to_ignore);
	auto traceIt = mapNoTraceManager.find(id);
	if (traceIt == mapNoTraceManager.end())
		return;
	if (traceIt->second.empty())
		return;

	map<int, vec_t> saveSize;

	for (auto ent : traceIt->second)
	{
		auto edict = Engine::entity_of_ent_index(ent.first);
		if (edict)
		{
			saveSize.insert({ ent.first, edict->vars.size.x });
			edict->vars.size.x = 0.0;
		}
	}

	Engine::trace_hull(start_pos, end_pos, trace_ignore_flags, hull_number, entity_to_ignore, result);

	for (auto ent : saveSize)
	{
		auto edict = Engine::entity_of_ent_index(ent.first);
		if (edict)
		{
			edict->vars.size.x = ent.second;
		}
	}

	RETURN_META(MetaResult::Supercede);
}

void server_deactivate()
{
	mapAddToFullPackManager.clear();
	mapCollisionManager.clear();
	mapNoTraceManager.clear();
}

static cell AMX_NATIVE_CALL addtofullpack_manager_set(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1, arg_entity_id, arg_entity_state, arg_value };

	int viewer_id = params[arg_viewer_id];
	int entity_id = params[arg_entity_id];

	if (viewer_id == entity_id)
	{
		return 0;
	}

	entity_state_e entity_state_type = static_cast<entity_state_e>(params[arg_entity_state]);

    cell* value = AmxxApi::get_amx_address(amx, params[arg_value]);
	bool value_exists = false;
	if (mapAddToFullPackManager.find(viewer_id) != mapAddToFullPackManager.end())
	{
		if (mapAddToFullPackManager[viewer_id].find(entity_id) != mapAddToFullPackManager[viewer_id].end())
		{
			auto exists = std::find_if(mapAddToFullPackManager[viewer_id][entity_id].begin(),
				mapAddToFullPackManager[viewer_id][entity_id].end(), [&](auto &es)
				{
					return (es->getType() == entity_state_type);
				});
			if (exists != mapAddToFullPackManager[viewer_id][entity_id].end())
			{
				(*exists)->updateValue(value);				
				value_exists = true;
			}		
		}
	}
	if (!value_exists)
	{
		mapAddToFullPackManager[viewer_id][entity_id].push_back(make_shared<AddToFullPackManager::SingleEntityState>(entity_state_type, value));
	}
	return 1;
}

static cell AMX_NATIVE_CALL addtofullpack_manager_unset(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1, arg_entity_id, arg_entity_state, arg_value };

	int viewer_id = params[arg_viewer_id];
	int entity_id = params[arg_entity_id];

	if (viewer_id == entity_id)
	{
		return 0;
	}

	entity_state_e entity_state_type = static_cast<entity_state_e>(params[arg_entity_state]);

	if (mapAddToFullPackManager.find(viewer_id) != mapAddToFullPackManager.end())
	{
		if (mapAddToFullPackManager[viewer_id].find(entity_id) != mapAddToFullPackManager[viewer_id].end())
		{
			auto exists = std::find_if(mapAddToFullPackManager[viewer_id][entity_id].begin(),
				mapAddToFullPackManager[viewer_id][entity_id].end(), [&](auto& es)
				{
					return (es->getType() == entity_state_type);
				});
			if (exists != mapAddToFullPackManager[viewer_id][entity_id].end())
			{
				mapAddToFullPackManager[viewer_id][entity_id].erase(exists);
				return 1;
			}
		}
	}
	// not found
	return 0; 
}

static cell AMX_NATIVE_CALL addtofullpack_manager_reset(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1 };

	int viewer_id = params[arg_viewer_id];

	if (mapAddToFullPackManager.find(viewer_id) == mapAddToFullPackManager.end())
	{
		return 0;
	}

	mapAddToFullPackManager.erase(viewer_id);
	return 1;
}


static cell AMX_NATIVE_CALL addtofullpack_manager_collision_enable(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1, arg_entity_id, arg_value };

	int viewer_id = params[arg_viewer_id];
	int entity_id = params[arg_entity_id];

	if (viewer_id == entity_id)
	{
		return 0;
	}

	cell* set = AmxxApi::get_amx_address(amx, params[arg_value]);

	mapCollisionManager[viewer_id][entity_id] = *set;
	return 1;
}

static cell AMX_NATIVE_CALL addtofullpack_manager_collision_disable(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1, arg_entity_id, arg_value };

	int viewer_id = params[arg_viewer_id];
	int entity_id = params[arg_entity_id];

	if (viewer_id == entity_id)
	{
		return 0;
	}

	if (mapCollisionManager.find(viewer_id) != mapCollisionManager.end())
	{
		if (mapCollisionManager[viewer_id].find(entity_id) != mapCollisionManager[viewer_id].end())
		{
			mapCollisionManager[viewer_id].erase(entity_id);
			return 1;
		}
	}

	return 0;
}

static cell AMX_NATIVE_CALL addtofullpack_manager_collision_reset(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1 };

	int viewer_id = params[arg_viewer_id];

	if (mapCollisionManager.find(viewer_id) == mapCollisionManager.end())
	{
		return 0;
	}

	mapCollisionManager.erase(viewer_id);
	return 1;
}


static cell AMX_NATIVE_CALL addtofullpack_manager_notrace_enable(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1, arg_entity_id, arg_value };

	int viewer_id = params[arg_viewer_id];
	int entity_id = params[arg_entity_id];

	if (viewer_id == entity_id || entity_id <= 0)
	{
		return 0;
	}

	cell* set = AmxxApi::get_amx_address(amx, params[arg_value]);

	mapNoTraceManager[viewer_id][entity_id] = *set;
	return 1;
}

static cell AMX_NATIVE_CALL addtofullpack_manager_notrace_disable(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1, arg_entity_id, arg_value };

	int viewer_id = params[arg_viewer_id];
	int entity_id = params[arg_entity_id];

	if (viewer_id == entity_id || entity_id <= 0)
	{
		return 0;
	}

	if (mapNoTraceManager.find(viewer_id) != mapNoTraceManager.end())
	{
		if (mapNoTraceManager[viewer_id].find(entity_id) != mapNoTraceManager[viewer_id].end())
		{
			mapNoTraceManager[viewer_id].erase(entity_id);
			return 1;
		}
	}

	return 0;
}

static cell AMX_NATIVE_CALL addtofullpack_manager_notrace_reset(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1 };

	int viewer_id = params[arg_viewer_id];

	if (mapNoTraceManager.find(viewer_id) == mapNoTraceManager.end())
	{
		return 0;
	}

	mapNoTraceManager.erase(viewer_id);
	return 1;
}

static cell AMX_NATIVE_CALL addtofullpack_manager_reset_all(Amx* amx, cell* params)
{
	enum args { arg_viewer_id = 1 };

	int viewer_id = params[arg_viewer_id];

	if (mapCollisionManager.find(viewer_id) != mapCollisionManager.end())
	{
		mapCollisionManager.erase(viewer_id);
	}

	if (mapAddToFullPackManager.find(viewer_id) != mapAddToFullPackManager.end())
	{
		mapAddToFullPackManager.erase(viewer_id);
	}

	if (mapNoTraceManager.find(viewer_id) != mapNoTraceManager.end())
	{
		mapNoTraceManager.erase(viewer_id);
	}


	return 1;
}

static const AmxNativeInfo natives[] =
{
	{"fullpack_set", addtofullpack_manager_set},
	{"fullpack_unset", addtofullpack_manager_unset},
	{"fullpack_reset", addtofullpack_manager_reset},
	{"fullpack_reset_all", addtofullpack_manager_reset_all},
	{"fullpack_semiclip_enable", addtofullpack_manager_collision_enable},
	{"fullpack_semiclip_disable", addtofullpack_manager_collision_disable},
	{"fullpack_semiclip_reset", addtofullpack_manager_collision_reset},
	{"fullpack_notrace_enable", addtofullpack_manager_notrace_enable},
	{"fullpack_notrace_disable", addtofullpack_manager_notrace_disable},
	{"fullpack_notrace_reset", addtofullpack_manager_notrace_reset},
	{nullptr, nullptr}
};

AmxxStatus on_amxx_attach()
{
	if (!RehldsApi::init() || !RegamedllApi::init())
		return AmxxStatus::FuncNotPresent;

	AddToFullPackManager::SingleEntityState::EntityStateInitTypes();

	GameDllHooks::add_to_full_pack(add_to_full_pack, true);

	GameDllHooks::pm_move(pm_move, false);

	EngineHooks::trace_line(trace_line, false);
	EngineHooks::trace_hull(trace_hull, false);

	GameDllHooks::server_deactivate(server_deactivate, true);
	AmxxApi::add_natives(natives);

	return AmxxStatus::Ok;
}

void on_amxx_detach()
{
}