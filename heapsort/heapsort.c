#include "cc_heapsort.h"
#include <string.h>

int parent_for(int i) {
  if (i == 0) {
    return -1;
  }

  return (i-1)/2;
}

int left_index_for(int i) {
  return i*2 + 1;
}

int right_index_for(int i) {
  return i*2 + 2;
}

void *offset(void *base, int index, size_t width) {
  return (void *)((char *)base + index * width);
}

void *swap(void *a, void *b, size_t width) {
  unsigned char buffer[width];
  memcpy(buffer, a, width);
  memcpy(a, b, width);
  memcpy(b, buffer, width);
}

// Assumes the heap is in the correct state sans index
void heapify_down(void *base, size_t nel, size_t width, compare_t comp, int index) {
  int left_index = left_index_for(index);
  int right_index = right_index_for(index);
  void *elem = offset(base, index, width);

  if (left_index < nel) {
    int candidate_index = left_index;

    if (right_index < nel) {
      void *left_elem = offset(base, left_index, width);
      void *right_elem = offset(base, right_index, width);

      if (comp(left_elem, right_elem) > 0) {
        candidate_index = right_index;
      }
    }

    void *candidate_elem = offset(base, candidate_index, width);

    if (comp(elem, candidate_elem) > 0) {
      swap(elem, candidate_elem, width); 
      heapify_down(base, nel, width, comp, candidate_index);
    }
  }
}

// Assumes that the heap is in the correct state sans index
void heapify_up(void *base, size_t nel, size_t width, compare_t comp, int index) {
  int parent_index = parent_for(index);

  if (parent_index == -1) {
    return;
  }

  void *elem = offset(base, index, width);
  void *parent_elem = offset(base, parent_index, width);

  if (comp(parent_elem, elem) > 0) {
    swap(elem, parent_elem, width);
    heapify_up(base, nel, width, comp, parent_index);
  }
}

void cc_heapsort(void *base, size_t nel, size_t width, compare_t comp) {

  // Build heap invariant
  for (int i = 0; i < nel; i++) {
    heapify_up(base, i + 1, width, comp, i);
  }

  // TODO -- sort and swap remaining items
  for (int i = 1; i <= nel; i++) {
    void *next_elem = offset(base, nel - i, width);
    swap(next_elem, base, width);
    heapify_down(base, nel - i, width, comp, 0);
  }
}
