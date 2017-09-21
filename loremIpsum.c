#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// answer is scatterbrained

struct tree_node {
	char *word;
	int x;
	struct tree_node *left;
	struct tree_node *right;
};

int isLetter(int ch) {
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

FILE *open_file(char *name) {
	FILE *fd;

	if ((fd = fopen(name, "r")) == NULL) {
		fprintf(stderr, "Could not open file!\n");
		exit(15);
	}
	return fd;
}

void read_word_from_file(FILE *fd, char *buf, int *x, int *y, int *fx, int *fy) {
	int ch, i = 0, found = 0;

	while (found == 0) {
		ch = fgetc(fd);
		if (feof(fd)) return;
		if (ch == ' ') *fx += 1;
		if (ch == '\n') {
			*fy += 1;
			*fx = 1;
		}
		if (isLetter(ch)) {
			*x = *fx;
			*fx += 1;
			*y = *fy;
			buf[i++] = ch;
			while ((ch = fgetc(fd)) && isLetter(ch)) {
				*fx += 1;
				buf[i++] = ch;
			}
			buf[i] = '\0';
			if (ch == ' ') *fx += 1;
			if (ch == '\n') {
				*fy += 1;
				*fx = 1;
			}
			found = 1;
		}
	}
}

struct tree_node *add_to_binary_tree_and_return_pointer(struct tree_node **thisTreeNode, char *the_word) {
	int comp, where = 0;	
	struct tree_node *newTreeNode, *curTreeNode;

	curTreeNode = *thisTreeNode;
	while (curTreeNode != NULL) {
		comp = strcmp(the_word, curTreeNode->word);
		if (comp == 0) {
			curTreeNode->x += 1;
			return curTreeNode;
		}
		else if ((comp < 0) && (curTreeNode->left == NULL)) {
			where = 1;
			break;
		}
		else if ((comp < 0) && (curTreeNode->left != NULL)) {
			curTreeNode = curTreeNode->left;
		}
		else if ((comp > 0) && (curTreeNode->right == NULL)) {
			where = 2;
			break;
		}
		else {
			curTreeNode = curTreeNode->right;
		}	
	}

	if ((newTreeNode = malloc(sizeof(struct tree_node))) == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		exit(11);
	}

	if ((newTreeNode->word = malloc((strlen(the_word)+1) * sizeof(char))) == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		exit(12);
	}
	strcpy(newTreeNode->word, the_word);
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	newTreeNode->x = 1;
	if (where == 0) (*thisTreeNode) = newTreeNode;
	if (where == 1) curTreeNode->left = newTreeNode;
	if (where == 2) curTreeNode->right = newTreeNode;
	return newTreeNode;
}



void search_in_database(struct tree_node *thisTreeNode) {
	int comp;	
	struct tree_node *curTreeNode;

	curTreeNode = thisTreeNode;
	if (curTreeNode->x == 1)
		printf("%s\n", curTreeNode->word);
		
	if (curTreeNode->right != NULL)
		search_in_database(curTreeNode->right);

	if (curTreeNode->left != NULL)
		search_in_database(curTreeNode->left);
}

int main(int argc, char **argv) {
	FILE *fd;
	int row, col, frow, fcol, i;
	char word_buf[100], fileName_buf[100];
	struct tree_node *hashTable[0];
	struct tree_node *tree;

	if (argc != 2) {
		fprintf(stderr, "USAGE: %s file_name.txt\n", argv[0]);
		exit(1);
	}
	else 
		fd = open_file(argv[1]);

	row = col = frow = fcol = 1;
	read_word_from_file(fd, word_buf, &row, &col, &frow, &fcol);
	while (!feof(fd)) {
		tree = add_to_binary_tree_and_return_pointer(&hashTable[0], word_buf);
		read_word_from_file(fd, word_buf, &row, &col, &frow, &fcol);
	}
	fclose(fd);
	
	tree = hashTable[0];
	search_in_database(tree);
	
	return 0;
}
