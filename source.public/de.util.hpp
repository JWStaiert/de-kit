#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <cstdint>

namespace de
{
	namespace util
	{
		template <typename T>
		struct functions
		{
			static constexpr bool is_signed( ) noexcept;

			static constexpr int digits10( ) noexcept;

			static constexpr int digits16( ) noexcept;

			static constexpr bool is_positive( const T p_value ) noexcept
			{
				if ( p_value >= 0 )
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			static constexpr bool is_negative( const T p_value ) noexcept
			{
				if ( p_value >= 0 )
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		};

		template<> constexpr bool functions<std::int8_t>::is_signed( ) noexcept { return true; }
		template<> constexpr bool functions<std::int16_t>::is_signed( ) noexcept { return true; }
		template<> constexpr bool functions<std::int32_t>::is_signed( ) noexcept { return true; }
		template<> constexpr bool functions<std::int64_t>::is_signed( ) noexcept { return true; }
		template<> constexpr bool functions<std::uint8_t>::is_signed( ) noexcept { return false; }
		template<> constexpr bool functions<std::uint16_t>::is_signed( ) noexcept { return false; }
		template<> constexpr bool functions<std::uint32_t>::is_signed( ) noexcept { return false; }
		template<> constexpr bool functions<std::uint64_t>::is_signed( ) noexcept { return false; }

		template<> constexpr int functions<std::int8_t>::digits10( ) noexcept { return 3; }
		template<> constexpr int functions<std::int16_t>::digits10( ) noexcept { return 5; }
		template<> constexpr int functions<std::int32_t>::digits10( ) noexcept { return 10; }
		template<> constexpr int functions<std::int64_t>::digits10( ) noexcept { return 19; }
		template<> constexpr int functions<std::uint8_t>::digits10( ) noexcept { return 3; }
		template<> constexpr int functions<std::uint16_t>::digits10( ) noexcept { return 5; }
		template<> constexpr int functions<std::uint32_t>::digits10( ) noexcept { return 10; }
		template<> constexpr int functions<std::uint64_t>::digits10( ) noexcept { return 20; }

		template<> constexpr int functions<std::int8_t>::digits16( ) noexcept { return 2; }
		template<> constexpr int functions<std::int16_t>::digits16( ) noexcept { return 4; }
		template<> constexpr int functions<std::int32_t>::digits16( ) noexcept { return 8; }
		template<> constexpr int functions<std::int64_t>::digits16( ) noexcept { return 16; }
		template<> constexpr int functions<std::uint8_t>::digits16( ) noexcept { return 2; }
		template<> constexpr int functions<std::uint16_t>::digits16( ) noexcept { return 4; }
		template<> constexpr int functions<std::uint32_t>::digits16( ) noexcept { return 8; }
		template<> constexpr int functions<std::uint64_t>::digits16( ) noexcept { return 16; }

		template <typename T>
		struct constants
		{
			static constexpr bool is_signed = functions<T>::is_signed( );

			static constexpr int digits10 = functions<T>::digits10( );

			static constexpr int digits16 = functions<T>::digits16( );
		};

		class cstring_basic
		{
			const std::uint32_t m_last;

			std::uint32_t m_end;

			char * m_buffer;

		public:

			cstring_basic( ) = delete;

			cstring_basic( char p_buffer[] , std::uint32_t p_size ) noexcept;

			cstring_basic( const cstring_basic & ) = delete;

			inline ~cstring_basic( ) noexcept
			{
			}

			cstring_basic & operator=( const cstring_basic & ) = delete;

			inline operator const char *( ) const noexcept
			{
				return m_buffer;
			}

			void append_char( const char p_char ) noexcept;

			void append_digit10( const std::uint8_t p_digit ) noexcept;

			void append_digit16( const std::uint8_t p_digit ) noexcept;

			void append_cstring( const char * p_cstring ) noexcept;

			template <typename T> void append_decimal( const T p_value ) noexcept;

			template <typename T> void append_hexadecimal( const T p_value ) noexcept;

			void reset( ) noexcept;
		};

		#ifndef DE__UTIL__DEFINE_EXTERN_TEMPLATES

		extern template void cstring_basic::append_decimal( const std::int8_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::int16_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::int32_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::int64_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::uint8_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::uint16_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::uint32_t p_value ) noexcept;
		extern template void cstring_basic::append_decimal( const std::uint64_t p_value ) noexcept;

		extern template void cstring_basic::append_hexadecimal( const std::int8_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::int16_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::int32_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::int64_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::uint8_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::uint16_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::uint32_t p_value ) noexcept;
		extern template void cstring_basic::append_hexadecimal( const std::uint64_t p_value ) noexcept;

		#endif

		template <std::uint32_t SIZE>
		class cstring_array : public cstring_basic
		{
			char m_buffer[ SIZE ];

		public:

			inline cstring_array( ) noexcept
				: cstring_basic { m_buffer , SIZE }
			{
			}

			cstring_array( const cstring_array & ) = delete;

			inline ~cstring_array( ) noexcept
			{
			}

			cstring_array & operator=( const cstring_array & ) = delete;
		};
	}
}

/* END */
