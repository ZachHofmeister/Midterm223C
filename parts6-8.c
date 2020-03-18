#include <stdio.h>
#include <string.h>

char* _strcpy(char* s, const char* t) {
	char * start = s; //Saves the starting address of the destination string
	while((*s++ = *t++) != '\0') {}
	return start;
}

char* _strncat(char* s, const char* t, size_t n) {
	char * start = s; 							//Saves the starting address of the destination string
	while (*s != '\0') ++s; 					//Move destination to point to the end
	while (n-- > 0 && (*s++ = *t++) != '\0') {} //copy, but after the contents since dest has been moved
	return start;
}

int _strcmp(const char* s, const char* t) {
	while (*s != '\0' && *t != '\0' && *s == *t) {
		++s;
		++t;
	}
	return *s - *t;
}

int main (int argc, const char * argv[]) {
	char test1[100] = "Replace this text";
	printf("%s\n", _strcpy(test1, "Hello there"));

	char test2[100] = "Add text after: ";
	printf("%s\n", _strncat(test2, "Hello there", 5));

	printf("%d\n", _strcmp("Hello", "Hello there"));

	return 0;
}