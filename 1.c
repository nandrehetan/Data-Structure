 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll_num;
    int marks;
    char name[50];
};
void print_students(struct student * f, int n) //See above
{
    int i;
    for(i=0; i < n; i++)
    {
        printf("Num eyes  : %d\n", f[i].roll_num);
        printf("Num legs  : %d\n", f[i].marks);
        printf("Num name  : %s\n\n", f[i].name);
    }
    for(i=3; i >= 0; i--)
    {
        f[i+1].roll_num = f[i].roll_num;
        f[i+1].marks = f[i].marks;
        f[i+1].name = f[i].name;
    }

}
int main ()
{
    struct student students_array[4];

    students_array[0].roll_num = 1;
    students_array[1].roll_num = 2;
    students_array[2].roll_num = 3;
    students_array[0].marks = 5;
    students_array[1].marks = 7;
    students_array[2].marks = 7;
    strcpy( students_array[1].name, "a Programming");
    strcpy( students_array[2].name, "b Programming");
     strcpy( students_array[2].name, "C Programming");
//     students_array[0].marks = 2;
    print_students(students_array, 3);
    print_students(students_array, 4);

}
