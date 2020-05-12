// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <cssdk/engine/eiface.h>
#include <metamod/engine.h>
#include <metamod/os_dep.h>
#include <cstring>

/// <summary>
/// </summary>
EngineFuncPointers g_engine_funcs;

/// <summary>
/// </summary>
GlobalVars* g_global_vars = nullptr;

#ifdef _WIN32
/// <summary>
/// <para>Entry point.</para>
/// </summary>
BOOL WINAPI DllMain([[maybe_unused]] HINSTANCE, [[maybe_unused]] const DWORD, [[maybe_unused]] LPVOID)
{
	return TRUE;
}
#endif

/// <summary>
/// <para>Receive engine function table from engine.<br/>
/// This appears to be the _first_ DLL routine called by the engine, so we do some setup operations here.</para>
/// </summary>
extern "C" void DLLEXPORT WINAPI GiveFnptrsToDll(EngineFuncPointers* engine_funcs, GlobalVars* global_vars)
{
	g_global_vars = global_vars;
	std::memcpy(&g_engine_funcs, engine_funcs, sizeof(EngineFuncPointers));
	Engine::engine_funcs_ = &g_engine_funcs;
}
