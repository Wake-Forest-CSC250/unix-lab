/* a rudimentary storage allocator. There are two routines. 
 * The first, alloc(n), returns a pointer to n consecutive character positions, 
 * which can be used by the caller of alloc for storing characters. 
 * The second, afree(p), releases the storage thus acquired so it can be reused later. 
 * The routines are "rudimentary" because the calls to afree must be made 
 * in the opposite order to the calls made on alloc. 
 * That is, the storage managed by alloc and afree is a stack (last-in, first-out).
 */
#define ALLOCSIZE 10000                             /* size of available space */

/* Our implementation has alloc hand out pieces of a large character array 
 * that we will call allocbuf. This array is private to alloc and afree. 
 * Since they deal in pointers, not array indices, no other routine need know 
 * the name of the array, which can be declared static in the source file (this one)
 * containing alloc and afree, and thus be invisible outside it.
 */
static char allocbuf[ALLOCSIZE];                    /* storage for alloc */
/* The other information needed is how much of allocbuf has been used. 
 * We use a pointer, called allocp, that points to the next free element.
 */
/* This could also have been written as:
 * static char *allocp = &allocbuf[0];
 * since the array name is the address of the zeroth element.
 */
static char *allocp = allocbuf;                     /* next free position */

/* return pointer to n characters 
 * When alloc is asked for n characters, it checks to see if there is enough room 
 * left in allocbuf. If so, alloc returns the current value of allocp 
 * (i.e., the beginning of the free block), then increments it by n 
 * to point to the next free area. If there is no room, alloc returns zero. 
 * 
 * Before call to alloc:
 *           --------------------------------------------------------------------
 * allocbuf: |     |  |     |         |                                         |
 *           --------------------------------------------------------------------
 *           <-          in use      -><-                  free                ->
 *                                     ^
 *                                   allocp
 * After call to alloc:
 *           --------------------------------------------------------------------
 * allocbuf: |     |  |     |         |                 |                       |
 *           --------------------------------------------------------------------
 *           <-                   in use               -><-        free        ->
 *                                                       ^
 *                                                     allocp
 * */
char *alloc(int n)
{
    /* checks if there's enough room to satisfy a request for n characters. 
     * If there is, the new value of allocp would be at most one beyond the end of allocbuf.
     */
    if (allocbuf + ALLOCSIZE - allocp >= n) {       /* it fits */
        allocp += n;
        return allocp - n;                          /* old p */
    } else                                          /* not enough room */
        /* It is safe to return zero because C guarantees
         * that zero is never a valid address for data.
         */
        return 0;
}

/* free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
