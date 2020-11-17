#include "stack.h"
#include <assert.h>
#include <stdio.h>

/*
  Test Cases
  1. When empty, check that stack_is_empty returns 1 and stack_is_full returns -1
  2. Attempt to pop an element off the stack when the stack is empty, should return -1
  3. When full, check that stack_is_full returns 1 and stack_is_empty returns -1
  4. Attempt to push an element onto the stack when the stack is full, should return -1
  5. Fill stack then empty stack, should return in order; Using a for loop to
     fill/empty stack here because all elements have not been tested yet.
  6. Fill stack, pop one value, push one value, get all values; Testing while loop
     with stack_push and stack_pop as loop as the conditions
  7. Fill stack then empty stack twice; Testing while loop with stack_is_full and
     stack_is_empty as the conditions
*/

int main(){

  int i = 0, j = 0;
  int test_array[STACK_SIZE] = {1,2,3,4,5,6,7,8,9,10};
  int test_int;

  stack_init();

  /* Test 1 */
  assert(1 == stack_is_empty());
  assert(-1 == stack_is_full());

  /* Test 2 */
  assert(-1 == stack_pop(&test_int));

  /* Test 5 - Part 1 */
  for (i = 0; i < STACK_SIZE; i++) {
    assert(1 == stack_push(test_array[i]));
  }

  /* Test 3 */
  assert(-1 == stack_is_empty());
  assert(1 == stack_is_full());

  /* Test 4 */
  assert(-1 == stack_push(test_array[0]));

  /* Test 5 - Part 2 */
  for (i = STACK_SIZE-1; i >= 0; i--) {
    assert(1 == stack_pop(&test_int));
    assert(test_array[i] == test_int);
  }

  /* Test 6 */
  i = 0;
  while (1 == stack_push(test_array[i])){
    i++;
  }
  assert(1 == stack_is_full());

  assert(1 == stack_pop(&test_int));
  assert(1 == stack_push(test_int));

  i = STACK_SIZE-1;
  while (1 == stack_pop(&test_int)){
    assert(test_int == test_array[i]);
    i--;
  }
  assert(1 == stack_is_empty());

  /* Test 7 */
  for (j = 0; j < 2; j++){
    i = 0;
    while (-1 == stack_is_full()){
      assert(1 == stack_push(test_array[i]));
      i++;
    }

    i = STACK_SIZE-1;
    while (-1 == stack_is_empty()){
      assert(1 == stack_pop(&test_int));
      assert(test_int == test_array[i]);
      i--;
    }
  }

  return 0;
}
