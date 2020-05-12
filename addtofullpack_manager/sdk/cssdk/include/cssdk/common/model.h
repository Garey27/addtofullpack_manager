// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/bsp.h>
#include <cssdk/common/cl_entity.h>
#include <cssdk/public/base_types.h>

/// <summary>
/// </summary>
constexpr auto SURF_PLANE_BACK = 2;

/// <summary>
/// </summary>
constexpr auto SURF_DRAW_SKY = 4;

/// <summary>
/// </summary>
constexpr auto SURF_DRAW_SPRITE = 8;

/// <summary>
/// </summary>
constexpr auto SURF_DRAW_TURB = 0x10;

/// <summary>
/// </summary>
constexpr auto SURF_DRAW_TILED = 0x20;

/// <summary>
/// </summary>
constexpr auto SURF_DRAW_BACKGROUND = 0x40;

/// <summary>
/// </summary>
constexpr auto MAX_MODEL_NAME = 64;

/// <summary>
/// </summary>
constexpr auto TEX_SPECIAL = 1;

/// <summary>
/// </summary>
constexpr auto STUDIO_RENDER = 1;

/// <summary>
/// </summary>
constexpr auto STUDIO_EVENTS = 2;

/// <summary>
/// </summary>
constexpr auto PLANE_ANY_Z = 5;

/// <summary>
/// </summary>
constexpr auto ALIAS_Z_CLIP_PLANE = 5;

/// <summary>
/// </summary>
constexpr auto ALIAS_LEFT_CLIP = 0x0001;

/// <summary>
/// </summary>
constexpr auto ALIAS_TOP_CLIP = 0x0002;

/// <summary>
/// </summary>
constexpr auto ALIAS_RIGHT_CLIP = 0x0004;

/// <summary>
/// </summary>
constexpr auto ALIAS_MODEL_VERSION = 0x006;

/// <summary>
/// </summary>
constexpr auto ALIAS_BOTTOM_CLIP = 0x0008;

/// <summary>
/// </summary>
constexpr auto ALIAS_Z_CLIP = 0x0010;

/// <summary>
/// </summary>
constexpr auto ALIAS_ON_SEAM = 0x0020;

/// <summary>
/// </summary>
constexpr auto ALIAS_XY_CLIP_MASK = 0x000F;

/// <summary>
/// </summary>
constexpr float ZI_SCALE = 0x8000;

/// <summary>
/// <para>Used to align key data structures.</para>
/// </summary>
constexpr auto CACHE_SIZE = 32;

/// <summary>
/// </summary>
constexpr auto MAX_INFO_STRING = 256;

/// <summary>
/// </summary>
constexpr auto MAX_SCOREBOARD_NAME = 32;

/// <summary>
/// Enum ModelType
/// </summary>
enum class ModelType {
	/// <summary>
	/// </summary>
	Bad = -1,

	/// <summary>
	/// </summary>
	Brush,

	/// <summary>
	/// </summary>
	Sprite,

	/// <summary>
	/// </summary>
	Alias,

	/// <summary>
	/// </summary>
	Studio
};

/// <summary>
/// Enum SyncType
/// </summary>
enum class SyncType {
	/// <summary>
	/// </summary>
	Sync,

	/// <summary>
	/// </summary>
	Rand
};

/// <summary>
/// </summary>
struct DecalStruct;

/// <summary>
/// </summary>
struct MSurface;

/// <summary>
/// </summary>
struct Texture;

/// <summary>
/// </summary>
struct SurfCache;

/// <summary>
/// Struct MTexInfo
/// </summary>
struct MTexInfo {
	/// <summary>
	/// <para>[s/t] unit vectors in world space.<br/>
	/// [i][3] is the s/t offset relative to the origin.<br/>
	/// s or t = dot(3Dpoint, vecs[i]) + vecs[i][3]</para>
	/// </summary>
	float vectors[2][4]{};

	/// <summary>
	/// <para>Mipmap limits for very small surfaces.</para>
	/// </summary>
	float mip_adjust{};

	/// <summary>
	/// </summary>
	Texture* texture{};

	/// <summary>
	/// <para>Sky or slime, no light map or 256 subdivision.</para>
	/// </summary>
	int flags{};
};

/// <summary>
/// Struct MPlane
/// </summary>
struct MPlane {
	/// <summary>
	/// <para>Surface normal.</para>
	/// </summary>
	Vector normal;

	/// <summary>
	/// <para>Closest approach to origin.</para>
	/// </summary>
	float dist{};

