// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//				Copyright (c) ITB CompuPhase, 1997-2005.
// ***********************************************************************

#pragma once

#include <cstdint>

#if !defined AMX_NATIVE_CALL
#define AMX_NATIVE_CALL
#endif

#if !defined AMXAPI
#if defined STDECL
#define AMXAPI __stdcall
#elif defined CDECL
#define AMXAPI __cdecl
#else
#define AMXAPI
#endif
#endif

#if !defined PAWN_CELL_SIZE
#define PAWN_CELL_SIZE 32  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#if PAWN_CELL_SIZE==32
using cell = int32_t;
using ucell = uint32_t;
using real = float;
#elif PAWN_CELL_SIZE==64
using cell = uint64_t;
using ucell = uint64_t;
using real = double;
#else
#error Unsupported cell size (PAWN_CELL_SIZE)
#endif

#if !defined _FAR
#define _FAR
#endif

/*
 * File format version							Required AMX version
 *	0 (original version)						0
 *	1 (opcodes JUMP.pri, SWITCH and CASETBL)	1
 *	2 (compressed files)						2
 *	3 (public variables)						2
 *	4 (opcodes SWAP.pri/alt and PUSHADDR)		4
 *	5 (tagnames table)							4
 *	6 (reformatted header)						6
 *	7 (name table, opcodes SYMTAG & SYSREQ.D)	7
 *	8 (opcode STMT, renewed debug interface)	8
 */

/// <summary>
/// <para>Current file version; also the current AMX version.</para>
/// </summary>
constexpr auto CUR_FILE_VERSION = 8;

/// <summary>
/// <para>Lowest supported file format version for the current AMX version.</para>
/// </summary>
constexpr auto MIN_FILE_VERSION = 6;

/// <summary>
/// <para>Minimum AMX version needed to support the current file format.</para>
/// </summary>
constexpr auto MIN_AMX_VERSION = 8;

/// <summary>
/// <para>This is always the same for us.</para>
/// </summary>
constexpr auto AMX_MAGIC = 0xF1E0;

/// <summary>
/// <para>Symbolic info available.</para>
/// </summary>
constexpr auto AMX_FLAG_DEBUG = 0x02;

/// <summary>
/// <para>Compact encoding.</para>
/// </summary>
constexpr auto AMX_FLAG_COMPACT = 0x04;

/// <summary>
/// <para>Opcode is a byte (not a cell).</para>
/// </summary>
constexpr auto AMX_FLAG_BYTE_OPC = 0x08;

/// <summary>
/// <para>no array bounds checking; no STMT opcode.</para>
/// </summary>
constexpr auto AMX_FLAG_NO_CHECKS = 0x10;

/// <summary>
/// <para>All native functions are registered.</para>
/// </summary>
constexpr auto AMX_FLAG_NTV_REG = 0x1000;

/// <summary>
/// <para>Abstract machine is JIT compiled.</para>
/// </summary>
constexpr auto AMX_FLAG_JIT_C = 0x2000;

/// <summary>
/// <para>Busy browsing.</para>
/// </summary>
constexpr auto AMX_FLAG_BROWSE = 0x4000;

/// <summary>
/// <para>Jump/call addresses relocated.</para>
/// </summary>
constexpr auto AMX_FLAG_RELOC = 0x8000;

/// <summary>
/// <para>Start at program entry point.</para>
/// </summary>
constexpr auto AMX_EXEC_MAIN = -1;

/// <summary>
/// <para>Continue from last address.</para>
/// </summary>
constexpr auto AMX_EXEC_CONT = -2;

/// <summary>
/// </summary>
constexpr auto AMX_USER_NUM = 4;

/// <summary>
/// <para>Maximum name length for file version <= 6.</para>
/// </summary>
constexpr auto AMX_EXP_MAX = 19;

/// <summary>
/// <para>Maximum name length of symbol name.</para>
/// </summary>
constexpr auto AMX_NAME_MAX = 63;

/// <summary>
/// Enum AmxError
/// </summary>
enum class AmxError {
	/// <summary>
	/// </summary>
	None = 0,

	//
	// Reserve the first 15 error codes for exit codes of the abstract machine.
	//

	/// <summary>
	/// <para>Forced exit.</para>
	/// </summary>
	Exit,

	/// <summary>
	/// <para>Assertion failed.</para>
	/// </summary>
	Assert,

	/// <summary>
	/// <para>Stack/heap collision.</para>
	/// </summary>
	StackErr,

	/// <summary>
	/// <para>Index out of bounds.</para>
	/// </summary>
	Bounds,

	/// <summary>
	/// <para>Invalid memory access.</para>
	/// </summary>
	MemAccess,

	/// <summary>
	/// <para>Invalid instruction.</para>
	/// </summary>
	InvalidInstr,

	/// <summary>
	/// <para>Stack underflow.</para>
	/// </summary>
	StackLow,

	/// <summary>
	/// <para>Heap underflow.</para>
	/// </summary>
	HeapLow,

