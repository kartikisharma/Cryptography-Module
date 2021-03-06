#include "caesar_cipher.c"
#include "pig_latin.c"
#include <string.h>
#include <stdio.h>
#include "crypto.h"
// Main Program file

int main(void) {
  char command[15];
  printf("Welcome to Cryptography Program!\n");
  while(1) {
    printf("Command? ('piglatin', 'caesar_encode', 'caesar_decode' or 'quit')\n");
    scanf("%s", command);
    int key;
    char word[81];
    char result[83];
    if (strcmp(command, "piglatin") == 0) {
      printf("Enter a message at most 80 characters long:\n");
      if (scanf("%s", word) != 1) break;
      pig_latin(word, result);
      printf("%s\n", result);
    }
    else if (strcmp(command, "encode") == 0) {
      while (1) {
        printf("Enter a key from 1 to 25:\n");
        int RetVal = scanf("%d", &key);
        if ((1 <= key)  && (key <= 25)) {
          char msg[81];
          input_msg(key, msg);
          printf("The encoded message is:\n");
          encode(msg, key);
          break;
        }
        else if ((RetVal != 1) || (key > 25) || (key < 1)) {
          printf("Invalid key! ");
        }
      }
    }
    else if(strcmp(command, "decode") == 0) {
    // note to self: get rid of the repetitive code below
      while (1) {
        printf("Enter a key from 1 to 25:\n");
        int RetVal = scanf("%d", &key);
        if ((1 <= key)  && (key <= 25)) {
          char msg[81];
          input_msg(key, msg);
          printf("The original message is:\n");
          decode(msg, key);
          break;
        }
        else if ((RetVal != 1) || (key > 25) || (key < 1)) {
          printf("Invalid key! ");
        }
      }
    }
    else if (strcmp(command, "quit") == 0) {
      printf("The program has been terminated!\n");
      break;
    }
    else {
    printf("Invalid input!\n");
    }
  }
}

