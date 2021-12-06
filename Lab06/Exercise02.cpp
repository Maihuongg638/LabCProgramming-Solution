/*
2. Receive n strings from the input and sort them ascendingly.
Ex:
__________________________________________
| Input: one two three                            |
| Output: one three two                         |
|_________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strlen(char *s)
{
    int idx = 0;
    while(s[idx++] != '\0'){}
    return idx - 1;
}
int Strcmp(char *s1, char *s2)
{
    int Min = Strlen(s1) < Strlen(s2) ? Strlen(s1) : Strlen(s2);
    int i;
    for (i = 0; i < Min; i++)
    {
        if (s1[i] < s2[i])
        {
            return -1;
        }
        else if (s1[i] > s2[i])
        {
            return 1;
        }
    }
    if (s1[i] == '\0')
    {
        if (s2[i] == '\0')
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    if (s2[i] == '\0')
    {
        if (s1[i] == '\0')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
void Ex2(int n, char *str[]){
	//Your codes her
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++) {
			if(Strcmp(str[i], str[j]) > 0)
            {
                char s[30];
                strcpy(s,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],s);
            }
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%s ", str[i]);
	}
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	char *testcase[argc];
	int i;
	for(i=0; i<argc; i++){
		testcase[i] = argv[i+1];
	}
	
	Ex2(argc, testcase);
	
	return 0;
}
