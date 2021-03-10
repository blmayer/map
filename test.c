#include "map.h"
#include <string.h>

int main(void) {
	map map;
	init(&map);

	int ret = add(&map, "abc", "this is test data abc");
	if (!ret) {
		printf("Error: add1 returned %d\n", ret);
		exit(1);
	}
	puts("add(abc): PASS");

	ret = add(&map, "abcd", "this is test data abcd");
	if (!ret) {
		printf("Error: add2 returned %d\n", ret);
		exit(2);
	}
	puts("add(abcd): PASS");

	ret = add(&map, "abc", "this is the new test data abc");
	if (!ret) {
		printf("Error: add3 returned %d\n", ret);
		exit(3);
	}
	puts("add(abc): PASS");

	/* Checking results */
	char *res = get(&map, "abc");
	if (strcmp(res, "this is the new test data abc") != 0) {
		printf("ERROR: abc returned '%s'\n", res);
		exit(4);
	}
	puts("get(abc): PASS");

	res = get(&map, "abcd");
	if (strcmp(res, "this is test data abcd") != 0) {
		printf("ERROR: abcd returned '%s'\n", res);
		exit(5);
	}
	puts("get(abcd): PASS");

	res = get(&map, "abx");
	if (res) {
		puts("ERROR: abx is not null");
		exit(6);
	}
	puts("get(abx): PASS");
}
