#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table you want to add or update
 * @key: the key (can not be an empty string)
 * @value: value associated with the key
 * Return: 1 if it succeeded || 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	unsigned long int i, pos;
	char *n_val;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	n_val = strdup(value);
	if (n_val == NULL)
		return (0);

	pos = key_index((const unsigned char *)key, ht->size);

	for (i = pos; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = n_val;
			return (1);
		}
	}
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(n_val);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = n_val;
	new->next = ht->array[pos];
	ht->array[pos] = new;
	return (1);
}
