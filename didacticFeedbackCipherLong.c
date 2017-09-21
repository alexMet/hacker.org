#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// cipher is really quite simple. i am sure you have solved it by now. "kettlewon" is your answer.

int main(int argc, char **argv) {
	int len, i, j, k;
	char *t = "e5534adac53023aaad55518ac42671f8a1471d94d8676ce1b11309c1c27a64b1ae1f4a91c73f2bfce74c5e8e826c27e1f74c4f8081296ff3ee4519968a6570e2aa0709c2c4687eece44a1589903e79ece75117cec73864eebe57119c9e367fefe9530dc1";
	long int ch;

	i = 0;
	len = strlen(t);
	char c[len/8][9];

	j = 0;
	for (i = 0; i < len-7; i += 8) {
		c[j][0] = t[i];
		c[j][1] = t[i+1];
		c[j][2] = t[i+2];
		c[j][3] = t[i+3];
		c[j][4] = t[i+4];
		c[j][5] = t[i+5];
		c[j][6] = t[i+6];
		c[j][7] = t[i+7];
		c[j][8] = '\0';
		j++;
	}

	k = 1;
	while (k < len/8) {
		ch = strtol(c[k], NULL, 16);
		ch = ch ^ strtol(c[k-1], NULL, 16);
		printf("%c", (ch & 0xff000000) >> 24);
		printf("%c", (ch & 0x00ff0000) >> 16);
		printf("%c", (ch & 0x0000ff00) >> 8);
		printf("%c", (ch & 0x000000ff));
		k++;
	}
	printf("\n");

	return 0;
}
