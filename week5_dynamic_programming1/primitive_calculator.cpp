#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  std::vector<int> a(n + 1);

  a[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    a[i] = a[i - 1] + 1;
    if (i % 2 == 0)
      a[i] = std::min(1 + a[i / 2], a[i]);
    if (i % 3 == 0)
      a[i] = std::min(1 + a[i / 3], a[i]);
  }

  while (n >= 1)
  {
    sequence.push_back(n);

    if (n % 3 == 0 && a[n / 3] + 1 == a[n])
    {
      n /= 3;
    }
    else if (n % 2 == 0 && a[n / 2] + 1 == a[n])
    {
      n /= 2;
    }
    else if (a[n - 1] + 1 == a[n])
    {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
