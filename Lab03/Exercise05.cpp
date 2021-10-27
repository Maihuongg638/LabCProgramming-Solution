/*
5. Write a function to move all positive element of an array upfront
Ex:
______________________________________
| Input: 2 -3 4 6 -7 9 8 -2          |
| Output: 2 4 6 9 8 -3 -7 -2         |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Ex5(int arr[], int n){
	for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] < 0)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(arr[j] > 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex5(testcase, argc);
	
	return 0;
}