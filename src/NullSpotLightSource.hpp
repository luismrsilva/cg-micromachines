/*
 * NullSpotLightSource.hpp
 *
 * */

#ifndef __NULLSPOTLIGHTSOURCE_H
#define __NULLSPOTLIGHTSOURCE_H

#include "SpotLightSource.hpp"

#include <stdlib.h>
#include <GL/glut.h>
#include "Vector3.hpp"

class NullSpotLightSource : public SpotLightSource {
	public:
		NullSpotLightSource();
		virtual ~NullSpotLightSource();
		bool getState();
		bool setState(bool state);
		bool toggleState();
		GLenum getNum();
		void setPosition(const Vector3 &pos);
		void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void setPosition(float x, float y, float z);
		void setAttenuation(GLfloat c, GLfloat l, GLfloat q);
		void draw();
		void setDirection(const Vector3 &dir);
		void setCutOff(GLfloat cut_off);
		void setExponent(GLfloat exp);
		void setDirection(float x, float y, float z);

};

#endif //__NULLSPOTLIGHTSOURCE_H
