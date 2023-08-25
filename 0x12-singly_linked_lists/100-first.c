#include <stdio.h>
/**
  * before_main - function that runs before main
  * Description: this function is a constructor that runs before the main
  *              function and prints a specific message
  */

void __attribute__((constructor)) before_main()
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
