#include <stdio.h>
#include <string.h>

// answer is 1492

int main(int argc, char **argv) {
	char t[] = "93752xxx746x27x1754xx90x93xxxxx238x44x75xx08750912738x8461x8759383xx328x4x4935903x6x5550360535004x0xx945958961296x267x8842xxx5x6xx61x4x48482x80xxx83316843x7x4x83x9521731xxx25x51xx457x6x5x9698222x771237745034x5133592x27xx8x87xx35221x36x0x50x23x7x63x998418xx";
	unsigned int len, i, j, sum;

	i = sum = 0;
	len = strlen(t);
	//printf("%d\n", len);
	while (i < len) {
		if (t[i] == 'x') {
			sum += (t[i-2] - '0') + (t[i-1] - '0');
			for (j = i; j < len-1; j++) {
				t[j] = t[j+1];
			}
			len--;
		} else {
			sum += (t[i] - '0');
			i++;
		}
	//	printf("%d %d %c %d\n", len, i, t[i], t[i]- '0');
	}
	printf("%d\n", sum);
	return 0;
}
