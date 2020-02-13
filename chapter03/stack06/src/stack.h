#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Validator {
	bool (* const p_validate)(struct Validator *p_self, int val);
	void * const p_data;
} Validator;

typedef struct {
	const int min;
	const int max;
} Range;

typedef struct {
	int prev_value;
} PrevValue;

typedef struct {
	int sp;
	const size_t size;
	int * const bp;
	Validator * const p_validator;
} Stack;

bool validate_range(Validator *p_self, int val);
bool validate_prev(Validator *p_self, int val);

bool push(Stack *p, int val);    // true => success, false => failure
bool pop(Stack *p, int *p_ret);  // true => success, false => failure

#define newStack(buf) { \
		0, sizeof(buf) / sizeof(int), (buf), \
		NULL \
		}

#define rangeValidator(p_range) { \
		validate_range, \
		p_range \
		}

#define prevValidator(p_prev) { \
		validate_prev, \
		p_prev \
		}

#define newStackWithValidator(buf, p_validator) { \
		0, sizeof(buf) / sizeof(int), (buf), \
		p_validator \
		}

#endif  // STACK_H
