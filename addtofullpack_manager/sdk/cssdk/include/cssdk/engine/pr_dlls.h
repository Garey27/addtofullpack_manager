// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/save_restore.h>
#include <cssdk/engine/entity_vars.h>
#include <cssdk/public/arch_types.h>

/// <summary>
/// </summary>
const int MAX_EXTENSION_DLL = 50;

/// <summary>
/// Struct FunctionTable
/// </summary>
struct FunctionTable {
	/// <summary>
	/// </summary>
	uint32 function{};

	/// <summary>
	/// </summary>
	char* function_name{};
};

/// <summary>
/// Struct ExtensionDll
/// </summary>
struct ExtensionDll {
	/// <summary>
	/// </summary>
	void* dll_handle{};

	/// <summary>
	/// </summary>
	FunctionTable* func_table{};

	/// <summary>
	/// </summary>
	int function_count{};
};

/// <summary>
/// </summary>
using EntityInit = void(*)(EntityVars*);

/// <summary>
/// </summary>
using DispatchFunction = void(*)(EntityVars*, void*);

/// <summary>
/// </summary>
using FieldIoFunction = void(*)(SaveRestoreData*, const char*, void*, TypeDescription*, int);
