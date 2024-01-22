#include "holberton.h"
#include <stdlib.h>

/**
* print_product - print product array
* @product: array to print
* @len: len of array
*/
void print_product(int *product, size_t len)
{
	size_t i;

	if (product == NULL || len == 0)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}
	for (i = *product ? 0 : 1; i < len; ++i)
		_putchar(product[i] + '0');
	_putchar('\n');
}

/**
* multiply - multiply two numbers represented as strings
* @product: array to store product
* @n1: first string
* @n2: second string
* @len1: length of first string
* @len2: length of second string
*/
void multiply(int *product, char *n1, char *n2, size_t len1, size_t len2)
{
	int i, j, carry;

	for (i = len1 - 1; i > -1; --i)
		for (j = len2 - 1; j > -1; --j)
		{
			carry = (n1[i] - '0') * (n2[j] - '0') + product[i + j + 1];
			product[i + j + 1] = carry % 10;
			product[i + j] += carry / 10;
		}
}

/**
* error_exit - Prints "Error" and exits with status 98
*/
void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(98);
}

/**
* main - entry point for infinite multiplication
* @argc: number of command-line arguments
* @argv: pointer to an array of character strings containing the arguments
*
* Return: 0 on success or 1 on error
*/
int main(int argc, char *argv[])
{
	int *product;
	size_t len1, len2;

	if (argc != 3)
	{
		error_exit();
	}

	if (*argv[1] == '0' || *argv[2] == '0')
	{
		print_product(NULL, 0);
		return (0);
	}

	len1 = strlen(argv[1]), len2 = strlen(argv[2]);
	product = calloc(len1 + len2, sizeof(*product));
	if (product == NULL)
	{
		error_exit();
	}

	multiply(product, argv[1], argv[2], len1, len2);
	print_product(product, len1 + len2);
	free(product);
	return (0);
}


