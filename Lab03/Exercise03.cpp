/*
3.	Input an array of n integers. Find the largest sorted sub array
(sorted array increasing/decreasing and has the largest number of elements)
Ex:
 _____________________________________________
| Input: 2 5 3 4 8 9 7 6 10                   |
| Output: Increasing 3 4 8 9 Decreasing 9 7 6 |
|_____________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Increasing : typeSublength = 1; decreasing : typeSublength = 0
void Ex3(int arr[], int n, int typeSublength = 1)
{
    int Length = 1;
    int max = 1;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i] < arr[i + 1]) == typeSublength)
        {
            Length++;
            if (Length > max)
            {
                max = Length;
                start = i + 2 - Length;
                end = i + 2;
            }
        }
        else
            Length = 1;
    }
    for (int i = start; i < end; i++)
        printf("%2d", arr[i]);
}

// Way 2:
void maxSizeDecrease(int a[], int n)
{
    int i, j;
    int temp = 0;
    int max = 0;
    int tempArr[n];
    int idx = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1] && i < n - 1)
        {
            temp++;
        }
        else
        {
            temp++;
            if (max < temp)
            {
                max = temp;
            }
            temp = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            tempArr[idx] = a[i];
            idx++;
        }
        else
        {
            tempArr[idx] = a[i];
            idx++;
            if (idx == max)
            {
                for (j = 0; j < max; j++)
                {
                    printf(" %d", tempArr[j]);
                }
            }
            idx = 0;
        }
    }
}
void maxSizeIncrease(int a[], int n)
{
    int i, j;
    int temp = 0;
    int max = 0;
    int tempArr[n];
    int idx = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1] && i < n - 1)
        {
            temp++;
        }
        else
        {
            temp++;
            if (max < temp)
            {
                max = temp;
            }
            temp = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1])
        {
            tempArr[idx] = a[i];
            idx++;
        }
        else
        {
            tempArr[idx] = a[i];
            idx++;
            if (idx == max)
            {
                for (j = 0; j < max; j++)
                {
                    printf(" %d ", tempArr[j]);
                }
            }
            idx = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    //testing variable, applying it to your algorithm for auto-evaluating
    argc--;
    int testcase[50], i;
    for (i = 0; i < argc; i++)
    {
        testcase[i] = atoi(argv[i + 1]);
    }
    // printf("\nIncreasing");
	// Ex3(testcase, argc);
    // printf(" Decreasing");
	// Ex3(testcase, argc, 0);

    printf("\nIncreasing");
    maxSizeIncrease(testcase, argc);
    printf(" Decreasing");
    maxSizeDecrease(testcase, argc);

    return 0;
}