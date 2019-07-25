#include <stdio.h>
#include <stdlib.h>
int main(void) {
  char chara;
  printf("%s\n", "Insert one character: ");
  scanf("%c", &chara);
  printf("Ascii code %d\n", (int)chara);
  return 0;
}
