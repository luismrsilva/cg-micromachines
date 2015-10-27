/*
 * OrthogonalCamera.hpp
 *
 * */

#ifndef __ORTOGONAL_CAMERA_H
#define __ORTOGONAL_CAMERA_H

#include "Camera.hpp"
#include "GameManager.hpp"

class OrthogonalCamera : public Camera {
	public:
		void computeProjectionMatrix();
		void computeVisualizationMatrix();
		OrthogonalCamera(GameManager *gameManager, double left, double right, double bottom, double top, double near, double far);
		~OrthogonalCamera();
	private:
		double _left;
		double _right;
		double _bottom;
		double _top;
		GameManager *_gameManager;
};


#endif //__ORTOGONAL_CAMERA_H
