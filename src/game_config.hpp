/*
 * game_config.hpp
 * Game configuration constants
 *
 * */

#ifndef __GAME_CONFIG_INCLUDED
#define __GAME_CONFIG_INCLUDED

#include "myunits.hpp"



#define GAME_WINDOW_TITLE		"tg010/cg-micromachines"


// Time between updates in ms
#define GAME_TIMER_PERIOD	20



// Key accelaraton
#define GAME_CAR_ANGLE_ACCELARATION(v)	180*v
#define GAME_CAR_SPEED_ACCELARATION		1.
#define GAME_CAR_SPEED_DRAG(v)		(0.130 + 110*1.225/2. * 0.81 * cm(10)*cm(10) * v * v)

#define GAME_OBJECTS_SPEED_DRAG(v)	(0.4 + 110*1.225/2. * 0.81 * cm(10)*cm(10) * v * v)



// World map limits

#define GAME_WORLD_MAX 		1.6f
#define GAME_TABLE_LIMIT 	1.5f


// Subdivision settings
#define GAME_TABLE_TILE_DIVISION_COUNT	128





// Object sizes
#define BUTTER_SIZE_X	cm(10)
#define BUTTER_SIZE_Y	cm(5)
#define BUTTER_SIZE_Z	cm(6)

#define ORANGE_RADIUS	cm(6)


// Camera stuff
#define GAME_CAMERA_MOVEMENT_SMOTHENESS		0.85

// Car stuff

#define GAME_CAR_SCALE	cm(13)
#define CAR_FRONT		cm(3.25)


#endif //__GAME_CONFIG_INCLUDED
