#include <stdio.h>


struct student
{
    int num_eyes;
    int num_legs;
};
void print_students(struct student * f, int n) //See above
{
    int i;
    for(i=0; i < n; i++)
    {
        printf("Num eyes  : %d\n", f[i].num_eyes);
        printf("Num legs  : %d\n", f[i].num_legs);
    }
    for(i=3; i >= 0; i--)
    {
        f[i+1].num_eyes = f[i].num_eyes;
        f[i+1].num_legs = f[i].num_legs;
    }

}
int main ()
{
    struct student students_array[4];

    students_array[0].num_eyes = 1;
    students_array[1].num_eyes = 2;
    students_array[2].num_eyes = 3;
    students_array[0].num_legs = 2;
    students_array[1].num_legs = 4;
    students_array[2].num_legs = 6;
//     students_array[0].num_legs = 2;
    print_students(students_array, 3);
    print_students(students_array, 4);

}
