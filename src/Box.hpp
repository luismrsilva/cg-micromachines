/*
 * Box.hpp
 *
 * */

#ifndef __BOX_H
#define __BOX_H

#include "GameObject.hpp"
#include "Vector3.hpp"

class Box : public GameObject{
	public:
		Box(double left, double right, double top, double bottom);
		Box(double width, double height, const Vector3 &center);
		~Box();
		void draw();
	private:
		double _left;
		double _right;
		double _top;
		double _bottom;
};

#endif //_BOX_H
