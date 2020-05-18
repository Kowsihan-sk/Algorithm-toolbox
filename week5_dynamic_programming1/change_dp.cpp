#include <iostream>
#include <algorithm>

int get_change(int m)
{
  int coin[3] = {1, 3, 4};
  int table[3][m + 1];

  for (int i = 0; i < 3; i++)
  {
    table[i][0] = 0;
    for (int j = 1; j < m + 1; j++)
    {
      if (j >= coin[i])
      {
        if (i == 0)
          table[i][j] = 1 + table[i][j - coin[i]];
        else
          table[i][j] = std::min(table[i - 1][j], 1 + table[i][j - coin[i]]);
      }
      else
        table[i][j] = table[i - 1][j];
    }
  }

  return table[2][m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
