#include <stdio.h>
#include <math.h>

struct point
{
    int x;
    int y;
};

int main()
{
    struct point p1, p2;
    float distance;

    printf("Enter x and y for point 1: ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter x and y for point 2: ");
    scanf("%d %d", &p2.x, &p2.y);

    distance = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));

    printf("Distance = %.2f", distance);

    return 0;
}
