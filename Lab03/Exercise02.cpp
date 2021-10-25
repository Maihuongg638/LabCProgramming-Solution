/*
2.	Input an array of n integers. Sort the odd numbers in
increasing order and even numbers in decreasing order.
Ex:
 ____________________________________ 
| Input: 2 5 3 4 8 6 7 9 2           |
| Output: 8 3 5 6 4 2 7 9 2          |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Output(int a[], int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}
void Ex2(int a[], int n){
	//Your codes here
	for(int i = 0; i < n - 1; i++)
    {
        if(a[i] % 2 == 0)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(a[j] % 2 == 0)
                {
                    if(a[i] < a[j])
                    {
                        int temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }
        }
        else{
            for(int j = i + 1; j < n; ++j)
            {
                if(a[j] % 2 != 0)
                {
                    if(a[i] > a[j])
                    {
                        int temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }
        }
    }
    Output(a, n);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[50],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex2(testcase, argc);
	
	return 0;
}