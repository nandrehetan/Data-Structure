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
void bubbleSort(struct student * arr , int size) {
  for (int j = 0; j < size - 1; ++j) {
    for (int i = 0; i < size - j - 1; ++i) {

      if (arr[i].roll_no > arr[i + 1].roll_no) {
          swap(arr,i,i+1);
//         int temp = arr[i];
//         arr[i] = arr[i + 1];
//         arr[i + 1] = temp;
      }
    }
  }
}

// void display(int arr[], int size) {
//   for (int i = 0; i < size; ++i) {
//     printf("%d  ", arr[i]);
//   }
//   printf("\n");
// }

int main() {
  int i, count;
   printf("How many students are u going to enter?: ");
   scanf("%d",&count);
   struct student arr[count];

   for(i=0;i<count;i++){
       printf("Enter %d students roll no: ", i);
       scanf("%d",&arr[i].roll_no);
       printf("Enter %d student name: ", i);
       scanf("%s",&arr[i].name);
       printf("Enter %d students marks: ", i);
       scanf("%d",&arr[i].marks);
    }
  bubbleSort(arr, count);
  printf("Order of Sorted elements: \n");
   for(i=0;i<count;i++){
       printf("student's name: %s\n", arr[i].name);
       printf(" student's roll no: %d\n", arr[i].roll_no);
       printf("student's marks: %d\n", arr[i].marks);
   }
}
