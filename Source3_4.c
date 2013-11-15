#include <stdio.h>
#include <ctype.h>
#include<limits.h>
#include<math.h>

#define MAX_CHARS 1000

void reverse(char s [])
{
	int i, j;
	char temp;
	for (j = 0; s[j] != '\0'; j++);
	if (s[--j] == '\n')
		s[j--] = '\0';

	for (i = 0; i < j; i++)
	{
		temp = s[i];
		s[i] = s[j];
		s[j--] = temp;
	}
}

/* itoa: convert n to characters in s */
void itoa(int n, char s [])
{
	int i, sign;
	if ((sign = n) < 0) /* record sign */
		n = -n; /* make n positive */
	i = 0;
	do {
		/* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

//the bug is in converting the sign to positive firstly, which will not work with the greatest negative int, 
//since negative of greatest negative int is the same as the greatest negative int because no positive int 
//can hold this value , by which we w'll get a negative n that will not work with the condition of do-while 
//which will repeat just once and get out.

void itoa2(int n, char s [])
{
	int i, sign;
	sign = n;
	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10)); //n will eventually be 0. 
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

//Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the 
//largest negative number, that is, the value of n equal to -(2wordsize-1). 
//Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
void ex3_4()
{
	char s[MAX_CHARS];
	int n = INT_MIN;//-2147483648;
	itoa2(n, s);
	printf("%s\n", s);
}

main()
{
	ex3_4();
	printf("\nPress ENTER to continue. . .\n");
	getchar();
}
