#include <stdio.h>

  struct student
{
    int roll_no;
    int marks;
    char name;
};
void swap(struct student * f ,int first,int last){
    int temp;
    char tempchr;
    temp = f[first].marks;
    f[first].marks = f[last].marks;
    f[last].marks = temp;
    temp = f[first].roll_no;
    f[first].roll_no = f[last].roll_no;
    f[last].roll_no = temp;
//     tempchr = f[first].name;
//     f[first].name = f[last].name;
//     f[last].name = tempchr;
}

  void heapify(struct student * arr, int n, int i) {
    int max = i; //Initialize max as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    //If left child is greater than root
    if (leftChild < n && arr[leftChild].roll_no > arr[max].roll_no)
      max = leftChild;

    //If right child is greater than max
    if (rightChild < n && arr[rightChild].roll_no > arr[max].roll_no)
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


void display(struct student * arr, int size) {
  for(int i=0;i<size;i++){
       printf("%d students roll no: %d\n", i+1,arr[i].roll_no);
       printf("students marks: %d\n", arr[i].marks);
   }
  printf("\n");
}


  int main() {
    int i, n;
   printf("How many students are u going to enter?: ");
   scanf("%d",&n);
   struct student arr[n];
//    printf("Enter %d student data: ", n);
   for(i=0;i<n;i++){
       printf("Enter %d students roll no: ", i);
       scanf("%d",&arr[i].roll_no);
       printf("Enter %d students marks: ", i);
       scanf("%d",&arr[i].marks);
    }
    display(arr, n);
    heapSort(arr, n);

    printf("Sorted array:\n");
    display(arr, n);
    display(arr, n);
  }
