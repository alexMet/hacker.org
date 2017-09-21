#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// After running the following command
// convert greenline.png -crop '84x1+0+0' txt:- > greenline.txt
// we get the following format:
// 0,0: (  0,116,  0)  #007400  srgb(0,116,0)
// there are only shades of green, so maybe the hex values are letters. So the answer is:
// these bytes are ascii text, as you obviously guessed. your answer is 'ilearnsogood'.

int main(void) {
	int ch, i;
	char let[3];
	FILE *fd;
	fd = fopen("greenline.txt", "r");

	while (1) {
		while ((ch = getc(fd)) != '#');
		fgetc(fd);
		fgetc(fd);

		let[0] = fgetc(fd);
		let[1] = fgetc(fd);
		let[2] = '\0';
		i = strtol(let, NULL, 16);
		printf("%c", i);

		while ((ch = fgetc(fd)) != '\n');
		fgetc(fd);
		if (feof(fd)) break;
	}
	printf("\n");
	return 0;
}
