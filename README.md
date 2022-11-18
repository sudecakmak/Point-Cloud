# Point-Cloud
Point clouds obtained from two different cameras are converted to the base coordinate system and obtained as a single point cloud.

# Project Description

## Classes
- **Point Class:** This class holds the coordinates of 3D points in the point cloud. Equal operator (= =), checks if the two point is equal.

- **PointCloud Class:** Keeps its points in a dynamically created Point array. Array size is taken as a parameter in the constructor function when creating the object. + operator, both points returns a single point cloud with points owned by the cloud. = operator, a point cloud allows it to be copied to another point cloud.

- **Transform Class:** Creates the transformation matrix (transMatrix). Later transformed point by subjecting the point or point cloud received with the doTrans function to this transformation or returns the point cloud.

- **DepthCamera Class:** Reads points from the file (fileName) when the capture function is called and assigns these points to the created point cloud object. Returns the point cloud. This operation is a is a simulation. Points are taken from a file rather than a camera.

- **RadiusOutlierFilter Class:** This filters the point cloud. Retrieves point cloud with filter function and returns the filtered version. The algorithm of this filtering process is as follows. Each point in the cloud each point is processed one by one. If there is no other point closer to the point than the radius value, this point removed from the point cloud.

- **PassThroughFilter Class:** This filters the point cloud. Retrieves point cloud with filter function and returns the filtered version. In this filtering process, at least one of the x, y and z values of the point outside the limits, this point is removed from the point cloud.

- **PointCloudRecorder Class:** This is used to save point clouds to file. save, when the function is called the file name with fileName is opened, the point cloud given as a parameter is points are saved in this file.

## How to transform points
![Screenshot 2022-11-18 011822](https://user-images.githubusercontent.com/102357822/202654908-2b15b2e5-1b82-4887-803f-621a8e372ba8.png)


# UML 
![Screenshot 2022-11-18 002141](https://user-images.githubusercontent.com/102357822/202562639-827016f5-5dca-4450-8da2-94ae2056d053.png)

# Algorithm

1. Retrieve point clouds from Camera-1 and Camera-2
2. Both point clouds filtered via the Radius Outlier Filter (radius: 25)
3. Both point clouds filtered via the PassThroughFilter 
(For Camera-1, xmin:0, xmax:400, ymin:0, ymax: 400, zmin: -45, zmax:45;
For camera-2, xmin:0, xmax: 500, ymin:0, ymax: 500, zmin: -45, zmax:45)
4. PassThroughFilter both point clouds filter 
(For Camera-1, xmin:0, xmax:400, ymin:0, ymax: 400, zmin: -45, zmax:45;
For camera-2, xmin:0, xmax: 500, ymin:0, ymax: 500, zmin: -45, zmax:45)
5. Both point clouds are base coordinates system using the Transform class.
(For Camera-1 (x, y, z): (100, 500, 50), (omega, beta, alpha):
(0, 0, -pi/2); For camera-2 (x, y, z): (550, 150,50), (omega, beta, alpha): (0, 0, pi/2)
6. A single point by summing both point clouds create the cloud.
7. Through PointCloudRecorder of point cloud save to file.

# Output Example

To visualize the point cloud in 3D, use [CloudCompare](https://www.danielgm.net/cc/)

![Screenshot 2022-11-18 012623](https://user-images.githubusercontent.com/102357822/202654603-a0ed8e35-4ce1-40b0-9739-a75e68d61795.png)

# Other Creators

- **[Hasan Yasen](https://github.com/ysnhasan1)**
- **[Metin Konuk](https://github.com/MetinKONUK)**


