#include "stack.h"

bool is_stack_full(Stack *stack);
bool is_stack_empty(Stack *stack);
bool validate(Validator *validator, int val);
bool is_odd(int x);
bool is_even(int x);

bool push(Stack *stack, int val)
{
	if (!validate(stack->validator, val) || is_stack_full(stack)) {
		return false;  // failure
	}

	stack->bp[stack->sp] = val;
	stack->sp += 1;

	return true;  // success
}

bool pop(Stack *stack, int *ret)
{
	if (is_stack_empty(stack)) {
		return false;  // failure
	}
	
	stack->sp -= 1;
	*ret = stack->bp[stack->sp];

	return true;  // success
}

bool is_stack_full(Stack *stack)
{
	return stack->sp == stack->size;
}

bool is_stack_empty(Stack *stack)
{
	return stack->sp == 0;
}

bool validate(Validator *validator, int val)
{
	if (!validator) {
		return true;
	}

	return validator->validate(validator, val);
}

bool validate_range(Validator *base, int val)
{
	// 構造体の最初のメンバへのポインタは，構造体へのポインタと同じ
	RangeValidator *self = (RangeValidator *)base;

	return self->min <= val && val <= self->max;
}

bool validate_odd_even_range(Validator *base, int val)
{
	// 構造体の最初のメンバへのポインタは，構造体へのポインタと同じ
	OddEvenRangeValidator *self = (OddEvenRangeValidator *)base;

	if (self->odd_mode == true) {
		if (!is_odd(val)) {
			return false;
		}
	} else {
		if (!is_even(val)) {
			return false;
		}
	}

	return self->base.min <= val && val <= self->base.max;
}

bool is_odd(int x)
{
	return x % 2 == 1;
}

bool is_even(int x)
{
	return x % 2 == 0;
}

bool validate_prev(Validator *base, int val)
{
	// 構造体の最初のメンバへのポインタは，構造体へのポインタと同じ
	PrevValidator *self = (PrevValidator *)base;

	if (val < self->prev_val) {
		return false;
	}
	self->prev_val = val;

	return true;
}
