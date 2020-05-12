// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#ifdef __x86_64__
#define X64_BITS
#endif

#if defined(_WIN32) && (!defined(__MINGW32__))
/// <summary>
/// </summary>
using int8 = __int8;

/// <summary>
/// </summary>
using uint8 = unsigned __int8;

/// <summary>
/// </summary>
using int16 = __int16;

/// <summary>
/// </summary>
using uint16 = unsigned __int16;

/// <summary>
/// </summary>
using int32 = __int32;

/// <summary>
/// </summary>
using uint32 = unsigned __int32;

/// <summary>
/// </summary>
using int64 = __int64;

/// <summary>
/// </summary>
using uint64 = unsigned __int64;

/// <summary>
/// <para>Integer that can accomodate a pointer.</para>
/// </summary>
using intp = __int32;

/// <summary>
/// <para>ie, sizeof(intp) >= sizeof(int) && sizeof(intp) >= sizeof(void*)</para>
/// </summary>
using uintp = unsigned __int32;
#else
/// <summary>
/// </summary>
using int8 = char;

/// <summary>
/// </summary>
using uint8 = unsigned char;

/// <summary>
/// </summary>
using int16 = short;

/// <summary>
/// </summary>
using uint16 = unsigned short;

/// <summary>
/// </summary>
using int32 = int;

/// <summary>
/// </summary>
using uint32 = unsigned int;

/// <summary>
/// </summary>
using int64 = long long;

/// <summary>
/// </summary>
using uint64 = unsigned long long;

#ifdef X64_BITS
/// <summary>
/// <para>Integer that can accomodate a pointer.</para>
/// </summary>
using intp = long long;

/// <summary>
/// </summary>
using uintp = unsigned long long;
#else
/// <summary>
/// <para>ie, sizeof(intp) >= sizeof(int) && sizeof(intp) >= sizeof(void*)</para>
/// </summary>
using intp = int;

/// <summary>
/// </summary>
using uintp = unsigned int;
#endif
#endif
