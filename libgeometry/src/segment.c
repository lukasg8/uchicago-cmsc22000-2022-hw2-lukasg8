/*
 * A segment data structure.
 *
 * See segment.h for function documentation.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "utils.h"
#include "segment.h"

/* See segment.h */
segment_t* segment_new(point_t *p1, point_t *p2)
{
    segment_t *s;
    int rc;

    s = malloc(sizeof(segment_t));

    if(s == NULL)
    {
        error("Could not allocate memory");
        return NULL;
    }

    rc = segment_init(s, p1, p2);
    if(rc != SUCCESS)
    {
        error("Could not initialize segment with ((%.2f, %.2f),(%.2f, %.2f))", p1->x, p1->y, p2->x, p2->y);
        return NULL;
    }

    return s;
}

/* See segment.h */
int segment_init(segment_t *s, point_t *p1, point_t *p2)
{
    assert(s != NULL);

    s->p1 = p1;
    s->p2 = p2;

    return SUCCESS;
}

/* See segment.h */
int segment_free(segment_t *s)
{
    assert(s != NULL);

    free(s);

    return SUCCESS;
}

/* Given three colinear points p, q, r, the function checks if
   point q lies on line segment 'pr' */
// bool on_segment(point_t *p, point_t *q, point_t *r)
bool on_segment(segment_t *pr, point_t *q)
{
    point_t *p = pr->p1;
    point_t *r = pr->p2;

    if (q->x == p->x && q->y == p->y)
        return false;

    if (q->x == r->x && q->y == r->y)
        return false;

    if (q->x <= max(p->x, r->x) && q->x >= min(p->x, r->x) &&
        q->y <= max(p->y, r->y) && q->y >= min(p->y, r->y))
       return true;

    return false;
}

/* See segment.h */
bool segment_intersect(segment_t *seg1, segment_t *seg2)
{
    point_t *p1 = seg1->p1;
    point_t *p2 = seg1->p2;
    point_t *q1 = seg2->p1;
    point_t *q2 = seg2->p2;
    
    // Find the four orientations needed for general and
    // special cases
    int o1 = point_orientation(p1, q1, p2);
    int o2 = point_orientation(p1, q1, q2);
    int o3 = point_orientation(p2, q2, p1);
    int o4 = point_orientation(p2, q2, q1);

    bool connected = (q1->x == p2->x && q1->y == p2->y);

    // General case
    if (o1 != o2 && o3 != o4 && !connected)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    segment_t *p1q1;
    p1q1->p1 = p1;
    p1q1->p2 = q1;
    if (o1 == 0 && on_segment(p1q1, p2)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && on_segment(p1q1, q2)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    segment_t *p2q2;
    p2q2->p1 = p2;
    p2q2->p2 = q2;
    if (o3 == 0 && on_segment(p2q2, p1)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && on_segment(p2q2, q1)) return true;

    return false; // Doesn't fall in any of the above cases

}

