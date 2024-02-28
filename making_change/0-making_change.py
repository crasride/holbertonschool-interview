#!/usr/bin/python3
""" Making Change """


def makeChange(coins, total):
    """
    Calculates the minimum number of coins needed to reach a given amount.

    :param coins: List of available coin denominations.
    :param total: Desired amount.
    :return: The minimum number of coins needed to reach the amount, or -1 if not possible.
    """

    # Check if the desired amount is less than or equal to zero
    if total <= 0:
        return 0

    # Sort the coins in descending order to use the greedy coin-changing approach
    coins.sort(reverse=True)
    num_coins = 0

    # Iterate through each coin
    for coin in coins:
        # Check if the desired amount has already been reached
        if total <= 0:
            break

        # Calculate the number of coins of the current denomination needed
        num_coins += total // coin
        # Update the remaining amount after using coins of the current denomination
        total %= coin

    # Return -1 if the amount could not be fully reached with the available coins
    return -1 if total != 0 else num_coins
