#include <iostream>

int get_change(int m)
{
  int total = 0;

  if (m >= 10)
  {
    total += (m - m % 10) / 10;
    m = m % 10;
  }
  if (m >= 5 && m < 10)
  {
    total += (m - m % 5) / 5;
    m = m % 5;
  }
  if (m >= 1 && m < 5)
  {
    total += m;
  }

  return total;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
