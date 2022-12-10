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
void assign(struct student * f ,int first,struct student * g,int last){
    f[first].marks = g[last].marks;
    f[first].roll_no = g[last].roll_no;
    strcpy(f[first].name,g[last].name);
}

void merge(struct student * arr, int start, int mid, int end) {

  int len1 = mid - start + 1;
  int len2 = end - mid;

  struct student leftArr[len1], rightArr[len2];

  for (int i = 0; i < len1; i++){
    assign(leftArr, i, arr,start + i);
    z++;
  }
  for (int j = 0; j < len2; j++){
    assign(rightArr,j ,arr,mid + 1 + j);
    z++;
  }
  int i, j, k;
  i = 0;
  j = 0;
  k = start;

  while (i < len1 && j < len2) {
    if (leftArr[i].roll_no <= rightArr[j].roll_no) {
      assign(arr,k,leftArr,i);
      i++;
      z++;
    } else {
      assign(arr,k,rightArr,j);
      j++;
      z++;
    }
    k++;
  }

  while (i < len1) {
    assign (arr,k,leftArr,i);
    i++;
    k++;
    z++;
  }

  while (j < len2) {
    assign(arr,k,rightArr,j);
    j++;
    k++;
    z++;
  }
}

void mergeSort(struct student * arr, int start, int end) {
  if (start < end) {

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void display(struct student * arr, int size) {
  for(int i=0;i<size;i++){
       printf("student name: %s\n", arr[i].name);
       printf(" students roll no: %d\n", arr[i].roll_no);
       printf("students marks: %d\n", arr[i].marks);
   }
  printf("\n");
}
int main() {
   int i, count;
   printf("How many students are u going to enter?: ");
   scanf("%d",&count);
   struct student arr[count];
  for(i=0;i<count;i++){
       printf("Enter student roll no: ");
       scanf("%d",&arr[i].roll_no);
       printf("Enter student name: ");
       scanf("%s",&arr[i].name);
       printf("Enter students marks: ");
       scanf("%d",&arr[i].marks);
    }
  printf("Original array\n");
  display(arr, count);

  mergeSort(arr, 0, count - 1);

  printf("Sorted array\n");
  display(arr, count);
  printf("number of comparisions performed are %d\n",z);
}
