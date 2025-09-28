#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <math.h>
#include<unistd.h>

#define BILLION 1E9

#ifndef ANALYZE_H
#define ANALYZE_H

#define SIZE_START 512
#define ITERATIONS 4
#define NEW_ITERATION 10000

#define SIZE_END 16384
#define two  2

#define MAX 5

typedef enum {
	bubble_sort_t,
	insertion_sort_t,
	quick_sort_t,
	linear_search_t,
	binary_search_t
} algorithm_t;

typedef enum {
	best_t,
	worst_t,
	average_t,
} case_t;

typedef struct {
	int size;
	double time;
} result_t;

void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n);

#endif
