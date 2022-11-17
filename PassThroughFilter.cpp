#include <iostream>
#include "PassThroughFilter.h"

using namespace std;

/*!
	\param ux a double argument.
	\param lx a double argument.
	\param uy a double argument.
	\param ly a double argument.
	\param uz a double argument.
	\param lz a double argument.
*/
PassThroughFilter::PassThroughFilter(double ux, double lx, double uy, double ly, double uz, double lz)
	: upperLimitX(ux), upperLimitY(uy), upperLimitZ(uz),
	lowerLimitX(lx), lowerLimitY(ly), lowerLimitZ(lz)
{

};

PassThroughFilter::PassThroughFilter()
{
	double num;

	cout << "Enter upper x limit: ";  cin >> num;  upperLimitX = num;
	cout << "Enter upper y limit: ";  cin >> num;  upperLimitY = num;
	cout << "Enter upper z limit: ";  cin >> num;  upperLimitZ = num;

	cout << "Enter lower x limit: ";  cin >> num;  lowerLimitX = num;
	cout << "Enter lower y limit: ";  cin >> num;  lowerLimitY = num;
	cout << "Enter lower z limit: ";  cin >> num;  lowerLimitZ = num;
};

/*!
	\param pc a PointCloud argument.
*/
void PassThroughFilter::filter(PointCloud& pc) {

	vector<Point*> points = pc.givePoints();
	int i = 0;

	while (i < points.size()) {

		bool c1 = ((points[i]->x < lowerLimitX) || (points[i]->x > upperLimitX));

		bool c2 = ((points[i]->y < lowerLimitY) || (points[i]->y > upperLimitY));

		bool c3 = ((points[i]->z < lowerLimitZ) || (points[i]->z > upperLimitZ));

		if (c1 || c2 || c3) {
			points.erase(points.begin() + i);
			i--;
		}

		i++;
	}

	pc.setPoints(points);
};