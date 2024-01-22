#include "holberton.h"

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 in case of success, 98 in case of failure, 1 if argc != 3
 */
int main(int argc, char **argv)
{
	int len1, len2, len_result, *result;

	if (argc != 3 || !verify_arg(argv[1]) || !verify_arg(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	len_result = len1 + len2;

	result = malloc(len_result * sizeof(int));

	if (!result)
		return (EXIT_FAILURE);

	initialize(result, len_result);
	multiply(argv[1], argv[2], result, len1, len2);
	print_result(result, len_result);

	free(result);
	return (EXIT_SUCCESS);
}

/**
 * verify_arg - Verifies if the argument is a number or not
 *
 * @num: string to verify
 *
 * Return: 1 if the argument is a number, 0 otherwise
 */
char verify_arg(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * multiply - Multiplies two numbers
 *
 * @num1: first number as a string
 * @num2: second number as a string
 * @result: array of int to contain the product
 * @len1: length of the first number
 * @len2: length of the second number
 */
void multiply(char *num1, char *num2, int *result, int len1, int len2)
{
	int i, j, product, pos1, pos2, digit1, digit2;

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			product = digit1 * digit2;

			pos1 = i + j;
			pos2 = i + j + 1;

			product += result[pos2];

			result[pos1] += product / 10;
			result[pos2] = product % 10;
		}
	}
}

/**
 * initialize - Initializes an array with 0
 *
 * @array: array to initialize
 * @size: size of the array
 */
void initialize(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * print_result - Prints the result of the multiplication
 *
 * @array: array containing the result
 * @size: size of the array
 */
void print_result(int *array, int size)
{
	int i = 0;

	while (i < size && array[i] == 0)
		i++;

	if (i == size)
		_putchar('0');
	else
	{
		for (; i < size; i++)
			_putchar(array[i] + '0');
	}
	_putchar('\n');
}
