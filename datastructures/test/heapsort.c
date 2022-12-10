#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int id;
    int subject_code;
    char name[100];
    char class[20];
};
int z = 0;
void swap(struct student * f ,int first,int last){
    int temp;
    char tempchr[100];
    temp = f[first].subject_code;
    f[first].subject_code = f[last].subject_code;
    f[last].subject_code = temp;
    temp = f[first].id;
    f[first].id = f[last].id;
    f[last].id = temp;
    strcpy(tempchr,f[first].name);
    strcpy(f[first].name,f[last].name);
    strcpy(f[last].name,tempchr);
    strcpy(tempchr,f[first].class);
    strcpy(f[first].class,f[last].class);
    strcpy(f[last].class,tempchr);
    z++;
}

  void heapify(struct student * arr, int n, int i) {
    int max = i; //Initialize max as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    //If left child is greater than root
    if (leftChild < n && arr[leftChild].id > arr[max].id)
      max = leftChild;

    //If right child is greater than max
    if (rightChild < n && arr[rightChild].id > arr[max].id)
      max = rightChild;

    //If max is not root
    if (max != i) {
      swap(arr,i,max);
      //heapify the affected sub-tree recursively
      heapify(arr, n, max);
    }
  }

  //Main function to perform heap sort
  void heapSort(struct student * arr, int n) {
    //Rearrange array (building heap)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    //Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
      swap(arr,0,i); //Current root moved to the end

      heapify(arr, i, 0); //calling max heapify on the heap reduced
    }
  }


void display(struct student * arr, int n) {
    int i;
  for(i=0;i<n;i++){
       printf("student's name: %s\n", arr[i].name);
       printf(" student's roll no: %d\n", arr[i].id);
       printf("student's total_subject_code: %d\n", arr[i].subject_code);
   }
}


  int main() {
    int i, n;
   printf("How many students are u going to enter?: ");
   scanf("%d",&n);
   struct student arr[n];
//    printf("Enter %d student data: ", n);
   for(i=0;i<n;i++){
       printf("Enter %d students roll no: ", i);
       scanf("%d",&arr[i].id);
       printf("Enter %d student name: ", i);
       scanf("%s",&arr[i].name);
       printf("Enter %d student class: ", i);
       scanf("%s",&arr[i].class);
       printf("Enter %d students subject_code: ", i);
       scanf("%d",&arr[i].subject_code);
    }
    display(arr, n);
    heapSort(arr, n);

    printf("Sorted array:\n");
    display(arr, n);
    printf("number of swaps performed are %d\n",z);
  }
