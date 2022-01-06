/*
3. Receive a string, find the shortest and longest word in that string.
Ex:
 __________________________________________________________
| Input: "   This is a string with shortest and longest word" |
| Output: Shortest word: a                                 |
|         Longest word: shortest                           |
|__________________________________________________________|
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void Ex3(char *s){
    int length = strlen(s);
    int check = 0, min = INT_MAX, max = 0;
    int start = -1, end;
    int maxword, minword, endmax, endmin;
    if(s[0] != ' ') {
        start = 0;
        check = 1;
    }
    for(int i = 0;  i < length - 1; i++){
        // find the index starting of the word
        if((s[i] == ' '  && s[i + 1] != ' ')|| start == 0){
            start = i + 1;
            if(start == 1){
                start = 0;
            }
            for(int j = start; j < length - 1; j++){
                if(s[j] != ' ' && s[j + 1] == ' '){
                    end = j;
                    i = j;  // update the index checking
                    break;
                }
            }
            int lenword = end - start;
			// check whether or not the word we are testing is shortest/ longest 
            if(lenword > max) 
            {
				max = lenword;
                maxword = start;
                endmax = end;
            }
            if(lenword >= 0 && lenword  < min)
            {
				min = lenword;
                minword = start;
                endmin = end;
            }
            start = -1;
        }
    }
    printf("Shortest word: ");
    for(int i = minword; i <= endmin; ++i)
    {
        printf("%c", s[i]);
    }
    printf("\nLongest word: ");
    for(int i = maxword; i <= endmax; ++i)
    {
        printf("%c", s[i]);
    }                            
}
int main() {
	//testing variable, applying it to your algorithm for auto-evaluating
	// char *testcase = argv[1];
	char testcase[] = "This is a string with shortest and longest word";

	Ex3(testcase);
	
	return 0;
}