/*
 * Vector3.hpp
 *
 * */

#ifndef __VECTOR3_H
#define __VECTOR3_H

class Vector3 {
	private:
		double _x;
		double _y;
		double _z;
	public:
		Vector3();
		Vector3(double x, double y, double z);
		~Vector3();
		double getX();
		double getY();
		double getZ();
		void set(double x, double y, double z);
		Vector3 operator=(const Vector3 vec);
		Vector3 operator*(double num);
		Vector3 operator+(const Vector3 vec);
		Vector3 operator-(const Vector3 vec);
};

#endif
