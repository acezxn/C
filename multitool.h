#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fatal(char *message) {
  char error_message[100];

  strcpy(error_message, "[!!] Fatal Error ");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}

void *ec_malloc(unsigned int size) {
  void *ptr;
  ptr = malloc(size);
  if(ptr == NULL)
    fatal("in ec_malloc() on memory allocation");
  return ptr;
}

void hexdump(const unsigned char *data_buffer, const unsigned int length) {
  unsigned char byte;
  unsigned int i, j;
  for(i=0; i < length; i++){
    byte = data_buffer[i];
    printf("%02x", data_buffer[i]);
    if(((i%16)==15)||(i==length-1)) {
      for(j=0; j < 15-(i%16); j++)
        printf(" ");
      printf("| ");
      for(j=(i-(i%16)); j <= i; j++) {
        byte = data_buffer[j];
        if((byte > 31) && (byte < 127))
          printf("%c", byte);
        else
          printf(".");
      }
      printf("\n");
    }
  }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fatal(char *message) {
  char error_message[100];

  strcpy(error_message, "[!!] Fatal Error ");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}

void *ec_malloc(unsigned int size) {
  void *ptr;
  ptr = malloc(size);
  if(ptr == NULL)
    fatal("in ec_malloc() on memory allocation");
  return ptr;
}

void hexdump(const unsigned char *data_buffer, const unsigned int length) {
  unsigned char byte;
  unsigned int i, j;
  for(i=0; i < length; i++){
    byte = data_buffer[i];
    printf("%02x", data_buffer[i]);
    if(((i%16)==15)||(i==length-1)) {
      for(j=0; j < 15-(i%16); j++)
        printf(" ");
      printf("| ");
      for(j=(i-(i%16)); j <= i; j++) {
        byte = data_buffer[j];
        if((byte > 31) && (byte < 127))
          printf("%c", byte);
        else
          printf(".");
      }
      printf("\n");
    }
  }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int len) {
  int i;
  for(i=0;i<len;i++) {
    printf("%d ", arr[i]);
  }
}


int power(int z, int p) {
  int x, out=1;
  for(x=0;x<p;x++){
    out = out * z;
  }
  return out;
}

int str2int(char* str) {
  int i, out=0, j=4;
  for(i=0;i<strlen(str);i++) {
    int multiply = power(10, j);
    out = out + ((str[i]-'0') * multiply);
    j--;
  }
  return out;
}

int char2int(char ch) {
  int num = ch - '0';
  return num;
}

int randXrep(int len) {
  srand(time(NULL));
  int d[len], i, total=0;
  int number = 10, r;
  for(i=0;i<len;i++) {
    r=rand() % number;
    d[i] = r;
    if(d[3] == 0) {
      r=rand() % number;
      d[3] = r;
    }
  }
  for(i=0;i<len;i++) {
    if(i == 0) {
      while(d[i] == d[i+3]){
        r=rand() % number;
        d[i] = r;
      }
    }
    if(i == 1) {
      while(d[i]==d[i-1] || d[i]==d[i+1] || d[i]==d[i+2]) {
        r=rand() % number;
        d[i] = r;
      }
    }
    if(i == 2){
      while(d[i]==d[i-2] || d[i]==d[i+1]) {
        r=rand() % number;
        d[i] = r;
      }
    }

  }
  for(i=0;i<len;i++) {
    total = total + d[i] * power(10, i);
  }
  return total;
}

char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  }
  while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

int randint(int begin, int end) {
  int out;
  int r=rand() % (abs(end-begin)+1);
  if(begin<end) {
    out = begin+r;
  }
  else if(begin==end) {
    out = begin;
  } else {
    out = end+r;
  }
  return out;
}


void printArray(int arr[], int len) {
  int i;
  for(i=0;i<len;i++) {
    printf("%d ", arr[i]);
  }
}


int power(int z, int p) {
  int x, out=1;
  for(x=0;x<p;x++){
    out = out * z;
  }
  return out;
}

int str2int(char* str) {
  int i, out=0, j=4;
  for(i=0;i<strlen(str);i++) {
    int multiply = power(10, j);
    out = out + ((str[i]-'0') * multiply);
    j--;
  }
  return out;
}

int char2int(char ch) {
  int num = ch - '0';
  return num;
}

int randXrep(int len) {
  srand(time(NULL));
  int d[len], i, total=0;
  int number = 10, r;
  for(i=0;i<len;i++) {
    r=rand() % number;
    d[i] = r;
    if(d[3] == 0) {
      r=rand() % number;
      d[3] = r;
    }
  }
  for(i=0;i<len;i++) {
    if(i == 0) {
      while(d[i] == d[i+3]){
        r=rand() % number;
        d[i] = r;
      }
    }
    if(i == 1) {
      while(d[i]==d[i-1] || d[i]==d[i+1] || d[i]==d[i+2]) {
        r=rand() % number;
        d[i] = r;
      }
    }
    if(i == 2){
      while(d[i]==d[i-2] || d[i]==d[i+1]) {
        r=rand() % number;
        d[i] = r;
      }
    }

  }
  for(i=0;i<len;i++) {
    total = total + d[i] * power(10, i);
  }
  return total;
}

char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  }
  while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}
