#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include "queue.h"

int main() {
  queue_t* q = queue_create();

  printf("Is empty: %d\n", queue_is_empty(q));

  if (q == NULL) {
    printf("queue_create failed\n");
    return 1;
  }

  for (DWORD i = 0; i < 10; i++) {
    queue_push(q, i);
  }

  printf("Is empty: %d\n", queue_is_empty(q));

  queue_print(q);

  printf("%d\n", queue_pop(q));
  printf("%d\n", queue_pop(q));
  printf("%d\n", queue_pop(q));
  queue_push(q, 10);
  queue_push(q, 11);
  queue_print(q);

  queue_delete(q);
  return 0;
}