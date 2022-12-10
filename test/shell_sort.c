#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int roll_no;
    int total_marks;
    char name[100];
};
int z = 0 ;
void swap(struct student * f ,int first,int last){
    int temp;
    char tempchr[100];
    temp = f[first].total_marks;
    f[first].total_marks = f[last].total_marks;
    f[last].total_marks = temp;
    temp = f[first].roll_no;
    f[first].roll_no = f[last].roll_no;
    f[last].roll_no = temp;
    strcpy(tempchr,f[first].name);
    strcpy(f[first].name,f[last].name);
    strcpy(f[last].name,tempchr);
    z++;
}
void shellsort(struct student * arr, int num)
{
    int i, j, k;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i].roll_no >= arr[k].roll_no)
                    break;
                else
                {
                    swap(arr,k,k+1);
//                     tmp = arr[k];
//                     arr[k] = arr[k+i];
//                     arr[k+i] = tmp;
                }
            }
        }
    }
}
int main()
{
    int i, count;
   printf("How many students are u going to enter?: ");
   scanf("%d",&count);
   struct student arr[count];
   for(i=0;i<count;i++){
       printf("Enter %d students roll no: ", i+1);
       scanf("%d",&arr[i].roll_no);
       printf("Enter %d student name: ", i+1);
       scanf("%s",&arr[i].name);
       printf("Enter %d students total_marks: ", i+1);
       scanf("%d",&arr[i].total_marks);
    }
    shellsort(arr, count);
    printf("Order of Sorted elements: \n");
   for(i=0;i<count;i++){
       printf("student's name: %s\n", arr[i].name);
       printf(" student's roll no: %d\n", arr[i].roll_no);
       printf("student's total_marks: %d\n", arr[i].total_marks);
   }
   printf("number of swaps performed are %d\n",z);
   return 0;
}