	/// <summary>
	/// <para>For texture axis selection and fast side tests.</para>
	/// </summary>
	byte type{};

	/// <summary>
	/// <para>signX + signY << 1 + signZ << 1</para>
	/// </summary>
	byte sign_bits{};

	/// <summary>
	/// </summary>
	byte pad[2]{};
};

/// <summary>
/// Struct MSurface
/// </summary>
struct MSurface {
	/// <summary>
	/// <para>Should be drawn when node is crossed.</para>
	/// </summary>
	int vis_frame{};

	/// <summary>
	/// <para>Last frame the surface was checked by an animated light.</para>
	/// </summary>
	int d_light_frame{};

	/// <summary>
	/// <para>Dynamically generated. Indicates if the surface illumination is modified by an animated light.</para>
	/// </summary>
	int d_light_bits{};

	/// <summary>
	/// <para>Pointer to shared plane.</para>
	/// </summary>
	MPlane* plane{};

	/// <summary>
	/// <para>See SURF_ constants.</para>
	/// </summary>
	int flags{};

	/// <summary>
	/// <para>Look up in Model->surf_edges[], negative numbers.</para>
	/// </summary>
	int first_edge{};

	/// <summary>
	/// <para>Are backwards edges.</para>
	/// </summary>
	int num_edges{};

	/// <summary>
	/// </summary>
	SurfCache* cache_spots[MIP_LEVELS]{};

	/// <summary>
	/// <para>Smallest s/t position on the surface.</para>
	/// </summary>
	short texture_min_size[2]{};

	/// <summary>
	/// <para>s/t texture size, 1..256 for all non-sky surfaces.</para>
	/// </summary>
	short extents[2]{};

	/// <summary>
	/// </summary>
	MTexInfo* tex_info{};

	/// <summary>
	/// <para>Index into d_light_style_value[] for animated lights
	/// no one surface can be effected by more than 4 animated lights.</para>
	/// </summary>
	byte styles[MAX_LIGHT_MAPS]{};

	/// <summary>
	/// </summary>
	Color24* samples{};

	/// <summary>
	/// </summary>
	DecalStruct* decals{};
};

/// <summary>
/// Struct DecalStruct
/// </summary>
struct DecalStruct {
	/// <summary>
	/// <para>Linked list for each surface.</para>
	/// </summary>
	DecalStruct* next{};

	/// <summary>
	/// <para>Surface id for persistence / unlinking.</para>
	/// </summary>
	MSurface* surface{};

	/// <summary>
	/// <para>Offset into surface texture (in texture coordinates, so we don't need floats).</para>
	/// </summary>
	short dx{};

	/// <summary>
	/// <para>Offset into surface texture (in texture coordinates, so we don't need floats).</para>
	/// </summary>
	short dy{};

	/// <summary>
	/// <para>Decal texture.</para>
	/// </summary>
	short texture{};

	/// <summary>
	/// <para>Pixel scale.</para>
	/// </summary>
	byte scale{};

	/// <summary>
	/// <para>Decal flags.</para>
	/// </summary>
	byte flags{};

	/// <summary>
	/// <para>Entity this is attached to.</para>
	/// </summary>
	short entity_index{};
};

/// <summary>
/// Struct MNode
/// </summary>
struct MNode {
	/// <summary>
	/// <para>0, to differentiate from leafs.</para>
	/// </summary>
	int contents{};

	/// <summary>
	/// <para>Node needs to be traversed if current.</para>
	/// </summary>
	int vis_frame{};

	/// <summary>
	/// <para>For bounding box culling.</para>
	/// </summary>
	short min_max_sizes[6]{};

	/// <summary>
	/// </summary>
	MNode* parent{};

	/// <summary>
	/// </summary>
	MPlane* plane{};

	/// <summary>
	/// </summary>
	MNode* children[2]{};

	/// <summary>
	/// </summary>
	unsigned short first_surface{};

	/// <summary>
	/// </summary>
	unsigned short num_surfaces{};
};

/// <summary>
/// Struct MLeaf
/// </summary>
struct MLeaf {
	/// <summary>
	///	<para>Will be a negative contents number.</para>
	/// </summary>
	int contents{};

	/// <summary>
	/// <para>Node needs to be traversed if current.</para>
	/// </summary>
	int vis_frame{};

	/// <summary>
	/// <para>For bounding box culling.</para>
	/// </summary>
	short min_max_sizes[6]{};

	/// <summary>
	/// </summary>
	MNode* parent{};

	/// <summary>
	/// </summary>
	byte* compressed_vis{};

	/// <summary>
	/// </summary>
	EFrag* e_frags{};

