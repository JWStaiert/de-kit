#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.log.hpp"

#include <string>

class de__log__test : public testing::Test
{
	std::streambuf * m_sbuf;

protected:

	std::stringstream m_log;

	std::vector<std::string> m_log_lines;

public:

	de__log__test( )
		: m_sbuf      { nullptr }
		, m_log       { }
		, m_log_lines { }
	{
		/* Save std::cout buffer. */
		m_sbuf = std::cout.rdbuf( );

		/* Set std::cout to our stringstream buffer. */
		std::cout.rdbuf( m_log.rdbuf( ) );
	}

	~de__log__test( )
	{
		/* Restore std::cout. */
		std::cout.rdbuf( m_sbuf );
	}

	void SetUp( )
	{
		de::log::start( "stdout" );
	}

	void TearDown( )
	{
		de::log::stop( );
	}

	void ProcessLog( )
	{
		std::string l_line;

		while ( std::getline( m_log , l_line ) )
		{
			m_log_lines.push_back( l_line );
		}
	}
};

/* END */
