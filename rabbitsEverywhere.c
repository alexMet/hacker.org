#include <stdio.h>

// answer is 4092

int main() {
	int f[18], sum, i;

	f[0] = 0;
	f[1] = 1;
	for (i = 2; i < 18; i++) f[i] = f[i-2] + f[i-1];

	sum = 0;
	for (i = 10; i < 18; i++) sum += f[i];
	printf("%d\n", sum);

	return 0;
}
