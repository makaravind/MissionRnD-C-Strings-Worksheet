/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	char **result;
	int i, j, start = 0, sj = 0, f, co, count = -1, set = 0, a;

	result = (char**)malloc(sizeof(char*) * SIZE);
	for (i = 0; i < SIZE; i++)
		result[i] = (char*)malloc(sizeof(char)*SIZE);

	if (str1 && str2){
		do{
			do{
				// space string
				for (i = 0; str1[i] && str1[i] == ' '; i++);
				if (str1[i] == '\0')
				{
					start = i;
					break;
				}
				i = start; j = sj; set = 0;

				//checking equality
				for (j = sj; str1[i] && str2[j] && str1[i] == str2[j] && str1[i] != ' '&&str2[j] != ' '; j++, i++);

				//if not equal then make j point to another word.
				if (str1[i] && str2[j] && str1[i] != str2[j])
				{
					for (sj = j; str2[sj] && str2[sj] != ' '; sj++);
					j = sj;
					for (sj = j; str2[sj] && str2[sj] == ' '; sj++);
				}

				//when found equal.
				else{
					set = 1;

					for (co = i - 1; str1[co] != ' '&& co > 0; co--);
					if (co == 0)
						co = -1;

					//inserting into result.
					for (f = co + 1, a = 0, count = count + 1; str1[f] && str1[f] != ' '; f++, a++)
					{
						result[count][a] = str1[f];
					}
					result[count][a] = '\0';

					//checking for next word.
					for (start = i; str1[start] && str1[start] == ' '; start++);
					sj = 0;
				}
			} while (str1[start] && str2[sj]);

			if (str1[start] == '\0')
				break;
			//setting i to next word
			if (set == 0){
				for (i = start; str1[i] && str1[i] != ' '; i++);
				for (start = i; str1[start] && str1[start] == ' '; start++);
				sj = 0;
			}
		} while (str1[start]);
		if (count == -1)
			return NULL;
		return result;
	}

	return NULL;
}