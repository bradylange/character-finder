#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Brady Lange
 * 3/12/18
 * File name: mystrchr.c
 * This program is my own version of finding the first instance of a character in a string which is a function in the C library
 */
 
 //My strchr function that I have created myself
 const char * mystrchr(const char * str, int character)
 {
	 //Add one to the length as the terminating null character can be pointed to in the string
	 int stringSize = strlen(str) + 1;
	 //Keeping track of how many times the loop has traversed
	 int i = 0;
	 //Casting the character input to a character so I can compare it
	 
	 char letter = (char)character;

	 //dereference str 
	 while(str != NULL)
	 {
		 if(str[i] == letter)
		 {
			 str = &str[i];
			 break;
		 }
		 else if(i == stringSize)
		 {
			 str = NULL;
		 }
		 i++;
	 }
	 
	 return str;

 } //End of 
 
 //Main function to test my strchr function
 int main(int argc, char * argv[])
 {
	 int i = 0;
	 int stringSize = strlen(argv[1]);
	 char string[stringSize];
	 int character = argv[2][0];
	 char * charPointer;
	 
	 //Making the string array more user friendly to work with
	 while(argv[1][i] != '\0')
	 {
		 string[i] = argv[1][i];
		 i++;
	 }
	 
	 printf("Looking for the %c character in %s...\n", character, string);
	 
	 charPointer = mystrchr(string, character);
	 
	 while(charPointer != NULL)
	 {
		 printf("Found the character %c at %ld\n", character, charPointer - string + 1);
		 charPointer = mystrchr(charPointer + 1, character);
	 }
	 
	 return 0;
	 
 } //End of main function