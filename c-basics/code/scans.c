#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double sum, v;
    int day, month, year;
    int scanned;
    char monthname[20];
    char* line;
    size_t linesize;

    /* Literal characters can appear in the scanf format string; 
     * but they must match the same characters in the input. 
     * So we could read dates of the form mm/dd/yy 
     * with the scanf statement.
     */
    scanf("%d/%d/%d", &month, &day, &year);

    /* a simple calculator */
    sum = 0;
    while (scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);

    /* Suppose we want to read input lines 
     * that contain dates of the form
     * September 23 2023
     */
    scanned = scanf("%s %d %d", monthname, &day, &year);
    printf("%d input scanned\n", scanned);

    /* Good to Know: */
    /* There is also a function sscanf that 
     * reads from a string instead of the standard input: 
     * int sscanf(char *string, char *format, arg1, arg2, ...)
     */
    /* To read input whose format is not fixed, 
     * it is often best to read a line at a time, 
     * then pick it apart with scanf
     */
    /* WARNING: The following example contains materials
     *          that have not been covered in this course.
     */
    linesize = 32;
    line = (char *)malloc(linesize * sizeof(char));
    if(line == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }
    getline(&line, &linesize, stdin);
    while (getline(&line, &linesize, stdin) > 0) {
        if (sscanf(line, "%s %d %d", monthname, &day, &year) == 3)
            printf("valid: %s\n", line);    /* September 23 2023 form */
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);    /* mm/dd/yy form */
        else
            printf("invalid: %s\n", line);  /* invalid form */
    }

    return 0;
}
