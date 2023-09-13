#include <stdio.h>
#include <math.h>

/* This is a structure declaration. It is not followed 
 * by a list of variables, so it reserves no storage;
 * it merely describes a template or shape of a structure. 
 * If the declaration is tagged, however, the tag can
 * be used later in definitions of instances of the structure.
 */
struct point {
        int x;
        int y;
};

/* Structures can be nested. */
struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int, int);
struct point addpoint(struct point, struct point);
int ptinrect(struct point, struct rect);

int main(void)
{
    double distance;
    /* Given the declaration of point above,
     * we can defines a variable pt which is 
     * a structure of type struct point.
     */
    struct point pt, pt2;
    /* We can also initialize a struct by 
    * following its definition with a list
    * of initializers, each a constant expression,
    * for the members.
    */
    struct point maxpt = {300, 300};
    struct rect screen;
    /* If a large structure is to be passed to a function, 
     * it is generally more efficient to pass a pointer
     * than to copy the whole structure.
     */
    struct point *pp;

    /* The structure member operator ``.'' 
     * connects the structure name and the member name.
     */
    printf("maxpt location: (%d,%d)\n", maxpt.x, maxpt.y);

    /* to compute the distance from the origin (0,0) to maxpt */
    distance = sqrt((double)maxpt.x * maxpt.x + (double)maxpt.y * maxpt.y);
    printf("maxpt distance from (0,0): %.2f\n", distance);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = maxpt;
    screen.pt2.x = 350;
    screen.pt2.y = 350;
    /* maxpt's member values are *copied* to screen's pt2,
     * so changing pt2's member values does not affect maxpt
     */
    printf("maxpt location: (%d,%d)\n", maxpt.x, maxpt.y);
    pt = makepoint((screen.pt1.x + screen.pt2.x)/2,
                   (screen.pt1.y + screen.pt2.y)/2);
    
    printf("pt location: (%d,%d)\n", pt.x, pt.y);
    pt2 = addpoint(pt, makepoint(10, 10));
    /* pt's location does not change! */
    printf("pt location: (%d,%d)\n", pt.x, pt.y);
    printf("pt2 location: (%d,%d)\n", pt2.x, pt2.y);

    printf("pt2 is%sin screen.\n", ptinrect(pt2, screen)? " " : " not ");

    /* pp now points to the pt stucture */
    pp = &pt;
    /* The parentheses are necessary in (*pp).x because 
     * the precedence of the structure member operator . is higher than *.
     * In general, the structure operators . and ->, 
     * together with () for function calls and [] for subscripts, 
     * are at the top of the precedence hierarchy and thus bind very tightly.
     */
    printf("pt is (%d,%d)\n", (*pp).x, (*pp).y);
    /* Alternatively, we can use -> */
    printf("pt is (%d,%d)\n", pp->x, pp->y);

    return 0;
}

/* make a point from x and y components 
 * the function illustrate how you can pass components separately
 * Notice that there is no conflict between the argument name 
 * and the member with the same name; 
 * indeed the re-use of the names stresses the relationship.
 */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/* add two points 
 * both the arguments and the return value are structures. 
 * We incremented the components in p1 
 * rather than using an explicit temporary variable 
 * to emphasize that structure parameters are 
 * **passed by value** like any others.*/
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* return 1 if p in r, 0 if not 
 * we have adopted the convention that 
 * a rectangle includes its left and bottom sides but not its top and right sides.
 * We also assume that the rectangle is presented in a standard form 
 * where the pt1 coordinates are less than the pt2 coordinates.
 */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}
