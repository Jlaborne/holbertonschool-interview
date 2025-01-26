def minOperations(n):
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