	/// <summary>
	/// <para>No callback, or invalid callback.</para>
	/// </summary>
	Callback,

	/// <summary>
	/// <para>Native function failed.</para>
	/// </summary>
	Native,

	/// <summary>
	/// <para>Divide by zero.</para>
	/// </summary>
	Divide,

	/// <summary>
	/// <para>Go into sleep mode - code can be restarted.</para>
	/// </summary>
	Sleep,

	/// <summary>
	/// <para>Invalid state for this access.</para>
	/// </summary>
	InvalidState,

	/// <summary>
	/// <para>Out of memory.</para>
	/// </summary>
	Memory = 16,

	/// <summary>
	/// <para>Invalid file format.</para>
	/// </summary>
	Format,

	/// <summary>
	/// <para>File is for a newer version of the AMX.</para>
	/// </summary>
	Version,

	/// <summary>
	/// <para>Function not found.</para>
	/// </summary>
	NotFound,

	/// <summary>
	/// <para>Invalid index parameter (bad entry point).</para>
	/// </summary>
	Index,

	/// <summary>
	/// <para>Debugger cannot run.</para>
	/// </summary>
	Debug,

	/// <summary>
	/// <para>AMX not initialized (or doubly initialized).</para>
	/// </summary>
	Init,

	/// <summary>
	/// <para>Unable to set user data field (table full).</para>
	/// </summary>
	UserData,

	/// <summary>
	/// <para>Cannot initialize the JIT.</para>
	/// </summary>
	InitJit,

	/// <summary>
	/// <para>Parameter error.</para>
	/// </summary>
	Params,

	/// <summary>
	/// <para>Domain error, expression result does not fit in range.</para>
	/// </summary>
	Domain,

	/// <summary>
	/// <para>General error (unknown or unspecific error).</para>
	/// </summary>
	General
};

struct Amx;
typedef int (AMXAPI *AmxDebug)(struct Amx* amx);
typedef cell (AMX_NATIVE_CALL *AmxNative)(struct Amx* amx, cell* params);
typedef int (AMXAPI *AmxCallback)(struct Amx* amx, cell index, cell* result, cell* params);

/*
 * Some compilers do not support the #pragma align, which should be fine. Some
 * compilers give a warning on unknown #pragmas, which is not so fine...
 */
#if (defined SN_TARGET_PS2 || defined __GNUC__) && !defined AMX_NO_ALIGN
	#define AMX_NO_ALIGN
#endif

#if defined __GNUC__
#define PACKED __attribute__((packed))
#else
#define PACKED
#endif

#if !defined AMX_NO_ALIGN
#if defined LINUX || defined __FreeBSD__ || defined __APPLE__
#pragma pack(1)
#elif defined MACOS && defined __MWERKS__
#pragma options align=mac68k
#else
#pragma pack(push)
#pragma pack(1)
#if defined __TURBOC__
#pragma option -a-
#endif
#endif
#endif

/// <summary>
/// Struct AmxNativeInfo
/// </summary>
struct AmxNativeInfo {
	/// <summary>
	/// </summary>
	const char _FAR* name PACKED;

	/// <summary>
	/// </summary>
	AmxNative func PACKED;
} PACKED;

/// <summary>
/// Struct AmxFuncStub
/// </summary>
struct AmxFuncStub {
	/// <summary>
	/// </summary>
	ucell address PACKED;

	/// <summary>
	/// </summary>
	char name[AMX_EXP_MAX + 1];
} PACKED;

/// <summary>
/// Struct AmxFuncStubNt
/// </summary>
struct AmxFuncStubNt {
	/// <summary>
	/// </summary>
	ucell address PACKED;

	/// <summary>
	/// <para>We need this for amxx to be backwards compatible.</para>
	/// </summary>
	ucell name_offset PACKED;
} PACKED;

/// <summary>
/// <para>The AmxHeader structure is both the memory format as the file format.<br/>
/// The structure is used internaly.</para>
/// </summary>
struct AmxHeader {
	/// <summary>
	/// <para>Size of the "file".</para>
	/// </summary>
	int32_t size PACKED;

	/// <summary>
	/// <para>Signature.</para>
	/// </summary>
	uint16_t magic PACKED;

	/// <summary>
    /// <para>File format version.</para>
    /// </summary>
	char file_version;

	/// <summary>
    /// <para>Required version of the AMX.</para>
    /// </summary>
	char amx_version;

	/// <summary>
    /// <para>.</para>
    /// </summary>
	int16_t flags PACKED;

	/// <summary>
    /// <para>Size of a definition record.</para>
    /// </summary>
	int16_t definition_size PACKED;

	/// <summary>
    /// <para>Initial value of COD - code block.</para>
    /// </summary>
	int32_t cod PACKED;

	/// <summary>
    /// <para>Initial value of DAT - data block.</para>
    /// </summary>
	int32_t dat PACKED;

	/// <summary>
    /// <para>Initial value of HEA - start of the heap.</para>
    /// </summary>
	int32_t hea PACKED;

