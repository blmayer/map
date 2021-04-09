#include "map.h"
#include <string.h>

void testadd(map *root) {
	int ret = add(root, "abc", "this is test data abc");
	if (!ret) {
		printf("Error: add1 returned %d\n", ret);
		exit(1);
	}
	puts("add(abc): PASS");

	ret = add(root, "abcd", "this is test data abcd");
	if (!ret) {
		printf("Error: add2 returned %d\n", ret);
		exit(2);
	}
	puts("add(abcd): PASS");

	ret = add(root, "abc", "this is the new test data abc");
	if (!ret) {
		printf("Error: add3 returned %d\n", ret);
		exit(3);
	}
	puts("add(abc): PASS");
}

void testget(map *root) {
	const char *res = get(root, "abc");
	if (strcmp(res, "this is the new test data abc") != 0) {
		printf("ERROR: abc returned '%s'\n", res);
		exit(4);
	}
	puts("get(abc): PASS");

	res = get(root, "abcd");
	if (strcmp(res, "this is test data abcd") != 0) {
		printf("ERROR: abcd returned '%s'\n", res);
		exit(5);
	}
	puts("get(abcd): PASS");

	res = get(root, "abx");
	if (res) {
		puts("ERROR: abx is not null");
		exit(6);
	}
	puts("get(abx): PASS");
}

void testdelete(map *root) {
	int res;

	res = delete(root, "abc");
	if (!res) {
		puts("ERROR removing abc");
		exit(7);
	}

	const char *content = get(root, "abc");
	if (content) {
		puts("ERROR: abc is not null");
		exit(8);
	}
	puts("remove(abc): PASS");
}

void testdestroy(map *root) {
	int res;

	res = destroy(root);
	if (!res) {
		puts("ERROR: destroy returned 0");
		exit(9);
	}
	puts("destroy(root): PASS");
}

int main(void) {
	map map;
	init(&map);

	/* Starting tests */
	puts("Testing add");
	testadd(&map);

	puts("Testing get");
	testget(&map);

	puts("Testing delete");
	testdelete(&map);

	puts("Testing destroy");
	testdestroy(&map);
}
