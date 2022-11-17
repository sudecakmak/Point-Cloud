#include "Point.h"
using namespace std;

Point::Point(double a = 0, double b = 0, double c = 0)
	:x(a), y(b), z(c)
{

};

/*!
	\param p a constant Point& argument
	\return boolean if the points are the same
*/
bool Point::operator==(const Point& p) {
	if (p.x == x && p.y == y && p.z == z)
		return true;
	return false;
};

/*!
	\param p a constant Point& argument
	\return the distance between 2 points
*/
const double Point::distance(const Point& p) {
	double distance = pow(this->x - p.x, 2) + pow(this->y - p.y, 2) + pow(this->z - p.z, 2);
	distance = sqrt(distance);
	return distance;
};