#!/usr/bin/python3
'''
'''


def minOperations(n):
    '''
    Calculates minimum copy all and paste operations to reach n characters
        Args:
        n: characters to reach
    Returns:
        minimum needed operations
    '''
    if n == 1:
        return 0

    operations = [0] * (n + 1)

    for i in range(2, n + 1):
        operations[i] = i
        for j in range(2, int(i**0.5) + 1):
            if i % j == 0:
                operations[i] = min(operations[i], operations[j] + i // j)

    return operations[n]
