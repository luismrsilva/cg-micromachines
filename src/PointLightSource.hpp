/*
 * PointightSource.hpp
 *
 * */

#ifndef __POINTLIGHTSOURCE_H
#define __POINTLIGHTSOURCE_H

#include "LightSource.hpp"

class PointLightSource : public LightSource {
	public:
		PointLightSource(GLenum num);
		~PointLightSource();
		void draw();
};

#endif //__POINTLIGHTSOURCE_H
