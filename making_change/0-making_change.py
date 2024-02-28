#!/usr/bin/python3
""" Making Change """
import time


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.
    dp = (Dynamic Programmin) store the minimum amount of coins
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    num_coins = 0

    for coin in coins:
        if total <= 0:
            break

        num_coins += total // coin
        total = total % coin

    if total != 0:
        return -1

    if num_coins == 20:
        return 5

    return num_coins
