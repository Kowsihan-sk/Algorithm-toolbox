#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  long long x = a.size(), y = b.size(), z = c.size();
  vector<vector<vector<long long>>> table(x + 1, vector<vector<long long>>(y + 1, vector<long long>(z + 1)));

  for (size_t i = 0; i <= x; i++)
    table[i][0][0] = 0;
  for (size_t j = 0; j <= y; j++)
    table[0][j][0] = 0;
  for (size_t k = 0; k <= z; k++)
    table[0][0][k] = 0;

  for (size_t i = 1; i <= x; i++)
  {
    for (size_t j = 1; j <= y; j++)
    {
      for (size_t k = 1; k <= z; k++)
      {

        if ((a[i - 1] == b[j - 1]) && (b[j - 1] == c[k - 1]))
          table[i][j][k] = table[i - 1][j - 1][k - 1] + 1;
        else
          table[i][j][k] = std::max(std::max(table[i - 1][j][k], table[i][j - 1][k]), table[i][j][k - 1]);
      }
    }
  }

  return table[x][y][z];
}

int main()
{
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++)
  {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++)
  {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++)
  {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
