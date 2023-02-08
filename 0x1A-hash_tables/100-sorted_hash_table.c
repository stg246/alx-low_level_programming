#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: size of the underlying array
 *
 * Return: The created hash table or NULL on error or if size == 0
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new = NULL;
	shash_node_t **array;

	array = calloc(size, sizeof(*array));
	if (!size || !array)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
	{
		free(array);
		return (NULL);
	}

	new->size = size;
	new->array = array;
	new->shead = NULL;
	new->stail = NULL;

	return (new);
}

/**
 * shash_table_update - Updates an element in a sorted hash table
 * @ht: pointer to the ordered hash table
 * @key: The key string
 * @value: The value associated with the key
 * @index: The calculated index associated with the key
 *
 * Return: (1) on success or (0) otherwise
 */
int shash_table_update(shash_table_t *ht, const char *key, const char *value,
			unsigned long int index)
{
	shash_node_t *current;

	if (!ht || !key || !value || !*key)
		return (0);

	current = ht->array[index];
	while (current)
	{
		if (!strcmp(current->key, key)) /* key exists already */
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

/**
 * shash_table_set - Adds an element to a sorted hash table
 * @ht: pointer to the ordered hash table
 * @key: The key string
 * @value: The value associated with the key
 *
 * Return: (1) on success or (0) otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *current, *new;

	if (!ht || !key || !value || !*key)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	if (shash_table_update(ht, key, value, index))
		return (1);

	new = malloc(sizeof(*new));
	if (!new)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);
	new->next = ht->array[index];
	ht->array[index] = new;

	current = ht->shead;
	while (current && strcmp(key, current->key) > 0)
		current = current->snext;

	new->snext = current;
	if (new->snext)
		new->sprev = current->sprev,
			current->sprev = new;
	else
		new->sprev = ht->stail,
			ht->stail = new;

	if (new->sprev)
		new->sprev->snext = new;
	else
		ht->shead = new;

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 *		in a sorted hash table
 * @ht: pointer to the ordered hash table
 * @key: The key string
 *
 * Return: The associated value if key was found or (NULL) otherwise
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	current = ht->array[index];
	while (current)
	{
		if (!strcmp(current->key, key)) /* key exists */
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: pointer to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	unsigned char not_empty = 0;

	if (!ht)
		return;

	putchar('{');
	current = ht->shead;

	while (current)
	{
		if (!not_empty)
			not_empty = 1;
		else
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table reversely
 * @ht: pointer to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	unsigned char not_empty = 0;

	if (!ht)
		return;

	putchar('{');
	current = ht->stail;

	while (current)
	{
		if (!not_empty)
			not_empty = 1;
		else
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a hash table
 * @ht: pointer to the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *next;

	if (!ht)
		return;

	current = ht->shead;
	while (current)
	{
		next = current->snext;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}

	free(ht->array);
	free(ht);
}
