/**
 * @file Point.h
 * @Author Metin KONUK
 * @date December 2021
 * @brief definitions of point class
 */
#pragma once
#include<vector>

 //! Point class
 /*!
	 Contains definitions of point class
 */
class Point {
public:
	double x, y, z;
public:
	//! A constructor. Takes the x, y, z values of the point.
	Point(double, double, double);

	//! An overload == operator
	/*! Checks if two points are same, Returns True if so, else False.
	*/
	bool operator==(const Point&);

	//! A function, calculates distance.
	/*! Calculates the distance between two points and returns the distance.
	*/
	const double distance(const Point&);
};