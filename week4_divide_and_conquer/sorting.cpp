#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;

// int partition2(vector<int> &a, int l, int r)
// {
//   int x = a[l];
//   int j = l;
//   for (int i = l + 1; i <= r; i++)
//   {
//     if (a[i] <= x)
//     {
//       j++;
//       swap(a[i], a[j]);
//     }
//   }
//   swap(a[l], a[j]);
//   return j;
// }

vector<int> partition3(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  int p_start = l;
  int p_end = r;
  vector<int> m(2);

  while (j <= p_end)
  {
    if (a[j] < x)
    {
      swap(a[p_start], a[j]);
      p_start++;
      j++;
    }
    else if (a[j] == x)
      j++;
    else
    {
      swap(a[j], a[p_end]);
      p_end--;
    }

    m[0] = p_start;
    m[1] = p_end;
  }
  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
