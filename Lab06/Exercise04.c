/*
4. Receive a string, remove all blank spaces at begin and
end of the string and leave only one blank space between words.
Ex:
 ________________________________________________
| Input: "  this  is an   unformatted  string "  |
| Output: this is an unformatted string          |
|________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void DelChar(char *s, int idxDel, int *len)
{
	for(int i = idxDel + 1; i <  *len; ++i)
	{
		s[i - 1] = s[i];
	}
	(*len)--;
	s[*len] = '\0';
}
void Ex4(char *str){
	//Your codes here
	int len = strlen(str);
	while (str[0] == ' ')
	{
		DelChar(str, 0, &len);
	}
	while (str[len - 1] == ' ')
	{
		DelChar(str, len - 1, &len);
	}
	int start = 0;
	for(int i = start + 1 ; i < len - 1; ++i)
	{
		if(str[i] == ' ' && str[i + 1] == ' ')
		{
			DelChar(str, i + 1, &len);
			i--;
		}
	}
	start = 0;
	while (str[start] != '\0')
	{
		printf("%c", str[start]);
		start++;
	}
}

int main(int argc, char *argv[]) {
	char testcase[] = "  this  is an   unformatted  string    ";

	Ex4(testcase);

	return 0;
}