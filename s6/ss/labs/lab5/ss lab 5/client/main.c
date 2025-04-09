// client.c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "shared.h"

int compare_ints(const void *a, const void *b) {
  return *(int *) a - *(int *) b;
}

int main() {
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[1024];
  int_array_t *array;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("socket");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  } else {
    printf("Connected to the server\n");
  }

  if (recv(sockfd, buffer, sizeof(buffer) * sizeof(buffer[0]), 0) == -1) {
    perror("recv");
    return 1;
  }

  array = int_array_from_raw(buffer);
  printf("Received: ");
  int_array_for_each_begin(array, el)
    printf("%d ", *el);
  int_array_for_each_end()
  printf("\n");

  qsort(array->data, array->size, sizeof(int), compare_ints);

  printf("Sorted: ");
  int_array_for_each_begin(array, el)
    printf("%d ", *el);
  int_array_for_each_end()
  printf("\n");

  send(sockfd, array, int_array_full_size(array), 0);

  printf("Sent back\n");

  close(sockfd);
  return 0;
}