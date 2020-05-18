#include <iostream>

int gcd_fast(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd_fast(b, a % b);
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
