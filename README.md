# Point-Cloud
Point clouds obtained from two different cameras are converted to the base coordinate system and obtained as a single point cloud.

# Project Description

## Classes
- **Point Class:** This class holds the coordinates of 3D points in the point cloud. Equal operator (= =), two checks if the point is equal.

- **PointCloud Class:** Keeps its points in a dynamically created Point array. of the directory its size is taken as a parameter in the constructor function when creating the object. + operator, both points Returns a single point cloud with points owned by the cloud. = operator, a point cloud allows it to be copied to another point cloud.

- **Transform Class:** The distance between the origins of two coordinate axes, as described in the Explanations section. (trans) and rotation angles (angles). Creates the transformation matrix (transMatrix). later Transformed point by subjecting the point or point cloud received with the doTrans function to this transformation. or returns the point cloud.

- **DepthCamera Class:** Reads points from the file named (fileName) when the capture function is called and assigns these points to the created point cloud object. Returns the point cloud. This operation is a is a simulation. Points are taken from a file rather than a camera.
