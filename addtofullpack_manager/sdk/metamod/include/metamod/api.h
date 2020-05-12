// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <metamod/metamod_config.h>

/// <summary>
/// <para>Metamod interface version.</para>
/// </summary>
constexpr auto META_INTERFACE_VERSION = "5:13";

/// <summary>
/// Enum MetamodStatus
/// </summary>
enum class MetamodStatus : int {
	/// <summary>
	/// </summary>
	Failed = 0,

	/// <summary>
	/// </summary>
	Ok
};

/// <summary>
/// <para>Flags returned by a plugin's API function.<br/></para>
/// </summary>
/// <remarks>
/// Order is crucial, as greater/less comparisons are made.
/// </remarks>
enum class MetaResult {
	/// <summary>
	/// </summary>
	Unset = 0,

	/// <summary>
	/// <para>Plugin didn't take any action.</para>
	/// </summary>
	Ignored,

	/// <summary>
	/// <para>Plugin did something, but real function should still be called.</para>
	/// </summary>
	Handled,

	/// <summary>
	/// <para>Call real function, but use my return value.</para>
	/// </summary>
	Override,

	/// <summary>
	/// <para>Skip real function; use my return value.</para>
	/// </summary>
	Supercede
};

/// <summary>
/// <para>Variables provided to plugins.</para>
/// </summary>
struct MetaGlobals {
	/// <summary>
	/// <para>Writable; plugin's return flag.</para>
	/// </summary>
	MetaResult result{};

	/// <summary>
	/// <para>Readable; return flag of the previous plugin called.</para>
	/// </summary>
	MetaResult prev_result{};

	/// <summary>
	/// <para>Readable; "highest" return flag so far.</para>
	/// </summary>
	MetaResult status{};

	/// <summary>
	/// <para>Readable; return value from "real" function.</para>
	/// </summary>
	void* orig_ret{};

	/// <summary>
	/// <para>Readable; return value from overriding/superceding plugin.</para>
	/// </summary>
	void* override_ret{};
};

/// <summary>
/// <para>Metamod globals.</para>
/// </summary>
extern MetaGlobals* g_meta_globals;

/// <summary>
/// <para>Sets the meta result (plugin's return flag).</para>
/// </summary>
inline void set_meta_result(const MetaResult result)
{
	g_meta_globals->result = result;
}

/// <summary>
/// <para>Gets the meta result status ("highest" return flag so far).</para>
/// </summary>
inline MetaResult meta_result_status()
{
	return g_meta_globals->status;
}

/// <summary>
/// <para>Gets the previous meta result (return flag of the previous plugin called).</para>
/// </summary>
inline MetaResult meta_result_previous()
{
	return g_meta_globals->prev_result;
}

/// <summary>
/// <para>Returns value from "real" function.</para>
/// </summary>
template <typename T>
T meta_result_orig_ret()
{
	return *reinterpret_cast<T*>(g_meta_globals->orig_ret);
}

/// <summary>
/// <para>Return value from overriding/superceding plugin.</para>
/// </summary>
template <typename T>
T meta_result_override_ret()
{
	return *reinterpret_cast<T*>(g_meta_globals->override_ret);
}

#define RETURN_META(result) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	do { set_meta_result(result); return; } while (0)

#define RETURN_META_VALUE(result, value) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	do { set_meta_result(result); return value; } while (0)

#ifdef META_INIT
void META_INIT();
#endif

#ifdef META_QUERY
void META_QUERY();
#endif

#ifdef META_ATTACH
MetamodStatus META_ATTACH();
#endif

#ifdef META_DETACH
void META_DETACH();
#endif
