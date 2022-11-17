/**
 * @file Transform.h
 * @Author Metin KONUK
 * @date December, 2021
 * @brief Applies linear algebric and geometric processes on the pointcloud object.
 * It has rotation matrix (3x3), transformation matrix (4x4), transformation values (arr[3]), angles (arr[3])
 * Rotation matrix, angles and transform values combine and create transformation matrix
 */
#pragma once
#include "PointCloud.h"
#include "Point.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647
 //! Transform class
 /*! It has two transformer functions. One takes Point and another takes PointCloud object as argument. They apply transform on given argument and return an object with the same type with the argument.
 */
class Transform {
private:
	double angles[3]; // alpha beta omega
	double trans[3]; // x, y, z
	double transMatrix[4][4]; // transformation matrix
	double rotationMatrix[3][3]; //rotation matrix
public:
	//! A constructor, no parameters
	Transform();

	//! A function, takes rotation angles as parameters
	/*! Creates rotation matrix
	 */
	void setRotation(double[]);

	//! A function, takes translation values as parameters
	/*! Creates translation matrix
	 */
	void setTranslation(double[]);

	//! A function, takes Point object as parameter
	/*! Transforms Point object and returns it
	 */
	Point doTransform(Point);

	//! A function, takes PointCloud Object as parameter
	/*! Transforms PointCloud object and returns it
	 */
	PointCloud doTransform(PointCloud);
};