#include <stdio.h>
#include <string.h>

// we use the letters of the alphabet and we pick the human readable sentence and the answer is
// this cipher is way, way harder than rot thirteen. here, you never know how far to shift! oh by the way, the answer is deadmanschest.

int main(int argc, char **argv) {
	int i, len, k;
	char up[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char low[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char *code = "cqrb lryqna rb fjh, fjh qjamna cqjw axc cqracnnw. qnan, hxd wnena twxf qxf oja cx bqroc! xq kh cqn fjh, cqn jwbfna rb mnjmvjwblqnbc.";
	char letter[300];

	len = strlen(code);
	k = 1;
	while (k <= 26) {
		for (i = 0; i < 26; i++) {
			letter[up[i]] = up[(i+k)%26];
			letter[low[i]] = low[(i+k)%26];
		}

		for (i = 0; i < len; i++) {
			if ((code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= 'a' && code[i] <= 'z'))
				printf("%c", letter[code[i]]);
			else
				printf("%c", code[i]);
		}
		printf("\n");
		k++;
	}
	return 0;
}
