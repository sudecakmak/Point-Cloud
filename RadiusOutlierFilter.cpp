#include "RadiusOutlierFilter.h"

/*!
	\param r a double argument.
*/
RadiusOutlierFilter::RadiusOutlierFilter(double r) :
	radius(r)
{

}

RadiusOutlierFilter::RadiusOutlierFilter()
{
	double num;
	cout << "Enter radius: ";  cin >> num; radius = num;
}

/*!
	\param pc a PointCloud argument.
*/
void RadiusOutlierFilter::filter(PointCloud& pc) {

	vector<Point*> points = pc.givePoints();
	double distance, minDistance;

	for (int i = 0; i < points.size(); ++i) {

		Point* p1 = points[i];
		minDistance = INFINITY;

		for (int j = 0; j < points.size(); ++j) {

			if (j == i) { continue; }
			else {
				distance = p1->distance(*points[j]);

				if (distance < minDistance)
					minDistance = distance;
			}

		}

		if (radius < minDistance)
		{
			points.erase(points.begin() + i);
			i--;
		}

	}

	pc.setPoints(points);
};
