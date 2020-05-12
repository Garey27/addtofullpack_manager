// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/base_types.h>

/// <summary>
/// <para>Half-Life regular version.</para>
/// </summary>
constexpr auto BSP_VERSION = 30;

/// <summary>
/// </summary>
constexpr auto MAX_MAP_HULLS = 4;

/// <summary>
/// </summary>
constexpr auto CONTENTS_EMPTY = -1;

/// <summary>
/// </summary>
constexpr auto CONTENTS_SOLID = -2;

/// <summary>
/// </summary>
constexpr auto CONTENTS_WATER = -3;

/// <summary>
/// </summary>
constexpr auto CONTENTS_SLIME = -4;

/// <summary>
/// </summary>
constexpr auto CONTENTS_LAVA = -5;

/// <summary>
/// </summary>
constexpr auto CONTENTS_SKY = -6;

/// <summary>
/// <para>Removed at csg time.</para>
/// </summary>
constexpr auto CONTENTS_ORIGIN = -7;

/// <summary>
/// <para>Changed to CONTENTS_SOLID.</para>
/// </summary>
constexpr auto CONTENTS_CLIP = -8;

/// <summary>
/// </summary>
constexpr auto CONTENTS_CURRENT_0 = -9;

/// <summary>
/// </summary>
constexpr auto CONTENTS_CURRENT_90 = -10;

/// <summary>
/// </summary>
constexpr auto CONTENTS_CURRENT_180 = -11;

/// <summary>
/// </summary>
constexpr auto CONTENTS_CURRENT_270 = -12;

/// <summary>
/// </summary>
constexpr auto CONTENTS_CURRENT_UP = -13;

/// <summary>
/// </summary>
constexpr auto CONTENTS_CURRENT_DOWN = -14;

/// <summary>
/// </summary>
constexpr auto CONTENTS_TRANSLUCENT = -15;

/// <summary>
/// </summary>
constexpr auto CONTENTS_LADDER = -16;

/// <summary>
/// </summary>
constexpr auto CONTENTS_FLY_FIELD = -17;

/// <summary>
/// </summary>
constexpr auto CONTENTS_GRAVITY_FLY_FIELD = -18;

/// <summary>
/// </summary>
constexpr auto CONTENTS_FOG = -19;

/// <summary>
/// </summary>
constexpr auto LUMP_ENTITIES = 0;

/// <summary>
/// </summary>
constexpr auto LUMP_PLANES = 1;

/// <summary>
/// </summary>
constexpr auto LUMP_TEXTURES = 2;

/// <summary>
/// </summary>
constexpr auto LUMP_VERTEXES = 3;

/// <summary>
/// </summary>
constexpr auto LUMP_VISIBILITY = 4;

/// <summary>
/// </summary>
constexpr auto LUMP_NODES = 5;

/// <summary>
/// </summary>
constexpr auto LUMP_TEX_INFO = 6;

/// <summary>
/// </summary>
constexpr auto LUMP_FACES = 7;

/// <summary>
/// </summary>
constexpr auto LUMP_LIGHTING = 8;

/// <summary>
/// </summary>
constexpr auto LUMP_CLIP_NODES = 9;

/// <summary>
/// </summary>
constexpr auto LUMP_LEAFS = 10;

/// <summary>
/// </summary>
constexpr auto LUMP_MARK_SURFACES = 11;

/// <summary>
/// </summary>
constexpr auto LUMP_EDGES = 12;

/// <summary>
/// </summary>
constexpr auto LUMP_SURF_EDGES = 13;

/// <summary>
/// </summary>
constexpr auto LUMP_MODELS = 14;

/// <summary>
/// </summary>
constexpr auto HEADER_LUMPS = 15;

/// <summary>
/// </summary>
constexpr auto MIP_LEVELS = 4;

/// <summary>
/// </summary>
constexpr auto MAX_LIGHT_MAPS = 4;

/// <summary>
/// <para>Automatic ambient sounds.</para>
/// </summary>
constexpr auto NUM_AMBIENTS = 4;

/// <summary>
/// Struct Lump
/// </summary>
struct Lump {
	/// <summary>
	/// </summary>
	int file_ofs{};

	/// <summary>
	/// </summary>
	int file_len{};
};

/// <summary>
/// Struct DModel
/// </summary>
struct DModel {
	/// <summary>
	/// </summary>
	float min_size[3]{};

	/// <summary>
	/// </summary>
	float max_size[3]{};

	/// <summary>
	/// </summary>
	float origin[3]{};

	/// <summary>
	/// </summary>
	int head_node[MAX_MAP_HULLS]{};

	/// <summary>
	/// <para>Not including the solid leaf 0.</para>
	/// </summary>
	int vis_leafs{};

