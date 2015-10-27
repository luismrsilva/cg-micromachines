/*
 * PerspectiveCamera.hpp
 *
 * */

#ifndef __PERSPECTIVE_CAMERA_H
#define __PERSPECTIVE_CAMERA_H

#include "Camera.hpp"

class PerspectiveCamera : public Camera {
	public:
		void update();
		void computeProjectionMatrix();
		void computeVisualizationMatrix();
		PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
		~PerspectiveCamera();
	private:
		double _fovy;
		double _aspect;
};


#endif //__PERSPECTIVE_CAMERA_H
