#include <stdio.h>
#include <string.h>

int isValid(char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		if(s[i] <  97 || s[i] > 122) return 0;
		else if(s[i] <  65 && s[i] >  90) return 0;
		else i++;
	}
	return 1;
}

int main(){

	int i = 0;
	char s[] = "welcome";
	// print length of string
	while(s[i] != '\0') i++;
	printf("The length of the string %s is %d\n", s, i);
	
	// make invert uppercase and lowercase
	i = 0;
	char scopy[] = "welcome";
	while(s[i] != '\0')
	{
		  if(s[i] >=  97 && s[i] <= 122) s[i] -= 32;
		  else if(s[i] >=  65 && s[i] <=  90) s[i] += 32;

		//if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
		//else if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		  i++;
	}
	printf("The inverted string %s is now %s\n", scopy, s);

	// count words in a sentence
	char sentence[] = "Hi my name is Billy Bob Joe!";
	i = 0;
	int count = 1; // ignore empty case and other edge cases
	while(sentence[i] != '\0')
	{
		if(sentence[i] == ' ') count++;	
		i++;
	}
	printf("There are %d words in the sentence \"%s\"\n", count, sentence);

	// check if the string is valid (has no non-letter characters)
	char valid[] = "hello";
	char invalid[] = "he\%llo";
	if(isValid(valid)) printf("The string %s is valid\n", valid);
	if(!isValid(invalid)) printf("The string %s is invalid\n", invalid);

	// reverse string
	char forward[] = "Python";
	char reverse[7] = {0};

	for(i = 0; forward[i] != '\0'; i++)
	{
		reverse[5 - i] = forward[i];
	}
	reverse[6] = '\0';
	printf("The word %s reversed is %s\n", forward, reverse);


	// reverse string in place
	char A[] = "Python";
	char Acpy[] = "Python";
	int j = 5; // position before \0 in "Python"
	char t;

	for(i = 0; i < j; i++,j--)
	{
		t = A[i];
		A[i] = A[j];
		A[j] = t;
	}
	printf("The reverse in place: %s becomes %s\n", Acpy, A);

	// check for palindrome with 2 pointer approach
	char palin[] = "madam";
	printf("Is the string %s a palidrome?\n", palin);
	for(i = 0, j = 4; i < j; i++, j--)
		if(palin[i] != palin[j]) printf("%s is not a palindrome\n", palin);
	printf("%s is a palindrome\n", palin);

	// check for palindrome with reverse copy and compare
	char palin2[] = "racecar";
	char palin2cpy[8];

	for(i = 0; palin2[i] != '\0'; i++)
		palin2cpy[6-i] = palin2[i];
	palin2cpy[7] = '\0';

	for(i = 0; palin2[i] != '\0'; i++)
	{
		if(palin2[i] != palin2cpy[i]) printf("%s is not a palindrome\n", palin2);
	}
	printf("%s is a palindrome\n", palin2);

	// find duplicates in a string with hash table
	char duplicates[] = "finding";
	int H[26] = {0};
	
	for(i = 0; i < 7; i++)
		H[ duplicates[i] - 97 ] += 1;

	printf("The following characters appeared more than once in the string %s\n", duplicates);
	for(i = 0; i < 26; i++)
		if( H[i] > 1) printf("%c ", i+97);

	printf("\n");	
	
	// find duplicates with bitwise hash table
	char dup[] = "finding";
	int B = 0, x = 0;

	for(i = 0; i < 7; i++)
	{
		x = 1;
		x = x << ( dup[i] - 97);  // shift bit left by position in alphabet
		if( (x & B) )
			printf("The letter %c is a duplicate in %s\n", dup[i], dup);
		else
			B = x | B;
	}

	// check if two strings are anagrams: when words are different but the same set of letters are used

	char ana1[] = "decimal";
	char ana2[] = "medical";
	memset(H, 0, sizeof(H));

	for(i = 0; i < 8; i++)
	{
		H[ ana1[i] - 97 ]++;	
	}
	for(i = 0; i < 8; i++)
	{
		H[ ana2[i] - 97 ]--;	
		if( H[ ana2[i] - 97 ] < 0) 
		printf("The strings %s and %s are not anagrams\n", ana1, ana2);
	}
	if( ana2[i-1] == '\0') printf("The strings \"%s\" and \"%s\" are anagrams\n", ana1, ana2);

	return 0;
}

