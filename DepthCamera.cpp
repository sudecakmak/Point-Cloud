#include "DepthCamera.h"
DepthCamera::DepthCamera() {

};

/*!
	\return Acquired pointcloud object
*/
PointCloud DepthCamera::capture() {

	cout << "Enter the file name: ";
	getline(cin, file_name);

	ifstream file(file_name);

	if (!file.is_open())
		return 0;
	int n = 0;
	double x, y, z;
	PointCloud pointcloud(0);
	while (!file.eof()) {
		file >> x >> y >> z;
		Point* point = new Point(x, y, z);
		pointcloud.addPoint(point);
		n++;
	}
	pointcloud.setpn(n);
	file.close();
	return pointcloud;
};
