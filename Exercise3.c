/*
3.	Write a program to find all prime number less than a given integer N 
(optional: provide an optimal solution)
Ex:
 ____________________________________
| Input: 10                          |
| Output: 2 3 5 7                    |
|____________________________________|

số nguyên tố : được định nghĩa là chỉ chia hết cho 1 và chính nó
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int testcase = atoi(argv[1]);
	//Your codes here
	if(testcase == 2) printf("%2d", 2);
	else
	{
		printf("%2d", 2);
		for(int i = 3; i <= testcase; i += 2)
		{
			int check = 0;
			for(int j = 3; j <= i/2; j+= 2)
			{
				if(i % j == 0)
				{
					check = 1;
					break;
				}
			}
			if(check == 0) printf("%2d", i);
		}
	}
	
	return 0;
}
