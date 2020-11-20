#include "Points.h"
#include <math.h>

using namespace std;
namespace ch2_p5_Leo_H
{
	points::points(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}

	void points::shift_x(double n)
	{
		x += n;
	}
	void points::shift_y(double n)
	{
		y += n;
	}
	void points::shift_z(double n)
	{
		z += n;
	}
	void points::rotate_along_x(double angle)
	{
		double new_y;
		double new_z;
		new_y = (y * cos(angle)) - (z * sin(angle));
		new_z = (y * sin(angle)) + (z * cos(angle));
		y = new_y;
		z = new_z;
	}
	void points::rotate_along_y(double angle)
	{
		double new_x = 0;
		double new_z = 0;
		new_x = (x * cos(angle)) + (z * sin(angle));
		new_z = (z * cos(angle)) - (x * sin(angle));
		x = new_x;
		z = new_z;
	}
	void points::rotate_along_z(double angle)
	{
		double new_x = 0;
		double new_y = 0;
		new_x = (x * cos(angle)) - (y * sin(angle));
		new_y = (x * sin(angle)) + (y * cos(angle));
		x = new_x;
		y = new_y;
	}
	double points::get_x() const
	{
		return x;
	}
	double points::get_y() const
	{
		return y;
	}
	double points::get_z() const
	{
		return z;
	}

	ostream& operator <<(ostream& outs, const points& source)
	{
		outs << source.get_x() << " " << source.get_y() << " " << source.get_z() << endl;
		return outs;
	}

}


