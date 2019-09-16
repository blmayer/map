#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	int count;
	char letter;
	char *content;
	struct node *next[];
};

int add(struct node *root, char *key, char *data);

char *get(struct node *root, char *key);

#endif
