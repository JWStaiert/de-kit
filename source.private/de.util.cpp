/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#define DE__UTIL__DEFINE_EXTERN_TEMPLATES
#include "de.util.hpp"

namespace de
{
	namespace util
	{
		cstring_basic::cstring_basic( char p_buffer[] , std::uint32_t p_size ) noexcept
			: m_last { p_size - 1u }
			, m_end { 0u }
			, m_buffer { p_buffer }
		{
			m_buffer[ 0 ] = 0;
			m_buffer[ m_last ] = 0;
		}

		void cstring_basic::append_char( const char p_char ) noexcept
		{
			if ( m_end < m_last )
			{
				m_buffer[ m_end ] = p_char;

				++m_end;

				m_buffer[ m_end ] = 0;
			}
		}

		void cstring_basic::append_digit10( const std::uint8_t p_digit ) noexcept
		{
			append_char( '0' + static_cast<char>( p_digit ) );
		}

		void cstring_basic::append_digit16( const std::uint8_t p_digit ) noexcept
		{
			if ( p_digit > 9 )
			{
				append_char( 'A' + static_cast<char>( p_digit ) - 10 );
			}
			else
			{
				append_char( '0' + static_cast<char>( p_digit ) );
			}
		}

		void cstring_basic::append_cstring( const char * p_cstring ) noexcept
		{
			auto i = 0u;

			while ( ( m_end < m_last ) && ( ( m_buffer[ m_end ] = p_cstring[ i ] ) != 0 ) )
			{
				++m_end;
				++i;
			}
		}

		template <typename T>
		void cstring_basic::append_decimal( const T p_value ) noexcept
		{
			if ( p_value == 0 )
			{
				append_char( '0' );
			}
			else
			{
				bool leading_zero = true;

				bool sign = functions<T>::is_negative( p_value );

				if ( sign ) append_char( '-' );

				for ( auto digit = constants<T>::digits10 ; digit > 0 ; --digit )
				{
					T divisor = 1;

					for ( auto i = 1 ; i < digit ; ++i ) divisor *= 10;

					T tmp = p_value;

					tmp /= divisor;
					tmp %= 10;

					if ( leading_zero && tmp != 0 )
					{
						leading_zero = false;
					}

					if ( !leading_zero )
					{
						if ( sign )
						{
							tmp = 0 - tmp;
						}

						append_digit10( static_cast<std::uint8_t>( tmp ) );
					}
				}
			}
		}

		template void cstring_basic::append_decimal( const std::int8_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::int16_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::int32_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::int64_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::uint8_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::uint16_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::uint32_t p_value ) noexcept;
		template void cstring_basic::append_decimal( const std::uint64_t p_value ) noexcept;

		template <typename T>
		void cstring_basic::append_hexadecimal( const T p_value ) noexcept
		{
			for ( auto digit = constants<T>::digits16 ; digit > 0 ; --digit )
			{
				T tmp = p_value;

				tmp >>= ( 4 * ( digit - 1 ) );

				tmp &= 0xF;

				append_digit16( static_cast<std::uint8_t>( tmp ) );
			}
		}

		template void cstring_basic::append_hexadecimal( const std::int8_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::int16_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::int32_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::int64_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::uint8_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::uint16_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::uint32_t p_value ) noexcept;
		template void cstring_basic::append_hexadecimal( const std::uint64_t p_value ) noexcept;

		void cstring_basic::reset( ) noexcept
		{
			m_end = 0;

			m_buffer[ 0 ] = 0;
		}
	}
}

/* END */