	/// <summary>
    /// <para>Initial value of STP - stack top.</para>
    /// </summary>
	int32_t stp PACKED;

	/// <summary>
    /// <para>Initial value of CIP - the instruction pointer.</para>
    /// </summary>
	int32_t cip PACKED;

	/// <summary>
    /// <para>Offset to the "public functions" table.</para>
    /// </summary>
	int32_t publics PACKED;

	/// <summary>
    /// <para>Offset to the "native functions" table.</para>
    /// </summary>
	int32_t natives PACKED;

	/// <summary>
    /// <para>Offset to the table of libraries.</para>
    /// </summary>
	int32_t libraries PACKED;

	/// <summary>
    /// <para>The "public variables" table.</para>
    /// </summary>
	int32_t public_vars PACKED;

	/// <summary>
    /// <para>The "public tagnames" table.</para>
    /// </summary>
	int32_t tags PACKED;

	/// <summary>
    /// <para>Name table.</para>
    /// </summary>
	int32_t name_table PACKED;
} PACKED;

/// <summary>
/// <para>The AMX structure is the internal structure for many functions.<br/>
/// Not all fields are valid at all times; many fields are cached in local variables.</para>
/// </summary>
struct Amx {
	/// <summary>
	/// <para>Points to the AMX header plus the code, optionally also the data.</para>
	/// </summary>
	unsigned char _FAR* base PACKED;

	/// <summary>
	/// <para>Points to separate data+stack+heap, may be NULL.</para>
	/// </summary>
	unsigned char _FAR* data PACKED;

	/// <summary>
	/// </summary>
	AmxCallback callback PACKED;

	/// <summary>
	/// <para>Debug callback.</para>
	/// </summary>
	AmxDebug debug PACKED;

	//
	// For external functions a few registers must be accessible from the outside.
	//

	/// <summary>
	/// <para>Instruction pointer: relative to base + AmxHeader->cod.</para>
	/// </summary>
	cell cip PACKED;

	/// <summary>
	/// <para>Stack frame base: relative to base + AmxHeader->dat.</para>
	/// </summary>
	cell frm PACKED;

	/// <summary>
	/// <para>Top of the heap: relative to base + AmxHeader->dat.</para>
	/// </summary>
	cell hea PACKED;

	/// <summary>
	/// <para>Bottom of the heap: relative to base + AmxHeader->dat.</para>
	/// </summary>
	cell hlw PACKED;

	/// <summary>
	/// <para>Stack pointer: relative to base + AmxHeader->dat.</para>
	/// </summary>
	cell stk PACKED;

	/// <summary>
	/// <para>Top of the stack: relative to base + AmxHeader->dat.</para>
	/// </summary>
	cell stp PACKED;

	/// <summary>
	/// <para>Current status.</para>
	/// </summary>
	int flags PACKED;

	//
	// User data.
	//

	/// <summary>
	/// </summary>
	long user_tags[AMX_USER_NUM] PACKED;

	/// <summary>
	/// </summary>
	void _FAR* user_data[AMX_USER_NUM] PACKED;

	//
	// Native functions can raise an error.
	//

	/// <summary>
	/// </summary>
	int error PACKED;

	//
	// Passing parameters requires a "count" field.
	//

	/// <summary>
	/// </summary>
	int param_count;

	//
	// The sleep opcode needs to store the full AMX status.
	//

	/// <summary>
	/// </summary>
	cell pri PACKED;

	/// <summary>
	/// </summary>
	cell alt PACKED;

	/// <summary>
	/// </summary>
	cell reset_stk PACKED;

	/// <summary>
	/// </summary>
	cell reset_hea PACKED;

	/// <summary>
	/// <para>Relocated address/value for the SYSREQ.D opcode.</para>
	/// </summary>
	cell sysreq_d PACKED;

	//
	// Support variables for the JIT.
	//

	/// <summary>
	/// <para>Required temporary buffer for relocations.</para>
	/// </summary>
	int reloc_size PACKED;

	/// <summary>
	/// <para>Estimated memory footprint of the native code.</para>
	/// </summary>
	long code_size PACKED;
} PACKED;

#if !defined AMX_NO_ALIGN
#if defined __LINUX__ || defined __FreeBSD__ || defined __APPLE__
#pragma pack()
#elif defined MACOS && defined __MWERKS__
#pragma options align=reset
#else
#pragma pack(pop)
#endif
#endif

/// <summary>
/// <para>Real to cell.</para>
/// </summary>
inline cell amx_ftoc(const real& value)
{
	return *reinterpret_cast<const cell*>(&value);
}

/// <summary>
/// <para>Cell to real.</para>
/// </summary>
inline real amx_ctof(const cell& value)
{
	return *reinterpret_cast<const real*>(&value);
}

/// <summary>
/// </summary>
inline cell* amx_address(const Amx* amx, const ucell address)
{
	return reinterpret_cast<cell*>(amx->base + reinterpret_cast<const AmxHeader*>(amx->base)->dat + address);
}
