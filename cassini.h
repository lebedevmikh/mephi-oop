#ifndef CASSINI_H
#define CASSINI_H


#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>

namespace cass
{
	class Point
	{
	public:
		double x;
		double y;
		Point(double x0 = 0, double y0 = 0): x(x0), y(y0) {};
	};


	class Cassini
	{
	private:
		Point F1;
		Point F2;
		Point center;

		double c;
		double a;


	public:
		Cassini(Point first, Point second, double arg);

		void set_F1(Point dot);
		void set_F2(Point dot);
		void set_a(int dist);


		Point get_F1() const{ return F1; }
		Point get_F2() const{ return F2; }
		Point get_center() const{ return center; }
		double get_c() const{ return c; }
		double get_a() const{ return a; }


		const double coordinate(double fi);
		const double curvature(double ro);

		const char* type();
		const char* cartesian(char* res);
	};


}


#endif 
