#!/usr/bin/python3
"""
Prime Game: Determines the winner of a game where players remove prime numbers
and their multiples from a set of consecutive integers.
"""


def sieve_of_eratosthenes(limit):
    """
    Generates a list of primes using Sieve of Eratosthenes
    Finding Prime numbers
    https://www.youtube.com/watch?v=eKp56OLhoQs
    """
    # Initialize a list to mark numbers as prime or not
    primes = [True] * (limit + 1)
    primes[0] = primes[1] = False  # 0 and 1 are not prime
    p = 2
    # Iterate over numbers until the square root of the limit
    while p * p <= limit:
        if primes[p]:
            # Mark multiples of p as not prime
            for i in range(p * p, limit + 1, p):
                primes[i] = False
        p += 1
    return primes


def isWinner(x, nums):
    """ Returns the name of the player that won the most rounds """
    if x <= 0:
        return None

    # Generate list of primes up to the maximum number in nums
    primes = sieve_of_eratosthenes(max(max(nums), 2))
    ben_wins = 0
    maria_wins = 0
    # Iterate over the given numbers
    for num in nums:
        # Count the number of primes up to num
        prime_count = sum(1 for j in range(2, num + 1) if primes[j])
        # Determine the winner of the round based on the count of primes
        if prime_count % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    # Decide the overall winner based on the total wins
    if ben_wins > maria_wins:
        return "Ben"
    elif maria_wins > ben_wins:
        return "Maria"
    else:
        return None
