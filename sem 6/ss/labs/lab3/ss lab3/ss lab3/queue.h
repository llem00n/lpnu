#ifndef QUEUE_H
#define QUEUE_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>

typedef struct queue queue_t;

queue_t* queue_create(VOID);
VOID queue_delete(queue_t*);
BOOL queue_is_empty(queue_t*);
VOID queue_push(queue_t*, DWORD);
DWORD queue_pop(queue_t*);
DWORD queue_peek(queue_t*);
VOID queue_print(queue_t*);

#endif
