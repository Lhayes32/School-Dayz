#include "quadratic.h"
#include <math.h>

namespace ch2_p8_Leo_H {
	quadratic::quadratic(double ap , double bp , double cp ) {
		a = ap;
		b = bp;
		c = cp;
		evaluation = 0;
	}
	void quadratic::set_coeff(double ap, double bp, double cp) {
		a = ap;
		b = bp; 
		c = cp;
	}
	double quadratic::case_one()
	{
		double calc = 0;
		if (count_real_roots() > 0) {
			if (a == 0 && b != 0)
				return -(c) / b;
			if ((a != 0) && (pow(b, 2) == (4 * a * c)))
				return -(b) / (2 * a);
			if (count_real_roots() == 2)
			{
				calc = -b - sqrt(pow(b, 2) - (4 * a * c));
				calc /= (2 * a);
				return calc;
			}
		}
		else
			return -1;
	}
	double quadratic::case_two()
	{
		double calc = 0;
		if (count_real_roots() > 0) {
			if (a == 0 && b != 0)
				return -(c) / b;
			if ((a != 0) && (pow(b, 2) == (4 * a * c)))
				return -(b) / (2 * a);
			if (count_real_roots() == 2)
			{
				calc = -b + sqrt(pow(b, 2) - (4 * a * c));
				calc /= (2 * a);
				return calc;
			}
		}
		else
			return -1;
	}
	int quadratic::count_real_roots() {
		if (a == 0 && b == 0 && c == 0)
			return 3;
		if (a == 0 && b == 0 && c != 0)
			return 0;
		if (a == 0 && b != 0)
			return 1;
		if ((a != 0) && (pow(b, 2) < (4 * a * c)))
			return 0;
		if ((a != 0) && (pow(b, 2) == (4 * a * c)))
			return 1;
		if ((a != 0) && (pow(b, 2) > (4 * a * c)))
			return 2;
	}
	double quadratic::get_a() const{
		return a;
	}
	double quadratic::get_b() const{
		return b;
	}
	double quadratic::get_c() const{
		return c;
	}
	
	double quadratic::evaluate(double x) {
		evaluation = (a * pow(x, 2.0)) + (b * x) + c;
		return evaluation;
	}
	quadratic operator +(const quadratic& q1, const quadratic& q2) {
		quadratic q3(q1.get_a() + q2.get_a(), q1.get_b() + q2.get_b(), q1.get_c() + q2.get_c());
		return q3;
	}
	quadratic operator *(double r, const quadratic& q) {
		quadratic q3(q.get_a() * r, q.get_b() * r, q.get_c() *r);
		return q3;
	}
}
