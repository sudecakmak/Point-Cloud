#include<iostream>
#include "Transform.h"

using namespace std;

Transform::Transform() {};

/*!
 \param ang an array containing rotation angles
*/

void Transform::setRotation(double ang[3]) {
	double a = ang[0];
	double b = ang[1];
	double y = ang[2];

	rotationMatrix[0][0] = cos(a) * cos(b);
	rotationMatrix[0][1] = cos(a) * sin(b) * sin(y) - sin(a) * cos(y);
	rotationMatrix[0][2] = cos(a) * sin(b) * cos(y) + sin(a) * sin(y);

	rotationMatrix[1][0] = sin(a) * cos(b);
	rotationMatrix[1][1] = sin(a) * sin(b) * sin(y) + cos(a) * cos(y);
	rotationMatrix[1][2] = sin(a) * sin(b) * cos(y) - cos(a) * sin(y);

	rotationMatrix[2][0] = -sin(b);
	rotationMatrix[2][1] = cos(b) * sin(y);
	rotationMatrix[2][2] = cos(b) * cos(y);
};

/*!
 \param tr an array containing translation values
*/

void Transform::setTranslation(double tr[3]) {
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			transMatrix[i][j] = rotationMatrix[i][j];
		};
	};

	transMatrix[0][3] = tr[0];
	transMatrix[1][3] = tr[1];
	transMatrix[2][3] = tr[2];
};

/*!
 \param pc a Point object
 \return Transformed Point object
*/

Point Transform::doTransform(Point p) {

	double P1[4] = { p.x, p.y, p.z, 1 };
	double P2[4] = { 0, 0, 0, 1 };

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			P2[i] += this->transMatrix[i][j] * P1[j];

	return Point(P2[0], P2[1], P2[2]);
};

/*!
 \param pc a PointCloud object
 \return Transformed PointCloud object
*/

PointCloud Transform::doTransform(PointCloud pc) {

	vector<Point*> points = pc.givePoints();
	PointCloud rpc = PointCloud(0);

	for (int f = 0; f < points.size(); ++f) {
		Point* p = points[f];
		double P1[4] = { p->x, p->y, p->z, 1 };
		double P2[4] = { 0, 0, 0, 1 };
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				P2[i] += this->transMatrix[i][j] * P1[j];
		Point* rp = new Point(P2[0], P2[1], P2[2]);
		rpc.addPoint(rp);
	}

	return rpc;
};