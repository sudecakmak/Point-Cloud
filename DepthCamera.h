/**
 * @file DepthCamera.h
 * @Author Hasan YASEN
 * @date December 2021
 * @brief Contains definitions of DepthCamera class
 * Reads coordinates files
 *
*/
#pragma once
#include "PointCloud.h"
#include "Transform.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

//! DepthCamera class
/*!Scans well-formatted files containing points' x, y and z coordinates.Pushes them into a pointcloud object's points-list
*/
class DepthCamera  {
private:
	string file_name;
public:
	//! A constructor, no arguments.
	DepthCamera();
	//! A function, reads files.
	/*! Reads files provided by user, stores captured coordinates, creates a pointcloud object including points-list thanks to those coordinates.
	*/
	PointCloud capture();
	//! A function
	/*! get when the function is called
	The extracted points will be passed through the filterpipe and then transformed and returned.*/

};
