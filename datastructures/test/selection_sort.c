#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct student
{
    int roll_no;
    int marks;
    char name[100];
};

void swap(struct student * f ,int first,int last){
    int temp;
    char tempchr[100];
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

//selection sort function
void selectionSort(struct student * arr, int n) {
  for (int j = 0; j< n - 1; j++) {
    int min = j;
    for (int i = j + 1; i < n; i++) {

      if (arr[i].roll_no < arr[min].roll_no)
        min = i;
    }

    swap(arr,min,j);
  }
}

void display(struct student * arr, int size) {
  for(i=count;i>=0;i--){
       printf("student's name: %s\n", arr[i].name);
       printf(" student's roll no: %d\n", arr[i].roll_no);
       printf("student's marks: %d\n", arr[i].marks);
   }
  printf("\n");
}

int main() {
  int i, n;
   printf("How many students are u going to enter?: ");
   scanf("%d",&n);
   struct student arr[n];
//    printf("Enter %d student data: ", n);
   for(i=0;i<count;i++){
       printf("Enter %d students roll no: ", i);
       scanf("%d",&arr[i].roll_no);
       printf("Enter %d student name: ", i);
       scanf("%s",&arr[i].name);
       printf("Enter %d students marks: ", i);
       scanf("%d",&arr[i].marks);
    }

  printf("Elements before sorting: \n");
  selectionSort(arr, n);
  printf("Elements after sorting:\n");
  display(arr, n);
}
