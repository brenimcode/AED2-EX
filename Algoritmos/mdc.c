#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
    //MDC de A e B, se A%B == 0 para o mdc entre eles é 
    if(a%b == 0){
        return b;
    }
    else{
        return mdc(b,a%b);
    }
}

int main(){
    int a,b;

    scanf("%d %d",&a,&b);
    printf("mdc(a,b) = [%d]\n",mdc(a,b));
    return 0;
}