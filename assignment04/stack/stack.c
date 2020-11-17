#include "stack.h"
#include <stdio.h>

// -1 is failure, 1 is pass

static int stack[STACK_SIZE];

static int *curr_ptr, *start_ptr, *end_ptr;

int stack_init() {
  curr_ptr = &stack[0];
  start_ptr = &stack[0];
  end_ptr = &stack[STACK_SIZE-1];
  return 1;
}

int stack_push(int value) {
  if (curr_ptr <= end_ptr) {
    *curr_ptr = value;
    curr_ptr++;
    return 1;
  }
  return -1;
}

int stack_pop(int *value) {
  if (curr_ptr != start_ptr){
    curr_ptr--;
    *value = *curr_ptr;
    return 1;
  }
  return -1;
}

int stack_is_empty() {
  return (curr_ptr == start_ptr) ? 1 : -1;
}

int stack_is_full() {
  return (curr_ptr > end_ptr) ? 1 : -1;
}
