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
		void setCenter(const Vector3 &center);
		Vector3* getCenter();
		Vector3* getUp();
		void setUp(const Vector3 &up);
	private:
		double _fovy;
		double _aspect;
		Vector3 _center;
		Vector3 _up;
};


#endif //__PERSPECTIVE_CAMERA_H
