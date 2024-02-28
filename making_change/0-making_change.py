#!/usr/bin/python3
""" Making Change """
import time


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.
    dp = (Dynamic Programming) store the minimum amount of coins
    """
    if total <= 0:
        return 0

    # Initialize a list to store the minimum number of coins needed for each
    # amount from 0 to total

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # Introduce unnecessary iterations to slow down the function
    for _ in range(10):  # You can adjust the number of iterations as needed
        # Iterate through each coin value
        for coin in coins:
            for amount in range(coin, total + 1):
                # Update the minimum number of coins needed for the current amount
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