	/// <summary>
	/// </summary>
	MSurface** first_mark_surface{};

	/// <summary>
	/// </summary>
	int num_mark_surfaces{};

	/// <summary>
	/// <para>BSP sequence number for leaf's contents.</para>
	/// </summary>
	int key{};

	/// <summary>
	/// </summary>
	byte ambient_sound_level[NUM_AMBIENTS]{};
};

/// <summary>
/// Struct MVertex
/// </summary>
struct MVertex {
	/// <summary>
	/// </summary>
	Vector position;
};

/// <summary>
/// Struct MEdge
/// </summary>
struct MEdge {
	/// <summary>
	/// </summary>
	unsigned short v[2]{};

	/// <summary>
	/// </summary>
	unsigned int cached_edge_offset{};
};

/// <summary>
/// Struct Hull
/// </summary>
struct Hull {
	/// <summary>
	/// </summary>
	DClipNode* clip_nodes{};

	/// <summary>
	/// </summary>
	MPlane* planes{};

	/// <summary>
	/// </summary>
	int first_clip_node{};

	/// <summary>
	/// </summary>
	int last_clip_node{};

	/// <summary>
	/// </summary>
	Vector clip_min_size;

	/// <summary>
	/// </summary>
	Vector clip_max_size;
};

/// <summary>
/// Struct CacheUser
/// </summary>
struct CacheUser {
	/// <summary>
	/// </summary>
	void* data{};
};

/// <summary>
/// Struct Model
/// </summary>
struct Model {
	/// <summary>
	/// </summary>
	char name[MAX_MODEL_NAME]{};

	/// <summary>
	/// </summary>
	qboolean need_load{};

	/// <summary>
	/// </summary>
	ModelType type{};

	/// <summary>
	/// </summary>
	int num_frames{};

	/// <summary>
	/// </summary>
	SyncType sync{};

	/// <summary>
	/// </summary>
	int flags{};

	//
	// Volume occupied by the model.
	//

	/// <summary>
	/// </summary>
	Vector min_size;

	/// <summary>
	/// </summary>
	Vector max_size;

	/// <summary>
	/// </summary>
	float radius{};

	//
	// Brush model.
	//

	/// <summary>
	/// </summary>
	int first_model_surface{};

	/// <summary>
	/// </summary>
	int num_model_surfaces{};

	/// <summary>
	/// </summary>
	int num_submodels{};

	/// <summary>
	/// </summary>
	DModel* submodels{};

	/// <summary>
	/// </summary>
	int num_planes{};

	/// <summary>
	/// </summary>
	MPlane* planes{};

	/// <summary>
	///	<para>Number of visible leafs, not counting 0.</para>
	/// </summary>
	int num_leafs{};

	/// <summary>
	/// </summary>
	MLeaf* leafs{};

	/// <summary>
	/// </summary>
	int num_vertexes{};

	/// <summary>
	/// </summary>
	MVertex* vertexes{};

	/// <summary>
	/// </summary>
	int num_edges{};

	/// <summary>
	/// </summary>
	MEdge* edges{};

	/// <summary>
	/// </summary>
	int num_nodes{};

	/// <summary>
	/// </summary>
	MNode* nodes{};

	/// <summary>
	/// </summary>
	int num_tex_info{};

	/// <summary>
	/// </summary>
	MTexInfo* tex_info{};

	/// <summary>
	/// </summary>
	int num_surfaces{};

	/// <summary>
	/// </summary>
	MSurface* surfaces{};

	/// <summary>
	/// </summary>
	int num_surf_edges{};

	/// <summary>
	/// </summary>
	int* surf_edges{};

	/// <summary>
	/// </summary>
	int num_clip_nodes{};

	/// <summary>
	/// </summary>
	DClipNode* clip_nodes{};

	/// <summary>
	/// </summary>
	int num_mark_surfaces{};

	/// <summary>
	/// </summary>
	MSurface** mark_surfaces{};

	/// <summary>
	/// </summary>
	Hull hulls[MAX_MAP_HULLS];

	/// <summary>
	/// </summary>
	int num_textures{};

	/// <summary>
	/// </summary>
	Texture** textures{};

	/// <summary>
	/// </summary>
	byte* vis_data{};

	/// <summary>
	/// </summary>
	Color24* light_data{};

	/// <summary>
	/// </summary>
	char* entities{};

	//
	// additional model data
	//

	/// <summary>
	/// <para>Only access through <c>Mod_Extradata</c></para>
	/// </summary>
	CacheUser cache;
};
