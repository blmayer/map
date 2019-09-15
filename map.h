#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	int count;
	char letter;
	void *content;
	struct node *next[];
};

int add(struct node *root, char *key, void *data, int len);

void *get(struct node *root, char *key);

#endif
