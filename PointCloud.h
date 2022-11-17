/**
 * @file PointCloud.h
 * @Author Hasan YASEN
 * @date December, 2021
 * @brief Definitions of PointCloud class
*/
#pragma once
#include "Point.h"

using namespace std;
//! PointCloud class
/*!
	Contains definitions of PointCloud class
*/
class PointCloud {
private:
	vector<Point*> points;
	int pointNumber;
public:
	//! Constructor, takes the size of pointcloud
	PointCloud(int);

	//! A function, adds point
	/*! Adds point to the points-list inside pointcloud class
	 */
	void addPoint(Point*);

	//! A function, returns points
	/*! Returns points-list inside pointcloud class
	 */
	vector<Point*>& givePoints();

	//! A function, sets pointNumber
	/*! Sets the pointNumber variable inside pointcloud class
	*/
	void setpn(int);

	//! A function, returns pointNumber
	/*! Returns the pointNumber variable's value inside pointcloud class
	 */
	int getpn();

	//! A function, sets points
	/*! Sets the points-list inside pointcloud class
	*/
	void setPoints(vector<Point*>);

	//! A function, prints points
	/*! Prints points which are inside pointcloud class to the console
	*/
	void Print_points(vector<Point*> p);

	PointCloud operator+(const PointCloud& pc);
};