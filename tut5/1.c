#include <stdio.h>
int initpos(int x,int n ,int m){
    return(((x%2)+(x/2))*((n+1)/(m+1))*2)-(x%2);
}
int main(){
    int x,y,m,n;
    printf("Enter size - "); // n = size , m is number of arrays
    scanf("%d", &n);
    printf("Enter number of queues - ");
    scanf("%d", &m);
    m--;
    n--;
    while(1){
    printf("Enter array  - ");
    scanf("%d", &x);
    x--;
    y = initpos(x,n,m);
    printf("%d",y);
    }
}
