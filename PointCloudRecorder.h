/**
* @file   PointCloudRecorder.h
* @Author Sude Cakmak
* @date   January, 2022
* @brief  for save PointCloud
*/

#pragma once
#include "PointCloud.h"
#include <string>
#include <fstream>

using namespace std;

//! PointCloudRecorder class
/*!
   It is used to save point clouds to file.
*/
class PointCloudRecorder {
private:
	string fileName;
	ofstream file;
public:
	//! A constructor. Opens the file. 
	PointCloudRecorder();

	/*! When the function is called, the file named with fileName is opened, the point cloud given as a parameter is
	points are saved in this file. */
	void save(vector<Point*>&);
};