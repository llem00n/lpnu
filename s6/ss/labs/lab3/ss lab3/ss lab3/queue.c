#include "queue.h"
#include <stdio.h>

#define QUEUE_CAPACITY (8 * 1024)

struct queue {
  unsigned* arr;
  SIZE_T size;
  SIZE_T start;
  SIZE_T capacity;
};

queue_t* queue_create(VOID) {
  queue_t* q = (queue_t*)VirtualAlloc(NULL, sizeof(queue_t), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (q == NULL) {
    return NULL;
  }

  q->arr = (DWORD*)VirtualAlloc(NULL, QUEUE_CAPACITY * sizeof(unsigned), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (q->arr == NULL) {
    VirtualFree(q, 0, MEM_RELEASE);
    return NULL;
  }

  q->size = 0;
  q->start = 0;
  q->capacity = QUEUE_CAPACITY;
  return q;
}

VOID queue_delete(queue_t* q) {
  if (q == NULL) {
    return;
  }
  VirtualFree(q->arr, 0, MEM_RELEASE);
  VirtualFree(q, 0, MEM_RELEASE);
}

BOOL queue_is_empty(queue_t* q) {
  return q->size == 0;
}

VOID queue_push(queue_t* q, DWORD data) {
  if (q->size == q->capacity) {
    return;
  }

  q->arr[(q->size + q->start) % q->capacity] = data;
  q->size++;
}

DWORD queue_pop(queue_t* q) {
  if (queue_is_empty(q)) {
    return 0;
  }

  DWORD data = q->arr[q->start++];
  q->size--;
  return data;
}

DWORD queue_peek(queue_t* q) {
  if (queue_is_empty(q)) {
    return 0;
  }

  return q->arr[q->start];
}

VOID queue_print(queue_t* q) {
  if (queue_is_empty(q)) {
    return;
  }

  for (int i = q->size - 1; i >= 0; i--) {
    printf("%d ", q->arr[(q->start + i) % q->capacity]);
  }
  printf("\n");
}
