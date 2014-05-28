#include <assert.h>
#include "cc_heapsort.h"
#include <time.h>
#include <stdlib.h>

int int_comp(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

void test1() {
  int arr[] = {4,1};
  size_t size = sizeof(arr)/sizeof(int);

  cc_heapsort(arr, size, sizeof(int), int_comp);

  assert(arr[0] < arr[1]);
}

void test2() {
  int arr[] = {8,7,6,5,4,3,2,1};
  size_t size = sizeof(arr)/sizeof(int);

  cc_heapsort(arr, size, sizeof(int), int_comp);

  for (int i = 0; i < size - 1; i++) {
    assert(arr[i] < arr[i + 1]);
  }
}

void test3() {
  int arr[10]; 
  size_t size = sizeof(arr)/sizeof(int);

  // Fill with random numbers
  for (int i = 0; i < size; i++) {
    arr[i] = rand();
  }

  cc_heapsort(arr, size, sizeof(int), int_comp);

  for (int i = 0; i < size - 1; i++) {
    assert(arr[i] < arr[i + 1]);
  }
}

int main() {
  srand(time(NULL));

  test1();
  test2();
  test3();

  return 0;
}
