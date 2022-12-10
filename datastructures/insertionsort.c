#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct student
{
    int roll_no;
    int marks;
    char name[100];
};
int z = 0;
void assign(struct student * f ,int first,struct student * g,int last){
    f[first].marks = g[last].marks;
    f[first].roll_no = g[last].roll_no;
    strcpy(f[first].name,g[last].name);
    z++;
}
    // function to print the elements of the array
void display(struct student * arr, int n) {
    int i;
  for(i=0;i<n;i++){
       printf("student's name: %s\n", arr[i].name);
       printf(" student's roll no: %d\n", arr[i].roll_no);
       printf("student's total_marks: %d\n", arr[i].marks);
   }
}
// function to sort the elements of the array
void insertionSort(struct student * arr, int n) {
  for (int i = 1; i < n; i++) {
    struct student tmp[1];
    assign(tmp,0,arr,i);
    int j = i - 1;
    while (tmp[0].roll_no < arr[j].roll_no && j >= 0) {
        assign(arr,j+1,arr,j);
//       arr[j + 1] = arr[j];
      --j;
    }
    assign(arr,j+1,tmp,0);
//     arr[j + 1] = tmp;
  }
}
// main function or driver function
int main() {
  int i, n;
   printf("How many students are u going to enter?: ");
   scanf("%d",&n);
   struct student arr[n];
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
  printf("number of assignments performed are %d\n",z);
}
