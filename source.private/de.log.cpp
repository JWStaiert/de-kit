/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "de.log.hpp"

#include <fstream>
#include <iostream>

namespace de
{
	namespace log
	{
		/* */
		de::log::_stream stream{ {}, {}, nullptr, {} };

		/* */
		class alloced_stream_delete
		{
			std::ostream* m_stream;

		public:
			alloced_stream_delete( ) noexcept;

			alloced_stream_delete( const alloced_stream_delete& ) = delete;

			~alloced_stream_delete( );

			alloced_stream_delete* operator=( const alloced_stream_delete& ) = delete;

			void delete_stream( );

			void set_stream( std::ostream* p_stream ) noexcept;
		};

		alloced_stream_delete::alloced_stream_delete( ) noexcept
			: m_stream{ nullptr }
		{
		}

		alloced_stream_delete::~alloced_stream_delete( )
		{
			delete_stream( );
		}

		void alloced_stream_delete::delete_stream( )
		{
			std::lock_guard<std::mutex> lock{ stream.mutex };

			if ( m_stream != nullptr )
			{
				*m_stream << std::endl << "Stream properly closed. END OF LOG." << std::endl;

				m_stream->flush( );

				delete m_stream;

				m_stream = nullptr;
			}
		}

		void alloced_stream_delete::set_stream( std::ostream* p_stream ) noexcept
		{
			m_stream = p_stream;
		}

		/* */
		static alloced_stream_delete stream_dealloc{};

		/* */
		void start( const std::filesystem::path& p_pathname )
		{
			std::lock_guard<std::mutex> lock{ stream.mutex };

			if ( p_pathname == "stdout" )
			{
				stream.ptr = &std::cout;
			}
			else if ( p_pathname == "stderr" )
			{
				stream.ptr = &std::cerr;
			}
			else
			{
				stream.ptr = new std::ofstream{ p_pathname, std::ios::trunc | std::ios::out };

				stream_dealloc.set_stream( stream.ptr );
			}
		}

		void stop( )
		{
			/* Set public stream pointer to nullptr. */
			{
				std::lock_guard<std::mutex> lock{ stream.mutex };

				stream.ptr = nullptr;
			}

			/* Deallocated stream if it was allocated during start. Test for this condition is integral to the alloced_stream_delete object.)*/
			stream_dealloc.delete_stream( );
		}
	}
}

/* END */
