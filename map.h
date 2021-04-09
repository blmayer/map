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

int add(map *root, const char *key, const char *data);

const char *get(map *root, const char *key);

int delete(map *root, const char *key);

int destroy(map *root);

#endif
