#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <memory.h>

#define MIN_PRIORITY 0
#define MAX_PRIORITY 99

void *thread(void *arg) {
  const int n = *(int *) arg;
  const int *src = (arg + sizeof(int));
  int *arr = malloc(sizeof(int) * n);
  memcpy(arr, src, sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        arr[j] ^= arr[j + 1];
        arr[j + 1] ^= arr[j];
        arr[j] ^= arr[j + 1];
      }
    }
  }

  clockid_t clock;
  pthread_getcpuclockid(pthread_self(), &clock);
  struct timespec ts;
  clock_gettime(clock, &ts);
  printf("%ld\n", ts.tv_nsec);

  return NULL;
}

int *gen_array(const int n) {
  srand(time(NULL));
  int *arr = malloc(sizeof(int) * (n + 1));
  arr[0] = n;
  for (int i = 1; i <= n; i++) {
    arr[i] = rand() % 100;
  }

  return arr;
}

int main(const int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <number of elements>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const int n = atoi(argv[1]);
  int *src = gen_array(n);

  printf("initial array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", src[i]);
  }
  printf("\n");

  pthread_t *threads = malloc(sizeof(pthread_t) * (MAX_PRIORITY - MIN_PRIORITY + 1));
  clockid_t *clocks = malloc(sizeof(clockid_t) * (MAX_PRIORITY - MIN_PRIORITY + 1));
  for (int i = MIN_PRIORITY; i <= MAX_PRIORITY; i++) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    struct sched_param param;
    param.sched_priority = i;
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&threads[i], &attr, thread, src);
    pthread_attr_destroy(&attr);
    pthread_join(threads[i], NULL);
  }

  for (int i = MIN_PRIORITY; i <= MAX_PRIORITY; i++) {

  }

  free(src);
  free(threads);

  return EXIT_SUCCESS;
}
