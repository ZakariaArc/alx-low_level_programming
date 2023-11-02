#include "hash_tables.h"
/**
 * key_index - returns the index at which the key/value pair
 *             should be stored in the array of the hash table
 * @key: the key for which the index is calculated
 * @size: the size of the array of the hash table
 * Return: the index at which the key should be stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
