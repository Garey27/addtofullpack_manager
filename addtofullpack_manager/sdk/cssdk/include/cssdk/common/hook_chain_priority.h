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
/// <para>Specifies priorities for hooks call order in the chain.<br/>
/// For equal priorities first registered hook will be called first.</para>
/// </summary>
enum class HookChainPriority {
	/// <summary>
	/// <para>Hook will be called before other hooks.</para>
	/// </summary>
	Uninterruptable = 255,

	/// <summary>
	/// <para>Hook will be called before hooks with <c>Normal</c> priority.</para>
	/// </summary>
	High = 192,

	/// <summary>
	/// <para>Default hook call priority.</para>
	/// </summary>
	Normal = 128,

	/// <summary>
	/// <para>Hook will be called after hooks with <c>Normal</c> priority.</para>
	/// </summary>
	Medium = 64,

	/// <summary>
	/// <para>Hook will be called after all other hooks.</para>
	/// </summary>
	Low = 0
};
