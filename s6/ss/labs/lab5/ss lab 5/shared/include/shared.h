#ifndef SS_LAB_5_SHARED_H
#define SS_LAB_5_SHARED_H

#include <stdlib.h>

typedef struct int_array {
  size_t size;
  int *data;
} int_array_t;

int_array_t *int_array_new(size_t size) {
  int_array_t *array = malloc(sizeof(int_array_t) + size * sizeof(int));
  array->size = size;
  array->data = (int *) (array + 1);
  return array;
}

void int_array_free(int_array_t *array) {
  free(array);
}

int_array_t *int_array_from_raw(void *buffer) {
  int_array_t *array = (int_array_t *) buffer;
  array->data = (int *) (array + 1);
}

size_t int_array_full_size(int_array_t *array) {
  return sizeof(int_array_t) + array->size * sizeof(int);
}

#define int_array_for_each_begin(array, el) \
  for (size_t i = 0; i < array->size; i++) { \
    int *el = &array->data[i];

#define int_array_for_each_end() }

#endif //SS_LAB_5_SHARED_H
