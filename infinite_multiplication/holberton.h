#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes Task 0*/
int _putchar(char c);
int _puts(char *s);
char verify_arg(char *num);
int _strlen(char *s);
void multiply_numbers(char *num1, char *num2, int *result, int len1, int len2);
void initialize_array(int *array, int size);
void print_result(int *array, int size);

#endif /* HOLBERTON_H */
