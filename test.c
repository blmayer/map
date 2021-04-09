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

	ret = add(root, "a", "this is the new test data a");
	if (!ret) {
		printf("Error: add4 returned %d\n", ret);
		exit(4);
	}
	puts("add(a): PASS");

	ret = add(root, "ab", "this is the new test data ab");
	if (!ret) {
		printf("Error: add5 returned %d\n", ret);
		exit(5);
	}
	puts("add(ab): PASS");
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
		printf("get(abcd) ERROR: abcd returned '%s'\n", res);
		exit(5);
	}
	puts("get(abcd): PASS");

	res = get(root, "abx");
	if (res) {
		puts("get(abcd) ERROR: abx is not null");
		exit(6);
	}
	puts("get(abx): PASS");
}

void testdelete(map *root) {
	int res;
	const char *content;

	res = delete(root, "abc");
	if (!res) {
		puts("ERROR removing abc");
		exit(7);
	}

	content = get(root, "abc");
	if (content) {
		puts("ERROR: abc is not null");
		exit(8);
	}
	puts("delete(abc): PASS");

	res = delete(root, "ac");
	if (!res) {
		puts("ERROR removing ac");
		exit(9);
	}

	content = get(root, "ac");
	if (content) {
		puts("ERROR: abc is not null");
		exit(10);
	}

	content = get(root, "a");
	if (!content) {
		puts("get(a) ERROR: a is null");
		exit(10);
	}
	puts("remove(ac): PASS");
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
	puts("# ==== Testing add ======================== #");
	testadd(&map);

	puts("# ==== Testing get ======================== #");
	testget(&map);

	puts("# ==== Testing delete ======================== #");
	testdelete(&map);

	puts("# ==== Testing destroy ======================== #");
	testdestroy(&map);
}
