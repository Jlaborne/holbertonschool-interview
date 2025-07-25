#!/usr/bin/python3
"""
Determines the fewest number of coins needed to meet a given total
"""


def makeChange(coins, total):
    """
    Return the minimum number of coins needed to reach total.
    If not possible, return -1.
    """
    if total <= 0:
        return 0

    # Initialize DP table with total+1 (impossible high value)
    dp = [total + 1] * (total + 1)
    dp[0] = 0  # 0 coins needed to reach 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != total + 1 else -1
