#include <iostream>

long long Pisano_period_length(long long m)
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }

    return 3;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long remainder = n % Pisano_period_length(m);

    long long F1 = 0, F2 = 1, F = remainder;
    for (int i = 1; i < remainder; i++)
    {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}

int main()
{
    long long n, m;

    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}