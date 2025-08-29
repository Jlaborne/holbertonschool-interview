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

    if max_n < 2:
        # No primes in any round
        return None

    # Sieve of Eratosthenes up to max_n
    is_prime = [False, False] + [True] * (max_n - 1)  # index 0..max_n
    p = 2
    while p * p <= max_n:
        if is_prime[p]:
            step = p
            start = p * p
            j = start
            while j <= max_n:
                is_prime[j] = False
                j += step
        p += 1

    # Prefix count of primes: primes_count[n] = number of primes <= n
    primes_count = [0] * (max_n + 1)
    c = 0
    i = 0
    while i <= max_n:
        if is_prime[i]:
            c += 1
        primes_count[i] = c
        i += 1

    maria = 0
    ben = 0
    for i in range(rounds):
        n = nums[i]
        # If prime count up to n is odd => Maria wins this round, else Ben
        if primes_count[n] % 2 == 1:
            maria += 1
        else:
            ben += 1

    if maria > ben:
        return "Maria"
    if ben > maria:
        return "Ben"
    return None
