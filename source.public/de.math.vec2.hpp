#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

namespace de
{
	namespace math
	{
		template<typename T>
		struct vec2
		{
			T x;
			T y;

			constexpr vec2( ) noexcept = default;

			constexpr vec2( const vec2<T>& ) noexcept = default;

			~vec2( ) noexcept = default;

			constexpr vec2<T>& operator=( const vec2<T>& ) noexcept = default;

			constexpr vec2( const T p_x, const T p_y = 0 ) noexcept
				: x{ p_x }
				, y{ p_y }
			{
			}

			inline vec2<T>& operator+=( const vec2<T> p_other ) noexcept
			{
				x += p_other.x;
				y += p_other.y;
				return *this;
			}

			inline vec2<T>& operator-=( const vec2<T> p_other ) noexcept
			{
				x -= p_other.x;
				y -= p_other.y;
				return *this;
			}

			inline vec2<T>& operator*=( const vec2<T> p_other ) noexcept
			{
				x *= p_other.x;
				y *= p_other.y;
				return *this;
			}

			inline vec2<T>& operator*=( const T p_multiplier ) noexcept
			{
				x *= p_multiplier;
				y *= p_multiplier;
				return *this;
			}

			inline vec2<T>& operator/=( const vec2<T> p_other ) noexcept
			{
				x /= p_other.x;
				y /= p_other.y;
				return *this;
			}

			inline vec2<T>& operator/=( const T p_divisor ) noexcept
			{
				x /= p_divisor;
				y /= p_divisor;
				return *this;
			}
		};
	}
}

template<typename T>
constexpr bool operator==( const de::math::vec2<T> p_a, const de::math::vec2<T> p_b ) noexcept
{
	return ( ( p_a.x == p_b.x ) && ( p_a.y == p_b.y ) );
}

template<typename T>
constexpr bool operator!=( const de::math::vec2<T> p_a, const de::math::vec2<T> p_b ) noexcept
{
	return ( ( p_a.x != p_b.x ) || ( p_a.y != p_b.y ) );
}

template<typename T>
constexpr bool operator<( const de::math::vec2<T> p_a, const de::math::vec2<T> p_b ) noexcept
{
	return ( ( p_a.x < p_b.x ) && ( p_a.y < p_b.y ) );
}

template<typename T>
constexpr bool operator<=( const de::math::vec2<T> p_a, const de::math::vec2<T> p_b ) noexcept
{
	return ( ( p_a.x <= p_b.x ) && ( p_a.y <= p_b.y ) );
}

template<typename T>
constexpr bool operator>( const de::math::vec2<T> p_a, const de::math::vec2<T> p_b ) noexcept
{
	return ( ( p_a.x > p_b.x ) && ( p_a.y > p_b.y ) );
}

template<typename T>
constexpr bool operator>=( const de::math::vec2<T> p_a, const de::math::vec2<T> p_b ) noexcept
{
	return ( ( p_a.x >= p_b.x ) && ( p_a.y >= p_b.y ) );
}

/* END */
