/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.log.hpp"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class de__log__test : public testing::Test
{
protected:

	const std::string m_logname;

	std::fstream m_log;

public:

	de__log__test( )
		: m_logname { "./test.log" }
		, m_log { }
	{
	}

	~de__log__test( )
	{
	}

	void SetUp( )
	{
		m_log.open( m_logname , ( std::ios::trunc | std::ios::in | std::ios::out ) );
	}

	void TearDown( )
	{
		m_log.close( );

		std::remove( m_logname.c_str( ) );
	}
};

class de__log__started_test : public de__log__test
{
public:

	de__log__started_test( )
	{
	}

	~de__log__started_test( )
	{
	}

	void SetUp( )
	{
		de__log__test::SetUp( );

		de::log::start( m_logname );
	}

	void TearDown( )
	{
		de::log::stop( );

		de__log__test::TearDown( );
	}
};

class de__log__stdout_test : public testing::Test
{
	std::streambuf * m_sbuf;

protected:

	std::stringstream m_log;

public:

	de__log__stdout_test( )
		: m_log { }
	{
		/* Save std::cout buffer. */
		m_sbuf = std::cout.rdbuf( );

		/* Set std::cout to our stringstream buffer. */
		std::cout.rdbuf( m_log.rdbuf( ) );
	}

	~de__log__stdout_test( )
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
};

class de__log__stderr_test : public testing::Test
{
	std::streambuf * m_sbuf;

protected:

	std::stringstream m_log;

public:

	de__log__stderr_test( )
		: m_log { }
	{
		/* Save std::cerr. */
		m_sbuf = std::cerr.rdbuf( );

		/* Set std::cerr to our stringstream buffer. */
		std::cerr.rdbuf( m_log.rdbuf( ) );
	}

	~de__log__stderr_test( )
	{
		/* Restore std::cerr. */
		std::cerr.rdbuf( m_sbuf );
	}

	void SetUp( )
	{
		de::log::start( "stderr" );
	}

	void TearDown( )
	{
		de::log::stop( );
	}
};

TEST( de__log , sizeof_stream )
{
	EXPECT_EQ( 256 , sizeof( de::log::_stream ) );
}

TEST( de_log , alignof_stream )
{
	EXPECT_EQ( 256 , alignof( de::log::_stream ) );
}

TEST_F( de__log__test , not_started_info_does_not_throw )
{
	EXPECT_NO_THROW( DE__LOG__INFO( "test" ) );
}

TEST_F( de__log__test , not_started_warning_does_not_throw )
{
	EXPECT_NO_THROW( DE__LOG__WARNING( "test" ) );
}

TEST_F( de__log__test , not_started_exception_does_not_throw )
{
	EXPECT_NO_THROW( DE__LOG__EXCEPTION( "test" ) );
}

TEST_F( de__log__test , start_stop_file_operations )
{
	std::fstream l_log;

	/* Add content to log file. */
	m_log << "Some content." << std::endl;
	m_log.flush( );

	/* Verify log file is not empty. */
	l_log.open( m_logname , std::ios::in );
	l_log.seekg( 0 , std::ios::end );
	EXPECT_GT( l_log.tellg( ) , 0 );
	l_log.close( );

	/* Start log. */
	EXPECT_NO_THROW(de::log::start( m_logname ));

	/* Verify log has been truncated. */
	l_log.open( m_logname , std::ios::in );
	l_log.seekg( 0 , std::ios::end );
	EXPECT_EQ( l_log.tellg( ) , 0 );
	l_log.close( );

	/* Stop log. */
	EXPECT_NO_THROW( de::log::stop( ) );

	/* Verify log contains stop text. */
	std::string l_line;
	std::vector<std::string> l_line_vector;

	l_log.open( m_logname , std::ios::in );

	while ( std::getline( l_log , l_line ) )
	{
		l_line_vector.push_back( l_line );
	}

	EXPECT_EQ( l_line_vector.size( ) , 2 );
	EXPECT_EQ( l_line_vector[ 0 ] , "" );
	EXPECT_EQ( l_line_vector[ 1 ] , "Stream properly closed. END OF LOG." );
}

TEST_F( de__log__started_test , info_message )
{
	EXPECT_NO_THROW( DE__LOG__INFO( "info message" << std::endl ) );

	std::string l_line;
	std::vector<std::string> l_line_vector;

	while ( std::getline( m_log , l_line ) )
	{
		l_line_vector.push_back( l_line );
	}

	EXPECT_EQ( l_line_vector.size( ) , 1 );
	EXPECT_EQ( l_line_vector[ 0 ] , "info message" );
}

TEST_F( de__log__started_test , warning_message )
{
	EXPECT_NO_THROW( DE__LOG__WARNING( "warning message" << std::endl ) );

	std::string l_line;
	std::vector<std::string> l_line_vector;

	while ( std::getline( m_log , l_line ) )
	{
		l_line_vector.push_back( l_line );
	}

	EXPECT_EQ( l_line_vector.size( ) , 1 );
	EXPECT_EQ( l_line_vector[ 0 ] , "de__log__started_test_warning_message_Test::TestBody@233 | warning message" );
}

TEST_F( de__log__started_test , exception_message )
{
	EXPECT_NO_THROW( DE__LOG__EXCEPTION( "exception message" << std::endl ) );

	std::string l_line;
	std::vector<std::string> l_line_vector;

	while ( std::getline( m_log , l_line ) )
	{
		l_line_vector.push_back( l_line );
	}

	EXPECT_EQ( l_line_vector.size( ) , 1 );
	EXPECT_EQ( l_line_vector[ 0 ] , "de__log__started_test_exception_message_Test::TestBody@249 | !EXCEPTION! | exception message" );
}

TEST_F( de__log__stdout_test , message )
{
	EXPECT_NO_THROW( DE__LOG__INFO( "message" << std::endl ) );

	std::string l_line;
	std::vector<std::string> l_line_vector;

	while ( std::getline( m_log , l_line ) )
	{
		l_line_vector.push_back( l_line );
	}

	EXPECT_EQ( l_line_vector.size( ) , 1 );
	EXPECT_EQ( l_line_vector[ 0 ] , "message" );
}

TEST_F( de__log__stderr_test , message )
{
	EXPECT_NO_THROW( DE__LOG__INFO( "message" << std::endl ) );

	std::string l_line;
	std::vector<std::string> l_line_vector;

	while ( std::getline( m_log , l_line ) )
	{
		l_line_vector.push_back( l_line );
	}

	EXPECT_EQ( l_line_vector.size( ) , 1 );
	EXPECT_EQ( l_line_vector[ 0 ] , "message" );
}

/* END */
