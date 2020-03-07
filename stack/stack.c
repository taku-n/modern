#include "stack.h"

bool is_stack_full(Stack *stack);
bool is_stack_empty(Stack *stack);
bool validate(Validator *validator, int val);

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

bool validate_range(Validator *self, int val)
{
	Range *range = (Range *)(self->data);

	return range->min <= val && val <= range->max;
}

bool validate_prev(Validator *self, int val)
{
	Prev *prev = (Prev *)self->data;
	if (val < prev->prev_val) {
		return false;
	}
	prev->prev_val = val;

	return true;
}
