#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int optimal_weight(int W, vector<int> &w, int success)
{
  int i, j, W_back, row;
  vector<vector<int>> M(w.size() + 1, vector<int>(W + 1, 0));

  for (i = 1; i <= w.size(); i++)
  {
    for (j = 1; j <= W; j++)
    {
      if (w[i - 1] > j)
        M[i][j] = M[i - 1][j];
      else
        M[i][j] = max(w[i - 1] + M[i - 1][j - w[i - 1]], M[i - 1][j]);
    }
    if (M[i][j - 1] == W)
      break;
  }
  W_back = W;
  vector<int> erase_idx;
  for (int idx = 0; idx < w.size(); idx++)
  {
    if (W_back - w[idx] >= 0)
    {
      W_back -= w[idx];
      erase_idx.push_back(idx);
    }
    if (W_back == 0)
    {
      int e = 0;
      for (int k = 0; k < erase_idx.size(); k++)
      {
        w.erase(w.begin() + erase_idx[k] - e);
        e++;
      }
      success++;
      break;
    }
  }
  return success;
}

int partition3(vector<int> &A)
{
  int p = 0;
  int success = 0;
  if (accumulate(A.begin(), A.end(), 0) % 3 == 0)
  {
    int max_perFriend = accumulate(A.begin(), A.end(), 0) / 3;
    sort(A.begin(), A.end(), greater<>());
    success = optimal_weight(max_perFriend, A, success);

    if (success != 1)
      return p;

    success = optimal_weight(max_perFriend, A, success);

    if (success == 2)
      p = 1;
  }
  return p;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}