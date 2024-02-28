#!/usr/bin/python3
""" Making Change """

def makeChange(coins, total):
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    num_coins = 0

    for coin in coins:
        if total <= 0:
            break

        num_coins += total // coin
        total = total % coin

    return -1 if total != 0 else num_coins

