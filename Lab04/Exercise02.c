/*
2.	Write a program to input an array of m x n.
Sort the odd column in increasing order and the
even column in decreasing order.
Ex:
___________________________________________________________________________________
| Input: 5(row) 4(col) 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 16 17 18 19 |
| The converted 2D array will be like this:                                        |
| 10 21 12 53                                                                      |
| 64 53 86 72                                                                      |
| 68 99 10 11                                                                      |
| 12 13 14 15                                                                      |
| 16 17 18 19                                                                      |
| Output:                                                                          |
| 68 13 86 11                                                                      |
| 64 17 18 15                                                                      |
| 16 21 14 19                                                                      |
| 12 53 12 53                                                                      |
| 10 99 10 72                                                                      |
|__________________________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void convert2DArr(int a[], int arr[][SIZE], int row, int col)
{
    for(int i = 0; i < row * col; ++i)
    {
        arr[i / col][i % col] = a[i];
    }
}
void Output(int arr[][SIZE], int row, int col)
{
    printf("\n");
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
}
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SortArr(int a[][SIZE], int row, int idxCol, int typesort)
{
    for(int i = 0; i < row - 1; ++i)
    {
        for(int j = i + 1; j < row; ++j)
        {
            if((a[i][idxCol] > a[j][idxCol]) == typesort)
            {
                Swap(&a[i][idxCol], &a[j][idxCol]);
            }
        }
    }
}
void Ex2(int arr[][SIZE], int row, int col){
	for(int i = 0; i < col; ++i)
    {
        int sort = i % 2 == 0 ? 0 : 1;
        SortArr(arr, row, i,  sort);
    }
    Output(arr, row, col);
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
    int a[SIZE][SIZE];
    convert2DArr(testcase, a, row, col);
	Ex2(a, row, col);
	return 0;
}