/*
5. Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. The brackets must close in the correct order.
Ex:
 ________________________
| Input: "{([])}"        |
| Output: Valid!         |
| Input: "{[)}"          |
| Output: Invalid!       |
|________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int Ex5(char *str){
	//Your codes here
	int len = strlen(str);
    for(int i = len - 1; i >= len / 2; i--)
    {
        if(str[i] == '}')
        {
            if(str[len - 1 - i] != '{')
                return 0;
        }
        else if (str[i] == ')')
        {
            if(str[len - 1 - i] != '(')
                return 0;
        }
        else
        {
            if(str[len - 1 - i] != '[')
                return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *testcase = argv[1];
	if(Ex5(testcase))
        printf("Valid!");
    else 
        printf("Invalid!");
	return 0;
}