/*
 * SpotLightSource.hpp
 *
 * */

#ifndef __SPOTLIGHTSOURCE_H
#define __SPOTLIGHTSOURCE_H

#include "LightSource.hpp"

class SpotLightSource : public LightSource {
	public:
		SpotLightSource(GLenum num);
		~SpotLightSource();
		void setDirection(const Vector3 &dir);
		void setCutOff(GLfloat cut_off);
		void setExponent(GLfloat exp);
		void setDirection(float x, float y, float z);
		void draw();
	private:
		float _direction[4];
		GLfloat _cut_off;
		GLfloat _exponent;
};

#endif //__SPOTLIGHTSOURCE_H
