#ifndef _CC_HEAPSORT_H_
#define _CC_HEAPSORT_H_

#include <stddef.h>

typedef int (*compare_t)(const void *a, const void *b);

// Creates an opportunity 
void cc_heapsort(void *mutable_array, size_t nel, size_t width, compare_t);

#endif
