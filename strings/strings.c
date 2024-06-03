#include <stdio.h>

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

	return 0;
}
