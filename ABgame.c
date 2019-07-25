#include "multitool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char arr[33];
  int ans = randXrep(4);
  char res[20];
  int i, j, a, b, gus = 0, k;
  char int_arr[20] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  printf("%s\n", "Four digit random number GENERATED!");

  while(str2int(res) != ans) {
    a = 0;
    b = 0;
    int wrng = 0;
    printf("%s\n>> ", "Guess a four digit number: ");
    scanf("%s", res);
    if(strlen(res)!=4) {
      printf("%sYou insert %lu digits!\n", "Insert four digits: ", strlen(res));
      continue;
    }
    for(i=0;i<4;i++) {
      if(i == 0) {
        while(res[i] == res[i+3]){
          printf("%s\n", "Digits can not repeat!");
          wrng = 1;
          break;
        }
      }
      if(i == 1) {
        while(res[i]==res[i-1] || res[i]==res[i+1] || res[i]==res[i+2]) {
          printf("%s\n", "Digits can not repeat!");
          wrng = 1;
          break;
        }
      }
      if(i == 2){
        while(res[i]==res[i-2] || res[i]==res[i+1]) {
          printf("%s\n", "Digits can not repeat!");
          wrng = 1;
          break;
        }
      }

    }
    if(wrng == 1) {
      continue;
    }

    for(i=0;i<4;i++) {
      wrng = 1;
      for(k=0;k<10;k++) {
        if (res[i] == int_arr[k]) {
          wrng = 0;
        }
      }
      if(wrng == 1) {
        break;
      }
    }

    if(wrng == 1) {
      printf("%s\n", "Insert digits only!");
      continue;
    }
    gus++;
    itoa(ans, arr, 10);
    for (i=0;i<4;i++) {
      for (j=0;j<4;j++) {
        if (i==j){
          if (res[i] == arr[j]) {
            a++;
            break;
          }

        } else {
          if (res[i] == arr[j]) {
            b++;
            break;
          }
        }
      }
    }
    if (a == 4) {
      printf("Correct! You took %d guesses!\n", gus);
      break;
    }
    printf("%dA%dB\n", a, b);
  }
  return 0;
}
