#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    from %= 60;
    to %= 60;

    if (to < from)
        to += 60;
    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next += current;
        current = new_current;
    }

    return sum % 10;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
