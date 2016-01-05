/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void ReverseString(char *str, int start, int end){
	for (char temp; start < end; start++, end--){
		temp = str[end];
		str[end] = str[start];
		str[start] = temp;
	}
}
void str_words_in_rev(char *input, int len){

	int wordstart, wordend;

	ReverseString(input, 0, len - 1);

	for (wordstart = wordend = 0; wordend < len; wordend++){
		if (input[wordend] != ' '){
			wordstart = wordend;
			while (input[wordend] != ' ' && wordend < len)
			{
				wordend++;
			}
			wordend--;
			ReverseString(input, wordstart, wordend);
		}
	}
}
