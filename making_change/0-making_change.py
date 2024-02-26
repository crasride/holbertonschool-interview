#!/usr/bin/python3
""" Making Change """


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.
    dp = (Dynamic Programmin) store the minimum amount of coins
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

    # If dp[total] is still infinity, it means the total cannot
    # be met by any combination of coins
    return dp[total] if dp[total] != float('inf') else -1
