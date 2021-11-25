/*
1. Receive a maximum 4-digit integer n. Write a program to read the number n.
________________________________________________
| Input: 1234                                    |
| Output: one thousand two hundred thirty four   |
|________________________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Read1DigitNum(int x)
{
    if(x == 0)
		printf("rezo ");
	else if(x == 1)
		printf("one ");
	else if(x == 2)
		printf("two ");
	else if(x == 3)
		printf("three ");
	else if(x == 4)
		printf("four ");
	else if(x == 5)
		printf("five ");
	else if(x == 6)
		printf("six ");
	else if(x == 7)
		printf("seven ");
	else if(x == 8)
		printf("eight ");
	else if(x == 9)
		printf("nine ");
}
void Read2DigitsNum(int x)
{
    int dv = x % 10;
    x /= 10;
    if(x == 0)
		Read1DigitNum(dv);
    else if(x == 1)
    {
        if(dv == 0)
            printf("ten ");
        else if(dv == 1)
            printf("eleven ");
        else if(dv == 2)
            printf("twelve ");
        else if(dv == 3)
            printf("thirteen ");
        else if(dv == 4)
            printf("fourteen ");
        else if(dv == 5)
            printf("fifteen ");
        else if(dv == 6)
            printf("sixteen ");
        else if(dv == 7)
            printf("seventeen ");
        else if(dv == 8)
            printf("eighteen ");
        else if(dv == 9)
            printf("nineteen ");
    }
	else
    {
        if(x == 2)
        {
            printf("twenty ");
        }
        else if(x == 3)
            printf("thirty ");
        else if(x == 4)
            printf("fourty ");
        else if(x == 5)
            printf("fifty ");
        else if(x == 6)
            printf("sixty ");
        else if(x == 7)
            printf("seventy ");
        else if(x == 8)
            printf("eighty ");
        else if(x == 9)
            printf("ninety ");
        if(dv != 0)
            Read1DigitNum(dv);
    }
	
} 
void Read3DigitsNum(int x)
{
	int BigestNum = x / 100;
	int NdDigits = x % 100;
	int  tens = NdDigits / 10;
	int unit = NdDigits % 10;

	Read1DigitNum(BigestNum);

	printf("hundred ");

	if(tens != 0)
		Read2DigitsNum(NdDigits);
	else
	{
		if(unit != 0)
		{
            printf("and ");
			Read1DigitNum(unit);
		}
	}
}

void LinkingSound(int divnum)
{
	if(divnum == 1 || divnum == 4)
		printf("thousand ");
	else if(divnum == 2 || divnum == 5)
		printf("million ");
	else if(divnum == 3 || divnum == 6)
		printf("billion ");
}
void Ex1(int n)
{
	//Your codes here
    int digitnums = n == 0 ? 1 : 0;
    int temp = n;
	while(temp != 0)
	{
		temp /= 10;
		digitnums++;
	}

	int divnum = (digitnums - 1) / 3;

	long long int Pow = pow(10, 3 * divnum);
		
	int GroupNum = n / Pow;

	if(GroupNum < 10)
		Read1DigitNum(GroupNum);
	else if(GroupNum < 100)
		Read2DigitsNum(GroupNum);
	else if(GroupNum < 1000)
		Read3DigitsNum(GroupNum);

	LinkingSound(divnum);

	n %= Pow;

	while(n != 0)
	{
		divnum--;
		Pow = pow(10, 3 * divnum);
		
		GroupNum = n / Pow;

		if(GroupNum != 0)
		{
			Read3DigitsNum(GroupNum);

			LinkingSound(divnum);
		}


		n %= Pow;
	}
}

int main(int argc, char *argv[])
{
	//testing variable, applying it to your algorithm for auto-evaluating
	int testcase = atoi(argv[1]);

	Ex1(testcase);

	return 0;
}
