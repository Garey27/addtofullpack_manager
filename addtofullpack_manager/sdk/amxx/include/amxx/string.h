// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#pragma once

#include <amxx/amx.h>

namespace amx
{
	/// <summary>
	/// Class String.
	/// </summary>
	class String final {
	public:
		/// <summary>
		/// </summary>
		String() = default;

		/// <summary>
		/// </summary>
		String(cell* address, ucell max_length);

		/// <summary>
		/// </summary>
		String(const Amx* amx, ucell address, ucell max_length);

		/// <summary>
		/// </summary>
		String(String&& rhs) noexcept;

		/// <summary>
		/// </summary>
		String(const String& rhs);

		/// <summary>
		/// </summary>
		~String();

		/// <summary>
		/// </summary>
		[[nodiscard]] bool empty() const;

		/// <summary>
		/// </summary>
		[[nodiscard]] ucell length() const;

		/// <summary>
		/// </summary>
		[[nodiscard]] ucell max_length() const;

		/// <summary>
		/// </summary>
		[[nodiscard]] const char* c_str() const;

		/// <summary>
		/// </summary>
		char operator[](ucell index) const;

		/// <summary>
		/// </summary>
		String& operator=(String&& rhs) noexcept;

		/// <summary>
		/// </summary>
		String& operator=(const String& rhs);

		/// <summary>
		/// </summary>
		String& operator=(const char* rhs);

		/// <summary>
		/// </summary>
		bool operator==(const char* rhs) const;

		/// <summary>
		/// </summary>
		bool operator==(const String& rhs) const;

		/// <summary>
		/// </summary>
		bool operator!=(const char* rhs) const;

		/// <summary>
		/// </summary>
		bool operator!=(const String& rhs) const;

	private:
		/// <summary>
		/// </summary>
		cell* address_;

		/// <summary>
		/// </summary>
		ucell max_length_;

		/// <summary>
		/// </summary>
		char* c_str_;
	};

	/// <summary>
	/// </summary>
	inline bool String::empty() const
	{
		return !c_str_ || c_str_[0] == '\0';
	}

	/// <summary>
	/// </summary>
	inline ucell String::max_length() const
	{
		return max_length_;
	}

	/// <summary>
	/// </summary>
	inline const char* String::c_str() const
	{
		return c_str_;
	}

	/// <summary>
	/// </summary>
	using string = String;
}
