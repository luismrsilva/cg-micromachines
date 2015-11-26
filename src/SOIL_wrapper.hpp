/**
 * SOIL_wrapper.hpp
 *
 * Allow compilation without libSOIL (-DNOSOIL)
 *
 * SOIL can be found at http://www.lonesock.net/soil.html
 */



#if defined(NOSOIL)
	#define SOIL_load_OGL_texture(a,b,c,d)	0
	#define SOIL_last_result()				"compiled without SOIL"


enum
{
	SOIL_FLAG_POWER_OF_TWO = 1,
	SOIL_FLAG_MIPMAPS = 2,
	SOIL_FLAG_TEXTURE_REPEATS = 4,
	SOIL_FLAG_MULTIPLY_ALPHA = 8,
	SOIL_FLAG_INVERT_Y = 16,
	SOIL_FLAG_COMPRESS_TO_DXT = 32,
	SOIL_FLAG_DDS_LOAD_DIRECT = 64,
	SOIL_FLAG_NTSC_SAFE_RGB = 128,
	SOIL_FLAG_CoCg_Y = 256,
	SOIL_FLAG_TEXTURE_RECTANGLE = 512
};

#else
	#include <SOIL/SOIL.h>
#endif
