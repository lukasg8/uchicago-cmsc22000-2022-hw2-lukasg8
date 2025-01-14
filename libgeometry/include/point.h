/*
 * A two-dimensional point data structure
 */

#ifndef INCLUDE_POINT_H_
#define INCLUDE_POINT_H_

#include <stdbool.h>
#include "common.h"

/* A point in two-dimensional space */
typedef struct {
    double x;
    double y;
} point_t;


/*
 * Allocates a new point in the heap.
 *
 * Parameters:
 *  - x,y: The coordinates of the point
 *
 * Returns:
 *  - A pointer to the point, or NULL if a point
 *    cannot be allocated
 */
point_t* point_new(double x, double y);


/*
 * Initializes the coordinates of a point
 *
 * Parameters:
 *  - p: A point. Must point to already allocated memory.
 *  - x,y: The coordinates of the point
 *
 * Returns:
 *  - 0 on success, 1 if an error occurs.
 */
int point_init(point_t *p, double x, double y);


/*
 * Frees the resources associated with a point
 *
 * Parameters:
 *  - p: A point. Must point to a point allocated with point_new
 *
 * Returns:
 *  - Always returns 0.
 */
int point_free(point_t *p);


/*
 * Computes the distance between two points
 *
 * Parameters:
 *  - p1, p2: Points
 *
 * Returns:
 *  - The euclidean distance between p1 and p2
 */
double point_distance(point_t *p1, point_t *p2);

/* Finds the orientation of the ordered triplet (p, q, r).
 *
 * Parameters:
 *  - p, q, r: points
 *
 * Return:
 *  - 0 if p, q and r are colinear
 *  - 1 if p, q, and r are clockwise
 *  - 2 if p, q, and r are counterclockwise
 */
int point_orientation(point_t *p, point_t *q, point_t *r);

#endif /* INCLUDE_POINT_H_ */
