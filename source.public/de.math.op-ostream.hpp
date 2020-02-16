#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <de.native-types.hpp>

#include <ostream>

#include <cstdint>

namespace de
{
	namespace math
	{
		template<typename T>
		struct vec2;

		template<typename T>
		struct vec3;
	}
}

#ifndef DE__MATH__OP_OSTREAM__DEFINE_EXTERN_TEMPLATES

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::int8_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::int16_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::int32_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::int64_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::uint8_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::uint16_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::uint32_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<std::uint64_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<de::float32>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec2<de::float64>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::int8_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::int16_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::int32_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::int64_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::uint8_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::uint16_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::uint32_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<std::uint64_t>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<de::float32>& );

extern std::ostream& operator<<( std::ostream&, const de::math::vec3<de::float64>& );

#endif

/* END */
