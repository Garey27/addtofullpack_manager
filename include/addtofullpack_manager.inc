#if defined _addtofullpack_manager_included
	#endinput
#endif

#define _addtofullpack_manager_included

#pragma reqlib addtofullpack_manager
#if !defined AMXMODX_NOAUTOLOAD
    #pragma loadlib addtofullpack_manager
#endif


enum entity_state_e
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


/**
 * Set entity state for entity that sends to viewer in module function AddtoFullpack.
 *
 * @param viewer		Viewer id
 * @param entity		Entity id
 * @param es			Entity state
 * @param any			Value
 *
 * @note 				Value should have exact same size as corresponding entity_state_t member!
 * 			
 * @note 				Usage examples:
 *  						fullpack_set(id, ent, es_origin, Float:{0.0, 0.0, 0.0});
 *							fullpack_set(id, ent, es_effects, EF_NODRAW);	
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_set(viewer, entity, entity_state_e:es, any:...);


/**
 * Unsets given field of entity state for entity.
 *
 * @param viewer		Viewer id
 * @param entity		Entity id
 * @param es			Entity state
 *	
 * @note 				Usage examples:
 *  						fullpack_unset(id, ent, es_origin);
 *							fullpack_unset(id, ent, es_effects);	
 *						
 * @return				1 on success, 0 if field not found
 */
native fullpack_unset(viewer, entity, entity_state_e:es);


/**
 * Reset all fields of entity state for entity.
 *
 * @param viewer		Viewer id
 *	
 * @note 				Usage examples:
 *							fullpack_reset(id);	
 *						
 * @return				1 on success, 0 if viewer dont have any assigned entity_state_e fields.
 */
native fullpack_reset(viewer);


/**
 * Sets semiclip (disable collision between two enities) between toucher and touched id
 *
 * @param toucher		Toucher id
 * @param touched		Touched id
 *
 * @note 				Be careful when disable collision between entity who have gravity and world (touched==0)!
 * 			
 * @note 				Usage examples:
 *  						fullpack_semiclip_enable(id, ent);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_semiclip_enable(toucher, touched);


/**
 * Disables semiclip (enable collision between two enities) between toucher and touched id
 *
 * @param toucher		Toucher id
 * @param touched		Touched id
 * 			
 * @note 				Usage examples:
 *  						fullpack_semiclip_disable(id, ent);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_semiclip_disable(toucher, touched);


/**
 * Resets all semiclip preferences that previously set with fullpack_semiclip_enable
 *
 * @param toucher		Toucher id
 * 			
 * @note 				Usage examples:
 *  						fullpack_semiclip_reset(toucher);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_semiclip_reset(toucher);


/**
 * Disables TraceLine/TraceHull functions between two entities
 *
 * @param id			Id that corresponding to skipEnt entity in trace_line/hull functions
 * @param ignore_id		Id that ignore in trace function
 * 			
 * @note 				Usage examples:
 *  						fullpack_notrace_enable(id, ent);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_notrace_enable(id, ignore_id);


/**
 * Enables TraceLine/TraceHull functions between two entities that previously disabled by fullpack_notrace_enable
 *
 * @param id			Id that corresponding to skipEnt entity in trace_line/hull functions
 * @param ignore_id		Id that ignore in trace function
 * 			
 * @note 				Usage examples:
 *  						fullpack_notrace_disable(id, ent);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_notrace_disable(id, ignore_id);


/**
 * Resets all trace preferences that previously disabled with fullpack_notrace_enable
 *
 * @param id			Id that corresponding to skipEnt entity in trace_line/hull functions
 * 			
 * @note 				Usage examples:
 *  						fullpack_notrace_reset(id);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_notrace_reset(id);

/**
 * Enable collision between two enities between toucher and touched id
 *
 * @param toucher		Toucher id
 * @param touched		Touched id
 *	
 * @note 				Usage examples:
 *  						fullpack_collision_enable(toucher, touched);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_nocollision_enable(toucher, touched);


/**
 * Disable collision between two enities between toucher and touched id
 *
 * @param toucher		Toucher id
 * @param touched		Touched id
 *		
 * @note 				Usage examples:
 *  						fullpack_collision_disable(toucher, touched);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_nocollision_disable(toucher, touched);


/**
 * Resets all collision preferences that previously set with fullpack_collision_disable
 *
 * @param toucher		Toucher id
 *		
 * @note 				Usage examples:
 *  						fullpack_collision_reset(toucher);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_nocollision_reset(toucher);


/**
 * Resets all states in module (fullpack, semiclip, notrace, nocollision) to given entity (Useful when player is connected/disconnected)
 *
 * @param id			Id to reset all states
 * 			
 * @note 				Usage examples:
 *  						fullpack_reset_all(id);
 *						
 * @return				1 on success, otherwise 0
 */
native fullpack_reset_all(index);