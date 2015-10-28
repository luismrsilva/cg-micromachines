/*
 * PerspectiveCamera.hpp
 *
 * */

#ifndef __PERSPECTIVE_CAMERA_H
#define __PERSPECTIVE_CAMERA_H

#include "Camera.hpp"

class PerspectiveCamera : public Camera {
	public:
		void computeProjectionMatrix();
		void computeVisualizationMatrix();
		PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
		~PerspectiveCamera();
		void setCenter(Vector3 center);
		void setUp(Vector3 up);
	private:
		double _fovy;
		double _aspect;
		Vector3 _center;
		Vector3 _up;
};


#endif //__PERSPECTIVE_CAMERA_H
