#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gen_heap.h"

Heap* CreateHeap(void** data, int num_elems, int (*compare)(void*, void*)) {
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->num_elems = 0;
  heap->compare = compare;
  int i;
  for (i = 0; i < num_elems; i++) {
  Insert(heap, data[i]);
  }

  return heap;
}

void DestroyHeap(Heap* heap) {
  int i;
  for (i = 0; i < PQ_SIZE+1; i++) {
  free(heap->data[i]);
}
  free(heap->data);
  free(heap);
}


int ParentIndex(int child_index) {
  if (child_index == 1)
    return(-1);
  else
    return((int) child_index/2);
}

int YoungChildIndex(int parent_index) {
  return(2 * parent_index);
}

void Insert(Heap* heap, void* new_data_val) {
  heap->num_elems++;
  heap->data[heap->num_elems] = new_data_val;
  BubbleUp(heap, heap->num_elems);
}


void Swap(Heap* heap, int child_index, int parent_index) {
  void* tmp = heap->data[child_index];
  heap->data[child_index] = heap->data[parent_index];
  heap->data[parent_index] = tmp;
}

void BubbleUp(Heap* heap, int index) {
  if (index > 1) {
  int parent = ParentIndex(index);
  if (heap->compare(heap->data[index], heap->data[parent]) < 0) {
    Swap(heap, index, parent);
    BubbleUp(heap, parent);
  }
  }
}

void* Delete(Heap* heap, int position) {
}

void* ExtractMin(Heap* heap) {
  void* val = heap->data[1];
  heap->data[1] = heap->data[heap->num_elems--];
  BubbleDown(heap, 1);
  return val;
}



void BubbleDown(Heap* heap, int index) {
  if (index == 0) return;

  int low_pri_index;
  int left_child = index * 2;
  int right_child = left_child + 1;

  if (left_child < heap->num_elems) {
      if (heap->compare(heap->data[left_child],  heap->data[right_child])
        > 0) {
        low_pri_index = right_child;
      } else {
        low_pri_index = left_child;
      }
    } else if (left_child == heap->num_elems) {
      low_pri_index = left_child;
  } else {
    return;  // NO CHILDREN!!!
  }
  if (heap->compare(heap->data[low_pri_index], heap->data[index]) < 0) {
    Swap(heap, low_pri_index, index);
    BubbleDown(heap, low_pri_index);
  }
}
