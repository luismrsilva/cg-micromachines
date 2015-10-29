/*
 * Box.hpp
 *
 * */

#ifndef __BOX_H
#define __BOX_H

#include "GameObject.hpp"
#include "Vector3.hpp"
#include <stdbool.h>

class Box : public GameObject{
	public:
		Box(double left, double right, double top, double bottom);
		Box(double width, double height, const Vector3 &center);
		~Box();
		void changeTo(double left, double right, double top, double bottom);
		void changeTo(double width, double height, const Vector3 &center);
		void draw() const;
		bool isIntersecting(const Box &box) const;
	private:
		double _left;
		double _right;
		double _top;
		double _bottom;
};

#endif //_BOX_H
