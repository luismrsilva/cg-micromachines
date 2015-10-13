/*
 * debug.hpp
 * Provides wrapper functions that only work when DEBUG is defined.
 * One way to define it is to use -D compiler flag (-DDEBUG).
 * */

#ifndef __DEBUG_HPP_INCLUDED
#define __DEBUG_HPP_INCLUDED

#ifdef DEBUG
	#include <iostream>
	#define D_PRINT(str) \
		std::cout << __FILE__ ":" << __LINE__ << "\t" str << std::endl
	#define D_TRACE(str) \
		std::cout << __FILE__ ":" << __LINE__ << "\t" << __FUNCTION__ str << std::endl
#else
	#define D_PRINT(str)
	#define D_TRACE(str)
#endif

#endif //__DEBUG_HPP_INCLUDED
