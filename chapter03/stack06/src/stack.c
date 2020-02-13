#include <stdbool.h>
#include "stack.h"

static bool is_stack_full(const Stack *p_stack)
{
	return p_stack->sp == p_stack->size;
}

static bool is_stack_empty(const Stack *p_stack)
{
	return p_stack->sp == 0;
}

bool validate_range(Validator *p_self, int val)
{
	Range *p_range = (Range *)(p_self->p_data);
	return p_range->min <= val && val <= p_range->max;
}

bool validate_prev(Validator *p_self, int val)
{
	PrevValue *p_prev = (PrevValue *)p_self->p_data;
	if (val < p_prev->prev_value) {
		return false;
	}
	p_prev->prev_value = val;
	return true;
}

bool validate(Validator *p, int val)
{
	if (!p) {
		return true;
	}
	return p->p_validate(p, val);
}

bool push(Stack *p_stack, int val)
{
	if (!validate(p_stack->p_validator, val) || is_stack_full(p_stack)) {
		return false;
	}
	p_stack->bp[p_stack->sp++] = val;
	return true;
}

bool pop(Stack *p_stack, int *p_ret)
{
	if (is_stack_empty(p_stack)) {
		return false;
	}
	*p_ret = p_stack->bp[--p_stack->sp];
	return true;
}
