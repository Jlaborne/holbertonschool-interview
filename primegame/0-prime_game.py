#!/usr/bin/python3
"""
Prime Game - determine the overall winner across x rounds.
No imports allowed.
"""


def isWinner(x, nums):
    """
    Determines who wins the most rounds of the prime game.

    Args:
        x (int): number of rounds
        nums (List[int]): list of n values for each round

    Returns:
        str or None: "Maria" if she wins most, "Ben" if he wins most, None on tie.
    """
    if not nums or x <= 0:
        return None

    rounds = min(x, len(nums))
    max_n = 0
    for i in range(rounds):
        if nums[i] > max_n:
            max_n = nums[i]

    # Sieve size covers indices 0..max_n
    is_prime = [False, False] + [True] * max(0, max_n - 1)
    p = 2
    while p * p <= max_n:
        if is_prime[p]:
            j = p * p
            while j <= max_n:
                is_prime[j] = False
                j += p
        p += 1

    # Prefix counts of primes: primes_count[n] = #primes <= n
    primes_count = [0] * (max_n + 1)
    cnt = 0
    for i in range(max_n + 1):
        if is_prime[i]:
            cnt += 1
        primes_count[i] = cnt

    maria = 0
    ben = 0
    for i in range(rounds):
        n = nums[i]
        if primes_count[n] % 2 == 1:
            maria += 1
        else:
            ben += 1

    if maria > ben:
        return "Maria"
    if ben > maria:
        return "Ben"
    return None
