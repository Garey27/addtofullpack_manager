// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/hook_chain_priority.h>

/// <summary>
/// Class HookChain.
/// </summary>
template <typename TRet, typename ...TArgs>
class HookChain {
protected:
	/// <summary>
	/// </summary>
	virtual ~HookChain() = default;

public:
	/// <summary>
	/// </summary>
	virtual TRet call_next(TArgs ...args) = 0;

	/// <summary>
	/// </summary>
	virtual TRet call_original(TArgs ...args) = 0;
};

/// <summary>
/// Class HookChainVoid.
/// </summary>
template <typename ...TArgs>
class HookChainVoid {
protected:
	/// <summary>
	/// </summary>
	virtual ~HookChainVoid() = default;

public:
	/// <summary>
	/// </summary>
	virtual void call_next(TArgs ...args) = 0;

	/// <summary>
	/// </summary>
	virtual void call_original(TArgs ...args) = 0;
};

/// <summary>
/// Class HookChainClass.
/// </summary>
template <typename TRet, typename TClass, typename ...TArgs>
class HookChainClass {
protected:
	/// <summary>
	/// </summary>
	virtual ~HookChainClass() = default;

public:
	/// <summary>
	/// </summary>
	virtual TRet call_next(TClass*, TArgs ...args) = 0;

	/// <summary>
	/// </summary>
	virtual TRet call_original(TClass*, TArgs ...args) = 0;
};

/// <summary>
/// <para>Hook chain registry(for hooks [un]registration).</para>
/// </summary>
template <typename TRet, typename ...TArgs>
class HookChainRegistry {
public:
	/// <summary>
	/// </summary>
	using HookFunc = TRet(*)(HookChain<TRet, TArgs...>*, TArgs ...);

	/// <summary>
	/// </summary>
	virtual void register_hook(HookFunc hook, HookChainPriority priority = HookChainPriority::Normal) = 0;

	/// <summary>
	/// </summary>
	virtual void unregister_hook(HookFunc hook) = 0;
};

/// <summary>
/// <para>Hook chain registry(for hooks [un]registration).</para>
/// </summary>
template <typename ...TArgs>
class HookChainVoidRegistry {
public:
	/// <summary>
	/// </summary>
	using HookFunc = void (*)(HookChainVoid<TArgs...>*, TArgs ...);

	/// <summary>
	/// </summary>
	virtual void register_hook(HookFunc hook, HookChainPriority priority = HookChainPriority::Normal) = 0;

	/// <summary>
	/// </summary>
	virtual void unregister_hook(HookFunc hook) = 0;
};

/// <summary>
/// <para>Hook chain registry(for hooks [un]registration).</para>
/// </summary>
template <typename TRet, typename TClass, typename ...TArgs>
class HookChainClassRegistry {
public:
	/// <summary>
	/// </summary>
	using HookFunc = TRet(*)(HookChainClass<TRet, TClass, TArgs...>*, TClass*, TArgs ...);

	/// <summary>
	/// </summary>
	virtual void register_hook(HookFunc hook, HookChainPriority priority = HookChainPriority::Normal) = 0;

	/// <summary>
	/// </summary>
	virtual void unregister_hook(HookFunc hook) = 0;
};
