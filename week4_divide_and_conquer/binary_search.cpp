#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

long long binary_search(const vector<long long> &a, long long x)
{
  long long left = 0, right = (long long)a.size();
  //write your code here
  long long mid = (left + right) / 2;

  while (right >= left)
  {
    mid = (left + right) / 2;

    if (a[mid] == x)
      return mid;
    else if (a[mid] < x)
      left = mid + 1;
    else
      right = mid - 1;
    if (right < left)
      return -1;
  }

  return -1;
}

long long linear_search(const vector<long long> &a, long long x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  long long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (long long i = 0; i < m; ++i)
  {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
