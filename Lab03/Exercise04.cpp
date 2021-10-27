/*
4. Write a function to check whether a given array is sorted or not.
Return 1 if sorted increasing, -1: decreasing, 0: not sorted
Ex:
______________________________________
| Input: 8 7 9 2 1 5 2               |
| Output: 0                          |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int CheckIncr(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		if(arr[i] > arr[i+1]) return 0;
	}
	return 1;
}

int CheckDecr(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		if(arr[i] < arr[i+1]) return 0;
	}
	return 1;
}

int Ex4(int arr[], int n){
	//Your codes here
    if(CheckDecr(arr, n))
		return -1;
	if(CheckIncr(arr, n))
		return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[50],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	printf("%d", Ex4(testcase, argc));

	return 0;
}