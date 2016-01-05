/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
int StrLength1(char *s){
	int count;
	for (count = 0; s[count] != '\0'; count++);
	return count;
}
int InRange(char c){
	if ((int)c == 32) return 0;
	//	if ((int)c < 97 || (int)c > 122) return -1;

	return 1;
}
char removeSpaces(char *str) {
	if (str == " " || str == NULL) return '\0';

	int length;
	length = StrLength1(str);
	char tmp; // for swapping
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		//j = i;
		j++;
		if (InRange(str[i]) == 1) i++;
		else if (InRange(str[i]) == 0)
		{
			while (j < length && InRange(str[j]) != 1){
				j++;
			}

			if (j == length) {
				str[i] = '\0';
				break;
			}
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i++;
		}
	}
	return '\0';
}