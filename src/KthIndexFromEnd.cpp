/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int StrLength(char *s){
	int count;
	for (count = 0; s[count] != '\0'; count++);
	return count;
}
char KthIndexFromEnd(char *str, int K) {
	// init error cases
	if (str == "" || str == nullptr) return '\0';
	if (K < 0) return '\0';

	int len = StrLength(str);

	if (len < K) return '\0';

	return str[(len - K) - 1];
}