#ifndef _DOG
#define _DOG

/**
 * struct dog - the dog structure
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the dog owner
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - the typedef for struct dog
*/
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
