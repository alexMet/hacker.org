#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// our answer might just be ottomelon

int main(int argc, char **argv) {
	int len, i, j;
	char *t = "751a6f1d3d5c3241365321016c05620a7e5e34413246660461412e5a2e412c49254a24";
	long int ch;

	i = 0;
	len = strlen(t);
	char c[len/2][3];

	j = 0;
	for (i = 0; i < len-1; i += 2) {
		c[j][0] = t[i];
		c[j][1] = t[i+1];
		c[j++][2] = '\0';
	}

	for (i = 1; i < len/2; i++) {
		ch = strtol(c[i], NULL, 16);
		ch = ch ^ strtol(c[i-1], NULL, 16);
		printf("%c", ch);
	}
	printf("\n");

	return 0;
}
