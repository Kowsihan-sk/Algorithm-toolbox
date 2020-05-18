#include <iostream>
#include <string>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2)
{
  int n = str1.size(), m = str2.size();
  int table[n + 1][m + 1];

  for (int i = 0; i <= n; i++)
    table[i][0] = i;
  for (int j = 0; j <= m; j++)
    table[0][j] = j;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
        table[i][j] = table[i - 1][j - 1];
      else
        table[i][j] = std::min(std::min(table[i - 1][j], table[i][j - 1]), table[i - 1][j - 1]) + 1;
    }
  }
  return table[n][m];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
