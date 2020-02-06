/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include "gtest/gtest.h"

#include "de.os.window.hpp"

#include "de.os.error.hpp"

#include "de.app.hpp"
#include "de.log.hpp"
#include "de.log.unit-test.hpp"

#include <string>

#include <Windows.h>

#define UUT__TEST_WINDOW_NAME "de::os::window test"

#define UUT__MESSAGE_BOX_CAPTION "Test Instructions"

TEST( de__os__window , ctor_success )
{
	try
	{
		const de::app uut_app { };

		de::os::window uut { uut_app };
	}
	catch ( const std::exception & exc )
	{
		FAIL( ) << "Unexpected exception. " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

TEST( de__os__window , dtor_unregisters_class )
{
	try
	{
		{
			const de::app uut_app { };

			de::os::window uut { uut_app };
		}

		EXPECT_TRUE( UnregisterClassA( "de::os::window" , NULL ) == 0 );

		EXPECT_EQ( std::string( de::os::error::get_message( ) ) , "GetLastError(00000583)=[Class does not exist]" );
	}
	catch ( const std::exception & exc )
	{
		FAIL( ) << "Unexpected exception. " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unrecognized exception.";
	}
}

class de__os__window__uut_initialized : public de__log__test
{
public:

	const de::app uut_app;

	de::os::window uut;

	de__os__window__uut_initialized( )
		: de__log__test { }
		, uut_app { UUT__TEST_WINDOW_NAME , { 1 , 0 , 0 } }
		, uut     { uut_app }
	{
	}

	virtual ~de__os__window__uut_initialized( )
	{
	}

	virtual void SetUp( )
	{
		de__log__test::SetUp( );
	}

	virtual void TearDown( )
	{
		de__log__test::TearDown( );
	}
};

TEST_F( de__os__window__uut_initialized , state_is_open )
{
	EXPECT_EQ( uut.state( ) , de::os::window_state::open );

	EXPECT_TRUE( MessageBoxA( NULL , "A \"" UUT__TEST_WINDOW_NAME "\" window has been initialized but not shown. Is it visible?" , UUT__MESSAGE_BOX_CAPTION , ( MB_YESNO | MB_TOPMOST ) ) == IDNO );
}

TEST_F( de__os__window__uut_initialized , show )
{
	uut.show( );

	EXPECT_TRUE( MessageBoxA( NULL , "Is the \"" UUT__TEST_WINDOW_NAME "\" window visible?" , UUT__MESSAGE_BOX_CAPTION , ( MB_YESNO | MB_TOPMOST ) ) == IDYES );
}

class de__os__window__uut_show : public de__os__window__uut_initialized
{
public:

	de__os__window__uut_show( )
		: de__os__window__uut_initialized { }
	{
	}

	virtual ~de__os__window__uut_show( )
	{
	}

	virtual void SetUp( )
	{
		de__os__window__uut_initialized::SetUp( );

		uut.show( );
	}

	virtual void TearDown( )
	{
		de__os__window__uut_initialized::TearDown( );
	}
};

TEST_F( de__os__window__uut_show , state_is_visible )
{
	EXPECT_EQ( uut.state( ) , de::os::window_state::visible );
}

TEST_F( de__os__window__uut_show , event_loop_close )
{
	ASSERT_TRUE( MessageBoxA( NULL , "Close the \"" UUT__TEST_WINDOW_NAME "\" window." , UUT__MESSAGE_BOX_CAPTION , ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.state( ) != de::os::window_state::closed )
	{
		while ( uut.has_event( ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ) , de::os::window_state::closed );
}

TEST_F( de__os__window__uut_show , event_loop_increase_size )
{
	de::os::window_size l_initial_size = uut.size( );

	ASSERT_TRUE( MessageBoxA( NULL , "Increase (but do not maximize) size of \"" UUT__TEST_WINDOW_NAME "\" window." , UUT__MESSAGE_BOX_CAPTION , ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.size( ) <= l_initial_size )
	{
		while ( uut.has_event( ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ) , de::os::window_state::visible );
	EXPECT_GT( uut.size( ) , l_initial_size );
}

TEST_F( de__os__window__uut_show , event_loop_decrease_size )
{
	de::os::window_size l_initial_size = uut.size( );

	ASSERT_TRUE( MessageBoxA( NULL , "Decrease (but do not minimize) size of \"" UUT__TEST_WINDOW_NAME "\" window." , UUT__MESSAGE_BOX_CAPTION , ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.size( ) >= l_initial_size )
	{
		while ( uut.has_event( ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ) , de::os::window_state::visible );
	EXPECT_LT( uut.size( ) , l_initial_size );
}

TEST_F( de__os__window__uut_show , event_loop_maximize )
{
	ASSERT_TRUE( MessageBoxA( NULL , "Maximize the \"de::os::window test\" window." , UUT__MESSAGE_BOX_CAPTION , ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.state( ) != de::os::window_state::visible_maximized )
	{
		while ( uut.has_event( ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ) , de::os::window_state::visible_maximized );
}

TEST_F( de__os__window__uut_show , event_loop_minimize )
{
	ASSERT_TRUE( MessageBoxA( NULL , "Minimize the \"" UUT__TEST_WINDOW_NAME "\" window." , UUT__MESSAGE_BOX_CAPTION , ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.state( ) != de::os::window_state::visible_minimized )
	{
		while ( uut.has_event( ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ) , de::os::window_state::visible_minimized );
}

/* END */
