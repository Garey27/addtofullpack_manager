// ***********************************************************************
// Author           : the_hunter
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************

#include <amxx/string.h>
#include <cstring>

namespace amx
{
	/// <summary>
	/// </summary>
	static char* init(const cell* const address, const ucell max_length)
	{
		const auto string = new char[max_length + 1];
		ucell i;

		for (i = 0; i < max_length && address[i]; ++i)
			string[i] = static_cast<char>(address[i]);

		string[i] = '\0';

		return string;
	}

	/// <summary>
	/// </summary>
	static int check_valid_char(const char* c) // Stolen from AMXX Mod X
	{
		int count;
		int byte_count;

		for (count = 1; (*c & 0xC0) == 0x80; count++)
			c--;

		switch (*c & 0xF0) {
		case 0xC0:
		case 0xD0:
			byte_count = 2;
			break;
		case 0xE0:
			byte_count = 3;
			break;
		case 0xF0:
			byte_count = 4;
			break;
		default: byte_count = 1;
		}

		if (byte_count != count)
			return count;

		return 0;
	}

	/// <summary>
	/// </summary>
	String::String(cell* address, const ucell max_length)
		: address_(address), max_length_(max_length), c_str_(nullptr)
	{
		c_str_ = init(address_, max_length_);
	}

	/// <summary>
	/// </summary>
	String::String(const Amx* amx, const ucell address, const ucell max_length)
		: address_(amx_address(amx, address)), max_length_(max_length), c_str_(nullptr)
	{
		c_str_ = init(address_, max_length_);
	}

	/// <summary>
	/// </summary>
	String::String(String&& rhs) noexcept
		: address_(rhs.address_), max_length_(rhs.max_length_), c_str_(rhs.c_str_)
	{
		rhs.max_length_ = 0;
		rhs.address_ = nullptr;
		rhs.c_str_ = nullptr;
	}

	/// <summary>
	/// </summary>
	String::String(const String& rhs)
		: address_(rhs.address_), max_length_(rhs.max_length_), c_str_(nullptr)
	{
		c_str_ = new char[max_length_ + 1];
		std::memcpy(static_cast<void*>(c_str_), rhs.c_str_, (max_length_ + 1) * sizeof(char));
	}

#ifdef __INTEL_COMPILER
	#pragma warning(push)
	#pragma warning(disable: 2017)
#endif

	/// <summary>
	/// </summary>
	String::~String()
	{
		delete[] c_str_;
	}

#ifdef __INTEL_COMPILER
	#pragma warning(pop)
#endif

	/// <summary>
	/// </summary>
	ucell String::length() const
	{
		return c_str_ ? std::strlen(c_str_) : 0;
	}

	/// <summary>
	/// </summary>
	char String::operator[](const ucell index) const
	{
		return c_str_ ? c_str_[index] : '\0';
	}

	/// <summary>
	/// </summary>
	String& String::operator=(String&& rhs) noexcept
	{
		if (&rhs != this) {
			delete[] c_str_;

			max_length_ = rhs.max_length_;
			address_ = rhs.address_;
			c_str_ = rhs.c_str_;

			rhs.max_length_ = 0;
			rhs.address_ = nullptr;
			rhs.c_str_ = nullptr;
		}

		return *this;
	}

	/// <summary>
	/// </summary>
	String& String::operator=(const String& rhs)
	{
		if (&rhs != this) {
			delete[] c_str_;

			max_length_ = rhs.max_length_;
			address_ = rhs.address_;

			c_str_ = new char[max_length_ + 1];
			std::memcpy(static_cast<void*>(c_str_), rhs.c_str_, (max_length_ + 1) * sizeof(char));
		}

		return *this;
	}

	/// <summary>
	/// </summary>
	String& String::operator=(const char* rhs)
	{
		if (c_str_ && rhs) {
			ucell i = 0;
			auto c = *rhs;

			while (i < max_length_ && c) {
				address_[i] = static_cast<unsigned char>(c_str_[i] = c);
				c = rhs[++i];
			}

			i -= check_valid_char(&c_str_[i - 1]);
			address_[i] = c_str_[i] = '\0';
		}

		return *this;
	}

	/// <summary>
	/// </summary>
	bool String::operator==(const char* rhs) const
	{
		return c_str_ ? std::strcmp(c_str_, rhs) == 0 : false;
	}

	/// <summary>
	/// </summary>
	bool String::operator==(const String& rhs) const
	{
		return c_str_ ? std::strcmp(c_str_, rhs.c_str_) == 0 : false;
	}

	/// <summary>
	/// </summary>
	bool String::operator!=(const char* rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	bool String::operator!=(const String& rhs) const
	{
		return !(*this == rhs);
	}
}
