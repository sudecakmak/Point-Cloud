#include "PointCloud.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*!
	\param pn an integer argument
*/
PointCloud::PointCloud(int pn)
	:pointNumber(pn)
{

};

/*!
	\param p a Point* p argument
*/
void PointCloud::addPoint(Point* p) {
	points.push_back(p);
};

/*!
	\return The points inside pointcloud object
*/
vector<Point*>& PointCloud::givePoints() {
	return points;
};

/*!
	\param n an integer argument
*/
void PointCloud::setpn(int n) {
	this->pointNumber = n;
}

/*!
	\return number of points inside pointcloud
*/
int PointCloud::getpn() {
	return this->pointNumber;
}

/*!
	\param p a vector<Point*> argument
*/
void PointCloud::setPoints(vector<Point*> p) {
	points = p;
}

/*!
	\param p a vector<Point*> argument
*/
void PointCloud::Print_points(vector<Point*> p) {

	for (int i = 0; i < p.size(); ++i) {
		cout << p[i]->x << setw(5) << p[i]->y << setw(5) << p[i]->z << endl;
	}
}

/*!
	\param p1 a PointCloud& argument
	\return the junction of two point clouds
*/
PointCloud PointCloud::operator+(const PointCloud& pc) {
	vector<Point*> ps1 = this->givePoints(), ps2 = pc.points;
	for (unsigned int i = 0; i < ps2.size(); ++i) {
		bool isin = false;
		for (unsigned int j = 0; j < ps1.size(); ++j)
			if (ps2[i]->x == ps1[j]->x && ps2[i]->y == ps1[j]->y && ps2[i]->z == ps1[j]->z)
				isin = true;
		if (isin == false)
			ps1.push_back(ps2[i]);
	}
	PointCloud result(ps1.size());
	result.setPoints(ps1);
	return result;
}
