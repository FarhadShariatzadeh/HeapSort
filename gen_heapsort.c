#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gen_heapsort.h"
#include "gen_heap.h"

void Heapify(Heap* heap, int which_elem) {
  int left = which_elem * 2;
  int right = left + 1;
  int lowest = which_elem;
  if (left <= heap->num_elems && heap->compare(heap->data[left],
  heap->data[lowest]) < 0) {
    lowest = left;
  } else {
    lowest = which_elem;
  }

  if (right <= heap->num_elems && heap->compare(heap->data[right],
  heap->data[lowest]) < 0) {
      lowest = right;
  }

  if (lowest != which_elem) {
    Swap(heap, which_elem, lowest);
    Heapify(heap, lowest);
  }
}

void HeapSort(void** data, int num_elems, int (*Compare)(void*, void*)) {
  Heap* heap = CreateHeap(data, num_elems, Compare);
  int i;
  for (i = 0; i < num_elems; i++) {
    data[i] = ExtractMin(heap);
  }
  free(heap);
}

