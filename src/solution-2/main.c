#include <stdio.h>
#include <stdlib.h>

void display(int* array, int count) {
  for(int i = 0; i < count; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {

  const size_t SIZE = 4;
  
  int buf[SIZE];
  
  for(size_t i = 0; i < SIZE; i++) {
    buf[i] = -1;
  }
  
  int *start = buf;
  int *current = buf;
  int *end = &buf[SIZE-1];

  int input;
  while (1) {
    scanf("%d", &input);
    *current = input;
    if(current != end) {
      current = current + 1; 
    } else {
      current = start;
    }
    display(buf, SIZE);
  }

  return 0;
}