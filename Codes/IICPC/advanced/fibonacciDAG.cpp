#include <iostream>
#include <vector>

std::vector<unsigned  long long int> memo;

unsigned long long int fibonacci_dag(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = fibonacci_dag(n - 1) + fibonacci_dag(n - 2);
    return memo[n];
}

int main() {
    int n = 700;
    memo.resize(n + 1, 0);
    std::cout << "Fibonacci of " << n << " is " << fibonacci_dag(n) << std::endl;
    return 0;
}






