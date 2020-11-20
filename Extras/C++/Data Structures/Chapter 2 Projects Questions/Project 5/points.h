#ifndef POINTS_H
#define POINTS_H
#include <iostream>

using namespace std;
namespace ch2_p5_Leo_H {
	class points {
	public:
		points(double a = 0, double b = 0, double c = 0);
		void shift_x(double n);
		void shift_y(double n);
		void shift_z(double n);
		double get_x() const;
		double get_y() const;
		double get_z() const;
		void rotate_along_x(double angle);
		void rotate_along_y(double angle);
		void rotate_along_z(double angle);
		
	private:
		double x;
		double y;
		double z;
	};
	ostream& operator <<(ostream& outs, const points& source);

}


#endif