#include <stdio.h>

int SIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == SIZE)
      return 1;
      else
      return 0;
}



int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf(" Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf(" Stack is full.\n");
   }
}
int main() {
   
   push(3);
   push(8);
   push(7);
   push(1);
   push(27);
   

   
   printf("All the Elements: \n");

   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack is full: %s\n" , isfull()?"true":"false");
   printf("Stack is empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}
