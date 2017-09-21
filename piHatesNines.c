#include <stdio.h>
#include <stdlib.h>

// answer is 8606570661584407016735064684551083448304103407143306886135064816123133500844233624141744252203847162068581577800344074422408

static int dig[1000000];

int main(int argc, char **argv) {
	FILE *fd;
	int i, cnt, max = 0, ch, maxi;
	
	fd = fopen(argv[1], "r");
	if (fd == NULL) exit(2);

	i = 0;
	while (1) {
		while ((ch = fgetc(fd)) != '\n') {
			dig[i++] = ch - '0';
		}
		if (i == 1000000) break;
		//for (j = 0; j < i; j++) printf("%d", dig[j]);
	}

	cnt = i = 0;
	while (i < 1000000) {
		if (dig[i] == 9) {
			if (cnt > max) {
				max = cnt;
				maxi = i;
			}
			cnt = 0;
		} else {
			cnt++;
		}
		i++;
	}

	//printf("%d %d\n", max, maxi);
	for (i = maxi - max; i < maxi; i++)
		printf("%d", dig[i]);
	
	printf("\n");
	return 0;
}
