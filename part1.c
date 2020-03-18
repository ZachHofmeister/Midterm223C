#include <stdio.h>
#include <ctype.h>

void count() {
	printf("Enter lines of text here: ...\n");
	int c, nc = 0, nt = 0, nbackslash = 0, nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') ++nl;
		else if (c == '\t') ++nt;
		else if (c == '\\') ++nbackslash;
		else if (isalnum(c)) ++nc;
	}
	printf("lines: %d\n", nl);
	printf("tabs: %d\n", nt);
	printf("backslashes: %d\n", nbackslash);
	printf("alphanumeric: %d\n", nc);
}

int main(int argc, const char* argv[]) {
	count();
	return 0;
} 