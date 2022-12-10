#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int roll_no;
    int total_marks;
    char name[100];
};
int n = 0 ;
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
}
void quicksort(struct student * f ,int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=f[first].roll_no;
      i=first;
      j=last;
      while(i<j){
         while(f[i].roll_no<=pivot&&i<last){
             i++;
        }
         while(f[j].roll_no>pivot){
             j--;
        }
         if(i<j){
             swap(f,i,j);
             n++;
         }
      }
      swap(f,j,first);
      n++;
      quicksort(f,first,j-1);
      quicksort(f,j+1,last);
   }
}
int main(){
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
   quicksort(arr,0,count-1);
   printf("Order of Sorted elements: \n");
   for(i=0;i<count;i++){
       printf("student's name: %s\n", arr[i].name);
       printf(" student's roll no: %d\n", arr[i].roll_no);
       printf("student's total_marks: %d\n", arr[i].total_marks);
   }
   printf("number of swaps performed are %d\n",n);
   return 0;
}
