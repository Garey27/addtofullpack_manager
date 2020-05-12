// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/dll/api/cs_entity.h>
#include <cssdk/dll/weapons.h>

/// <summary>
/// Class CsPlayerItem.
/// </summary>
class CsPlayerItem : public CsAnimating {
public:
	/// <summary>
	/// </summary>
	virtual void set_item_info(ItemInfo* info) = 0;

	/// <summary>
	/// </summary>
	virtual int get_item_info(ItemInfo* info) = 0;

	/// <summary>
	/// </summary>
	ItemInfo item_info;

	/// <summary>
	/// </summary>
	[[nodiscard]] PlayerItemBase* player_item_base() const
	{
		return reinterpret_cast<PlayerItemBase*>(this->containing_entity);
	}
};
