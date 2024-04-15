#include "regex.h"

/**
* regex_match - Check if a given pattern matches a given string
* @str: The string to scan
* @pattern: The regular expression pattern
*
* Return: 1 if the pattern matches the string, 0 otherwise
*/
int regex_match(char const *str, char const *pattern)
{
	/* Base case: If both string and pattern are empty, the match is successful */
	if (*str == '\0' && *pattern == '\0')
		return (1);

	/* If the next character in the pattern is '*', we handle the repeat logic */
	if (*(pattern + 1) == '*')
	{
		/* We try to match the pattern without the preceding character */
		if (regex_match(str, pattern + 2))
			return (1);
		/*
		* If no match occurs, we try to match the pattern with the preceding
		* character repeated zero or more times
		*/
		while (*str && (*str == *pattern || *pattern == '.'))
		{
			if (regex_match(++str, pattern + 2))
				return (1);
		}

		/* If no match was found, we return 0 */
		return (0);
	}
	/*
	* If one of the two (string or pattern) is empty and we are not dealing
	* with '*', there is no match
	*/
	if (*str == '\0' || *pattern == '\0')
		return (0);

	/*
	* If the pattern contains a '.', it matches any character in the string
	* Or if the characters match literally, we advance to the next characters
	* in the string and pattern
	*/
	if (*pattern == '.' || *str == *pattern)
		return (regex_match(str + 1, pattern + 1));

	/* If none of the above cases are true, there is no match */
	return (0);
}
