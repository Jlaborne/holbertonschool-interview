#!/usr/bin/python3
"""
This module provides a function to calculate how much
rainwater can be trapped between walls after it rains.
"""


def rain(walls):
    """
    Calculates the total amount of rainwater retained.

    Args:
        walls (list): A list of non-negative integers representing
                      wall heights.

    Returns:
        int: Total units of water retained after raining.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    total_water = 0

    # Compute max height to the left of each wall
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Compute max height to the right of each wall
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Compute water above each wall
    for i in range(n):
        water = min(left_max[i], right_max[i]) - walls[i]
        total_water += water

    return total_water
