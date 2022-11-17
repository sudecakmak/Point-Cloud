#include <iostream>
#include <iomanip>
#include <vector>
#include "Point.h"
#include "PointCloud.h"
#include "PassThroughFilter.h"
#include "DepthCamera.h"
#include "RadiusOutlierFilter.h"
#include "PointCloudRecorder.h"
#include "Transform.h"

using namespace std;

int main() {

	DepthCamera dc;
	PointCloud pc(0);

	// Test for DepthCamera, camera1.txt
	// PointCloud1
	PointCloud pc1 = dc.capture();
	vector<Point*> pc1_points = pc1.givePoints();
	cout << "PointCloud1:" << endl;
	cout << "Point Size : " << pc1_points.size() << "\n\n\n";
	//pc1.Print_points(pc1_points); cout << "\n\n";


	// Test for DepthCamera, camera2.txt
	// PointCloud2
	PointCloud pc2 = dc.capture();
	vector<Point*> pc2_points = pc2.givePoints();
	cout << "PointCloud2:" << endl;
	cout << "Point Size : " << pc2_points.size() << endl;
	//pc2.Print_points(pc2_points); cout << "\n\n";


	// Test for RadiusOutlierFilter
	RadiusOutlierFilter rof1(25);
	rof1.filter(pc1);
	pc1_points = pc1.givePoints();
	cout << "\n\nRadiusOutlierFilter for PointCloud1:" << endl;
	cout << "Point Size : " << pc1_points.size() << endl;
	//pc1.Print_points(pc1_points); cout << "\n\n";

	RadiusOutlierFilter rof2(25);
	rof1.filter(pc2);
	pc2_points = pc2.givePoints();
	cout << "\n\nRadiusOutlierFilter for PointCloud2: " << endl;
	cout << "Point Size : " << pc2_points.size() << endl;
	//pc2.Print_points(pc2_points); cout << "\n\n";


	// Test for PassThroughFilter
	PassThroughFilter ptf1(400, 0, 400, 0, 45, -45);
	ptf1.filter(pc1);
	pc1_points = pc1.givePoints();
	cout << "\n\nPassThroughFilter for PointCloud1: " << endl;
	cout << "Point Size : " << pc1_points.size() << endl;
	//pc1.Print_points(pc1_points); cout << "\n\n";

	PassThroughFilter ptf2(500, 0, 500, 0, 45, -45);
	ptf2.filter(pc2);
	pc2_points = pc2.givePoints();
	cout << "\n\nPassThroughFilter for PointCloud2: " << endl;
	cout << "Point Size : " << pc2_points.size() << endl;
	//pc2.Print_points(pc2_points); cout << "\n\n";


	// Test for Transform
	Transform tf1;
	double angles1[3] = { -PI / 2, 0, 0 }; // alpha beta omega
	double trans1[3] = { 100, 500, 50 }; // x, y, z
	tf1.setRotation(angles1);
	tf1.setTranslation(trans1);
	pc1 = tf1.doTransform(pc1);

	Transform tf2;
	double angles2[3] = { PI / 2, 0, 0 }; // alpha beta omega
	double trans2[3] = { 550, 150, 50 }; // x, y, z
	tf2.setRotation(angles2);
	tf2.setTranslation(trans2);
	pc2 = tf2.doTransform(pc2);

	// Test for PointCloud
	// PointCloud
	pc = pc1 + pc2;
	cout << "\n\nPointCloud:" << endl;
	cout << "Point Size : " << pc.givePoints().size() << endl;
	//pc1.Print_points(pc);


	//Test for PointCloudRecorder
	PointCloudRecorder pcr;
	pcr.save(pc.givePoints());
}