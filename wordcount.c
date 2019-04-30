// Binary Search Tree Application: Word Frequency
// Ryan Krawczyk (CSCI227103)

#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 80

struct wordcount {
	char word[MAX];
	int count;
};
typedef struct wordcount WordCount;

WordCount *topFreq;

// Dynamically allocates memory for WordCount structure
WordCount *createWordNode(char *s) {
	WordCount *node = (WordCount *) malloc(sizeof(WordCount));
	strcpy(node->word, s);
	node->count = 0;
	return node;
}

// Accesses string comparator of ASCII code for word fields of WordCount structure
int compare(WordCount *w1, WordCount *w2) {
	return strcmp(w1->word, w2->word);
}

// Inserts WordCount node into tree, updates top frequency word based on count field
void addWord(BSTnode *root, char *s) {
	WordCount *node = createWordNode(s);
	insert(root, node, compare);
	BSTnode *currentNode = find(root, node, compare);
	WordCount *currentWord = currentNode->item;
	currentWord->count += 1;
	if (currentWord->count > topFreq->count) topFreq = currentWord;
}

int main() {
	char *nextWord = (char *) malloc(MAX * sizeof(char));
	int rs = scanf("%s", nextWord);
	WordCount *node = createWordNode(nextWord);
	node->count += 1;
	BSTnode *root = createNode(node);
	topFreq = node;
	rs = scanf("%s", nextWord);
	while (rs != -1) {
		addWord(root, nextWord);
		rs = scanf("%s", nextWord);
	}
	printf("\nThe most frequent word is \"%s\", which appears %d times.\n\n", topFreq->word, topFreq->count);
	free(nextWord);
	return 0;
}

