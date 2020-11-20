#ifndef QUADRATIC_H
#define QUADRATIC_H

namespace ch2_p8_Leo_H {
	class quadratic {
	public:
		quadratic(double ap = 0, double bp = 0, double cp = 0);
		void set_coeff(double ap, double bp, double cp);
		double case_one();
		double case_two();
		int count_real_roots();
		double get_a() const;
		double get_b() const;
		double get_c() const;
		double evaluate(double x);
	private:
		double a;
		double b;
		double c;
		double evaluation;
	};
	quadratic operator +(const quadratic& q1, const quadratic& q2);
	quadratic operator *(double r, const quadratic& q);
}



#endif
