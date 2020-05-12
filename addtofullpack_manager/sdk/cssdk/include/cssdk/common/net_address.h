// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

/// <summary>
/// Enum NetAddressType
/// </summary>
enum class NetAddressType {
	/// <summary>
	/// </summary>
	Unused = 0,

	/// <summary>
	/// </summary>
	Loopback,

	/// <summary>
	/// </summary>
	Broadcast,

	/// <summary>
	/// </summary>
	Ip,

	/// <summary>
	/// </summary>
	Ipx,

	/// <summary>
	/// </summary>
	BroadcastIpx
};

/// <summary>
/// Struct NetAddress
/// </summary>
struct NetAddress {
	/// <summary>
	/// </summary>
	NetAddressType type{};

	/// <summary>
	/// </summary>
	unsigned char ip[4]{};

	/// <summary>
	/// </summary>
	unsigned char ipx[10]{};

	/// <summary>
	/// </summary>
	unsigned short port{};
};
