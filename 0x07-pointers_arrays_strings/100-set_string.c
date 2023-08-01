#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * set_string - Sets the value of a pointer to a char.
 * @s: The pointer to be modified.
 * @to: The string to set the pointer to.
 */

void set_string(char **s, char *to)
{
	*s = to;
}
