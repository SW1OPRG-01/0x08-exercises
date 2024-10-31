#include <stdlib.h>
#include <stdio.h>

void display(int*, int);
void init_buffer(int*, int);
void move(int*, int**, int); 

int main(int argc, char* argv[]) {
  int buffer_size = atoi(argv[1]);
  int buffer[255];
  init_buffer(buffer, buffer_size);
  int *current = buffer;
  
  for(int i = 2; i < argc; i++) {
    *current = atoi(argv[i]);
    display(buffer, buffer_size);
    move(buffer, &current, buffer_size);
  }

  int input;
  while(1) {
    printf("Enter next value: ");
    scanf("%d", &input);
    *current = input;
    display(buffer, buffer_size);
    move(buffer, &current, buffer_size);
  }

  return 0;
}

void display(int* array, int count) {
  for(int i = 0; i < count; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void init_buffer(int* array, int count) {
  for(int i = 0; i < count; i++) {
    array[i] = 0;
  }
}

void move(int* buffer, int** indexer, int size) {
    if(*indexer == buffer + size - 1) {
      *indexer = buffer;
    } else {
      *indexer += 1;
    }
}
