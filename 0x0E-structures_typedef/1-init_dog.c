#include "dog.h"
#include <stddef.h>
/**
 * init_dog - function that initialize a variable of type dog struct
 * @d: the input pointer to struct dog
 * @name: the input for the dog name
 * @age: the input for the dog age
 * @owner: the input for the dog owner
 *
 * Return: nothing
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
