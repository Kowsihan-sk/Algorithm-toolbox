#include <iostream>
#include <vector>

using std::vector;

int Max_index(vector<int> weights, vector<int> values)
{
  int m_index = 0;
  double max_kg = 0;

  for (int i = 0; i < weights.size(); i++)
  {
    if (weights[i] != 0 && (double)values[i] / weights[i] > max_kg)
    {
      max_kg = (double)values[i] / weights[i];
      m_index = i;
    }
  }
  return m_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;

  for (int i = 0; i < weights.size(); i++)
  {
    if (capacity == 0)
      return value;
    int max_index = Max_index(weights, values);
    int w = std::min(capacity, weights[max_index]);
    value += w * (double)values[max_index] / weights[max_index];
    weights[max_index] -= w;
    capacity -= w;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}