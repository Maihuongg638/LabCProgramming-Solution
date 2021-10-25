/*
1.	Input an array of n integers. Write a function to check whether
the array is symmetric or not (optional: use recursive)
Ex:
 ____________________________________ 
| Input: 1 2 3 2 1                   |
| Output: symmetric                  |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Ex1(int arr[], int n){
	//Your codes here
    for(int i = 0; i < n / 2; i++)
    {
        if(arr[i] != arr[n - 1 - i])    return 0;
    }
    return 1;
}



int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[100],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
    Ex1(testcase, argc) ? printf("symmetric") : printf("asymmetric");

	return 0;
}