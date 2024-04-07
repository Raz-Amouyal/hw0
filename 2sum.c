#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);
bool binarySearch(int nums[], int nums_size, int target);
int compareInts(const void* a, const void* b);
void copyArray (int dest[], int src[], int len);
int findIndex(int array[], int len, int target, int ignore);
void swap(int *a, int *b);

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	scanf("%d", &target);

	while (scanf("%d", &nums[array_size++]) == 1);
	array_size--;

	twoSum(nums, array_size, target);

	return (0);
}

void twoSum(int nums[], int nums_size, int target) {
	/* YOUR CODE HERE */
	int sorted[nums_size];
	copyArray(sorted, nums, nums_size);
    qsort(sorted, nums_size, sizeof(int), compareInts);

	for(int i=0 ; i < nums_size-1 ; i++){
	    int newTarget = target - sorted[i];
        if(binarySearch(sorted+i+1, nums_size-i-1, newTarget)){
            int k = findIndex(nums, nums_size, sorted[i], -1);
            int j = findIndex(nums, nums_size, newTarget, k);
            if(k>j){
                swap(&k, &j);
            }
            printf("(%d, %d)",k,j);
            return;
        }
	}
}



bool binarySearch(int nums[], int nums_size, int target){
    int left = 0, right = nums_size-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (nums[mid] < target){
            left = mid+1;
        } else if (nums[mid] > target){
            right = mid-1;
        } else if (nums[mid] == target){
            return true;
        }
    }
    return false;
}

int compareInts(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

void copyArray (int dest[], int src[], int len){
    for(int i=0 ; i<len ; i++){
        dest[i] = src[i];
    }
}

int findIndex(int array[], int len, int target, int ignore){

    for(int i=0 ; i<len ; i++){
        if(array[i] == target && i != ignore){
            return i;
        }
    }
    return -1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

