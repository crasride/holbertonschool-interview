#!/usr/bin/python3
"""
Prime Game
"""

def is_prime(num):
    """ Returns True if num is prime, False otherwise """
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

def isWinner(x, nums):
    """ Returns the name of the player that won the most rounds """
    winner = None
    for i in range(x):
        num = nums[i]
        prime_count = sum(1 for j in range(2, num + 1) if is_prime(j))
        if prime_count % 2 == 0:
            winner = "Ben" if i % 2 == 0 else "Maria"
        else:
            winner = "Maria" if i % 2 == 0 else "Ben"
    return winner



