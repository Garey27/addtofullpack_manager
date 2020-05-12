// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/public/base_types.h>
#include <cmath>

/// <summary>
/// <para>Used for many path finding and many other operations that are treated as planar rather than 3D.</para>
/// </summary>
class Vector2D {
public:
	/// <summary>
	/// </summary>
	Vector2D() : x(0.0f), y(0.0f)
	{
	}

	/// <summary>
	/// </summary>
	Vector2D(const vec_t x_axis, const vec_t y_axis) : x(x_axis), y(y_axis)
	{
	}

	/// <summary>
	/// </summary>
	explicit Vector2D(const vec_t scalar) : x(scalar), y(scalar)
	{
	}

	/// <summary>
	/// </summary>
	explicit Vector2D(const vec_t vec_2d[2]) : x(vec_2d[0]), y(vec_2d[1])
	{
	}

	/// <summary>
	/// </summary>
	Vector2D& operator=(const vec_t rhs)
	{
		x = y = rhs;
		return *this;
	}

	/// <summary>
	/// </summary>
	bool operator==(const vec_t rhs) const
	{
		return x == rhs && y == rhs;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const vec_t rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	bool operator==(const Vector2D& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const Vector2D& rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator+(const vec_t rhs) const
	{
		return Vector2D(x + rhs, y + rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator-(const vec_t rhs) const
	{
		return Vector2D(x - rhs, y - rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator*(const vec_t rhs) const
	{
		return Vector2D(x * rhs, y * rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator/(const vec_t rhs) const
	{
		return Vector2D(x / rhs, y / rhs);
	}

	/// <summary>
	/// </summary>
	Vector2D operator+(const Vector2D& rhs) const
	{
		return Vector2D(x + rhs.x, y + rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D operator-(const Vector2D& rhs) const
	{
		return Vector2D(x - rhs.x, y - rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D operator*(const Vector2D& rhs) const
	{
		return Vector2D(x * rhs.x, y * rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D operator/(const Vector2D& rhs) const
	{
		return Vector2D(x / rhs.x, y / rhs.y);
	}

	/// <summary>
	/// </summary>
	Vector2D& operator+=(const vec_t rhs)
	{
		x += rhs;
		y += rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator-=(const vec_t rhs)
	{
		x -= rhs;
		y -= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator*=(const vec_t rhs)
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator/=(const vec_t rhs)
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator+=(const Vector2D& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator-=(const Vector2D& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator*=(const Vector2D& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector2D& operator/=(const Vector2D& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;

		return *this;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] vec_t length() const
	{
		return std::sqrt(x * x + y * y);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector2D normalize() const
	{
		auto len = length();

		if (!len)
			return Vector2D(0.0f, 0.0f);

		len = 1.0f / len;

		return Vector2D(x * len, y * len);
	}

	/// <summary>
	/// </summary>
	void copy_to_array(vec_t vec_2d[2]) const
	{
		vec_2d[0] = x;
		vec_2d[1] = y;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_zero(const vec_t tolerance = 0.01f) const
	{
		return x > -tolerance && x < tolerance && y > -tolerance && y < tolerance;
	}

	/// <summary>
	/// </summary>
	void clear()
	{
		x = y = 0.0f;
	}

	/// <summary>
	/// </summary>
	vec_t x;

	/// <summary>
	/// </summary>
	vec_t y;
};

/// <summary>
/// Class Vector
/// </summary>
class Vector {
public:
	/// <summary>
	/// </summary>
	Vector() : x(0.0f), y(0.0f), z(0.0f)
	{
	}

	/// <summary>
	/// </summary>
	Vector(const vec_t x_axis, const vec_t y_axis, const vec_t z_axis) : x(x_axis), y(y_axis), z(z_axis)
	{
	}

	/// <summary>
	/// </summary>
	explicit Vector(const vec_t scalar) : x(scalar), y(scalar), z(scalar)
	{
	}

	/// <summary>
	/// </summary>
	explicit Vector(const vec_t vec_3d[3]) : x(vec_3d[0]), y(vec_3d[1]), z(vec_3d[2])
	{
	}

	/// <summary>
	/// </summary>
	Vector& operator=(const vec_t rhs)
	{
		x = y = z = rhs;
		return *this;
	}

	/// <summary>
	/// </summary>
	bool operator==(const vec_t rhs) const
	{
		return x == rhs && y == rhs && z == rhs;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const vec_t rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	bool operator==(const Vector& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	/// <summary>
	/// </summary>
	bool operator!=(const Vector& rhs) const
	{
		return !(*this == rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator+(const vec_t rhs) const
	{
		return Vector(x + rhs, y + rhs, z + rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator-(const vec_t rhs) const
	{
		return Vector(x - rhs, y - rhs, z - rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator*(const vec_t rhs) const
	{
		return Vector(x * rhs, y * rhs, z * rhs);
	}

	/// <summary>
	/// </summary>
	Vector operator/(const vec_t rhs) const
	{
		return Vector(x / rhs, y / rhs, z / rhs);
	}

	/// <summary>
	/// </summary>
	Vector& operator+=(const Vector& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator-=(const Vector& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator*=(const Vector& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;

		return *this;
	}

	/// <summary>
	/// </summary>
	Vector& operator/=(const Vector& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;

		return *this;
	}

	/// <summary>
	/// <para>Vectors will now automatically convert to vec_t* when needed.</para>
	/// </summary>
	explicit operator vec_t*()
	{
		return &x;
	}

	/// <summary>
	/// <para>Vectors will now automatically convert to vec_t* when needed.</para>
	/// </summary>
	explicit operator const vec_t*() const
	{
		return &x;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector2D make_2d() const
	{
		Vector2D vec;
		vec.x = x;
		vec.y = y;

		return vec;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] vec_t length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] vec_t length_2d() const
	{
		return std::sqrt(x * x + y * y);
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] Vector normalize() const
	{
		auto len = length();

		if (!len)
			return Vector(0.0f, 0.0f, 1.0f);

		len = 1.0f / len;

		return Vector(x * len, y * len, z * len);
	}

	/// <summary>
	/// <para>Normalizes the vector's components.<br/></para>
	/// </summary>
	/// <returns>Old length.<br/></returns>
	vec_t normalize_in_place()
	{
		const auto len = length();

		if (!len) {
			x = y = 0.0f;
			z = 1.0f;
		}
		else {
			x = 1.0f / len * x;
			y = 1.0f / len * y;
			z = 1.0f / len * z;
		}

		return len;
	}

	/// <summary>
	/// </summary>
	void copy_to_array(vec_t vec_3d[3]) const
	{
		vec_3d[0] = x;
		vec_3d[1] = y;
		vec_3d[2] = z;
	}

	/// <summary>
	/// </summary>
	[[nodiscard]] bool is_zero(const vec_t tolerance = 0.01f) const
	{
		return x > -tolerance && x < tolerance && y > -tolerance && y < tolerance && z > -tolerance && z < tolerance;
	}

	/// <summary>
	/// </summary>
	void clear()
	{
		x = y = z = 0.0f;
	}

	/// <summary>
	/// </summary>
	vec_t x;

	/// <summary>
	/// </summary>
	vec_t y;

	/// <summary>
	/// </summary>
	vec_t z;
};
