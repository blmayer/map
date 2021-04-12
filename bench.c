#include "map.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void rand_str(FILE *source, int n, char *out) {
	int i = n;
    fread(out, 1, n, source);

	while(i--){
        out[i] = ((out[i] + 255) % 94) + 33;
	}
    out[n-1] = '\0';
}

double time_diff(struct timeval x , struct timeval y) {
	double x_ms, y_ms;
	
	x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
	y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;
	
	return (double)y_ms - (double)x_ms;
}

int main(void) {
    FILE *source = fopen("/dev/urandom", "r");
    char *key, *value;
    long n, times;
    double time = 0;
    struct timeval start = {0,0}, end = {0,0};
    struct node root;

    key = malloc(100);
    value = malloc(100);

    /* Bench addition time */
    puts("op,length,times,usec");
    for (n = 50; n < 5000; n += 50) {
        value = realloc(value, 100);
        rand_str(source, 100, value);
        init(&root);
        
        for (times = 1000; times > 0; times--) {
            key = realloc(key, n);
            rand_str(source, n, key);

            /* Count the time */
            gettimeofday(&start, NULL);
            add(&root, key, value);
            gettimeofday(&end, NULL);
            time += time_diff(start, end);
        }

        printf("add,%ld,1000,%f\n", n, time);

        destroy(&root);
    }

    /* Bench retrieval time */
    for (n = 50; n < 5000; n += 50) {
        value = realloc(value, 100);
        rand_str(source, 100, value);
        init(&root);
        
        for (times = 1000; times > 0; times--) {
            key = realloc(key, n);
            rand_str(source, n, key);

            /* Count the time */
            gettimeofday(&start, NULL);
            add(&root, key, value);
            gettimeofday(&end, NULL);
            time += time_diff(start, end);
        }

        printf("get,%ld,1000,%f\n", n, time);

        destroy(&root);
    }

    /* Bench capacity time */
    init(&root);
    puts("adding elements");
    for (n = 1; n < __INT_MAX__; n++) {
        rand_str(source, 100, value);
        rand_str(source, 100, key);

        /* Count the time */
        gettimeofday(&start, NULL);
        if (!add(&root, key, value)) {
            puts("add() error");
            break;
        }
        gettimeofday(&end, NULL);
        time += time_diff(start, end);
    
        printf("\relements: %ld, time: %f", n, time);
    }
    fclose(source);

    return 0;
}
