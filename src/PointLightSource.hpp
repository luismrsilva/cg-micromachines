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
		void setAttenuation(GLfloat c, GLfloat l, GLfloat q);
		void draw();
	private:
		GLfloat _constantAttenuation;
		GLfloat _linearAttenuation;
		GLfloat _quadraticAttenuation;
};

#endif //__POINTLIGHTSOURCE_H
