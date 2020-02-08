#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include <de.log.hpp>

#include <string>

class de__log__test_fixture : public testing::Test
{
	std::streambuf* m_sbuf;

protected:
	std::stringstream m_log;

	std::vector<std::string> m_log_lines;

public:
	de__log__test_fixture( )
		: m_sbuf{ nullptr }
		, m_log{}
		, m_log_lines{}
	{
		/* Save std::cout buffer. */
		m_sbuf = std::cout.rdbuf( );

		/* Set std::cout to our stringstream buffer. */
		std::cout.rdbuf( m_log.rdbuf( ) );
	}

	virtual ~de__log__test_fixture( )
	{
		/* Restore std::cout. */
		std::cout.rdbuf( m_sbuf );
	}

	virtual void SetUp( )
	{
		testing::Test::SetUp( );

		de::log::start( "stdout" );
	}

	virtual void TearDown( )
	{
		de::log::stop( );

		CheckLog( );

		testing::Test::TearDown( );
	}

	void ProcessLog( )
	{
		std::string l_line;

		while ( std::getline( m_log, l_line ) )
		{
			m_log_lines.push_back( l_line );
		}
	}

	void ClearLog( )
	{
		m_log.str( std::string{} );
		m_log_lines.resize( 0 );
	}

	void CheckLog( )
	{
		ProcessLog( );

		for ( auto i : m_log_lines )
		{
			ADD_FAILURE( ) << "unexpected log line: " << i << std::endl;
		}
	}
};

/* END */
