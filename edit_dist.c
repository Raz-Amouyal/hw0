#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int edit_dist(char word1[], char word2[]);
int min(int x, int y, int z);
void print(int* a,int l1, int l2 );

int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];

	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) - 1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) - 1] = '\0';

	printf("%d\n", edit_dist(word1, word2));

	return (0);
}

int edit_dist(char word1[], char word2[]) {
	int l1 = strlen(word1) + 1;
    int l2 = strlen(word2) + 1;

    if (l1 == 1){
        return l2 - 1;
    } else if (l2 == 1){
        return l1 - 1;
    }
    //printf("l1: %d  ,  l2: %d \n",l1 ,l2);
    int d[l1][l2];

    for (int i = 0; i < l1; ++i) {
        d[i][0] = i;
        //printf("%d ",d[i][0]);
    }
    //printf("\n");
    for (int j = 0; j < l2; ++j) {
        d[0][j] = j;
        //printf("%d ",d[0][j]);
    }
    //printf("\n\n\n");

    for (int i = 1; i < l1; ++i) {
        for (int j = 1; j < l2; ++j) {
            if (word1[i-1] == word2[j-1]){
                d[i][j] = d[i-1][j-1];
            } else{
                d[i][j] = min (d[i-1][j] + 1,
                               d[i][j-1] + 1,
                               d[i-1][j-1] + 1);
            }
            //printf("%d ",d[i][j]);
        }
        //printf("\n");
    }
    //printf("\n\n");
    //print(d,l1,l2);
    return d[l1 -1][l2 -1];

}

int min(int x, int y, int z){
    int min = (x < y) ? x : y;
    return (min < z) ? min : z;
}

void print(int* a,int l1, int l2 ){
    for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
            printf("%d ",*(a+i*l2+j));
        }
        printf("\n");
    }
}

//fghhfghfghfghdserfg

