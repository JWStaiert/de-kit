#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#define DE__MATH__OP_OSTREAM__DEFINE_EXTERN_TEMPLATES
#include "de.math.op-ostream.hpp"

#include <de.math.vec2.hpp>
#include <de.math.vec3.hpp>

#include <ostream>

#include <cstdint>

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::int8_t>& p_value )
{
	// TODO: Fix this so it outputs numerals and not characters.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::int16_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::int32_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::int64_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::uint8_t>& p_value )
{
	// TODO: Fix this so it outputs numerals and not characters.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::uint16_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::uint32_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<std::uint64_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<de::float32>& p_value )
{
	// TODO: Fix this so it is bit-wise accurate.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec2<de::float64>& p_value )
{
	// TODO: Fix this so it is bit-wise accurate.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::int8_t>& p_value )
{
	// TODO: Fix this so it outputs numerals and not characters.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::int16_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::int32_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::int64_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::uint8_t>& p_value )
{
	// TODO: Fix this so it outputs numerals and not characters.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::uint16_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::uint32_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<std::uint64_t>& p_value )
{
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<de::float32>& p_value )
{
	// TODO: Fix this so it is bit-wise accurate.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

std::ostream& operator<<( std::ostream& p_stream, const de::math::vec3<de::float64>& p_value )
{
	// TODO: Fix this so it is bit-wise accurate.
	p_stream << "{ x = " << p_value.x << " , y = " << p_value.y << " , z = " << p_value.z << " }";
	return p_stream;
}

/* END */
