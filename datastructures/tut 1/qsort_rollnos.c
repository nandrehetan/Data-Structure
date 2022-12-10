#include<stdio.h>
#include <string.h>
struct student
{
    int roll_nos;
    int marks;
    char name[50];
};

void swap(struct student * student_array ,int x,int y){
    int temp;
    char tempchar[50];
    temp = student_array[x].marks;
    student_array[x].marks = student_array[y].marks;
    student_array[y].marks = temp;
    temp = student_array[x].roll_nos;
    student_array[x].roll_nos = student_array[y].roll_nos;
    student_array[y].roll_nos = temp;
    strcpy(tempchar,student_array[x].name);
    strcpy(student_array[x].name,student_array[y].name);
    strcpy(student_array[y].name,tempchar);
}
void quicksort(struct student * student_array ,int x,int y){
   int i, j, pivot, temp;
   if(x<y){
      pivot=student_array[x].marks;
      i=x;
      j=y;
      while(i<j){
         while(student_array[i].marks<=pivot&&i<y){
             i++;
        }
         while(student_array[j].marks>pivot){
             j--;
        }
         if(i<j){
             swap(student_array,i,j);
         }
      }
      swap(student_array,j,x);
      quicksort(student_array,x,j-1);
      quicksort(student_array,j+1,y);
   }
}
int main(){
   int i, x;
   printf("How many students are there in the class: ");
   scanf("%d",&x);
   struct student student_array[x];
//    printf("Enter %d student data: ", count);
   for(i=0;i<x;i++){
       printf("%d Student \nEnter name of student : ", i+1);
       scanf("%s",&student_array[i].name);
       printf("Enter students marks: ", i);
       scanf("%d",&student_array[i].marks);

    }
   quicksort(student_array,0,x-1);
   for(i=0;i<x;i++){
       student_array[i].roll_nos = x-i;
}
   for(i=x-1;i>=0;i--){
      printf("%s 's roll no: %d\n",student_array[i].name,student_array[i].roll_nos);
      printf("%s 's marks: %d\n", student_array[i].name,student_array[i].marks);
   }
   return 0;
}
