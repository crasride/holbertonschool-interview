#!/usr/bin/python3
'''
Calculates minimum copy all and paste operations to reach n characters
'''


def minOperations(n):
    """
    Args:
      n: The number of characters to reach
    Returns:
      The minimum needed operations
    """
    total_operations = 0
    divisor = 2
    while divisor * divisor <= n:
        if n % divisor:
            divisor += 1
        else:
            n //= divisor
            total_operations += divisor
    if n > 1:
        total_operations += n
    return total_operations
