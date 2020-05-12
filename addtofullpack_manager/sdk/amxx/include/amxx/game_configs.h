/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#pragma once

#include <cstddef>

/// <summary>
/// </summary>
class TextListener;

/// <summary>
/// Enum ConfigFieldType
/// </summary>
enum class ConfigFieldType {
	/// <summary>
	/// </summary>
	None,

	/// <summary>
	/// <para>Floating point value.</para>
	/// </summary>
	Float,

	/// <summary>
	/// <para>String ID (return from ALLOC_STRING).</para>
	/// </summary>
	StringInt,

	/// <summary>
	/// <para>String, pointer-to-char.</para>
	/// </summary>
	StringPtr,

	/// <summary>
	/// <para>String, fixed size.</para>
	/// </summary>
	String,

	/// <summary>
	/// <para>Classes pointer derived of <c>EntityBase</c>.</para>
	/// </summary>
	ClassPtr,

	/// <summary>
	/// <para>Arbitrary classes, direct.</para>
	/// </summary>
	Class,

	/// <summary>
	/// <para>Arbitrary structures, direct.</para>
	/// </summary>
	Structure,

	/// <summary>
	/// <para>Entity handle.</para>
	/// </summary>
	EntHandle,

	/// <summary>
	/// <para><c>EntityVars*</c></para>
	/// </summary>
	EntVars,

	/// <summary>
	/// <para><c>Edict*</c></para>
	/// </summary>
	Edict,

	/// <summary>
	/// <para><c>Vector</c></para>
	/// </summary>
	Vector,

	/// <summary>
	/// <para>Arbitrary data pointer.</para>
	/// </summary>
	Pointer,

	/// <summary>
	/// <para>Integer or enum.</para>
	/// </summary>
	Integer,

	/// <summary>
	/// <para>Class function pointer (think, use, etc).</para>
	/// </summary>
	Function,

	/// <summary>
	/// <para>Boolean.</para>
	/// </summary>
	Boolean,

	/// <summary>
	/// <para>2 bytes integer.</para>
	/// </summary>
	Short,

	/// <summary>
	/// <para>1 byte.</para>
	/// </summary>
	Character
};

/// <summary>
/// Struct ConfigTypeDescription
/// </summary>
struct ConfigTypeDescription {
	/// <summary>
	/// </summary>
	ConfigTypeDescription()
	{
		reset();
	}

	/// <summary>
	/// </summary>
	void reset()
	{
		field_type = ConfigFieldType::None;
		field_offset = 0;
		field_size = 0;
		field_unsigned = false;
	}

	/// <summary>
	/// </summary>
	ConfigFieldType field_type{};

	/// <summary>
	/// </summary>
	int field_offset{};

	/// <summary>
	/// </summary>
	int field_size{};

	/// <summary>
	/// </summary>
	bool field_unsigned{};
};

/// <summary>
/// Class GameConfig.
/// </summary>
class GameConfig {
public:
	/// <summary>
	/// <para>Returns an offset value.<br/></para>
	/// </summary>
	/// 
	/// <param name="key">Key to retrieve from the offset section.</param>
	/// <param name="value">Pointer to store the ConfigTypeDescription reference in.<br/></param>
	/// 
	/// <returns>True if found, false otherwise.</returns>
	virtual bool get_offset(const char* key, ConfigTypeDescription* value) = 0;

	/// <summary>
	/// <para>Returns an offset value from given class.<br/></para>
	/// </summary>
	/// 
	/// <param name="classname">Class name to match from the offset section.</param>
	/// <param name="key">Key to retrieve from the offset section.</param>
	/// <param name="value">Pointer to store the ConfigTypeDescription reference in.<br/></param>
	/// 
	/// <returns>True if found, false otherwise.</returns>
	virtual bool get_offset_by_class(const char* classname, const char* key, ConfigTypeDescription* value) = 0;

	/// <summary>
	/// <para>Returns the value of a key from the "Keys" section.<br/></para>
	/// </summary>
	/// 
	/// <param name="key">Key to retrieve from the Keys section.<br/></param>
	/// 
	/// <returns>String containing the value, or NULL if not found.</returns>
	virtual const char* get_key_value(const char* key) = 0;

	/// <summary>
	/// <para>Retrieves a cached memory signature.<br/></para>
	/// </summary>
	/// 
	/// <param name="key">Name of the signature.</param>
	/// <param name="address">Pointer to store the memory address in (NULL is copied if signature is not found in binary).<br/></param>
	/// 
	/// <returns>True if the section exists and key for current platform was found, false otherwise.</returns>
	virtual bool get_mem_sig(const char* key, void** address) = 0;

	/// <summary>
	/// <para>Retrieves the value of an address from the "Address" section.<br/></para>
	/// </summary>
	/// 
	/// <param name="key">Key to retrieve from the Address section.</param>
	/// <param name="address">Pointer to store the memory address.<br/></param>
	/// 
	/// <returns>True on success, false on failure.</returns>
	virtual bool get_address(const char* key, void** address) = 0;
};

/// <summary>
/// Class GameConfigManager.
/// </summary>
class GameConfigManager {
public:
	/// <summary>
	/// <para>Loads or finds an already loaded game config file.<br/></para>
	/// </summary>
	/// 
	/// <param name="file">File to load. The path must be relative to the 'gamedata' folder and the extension should be omitted.</param>
	/// <param name="config">Pointer to store the game config pointer. Pointer will be valid even on failure.</param>
	/// <param name="error">Optional error message buffer.</param>
	/// <param name="maxlength">Maximum length of the error buffer.<br/></param>
	/// 
	/// <returns>True on success, false if the file failed.</returns>
	virtual bool load_game_config_file(const char* file, GameConfig** config, char* error, std::size_t maxlength) = 0;

	/// <summary>
	/// <para>Closes an <c>GameConfig</c> pointer.
	/// Since a file can be loaded more than once, the file will not actually be removed from memory
	/// until it is closed once for each call to <c>load_game_config_file</c>.<br/></para>
	/// </summary>
	/// 
	/// <param name="config">Pointer to the <c>GameConfig</c> to close.</param>
	virtual void close_game_config_file(GameConfig* config) = 0;

	/// <summary>
	/// <para>Adds a custom gamedata section hook.<br/></para>
	/// </summary>
	/// 
	/// <param name="section_name">Section name to hook.</param>
	/// <param name="listener">Listener callback.</param>
	virtual void add_user_config_hook(const char* section_name, TextListener* listener) = 0;

	/// <summary>
	/// <para>Removes a custom gamedata section hook.<br/></para>
	/// </summary>
	/// 
	/// <param name="section_name">Section name to unhook.</param>
	/// <param name="listener">Listener callback.</param>
	virtual void remove_user_config_hook(const char* section_name, TextListener* listener) = 0;
};
