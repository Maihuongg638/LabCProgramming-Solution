/*
5.	Receive an array of m x n with all distinguished elements.
Find the minimum element of each row then find the maximum
number from those.
Ex:
_______________________________________________________________________________
| Input: 5(row) 4(col) 10 21 22 54 64 53 86 72 68 99 30 11 12 23 69 15 16 77 98 19 |
| The converted 2D array will be like this:                                        |
| 10 21 22 54                                                                      |
| 64 53 86 72                                                                      |
| 68 99 30 11                                                                      |
| 12 23 69 15                                                                      |
| 16 77 98 19                                                                      |
| Output:                                                                          |
| 53                                                                               |
|__________________________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void convert2DArr(int a[], int arr[][SIZE], int row, int col)
{
    for (int i = 0; i < row * col; ++i)
    {
        arr[i / col][i % col] = a[i];
    }
}
int MinRow(int a[][SIZE], int col, int idxRow)
{
    int min = a[idxRow][0];
    for(int i = 1; i < col; ++i)
    {
        min = a[idxRow][i] < min ? a[idxRow][i] : min;
    }
    return min;
}
void Ex5(int arr[], int m, int n){
	int a[SIZE][SIZE];
    convert2DArr(arr, a, m, n);
    int max = MinRow(a, n, 0);
    for(int i = 1; i < m; ++i)
    {
        int temp = MinRow(a, n, i);
        max = temp > max ? temp : max;
    }
    
    printf("%d", max);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	argc-=3;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+3]);
	}

	Ex5(testcase, row, col);
	
	return 0;
}