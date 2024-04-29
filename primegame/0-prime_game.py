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
    if x <= 0:
        return None

    ben_wins = 0
    maria_wins = 0
    for num in nums:
        prime_count = sum(1 for j in range(2, num + 1) if is_prime(j))
        if prime_count % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if ben_wins > maria_wins:
        return "Ben"
    elif maria_wins > ben_wins:
        return "Maria"
    else:
        return None
