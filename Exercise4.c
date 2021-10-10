/*
4.	Write a program to display a hollow triangle by asterisks (*) on the screen.
The input will be the height of the triangle and the thickness of the borders.
Ex:
 ____________________________________
| Input: 7 2                         |
| Output:                            |
|             *                      |
|           * * *                    |
|         * *   * *                  |
|       * *       * *                |
|     * *           * *              |
|   * * * * * * * * * * *            |
| * * * * * * * * * * * * *          |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int height = atoi(argv[1]);
	int border = atoi(argv[2]);
	//Your codes here
	int starnum = 1;
	int bigestdis = (height * 2) - 1;
	int day = height - border + 1;
	for(int i = 1; i <= height; ++i)
	{
		int nullspace = height - i;
		int innerSpace = starnum - (border * 2);
		if(i >= day)
		{
			for(int j = 1; j <= bigestdis; ++j)
			{
				if(j <= nullspace || j > nullspace + starnum)
				{
					printf("   ");
				}
				else
					printf("*  ");
			}
		}
		else
		{
			for(int j = 1; j <= bigestdis; ++j)
			{
				if(j <= nullspace || j > nullspace + starnum)
				{
					printf("   ");
				}
				else 
				{
					if(starnum <= border * 2)
						printf("*  ");
					else
					{
						if(j <= nullspace + border  || j > nullspace + border + innerSpace)
							printf("*  ");
						else
							printf("   ");
					}
				}
			}
		}
		starnum += 2;
		printf("\n");
	}
	return 0;
}