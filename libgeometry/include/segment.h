/*
 * A segment data structure
 */

#include <stdbool.h>
#include "common.h"
#include "point.h"

/* A segment */
typedef struct {
    point_t *p1;
    point_t *p2;
} segment_t;

/*
 * Allocates a new segment in the heap.
 *
 * Parameters:
 *  - p1,p2 : the points of the segment
 *
 * Returns:
 *  - A pointer to the segment, or NULL if a segment
 *    cannot be allocated
 */
segment_t* segment_new(point_t *p1, point_t *p2);

/*
 * Initializes the points of a segment
 *
 * Parameters:
 *  - s: A segment. Must point to already allocated memory.
 *  - p1,p2: The points of the segment
 *
 * Returns:
 *  - 0 on success, 1 if an error occurs.
 */
int segment_init(segment_t *s, point_t *p1, point_t *p2);

/*
 * Frees the resources associated with a segment
 *
 * Parameters:
 *  - s: A segment. Must point to a segment allocated with segment_new
 *
 * Returns:
 *  - Always returns 0.
 */
int segment_free(segment_t *s);

/*
 * Determines whether two segments intersect
 *
 * Parameters:
 *  - p1, q1: Two points describing segment 1
 *  - p2, q2: Two points describing segment 2
 *
 * Returns:
 *  - true if they intersect, false otherwise
 */
bool segment_intersect(segment_t *seg1, segment_t *seg2);

