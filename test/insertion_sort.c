#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct student
{
    int roll_no;
    int marks;
    char name[100];
};
int z = 0 ;
void assign(struct student * f ,int first,int last){
    f[first].marks = f[last].marks;
    f[first].roll_no = f[last].roll_no;
    strcpy(f[first].name,f[last].name);
}
    // function to print the elements of the array
void display(struct student * arr, int size) {
  for(int i=0;i<size;i++){
       printf("student name: %s\n", arr[i].name);
       printf(" students roll no: %d\n", arr[i].roll_no);
       printf("students marks: %d\n", arr[i].marks);
   }
  printf("\n");
}
// function to sort the elements of the array
void insertionSort(struct student * arr, int n) {
  for (int i = 1; i < n; i++) {
    int tmp = arr[i].roll_no;
    int j = i - 1;


    while (tmp < arr[j].roll_no && j >= 0) {
      assign(arr,j + 1,j);
      z++;
      --j;
    }
    assign(arr,j+1,i);
    z++;
  }
}
// main function or driver function
 int main() {
   int i, n;
   printf("How many students are u going to enter?: ");
   scanf("%d",&n);
   struct student arr[n];
//    printf("Enter %d student data: ", n);
   for(i=0;i<n;i++){
       printf("Enter %d students roll no: ", i+1);
       scanf("%d",&arr[i].roll_no);
       printf("Enter %d student name: ", i+1);
       scanf("%s",&arr[i].name);
       printf("Enter %d students total_marks: ", i+1);
       scanf("%d",&arr[i].marks);
    }

  printf("Elements before sorting:\n");
  display(arr, n);
  insertionSort(arr, n);
  printf("Elements after sorting:\n");
  display(arr, n);
  printf("number of swaps performed are %d\n",z);
}
