#include <stdio.h>

#include "stack.h"

int main(int argc, char *argv[], char *envp[])
{
	// No Validator

	int buf[4];
	Stack stack = {0, sizeof(buf) / sizeof(int), buf, NULL};

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	int ret;
	pop(&stack, &ret);
	printf("poped => %d\n", ret);  //=> 3
	pop(&stack, &ret);
	printf("poped => %d\n", ret);  //=> 2
	pop(&stack, &ret);
	printf("poped => %d\n", ret);  //=> 1

	// Range Validator

	Range range = {0, 9};
	Validator validator_range = {validate_range, &range};

	int buf_range[4];
	Stack stack_range = {0, sizeof(buf_range) / sizeof(int), buf_range, &validator_range};

	push(&stack_range, 1);
	push(&stack_range, 2);
	push(&stack_range, 3);

	pop(&stack_range, &ret);
	printf("poped => %d\n", ret);  //=> 3
	pop(&stack_range, &ret);
	printf("poped => %d\n", ret);  //=> 2
	pop(&stack_range, &ret);
	printf("poped => %d\n", ret);  //=> 1

	printf("%d\n", push(&stack_range, 42));

	// Prev Validator

	Prev prev = {0};
	Validator validator_prev = {validate_prev, &prev};

	int buf_prev[4];
	Stack stack_prev = {0, sizeof(buf_prev) / sizeof(buf_prev), buf_prev, &validator_prev};

	return 0;
}
