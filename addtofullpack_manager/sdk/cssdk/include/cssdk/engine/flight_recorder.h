// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/arch_types.h>

/// <summary>
/// Class RehldsFlightRecorder.
/// </summary>
class RehldsFlightRecorder {
public:
	/// <summary>
	/// </summary>
	virtual ~RehldsFlightRecorder() = default;

	/// <summary>
	/// </summary>
	virtual uint16 register_message(const char* module, const char* message, unsigned int version, bool in_out) = 0;

	/// <summary>
	/// </summary>
	virtual void start_message(uint16 msg, bool entrance) = 0;

	/// <summary>
	/// </summary>
	virtual void end_message(uint16 msg, bool entrance) = 0;

	/// <summary>
	/// </summary>
	virtual void write_int8(int8 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_uint8(uint8 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_int16(int16 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_uint16(uint16 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_int32(int32 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_uint32(uint32 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_int64(int64 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_uint64(uint64 v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_float(float v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_double(double v) = 0;

	/// <summary>
	/// </summary>
	virtual void write_string(const char* s) = 0;

	/// <summary>
	/// </summary>
	virtual void write_buffer(const void* data, unsigned int len) = 0;
};
