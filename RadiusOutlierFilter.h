/**
* @file   RadiusOutlierFilter.h
* @Author Sude Cakmak
* @date   January, 2022
* @brief  to filter the point cloud
*/

#pragma once
#include "PointCloud.h"
#include <iostream>

using namespace std;

//! PointCloud class
/*!
   It is used to filter the point cloud.
*/
class RadiusOutlierFilter {
private:
	double radius;
public:
	//! A constructor. Gets the radius.
	RadiusOutlierFilter(double);
	//! A constructor. Gets the radius.
	RadiusOutlierFilter();
	/*! Retrieves point cloud with filter function
	and returns the filtered version.Each point in the cloud
	Each point is processed one by one. If there is no other point closer to the point than the radius value, this point
	removed from the point cloud.*/
	void filter(PointCloud&);
};