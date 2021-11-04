/*
4. Input an array of m x n. Provide the following functions:
	a.	Insert one row
	b.	Remove one row
	c.	Insert one column
	d.	Remove one column
Ex:
____________________________________________________________________
| Input: 5(row) 4(col) 1(choice) 2(location) 1 2 3 4 (insert array) |
| 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 16 17 18 19       |
| Output:                                                           |
| 10 21 12 53                                                       |
| 64 53 86 72                                                       |
| 1 2 3 4                                                           |
| 68 99 10 11                                                       |
| 12 13 14 15                                                       |
| 16 17 18 19                                                       |
|___________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void convert2DArr(int[], int[][SIZE], int, int);
void PrintArr(int[][SIZE], int, int);
void Swap(int *, int *);
void SwapRow(int a[][SIZE], int column, int row1, int row2)
{
    for (int i = 0; i < column; i++)
    {
        Swap(&a[row1][i], &a[row2][i]);
    }
}

void DelRow(int a[][SIZE], int &row, int column, int idxRowDel)
{
    for (int i = idxRowDel; i < row - 1; i++)
    {
        SwapRow(a, column, i, i + 1);
    }
    row--;
}

void InsertRow(int a[][SIZE], int &row, int column, int arrAdd[], int idxAdd)
{
    row++;
    for (int i = 0; i < column; i++)
    {
        a[row - 1][i] = arrAdd[i];
    }
    for (int i = row - 1; i > idxAdd; i--)
    {
        SwapRow(a, column, i, i - 1);
    }
}

void SwapColumn(int a[][SIZE], int row, int col1, int col2)
{
    for (int i = 0; i < row; i++)
    {
        Swap(&a[i][col1], &a[i][col2]);
    }
}

void DelColum(int a[][SIZE], int row, int &column, int idxColDel)
{
    for (int i = idxColDel; i < column - 1; i++)
    {
        SwapColumn(a, row, i, i + 1);
    }
    column--;
}

void InsertColumn(int a[][SIZE], int row, int &column, int b[], int idxInsert)
{
    column++;
    for (int i = 0; i < row; i++)
    {
        a[i][column - 1] = b[i];
    }
    for (int i = column - 1; i > idxInsert; i--)
    {
        SwapColumn(a, row, i, i - 1);
    }
}

int main(int argc, char *argv[])
{
    //testing variable, applying it to your algorithm for auto-evaluating
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    int choice = atoi(argv[3]);
    /* choice values:
	1 for Insert one row
	2 for Remove one row
	3 for Insert one column
	4 for Remove one column 
	*/
    int loc = atoi(argv[4]); //location of inserting/removing row/column
    int a[SIZE][SIZE];
    if (choice == 2 || choice == 4)
    {
        argc -= 5;
        int testcase[argc], i;
        for (i = 0; i < argc; i++)
        {
            testcase[i] = atoi(argv[i + 5]);
        }
        convert2DArr(testcase, a, row, col);
        if (choice == 2)
            DelRow(a, row, col, loc);
        else
            DelColum(a, row, col, loc);

    }
    else if (choice == 1)
    {
        int in_row[col], column;
        for (column = 0; column < col; column++)
        {
            in_row[column] = atoi(argv[column + 5]);
        }
        argc -= 5;
        argc -= col;
        int testcase[argc], i;
        for (i = 0; i < argc; i++)
        {
            testcase[i] = atoi(argv[i + 5 + col]);
        }
        convert2DArr(testcase, a, row, col);
        InsertRow(a, row, col, in_row, loc);
    }
    else if (choice == 3)
    {
        int in_col[row], r;
        for (r = 0; r < row; r++)
        {
            in_col[r] = atoi(argv[r + 5]);
        }
        argc -= 5;
        argc -= row;
        int testcase[argc], i;
        for (i = 0; i < argc; i++)
        {
            testcase[i] = atoi(argv[i + 5 + row]);
        }
        convert2DArr(testcase, a, row, col);
        InsertColumn(a, row, col, in_col, loc);
    }
    else
        printf("Invalid option!");
    PrintArr(a, row, col);
    return 0;
}
void convert2DArr(int a[], int arr[][SIZE], int row, int col)
{
    for (int i = 0; i < row * col; ++i)
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
void PrintArr(int a[][SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; ++j)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}