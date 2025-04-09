#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE 32 // Size of data block in bits

// Replace this with your actual Feistel function (f function)
uint32_t f(uint32_t right, uint32_t key) {
  // Implement your desired logic here.
  // This example simply performs XOR with the key.
  return right ^ key;
}

// Feistel round function
uint32_t feistel_round(uint32_t left, uint32_t right, uint32_t key) {
  return left ^ f(right, key);
}

// Encryption function
uint64_t encrypt(uint32_t left, uint32_t right, uint32_t rounds, uint32_t keys[]) {
  for (int i = 0; i < rounds; i++) {
    uint32_t temp = right;
    right = feistel_round(left, right, keys[i]);
    left = temp;
  }

  // Combine left and right halves into a single 64-bit value
  uint64_t ciphertext = ((uint64_t)left << BLOCK_SIZE) | right;
  return ciphertext;
}

// Decryption function (similar to encryption but with reversed key order)
uint64_t decrypt(uint64_t ciphertext, uint32_t rounds, uint32_t keys[]) {
  uint32_t left = (uint32_t)(ciphertext >> BLOCK_SIZE);
  uint32_t right = (uint32_t)(ciphertext);

  for (int i = rounds - 1; i >= 0; i--) {
    uint32_t temp = left;
    left = feistel_round(right, left, keys[i]);
    right = temp;
  }

  return ((uint64_t)left << BLOCK_SIZE) | right;
}

int main() {
  uint32_t message[] = {0x12345678, 0xABCDEF00, 0x12345678, 0xABCDEF00 };
  constexpr uint32_t message_size = sizeof(message) / sizeof(message[0]);
  uint32_t ciphertext[message_size], decrypted[message_size];
  uint32_t key[4] = {0x0F0F0F0F, 0xF0F0F0F0, 0x0F0F0F0F, 0xF0F0F0F0};
  uint32_t rounds = 4;

  printf("Original  message: ");
  for (int i = 0; i < message_size; i++) {
    printf("0x%08X ", message[i]);
  }
  printf("\n");

  for (int i = 0; i < message_size; i += 2) {
    uint64_t encrypted = encrypt(message[i], message[i + 1], rounds, key);
    ciphertext[i] = (uint32_t)(encrypted >> BLOCK_SIZE);
    ciphertext[i + 1] = (uint32_t)(encrypted);
  }

  printf("Encrypted message: ");
  for (int i = 0; i < message_size; i++) {
    printf("0x%08X ", ciphertext[i]);
  }
  printf("\n");

  for (int i = 0; i < message_size; i += 2) {
    uint64_t decrypted_val = decrypt(((uint64_t)ciphertext[i] << BLOCK_SIZE) | ciphertext[i + 1], rounds, key);
    decrypted[i] = (uint32_t)(decrypted_val >> BLOCK_SIZE);
    decrypted[i + 1] = (uint32_t)(decrypted_val);
  }

  printf("Decrypted message: ");
  for (int i = 0; i < message_size; i++) {
    printf("0x%08X ", decrypted[i]);
  }
  printf("\n");

  return 0;
}
