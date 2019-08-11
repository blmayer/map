#include "map.h"

int add(struct node *root, char *key, void *data)
{
	struct node *curr = root;
	while (*key) {
		// Create the array for the first time
		if (curr->count == 0) {
			*curr->next = malloc(sizeof(struct node *));
		}

		char found = 0;
		for (int i = 0; i < curr->count; i++) {
			if (curr->next[i]->letter == *key) {
				curr = curr->next[i];
				found = 1;
				break;
			}
		}

		if (!found) {
			/* Key was not found, create one */
			curr->next[curr->count] = malloc(sizeof(struct node));
			curr->next[curr->count]->letter = *key;
			curr->next[curr->count]->content = NULL;
			curr->next[curr->count]->count = 0;
			curr->count++;
			curr = curr->next[curr->count - 1];
		}

		key++;
	}

	/* Free previous data */
	if (curr->content) {
		free(curr->content);
	}

	curr->content = malloc(strlen(data) + 1);
	memcpy(curr->content, data, strlen(data) + 1);

	return 1;
}

void *get(struct node *root, char *key)
{
	struct node *curr = root;
	while (*key) {
		for (int i = 0; i < curr->count; i++) {
			if (curr->next[i]->letter == *key) {
				curr = curr->next[i];
				break;
			}
		}

		key++;
	}
	return curr->content;
}
