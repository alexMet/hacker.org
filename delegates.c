#include <stdio.h>
#include <math.h>

// answer is 2277532

int main() {
	int i, sum, to;
	int p[10000];

	to = sqrt(2118);
	sum = 0;
	for (i = 0; i < 10000; i++) p[i] = 0;
	for (i = 1; i <= to; i++) p[i*i] = 1;
	for (i = 0; i <= 2118; i++) 
		if (p[i] == 1) sum += 2*i;
		else sum += i;

	printf("%d\n", sum);
	return 0;
}
