// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <metamod/gamedll.h>

/// <summary>
/// <para>DLL functions table.</para>
/// </summary>
const DllFuncPointers* GameDll::dll_funcs_ = nullptr;

/// <summary>
/// <para>New DLL functions table.</para>
/// </summary>
const DllNewFuncPointers* GameDllNew::dll_new_funcs_ = nullptr;
