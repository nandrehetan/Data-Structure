#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct faculty
{
    int ID;
    int subject_code;
    char name[100];
    char class[100];
};
int z = 0 ;
void assign(struct faculty * f ,int first,struct faculty * g,int last){
    f[first].subject_code = g[last].subject_code;
    f[first].ID = g[last].ID;
    strcpy(f[first].name,g[last].name);
    strcpy(f[first].class,g[last].class);
}

void merge(struct faculty * arr, int start, int mid, int end) {

  int len1 = mid - start + 1;
  int len2 = end - mid;

  struct faculty leftArr[len1], rightArr[len2];

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
    if (leftArr[i].ID <= rightArr[j].ID) {
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

void mergeSort(struct faculty * arr, int start, int end) {
  if (start < end) {

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void display(struct faculty * arr, int size) {
  for(int i=0;i<size;i++){
       printf("faculty name: %s\n", arr[i].name);
       printf("faculty class name: %s\n", arr[i].class);
       printf(" facultys id: %d\n", arr[i].ID);
       printf("facultys subject code: %d\n", arr[i].subject_code);
   }
  printf("\n");
}
int main() {
   int i, count;
   printf("How many facultys are u going to enter?: ");
   scanf("%d",&count);
   struct faculty arr[count];
  for(i=0;i<count;i++){
       printf("Enter faculty roll no: ");
       scanf("%d",&arr[i].ID);
       printf("Enter faculty name: ");
       scanf("%s",&arr[i].name);
       printf("Enter faculty's class name: ");
       scanf("%s",&arr[i].class);
       printf("Enter facultys subject code:");
       scanf("%d",&arr[i].subject_code);
    }
  printf("Original array\n");
  display(arr, count);

  mergeSort(arr, 0, count - 1);

  printf("Sorted array\n");
  display(arr, count);
  printf("number of comparisions performed are %d\n",z);
}
