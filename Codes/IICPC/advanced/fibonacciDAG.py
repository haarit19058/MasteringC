def fibonacci_dag(n, memo=None):
    if memo is None:
        memo = {}
    
    if n in memo:
        return memo[n]
    
    if n <= 0:
        result = 0
    elif n == 1:
        result = 1
    else:
        result = fibonacci_dag(n - 1, memo) + fibonacci_dag(n - 2, memo)
    
    memo[n] = result
    return result

# Example usage
print(fibonacci_dag(500))  # Output: 55