	/// <summary>
	/// </summary>
	int first_face{};

	/// <summary>
	/// </summary>
	int num_faces{};
};

/// <summary>
/// Struct DHeader
/// </summary>
struct DHeader {
	/// <summary>
	/// </summary>
	int version{};

	/// <summary>
	/// </summary>
	Lump lumps[HEADER_LUMPS];
};

/// <summary>
/// Struct DMipTexLump
/// </summary>
struct DMipTexLump {
	/// <summary>
	/// </summary>
	int num_mip_tex{};

	/// <summary>
	/// </summary>
	int data_ofs[4]{};
};

/// <summary>
/// Struct MipTex
/// </summary>
struct MipTex {
	/// <summary>
	/// </summary>
	char name[16]{};

	/// <summary>
	/// </summary>
	unsigned width{};

	/// <summary>
	/// </summary>
	unsigned height{};

	/// <summary>
	/// <para>Four mip maps stored.</para>
	/// </summary>
	unsigned offsets[MIP_LEVELS]{};
};

/// <summary>
/// Struct DVertex
/// </summary>
struct DVertex {
	/// <summary>
	/// </summary>
	float point[3]{};
};

/// <summary>
/// Struct DPlane
/// </summary>
struct DPlane {
	/// <summary>
	/// </summary>
	float normal[3]{};

	/// <summary>
	/// </summary>
	float dist{};

	/// <summary>
	/// </summary>
	int type{};
};

/// <summary>
/// Struct DNode
/// </summary>
struct DNode {
	/// <summary>
	/// </summary>
	int plane_num{};

	/// <summary>
	/// <para>Negative numbers are -(leafs+1), not nodes.</para>
	/// </summary>
	short children[2]{};

	/// <summary>
	/// <para>For sphere culling.</para>
	/// </summary>
	short min_size[3]{};

	/// <summary>
	/// <para>For sphere culling.</para>
	/// </summary>
	short max_size[3]{};

	/// <summary>
	/// </summary>
	unsigned short first_face{};

	/// <summary>
	/// <para>Counting both sides.</para>
	/// </summary>
	unsigned short num_faces{};
};

/// <summary>
/// Struct DClipNode
/// </summary>
struct DClipNode {
	/// <summary>
	/// </summary>
	int plane_num{};

	/// <summary>
	/// <para>Negative numbers are contents.</para>
	/// </summary>
	short children[2]{};
};

/// <summary>
/// Struct TexInfo
/// </summary>
struct TexInfo {
	/// <summary>
	/// <para>[s/t][xyz offset].</para>
	/// </summary>
	float vectors[2][4]{};

	/// <summary>
	/// </summary>
	int mip_tex{};

	/// <summary>
	/// </summary>
	int flags{};
};

/// <summary>
/// Struct DEdge<br/>
/// </summary>
/// <remarks>
/// That edge 0 is never used, because negative edge nums are used for
/// counterclockwise use of the edge in a face.
/// </remarks>
struct DEdge {
	/// <summary>
	/// <para>Vertex numbers.</para>
	/// </summary>
	unsigned short vertex[2]{};
};

/// <summary>
/// Struct DFace
/// </summary>
struct DFace {
	/// <summary>
	/// </summary>
	short plane_num{};

	/// <summary>
	/// </summary>
	short side{};

	/// <summary>
	/// <para>We must support > 64k edges.</para>
	/// </summary>
	int first_edge{};

	/// <summary>
	/// </summary>
	short num_edges{};

	/// <summary>
	/// </summary>
	short tex_info{};

	/// <summary>
	/// </summary>
	byte styles[MAX_LIGHT_MAPS]{};

	/// <summary>
	/// <para>Start of [num_styles * surf_size] samples.</para>
	/// </summary>
	int light_ofs{};
};

/// <summary>
/// Struct DLeaf<br/>
/// </summary>
/// <remarks>
/// Leaf 0 is the generic CONTENTS_SOLID leaf, used for all solid areas
/// all other leafs need visibility info.
/// </remarks>
struct DLeaf {
	/// <summary>
	/// </summary>
	int contents{};

	/// <summary>
	/// <para>-1 = no visibility info.</para>
	/// </summary>
	int vis_ofs{};

	/// <summary>
	/// <para>For frustum culling.</para>
	/// </summary>
	short min_size[3]{};

	/// <summary>
	/// <para>For frustum culling.</para>
	/// </summary>
	short max_size[3]{};

	/// <summary>
	/// </summary>
	unsigned short first_mark_surface{};

	/// <summary>
	/// </summary>
	unsigned short num_mark_surfaces{};

	/// <summary>
	/// </summary>
	byte ambient_level[NUM_AMBIENTS]{};
};
