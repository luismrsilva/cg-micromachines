/*
 * OrthogonalCamera.hpp
 *
 * */

#ifndef __ORTOGONAL_CAMERA_H
#define __ORTOGONAL_CAMERA_H

#include "Camera.hpp"

class OrthogonalCamera : Camera {
	public:
		void update();
		void computeProjectionMatrix();
		void computeVisualizationMatrix();
		OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
		~OrthogonalCamera();
	private:
		double _left;
		double _right;
		double _bottom;
		double _top;
};


#endif //__ORTOGONAL_CAMERA_H
