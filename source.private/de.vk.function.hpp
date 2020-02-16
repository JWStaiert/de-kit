#pragma once
/* Copyright (c) 2020 Jason William Staiert. All Rights Reserved. */

#define DE__VK__FUNCTION_EXTERN( p_name ) extern PFN_##p_name _##p_name

#define DE__VK__FUNCTION( p_name ) PFN_##p_name _##p_name = nullptr

#define DE__VK__FUNCTION_LOAD( p_name, p_get_addr_fn ) _##p_name = static_cast<PFN_##p_name>( p_get_addr_fn( #p_name ) )

#define DE__VK__FUNCTION_CALL( p_name ) _##p_name

/* END */
