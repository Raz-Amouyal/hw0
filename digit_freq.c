// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_STRING_SIZE 1001
#define NUM_OF_DIGITS 10
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int counter[NUM_OF_DIGITS]={0};
    char temp;
    while (scanf("%c", &temp) == 1){
        if (temp >= '0' && temp <= '9'){
            counter[temp - '0']++;
        }
    }

    for(int i=0 ; i < NUM_OF_DIGITS ; i++){
        printf("%d ",counter[i]);
    }

    return 0;
}
