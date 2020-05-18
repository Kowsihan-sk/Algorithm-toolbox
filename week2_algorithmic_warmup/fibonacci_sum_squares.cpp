#include <iostream>

int fibonacci_sum_squares_naive(long long n)
{
    if (n <= 1)
        return n;

    n++;
    n %= 60;
    long long previous = 0;
    long long current = 1;
    // long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous % 10;
        previous = current % 10;
        current = tmp_previous % 10 + current % 10;
        // sum += current * current;
    }

    return ((current % 10) * (previous % 10)) % 10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
