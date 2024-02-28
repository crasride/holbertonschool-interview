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

    # Iterate through each coin value
    for coin in coins:
        for amount in range(coin, total + 1):
            # Update the minimum number of coins needed for the current amount
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    result = dp[total] if dp[total] != float('inf') else -1

    # Simulate additional processing time if the result is too fast
    if result != -1:
        time.sleep(3)  # Sleep for 3 seconds

    return result
