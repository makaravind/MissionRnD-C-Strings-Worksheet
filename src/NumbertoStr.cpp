/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<stdlib.h>
int Rev(int x){
	int num = 0;
	int digit;
	while (x != 0){
		digit = x % 10;
		num = (num * 10) + digit;
		x /= 10;
	}
	return num;
}
int AddInt(int ipart, char *s, int nop){
	int i = 0;
	if (nop == 1){
		s[0] = '-';
		ipart = -ipart;
		i = 1;
	}
	ipart = Rev(ipart);

	while (ipart != 0){
		int digit = ipart % 10;
		s[i++] = digit + 48;
		ipart /= 10;
	}
	s[i] = '\0';
	return i;
}
int AddDecimal(int dpart, char *s, int start){
	dpart = Rev(dpart);
	int i = start;
	while (dpart != 0)
	{
		int digit = dpart % 10;
		s[i++] = digit + 48;
		dpart /= 10;
	}
	s[i] = '\0';
	return i;
}
void number_to_str(float number, char *str, int afterdecimal){
	int ipart = (int)number;
	double dpart = number - ipart;

	for (int i = 0; i < afterdecimal; i++){
		dpart *= 10;
	}
	// check neg 

	int dintpart = (int)dpart;
	int nop = -1;
	if (number < 0) {
		nop = 1;
		dintpart = -dintpart;
	}
	else nop = 0;
	int intlength = AddInt(ipart, str, nop);

	if (dintpart != 0){
		str[intlength++] = '.';
		int  decilength = AddDecimal(dintpart, str, intlength);
	}

}
