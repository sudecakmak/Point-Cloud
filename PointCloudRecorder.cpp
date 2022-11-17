#include "PointCloudRecorder.h"
#include <iomanip>

PointCloudRecorder::PointCloudRecorder() {

	fileName = "result.txt";
	file.open(fileName);
}

/*!
	\param points a vector argument.
*/
void PointCloudRecorder::save(vector<Point*> &points) {

	for (int i = 0; i < points.size(); ++i) {

		Point* p = points[i];
		file << setw(5);

		file << p->x;
		file << setw(5);

		file << p->y;
		file << setw(5);

		file << p->z;
		file << setw(5);

		file << endl;

	}

	file.close();
}