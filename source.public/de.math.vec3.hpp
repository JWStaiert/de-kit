#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

namespace de
{
	namespace math
	{
		template<typename T>
		struct vec3
		{
			T x;
			T y;
			T z;

			constexpr vec3( ) noexcept = default;

			constexpr vec3( const vec3<T>& ) noexcept = default;

			constexpr vec3( vec3<T>&& ) = delete;

			~vec3( ) = default;

			constexpr vec3<T>& operator=( const vec3<T>& ) noexcept = default;

			constexpr vec3<T>& operator=( vec3<T>&& ) = delete;

			constexpr vec3( const T p_x, const T p_y = 0 , const T p_z = 0 ) noexcept
				: x{ p_x }
				, y{ p_y }
				, z{ p_z }
			{
			}

			inline vec3<T>& operator+=( const vec3<T> p_other ) noexcept
			{
				x += p_other.x;
				y += p_other.y;
				z += p_other.z;
				return *this;
			}

			inline vec3<T>& operator-=( const vec3<T> p_other ) noexcept
			{
				x -= p_other.x;
				y -= p_other.y;
				z -= p_other.z;
				return *this;
			}

			inline vec3<T>& operator*=( const vec3<T> p_other ) noexcept
			{
				x *= p_other.x;
				y *= p_other.y;
				z *= p_other.z;
				return *this;
			}

			inline vec3<T>& operator*=( const T p_multiplier ) noexcept
			{
				x *= p_multiplier;
				y *= p_multiplier;
				z *= p_multiplier;
				return *this;
			}

			inline vec3<T>& operator/=( const vec3<T> p_other ) noexcept
			{
				x /= p_other.x;
				y /= p_other.y;
				z /= p_other.z;
				return *this;
			}

			inline vec3<T>& operator/=( const T p_divisor ) noexcept
			{
				x /= p_divisor;
				y /= p_divisor;
				z /= p_divisor;
				return *this;
			}
		};
	}
}

template<typename T>
constexpr bool operator==( const de::math::vec3<T> p_a, const de::math::vec3<T> p_b ) noexcept
{
	return ( ( p_a.x == p_b.x ) && ( p_a.y == p_b.y ) && ( p_a.z == p_b.z ) );
}

template<typename T>
constexpr bool operator!=( const de::math::vec3<T> p_a, const de::math::vec3<T> p_b ) noexcept
{
	return ( ( p_a.x != p_b.x ) || ( p_a.y != p_b.y ) || ( p_a.z != p_b.z ) );
}

template<typename T>
constexpr bool operator<( const de::math::vec3<T> p_a, const de::math::vec3<T> p_b ) noexcept
{
	return ( ( p_a.x < p_b.x ) && ( p_a.y < p_b.y ) && ( p_a.z < p_b.z ) );
}

template<typename T>
constexpr bool operator<=( const de::math::vec3<T> p_a, const de::math::vec3<T> p_b ) noexcept
{
	return ( ( p_a.x <= p_b.x ) && ( p_a.y <= p_b.y ) && ( p_a.z <= p_b.z ) );
}

template<typename T>
constexpr bool operator>( const de::math::vec3<T> p_a, const de::math::vec3<T> p_b ) noexcept
{
	return ( ( p_a.x > p_b.x ) && ( p_a.y > p_b.y ) && ( p_a.z > p_b.z ) );
}

template<typename T>
constexpr bool operator>=( const de::math::vec3<T> p_a, const de::math::vec3<T> p_b ) noexcept
{
	return ( ( p_a.x >= p_b.x ) && ( p_a.y >= p_b.y ) && ( p_a.z >= p_b.z ) );
}

/* END */
