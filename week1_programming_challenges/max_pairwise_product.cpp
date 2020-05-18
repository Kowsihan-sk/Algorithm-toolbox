#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    int max_index1 = 0, max_index2 = -5;

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > numbers[max_index1])
            max_index1 = i;
    }

    for (int i = 0; i < n; i++)
    {
        if ((max_index2 == -5 || numbers[i] > numbers[max_index2]) && max_index1 != i)
            max_index2 = i;
    }

    max_product = ((long long)(numbers[max_index1])) * numbers[max_index2];

    return max_product;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers);
    std::cout << "\n";

    return 0;
}
