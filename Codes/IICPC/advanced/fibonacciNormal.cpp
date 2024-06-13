#include <iostream>

int fibonacci_normal(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_normal(n - 1) + fibonacci_normal(n - 2);
    }
}

int main() {
    int n = 45;
    std::cout << "Fibonacci of " << n << " is " << fibonacci_normal(n) << std::endl;
    return 0;
}
