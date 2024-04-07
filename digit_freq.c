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
    char str[MAX_STRING_SIZE];
    fgets(str, MAX_STRING_SIZE, stdin);
    int l1 = strlen(str);
    str[l1 - 1] = '\0';
    for (int i = 0; i < l1; ++i) {
        if (str[i] >= '0' && str[i] <= '9'){
            counter[str[i] - '0']++;
        }
    }
    

   for(int i=0 ; i < NUM_OF_DIGITS -1 ; i++){
        printf("%d ",counter[i]);
    }
    printf("%d",counter[9]);

    return 0;
}
