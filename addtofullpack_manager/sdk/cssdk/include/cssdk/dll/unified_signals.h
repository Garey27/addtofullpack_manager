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
/// </summary>
constexpr auto SIGNAL_BUY = 1 << 0;

/// <summary>
/// </summary>
constexpr auto SIGNAL_BOMB = 1 << 1;

/// <summary>
/// </summary>
constexpr auto SIGNAL_RESCUE = 1 << 2;

/// <summary>
/// </summary>
constexpr auto SIGNAL_ESCAPE = 1 << 3;

/// <summary>
/// </summary>
constexpr auto SIGNAL_VIP_SAFETY = 1 << 4;

/// <summary>
/// Class UnifiedSignals.
/// </summary>
class UnifiedSignals {
public:
	/// <summary>
	/// </summary>
	void update()
	{
		state_ = signal_;
		signal_ = 0;
	}

	/// <summary>
	/// </summary>
	void signal(const int flags)
	{
		signal_ |= flags;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] int get_signal() const
	{
		return signal_;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] int get_state() const
	{
		return state_;
	}

private:
	/// <summary>
	/// </summary>
	int signal_{};

	/// <summary>
	/// </summary>
	int state_{};
};
