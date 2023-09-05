#!/usr/bin/python3
'''
Calculates minimum number of copy and paste operations to reach n characters
'''


def minOperations(n):
    """
    Args:
        n (int): The number of characters to reach
    Returns:
        int: The minimum needed operations
    """
    # Initialize the variable to count total operations
    total_operations = 0
    # Initialize the divisor to 2, the smallest prime number
    divisor = 2

    # While the square of the divisor is less than or equal to 'n'
    while divisor * divisor <= n:
        # If 'n' is not divisible by the current divisor
        if n % divisor:
            # Increment the divisor to try the next number
            divisor += 1
        else:
            # If 'n' is divisible by the current divisor, divide it
            n //= divisor
            # Add the current divisor to the total operations
            total_operations += divisor

    # If 'n' is greater than 1 at the end, add it to the total operations
    if n > 1:
        total_operations += n

    # Return the total number of required operations
    return total_operations
