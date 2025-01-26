#!/usr/bin/python3
"""
Calculating the minimum number of operations
to produce n H characters in the file.
"""


def minOperations(n):
    """
    Calculate the fewest number of operations to produce n H characters.
    Returns 0 if n is impossible to achieve.
    """
    
    if n <= 1:
        return 0  # Impossible to achieve
    
    operations = 0
    factor = 2  # Start with the smallest prime number
    
    while n > 1:
        while n % factor == 0:
            operations += factor  # Add the factor to operations
            n //= factor  # Divide n by the factor
        factor += 1  # Move to the next possible factor
    
    return operations