#ifndef STACK_H
#define STACK_H

#include <stdbool.h>  // bool, true, false
#include <stddef.h>   // NULL, size_t

typedef struct Validator {
	bool (*validate)(struct Validator *self, int val);
	void *data;
} Validator;

typedef struct {
	int sp;
	size_t size;
	int *bp;
	Validator *validator;
} Stack;

typedef struct {
	int min;
	int max;
} Range;

typedef struct {
	int prev_val;
} Prev;

bool push(Stack *stack, int val);  // true => success, false => failure
bool pop(Stack *stack, int *ret);  // true => success, false => failure

bool validate_range(Validator *self, int val);
bool validate_prev(Validator *self, int val);

#endif  // STACK_H
