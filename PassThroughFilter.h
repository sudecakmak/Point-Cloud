#pragma once
/**
* @file   PassThroughFilter.h
* @Author Sude Cakmak
* @date   January, 2022
* @brief  to filter points
*/

#pragma once
#include "PointCloud.h"
#include <vector>

//! PassThroughFilter class
/*!
   It is used to filter points.
*/
class PassThroughFilter {
private:
	double upperLimitX, upperLimitY, upperLimitZ;
	double lowerLimitX, lowerLimitY, lowerLimitZ;
public:
	//! A constructor. 
	PassThroughFilter();
	//! A constructor.
	PassThroughFilter(double, double, double, double, double, double);
	/*!
	Retrieves the point cloud and returns the filtered version. In this filtering process, at least one of the
	x, y and z values of the point outside the limits, this point is removed from the point cloud.*/
	void filter(PointCloud&);
};