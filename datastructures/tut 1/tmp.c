#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int roll_no;
    int marks;
    char name[10];
};

void swap(struct student * f ,int first,int last){
    int temp;
    char tempchr[10];
    temp = f[first].marks;
    f[first].marks = f[last].marks;
    f[last].marks = temp;
    temp = f[first].roll_no;
    f[first].roll_no = f[last].roll_no;
    f[last].roll_no = temp;
    strcpy(tempchr,f[first].name);
    strcpy(f[first].name,f[last].name);
    strcpy(f[last].name,tempchr);
}
void quicksort(struct student * f ,int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=f[first].marks;
      i=first;
      j=last;
      while(i<j){
         while(f[i].marks<=pivot&&i<last){
             i++;
        }
         while(f[j].marks>pivot){
             j--;
        }
         if(i<j){
             swap(f,i,j);
//             temp=f[i].marks;
//             f[i].marks=f[j].marks;
//             f[j].marks=temp;
         }
      }
      swap(f,j,first);
//       temp=number[pivot];
//       number[pivot]=number[j];
//       number[j]=temp;
      quicksort(f,first,j-1);
      quicksort(f,j+1,last);
   }
}
int main(){
   int i, count;
   printf("How many students are u going to enter?: ");
   scanf("%d",&count);
   struct student arr[count];
//    printf("Enter %d student data: ", count);
   for(i=0;i<count;i++){
       printf("Enter %d student name: ", i);
       scanf("%s",&arr[i].name);
       printf("Enter %d students marks: ", i);
       scanf("%d",&arr[i].marks);

    }
   quicksort(arr,0,count-1);
   for(i=0;i<count;i++){
       arr[i].roll_no = count-i;
}
   for(i=count;i>=0;i--){
       printf(" students roll no: %d\n", arr[i].roll_no);
       printf("students marks: %d\n", arr[i].marks);
       printf("student name: %s\n", arr[i].name);

   }
   return 0;
}
