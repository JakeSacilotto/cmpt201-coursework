#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Jake Sacilotto
// 301595190
// Lab 1 Jan 16 

// look at man page for getline
// look at man page for strtok_r()

int main() {

  while (1) {

    printf("Please enter some text: ");

    char *buff = NULL;
    size_t size = 0;
    ssize_t num_char = getline(&buff, &size, stdin);
    if (num_char == -1) {
      perror("getline failed");
      exit(EXIT_FAILURE);
    }
    printf("Tokens: \n");

    char *saveptr;
    char *ret = strtok_r(buff, " ", &saveptr);
    // now if its second call or null we have diff line
    // this will enter the loop if there are words to print
    // if it turns NULL that means no more tokens
    while (ret != NULL) {
      printf("  %s\n", ret);
      ret = strtok_r(NULL, " ", &saveptr);
    }
    free(buff);
  }
}
