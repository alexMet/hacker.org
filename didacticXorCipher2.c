#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// from all the answers we pick the human readable one
// PLEASESUBMITHACKADOODLEFORTHISCHALLENGE

int main(int argc, char **argv) {
	int len, i, j;
	char *t = "948881859781c4979186898d90c4c68c85878f85808b8b808881c6c4828b96c4908c8d97c4878c858888818a8381";
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

	for (j = 100; j < 200; j++) {
		for (i = 0; i < len/2; i++) {
			ch = strtol(c[i], NULL, 16);
			printf("%c", ch ^ j);
		}
		printf("\n");
	}
	return 0;
}
