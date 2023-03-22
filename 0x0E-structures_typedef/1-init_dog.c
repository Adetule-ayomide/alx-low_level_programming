#include <stdlib.h>
#include <stdio.h>

/**
 * init_dog - Initialises a dog structure
 * @d: A dog structure
 * @name: The name of dog
 * @age: Tge age of dog
 * @owner: The owner of the dog
 *
 * Return: Nothing
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
