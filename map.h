#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node map;

struct node {
	int count;
	char letter;
	char *content;
	map *next;
};

int init(map *root);

int add(map *root, char *key, char *data);

char *get(map *root, char *key);

int destroy(map *root);

#endif
