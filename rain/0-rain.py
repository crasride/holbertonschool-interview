#!/usr/bin/python3
"""
0-rain module
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    param walls: List non-negative integers representing the heights of walls.
    return: Integer indicating the total amount of rainwater retained.
    """

    # Check if the list of walls is empty or has only two elements
    if not walls or len(walls) <= 2:
        return 0

    total_water = 0
    # Initialize arrays store left and right maximum heights for each position
    left_max = [0] * len(walls)
    right_max = [0] * len(walls)

    # Calculate the left maximum heights for each position
    left_max[0] = walls[0]
    for i in range(1, len(walls)):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Calculate the right maximum heights for each position
    right_max[-1] = walls[-1]
    for i in range(len(walls) - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate the total amount of retained water at each position
    for i in range(len(walls)):
        total_water += min(left_max[i], right_max[i]) - walls[i]

    return total_water
