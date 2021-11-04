/*
3.	Input an array of n x n (n is even). Sort the first diagonal in
increasing order and the second diagonal in decreasing order.
First diagonal starts with element [0,0], second diagonal starts with elements [n-1,0]
Ex:
_________________________________________________________________
| Input: 4(edge) 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 |
| The converted 2D array will be like this:                      |
| 10 21 12 53                                                    |
| 64 53 86 72                                                    |
| 68 99 10 11                                                    |
| 12 13 14 15                                                    |
| Output:                                                        |
| 10 21 12 12                                                    |
| 64 10 53 72                                                    |
| 68 86 15 11                                                    |
| 99 13 14 53                                                    |
|________________________________________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void convert2DArr(int [], int [][MAX], int , int );
void Swap(int *, int *);
void SortArr(int [], int , int );
void PrintArr(int [][MAX], int);

void Ex3(int in_arr[], int n){
    int a[MAX][MAX];
    convert2DArr(in_arr, a, n, n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(a[j][j] < a[i][i])
                Swap(&a[j][j], &a[i][i]);
            if(a[j][n - 1 - j] < a[i][n - 1 - i])
                Swap(&a[j][n - 1 - j], &a[i][n - 1 - i]);
        }
    }
    PrintArr(a, n);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int edge = atoi(argv[1]);
	argc-=2;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+2]);
	}
	Ex3(testcase, edge);
	
	return 0;
}

void convert2DArr(int a[], int arr[][MAX], int row, int col)
{
    for(int i = 0; i < row * col; ++i)
    {
        arr[i / col][i % col] = a[i];
    }
}
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SortArr(int a[], int n, int typesort)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1;  j < n; j++){
            if((a[i] > a[j]) == typesort)
            {
                Swap(&a[i], &a[j]);
            }
        }
    }
}
void PrintArr(int a[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; ++j)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}