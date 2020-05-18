#include <iostream>

int get_fibonacci_last_digit_fast(int n)
{
    if (n <= 1)
        return n;

    int f[n];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] % 10 + f[i - 2] % 10;
    }

    return f[n] % 10;
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
