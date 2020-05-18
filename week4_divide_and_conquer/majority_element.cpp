#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long get_majority_element(vector<long long> &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  //write your code here
  std::sort(a.begin(), a.end());

  for (int i = 0; i < right; i++)
  {
    long long current = a[i];
    int count = 0;
    for (int j = i; j < right; j++)
    {
      bool temp = true;
      if (a[j] == current)
      {
        count++;
        temp = false;
      }
      if (count > right / 2)
        return 1;
      if (temp)
        break;
    }
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
