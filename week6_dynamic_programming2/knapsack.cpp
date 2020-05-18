#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  int x = w.size();
  vector<vector<int>> table(x + 1, vector<int>(W + 1));

  for (size_t i = 0; i <= x; i++)
    table[i][0] = 0;
  for (size_t i = 0; i <= W; i++)
    table[0][i] = 0;

  for (int i = 1; i <= x; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (j < w[i - 1])
        table[i][j] = table[i - 1][j];
      else
        table[i][j] = std::max((w[i - 1] + table[i - 1][j - w[i - 1]]), table[i - 1][j]);
    }
  }
  return table[x][W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
