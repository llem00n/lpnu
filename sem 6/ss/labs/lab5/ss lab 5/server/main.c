#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "shared.h"

int main() {
  int sockfd, connfd, array_size, port = 8080;
  struct sockaddr_in addr, client_addr;
  socklen_t client_addr_len;
  char buffer[1024];

  if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("socket");
    return 1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
    perror("bind");
    return 1;
  }

  printf("Enter array size: ");
  scanf("%d", &array_size);

  int_array_t *array = int_array_new(array_size);
  srand(time(nullptr));
  printf("Generated: ");
  int_array_for_each_begin(array, el)
    *el = -100 + rand() % 200;
    printf("%d ", *el);
  int_array_for_each_end()
  printf("\n");

  if (listen(sockfd, 1) == -1) {
    perror("listen");
    return 1;
  } else {
    printf("Listening on port %d\n", port);
  }

  client_addr_len = sizeof(client_addr);
  if ((connfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len)) == -1) {
    perror("accept");
    return 1;
  } else {
    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
  }

  send(connfd, array, int_array_full_size(array), 0);
  printf("Sent\n");

  recv(connfd, buffer, 1024, 0);
  printf("Received back\n");

  int_array_free(array);
  array = int_array_from_raw(buffer);

  printf("Sorted: ");
  int_array_for_each_begin(array, el)
    printf("%d ", *el);
  int_array_for_each_end()
  printf("\n");

  close(connfd);

  return 0;
}