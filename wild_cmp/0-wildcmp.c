#include "holberton.h"

/**
* wildcmp - Compare two strings with wildcard support.
* @s1: The first string.
* @s2: The second string (may contain wildcard '*').
*
* Return: 1 if the strings can be considered identical, otherwise return 0.
*/
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* If both strings reach the end */
		return (1);
	if (*s2 == '*') /* If current character in s2 is '*' */
	{
		if (*s1 == '\0') /* If s1 reaches the end but s2 still has '*' */
			return (wildcmp(s1, s2 + 1)); /* Recursively check without '*' */
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
		/* Check if '*' represents empty string or move forward in s1 */
	}
	if (*s1 == *s2) /* If characters match */
		return (wildcmp(s1 + 1, s2 + 1)); /* Move to next characters */
	return (0); /* If none the above conditions met, strings are not identical */
}
