#include "substring.h"

/**
* mark_words_in_substring - Marks the words found in a substring
* @s: The substring to scan
* @words: The words to find
* @nb_words: The number of words
* @word_len: The length of each word
* @seen: The array to mark the words found
*
* Return: 1 if all the words are found, 0 otherwise
*/
static int mark_words_in_substring(char const *s, char const **words,
										int nb_words, int word_len, int *seen)
{
	int j, k;

	/* Recorremos la subcadena */
	for (j = 0; j < nb_words; j++)
	{
		/* Buscamos la palabra en la subcadena */
		for (k = 0; k < nb_words; k++)
		{
			/* Si la palabra no ha sido vista y se encuentra en la subcadena */
			if (seen[k] == 0 && strncmp(s + j * word_len, words[k], word_len) == 0)
			{
				seen[k] = 1;
				break;
			}
		}
		if (k == nb_words)
		{
			return (0); /* No se encontró una palabra */
		}
	}
	return (1); /* Todas las palabras están en la subcadena */
}

/**
* find_substring - Finds all the possible substrings containing a list of words
* @s: The string to scan
* @words: The words to find
* @nb_words: The number of words
* @n: The number of elements in the returned array
*
* Return: An array with the indices of the substrings, NULL if none found
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !words || nb_words <= 0)
		return (NULL);
	/* Tamaño de la subcadena y la longitud de las palabras */
	int s_len = strlen(s); /* Longitud de la cadena */
	int word_len = strlen(words[0]); /* Longitud de las palabras */
	int total_len = nb_words * word_len; /* Longitud total de las palabras */
	int *indices = malloc(sizeof(int) * s_len); /* Índices de las subcadenas */

	if (!indices)
		return (NULL);
	/* Contadores */
	int i;
	*n = 0; /* Inicializamos el contador de índices */
	/* Recorremos la cadena */
	for (i = 0; i <= s_len - total_len; i++)
	{
		/* Creamos una tabla temporal para verificar las palabras */
		int *seen = calloc(nb_words, sizeof(int));
		/* Si no se pudo reservar memoria, liberamos y devolvemos NULL */
		if (!seen)
		{
			free(indices);
			return (NULL);
		}
		/* Marcamos las palabras vistos en la subcadena */
		int valid = mark_words_in_substring(s + i, words, nb_words, word_len, seen);
		/* Si todas las palabras están en la subcadena */
		if (valid)
		{
			indices[*n] = i;
			(*n)++;
		}
		free(seen);
	}
	if (*n == 0) /* Si no se encontraron índices, liberamos y devolvemos NULL */
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
