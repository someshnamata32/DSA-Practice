#include <stdio.h>

struct student
{
    char name[50];
    int roll;
    char branch[20];
    float cgpa;
};

int main()
{
    struct student s[5];
    int i, index = 0;
    float highest;

    for(i=0;i<5;i++)
    {
        printf("Enter details of student %d\n",i+1);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Roll: ");
        scanf("%d",&s[i].roll);

        printf("Branch: ");
        scanf(" %[^\n]", s[i].branch);

        printf("CGPA: ");
        scanf("%f",&s[i].cgpa);
    }

    highest = s[0].cgpa;

    for(i=1;i<5;i++)
    {
        if(s[i].cgpa > highest)
        {
            highest = s[i].cgpa;
            index = i;
        }
    }

    printf("\nStudent with highest CGPA\n");
    printf("Name: %s\n", s[index].name);
    printf("Roll: %d\n", s[index].roll);
    printf("Branch: %s\n", s[index].branch);
    printf("CGPA: %.2f\n", s[index].cgpa);

    return 0;
}
