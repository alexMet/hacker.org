#include <stdio.h>
#include <stdlib.h>

// we get the colors of the image by running
// convert blue.png -crop '33x12+0+0' txt:- > blue.txt
// after we run the program we get the following output
// we can see that it says "case" if every line was printed
// in reverse order and we are hinted by the "not oldshape"

/*
:D        $$                *

the answer is not 'oldshape'

	\=--o>  A    } \--=/  \__--.
	I       |    i     |  |
	i       |--_-! -=+:\  I-==~
	!       I    | |      |
	|       /    \ /==>>  /))))>
	`0oOoo   .__,
		 $      here \/
^^      $   look ||   main()
*/

int main(void) {
	int ch, i;
	char let[3];
	FILE *fd;
	fd = fopen("blue.txt", "r");

  int h = 0;
	while (1) {
		while ((ch = getc(fd)) != '#');
		fgetc(fd);
		fgetc(fd);
		fgetc(fd);
		fgetc(fd);

		let[0] = fgetc(fd);
		let[1] = fgetc(fd);
		let[2] = '\0';
		i = strtol(let, NULL, 16);
		printf("%c", i);

		while ((ch = fgetc(fd)) != '\n');
		fgetc(fd);

    if (++h == 33) {
    	printf("\n");
      h = 0;
    }
		if (feof(fd)) break;
	}

	printf("\n");
	return 0;
}
