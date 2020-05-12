// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/os_config.h>

/// <summary>
/// </summary>
constexpr auto CREATE_INTERFACE_PROC_NAME = "CreateInterface";

/// <summary>
/// </summary>
enum class CreateInterfaceStatus {
	/// <summary>
	/// </summary>
	Ok = 0,

	/// <summary>
	/// </summary>
	Failed
};

/// <summary>
/// <para>All interfaces derive from this.</para>
/// </summary>
class SysInterfaceBase {
public:
	/// <summary>
	/// </summary>
	virtual ~SysInterfaceBase() = default;
};

/// <summary>
/// </summary>
using CreateInterfaceFn = SysInterfaceBase* (*)(const char* name, CreateInterfaceStatus* return_code);

/// <summary>
/// </summary>
using InstantiateInterfaceFn = SysInterfaceBase* (*)();

/// <summary>
/// <para>Used internally to register classes.</para>
/// </summary>
class SysInterfaceReg {
public:
	/// <summary>
	/// </summary>
	SysInterfaceReg(const InstantiateInterfaceFn fn, const char* interface_name) : name(interface_name)
	{
		create_fn = fn;
		next = interface_regs;
		interface_regs = this;
	}

	/// <summary>
	/// </summary>
	InstantiateInterfaceFn create_fn{};

	/// <summary>
	/// </summary>
	const char* name{};

	/// <summary>
	/// <para>For the global list.</para>
	/// </summary>
	SysInterfaceReg* next{};

	/// <summary>
	/// </summary>
	static SysInterfaceReg* interface_regs;
};

// Use this to expose an interface that can have multiple instances.
// e.g.:
// EXPOSE_INTERFACE(CInterfaceImp, IInterface, "MyInterface001")
// This will expose a class called CInterfaceImp that implements IInterface (a pure class)
// clients can receive a pointer to this class by calling CreateInterface("MyInterface001")
//
// In practice, the shared header file defines the interface (IInterface) and version name ("MyInterface001")
// so that each component can use these names/vtables to communicate
//
// A single class can support multiple interfaces through multiple inheritance
//
// Use this if you want to write the factory function.
#define EXPOSE_INTERFACE_FN(functionName, interfaceName, versionName) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	static SysInterfaceReg __g_Create##interfaceName##_reg(functionName, versionName);

#define EXPOSE_INTERFACE(className, interfaceName, versionName) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	static SysInterfaceBase *__Create##className##_interface() {return (interfaceName*)new (className);} \
	static SysInterfaceReg __g_Create##className##_reg(__Create##className##_interface, versionName);

// Use this to expose a singleton interface with a global variable you've created.
#define EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, globalVarName) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	static SysInterfaceBase *__Create##className##interfaceName##_interface() {return (SysInterfaceBase *)&(globalVarName);} \
	static SysInterfaceReg __g_Create##className##interfaceName##_reg(__Create##className##interfaceName##_interface, versionName);

// Use this to expose a singleton interface. This creates the global variable for you automatically.
#define EXPOSE_SINGLE_INTERFACE(className, interfaceName, versionName) /* NOLINT(cppcoreguidelines-macro-usage) */ \
	static className __g_##className##_singleton; \
	EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, __g_##className##_singleton)

#if defined(_WIN32)
#define EXPORT_FUNCTION __declspec(dllexport) EXT_FUNC  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define EXPORT_FUNCTION __attribute__((visibility("default"))) EXT_FUNC  // NOLINT(cppcoreguidelines-macro-usage)
#endif

/// <summary>
/// <para>Load/unload components.</para>
/// </summary>
class SysModule;

extern "C" {
/// <summary>
/// </summary>
EXPORT_FUNCTION SysInterfaceBase* create_interface(const char* name, CreateInterfaceStatus* return_code);
}

/// <summary>
/// </summary>
void* initialize_interface(char const* interface_name, CreateInterfaceFn* factory_list, int num_factories);

/// <summary>
/// </summary>
CreateInterfaceFn sys_get_factory_this();

/// <summary>
/// <para>Loads a DLL/component from disk and returns a handle to it.<br/></para>
/// </summary>
/// <param name="module_name">Filename of the component.<br/></param>
/// <returns>Opaque handle to the module (hides system dependency).</returns>
SysModule* sys_load_module(const char* module_name);

/// <summary>
/// <para>Unloads a DLL/component from.<br/></para>
/// </summary>
/// <param name="module_handle">Opaque handle to the module (hides system dependency).</param>
bool sys_unload_module(SysModule*& module_handle);

/// <summary>
/// <para>Returns a pointer to a function, given a module.<br/></para>
/// </summary>
/// <param name="module_handle">Opaque handle to the module (hides system dependency).<br/></param>
/// <returns>Factory for this module.</returns>
CreateInterfaceFn sys_get_factory(SysModule* module_handle);
