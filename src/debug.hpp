/*
 * debug.hpp
 * Provides wrapper functions that only work when DEBUG is defined.
 * One way to define it is to use -D compiler flag (-DDEBUG).
 * */

#ifdef DEBUG
	#define D_PRINT(str) \
		cout << __FILE__ ":" << __LINE__ << "\t" str << endl
	#define D_TRACE(str) \
		cout << __FILE__ ":" << __LINE__ << "\t" << __FUNCTION__ str << endl
#else
	#define D_PRINT(str)
	#define D_TRACE(str)
#endif
