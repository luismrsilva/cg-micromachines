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
		Vector3(double mod, double angleXY_deg);
		~Vector3();
		double getX() const;
		double getY() const;
		double getZ() const;
		void set(double x, double y, double z);
		Vector3 operator=(const Vector3 &vec);
		Vector3 operator*(double num) const;
		Vector3 operator+(const Vector3 &vec) const;
		Vector3 operator-(const Vector3 &vec) const;
		Vector3 rotateZ(double deg);
		double getXYModulus() const;
		double getXYAngle() const;
		Vector3 increaseMod(double mod_inc);
		void print() const;
		void println() const;
};

#endif
