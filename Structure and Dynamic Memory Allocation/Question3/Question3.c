#include <stdio.h>

struct distance
{
    int km;
    int m;
};

struct distance addDistance(struct distance d1, struct distance d2)
{
    struct distance result;

    result.km = d1.km + d2.km;
    result.m = d1.m + d2.m;

    if(result.m >= 1000)
    {
        result.km += result.m / 1000;
        result.m = result.m % 1000;
    }

    return result;
}

int main()
{
    struct distance d1, d2, d3;

    printf("Enter distance 1 (km m): ");
    scanf("%d %d",&d1.km,&d1.m);

    printf("Enter distance 2 (km m): ");
    scanf("%d %d",&d2.km,&d2.m);

    d3 = addDistance(d1,d2);

    printf("Total Distance = %d km %d m", d3.km, d3.m);

    return 0;
}
