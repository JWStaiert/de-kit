/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#include <gtest/gtest.h>

#include "de.os.window.hpp"

#include <de.app.hpp>
#include <de.log.hpp>

#include <de.os.error.hpp>

#include <unit-test.de.log.hpp>

#include <string>

#include <cstdint>

#include <Windows.h>

#define UUT__TEST_WINDOW_NAME L"de::os::window test"

#define UUT__MESSAGE_BOX_CAPTION L"Test Instructions"

TEST( de__os__window, assumptions )
{
	EXPECT_EQ( sizeof( LONG_PTR ), sizeof( void* ) );
}

TEST( de__os__window, window_properties_defaults )
{
	de::os::window_properties uut{};

	EXPECT_EQ( uut.name, L"default application name" );
	EXPECT_EQ( uut.menus.size( ), 0 );
}

TEST( de__os__window, ctor_success )
{
	try
	{
		de::os::window uut{};
	}
	catch ( const std::exception& exc )
	{
		FAIL( ) << "Unexpected standard exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

class de__os__window__test_fixture : public de__log__test_fixture
{
public:
	de__os__window__test_fixture( )
		: de__log__test_fixture{}
	{
	}

	virtual ~de__os__window__test_fixture( )
	{
	}

	virtual void SetUp( )
	{
		de__log__test_fixture::SetUp( );
	}

	virtual void TearDown( )
	{
		de__log__test_fixture::TearDown( );
	}

	const wchar_t* GetCLASS_NAME( ) const
	{
		return de::os::window::CLASS_NAME;
	}
};

TEST_F( de__os__window__test_fixture, dtor_unregisters_class )
{
	try
	{
		{
			de::os::window uut{};
		}

		EXPECT_TRUE( UnregisterClassW( GetCLASS_NAME( ), NULL ) == FALSE );

		EXPECT_EQ( std::string( de::os::error::get_message( ) ), "GetLastError(00000583)=[Class does not exist]" );
	}
	catch ( const std::exception& exc )
	{
		FAIL( ) << "Unexpected standard exception: " << exc.what( );
	}
	catch ( ... )
	{
		FAIL( ) << "Unexpected exception.";
	}
}

struct uut_command
{
	enum
	{
		command_a = 1,
		command_b,
		check_1,
		check_2,
		name,
	};
};

static const de::os::window_menu UUT_MENU_COMMAND{ L"Command",
	{
		{ de::os::window_menu_type::command, L"A", uut_command::command_a },
		{},
		{ de::os::window_menu_type::command, L"B", uut_command::command_b },
	} };

static const de::os::window_menu UUT_MENU_CHECK{ L"Check",
	{
		{ de::os::window_menu_type::checkbox, L"1", uut_command::check_1 },
		{ de::os::window_menu_type::checkbox, L"2", uut_command::check_2 },
	} };

static const de::os::window_menu UUT_MENU_NAME{ L"Name", {}, uut_command::name };

static const de::os::window_properties UUT_PROPERTIES{ UUT__TEST_WINDOW_NAME, { UUT_MENU_COMMAND, UUT_MENU_CHECK, UUT_MENU_NAME } };

TEST( de__os__window, window_menu_initialization )
{
	// Command Menu Items
	EXPECT_EQ( UUT_MENU_COMMAND.name, L"Command" );
	ASSERT_EQ( UUT_MENU_COMMAND.items.size( ), 3 );
	EXPECT_EQ( UUT_MENU_COMMAND.id, -1 );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 0 ].type, de::os::window_menu_type::command );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 0 ].name, L"A" );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 0 ].id, uut_command::command_a );

	EXPECT_EQ( UUT_MENU_COMMAND.items[ 1 ].type, de::os::window_menu_type::separator );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 1 ].name, L"" );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 1 ].id, -1 );

	EXPECT_EQ( UUT_MENU_COMMAND.items[ 2 ].type, de::os::window_menu_type::command );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 2 ].name, L"B" );
	EXPECT_EQ( UUT_MENU_COMMAND.items[ 2 ].id, uut_command::command_b );

	// Check Menu Items
	EXPECT_EQ( UUT_MENU_CHECK.name, L"Check" );
	ASSERT_EQ( UUT_MENU_CHECK.items.size( ), 2 );
	EXPECT_EQ( UUT_MENU_CHECK.id, -1 );
	EXPECT_EQ( UUT_MENU_CHECK.items[ 0 ].type, de::os::window_menu_type::checkbox );
	EXPECT_EQ( UUT_MENU_CHECK.items[ 0 ].name, L"1" );
	EXPECT_EQ( UUT_MENU_CHECK.items[ 0 ].id, uut_command::check_1 );

	EXPECT_EQ( UUT_MENU_CHECK.items[ 1 ].type, de::os::window_menu_type::checkbox );
	EXPECT_EQ( UUT_MENU_CHECK.items[ 1 ].name, L"2" );
	EXPECT_EQ( UUT_MENU_CHECK.items[ 1 ].id, uut_command::check_2 );

	// Help Menu Items
	EXPECT_EQ( UUT_MENU_NAME.name, L"Name" );
	ASSERT_EQ( UUT_MENU_NAME.items.size( ), 0 );
	EXPECT_EQ( UUT_MENU_NAME.id, uut_command::name );

	// Window Properties
	ASSERT_EQ( UUT_PROPERTIES.menus.size( ), 3 );
	EXPECT_EQ( UUT_PROPERTIES.menus[ 0 ].name, L"Command" );
	EXPECT_EQ( UUT_PROPERTIES.menus[ 1 ].name, L"Check" );
	EXPECT_EQ( UUT_PROPERTIES.menus[ 2 ].name, L"Name" );
}

