#ifndef _CALC
#define _CALC
/**
  * struct op - the structure for holding operation data
  * @op: the operator symbol
  * @f: a function pointer to the corresponding operation function
  */

typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif
