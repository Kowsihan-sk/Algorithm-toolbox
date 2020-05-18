#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b)
{
  int n = a.size(), m = b.size();
  int table[n + 1][m + 1];

  for (int i = 0; i <= n; i++)
    table[i][0] = 0;
  for (int j = 0; j <= m; j++)
    table[0][j] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (a[i - 1] == b[j - 1])
        table[i][j] = table[i - 1][j - 1] + 1;
      else
        table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
    }
  }

  return table[n][m];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
