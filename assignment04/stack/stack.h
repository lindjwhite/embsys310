#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE    10

int stack_init();
int stack_push(int value);
int stack_pop(int *value);
int stack_is_empty();
int stack_is_full();

#endif
