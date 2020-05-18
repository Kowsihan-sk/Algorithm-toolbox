#include <iostream>

long long lcm_fast(int a, int b)
{
  long long lcm = 1;
  long long smaller = 0;

  if (a < b)
    smaller = a;
  else
    smaller = b;

  for (int i = 1; i <= (long long)a * b; lcm = i * smaller, i++)
  {
    if (lcm % a == 0 && lcm % b == 0)
      return lcm;
  }

  return (long long)a * b;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
