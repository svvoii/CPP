#include "../includes/Point.hpp"
/*
** BSP stands for Binary Space Partitioning.
** BSP is a method for recursively subdividing a space into convex sets
** by hyperplanes. This subdivision gives rise to a representation of the
** space in the form of a binary tree, known as a BSP tree.
**
** In the context of 2D space (like game map), BSP is used to divide the
** the space into individual areas. 
** 
** In this exercise, we are given three points which form a triangle,
** `a`, `b`, and `c`. We are also given a point `point` which we need to
** check if it is inside the triangle or not.
** 
** We use `Baricentric coordinate system` to determine if the `point` is
** inside the triangle or not.
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	float	vectorCAx = c.getX().toFloat() - a.getX().toFloat();
	float	vectorCAy = c.getY().toFloat() - a.getY().toFloat();
	float	vectorBAx = b.getX().toFloat() - a.getX().toFloat();
	float	vectorBAy = b.getY().toFloat() - a.getY().toFloat();
	float	vectorPAx = point.getX().toFloat() - a.getX().toFloat();
	float	vectorPAy = point.getY().toFloat() - a.getY().toFloat();

	float	dotCAxy = vectorCAx * vectorCAx + vectorCAy * vectorCAy;
	float	dotCAxyBAxy = vectorCAx * vectorBAx + vectorCAy * vectorBAy;
	float	dotCAxyPAxy = vectorCAx * vectorPAx + vectorCAy * vectorPAy;
	float	dotBAxy = vectorBAx * vectorBAx + vectorBAy * vectorBAy;
	float	dotBAxyPAxy = vectorBAx * vectorPAx + vectorBAy * vectorPAy;

	float	invDenom = 1 / (dotCAxy * dotBAxy - dotCAxyBAxy * dotCAxyBAxy);
	float	u = (dotBAxy * dotCAxyPAxy - dotCAxyBAxy * dotBAxyPAxy) * invDenom;
	float	v = (dotCAxy * dotBAxyPAxy - dotCAxyBAxy * dotCAxyPAxy) * invDenom;

	return (u >= 0) && (v >= 0) && (u + v < 1);
}

/*
** The approach above is called the 'Barycentric coordinate system'.
** It uses geometrical algorithm to determine if a 'point' is inside
** a triangle `abc` or not.
** 
** First we calculate the vectors from point `a` to points `b`, `c`, and `p`.
** This is done by substracting the `x` and `y` coordinates of point `a`
** from the `x` and `y` coordinates of points `b`, `c`, and `point`.
**
** Then we calculate the dot product of the vectors. The dot product is
** a scalar value that gives information about the magnitudes of the
** vectors and the angle between them.
** It is calculated by multiplying the corresponding components of the
** vectors and then adding the results.
**
** Then we calculate the inverse of the denominator of the 'Baricentric'
** coordinates. This is done to avoid division operations later, which
** are more computationally expensive.
**
** Then we calculate the 'Baricentric' coordinates `u` and `v` for the
** `point`. These coordinates represent the weights of the vectors
** `CA` and `BA` that make up the vector `PA`.
** If both `u` and `v` are between 0 and 1, and their sum is less than 1,
** then the `point` is inside the triangle `abc`.
**
** The formula for calculating the 'Baricentric' coordinates is:
** u = (dotBAxy * dotCAxyPAxy - dotCAxyBAxy * dotBAxyPAxy) * invDenom;
** v = (dotCAxy * dotBAxyPAxy - dotCAxyBAxy * dotCAxyPAxy) * invDenom;
** 
** `invDenom` is the inverse of the denominator of the 'Baricentric' coordinates. 
*/
