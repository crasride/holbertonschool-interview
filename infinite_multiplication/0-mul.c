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
		_puts("Error\n");
		exit(98);
	}
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len_result = len1 + len2;

	result = malloc(len_result * sizeof(int));

	if (!result)
		return (EXIT_FAILURE);

	initialize_array(result, len_result);
	multiply_numbers(argv[1], argv[2], result, len1, len2);
	print_result(result, len_result);

	free(result);
	return (EXIT_SUCCESS);
}

/**
 * _puts - prints a string
 *
 * @s: string to print
 *
 * Return: the length of the string
 */
int _puts(char *s)
{
	int length = 0;

	for (; *s; s++)
		length += _putchar(*s);

	return (length);
}

/**
 * _strlen - Finds the length of a string
 *
 * @s: string to find the length
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
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
 * multiply_numbers - Multiplies two numbers
 *
 * @num1: first number as a string
 * @num2: second number as a string
 * @result: array of int to contain the product
 * @len1: length of the first number
 * @len2: length of the second number
 */
void multiply_numbers(char *num1, char *num2, int *result, int len1, int len2)
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
 * initialize_array - Initializes an array with 0
 *
 * @array: array to initialize
 * @size: size of the array
 */
void initialize_array(int *array, int size)
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
