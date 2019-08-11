#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int count;
	char letter;
	void *content;
	struct node *next[];
};

int add(struct node *root, char *key, void *data);

void *get(struct node *root, char *key);

#endif
