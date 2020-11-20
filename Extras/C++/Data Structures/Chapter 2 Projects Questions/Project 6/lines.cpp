#include "lines.h"
#include "math.h"

using namespace ch2_p5_Leo_H;
namespace ch2_p6_Leo_H {
	double lines::find_line_segment() {
		double radicand = 0;
		radicand = pow((po2.get_x() - po1.get_x()), 2)
			+ pow((po2.get_y() - po1.get_y()), 2)
			+ pow((po2.get_z() - po1.get_z()), 2);
		distance = sqrt(radicand);
		return distance;
	}
}