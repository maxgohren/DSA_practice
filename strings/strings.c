#include <stdio.h>

int isValid(char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		printf("s[%d] = %c\n", i, s[i]);
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

	return 0;
}
