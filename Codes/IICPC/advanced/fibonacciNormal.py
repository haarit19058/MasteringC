def fibonacci_normal(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_normal(n - 1) + fibonacci_normal(n - 2)

# Example usage
print(fibonacci_normal(45))  # Output: 55
