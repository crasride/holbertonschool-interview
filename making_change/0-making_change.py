#!/usr/bin/python3
""" Making Change """


def makeChange(coins, total):
    """
    Find fewest number of coins needed to reach total.

    Args:
        coins: list of coin values
        total: value to reach

    Returns:
        Minimum number of coins needed to reach total.
    """
    if total < 1:
        return 0

    min_arr = [float("inf")] * (total + 1)
    min_arr[0] = 0

    for i in range(1, total + 1):
        for c in coins:
            min_arr[i] = min(min_arr[i], min_arr[i - c] + 1)

    return min_arr[total] if min_arr[total] != float("inf") else -1