class de__os__window__uut_open_test_fixture : public de__os__window__test_fixture
{
public:
	de::os::window uut;

	de__os__window__uut_open_test_fixture( )
		: de__os__window__test_fixture{}
		, uut{ UUT_PROPERTIES }
	{
	}

	virtual ~de__os__window__uut_open_test_fixture( )
	{
	}

	virtual void SetUp( )
	{
		de__os__window__test_fixture::SetUp( );
	}

	virtual void TearDown( )
	{
		de__os__window__test_fixture::TearDown( );
	}
};

TEST_F( de__os__window__uut_open_test_fixture, state_is_open )
{
	EXPECT_EQ( uut.state( ), de::os::window_state::open );

	EXPECT_TRUE( MessageBoxW( NULL, L"A \"" UUT__TEST_WINDOW_NAME "\" window has been initialized but not shown. Is it visible?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDNO );
}

TEST_F( de__os__window__uut_open_test_fixture, show )
{
	uut.show( );

	EXPECT_TRUE( MessageBoxW( NULL, L"Is the \"" UUT__TEST_WINDOW_NAME "\" window visible?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDYES );
}

class de__os__window__uut_visuble_test_fixture : public de__os__window__uut_open_test_fixture
{
public:
	de::os::window_event uut_event;

	de__os__window__uut_visuble_test_fixture( )
		: de__os__window__uut_open_test_fixture{}
	{
	}

	virtual ~de__os__window__uut_visuble_test_fixture( )
	{
	}

	virtual void SetUp( )
	{
		de__os__window__uut_open_test_fixture::SetUp( );

		uut.show( );
	}

	virtual void TearDown( )
	{
		de__os__window__uut_open_test_fixture::TearDown( );
	}
};

TEST_F( de__os__window__uut_visuble_test_fixture, state_is_visible )
{
	EXPECT_EQ( uut.state( ), de::os::window_state::visible );
}

TEST_F( de__os__window__uut_visuble_test_fixture, event_loop_close )
{
	ASSERT_TRUE( MessageBoxW( NULL, L"Close the \"" UUT__TEST_WINDOW_NAME "\" window.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.state( ) != de::os::window_state::closed )
	{
		while ( uut.has_event( uut_event ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ), de::os::window_state::closed );
}

TEST_F( de__os__window__uut_visuble_test_fixture, event_loop_increase_size )
{
	de::os::window_size l_initial_size = uut.size( );

	ASSERT_TRUE( MessageBoxW( NULL, L"Increase (but do not maximize) size of \"" UUT__TEST_WINDOW_NAME "\" window.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.size( ) <= l_initial_size )
	{
		while ( uut.has_event( uut_event ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ), de::os::window_state::visible );
	EXPECT_GT( uut.size( ), l_initial_size );
}

TEST_F( de__os__window__uut_visuble_test_fixture, event_loop_decrease_size )
{
	de::os::window_size l_initial_size = uut.size( );

	ASSERT_TRUE( MessageBoxW( NULL, L"Decrease (but do not minimize) size of \"" UUT__TEST_WINDOW_NAME "\" window.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.size( ) >= l_initial_size )
	{
		while ( uut.has_event( uut_event ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ), de::os::window_state::visible );
	EXPECT_LT( uut.size( ), l_initial_size );
}

TEST_F( de__os__window__uut_visuble_test_fixture, event_loop_maximize )
{
	ASSERT_TRUE( MessageBoxW( NULL, L"Maximize the \"de::os::window test\" window.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.state( ) != de::os::window_state::visible_maximized )
	{
		while ( uut.has_event( uut_event ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ), de::os::window_state::visible_maximized );
}

TEST_F( de__os__window__uut_visuble_test_fixture, event_loop_minimize )
{
	ASSERT_TRUE( MessageBoxW( NULL, L"Minimize the \"" UUT__TEST_WINDOW_NAME "\" window.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	while ( uut.state( ) != de::os::window_state::visible_minimized )
	{
		while ( uut.has_event( uut_event ) )
		{
		}
	}

	EXPECT_EQ( uut.state( ), de::os::window_state::visible_minimized );
}

TEST_F( de__os__window__uut_visuble_test_fixture, event_loop_menu_commands )
{
	EXPECT_TRUE( MessageBoxW( NULL, L"Is a menu bar visible in \"" UUT__TEST_WINDOW_NAME "\" window?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDYES );

	EXPECT_TRUE( MessageBoxW( NULL, L"Does the menu bar contain the items 'Command' 'Check' and 'Name'?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDYES );

	ASSERT_TRUE( MessageBoxW( NULL, L"Select item Command>A.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	bool l_command_a_selected = false;

	while ( !l_command_a_selected )
	{
		while ( uut.has_event( uut_event ) )
		{
			l_command_a_selected = ( ( uut_event.type == de::os::window_event::command_type ) && ( uut_event.id == uut_command::command_a ) );
		}
	}

	ASSERT_TRUE( MessageBoxW( NULL, L"Select item Command>B.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	bool l_command_b_selected = false;

	while ( !l_command_b_selected )
	{
		while ( uut.has_event( uut_event ) )
		{
			l_command_b_selected = ( ( uut_event.type == de::os::window_event::command_type ) && ( uut_event.id == uut_command::command_b ) );
		}
	}

	EXPECT_TRUE( MessageBoxW( NULL, L"Select the Check menu. Is there an icon next to Check>1 or Check>2?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDNO );

	ASSERT_TRUE( MessageBoxW( NULL, L"Select item Check>1.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	bool l_check_1_selected = false;

	while ( !l_check_1_selected )
	{
		while ( uut.has_event( uut_event ) )
		{
			l_check_1_selected = ( ( uut_event.type == de::os::window_event::command_type ) && ( uut_event.id == uut_command::check_1 ) );
		}
	}

	uut.check_menu_item( uut_command::check_1 );

	EXPECT_TRUE( l_check_1_selected );

	EXPECT_TRUE( MessageBoxW( NULL, L"Select the Check menu. Is there now an icon next to Check>1?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDYES );

	ASSERT_TRUE( MessageBoxW( NULL, L"Select item Check>2.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	bool l_check_2_selected = false;

	while ( !l_check_2_selected )
	{
		while ( uut.has_event( uut_event ) )
		{
			l_check_2_selected = ( ( uut_event.type == de::os::window_event::command_type ) && ( uut_event.id == uut_command::check_2 ) );
		}
	}

	uut.check_menu_item( uut_command::check_2 );

	EXPECT_TRUE( MessageBoxW( NULL, L"Select the Check menu. Is there now an icon next to Check>2?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDYES );

	ASSERT_TRUE( MessageBoxW( NULL, L"Select item Check>1 again.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	bool l_check_1_selected_again = false;

	while ( !l_check_1_selected_again )
	{
		while ( uut.has_event( uut_event ) )
		{
			l_check_1_selected_again = ( ( uut_event.type == de::os::window_event::command_type ) && ( uut_event.id == uut_command::check_1 ) );
		}
	}

	uut.uncheck_menu_item( uut_command::check_1 );

	EXPECT_TRUE( MessageBoxW( NULL, L"Select the Check menu. Has the icon next to Check>1 disappeared?", UUT__MESSAGE_BOX_CAPTION, ( MB_YESNO | MB_TOPMOST ) ) == IDYES );

	ASSERT_TRUE( MessageBoxW( NULL, L"Select item Name.", UUT__MESSAGE_BOX_CAPTION, ( MB_OK | MB_TOPMOST ) ) == IDOK );

	bool l_name_selected = false;

	while ( !l_name_selected )
	{
		while ( uut.has_event( uut_event ) )
		{
			l_name_selected = ( ( uut_event.type == de::os::window_event::command_type ) && ( uut_event.id == uut_command::name ) );
		}
	}
}

/* END */
