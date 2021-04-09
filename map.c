#include "map.h"

int init(map *root) {
	if (!root) {
		return 0;
	}

	root->count = 0;
	root->next = NULL;
	root->content = NULL;

	return 1;
}

int add(map *root, char *key, char *data) {
	map *curr = root;
	char found = 0;
	int i = 0, len = 0;

	while (*key) {
		/* Check next */
		for (i = 0; i < curr->count; i++) {
			if (curr->next[i].letter == *key) {
				curr = (curr->next+i);
				found = 1;
				break;
			}
		}

		if (found) {
			found = 0;
			*key++;
			continue;
		}

		/* Create the next element if not at end of key */
		if (*key) {
			curr->count++;
			if (!curr->next) {
				curr->next = malloc(sizeof(map));
			} else {
				curr->next = realloc(curr->next, (curr->count) * sizeof(map));
			}
			if (!curr->next) {
				puts("next allocation error");
				return 0;
			}

			curr = &curr->next[curr->count - 1];
			if (!init(curr)) {
				puts("initialization error");
				return 0;
			}
		}
		curr->letter = *(key++);
	}

	/* Free previous data */
	if (curr->content) {
		free(curr->content);
	}

	while (data[len++]) {
		;
	}

	curr->content = malloc(len);
	if (!curr->content) {
		puts("content allocation error");
		return 0;
	}

	while (len--) {
		curr->content[len] = data[len];
	}

	return 1;
}

char *get(map *root, char *key) {
	map *curr = root;
	int i = 0;
	while (*key) {
		for (i = 0; i < curr->count; i++) {
			if (curr->next[i].letter == *key) {
				curr = &curr->next[i];
				break;
			}
		}

		key++;
	}
	return curr->content;
}

int delete(map *root, char *key) {
	map *curr = root;
	int i = 0;
	while (*key) {
		for (i = 0; i < curr->count; i++) {
			if (curr->next[i].letter == *key) {
				curr = &curr->next[i];
				break;
			}
		}

		key++;
	}

	/* Delete only the content */
	if (curr->content) {
		free(curr->content);
		curr->content = NULL;
	}

	return 1;
}

int destroy(map *root) {
	int i, count = 1;

	/* Descent into each next element and destroy it */
	for (i = 0; i < root->count; i++) {
		count += destroy(&root->next[i]);
	}
	
	/* Erase itself	*/
	if (root->content) {
		free(root->content);
	}
	if (root->next) {
		free(root->next);
	}
	
	return count;
}
